#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Zoness_ZoObnema_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192E64: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80192E68: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x80192E6C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80192E70: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80192E74: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x80192E78: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80192E7C: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x80192E80: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80192E84: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80192E88: lh          $v0, 0xB8($s3)
    ctx->r2 = MEM_H(ctx->r19, 0XB8);
    // 0x80192E8C: lui         $at, 0x43BE
    ctx->r1 = S32(0X43BE << 16);
    // 0x80192E90: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80192E94: beql        $v0, $zero, L_80192ECC
    if (ctx->r2 == 0) {
        // 0x80192E98: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80192ECC;
    }
    goto skip_0;
    // 0x80192E98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x80192E9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80192EA0: beq         $v0, $at, L_80192ED8
    if (ctx->r2 == ctx->r1) {
        // 0x80192EA4: addiu       $a0, $s3, 0xE8
        ctx->r4 = ADD32(ctx->r19, 0XE8);
            goto L_80192ED8;
    }
    // 0x80192EA4: addiu       $a0, $s3, 0xE8
    ctx->r4 = ADD32(ctx->r19, 0XE8);
    // 0x80192EA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80192EAC: beq         $v0, $at, L_80192FB8
    if (ctx->r2 == ctx->r1) {
        // 0x80192EB0: addiu       $a0, $s3, 0xE8
        ctx->r4 = ADD32(ctx->r19, 0XE8);
            goto L_80192FB8;
    }
    // 0x80192EB0: addiu       $a0, $s3, 0xE8
    ctx->r4 = ADD32(ctx->r19, 0XE8);
    // 0x80192EB4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80192EB8: beq         $v0, $at, L_80193044
    if (ctx->r2 == ctx->r1) {
        // 0x80192EBC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80193044;
    }
    // 0x80192EBC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80192EC0: b           L_80193110
    // 0x80192EC4: lb          $v0, 0xD0($s3)
    ctx->r2 = MEM_B(ctx->r19, 0XD0);
        goto L_80193110;
    // 0x80192EC4: lb          $v0, 0xD0($s3)
    ctx->r2 = MEM_B(ctx->r19, 0XD0);
    // 0x80192EC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80192ECC:
    // 0x80192ECC: sh          $t6, 0xB8($s3)
    MEM_H(0XB8, ctx->r19) = ctx->r14;
    // 0x80192ED0: b           L_8019310C
    // 0x80192ED4: swc1        $f4, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f4.u32l;
        goto L_8019310C;
    // 0x80192ED4: swc1        $f4, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f4.u32l;
L_80192ED8:
    // 0x80192ED8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80192EDC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80192EE0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80192EE4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192EE8: lwc1        $f6, 0xEEC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XEEC);
    // 0x80192EEC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80192EF0: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80192EF4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80192EF8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80192EFC: jal         0x8009BC2C
    // 0x80192F00: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x80192F00: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80192F04: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192F08: lwc1        $f8, 0xEF0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XEF0);
    // 0x80192F0C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80192F10: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80192F14: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80192F18: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80192F1C: addiu       $a0, $s3, 0xF0
    ctx->r4 = ADD32(ctx->r19, 0XF0);
    // 0x80192F20: jal         0x8009BC2C
    // 0x80192F24: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80192F24: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80192F28: lhu         $t7, 0xBC($s3)
    ctx->r15 = MEM_HU(ctx->r19, 0XBC);
    // 0x80192F2C: bnel        $t7, $zero, L_80193110
    if (ctx->r15 != 0) {
        // 0x80192F30: lb          $v0, 0xD0($s3)
        ctx->r2 = MEM_B(ctx->r19, 0XD0);
            goto L_80193110;
    }
    goto skip_1;
    // 0x80192F30: lb          $v0, 0xD0($s3)
    ctx->r2 = MEM_B(ctx->r19, 0XD0);
    skip_1:
    // 0x80192F34: lh          $t8, 0xB6($s3)
    ctx->r24 = MEM_H(ctx->r19, 0XB6);
    // 0x80192F38: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80192F3C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80192F40: sh          $t9, 0xB6($s3)
    MEM_H(0XB6, ctx->r19) = ctx->r25;
    // 0x80192F44: lh          $t0, 0xB6($s3)
    ctx->r8 = MEM_H(ctx->r19, 0XB6);
    // 0x80192F48: bne         $t0, $at, L_8019310C
    if (ctx->r8 != ctx->r1) {
        // 0x80192F4C: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_8019310C;
    }
    // 0x80192F4C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192F50: lwc1        $f16, 0xEF4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XEF4);
    // 0x80192F54: lwc1        $f10, 0x14($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X14);
    // 0x80192F58: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80192F5C: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x80192F60: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80192F64: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80192F68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80192F6C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80192F70: jal         0x80005E90
    // 0x80192F74: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x80192F74: nop

    after_2:
    // 0x80192F78: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80192F7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80192F80: swc1        $f20, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f20.u32l;
    // 0x80192F84: swc1        $f20, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f20.u32l;
    // 0x80192F88: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80192F8C: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x80192F90: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    // 0x80192F94: jal         0x80006A20
    // 0x80192F98: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_3;
    // 0x80192F98: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80192F9C: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80192FA0: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80192FA4: swc1        $f6, 0xE8($s3)
    MEM_W(0XE8, ctx->r19) = ctx->f6.u32l;
    // 0x80192FA8: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80192FAC: sh          $t1, 0xB8($s3)
    MEM_H(0XB8, ctx->r19) = ctx->r9;
    // 0x80192FB0: b           L_8019310C
    // 0x80192FB4: swc1        $f8, 0xF0($s3)
    MEM_W(0XF0, ctx->r19) = ctx->f8.u32l;
        goto L_8019310C;
    // 0x80192FB4: swc1        $f8, 0xF0($s3)
    MEM_W(0XF0, ctx->r19) = ctx->f8.u32l;
L_80192FB8:
    // 0x80192FB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80192FBC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80192FC0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80192FC4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192FC8: lwc1        $f10, 0xEF8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XEF8);
    // 0x80192FCC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80192FD0: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80192FD4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80192FD8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80192FDC: jal         0x8009BC2C
    // 0x80192FE0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x80192FE0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x80192FE4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192FE8: lwc1        $f16, 0xEFC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XEFC);
    // 0x80192FEC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80192FF0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80192FF4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80192FF8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80192FFC: addiu       $a0, $s3, 0xF0
    ctx->r4 = ADD32(ctx->r19, 0XF0);
    // 0x80193000: jal         0x8009BC2C
    // 0x80193004: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x80193004: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x80193008: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8019300C: jal         0x8009ACDC
    // 0x80193010: addiu       $a0, $a0, -0x5048
    ctx->r4 = ADD32(ctx->r4, -0X5048);
    Animation_GetFrameCount(rdram, ctx);
        goto after_6;
    // 0x80193010: addiu       $a0, $a0, -0x5048
    ctx->r4 = ADD32(ctx->r4, -0X5048);
    after_6:
    // 0x80193014: lh          $v1, 0xB6($s3)
    ctx->r3 = MEM_H(ctx->r19, 0XB6);
    // 0x80193018: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x8019301C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80193020: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80193024: beq         $at, $zero, L_80193034
    if (ctx->r1 == 0) {
        // 0x80193028: addiu       $t2, $v1, 0x1
        ctx->r10 = ADD32(ctx->r3, 0X1);
            goto L_80193034;
    }
    // 0x80193028: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x8019302C: b           L_8019310C
    // 0x80193030: sh          $t2, 0xB6($s3)
    MEM_H(0XB6, ctx->r19) = ctx->r10;
        goto L_8019310C;
    // 0x80193030: sh          $t2, 0xB6($s3)
    MEM_H(0XB6, ctx->r19) = ctx->r10;
L_80193034:
    // 0x80193034: sh          $zero, 0xB6($s3)
    MEM_H(0XB6, ctx->r19) = 0;
    // 0x80193038: sh          $t3, 0xBC($s3)
    MEM_H(0XBC, ctx->r19) = ctx->r11;
    // 0x8019303C: b           L_8019310C
    // 0x80193040: sh          $t4, 0xB8($s3)
    MEM_H(0XB8, ctx->r19) = ctx->r12;
        goto L_8019310C;
    // 0x80193040: sh          $t4, 0xB8($s3)
    MEM_H(0XB8, ctx->r19) = ctx->r12;
L_80193044:
    // 0x80193044: addiu       $s1, $s3, 0x18C
    ctx->r17 = ADD32(ctx->r19, 0X18C);
    // 0x80193048: addiu       $s2, $s3, 0x1F8
    ctx->r18 = ADD32(ctx->r19, 0X1F8);
L_8019304C:
    // 0x8019304C: jal         0x80004EB0
    // 0x80193050: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x80193050: nop

    after_7:
    // 0x80193054: jal         0x80004EB0
    // 0x80193058: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x80193058: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_8:
    // 0x8019305C: jal         0x80004EB0
    // 0x80193060: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x80193060: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_9:
    // 0x80193064: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80193068: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019306C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80193070: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80193074: sub.s       $f4, $f20, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f18.fl;
    // 0x80193078: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8019307C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80193080: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80193084: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80193088: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019308C: addiu       $t5, $zero, 0x3B
    ctx->r13 = ADD32(0, 0X3B);
    // 0x80193090: mul.s       $f16, $f22, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x80193094: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80193098: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x8019309C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801930A0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801930A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801930A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801930AC: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x801930B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801930B4: lwc1        $f6, 0x110($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X110);
    // 0x801930B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801930BC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x801930C0: jal         0x801900FC
    // 0x801930C4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Zoness_ActorDebris_Spawn(rdram, ctx);
        goto after_10;
    // 0x801930C4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x801930C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801930CC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801930D0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x801930D4: bne         $s0, $at, L_8019304C
    if (ctx->r16 != ctx->r1) {
        // 0x801930D8: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_8019304C;
    }
    // 0x801930D8: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x801930DC: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x801930E0: sb          $t7, 0x44($s3)
    MEM_B(0X44, ctx->r19) = ctx->r15;
    // 0x801930E4: jal         0x80066254
    // 0x801930E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Actor_Despawn(rdram, ctx);
        goto after_11;
    // 0x801930E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_11:
    // 0x801930EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801930F0: jal         0x80060FBC
    // 0x801930F4: addiu       $a1, $s3, 0x100
    ctx->r5 = ADD32(ctx->r19, 0X100);
    Object_Kill(rdram, ctx);
        goto after_12;
    // 0x801930F4: addiu       $a1, $s3, 0x100
    ctx->r5 = ADD32(ctx->r19, 0X100);
    after_12:
    // 0x801930F8: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    // 0x801930FC: lwc1        $f14, 0x8($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80193100: lw          $a2, 0xC($s3)
    ctx->r6 = MEM_W(ctx->r19, 0XC);
    // 0x80193104: jal         0x8007D0E0
    // 0x80193108: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_13;
    // 0x80193108: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_13:
L_8019310C:
    // 0x8019310C: lb          $v0, 0xD0($s3)
    ctx->r2 = MEM_B(ctx->r19, 0XD0);
L_80193110:
    // 0x80193110: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80193114: beql        $v0, $zero, L_801931BC
    if (ctx->r2 == 0) {
        // 0x80193118: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_801931BC;
    }
    goto skip_2;
    // 0x80193118: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    skip_2:
    // 0x8019311C: beq         $v0, $at, L_8019318C
    if (ctx->r2 == ctx->r1) {
        // 0x80193120: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8019318C;
    }
    // 0x80193120: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80193124: lh          $v0, 0xB8($s3)
    ctx->r2 = MEM_H(ctx->r19, 0XB8);
    // 0x80193128: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8019312C: beql        $v0, $zero, L_801931B8
    if (ctx->r2 == 0) {
        // 0x80193130: sb          $zero, 0xD0($s3)
        MEM_B(0XD0, ctx->r19) = 0;
            goto L_801931B8;
    }
    goto skip_3;
    // 0x80193130: sb          $zero, 0xD0($s3)
    MEM_B(0XD0, ctx->r19) = 0;
    skip_3:
    // 0x80193134: beq         $v0, $at, L_801931B4
    if (ctx->r2 == ctx->r1) {
        // 0x80193138: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_801931B4;
    }
    // 0x80193138: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019313C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80193140: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80193144: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80193148: lwc1        $f14, 0x8($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8019314C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80193150: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80193154: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80193158: jal         0x80077240
    // 0x8019315C: nop

    BonusText_Display(rdram, ctx);
        goto after_14;
    // 0x8019315C: nop

    after_14:
    // 0x80193160: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80193164: addiu       $v1, $v1, 0x1A98
    ctx->r3 = ADD32(ctx->r3, 0X1A98);
    // 0x80193168: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8019316C: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x80193170: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80193174: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x80193178: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8019317C: sw          $t0, 0x7850($at)
    MEM_W(0X7850, ctx->r1) = ctx->r8;
    // 0x80193180: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80193184: b           L_801931B4
    // 0x80193188: sh          $t1, 0xB8($s3)
    MEM_H(0XB8, ctx->r19) = ctx->r9;
        goto L_801931B4;
    // 0x80193188: sh          $t1, 0xB8($s3)
    MEM_H(0XB8, ctx->r19) = ctx->r9;
L_8019318C:
    // 0x8019318C: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80193190: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80193194: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x80193198: lui         $a0, 0x2912
    ctx->r4 = S32(0X2912 << 16);
    // 0x8019319C: ori         $a0, $a0, 0x1007
    ctx->r4 = ctx->r4 | 0X1007;
    // 0x801931A0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801931A4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801931A8: addiu       $a1, $s3, 0x100
    ctx->r5 = ADD32(ctx->r19, 0X100);
    // 0x801931AC: jal         0x80019218
    // 0x801931B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_15;
    // 0x801931B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_15:
L_801931B4:
    // 0x801931B4: sb          $zero, 0xD0($s3)
    MEM_B(0XD0, ctx->r19) = 0;
L_801931B8:
    // 0x801931B8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
L_801931BC:
    // 0x801931BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801931C0: lwc1        $f18, 0x8($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X8);
    // 0x801931C4: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x801931C8: lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X4);
    // 0x801931CC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801931D0: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x801931D4: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x801931D8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801931DC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801931E0: jal         0x800A73E4
    // 0x801931E4: nop

    Play_CheckDynaFloorCollision(rdram, ctx);
        goto after_16;
    // 0x801931E4: nop

    after_16:
    // 0x801931E8: beq         $v0, $zero, L_8019321C
    if (ctx->r2 == 0) {
        // 0x801931EC: lwc1        $f10, 0x70($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
            goto L_8019321C;
    }
    // 0x801931EC: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801931F0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x801931F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801931F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801931FC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80193200: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80193204: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80193208: addiu       $a0, $s3, 0x8
    ctx->r4 = ADD32(ctx->r19, 0X8);
    // 0x8019320C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80193210: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80193214: jal         0x8009BC2C
    // 0x80193218: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x80193218: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_17:
L_8019321C:
    // 0x8019321C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80193220: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80193224: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x80193228: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x8019322C: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x80193230: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x80193234: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x80193238: jr          $ra
    // 0x8019323C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8019323C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void Aquas_AqJellyfish_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BC930: addiu       $sp, $sp, -0x190
    ctx->r29 = ADD32(ctx->r29, -0X190);
    // 0x801BC934: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801BC938: sw          $a0, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r4;
    // 0x801BC93C: lw          $t6, 0x190($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X190);
    // 0x801BC940: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x801BC944: addiu       $a0, $a0, 0x3780
    ctx->r4 = ADD32(ctx->r4, 0X3780);
    // 0x801BC948: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x801BC94C: jal         0x8009AA20
    // 0x801BC950: lh          $a1, 0xB6($t6)
    ctx->r5 = MEM_H(ctx->r14, 0XB6);
    Animation_GetFrameData(rdram, ctx);
        goto after_0;
    // 0x801BC950: lh          $a1, 0xB6($t6)
    ctx->r5 = MEM_H(ctx->r14, 0XB6);
    after_0:
    // 0x801BC954: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801BC958: lw          $t9, -0x4438($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4438);
    // 0x801BC95C: lw          $t8, 0x190($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X190);
    // 0x801BC960: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801BC964: addiu       $t7, $t7, -0x36E4
    ctx->r15 = ADD32(ctx->r15, -0X36E4);
    // 0x801BC968: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x801BC96C: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x801BC970: addiu       $a3, $a3, -0x3AD0
    ctx->r7 = ADD32(ctx->r7, -0X3AD0);
    // 0x801BC974: addiu       $a1, $a1, 0x390C
    ctx->r5 = ADD32(ctx->r5, 0X390C);
    // 0x801BC978: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801BC97C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801BC980: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x801BC984: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801BC988: jal         0x8009A72C
    // 0x801BC98C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_1;
    // 0x801BC98C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_1:
    // 0x801BC990: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801BC994: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
    // 0x801BC998: jr          $ra
    // 0x801BC99C: nop

    return;
    // 0x801BC99C: nop

;}
RECOMP_FUNC void Zoness_Effect394_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801937D8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801937DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801937E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801937E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801937E8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801937EC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x801937F0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x801937F4: jal         0x80061474
    // 0x801937F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x801937F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801937FC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80193800: lwc1        $f4, 0xF38($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XF38);
    // 0x80193804: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80193808: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019380C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80193810: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80193814: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80193818: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019381C: jal         0x80005E90
    // 0x80193820: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x80193820: nop

    after_1:
    // 0x80193824: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80193828: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8019382C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80193830: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80193834: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80193838: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8019383C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x80193840: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80193844: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80193848: jal         0x80006970
    // 0x8019384C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x8019384C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80193850: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80193854: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80193858: addiu       $t7, $zero, 0x18A
    ctx->r15 = ADD32(0, 0X18A);
    // 0x8019385C: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
    // 0x80193860: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80193864: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80193868: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019386C: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x80193870: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80193874: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80193878: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8019387C: swc1        $f4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
    // 0x80193880: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80193884: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80193888: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8019388C: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80193890: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80193894: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80193898: sh          $t8, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r24;
    // 0x8019389C: swc1        $f16, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f16.u32l;
    // 0x801938A0: jal         0x80004EB0
    // 0x801938A4: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x801938A4: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    after_3:
    // 0x801938A8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801938AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801938B0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801938B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801938B8: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x801938BC: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x801938C0: addiu       $t0, $zero, 0xE
    ctx->r8 = ADD32(0, 0XE);
    // 0x801938C4: sh          $t9, 0x78($s0)
    MEM_H(0X78, ctx->r16) = ctx->r25;
    // 0x801938C8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801938CC: sh          $t0, 0x7A($s0)
    MEM_H(0X7A, ctx->r16) = ctx->r8;
    // 0x801938D0: jal         0x80004EB0
    // 0x801938D4: swc1        $f8, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x801938D4: swc1        $f8, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x801938D8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x801938DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801938E0: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x801938E4: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x801938E8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801938EC: jal         0x800612B8
    // 0x801938F0: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_5;
    // 0x801938F0: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    after_5:
    // 0x801938F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801938F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801938FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80193900: jr          $ra
    // 0x80193904: nop

    return;
    // 0x80193904: nop

;}
RECOMP_FUNC void Solar_801A0CEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A0CEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801A0CF0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801A0CF4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801A0CF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801A0CFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801A0D00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801A0D04: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801A0D08: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801A0D0C: jal         0x800613C4
    // 0x801A0D10: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x801A0D10: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x801A0D14: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801A0D18: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x801A0D1C: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801A0D20: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801A0D24: addiu       $t7, $zero, 0x116
    ctx->r15 = ADD32(0, 0X116);
    // 0x801A0D28: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x801A0D2C: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x801A0D30: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801A0D34: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801A0D38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A0D3C: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x801A0D40: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801A0D44: sh          $t8, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r24;
    // 0x801A0D48: sh          $v0, 0xB8($a2)
    MEM_H(0XB8, ctx->r6) = ctx->r2;
    // 0x801A0D4C: swc1        $f0, 0xF0($a2)
    MEM_W(0XF0, ctx->r6) = ctx->f0.u32l;
    // 0x801A0D50: swc1        $f0, 0x118($a2)
    MEM_W(0X118, ctx->r6) = ctx->f0.u32l;
    // 0x801A0D54: bne         $v0, $at, L_801A0D6C
    if (ctx->r2 != ctx->r1) {
        // 0x801A0D58: swc1        $f6, 0xC($a2)
        MEM_W(0XC, ctx->r6) = ctx->f6.u32l;
            goto L_801A0D6C;
    }
    // 0x801A0D58: swc1        $f6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f6.u32l;
    // 0x801A0D5C: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x801A0D60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A0D64: nop

    // 0x801A0D68: swc1        $f8, 0x114($a2)
    MEM_W(0X114, ctx->r6) = ctx->f8.u32l;
L_801A0D6C:
    // 0x801A0D6C: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    // 0x801A0D70: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x801A0D74: jal         0x800612B8
    // 0x801A0D78: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x801A0D78: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    after_1:
    // 0x801A0D7C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801A0D80: sb          $zero, 0x3C($a2)
    MEM_B(0X3C, ctx->r6) = 0;
    // 0x801A0D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801A0D88: jr          $ra
    // 0x801A0D8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801A0D8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Solar_Effect392_Setup5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019FDE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019FDE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8019FDE8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8019FDEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019FDF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8019FDF4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8019FDF8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8019FDFC: jal         0x80061474
    // 0x8019FE00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8019FE00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8019FE04: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8019FE08: addiu       $t7, $zero, 0x188
    ctx->r15 = ADD32(0, 0X188);
    // 0x8019FE0C: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8019FE10: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8019FE14: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8019FE18: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8019FE1C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8019FE20: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8019FE24: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8019FE28: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8019FE2C: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8019FE30: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8019FE34: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8019FE38: beq         $t8, $zero, L_8019FE5C
    if (ctx->r24 == 0) {
        // 0x8019FE3C: nop
    
            goto L_8019FE5C;
    }
    // 0x8019FE3C: nop

    // 0x8019FE40: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x8019FE44: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8019FE48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019FE4C: lwc1        $f10, 0xC8($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XC8);
    // 0x8019FE50: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019FE54: b           L_8019FE74
    // 0x8019FE58: swc1        $f18, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f18.u32l;
        goto L_8019FE74;
    // 0x8019FE58: swc1        $f18, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f18.u32l;
L_8019FE5C:
    // 0x8019FE5C: lw          $t0, -0x7D80($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D80);
    // 0x8019FE60: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8019FE64: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019FE68: lwc1        $f4, 0xC8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC8);
    // 0x8019FE6C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019FE70: swc1        $f8, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f8.u32l;
L_8019FE74:
    // 0x8019FE74: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8019FE78: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019FE7C: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    // 0x8019FE80: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8019FE84: lwc1        $f16, 0x14($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X14);
    // 0x8019FE88: swc1        $f18, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f18.u32l;
    // 0x8019FE8C: jal         0x80004EB0
    // 0x8019FE90: swc1        $f16, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8019FE90: swc1        $f16, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f16.u32l;
    after_1:
    // 0x8019FE94: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8019FE98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019FE9C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8019FEA0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8019FEA4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8019FEA8: sh          $t2, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r10;
    // 0x8019FEAC: sh          $t3, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r11;
    // 0x8019FEB0: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8019FEB4: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8019FEB8: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x8019FEBC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8019FEC0: addiu       $t5, $t4, 0x5
    ctx->r13 = ADD32(ctx->r12, 0X5);
    // 0x8019FEC4: jal         0x800612B8
    // 0x8019FEC8: sh          $t5, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r13;
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x8019FEC8: sh          $t5, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r13;
    after_2:
    // 0x8019FECC: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x8019FED0: sb          $t6, 0x34($s0)
    MEM_B(0X34, ctx->r16) = ctx->r14;
    // 0x8019FED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019FED8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8019FEDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019FEE0: jr          $ra
    // 0x8019FEE4: nop

    return;
    // 0x8019FEE4: nop

;}
RECOMP_FUNC void Zoness_ZoSearchLight_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019CE58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019CE5C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8019CE60: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8019CE64: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8019CE68: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8019CE6C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8019CE70: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019CE74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019CE78: jal         0x800B8DD0
    // 0x8019CE7C: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8019CE7C: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    after_0:
    // 0x8019CE80: lw          $t6, 0x50($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X50);
    // 0x8019CE84: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019CE88: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8019CE8C: beq         $t6, $zero, L_8019CFA0
    if (ctx->r14 == 0) {
        // 0x8019CE90: lui         $t2, 0x8016
        ctx->r10 = S32(0X8016 << 16);
            goto L_8019CFA0;
    }
    // 0x8019CE90: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8019CE94: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019CE98: lw          $a2, 0x114($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X114);
    // 0x8019CE9C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8019CEA0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019CEA4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019CEA8: jal         0x80005B00
    // 0x8019CEAC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x8019CEAC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_1:
    // 0x8019CEB0: lwc1        $f4, 0x124($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X124);
    // 0x8019CEB4: lwc1        $f6, 0x18($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8019CEB8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CEBC: lwc1        $f10, 0x12CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X12CC);
    // 0x8019CEC0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019CEC4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019CEC8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8019CECC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019CED0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019CED4: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8019CED8: jal         0x80005FE0
    // 0x8019CEDC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8019CEDC: nop

    after_2:
    // 0x8019CEE0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019CEE4: lw          $a1, 0x118($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X118);
    // 0x8019CEE8: lw          $a2, 0x11C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X11C);
    // 0x8019CEEC: lw          $a3, 0x120($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X120);
    // 0x8019CEF0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8019CEF4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8019CEF8: jal         0x80005C34
    // 0x8019CEFC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x8019CEFC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_3:
    // 0x8019CF00: jal         0x80006EB8
    // 0x8019CF04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x8019CF04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8019CF08: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8019CF0C: lbu         $t9, 0x1684($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X1684);
    // 0x8019CF10: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8019CF14: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x8019CF18: beq         $t9, $zero, L_8019CF60
    if (ctx->r25 == 0) {
        // 0x8019CF1C: lui         $t0, 0xFB00
        ctx->r8 = S32(0XFB00 << 16);
            goto L_8019CF60;
    }
    // 0x8019CF1C: lui         $t0, 0xFB00
    ctx->r8 = S32(0XFB00 << 16);
    // 0x8019CF20: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019CF24: lui         $t2, 0xFFBF
    ctx->r10 = S32(0XFFBF << 16);
    // 0x8019CF28: ori         $t2, $t2, 0x2BFF
    ctx->r10 = ctx->r10 | 0X2BFF;
    // 0x8019CF2C: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8019CF30: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8019CF34: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8019CF38: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8019CF3C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019CF40: lui         $t5, 0xFF00
    ctx->r13 = S32(0XFF00 << 16);
    // 0x8019CF44: ori         $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 | 0XFF;
    // 0x8019CF48: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8019CF4C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8019CF50: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8019CF54: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8019CF58: b           L_8019D030
    // 0x8019CF5C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_8019D030;
    // 0x8019CF5C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8019CF60:
    // 0x8019CF60: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019CF64: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8019CF68: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8019CF6C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8019CF70: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8019CF74: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8019CF78: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8019CF7C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019CF80: lui         $t1, 0xFFFF
    ctx->r9 = S32(0XFFFF << 16);
    // 0x8019CF84: ori         $t1, $t1, 0x7FFF
    ctx->r9 = ctx->r9 | 0X7FFF;
    // 0x8019CF88: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8019CF8C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8019CF90: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8019CF94: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8019CF98: b           L_8019D030
    // 0x8019CF9C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_8019D030;
    // 0x8019CF9C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8019CFA0:
    // 0x8019CFA0: lbu         $t2, 0x1684($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X1684);
    // 0x8019CFA4: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x8019CFA8: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x8019CFAC: beq         $t2, $zero, L_8019CFF4
    if (ctx->r10 == 0) {
        // 0x8019CFB0: lui         $t3, 0xFB00
        ctx->r11 = S32(0XFB00 << 16);
            goto L_8019CFF4;
    }
    // 0x8019CFB0: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x8019CFB4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019CFB8: lui         $t5, 0xFFBF
    ctx->r13 = S32(0XFFBF << 16);
    // 0x8019CFBC: ori         $t5, $t5, 0x2B32
    ctx->r13 = ctx->r13 | 0X2B32;
    // 0x8019CFC0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8019CFC4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8019CFC8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8019CFCC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8019CFD0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019CFD4: lui         $t8, 0xFF00
    ctx->r24 = S32(0XFF00 << 16);
    // 0x8019CFD8: ori         $t8, $t8, 0xFF
    ctx->r24 = ctx->r24 | 0XFF;
    // 0x8019CFDC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8019CFE0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8019CFE4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8019CFE8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8019CFEC: b           L_8019D030
    // 0x8019CFF0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_8019D030;
    // 0x8019CFF0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8019CFF4:
    // 0x8019CFF4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019CFF8: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x8019CFFC: addiu       $t1, $zero, -0xCE
    ctx->r9 = ADD32(0, -0XCE);
    // 0x8019D000: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8019D004: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8019D008: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8019D00C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8019D010: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019D014: lui         $t4, 0xFFFF
    ctx->r12 = S32(0XFFFF << 16);
    // 0x8019D018: ori         $t4, $t4, 0x7FFF
    ctx->r12 = ctx->r12 | 0X7FFF;
    // 0x8019D01C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8019D020: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8019D024: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8019D028: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8019D02C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8019D030:
    // 0x8019D030: lui         $t7, 0x602
    ctx->r15 = S32(0X602 << 16);
    // 0x8019D034: addiu       $t7, $t7, -0x7E20
    ctx->r15 = ADD32(ctx->r15, -0X7E20);
    // 0x8019D038: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8019D03C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8019D040: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8019D044: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8019D048: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8019D04C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019D050: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8019D054: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8019D058: jr          $ra
    // 0x8019D05C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8019D05C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Zoness_ZoSpikeBall_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019ACCC: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x8019ACD0: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8019ACD4: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8019ACD8: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8019ACDC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8019ACE0: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x8019ACE4: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8019ACE8: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x8019ACEC: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x8019ACF0: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8019ACF4: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x8019ACF8: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x8019ACFC: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8019AD00: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8019AD04: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8019AD08: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8019AD0C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8019AD10: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8019AD14: jal         0x80005740
    // 0x8019AD18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_0;
    // 0x8019AD18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8019AD1C: jal         0x80005708
    // 0x8019AD20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x8019AD20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8019AD24: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8019AD28: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x8019AD2C: addiu       $s1, $zero, 0x2000
    ctx->r17 = ADD32(0, 0X2000);
    // 0x8019AD30: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8019AD34: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x8019AD38: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019AD3C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8019AD40: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x8019AD44: sw          $s1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r17;
    // 0x8019AD48: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8019AD4C: lh          $a0, -0xEA2($a0)
    ctx->r4 = MEM_H(ctx->r4, -0XEA2);
    // 0x8019AD50: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8019AD54: beq         $a0, $at, L_8019B03C
    if (ctx->r4 == ctx->r1) {
        // 0x8019AD58: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8019B03C;
    }
    // 0x8019AD58: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8019AD5C: beq         $a0, $at, L_8019B03C
    if (ctx->r4 == ctx->r1) {
        // 0x8019AD60: lui         $a1, 0x8018
        ctx->r5 = S32(0X8018 << 16);
            goto L_8019B03C;
    }
    // 0x8019AD60: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8019AD64: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8019AD68: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8019AD6C: lw          $t9, -0x7C24($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7C24);
    // 0x8019AD70: lw          $t8, -0x7C28($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C28);
    // 0x8019AD74: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019AD78: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8019AD7C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8019AD80: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8019AD84: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8019AD88: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8019AD8C: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8019AD90: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8019AD94: jal         0x800B9B38
    // 0x8019AD98: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    RCP_SetupDL_60(rdram, ctx);
        goto after_2;
    // 0x8019AD98: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_2:
    // 0x8019AD9C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019ADA0: addiu       $a0, $a0, 0x24E8
    ctx->r4 = ADD32(ctx->r4, 0X24E8);
    // 0x8019ADA4: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8019ADA8: lui         $t1, 0xB600
    ctx->r9 = S32(0XB600 << 16);
    // 0x8019ADAC: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x8019ADB0: sw          $t0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r8;
    // 0x8019ADB4: sw          $s1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r17;
    // 0x8019ADB8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8019ADBC: lwc1        $f4, 0x104($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X104);
    // 0x8019ADC0: lwc1        $f6, 0x4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8019ADC4: lwc1        $f16, 0x10C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x8019ADC8: lwc1        $f18, 0xC($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8019ADCC: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019ADD0: lwc1        $f8, 0x108($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X108);
    // 0x8019ADD4: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8019ADD8: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8019ADDC: mul.s       $f22, $f12, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f22.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8019ADE0: sub.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8019ADE4: mul.s       $f24, $f14, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f24.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8019ADE8: nop

    // 0x8019ADEC: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8019ADF0: add.s       $f6, $f22, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f22.fl + ctx->f4.fl;
    // 0x8019ADF4: add.s       $f0, $f6, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8019ADF8: jal         0x80005100
    // 0x8019ADFC: sqrt.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_3;
    // 0x8019ADFC: sqrt.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = sqrtf(ctx->f0.fl);
    after_3:
    // 0x8019AE00: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x8019AE04: add.s       $f0, $f22, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f22.fl + ctx->f24.fl;
    // 0x8019AE08: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8019AE0C: jal         0x80005100
    // 0x8019AE10: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_4;
    // 0x8019AE10: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_4:
    // 0x8019AE14: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8019AE18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019AE1C: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
    // 0x8019AE20: div.s       $f10, $f26, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f26.fl, ctx->f8.fl);
    // 0x8019AE24: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8019AE28: mfc1        $s4, $f16
    ctx->r20 = (int32_t)ctx->f16.u32l;
    // 0x8019AE2C: nop

    // 0x8019AE30: slti        $at, $s4, 0x33
    ctx->r1 = SIGNED(ctx->r20) < 0X33 ? 1 : 0;
    // 0x8019AE34: bne         $at, $zero, L_8019AE40
    if (ctx->r1 != 0) {
        // 0x8019AE38: nop
    
            goto L_8019AE40;
    }
    // 0x8019AE38: nop

    // 0x8019AE3C: addiu       $s4, $zero, 0x32
    ctx->r20 = ADD32(0, 0X32);
L_8019AE40:
    // 0x8019AE40: bgez        $s4, L_8019AE4C
    if (SIGNED(ctx->r20) >= 0) {
        // 0x8019AE44: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_8019AE4C;
    }
    // 0x8019AE44: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019AE48: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8019AE4C:
    // 0x8019AE4C: lwc1        $f18, 0xC($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8019AE50: lwc1        $f4, 0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8019AE54: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x8019AE58: lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X8);
    // 0x8019AE5C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019AE60: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8019AE64: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8019AE68: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019AE6C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8019AE70: jal         0x80005B00
    // 0x8019AE74: nop

    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x8019AE74: nop

    after_5:
    // 0x8019AE78: mfc1        $a1, $f28
    ctx->r5 = (int32_t)ctx->f28.u32l;
    // 0x8019AE7C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019AE80: jal         0x80005E90
    // 0x8019AE84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x8019AE84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x8019AE88: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8019AE8C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019AE90: jal         0x80005D44
    // 0x8019AE94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x8019AE94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x8019AE98: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x8019AE9C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8019AEA0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8019AEA4: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x8019AEA8: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8019AEAC: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8019AEB0: jal         0x80005B00
    // 0x8019AEB4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_8;
    // 0x8019AEB4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x8019AEB8: mtc1        $s4, $f10
    ctx->f10.u32l = ctx->r20;
    // 0x8019AEBC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019AEC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019AEC4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8019AEC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019AECC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019AED0: lui         $t5, 0x602
    ctx->r13 = S32(0X602 << 16);
    // 0x8019AED4: addiu       $t5, $t5, -0x79A0
    ctx->r13 = ADD32(ctx->r13, -0X79A0);
    // 0x8019AED8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019AEDC: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8019AEE0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8019AEE4: blez        $s4, L_8019B03C
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8019AEE8: add.s       $f0, $f18, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
            goto L_8019B03C;
    }
    // 0x8019AEE8: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019AEEC: lwc1        $f28, 0x1240($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X1240);
    // 0x8019AEF0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8019AEF4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8019AEF8: sw          $t5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r13;
    // 0x8019AEFC: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
L_8019AF00:
    // 0x8019AF00: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x8019AF04: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8019AF08: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8019AF0C: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8019AF10: nop

    // 0x8019AF14: mul.s       $f20, $f8, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = MUL_S(ctx->f8.fl, ctx->f28.fl);
    // 0x8019AF18: jal         0x80023090
    // 0x8019AF1C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __sinf_recomp(rdram, ctx);
        goto after_9;
    // 0x8019AF1C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_9:
    // 0x8019AF20: lwc1        $f16, 0x128($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X128);
    // 0x8019AF24: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8019AF28: mul.s       $f22, $f16, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8019AF2C: jal         0x80023250
    // 0x8019AF30: nop

    __cosf_recomp(rdram, ctx);
        goto after_10;
    // 0x8019AF30: nop

    after_10:
    // 0x8019AF34: lwc1        $f18, 0x128($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X128);
    // 0x8019AF38: lui         $at, 0xBE80
    ctx->r1 = S32(0XBE80 << 16);
    // 0x8019AF3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019AF40: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8019AF44: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x8019AF48: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8019AF4C: lw          $a3, 0x118($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X118);
    // 0x8019AF50: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8019AF54: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8019AF58: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019AF5C: mul.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019AF60: jal         0x80005B00
    // 0x8019AF64: nop

    Matrix_Translate(rdram, ctx);
        goto after_11;
    // 0x8019AF64: nop

    after_11:
    // 0x8019AF68: jal         0x80005708
    // 0x8019AF6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_12;
    // 0x8019AF6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8019AF70: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x8019AF74: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8019AF78: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8019AF7C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8019AF80: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8019AF84: jal         0x80005B00
    // 0x8019AF88: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_13;
    // 0x8019AF88: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_13:
    // 0x8019AF8C: mul.s       $f10, $f28, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f20.fl);
    // 0x8019AF90: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019AF94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019AF98: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8019AF9C: jal         0x80005D44
    // 0x8019AFA0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_14;
    // 0x8019AFA0: nop

    after_14:
    // 0x8019AFA4: jal         0x80005708
    // 0x8019AFA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_15;
    // 0x8019AFA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8019AFAC: mul.s       $f8, $f28, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f30.fl);
    // 0x8019AFB0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019AFB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019AFB8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019AFBC: jal         0x80005FE0
    // 0x8019AFC0: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_16;
    // 0x8019AFC0: nop

    after_16:
    // 0x8019AFC4: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x8019AFC8: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8019AFCC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019AFD0: jal         0x80005D44
    // 0x8019AFD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_17;
    // 0x8019AFD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
    // 0x8019AFD8: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x8019AFDC: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x8019AFE0: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x8019AFE4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8019AFE8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8019AFEC: jal         0x80005C34
    // 0x8019AFF0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_18;
    // 0x8019AFF0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_18:
    // 0x8019AFF4: jal         0x80006EB8
    // 0x8019AFF8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_19;
    // 0x8019AFF8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_19:
    // 0x8019AFFC: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8019B000: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8019B004: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8019B008: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x8019B00C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8019B010: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x8019B014: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8019B018: jal         0x80005740
    // 0x8019B01C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_20;
    // 0x8019B01C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8019B020: jal         0x80005740
    // 0x8019B024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_21;
    // 0x8019B024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8019B028: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8019B02C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019B030: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8019B034: bne         $s1, $s4, L_8019AF00
    if (ctx->r17 != ctx->r20) {
        // 0x8019B038: add.s       $f30, $f30, $f16
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f30.fl = ctx->f30.fl + ctx->f16.fl;
            goto L_8019AF00;
    }
    // 0x8019B038: add.s       $f30, $f30, $f16
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f30.fl = ctx->f30.fl + ctx->f16.fl;
L_8019B03C:
    // 0x8019B03C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019B040: lwc1        $f28, 0x1244($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X1244);
    // 0x8019B044: jal         0x80005740
    // 0x8019B048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_22;
    // 0x8019B048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8019B04C: jal         0x80005708
    // 0x8019B050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_23;
    // 0x8019B050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x8019B054: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019B058: lwc1        $f4, 0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8019B05C: lwc1        $f18, 0xC($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8019B060: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x8019B064: lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X8);
    // 0x8019B068: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019B06C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8019B070: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8019B074: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019B078: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8019B07C: jal         0x80005B00
    // 0x8019B080: nop

    Matrix_Translate(rdram, ctx);
        goto after_24;
    // 0x8019B080: nop

    after_24:
    // 0x8019B084: lwc1        $f10, 0x14($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8019B088: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019B08C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019B090: mul.s       $f8, $f10, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f28.fl);
    // 0x8019B094: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019B098: jal         0x80005E90
    // 0x8019B09C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_25;
    // 0x8019B09C: nop

    after_25:
    // 0x8019B0A0: lwc1        $f16, 0x10($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8019B0A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019B0A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019B0AC: mul.s       $f18, $f16, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f28.fl);
    // 0x8019B0B0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8019B0B4: jal         0x80005D44
    // 0x8019B0B8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_26;
    // 0x8019B0B8: nop

    after_26:
    // 0x8019B0BC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019B0C0: lwc1        $f0, 0x1248($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X1248);
    // 0x8019B0C4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8019B0C8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8019B0CC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019B0D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019B0D4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019B0D8: jal         0x80005C34
    // 0x8019B0DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_27;
    // 0x8019B0DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_27:
    // 0x8019B0E0: jal         0x80006EB8
    // 0x8019B0E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_28;
    // 0x8019B0E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_28:
    // 0x8019B0E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8019B0EC: jal         0x800B8DD0
    // 0x8019B0F0: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    RCP_SetupDL(rdram, ctx);
        goto after_29;
    // 0x8019B0F0: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    after_29:
    // 0x8019B0F4: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8019B0F8: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8019B0FC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8019B100: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8019B104: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x8019B108: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8019B10C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8019B110: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8019B114: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8019B118: addiu       $t9, $t9, 0x4380
    ctx->r25 = ADD32(ctx->r25, 0X4380);
    // 0x8019B11C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8019B120: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x8019B124: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8019B128: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8019B12C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8019B130: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019B134: lwc1        $f4, 0x2534($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2534);
    // 0x8019B138: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019B13C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019B140: mul.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x8019B144: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8019B148: jal         0x80005E90
    // 0x8019B14C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_30;
    // 0x8019B14C: nop

    after_30:
    // 0x8019B150: lwc1        $f10, 0x11C($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X11C);
    // 0x8019B154: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019B158: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019B15C: mul.s       $f8, $f10, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f28.fl);
    // 0x8019B160: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019B164: jal         0x80005D44
    // 0x8019B168: nop

    Matrix_RotateX(rdram, ctx);
        goto after_31;
    // 0x8019B168: nop

    after_31:
    // 0x8019B16C: lwc1        $f16, 0x120($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X120);
    // 0x8019B170: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019B174: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019B178: mul.s       $f18, $f16, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f28.fl);
    // 0x8019B17C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8019B180: jal         0x80005FE0
    // 0x8019B184: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_32;
    // 0x8019B184: nop

    after_32:
    // 0x8019B188: jal         0x80006EB8
    // 0x8019B18C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_33;
    // 0x8019B18C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_33:
    // 0x8019B190: jal         0x800B9E80
    // 0x8019B194: nop

    RCP_SetupDL_55(rdram, ctx);
        goto after_34;
    // 0x8019B194: nop

    after_34:
    // 0x8019B198: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8019B19C: lui         $t2, 0x602
    ctx->r10 = S32(0X602 << 16);
    // 0x8019B1A0: addiu       $t2, $t2, -0x4340
    ctx->r10 = ADD32(ctx->r10, -0X4340);
    // 0x8019B1A4: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x8019B1A8: sw          $t0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r8;
    // 0x8019B1AC: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8019B1B0: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8019B1B4: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8019B1B8: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8019B1BC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8019B1C0: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8019B1C4: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8019B1C8: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8019B1CC: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x8019B1D0: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x8019B1D4: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8019B1D8: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8019B1DC: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8019B1E0: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x8019B1E4: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x8019B1E8: jr          $ra
    // 0x8019B1EC: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x8019B1EC: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void Aquas_AqPearl_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B0EC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801B0EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801B0EC8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801B0ECC: lhu         $t6, 0xBC($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0XBC);
    // 0x801B0ED0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B0ED4: bnel        $t6, $zero, L_801B0F7C
    if (ctx->r14 != 0) {
        // 0x801B0ED8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801B0F7C;
    }
    goto skip_0;
    // 0x801B0ED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801B0EDC: lwc1        $f12, 0x1CC8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X1CC8);
    // 0x801B0EE0: jal         0x8005980C
    // 0x801B0EE4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x801B0EE4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x801B0EE8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801B0EEC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801B0EF0: jal         0x800B8DD0
    // 0x801B0EF4: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x801B0EF4: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    after_1:
    // 0x801B0EF8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801B0EFC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801B0F00: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801B0F04: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801B0F08: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x801B0F0C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801B0F10: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801B0F14: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801B0F18: lw          $t9, 0x5C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X5C);
    // 0x801B0F1C: lw          $t6, 0x58($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X58);
    // 0x801B0F20: lw          $t3, 0x54($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X54);
    // 0x801B0F24: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x801B0F28: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x801B0F2C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x801B0F30: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x801B0F34: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x801B0F38: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x801B0F3C: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x801B0F40: ori         $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 | 0XFF;
    // 0x801B0F44: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x801B0F48: jal         0x80006EB8
    // 0x801B0F4C: nop

    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x801B0F4C: nop

    after_2:
    // 0x801B0F50: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801B0F54: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801B0F58: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801B0F5C: lui         $t1, 0x602
    ctx->r9 = S32(0X602 << 16);
    // 0x801B0F60: addiu       $t1, $t1, 0x4A50
    ctx->r9 = ADD32(ctx->r9, 0X4A50);
    // 0x801B0F64: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x801B0F68: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x801B0F6C: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x801B0F70: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x801B0F74: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x801B0F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801B0F7C:
    // 0x801B0F7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801B0F80: jr          $ra
    // 0x801B0F84: nop

    return;
    // 0x801B0F84: nop

;}
RECOMP_FUNC void Aquas_AqOyster_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BE3F8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801BE3FC: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x801BE400: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801BE404: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801BE408: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x801BE40C: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x801BE410: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x801BE414: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x801BE418: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x801BE41C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801BE420: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801BE424: lh          $v1, 0xB8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XB8);
    // 0x801BE428: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x801BE42C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801BE430: beq         $v1, $zero, L_801BE47C
    if (ctx->r3 == 0) {
        // 0x801BE434: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801BE47C;
    }
    // 0x801BE434: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801BE438: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801BE43C: beq         $v0, $at, L_801BE4CC
    if (ctx->r2 == ctx->r1) {
        // 0x801BE440: lui         $s0, 0x8018
        ctx->r16 = S32(0X8018 << 16);
            goto L_801BE4CC;
    }
    // 0x801BE440: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x801BE444: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801BE448: beq         $v0, $at, L_801BE614
    if (ctx->r2 == ctx->r1) {
        // 0x801BE44C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801BE614;
    }
    // 0x801BE44C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801BE450: beq         $v0, $at, L_801BE8E4
    if (ctx->r2 == ctx->r1) {
        // 0x801BE454: lui         $at, 0x428C
        ctx->r1 = S32(0X428C << 16);
            goto L_801BE8E4;
    }
    // 0x801BE454: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801BE458: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x801BE45C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801BE460: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x801BE464: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801BE468: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801BE46C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801BE470: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801BE474: b           L_801BE90C
    // 0x801BE478: lb          $t6, 0xD0($s1)
    ctx->r14 = MEM_B(ctx->r17, 0XD0);
        goto L_801BE90C;
    // 0x801BE478: lb          $t6, 0xD0($s1)
    ctx->r14 = MEM_B(ctx->r17, 0XD0);
L_801BE47C:
    // 0x801BE47C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801BE480: sh          $t6, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = ctx->r14;
    // 0x801BE484: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801BE488: swc1        $f4, 0x114($s1)
    MEM_W(0X114, ctx->r17) = ctx->f4.u32l;
    // 0x801BE48C: lwc1        $f6, 0x222C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X222C);
    // 0x801BE490: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801BE494: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x801BE498: swc1        $f6, 0x118($s1)
    MEM_W(0X118, ctx->r17) = ctx->f6.u32l;
    // 0x801BE49C: lwc1        $f8, 0x2230($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X2230);
    // 0x801BE4A0: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801BE4A4: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x801BE4A8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801BE4AC: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x801BE4B0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801BE4B4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801BE4B8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801BE4BC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801BE4C0: sh          $t7, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r15;
    // 0x801BE4C4: b           L_801BE908
    // 0x801BE4C8: swc1        $f8, 0x11C($s1)
    MEM_W(0X11C, ctx->r17) = ctx->f8.u32l;
        goto L_801BE908;
    // 0x801BE4C8: swc1        $f8, 0x11C($s1)
    MEM_W(0X11C, ctx->r17) = ctx->f8.u32l;
L_801BE4CC:
    // 0x801BE4CC: addiu       $s0, $s0, -0x7D80
    ctx->r16 = ADD32(ctx->r16, -0X7D80);
    // 0x801BE4D0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801BE4D4: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801BE4D8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801BE4DC: lwc1        $f10, 0x7C($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X7C);
    // 0x801BE4E0: lwc1        $f18, 0x2234($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X2234);
    // 0x801BE4E4: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x801BE4E8: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801BE4EC: addiu       $v0, $v0, 0x14E4
    ctx->r2 = ADD32(ctx->r2, 0X14E4);
    // 0x801BE4F0: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x801BE4F4: srl         $t0, $t9, 28
    ctx->r8 = S32(U32(ctx->r25) >> 28);
    // 0x801BE4F8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801BE4FC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801BE500: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x801BE504: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x801BE508: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x801BE50C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801BE510: bc1f        L_801BE5EC
    if (!c1cs) {
        // 0x801BE514: ori         $at, $at, 0xFFFF
        ctx->r1 = ctx->r1 | 0XFFFF;
            goto L_801BE5EC;
    }
    // 0x801BE514: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x801BE518: lw          $t2, 0x1FD0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1FD0);
    // 0x801BE51C: and         $t3, $v0, $at
    ctx->r11 = ctx->r2 & ctx->r1;
    // 0x801BE520: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801BE524: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x801BE528: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x801BE52C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801BE530: sw          $t5, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r13;
    // 0x801BE534: sb          $zero, 0x34($s1)
    MEM_B(0X34, ctx->r17) = 0;
    // 0x801BE538: jal         0x80004EB0
    // 0x801BE53C: sb          $t6, 0x3C($s1)
    MEM_B(0X3C, ctx->r17) = ctx->r14;
    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x801BE53C: sb          $t6, 0x3C($s1)
    MEM_B(0X3C, ctx->r17) = ctx->r14;
    after_0:
    // 0x801BE540: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801BE544: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801BE548: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801BE54C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801BE550: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801BE554: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801BE558: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801BE55C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801BE560: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801BE564: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801BE568: nop

    // 0x801BE56C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801BE570: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801BE574: nop

    // 0x801BE578: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801BE57C: beql        $t8, $zero, L_801BE5CC
    if (ctx->r24 == 0) {
        // 0x801BE580: mfc1        $t8, $f16
        ctx->r24 = (int32_t)ctx->f16.u32l;
            goto L_801BE5CC;
    }
    goto skip_0;
    // 0x801BE580: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x801BE584: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801BE588: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801BE58C: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801BE590: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x801BE594: nop

    // 0x801BE598: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801BE59C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x801BE5A0: nop

    // 0x801BE5A4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x801BE5A8: bne         $t8, $zero, L_801BE5C0
    if (ctx->r24 != 0) {
        // 0x801BE5AC: nop
    
            goto L_801BE5C0;
    }
    // 0x801BE5AC: nop

    // 0x801BE5B0: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x801BE5B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801BE5B8: b           L_801BE5D8
    // 0x801BE5BC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_801BE5D8;
    // 0x801BE5BC: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_801BE5C0:
    // 0x801BE5C0: b           L_801BE5D8
    // 0x801BE5C4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_801BE5D8;
    // 0x801BE5C4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801BE5C8: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
L_801BE5CC:
    // 0x801BE5CC: nop

    // 0x801BE5D0: bltz        $t8, L_801BE5C0
    if (SIGNED(ctx->r24) < 0) {
        // 0x801BE5D4: nop
    
            goto L_801BE5C0;
    }
    // 0x801BE5D4: nop

L_801BE5D8:
    // 0x801BE5D8: lh          $t9, 0xB8($s1)
    ctx->r25 = MEM_H(ctx->r17, 0XB8);
    // 0x801BE5DC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801BE5E0: sh          $t8, 0xBC($s1)
    MEM_H(0XBC, ctx->r17) = ctx->r24;
    // 0x801BE5E4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x801BE5E8: sh          $t0, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r8;
L_801BE5EC:
    // 0x801BE5EC: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801BE5F0: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x801BE5F4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801BE5F8: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x801BE5FC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801BE600: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801BE604: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801BE608: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801BE60C: b           L_801BE90C
    // 0x801BE610: lb          $t6, 0xD0($s1)
    ctx->r14 = MEM_B(ctx->r17, 0XD0);
        goto L_801BE90C;
    // 0x801BE610: lb          $t6, 0xD0($s1)
    ctx->r14 = MEM_B(ctx->r17, 0XD0);
L_801BE614:
    // 0x801BE614: lh          $t1, 0xB6($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XB6);
    // 0x801BE618: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801BE61C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801BE620: sh          $t2, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r10;
    // 0x801BE624: lh          $v0, 0xB6($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XB6);
    // 0x801BE628: bne         $v0, $at, L_801BE6C4
    if (ctx->r2 != ctx->r1) {
        // 0x801BE62C: lui         $at, 0x428C
        ctx->r1 = S32(0X428C << 16);
            goto L_801BE6C4;
    }
    // 0x801BE62C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801BE630: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x801BE634: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801BE638: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x801BE63C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801BE640: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801BE644: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801BE648: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801BE64C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801BE650:
    // 0x801BE650: jal         0x80004EB0
    // 0x801BE654: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x801BE654: nop

    after_1:
    // 0x801BE658: jal         0x80004EB0
    // 0x801BE65C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x801BE65C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_2:
    // 0x801BE660: sub.s       $f18, $f20, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f20.fl - ctx->f26.fl;
    // 0x801BE664: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801BE668: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801BE66C: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801BE670: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x801BE674: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801BE678: sub.s       $f18, $f0, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x801BE67C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801BE680: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x801BE684: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801BE688: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801BE68C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801BE690: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801BE694: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801BE698: mul.s       $f4, $f18, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f30.fl);
    // 0x801BE69C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801BE6A0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801BE6A4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801BE6A8: jal         0x801AC8A8
    // 0x801BE6AC: add.s       $f14, $f4, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f16.fl;
    Aquas_Bubble_Spawn(rdram, ctx);
        goto after_3;
    // 0x801BE6AC: add.s       $f14, $f4, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f16.fl;
    after_3:
    // 0x801BE6B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801BE6B4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801BE6B8: bne         $s0, $at, L_801BE650
    if (ctx->r16 != ctx->r1) {
        // 0x801BE6BC: nop
    
            goto L_801BE650;
    }
    // 0x801BE6BC: nop

    // 0x801BE6C0: lh          $v0, 0xB6($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XB6);
L_801BE6C4:
    // 0x801BE6C4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801BE6C8: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801BE6CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801BE6D0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801BE6D4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801BE6D8: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x801BE6DC: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801BE6E0: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x801BE6E4: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x801BE6E8: bne         $v0, $at, L_801BE8A0
    if (ctx->r2 != ctx->r1) {
        // 0x801BE6EC: nop
    
            goto L_801BE8A0;
    }
    // 0x801BE6EC: nop

    // 0x801BE6F0: lh          $t4, 0xCE($s1)
    ctx->r12 = MEM_H(ctx->r17, 0XCE);
    // 0x801BE6F4: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x801BE6F8: addiu       $s0, $s0, -0x7D80
    ctx->r16 = ADD32(ctx->r16, -0X7D80);
    // 0x801BE6FC: beq         $t4, $zero, L_801BE8A0
    if (ctx->r12 == 0) {
        // 0x801BE700: addiu       $t5, $zero, 0x11
        ctx->r13 = ADD32(0, 0X11);
            goto L_801BE8A0;
    }
    // 0x801BE700: addiu       $t5, $zero, 0x11
    ctx->r13 = ADD32(0, 0X11);
    // 0x801BE704: sh          $t5, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r13;
    // 0x801BE708: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801BE70C: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801BE710: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801BE714: lwc1        $f4, 0x138($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X138);
    // 0x801BE718: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801BE71C: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801BE720: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801BE724: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x801BE728: nop

    // 0x801BE72C: bc1f        L_801BE8A0
    if (!c1cs) {
        // 0x801BE730: nop
    
            goto L_801BE8A0;
    }
    // 0x801BE730: nop

    // 0x801BE734: lhu         $v0, 0xBC($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XBC);
    // 0x801BE738: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x801BE73C: beq         $at, $zero, L_801BE8A0
    if (ctx->r1 == 0) {
        // 0x801BE740: andi        $t7, $v0, 0x3
        ctx->r15 = ctx->r2 & 0X3;
            goto L_801BE8A0;
    }
    // 0x801BE740: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x801BE744: bne         $t7, $zero, L_801BE8A0
    if (ctx->r15 != 0) {
        // 0x801BE748: nop
    
            goto L_801BE8A0;
    }
    // 0x801BE748: nop

    // 0x801BE74C: jal         0x80004EB0
    // 0x801BE750: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x801BE750: nop

    after_4:
    // 0x801BE754: sub.s       $f6, $f0, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x801BE758: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801BE75C: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801BE760: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x801BE764: lwc1        $f10, 0x74($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X74);
    // 0x801BE768: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801BE76C: jal         0x80004EB0
    // 0x801BE770: sub.s       $f20, $f18, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f18.fl - ctx->f4.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x801BE770: sub.s       $f20, $f18, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f18.fl - ctx->f4.fl;
    after_5:
    // 0x801BE774: sub.s       $f16, $f0, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x801BE778: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801BE77C: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801BE780: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x801BE784: mul.s       $f6, $f16, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x801BE788: lwc1        $f8, 0x78($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X78);
    // 0x801BE78C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801BE790: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x801BE794: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x801BE798: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801BE79C: lwc1        $f16, 0x138($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X138);
    // 0x801BE7A0: sub.s       $f22, $f16, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x801BE7A4: jal         0x80005100
    // 0x801BE7A8: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    Math_Atan2F(rdram, ctx);
        goto after_6;
    // 0x801BE7A8: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_6:
    // 0x801BE7AC: jal         0x8009F768
    // 0x801BE7B0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_7;
    // 0x801BE7B0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_7:
    // 0x801BE7B4: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x801BE7B8: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x801BE7BC: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801BE7C0: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x801BE7C4: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801BE7C8: jal         0x80005100
    // 0x801BE7CC: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_8;
    // 0x801BE7CC: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_8:
    // 0x801BE7D0: jal         0x8009F768
    // 0x801BE7D4: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_9;
    // 0x801BE7D4: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_9:
    // 0x801BE7D8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801BE7DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801BE7E0: jal         0x801BE274
    // 0x801BE7E4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    Aquas_801BE274(rdram, ctx);
        goto after_10;
    // 0x801BE7E4: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_10:
    // 0x801BE7E8: lhu         $t9, 0xBC($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0XBC);
    // 0x801BE7EC: bne         $t9, $zero, L_801BE8A0
    if (ctx->r25 != 0) {
        // 0x801BE7F0: nop
    
            goto L_801BE8A0;
    }
    // 0x801BE7F0: nop

    // 0x801BE7F4: jal         0x80004EB0
    // 0x801BE7F8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_11;
    // 0x801BE7F8: nop

    after_11:
    // 0x801BE7FC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801BE800: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801BE804: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801BE808: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801BE80C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801BE810: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801BE814: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801BE818: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x801BE81C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x801BE820: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801BE824: nop

    // 0x801BE828: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801BE82C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801BE830: nop

    // 0x801BE834: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801BE838: beql        $t1, $zero, L_801BE888
    if (ctx->r9 == 0) {
        // 0x801BE83C: mfc1        $t1, $f8
        ctx->r9 = (int32_t)ctx->f8.u32l;
            goto L_801BE888;
    }
    goto skip_1;
    // 0x801BE83C: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x801BE840: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801BE844: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801BE848: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801BE84C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801BE850: nop

    // 0x801BE854: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801BE858: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801BE85C: nop

    // 0x801BE860: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801BE864: bne         $t1, $zero, L_801BE87C
    if (ctx->r9 != 0) {
        // 0x801BE868: nop
    
            goto L_801BE87C;
    }
    // 0x801BE868: nop

    // 0x801BE86C: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x801BE870: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801BE874: b           L_801BE894
    // 0x801BE878: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_801BE894;
    // 0x801BE878: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_801BE87C:
    // 0x801BE87C: b           L_801BE894
    // 0x801BE880: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_801BE894;
    // 0x801BE880: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801BE884: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
L_801BE888:
    // 0x801BE888: nop

    // 0x801BE88C: bltz        $t1, L_801BE87C
    if (SIGNED(ctx->r9) < 0) {
        // 0x801BE890: nop
    
            goto L_801BE87C;
    }
    // 0x801BE890: nop

L_801BE894:
    // 0x801BE894: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x801BE898: sh          $t1, 0xBC($s1)
    MEM_H(0XBC, ctx->r17) = ctx->r9;
    // 0x801BE89C: nop

L_801BE8A0:
    // 0x801BE8A0: lui         $s0, 0x602
    ctx->r16 = S32(0X602 << 16);
    // 0x801BE8A4: addiu       $s0, $s0, 0x201C
    ctx->r16 = ADD32(ctx->r16, 0X201C);
    // 0x801BE8A8: jal         0x8009ACDC
    // 0x801BE8AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Animation_GetFrameCount(rdram, ctx);
        goto after_12;
    // 0x801BE8AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x801BE8B0: lh          $t2, 0xB6($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XB6);
    // 0x801BE8B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801BE8B8: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801BE8BC: bnel        $at, $zero, L_801BE90C
    if (ctx->r1 != 0) {
        // 0x801BE8C0: lb          $t6, 0xD0($s1)
        ctx->r14 = MEM_B(ctx->r17, 0XD0);
            goto L_801BE90C;
    }
    goto skip_2;
    // 0x801BE8C0: lb          $t6, 0xD0($s1)
    ctx->r14 = MEM_B(ctx->r17, 0XD0);
    skip_2:
    // 0x801BE8C4: jal         0x8009ACDC
    // 0x801BE8C8: sb          $zero, 0x3C($s1)
    MEM_B(0X3C, ctx->r17) = 0;
    Animation_GetFrameCount(rdram, ctx);
        goto after_13;
    // 0x801BE8C8: sb          $zero, 0x3C($s1)
    MEM_B(0X3C, ctx->r17) = 0;
    after_13:
    // 0x801BE8CC: lh          $t4, 0xB8($s1)
    ctx->r12 = MEM_H(ctx->r17, 0XB8);
    // 0x801BE8D0: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x801BE8D4: sh          $t3, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r11;
    // 0x801BE8D8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x801BE8DC: b           L_801BE908
    // 0x801BE8E0: sh          $t5, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r13;
        goto L_801BE908;
    // 0x801BE8E0: sh          $t5, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r13;
L_801BE8E4:
    // 0x801BE8E4: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801BE8E8: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x801BE8EC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801BE8F0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x801BE8F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801BE8F8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801BE8FC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801BE900: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801BE904: nop

L_801BE908:
    // 0x801BE908: lb          $t6, 0xD0($s1)
    ctx->r14 = MEM_B(ctx->r17, 0XD0);
L_801BE90C:
    // 0x801BE90C: beql        $t6, $zero, L_801BEAF4
    if (ctx->r14 == 0) {
        // 0x801BE910: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801BEAF4;
    }
    goto skip_3;
    // 0x801BE910: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_3:
    // 0x801BE914: lh          $v0, 0xCE($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XCE);
    // 0x801BE918: sb          $zero, 0xD0($s1)
    MEM_B(0XD0, ctx->r17) = 0;
    // 0x801BE91C: beql        $v0, $zero, L_801BEAF4
    if (ctx->r2 == 0) {
        // 0x801BE920: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_801BEAF4;
    }
    goto skip_4;
    // 0x801BE920: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_4:
    // 0x801BE924: lh          $t7, 0xB8($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XB8);
    // 0x801BE928: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801BE92C: bnel        $t7, $at, L_801BEA98
    if (ctx->r15 != ctx->r1) {
        // 0x801BE930: lh          $t4, 0xB8($s1)
        ctx->r12 = MEM_H(ctx->r17, 0XB8);
            goto L_801BEA98;
    }
    goto skip_5;
    // 0x801BE930: lh          $t4, 0xB8($s1)
    ctx->r12 = MEM_H(ctx->r17, 0XB8);
    skip_5:
    // 0x801BE934: lhu         $t8, 0xD6($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0XD6);
    // 0x801BE938: andi        $t1, $zero, 0xFF
    ctx->r9 = 0 & 0XFF;
    // 0x801BE93C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801BE940: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x801BE944: sh          $t9, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = ctx->r25;
    // 0x801BE948: lh          $t0, 0xCE($s1)
    ctx->r8 = MEM_H(ctx->r17, 0XCE);
    // 0x801BE94C: bgtzl       $t0, L_801BEA98
    if (SIGNED(ctx->r8) > 0) {
        // 0x801BE950: lh          $t4, 0xB8($s1)
        ctx->r12 = MEM_H(ctx->r17, 0XB8);
            goto L_801BEA98;
    }
    goto skip_6;
    // 0x801BE950: lh          $t4, 0xB8($s1)
    ctx->r12 = MEM_H(ctx->r17, 0XB8);
    skip_6:
    // 0x801BE954: sb          $zero, 0x44($s1)
    MEM_B(0X44, ctx->r17) = 0;
    // 0x801BE958: jal         0x80066254
    // 0x801BE95C: sh          $t1, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = ctx->r9;
    Actor_Despawn(rdram, ctx);
        goto after_14;
    // 0x801BE95C: sh          $t1, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = ctx->r9;
    after_14:
    // 0x801BE960: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801BE964:
    // 0x801BE964: jal         0x80004EB0
    // 0x801BE968: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_15;
    // 0x801BE968: nop

    after_15:
    // 0x801BE96C: jal         0x80004EB0
    // 0x801BE970: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_16;
    // 0x801BE970: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_16:
    // 0x801BE974: sub.s       $f10, $f20, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f26.fl;
    // 0x801BE978: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801BE97C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801BE980: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801BE984: mul.s       $f18, $f10, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x801BE988: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801BE98C: sub.s       $f10, $f0, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x801BE990: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801BE994: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x801BE998: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x801BE99C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801BE9A0: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x801BE9A4: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801BE9A8: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801BE9AC: mul.s       $f18, $f10, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f30.fl);
    // 0x801BE9B0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801BE9B4: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x801BE9B8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801BE9BC: jal         0x801AC8A8
    // 0x801BE9C0: add.s       $f14, $f18, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f8.fl;
    Aquas_Bubble_Spawn(rdram, ctx);
        goto after_17;
    // 0x801BE9C0: add.s       $f14, $f18, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f8.fl;
    after_17:
    // 0x801BE9C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801BE9C8: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x801BE9CC: bne         $at, $zero, L_801BE964
    if (ctx->r1 != 0) {
        // 0x801BE9D0: nop
    
            goto L_801BE964;
    }
    // 0x801BE9D0: nop

    // 0x801BE9D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801BE9D8:
    // 0x801BE9D8: jal         0x80004EB0
    // 0x801BE9DC: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_18;
    // 0x801BE9DC: nop

    after_18:
    // 0x801BE9E0: jal         0x80004EB0
    // 0x801BE9E4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_19;
    // 0x801BE9E4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_19:
    // 0x801BE9E8: jal         0x80004EB0
    // 0x801BE9EC: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_20;
    // 0x801BE9EC: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    after_20:
    // 0x801BE9F0: jal         0x80004EB0
    // 0x801BE9F4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_21;
    // 0x801BE9F4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_21:
    // 0x801BE9F8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801BE9FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801BEA00: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801BEA04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801BEA08: mul.s       $f18, $f22, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x801BEA0C: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801BEA10: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801BEA14: mul.s       $f4, $f24, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f28.fl);
    // 0x801BEA18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801BEA1C: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x801BEA20: mul.s       $f10, $f20, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x801BEA24: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x801BEA28: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801BEA2C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801BEA30: add.s       $f14, $f4, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x801BEA34: mul.s       $f4, $f0, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x801BEA38: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801BEA3C: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x801BEA40: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801BEA44: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x801BEA48: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801BEA4C: jal         0x80081A8C
    // 0x801BEA50: nop

    func_effect_80081A8C(rdram, ctx);
        goto after_22;
    // 0x801BEA50: nop

    after_22:
    // 0x801BEA54: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801BEA58: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801BEA5C: bne         $s0, $at, L_801BE9D8
    if (ctx->r16 != ctx->r1) {
        // 0x801BEA60: nop
    
            goto L_801BE9D8;
    }
    // 0x801BEA60: nop

    // 0x801BEA64: jal         0x800815DC
    // 0x801BEA68: nop

    func_effect_800815DC(rdram, ctx);
        goto after_23;
    // 0x801BEA68: nop

    after_23:
    // 0x801BEA6C: lui         $at, 0x424C
    ctx->r1 = S32(0X424C << 16);
    // 0x801BEA70: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801BEA74: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801BEA78: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801BEA7C: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801BEA80: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x801BEA84: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801BEA88: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801BEA8C: jal         0x8007CF30
    // 0x801BEA90: nop

    Effect_FireSmoke1_Spawn(rdram, ctx);
        goto after_24;
    // 0x801BEA90: nop

    after_24:
    // 0x801BEA94: lh          $t4, 0xB8($s1)
    ctx->r12 = MEM_H(ctx->r17, 0XB8);
L_801BEA98:
    // 0x801BEA98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801BEA9C: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x801BEAA0: bne         $t4, $at, L_801BEAF0
    if (ctx->r12 != ctx->r1) {
        // 0x801BEAA4: addiu       $v0, $v0, 0x14E4
        ctx->r2 = ADD32(ctx->r2, 0X14E4);
            goto L_801BEAF0;
    }
    // 0x801BEAA4: addiu       $v0, $v0, 0x14E4
    ctx->r2 = ADD32(ctx->r2, 0X14E4);
    // 0x801BEAA8: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x801BEAAC: srl         $t6, $t5, 28
    ctx->r14 = S32(U32(ctx->r13) >> 28);
    // 0x801BEAB0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801BEAB4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x801BEAB8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801BEABC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x801BEAC0: lw          $t8, 0x1FD0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1FD0);
    // 0x801BEAC4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x801BEAC8: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x801BEACC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801BEAD0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x801BEAD4: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x801BEAD8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BEADC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801BEAE0: sw          $t1, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r9;
    // 0x801BEAE4: sb          $zero, 0x34($s1)
    MEM_B(0X34, ctx->r17) = 0;
    // 0x801BEAE8: sb          $t2, 0x3C($s1)
    MEM_B(0X3C, ctx->r17) = ctx->r10;
    // 0x801BEAEC: sh          $t3, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r11;
L_801BEAF0:
    // 0x801BEAF0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801BEAF4:
    // 0x801BEAF4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801BEAF8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801BEAFC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x801BEB00: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x801BEB04: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x801BEB08: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x801BEB0C: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x801BEB10: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x801BEB14: jr          $ra
    // 0x801BEB18: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x801BEB18: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void Zoness_8019907C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019907C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80199080: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80199084: addiu       $v0, $v0, 0x23D0
    ctx->r2 = ADD32(ctx->r2, 0X23D0);
    // 0x80199088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019908C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80199090: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x80199094: bne         $t6, $zero, L_80199134
    if (ctx->r14 != 0) {
        // 0x80199098: nop
    
            goto L_80199134;
    }
    // 0x80199098: nop

    // 0x8019909C: lw          $t7, 0x28($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X28);
    // 0x801990A0: bne         $t7, $zero, L_80199134
    if (ctx->r15 != 0) {
        // 0x801990A4: nop
    
            goto L_80199134;
    }
    // 0x801990A4: nop

    // 0x801990A8: lw          $t8, 0x7C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X7C);
    // 0x801990AC: bnel        $t8, $zero, L_801990E4
    if (ctx->r24 != 0) {
        // 0x801990B0: lw          $t1, 0x78($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X78);
            goto L_801990E4;
    }
    goto skip_0;
    // 0x801990B0: lw          $t1, 0x78($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X78);
    skip_0:
    // 0x801990B4: lw          $t9, 0x78($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X78);
    // 0x801990B8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801990BC: addiu       $a0, $a0, -0x25E4
    ctx->r4 = ADD32(ctx->r4, -0X25E4);
    // 0x801990C0: beql        $t9, $zero, L_801990E4
    if (ctx->r25 == 0) {
        // 0x801990C4: lw          $t1, 0x78($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X78);
            goto L_801990E4;
    }
    goto skip_1;
    // 0x801990C4: lw          $t1, 0x78($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X78);
    skip_1:
    // 0x801990C8: jal         0x800BA808
    // 0x801990CC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_0;
    // 0x801990CC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_0:
    // 0x801990D0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801990D4: addiu       $v0, $v0, 0x23D0
    ctx->r2 = ADD32(ctx->r2, 0X23D0);
    // 0x801990D8: addiu       $t0, $zero, 0x14D
    ctx->r8 = ADD32(0, 0X14D);
    // 0x801990DC: sw          $t0, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->r8;
    // 0x801990E0: lw          $t1, 0x78($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X78);
L_801990E4:
    // 0x801990E4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801990E8: addiu       $a0, $a0, -0x2744
    ctx->r4 = ADD32(ctx->r4, -0X2744);
    // 0x801990EC: bnel        $t1, $zero, L_8019911C
    if (ctx->r9 != 0) {
        // 0x801990F0: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_8019911C;
    }
    goto skip_2;
    // 0x801990F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_2:
    // 0x801990F4: jal         0x800BA808
    // 0x801990F8: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    Radio_PlayMessage(rdram, ctx);
        goto after_1;
    // 0x801990F8: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_1:
    // 0x801990FC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80199100: addiu       $v0, $v0, 0x23D0
    ctx->r2 = ADD32(ctx->r2, 0X23D0);
    // 0x80199104: lw          $t3, 0x78($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X78);
    // 0x80199108: addiu       $t2, $zero, 0x14D
    ctx->r10 = ADD32(0, 0X14D);
    // 0x8019910C: sw          $t2, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->r10;
    // 0x80199110: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80199114: sw          $t4, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r12;
    // 0x80199118: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8019911C:
    // 0x8019911C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80199120: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199124: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80199128: swc1        $f4, 0x261C($at)
    MEM_W(0X261C, ctx->r1) = ctx->f4.u32l;
    // 0x8019912C: b           L_8019913C
    // 0x80199130: sh          $t5, 0x4E($t6)
    MEM_H(0X4E, ctx->r14) = ctx->r13;
        goto L_8019913C;
    // 0x80199130: sh          $t5, 0x4E($t6)
    MEM_H(0X4E, ctx->r14) = ctx->r13;
L_80199134:
    // 0x80199134: jal         0x80198ECC
    // 0x80199138: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    Zoness_80198ECC(rdram, ctx);
        goto after_2;
    // 0x80199138: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_8019913C:
    // 0x8019913C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80199140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80199144: jr          $ra
    // 0x80199148: nop

    return;
    // 0x80199148: nop

;}
RECOMP_FUNC void Zoness_Effect394_Setup3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193B08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80193B0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80193B10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80193B14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80193B18: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80193B1C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80193B20: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80193B24: jal         0x80061474
    // 0x80193B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x80193B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80193B2C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80193B30: addiu       $t7, $zero, 0x18A
    ctx->r15 = ADD32(0, 0X18A);
    // 0x80193B34: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80193B38: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x80193B3C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80193B40: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80193B44: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80193B48: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80193B4C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80193B50: jal         0x80004EB0
    // 0x80193B54: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80193B54: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x80193B58: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80193B5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80193B60: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80193B64: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80193B68: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80193B6C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80193B70: jal         0x80004EB0
    // 0x80193B74: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x80193B74: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x80193B78: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80193B7C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80193B80: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80193B84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80193B88: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80193B8C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80193B90: sh          $t8, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r24;
    // 0x80193B94: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80193B98: jal         0x80004EB0
    // 0x80193B9C: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x80193B9C: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    after_3:
    // 0x80193BA0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80193BA4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80193BA8: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80193BAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80193BB0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80193BB4: addiu       $t1, $zero, 0xB4
    ctx->r9 = ADD32(0, 0XB4);
    // 0x80193BB8: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80193BBC: addiu       $t3, $zero, 0x65
    ctx->r11 = ADD32(0, 0X65);
    // 0x80193BC0: bc1f        L_80193BD4
    if (!c1cs) {
        // 0x80193BC4: addiu       $t4, $zero, 0xF
        ctx->r12 = ADD32(0, 0XF);
            goto L_80193BD4;
    }
    // 0x80193BC4: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x80193BC8: lh          $t9, 0x48($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X48);
    // 0x80193BCC: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x80193BD0: sh          $t0, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r8;
L_80193BD4:
    // 0x80193BD4: sh          $t1, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r9;
    // 0x80193BD8: sh          $t2, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r10;
    // 0x80193BDC: sh          $t3, 0x78($s0)
    MEM_H(0X78, ctx->r16) = ctx->r11;
    // 0x80193BE0: sh          $t4, 0x7A($s0)
    MEM_H(0X7A, ctx->r16) = ctx->r12;
    // 0x80193BE4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80193BE8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80193BEC: jal         0x80004EB0
    // 0x80193BF0: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x80193BF0: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x80193BF4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80193BF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80193BFC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80193C00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80193C04: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80193C08: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80193C0C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80193C10: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    // 0x80193C14: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80193C18: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x80193C1C: nop

    // 0x80193C20: bc1f        L_80193C40
    if (!c1cs) {
        // 0x80193C24: nop
    
            goto L_80193C40;
    }
    // 0x80193C24: nop

    // 0x80193C28: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x80193C2C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80193C30: lwc1        $f8, 0xF40($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XF40);
    // 0x80193C34: lwc1        $f6, 0xC8($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XC8);
    // 0x80193C38: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80193C3C: swc1        $f10, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f10.u32l;
L_80193C40:
    // 0x80193C40: jal         0x800612B8
    // 0x80193C44: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_5;
    // 0x80193C44: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_5:
    // 0x80193C48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80193C4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80193C50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80193C54: jr          $ra
    // 0x80193C58: nop

    return;
    // 0x80193C58: nop

;}
RECOMP_FUNC void Area6_ActorCsOrbGlow_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EA88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018EA8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018EA90: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8018EA94: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8018EA98: jal         0x800613C4
    // 0x8018EA9C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018EA9C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8018EAA0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8018EAA4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018EAA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018EAAC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018EAB0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8018EAB4: addiu       $t7, $zero, 0xC3
    ctx->r15 = ADD32(0, 0XC3);
    // 0x8018EAB8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018EABC: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8018EAC0: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x8018EAC4: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
    // 0x8018EAC8: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x8018EACC: lwc1        $f4, -0xEE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XEE4);
    // 0x8018EAD0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8018EAD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018EAD8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8018EADC: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
    // 0x8018EAE0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018EAE4: addiu       $t8, $zero, 0x25
    ctx->r24 = ADD32(0, 0X25);
    // 0x8018EAE8: addiu       $t9, $zero, 0xF0
    ctx->r25 = ADD32(0, 0XF0);
    // 0x8018EAEC: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8018EAF0: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x8018EAF4: sh          $t8, 0xB6($a2)
    MEM_H(0XB6, ctx->r6) = ctx->r24;
    // 0x8018EAF8: sh          $v1, 0xB8($a2)
    MEM_H(0XB8, ctx->r6) = ctx->r3;
    // 0x8018EAFC: sw          $v0, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->r2;
    // 0x8018EB00: sw          $v0, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->r2;
    // 0x8018EB04: sw          $v0, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r2;
    // 0x8018EB08: sw          $t9, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->r25;
    // 0x8018EB0C: sw          $zero, 0x60($a2)
    MEM_W(0X60, ctx->r6) = 0;
    // 0x8018EB10: sw          $zero, 0x64($a2)
    MEM_W(0X64, ctx->r6) = 0;
    // 0x8018EB14: sw          $v0, 0x68($a2)
    MEM_W(0X68, ctx->r6) = ctx->r2;
    // 0x8018EB18: sw          $v1, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->r3;
    // 0x8018EB1C: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8018EB20: swc1        $f2, 0x124($a2)
    MEM_W(0X124, ctx->r6) = ctx->f2.u32l;
    // 0x8018EB24: jal         0x800612B8
    // 0x8018EB28: swc1        $f2, 0x110($a2)
    MEM_W(0X110, ctx->r6) = ctx->f2.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8018EB28: swc1        $f2, 0x110($a2)
    MEM_W(0X110, ctx->r6) = ctx->f2.u32l;
    after_1:
    // 0x8018EB2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018EB30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018EB34: jr          $ra
    // 0x8018EB38: nop

    return;
    // 0x8018EB38: nop

;}
RECOMP_FUNC void Aquas_801A8E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A8E30: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x801A8E34: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x801A8E38: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x801A8E3C: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x801A8E40: addiu       $a0, $a0, 0x1FD0
    ctx->r4 = ADD32(ctx->r4, 0X1FD0);
    // 0x801A8E44: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801A8E48: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x801A8E4C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x801A8E50: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x801A8E54: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x801A8E58: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801A8E5C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x801A8E60: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801A8E64: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801A8E68: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x801A8E6C: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x801A8E70: addiu       $v0, $v0, 0x1D90
    ctx->r2 = ADD32(ctx->r2, 0X1D90);
    // 0x801A8E74: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x801A8E78: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x801A8E7C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801A8E80: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x801A8E84: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x801A8E88: lui         $v1, 0x601
    ctx->r3 = S32(0X601 << 16);
    // 0x801A8E8C: and         $t5, $v0, $a1
    ctx->r13 = ctx->r2 & ctx->r5;
    // 0x801A8E90: addiu       $v1, $v1, 0x1A78
    ctx->r3 = ADD32(ctx->r3, 0X1A78);
    // 0x801A8E94: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x801A8E98: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x801A8E9C: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x801A8EA0: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x801A8EA4: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x801A8EA8: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x801A8EAC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801A8EB0: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    // 0x801A8EB4: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801A8EB8: and         $t7, $v1, $a1
    ctx->r15 = ctx->r3 & ctx->r5;
    // 0x801A8EBC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801A8EC0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A8EC4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x801A8EC8: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x801A8ECC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801A8ED0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801A8ED4: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x801A8ED8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x801A8EDC: addiu       $s1, $sp, 0xA8
    ctx->r17 = ADD32(ctx->r29, 0XA8);
    // 0x801A8EE0: addiu       $s0, $sp, 0x64
    ctx->r16 = ADD32(ctx->r29, 0X64);
    // 0x801A8EE4: addiu       $s4, $sp, 0xA8
    ctx->r20 = ADD32(ctx->r29, 0XA8);
    // 0x801A8EE8: addiu       $s3, $sp, 0xA4
    ctx->r19 = ADD32(ctx->r29, 0XA4);
    // 0x801A8EEC: addiu       $s2, $sp, 0x64
    ctx->r18 = ADD32(ctx->r29, 0X64);
L_801A8EF0:
    // 0x801A8EF0: beql        $s0, $s2, L_801A8F04
    if (ctx->r16 == ctx->r18) {
        // 0x801A8EF4: swc1        $f20, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->f20.u32l;
            goto L_801A8F04;
    }
    goto skip_0;
    // 0x801A8EF4: swc1        $f20, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f20.u32l;
    skip_0:
    // 0x801A8EF8: bne         $s0, $s3, L_801A8F0C
    if (ctx->r16 != ctx->r19) {
        // 0x801A8EFC: nop
    
            goto L_801A8F0C;
    }
    // 0x801A8EFC: nop

    // 0x801A8F00: swc1        $f20, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f20.u32l;
L_801A8F04:
    // 0x801A8F04: b           L_801A8F30
    // 0x801A8F08: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
        goto L_801A8F30;
    // 0x801A8F08: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
L_801A8F0C:
    // 0x801A8F0C: jal         0x80004EB0
    // 0x801A8F10: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x801A8F10: nop

    after_0:
    // 0x801A8F14: sub.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x801A8F18: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x801A8F1C: jal         0x80004EB0
    // 0x801A8F20: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x801A8F20: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    after_1:
    // 0x801A8F24: sub.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x801A8F28: mul.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x801A8F2C: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
L_801A8F30:
    // 0x801A8F30: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x801A8F34: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x801A8F38: bne         $at, $zero, L_801A8EF0
    if (ctx->r1 != 0) {
        // 0x801A8F3C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_801A8EF0;
    }
    // 0x801A8F3C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x801A8F40: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x801A8F44: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x801A8F48: addiu       $a3, $sp, 0xA8
    ctx->r7 = ADD32(ctx->r29, 0XA8);
    // 0x801A8F4C: lh          $t4, 0x4($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X4);
    // 0x801A8F50: lh          $t7, 0x0($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X0);
    // 0x801A8F54: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x801A8F58: addiu       $t5, $t4, 0xC8
    ctx->r13 = ADD32(ctx->r12, 0XC8);
    // 0x801A8F5C: div         $zero, $t5, $a2
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r6)));
    // 0x801A8F60: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x801A8F64: mflo        $a1
    ctx->r5 = lo;
    // 0x801A8F68: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x801A8F6C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801A8F70: addu        $t6, $a3, $v1
    ctx->r14 = ADD32(ctx->r7, ctx->r3);
    // 0x801A8F74: lwc1        $f16, 0x0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X0);
    // 0x801A8F78: addiu       $t0, $sp, 0x64
    ctx->r8 = ADD32(ctx->r29, 0X64);
    // 0x801A8F7C: bne         $a2, $zero, L_801A8F88
    if (ctx->r6 != 0) {
        // 0x801A8F80: nop
    
            goto L_801A8F88;
    }
    // 0x801A8F80: nop

    // 0x801A8F84: break       7
    do_break(2149224324);
L_801A8F88:
    // 0x801A8F88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801A8F8C: bne         $a2, $at, L_801A8FA0
    if (ctx->r6 != ctx->r1) {
        // 0x801A8F90: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801A8FA0;
    }
    // 0x801A8F90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801A8F94: bne         $t5, $at, L_801A8FA0
    if (ctx->r13 != ctx->r1) {
        // 0x801A8F98: nop
    
            goto L_801A8FA0;
    }
    // 0x801A8F98: nop

    // 0x801A8F9C: break       6
    do_break(2149224348);
L_801A8FA0:
    // 0x801A8FA0: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x801A8FA4: addu        $t4, $t0, $v1
    ctx->r12 = ADD32(ctx->r8, ctx->r3);
    // 0x801A8FA8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x801A8FAC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801A8FB0: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x801A8FB4: nop

    // 0x801A8FB8: sh          $t9, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r25;
    // 0x801A8FBC: lh          $t5, 0x2($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X2);
    // 0x801A8FC0: lwc1        $f10, 0x0($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X0);
    // 0x801A8FC4: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x801A8FC8: nop

    // 0x801A8FCC: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801A8FD0: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A8FD4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801A8FD8: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x801A8FDC: nop

    // 0x801A8FE0: sh          $t7, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r15;
    // 0x801A8FE4: lh          $t8, 0x14($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X14);
    // 0x801A8FE8: lh          $t5, 0x10($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X10);
    // 0x801A8FEC: addiu       $t9, $t8, 0xC8
    ctx->r25 = ADD32(ctx->r24, 0XC8);
    // 0x801A8FF0: div         $zero, $t9, $a2
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r6)));
    // 0x801A8FF4: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x801A8FF8: mflo        $a1
    ctx->r5 = lo;
    // 0x801A8FFC: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x801A9000: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801A9004: addu        $t4, $a3, $v1
    ctx->r12 = ADD32(ctx->r7, ctx->r3);
    // 0x801A9008: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x801A900C: bne         $a2, $zero, L_801A9018
    if (ctx->r6 != 0) {
        // 0x801A9010: nop
    
            goto L_801A9018;
    }
    // 0x801A9010: nop

    // 0x801A9014: break       7
    do_break(2149224468);
L_801A9018:
    // 0x801A9018: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801A901C: bne         $a2, $at, L_801A9030
    if (ctx->r6 != ctx->r1) {
        // 0x801A9020: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801A9030;
    }
    // 0x801A9020: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801A9024: bne         $t9, $at, L_801A9030
    if (ctx->r25 != ctx->r1) {
        // 0x801A9028: nop
    
            goto L_801A9030;
    }
    // 0x801A9028: nop

    // 0x801A902C: break       6
    do_break(2149224492);
L_801A9030:
    // 0x801A9030: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A9034: addu        $t8, $t0, $v1
    ctx->r24 = ADD32(ctx->r8, ctx->r3);
    // 0x801A9038: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801A903C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x801A9040: nop

    // 0x801A9044: sh          $t7, 0x10($t3)
    MEM_H(0X10, ctx->r11) = ctx->r15;
    // 0x801A9048: lh          $t9, 0x12($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X12);
    // 0x801A904C: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x801A9050: addiu       $t2, $zero, 0x22
    ctx->r10 = ADD32(0, 0X22);
    // 0x801A9054: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x801A9058: nop

    // 0x801A905C: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801A9060: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A9064: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801A9068: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x801A906C: nop

    // 0x801A9070: sh          $t5, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r13;
    // 0x801A9074: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x801A9078: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x801A907C: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x801A9080: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
L_801A9084:
    // 0x801A9084: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x801A9088: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x801A908C: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x801A9090: addiu       $t7, $t6, 0xC8
    ctx->r15 = ADD32(ctx->r14, 0XC8);
    // 0x801A9094: div         $zero, $t7, $a2
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r6)));
    // 0x801A9098: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x801A909C: mflo        $a1
    ctx->r5 = lo;
    // 0x801A90A0: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x801A90A4: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801A90A8: addu        $t8, $a3, $v1
    ctx->r24 = ADD32(ctx->r7, ctx->r3);
    // 0x801A90AC: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x801A90B0: bne         $a2, $zero, L_801A90BC
    if (ctx->r6 != 0) {
        // 0x801A90B4: nop
    
            goto L_801A90BC;
    }
    // 0x801A90B4: nop

    // 0x801A90B8: break       7
    do_break(2149224632);
L_801A90BC:
    // 0x801A90BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801A90C0: bne         $a2, $at, L_801A90D4
    if (ctx->r6 != ctx->r1) {
        // 0x801A90C4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801A90D4;
    }
    // 0x801A90C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801A90C8: bne         $t7, $at, L_801A90D4
    if (ctx->r15 != ctx->r1) {
        // 0x801A90CC: nop
    
            goto L_801A90D4;
    }
    // 0x801A90CC: nop

    // 0x801A90D0: break       6
    do_break(2149224656);
L_801A90D4:
    // 0x801A90D4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A90D8: addu        $t6, $t0, $v1
    ctx->r14 = ADD32(ctx->r8, ctx->r3);
    // 0x801A90DC: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x801A90E0: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x801A90E4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801A90E8: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x801A90EC: nop

    // 0x801A90F0: sh          $t5, -0x40($a0)
    MEM_H(-0X40, ctx->r4) = ctx->r13;
    // 0x801A90F4: lh          $t7, -0x3E($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X3E);
    // 0x801A90F8: lwc1        $f16, 0x0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X0);
    // 0x801A90FC: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x801A9100: nop

    // 0x801A9104: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801A9108: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x801A910C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801A9110: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x801A9114: nop

    // 0x801A9118: sh          $t9, -0x3E($a0)
    MEM_H(-0X3E, ctx->r4) = ctx->r25;
    // 0x801A911C: lh          $t4, -0x2C($v0)
    ctx->r12 = MEM_H(ctx->r2, -0X2C);
    // 0x801A9120: lh          $t7, -0x30($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X30);
    // 0x801A9124: addiu       $t5, $t4, 0xC8
    ctx->r13 = ADD32(ctx->r12, 0XC8);
    // 0x801A9128: div         $zero, $t5, $a2
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r6)));
    // 0x801A912C: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x801A9130: mflo        $a1
    ctx->r5 = lo;
    // 0x801A9134: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x801A9138: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801A913C: addu        $t6, $a3, $v1
    ctx->r14 = ADD32(ctx->r7, ctx->r3);
    // 0x801A9140: lwc1        $f10, 0x0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X0);
    // 0x801A9144: bne         $a2, $zero, L_801A9150
    if (ctx->r6 != 0) {
        // 0x801A9148: nop
    
            goto L_801A9150;
    }
    // 0x801A9148: nop

    // 0x801A914C: break       7
    do_break(2149224780);
L_801A9150:
    // 0x801A9150: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801A9154: bne         $a2, $at, L_801A9168
    if (ctx->r6 != ctx->r1) {
        // 0x801A9158: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801A9168;
    }
    // 0x801A9158: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801A915C: bne         $t5, $at, L_801A9168
    if (ctx->r13 != ctx->r1) {
        // 0x801A9160: nop
    
            goto L_801A9168;
    }
    // 0x801A9160: nop

    // 0x801A9164: break       6
    do_break(2149224804);
L_801A9168:
    // 0x801A9168: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A916C: addu        $t4, $t0, $v1
    ctx->r12 = ADD32(ctx->r8, ctx->r3);
    // 0x801A9170: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801A9174: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x801A9178: nop

    // 0x801A917C: sh          $t9, -0x30($a0)
    MEM_H(-0X30, ctx->r4) = ctx->r25;
    // 0x801A9180: lh          $t5, -0x2E($v0)
    ctx->r13 = MEM_H(ctx->r2, -0X2E);
    // 0x801A9184: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x801A9188: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x801A918C: nop

    // 0x801A9190: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801A9194: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A9198: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801A919C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x801A91A0: nop

    // 0x801A91A4: sh          $t7, -0x2E($a0)
    MEM_H(-0X2E, ctx->r4) = ctx->r15;
    // 0x801A91A8: lh          $t8, -0x1C($v0)
    ctx->r24 = MEM_H(ctx->r2, -0X1C);
    // 0x801A91AC: lh          $t5, -0x20($v0)
    ctx->r13 = MEM_H(ctx->r2, -0X20);
    // 0x801A91B0: addiu       $t9, $t8, 0xC8
    ctx->r25 = ADD32(ctx->r24, 0XC8);
    // 0x801A91B4: div         $zero, $t9, $a2
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r6)));
    // 0x801A91B8: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x801A91BC: mflo        $a1
    ctx->r5 = lo;
    // 0x801A91C0: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x801A91C4: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801A91C8: addu        $t4, $a3, $v1
    ctx->r12 = ADD32(ctx->r7, ctx->r3);
    // 0x801A91CC: lwc1        $f6, 0x0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X0);
    // 0x801A91D0: bne         $a2, $zero, L_801A91DC
    if (ctx->r6 != 0) {
        // 0x801A91D4: nop
    
            goto L_801A91DC;
    }
    // 0x801A91D4: nop

    // 0x801A91D8: break       7
    do_break(2149224920);
L_801A91DC:
    // 0x801A91DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801A91E0: bne         $a2, $at, L_801A91F4
    if (ctx->r6 != ctx->r1) {
        // 0x801A91E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801A91F4;
    }
    // 0x801A91E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801A91E8: bne         $t9, $at, L_801A91F4
    if (ctx->r25 != ctx->r1) {
        // 0x801A91EC: nop
    
            goto L_801A91F4;
    }
    // 0x801A91EC: nop

    // 0x801A91F0: break       6
    do_break(2149224944);
L_801A91F4:
    // 0x801A91F4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A91F8: addu        $t8, $t0, $v1
    ctx->r24 = ADD32(ctx->r8, ctx->r3);
    // 0x801A91FC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801A9200: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x801A9204: nop

    // 0x801A9208: sh          $t7, -0x20($a0)
    MEM_H(-0X20, ctx->r4) = ctx->r15;
    // 0x801A920C: lh          $t9, -0x1E($v0)
    ctx->r25 = MEM_H(ctx->r2, -0X1E);
    // 0x801A9210: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x801A9214: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x801A9218: nop

    // 0x801A921C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801A9220: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A9224: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801A9228: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x801A922C: nop

    // 0x801A9230: sh          $t5, -0x1E($a0)
    MEM_H(-0X1E, ctx->r4) = ctx->r13;
    // 0x801A9234: lh          $t6, -0xC($v0)
    ctx->r14 = MEM_H(ctx->r2, -0XC);
    // 0x801A9238: lh          $t9, -0x10($v0)
    ctx->r25 = MEM_H(ctx->r2, -0X10);
    // 0x801A923C: addiu       $t7, $t6, 0xC8
    ctx->r15 = ADD32(ctx->r14, 0XC8);
    // 0x801A9240: div         $zero, $t7, $a2
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r6)));
    // 0x801A9244: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x801A9248: mflo        $a1
    ctx->r5 = lo;
    // 0x801A924C: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x801A9250: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801A9254: addu        $t8, $a3, $v1
    ctx->r24 = ADD32(ctx->r7, ctx->r3);
    // 0x801A9258: lwc1        $f16, 0x0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X0);
    // 0x801A925C: bne         $a2, $zero, L_801A9268
    if (ctx->r6 != 0) {
        // 0x801A9260: nop
    
            goto L_801A9268;
    }
    // 0x801A9260: nop

    // 0x801A9264: break       7
    do_break(2149225060);
L_801A9268:
    // 0x801A9268: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801A926C: bne         $a2, $at, L_801A9280
    if (ctx->r6 != ctx->r1) {
        // 0x801A9270: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801A9280;
    }
    // 0x801A9270: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801A9274: bne         $t7, $at, L_801A9280
    if (ctx->r15 != ctx->r1) {
        // 0x801A9278: nop
    
            goto L_801A9280;
    }
    // 0x801A9278: nop

    // 0x801A927C: break       6
    do_break(2149225084);
L_801A9280:
    // 0x801A9280: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x801A9284: addu        $t6, $t0, $v1
    ctx->r14 = ADD32(ctx->r8, ctx->r3);
    // 0x801A9288: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801A928C: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x801A9290: nop

    // 0x801A9294: sh          $t5, -0x10($a0)
    MEM_H(-0X10, ctx->r4) = ctx->r13;
    // 0x801A9298: lh          $t7, -0xE($v0)
    ctx->r15 = MEM_H(ctx->r2, -0XE);
    // 0x801A929C: lwc1        $f10, 0x0($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X0);
    // 0x801A92A0: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x801A92A4: nop

    // 0x801A92A8: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801A92AC: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A92B0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801A92B4: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x801A92B8: bne         $t1, $t2, L_801A9084
    if (ctx->r9 != ctx->r10) {
        // 0x801A92BC: sh          $t9, -0xE($a0)
        MEM_H(-0XE, ctx->r4) = ctx->r25;
            goto L_801A9084;
    }
    // 0x801A92BC: sh          $t9, -0xE($a0)
    MEM_H(-0XE, ctx->r4) = ctx->r25;
    // 0x801A92C0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801A92C4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801A92C8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801A92CC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x801A92D0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x801A92D4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x801A92D8: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x801A92DC: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x801A92E0: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x801A92E4: jr          $ra
    // 0x801A92E8: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x801A92E8: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void Zoness_ZoEnergyBall_Init2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191BB8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80191BBC: jr          $ra
    // 0x80191BC0: nop

    return;
    // 0x80191BC0: nop

;}
RECOMP_FUNC void Aquas_AqOyster_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BEB1C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801BEB20: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801BEB24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801BEB28: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801BEB2C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801BEB30: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801BEB34: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801BEB38: jal         0x8005980C
    // 0x801BEB3C: nop

    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x801BEB3C: nop

    after_0:
    // 0x801BEB40: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x801BEB44: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x801BEB48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801BEB4C: jal         0x800B8DD0
    // 0x801BEB50: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x801BEB50: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_1:
    // 0x801BEB54: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x801BEB58: lui         $t8, 0xFF8F
    ctx->r24 = S32(0XFF8F << 16);
    // 0x801BEB5C: ori         $t8, $t8, 0x8FFF
    ctx->r24 = ctx->r24 | 0X8FFF;
    // 0x801BEB60: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801BEB64: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x801BEB68: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801BEB6C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801BEB70: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x801BEB74: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x801BEB78: lh          $a1, 0xB6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XB6);
    // 0x801BEB7C: addiu       $a2, $s0, 0x18C
    ctx->r6 = ADD32(ctx->r16, 0X18C);
    // 0x801BEB80: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x801BEB84: jal         0x8009AA20
    // 0x801BEB88: addiu       $a0, $a0, 0x201C
    ctx->r4 = ADD32(ctx->r4, 0X201C);
    Animation_GetFrameData(rdram, ctx);
        goto after_2;
    // 0x801BEB88: addiu       $a0, $a0, 0x201C
    ctx->r4 = ADD32(ctx->r4, 0X201C);
    after_2:
    // 0x801BEB8C: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x801BEB90: addiu       $t0, $t0, 0x4660
    ctx->r8 = ADD32(ctx->r8, 0X4660);
    // 0x801BEB94: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x801BEB98: addiu       $t9, $s0, 0x40
    ctx->r25 = ADD32(ctx->r16, 0X40);
    // 0x801BEB9C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x801BEBA0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801BEBA4: addiu       $a1, $a1, 0x20E8
    ctx->r5 = ADD32(ctx->r5, 0X20E8);
    // 0x801BEBA8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x801BEBAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BEBB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801BEBB4: jal         0x8009A72C
    // 0x801BEBB8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_3;
    // 0x801BEBB8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x801BEBBC: lh          $t1, 0xCE($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XCE);
    // 0x801BEBC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801BEBC4: beql        $t1, $zero, L_801BEC40
    if (ctx->r9 == 0) {
        // 0x801BEBC8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801BEC40;
    }
    goto skip_0;
    // 0x801BEBC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x801BEBCC: jal         0x800B8DD0
    // 0x801BEBD0: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x801BEBD0: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_4:
    // 0x801BEBD4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BEBD8: lw          $a1, 0x114($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X114);
    // 0x801BEBDC: lw          $a2, 0x118($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X118);
    // 0x801BEBE0: lw          $a3, 0x11C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X11C);
    // 0x801BEBE4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801BEBE8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801BEBEC: jal         0x80005C34
    // 0x801BEBF0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x801BEBF0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_5:
    // 0x801BEBF4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BEBF8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801BEBFC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801BEC00: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801BEC04: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801BEC08: lui         $a2, 0xC100
    ctx->r6 = S32(0XC100 << 16);
    // 0x801BEC0C: jal         0x80005B00
    // 0x801BEC10: lui         $a3, 0x424C
    ctx->r7 = S32(0X424C << 16);
    Matrix_Translate(rdram, ctx);
        goto after_6;
    // 0x801BEC10: lui         $a3, 0x424C
    ctx->r7 = S32(0X424C << 16);
    after_6:
    // 0x801BEC14: jal         0x80006EB8
    // 0x801BEC18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x801BEC18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x801BEC1C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x801BEC20: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x801BEC24: addiu       $t6, $t6, 0x2C10
    ctx->r14 = ADD32(ctx->r14, 0X2C10);
    // 0x801BEC28: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x801BEC2C: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x801BEC30: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x801BEC34: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801BEC38: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801BEC3C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801BEC40:
    // 0x801BEC40: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801BEC44: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801BEC48: jr          $ra
    // 0x801BEC4C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801BEC4C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Zoness_ZGull_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191680: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80191684: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80191688: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019168C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80191690: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80191694: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80191698: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8019169C: nop

    // 0x801916A0: bc1f        L_801916AC
    if (!c1cs) {
        // 0x801916A4: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_801916AC;
    }
    // 0x801916A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801916A8: sh          $t6, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r14;
L_801916AC:
    // 0x801916AC: lb          $t7, 0xD0($s0)
    ctx->r15 = MEM_B(ctx->r16, 0XD0);
    // 0x801916B0: beql        $t7, $zero, L_80191760
    if (ctx->r15 == 0) {
        // 0x801916B4: lh          $t6, 0xB6($s0)
        ctx->r14 = MEM_H(ctx->r16, 0XB6);
            goto L_80191760;
    }
    goto skip_0;
    // 0x801916B4: lh          $t6, 0xB6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB6);
    skip_0:
    // 0x801916B8: lh          $v0, 0xCE($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XCE);
    // 0x801916BC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801916C0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801916C4: beq         $v0, $zero, L_8019175C
    if (ctx->r2 == 0) {
        // 0x801916C8: addiu       $t8, $zero, 0xF
        ctx->r24 = ADD32(0, 0XF);
            goto L_8019175C;
    }
    // 0x801916C8: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x801916CC: lhu         $t9, 0xD6($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XD6);
    // 0x801916D0: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x801916D4: sh          $t8, 0xC6($s0)
    MEM_H(0XC6, ctx->r16) = ctx->r24;
    // 0x801916D8: subu        $t0, $v0, $t9
    ctx->r8 = SUB32(ctx->r2, ctx->r25);
    // 0x801916DC: sh          $t0, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r8;
    // 0x801916E0: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x801916E4: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x801916E8: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x801916EC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x801916F0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801916F4: ori         $a0, $a0, 0x3037
    ctx->r4 = ctx->r4 | 0X3037;
    // 0x801916F8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801916FC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80191700: jal         0x80019218
    // 0x80191704: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x80191704: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80191708: lh          $t2, 0xCE($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XCE);
    // 0x8019170C: andi        $t3, $zero, 0xFF
    ctx->r11 = 0 & 0XFF;
    // 0x80191710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80191714: bgtzl       $t2, L_80191760
    if (SIGNED(ctx->r10) > 0) {
        // 0x80191718: lh          $t6, 0xB6($s0)
        ctx->r14 = MEM_H(ctx->r16, 0XB6);
            goto L_80191760;
    }
    goto skip_1;
    // 0x80191718: lh          $t6, 0xB6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB6);
    skip_1:
    // 0x8019171C: sb          $zero, 0x44($s0)
    MEM_B(0X44, ctx->r16) = 0;
    // 0x80191720: jal         0x80066254
    // 0x80191724: sh          $t3, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r11;
    Actor_Despawn(rdram, ctx);
        goto after_1;
    // 0x80191724: sh          $t3, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r11;
    after_1:
    // 0x80191728: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8019172C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80191730: sh          $t4, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r12;
    // 0x80191734: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80191738: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019173C: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x80191740: lui         $a0, 0x2901
    ctx->r4 = S32(0X2901 << 16);
    // 0x80191744: ori         $a0, $a0, 0x8036
    ctx->r4 = ctx->r4 | 0X8036;
    // 0x80191748: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8019174C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80191750: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80191754: jal         0x80019218
    // 0x80191758: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x80191758: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
L_8019175C:
    // 0x8019175C: lh          $t6, 0xB6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB6);
L_80191760:
    // 0x80191760: lui         $a0, 0x400
    ctx->r4 = S32(0X400 << 16);
    // 0x80191764: addiu       $a0, $a0, 0x57AC
    ctx->r4 = ADD32(ctx->r4, 0X57AC);
    // 0x80191768: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8019176C: jal         0x8009ACDC
    // 0x80191770: sh          $t7, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r15;
    Animation_GetFrameCount(rdram, ctx);
        goto after_3;
    // 0x80191770: sh          $t7, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r15;
    after_3:
    // 0x80191774: lh          $t8, 0xB6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XB6);
    // 0x80191778: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8019177C: bnel        $at, $zero, L_8019178C
    if (ctx->r1 != 0) {
        // 0x80191780: lhu         $t9, 0xBC($s0)
        ctx->r25 = MEM_HU(ctx->r16, 0XBC);
            goto L_8019178C;
    }
    goto skip_2;
    // 0x80191780: lhu         $t9, 0xBC($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XBC);
    skip_2:
    // 0x80191784: sh          $zero, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = 0;
    // 0x80191788: lhu         $t9, 0xBC($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XBC);
L_8019178C:
    // 0x8019178C: bne         $t9, $zero, L_80191814
    if (ctx->r25 != 0) {
        // 0x80191790: addiu       $t0, $zero, 0x1E
        ctx->r8 = ADD32(0, 0X1E);
            goto L_80191814;
    }
    // 0x80191790: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x80191794: jal         0x80004EB0
    // 0x80191798: sh          $t0, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r8;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x80191798: sh          $t0, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r8;
    after_4:
    // 0x8019179C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801917A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801917A4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801917A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801917AC: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x801917B0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x801917B4: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x801917B8: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x801917BC: lwc1        $f8, 0x74($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X74);
    // 0x801917C0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801917C4: jal         0x80004EB0
    // 0x801917C8: swc1        $f10, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x801917C8: swc1        $f10, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f10.u32l;
    after_5:
    // 0x801917CC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801917D0: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x801917D4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801917D8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801917DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801917E0: lwc1        $f4, 0x78($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X78);
    // 0x801917E4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801917E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801917EC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801917F0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801917F4: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801917F8: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801917FC: swc1        $f6, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f6.u32l;
    // 0x80191800: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80191804: lwc1        $f4, 0xE38($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XE38);
    // 0x80191808: lwc1        $f10, 0x138($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X138);
    // 0x8019180C: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80191810: swc1        $f8, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f8.u32l;
L_80191814:
    // 0x80191814: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80191818: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x8019181C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80191820: lwc1        $f6, 0x120($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X120);
    // 0x80191824: lwc1        $f8, 0x118($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X118);
    // 0x80191828: lwc1        $f10, 0xC8($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XC8);
    // 0x8019182C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80191830: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80191834: lwc1        $f10, 0x11C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x80191838: swc1        $f4, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f4.u32l;
    // 0x8019183C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80191840: sub.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80191844: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80191848: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x8019184C: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80191850: lwc1        $f6, 0x120($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X120);
    // 0x80191854: swc1        $f12, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f12.u32l;
    // 0x80191858: sub.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8019185C: jal         0x80005100
    // 0x80191860: swc1        $f14, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_6;
    // 0x80191860: swc1        $f14, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f14.u32l;
    after_6:
    // 0x80191864: jal         0x8009F768
    // 0x80191868: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_7;
    // 0x80191868: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_7:
    // 0x8019186C: lw          $t5, 0x50($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X50);
    // 0x80191870: lh          $t8, 0xB8($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XB8);
    // 0x80191874: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80191878: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8019187C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80191880: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80191884: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80191888: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8019188C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80191890: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80191894: addiu       $t7, $t7, 0x3FE0
    ctx->r15 = ADD32(ctx->r15, 0X3FE0);
    // 0x80191898: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8019189C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x801918A0: bne         $t8, $zero, L_801918B0
    if (ctx->r24 != 0) {
        // 0x801918A4: addu        $v0, $t6, $t7
        ctx->r2 = ADD32(ctx->r14, ctx->r15);
            goto L_801918B0;
    }
    // 0x801918A4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801918A8: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x801918AC: bne         $t9, $zero, L_801918F8
    if (ctx->r25 != 0) {
        // 0x801918B0: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_801918F8;
    }
L_801918B0:
    // 0x801918B0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x801918B4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801918B8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801918BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801918C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801918C4: sb          $zero, 0xCA($s0)
    MEM_B(0XCA, ctx->r16) = 0;
    // 0x801918C8: add.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x801918CC: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x801918D0: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    // 0x801918D4: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x801918D8: nop

    // 0x801918DC: bc1fl       L_801918EC
    if (!c1cs) {
        // 0x801918E0: lhu         $t0, 0xC6($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0XC6);
            goto L_801918EC;
    }
    goto skip_3;
    // 0x801918E0: lhu         $t0, 0xC6($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XC6);
    skip_3:
    // 0x801918E4: sub.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x801918E8: lhu         $t0, 0xC6($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XC6);
L_801918EC:
    // 0x801918EC: bnel        $t0, $zero, L_801918FC
    if (ctx->r8 != 0) {
        // 0x801918F0: lwc1        $f18, 0x64($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
            goto L_801918FC;
    }
    goto skip_4;
    // 0x801918F0: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    skip_4:
    // 0x801918F4: sh          $t1, 0xC6($s0)
    MEM_H(0XC6, ctx->r16) = ctx->r9;
L_801918F8:
    // 0x801918F8: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
L_801918FC:
    // 0x801918FC: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80191900: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80191904: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80191908: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    // 0x8019190C: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80191910: add.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80191914: jal         0x80005100
    // 0x80191918: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_8;
    // 0x80191918: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_8:
    // 0x8019191C: jal         0x8009F768
    // 0x80191920: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_9;
    // 0x80191920: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_9:
    // 0x80191924: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80191928: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019192C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80191930: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80191934: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80191938: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019193C: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x80191940: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x80191944: jal         0x8009BD38
    // 0x80191948: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_10;
    // 0x80191948: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x8019194C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80191950: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80191954: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x80191958: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019195C: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x80191960: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80191964: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x80191968: jal         0x8009BD38
    // 0x8019196C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_11;
    // 0x8019196C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x80191970: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80191974: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80191978: lui         $at, 0x43A5
    ctx->r1 = S32(0X43A5 << 16);
    // 0x8019197C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80191980: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80191984: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80191988: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8019198C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80191990: bc1f        L_801919A4
    if (!c1cs) {
        // 0x80191994: addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
            goto L_801919A4;
    }
    // 0x80191994: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80191998: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8019199C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801919A0: nop

L_801919A4:
    // 0x801919A4: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801919A8: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x801919AC: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x801919B0: jal         0x8009BD38
    // 0x801919B4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_12;
    // 0x801919B4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_12:
    // 0x801919B8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801919BC: lwc1        $f4, 0xE3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XE3C);
    // 0x801919C0: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801919C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801919C8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801919CC: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x801919D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801919D4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801919D8: jal         0x80005E90
    // 0x801919DC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_13;
    // 0x801919DC: nop

    after_13:
    // 0x801919E0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801919E4: lwc1        $f10, 0xE40($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XE40);
    // 0x801919E8: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801919EC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801919F0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801919F4: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801919F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801919FC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80191A00: jal         0x80005D44
    // 0x80191A04: nop

    Matrix_RotateX(rdram, ctx);
        goto after_14;
    // 0x80191A04: nop

    after_14:
    // 0x80191A08: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80191A0C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80191A10: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80191A14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80191A18: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191A1C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80191A20: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80191A24: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80191A28: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x80191A2C: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x80191A30: jal         0x80006A20
    // 0x80191A34: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_15;
    // 0x80191A34: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    after_15:
    // 0x80191A38: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80191A3C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80191A40: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80191A44: swc1        $f4, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f4.u32l;
    // 0x80191A48: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80191A4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80191A50: lw          $t2, 0x40($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X40);
    // 0x80191A54: swc1        $f8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f8.u32l;
    // 0x80191A58: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80191A5C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80191A60: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80191A64: swc1        $f4, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f4.u32l;
    // 0x80191A68: lw          $t4, 0x50($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X50);
    // 0x80191A6C: bnel        $t3, $t4, L_80191B3C
    if (ctx->r11 != ctx->r12) {
        // 0x80191A70: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80191B3C;
    }
    goto skip_5;
    // 0x80191A70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x80191A74: lh          $t5, 0xB8($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XB8);
    // 0x80191A78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80191A7C: bnel        $t5, $zero, L_80191B28
    if (ctx->r13 != 0) {
        // 0x80191A80: lwc1        $f4, 0xEC($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0XEC);
            goto L_80191B28;
    }
    goto skip_6;
    // 0x80191A80: lwc1        $f4, 0xEC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XEC);
    skip_6:
    // 0x80191A84: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80191A88: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80191A8C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80191A90: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80191A94: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80191A98: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80191A9C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80191AA0: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80191AA4: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80191AA8: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80191AAC: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80191AB0: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x80191AB4: swc1        $f6, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f6.u32l;
    // 0x80191AB8: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80191ABC: swc1        $f10, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f10.u32l;
    // 0x80191AC0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80191AC4: swc1        $f4, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f4.u32l;
    // 0x80191AC8: lw          $t6, 0x7DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7DB0);
    // 0x80191ACC: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x80191AD0: bnel        $t7, $zero, L_80191B3C
    if (ctx->r15 != 0) {
        // 0x80191AD4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80191B3C;
    }
    goto skip_7;
    // 0x80191AD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x80191AD8: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x80191ADC: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80191AE0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80191AE4: lwc1        $f8, 0x74($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X74);
    // 0x80191AE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80191AEC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80191AF0: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80191AF4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80191AF8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80191AFC: nop

    // 0x80191B00: bc1fl       L_80191B3C
    if (!c1cs) {
        // 0x80191B04: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80191B3C;
    }
    goto skip_8;
    // 0x80191B04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x80191B08: lwc1        $f12, 0x124($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X124);
    // 0x80191B0C: lwc1        $f14, 0x128($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X128);
    // 0x80191B10: lw          $a2, 0x12C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X12C);
    // 0x80191B14: jal         0x80081BEC
    // 0x80191B18: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_effect_80081BEC(rdram, ctx);
        goto after_16;
    // 0x80191B18: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_16:
    // 0x80191B1C: b           L_80191B3C
    // 0x80191B20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80191B3C;
    // 0x80191B20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80191B24: lwc1        $f4, 0xEC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XEC);
L_80191B28:
    // 0x80191B28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80191B2C: nop

    // 0x80191B30: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80191B34: swc1        $f6, 0xEC($v0)
    MEM_W(0XEC, ctx->r2) = ctx->f6.u32l;
    // 0x80191B38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80191B3C:
    // 0x80191B3C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80191B40: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80191B44: jr          $ra
    // 0x80191B48: nop

    return;
    // 0x80191B48: nop

;}
RECOMP_FUNC void Aquas_801B0FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B0FCC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B0FD0: addiu       $v0, $v0, 0x4308
    ctx->r2 = ADD32(ctx->r2, 0X4308);
    // 0x801B0FD4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B0FD8: lwc1        $f4, 0x1CCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1CCC);
    // 0x801B0FDC: lui         $at, 0xC1E0
    ctx->r1 = S32(0XC1E0 << 16);
    // 0x801B0FE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801B0FE4: swc1        $f4, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->f4.u32l;
    // 0x801B0FE8: lwc1        $f0, 0x110($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X110);
    // 0x801B0FEC: addiu       $t6, $zero, 0x1F4
    ctx->r14 = ADD32(0, 0X1F4);
    // 0x801B0FF0: swc1        $f0, 0xF4($v0)
    MEM_W(0XF4, ctx->r2) = ctx->f0.u32l;
    // 0x801B0FF4: swc1        $f0, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->f0.u32l;
    // 0x801B0FF8: sh          $t6, 0xAE($a0)
    MEM_H(0XAE, ctx->r4) = ctx->r14;
    // 0x801B0FFC: swc1        $f6, 0x13C($v0)
    MEM_W(0X13C, ctx->r2) = ctx->f6.u32l;
    // 0x801B1000: jr          $ra
    // 0x801B1004: nop

    return;
    // 0x801B1004: nop

;}
RECOMP_FUNC void Area6_A6Gorgon_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018C54C: addiu       $sp, $sp, -0x238
    ctx->r29 = ADD32(ctx->r29, -0X238);
    // 0x8018C550: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8018C554: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8018C558: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8018C55C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8018C560: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8018C564: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8018C568: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8018C56C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8018C570: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8018C574: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8018C578: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8018C57C: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8018C580: sw          $a0, 0x238($sp)
    MEM_W(0X238, ctx->r29) = ctx->r4;
    // 0x8018C584: lw          $t6, 0x238($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X238);
    // 0x8018C588: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8018C58C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8018C590: lh          $t7, 0x4E($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4E);
    // 0x8018C594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018C598: bne         $t7, $zero, L_8018C684
    if (ctx->r15 != 0) {
        // 0x8018C59C: nop
    
            goto L_8018C684;
    }
    // 0x8018C59C: nop

    // 0x8018C5A0: jal         0x800B8DD0
    // 0x8018C5A4: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8018C5A4: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_0:
    // 0x8018C5A8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018C5AC: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8018C5B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018C5B4: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x8018C5B8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018C5BC: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8018C5C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C5C4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018C5C8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8018C5CC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018C5D0: lwc1        $f4, 0x2314($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2314);
    // 0x8018C5D4: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8018C5D8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018C5DC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018C5E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018C5E4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018C5E8: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8018C5EC: nop

    // 0x8018C5F0: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8018C5F4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8018C5F8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8018C5FC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018C600: lui         $t8, 0xFFFF
    ctx->r24 = S32(0XFFFF << 16);
    // 0x8018C604: ori         $t8, $t8, 0xFF
    ctx->r24 = ctx->r24 | 0XFF;
    // 0x8018C608: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018C60C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8018C610: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x8018C614: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018C618: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8018C61C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018C620: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8018C624: jal         0x80005C34
    // 0x8018C628: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x8018C628: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_1:
    // 0x8018C62C: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018C630: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C634: lwc1        $f10, 0xA98($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XA98);
    // 0x8018C638: lwc1        $f8, 0x15C($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X15C);
    // 0x8018C63C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018C640: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018C644: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018C648: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8018C64C: jal         0x80005FE0
    // 0x8018C650: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8018C650: nop

    after_2:
    // 0x8018C654: jal         0x80006EB8
    // 0x8018C658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_3;
    // 0x8018C658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8018C65C: lui         $s1, 0x600
    ctx->r17 = S32(0X600 << 16);
    // 0x8018C660: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018C664: lui         $t7, 0x102
    ctx->r15 = S32(0X102 << 16);
    // 0x8018C668: addiu       $t7, $t7, -0x3D20
    ctx->r15 = ADD32(ctx->r15, -0X3D20);
    // 0x8018C66C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018C670: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8018C674: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8018C678: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x8018C67C: b           L_8018D398
    // 0x8018C680: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8018D398;
    // 0x8018C680: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8018C684:
    // 0x8018C684: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x8018C688: addiu       $s3, $s3, 0x22F0
    ctx->r19 = ADD32(ctx->r19, 0X22F0);
    // 0x8018C68C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8018C690: lwc1        $f18, 0x24($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X24);
    // 0x8018C694: c.eq.s      $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f22.fl == ctx->f18.fl;
    // 0x8018C698: nop

    // 0x8018C69C: bc1t        L_8018D394
    if (c1cs) {
        // 0x8018C6A0: addiu       $s1, $sp, 0xD0
        ctx->r17 = ADD32(ctx->r29, 0XD0);
            goto L_8018D394;
    }
    // 0x8018C6A0: addiu       $s1, $sp, 0xD0
    ctx->r17 = ADD32(ctx->r29, 0XD0);
    // 0x8018C6A4: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8018C6A8: addiu       $a0, $a0, -0x766C
    ctx->r4 = ADD32(ctx->r4, -0X766C);
    // 0x8018C6AC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8018C6B0: jal         0x8009AA20
    // 0x8018C6B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Animation_GetFrameData(rdram, ctx);
        goto after_4;
    // 0x8018C6B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8018C6B8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8018C6BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018C6C0: lwc1        $f6, 0x24($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X24);
    // 0x8018C6C4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8018C6C8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8018C6CC: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8018C6D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018C6D4: bc1t        L_8018C8A8
    if (c1cs) {
        // 0x8018C6D8: nop
    
            goto L_8018C8A8;
    }
    // 0x8018C6D8: nop

    // 0x8018C6DC: jal         0x800B8DD0
    // 0x8018C6E0: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    RCP_SetupDL(rdram, ctx);
        goto after_5;
    // 0x8018C6E0: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    after_5:
    // 0x8018C6E4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018C6E8: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8018C6EC: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8018C6F0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018C6F4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8018C6F8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018C6FC: lwc1        $f8, 0x24($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X24);
    // 0x8018C700: lui         $s4, 0x8017
    ctx->r20 = S32(0X8017 << 16);
    // 0x8018C704: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8018C708: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8018C70C: addiu       $s4, $s4, 0x7DB0
    ctx->r20 = ADD32(ctx->r20, 0X7DB0);
    // 0x8018C710: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8018C714: nop

    // 0x8018C718: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8018C71C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8018C720: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8018C724: lw          $t6, 0x7E7C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7E7C);
    // 0x8018C728: swc1        $f22, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f22.u32l;
    // 0x8018C72C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8018C730: bnel        $t7, $zero, L_8018C740
    if (ctx->r15 != 0) {
        // 0x8018C734: lw          $t8, 0x0($s4)
        ctx->r24 = MEM_W(ctx->r20, 0X0);
            goto L_8018C740;
    }
    goto skip_0;
    // 0x8018C734: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    skip_0:
    // 0x8018C738: swc1        $f22, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f22.u32l;
    // 0x8018C73C: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
L_8018C740:
    // 0x8018C740: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8018C744: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018C748: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8018C74C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C750: lwc1        $f8, 0xA9C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XA9C);
    // 0x8018C754: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8018C758: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018C75C: swc1        $f22, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f22.u32l;
    // 0x8018C760: swc1        $f22, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f22.u32l;
    // 0x8018C764: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018C768: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018C76C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018C770: nop

    // 0x8018C774: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018C778: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018C77C: jal         0x80005FE0
    // 0x8018C780: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x8018C780: nop

    after_6:
    // 0x8018C784: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018C788: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018C78C: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x8018C790: jal         0x80006970
    // 0x8018C794: addiu       $a2, $sp, 0xB8
    ctx->r6 = ADD32(ctx->r29, 0XB8);
    Matrix_MultVec3f(rdram, ctx);
        goto after_7;
    // 0x8018C794: addiu       $a2, $sp, 0xB8
    ctx->r6 = ADD32(ctx->r29, 0XB8);
    after_7:
    // 0x8018C798: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8018C79C: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x8018C7A0: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8018C7A4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018C7A8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8018C7AC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018C7B0: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
    // 0x8018C7B4: jal         0x80005B00
    // 0x8018C7B8: lw          $a2, 0xBC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XBC);
    Matrix_Translate(rdram, ctx);
        goto after_8;
    // 0x8018C7B8: lw          $a2, 0xBC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XBC);
    after_8:
    // 0x8018C7BC: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018C7C0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018C7C4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018C7C8: lwc1        $f0, 0x3F8($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X3F8);
    // 0x8018C7CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018C7D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018C7D4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018C7D8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018C7DC: jal         0x80005C34
    // 0x8018C7E0: nop

    Matrix_Scale(rdram, ctx);
        goto after_9;
    // 0x8018C7E0: nop

    after_9:
    // 0x8018C7E4: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8018C7E8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018C7EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018C7F0: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8018C7F4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C7F8: lwc1        $f8, 0xAA0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XAA0);
    // 0x8018C7FC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8018C800: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018C804: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018C808: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018C80C: nop

    // 0x8018C810: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018C814: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018C818: jal         0x80005FE0
    // 0x8018C81C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_10;
    // 0x8018C81C: nop

    after_10:
    // 0x8018C820: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018C824: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018C828: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018C82C: lw          $a1, 0x160($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X160);
    // 0x8018C830: lw          $a2, 0x164($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X164);
    // 0x8018C834: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018C838: jal         0x80005C34
    // 0x8018C83C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_11;
    // 0x8018C83C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_11:
    // 0x8018C840: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8018C844: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018C848: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018C84C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8018C850: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C854: lwc1        $f10, 0xAA4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XAA4);
    // 0x8018C858: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8018C85C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018C860: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018C864: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8018C868: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018C86C: nop

    // 0x8018C870: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018C874: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8018C878: jal         0x80005FE0
    // 0x8018C87C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_12;
    // 0x8018C87C: nop

    after_12:
    // 0x8018C880: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018C884: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018C888: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018C88C: lw          $a1, 0x160($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X160);
    // 0x8018C890: lw          $a2, 0x164($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X164);
    // 0x8018C894: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018C898: jal         0x80005C34
    // 0x8018C89C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_13;
    // 0x8018C89C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_13:
    // 0x8018C8A0: b           L_8018C95C
    // 0x8018C8A4: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
        goto L_8018C95C;
    // 0x8018C8A4: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
L_8018C8A8:
    // 0x8018C8A8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8018C8AC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8018C8B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018C8B4: jal         0x800B8DD0
    // 0x8018C8B8: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    RCP_SetupDL(rdram, ctx);
        goto after_14;
    // 0x8018C8B8: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_14:
    // 0x8018C8BC: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018C8C0: lh          $t7, 0x5C($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X5C);
    // 0x8018C8C4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8018C8C8: beql        $t8, $zero, L_8018C8FC
    if (ctx->r24 == 0) {
        // 0x8018C8CC: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8018C8FC;
    }
    goto skip_1;
    // 0x8018C8CC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x8018C8D0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018C8D4: lui         $t7, 0xFF00
    ctx->r15 = S32(0XFF00 << 16);
    // 0x8018C8D8: ori         $t7, $t7, 0xFF
    ctx->r15 = ctx->r15 | 0XFF;
    // 0x8018C8DC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8018C8E0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8018C8E4: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8018C8E8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8018C8EC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8018C8F0: b           L_8018C960
    // 0x8018C8F4: lwc1        $f18, 0xFC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XFC);
        goto L_8018C960;
    // 0x8018C8F4: lwc1        $f18, 0xFC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XFC);
    // 0x8018C8F8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8018C8FC:
    // 0x8018C8FC: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8018C900: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018C904: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8018C908: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018C90C: lwc1        $f18, 0x2C($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X2C);
    // 0x8018C910: lwc1        $f6, 0x28($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X28);
    // 0x8018C914: lwc1        $f10, 0x30($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X30);
    // 0x8018C918: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8018C91C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8018C920: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8018C924: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8018C928: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8018C92C: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8018C930: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8018C934: nop

    // 0x8018C938: sll         $t6, $t8, 24
    ctx->r14 = S32(ctx->r24 << 24);
    // 0x8018C93C: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8018C940: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8018C944: nop

    // 0x8018C948: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x8018C94C: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x8018C950: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8018C954: ori         $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 | 0XFF;
    // 0x8018C958: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_8018C95C:
    // 0x8018C95C: lwc1        $f18, 0xFC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XFC);
L_8018C960:
    // 0x8018C960: lwc1        $f4, 0xD8($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XD8);
    // 0x8018C964: lwc1        $f8, 0x108($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X108);
    // 0x8018C968: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8018C96C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8018C970: lwc1        $f18, 0x114($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8018C974: addiu       $t8, $t8, 0x4660
    ctx->r24 = ADD32(ctx->r24, 0X4660);
    // 0x8018C978: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x8018C97C: swc1        $f6, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f6.u32l;
    // 0x8018C980: lwc1        $f10, 0xD8($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XD8);
    // 0x8018C984: addiu       $t7, $t5, 0x40
    ctx->r15 = ADD32(ctx->r13, 0X40);
    // 0x8018C988: addiu       $a1, $a1, -0x7460
    ctx->r5 = ADD32(ctx->r5, -0X7460);
    // 0x8018C98C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8018C990: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8018C994: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8018C998: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8018C99C: swc1        $f16, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f16.u32l;
    // 0x8018C9A0: lwc1        $f4, 0xD8($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XD8);
    // 0x8018C9A4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018C9A8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018C9AC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8018C9B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8018C9B4: jal         0x8009A72C
    // 0x8018C9B8: swc1        $f6, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f6.u32l;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_15;
    // 0x8018C9B8: swc1        $f6, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f6.u32l;
    after_15:
    // 0x8018C9BC: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018C9C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018C9C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018C9C8: lwc1        $f8, 0x3F8($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X3F8);
    // 0x8018C9CC: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8018C9D0: nop

    // 0x8018C9D4: bc1f        L_8018D140
    if (!c1cs) {
        // 0x8018C9D8: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_8018D140;
    }
    // 0x8018C9D8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8018C9DC: lui         $fp, 0x801C
    ctx->r30 = S32(0X801C << 16);
    // 0x8018C9E0: lui         $s7, 0x801C
    ctx->r23 = S32(0X801C << 16);
    // 0x8018C9E4: lui         $s6, 0x801C
    ctx->r22 = S32(0X801C << 16);
    // 0x8018C9E8: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x8018C9EC: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x8018C9F0: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x8018C9F4: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x8018C9F8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018C9FC: addiu       $s2, $s2, -0x1200
    ctx->r18 = ADD32(ctx->r18, -0X1200);
    // 0x8018CA00: addiu       $s3, $s3, -0x1170
    ctx->r19 = ADD32(ctx->r19, -0X1170);
    // 0x8018CA04: addiu       $s4, $s4, -0x1140
    ctx->r20 = ADD32(ctx->r20, -0X1140);
    // 0x8018CA08: addiu       $s5, $s5, -0x1080
    ctx->r21 = ADD32(ctx->r21, -0X1080);
    // 0x8018CA0C: addiu       $s6, $s6, -0xFF0
    ctx->r22 = ADD32(ctx->r22, -0XFF0);
    // 0x8018CA10: addiu       $s7, $s7, -0xFC0
    ctx->r23 = ADD32(ctx->r23, -0XFC0);
    // 0x8018CA14: addiu       $fp, $fp, -0xF00
    ctx->r30 = ADD32(ctx->r30, -0XF00);
    // 0x8018CA18: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018CA1C: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x8018CA20: addiu       $s0, $zero, 0xC
    ctx->r16 = ADD32(0, 0XC);
L_8018CA24:
    // 0x8018CA24: lh          $t9, 0xCA($t3)
    ctx->r25 = MEM_H(ctx->r11, 0XCA);
    // 0x8018CA28: bnel        $t9, $zero, L_8018CD40
    if (ctx->r25 != 0) {
        // 0x8018CA2C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8018CD40;
    }
    goto skip_2;
    // 0x8018CA2C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x8018CA30: lh          $t6, 0x4E($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4E);
    // 0x8018CA34: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018CA38: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x8018CA3C: beq         $t6, $at, L_8018CD3C
    if (ctx->r14 == ctx->r1) {
        // 0x8018CA40: lui         $t7, 0x801C
        ctx->r15 = S32(0X801C << 16);
            goto L_8018CD3C;
    }
    // 0x8018CA40: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8018CA44: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x8018CA48: lw          $t7, 0x2258($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2258);
    // 0x8018CA4C: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x8018CA50: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8018CA54: bnel        $t7, $zero, L_8018CD40
    if (ctx->r15 != 0) {
        // 0x8018CA58: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8018CD40;
    }
    goto skip_3;
    // 0x8018CA58: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_3:
    // 0x8018CA5C: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x8018CA60: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x8018CA64: bnel        $t9, $zero, L_8018CD40
    if (ctx->r25 != 0) {
        // 0x8018CA68: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8018CD40;
    }
    goto skip_4;
    // 0x8018CA68: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_4:
    // 0x8018CA6C: lh          $t6, 0xBE($t3)
    ctx->r14 = MEM_H(ctx->r11, 0XBE);
    // 0x8018CA70: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018CA74: beql        $t6, $zero, L_8018CD40
    if (ctx->r14 == 0) {
        // 0x8018CA78: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8018CD40;
    }
    goto skip_5;
    // 0x8018CA78: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x8018CA7C: lw          $t7, 0x7854($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7854);
    // 0x8018CA80: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8018CA84: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018CA88: beq         $t7, $at, L_8018CD3C
    if (ctx->r15 == ctx->r1) {
        // 0x8018CA8C: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_8018CD3C;
    }
    // 0x8018CA8C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018CA90: lwc1        $f18, 0xAA8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XAA8);
    // 0x8018CA94: lwc1        $f16, 0x14($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X14);
    // 0x8018CA98: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x8018CA9C: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x8018CAA0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018CAA4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018CAA8: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x8018CAAC: addiu       $t6, $t9, 0x1AC
    ctx->r14 = ADD32(ctx->r25, 0X1AC);
    // 0x8018CAB0: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x8018CAB4: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x8018CAB8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018CABC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8018CAC0: jal         0x80005E90
    // 0x8018CAC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Matrix_RotateY(rdram, ctx);
        goto after_16;
    // 0x8018CAC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x8018CAC8: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018CACC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018CAD0: lwc1        $f8, 0xAAC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XAAC);
    // 0x8018CAD4: lwc1        $f6, 0x10($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X10);
    // 0x8018CAD8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018CADC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018CAE0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018CAE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018CAE8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018CAEC: jal         0x80005D44
    // 0x8018CAF0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_17;
    // 0x8018CAF0: nop

    after_17:
    // 0x8018CAF4: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018CAF8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018CAFC: lwc1        $f18, 0xAB0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XAB0);
    // 0x8018CB00: lwc1        $f16, 0x18($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X18);
    // 0x8018CB04: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018CB08: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018CB0C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018CB10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018CB14: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8018CB18: jal         0x80005FE0
    // 0x8018CB1C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_18;
    // 0x8018CB1C: nop

    after_18:
    // 0x8018CB20: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018CB24: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018CB28: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8018CB2C: jal         0x80006970
    // 0x8018CB30: addiu       $a2, $sp, 0xC4
    ctx->r6 = ADD32(ctx->r29, 0XC4);
    Matrix_MultVec3f(rdram, ctx);
        goto after_19;
    // 0x8018CB30: addiu       $a2, $sp, 0xC4
    ctx->r6 = ADD32(ctx->r29, 0XC4);
    after_19:
    // 0x8018CB34: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018CB38: lwc1        $f18, 0xCC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8018CB3C: lwc1        $f16, 0xC4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8018CB40: lwc1        $f10, 0xC($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XC);
    // 0x8018CB44: lwc1        $f8, 0x4($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8018CB48: lwc1        $f6, 0x8($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X8);
    // 0x8018CB4C: add.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8018CB50: lwc1        $f10, 0xC8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8018CB54: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x8018CB58: add.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8018CB5C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8018CB60: jal         0x8007D0E0
    // 0x8018CB64: add.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f10.fl;
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_20;
    // 0x8018CB64: add.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f10.fl;
    after_20:
    // 0x8018CB68: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018CB6C: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8018CB70: lwc1        $f4, 0xC8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8018CB74: lwc1        $f8, 0x4($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8018CB78: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018CB7C: lw          $v0, 0x22B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X22B8);
    // 0x8018CB80: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018CB84: lwc1        $f10, 0xCC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8018CB88: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8018CB8C: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8018CB90: swc1        $f16, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f16.u32l;
    // 0x8018CB94: lwc1        $f18, 0x8($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X8);
    // 0x8018CB98: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x8018CB9C: addiu       $t2, $t2, -0xE40
    ctx->r10 = ADD32(ctx->r10, -0XE40);
    // 0x8018CBA0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018CBA4: addiu       $t1, $t1, -0xE70
    ctx->r9 = ADD32(ctx->r9, -0XE70);
    // 0x8018CBA8: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x8018CBAC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018CBB0: swc1        $f6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f6.u32l;
    // 0x8018CBB4: lwc1        $f8, 0xC($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XC);
    // 0x8018CBB8: addiu       $ra, $zero, 0x2
    ctx->r31 = ADD32(0, 0X2);
    // 0x8018CBBC: ori         $a1, $a1, 0xB009
    ctx->r5 = ctx->r5 | 0XB009;
    // 0x8018CBC0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018CBC4: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x8018CBC8: bne         $v0, $zero, L_8018CC00
    if (ctx->r2 != 0) {
        // 0x8018CBCC: swc1        $f16, 0xC0($sp)
        MEM_W(0XC0, ctx->r29) = ctx->f16.u32l;
            goto L_8018CC00;
    }
    // 0x8018CBCC: swc1        $f16, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f16.u32l;
    // 0x8018CBD0: jal         0x8007A6F0
    // 0x8018CBD4: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_21;
    // 0x8018CBD4: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    after_21:
    // 0x8018CBD8: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8018CBDC: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8018CBE0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018CBE4: lw          $v0, 0x22B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X22B8);
    // 0x8018CBE8: addiu       $t2, $t2, -0xE40
    ctx->r10 = ADD32(ctx->r10, -0XE40);
    // 0x8018CBEC: addiu       $t1, $t1, -0xE70
    ctx->r9 = ADD32(ctx->r9, -0XE70);
    // 0x8018CBF0: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x8018CBF4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018CBF8: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018CBFC: addiu       $ra, $zero, 0x2
    ctx->r31 = ADD32(0, 0X2);
L_8018CC00:
    // 0x8018CC00: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018CC04: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8018CC08: addiu       $v1, $v1, 0x2250
    ctx->r3 = ADD32(ctx->r3, 0X2250);
    // 0x8018CC0C: sw          $t7, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->r15;
    // 0x8018CC10: andi        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 & 0X1;
    // 0x8018CC14: sw          $t9, 0x68($v1)
    MEM_W(0X68, ctx->r3) = ctx->r25;
    // 0x8018CC18: lh          $t6, 0xBE($t3)
    ctx->r14 = MEM_H(ctx->r11, 0XBE);
    // 0x8018CC1C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8018CC20: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x8018CC24: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8018CC28: sh          $t7, 0xBE($t3)
    MEM_H(0XBE, ctx->r11) = ctx->r15;
    // 0x8018CC2C: lh          $t8, 0xBE($t3)
    ctx->r24 = MEM_H(ctx->r11, 0XBE);
    // 0x8018CC30: bgtzl       $t8, L_8018CD40
    if (SIGNED(ctx->r24) > 0) {
        // 0x8018CC34: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8018CD40;
    }
    goto skip_6;
    // 0x8018CC34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_6:
    // 0x8018CC38: sh          $t9, 0xAC($t3)
    MEM_H(0XAC, ctx->r11) = ctx->r25;
    // 0x8018CC3C: sh          $t4, 0xD4($t5)
    MEM_H(0XD4, ctx->r13) = ctx->r12;
    // 0x8018CC40: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8018CC44: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018CC48: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8018CC4C: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x8018CC50: swc1        $f22, 0x130($v0)
    MEM_W(0X130, ctx->r2) = ctx->f22.u32l;
    // 0x8018CC54: swc1        $f22, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->f22.u32l;
    // 0x8018CC58: swc1        $f22, 0x124($v0)
    MEM_W(0X124, ctx->r2) = ctx->f22.u32l;
    // 0x8018CC5C: swc1        $f22, 0x100($v0)
    MEM_W(0X100, ctx->r2) = ctx->f22.u32l;
    // 0x8018CC60: swc1        $f18, 0x13C($v0)
    MEM_W(0X13C, ctx->r2) = ctx->f18.u32l;
L_8018CC64:
    // 0x8018CC64: bne         $s1, $zero, L_8018CCA8
    if (ctx->r17 != 0) {
        // 0x8018CC68: nop
    
            goto L_8018CCA8;
    }
    // 0x8018CC68: nop

    // 0x8018CC6C: multu       $t0, $s0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018CC70: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8018CC74: addiu       $t7, $t7, -0x1290
    ctx->r15 = ADD32(ctx->r15, -0X1290);
    // 0x8018CC78: sll         $a1, $t0, 2
    ctx->r5 = S32(ctx->r8 << 2);
    // 0x8018CC7C: addu        $t8, $s3, $a1
    ctx->r24 = ADD32(ctx->r19, ctx->r5);
    // 0x8018CC80: swc1        $f20, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f20.u32l;
    // 0x8018CC84: addu        $t9, $s4, $a1
    ctx->r25 = ADD32(ctx->r20, ctx->r5);
    // 0x8018CC88: swc1        $f20, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f20.u32l;
    // 0x8018CC8C: mflo        $v0
    ctx->r2 = lo;
    // 0x8018CC90: addu        $v1, $s2, $v0
    ctx->r3 = ADD32(ctx->r18, ctx->r2);
    // 0x8018CC94: addu        $a0, $v0, $t7
    ctx->r4 = ADD32(ctx->r2, ctx->r15);
    // 0x8018CC98: swc1        $f22, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f22.u32l;
    // 0x8018CC9C: swc1        $f22, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f22.u32l;
    // 0x8018CCA0: swc1        $f22, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f22.u32l;
    // 0x8018CCA4: swc1        $f22, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f22.u32l;
L_8018CCA8:
    // 0x8018CCA8: bne         $s1, $t4, L_8018CCEC
    if (ctx->r17 != ctx->r12) {
        // 0x8018CCAC: nop
    
            goto L_8018CCEC;
    }
    // 0x8018CCAC: nop

    // 0x8018CCB0: multu       $t0, $s0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018CCB4: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8018CCB8: addiu       $t6, $t6, -0x1110
    ctx->r14 = ADD32(ctx->r14, -0X1110);
    // 0x8018CCBC: sll         $a1, $t0, 2
    ctx->r5 = S32(ctx->r8 << 2);
    // 0x8018CCC0: addu        $t7, $s6, $a1
    ctx->r15 = ADD32(ctx->r22, ctx->r5);
    // 0x8018CCC4: swc1        $f20, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f20.u32l;
    // 0x8018CCC8: addu        $t8, $s7, $a1
    ctx->r24 = ADD32(ctx->r23, ctx->r5);
    // 0x8018CCCC: swc1        $f20, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f20.u32l;
    // 0x8018CCD0: mflo        $v0
    ctx->r2 = lo;
    // 0x8018CCD4: addu        $v1, $s5, $v0
    ctx->r3 = ADD32(ctx->r21, ctx->r2);
    // 0x8018CCD8: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x8018CCDC: swc1        $f22, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f22.u32l;
    // 0x8018CCE0: swc1        $f22, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f22.u32l;
    // 0x8018CCE4: swc1        $f22, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f22.u32l;
    // 0x8018CCE8: swc1        $f22, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f22.u32l;
L_8018CCEC:
    // 0x8018CCEC: bnel        $s1, $ra, L_8018CD34
    if (ctx->r17 != ctx->r31) {
        // 0x8018CCF0: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8018CD34;
    }
    goto skip_7;
    // 0x8018CCF0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_7:
    // 0x8018CCF4: multu       $t0, $s0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018CCF8: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8018CCFC: addiu       $t9, $t9, -0xF90
    ctx->r25 = ADD32(ctx->r25, -0XF90);
    // 0x8018CD00: sll         $a1, $t0, 2
    ctx->r5 = S32(ctx->r8 << 2);
    // 0x8018CD04: addu        $t6, $t1, $a1
    ctx->r14 = ADD32(ctx->r9, ctx->r5);
    // 0x8018CD08: swc1        $f20, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f20.u32l;
    // 0x8018CD0C: addu        $t7, $t2, $a1
    ctx->r15 = ADD32(ctx->r10, ctx->r5);
    // 0x8018CD10: swc1        $f20, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f20.u32l;
    // 0x8018CD14: mflo        $v0
    ctx->r2 = lo;
    // 0x8018CD18: addu        $v1, $fp, $v0
    ctx->r3 = ADD32(ctx->r30, ctx->r2);
    // 0x8018CD1C: addu        $a0, $v0, $t9
    ctx->r4 = ADD32(ctx->r2, ctx->r25);
    // 0x8018CD20: swc1        $f22, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f22.u32l;
    // 0x8018CD24: swc1        $f22, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f22.u32l;
    // 0x8018CD28: swc1        $f22, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f22.u32l;
    // 0x8018CD2C: swc1        $f22, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f22.u32l;
    // 0x8018CD30: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_8018CD34:
    // 0x8018CD34: bne         $t0, $s0, L_8018CC64
    if (ctx->r8 != ctx->r16) {
        // 0x8018CD38: nop
    
            goto L_8018CC64;
    }
    // 0x8018CD38: nop

L_8018CD3C:
    // 0x8018CD3C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8018CD40:
    // 0x8018CD40: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018CD44: bne         $s1, $at, L_8018CA24
    if (ctx->r17 != ctx->r1) {
        // 0x8018CD48: addiu       $t3, $t3, 0x2
        ctx->r11 = ADD32(ctx->r11, 0X2);
            goto L_8018CA24;
    }
    // 0x8018CD48: addiu       $t3, $t3, 0x2
    ctx->r11 = ADD32(ctx->r11, 0X2);
    // 0x8018CD4C: lh          $t8, 0x88($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X88);
    // 0x8018CD50: lw          $a2, 0x13C($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X13C);
    // 0x8018CD54: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018CD58: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8018CD5C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8018CD60: lwc1        $f6, 0x100($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X100);
    // 0x8018CD64: lwc1        $f4, 0x124($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X124);
    // 0x8018CD68: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x8018CD6C: addiu       $a0, $a0, -0x1290
    ctx->r4 = ADD32(ctx->r4, -0X1290);
    // 0x8018CD70: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018CD74: addiu       $a3, $t5, 0x1AC
    ctx->r7 = ADD32(ctx->r13, 0X1AC);
    // 0x8018CD78: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8018CD7C: lh          $t6, 0xBE($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XBE);
    // 0x8018CD80: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8018CD84: lwc1        $f10, 0xD8($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XD8);
    // 0x8018CD88: jal         0x8018BCD4
    // 0x8018CD8C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    Area6_8018BCD4(rdram, ctx);
        goto after_22;
    // 0x8018CD8C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_22:
    // 0x8018CD90: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018CD94: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x8018CD98: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018CD9C: lh          $t7, 0x8A($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X8A);
    // 0x8018CDA0: lw          $a2, 0x140($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X140);
    // 0x8018CDA4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018CDA8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8018CDAC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018CDB0: lwc1        $f18, 0x104($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X104);
    // 0x8018CDB4: lwc1        $f16, 0x128($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X128);
    // 0x8018CDB8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018CDBC: addiu       $a0, $a0, -0x1110
    ctx->r4 = ADD32(ctx->r4, -0X1110);
    // 0x8018CDC0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018CDC4: addiu       $a3, $t5, 0x1B8
    ctx->r7 = ADD32(ctx->r13, 0X1B8);
    // 0x8018CDC8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8018CDCC: lh          $t9, 0xC0($t5)
    ctx->r25 = MEM_H(ctx->r13, 0XC0);
    // 0x8018CDD0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8018CDD4: lwc1        $f6, 0xD8($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XD8);
    // 0x8018CDD8: jal         0x8018BCD4
    // 0x8018CDDC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    Area6_8018BCD4(rdram, ctx);
        goto after_23;
    // 0x8018CDDC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_23:
    // 0x8018CDE0: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018CDE4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018CDE8: addiu       $a0, $a0, -0xF90
    ctx->r4 = ADD32(ctx->r4, -0XF90);
    // 0x8018CDEC: lh          $t6, 0x8C($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X8C);
    // 0x8018CDF0: lw          $a2, 0x144($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X144);
    // 0x8018CDF4: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    // 0x8018CDF8: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8018CDFC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018CE00: lwc1        $f10, 0x108($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X108);
    // 0x8018CE04: lwc1        $f8, 0x12C($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X12C);
    // 0x8018CE08: addiu       $a3, $t5, 0x1C4
    ctx->r7 = ADD32(ctx->r13, 0X1C4);
    // 0x8018CE0C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018CE10: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8018CE14: lh          $t8, 0xC2($t5)
    ctx->r24 = MEM_H(ctx->r13, 0XC2);
    // 0x8018CE18: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018CE1C: lwc1        $f18, 0xD8($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XD8);
    // 0x8018CE20: jal         0x8018BCD4
    // 0x8018CE24: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    Area6_8018BCD4(rdram, ctx);
        goto after_24;
    // 0x8018CE24: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_24:
    // 0x8018CE28: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018CE2C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018CE30: addiu       $ra, $zero, 0x2
    ctx->r31 = ADD32(0, 0X2);
    // 0x8018CE34: lh          $t9, 0xA6($t5)
    ctx->r25 = MEM_H(ctx->r13, 0XA6);
    // 0x8018CE38: beql        $t9, $zero, L_8018CEAC
    if (ctx->r25 == 0) {
        // 0x8018CE3C: lh          $t8, 0xA8($t5)
        ctx->r24 = MEM_H(ctx->r13, 0XA8);
            goto L_8018CEAC;
    }
    goto skip_8;
    // 0x8018CE3C: lh          $t8, 0xA8($t5)
    ctx->r24 = MEM_H(ctx->r13, 0XA8);
    skip_8:
    // 0x8018CE40: lh          $t6, 0x4E($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4E);
    // 0x8018CE44: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8018CE48: addiu       $s1, $s1, 0x22F0
    ctx->r17 = ADD32(ctx->r17, 0X22F0);
    // 0x8018CE4C: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8018CE50: bne         $at, $zero, L_8018CEA8
    if (ctx->r1 != 0) {
        // 0x8018CE54: lui         $at, 0x437F
        ctx->r1 = S32(0X437F << 16);
            goto L_8018CEA8;
    }
    // 0x8018CE54: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8018CE58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018CE5C: lwc1        $f6, 0x24($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8018CE60: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8018CE64: addiu       $s0, $s0, 0x2250
    ctx->r16 = ADD32(ctx->r16, 0X2250);
    // 0x8018CE68: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8018CE6C: nop

    // 0x8018CE70: bc1fl       L_8018CEAC
    if (!c1cs) {
        // 0x8018CE74: lh          $t8, 0xA8($t5)
        ctx->r24 = MEM_H(ctx->r13, 0XA8);
            goto L_8018CEAC;
    }
    goto skip_9;
    // 0x8018CE74: lh          $t8, 0xA8($t5)
    ctx->r24 = MEM_H(ctx->r13, 0XA8);
    skip_9:
    // 0x8018CE78: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8018CE7C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018CE80: addiu       $a0, $a0, -0xE10
    ctx->r4 = ADD32(ctx->r4, -0XE10);
    // 0x8018CE84: bne         $t7, $zero, L_8018CEA8
    if (ctx->r15 != 0) {
        // 0x8018CE88: addiu       $a2, $t5, 0x1D0
        ctx->r6 = ADD32(ctx->r13, 0X1D0);
            goto L_8018CEA8;
    }
    // 0x8018CE88: addiu       $a2, $t5, 0x1D0
    ctx->r6 = ADD32(ctx->r13, 0X1D0);
    // 0x8018CE8C: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x8018CE90: lw          $a3, 0xD8($t5)
    ctx->r7 = MEM_W(ctx->r13, 0XD8);
    // 0x8018CE94: jal         0x8018C0D0
    // 0x8018CE98: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    Area6_8018C0D0(rdram, ctx);
        goto after_25;
    // 0x8018CE98: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_25:
    // 0x8018CE9C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018CEA0: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018CEA4: addiu       $ra, $zero, 0x2
    ctx->r31 = ADD32(0, 0X2);
L_8018CEA8:
    // 0x8018CEA8: lh          $t8, 0xA8($t5)
    ctx->r24 = MEM_H(ctx->r13, 0XA8);
L_8018CEAC:
    // 0x8018CEAC: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8018CEB0: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8018CEB4: addiu       $s1, $s1, 0x22F0
    ctx->r17 = ADD32(ctx->r17, 0X22F0);
    // 0x8018CEB8: beq         $t8, $zero, L_8018CF18
    if (ctx->r24 == 0) {
        // 0x8018CEBC: addiu       $s0, $s0, 0x2250
        ctx->r16 = ADD32(ctx->r16, 0X2250);
            goto L_8018CF18;
    }
    // 0x8018CEBC: addiu       $s0, $s0, 0x2250
    ctx->r16 = ADD32(ctx->r16, 0X2250);
    // 0x8018CEC0: lh          $t9, 0x4E($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X4E);
    // 0x8018CEC4: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x8018CEC8: bne         $at, $zero, L_8018CF18
    if (ctx->r1 != 0) {
        // 0x8018CECC: lui         $at, 0x437F
        ctx->r1 = S32(0X437F << 16);
            goto L_8018CF18;
    }
    // 0x8018CECC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8018CED0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018CED4: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8018CED8: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8018CEDC: nop

    // 0x8018CEE0: bc1fl       L_8018CF1C
    if (!c1cs) {
        // 0x8018CEE4: lh          $t7, 0xAA($t5)
        ctx->r15 = MEM_H(ctx->r13, 0XAA);
            goto L_8018CF1C;
    }
    goto skip_10;
    // 0x8018CEE4: lh          $t7, 0xAA($t5)
    ctx->r15 = MEM_H(ctx->r13, 0XAA);
    skip_10:
    // 0x8018CEE8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8018CEEC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018CEF0: addiu       $a0, $a0, -0xDE0
    ctx->r4 = ADD32(ctx->r4, -0XDE0);
    // 0x8018CEF4: bne         $t6, $zero, L_8018CF18
    if (ctx->r14 != 0) {
        // 0x8018CEF8: addiu       $a2, $t5, 0x1DC
        ctx->r6 = ADD32(ctx->r13, 0X1DC);
            goto L_8018CF18;
    }
    // 0x8018CEF8: addiu       $a2, $t5, 0x1DC
    ctx->r6 = ADD32(ctx->r13, 0X1DC);
    // 0x8018CEFC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018CF00: lw          $a3, 0xD8($t5)
    ctx->r7 = MEM_W(ctx->r13, 0XD8);
    // 0x8018CF04: jal         0x8018C0D0
    // 0x8018CF08: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    Area6_8018C0D0(rdram, ctx);
        goto after_26;
    // 0x8018CF08: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_26:
    // 0x8018CF0C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018CF10: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018CF14: addiu       $ra, $zero, 0x2
    ctx->r31 = ADD32(0, 0X2);
L_8018CF18:
    // 0x8018CF18: lh          $t7, 0xAA($t5)
    ctx->r15 = MEM_H(ctx->r13, 0XAA);
L_8018CF1C:
    // 0x8018CF1C: beql        $t7, $zero, L_8018CF80
    if (ctx->r15 == 0) {
        // 0x8018CF20: lh          $v0, 0xBA($t5)
        ctx->r2 = MEM_H(ctx->r13, 0XBA);
            goto L_8018CF80;
    }
    goto skip_11;
    // 0x8018CF20: lh          $v0, 0xBA($t5)
    ctx->r2 = MEM_H(ctx->r13, 0XBA);
    skip_11:
    // 0x8018CF24: lh          $t8, 0x4E($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X4E);
    // 0x8018CF28: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x8018CF2C: bne         $at, $zero, L_8018CF7C
    if (ctx->r1 != 0) {
        // 0x8018CF30: lui         $at, 0x437F
        ctx->r1 = S32(0X437F << 16);
            goto L_8018CF7C;
    }
    // 0x8018CF30: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8018CF34: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018CF38: lwc1        $f18, 0x24($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8018CF3C: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x8018CF40: nop

    // 0x8018CF44: bc1fl       L_8018CF80
    if (!c1cs) {
        // 0x8018CF48: lh          $v0, 0xBA($t5)
        ctx->r2 = MEM_H(ctx->r13, 0XBA);
            goto L_8018CF80;
    }
    goto skip_12;
    // 0x8018CF48: lh          $v0, 0xBA($t5)
    ctx->r2 = MEM_H(ctx->r13, 0XBA);
    skip_12:
    // 0x8018CF4C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8018CF50: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018CF54: addiu       $a0, $a0, -0xDB0
    ctx->r4 = ADD32(ctx->r4, -0XDB0);
    // 0x8018CF58: bne         $t9, $zero, L_8018CF7C
    if (ctx->r25 != 0) {
        // 0x8018CF5C: lui         $a1, 0x42F0
        ctx->r5 = S32(0X42F0 << 16);
            goto L_8018CF7C;
    }
    // 0x8018CF5C: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    // 0x8018CF60: lw          $a3, 0xD8($t5)
    ctx->r7 = MEM_W(ctx->r13, 0XD8);
    // 0x8018CF64: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8018CF68: jal         0x8018C0D0
    // 0x8018CF6C: addiu       $a2, $t5, 0x1E8
    ctx->r6 = ADD32(ctx->r13, 0X1E8);
    Area6_8018C0D0(rdram, ctx);
        goto after_27;
    // 0x8018CF6C: addiu       $a2, $t5, 0x1E8
    ctx->r6 = ADD32(ctx->r13, 0X1E8);
    after_27:
    // 0x8018CF70: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018CF74: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018CF78: addiu       $ra, $zero, 0x2
    ctx->r31 = ADD32(0, 0X2);
L_8018CF7C:
    // 0x8018CF7C: lh          $v0, 0xBA($t5)
    ctx->r2 = MEM_H(ctx->r13, 0XBA);
L_8018CF80:
    // 0x8018CF80: addiu       $a0, $t5, 0x14C
    ctx->r4 = ADD32(ctx->r13, 0X14C);
    // 0x8018CF84: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8018CF88: beq         $v0, $zero, L_8018D0D0
    if (ctx->r2 == 0) {
        // 0x8018CF8C: lui         $a3, 0x4120
        ctx->r7 = S32(0X4120 << 16);
            goto L_8018D0D0;
    }
    // 0x8018CF8C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018CF90: lh          $v1, 0x58($t5)
    ctx->r3 = MEM_H(ctx->r13, 0X58);
    // 0x8018CF94: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8018CF98: beq         $v1, $zero, L_8018CFE8
    if (ctx->r3 == 0) {
        // 0x8018CF9C: andi        $t6, $v1, 0x3
        ctx->r14 = ctx->r3 & 0X3;
            goto L_8018CFE8;
    }
    // 0x8018CF9C: andi        $t6, $v1, 0x3
    ctx->r14 = ctx->r3 & 0X3;
    // 0x8018CFA0: bne         $t6, $zero, L_8018CFE8
    if (ctx->r14 != 0) {
        // 0x8018CFA4: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8018CFE8;
    }
    // 0x8018CFA4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018CFA8: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8018CFAC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018CFB0: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8018CFB4: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8018CFB8: ori         $a0, $a0, 0x4003
    ctx->r4 = ctx->r4 | 0X4003;
    // 0x8018CFBC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018CFC0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018CFC4: addiu       $a1, $t5, 0x3FC
    ctx->r5 = ADD32(ctx->r13, 0X3FC);
    // 0x8018CFC8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8018CFCC: jal         0x80019218
    // 0x8018CFD0: sw          $t0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r8;
    Audio_PlaySfx(rdram, ctx);
        goto after_28;
    // 0x8018CFD0: sw          $t0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r8;
    after_28:
    // 0x8018CFD4: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018CFD8: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    // 0x8018CFDC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018CFE0: addiu       $ra, $zero, 0x2
    ctx->r31 = ADD32(0, 0X2);
    // 0x8018CFE4: lh          $v1, 0x58($t5)
    ctx->r3 = MEM_H(ctx->r13, 0X58);
L_8018CFE8:
    // 0x8018CFE8: bnel        $t4, $v1, L_8018D03C
    if (ctx->r12 != ctx->r3) {
        // 0x8018CFEC: sll         $a1, $t0, 2
        ctx->r5 = S32(ctx->r8 << 2);
            goto L_8018D03C;
    }
    goto skip_13;
    // 0x8018CFEC: sll         $a1, $t0, 2
    ctx->r5 = S32(ctx->r8 << 2);
    skip_13:
    // 0x8018CFF0: lh          $v0, 0xBA($t5)
    ctx->r2 = MEM_H(ctx->r13, 0XBA);
    // 0x8018CFF4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018CFF8: addiu       $a0, $a0, -0x201C
    ctx->r4 = ADD32(ctx->r4, -0X201C);
    // 0x8018CFFC: bne         $ra, $v0, L_8018D018
    if (ctx->r31 != ctx->r2) {
        // 0x8018D000: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_8018D018;
    }
    // 0x8018D000: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8018D004: jal         0x800BA808
    // 0x8018D008: sw          $t0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r8;
    Radio_PlayMessage(rdram, ctx);
        goto after_29;
    // 0x8018D008: sw          $t0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r8;
    after_29:
    // 0x8018D00C: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    // 0x8018D010: b           L_8018D038
    // 0x8018D014: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
        goto L_8018D038;
    // 0x8018D014: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
L_8018D018:
    // 0x8018D018: bne         $t4, $v0, L_8018D038
    if (ctx->r12 != ctx->r2) {
        // 0x8018D01C: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018D038;
    }
    // 0x8018D01C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018D020: addiu       $a0, $a0, -0x1FEC
    ctx->r4 = ADD32(ctx->r4, -0X1FEC);
    // 0x8018D024: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8018D028: jal         0x800BA808
    // 0x8018D02C: sw          $t0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r8;
    Radio_PlayMessage(rdram, ctx);
        goto after_30;
    // 0x8018D02C: sw          $t0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r8;
    after_30:
    // 0x8018D030: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    // 0x8018D034: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
L_8018D038:
    // 0x8018D038: sll         $a1, $t0, 2
    ctx->r5 = S32(ctx->r8 << 2);
L_8018D03C:
    // 0x8018D03C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018D040: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8018D044: lw          $v1, -0xCF0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XCF0);
    // 0x8018D048: lh          $v0, 0xB4($t5)
    ctx->r2 = MEM_H(ctx->r13, 0XB4);
    // 0x8018D04C: beq         $v0, $v1, L_8018D06C
    if (ctx->r2 == ctx->r3) {
        // 0x8018D050: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8018D06C;
    }
    // 0x8018D050: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8018D054: beq         $at, $zero, L_8018D068
    if (ctx->r1 == 0) {
        // 0x8018D058: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_8018D068;
    }
    // 0x8018D058: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8018D05C: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8018D060: b           L_8018D06C
    // 0x8018D064: sh          $t8, 0xB4($t5)
    MEM_H(0XB4, ctx->r13) = ctx->r24;
        goto L_8018D06C;
    // 0x8018D064: sh          $t8, 0xB4($t5)
    MEM_H(0XB4, ctx->r13) = ctx->r24;
L_8018D068:
    // 0x8018D068: sh          $t9, 0xB4($t5)
    MEM_H(0XB4, ctx->r13) = ctx->r25;
L_8018D06C:
    // 0x8018D06C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018D070: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8018D074: lw          $v1, -0xCE4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XCE4);
    // 0x8018D078: lh          $v0, 0xB6($t5)
    ctx->r2 = MEM_H(ctx->r13, 0XB6);
    // 0x8018D07C: beq         $v0, $v1, L_8018D09C
    if (ctx->r2 == ctx->r3) {
        // 0x8018D080: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8018D09C;
    }
    // 0x8018D080: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8018D084: beq         $at, $zero, L_8018D098
    if (ctx->r1 == 0) {
        // 0x8018D088: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8018D098;
    }
    // 0x8018D088: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8018D08C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8018D090: b           L_8018D09C
    // 0x8018D094: sh          $t6, 0xB6($t5)
    MEM_H(0XB6, ctx->r13) = ctx->r14;
        goto L_8018D09C;
    // 0x8018D094: sh          $t6, 0xB6($t5)
    MEM_H(0XB6, ctx->r13) = ctx->r14;
L_8018D098:
    // 0x8018D098: sh          $t7, 0xB6($t5)
    MEM_H(0XB6, ctx->r13) = ctx->r15;
L_8018D09C:
    // 0x8018D09C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018D0A0: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8018D0A4: lw          $v1, -0xCD8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XCD8);
    // 0x8018D0A8: lh          $v0, 0xB8($t5)
    ctx->r2 = MEM_H(ctx->r13, 0XB8);
    // 0x8018D0AC: beq         $v0, $v1, L_8018D140
    if (ctx->r2 == ctx->r3) {
        // 0x8018D0B0: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8018D140;
    }
    // 0x8018D0B0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8018D0B4: beq         $at, $zero, L_8018D0C8
    if (ctx->r1 == 0) {
        // 0x8018D0B8: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_8018D0C8;
    }
    // 0x8018D0B8: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8018D0BC: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8018D0C0: b           L_8018D140
    // 0x8018D0C4: sh          $t8, 0xB8($t5)
    MEM_H(0XB8, ctx->r13) = ctx->r24;
        goto L_8018D140;
    // 0x8018D0C4: sh          $t8, 0xB8($t5)
    MEM_H(0XB8, ctx->r13) = ctx->r24;
L_8018D0C8:
    // 0x8018D0C8: b           L_8018D140
    // 0x8018D0CC: sh          $t9, 0xB8($t5)
    MEM_H(0XB8, ctx->r13) = ctx->r25;
        goto L_8018D140;
    // 0x8018D0CC: sh          $t9, 0xB8($t5)
    MEM_H(0XB8, ctx->r13) = ctx->r25;
L_8018D0D0:
    // 0x8018D0D0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018D0D4: lwc1        $f4, 0xAB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XAB4);
    // 0x8018D0D8: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x8018D0DC: jal         0x8009BC2C
    // 0x8018D0E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_31;
    // 0x8018D0E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_31:
    // 0x8018D0E4: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018D0E8: lh          $t6, 0x54($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X54);
    // 0x8018D0EC: bne         $t6, $zero, L_8018D140
    if (ctx->r14 != 0) {
        // 0x8018D0F0: nop
    
            goto L_8018D140;
    }
    // 0x8018D0F0: nop

    // 0x8018D0F4: lh          $t7, 0xD0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0XD0);
    // 0x8018D0F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8018D0FC: bne         $t7, $at, L_8018D140
    if (ctx->r15 != ctx->r1) {
        // 0x8018D100: nop
    
            goto L_8018D140;
    }
    // 0x8018D100: nop

    // 0x8018D104: lw          $t8, 0x7C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X7C);
    // 0x8018D108: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018D10C: addiu       $a0, $a0, -0x1FD0
    ctx->r4 = ADD32(ctx->r4, -0X1FD0);
    // 0x8018D110: bne         $t8, $zero, L_8018D140
    if (ctx->r24 != 0) {
        // 0x8018D114: nop
    
            goto L_8018D140;
    }
    // 0x8018D114: nop

    // 0x8018D118: jal         0x800BA808
    // 0x8018D11C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_32;
    // 0x8018D11C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_32:
    // 0x8018D120: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018D124: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8018D128: sh          $t9, 0xD0($t5)
    MEM_H(0XD0, ctx->r13) = ctx->r25;
    // 0x8018D12C: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x8018D130: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018D134: sw          $t7, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r15;
    // 0x8018D138: andi        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 & 0X1;
    // 0x8018D13C: sw          $t9, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r25;
L_8018D140:
    // 0x8018D140: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8018D144: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x8018D148: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8018D14C: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x8018D150: addiu       $s3, $s3, 0x22F0
    ctx->r19 = ADD32(ctx->r19, 0X22F0);
    // 0x8018D154: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8018D158: jal         0x80005708
    // 0x8018D15C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_33;
    // 0x8018D15C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_33:
    // 0x8018D160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D164: jal         0x800B8DD0
    // 0x8018D168: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    RCP_SetupDL(rdram, ctx);
        goto after_34;
    // 0x8018D168: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    after_34:
    // 0x8018D16C: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x8018D170: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018D174: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018D178: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018D17C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x8018D180: jal         0x80005B00
    // 0x8018D184: lui         $a3, 0x428C
    ctx->r7 = S32(0X428C << 16);
    Matrix_Translate(rdram, ctx);
        goto after_35;
    // 0x8018D184: lui         $a3, 0x428C
    ctx->r7 = S32(0X428C << 16);
    after_35:
    // 0x8018D188: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018D18C: lwc1        $f0, 0xAB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XAB8);
    // 0x8018D190: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018D194: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018D198: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018D19C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018D1A0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018D1A4: jal         0x80005C34
    // 0x8018D1A8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_36;
    // 0x8018D1A8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_36:
    // 0x8018D1AC: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018D1B0: lh          $t8, 0x5C($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X5C);
    // 0x8018D1B4: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8018D1B8: beql        $t9, $zero, L_8018D1EC
    if (ctx->r25 == 0) {
        // 0x8018D1BC: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8018D1EC;
    }
    goto skip_14;
    // 0x8018D1BC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_14:
    // 0x8018D1C0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018D1C4: lui         $t8, 0xFF00
    ctx->r24 = S32(0XFF00 << 16);
    // 0x8018D1C8: ori         $t8, $t8, 0xFF
    ctx->r24 = ctx->r24 | 0XFF;
    // 0x8018D1CC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018D1D0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8018D1D4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8018D1D8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018D1DC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8018D1E0: b           L_8018D21C
    // 0x8018D1E4: nop

        goto L_8018D21C;
    // 0x8018D1E4: nop

    // 0x8018D1E8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8018D1EC:
    // 0x8018D1EC: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8018D1F0: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8018D1F4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8018D1F8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8018D1FC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8018D200: lwc1        $f6, 0x24($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X24);
    // 0x8018D204: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8018D208: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8018D20C: nop

    // 0x8018D210: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8018D214: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8018D218: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_8018D21C:
    // 0x8018D21C: jal         0x80006EB8
    // 0x8018D220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_37;
    // 0x8018D220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x8018D224: lui         $s1, 0x600
    ctx->r17 = S32(0X600 << 16);
    // 0x8018D228: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018D22C: lui         $t8, 0x602
    ctx->r24 = S32(0X602 << 16);
    // 0x8018D230: addiu       $t8, $t8, -0x4D50
    ctx->r24 = ADD32(ctx->r24, -0X4D50);
    // 0x8018D234: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8018D238: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8018D23C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8018D240: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x8018D244: jal         0x80005740
    // 0x8018D248: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_38;
    // 0x8018D248: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_38:
    // 0x8018D24C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D250: jal         0x800B8DD0
    // 0x8018D254: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    RCP_SetupDL(rdram, ctx);
        goto after_39;
    // 0x8018D254: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    after_39:
    // 0x8018D258: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8018D25C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018D260: lwc1        $f16, 0x24($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X24);
    // 0x8018D264: lw          $t5, 0x238($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X238);
    // 0x8018D268: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x8018D26C: nop

    // 0x8018D270: bc1tl       L_8018D2DC
    if (c1cs) {
        // 0x8018D274: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8018D2DC;
    }
    goto skip_15;
    // 0x8018D274: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_15:
    // 0x8018D278: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018D27C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8018D280: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8018D284: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8018D288: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8018D28C: lwc1        $f18, 0x24($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X24);
    // 0x8018D290: lh          $t7, 0xB4($t5)
    ctx->r15 = MEM_H(ctx->r13, 0XB4);
    // 0x8018D294: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8018D298: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8018D29C: nop

    // 0x8018D2A0: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8018D2A4: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x8018D2A8: lh          $t7, 0xB6($t5)
    ctx->r15 = MEM_H(ctx->r13, 0XB6);
    // 0x8018D2AC: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8018D2B0: andi        $t9, $t7, 0xFF
    ctx->r25 = ctx->r15 & 0XFF;
    // 0x8018D2B4: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x8018D2B8: lh          $t9, 0xB8($t5)
    ctx->r25 = MEM_H(ctx->r13, 0XB8);
    // 0x8018D2BC: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8018D2C0: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x8018D2C4: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x8018D2C8: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8018D2CC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8018D2D0: b           L_8018D334
    // 0x8018D2D4: lui         $at, 0x4294
    ctx->r1 = S32(0X4294 << 16);
        goto L_8018D334;
    // 0x8018D2D4: lui         $at, 0x4294
    ctx->r1 = S32(0X4294 << 16);
    // 0x8018D2D8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8018D2DC:
    // 0x8018D2DC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8018D2E0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018D2E4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8018D2E8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018D2EC: lwc1        $f6, 0x14C($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X14C);
    // 0x8018D2F0: lh          $t8, 0xB4($t5)
    ctx->r24 = MEM_H(ctx->r13, 0XB4);
    // 0x8018D2F4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8018D2F8: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8018D2FC: nop

    // 0x8018D300: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x8018D304: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x8018D308: lh          $t8, 0xB6($t5)
    ctx->r24 = MEM_H(ctx->r13, 0XB6);
    // 0x8018D30C: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8018D310: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x8018D314: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x8018D318: lh          $t6, 0xB8($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XB8);
    // 0x8018D31C: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8018D320: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8018D324: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x8018D328: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8018D32C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8018D330: lui         $at, 0x4294
    ctx->r1 = S32(0X4294 << 16);
L_8018D334:
    // 0x8018D334: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018D338: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x8018D33C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8018D340: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018D344: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8018D348: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018D34C: jal         0x80005B00
    // 0x8018D350: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_40;
    // 0x8018D350: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_40:
    // 0x8018D354: jal         0x80006EB8
    // 0x8018D358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_41;
    // 0x8018D358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x8018D35C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018D360: lui         $t9, 0x601
    ctx->r25 = S32(0X601 << 16);
    // 0x8018D364: addiu       $t9, $t9, 0x1910
    ctx->r25 = ADD32(ctx->r25, 0X1910);
    // 0x8018D368: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018D36C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8018D370: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8018D374: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
    // 0x8018D378: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x8018D37C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8018D380: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8018D384: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018D388: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018D38C: jal         0x80005B00
    // 0x8018D390: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_42;
    // 0x8018D390: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_42:
L_8018D394:
    // 0x8018D394: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8018D398:
    // 0x8018D398: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8018D39C: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8018D3A0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8018D3A4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D3A8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8018D3AC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8018D3B0: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8018D3B4: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8018D3B8: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8018D3BC: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8018D3C0: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8018D3C4: jr          $ra
    // 0x8018D3C8: addiu       $sp, $sp, 0x238
    ctx->r29 = ADD32(ctx->r29, 0X238);
    return;
    // 0x8018D3C8: addiu       $sp, $sp, 0x238
    ctx->r29 = ADD32(ctx->r29, 0X238);
;}
RECOMP_FUNC void Area6_Effect395_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187704: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80187708: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018770C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80187710: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80187714: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x80187718: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x8018771C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_80187720:
    // 0x80187720: bnel        $t6, $zero, L_8018773C
    if (ctx->r14 != 0) {
        // 0x80187724: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_8018773C;
    }
    goto skip_0;
    // 0x80187724: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x80187728: jal         0x8018767C
    // 0x8018772C: nop

    Area6_Effect395_Setup(rdram, ctx);
        goto after_0;
    // 0x8018772C: nop

    after_0:
    // 0x80187730: b           L_80187748
    // 0x80187734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80187748;
    // 0x80187734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80187738: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_8018773C:
    // 0x8018773C: bnel        $a0, $v0, L_80187720
    if (ctx->r4 != ctx->r2) {
        // 0x80187740: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_80187720;
    }
    goto skip_1;
    // 0x80187740: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x80187744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80187748:
    // 0x80187748: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018774C: jr          $ra
    // 0x80187750: nop

    return;
    // 0x80187750: nop

;}
RECOMP_FUNC void Solar_SoProminence_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A003C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801A0040: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A0044: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801A0048: lh          $v0, 0xB8($a2)
    ctx->r2 = MEM_H(ctx->r6, 0XB8);
    // 0x801A004C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A0050: beql        $v0, $zero, L_801A006C
    if (ctx->r2 == 0) {
        // 0x801A0054: lhu         $t6, 0xBE($a2)
        ctx->r14 = MEM_HU(ctx->r6, 0XBE);
            goto L_801A006C;
    }
    goto skip_0;
    // 0x801A0054: lhu         $t6, 0xBE($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0XBE);
    skip_0:
    // 0x801A0058: beql        $v0, $at, L_801A00C0
    if (ctx->r2 == ctx->r1) {
        // 0x801A005C: lhu         $t3, 0xBE($a2)
        ctx->r11 = MEM_HU(ctx->r6, 0XBE);
            goto L_801A00C0;
    }
    goto skip_1;
    // 0x801A005C: lhu         $t3, 0xBE($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0XBE);
    skip_1:
    // 0x801A0060: b           L_801A0114
    // 0x801A0064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801A0114;
    // 0x801A0064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A0068: lhu         $t6, 0xBE($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0XBE);
L_801A006C:
    // 0x801A006C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A0070: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x801A0074: bnel        $t6, $zero, L_801A008C
    if (ctx->r14 != 0) {
        // 0x801A0078: lhu         $t9, 0xBC($a2)
        ctx->r25 = MEM_HU(ctx->r6, 0XBC);
            goto L_801A008C;
    }
    goto skip_2;
    // 0x801A0078: lhu         $t9, 0xBC($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0XBC);
    skip_2:
    // 0x801A007C: sh          $t7, 0xB8($a2)
    MEM_H(0XB8, ctx->r6) = ctx->r15;
    // 0x801A0080: b           L_801A0110
    // 0x801A0084: sh          $t8, 0xBE($a2)
    MEM_H(0XBE, ctx->r6) = ctx->r24;
        goto L_801A0110;
    // 0x801A0084: sh          $t8, 0xBE($a2)
    MEM_H(0XBE, ctx->r6) = ctx->r24;
    // 0x801A0088: lhu         $t9, 0xBC($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0XBC);
L_801A008C:
    // 0x801A008C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801A0090: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801A0094: bne         $t9, $zero, L_801A0110
    if (ctx->r25 != 0) {
        // 0x801A0098: lui         $a1, 0x447A
        ctx->r5 = S32(0X447A << 16);
            goto L_801A0110;
    }
    // 0x801A0098: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x801A009C: sh          $t0, 0xBC($a2)
    MEM_H(0XBC, ctx->r6) = ctx->r8;
    // 0x801A00A0: jal         0x8019FEE8
    // 0x801A00A4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    Solar_Effect392_Spawn3(rdram, ctx);
        goto after_0;
    // 0x801A00A4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x801A00A8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x801A00AC: lh          $t1, 0x4E($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X4E);
    // 0x801A00B0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801A00B4: b           L_801A0110
    // 0x801A00B8: sh          $t2, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = ctx->r10;
        goto L_801A0110;
    // 0x801A00B8: sh          $t2, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = ctx->r10;
    // 0x801A00BC: lhu         $t3, 0xBE($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0XBE);
L_801A00C0:
    // 0x801A00C0: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x801A00C4: addiu       $a0, $a2, 0x100
    ctx->r4 = ADD32(ctx->r6, 0X100);
    // 0x801A00C8: bne         $t3, $zero, L_801A0110
    if (ctx->r11 != 0) {
        // 0x801A00CC: addiu       $a1, $a2, 0x4
        ctx->r5 = ADD32(ctx->r6, 0X4);
            goto L_801A0110;
    }
    // 0x801A00CC: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x801A00D0: sh          $zero, 0xB8($a2)
    MEM_H(0XB8, ctx->r6) = 0;
    // 0x801A00D4: sh          $t4, 0xBE($a2)
    MEM_H(0XBE, ctx->r6) = ctx->r12;
    // 0x801A00D8: sh          $zero, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = 0;
    // 0x801A00DC: jal         0x8005F0E8
    // 0x801A00E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    Object_SetSfxSourceToPos(rdram, ctx);
        goto after_1;
    // 0x801A00E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x801A00E4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A00E8: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x801A00EC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A00F0: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x801A00F4: lui         $a0, 0x1903
    ctx->r4 = S32(0X1903 << 16);
    // 0x801A00F8: ori         $a0, $a0, 0x5053
    ctx->r4 = ctx->r4 | 0X5053;
    // 0x801A00FC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801A0100: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A0104: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x801A0108: jal         0x80019218
    // 0x801A010C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x801A010C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
L_801A0110:
    // 0x801A0110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801A0114:
    // 0x801A0114: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801A0118: jr          $ra
    // 0x801A011C: nop

    return;
    // 0x801A011C: nop

;}
RECOMP_FUNC void Zoness_8019962C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019962C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80199630: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80199634: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80199638: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8019963C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199640: lwc1        $f4, 0x1208($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1208);
    // 0x80199644: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80199648: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019964C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80199650: addiu       $a0, $a0, 0x261C
    ctx->r4 = ADD32(ctx->r4, 0X261C);
    // 0x80199654: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80199658: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x8019965C: jal         0x8009BC2C
    // 0x80199660: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x80199660: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80199664: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199668: lwc1        $f6, 0x120C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X120C);
    // 0x8019966C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80199670: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80199674: lw          $a3, 0x261C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X261C);
    // 0x80199678: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8019967C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80199680: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80199684: jal         0x8009BD38
    // 0x80199688: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_1;
    // 0x80199688: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_1:
    // 0x8019968C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80199690: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80199694: jr          $ra
    // 0x80199698: nop

    return;
    // 0x80199698: nop

;}
RECOMP_FUNC void Aquas_AqFishGroup_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BDDFC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801BDE00: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801BDE04: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801BDE08: addiu       $a2, $zero, 0x2000
    ctx->r6 = ADD32(0, 0X2000);
    // 0x801BDE0C: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x801BDE10: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801BDE14: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x801BDE18: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x801BDE1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801BDE20: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801BDE24: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x801BDE28: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x801BDE2C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801BDE30: beq         $a0, $at, L_801BDE4C
    if (ctx->r4 == ctx->r1) {
        // 0x801BDE34: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801BDE4C;
    }
    // 0x801BDE34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801BDE38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801BDE3C: beq         $a0, $at, L_801BDE4C
    if (ctx->r4 == ctx->r1) {
        // 0x801BDE40: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_801BDE4C;
    }
    // 0x801BDE40: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801BDE44: bne         $a0, $at, L_801BDE64
    if (ctx->r4 != ctx->r1) {
        // 0x801BDE48: nop
    
            goto L_801BDE64;
    }
    // 0x801BDE48: nop

L_801BDE4C:
    // 0x801BDE4C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x801BDE50: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x801BDE54: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801BDE58: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x801BDE5C: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x801BDE60: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_801BDE64:
    // 0x801BDE64: jr          $ra
    // 0x801BDE68: nop

    return;
    // 0x801BDE68: nop

;}
RECOMP_FUNC void Aquas_SetupDebris(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A9374: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801A9378: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801A937C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801A9380: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801A9384: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801A9388: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801A938C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801A9390: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801A9394: jal         0x800613C4
    // 0x801A9398: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x801A9398: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x801A939C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801A93A0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801A93A4: addiu       $t7, $zero, 0xBD
    ctx->r15 = ADD32(0, 0XBD);
    // 0x801A93A8: sb          $t6, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r14;
    // 0x801A93AC: sh          $t7, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r15;
    // 0x801A93B0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x801A93B4: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x801A93B8: addiu       $a0, $a3, 0x1C
    ctx->r4 = ADD32(ctx->r7, 0X1C);
    // 0x801A93BC: sh          $t8, 0xB8($a3)
    MEM_H(0XB8, ctx->r7) = ctx->r24;
    // 0x801A93C0: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801A93C4: swc1        $f4, 0x110($a3)
    MEM_W(0X110, ctx->r7) = ctx->f4.u32l;
    // 0x801A93C8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x801A93CC: sh          $t9, 0x48($a3)
    MEM_H(0X48, ctx->r7) = ctx->r25;
    // 0x801A93D0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x801A93D4: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x801A93D8: sw          $at, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r1;
    // 0x801A93DC: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x801A93E0: sw          $t2, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r10;
    // 0x801A93E4: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x801A93E8: sw          $at, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r1;
    // 0x801A93EC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x801A93F0: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x801A93F4: sw          $at, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r1;
    // 0x801A93F8: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x801A93FC: sw          $t5, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r13;
    // 0x801A9400: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x801A9404: sw          $at, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r1;
    // 0x801A9408: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801A940C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A9410: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A9414: swc1        $f6, 0xE8($a3)
    MEM_W(0XE8, ctx->r7) = ctx->f6.u32l;
    // 0x801A9418: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801A941C: swc1        $f8, 0xEC($a3)
    MEM_W(0XEC, ctx->r7) = ctx->f8.u32l;
    // 0x801A9420: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A9424: swc1        $f10, 0xF0($a3)
    MEM_W(0XF0, ctx->r7) = ctx->f10.u32l;
    // 0x801A9428: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x801A942C: swc1        $f16, 0x10C($a3)
    MEM_W(0X10C, ctx->r7) = ctx->f16.u32l;
    // 0x801A9430: jal         0x800612B8
    // 0x801A9434: sh          $t6, 0xBC($a3)
    MEM_H(0XBC, ctx->r7) = ctx->r14;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x801A9434: sh          $t6, 0xBC($a3)
    MEM_H(0XBC, ctx->r7) = ctx->r14;
    after_1:
    // 0x801A9438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801A943C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801A9440: jr          $ra
    // 0x801A9444: nop

    return;
    // 0x801A9444: nop

;}
RECOMP_FUNC void Aquas_AqSpindlyFish_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B76EC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801B76F0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801B76F4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801B76F8: addiu       $a2, $zero, 0x2000
    ctx->r6 = ADD32(0, 0X2000);
    // 0x801B76FC: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x801B7700: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801B7704: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x801B7708: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x801B770C: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x801B7710: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801B7714: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x801B7718: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x801B771C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801B7720: bne         $at, $zero, L_801B774C
    if (ctx->r1 != 0) {
        // 0x801B7724: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801B774C;
    }
    // 0x801B7724: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801B7728: slti        $at, $a0, 0xE
    ctx->r1 = SIGNED(ctx->r4) < 0XE ? 1 : 0;
    // 0x801B772C: beq         $at, $zero, L_801B774C
    if (ctx->r1 == 0) {
        // 0x801B7730: nop
    
            goto L_801B774C;
    }
    // 0x801B7730: nop

    // 0x801B7734: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x801B7738: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x801B773C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801B7740: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x801B7744: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x801B7748: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_801B774C:
    // 0x801B774C: jr          $ra
    // 0x801B7750: nop

    return;
    // 0x801B7750: nop

;}
RECOMP_FUNC void Aquas_801BDF14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BDF14: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801BDF18: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801BDF1C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x801BDF20: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x801BDF24: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x801BDF28: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x801BDF2C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x801BDF30: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x801BDF34: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x801BDF38: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x801BDF3C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801BDF40: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801BDF44: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801BDF48: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x801BDF4C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801BDF50: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801BDF54: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x801BDF58: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x801BDF5C: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x801BDF60: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801BDF64: addiu       $s0, $s0, 0x42D4
    ctx->r16 = ADD32(ctx->r16, 0X42D4);
    // 0x801BDF68: addiu       $s3, $s3, 0x75C
    ctx->r19 = ADD32(ctx->r19, 0X75C);
    // 0x801BDF6C: addiu       $s1, $s1, 0x504
    ctx->r17 = ADD32(ctx->r17, 0X504);
    // 0x801BDF70: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801BDF74: addiu       $fp, $zero, 0x32
    ctx->r30 = ADD32(0, 0X32);
    // 0x801BDF78: addiu       $s7, $zero, 0xE7
    ctx->r23 = ADD32(0, 0XE7);
    // 0x801BDF7C: addiu       $s6, $zero, 0x29
    ctx->r22 = ADD32(0, 0X29);
    // 0x801BDF80: addiu       $s5, $zero, 0xC3
    ctx->r21 = ADD32(0, 0XC3);
    // 0x801BDF84: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_801BDF88:
    // 0x801BDF88: jal         0x800613C4
    // 0x801BDF8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x801BDF8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801BDF90: sb          $s4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r20;
    // 0x801BDF94: sh          $s5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r21;
    // 0x801BDF98: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x801BDF9C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x801BDFA0: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801BDFA4: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x801BDFA8: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801BDFAC: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x801BDFB0: lwc1        $f10, 0x0($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X0);
    // 0x801BDFB4: sh          $s6, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r22;
    // 0x801BDFB8: jal         0x80004EB0
    // 0x801BDFBC: swc1        $f10, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x801BDFBC: swc1        $f10, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x801BDFC0: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x801BDFC4: sw          $s2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r18;
    // 0x801BDFC8: sh          $s7, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r23;
    // 0x801BDFCC: swc1        $f22, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f22.u32l;
    // 0x801BDFD0: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x801BDFD4: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x801BDFD8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801BDFDC: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x801BDFE0: jal         0x800612B8
    // 0x801BDFE4: sw          $t7, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r15;
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x801BDFE4: sw          $t7, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r15;
    after_2:
    // 0x801BDFE8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801BDFEC: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x801BDFF0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x801BDFF4: bne         $s2, $fp, L_801BDF88
    if (ctx->r18 != ctx->r30) {
        // 0x801BDFF8: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_801BDF88;
    }
    // 0x801BDFF8: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
    // 0x801BDFFC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801BE000: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801BE004: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801BE008: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801BE00C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x801BE010: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x801BE014: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x801BE018: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x801BE01C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x801BE020: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x801BE024: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x801BE028: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x801BE02C: jr          $ra
    // 0x801BE030: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801BE030: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Aquas_Actor188_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BEC68: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801BEC6C: jr          $ra
    // 0x801BEC70: nop

    return;
    // 0x801BEC70: nop

;}
RECOMP_FUNC void Solar_Effect392_Spawn4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019FF44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019FF48: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8019FF4C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8019FF50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019FF54: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8019FF58: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8019FF5C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019FF60: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8019FF64: addiu       $a1, $a1, 0x2778
    ctx->r5 = ADD32(ctx->r5, 0X2778);
    // 0x8019FF68: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
L_8019FF6C:
    // 0x8019FF6C: bnel        $t6, $zero, L_8019FFA4
    if (ctx->r14 != 0) {
        // 0x8019FF70: addiu       $a1, $a1, -0x8C
        ctx->r5 = ADD32(ctx->r5, -0X8C);
            goto L_8019FFA4;
    }
    goto skip_0;
    // 0x8019FF70: addiu       $a1, $a1, -0x8C
    ctx->r5 = ADD32(ctx->r5, -0X8C);
    skip_0:
    // 0x8019FF74: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8019FF78: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8019FF7C: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8019FF80: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8019FF84: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8019FF88: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019FF8C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8019FF90: jal         0x8019FAA4
    // 0x8019FF94: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Solar_Effect392_Setup4(rdram, ctx);
        goto after_0;
    // 0x8019FF94: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8019FF98: b           L_8019FFB4
    // 0x8019FF9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8019FFB4;
    // 0x8019FF9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019FFA0: addiu       $a1, $a1, -0x8C
    ctx->r5 = ADD32(ctx->r5, -0X8C);
L_8019FFA4:
    // 0x8019FFA4: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x8019FFA8: beql        $at, $zero, L_8019FF6C
    if (ctx->r1 == 0) {
        // 0x8019FFAC: lbu         $t6, 0x0($a1)
        ctx->r14 = MEM_BU(ctx->r5, 0X0);
            goto L_8019FF6C;
    }
    goto skip_1;
    // 0x8019FFAC: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    skip_1:
    // 0x8019FFB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8019FFB4:
    // 0x8019FFB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019FFB8: jr          $ra
    // 0x8019FFBC: nop

    return;
    // 0x8019FFBC: nop

;}
RECOMP_FUNC void SectorZ_FireSmokeEffectSpawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199BDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80199BE0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80199BE4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80199BE8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80199BEC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80199BF0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80199BF4: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x80199BF8: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x80199BFC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_80199C00:
    // 0x80199C00: bnel        $t6, $zero, L_80199C44
    if (ctx->r14 != 0) {
        // 0x80199C04: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_80199C44;
    }
    goto skip_0;
    // 0x80199C04: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x80199C08: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80199C0C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80199C10: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80199C14: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80199C18: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80199C1C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80199C20: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80199C24: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80199C28: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80199C2C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80199C30: jal         0x80199B18
    // 0x80199C34: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    SectorZ_FireSmokeEffectSetup(rdram, ctx);
        goto after_0;
    // 0x80199C34: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x80199C38: b           L_80199C54
    // 0x80199C3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80199C54;
    // 0x80199C3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80199C40: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_80199C44:
    // 0x80199C44: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80199C48: beql        $at, $zero, L_80199C00
    if (ctx->r1 == 0) {
        // 0x80199C4C: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_80199C00;
    }
    goto skip_1;
    // 0x80199C4C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x80199C50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80199C54:
    // 0x80199C54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80199C58: jr          $ra
    // 0x80199C5C: nop

    return;
    // 0x80199C5C: nop

;}
RECOMP_FUNC void SectorZ_TeamSetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019B888: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8019B88C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8019B890: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8019B894: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8019B898: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8019B89C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8019B8A0: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8019B8A4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8019B8A8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8019B8AC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8019B8B0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8019B8B4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8019B8B8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8019B8BC: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8019B8C0: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8019B8C4: lui         $s6, 0x8017
    ctx->r22 = S32(0X8017 << 16);
    // 0x8019B8C8: lui         $s5, 0x800C
    ctx->r21 = S32(0X800C << 16);
    // 0x8019B8CC: lui         $s4, 0x8018
    ctx->r20 = S32(0X8018 << 16);
    // 0x8019B8D0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8019B8D4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8019B8D8: addiu       $s4, $s4, -0x7D80
    ctx->r20 = ADD32(ctx->r20, -0X7D80);
    // 0x8019B8DC: addiu       $s5, $s5, 0x5D34
    ctx->r21 = ADD32(ctx->r21, 0X5D34);
    // 0x8019B8E0: addiu       $s6, $s6, 0x78B0
    ctx->r22 = ADD32(ctx->r22, 0X78B0);
    // 0x8019B8E4: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x8019B8E8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8019B8EC: addiu       $fp, $zero, 0xC5
    ctx->r30 = ADD32(0, 0XC5);
    // 0x8019B8F0: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
L_8019B8F4:
    // 0x8019B8F4: blez        $s1, L_8019B90C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8019B8F8: sll         $t6, $s1, 2
        ctx->r14 = S32(ctx->r17 << 2);
            goto L_8019B90C;
    }
    // 0x8019B8F8: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8019B8FC: addu        $t7, $s6, $t6
    ctx->r15 = ADD32(ctx->r22, ctx->r14);
    // 0x8019B900: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8019B904: blezl       $t8, L_8019BA20
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8019B908: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8019BA20;
    }
    goto skip_0;
    // 0x8019B908: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
L_8019B90C:
    // 0x8019B90C: jal         0x800613C4
    // 0x8019B910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8019B910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8019B914: sb          $s7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r23;
    // 0x8019B918: sh          $fp, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r30;
    // 0x8019B91C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8019B920: jal         0x800612B8
    // 0x8019B924: andi        $a1, $fp, 0xFFFF
    ctx->r5 = ctx->r30 & 0XFFFF;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8019B924: andi        $a1, $fp, 0xFFFF
    ctx->r5 = ctx->r30 & 0XFFFF;
    after_1:
    // 0x8019B928: bne         $s1, $zero, L_8019B93C
    if (ctx->r17 != 0) {
        // 0x8019B92C: sll         $t0, $s1, 2
        ctx->r8 = S32(ctx->r17 << 2);
            goto L_8019B93C;
    }
    // 0x8019B92C: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x8019B930: addiu       $t9, $zero, 0x3E8
    ctx->r25 = ADD32(0, 0X3E8);
    // 0x8019B934: b           L_8019BA1C
    // 0x8019B938: sh          $t9, 0xE4($s0)
    MEM_H(0XE4, ctx->r16) = ctx->r25;
        goto L_8019BA1C;
    // 0x8019B938: sh          $t9, 0xE4($s0)
    MEM_H(0XE4, ctx->r16) = ctx->r25;
L_8019B93C:
    // 0x8019B93C: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x8019B940: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x8019B944: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8019B948: addiu       $t1, $t1, -0xA14
    ctx->r9 = ADD32(ctx->r9, -0XA14);
    // 0x8019B94C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8019B950: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8019B954: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8019B958: lwc1        $f6, 0x74($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X74);
    // 0x8019B95C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8019B960: addiu       $v1, $v1, -0x3FE4
    ctx->r3 = ADD32(ctx->r3, -0X3FE4);
    // 0x8019B964: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019B968: sll         $t9, $v1, 4
    ctx->r25 = S32(ctx->r3 << 4);
    // 0x8019B96C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8019B970: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8019B974: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x8019B978: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x8019B97C: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8019B980: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8019B984: lwc1        $f16, 0x78($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X78);
    // 0x8019B988: srl         $t0, $t9, 28
    ctx->r8 = S32(U32(ctx->r25) >> 28);
    // 0x8019B98C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8019B990: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019B994: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8019B998: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8019B99C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8019B9A0: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x8019B9A4: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x8019B9A8: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8019B9AC: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8019B9B0: lwc1        $f6, 0x7C($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X7C);
    // 0x8019B9B4: sh          $s1, 0xE4($s0)
    MEM_H(0XE4, ctx->r16) = ctx->r17;
    // 0x8019B9B8: sh          $t5, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r13;
    // 0x8019B9BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019B9C0: swc1        $f20, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f20.u32l;
    // 0x8019B9C4: sh          $t6, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r14;
    // 0x8019B9C8: sw          $t7, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r15;
    // 0x8019B9CC: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8019B9D0: addiu       $t2, $t2, 0x1FD0
    ctx->r10 = ADD32(ctx->r10, 0X1FD0);
    // 0x8019B9D4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8019B9D8: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8019B9DC: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x8019B9E0: addu        $s2, $t1, $t2
    ctx->r18 = ADD32(ctx->r9, ctx->r10);
    // 0x8019B9E4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8019B9E8: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x8019B9EC: and         $s3, $v1, $at
    ctx->r19 = ctx->r3 & ctx->r1;
    // 0x8019B9F0: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8019B9F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019B9F8: jal         0x80019218
    // 0x8019B9FC: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8019B9FC: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_2:
    // 0x8019BA00: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8019BA04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019BA08: sh          $zero, 0x32($s0)
    MEM_H(0X32, ctx->r16) = 0;
    // 0x8019BA0C: addu        $t4, $t3, $s3
    ctx->r12 = ADD32(ctx->r11, ctx->r19);
    // 0x8019BA10: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x8019BA14: sw          $t5, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r13;
    // 0x8019BA18: swc1        $f22, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f22.u32l;
L_8019BA1C:
    // 0x8019BA1C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8019BA20:
    // 0x8019BA20: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8019BA24: bne         $s1, $at, L_8019B8F4
    if (ctx->r17 != ctx->r1) {
        // 0x8019BA28: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_8019B8F4;
    }
    // 0x8019BA28: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
    // 0x8019BA2C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8019BA30: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8019BA34: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8019BA38: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8019BA3C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8019BA40: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8019BA44: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8019BA48: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8019BA4C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8019BA50: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8019BA54: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8019BA58: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8019BA5C: jr          $ra
    // 0x8019BA60: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8019BA60: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Katina_BossHandleDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193EF0: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80193EF4: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x80193EF8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80193EFC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80193F00: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x80193F04: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80193F08: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x80193F0C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80193F10: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80193F14: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80193F18: lb          $t6, 0x62($s2)
    ctx->r14 = MEM_B(ctx->r18, 0X62);
    // 0x80193F1C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80193F20: beq         $t6, $zero, L_80194260
    if (ctx->r14 == 0) {
        // 0x80193F24: nop
    
            goto L_80194260;
    }
    // 0x80193F24: nop

    // 0x80193F28: sb          $zero, 0x62($s2)
    MEM_B(0X62, ctx->r18) = 0;
    // 0x80193F2C: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x80193F30: lw          $t8, 0x1C8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C8);
    // 0x80193F34: beql        $t8, $zero, L_80194434
    if (ctx->r24 == 0) {
        // 0x80193F38: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80194434;
    }
    goto skip_0;
    // 0x80193F38: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x80193F3C: lh          $v0, 0x66($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X66);
    // 0x80193F40: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x80193F44: beq         $at, $zero, L_80194260
    if (ctx->r1 == 0) {
        // 0x80193F48: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_80194260;
    }
    // 0x80193F48: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80193F4C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80193F50: addu        $at, $at, $t9
    gpr jr_addend_80193F58 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80193F54: lw          $t9, -0x1AC($at)
    ctx->r25 = ADD32(ctx->r1, -0X1AC);
    // 0x80193F58: jr          $t9
    // 0x80193F5C: nop

    switch (jr_addend_80193F58 >> 2) {
        case 0: goto L_80193F60; break;
        case 1: goto L_80193F60; break;
        case 2: goto L_80193F60; break;
        case 3: goto L_80193F60; break;
        case 4: goto L_80194050; break;
        case 5: goto L_80194050; break;
        case 6: goto L_80194050; break;
        case 7: goto L_80194050; break;
        default: switch_error(__func__, 0x80193F58, 0x8019FE54);
    }
    // 0x80193F5C: nop

L_80193F60:
    // 0x80193F60: sll         $t0, $v0, 1
    ctx->r8 = S32(ctx->r2 << 1);
    // 0x80193F64: addu        $s0, $s2, $t0
    ctx->r16 = ADD32(ctx->r18, ctx->r8);
    // 0x80193F68: lh          $t1, 0x9C($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X9C);
    // 0x80193F6C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80193F70: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x80193F74: blez        $t1, L_80194048
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80193F78: nop
    
            goto L_80194048;
    }
    // 0x80193F78: nop

    // 0x80193F7C: lwc1        $f22, -0x18C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X18C);
    // 0x80193F80: sh          $t2, 0x88($s0)
    MEM_H(0X88, ctx->r16) = ctx->r10;
    // 0x80193F84: lh          $t3, 0x66($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X66);
    // 0x80193F88: lh          $t6, 0x64($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X64);
    // 0x80193F8C: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
    // 0x80193F90: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80193F94: addu        $s0, $s2, $t4
    ctx->r16 = ADD32(ctx->r18, ctx->r12);
    // 0x80193F98: lh          $t5, 0x9C($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X9C);
    // 0x80193F9C: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x80193FA0: ori         $a1, $a1, 0x4003
    ctx->r5 = ctx->r5 | 0X4003;
    // 0x80193FA4: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x80193FA8: sh          $t7, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = ctx->r15;
    // 0x80193FAC: lh          $t8, 0x66($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X66);
    // 0x80193FB0: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80193FB4: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80193FB8: multu       $t8, $s3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80193FBC: mflo        $t9
    ctx->r25 = lo;
    // 0x80193FC0: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x80193FC4: lwc1        $f4, 0x1AC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X1AC);
    // 0x80193FC8: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80193FCC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80193FD0: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x80193FD4: lh          $t1, 0x66($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X66);
    // 0x80193FD8: lwc1        $f6, 0x8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80193FDC: multu       $t1, $s3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80193FE0: mflo        $t2
    ctx->r10 = lo;
    // 0x80193FE4: addu        $t3, $s2, $t2
    ctx->r11 = ADD32(ctx->r18, ctx->r10);
    // 0x80193FE8: lwc1        $f18, 0x1B0($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X1B0);
    // 0x80193FEC: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x80193FF0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80193FF4: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x80193FF8: lh          $t4, 0x66($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X66);
    // 0x80193FFC: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80194000: multu       $t4, $s3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80194004: mflo        $t5
    ctx->r13 = lo;
    // 0x80194008: addu        $t6, $s2, $t5
    ctx->r14 = ADD32(ctx->r18, ctx->r13);
    // 0x8019400C: lwc1        $f10, 0x1B4($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X1B4);
    // 0x80194010: mul.s       $f18, $f10, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x80194014: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80194018: jal         0x8007A6F0
    // 0x8019401C: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_0;
    // 0x8019401C: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80194020: lh          $t7, 0x66($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X66);
    // 0x80194024: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80194028: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8019402C: addu        $s0, $s2, $t8
    ctx->r16 = ADD32(ctx->r18, ctx->r24);
    // 0x80194030: lh          $t9, 0x9C($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X9C);
    // 0x80194034: bgtz        $t9, L_80194048
    if (SIGNED(ctx->r25) > 0) {
        // 0x80194038: nop
    
            goto L_80194048;
    }
    // 0x80194038: nop

    // 0x8019403C: sh          $zero, 0x9C($s0)
    MEM_H(0X9C, ctx->r16) = 0;
    // 0x80194040: jal         0x80193CE4
    // 0x80194044: lh          $a1, 0x66($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X66);
    Katina_Hatch_Destroy(rdram, ctx);
        goto after_1;
    // 0x80194044: lh          $a1, 0x66($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X66);
    after_1:
L_80194048:
    // 0x80194048: b           L_80194260
    // 0x8019404C: nop

        goto L_80194260;
    // 0x8019404C: nop

L_80194050:
    // 0x80194050: lh          $v0, 0xA4($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XA4);
    // 0x80194054: blez        $v0, L_80194260
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80194058: nop
    
            goto L_80194260;
    }
    // 0x80194058: nop

    // 0x8019405C: lh          $t0, 0x4E($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X4E);
    // 0x80194060: slti        $at, $t0, 0xB
    ctx->r1 = SIGNED(ctx->r8) < 0XB ? 1 : 0;
    // 0x80194064: bne         $at, $zero, L_80194260
    if (ctx->r1 != 0) {
        // 0x80194068: nop
    
            goto L_80194260;
    }
    // 0x80194068: nop

    // 0x8019406C: lh          $t1, 0x64($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X64);
    // 0x80194070: addiu       $s3, $zero, 0x14
    ctx->r19 = ADD32(0, 0X14);
    // 0x80194074: sh          $s3, 0x90($s2)
    MEM_H(0X90, ctx->r18) = ctx->r19;
    // 0x80194078: subu        $t2, $v0, $t1
    ctx->r10 = SUB32(ctx->r2, ctx->r9);
    // 0x8019407C: sh          $t2, 0xA4($s2)
    MEM_H(0XA4, ctx->r18) = ctx->r10;
    // 0x80194080: lh          $t3, 0xA4($s2)
    ctx->r11 = MEM_H(ctx->r18, 0XA4);
    // 0x80194084: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    // 0x80194088: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x8019408C: slti        $at, $t3, 0x64
    ctx->r1 = SIGNED(ctx->r11) < 0X64 ? 1 : 0;
    // 0x80194090: beq         $at, $zero, L_801940B0
    if (ctx->r1 == 0) {
        // 0x80194094: nop
    
            goto L_801940B0;
    }
    // 0x80194094: nop

    // 0x80194098: lui         $a1, 0x2943
    ctx->r5 = S32(0X2943 << 16);
    // 0x8019409C: ori         $a1, $a1, 0x500F
    ctx->r5 = ctx->r5 | 0X500F;
    // 0x801940A0: jal         0x8007A6F0
    // 0x801940A4: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_2;
    // 0x801940A4: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    after_2:
    // 0x801940A8: b           L_801940BC
    // 0x801940AC: lh          $t4, 0xA4($s2)
    ctx->r12 = MEM_H(ctx->r18, 0XA4);
        goto L_801940BC;
    // 0x801940AC: lh          $t4, 0xA4($s2)
    ctx->r12 = MEM_H(ctx->r18, 0XA4);
L_801940B0:
    // 0x801940B0: jal         0x8007A6F0
    // 0x801940B4: ori         $a1, $a1, 0x4003
    ctx->r5 = ctx->r5 | 0X4003;
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_3;
    // 0x801940B4: ori         $a1, $a1, 0x4003
    ctx->r5 = ctx->r5 | 0X4003;
    after_3:
    // 0x801940B8: lh          $t4, 0xA4($s2)
    ctx->r12 = MEM_H(ctx->r18, 0XA4);
L_801940BC:
    // 0x801940BC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801940C0: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x801940C4: bgtz        $t4, L_80194260
    if (SIGNED(ctx->r12) > 0) {
        // 0x801940C8: nop
    
            goto L_80194260;
    }
    // 0x801940C8: nop

    // 0x801940CC: lwc1        $f8, 0x8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X8);
    // 0x801940D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801940D4: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801940D8: lw          $a2, 0xC($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XC);
    // 0x801940DC: jal         0x8007D2C8
    // 0x801940E0: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_4;
    // 0x801940E0: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_4:
    // 0x801940E4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801940E8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801940EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801940F0: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x801940F4: sh          $t5, 0x9A($s2)
    MEM_H(0X9A, ctx->r18) = ctx->r13;
    // 0x801940F8: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x801940FC: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80194100: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80194104: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x80194108: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8019410C: swc1        $f20, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f20.u32l;
    // 0x80194110: swc1        $f20, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f20.u32l;
    // 0x80194114: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
L_80194118:
    // 0x80194118: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x8019411C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80194120: lwc1        $f10, -0x184($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X184);
    // 0x80194124: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80194128: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019412C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80194130: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80194134: nop

    // 0x80194138: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019413C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80194140: jal         0x80005E90
    // 0x80194144: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x80194144: nop

    after_5:
    // 0x80194148: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019414C: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80194150: jal         0x80006A20
    // 0x80194154: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_6;
    // 0x80194154: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_6:
    // 0x80194158: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8019415C: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80194160: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80194164: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80194168: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019416C: lwc1        $f8, 0x8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80194170: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80194174: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80194178: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8019417C: lui         $a3, 0x3FCC
    ctx->r7 = S32(0X3FCC << 16);
    // 0x80194180: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80194184: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80194188: add.s       $f14, $f18, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x8019418C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80194190: jal         0x800794CC
    // 0x80194194: nop

    Effect_Effect357_Spawn50(rdram, ctx);
        goto after_7;
    // 0x80194194: nop

    after_7:
    // 0x80194198: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8019419C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801941A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801941A4: lwc1        $f4, -0x180($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X180);
    // 0x801941A8: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x801941AC: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
    // 0x801941B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801941B4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801941B8: add.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f10.fl;
    // 0x801941BC: bne         $s0, $at, L_80194118
    if (ctx->r16 != ctx->r1) {
        // 0x801941C0: swc1        $f6, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
            goto L_80194118;
    }
    // 0x801941C0: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x801941C4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801941C8: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x801941CC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801941D0: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x801941D4: lui         $a0, 0x2940
    ctx->r4 = S32(0X2940 << 16);
    // 0x801941D8: ori         $a0, $a0, 0xD09A
    ctx->r4 = ctx->r4 | 0XD09A;
    // 0x801941DC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801941E0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801941E4: addiu       $a1, $s2, 0x3FC
    ctx->r5 = ADD32(ctx->r18, 0X3FC);
    // 0x801941E8: jal         0x80019218
    // 0x801941EC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_8;
    // 0x801941EC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_8:
    // 0x801941F0: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x801941F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801941F8: sh          $t7, 0x1A60($at)
    MEM_H(0X1A60, ctx->r1) = ctx->r15;
    // 0x801941FC: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x80194200: lui         $a0, 0x1032
    ctx->r4 = S32(0X1032 << 16);
    // 0x80194204: sh          $s3, 0x4E($s2)
    MEM_H(0X4E, ctx->r18) = ctx->r19;
    // 0x80194208: sh          $t8, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r24;
    // 0x8019420C: jal         0x800182F4
    // 0x80194210: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_9;
    // 0x80194210: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_9:
    // 0x80194214: lui         $a0, 0x1132
    ctx->r4 = S32(0X1132 << 16);
    // 0x80194218: jal         0x800182F4
    // 0x8019421C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_10;
    // 0x8019421C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_10:
    // 0x80194220: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80194224: addiu       $a0, $a0, 0x2774
    ctx->r4 = ADD32(ctx->r4, 0X2774);
    // 0x80194228: jal         0x800BA808
    // 0x8019422C: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    Radio_PlayMessage(rdram, ctx);
        goto after_11;
    // 0x8019422C: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    after_11:
    // 0x80194230: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80194234: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80194238: lwc1        $f8, 0x8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8019423C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80194240: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80194244: jal         0x80042EC0
    // 0x80194248: swc1        $f18, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f18.u32l;
    Boss_AwardBonus(rdram, ctx);
        goto after_12;
    // 0x80194248: swc1        $f18, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f18.u32l;
    after_12:
    // 0x8019424C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80194250: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80194254: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80194258: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019425C: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
L_80194260:
    // 0x80194260: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80194264: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x80194268: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019426C: lwc1        $f22, -0x17C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X17C);
    // 0x80194270: lw          $t0, 0x1C8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C8);
    // 0x80194274: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80194278: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8019427C: bne         $t0, $at, L_80194344
    if (ctx->r8 != ctx->r1) {
        // 0x80194280: addiu       $s3, $zero, 0xC
        ctx->r19 = ADD32(0, 0XC);
            goto L_80194344;
    }
    // 0x80194280: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
    // 0x80194284: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80194288: lw          $t1, 0x7DB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DB0);
    // 0x8019428C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80194290: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x80194294: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x80194298: bne         $t2, $zero, L_80194344
    if (ctx->r10 != 0) {
        // 0x8019429C: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_80194344;
    }
    // 0x8019429C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801942A0: lwc1        $f20, -0x178($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X178);
L_801942A4:
    // 0x801942A4: lh          $t3, 0x9C($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X9C);
    // 0x801942A8: bgtzl       $t3, L_80194338
    if (SIGNED(ctx->r11) > 0) {
        // 0x801942AC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80194338;
    }
    goto skip_1;
    // 0x801942AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x801942B0: jal         0x80004EB0
    // 0x801942B4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_13;
    // 0x801942B4: nop

    after_13:
    // 0x801942B8: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x801942BC: nop

    // 0x801942C0: bc1fl       L_80194338
    if (!c1cs) {
        // 0x801942C4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80194338;
    }
    goto skip_2;
    // 0x801942C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x801942C8: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801942CC: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801942D0: lw          $a3, 0x6C($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X6C);
    // 0x801942D4: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x801942D8: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x801942DC: mflo        $t4
    ctx->r12 = lo;
    // 0x801942E0: addu        $v0, $s2, $t4
    ctx->r2 = ADD32(ctx->r18, ctx->r12);
    // 0x801942E4: lwc1        $f10, 0x1AC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1AC);
    // 0x801942E8: lwc1        $f6, 0x1B0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1B0);
    // 0x801942EC: mul.s       $f18, $f10, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x801942F0: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
    // 0x801942F4: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x801942F8: lwc1        $f6, 0xC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XC);
    // 0x801942FC: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80194300: lwc1        $f18, 0x1B4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1B4);
    // 0x80194304: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80194308: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x8019430C: lwc1        $f10, 0x70($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X70);
    // 0x80194310: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80194314: lwc1        $f18, 0x74($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X74);
    // 0x80194318: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8019431C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80194320: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80194324: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80194328: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8019432C: jal         0x8007BFFC
    // 0x80194330: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_14;
    // 0x80194330: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_14:
    // 0x80194334: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80194338:
    // 0x80194338: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8019433C: bne         $s0, $at, L_801942A4
    if (ctx->r16 != ctx->r1) {
        // 0x80194340: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_801942A4;
    }
    // 0x80194340: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
L_80194344:
    // 0x80194344: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80194348: lwc1        $f20, -0x174($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X174);
    // 0x8019434C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80194350: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_80194354:
    // 0x80194354: lh          $v0, 0x92($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X92);
    // 0x80194358: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8019435C: beq         $v0, $zero, L_80194420
    if (ctx->r2 == 0) {
        // 0x80194360: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80194420;
    }
    // 0x80194360: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80194364: beq         $at, $zero, L_801943E4
    if (ctx->r1 == 0) {
        // 0x80194368: sh          $t6, 0x92($s1)
        MEM_H(0X92, ctx->r17) = ctx->r14;
            goto L_801943E4;
    }
    // 0x80194368: sh          $t6, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r14;
    // 0x8019436C: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80194370: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80194374: lwc1        $f10, -0x170($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X170);
    // 0x80194378: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8019437C: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80194380: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80194384: mflo        $t7
    ctx->r15 = lo;
    // 0x80194388: addu        $v0, $s2, $t7
    ctx->r2 = ADD32(ctx->r18, ctx->r15);
    // 0x8019438C: lwc1        $f0, 0x1AC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1AC);
    // 0x80194390: lwc1        $f2, 0x1B0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X1B0);
    // 0x80194394: lwc1        $f16, 0x1B4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1B4);
    // 0x80194398: mul.s       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8019439C: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801943A0: mul.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x801943A4: lwc1        $f8, 0xC($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0XC);
    // 0x801943A8: mul.s       $f6, $f16, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x801943AC: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801943B0: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x801943B4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801943B8: mul.s       $f4, $f2, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x801943BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801943C0: mul.s       $f6, $f16, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x801943C4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801943C8: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801943CC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801943D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801943D4: jal         0x80192C08
    // 0x801943D8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Katina_FireSmokeEffectSpawn(rdram, ctx);
        goto after_15;
    // 0x801943D8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_15:
    // 0x801943DC: b           L_80194424
    // 0x801943E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80194424;
    // 0x801943E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801943E4:
    // 0x801943E4: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x801943E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801943EC: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x801943F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801943F4: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
    // 0x801943F8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801943FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80194400: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80194404: lw          $a2, 0xC($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XC);
    // 0x80194408: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8019440C: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x80194410: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80194414: sub.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80194418: jal         0x80192C08
    // 0x8019441C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Katina_FireSmokeEffectSpawn(rdram, ctx);
        goto after_16;
    // 0x8019441C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_16:
L_80194420:
    // 0x80194420: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80194424:
    // 0x80194424: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80194428: bne         $s0, $at, L_80194354
    if (ctx->r16 != ctx->r1) {
        // 0x8019442C: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_80194354;
    }
    // 0x8019442C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80194430: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80194434:
    // 0x80194434: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80194438: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8019443C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80194440: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x80194444: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x80194448: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x8019444C: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x80194450: jr          $ra
    // 0x80194454: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80194454: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void Bolse_ActorCsBoFighter_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EE4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018EE50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018EE54: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018EE58: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x8018EE5C: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x8018EE60: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8018EE64: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x8018EE68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018EE6C: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
L_8018EE70:
    // 0x8018EE70: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8018EE74: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8018EE78: bne         $t6, $zero, L_8018EF50
    if (ctx->r14 != 0) {
        // 0x8018EE7C: nop
    
            goto L_8018EF50;
    }
    // 0x8018EE7C: nop

    // 0x8018EE80: jal         0x800613C4
    // 0x8018EE84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018EE84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8018EE88: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018EE8C: addiu       $t8, $zero, 0xC3
    ctx->r24 = ADD32(0, 0XC3);
    // 0x8018EE90: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x8018EE94: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x8018EE98: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8018EE9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018EEA0: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x8018EEA4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8018EEA8: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8018EEAC: lwc1        $f6, -0x2C70($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2C70);
    // 0x8018EEB0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018EEB4: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
    // 0x8018EEB8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018EEBC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x8018EEC0: lwc1        $f16, -0x64C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X64C);
    // 0x8018EEC4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8018EEC8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018EECC: sh          $t9, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r25;
    // 0x8018EED0: sh          $t0, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r8;
    // 0x8018EED4: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8018EED8: jal         0x80004EB0
    // 0x8018EEDC: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8018EEDC: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
    after_1:
    // 0x8018EEE0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018EEE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018EEE8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8018EEEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018EEF0: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8018EEF4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018EEF8: jal         0x80004EB0
    // 0x8018EEFC: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8018EEFC: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    after_2:
    // 0x8018EF00: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018EF04: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018EF08: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8018EF0C: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8018EF10: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8018EF14: jal         0x800612B8
    // 0x8018EF18: swc1        $f18, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f18.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x8018EF18: swc1        $f18, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f18.u32l;
    after_3:
    // 0x8018EF1C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018EF20: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8018EF24: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018EF28: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8018EF2C: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x8018EF30: ori         $a0, $a0, 0x2002
    ctx->r4 = ctx->r4 | 0X2002;
    // 0x8018EF34: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8018EF38: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018EF3C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8018EF40: jal         0x80019218
    // 0x8018EF44: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x8018EF44: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x8018EF48: b           L_8018EF5C
    // 0x8018EF4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8018EF5C;
    // 0x8018EF4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8018EF50:
    // 0x8018EF50: bne         $v0, $v1, L_8018EE70
    if (ctx->r2 != ctx->r3) {
        // 0x8018EF54: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_8018EE70;
    }
    // 0x8018EF54: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
    // 0x8018EF58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8018EF5C:
    // 0x8018EF5C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018EF60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018EF64: jr          $ra
    // 0x8018EF68: nop

    return;
    // 0x8018EF68: nop

;}
RECOMP_FUNC void Katina_KaFrontlineBase_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193718: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8019371C: sw          $s3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r19;
    // 0x80193720: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80193724: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80193728: sw          $s2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r18;
    // 0x8019372C: sw          $s1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r17;
    // 0x80193730: sw          $s0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r16;
    // 0x80193734: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80193738: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x8019373C: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80193740: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80193744: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80193748: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8019374C: lh          $v1, 0x4E($s3)
    ctx->r3 = MEM_H(ctx->r19, 0X4E);
    // 0x80193750: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80193754: beq         $v1, $zero, L_80193AB0
    if (ctx->r3 == 0) {
        // 0x80193758: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80193AB0;
    }
    // 0x80193758: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8019375C: beq         $v1, $at, L_80193778
    if (ctx->r3 == ctx->r1) {
        // 0x80193760: addiu       $t6, $zero, 0x4
        ctx->r14 = ADD32(0, 0X4);
            goto L_80193778;
    }
    // 0x80193760: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80193764: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x80193768: beql        $v0, $s2, L_801937EC
    if (ctx->r2 == ctx->r18) {
        // 0x8019376C: lh          $t1, 0x50($s3)
        ctx->r9 = MEM_H(ctx->r19, 0X50);
            goto L_801937EC;
    }
    goto skip_0;
    // 0x8019376C: lh          $t1, 0x50($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X50);
    skip_0:
    // 0x80193770: b           L_80193AB4
    // 0x80193774: lb          $t0, 0x62($s3)
    ctx->r8 = MEM_B(ctx->r19, 0X62);
        goto L_80193AB4;
    // 0x80193774: lb          $t0, 0x62($s3)
    ctx->r8 = MEM_B(ctx->r19, 0X62);
L_80193778:
    // 0x80193778: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8019377C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80193780: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80193784: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80193788: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8019378C: lwc1        $f4, 0x8($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80193790: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x80193794: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80193798: sh          $t6, 0x50($s3)
    MEM_H(0X50, ctx->r19) = ctx->r14;
    // 0x8019379C: sh          $t7, 0x4E($s3)
    MEM_H(0X4E, ctx->r19) = ctx->r15;
    // 0x801937A0: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    // 0x801937A4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x801937A8: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x801937AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801937B0: lui         $a3, 0x428E
    ctx->r7 = S32(0X428E << 16);
    // 0x801937B4: jal         0x8007B344
    // 0x801937B8: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    Effect_Effect384_Spawn(rdram, ctx);
        goto after_0;
    // 0x801937B8: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x801937BC: addiu       $t9, $zero, 0x19
    ctx->r25 = ADD32(0, 0X19);
    // 0x801937C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801937C4: sw          $t9, -0x7B80($at)
    MEM_W(-0X7B80, ctx->r1) = ctx->r25;
    // 0x801937C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801937CC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801937D0: sw          $t0, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r8;
    // 0x801937D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801937D8: sw          $zero, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = 0;
    // 0x801937DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801937E0: sw          $zero, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = 0;
    // 0x801937E4: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x801937E8: lh          $t1, 0x50($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X50);
L_801937EC:
    // 0x801937EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801937F0: bne         $t1, $at, L_801939A8
    if (ctx->r9 != ctx->r1) {
        // 0x801937F4: lui         $at, 0x43FA
        ctx->r1 = S32(0X43FA << 16);
            goto L_801939A8;
    }
    // 0x801937F4: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x801937F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801937FC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80193800: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80193804: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80193808: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8019380C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80193810: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80193814: lui         $at, 0x40C8
    ctx->r1 = S32(0X40C8 << 16);
    // 0x80193818: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8019381C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80193820: swc1        $f4, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f4.u32l;
    // 0x80193824: swc1        $f22, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f22.u32l;
    // 0x80193828: bc1f        L_801938E8
    if (!c1cs) {
        // 0x8019382C: swc1        $f22, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->f22.u32l;
            goto L_801938E8;
    }
    // 0x8019382C: swc1        $f22, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f22.u32l;
    // 0x80193830: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80193834: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80193838: lwc1        $f28, -0x1C0($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X1C0);
    // 0x8019383C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80193840: lwc1        $f26, -0x1BC($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X1BC);
    // 0x80193844: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x80193848: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8019384C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80193850: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x80193854: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
L_80193858:
    // 0x80193858: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019385C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80193860: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80193864: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x80193868: nop

    // 0x8019386C: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80193870: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80193874: jal         0x80005E90
    // 0x80193878: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x80193878: nop

    after_1:
    // 0x8019387C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80193880: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    // 0x80193884: jal         0x80006A20
    // 0x80193888: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x80193888: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    after_2:
    // 0x8019388C: lwc1        $f0, 0x98($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80193890: lwc1        $f12, 0x90($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80193894: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80193898: nop

    // 0x8019389C: bc1fl       L_801938D0
    if (!c1cs) {
        // 0x801938A0: lui         $at, 0x4416
        ctx->r1 = S32(0X4416 << 16);
            goto L_801938D0;
    }
    goto skip_1;
    // 0x801938A0: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    skip_1:
    // 0x801938A4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801938A8: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x801938AC: jal         0x8007953C
    // 0x801938B0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    Effect_Effect357_Spawn80(rdram, ctx);
        goto after_3;
    // 0x801938B0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_3:
    // 0x801938B4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801938B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801938BC: lwc1        $f8, 0xA4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x801938C0: add.s       $f20, $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f30.fl;
    // 0x801938C4: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801938C8: swc1        $f18, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f18.u32l;
    // 0x801938CC: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
L_801938D0:
    // 0x801938D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801938D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801938D8: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x801938DC: nop

    // 0x801938E0: bc1tl       L_80193858
    if (c1cs) {
        // 0x801938E4: mtc1        $s0, $f10
        ctx->f10.u32l = ctx->r16;
            goto L_80193858;
    }
    goto skip_2;
    // 0x801938E4: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    skip_2:
L_801938E8:
    // 0x801938E8: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x801938EC: lbu         $t2, 0x5D68($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X5D68);
    // 0x801938F0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x801938F4: addiu       $v0, $v0, 0x605C
    ctx->r2 = ADD32(ctx->r2, 0X605C);
    // 0x801938F8: bne         $s2, $t2, L_80193918
    if (ctx->r18 != ctx->r10) {
        // 0x801938FC: addiu       $s0, $zero, 0xC
        ctx->r16 = ADD32(0, 0XC);
            goto L_80193918;
    }
    // 0x801938FC: addiu       $s0, $zero, 0xC
    ctx->r16 = ADD32(0, 0XC);
    // 0x80193900: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80193904: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80193908: sb          $t3, 0x5D68($at)
    MEM_B(0X5D68, ctx->r1) = ctx->r11;
    // 0x8019390C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80193910: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x80193914: sh          $t4, 0x5E24($at)
    MEM_H(0X5E24, ctx->r1) = ctx->r12;
L_80193918:
    // 0x80193918: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x8019391C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80193920: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80193924: bne         $s2, $t5, L_80193934
    if (ctx->r18 != ctx->r13) {
        // 0x80193928: addiu       $a0, $zero, 0x1E
        ctx->r4 = ADD32(0, 0X1E);
            goto L_80193934;
    }
    // 0x80193928: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8019392C: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x80193930: sh          $a0, 0xBC($v0)
    MEM_H(0XBC, ctx->r2) = ctx->r4;
L_80193934:
    // 0x80193934: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80193938: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x8019393C: addiu       $v0, $v0, 0x2F4
    ctx->r2 = ADD32(ctx->r2, 0X2F4);
L_80193940:
    // 0x80193940: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80193944: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80193948: bnel        $s2, $t6, L_8019395C
    if (ctx->r18 != ctx->r14) {
        // 0x8019394C: lbu         $t7, 0x2F4($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X2F4);
            goto L_8019395C;
    }
    goto skip_3;
    // 0x8019394C: lbu         $t7, 0x2F4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2F4);
    skip_3:
    // 0x80193950: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x80193954: sh          $a0, 0xBC($v0)
    MEM_H(0XBC, ctx->r2) = ctx->r4;
    // 0x80193958: lbu         $t7, 0x2F4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2F4);
L_8019395C:
    // 0x8019395C: addiu       $v0, $v0, 0x2F4
    ctx->r2 = ADD32(ctx->r2, 0X2F4);
    // 0x80193960: bnel        $s2, $t7, L_80193974
    if (ctx->r18 != ctx->r15) {
        // 0x80193964: lbu         $t8, 0x2F4($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0X2F4);
            goto L_80193974;
    }
    goto skip_4;
    // 0x80193964: lbu         $t8, 0x2F4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2F4);
    skip_4:
    // 0x80193968: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8019396C: sh          $a0, 0xBC($v0)
    MEM_H(0XBC, ctx->r2) = ctx->r4;
    // 0x80193970: lbu         $t8, 0x2F4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2F4);
L_80193974:
    // 0x80193974: addiu       $v0, $v0, 0x2F4
    ctx->r2 = ADD32(ctx->r2, 0X2F4);
    // 0x80193978: bnel        $s2, $t8, L_8019398C
    if (ctx->r18 != ctx->r24) {
        // 0x8019397C: lbu         $t9, 0x2F4($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X2F4);
            goto L_8019398C;
    }
    goto skip_5;
    // 0x8019397C: lbu         $t9, 0x2F4($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2F4);
    skip_5:
    // 0x80193980: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x80193984: sh          $a0, 0xBC($v0)
    MEM_H(0XBC, ctx->r2) = ctx->r4;
    // 0x80193988: lbu         $t9, 0x2F4($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2F4);
L_8019398C:
    // 0x8019398C: addiu       $v0, $v0, 0x2F4
    ctx->r2 = ADD32(ctx->r2, 0X2F4);
    // 0x80193990: bne         $s2, $t9, L_801939A0
    if (ctx->r18 != ctx->r25) {
        // 0x80193994: nop
    
            goto L_801939A0;
    }
    // 0x80193994: nop

    // 0x80193998: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8019399C: sh          $a0, 0xBC($v0)
    MEM_H(0XBC, ctx->r2) = ctx->r4;
L_801939A0:
    // 0x801939A0: bne         $s0, $a1, L_80193940
    if (ctx->r16 != ctx->r5) {
        // 0x801939A4: addiu       $v0, $v0, 0x2F4
        ctx->r2 = ADD32(ctx->r2, 0X2F4);
            goto L_80193940;
    }
    // 0x801939A4: addiu       $v0, $v0, 0x2F4
    ctx->r2 = ADD32(ctx->r2, 0X2F4);
L_801939A8:
    // 0x801939A8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801939AC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801939B0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801939B4:
    // 0x801939B4: jal         0x80004EB0
    // 0x801939B8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x801939B8: nop

    after_4:
    // 0x801939BC: jal         0x80004EB0
    // 0x801939C0: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x801939C0: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    after_5:
    // 0x801939C4: jal         0x80004EB0
    // 0x801939C8: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x801939C8: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x801939CC: jal         0x80004EB0
    // 0x801939D0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x801939D0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_7:
    // 0x801939D4: jal         0x80004EB0
    // 0x801939D8: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x801939D8: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    after_8:
    // 0x801939DC: jal         0x80004EB0
    // 0x801939E0: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x801939E0: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    after_9:
    // 0x801939E4: jal         0x80004EB0
    // 0x801939E8: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x801939E8: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    after_10:
    // 0x801939EC: sub.s       $f6, $f30, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f30.fl - ctx->f20.fl;
    // 0x801939F0: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x801939F4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801939F8: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801939FC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80193A00: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80193A04: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80193A08: sub.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f20.fl;
    // 0x80193A0C: lwc1        $f10, 0x4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80193A10: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80193A14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80193A18: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80193A1C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80193A20: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80193A24: lwc1        $f10, 0x8($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80193A28: sub.s       $f6, $f22, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f20.fl;
    // 0x80193A2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80193A30: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80193A34: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80193A38: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80193A3C: lwc1        $f18, 0xC($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80193A40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80193A44: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80193A48: add.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80193A4C: sub.s       $f4, $f24, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f24.fl - ctx->f20.fl;
    // 0x80193A50: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80193A54: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80193A58: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80193A5C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80193A60: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80193A64: mul.s       $f8, $f26, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f18.fl);
    // 0x80193A68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80193A6C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80193A70: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80193A74: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80193A78: sub.s       $f10, $f28, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f28.fl - ctx->f20.fl;
    // 0x80193A7C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80193A80: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80193A84: nop

    // 0x80193A88: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80193A8C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80193A90: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80193A94: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80193A98: jal         0x80192C08
    // 0x80193A9C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Katina_FireSmokeEffectSpawn(rdram, ctx);
        goto after_11;
    // 0x80193A9C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x80193AA0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80193AA4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80193AA8: bne         $s0, $at, L_801939B4
    if (ctx->r16 != ctx->r1) {
        // 0x80193AAC: nop
    
            goto L_801939B4;
    }
    // 0x80193AAC: nop

L_80193AB0:
    // 0x80193AB0: lb          $t0, 0x62($s3)
    ctx->r8 = MEM_B(ctx->r19, 0X62);
L_80193AB4:
    // 0x80193AB4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80193AB8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80193ABC: beq         $t0, $zero, L_80193AE8
    if (ctx->r8 == 0) {
        // 0x80193AC0: lui         $a0, 0x2912
        ctx->r4 = S32(0X2912 << 16);
            goto L_80193AE8;
    }
    // 0x80193AC0: lui         $a0, 0x2912
    ctx->r4 = S32(0X2912 << 16);
    // 0x80193AC4: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80193AC8: sb          $zero, 0x62($s3)
    MEM_B(0X62, ctx->r19) = 0;
    // 0x80193ACC: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x80193AD0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80193AD4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80193AD8: ori         $a0, $a0, 0x1007
    ctx->r4 = ctx->r4 | 0X1007;
    // 0x80193ADC: addiu       $a1, $s3, 0x3FC
    ctx->r5 = ADD32(ctx->r19, 0X3FC);
    // 0x80193AE0: jal         0x80019218
    // 0x80193AE4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_12;
    // 0x80193AE4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_12:
L_80193AE8:
    // 0x80193AE8: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80193AEC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80193AF0: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80193AF4: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80193AF8: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80193AFC: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80193B00: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80193B04: lw          $s0, 0x54($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X54);
    // 0x80193B08: lw          $s1, 0x58($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X58);
    // 0x80193B0C: lw          $s2, 0x5C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X5C);
    // 0x80193B10: lw          $s3, 0x60($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X60);
    // 0x80193B14: jr          $ra
    // 0x80193B18: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80193B18: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void Bolse_8018D124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D124: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8018D128: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8018D12C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018D130: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8018D134: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8018D138: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018D13C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D140: lwc1        $f10, -0x684($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X684);
    // 0x8018D144: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018D148: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018D14C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018D150: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018D154: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018D158: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8018D15C: jal         0x80005E90
    // 0x8018D160: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x8018D160: nop

    after_0:
    // 0x8018D164: lwc1        $f18, 0xF4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8018D168: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D16C: lwc1        $f6, -0x680($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X680);
    // 0x8018D170: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8018D174: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018D178: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018D17C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018D180: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D184: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018D188: jal         0x80005D44
    // 0x8018D18C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x8018D18C: nop

    after_1:
    // 0x8018D190: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018D194: lhu         $t6, 0x7828($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X7828);
    // 0x8018D198: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018D19C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018D1A0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8018D1A4: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8018D1A8: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x8018D1AC: bgez        $t6, L_8018D1C4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8018D1B0: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8018D1C4;
    }
    // 0x8018D1B0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018D1B4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018D1B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018D1BC: nop

    // 0x8018D1C0: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8018D1C4:
    // 0x8018D1C4: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x8018D1C8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018D1CC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8018D1D0: jal         0x80006A20
    // 0x8018D1D4: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x8018D1D4: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_2:
    // 0x8018D1D8: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D1DC: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018D1E0: lwc1        $f14, 0xF4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8018D1E4: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8018D1E8: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018D1EC: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8018D1F0: add.s       $f18, $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x8018D1F4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018D1F8: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8018D1FC: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x8018D200: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018D204: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018D208: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018D20C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x8018D210: lwc1        $f14, 0xF8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8018D214: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018D218: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018D21C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018D220: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018D224: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018D228: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    // 0x8018D22C: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8018D230: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8018D234: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x8018D238: add.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8018D23C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8018D240: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8018D244: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8018D248: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8018D24C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8018D250: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8018D254: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8018D258: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8018D25C: jal         0x8007F04C
    // 0x8018D260: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    Effect_SpawnById2(rdram, ctx);
        goto after_3;
    // 0x8018D260: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x8018D264: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8018D268: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8018D26C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8018D270: jr          $ra
    // 0x8018D274: nop

    return;
    // 0x8018D274: nop

;}
RECOMP_FUNC void Bolse_SpawnEnemies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018BEF8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018BEFC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018BF00: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018BF04: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8018BF08: addiu       $v0, $a1, 0xA
    ctx->r2 = ADD32(ctx->r5, 0XA);
    // 0x8018BF0C: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x8018BF10: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8018BF14: addiu       $s0, $s0, 0x5D68
    ctx->r16 = ADD32(ctx->r16, 0X5D68);
    // 0x8018BF18: bne         $at, $zero, L_8018C144
    if (ctx->r1 != 0) {
        // 0x8018BF1C: addiu       $v1, $zero, 0xA
        ctx->r3 = ADD32(0, 0XA);
            goto L_8018C144;
    }
    // 0x8018BF1C: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
L_8018BF20:
    // 0x8018BF20: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8018BF24: bne         $t6, $zero, L_8018C138
    if (ctx->r14 != 0) {
        // 0x8018BF28: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8018C138;
    }
    // 0x8018BF28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018BF2C: jal         0x800613C4
    // 0x8018BF30: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018BF30: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x8018BF34: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018BF38: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8018BF3C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8018BF40: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8018BF44: addiu       $t8, $zero, 0xC5
    ctx->r24 = ADD32(0, 0XC5);
    // 0x8018BF48: addiu       $t0, $t0, 0x530
    ctx->r8 = ADD32(ctx->r8, 0X530);
    // 0x8018BF4C: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x8018BF50: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x8018BF54: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8018BF58: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8018BF5C: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8018BF60: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8018BF64: slti        $at, $t9, 0x3E9
    ctx->r1 = SIGNED(ctx->r25) < 0X3E9 ? 1 : 0;
    // 0x8018BF68: bne         $at, $zero, L_8018BF94
    if (ctx->r1 != 0) {
        // 0x8018BF6C: ori         $a0, $a0, 0x305F
        ctx->r4 = ctx->r4 | 0X305F;
            goto L_8018BF94;
    }
    // 0x8018BF6C: ori         $a0, $a0, 0x305F
    ctx->r4 = ctx->r4 | 0X305F;
    // 0x8018BF70: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018BF74: lwc1        $f6, -0x6E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6E0);
    // 0x8018BF78: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018BF7C: addiu       $t1, $s0, 0x100
    ctx->r9 = ADD32(ctx->r16, 0X100);
    // 0x8018BF80: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8018BF84: lwc1        $f8, -0x6DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6DC);
    // 0x8018BF88: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8018BF8C: b           L_8018C00C
    // 0x8018BF90: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
        goto L_8018C00C;
    // 0x8018BF90: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_8018BF94:
    // 0x8018BF94: lh          $t3, 0x4E($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X4E);
    // 0x8018BF98: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018BF9C: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8018BFA0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8018BFA4: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8018BFA8: lwc1        $f10, -0x111C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X111C);
    // 0x8018BFAC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8018BFB0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018BFB4: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x8018BFB8: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8018BFBC: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x8018BFC0: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8018BFC4: addiu       $a3, $t5, 0x5D34
    ctx->r7 = ADD32(ctx->r13, 0X5D34);
    // 0x8018BFC8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8018BFCC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8018BFD0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018BFD4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8018BFD8: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8018BFDC: jal         0x80019218
    // 0x8018BFE0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8018BFE0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8018BFE4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8018BFE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018BFEC: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8018BFF0: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8018BFF4: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8018BFF8: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8018BFFC: addiu       $t0, $t0, 0x530
    ctx->r8 = ADD32(ctx->r8, 0X530);
    // 0x8018C000: sh          $t7, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r15;
    // 0x8018C004: sh          $t8, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r24;
    // 0x8018C008: swc1        $f18, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f18.u32l;
L_8018C00C:
    // 0x8018C00C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8018C010: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8018C014: addiu       $t9, $zero, 0x12C
    ctx->r25 = ADD32(0, 0X12C);
    // 0x8018C018: slti        $at, $v1, 0xD
    ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
    // 0x8018C01C: sh          $a0, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r4;
    // 0x8018C020: sh          $t9, 0xC4($s0)
    MEM_H(0XC4, ctx->r16) = ctx->r25;
    // 0x8018C024: sh          $v1, 0xE4($s0)
    MEM_H(0XE4, ctx->r16) = ctx->r3;
    // 0x8018C028: beq         $at, $zero, L_8018C044
    if (ctx->r1 == 0) {
        // 0x8018C02C: sh          $v0, 0xE6($s0)
        MEM_H(0XE6, ctx->r16) = ctx->r2;
            goto L_8018C044;
    }
    // 0x8018C02C: sh          $v0, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r2;
    // 0x8018C030: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8018C034: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8018C038: addiu       $a1, $a1, 0x3FE0
    ctx->r5 = ADD32(ctx->r5, 0X3FE0);
    // 0x8018C03C: sh          $t1, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r9;
    // 0x8018C040: sh          $v0, 0x6CE($a1)
    MEM_H(0X6CE, ctx->r5) = ctx->r2;
L_8018C044:
    // 0x8018C044: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8018C048: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8018C04C: beq         $v1, $at, L_8018C060
    if (ctx->r3 == ctx->r1) {
        // 0x8018C050: addiu       $a1, $a1, 0x3FE0
        ctx->r5 = ADD32(ctx->r5, 0X3FE0);
            goto L_8018C060;
    }
    // 0x8018C050: addiu       $a1, $a1, 0x3FE0
    ctx->r5 = ADD32(ctx->r5, 0X3FE0);
    // 0x8018C054: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8018C058: bnel        $v1, $at, L_8018C068
    if (ctx->r3 != ctx->r1) {
        // 0x8018C05C: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_8018C068;
    }
    goto skip_0;
    // 0x8018C05C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    skip_0:
L_8018C060:
    // 0x8018C060: sh          $zero, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = 0;
    // 0x8018C064: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
L_8018C068:
    // 0x8018C068: beq         $v1, $at, L_8018C078
    if (ctx->r3 == ctx->r1) {
        // 0x8018C06C: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_8018C078;
    }
    // 0x8018C06C: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    // 0x8018C070: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x8018C074: bne         $v1, $at, L_8018C084
    if (ctx->r3 != ctx->r1) {
        // 0x8018C078: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8018C084;
    }
L_8018C078:
    // 0x8018C078: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8018C07C: sh          $t2, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r10;
    // 0x8018C080: sh          $v0, 0x9C2($a1)
    MEM_H(0X9C2, ctx->r5) = ctx->r2;
L_8018C084:
    // 0x8018C084: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8018C088: bne         $v1, $at, L_8018C098
    if (ctx->r3 != ctx->r1) {
        // 0x8018C08C: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_8018C098;
    }
    // 0x8018C08C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8018C090: sh          $a0, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r4;
    // 0x8018C094: sh          $v0, 0x3DA($a1)
    MEM_H(0X3DA, ctx->r5) = ctx->r2;
L_8018C098:
    // 0x8018C098: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8018C09C: slti        $at, $t3, 0x3E81
    ctx->r1 = SIGNED(ctx->r11) < 0X3E81 ? 1 : 0;
    // 0x8018C0A0: bne         $at, $zero, L_8018C0BC
    if (ctx->r1 != 0) {
        // 0x8018C0A4: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_8018C0BC;
    }
    // 0x8018C0A4: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x8018C0A8: beq         $v1, $at, L_8018C0B8
    if (ctx->r3 == ctx->r1) {
        // 0x8018C0AC: addiu       $at, $zero, 0x18
        ctx->r1 = ADD32(0, 0X18);
            goto L_8018C0B8;
    }
    // 0x8018C0AC: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8018C0B0: bnel        $v1, $at, L_8018C0C0
    if (ctx->r3 != ctx->r1) {
        // 0x8018C0B4: sh          $t4, 0xCE($s0)
        MEM_H(0XCE, ctx->r16) = ctx->r12;
            goto L_8018C0C0;
    }
    goto skip_1;
    // 0x8018C0B4: sh          $t4, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r12;
    skip_1:
L_8018C0B8:
    // 0x8018C0B8: sh          $zero, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = 0;
L_8018C0BC:
    // 0x8018C0BC: sh          $t4, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r12;
L_8018C0C0:
    // 0x8018C0C0: sw          $a0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r4;
    // 0x8018C0C4: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8018C0C8: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8018C0CC: slti        $at, $t5, 0x3E80
    ctx->r1 = SIGNED(ctx->r13) < 0X3E80 ? 1 : 0;
    // 0x8018C0D0: beq         $at, $zero, L_8018C0DC
    if (ctx->r1 == 0) {
        // 0x8018C0D4: nop
    
            goto L_8018C0DC;
    }
    // 0x8018C0D4: nop

    // 0x8018C0D8: sb          $t6, 0x44($s0)
    MEM_B(0X44, ctx->r16) = ctx->r14;
L_8018C0DC:
    // 0x8018C0DC: jal         0x800612B8
    // 0x8018C0E0: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x8018C0E0: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_2:
    // 0x8018C0E4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018C0E8: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8018C0EC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018C0F0: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8018C0F4: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8018C0F8: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x8018C0FC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018C100: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018C104: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8018C108: jal         0x80019218
    // 0x8018C10C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x8018C10C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x8018C110: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8018C114: lh          $t8, 0x4E($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4E);
    // 0x8018C118: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8018C11C: sh          $t9, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r25;
    // 0x8018C120: lh          $t1, 0x4E($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X4E);
    // 0x8018C124: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x8018C128: bnel        $at, $zero, L_8018C148
    if (ctx->r1 != 0) {
        // 0x8018C12C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8018C148;
    }
    goto skip_2;
    // 0x8018C12C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8018C130: b           L_8018C144
    // 0x8018C134: sh          $zero, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = 0;
        goto L_8018C144;
    // 0x8018C134: sh          $zero, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = 0;
L_8018C138:
    // 0x8018C138: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8018C13C: bne         $v1, $v0, L_8018BF20
    if (ctx->r3 != ctx->r2) {
        // 0x8018C140: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_8018BF20;
    }
    // 0x8018C140: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
L_8018C144:
    // 0x8018C144: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8018C148:
    // 0x8018C148: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018C14C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8018C150: jr          $ra
    // 0x8018C154: nop

    return;
    // 0x8018C154: nop

;}
RECOMP_FUNC void OvlI4_CallFunction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187520: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80187524: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80187528: addiu       $t6, $a0, -0x5A
    ctx->r14 = ADD32(ctx->r4, -0X5A);
    // 0x8018752C: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x80187530: beq         $at, $zero, L_801875D4
    if (ctx->r1 == 0) {
        // 0x80187534: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_801875D4;
    }
    // 0x80187534: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80187538: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018753C: addu        $at, $at, $t6
    gpr jr_addend_80187544 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80187540: lw          $t6, -0x910($at)
    ctx->r14 = ADD32(ctx->r1, -0X910);
    // 0x80187544: jr          $t6
    // 0x80187548: nop

    switch (jr_addend_80187544 >> 2) {
        case 0: goto L_8018754C; break;
        case 1: goto L_8018755C; break;
        case 2: goto L_8018756C; break;
        case 3: goto L_8018757C; break;
        case 4: goto L_8018758C; break;
        case 5: goto L_8018759C; break;
        case 6: goto L_801875AC; break;
        case 7: goto L_801875BC; break;
        case 8: goto L_801875CC; break;
        default: switch_error(__func__, 0x80187544, 0x8019F6F0);
    }
    // 0x80187548: nop

L_8018754C:
    // 0x8018754C: jal         0x8018927C
    // 0x80187550: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    Fortuna_LevelComplete(rdram, ctx);
        goto after_0;
    // 0x80187550: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80187554: b           L_801875D8
    // 0x80187558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801875D8;
    // 0x80187558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018755C:
    // 0x8018755C: jal         0x8018E710
    // 0x80187560: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    Bolse_BoBase_Update(rdram, ctx);
        goto after_1;
    // 0x80187560: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80187564: b           L_801875D8
    // 0x80187568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801875D8;
    // 0x80187568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018756C:
    // 0x8018756C: jal         0x8018E870
    // 0x80187570: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    Bolse_BoBase_Draw(rdram, ctx);
        goto after_2;
    // 0x80187570: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x80187574: b           L_801875D8
    // 0x80187578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801875D8;
    // 0x80187578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018757C:
    // 0x8018757C: jal         0x80191BAC
    // 0x80187580: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    Bolse_BoBaseShield_Update(rdram, ctx);
        goto after_3;
    // 0x80187580: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x80187584: b           L_801875D8
    // 0x80187588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801875D8;
    // 0x80187588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018758C:
    // 0x8018758C: jal         0x80191DB0
    // 0x80187590: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    Bolse_BoBaseShield_Draw(rdram, ctx);
        goto after_4;
    // 0x80187590: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x80187594: b           L_801875D8
    // 0x80187598: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801875D8;
    // 0x80187598: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018759C:
    // 0x8018759C: jal         0x8018D7F0
    // 0x801875A0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    Bolse_BoShieldReactor_Update(rdram, ctx);
        goto after_5;
    // 0x801875A0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_5:
    // 0x801875A4: b           L_801875D8
    // 0x801875A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801875D8;
    // 0x801875A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801875AC:
    // 0x801875AC: jal         0x8018D960
    // 0x801875B0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    Bolse_BoShieldReactor_Draw(rdram, ctx);
        goto after_6;
    // 0x801875B0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_6:
    // 0x801875B4: b           L_801875D8
    // 0x801875B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801875D8;
    // 0x801875B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801875BC:
    // 0x801875BC: jal         0x8018D394
    // 0x801875C0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    Bolse_BoLaserCannon_Update(rdram, ctx);
        goto after_7;
    // 0x801875C0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_7:
    // 0x801875C4: b           L_801875D8
    // 0x801875C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801875D8;
    // 0x801875C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801875CC:
    // 0x801875CC: jal         0x8018D454
    // 0x801875D0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    Bolse_BoLaserCannon_Draw(rdram, ctx);
        goto after_8;
    // 0x801875D0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_8:
L_801875D4:
    // 0x801875D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801875D8:
    // 0x801875D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801875DC: jr          $ra
    // 0x801875E0: nop

    return;
    // 0x801875E0: nop

;}
RECOMP_FUNC void Bolse_BoBaseCore_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191A6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80191A70: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80191A74: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80191A78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80191A7C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80191A80: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80191A84: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80191A88: addiu       $t6, $t6, -0xF34
    ctx->r14 = ADD32(ctx->r14, -0XF34);
    // 0x80191A8C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80191A90: addiu       $t0, $a3, -0x1
    ctx->r8 = ADD32(ctx->r7, -0X1);
    // 0x80191A94: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x80191A98: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80191A9C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80191AA0: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80191AA4: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x80191AA8: sltiu       $at, $t0, 0x8
    ctx->r1 = ctx->r8 < 0X8 ? 1 : 0;
    // 0x80191AAC: beq         $at, $zero, L_80191AEC
    if (ctx->r1 == 0) {
        // 0x80191AB0: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80191AEC;
    }
    // 0x80191AB0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80191AB4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191AB8: addu        $at, $at, $t0
    gpr jr_addend_80191AC0 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80191ABC: lw          $t0, -0x32C($at)
    ctx->r8 = ADD32(ctx->r1, -0X32C);
    // 0x80191AC0: jr          $t0
    // 0x80191AC4: nop

    switch (jr_addend_80191AC0 >> 2) {
        case 0: goto L_80191AC8; break;
        case 1: goto L_80191AC8; break;
        case 2: goto L_80191AC8; break;
        case 3: goto L_80191AC8; break;
        case 4: goto L_80191AC8; break;
        case 5: goto L_80191AC8; break;
        case 6: goto L_80191AC8; break;
        case 7: goto L_80191AC8; break;
        default: switch_error(__func__, 0x80191AC0, 0x8019FCD4);
    }
    // 0x80191AC4: nop

L_80191AC8:
    // 0x80191AC8: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80191ACC: sll         $t2, $a3, 2
    ctx->r10 = S32(ctx->r7 << 2);
    // 0x80191AD0: subu        $t2, $t2, $a3
    ctx->r10 = SUB32(ctx->r10, ctx->r7);
    // 0x80191AD4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80191AD8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191ADC: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    // 0x80191AE0: addiu       $a2, $a2, 0x194
    ctx->r6 = ADD32(ctx->r6, 0X194);
    // 0x80191AE4: jal         0x80006970
    // 0x80191AE8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x80191AE8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_0:
L_80191AEC:
    // 0x80191AEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80191AF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80191AF4: jr          $ra
    // 0x80191AF8: nop

    return;
    // 0x80191AF8: nop

;}
RECOMP_FUNC void Bolse_Effect397_Setup2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190F58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80190F5C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80190F60: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80190F64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80190F68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80190F6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80190F70: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80190F74: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80190F78: jal         0x80061474
    // 0x80190F7C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x80190F7C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80190F80: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80190F84: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80190F88: addiu       $t7, $zero, 0x18D
    ctx->r15 = ADD32(0, 0X18D);
    // 0x80190F8C: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x80190F90: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x80190F94: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80190F98: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80190F9C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80190FA0: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x80190FA4: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80190FA8: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x80190FAC: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x80190FB0: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x80190FB4: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80190FB8: sh          $t8, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = ctx->r24;
    // 0x80190FBC: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x80190FC0: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80190FC4: sh          $t9, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r25;
    // 0x80190FC8: jal         0x800612B8
    // 0x80190FCC: swc1        $f10, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f10.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80190FCC: swc1        $f10, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f10.u32l;
    after_1:
    // 0x80190FD0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80190FD4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80190FD8: sh          $t0, 0x30($a2)
    MEM_H(0X30, ctx->r6) = ctx->r8;
    // 0x80190FDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80190FE0: jr          $ra
    // 0x80190FE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80190FE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Katina_KaFrontlineBase_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193B1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80193B20: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80193B24: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80193B28: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80193B2C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80193B30: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80193B34: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80193B38: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80193B3C: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x80193B40: ori         $t7, $t7, 0x8
    ctx->r15 = ctx->r15 | 0X8;
    // 0x80193B44: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80193B48: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80193B4C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80193B50: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80193B54: lw          $t0, -0x7C28($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7C28);
    // 0x80193B58: addiu       $t8, $zero, 0x3EA
    ctx->r24 = ADD32(0, 0X3EA);
    // 0x80193B5C: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x80193B60: subu        $t1, $t8, $t0
    ctx->r9 = SUB32(ctx->r24, ctx->r8);
    // 0x80193B64: ori         $t9, $t9, 0xF400
    ctx->r25 = ctx->r25 | 0XF400;
    // 0x80193B68: div         $zero, $t9, $t1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r9)));
    // 0x80193B6C: negu        $t5, $t0
    ctx->r13 = SUB32(0, ctx->r8);
    // 0x80193B70: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x80193B74: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x80193B78: mflo        $t2
    ctx->r10 = lo;
    // 0x80193B7C: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x80193B80: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80193B84: div         $zero, $t7, $t1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r9)));
    // 0x80193B88: mflo        $t8
    ctx->r24 = lo;
    // 0x80193B8C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80193B90: bne         $t1, $zero, L_80193B9C
    if (ctx->r9 != 0) {
        // 0x80193B94: nop
    
            goto L_80193B9C;
    }
    // 0x80193B94: nop

    // 0x80193B98: break       7
    do_break(2149137304);
L_80193B9C:
    // 0x80193B9C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80193BA0: bne         $t1, $at, L_80193BB4
    if (ctx->r9 != ctx->r1) {
        // 0x80193BA4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80193BB4;
    }
    // 0x80193BA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80193BA8: bne         $t9, $at, L_80193BB4
    if (ctx->r25 != ctx->r1) {
        // 0x80193BAC: nop
    
            goto L_80193BB4;
    }
    // 0x80193BAC: nop

    // 0x80193BB0: break       6
    do_break(2149137328);
L_80193BB4:
    // 0x80193BB4: addu        $at, $t9, $zero
    ctx->r1 = ADD32(ctx->r25, 0);
    // 0x80193BB8: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80193BBC: or          $t2, $t4, $t9
    ctx->r10 = ctx->r12 | ctx->r25;
    // 0x80193BC0: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80193BC4: bne         $t1, $zero, L_80193BD0
    if (ctx->r9 != 0) {
        // 0x80193BC8: nop
    
            goto L_80193BD0;
    }
    // 0x80193BC8: nop

    // 0x80193BCC: break       7
    do_break(2149137356);
L_80193BD0:
    // 0x80193BD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80193BD4: bne         $t1, $at, L_80193BE8
    if (ctx->r9 != ctx->r1) {
        // 0x80193BD8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80193BE8;
    }
    // 0x80193BD8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80193BDC: bne         $t7, $at, L_80193BE8
    if (ctx->r15 != ctx->r1) {
        // 0x80193BE0: nop
    
            goto L_80193BE8;
    }
    // 0x80193BE0: nop

    // 0x80193BE4: break       6
    do_break(2149137380);
L_80193BE8:
    // 0x80193BE8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80193BEC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80193BF0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80193BF4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80193BF8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80193BFC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80193C00: jal         0x80005B00
    // 0x80193C04: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x80193C04: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_0:
    // 0x80193C08: jal         0x80006EB8
    // 0x80193C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_1;
    // 0x80193C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80193C10: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80193C14: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80193C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80193C1C: lh          $t6, 0x4E($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4E);
    // 0x80193C20: bne         $t6, $zero, L_80193C4C
    if (ctx->r14 != 0) {
        // 0x80193C24: nop
    
            goto L_80193C4C;
    }
    // 0x80193C24: nop

    // 0x80193C28: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80193C2C: lui         $t4, 0x601
    ctx->r12 = S32(0X601 << 16);
    // 0x80193C30: addiu       $t4, $t4, -0x4510
    ctx->r12 = ADD32(ctx->r12, -0X4510);
    // 0x80193C34: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80193C38: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80193C3C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80193C40: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80193C44: b           L_80193C94
    // 0x80193C48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80193C94;
    // 0x80193C48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80193C4C:
    // 0x80193C4C: jal         0x800B8DD0
    // 0x80193C50: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x80193C50: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    after_2:
    // 0x80193C54: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80193C58: lui         $t2, 0xB600
    ctx->r10 = S32(0XB600 << 16);
    // 0x80193C5C: addiu       $t3, $zero, 0x2000
    ctx->r11 = ADD32(0, 0X2000);
    // 0x80193C60: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80193C64: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80193C68: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80193C6C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80193C70: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80193C74: lui         $t7, 0x601
    ctx->r15 = S32(0X601 << 16);
    // 0x80193C78: addiu       $t7, $t7, -0x3B20
    ctx->r15 = ADD32(ctx->r15, -0X3B20);
    // 0x80193C7C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80193C80: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80193C84: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80193C88: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80193C8C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80193C90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80193C94:
    // 0x80193C94: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80193C98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80193C9C: jr          $ra
    // 0x80193CA0: nop

    return;
    // 0x80193CA0: nop

;}
RECOMP_FUNC void Bolse_8018F83C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F83C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018F840: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018F844: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018F848: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018F84C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8018F850: jal         0x800613C4
    // 0x8018F854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018F854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8018F858: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018F85C: addiu       $t7, $zero, 0xC3
    ctx->r15 = ADD32(0, 0XC3);
    // 0x8018F860: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8018F864: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8018F868: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8018F86C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018F870: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x8018F874: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8018F878: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F87C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8018F880: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8018F884: lwc1        $f6, -0xF94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XF94);
    // 0x8018F888: lwc1        $f4, 0x74($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X74);
    // 0x8018F88C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F890: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8018F894: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018F898: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8018F89C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8018F8A0: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x8018F8A4: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8018F8A8: lwc1        $f16, -0xF88($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XF88);
    // 0x8018F8AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F8B0: lwc1        $f10, 0x78($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X78);
    // 0x8018F8B4: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8018F8B8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018F8BC: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x8018F8C0: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8018F8C4: lwc1        $f6, -0xF7C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XF7C);
    // 0x8018F8C8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018F8CC: lwc1        $f4, 0x7C($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X7C);
    // 0x8018F8D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018F8D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F8D8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018F8DC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8018F8E0: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x8018F8E4: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8018F8E8: lwc1        $f16, -0xF70($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XF70);
    // 0x8018F8EC: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    // 0x8018F8F0: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8018F8F4: lwc1        $f18, 0xD0($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XD0);
    // 0x8018F8F8: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8018F8FC: jal         0x800612B8
    // 0x8018F900: swc1        $f4, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f4.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8018F900: swc1        $f4, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x8018F904: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018F908: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018F90C: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x8018F910: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018F914: sw          $t3, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r11;
    // 0x8018F918: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x8018F91C: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8018F920: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x8018F924: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8018F928: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018F92C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8018F930: jal         0x80019218
    // 0x8018F934: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8018F934: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x8018F938: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018F93C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018F940: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018F944: jr          $ra
    // 0x8018F948: nop

    return;
    // 0x8018F948: nop

;}
RECOMP_FUNC void SectorZ_UpdateEvents(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019AB8C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8019AB90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019AB94: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8019AB98: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8019AB9C: addiu       $t7, $t7, -0xAEC
    ctx->r15 = ADD32(ctx->r15, -0XAEC);
    // 0x8019ABA0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8019ABA4: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x8019ABA8: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x8019ABAC: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8019ABB0: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8019ABB4: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8019ABB8: lw          $t1, 0xC($t7)
    ctx->r9 = MEM_W(ctx->r15, 0XC);
    // 0x8019ABBC: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8019ABC0: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x8019ABC4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8019ABC8: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x8019ABCC: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x8019ABD0: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x8019ABD4: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8019ABD8: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x8019ABDC: lh          $v0, 0xB8($t3)
    ctx->r2 = MEM_H(ctx->r11, 0XB8);
    // 0x8019ABE0: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x8019ABE4: bne         $at, $zero, L_8019AC00
    if (ctx->r1 != 0) {
        // 0x8019ABE8: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_8019AC00;
    }
    // 0x8019ABE8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8019ABEC: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x8019ABF0: beq         $v0, $at, L_8019B390
    if (ctx->r2 == ctx->r1) {
        // 0x8019ABF4: nop
    
            goto L_8019B390;
    }
    // 0x8019ABF4: nop

    // 0x8019ABF8: b           L_8019B390
    // 0x8019ABFC: nop

        goto L_8019B390;
    // 0x8019ABFC: nop

L_8019AC00:
    // 0x8019AC00: sltiu       $at, $v0, 0x15
    ctx->r1 = ctx->r2 < 0X15 ? 1 : 0;
    // 0x8019AC04: beq         $at, $zero, L_8019B390
    if (ctx->r1 == 0) {
        // 0x8019AC08: sll         $t4, $v0, 2
        ctx->r12 = S32(ctx->r2 << 2);
            goto L_8019B390;
    }
    // 0x8019AC08: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8019AC0C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019AC10: addu        $at, $at, $t4
    gpr jr_addend_8019AC18 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8019AC14: lw          $t4, 0x140($at)
    ctx->r12 = ADD32(ctx->r1, 0X140);
    // 0x8019AC18: jr          $t4
    // 0x8019AC1C: nop

    switch (jr_addend_8019AC18 >> 2) {
        case 0: goto L_8019AC20; break;
        case 1: goto L_8019B390; break;
        case 2: goto L_8019ACB8; break;
        case 3: goto L_8019AD58; break;
        case 4: goto L_8019B390; break;
        case 5: goto L_8019B390; break;
        case 6: goto L_8019AF9C; break;
        case 7: goto L_8019B390; break;
        case 8: goto L_8019B390; break;
        case 9: goto L_8019B390; break;
        case 10: goto L_8019B038; break;
        case 11: goto L_8019B390; break;
        case 12: goto L_8019B390; break;
        case 13: goto L_8019B390; break;
        case 14: goto L_8019B390; break;
        case 15: goto L_8019B390; break;
        case 16: goto L_8019B390; break;
        case 17: goto L_8019B390; break;
        case 18: goto L_8019B390; break;
        case 19: goto L_8019B390; break;
        case 20: goto L_8019AD40; break;
        default: switch_error(__func__, 0x8019AC18, 0x801A0140);
    }
    // 0x8019AC1C: nop

L_8019AC20:
    // 0x8019AC20: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x8019AC24: addiu       $v0, $v0, 0x560
    ctx->r2 = ADD32(ctx->r2, 0X560);
    // 0x8019AC28: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8019AC2C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019AC30: sw          $zero, 0x564($at)
    MEM_W(0X564, ctx->r1) = 0;
    // 0x8019AC34: lui         $at, 0x427C
    ctx->r1 = S32(0X427C << 16);
    // 0x8019AC38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019AC3C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019AC40: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8019AC44: swc1        $f4, -0x6EC($at)
    MEM_W(-0X6EC, ctx->r1) = ctx->f4.u32l;
    // 0x8019AC48: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8019AC4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019AC50: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019AC54: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019AC58: swc1        $f6, -0x6E8($at)
    MEM_W(-0X6E8, ctx->r1) = ctx->f6.u32l;
    // 0x8019AC5C: lui         $at, 0x431E
    ctx->r1 = S32(0X431E << 16);
    // 0x8019AC60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019AC64: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019AC68: addiu       $a0, $a0, -0x6D8
    ctx->r4 = ADD32(ctx->r4, -0X6D8);
    // 0x8019AC6C: swc1        $f8, -0x6E4($at)
    MEM_W(-0X6E4, ctx->r1) = ctx->f8.u32l;
    // 0x8019AC70: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019AC74: lwc1        $f10, 0x194($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X194);
    // 0x8019AC78: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019AC7C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8019AC80: swc1        $f10, 0x1A44($at)
    MEM_W(0X1A44, ctx->r1) = ctx->f10.u32l;
    // 0x8019AC84: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8019AC88: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8019AC8C: sh          $v1, 0xB8($t9)
    MEM_H(0XB8, ctx->r25) = ctx->r3;
    // 0x8019AC90: lw          $t8, -0x6DC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6DC);
    // 0x8019AC94: lui         $t7, 0xF
    ctx->r15 = S32(0XF << 16);
    // 0x8019AC98: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8019AC9C: beq         $t8, $zero, L_8019ACB0
    if (ctx->r24 == 0) {
        // 0x8019ACA0: ori         $t7, $t7, 0x4240
        ctx->r15 = ctx->r15 | 0X4240;
            goto L_8019ACB0;
    }
    // 0x8019ACA0: ori         $t7, $t7, 0x4240
    ctx->r15 = ctx->r15 | 0X4240;
    // 0x8019ACA4: lw          $t6, 0x1A9C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1A9C);
    // 0x8019ACA8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019ACAC: sw          $t6, 0x1A98($at)
    MEM_W(0X1A98, ctx->r1) = ctx->r14;
L_8019ACB0:
    // 0x8019ACB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8019ACB4: sw          $t7, -0x64B4($at)
    MEM_W(-0X64B4, ctx->r1) = ctx->r15;
L_8019ACB8:
    // 0x8019ACB8: jal         0x8019AA9C
    // 0x8019ACBC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    SectorZ_GFoxArwingRepair(rdram, ctx);
        goto after_0;
    // 0x8019ACBC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x8019ACC0: bne         $v0, $zero, L_8019B390
    if (ctx->r2 != 0) {
        // 0x8019ACC4: nop
    
            goto L_8019B390;
    }
    // 0x8019ACC4: nop

    // 0x8019ACC8: jal         0x8019A3E8
    // 0x8019ACCC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    SectorZ_EnemyUpdate(rdram, ctx);
        goto after_1;
    // 0x8019ACCC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_1:
    // 0x8019ACD0: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8019ACD4: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
    // 0x8019ACD8: lhu         $v0, 0xBE($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0XBE);
    // 0x8019ACDC: beq         $v0, $at, L_8019B390
    if (ctx->r2 == ctx->r1) {
        // 0x8019ACE0: addiu       $at, $zero, 0xEB
        ctx->r1 = ADD32(0, 0XEB);
            goto L_8019B390;
    }
    // 0x8019ACE0: addiu       $at, $zero, 0xEB
    ctx->r1 = ADD32(0, 0XEB);
    // 0x8019ACE4: beq         $v0, $at, L_8019AD2C
    if (ctx->r2 == ctx->r1) {
        // 0x8019ACE8: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8019AD2C;
    }
    // 0x8019ACE8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019ACEC: addiu       $at, $zero, 0x181
    ctx->r1 = ADD32(0, 0X181);
    // 0x8019ACF0: beq         $v0, $at, L_8019AD18
    if (ctx->r2 == ctx->r1) {
        // 0x8019ACF4: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8019AD18;
    }
    // 0x8019ACF4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019ACF8: addiu       $at, $zero, 0x224
    ctx->r1 = ADD32(0, 0X224);
    // 0x8019ACFC: bne         $v0, $at, L_8019B390
    if (ctx->r2 != ctx->r1) {
        // 0x8019AD00: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8019B390;
    }
    // 0x8019AD00: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019AD04: addiu       $a0, $a0, 0x1220
    ctx->r4 = ADD32(ctx->r4, 0X1220);
    // 0x8019AD08: jal         0x800BA808
    // 0x8019AD0C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_2;
    // 0x8019AD0C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_2:
    // 0x8019AD10: b           L_8019B390
    // 0x8019AD14: nop

        goto L_8019B390;
    // 0x8019AD14: nop

L_8019AD18:
    // 0x8019AD18: addiu       $a0, $a0, 0x126C
    ctx->r4 = ADD32(ctx->r4, 0X126C);
    // 0x8019AD1C: jal         0x800BA808
    // 0x8019AD20: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_3;
    // 0x8019AD20: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_3:
    // 0x8019AD24: b           L_8019B390
    // 0x8019AD28: nop

        goto L_8019B390;
    // 0x8019AD28: nop

L_8019AD2C:
    // 0x8019AD2C: addiu       $a0, $a0, 0x12BC
    ctx->r4 = ADD32(ctx->r4, 0X12BC);
    // 0x8019AD30: jal         0x800BA808
    // 0x8019AD34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_4;
    // 0x8019AD34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8019AD38: b           L_8019B390
    // 0x8019AD3C: nop

        goto L_8019B390;
    // 0x8019AD3C: nop

L_8019AD40:
    // 0x8019AD40: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019AD44: addiu       $a0, $a0, -0x6D8
    ctx->r4 = ADD32(ctx->r4, -0X6D8);
    // 0x8019AD48: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8019AD4C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8019AD50: b           L_8019B390
    // 0x8019AD54: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
        goto L_8019B390;
    // 0x8019AD54: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
L_8019AD58:
    // 0x8019AD58: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019AD5C: addiu       $v0, $v0, 0x7A80
    ctx->r2 = ADD32(ctx->r2, 0X7A80);
    // 0x8019AD60: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8019AD64: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8019AD68: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8019AD6C: bne         $t0, $t5, L_8019AD94
    if (ctx->r8 != ctx->r13) {
        // 0x8019AD70: sw          $t5, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r13;
            goto L_8019AD94;
    }
    // 0x8019AD70: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8019AD74: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019AD78: lwc1        $f12, 0x5784($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X5784);
    // 0x8019AD7C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019AD80: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8019AD84: lw          $a2, 0x578C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X578C);
    // 0x8019AD88: lwc1        $f14, 0x5788($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X5788);
    // 0x8019AD8C: jal         0x80078E50
    // 0x8019AD90: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    Effect_Sparkle_Spawn(rdram, ctx);
        goto after_5;
    // 0x8019AD90: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    after_5:
L_8019AD94:
    // 0x8019AD94: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019AD98: lwc1        $f0, 0x198($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X198);
    // 0x8019AD9C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019ADA0: lwc1        $f18, 0x5868($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5868);
    // 0x8019ADA4: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8019ADA8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019ADAC: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8019ADB0: lwc1        $f16, 0x40($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X40);
    // 0x8019ADB4: lwc1        $f8, 0x44($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X44);
    // 0x8019ADB8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8019ADBC: lui         $a3, 0x469C
    ctx->r7 = S32(0X469C << 16);
    // 0x8019ADC0: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x8019ADC4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8019ADC8: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8019ADCC: lwc1        $f4, 0x48($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X48);
    // 0x8019ADD0: addiu       $a0, $t8, 0x4C
    ctx->r4 = ADD32(ctx->r24, 0X4C);
    // 0x8019ADD4: swc1        $f6, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f6.u32l;
    // 0x8019ADD8: lwc1        $f10, 0x586C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X586C);
    // 0x8019ADDC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019ADE0: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8019ADE4: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8019ADE8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019ADEC: swc1        $f16, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->f16.u32l;
    // 0x8019ADF0: lwc1        $f6, 0x5870($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5870);
    // 0x8019ADF4: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8019ADF8: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8019ADFC: swc1        $f8, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f8.u32l;
    // 0x8019AE00: lw          $a1, 0x5784($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5784);
    // 0x8019AE04: jal         0x8009BC2C
    // 0x8019AE08: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x8019AE08: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x8019AE0C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8019AE10: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8019AE14: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8019AE18: lui         $a3, 0x469C
    ctx->r7 = S32(0X469C << 16);
    // 0x8019AE1C: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x8019AE20: lw          $a1, 0x5788($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5788);
    // 0x8019AE24: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8019AE28: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    // 0x8019AE2C: jal         0x8009BC2C
    // 0x8019AE30: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x8019AE30: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x8019AE34: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8019AE38: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019AE3C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8019AE40: lui         $a3, 0x469C
    ctx->r7 = S32(0X469C << 16);
    // 0x8019AE44: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x8019AE48: lw          $a1, 0x578C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X578C);
    // 0x8019AE4C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8019AE50: addiu       $a0, $a0, 0x54
    ctx->r4 = ADD32(ctx->r4, 0X54);
    // 0x8019AE54: jal         0x8009BC2C
    // 0x8019AE58: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x8019AE58: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x8019AE5C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8019AE60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019AE64: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019AE68: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8019AE6C: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8019AE70: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    // 0x8019AE74: jal         0x8009BC2C
    // 0x8019AE78: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x8019AE78: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_9:
    // 0x8019AE7C: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8019AE80: addiu       $at, $zero, 0x8C
    ctx->r1 = ADD32(0, 0X8C);
    // 0x8019AE84: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8019AE88: lhu         $v1, 0xBC($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0XBC);
    // 0x8019AE8C: beq         $v1, $at, L_8019AEF0
    if (ctx->r3 == ctx->r1) {
        // 0x8019AE90: addiu       $at, $zero, 0xE6
        ctx->r1 = ADD32(0, 0XE6);
            goto L_8019AEF0;
    }
    // 0x8019AE90: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    // 0x8019AE94: beq         $v1, $at, L_8019AF40
    if (ctx->r3 == ctx->r1) {
        // 0x8019AE98: addiu       $at, $zero, 0x104
        ctx->r1 = ADD32(0, 0X104);
            goto L_8019AF40;
    }
    // 0x8019AE98: addiu       $at, $zero, 0x104
    ctx->r1 = ADD32(0, 0X104);
    // 0x8019AE9C: beq         $v1, $at, L_8019AF18
    if (ctx->r3 == ctx->r1) {
        // 0x8019AEA0: addiu       $at, $zero, 0x105
        ctx->r1 = ADD32(0, 0X105);
            goto L_8019AF18;
    }
    // 0x8019AEA0: addiu       $at, $zero, 0x105
    ctx->r1 = ADD32(0, 0X105);
    // 0x8019AEA4: beq         $v1, $at, L_8019AED4
    if (ctx->r3 == ctx->r1) {
        // 0x8019AEA8: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8019AED4;
    }
    // 0x8019AEA8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019AEAC: addiu       $at, $zero, 0x172
    ctx->r1 = ADD32(0, 0X172);
    // 0x8019AEB0: bne         $v1, $at, L_8019AF64
    if (ctx->r3 != ctx->r1) {
        // 0x8019AEB4: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8019AF64;
    }
    // 0x8019AEB4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019AEB8: addiu       $a0, $a0, 0x1438
    ctx->r4 = ADD32(ctx->r4, 0X1438);
    // 0x8019AEBC: jal         0x800BA808
    // 0x8019AEC0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    Radio_PlayMessage(rdram, ctx);
        goto after_10;
    // 0x8019AEC0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_10:
    // 0x8019AEC4: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8019AEC8: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8019AECC: b           L_8019AF64
    // 0x8019AED0: lhu         $v1, 0xBC($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0XBC);
        goto L_8019AF64;
    // 0x8019AED0: lhu         $v1, 0xBC($t7)
    ctx->r3 = MEM_HU(ctx->r15, 0XBC);
L_8019AED4:
    // 0x8019AED4: addiu       $a0, $a0, 0x147C
    ctx->r4 = ADD32(ctx->r4, 0X147C);
    // 0x8019AED8: jal         0x800BA808
    // 0x8019AEDC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_11;
    // 0x8019AEDC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_11:
    // 0x8019AEE0: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8019AEE4: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8019AEE8: b           L_8019AF64
    // 0x8019AEEC: lhu         $v1, 0xBC($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0XBC);
        goto L_8019AF64;
    // 0x8019AEEC: lhu         $v1, 0xBC($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0XBC);
L_8019AEF0:
    // 0x8019AEF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019AEF4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019AEF8: sw          $zero, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = 0;
    // 0x8019AEFC: addiu       $a0, $a0, 0x14D4
    ctx->r4 = ADD32(ctx->r4, 0X14D4);
    // 0x8019AF00: jal         0x800BA808
    // 0x8019AF04: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    Radio_PlayMessage(rdram, ctx);
        goto after_12;
    // 0x8019AF04: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_12:
    // 0x8019AF08: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8019AF0C: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8019AF10: b           L_8019AF64
    // 0x8019AF14: lhu         $v1, 0xBC($t2)
    ctx->r3 = MEM_HU(ctx->r10, 0XBC);
        goto L_8019AF64;
    // 0x8019AF14: lhu         $v1, 0xBC($t2)
    ctx->r3 = MEM_HU(ctx->r10, 0XBC);
L_8019AF18:
    // 0x8019AF18: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8019AF1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019AF20: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019AF24: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019AF28: swc1        $f10, 0x58B0($at)
    MEM_W(0X58B0, ctx->r1) = ctx->f10.u32l;
    // 0x8019AF2C: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8019AF30: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019AF34: swc1        $f8, 0x58B4($at)
    MEM_W(0X58B4, ctx->r1) = ctx->f8.u32l;
    // 0x8019AF38: b           L_8019AF64
    // 0x8019AF3C: lhu         $v1, 0xBC($t3)
    ctx->r3 = MEM_HU(ctx->r11, 0XBC);
        goto L_8019AF64;
    // 0x8019AF3C: lhu         $v1, 0xBC($t3)
    ctx->r3 = MEM_HU(ctx->r11, 0XBC);
L_8019AF40:
    // 0x8019AF40: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019AF44: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019AF48: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8019AF4C: swc1        $f18, 0x58B0($at)
    MEM_W(0X58B0, ctx->r1) = ctx->f18.u32l;
    // 0x8019AF50: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019AF54: lwc1        $f16, 0x19C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X19C);
    // 0x8019AF58: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019AF5C: swc1        $f16, 0x58B4($at)
    MEM_W(0X58B4, ctx->r1) = ctx->f16.u32l;
    // 0x8019AF60: lhu         $v1, 0xBC($t4)
    ctx->r3 = MEM_HU(ctx->r12, 0XBC);
L_8019AF64:
    // 0x8019AF64: addiu       $at, $zero, 0x46
    ctx->r1 = ADD32(0, 0X46);
    // 0x8019AF68: bne         $v1, $at, L_8019B390
    if (ctx->r3 != ctx->r1) {
        // 0x8019AF6C: nop
    
            goto L_8019B390;
    }
    // 0x8019AF6C: nop

    // 0x8019AF70: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8019AF74: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8019AF78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8019AF7C: sh          $v1, 0xB8($t5)
    MEM_H(0XB8, ctx->r13) = ctx->r3;
    // 0x8019AF80: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8019AF84: jal         0x800B7184
    // 0x8019AF88: sw          $t0, 0x1C8($a0)
    MEM_W(0X1C8, ctx->r4) = ctx->r8;
    Camera_Update360(rdram, ctx);
        goto after_13;
    // 0x8019AF88: sw          $t0, 0x1C8($a0)
    MEM_W(0X1C8, ctx->r4) = ctx->r8;
    after_13:
    // 0x8019AF8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019AF90: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8019AF94: b           L_8019B390
    // 0x8019AF98: swc1        $f6, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f6.u32l;
        goto L_8019B390;
    // 0x8019AF98: swc1        $f6, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f6.u32l;
L_8019AF9C:
    // 0x8019AF9C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019AFA0: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x8019AFA4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8019AFA8: sh          $zero, 0x3DA($v0)
    MEM_H(0X3DA, ctx->r2) = 0;
    // 0x8019AFAC: sh          $v1, 0x3AC($v0)
    MEM_H(0X3AC, ctx->r2) = ctx->r3;
    // 0x8019AFB0: sh          $zero, 0x6CE($v0)
    MEM_H(0X6CE, ctx->r2) = 0;
    // 0x8019AFB4: sh          $v1, 0x6A0($v0)
    MEM_H(0X6A0, ctx->r2) = ctx->r3;
    // 0x8019AFB8: sh          $zero, 0x9C2($v0)
    MEM_H(0X9C2, ctx->r2) = 0;
    // 0x8019AFBC: sh          $v1, 0x994($v0)
    MEM_H(0X994, ctx->r2) = ctx->r3;
    // 0x8019AFC0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8019AFC4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019AFC8: sh          $t6, 0x5E4E($at)
    MEM_H(0X5E4E, ctx->r1) = ctx->r14;
    // 0x8019AFCC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019AFD0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8019AFD4: sh          $t7, 0x5E20($at)
    MEM_H(0X5E20, ctx->r1) = ctx->r15;
    // 0x8019AFD8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019AFDC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8019AFE0: sh          $t1, 0x6142($at)
    MEM_H(0X6142, ctx->r1) = ctx->r9;
    // 0x8019AFE4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019AFE8: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019AFEC: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8019AFF0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019AFF4: addiu       $a0, $a0, -0xEF0
    ctx->r4 = ADD32(ctx->r4, -0XEF0);
    // 0x8019AFF8: sh          $t2, 0x6114($at)
    MEM_H(0X6114, ctx->r1) = ctx->r10;
    // 0x8019AFFC: addiu       $v0, $v0, 0x6350
    ctx->r2 = ADD32(ctx->r2, 0X6350);
    // 0x8019B000: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8019B004: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
L_8019B008:
    // 0x8019B008: addiu       $v0, $v0, 0xBD0
    ctx->r2 = ADD32(ctx->r2, 0XBD0);
    // 0x8019B00C: sh          $v1, -0x7F6($v0)
    MEM_H(-0X7F6, ctx->r2) = ctx->r3;
    // 0x8019B010: sh          $t0, -0x824($v0)
    MEM_H(-0X824, ctx->r2) = ctx->r8;
    // 0x8019B014: sh          $v1, -0x502($v0)
    MEM_H(-0X502, ctx->r2) = ctx->r3;
    // 0x8019B018: sh          $t0, -0x530($v0)
    MEM_H(-0X530, ctx->r2) = ctx->r8;
    // 0x8019B01C: sh          $v1, -0x20E($v0)
    MEM_H(-0X20E, ctx->r2) = ctx->r3;
    // 0x8019B020: sh          $t0, -0x23C($v0)
    MEM_H(-0X23C, ctx->r2) = ctx->r8;
    // 0x8019B024: sh          $v1, -0xAEA($v0)
    MEM_H(-0XAEA, ctx->r2) = ctx->r3;
    // 0x8019B028: bne         $v0, $a0, L_8019B008
    if (ctx->r2 != ctx->r4) {
        // 0x8019B02C: sh          $t0, -0xB18($v0)
        MEM_H(-0XB18, ctx->r2) = ctx->r8;
            goto L_8019B008;
    }
    // 0x8019B02C: sh          $t0, -0xB18($v0)
    MEM_H(-0XB18, ctx->r2) = ctx->r8;
    // 0x8019B030: b           L_8019B390
    // 0x8019B034: nop

        goto L_8019B390;
    // 0x8019B034: nop

L_8019B038:
    // 0x8019B038: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8019B03C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8019B040: addiu       $v1, $v1, -0x7CA8
    ctx->r3 = ADD32(ctx->r3, -0X7CA8);
    // 0x8019B044: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8019B048: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019B04C: sw          $zero, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = 0;
    // 0x8019B050: lhu         $v0, 0xBC($t4)
    ctx->r2 = MEM_HU(ctx->r12, 0XBC);
    // 0x8019B054: addiu       $at, $zero, 0x25EE
    ctx->r1 = ADD32(0, 0X25EE);
    // 0x8019B058: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8019B05C: beq         $v0, $at, L_8019B12C
    if (ctx->r2 == ctx->r1) {
        // 0x8019B060: addiu       $t0, $zero, 0x3
        ctx->r8 = ADD32(0, 0X3);
            goto L_8019B12C;
    }
    // 0x8019B060: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8019B064: addiu       $at, $zero, 0x2602
    ctx->r1 = ADD32(0, 0X2602);
    // 0x8019B068: beq         $v0, $at, L_8019B114
    if (ctx->r2 == ctx->r1) {
        // 0x8019B06C: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_8019B114;
    }
    // 0x8019B06C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8019B070: addiu       $at, $zero, 0x260C
    ctx->r1 = ADD32(0, 0X260C);
    // 0x8019B074: beq         $v0, $at, L_8019B0FC
    if (ctx->r2 == ctx->r1) {
        // 0x8019B078: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_8019B0FC;
    }
    // 0x8019B078: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8019B07C: addiu       $at, $zero, 0x2634
    ctx->r1 = ADD32(0, 0X2634);
    // 0x8019B080: beq         $v0, $at, L_8019B0E4
    if (ctx->r2 == ctx->r1) {
        // 0x8019B084: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_8019B0E4;
    }
    // 0x8019B084: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8019B088: addiu       $at, $zero, 0x2648
    ctx->r1 = ADD32(0, 0X2648);
    // 0x8019B08C: beq         $v0, $at, L_8019B0A0
    if (ctx->r2 == ctx->r1) {
        // 0x8019B090: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8019B0A0;
    }
    // 0x8019B090: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019B094: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019B098: b           L_8019B13C
    // 0x8019B09C: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
        goto L_8019B13C;
    // 0x8019B09C: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
L_8019B0A0:
    // 0x8019B0A0: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8019B0A4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019B0A8: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x8019B0AC: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8019B0B0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8019B0B4: addiu       $a1, $a1, 0x5E68
    ctx->r5 = ADD32(ctx->r5, 0X5E68);
    // 0x8019B0B8: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8019B0BC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8019B0C0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019B0C4: jal         0x80019218
    // 0x8019B0C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_14;
    // 0x8019B0C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x8019B0CC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8019B0D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019B0D4: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019B0D8: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x8019B0DC: b           L_8019B13C
    // 0x8019B0E0: swc1        $f4, 0x1F10($v0)
    MEM_W(0X1F10, ctx->r2) = ctx->f4.u32l;
        goto L_8019B13C;
    // 0x8019B0E0: swc1        $f4, 0x1F10($v0)
    MEM_W(0X1F10, ctx->r2) = ctx->f4.u32l;
L_8019B0E4:
    // 0x8019B0E4: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019B0E8: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x8019B0EC: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8019B0F0: sh          $v1, 0x274A($v0)
    MEM_H(0X274A, ctx->r2) = ctx->r3;
    // 0x8019B0F4: b           L_8019B13C
    // 0x8019B0F8: sh          $t0, 0x271C($v0)
    MEM_H(0X271C, ctx->r2) = ctx->r8;
        goto L_8019B13C;
    // 0x8019B0F8: sh          $t0, 0x271C($v0)
    MEM_H(0X271C, ctx->r2) = ctx->r8;
L_8019B0FC:
    // 0x8019B0FC: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019B100: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x8019B104: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8019B108: sh          $v1, 0x2A3E($v0)
    MEM_H(0X2A3E, ctx->r2) = ctx->r3;
    // 0x8019B10C: b           L_8019B13C
    // 0x8019B110: sh          $t0, 0x2A10($v0)
    MEM_H(0X2A10, ctx->r2) = ctx->r8;
        goto L_8019B13C;
    // 0x8019B110: sh          $t0, 0x2A10($v0)
    MEM_H(0X2A10, ctx->r2) = ctx->r8;
L_8019B114:
    // 0x8019B114: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019B118: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x8019B11C: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8019B120: sh          $v1, 0x2D32($v0)
    MEM_H(0X2D32, ctx->r2) = ctx->r3;
    // 0x8019B124: b           L_8019B13C
    // 0x8019B128: sh          $t0, 0x2D04($v0)
    MEM_H(0X2D04, ctx->r2) = ctx->r8;
        goto L_8019B13C;
    // 0x8019B128: sh          $t0, 0x2D04($v0)
    MEM_H(0X2D04, ctx->r2) = ctx->r8;
L_8019B12C:
    // 0x8019B12C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019B130: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x8019B134: sh          $v1, 0x3026($v0)
    MEM_H(0X3026, ctx->r2) = ctx->r3;
    // 0x8019B138: sh          $t0, 0x2FF8($v0)
    MEM_H(0X2FF8, ctx->r2) = ctx->r8;
L_8019B13C:
    // 0x8019B13C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8019B140: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019B144: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8019B148: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019B14C: lw          $a1, 0x1D8C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1D8C);
    // 0x8019B150: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x8019B154: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    // 0x8019B158: jal         0x8009BC2C
    // 0x8019B15C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x8019B15C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_15:
    // 0x8019B160: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8019B164: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019B168: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019B16C: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x8019B170: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8019B174: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019B178: lw          $a1, 0x1D90($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1D90);
    // 0x8019B17C: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x8019B180: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    // 0x8019B184: jal         0x8009BC2C
    // 0x8019B188: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x8019B188: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_16:
    // 0x8019B18C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8019B190: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019B194: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019B198: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x8019B19C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8019B1A0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019B1A4: lw          $a1, 0x1D94($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1D94);
    // 0x8019B1A8: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x8019B1AC: addiu       $a0, $a0, 0x54
    ctx->r4 = ADD32(ctx->r4, 0X54);
    // 0x8019B1B0: jal         0x8009BC2C
    // 0x8019B1B4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x8019B1B4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_17:
    // 0x8019B1B8: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x8019B1BC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8019B1C0: lui         $a1, 0x442F
    ctx->r5 = S32(0X442F << 16);
    // 0x8019B1C4: lhu         $t9, 0xBC($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0XBC);
    // 0x8019B1C8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8019B1CC: addiu       $a0, $v1, 0x13C
    ctx->r4 = ADD32(ctx->r3, 0X13C);
    // 0x8019B1D0: slti        $at, $t9, 0x2648
    ctx->r1 = SIGNED(ctx->r25) < 0X2648 ? 1 : 0;
    // 0x8019B1D4: beql        $at, $zero, L_8019B22C
    if (ctx->r1 == 0) {
        // 0x8019B1D8: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_8019B22C;
    }
    goto skip_0;
    // 0x8019B1D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x8019B1DC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8019B1E0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019B1E4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019B1E8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019B1EC: addiu       $a0, $a0, 0x5E80
    ctx->r4 = ADD32(ctx->r4, 0X5E80);
    // 0x8019B1F0: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x8019B1F4: jal         0x8009BC2C
    // 0x8019B1F8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_18;
    // 0x8019B1F8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_18:
    // 0x8019B1FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019B200: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019B204: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019B208: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019B20C: addiu       $a0, $a0, 0x5EF0
    ctx->r4 = ADD32(ctx->r4, 0X5EF0);
    // 0x8019B210: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x8019B214: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8019B218: jal         0x8009BC2C
    // 0x8019B21C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_19;
    // 0x8019B21C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_19:
    // 0x8019B220: b           L_8019B30C
    // 0x8019B224: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
        goto L_8019B30C;
    // 0x8019B224: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8019B228: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8019B22C:
    // 0x8019B22C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8019B230: jal         0x8009BC2C
    // 0x8019B234: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_20;
    // 0x8019B234: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_20:
    // 0x8019B238: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019B23C: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x8019B240: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8019B244: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019B248: lwc1        $f10, 0x1D8C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1D8C);
    // 0x8019B24C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8019B250: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8019B254: sub.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8019B258: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8019B25C: lui         $a2, 0x3D8F
    ctx->r6 = S32(0X3D8F << 16);
    // 0x8019B260: lw          $a3, 0x13C($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X13C);
    // 0x8019B264: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8019B268: ori         $a2, $a2, 0x5C29
    ctx->r6 = ctx->r6 | 0X5C29;
    // 0x8019B26C: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x8019B270: jal         0x8009BC2C
    // 0x8019B274: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_21;
    // 0x8019B274: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_21:
    // 0x8019B278: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8019B27C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8019B280: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019B284: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019B288: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x8019B28C: lui         $a2, 0x3D8F
    ctx->r6 = S32(0X3D8F << 16);
    // 0x8019B290: lw          $a3, 0x13C($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X13C);
    // 0x8019B294: ori         $a2, $a2, 0x5C29
    ctx->r6 = ctx->r6 | 0X5C29;
    // 0x8019B298: lw          $a1, 0x1D90($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1D90);
    // 0x8019B29C: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    // 0x8019B2A0: jal         0x8009BC2C
    // 0x8019B2A4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_22;
    // 0x8019B2A4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_22:
    // 0x8019B2A8: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019B2AC: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x8019B2B0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8019B2B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019B2B8: lwc1        $f4, 0x1D94($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1D94);
    // 0x8019B2BC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8019B2C0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019B2C4: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8019B2C8: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8019B2CC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019B2D0: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x8019B2D4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019B2D8: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x8019B2DC: jal         0x8009BC2C
    // 0x8019B2E0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_23;
    // 0x8019B2E0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_23:
    // 0x8019B2E4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8019B2E8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019B2EC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019B2F0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019B2F4: addiu       $a0, $a0, 0x5EF0
    ctx->r4 = ADD32(ctx->r4, 0X5EF0);
    // 0x8019B2F8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x8019B2FC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8019B300: jal         0x8009BC2C
    // 0x8019B304: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_24;
    // 0x8019B304: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_24:
    // 0x8019B308: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
L_8019B30C:
    // 0x8019B30C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8019B310: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8019B314: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8019B318: lhu         $t7, 0xBC($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0XBC);
    // 0x8019B31C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8019B320: slti        $at, $t7, 0x25D0
    ctx->r1 = SIGNED(ctx->r15) < 0X25D0 ? 1 : 0;
    // 0x8019B324: beq         $at, $zero, L_8019B390
    if (ctx->r1 == 0) {
        // 0x8019B328: nop
    
            goto L_8019B390;
    }
    // 0x8019B328: nop

    // 0x8019B32C: sh          $v1, 0xB8($a2)
    MEM_H(0XB8, ctx->r6) = ctx->r3;
    // 0x8019B330: jal         0x800B7184
    // 0x8019B334: sw          $t0, 0x1C8($a0)
    MEM_W(0X1C8, ctx->r4) = ctx->r8;
    Camera_Update360(rdram, ctx);
        goto after_25;
    // 0x8019B334: sw          $t0, 0x1C8($a0)
    MEM_W(0X1C8, ctx->r4) = ctx->r8;
    after_25:
    // 0x8019B338: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8019B33C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019B340: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8019B344: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019B348: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8019B34C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019B350: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019B354: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x8019B358: swc1        $f6, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f6.u32l;
    // 0x8019B35C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019B360: swc1        $f4, 0x1EA0($v0)
    MEM_W(0X1EA0, ctx->r2) = ctx->f4.u32l;
    // 0x8019B364: swc1        $f10, 0x1F10($v0)
    MEM_W(0X1F10, ctx->r2) = ctx->f10.u32l;
    // 0x8019B368: lwc1        $f8, 0x1A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1A0);
    // 0x8019B36C: sw          $zero, 0x1DFC($v0)
    MEM_W(0X1DFC, ctx->r2) = 0;
    // 0x8019B370: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8019B374: swc1        $f8, 0x1D94($v0)
    MEM_W(0X1D94, ctx->r2) = ctx->f8.u32l;
    // 0x8019B378: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x8019B37C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019B380: addiu       $t3, $zero, 0x226
    ctx->r11 = ADD32(0, 0X226);
    // 0x8019B384: swc1        $f18, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->f18.u32l;
    // 0x8019B388: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8019B38C: sh          $t3, 0xBE($t4)
    MEM_H(0XBE, ctx->r12) = ctx->r11;
L_8019B390:
    // 0x8019B390: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8019B394: lw          $t5, 0x7DB0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DB0);
    // 0x8019B398: andi        $t9, $t5, 0x18
    ctx->r25 = ctx->r13 & 0X18;
    // 0x8019B39C: bnel        $t9, $zero, L_8019B418
    if (ctx->r25 != 0) {
        // 0x8019B3A0: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8019B418;
    }
    goto skip_1;
    // 0x8019B3A0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_1:
    // 0x8019B3A4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8019B3A8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019B3AC: lui         $a3, 0x4117
    ctx->r7 = S32(0X4117 << 16);
    // 0x8019B3B0: ori         $a3, $a3, 0x3334
    ctx->r7 = ctx->r7 | 0X3334;
    // 0x8019B3B4: addiu       $a0, $a0, -0x6EC
    ctx->r4 = ADD32(ctx->r4, -0X6EC);
    // 0x8019B3B8: lui         $a1, 0x427C
    ctx->r5 = S32(0X427C << 16);
    // 0x8019B3BC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8019B3C0: jal         0x8009BC2C
    // 0x8019B3C4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_26;
    // 0x8019B3C4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_26:
    // 0x8019B3C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019B3CC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019B3D0: addiu       $a0, $a0, -0x6E8
    ctx->r4 = ADD32(ctx->r4, -0X6E8);
    // 0x8019B3D4: lui         $a1, 0x437F
    ctx->r5 = S32(0X437F << 16);
    // 0x8019B3D8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8019B3DC: lui         $a3, 0x420D
    ctx->r7 = S32(0X420D << 16);
    // 0x8019B3E0: jal         0x8009BC2C
    // 0x8019B3E4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_27;
    // 0x8019B3E4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_27:
    // 0x8019B3E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019B3EC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019B3F0: lui         $a3, 0x41AC
    ctx->r7 = S32(0X41AC << 16);
    // 0x8019B3F4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8019B3F8: addiu       $a0, $a0, -0x6E4
    ctx->r4 = ADD32(ctx->r4, -0X6E4);
    // 0x8019B3FC: lui         $a1, 0x431E
    ctx->r5 = S32(0X431E << 16);
    // 0x8019B400: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8019B404: jal         0x8009BC2C
    // 0x8019B408: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_28;
    // 0x8019B408: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_28:
    // 0x8019B40C: b           L_8019B480
    // 0x8019B410: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8019B480;
    // 0x8019B410: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019B414: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_8019B418:
    // 0x8019B418: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019B41C: lui         $a3, 0x4049
    ctx->r7 = S32(0X4049 << 16);
    // 0x8019B420: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8019B424: addiu       $a0, $a0, -0x6EC
    ctx->r4 = ADD32(ctx->r4, -0X6EC);
    // 0x8019B428: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019B42C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8019B430: jal         0x8009BC2C
    // 0x8019B434: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_29;
    // 0x8019B434: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_29:
    // 0x8019B438: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019B43C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019B440: addiu       $a0, $a0, -0x6E8
    ctx->r4 = ADD32(ctx->r4, -0X6E8);
    // 0x8019B444: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x8019B448: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8019B44C: lui         $a3, 0x413C
    ctx->r7 = S32(0X413C << 16);
    // 0x8019B450: jal         0x8009BC2C
    // 0x8019B454: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_30;
    // 0x8019B454: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_30:
    // 0x8019B458: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019B45C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019B460: lui         $a3, 0x40E6
    ctx->r7 = S32(0X40E6 << 16);
    // 0x8019B464: ori         $a3, $a3, 0x6667
    ctx->r7 = ctx->r7 | 0X6667;
    // 0x8019B468: addiu       $a0, $a0, -0x6E4
    ctx->r4 = ADD32(ctx->r4, -0X6E4);
    // 0x8019B46C: lui         $a1, 0x4160
    ctx->r5 = S32(0X4160 << 16);
    // 0x8019B470: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8019B474: jal         0x8009BC2C
    // 0x8019B478: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_31;
    // 0x8019B478: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_31:
    // 0x8019B47C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8019B480:
    // 0x8019B480: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8019B484: jr          $ra
    // 0x8019B488: nop

    return;
    // 0x8019B488: nop

;}
RECOMP_FUNC void Katina_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80198930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80198934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80198938: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019893C: jal         0x80061404
    // 0x80198940: addiu       $a0, $a0, -0xAE8
    ctx->r4 = ADD32(ctx->r4, -0XAE8);
    Boss_Initialize(rdram, ctx);
        goto after_0;
    // 0x80198940: addiu       $a0, $a0, -0xAE8
    ctx->r4 = ADD32(ctx->r4, -0XAE8);
    after_0:
    // 0x80198944: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80198948: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019894C: sb          $t6, -0xAE8($at)
    MEM_B(-0XAE8, ctx->r1) = ctx->r14;
    // 0x80198950: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80198954: lwc1        $f4, 0x34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X34);
    // 0x80198958: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019895C: addiu       $a1, $zero, 0x13C
    ctx->r5 = ADD32(0, 0X13C);
    // 0x80198960: swc1        $f4, -0xAE4($at)
    MEM_W(-0XAE4, ctx->r1) = ctx->f4.u32l;
    // 0x80198964: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80198968: lwc1        $f6, 0x38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X38);
    // 0x8019896C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80198970: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80198974: swc1        $f6, -0xAE0($at)
    MEM_W(-0XAE0, ctx->r1) = ctx->f6.u32l;
    // 0x80198978: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019897C: lwc1        $f8, 0x3C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3C);
    // 0x80198980: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80198984: addiu       $a0, $a0, -0xACC
    ctx->r4 = ADD32(ctx->r4, -0XACC);
    // 0x80198988: swc1        $f8, -0xADC($at)
    MEM_W(-0XADC, ctx->r1) = ctx->f8.u32l;
    // 0x8019898C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80198990: jal         0x800612B8
    // 0x80198994: sh          $a1, -0xAE6($at)
    MEM_H(-0XAE6, ctx->r1) = ctx->r5;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80198994: sh          $a1, -0xAE6($at)
    MEM_H(-0XAE6, ctx->r1) = ctx->r5;
    after_1:
    // 0x80198998: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019899C: jal         0x80061404
    // 0x801989A0: addiu       $a0, $a0, -0xEF0
    ctx->r4 = ADD32(ctx->r4, -0XEF0);
    Boss_Initialize(rdram, ctx);
        goto after_2;
    // 0x801989A0: addiu       $a0, $a0, -0xEF0
    ctx->r4 = ADD32(ctx->r4, -0XEF0);
    after_2:
    // 0x801989A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801989A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801989AC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801989B0: sb          $t7, -0xEF0($at)
    MEM_B(-0XEF0, ctx->r1) = ctx->r15;
    // 0x801989B4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801989B8: swc1        $f0, -0xEEC($at)
    MEM_W(-0XEEC, ctx->r1) = ctx->f0.u32l;
    // 0x801989BC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801989C0: swc1        $f0, -0xEE8($at)
    MEM_W(-0XEE8, ctx->r1) = ctx->f0.u32l;
    // 0x801989C4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801989C8: swc1        $f0, -0xEE4($at)
    MEM_W(-0XEE4, ctx->r1) = ctx->f0.u32l;
    // 0x801989CC: addiu       $a1, $zero, 0x13D
    ctx->r5 = ADD32(0, 0X13D);
    // 0x801989D0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801989D4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801989D8: addiu       $a0, $a0, -0xED4
    ctx->r4 = ADD32(ctx->r4, -0XED4);
    // 0x801989DC: jal         0x800612B8
    // 0x801989E0: sh          $a1, -0xEEE($at)
    MEM_H(-0XEEE, ctx->r1) = ctx->r5;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x801989E0: sh          $a1, -0xEEE($at)
    MEM_H(-0XEEE, ctx->r1) = ctx->r5;
    after_3:
    // 0x801989E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801989E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801989EC: jr          $ra
    // 0x801989F0: nop

    return;
    // 0x801989F0: nop

;}
RECOMP_FUNC void Katina_FireSmokeEffectSpawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192C08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80192C0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80192C10: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80192C14: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80192C18: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80192C1C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80192C20: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x80192C24: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x80192C28: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_80192C2C:
    // 0x80192C2C: bnel        $t6, $zero, L_80192C70
    if (ctx->r14 != 0) {
        // 0x80192C30: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_80192C70;
    }
    goto skip_0;
    // 0x80192C30: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x80192C34: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80192C38: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80192C3C: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80192C40: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80192C44: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80192C48: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80192C4C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80192C50: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80192C54: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80192C58: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80192C5C: jal         0x80192B4C
    // 0x80192C60: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    Katina_FireSmokeEffectSetup(rdram, ctx);
        goto after_0;
    // 0x80192C60: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x80192C64: b           L_80192C80
    // 0x80192C68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80192C80;
    // 0x80192C68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80192C6C: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_80192C70:
    // 0x80192C70: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80192C74: beql        $at, $zero, L_80192C2C
    if (ctx->r1 == 0) {
        // 0x80192C78: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_80192C2C;
    }
    goto skip_1;
    // 0x80192C78: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x80192C7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80192C80:
    // 0x80192C80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80192C84: jr          $ra
    // 0x80192C88: nop

    return;
    // 0x80192C88: nop

;}
RECOMP_FUNC void Bolse_LevelStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EF6C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8018EF70: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018EF74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018EF78: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018EF7C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018EF80: addiu       $v1, $zero, 0x1E
    ctx->r3 = ADD32(0, 0X1E);
    // 0x8018EF84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018EF88: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x8018EF8C: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
    // 0x8018EF90: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x8018EF94: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x8018EF98: beq         $v0, $zero, L_8018EFC0
    if (ctx->r2 == 0) {
        // 0x8018EF9C: addiu       $t8, $zero, 0x3E8
        ctx->r24 = ADD32(0, 0X3E8);
            goto L_8018EFC0;
    }
    // 0x8018EF9C: addiu       $t8, $zero, 0x3E8
    ctx->r24 = ADD32(0, 0X3E8);
    // 0x8018EFA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018EFA4: beq         $v0, $a2, L_8018F14C
    if (ctx->r2 == ctx->r6) {
        // 0x8018EFA8: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_8018F14C;
    }
    // 0x8018EFA8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018EFAC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018EFB0: beq         $v0, $at, L_8018F4F4
    if (ctx->r2 == ctx->r1) {
        // 0x8018EFB4: nop
    
            goto L_8018F4F4;
    }
    // 0x8018EFB4: nop

    // 0x8018EFB8: b           L_8018F640
    // 0x8018EFBC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_8018F640;
    // 0x8018EFBC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8018EFC0:
    // 0x8018EFC0: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x8018EFC4: sw          $v0, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r2;
    // 0x8018EFC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018EFCC: sw          $v0, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r2;
    // 0x8018EFD0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018EFD4: sw          $t6, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r14;
    // 0x8018EFD8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018EFDC: sw          $zero, -0x7AAC($at)
    MEM_W(-0X7AAC, ctx->r1) = 0;
    // 0x8018EFE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018EFE4: sw          $t7, -0x7AA8($at)
    MEM_W(-0X7AA8, ctx->r1) = ctx->r15;
    // 0x8018EFE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018EFEC: sw          $v1, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r3;
    // 0x8018EFF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018EFF4: sw          $t8, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r24;
    // 0x8018EFF8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018EFFC: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x8018F000: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018F004: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018F008: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018F00C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018F010: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018F014: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8018F018: swc1        $f6, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f6.u32l;
    // 0x8018F01C: swc1        $f8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f8.u32l;
    // 0x8018F020: swc1        $f10, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f10.u32l;
    // 0x8018F024: swc1        $f16, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f16.u32l;
    // 0x8018F028: lw          $t9, 0x78B4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78B4);
    // 0x8018F02C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018F030: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x8018F034: blez        $t9, L_8018F044
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8018F038: nop
    
            goto L_8018F044;
    }
    // 0x8018F038: nop

    // 0x8018F03C: jal         0x8018EAEC
    // 0x8018F040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Bolse_8018EAEC(rdram, ctx);
        goto after_0;
    // 0x8018F040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
L_8018F044:
    // 0x8018F044: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8018F048: lw          $t0, 0x78B8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78B8);
    // 0x8018F04C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018F050: addiu       $a0, $a0, 0x42D4
    ctx->r4 = ADD32(ctx->r4, 0X42D4);
    // 0x8018F054: blez        $t0, L_8018F064
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8018F058: nop
    
            goto L_8018F064;
    }
    // 0x8018F058: nop

    // 0x8018F05C: jal         0x8018EAEC
    // 0x8018F060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Bolse_8018EAEC(rdram, ctx);
        goto after_1;
    // 0x8018F060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_8018F064:
    // 0x8018F064: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8018F068: lw          $t1, 0x78BC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78BC);
    // 0x8018F06C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018F070: addiu       $a0, $a0, 0x45C8
    ctx->r4 = ADD32(ctx->r4, 0X45C8);
    // 0x8018F074: blez        $t1, L_8018F084
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8018F078: nop
    
            goto L_8018F084;
    }
    // 0x8018F078: nop

    // 0x8018F07C: jal         0x8018EAEC
    // 0x8018F080: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Bolse_8018EAEC(rdram, ctx);
        goto after_2;
    // 0x8018F080: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
L_8018F084:
    // 0x8018F084: jal         0x8018EC1C
    // 0x8018F088: nop

    Bolse_CsBoSatellite_Setup(rdram, ctx);
        goto after_3;
    // 0x8018F088: nop

    after_3:
    // 0x8018F08C: jal         0x8018ECB4
    // 0x8018F090: nop

    Bolse_BoBaseShield_Setup(rdram, ctx);
        goto after_4;
    // 0x8018F090: nop

    after_4:
    // 0x8018F094: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F098: lwc1        $f0, -0x648($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X648);
    // 0x8018F09C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018F0A0: addiu       $v1, $v1, 0x7A48
    ctx->r3 = ADD32(ctx->r3, 0X7A48);
    // 0x8018F0A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F0A8: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8018F0AC: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x8018F0B0: lwc1        $f18, -0x644($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X644);
    // 0x8018F0B4: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8018F0B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018F0BC: swc1        $f18, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f18.u32l;
    // 0x8018F0C0: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8018F0C4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F0C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018F0CC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018F0D0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018F0D4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018F0D8: addiu       $v0, $v0, -0x7CA8
    ctx->r2 = ADD32(ctx->r2, -0X7CA8);
    // 0x8018F0DC: swc1        $f8, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f8.u32l;
    // 0x8018F0E0: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8018F0E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F0E8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8018F0EC: swc1        $f10, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f10.u32l;
    // 0x8018F0F0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8018F0F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018F0F8: lwc1        $f16, 0x7C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018F0FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F100: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8018F104: swc1        $f4, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f4.u32l;
    // 0x8018F108: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F10C: swc1        $f6, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f6.u32l;
    // 0x8018F110: lwc1        $f8, 0x78($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8018F114: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F118: swc1        $f8, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f8.u32l;
    // 0x8018F11C: lwc1        $f10, 0x7C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018F120: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F124: swc1        $f10, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f10.u32l;
    // 0x8018F128: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018F12C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018F130: sw          $a2, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r6;
    // 0x8018F134: sw          $a2, 0x204($s0)
    MEM_W(0X204, ctx->r16) = ctx->r6;
    // 0x8018F138: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8018F13C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018F140: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x8018F144: b           L_8018F63C
    // 0x8018F148: sw          $t2, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r10;
        goto L_8018F63C;
    // 0x8018F148: sw          $t2, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r10;
L_8018F14C:
    // 0x8018F14C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018F150: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018F154: addiu       $v0, $v0, -0x7CA8
    ctx->r2 = ADD32(ctx->r2, -0X7CA8);
    // 0x8018F158: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8018F15C: swc1        $f18, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f18.u32l;
    // 0x8018F160: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8018F164: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F168: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018F16C: swc1        $f4, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f4.u32l;
    // 0x8018F170: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018F174: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F178: addiu       $v1, $v1, 0x7A48
    ctx->r3 = ADD32(ctx->r3, 0X7A48);
    // 0x8018F17C: swc1        $f6, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f6.u32l;
    // 0x8018F180: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x8018F184: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018F188: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8018F18C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F190: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018F194: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
    // 0x8018F198: lwc1        $f4, -0x640($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X640);
    // 0x8018F19C: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8018F1A0: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018F1A4: jal         0x80023090
    // 0x8018F1A8: nop

    __sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x8018F1A8: nop

    after_5:
    // 0x8018F1AC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018F1B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018F1B4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F1B8: lwc1        $f10, 0x7A50($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7A50);
    // 0x8018F1BC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8018F1C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F1C4: lwc1        $f16, -0x63C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X63C);
    // 0x8018F1C8: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018F1CC: jal         0x80023090
    // 0x8018F1D0: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_6;
    // 0x8018F1D0: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x8018F1D4: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x8018F1D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018F1DC: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8018F1E0: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8018F1E4: swc1        $f4, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f4.u32l;
    // 0x8018F1E8: lw          $t4, 0x7A80($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7A80);
    // 0x8018F1EC: andi        $t5, $t4, 0x7
    ctx->r13 = ctx->r12 & 0X7;
    // 0x8018F1F0: bne         $t5, $zero, L_8018F224
    if (ctx->r13 != 0) {
        // 0x8018F1F4: nop
    
            goto L_8018F224;
    }
    // 0x8018F1F4: nop

    // 0x8018F1F8: jal         0x80004EB0
    // 0x8018F1FC: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x8018F1FC: nop

    after_7:
    // 0x8018F200: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018F204: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018F208: nop

    // 0x8018F20C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8018F210: nop

    // 0x8018F214: bc1f        L_8018F224
    if (!c1cs) {
        // 0x8018F218: nop
    
            goto L_8018F224;
    }
    // 0x8018F218: nop

    // 0x8018F21C: jal         0x8018ED44
    // 0x8018F220: nop

    Bolse_ActorCsLaserShot_Spawn(rdram, ctx);
        goto after_8;
    // 0x8018F220: nop

    after_8:
L_8018F224:
    // 0x8018F224: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018F228: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x8018F22C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8018F230: bne         $at, $zero, L_8018F258
    if (ctx->r1 != 0) {
        // 0x8018F234: addiu       $t6, $v0, -0x1E
        ctx->r14 = ADD32(ctx->r2, -0X1E);
            goto L_8018F258;
    }
    // 0x8018F234: addiu       $t6, $v0, -0x1E
    ctx->r14 = ADD32(ctx->r2, -0X1E);
    // 0x8018F238: sltiu       $at, $t6, 0x62
    ctx->r1 = ctx->r14 < 0X62 ? 1 : 0;
    // 0x8018F23C: beq         $at, $zero, L_8018F4EC
    if (ctx->r1 == 0) {
        // 0x8018F240: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8018F4EC;
    }
    // 0x8018F240: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018F244: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F248: addu        $at, $at, $t6
    gpr jr_addend_8018F250 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8018F24C: lw          $t6, -0x638($at)
    ctx->r14 = ADD32(ctx->r1, -0X638);
    // 0x8018F250: jr          $t6
    // 0x8018F254: nop

    switch (jr_addend_8018F250 >> 2) {
        case 0: goto L_8018F280; break;
        case 1: goto L_8018F4EC; break;
        case 2: goto L_8018F4EC; break;
        case 3: goto L_8018F4EC; break;
        case 4: goto L_8018F4EC; break;
        case 5: goto L_8018F4EC; break;
        case 6: goto L_8018F4EC; break;
        case 7: goto L_8018F4EC; break;
        case 8: goto L_8018F4EC; break;
        case 9: goto L_8018F4EC; break;
        case 10: goto L_8018F29C; break;
        case 11: goto L_8018F4EC; break;
        case 12: goto L_8018F4EC; break;
        case 13: goto L_8018F4EC; break;
        case 14: goto L_8018F4EC; break;
        case 15: goto L_8018F4EC; break;
        case 16: goto L_8018F4EC; break;
        case 17: goto L_8018F4EC; break;
        case 18: goto L_8018F4EC; break;
        case 19: goto L_8018F4EC; break;
        case 20: goto L_8018F2B8; break;
        case 21: goto L_8018F4EC; break;
        case 22: goto L_8018F4EC; break;
        case 23: goto L_8018F4EC; break;
        case 24: goto L_8018F4EC; break;
        case 25: goto L_8018F4EC; break;
        case 26: goto L_8018F4EC; break;
        case 27: goto L_8018F4EC; break;
        case 28: goto L_8018F4EC; break;
        case 29: goto L_8018F4EC; break;
        case 30: goto L_8018F4EC; break;
        case 31: goto L_8018F4EC; break;
        case 32: goto L_8018F4EC; break;
        case 33: goto L_8018F4EC; break;
        case 34: goto L_8018F4EC; break;
        case 35: goto L_8018F4EC; break;
        case 36: goto L_8018F4EC; break;
        case 37: goto L_8018F4EC; break;
        case 38: goto L_8018F4EC; break;
        case 39: goto L_8018F4EC; break;
        case 40: goto L_8018F2D8; break;
        case 41: goto L_8018F4EC; break;
        case 42: goto L_8018F4EC; break;
        case 43: goto L_8018F4EC; break;
        case 44: goto L_8018F4EC; break;
        case 45: goto L_8018F4EC; break;
        case 46: goto L_8018F4EC; break;
        case 47: goto L_8018F4EC; break;
        case 48: goto L_8018F4EC; break;
        case 49: goto L_8018F4EC; break;
        case 50: goto L_8018F2F8; break;
        case 51: goto L_8018F4EC; break;
        case 52: goto L_8018F4EC; break;
        case 53: goto L_8018F4EC; break;
        case 54: goto L_8018F4EC; break;
        case 55: goto L_8018F318; break;
        case 56: goto L_8018F4EC; break;
        case 57: goto L_8018F4EC; break;
        case 58: goto L_8018F4EC; break;
        case 59: goto L_8018F4EC; break;
        case 60: goto L_8018F4EC; break;
        case 61: goto L_8018F4EC; break;
        case 62: goto L_8018F4EC; break;
        case 63: goto L_8018F4EC; break;
        case 64: goto L_8018F4EC; break;
        case 65: goto L_8018F4EC; break;
        case 66: goto L_8018F4EC; break;
        case 67: goto L_8018F4EC; break;
        case 68: goto L_8018F4EC; break;
        case 69: goto L_8018F4EC; break;
        case 70: goto L_8018F338; break;
        case 71: goto L_8018F4EC; break;
        case 72: goto L_8018F4EC; break;
        case 73: goto L_8018F4EC; break;
        case 74: goto L_8018F4EC; break;
        case 75: goto L_8018F4EC; break;
        case 76: goto L_8018F4EC; break;
        case 77: goto L_8018F4EC; break;
        case 78: goto L_8018F4EC; break;
        case 79: goto L_8018F4EC; break;
        case 80: goto L_8018F4EC; break;
        case 81: goto L_8018F4EC; break;
        case 82: goto L_8018F4EC; break;
        case 83: goto L_8018F4EC; break;
        case 84: goto L_8018F4EC; break;
        case 85: goto L_8018F4EC; break;
        case 86: goto L_8018F4EC; break;
        case 87: goto L_8018F4EC; break;
        case 88: goto L_8018F4EC; break;
        case 89: goto L_8018F4EC; break;
        case 90: goto L_8018F354; break;
        case 91: goto L_8018F4EC; break;
        case 92: goto L_8018F4EC; break;
        case 93: goto L_8018F4EC; break;
        case 94: goto L_8018F4EC; break;
        case 95: goto L_8018F4EC; break;
        case 96: goto L_8018F4EC; break;
        case 97: goto L_8018F370; break;
        default: switch_error(__func__, 0x8018F250, 0x8019F9C8);
    }
    // 0x8018F254: nop

L_8018F258:
    // 0x8018F258: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018F25C: bne         $v0, $at, L_8018F4EC
    if (ctx->r2 != ctx->r1) {
        // 0x8018F260: lui         $at, 0x4416
        ctx->r1 = S32(0X4416 << 16);
            goto L_8018F4EC;
    }
    // 0x8018F260: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8018F264: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018F268: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8018F26C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8018F270: jal         0x8018EE4C
    // 0x8018F274: nop

    Bolse_ActorCsBoFighter_Spawn(rdram, ctx);
        goto after_9;
    // 0x8018F274: nop

    after_9:
    // 0x8018F278: b           L_8018F640
    // 0x8018F27C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_8018F640;
    // 0x8018F27C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8018F280:
    // 0x8018F280: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8018F284: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018F288: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8018F28C: jal         0x8018EE4C
    // 0x8018F290: nop

    Bolse_ActorCsBoFighter_Spawn(rdram, ctx);
        goto after_10;
    // 0x8018F290: nop

    after_10:
    // 0x8018F294: b           L_8018F640
    // 0x8018F298: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_8018F640;
    // 0x8018F298: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8018F29C:
    // 0x8018F29C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018F2A0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8018F2A4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8018F2A8: jal         0x8018EE4C
    // 0x8018F2AC: nop

    Bolse_ActorCsBoFighter_Spawn(rdram, ctx);
        goto after_11;
    // 0x8018F2AC: nop

    after_11:
    // 0x8018F2B0: b           L_8018F640
    // 0x8018F2B4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_8018F640;
    // 0x8018F2B4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8018F2B8:
    // 0x8018F2B8: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x8018F2BC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018F2C0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8018F2C4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8018F2C8: jal         0x8018EE4C
    // 0x8018F2CC: nop

    Bolse_ActorCsBoFighter_Spawn(rdram, ctx);
        goto after_12;
    // 0x8018F2CC: nop

    after_12:
    // 0x8018F2D0: b           L_8018F640
    // 0x8018F2D4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_8018F640;
    // 0x8018F2D4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8018F2D8:
    // 0x8018F2D8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8018F2DC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018F2E0: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x8018F2E4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8018F2E8: jal         0x8018EE4C
    // 0x8018F2EC: nop

    Bolse_ActorCsBoFighter_Spawn(rdram, ctx);
        goto after_13;
    // 0x8018F2EC: nop

    after_13:
    // 0x8018F2F0: b           L_8018F640
    // 0x8018F2F4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_8018F640;
    // 0x8018F2F4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8018F2F8:
    // 0x8018F2F8: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x8018F2FC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018F300: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8018F304: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8018F308: jal         0x8018EE4C
    // 0x8018F30C: nop

    Bolse_ActorCsBoFighter_Spawn(rdram, ctx);
        goto after_14;
    // 0x8018F30C: nop

    after_14:
    // 0x8018F310: b           L_8018F640
    // 0x8018F314: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_8018F640;
    // 0x8018F314: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8018F318:
    // 0x8018F318: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8018F31C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018F320: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x8018F324: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8018F328: jal         0x8018EE4C
    // 0x8018F32C: nop

    Bolse_ActorCsBoFighter_Spawn(rdram, ctx);
        goto after_15;
    // 0x8018F32C: nop

    after_15:
    // 0x8018F330: b           L_8018F640
    // 0x8018F334: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_8018F640;
    // 0x8018F334: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8018F338:
    // 0x8018F338: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x8018F33C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018F340: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8018F344: jal         0x8018EE4C
    // 0x8018F348: nop

    Bolse_ActorCsBoFighter_Spawn(rdram, ctx);
        goto after_16;
    // 0x8018F348: nop

    after_16:
    // 0x8018F34C: b           L_8018F640
    // 0x8018F350: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_8018F640;
    // 0x8018F350: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8018F354:
    // 0x8018F354: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x8018F358: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018F35C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8018F360: jal         0x8018EE4C
    // 0x8018F364: nop

    Bolse_ActorCsBoFighter_Spawn(rdram, ctx);
        goto after_17;
    // 0x8018F364: nop

    after_17:
    // 0x8018F368: b           L_8018F640
    // 0x8018F36C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_8018F640;
    // 0x8018F36C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8018F370:
    // 0x8018F370: jal         0x800A6148
    // 0x8018F374: nop

    Play_ClearObjectData(rdram, ctx);
        goto after_18;
    // 0x8018F374: nop

    after_18:
    // 0x8018F378: jal         0x80191ED8
    // 0x8018F37C: nop

    Bolse_LoadLevelObjects(rdram, ctx);
        goto after_19;
    // 0x8018F37C: nop

    after_19:
    // 0x8018F380: jal         0x8002F180
    // 0x8018F384: nop

    ActorAllRange_SpawnTeam(rdram, ctx);
        goto after_20;
    // 0x8018F384: nop

    after_20:
    // 0x8018F388: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x8018F38C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018F390: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018F394: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8018F398: sw          $t7, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r15;
    // 0x8018F39C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F3A0: swc1        $f8, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f8.u32l;
    // 0x8018F3A4: swc1        $f10, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f10.u32l;
    // 0x8018F3A8: lwc1        $f16, -0x4B0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4B0);
    // 0x8018F3AC: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x8018F3B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018F3B4: lui         $at, 0x43B0
    ctx->r1 = S32(0X43B0 << 16);
    // 0x8018F3B8: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8018F3BC: lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // 0x8018F3C0: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018F3C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018F3C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018F3CC: addiu       $a1, $a1, -0xFAC
    ctx->r5 = ADD32(ctx->r5, -0XFAC);
    // 0x8018F3D0: addiu       $v1, $v1, -0xFD0
    ctx->r3 = ADD32(ctx->r3, -0XFD0);
    // 0x8018F3D4: addiu       $v0, $v0, 0x42D4
    ctx->r2 = ADD32(ctx->r2, 0X42D4);
    // 0x8018F3D8: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    // 0x8018F3DC: swc1        $f16, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f16.u32l;
    // 0x8018F3E0: swc1        $f18, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f18.u32l;
L_8018F3E4:
    // 0x8018F3E4: lwc1        $f4, -0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0XC);
    // 0x8018F3E8: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8018F3EC: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x8018F3F0: addiu       $v0, $v0, 0x2F4
    ctx->r2 = ADD32(ctx->r2, 0X2F4);
    // 0x8018F3F4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018F3F8: swc1        $f8, -0x2F0($v0)
    MEM_W(-0X2F0, ctx->r2) = ctx->f8.u32l;
    // 0x8018F3FC: lwc1        $f16, 0x78($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8018F400: lwc1        $f10, -0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, -0X14);
    // 0x8018F404: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018F408: swc1        $f18, -0x2EC($v0)
    MEM_W(-0X2EC, ctx->r2) = ctx->f18.u32l;
    // 0x8018F40C: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018F410: lwc1        $f4, -0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0X10);
    // 0x8018F414: swc1        $f0, -0x200($v0)
    MEM_W(-0X200, ctx->r2) = ctx->f0.u32l;
    // 0x8018F418: sh          $a2, -0x23C($v0)
    MEM_H(-0X23C, ctx->r2) = ctx->r6;
    // 0x8018F41C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018F420: sh          $a0, -0x238($v0)
    MEM_H(-0X238, ctx->r2) = ctx->r4;
    // 0x8018F424: bne         $v1, $a1, L_8018F3E4
    if (ctx->r3 != ctx->r5) {
        // 0x8018F428: swc1        $f8, -0x2E8($v0)
        MEM_W(-0X2E8, ctx->r2) = ctx->f8.u32l;
            goto L_8018F3E4;
    }
    // 0x8018F428: swc1        $f8, -0x2E8($v0)
    MEM_W(-0X2E8, ctx->r2) = ctx->f8.u32l;
    // 0x8018F42C: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x8018F430: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018F434: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F438: addiu       $t8, $zero, 0x12C
    ctx->r24 = ADD32(0, 0X12C);
    // 0x8018F43C: swc1        $f10, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f10.u32l;
    // 0x8018F440: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x8018F444: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018F448: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F44C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018F450: swc1        $f16, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f16.u32l;
    // 0x8018F454: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F458: lwc1        $f18, -0x4AC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X4AC);
    // 0x8018F45C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F460: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x8018F464: swc1        $f18, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f18.u32l;
    // 0x8018F468: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8018F46C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F470: addiu       $t1, $zero, 0x50
    ctx->r9 = ADD32(0, 0X50);
    // 0x8018F474: swc1        $f4, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f4.u32l;
    // 0x8018F478: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8018F47C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F480: addiu       $t2, $zero, 0x6E
    ctx->r10 = ADD32(0, 0X6E);
    // 0x8018F484: swc1        $f6, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f6.u32l;
    // 0x8018F488: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018F48C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F490: addiu       $t3, $zero, 0x96
    ctx->r11 = ADD32(0, 0X96);
    // 0x8018F494: swc1        $f8, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f8.u32l;
    // 0x8018F498: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018F49C: sw          $t8, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r24;
    // 0x8018F4A0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F4A4: sb          $t9, 0x7A98($at)
    MEM_B(0X7A98, ctx->r1) = ctx->r25;
    // 0x8018F4A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018F4AC: sw          $t0, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r8;
    // 0x8018F4B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018F4B4: sw          $t1, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r9;
    // 0x8018F4B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018F4BC: sw          $t2, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r10;
    // 0x8018F4C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018F4C4: sw          $t3, -0x7AAC($at)
    MEM_W(-0X7AAC, ctx->r1) = ctx->r11;
    // 0x8018F4C8: addiu       $v1, $zero, 0x1E
    ctx->r3 = ADD32(0, 0X1E);
    // 0x8018F4CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018F4D0: sw          $v1, -0x7AA8($at)
    MEM_W(-0X7AA8, ctx->r1) = ctx->r3;
    // 0x8018F4D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018F4D8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018F4DC: sw          $v1, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r3;
    // 0x8018F4E0: addiu       $a0, $a0, -0x1B0
    ctx->r4 = ADD32(ctx->r4, -0X1B0);
    // 0x8018F4E4: jal         0x800BA808
    // 0x8018F4E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_21;
    // 0x8018F4E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
L_8018F4EC:
    // 0x8018F4EC: b           L_8018F640
    // 0x8018F4F0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_8018F640;
    // 0x8018F4F0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8018F4F4:
    // 0x8018F4F4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F4F8: lwc1        $f16, -0x4A8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X4A8);
    // 0x8018F4FC: lwc1        $f10, 0xC8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8018F500: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F504: lwc1        $f4, 0x7988($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7988);
    // 0x8018F508: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018F50C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018F510: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018F514: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x8018F518: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018F51C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8018F520: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8018F524: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018F528: swc1        $f6, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f6.u32l;
    // 0x8018F52C: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8018F530: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F534: swc1        $f8, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f8.u32l;
    // 0x8018F538: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8018F53C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F540: swc1        $f10, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f10.u32l;
    // 0x8018F544: lwc1        $f16, 0x7C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018F548: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F54C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018F550: jal         0x8009BC2C
    // 0x8018F554: swc1        $f16, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_22;
    // 0x8018F554: swc1        $f16, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f16.u32l;
    after_22:
    // 0x8018F558: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018F55C: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x8018F560: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x8018F564: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8018F568: bne         $v0, $at, L_8018F57C
    if (ctx->r2 != ctx->r1) {
        // 0x8018F56C: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_8018F57C;
    }
    // 0x8018F56C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8018F570: sw          $t4, 0x204($s0)
    MEM_W(0X204, ctx->r16) = ctx->r12;
    // 0x8018F574: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018F578: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_8018F57C:
    // 0x8018F57C: addiu       $at, $zero, 0x10E
    ctx->r1 = ADD32(0, 0X10E);
    // 0x8018F580: bne         $v0, $at, L_8018F63C
    if (ctx->r2 != ctx->r1) {
        // 0x8018F584: lui         $v1, 0x801A
        ctx->r3 = S32(0X801A << 16);
            goto L_8018F63C;
    }
    // 0x8018F584: lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // 0x8018F588: sw          $a2, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r6;
    // 0x8018F58C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018F590: lwc1        $f18, 0x1A54($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1A54);
    // 0x8018F594: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F598: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8018F59C: swc1        $f18, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f18.u32l;
    // 0x8018F5A0: lwc1        $f6, -0x4A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4A4);
    // 0x8018F5A4: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018F5A8: addiu       $a1, $a1, -0xF88
    ctx->r5 = ADD32(ctx->r5, -0XF88);
    // 0x8018F5AC: addiu       $v0, $v0, 0x42D4
    ctx->r2 = ADD32(ctx->r2, 0X42D4);
    // 0x8018F5B0: addiu       $v1, $v1, -0xFAC
    ctx->r3 = ADD32(ctx->r3, -0XFAC);
    // 0x8018F5B4: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x8018F5B8: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x8018F5BC: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x8018F5C0: beq         $v1, $a1, L_8018F5F8
    if (ctx->r3 == ctx->r5) {
        // 0x8018F5C4: lwc1        $f18, -0x18($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, -0X18);
            goto L_8018F5F8;
    }
    // 0x8018F5C4: lwc1        $f18, -0x18($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, -0X18);
    // 0x8018F5C8: swc1        $f18, 0x124($v0)
    MEM_W(0X124, ctx->r2) = ctx->f18.u32l;
L_8018F5CC:
    // 0x8018F5CC: lwc1        $f16, -0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0X14);
    // 0x8018F5D0: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x8018F5D4: addiu       $v0, $v0, 0x2F4
    ctx->r2 = ADD32(ctx->r2, 0X2F4);
    // 0x8018F5D8: swc1        $f16, -0x1CC($v0)
    MEM_W(-0X1CC, ctx->r2) = ctx->f16.u32l;
    // 0x8018F5DC: lwc1        $f16, -0x1C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0X1C);
    // 0x8018F5E0: sh          $a2, -0x23C($v0)
    MEM_H(-0X23C, ctx->r2) = ctx->r6;
    // 0x8018F5E4: sh          $a0, -0x238($v0)
    MEM_H(-0X238, ctx->r2) = ctx->r4;
    // 0x8018F5E8: swc1        $f16, -0x1C8($v0)
    MEM_W(-0X1C8, ctx->r2) = ctx->f16.u32l;
    // 0x8018F5EC: lwc1        $f18, -0x18($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, -0X18);
    // 0x8018F5F0: bnel        $v1, $a1, L_8018F5CC
    if (ctx->r3 != ctx->r5) {
        // 0x8018F5F4: swc1        $f18, 0x124($v0)
        MEM_W(0X124, ctx->r2) = ctx->f18.u32l;
            goto L_8018F5CC;
    }
    goto skip_0;
    // 0x8018F5F4: swc1        $f18, 0x124($v0)
    MEM_W(0X124, ctx->r2) = ctx->f18.u32l;
    skip_0:
L_8018F5F8:
    // 0x8018F5F8: swc1        $f18, 0x124($v0)
    MEM_W(0X124, ctx->r2) = ctx->f18.u32l;
    // 0x8018F5FC: lwc1        $f16, -0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0X14);
    // 0x8018F600: addiu       $v0, $v0, 0x2F4
    ctx->r2 = ADD32(ctx->r2, 0X2F4);
    // 0x8018F604: swc1        $f16, -0x1CC($v0)
    MEM_W(-0X1CC, ctx->r2) = ctx->f16.u32l;
    // 0x8018F608: lwc1        $f16, -0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0X10);
    // 0x8018F60C: sh          $a2, -0x23C($v0)
    MEM_H(-0X23C, ctx->r2) = ctx->r6;
    // 0x8018F610: sh          $a0, -0x238($v0)
    MEM_H(-0X238, ctx->r2) = ctx->r4;
    // 0x8018F614: swc1        $f16, -0x1C8($v0)
    MEM_W(-0X1C8, ctx->r2) = ctx->f16.u32l;
    // 0x8018F618: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018F61C: lhu         $a1, 0x7C90($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X7C90);
    // 0x8018F620: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018F624: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018F628: jal         0x8001D444
    // 0x8018F62C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_23;
    // 0x8018F62C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_23:
    // 0x8018F630: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x8018F634: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F638: sw          $t5, 0x7838($at)
    MEM_W(0X7838, ctx->r1) = ctx->r13;
L_8018F63C:
    // 0x8018F63C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8018F640:
    // 0x8018F640: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018F644: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8018F648: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F64C: lwc1        $f8, -0x4A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4A0);
    // 0x8018F650: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8018F654: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F658: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018F65C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018F660: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018F664: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018F668: jal         0x80005E90
    // 0x8018F66C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_24;
    // 0x8018F66C: nop

    after_24:
    // 0x8018F670: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F674: lwc1        $f4, -0x49C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X49C);
    // 0x8018F678: lwc1        $f16, 0xE4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x8018F67C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F680: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018F684: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8018F688: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018F68C: neg.s       $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = -ctx->f18.fl;
    // 0x8018F690: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018F694: jal         0x80005D44
    // 0x8018F698: nop

    Matrix_RotateX(rdram, ctx);
        goto after_25;
    // 0x8018F698: nop

    after_25:
    // 0x8018F69C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018F6A0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018F6A4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F6A8: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x8018F6AC: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x8018F6B0: lwc1        $f16, 0xD0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x8018F6B4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018F6B8: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8018F6BC: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x8018F6C0: jal         0x80006A20
    // 0x8018F6C4: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_26;
    // 0x8018F6C4: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    after_26:
    // 0x8018F6C8: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8018F6CC: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8018F6D0: lwc1        $f14, 0x74($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8018F6D4: lwc1        $f12, 0x7C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018F6D8: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8018F6DC: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8018F6E0: lwc1        $f10, 0xEC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8018F6E4: lwc1        $f8, 0x12C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x8018F6E8: swc1        $f16, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f16.u32l;
    // 0x8018F6EC: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8018F6F0: add.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8018F6F4: lwc1        $f10, 0xC0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8018F6F8: lwc1        $f6, 0x130($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X130);
    // 0x8018F6FC: swc1        $f16, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f16.u32l;
    // 0x8018F700: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x8018F704: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8018F708: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8018F70C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018F710: swc1        $f14, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f14.u32l;
    // 0x8018F714: add.s       $f16, $f12, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x8018F718: lwc1        $f12, 0xC4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8018F71C: swc1        $f10, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f10.u32l;
    // 0x8018F720: add.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8018F724: swc1        $f16, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f16.u32l;
    // 0x8018F728: lwc1        $f16, 0x7C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018F72C: add.s       $f12, $f18, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x8018F730: swc1        $f6, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f6.u32l;
    // 0x8018F734: swc1        $f16, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f16.u32l;
    // 0x8018F738: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018F73C: swc1        $f12, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f12.u32l;
    // 0x8018F740: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8018F744: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8018F748: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x8018F74C: lw          $a1, 0x7978($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7978);
    // 0x8018F750: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8018F754: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8018F758: jal         0x8009BC2C
    // 0x8018F75C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_27;
    // 0x8018F75C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_27:
    // 0x8018F760: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018F764: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018F768: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8018F76C: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8018F770: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8018F774: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8018F778: lw          $a1, 0x7980($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7980);
    // 0x8018F77C: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x8018F780: jal         0x8009BC2C
    // 0x8018F784: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_28;
    // 0x8018F784: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_28:
    // 0x8018F788: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018F78C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018F790: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8018F794: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8018F798: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8018F79C: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8018F7A0: lw          $a1, 0x7988($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7988);
    // 0x8018F7A4: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x8018F7A8: jal         0x8009BC2C
    // 0x8018F7AC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_29;
    // 0x8018F7AC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_29:
    // 0x8018F7B0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018F7B4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018F7B8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8018F7BC: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8018F7C0: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8018F7C4: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8018F7C8: lw          $a1, 0x79A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79A0);
    // 0x8018F7CC: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x8018F7D0: jal         0x8009BC2C
    // 0x8018F7D4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_30;
    // 0x8018F7D4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_30:
    // 0x8018F7D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018F7DC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018F7E0: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8018F7E4: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8018F7E8: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8018F7EC: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8018F7F0: lw          $a1, 0x79B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79B8);
    // 0x8018F7F4: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x8018F7F8: jal         0x8009BC2C
    // 0x8018F7FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_31;
    // 0x8018F7FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_31:
    // 0x8018F800: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018F804: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018F808: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8018F80C: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8018F810: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8018F814: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8018F818: lw          $a1, 0x79C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79C0);
    // 0x8018F81C: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x8018F820: jal         0x8009BC2C
    // 0x8018F824: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_32;
    // 0x8018F824: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_32:
    // 0x8018F828: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018F82C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018F830: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8018F834: jr          $ra
    // 0x8018F838: nop

    return;
    // 0x8018F838: nop

;}
RECOMP_FUNC void Fortuna_CsExplosion(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018906C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80189070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80189074: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80189078: jal         0x800613C4
    // 0x8018907C: addiu       $a0, $a0, -0x2C78
    ctx->r4 = ADD32(ctx->r4, -0X2C78);
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018907C: addiu       $a0, $a0, -0x2C78
    ctx->r4 = ADD32(ctx->r4, -0X2C78);
    after_0:
    // 0x80189080: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80189084: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80189088: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018908C: sb          $t6, -0x2C78($at)
    MEM_B(-0X2C78, ctx->r1) = ctx->r14;
    // 0x80189090: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189094: swc1        $f0, -0x2C74($at)
    MEM_W(-0X2C74, ctx->r1) = ctx->f0.u32l;
    // 0x80189098: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018909C: swc1        $f0, -0x2C70($at)
    MEM_W(-0X2C70, ctx->r1) = ctx->f0.u32l;
    // 0x801890A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801890A4: lwc1        $f4, -0x838($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X838);
    // 0x801890A8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801890AC: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x801890B0: swc1        $f4, -0x2C6C($at)
    MEM_W(-0X2C6C, ctx->r1) = ctx->f4.u32l;
    // 0x801890B4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801890B8: sh          $t7, -0x2BC2($at)
    MEM_H(-0X2BC2, ctx->r1) = ctx->r15;
    // 0x801890BC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801890C0: swc1        $f0, -0x2B68($at)
    MEM_W(-0X2B68, ctx->r1) = ctx->f0.u32l;
    // 0x801890C4: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    // 0x801890C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801890CC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801890D0: addiu       $a0, $a0, -0x2C5C
    ctx->r4 = ADD32(ctx->r4, -0X2C5C);
    // 0x801890D4: jal         0x800612B8
    // 0x801890D8: sh          $a1, -0x2C76($at)
    MEM_H(-0X2C76, ctx->r1) = ctx->r5;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x801890D8: sh          $a1, -0x2C76($at)
    MEM_H(-0X2C76, ctx->r1) = ctx->r5;
    after_1:
    // 0x801890DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801890E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801890E4: jr          $ra
    // 0x801890E8: nop

    return;
    // 0x801890E8: nop

;}
RECOMP_FUNC void Katina_StartCutsceneUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192C8C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80192C90: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80192C94: lui         $fp, 0x8014
    ctx->r30 = S32(0X8014 << 16);
    // 0x80192C98: addiu       $fp, $fp, -0x4438
    ctx->r30 = ADD32(ctx->r30, -0X4438);
    // 0x80192C9C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80192CA0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80192CA4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80192CA8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80192CAC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80192CB0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80192CB4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80192CB8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80192CBC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80192CC0: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80192CC4: lui         $a1, 0xBF49
    ctx->r5 = S32(0XBF49 << 16);
    // 0x80192CC8: addiu       $s0, $s0, 0x4BB0
    ctx->r16 = ADD32(ctx->r16, 0X4BB0);
    // 0x80192CCC: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80192CD0: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x80192CD4: jal         0x80005E90
    // 0x80192CD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x80192CD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80192CDC: lui         $s7, 0x800C
    ctx->r23 = S32(0X800C << 16);
    // 0x80192CE0: addiu       $s7, $s7, 0x5D34
    ctx->r23 = ADD32(ctx->r23, 0X5D34);
    // 0x80192CE4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80192CE8: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_80192CEC:
    // 0x80192CEC: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80192CF0: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x80192CF4: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x80192CF8: bne         $t6, $zero, L_80192DE0
    if (ctx->r14 != 0) {
        // 0x80192CFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80192DE0;
    }
    // 0x80192CFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80192D00: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80192D04: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80192D08: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80192D0C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80192D10: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80192D14: addiu       $t1, $t1, -0xEA4
    ctx->r9 = ADD32(ctx->r9, -0XEA4);
    // 0x80192D18: addiu       $t9, $t9, -0xEEC
    ctx->r25 = ADD32(ctx->r25, -0XEEC);
    // 0x80192D1C: addiu       $t8, $t8, -0xEC8
    ctx->r24 = ADD32(ctx->r24, -0XEC8);
    // 0x80192D20: addiu       $t7, $t7, -0xF10
    ctx->r15 = ADD32(ctx->r15, -0XF10);
    // 0x80192D24: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x80192D28: addu        $s5, $t0, $t1
    ctx->r21 = ADD32(ctx->r8, ctx->r9);
    // 0x80192D2C: addu        $s2, $v0, $t7
    ctx->r18 = ADD32(ctx->r2, ctx->r15);
    // 0x80192D30: addu        $s3, $v0, $t8
    ctx->r19 = ADD32(ctx->r2, ctx->r24);
    // 0x80192D34: jal         0x800613C4
    // 0x80192D38: addu        $s4, $v0, $t9
    ctx->r20 = ADD32(ctx->r2, ctx->r25);
    Actor_Initialize(rdram, ctx);
        goto after_1;
    // 0x80192D38: addu        $s4, $v0, $t9
    ctx->r20 = ADD32(ctx->r2, ctx->r25);
    after_1:
    // 0x80192D3C: addiu       $t2, $zero, 0xC3
    ctx->r10 = ADD32(0, 0XC3);
    // 0x80192D40: sb          $s6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r22;
    // 0x80192D44: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // 0x80192D48: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    // 0x80192D4C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80192D50: jal         0x80006A20
    // 0x80192D54: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x80192D54: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x80192D58: lw          $at, 0x0($s3)
    ctx->r1 = MEM_W(ctx->r19, 0X0);
    // 0x80192D5C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80192D60: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x80192D64: sw          $at, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r1;
    // 0x80192D68: lw          $t4, 0x4($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X4);
    // 0x80192D6C: sw          $t4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r12;
    // 0x80192D70: lw          $at, 0x8($s3)
    ctx->r1 = MEM_W(ctx->r19, 0X8);
    // 0x80192D74: sw          $at, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r1;
    // 0x80192D78: jal         0x80006A20
    // 0x80192D7C: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_3;
    // 0x80192D7C: lw          $a0, 0x0($fp)
    ctx->r4 = MEM_W(ctx->r30, 0X0);
    after_3:
    // 0x80192D80: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80192D84: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80192D88: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80192D8C: swc1        $f4, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f4.u32l;
    // 0x80192D90: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80192D94: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80192D98: swc1        $f6, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f6.u32l;
    // 0x80192D9C: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80192DA0: swc1        $f8, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f8.u32l;
    // 0x80192DA4: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x80192DA8: sb          $s6, 0xC9($s0)
    MEM_B(0XC9, ctx->r16) = ctx->r22;
    // 0x80192DAC: sw          $t6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r14;
    // 0x80192DB0: jal         0x800612B8
    // 0x80192DB4: sh          $t5, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r13;
    Object_SetInfo(rdram, ctx);
        goto after_4;
    // 0x80192DB4: sh          $t5, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r13;
    after_4:
    // 0x80192DB8: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80192DBC: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x80192DC0: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x80192DC4: ori         $a0, $a0, 0x11
    ctx->r4 = ctx->r4 | 0X11;
    // 0x80192DC8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80192DCC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80192DD0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80192DD4: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80192DD8: jal         0x80019218
    // 0x80192DDC: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x80192DDC: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    after_5:
L_80192DE0:
    // 0x80192DE0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80192DE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80192DE8: bne         $s1, $at, L_80192CEC
    if (ctx->r17 != ctx->r1) {
        // 0x80192DEC: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_80192CEC;
    }
    // 0x80192DEC: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
    // 0x80192DF0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80192DF4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80192DF8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80192DFC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80192E00: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80192E04: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80192E08: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80192E0C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80192E10: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80192E14: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80192E18: jr          $ra
    // 0x80192E1C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80192E1C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void Fortuna_LevelComplete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018927C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80189280: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80189284: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80189288: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018928C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80189290: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
    // 0x80189294: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80189298: beql        $at, $zero, L_801893EC
    if (ctx->r1 == 0) {
        // 0x8018929C: mtc1        $zero, $f20
        ctx->f20.u32l = 0;
            goto L_801893EC;
    }
    goto skip_0;
    // 0x8018929C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    skip_0:
    // 0x801892A0: bltz        $v0, L_801893E8
    if (SIGNED(ctx->r2) < 0) {
        // 0x801892A4: addiu       $a0, $s0, 0x130
        ctx->r4 = ADD32(ctx->r16, 0X130);
            goto L_801893E8;
    }
    // 0x801892A4: addiu       $a0, $s0, 0x130
    ctx->r4 = ADD32(ctx->r16, 0X130);
    // 0x801892A8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801892AC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801892B0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801892B4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801892B8: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x801892BC: jal         0x8009BC2C
    // 0x801892C0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x801892C0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x801892C4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801892C8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801892CC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801892D0: addiu       $a0, $s0, 0x12C
    ctx->r4 = ADD32(ctx->r16, 0X12C);
    // 0x801892D4: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x801892D8: jal         0x8009BC2C
    // 0x801892DC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x801892DC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x801892E0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801892E4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801892E8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801892EC: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x801892F0: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x801892F4: jal         0x8009BC2C
    // 0x801892F8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801892F8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_2:
    // 0x801892FC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80189300: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80189304: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189308: addiu       $a0, $s0, 0x4D8
    ctx->r4 = ADD32(ctx->r16, 0X4D8);
    // 0x8018930C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80189310: jal         0x8009BD38
    // 0x80189314: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_3;
    // 0x80189314: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x80189318: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018931C: lbu         $t6, 0x7930($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7930);
    // 0x80189320: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80189324: bnel        $t6, $zero, L_8018936C
    if (ctx->r14 != 0) {
        // 0x80189328: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8018936C;
    }
    goto skip_1;
    // 0x80189328: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_1:
    // 0x8018932C: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x80189330: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80189334: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80189338: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018933C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189340: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80189344: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x80189348: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018934C: bc1fl       L_8018939C
    if (!c1cs) {
        // 0x80189350: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8018939C;
    }
    goto skip_2;
    // 0x80189350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80189354: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80189358: jal         0x8009BC2C
    // 0x8018935C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x8018935C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_4:
    // 0x80189360: b           L_8018939C
    // 0x80189364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8018939C;
    // 0x80189364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80189368: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8018936C:
    // 0x8018936C: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80189370: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80189374: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189378: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8018937C: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x80189380: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80189384: bc1fl       L_8018939C
    if (!c1cs) {
        // 0x80189388: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8018939C;
    }
    goto skip_3;
    // 0x80189388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x8018938C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80189390: jal         0x8009BC2C
    // 0x80189394: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x80189394: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_5:
    // 0x80189398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8018939C:
    // 0x8018939C: jal         0x800B7184
    // 0x801893A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Camera_Update360(rdram, ctx);
        goto after_6;
    // 0x801893A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x801893A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801893A8: lwc1        $f0, -0x830($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X830);
    // 0x801893AC: lwc1        $f10, 0xC0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x801893B0: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x801893B4: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x801893B8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801893BC: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x801893C0: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801893C4: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801893C8: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x801893CC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x801893D0: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x801893D4: lwc1        $f18, 0xC8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x801893D8: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    // 0x801893DC: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801893E0: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x801893E4: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
L_801893E8:
    // 0x801893E8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
L_801893EC:
    // 0x801893EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801893F0: lwc1        $f0, -0x82C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X82C);
    // 0x801893F4: swc1        $f20, 0x4A0($s0)
    MEM_W(0X4A0, ctx->r16) = ctx->f20.u32l;
    // 0x801893F8: swc1        $f20, 0x4A8($s0)
    MEM_W(0X4A8, ctx->r16) = ctx->f20.u32l;
    // 0x801893FC: swc1        $f20, 0x4A4($s0)
    MEM_W(0X4A4, ctx->r16) = ctx->f20.u32l;
    // 0x80189400: swc1        $f20, 0x4AC($s0)
    MEM_W(0X4AC, ctx->r16) = ctx->f20.u32l;
    // 0x80189404: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80189408: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018940C: addiu       $a0, $s0, 0x110
    ctx->r4 = ADD32(ctx->r16, 0X110);
    // 0x80189410: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x80189414: jal         0x8009BC2C
    // 0x80189418: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x80189418: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_7:
    // 0x8018941C: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
    // 0x80189420: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80189424: sltiu       $at, $t7, 0x18
    ctx->r1 = ctx->r15 < 0X18 ? 1 : 0;
    // 0x80189428: beq         $at, $zero, L_8018B8C8
    if (ctx->r1 == 0) {
        // 0x8018942C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8018B8C8;
    }
    // 0x8018942C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80189430: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80189434: addu        $at, $at, $t7
    gpr jr_addend_8018943C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80189438: lw          $t7, -0x828($at)
    ctx->r15 = ADD32(ctx->r1, -0X828);
    // 0x8018943C: jr          $t7
    // 0x80189440: nop

    switch (jr_addend_8018943C >> 2) {
        case 0: goto L_80189444; break;
        case 1: goto L_80189540; break;
        case 2: goto L_801896E4; break;
        case 3: goto L_80189860; break;
        case 4: goto L_8018B8C8; break;
        case 5: goto L_8018B8C8; break;
        case 6: goto L_8018B8C8; break;
        case 7: goto L_8018B8C8; break;
        case 8: goto L_8018B8C8; break;
        case 9: goto L_8018B8C8; break;
        case 10: goto L_8018B8C8; break;
        case 11: goto L_80189C04; break;
        case 12: goto L_80189DB8; break;
        case 13: goto L_8018A480; break;
        case 14: goto L_8018B8C8; break;
        case 15: goto L_8018B8C8; break;
        case 16: goto L_8018B8C8; break;
        case 17: goto L_8018B8C8; break;
        case 18: goto L_8018B8C8; break;
        case 19: goto L_8018B8C8; break;
        case 20: goto L_8018B8C8; break;
        case 21: goto L_8018A8A0; break;
        case 22: goto L_8018AAB4; break;
        case 23: goto L_8018AEB4; break;
        default: switch_error(__func__, 0x8018943C, 0x8019F7D8);
    }
    // 0x80189440: nop

L_80189444:
    // 0x80189444: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80189448: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018944C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80189450: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189454: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x80189458: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018945C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80189460: sb          $t8, 0x4C8($s0)
    MEM_B(0X4C8, ctx->r16) = ctx->r24;
    // 0x80189464: swc1        $f20, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f20.u32l;
    // 0x80189468: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018946C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80189470: swc1        $f0, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f0.u32l;
    // 0x80189474: swc1        $f10, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f10.u32l;
    // 0x80189478: swc1        $f8, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f8.u32l;
    // 0x8018947C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80189480: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189484: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x80189488: jal         0x8009BC2C
    // 0x8018948C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x8018948C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_8:
    // 0x80189490: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x80189494: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80189498: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018949C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801894A0: swc1        $f20, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f20.u32l;
    // 0x801894A4: swc1        $f20, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f20.u32l;
    // 0x801894A8: swc1        $f20, 0x4D8($s0)
    MEM_W(0X4D8, ctx->r16) = ctx->f20.u32l;
    // 0x801894AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801894B0: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x801894B4: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    // 0x801894B8: lwc1        $f6, -0x7C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7C8);
    // 0x801894BC: lw          $t9, 0x1F8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F8);
    // 0x801894C0: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x801894C4: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x801894C8: lwc1        $f8, 0x138($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X138);
    // 0x801894CC: slti        $at, $t9, 0x50
    ctx->r1 = SIGNED(ctx->r25) < 0X50 ? 1 : 0;
    // 0x801894D0: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    // 0x801894D4: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    // 0x801894D8: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    // 0x801894DC: beq         $at, $zero, L_80189538
    if (ctx->r1 == 0) {
        // 0x801894E0: swc1        $f8, 0x54($s0)
        MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
            goto L_80189538;
    }
    // 0x801894E0: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    // 0x801894E4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x801894E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801894EC: sw          $v0, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r2;
    // 0x801894F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801894F4: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x801894F8: sw          $t6, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r14;
    // 0x801894FC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80189500: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80189504: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80189508: addiu       $a1, $a1, -0x7CB8
    ctx->r5 = ADD32(ctx->r5, -0X7CB8);
    // 0x8018950C: addiu       $a0, $a0, -0x7CB0
    ctx->r4 = ADD32(ctx->r4, -0X7CB0);
    // 0x80189510: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x80189514: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80189518: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8018951C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80189520: lw          $t9, 0x1F8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F8);
    // 0x80189524: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80189528: bne         $t9, $zero, L_80189538
    if (ctx->r25 != 0) {
        // 0x8018952C: nop
    
            goto L_80189538;
    }
    // 0x8018952C: nop

    // 0x80189530: sw          $zero, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = 0;
    // 0x80189534: sw          $t6, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r14;
L_80189538:
    // 0x80189538: b           L_8018B8C8
    // 0x8018953C: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
        goto L_8018B8C8;
    // 0x8018953C: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
L_80189540:
    // 0x80189540: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80189544: lbu         $t7, 0x7930($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7930);
    // 0x80189548: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x8018954C: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x80189550: bne         $t7, $zero, L_801895AC
    if (ctx->r15 != 0) {
        // 0x80189554: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_801895AC;
    }
    // 0x80189554: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80189558: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018955C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189560: lui         $a3, 0x4020
    ctx->r7 = S32(0X4020 << 16);
    // 0x80189564: jal         0x8009BC2C
    // 0x80189568: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x80189568: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_9:
    // 0x8018956C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80189570: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189574: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x80189578: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x8018957C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80189580: jal         0x8009BC2C
    // 0x80189584: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x80189584: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_10:
    // 0x80189588: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018958C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80189590: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189594: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x80189598: lui         $a3, 0x4020
    ctx->r7 = S32(0X4020 << 16);
    // 0x8018959C: jal         0x8009BC2C
    // 0x801895A0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x801895A0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_11:
    // 0x801895A4: b           L_80189644
    // 0x801895A8: lw          $t8, 0x1F8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F8);
        goto L_80189644;
    // 0x801895A8: lw          $t8, 0x1F8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F8);
L_801895AC:
    // 0x801895AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801895B0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801895B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801895B8: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x801895BC: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    // 0x801895C0: lwc1        $f14, 0x138($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X138);
    // 0x801895C4: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x801895C8: swc1        $f18, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f18.u32l;
    // 0x801895CC: jal         0x80005100
    // 0x801895D0: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_12;
    // 0x801895D0: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    after_12:
    // 0x801895D4: jal         0x8009F768
    // 0x801895D8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_13;
    // 0x801895D8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_13:
    // 0x801895DC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801895E0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801895E4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801895E8: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x801895EC: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x801895F0: jal         0x8009BC2C
    // 0x801895F4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x801895F4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_14:
    // 0x801895F8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801895FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189600: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80189604: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189608: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8018960C: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x80189610: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80189614: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80189618: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018961C: jal         0x8009BC2C
    // 0x80189620: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x80189620: nop

    after_15:
    // 0x80189624: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80189628: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018962C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189630: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x80189634: lui         $a3, 0x4020
    ctx->r7 = S32(0X4020 << 16);
    // 0x80189638: jal         0x8009BC2C
    // 0x8018963C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x8018963C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_16:
    // 0x80189640: lw          $t8, 0x1F8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F8);
L_80189644:
    // 0x80189644: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80189648: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8018964C: bne         $t8, $zero, L_801896DC
    if (ctx->r24 != 0) {
        // 0x80189650: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_801896DC;
    }
    // 0x80189650: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80189654: lbu         $t9, 0x7930($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X7930);
    // 0x80189658: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8018965C: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x80189660: beq         $t9, $zero, L_801896A0
    if (ctx->r25 == 0) {
        // 0x80189664: addiu       $a1, $s0, 0x460
        ctx->r5 = ADD32(ctx->r16, 0X460);
            goto L_801896A0;
    }
    // 0x80189664: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    // 0x80189668: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x8018966C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80189670: lui         $at, 0xC52F
    ctx->r1 = S32(0XC52F << 16);
    // 0x80189674: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80189678: addiu       $t6, $zero, 0x96
    ctx->r14 = ADD32(0, 0X96);
    // 0x8018967C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80189680: sw          $t6, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r14;
    // 0x80189684: sw          $t7, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r15;
    // 0x80189688: swc1        $f20, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f20.u32l;
    // 0x8018968C: swc1        $f20, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f20.u32l;
    // 0x80189690: swc1        $f20, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f20.u32l;
    // 0x80189694: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    // 0x80189698: b           L_801896B0
    // 0x8018969C: swc1        $f16, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f16.u32l;
        goto L_801896B0;
    // 0x8018969C: swc1        $f16, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f16.u32l;
L_801896A0:
    // 0x801896A0: addiu       $t8, $zero, 0x118
    ctx->r24 = ADD32(0, 0X118);
    // 0x801896A4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801896A8: sw          $t8, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r24;
    // 0x801896AC: sw          $t9, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r25;
L_801896B0:
    // 0x801896B0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801896B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801896B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801896BC: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x801896C0: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x801896C4: swc1        $f6, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f6.u32l;
    // 0x801896C8: swc1        $f4, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f4.u32l;
    // 0x801896CC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801896D0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801896D4: jal         0x80019218
    // 0x801896D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_17;
    // 0x801896D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
L_801896DC:
    // 0x801896DC: b           L_8018B8C8
    // 0x801896E0: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
        goto L_8018B8C8;
    // 0x801896E0: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
L_801896E4:
    // 0x801896E4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801896E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801896EC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801896F0: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x801896F4: swc1        $f10, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f10.u32l;
    // 0x801896F8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801896FC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80189700: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189704: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x80189708: jal         0x8009BC2C
    // 0x8018970C: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_18;
    // 0x8018970C: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    after_18:
    // 0x80189710: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80189714: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189718: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x8018971C: lui         $a1, 0xC220
    ctx->r5 = S32(0XC220 << 16);
    // 0x80189720: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80189724: jal         0x8009BC2C
    // 0x80189728: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_19;
    // 0x80189728: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_19:
    // 0x8018972C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80189730: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189734: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x80189738: lui         $a1, 0xC2F0
    ctx->r5 = S32(0XC2F0 << 16);
    // 0x8018973C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80189740: jal         0x8009BC2C
    // 0x80189744: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_20;
    // 0x80189744: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_20:
    // 0x80189748: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8018974C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80189750: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80189754: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80189758: lwc1        $f8, 0xD0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x8018975C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80189760: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80189764: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80189768: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018976C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80189770: addiu       $t9, $zero, 0x3E8
    ctx->r25 = ADD32(0, 0X3E8);
    // 0x80189774: swc1        $f16, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f16.u32l;
    // 0x80189778: lwc1        $f6, 0xD0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x8018977C: addiu       $a1, $a1, 0x40E0
    ctx->r5 = ADD32(ctx->r5, 0X40E0);
    // 0x80189780: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x80189784: c.le.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl <= ctx->f6.fl;
    // 0x80189788: nop

    // 0x8018978C: bc1fl       L_801897CC
    if (!c1cs) {
        // 0x80189790: lw          $t7, 0x1F8($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X1F8);
            goto L_801897CC;
    }
    goto skip_4;
    // 0x80189790: lw          $t7, 0x1F8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F8);
    skip_4:
    // 0x80189794: lwc1        $f0, -0x7C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7C4);
    // 0x80189798: swc1        $f2, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f2.u32l;
    // 0x8018979C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801897A0: lwc1        $f10, -0x7C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7C0);
    // 0x801897A4: lwc1        $f4, 0x25C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X25C);
    // 0x801897A8: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x801897AC: swc1        $f8, 0x25C($s0)
    MEM_W(0X25C, ctx->r16) = ctx->f8.u32l;
    // 0x801897B0: lwc1        $f18, 0x25C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X25C);
    // 0x801897B4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x801897B8: nop

    // 0x801897BC: bc1fl       L_801897CC
    if (!c1cs) {
        // 0x801897C0: lw          $t7, 0x1F8($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X1F8);
            goto L_801897CC;
    }
    goto skip_5;
    // 0x801897C0: lw          $t7, 0x1F8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F8);
    skip_5:
    // 0x801897C4: swc1        $f0, 0x25C($s0)
    MEM_W(0X25C, ctx->r16) = ctx->f0.u32l;
    // 0x801897C8: lw          $t7, 0x1F8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F8);
L_801897CC:
    // 0x801897CC: bne         $t7, $zero, L_80189858
    if (ctx->r15 != 0) {
        // 0x801897D0: nop
    
            goto L_80189858;
    }
    // 0x801897D0: nop

    // 0x801897D4: sw          $t8, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r24;
    // 0x801897D8: sw          $t9, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r25;
L_801897DC:
    // 0x801897DC: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x801897E0: jal         0x80060FBC
    // 0x801897E4: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    Object_Kill(rdram, ctx);
        goto after_21;
    // 0x801897E4: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_21:
    // 0x801897E8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x801897EC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801897F0: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x801897F4: addiu       $t6, $t6, -0xDF0
    ctx->r14 = ADD32(ctx->r14, -0XDF0);
    // 0x801897F8: addiu       $a1, $a1, 0x2F4
    ctx->r5 = ADD32(ctx->r5, 0X2F4);
    // 0x801897FC: bne         $a1, $t6, L_801897DC
    if (ctx->r5 != ctx->r14) {
        // 0x80189800: addiu       $a0, $a0, 0x2F4
        ctx->r4 = ADD32(ctx->r4, 0X2F4);
            goto L_801897DC;
    }
    // 0x80189800: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
    // 0x80189804: jal         0x8001CA24
    // 0x80189808: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_StopPlayerNoise(rdram, ctx);
        goto after_22;
    // 0x80189808: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_22:
    // 0x8018980C: jal         0x8001A500
    // 0x80189810: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    Audio_KillSfxBySource(rdram, ctx);
        goto after_23;
    // 0x80189810: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    after_23:
    // 0x80189814: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80189818: sw          $zero, 0x234($s0)
    MEM_W(0X234, ctx->r16) = 0;
    // 0x8018981C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189820: sw          $v0, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r2;
    // 0x80189824: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189828: sw          $v0, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r2;
    // 0x8018982C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80189830: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80189834: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80189838: addiu       $a1, $a1, -0x7CB8
    ctx->r5 = ADD32(ctx->r5, -0X7CB8);
    // 0x8018983C: addiu       $a0, $a0, -0x7CB0
    ctx->r4 = ADD32(ctx->r4, -0X7CB0);
    // 0x80189840: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x80189844: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80189848: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8018984C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80189850: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189854: sw          $zero, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = 0;
L_80189858:
    // 0x80189858: b           L_8018B8C8
    // 0x8018985C: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
        goto L_8018B8C8;
    // 0x8018985C: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
L_80189860:
    // 0x80189860: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80189864: lbu         $t6, 0x7930($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7930);
    // 0x80189868: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018986C: bnel        $t6, $zero, L_80189898
    if (ctx->r14 != 0) {
        // 0x80189870: lw          $v0, 0x1F8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F8);
            goto L_80189898;
    }
    goto skip_6;
    // 0x80189870: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
    skip_6:
    // 0x80189874: lw          $t7, 0x1F8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F8);
    // 0x80189878: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8018987C: slti        $at, $t7, 0x33F
    ctx->r1 = SIGNED(ctx->r15) < 0X33F ? 1 : 0;
    // 0x80189880: bne         $at, $zero, L_80189894
    if (ctx->r1 != 0) {
        // 0x80189884: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_80189894;
    }
    // 0x80189884: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189888: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x8018988C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189890: sw          $t8, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r24;
L_80189894:
    // 0x80189894: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
L_80189898:
    // 0x80189898: addiu       $at, $zero, 0x32A
    ctx->r1 = ADD32(0, 0X32A);
    // 0x8018989C: bnel        $v0, $at, L_801898B4
    if (ctx->r2 != ctx->r1) {
        // 0x801898A0: addiu       $at, $zero, 0x33E
        ctx->r1 = ADD32(0, 0X33E);
            goto L_801898B4;
    }
    goto skip_7;
    // 0x801898A0: addiu       $at, $zero, 0x33E
    ctx->r1 = ADD32(0, 0X33E);
    skip_7:
    // 0x801898A4: jal         0x8001A500
    // 0x801898A8: addiu       $a0, $a0, -0xAF4
    ctx->r4 = ADD32(ctx->r4, -0XAF4);
    Audio_KillSfxBySource(rdram, ctx);
        goto after_24;
    // 0x801898A8: addiu       $a0, $a0, -0xAF4
    ctx->r4 = ADD32(ctx->r4, -0XAF4);
    after_24:
    // 0x801898AC: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
    // 0x801898B0: addiu       $at, $zero, 0x33E
    ctx->r1 = ADD32(0, 0X33E);
L_801898B4:
    // 0x801898B4: bne         $v0, $at, L_801898F8
    if (ctx->r2 != ctx->r1) {
        // 0x801898B8: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_801898F8;
    }
    // 0x801898B8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801898BC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x801898C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801898C4: sw          $v0, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r2;
    // 0x801898C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801898CC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801898D0: sw          $t9, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r25;
    // 0x801898D4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x801898D8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801898DC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801898E0: addiu       $a1, $a1, -0x7CB8
    ctx->r5 = ADD32(ctx->r5, -0X7CB8);
    // 0x801898E4: addiu       $a0, $a0, -0x7CB0
    ctx->r4 = ADD32(ctx->r4, -0X7CB0);
    // 0x801898E8: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x801898EC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x801898F0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x801898F4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_801898F8:
    // 0x801898F8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801898FC: addiu       $a0, $a0, -0xEF0
    ctx->r4 = ADD32(ctx->r4, -0XEF0);
    // 0x80189900: jal         0x80090200
    // 0x80189904: sh          $t8, 0x88($a0)
    MEM_H(0X88, ctx->r4) = ctx->r24;
    FoBase_ExplodeCs(rdram, ctx);
        goto after_25;
    // 0x80189904: sh          $t8, 0x88($a0)
    MEM_H(0X88, ctx->r4) = ctx->r24;
    after_25:
    // 0x80189908: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018990C: beq         $v0, $at, L_80189920
    if (ctx->r2 == ctx->r1) {
        // 0x80189910: lui         $t9, 0x8017
        ctx->r25 = S32(0X8017 << 16);
            goto L_80189920;
    }
    // 0x80189910: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80189914: lbu         $t9, 0x7930($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X7930);
    // 0x80189918: beq         $t9, $zero, L_80189BFC
    if (ctx->r25 == 0) {
        // 0x8018991C: nop
    
            goto L_80189BFC;
    }
    // 0x8018991C: nop

L_80189920:
    // 0x80189920: jal         0x800A6148
    // 0x80189924: nop

    Play_ClearObjectData(rdram, ctx);
        goto after_26;
    // 0x80189924: nop

    after_26:
    // 0x80189928: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018992C: lbu         $t6, 0x7930($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7930);
    // 0x80189930: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80189934: addiu       $a0, $zero, 0x44C0
    ctx->r4 = ADD32(0, 0X44C0);
    // 0x80189938: bne         $t6, $zero, L_8018994C
    if (ctx->r14 != 0) {
        // 0x8018993C: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_8018994C;
    }
    // 0x8018993C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80189940: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80189944: b           L_80189954
    // 0x80189948: sw          $t7, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r15;
        goto L_80189954;
    // 0x80189948: sw          $t7, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r15;
L_8018994C:
    // 0x8018994C: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x80189950: sw          $t8, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r24;
L_80189954:
    // 0x80189954: addiu       $v0, $v0, -0x7D58
    ctx->r2 = ADD32(ctx->r2, -0X7D58);
L_80189958:
    // 0x80189958: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8018995C: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x80189960: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x80189964: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80189968: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8018996C: sb          $zero, 0x58($t8)
    MEM_B(0X58, ctx->r24) = 0;
    // 0x80189970: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80189974: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x80189978: sb          $zero, 0xB0($t6)
    MEM_B(0XB0, ctx->r14) = 0;
    // 0x8018997C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80189980: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80189984: addiu       $v1, $v1, 0x160
    ctx->r3 = ADD32(ctx->r3, 0X160);
    // 0x80189988: bne         $v1, $a0, L_80189958
    if (ctx->r3 != ctx->r4) {
        // 0x8018998C: sb          $zero, 0x108($t8)
        MEM_B(0X108, ctx->r24) = 0;
            goto L_80189958;
    }
    // 0x8018998C: sb          $zero, 0x108($t8)
    MEM_B(0X108, ctx->r24) = 0;
    // 0x80189990: jal         0x800A5EBC
    // 0x80189994: nop

    Play_SetupStarfield(rdram, ctx);
        goto after_27;
    // 0x80189994: nop

    after_27:
    // 0x80189998: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018999C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801899A0: sb          $t9, 0x7C98($at)
    MEM_B(0X7C98, ctx->r1) = ctx->r25;
    // 0x801899A4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801899A8: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801899AC: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x801899B0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x801899B4: addiu       $t0, $t0, 0x1A36
    ctx->r8 = ADD32(ctx->r8, 0X1A36);
    // 0x801899B8: addiu       $a3, $a3, -0x7CE0
    ctx->r7 = ADD32(ctx->r7, -0X7CE0);
    // 0x801899BC: addiu       $a2, $a2, -0x7CD8
    ctx->r6 = ADD32(ctx->r6, -0X7CD8);
    // 0x801899C0: addiu       $a1, $a1, -0x7CD0
    ctx->r5 = ADD32(ctx->r5, -0X7CD0);
    // 0x801899C4: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x801899C8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x801899CC: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x801899D0: sh          $zero, 0x0($t0)
    MEM_H(0X0, ctx->r8) = 0;
    // 0x801899D4: andi        $t9, $zero, 0xFFFF
    ctx->r25 = 0 & 0XFFFF;
    // 0x801899D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801899DC: sw          $t9, -0x7B54($at)
    MEM_W(-0X7B54, ctx->r1) = ctx->r25;
    // 0x801899E0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x801899E4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x801899E8: addiu       $t6, $zero, 0x56
    ctx->r14 = ADD32(0, 0X56);
    // 0x801899EC: addiu       $t2, $t2, -0x7A9C
    ctx->r10 = ADD32(ctx->r10, -0X7A9C);
    // 0x801899F0: addiu       $t1, $t1, 0x1A70
    ctx->r9 = ADD32(ctx->r9, 0X1A70);
    // 0x801899F4: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x801899F8: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x801899FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189A00: sw          $t6, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r14;
    // 0x80189A04: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80189A08: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80189A0C: addiu       $t9, $zero, 0x3A
    ctx->r25 = ADD32(0, 0X3A);
    // 0x80189A10: addiu       $t4, $t4, -0x7A98
    ctx->r12 = ADD32(ctx->r12, -0X7A98);
    // 0x80189A14: addiu       $t3, $t3, 0x1A74
    ctx->r11 = ADD32(ctx->r11, 0X1A74);
    // 0x80189A18: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x80189A1C: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x80189A20: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189A24: sw          $t9, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r25;
    // 0x80189A28: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80189A2C: lui         $ra, 0x8018
    ctx->r31 = S32(0X8018 << 16);
    // 0x80189A30: addiu       $t8, $zero, 0x19
    ctx->r24 = ADD32(0, 0X19);
    // 0x80189A34: addiu       $ra, $ra, -0x7A94
    ctx->r31 = ADD32(ctx->r31, -0X7A94);
    // 0x80189A38: addiu       $t5, $t5, 0x1A78
    ctx->r13 = ADD32(ctx->r13, 0X1A78);
    // 0x80189A3C: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x80189A40: sw          $t8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r24;
    // 0x80189A44: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189A48: sw          $t8, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r24;
    // 0x80189A4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189A50: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x80189A54: sw          $t7, -0x7AAC($at)
    MEM_W(-0X7AAC, ctx->r1) = ctx->r15;
    // 0x80189A58: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189A5C: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80189A60: sw          $t8, -0x7AA8($at)
    MEM_W(-0X7AA8, ctx->r1) = ctx->r24;
    // 0x80189A64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189A68: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    // 0x80189A6C: sw          $t9, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r25;
    // 0x80189A70: lui         $at, 0xC26C
    ctx->r1 = S32(0XC26C << 16);
    // 0x80189A74: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80189A78: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80189A7C: addiu       $v0, $v0, -0x7B3C
    ctx->r2 = ADD32(ctx->r2, -0X7B3C);
    // 0x80189A80: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x80189A84: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80189A88: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189A8C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80189A90: swc1        $f6, -0x7B08($at)
    MEM_W(-0X7B08, ctx->r1) = ctx->f6.u32l;
    // 0x80189A94: lwc1        $f4, -0x7B08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7B08);
    // 0x80189A98: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189A9C: addiu       $v1, $v1, -0x7B38
    ctx->r3 = ADD32(ctx->r3, -0X7B38);
    // 0x80189AA0: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80189AA4: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80189AA8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80189AAC: addiu       $a0, $a0, -0x7B34
    ctx->r4 = ADD32(ctx->r4, -0X7B34);
    // 0x80189AB0: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80189AB4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80189AB8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80189ABC: swc1        $f8, -0x7B30($at)
    MEM_W(-0X7B30, ctx->r1) = ctx->f8.u32l;
    // 0x80189AC0: lui         $at, 0x4268
    ctx->r1 = S32(0X4268 << 16);
    // 0x80189AC4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80189AC8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189ACC: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x80189AD0: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80189AD4: swc1        $f16, -0x7B04($at)
    MEM_W(-0X7B04, ctx->r1) = ctx->f16.u32l;
    // 0x80189AD8: lwc1        $f6, -0x7B04($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7B04);
    // 0x80189ADC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189AE0: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80189AE4: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80189AE8: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x80189AEC: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80189AF0: swc1        $f10, -0x7B2C($at)
    MEM_W(-0X7B2C, ctx->r1) = ctx->f10.u32l;
    // 0x80189AF4: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x80189AF8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80189AFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189B00: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80189B04: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80189B08: swc1        $f18, -0x7B00($at)
    MEM_W(-0X7B00, ctx->r1) = ctx->f18.u32l;
    // 0x80189B0C: lwc1        $f16, -0x7B00($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7B00);
    // 0x80189B10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189B14: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x80189B18: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80189B1C: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x80189B20: lbu         $t6, 0x7930($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7930);
    // 0x80189B24: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80189B28: bne         $t6, $zero, L_80189B60
    if (ctx->r14 != 0) {
        // 0x80189B2C: swc1        $f4, -0x7B28($at)
        MEM_W(-0X7B28, ctx->r1) = ctx->f4.u32l;
            goto L_80189B60;
    }
    // 0x80189B2C: swc1        $f4, -0x7B28($at)
    MEM_W(-0X7B28, ctx->r1) = ctx->f4.u32l;
    // 0x80189B30: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80189B34: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189B38: swc1        $f20, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f20.u32l;
    // 0x80189B3C: swc1        $f20, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f20.u32l;
    // 0x80189B40: swc1        $f20, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f20.u32l;
    // 0x80189B44: swc1        $f20, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f20.u32l;
    // 0x80189B48: swc1        $f20, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f20.u32l;
    // 0x80189B4C: swc1        $f20, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f20.u32l;
    // 0x80189B50: jal         0x8018906C
    // 0x80189B54: swc1        $f10, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f10.u32l;
    Fortuna_CsExplosion(rdram, ctx);
        goto after_28;
    // 0x80189B54: swc1        $f10, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f10.u32l;
    after_28:
    // 0x80189B58: b           L_80189B98
    // 0x80189B5C: nop

        goto L_80189B98;
    // 0x80189B5C: nop

L_80189B60:
    // 0x80189B60: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80189B64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80189B68: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80189B6C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80189B70: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80189B74: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80189B78: swc1        $f20, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f20.u32l;
    // 0x80189B7C: swc1        $f20, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f20.u32l;
    // 0x80189B80: swc1        $f20, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f20.u32l;
    // 0x80189B84: swc1        $f20, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f20.u32l;
    // 0x80189B88: swc1        $f20, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f20.u32l;
    // 0x80189B8C: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    // 0x80189B90: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    // 0x80189B94: swc1        $f16, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f16.u32l;
L_80189B98:
    // 0x80189B98: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80189B9C: lwc1        $f6, -0x7BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7BC);
    // 0x80189BA0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189BA4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80189BA8: swc1        $f6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f6.u32l;
    // 0x80189BAC: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x80189BB0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80189BB4: lui         $a0, 0x1064
    ctx->r4 = S32(0X1064 << 16);
    // 0x80189BB8: sb          $t7, 0x4C8($s0)
    MEM_B(0X4C8, ctx->r16) = ctx->r15;
    // 0x80189BBC: sw          $t8, 0x204($s0)
    MEM_W(0X204, ctx->r16) = ctx->r24;
    // 0x80189BC0: jal         0x800182F4
    // 0x80189BC4: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_29;
    // 0x80189BC4: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_29:
    // 0x80189BC8: lui         $a0, 0x1164
    ctx->r4 = S32(0X1164 << 16);
    // 0x80189BCC: jal         0x800182F4
    // 0x80189BD0: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_30;
    // 0x80189BD0: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_30:
    // 0x80189BD4: jal         0x8001C8B8
    // 0x80189BD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_StartPlayerNoise(rdram, ctx);
        goto after_31;
    // 0x80189BD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_31:
    // 0x80189BDC: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80189BE0: lbu         $t9, 0x7930($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X7930);
    // 0x80189BE4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80189BE8: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x80189BEC: bne         $t9, $zero, L_80189BFC
    if (ctx->r25 != 0) {
        // 0x80189BF0: nop
    
            goto L_80189BFC;
    }
    // 0x80189BF0: nop

    // 0x80189BF4: jal         0x801890EC
    // 0x80189BF8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    Fortuna_LevelComplete_CsSpawnTeam(rdram, ctx);
        goto after_32;
    // 0x80189BF8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_32:
L_80189BFC:
    // 0x80189BFC: b           L_8018B8C8
    // 0x80189C00: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
        goto L_8018B8C8;
    // 0x80189C00: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
L_80189C04:
    // 0x80189C04: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80189C08: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80189C0C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80189C10: sw          $t6, 0x234($s0)
    MEM_W(0X234, ctx->r16) = ctx->r14;
    // 0x80189C14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189C18: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x80189C1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189C20: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80189C24: sw          $t7, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r15;
    // 0x80189C28: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80189C2C: swc1        $f20, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f20.u32l;
    // 0x80189C30: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80189C34: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x80189C38: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    // 0x80189C3C: lwc1        $f10, 0x3FE4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X3FE4);
    // 0x80189C40: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80189C44: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80189C48: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
    // 0x80189C4C: lwc1        $f8, 0x3FE8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3FE8);
    // 0x80189C50: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80189C54: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    // 0x80189C58: lwc1        $f18, 0x3FEC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3FEC);
    // 0x80189C5C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80189C60: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    // 0x80189C64: lw          $t8, 0x7A80($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7A80);
    // 0x80189C68: bne         $t8, $at, L_80189CD8
    if (ctx->r24 != ctx->r1) {
        // 0x80189C6C: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80189CD8;
    }
    // 0x80189C6C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80189C70: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80189C74: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80189C78: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80189C7C: swc1        $f0, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f0.u32l;
    // 0x80189C80: lw          $t9, 0x78B4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78B4);
    // 0x80189C84: addiu       $a0, $a0, 0x48BC
    ctx->r4 = ADD32(ctx->r4, 0X48BC);
    // 0x80189C88: blez        $t9, L_80189C98
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80189C8C: nop
    
            goto L_80189C98;
    }
    // 0x80189C8C: nop

    // 0x80189C90: jal         0x801890EC
    // 0x80189C94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Fortuna_LevelComplete_CsSpawnTeam(rdram, ctx);
        goto after_33;
    // 0x80189C94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_33:
L_80189C98:
    // 0x80189C98: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80189C9C: lw          $t6, 0x78B8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78B8);
    // 0x80189CA0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80189CA4: addiu       $a0, $a0, 0x42D4
    ctx->r4 = ADD32(ctx->r4, 0X42D4);
    // 0x80189CA8: blez        $t6, L_80189CB8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80189CAC: nop
    
            goto L_80189CB8;
    }
    // 0x80189CAC: nop

    // 0x80189CB0: jal         0x801890EC
    // 0x80189CB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Fortuna_LevelComplete_CsSpawnTeam(rdram, ctx);
        goto after_34;
    // 0x80189CB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_34:
L_80189CB8:
    // 0x80189CB8: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80189CBC: lw          $t7, 0x78BC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78BC);
    // 0x80189CC0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80189CC4: addiu       $a0, $a0, 0x45C8
    ctx->r4 = ADD32(ctx->r4, 0X45C8);
    // 0x80189CC8: blez        $t7, L_80189CD8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80189CCC: nop
    
            goto L_80189CD8;
    }
    // 0x80189CCC: nop

    // 0x80189CD0: jal         0x801890EC
    // 0x80189CD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Fortuna_LevelComplete_CsSpawnTeam(rdram, ctx);
        goto after_35;
    // 0x80189CD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_35:
L_80189CD8:
    // 0x80189CD8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80189CDC: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x80189CE0: addiu       $at, $zero, 0x1F0
    ctx->r1 = ADD32(0, 0X1F0);
    // 0x80189CE4: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x80189CE8: bne         $v1, $at, L_80189D4C
    if (ctx->r3 != ctx->r1) {
        // 0x80189CEC: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_80189D4C;
    }
    // 0x80189CEC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80189CF0: sw          $t8, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r24;
    // 0x80189CF4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80189CF8: lwc1        $f16, -0x7B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7B8);
    // 0x80189CFC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189D00: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80189D04: swc1        $f16, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f16.u32l;
    // 0x80189D08: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189D0C: swc1        $f20, 0x7A4C($at)
    MEM_W(0X7A4C, ctx->r1) = ctx->f20.u32l;
    // 0x80189D10: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x80189D14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80189D18: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189D1C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80189D20: swc1        $f6, 0x7A50($at)
    MEM_W(0X7A50, ctx->r1) = ctx->f6.u32l;
    // 0x80189D24: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189D28: swc1        $f20, 0x7A54($at)
    MEM_W(0X7A54, ctx->r1) = ctx->f20.u32l;
    // 0x80189D2C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80189D30: sw          $t9, 0x4944($at)
    MEM_W(0X4944, ctx->r1) = ctx->r25;
    // 0x80189D34: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80189D38: sw          $t6, 0x435C($at)
    MEM_W(0X435C, ctx->r1) = ctx->r14;
    // 0x80189D3C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80189D40: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80189D44: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x80189D48: sw          $t7, 0x4650($at)
    MEM_W(0X4650, ctx->r1) = ctx->r15;
L_80189D4C:
    // 0x80189D4C: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80189D50: bne         $v1, $at, L_80189D9C
    if (ctx->r3 != ctx->r1) {
        // 0x80189D54: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_80189D9C;
    }
    // 0x80189D54: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80189D58: lbu         $t8, 0x7930($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7930);
    // 0x80189D5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80189D60: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x80189D64: bne         $t8, $zero, L_80189D8C
    if (ctx->r24 != 0) {
        // 0x80189D68: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80189D8C;
    }
    // 0x80189D68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80189D6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80189D70: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x80189D74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80189D78: jal         0x8001D444
    // 0x80189D7C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_36;
    // 0x80189D7C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_36:
    // 0x80189D80: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80189D84: b           L_80189D9C
    // 0x80189D88: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_80189D9C;
    // 0x80189D88: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_80189D8C:
    // 0x80189D8C: jal         0x8001D444
    // 0x80189D90: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_37;
    // 0x80189D90: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_37:
    // 0x80189D94: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80189D98: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_80189D9C:
    // 0x80189D9C: addiu       $at, $zero, 0x1A4
    ctx->r1 = ADD32(0, 0X1A4);
    // 0x80189DA0: bne         $v1, $at, L_80189DB0
    if (ctx->r3 != ctx->r1) {
        // 0x80189DA4: addiu       $t9, $zero, 0x64
        ctx->r25 = ADD32(0, 0X64);
            goto L_80189DB0;
    }
    // 0x80189DA4: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x80189DA8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189DAC: sw          $t9, 0x7840($at)
    MEM_W(0X7840, ctx->r1) = ctx->r25;
L_80189DB0:
    // 0x80189DB0: b           L_8018B8C8
    // 0x80189DB4: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
        goto L_8018B8C8;
    // 0x80189DB4: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
L_80189DB8:
    // 0x80189DB8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189DBC: lwc1        $f4, 0x7A4C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7A4C);
    // 0x80189DC0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189DC4: lwc1        $f10, 0x7A54($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7A54);
    // 0x80189DC8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189DCC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80189DD0: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80189DD4: lui         $a1, 0xBE32
    ctx->r5 = S32(0XBE32 << 16);
    // 0x80189DD8: ori         $a1, $a1, 0xB8C2
    ctx->r5 = ctx->r5 | 0XB8C2;
    // 0x80189DDC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80189DE0: swc1        $f8, 0x7A4C($at)
    MEM_W(0X7A4C, ctx->r1) = ctx->f8.u32l;
    // 0x80189DE4: jal         0x80005D44
    // 0x80189DE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Matrix_RotateX(rdram, ctx);
        goto after_38;
    // 0x80189DE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_38:
    // 0x80189DEC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189DF0: lwc1        $f18, 0x7A4C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7A4C);
    // 0x80189DF4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80189DF8: lwc1        $f16, -0x7B4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7B4);
    // 0x80189DFC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80189E00: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80189E04: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80189E08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80189E0C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80189E10: jal         0x80005E90
    // 0x80189E14: nop

    Matrix_RotateY(rdram, ctx);
        goto after_39;
    // 0x80189E14: nop

    after_39:
    // 0x80189E18: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189E1C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80189E20: lwc1        $f10, 0x7A50($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7A50);
    // 0x80189E24: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80189E28: swc1        $f20, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f20.u32l;
    // 0x80189E2C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80189E30: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x80189E34: addiu       $a2, $s0, 0x2F8
    ctx->r6 = ADD32(ctx->r16, 0X2F8);
    // 0x80189E38: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x80189E3C: jal         0x80006970
    // 0x80189E40: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_40;
    // 0x80189E40: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    after_40:
    // 0x80189E44: lwc1        $f8, 0x2F8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2F8);
    // 0x80189E48: lwc1        $f18, 0x74($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80189E4C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80189E50: addiu       $v0, $v0, 0x7978
    ctx->r2 = ADD32(ctx->r2, 0X7978);
    // 0x80189E54: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80189E58: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80189E5C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80189E60: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189E64: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x80189E68: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80189E6C: lwc1        $f6, 0x2FC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2FC);
    // 0x80189E70: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80189E74: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80189E78: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80189E7C: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x80189E80: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80189E84: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80189E88: swc1        $f10, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f10.u32l;
    // 0x80189E8C: lwc1        $f18, 0x7C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80189E90: lwc1        $f8, 0x300($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X300);
    // 0x80189E94: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189E98: sub.s       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80189E9C: addiu       $a0, $a0, 0x7A48
    ctx->r4 = ADD32(ctx->r4, 0X7A48);
    // 0x80189EA0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80189EA4: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80189EA8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80189EAC: swc1        $f6, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f6.u32l;
    // 0x80189EB0: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80189EB4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189EB8: swc1        $f4, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f4.u32l;
    // 0x80189EBC: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80189EC0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189EC4: swc1        $f10, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f10.u32l;
    // 0x80189EC8: lwc1        $f18, 0x7C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80189ECC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189ED0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80189ED4: sub.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80189ED8: jal         0x8009BC2C
    // 0x80189EDC: swc1        $f8, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_41;
    // 0x80189EDC: swc1        $f8, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f8.u32l;
    after_41:
    // 0x80189EE0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80189EE4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80189EE8: addiu       $v0, $v0, 0x7978
    ctx->r2 = ADD32(ctx->r2, 0X7978);
    // 0x80189EEC: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80189EF0: lui         $a3, 0x469C
    ctx->r7 = S32(0X469C << 16);
    // 0x80189EF4: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x80189EF8: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80189EFC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80189F00: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x80189F04: jal         0x8009BC2C
    // 0x80189F08: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_42;
    // 0x80189F08: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_42:
    // 0x80189F0C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80189F10: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80189F14: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80189F18: lui         $a3, 0x469C
    ctx->r7 = S32(0X469C << 16);
    // 0x80189F1C: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x80189F20: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80189F24: lw          $a1, 0x7980($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7980);
    // 0x80189F28: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x80189F2C: jal         0x8009BC2C
    // 0x80189F30: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_43;
    // 0x80189F30: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_43:
    // 0x80189F34: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80189F38: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80189F3C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80189F40: lui         $a3, 0x469C
    ctx->r7 = S32(0X469C << 16);
    // 0x80189F44: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x80189F48: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80189F4C: lw          $a1, 0x7988($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7988);
    // 0x80189F50: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x80189F54: jal         0x8009BC2C
    // 0x80189F58: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_44;
    // 0x80189F58: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_44:
    // 0x80189F5C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80189F60: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80189F64: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80189F68: lui         $a3, 0x469C
    ctx->r7 = S32(0X469C << 16);
    // 0x80189F6C: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x80189F70: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80189F74: lw          $a1, 0x79A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79A0);
    // 0x80189F78: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x80189F7C: jal         0x8009BC2C
    // 0x80189F80: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_45;
    // 0x80189F80: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_45:
    // 0x80189F84: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80189F88: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80189F8C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80189F90: lui         $a3, 0x469C
    ctx->r7 = S32(0X469C << 16);
    // 0x80189F94: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x80189F98: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80189F9C: lw          $a1, 0x79B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79B8);
    // 0x80189FA0: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x80189FA4: jal         0x8009BC2C
    // 0x80189FA8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_46;
    // 0x80189FA8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_46:
    // 0x80189FAC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80189FB0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80189FB4: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80189FB8: lui         $a3, 0x469C
    ctx->r7 = S32(0X469C << 16);
    // 0x80189FBC: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x80189FC0: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80189FC4: lw          $a1, 0x79C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79C0);
    // 0x80189FC8: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x80189FCC: jal         0x8009BC2C
    // 0x80189FD0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_47;
    // 0x80189FD0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_47:
    // 0x80189FD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80189FD8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80189FDC: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80189FE0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189FE4: addiu       $a0, $s0, 0xD0
    ctx->r4 = ADD32(ctx->r16, 0XD0);
    // 0x80189FE8: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80189FEC: jal         0x8009BC2C
    // 0x80189FF0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_48;
    // 0x80189FF0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_48:
    // 0x80189FF4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80189FF8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80189FFC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018A000: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018A004: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018A008: addiu       $a0, $a0, 0x49AC
    ctx->r4 = ADD32(ctx->r4, 0X49AC);
    // 0x8018A00C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8018A010: jal         0x8009BC2C
    // 0x8018A014: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_49;
    // 0x8018A014: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_49:
    // 0x8018A018: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018A01C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018A020: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018A024: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018A028: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018A02C: addiu       $a0, $a0, 0x43C4
    ctx->r4 = ADD32(ctx->r4, 0X43C4);
    // 0x8018A030: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8018A034: jal         0x8009BC2C
    // 0x8018A038: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_50;
    // 0x8018A038: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_50:
    // 0x8018A03C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018A040: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018A044: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018A048: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018A04C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018A050: addiu       $a0, $a0, 0x46B8
    ctx->r4 = ADD32(ctx->r4, 0X46B8);
    // 0x8018A054: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8018A058: jal         0x8009BC2C
    // 0x8018A05C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_51;
    // 0x8018A05C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_51:
    // 0x8018A060: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018A064: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018A068: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018A06C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018A070: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018A074: addiu       $a0, $a0, 0x40D0
    ctx->r4 = ADD32(ctx->r4, 0X40D0);
    // 0x8018A078: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8018A07C: jal         0x8009BC2C
    // 0x8018A080: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_52;
    // 0x8018A080: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_52:
    // 0x8018A084: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018A088: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8018A08C: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
    // 0x8018A090: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018A094: bne         $v1, $at, L_8018A0AC
    if (ctx->r3 != ctx->r1) {
        // 0x8018A098: addiu       $a0, $a0, 0x33C0
        ctx->r4 = ADD32(ctx->r4, 0X33C0);
            goto L_8018A0AC;
    }
    // 0x8018A098: addiu       $a0, $a0, 0x33C0
    ctx->r4 = ADD32(ctx->r4, 0X33C0);
    // 0x8018A09C: jal         0x800BA808
    // 0x8018A0A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_53;
    // 0x8018A0A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_53:
    // 0x8018A0A4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018A0A8: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018A0AC:
    // 0x8018A0AC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018A0B0: lbu         $t6, 0x7930($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7930);
    // 0x8018A0B4: addiu       $at, $zero, 0x24C
    ctx->r1 = ADD32(0, 0X24C);
    // 0x8018A0B8: bne         $t6, $zero, L_8018A20C
    if (ctx->r14 != 0) {
        // 0x8018A0BC: nop
    
            goto L_8018A20C;
    }
    // 0x8018A0BC: nop

    // 0x8018A0C0: addiu       $at, $zero, 0x24C
    ctx->r1 = ADD32(0, 0X24C);
    // 0x8018A0C4: beq         $v1, $at, L_8018A0EC
    if (ctx->r3 == ctx->r1) {
        // 0x8018A0C8: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_8018A0EC;
    }
    // 0x8018A0C8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018A0CC: addiu       $at, $zero, 0x2DF
    ctx->r1 = ADD32(0, 0X2DF);
    // 0x8018A0D0: beq         $v1, $at, L_8018A14C
    if (ctx->r3 == ctx->r1) {
        // 0x8018A0D4: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_8018A14C;
    }
    // 0x8018A0D4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018A0D8: addiu       $at, $zero, 0x371
    ctx->r1 = ADD32(0, 0X371);
    // 0x8018A0DC: beq         $v1, $at, L_8018A1AC
    if (ctx->r3 == ctx->r1) {
        // 0x8018A0E0: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_8018A1AC;
    }
    // 0x8018A0E0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018A0E4: b           L_8018A354
    // 0x8018A0E8: slti        $at, $v1, 0x470
    ctx->r1 = SIGNED(ctx->r3) < 0X470 ? 1 : 0;
        goto L_8018A354;
    // 0x8018A0E8: slti        $at, $v1, 0x470
    ctx->r1 = SIGNED(ctx->r3) < 0X470 ? 1 : 0;
L_8018A0EC:
    // 0x8018A0EC: lw          $v0, 0x78B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78B8);
    // 0x8018A0F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018A0F4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018A0F8: beq         $v0, $at, L_8018A110
    if (ctx->r2 == ctx->r1) {
        // 0x8018A0FC: addiu       $a0, $a0, 0x4B2C
        ctx->r4 = ADD32(ctx->r4, 0X4B2C);
            goto L_8018A110;
    }
    // 0x8018A0FC: addiu       $a0, $a0, 0x4B2C
    ctx->r4 = ADD32(ctx->r4, 0X4B2C);
    // 0x8018A100: beq         $v0, $zero, L_8018A120
    if (ctx->r2 == 0) {
        // 0x8018A104: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018A120;
    }
    // 0x8018A104: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018A108: b           L_8018A134
    // 0x8018A10C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
        goto L_8018A134;
    // 0x8018A10C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
L_8018A110:
    // 0x8018A110: jal         0x800BA808
    // 0x8018A114: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_54;
    // 0x8018A114: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_54:
    // 0x8018A118: b           L_8018A140
    // 0x8018A11C: nop

        goto L_8018A140;
    // 0x8018A11C: nop

L_8018A120:
    // 0x8018A120: addiu       $a0, $a0, 0x4C68
    ctx->r4 = ADD32(ctx->r4, 0X4C68);
    // 0x8018A124: jal         0x800BA808
    // 0x8018A128: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_55;
    // 0x8018A128: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_55:
    // 0x8018A12C: b           L_8018A140
    // 0x8018A130: nop

        goto L_8018A140;
    // 0x8018A130: nop

L_8018A134:
    // 0x8018A134: addiu       $a0, $a0, -0x97C
    ctx->r4 = ADD32(ctx->r4, -0X97C);
    // 0x8018A138: jal         0x800BA808
    // 0x8018A13C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_56;
    // 0x8018A13C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_56:
L_8018A140:
    // 0x8018A140: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018A144: b           L_8018A350
    // 0x8018A148: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_8018A350;
    // 0x8018A148: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018A14C:
    // 0x8018A14C: lw          $v0, 0x78BC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78BC);
    // 0x8018A150: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018A154: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018A158: beq         $v0, $at, L_8018A170
    if (ctx->r2 == ctx->r1) {
        // 0x8018A15C: addiu       $a0, $a0, 0x4AE0
        ctx->r4 = ADD32(ctx->r4, 0X4AE0);
            goto L_8018A170;
    }
    // 0x8018A15C: addiu       $a0, $a0, 0x4AE0
    ctx->r4 = ADD32(ctx->r4, 0X4AE0);
    // 0x8018A160: beq         $v0, $zero, L_8018A180
    if (ctx->r2 == 0) {
        // 0x8018A164: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018A180;
    }
    // 0x8018A164: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018A168: b           L_8018A194
    // 0x8018A16C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
        goto L_8018A194;
    // 0x8018A16C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
L_8018A170:
    // 0x8018A170: jal         0x800BA808
    // 0x8018A174: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_57;
    // 0x8018A174: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_57:
    // 0x8018A178: b           L_8018A1A0
    // 0x8018A17C: nop

        goto L_8018A1A0;
    // 0x8018A17C: nop

L_8018A180:
    // 0x8018A180: addiu       $a0, $a0, 0x4C1C
    ctx->r4 = ADD32(ctx->r4, 0X4C1C);
    // 0x8018A184: jal         0x800BA808
    // 0x8018A188: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_58;
    // 0x8018A188: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_58:
    // 0x8018A18C: b           L_8018A1A0
    // 0x8018A190: nop

        goto L_8018A1A0;
    // 0x8018A190: nop

L_8018A194:
    // 0x8018A194: addiu       $a0, $a0, -0x950
    ctx->r4 = ADD32(ctx->r4, -0X950);
    // 0x8018A198: jal         0x800BA808
    // 0x8018A19C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_59;
    // 0x8018A19C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_59:
L_8018A1A0:
    // 0x8018A1A0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018A1A4: b           L_8018A350
    // 0x8018A1A8: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_8018A350;
    // 0x8018A1A8: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018A1AC:
    // 0x8018A1AC: lw          $v0, 0x78B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78B4);
    // 0x8018A1B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018A1B4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018A1B8: beq         $v0, $at, L_8018A1D0
    if (ctx->r2 == ctx->r1) {
        // 0x8018A1BC: addiu       $a0, $a0, 0x4A94
        ctx->r4 = ADD32(ctx->r4, 0X4A94);
            goto L_8018A1D0;
    }
    // 0x8018A1BC: addiu       $a0, $a0, 0x4A94
    ctx->r4 = ADD32(ctx->r4, 0X4A94);
    // 0x8018A1C0: beq         $v0, $zero, L_8018A1E0
    if (ctx->r2 == 0) {
        // 0x8018A1C4: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018A1E0;
    }
    // 0x8018A1C4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018A1C8: b           L_8018A1F4
    // 0x8018A1CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
        goto L_8018A1F4;
    // 0x8018A1CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
L_8018A1D0:
    // 0x8018A1D0: jal         0x800BA808
    // 0x8018A1D4: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_60;
    // 0x8018A1D4: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_60:
    // 0x8018A1D8: b           L_8018A200
    // 0x8018A1DC: nop

        goto L_8018A200;
    // 0x8018A1DC: nop

L_8018A1E0:
    // 0x8018A1E0: addiu       $a0, $a0, 0x4B7C
    ctx->r4 = ADD32(ctx->r4, 0X4B7C);
    // 0x8018A1E4: jal         0x800BA808
    // 0x8018A1E8: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_61;
    // 0x8018A1E8: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_61:
    // 0x8018A1EC: b           L_8018A200
    // 0x8018A1F0: nop

        goto L_8018A200;
    // 0x8018A1F0: nop

L_8018A1F4:
    // 0x8018A1F4: addiu       $a0, $a0, -0x904
    ctx->r4 = ADD32(ctx->r4, -0X904);
    // 0x8018A1F8: jal         0x800BA808
    // 0x8018A1FC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_62;
    // 0x8018A1FC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_62:
L_8018A200:
    // 0x8018A200: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018A204: b           L_8018A350
    // 0x8018A208: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_8018A350;
    // 0x8018A208: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018A20C:
    // 0x8018A20C: beq         $v1, $at, L_8018A234
    if (ctx->r3 == ctx->r1) {
        // 0x8018A210: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_8018A234;
    }
    // 0x8018A210: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018A214: addiu       $at, $zero, 0x2DF
    ctx->r1 = ADD32(0, 0X2DF);
    // 0x8018A218: beq         $v1, $at, L_8018A294
    if (ctx->r3 == ctx->r1) {
        // 0x8018A21C: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_8018A294;
    }
    // 0x8018A21C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018A220: addiu       $at, $zero, 0x371
    ctx->r1 = ADD32(0, 0X371);
    // 0x8018A224: beq         $v1, $at, L_8018A2F4
    if (ctx->r3 == ctx->r1) {
        // 0x8018A228: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_8018A2F4;
    }
    // 0x8018A228: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018A22C: b           L_8018A354
    // 0x8018A230: slti        $at, $v1, 0x470
    ctx->r1 = SIGNED(ctx->r3) < 0X470 ? 1 : 0;
        goto L_8018A354;
    // 0x8018A230: slti        $at, $v1, 0x470
    ctx->r1 = SIGNED(ctx->r3) < 0X470 ? 1 : 0;
L_8018A234:
    // 0x8018A234: lw          $v0, 0x78B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78B8);
    // 0x8018A238: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018A23C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018A240: beq         $v0, $at, L_8018A258
    if (ctx->r2 == ctx->r1) {
        // 0x8018A244: addiu       $a0, $a0, 0x4B2C
        ctx->r4 = ADD32(ctx->r4, 0X4B2C);
            goto L_8018A258;
    }
    // 0x8018A244: addiu       $a0, $a0, 0x4B2C
    ctx->r4 = ADD32(ctx->r4, 0X4B2C);
    // 0x8018A248: beq         $v0, $zero, L_8018A268
    if (ctx->r2 == 0) {
        // 0x8018A24C: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018A268;
    }
    // 0x8018A24C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018A250: b           L_8018A27C
    // 0x8018A254: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
        goto L_8018A27C;
    // 0x8018A254: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
L_8018A258:
    // 0x8018A258: jal         0x800BA808
    // 0x8018A25C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_63;
    // 0x8018A25C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_63:
    // 0x8018A260: b           L_8018A288
    // 0x8018A264: nop

        goto L_8018A288;
    // 0x8018A264: nop

L_8018A268:
    // 0x8018A268: addiu       $a0, $a0, 0x4C68
    ctx->r4 = ADD32(ctx->r4, 0X4C68);
    // 0x8018A26C: jal         0x800BA808
    // 0x8018A270: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_64;
    // 0x8018A270: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_64:
    // 0x8018A274: b           L_8018A288
    // 0x8018A278: nop

        goto L_8018A288;
    // 0x8018A278: nop

L_8018A27C:
    // 0x8018A27C: addiu       $a0, $a0, -0x8D4
    ctx->r4 = ADD32(ctx->r4, -0X8D4);
    // 0x8018A280: jal         0x800BA808
    // 0x8018A284: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_65;
    // 0x8018A284: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_65:
L_8018A288:
    // 0x8018A288: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018A28C: b           L_8018A350
    // 0x8018A290: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_8018A350;
    // 0x8018A290: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018A294:
    // 0x8018A294: lw          $v0, 0x78BC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78BC);
    // 0x8018A298: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018A29C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018A2A0: beq         $v0, $at, L_8018A2B8
    if (ctx->r2 == ctx->r1) {
        // 0x8018A2A4: addiu       $a0, $a0, 0x4AE0
        ctx->r4 = ADD32(ctx->r4, 0X4AE0);
            goto L_8018A2B8;
    }
    // 0x8018A2A4: addiu       $a0, $a0, 0x4AE0
    ctx->r4 = ADD32(ctx->r4, 0X4AE0);
    // 0x8018A2A8: beq         $v0, $zero, L_8018A2C8
    if (ctx->r2 == 0) {
        // 0x8018A2AC: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018A2C8;
    }
    // 0x8018A2AC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018A2B0: b           L_8018A2DC
    // 0x8018A2B4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
        goto L_8018A2DC;
    // 0x8018A2B4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
L_8018A2B8:
    // 0x8018A2B8: jal         0x800BA808
    // 0x8018A2BC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_66;
    // 0x8018A2BC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_66:
    // 0x8018A2C0: b           L_8018A2E8
    // 0x8018A2C4: nop

        goto L_8018A2E8;
    // 0x8018A2C4: nop

L_8018A2C8:
    // 0x8018A2C8: addiu       $a0, $a0, 0x4C1C
    ctx->r4 = ADD32(ctx->r4, 0X4C1C);
    // 0x8018A2CC: jal         0x800BA808
    // 0x8018A2D0: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_67;
    // 0x8018A2D0: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_67:
    // 0x8018A2D4: b           L_8018A2E8
    // 0x8018A2D8: nop

        goto L_8018A2E8;
    // 0x8018A2D8: nop

L_8018A2DC:
    // 0x8018A2DC: addiu       $a0, $a0, -0x8AC
    ctx->r4 = ADD32(ctx->r4, -0X8AC);
    // 0x8018A2E0: jal         0x800BA808
    // 0x8018A2E4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_68;
    // 0x8018A2E4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_68:
L_8018A2E8:
    // 0x8018A2E8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018A2EC: b           L_8018A350
    // 0x8018A2F0: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_8018A350;
    // 0x8018A2F0: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018A2F4:
    // 0x8018A2F4: lw          $v0, 0x78B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78B4);
    // 0x8018A2F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018A2FC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018A300: beq         $v0, $at, L_8018A318
    if (ctx->r2 == ctx->r1) {
        // 0x8018A304: addiu       $a0, $a0, 0x4A94
        ctx->r4 = ADD32(ctx->r4, 0X4A94);
            goto L_8018A318;
    }
    // 0x8018A304: addiu       $a0, $a0, 0x4A94
    ctx->r4 = ADD32(ctx->r4, 0X4A94);
    // 0x8018A308: beq         $v0, $zero, L_8018A328
    if (ctx->r2 == 0) {
        // 0x8018A30C: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018A328;
    }
    // 0x8018A30C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018A310: b           L_8018A33C
    // 0x8018A314: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
        goto L_8018A33C;
    // 0x8018A314: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
L_8018A318:
    // 0x8018A318: jal         0x800BA808
    // 0x8018A31C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_69;
    // 0x8018A31C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_69:
    // 0x8018A320: b           L_8018A348
    // 0x8018A324: nop

        goto L_8018A348;
    // 0x8018A324: nop

L_8018A328:
    // 0x8018A328: addiu       $a0, $a0, 0x4B7C
    ctx->r4 = ADD32(ctx->r4, 0X4B7C);
    // 0x8018A32C: jal         0x800BA808
    // 0x8018A330: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_70;
    // 0x8018A330: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_70:
    // 0x8018A334: b           L_8018A348
    // 0x8018A338: nop

        goto L_8018A348;
    // 0x8018A338: nop

L_8018A33C:
    // 0x8018A33C: addiu       $a0, $a0, -0x880
    ctx->r4 = ADD32(ctx->r4, -0X880);
    // 0x8018A340: jal         0x800BA808
    // 0x8018A344: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_71;
    // 0x8018A344: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_71:
L_8018A348:
    // 0x8018A348: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018A34C: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018A350:
    // 0x8018A350: slti        $at, $v1, 0x470
    ctx->r1 = SIGNED(ctx->r3) < 0X470 ? 1 : 0;
L_8018A354:
    // 0x8018A354: beq         $at, $zero, L_8018A38C
    if (ctx->r1 == 0) {
        // 0x8018A358: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_8018A38C;
    }
    // 0x8018A358: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018A35C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018A360: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018A364: lui         $a1, 0x3F0C
    ctx->r5 = S32(0X3F0C << 16);
    // 0x8018A368: lui         $a3, 0x3CA3
    ctx->r7 = S32(0X3CA3 << 16);
    // 0x8018A36C: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8018A370: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8018A374: addiu       $a0, $a0, 0x7A54
    ctx->r4 = ADD32(ctx->r4, 0X7A54);
    // 0x8018A378: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8018A37C: jal         0x8009BC2C
    // 0x8018A380: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_72;
    // 0x8018A380: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_72:
    // 0x8018A384: b           L_8018A478
    // 0x8018A388: nop

        goto L_8018A478;
    // 0x8018A388: nop

L_8018A38C:
    // 0x8018A38C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018A390: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A394: lwc1        $f0, -0x7B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7B0);
    // 0x8018A398: addiu       $v1, $v1, -0x7BD4
    ctx->r3 = ADD32(ctx->r3, -0X7BD4);
    // 0x8018A39C: addiu       $v0, $v0, -0x7BD0
    ctx->r2 = ADD32(ctx->r2, -0X7BD0);
    // 0x8018A3A0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018A3A4: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018A3A8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018A3AC: add.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8018A3B0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018A3B4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018A3B8: add.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8018A3BC: lui         $a3, 0x3CA3
    ctx->r7 = S32(0X3CA3 << 16);
    // 0x8018A3C0: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8018A3C4: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8018A3C8: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x8018A3CC: addiu       $a0, $a0, 0x7A54
    ctx->r4 = ADD32(ctx->r4, 0X7A54);
    // 0x8018A3D0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8018A3D4: jal         0x8009BC2C
    // 0x8018A3D8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_73;
    // 0x8018A3D8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_73:
    // 0x8018A3DC: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018A3E0: lw          $t7, 0x7A80($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7A80);
    // 0x8018A3E4: addiu       $at, $zero, 0x4C0
    ctx->r1 = ADD32(0, 0X4C0);
    // 0x8018A3E8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018A3EC: bne         $t7, $at, L_8018A478
    if (ctx->r15 != ctx->r1) {
        // 0x8018A3F0: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_8018A478;
    }
    // 0x8018A3F0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018A3F4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A3F8: lwc1        $f0, -0x7AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7AC);
    // 0x8018A3FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018A400: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018A404: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8018A408: addiu       $t9, $zero, 0x3E8
    ctx->r25 = ADD32(0, 0X3E8);
    // 0x8018A40C: sw          $t8, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r24;
    // 0x8018A410: sw          $t9, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r25;
    // 0x8018A414: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A418: swc1        $f16, 0x7A58($at)
    MEM_W(0X7A58, ctx->r1) = ctx->f16.u32l;
    // 0x8018A41C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A420: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8018A424: swc1        $f0, 0x46B4($at)
    MEM_W(0X46B4, ctx->r1) = ctx->f0.u32l;
    // 0x8018A428: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A42C: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8018A430: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8018A434: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8018A438: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8018A43C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018A440: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    // 0x8018A444: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018A448: jal         0x80019218
    // 0x8018A44C: swc1        $f0, 0x43C0($at)
    MEM_W(0X43C0, ctx->r1) = ctx->f0.u32l;
    Audio_PlaySfx(rdram, ctx);
        goto after_74;
    // 0x8018A44C: swc1        $f0, 0x43C0($at)
    MEM_W(0X43C0, ctx->r1) = ctx->f0.u32l;
    after_74:
    // 0x8018A450: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018A454: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018A458: lui         $a0, 0x1032
    ctx->r4 = S32(0X1032 << 16);
    // 0x8018A45C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    // 0x8018A460: swc1        $f0, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f0.u32l;
    // 0x8018A464: jal         0x800182F4
    // 0x8018A468: swc1        $f0, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f0.u32l;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_75;
    // 0x8018A468: swc1        $f0, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f0.u32l;
    after_75:
    // 0x8018A46C: lui         $a0, 0x1132
    ctx->r4 = S32(0X1132 << 16);
    // 0x8018A470: jal         0x800182F4
    // 0x8018A474: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_76;
    // 0x8018A474: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_76:
L_8018A478:
    // 0x8018A478: b           L_8018B8C8
    // 0x8018A47C: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
        goto L_8018B8C8;
    // 0x8018A47C: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
L_8018A480:
    // 0x8018A480: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018A484: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018A488: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A48C: lwc1        $f0, -0x7A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7A8);
    // 0x8018A490: addiu       $v1, $v1, -0x7BD4
    ctx->r3 = ADD32(ctx->r3, -0X7BD4);
    // 0x8018A494: addiu       $v0, $v0, -0x7BD0
    ctx->r2 = ADD32(ctx->r2, -0X7BD0);
    // 0x8018A498: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018A49C: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018A4A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018A4A4: add.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8018A4A8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018A4AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A4B0: add.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8018A4B4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8018A4B8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018A4BC: addiu       $a0, $a0, 0x7A48
    ctx->r4 = ADD32(ctx->r4, 0X7A48);
    // 0x8018A4C0: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x8018A4C4: lwc1        $f8, 0xD0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x8018A4C8: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8018A4CC: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018A4D0: add.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8018A4D4: swc1        $f16, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f16.u32l;
    // 0x8018A4D8: lwc1        $f6, 0xD0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x8018A4DC: lwc1        $f4, -0x7A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7A4);
    // 0x8018A4E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A4E4: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8018A4E8: swc1        $f10, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f10.u32l;
    // 0x8018A4EC: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8018A4F0: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8018A4F4: swc1        $f16, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f16.u32l;
    // 0x8018A4F8: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8018A4FC: lwc1        $f4, -0x7A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7A0);
    // 0x8018A500: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8018A504: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018A508: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8018A50C: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x8018A510: swc1        $f18, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f18.u32l;
    // 0x8018A514: lw          $t7, 0x78B4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78B4);
    // 0x8018A518: blez        $t7, L_8018A5D8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8018A51C: nop
    
            goto L_8018A5D8;
    }
    // 0x8018A51C: nop

    // 0x8018A520: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
    // 0x8018A524: addiu       $at, $zero, 0x3D4
    ctx->r1 = ADD32(0, 0X3D4);
    // 0x8018A528: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018A52C: bne         $v0, $at, L_8018A588
    if (ctx->r2 != ctx->r1) {
        // 0x8018A530: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_8018A588;
    }
    // 0x8018A530: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018A534: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8018A538: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8018A53C: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8018A540: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8018A544: addiu       $a1, $a1, 0x49BC
    ctx->r5 = ADD32(ctx->r5, 0X49BC);
    // 0x8018A548: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8018A54C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8018A550: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018A554: jal         0x80019218
    // 0x8018A558: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_77;
    // 0x8018A558: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_77:
    // 0x8018A55C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018A560: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018A564: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A568: swc1        $f8, 0x49A8($at)
    MEM_W(0X49A8, ctx->r1) = ctx->f8.u32l;
    // 0x8018A56C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018A570: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018A574: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A578: swc1        $f16, 0x4A44($at)
    MEM_W(0X4A44, ctx->r1) = ctx->f16.u32l;
    // 0x8018A57C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018A580: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018A584: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
L_8018A588:
    // 0x8018A588: slti        $at, $v0, 0x3D4
    ctx->r1 = SIGNED(ctx->r2) < 0X3D4 ? 1 : 0;
    // 0x8018A58C: beq         $at, $zero, L_8018A5D8
    if (ctx->r1 == 0) {
        // 0x8018A590: lui         $at, 0x8016
        ctx->r1 = S32(0X8016 << 16);
            goto L_8018A5D8;
    }
    // 0x8018A590: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A594: lwc1        $f0, 0x49AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X49AC);
    // 0x8018A598: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A59C: lwc1        $f6, -0x79C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X79C);
    // 0x8018A5A0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8018A5A4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A5A8: lwc1        $f4, 0x49A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X49A8);
    // 0x8018A5AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A5B0: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8018A5B4: lwc1        $f10, -0x798($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X798);
    // 0x8018A5B8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A5BC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8018A5C0: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8018A5C4: swc1        $f18, 0x49A8($at)
    MEM_W(0X49A8, ctx->r1) = ctx->f18.u32l;
    // 0x8018A5C8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A5CC: sw          $t9, 0x4938($at)
    MEM_W(0X4938, ctx->r1) = ctx->r25;
    // 0x8018A5D0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A5D4: swc1        $f0, 0x49AC($at)
    MEM_W(0X49AC, ctx->r1) = ctx->f0.u32l;
L_8018A5D8:
    // 0x8018A5D8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018A5DC: lw          $t6, 0x78BC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78BC);
    // 0x8018A5E0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018A5E4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018A5E8: blez        $t6, L_8018A654
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8018A5EC: lw          $v0, 0x1F8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F8);
            goto L_8018A654;
    }
    // 0x8018A5EC: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
    // 0x8018A5F0: addiu       $at, $zero, 0x3C0
    ctx->r1 = ADD32(0, 0X3C0);
    // 0x8018A5F4: bne         $v0, $at, L_8018A654
    if (ctx->r2 != ctx->r1) {
        // 0x8018A5F8: lui         $a0, 0x900
        ctx->r4 = S32(0X900 << 16);
            goto L_8018A654;
    }
    // 0x8018A5F8: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8018A5FC: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8018A600: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8018A604: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8018A608: addiu       $a1, $a1, 0x46C8
    ctx->r5 = ADD32(ctx->r5, 0X46C8);
    // 0x8018A60C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018A610: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8018A614: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018A618: jal         0x80019218
    // 0x8018A61C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_78;
    // 0x8018A61C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_78:
    // 0x8018A620: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018A624: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018A628: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A62C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018A630: swc1        $f8, 0x46B4($at)
    MEM_W(0X46B4, ctx->r1) = ctx->f8.u32l;
    // 0x8018A634: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018A638: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018A63C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A640: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018A644: swc1        $f16, 0x4750($at)
    MEM_W(0X4750, ctx->r1) = ctx->f16.u32l;
    // 0x8018A648: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018A64C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018A650: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
L_8018A654:
    // 0x8018A654: slti        $at, $v0, 0x3C0
    ctx->r1 = SIGNED(ctx->r2) < 0X3C0 ? 1 : 0;
    // 0x8018A658: beq         $at, $zero, L_8018A6B0
    if (ctx->r1 == 0) {
        // 0x8018A65C: lui         $t9, 0x8017
        ctx->r25 = S32(0X8017 << 16);
            goto L_8018A6B0;
    }
    // 0x8018A65C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8018A660: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A664: lwc1        $f6, 0x46B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X46B8);
    // 0x8018A668: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8018A66C: add.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8018A670: swc1        $f4, 0x46B8($at)
    MEM_W(0X46B8, ctx->r1) = ctx->f4.u32l;
    // 0x8018A674: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A678: lwc1        $f10, -0x794($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X794);
    // 0x8018A67C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A680: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8018A684: swc1        $f18, 0x46B8($at)
    MEM_W(0X46B8, ctx->r1) = ctx->f18.u32l;
    // 0x8018A688: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A68C: lwc1        $f8, 0x46B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X46B4);
    // 0x8018A690: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A694: lwc1        $f16, -0x790($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X790);
    // 0x8018A698: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A69C: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8018A6A0: swc1        $f6, 0x46B4($at)
    MEM_W(0X46B4, ctx->r1) = ctx->f6.u32l;
    // 0x8018A6A4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A6A8: sw          $t8, 0x4644($at)
    MEM_W(0X4644, ctx->r1) = ctx->r24;
    // 0x8018A6AC: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
L_8018A6B0:
    // 0x8018A6B0: lw          $t9, 0x78B8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78B8);
    // 0x8018A6B4: addiu       $at, $zero, 0x3AC
    ctx->r1 = ADD32(0, 0X3AC);
    // 0x8018A6B8: blezl       $t9, L_8018A774
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8018A6BC: addiu       $at, $zero, 0x38E
        ctx->r1 = ADD32(0, 0X38E);
            goto L_8018A774;
    }
    goto skip_8;
    // 0x8018A6BC: addiu       $at, $zero, 0x38E
    ctx->r1 = ADD32(0, 0X38E);
    skip_8:
    // 0x8018A6C0: bne         $v0, $at, L_8018A718
    if (ctx->r2 != ctx->r1) {
        // 0x8018A6C4: lui         $a0, 0x900
        ctx->r4 = S32(0X900 << 16);
            goto L_8018A718;
    }
    // 0x8018A6C4: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8018A6C8: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8018A6CC: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8018A6D0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8018A6D4: addiu       $a1, $a1, 0x43D4
    ctx->r5 = ADD32(ctx->r5, 0X43D4);
    // 0x8018A6D8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8018A6DC: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8018A6E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018A6E4: jal         0x80019218
    // 0x8018A6E8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_79;
    // 0x8018A6E8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_79:
    // 0x8018A6EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018A6F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018A6F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A6F8: swc1        $f4, 0x43C0($at)
    MEM_W(0X43C0, ctx->r1) = ctx->f4.u32l;
    // 0x8018A6FC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018A700: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018A704: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A708: swc1        $f10, 0x445C($at)
    MEM_W(0X445C, ctx->r1) = ctx->f10.u32l;
    // 0x8018A70C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018A710: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018A714: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
L_8018A718:
    // 0x8018A718: slti        $at, $v0, 0x3AC
    ctx->r1 = SIGNED(ctx->r2) < 0X3AC ? 1 : 0;
    // 0x8018A71C: beq         $at, $zero, L_8018A770
    if (ctx->r1 == 0) {
        // 0x8018A720: lui         $at, 0x8016
        ctx->r1 = S32(0X8016 << 16);
            goto L_8018A770;
    }
    // 0x8018A720: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A724: lwc1        $f18, 0x43C4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X43C4);
    // 0x8018A728: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8018A72C: add.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8018A730: swc1        $f8, 0x43C4($at)
    MEM_W(0X43C4, ctx->r1) = ctx->f8.u32l;
    // 0x8018A734: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A738: lwc1        $f16, -0x78C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X78C);
    // 0x8018A73C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A740: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8018A744: swc1        $f6, 0x43C4($at)
    MEM_W(0X43C4, ctx->r1) = ctx->f6.u32l;
    // 0x8018A748: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A74C: lwc1        $f4, 0x43C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X43C0);
    // 0x8018A750: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A754: lwc1        $f10, -0x788($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X788);
    // 0x8018A758: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A75C: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8018A760: swc1        $f18, 0x43C0($at)
    MEM_W(0X43C0, ctx->r1) = ctx->f18.u32l;
    // 0x8018A764: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A768: sw          $t7, 0x4350($at)
    MEM_W(0X4350, ctx->r1) = ctx->r15;
    // 0x8018A76C: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
L_8018A770:
    // 0x8018A770: addiu       $at, $zero, 0x38E
    ctx->r1 = ADD32(0, 0X38E);
L_8018A774:
    // 0x8018A774: bne         $v0, $at, L_8018A798
    if (ctx->r2 != ctx->r1) {
        // 0x8018A778: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_8018A798;
    }
    // 0x8018A778: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8018A77C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A780: swc1        $f2, 0x40CC($at)
    MEM_W(0X40CC, ctx->r1) = ctx->f2.u32l;
    // 0x8018A784: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8018A788: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018A78C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A790: swc1        $f8, 0x3FF0($at)
    MEM_W(0X3FF0, ctx->r1) = ctx->f8.u32l;
    // 0x8018A794: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
L_8018A798:
    // 0x8018A798: slti        $at, $v0, 0x38E
    ctx->r1 = SIGNED(ctx->r2) < 0X38E ? 1 : 0;
    // 0x8018A79C: beq         $at, $zero, L_8018A7FC
    if (ctx->r1 == 0) {
        // 0x8018A7A0: addiu       $t9, $zero, 0x6
        ctx->r25 = ADD32(0, 0X6);
            goto L_8018A7FC;
    }
    // 0x8018A7A0: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8018A7A4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A7A8: lwc1        $f0, 0x40D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X40D0);
    // 0x8018A7AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A7B0: lwc1        $f16, -0x784($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X784);
    // 0x8018A7B4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8018A7B8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A7BC: lwc1        $f6, 0x40CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X40CC);
    // 0x8018A7C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A7C4: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8018A7C8: lwc1        $f4, -0x780($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X780);
    // 0x8018A7CC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A7D0: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8018A7D4: swc1        $f10, 0x40CC($at)
    MEM_W(0X40CC, ctx->r1) = ctx->f10.u32l;
    // 0x8018A7D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A7DC: lwc1        $f18, 0x3FF0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3FF0);
    // 0x8018A7E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A7E4: lwc1        $f8, -0x77C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X77C);
    // 0x8018A7E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A7EC: mul.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8018A7F0: swc1        $f16, 0x3FF0($at)
    MEM_W(0X3FF0, ctx->r1) = ctx->f16.u32l;
    // 0x8018A7F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A7F8: swc1        $f0, 0x40D0($at)
    MEM_W(0X40D0, ctx->r1) = ctx->f0.u32l;
L_8018A7FC:
    // 0x8018A7FC: lw          $t8, 0x7A80($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7A80);
    // 0x8018A800: addiu       $at, $zero, 0x566
    ctx->r1 = ADD32(0, 0X566);
    // 0x8018A804: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8018A808: bne         $t8, $at, L_8018A898
    if (ctx->r24 != ctx->r1) {
        // 0x8018A80C: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_8018A898;
    }
    // 0x8018A80C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8018A810: sw          $t9, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r25;
    // 0x8018A814: sw          $zero, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = 0;
    // 0x8018A818: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A81C: jal         0x8001DBD0
    // 0x8018A820: sw          $t6, -0x7C84($at)
    MEM_W(-0X7C84, ctx->r1) = ctx->r14;
    Audio_FadeOutAll(rdram, ctx);
        goto after_80;
    // 0x8018A820: sw          $t6, -0x7C84($at)
    MEM_W(-0X7C84, ctx->r1) = ctx->r14;
    after_80:
    // 0x8018A824: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018A828: lw          $t7, 0x7CD0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7CD0);
    // 0x8018A82C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8018A830: lw          $t8, 0x7CD4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7CD4);
    // 0x8018A834: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A838: sw          $t7, 0x7CF0($at)
    MEM_W(0X7CF0, ctx->r1) = ctx->r15;
    // 0x8018A83C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A840: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8018A844: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018A848: addiu       $t6, $t6, 0x7CD0
    ctx->r14 = ADD32(ctx->r14, 0X7CD0);
    // 0x8018A84C: sll         $a0, $a2, 2
    ctx->r4 = S32(ctx->r6 << 2);
    // 0x8018A850: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8018A854: sw          $t8, 0x7CF4($at)
    MEM_W(0X7CF4, ctx->r1) = ctx->r24;
    // 0x8018A858: addiu       $t9, $t9, 0x7CF0
    ctx->r25 = ADD32(ctx->r25, 0X7CF0);
    // 0x8018A85C: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x8018A860: addu        $v0, $a0, $t9
    ctx->r2 = ADD32(ctx->r4, ctx->r25);
    // 0x8018A864: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x8018A868: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x8018A86C: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x8018A870: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8018A874: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x8018A878: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x8018A87C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8018A880: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x8018A884: jal         0x800A3F50
    // 0x8018A888: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    Play_CheckMedalStatus(rdram, ctx);
        goto after_81;
    // 0x8018A888: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    after_81:
    // 0x8018A88C: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8018A890: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8018A894: sb          $t7, 0x318E($at)
    MEM_B(0X318E, ctx->r1) = ctx->r15;
L_8018A898:
    // 0x8018A898: b           L_8018B8C8
    // 0x8018A89C: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
        goto L_8018B8C8;
    // 0x8018A89C: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
L_8018A8A0:
    // 0x8018A8A0: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8018A8A4: lw          $t8, 0x78B4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78B4);
    // 0x8018A8A8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018A8AC: addiu       $a0, $a0, 0x48BC
    ctx->r4 = ADD32(ctx->r4, 0X48BC);
    // 0x8018A8B0: blez        $t8, L_8018A91C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8018A8B4: nop
    
            goto L_8018A91C;
    }
    // 0x8018A8B4: nop

    // 0x8018A8B8: jal         0x801890EC
    // 0x8018A8BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Fortuna_LevelComplete_CsSpawnTeam(rdram, ctx);
        goto after_82;
    // 0x8018A8BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_82:
    // 0x8018A8C0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8018A8C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018A8C8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018A8CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018A8D0: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8018A8D4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A8D8: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8018A8DC: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8018A8E0: swc1        $f18, 0x48C0($at)
    MEM_W(0X48C0, ctx->r1) = ctx->f18.u32l;
    // 0x8018A8E4: lwc1        $f8, 0x78($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8018A8E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A8EC: add.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018A8F0: swc1        $f16, 0x48C4($at)
    MEM_W(0X48C4, ctx->r1) = ctx->f16.u32l;
    // 0x8018A8F4: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8018A8F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018A8FC: lwc1        $f6, 0x138($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8018A900: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A904: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8018A908: swc1        $f10, 0x48C8($at)
    MEM_W(0X48C8, ctx->r1) = ctx->f10.u32l;
    // 0x8018A90C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8018A910: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018A914: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A918: swc1        $f18, 0x48D4($at)
    MEM_W(0X48D4, ctx->r1) = ctx->f18.u32l;
L_8018A91C:
    // 0x8018A91C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8018A920: lw          $t9, 0x78B8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78B8);
    // 0x8018A924: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018A928: addiu       $a0, $a0, 0x42D4
    ctx->r4 = ADD32(ctx->r4, 0X42D4);
    // 0x8018A92C: blez        $t9, L_8018A998
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8018A930: nop
    
            goto L_8018A998;
    }
    // 0x8018A930: nop

    // 0x8018A934: jal         0x801890EC
    // 0x8018A938: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Fortuna_LevelComplete_CsSpawnTeam(rdram, ctx);
        goto after_83;
    // 0x8018A938: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_83:
    // 0x8018A93C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8018A940: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018A944: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018A948: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018A94C: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8018A950: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A954: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8018A958: add.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8018A95C: swc1        $f4, 0x42D8($at)
    MEM_W(0X42D8, ctx->r1) = ctx->f4.u32l;
    // 0x8018A960: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8018A964: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A968: add.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8018A96C: swc1        $f18, 0x42DC($at)
    MEM_W(0X42DC, ctx->r1) = ctx->f18.u32l;
    // 0x8018A970: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8018A974: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018A978: lwc1        $f8, 0x138($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8018A97C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A980: sub.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8018A984: swc1        $f6, 0x42E0($at)
    MEM_W(0X42E0, ctx->r1) = ctx->f6.u32l;
    // 0x8018A988: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x8018A98C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018A990: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A994: swc1        $f4, 0x42EC($at)
    MEM_W(0X42EC, ctx->r1) = ctx->f4.u32l;
L_8018A998:
    // 0x8018A998: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018A99C: lw          $t6, 0x78BC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78BC);
    // 0x8018A9A0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018A9A4: addiu       $a0, $a0, 0x45C8
    ctx->r4 = ADD32(ctx->r4, 0X45C8);
    // 0x8018A9A8: blez        $t6, L_8018AA00
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8018A9AC: nop
    
            goto L_8018AA00;
    }
    // 0x8018A9AC: nop

    // 0x8018A9B0: jal         0x801890EC
    // 0x8018A9B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Fortuna_LevelComplete_CsSpawnTeam(rdram, ctx);
        goto after_84;
    // 0x8018A9B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_84:
    // 0x8018A9B8: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8018A9BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018A9C0: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8018A9C4: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8018A9C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018A9CC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A9D0: swc1        $f10, 0x45CC($at)
    MEM_W(0X45CC, ctx->r1) = ctx->f10.u32l;
    // 0x8018A9D4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018A9D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018A9DC: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8018A9E0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A9E4: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8018A9E8: add.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8018A9EC: swc1        $f6, 0x45D0($at)
    MEM_W(0X45D0, ctx->r1) = ctx->f6.u32l;
    // 0x8018A9F0: lwc1        $f4, 0x138($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8018A9F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A9F8: sub.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x8018A9FC: swc1        $f10, 0x45D4($at)
    MEM_W(0X45D4, ctx->r1) = ctx->f10.u32l;
L_8018AA00:
    // 0x8018AA00: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018AA04: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x8018AA08: jal         0x801890EC
    // 0x8018AA0C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    Fortuna_LevelComplete_CsSpawnTeam(rdram, ctx);
        goto after_85;
    // 0x8018AA0C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_85:
    // 0x8018AA10: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8018AA14: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018AA18: lwc1        $f18, 0x7C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018AA1C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018AA20: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018AA24: add.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8018AA28: addiu       $t8, $zero, 0x15
    ctx->r24 = ADD32(0, 0X15);
    // 0x8018AA2C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018AA30: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018AA34: swc1        $f8, 0x3FEC($at)
    MEM_W(0X3FEC, ctx->r1) = ctx->f8.u32l;
    // 0x8018AA38: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018AA3C: swc1        $f20, 0x40D0($at)
    MEM_W(0X40D0, ctx->r1) = ctx->f20.u32l;
    // 0x8018AA40: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018AA44: sb          $t7, 0x401C($at)
    MEM_B(0X401C, ctx->r1) = ctx->r15;
    // 0x8018AA48: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AA4C: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x8018AA50: sw          $t8, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r24;
    // 0x8018AA54: sw          $t9, 0x234($s0)
    MEM_W(0X234, ctx->r16) = ctx->r25;
    // 0x8018AA58: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AA5C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018AA60: addiu       $v1, $v1, 0x7A6C
    ctx->r3 = ADD32(ctx->r3, 0X7A6C);
    // 0x8018AA64: swc1        $f20, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f20.u32l;
    // 0x8018AA68: addiu       $v0, $v0, 0x7A4C
    ctx->r2 = ADD32(ctx->r2, 0X7A4C);
L_8018AA6C:
    // 0x8018AA6C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8018AA70: swc1        $f20, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f20.u32l;
    // 0x8018AA74: swc1        $f20, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f20.u32l;
    // 0x8018AA78: swc1        $f20, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f20.u32l;
    // 0x8018AA7C: bne         $v0, $v1, L_8018AA6C
    if (ctx->r2 != ctx->r3) {
        // 0x8018AA80: swc1        $f20, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = ctx->f20.u32l;
            goto L_8018AA6C;
    }
    // 0x8018AA80: swc1        $f20, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f20.u32l;
    // 0x8018AA84: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018AA88: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018AA8C: lui         $at, 0x42BC
    ctx->r1 = S32(0X42BC << 16);
    // 0x8018AA90: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018AA94: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AA98: swc1        $f16, 0x7A5C($at)
    MEM_W(0X7A5C, ctx->r1) = ctx->f16.u32l;
    // 0x8018AA9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AAA0: swc1        $f20, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f20.u32l;
    // 0x8018AAA4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AAA8: swc1        $f0, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f0.u32l;
    // 0x8018AAAC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AAB0: swc1        $f20, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f20.u32l;
L_8018AAB4:
    // 0x8018AAB4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018AAB8: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8018AABC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018AAC0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018AAC4: slti        $at, $v1, 0x1E
    ctx->r1 = SIGNED(ctx->r3) < 0X1E ? 1 : 0;
    // 0x8018AAC8: beq         $at, $zero, L_8018AAD8
    if (ctx->r1 == 0) {
        // 0x8018AACC: lui         $t6, 0x8018
        ctx->r14 = S32(0X8018 << 16);
            goto L_8018AAD8;
    }
    // 0x8018AACC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8018AAD0: b           L_8018B8C8
    // 0x8018AAD4: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
        goto L_8018B8C8;
    // 0x8018AAD4: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
L_8018AAD8:
    // 0x8018AAD8: lw          $t6, -0x7CC0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CC0);
    // 0x8018AADC: beq         $t6, $zero, L_8018AAF4
    if (ctx->r14 == 0) {
        // 0x8018AAE0: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_8018AAF4;
    }
    // 0x8018AAE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AAE4: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x8018AAE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AAEC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018AAF0: sw          $t7, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r15;
L_8018AAF4:
    // 0x8018AAF4: addiu       $at, $zero, 0x8C
    ctx->r1 = ADD32(0, 0X8C);
    // 0x8018AAF8: bnel        $v1, $at, L_8018AB30
    if (ctx->r3 != ctx->r1) {
        // 0x8018AAFC: slti        $at, $v1, 0x8D
        ctx->r1 = SIGNED(ctx->r3) < 0X8D ? 1 : 0;
            goto L_8018AB30;
    }
    goto skip_9;
    // 0x8018AAFC: slti        $at, $v1, 0x8D
    ctx->r1 = SIGNED(ctx->r3) < 0X8D ? 1 : 0;
    skip_9:
    // 0x8018AB00: swc1        $f0, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f0.u32l;
    // 0x8018AB04: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018AB08: swc1        $f0, 0x49AC($at)
    MEM_W(0X49AC, ctx->r1) = ctx->f0.u32l;
    // 0x8018AB0C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018AB10: swc1        $f0, 0x43C4($at)
    MEM_W(0X43C4, ctx->r1) = ctx->f0.u32l;
    // 0x8018AB14: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018AB18: swc1        $f0, 0x46B8($at)
    MEM_W(0X46B8, ctx->r1) = ctx->f0.u32l;
    // 0x8018AB1C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018AB20: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018AB24: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8018AB28: swc1        $f0, 0x40D0($at)
    MEM_W(0X40D0, ctx->r1) = ctx->f0.u32l;
    // 0x8018AB2C: slti        $at, $v1, 0x8D
    ctx->r1 = SIGNED(ctx->r3) < 0X8D ? 1 : 0;
L_8018AB30:
    // 0x8018AB30: bne         $at, $zero, L_8018ABB8
    if (ctx->r1 != 0) {
        // 0x8018AB34: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_8018ABB8;
    }
    // 0x8018AB34: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018AB38: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018AB3C: lwc1        $f6, -0x778($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X778);
    // 0x8018AB40: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018AB44: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8018AB48: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x8018AB4C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8018AB50: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8018AB54: addiu       $a0, $a0, 0x48D4
    ctx->r4 = ADD32(ctx->r4, 0X48D4);
    // 0x8018AB58: jal         0x8009BC2C
    // 0x8018AB5C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_86;
    // 0x8018AB5C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_86:
    // 0x8018AB60: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018AB64: lwc1        $f4, -0x774($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X774);
    // 0x8018AB68: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018AB6C: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8018AB70: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8018AB74: addiu       $a0, $a0, 0x48C0
    ctx->r4 = ADD32(ctx->r4, 0X48C0);
    // 0x8018AB78: lui         $a1, 0xC2C8
    ctx->r5 = S32(0XC2C8 << 16);
    // 0x8018AB7C: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018AB80: jal         0x8009BC2C
    // 0x8018AB84: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_87;
    // 0x8018AB84: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_87:
    // 0x8018AB88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018AB8C: lwc1        $f10, -0x770($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X770);
    // 0x8018AB90: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018AB94: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8018AB98: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8018AB9C: addiu       $a0, $a0, 0x48C4
    ctx->r4 = ADD32(ctx->r4, 0X48C4);
    // 0x8018ABA0: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x8018ABA4: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018ABA8: jal         0x8009BC2C
    // 0x8018ABAC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_88;
    // 0x8018ABAC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_88:
    // 0x8018ABB0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018ABB4: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018ABB8:
    // 0x8018ABB8: slti        $at, $v1, 0xB5
    ctx->r1 = SIGNED(ctx->r3) < 0XB5 ? 1 : 0;
    // 0x8018ABBC: bne         $at, $zero, L_8018AC44
    if (ctx->r1 != 0) {
        // 0x8018ABC0: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_8018AC44;
    }
    // 0x8018ABC0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018ABC4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018ABC8: lwc1        $f18, -0x76C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X76C);
    // 0x8018ABCC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018ABD0: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8018ABD4: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x8018ABD8: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8018ABDC: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8018ABE0: addiu       $a0, $a0, 0x42EC
    ctx->r4 = ADD32(ctx->r4, 0X42EC);
    // 0x8018ABE4: jal         0x8009BC2C
    // 0x8018ABE8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_89;
    // 0x8018ABE8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_89:
    // 0x8018ABEC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018ABF0: lwc1        $f8, -0x768($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X768);
    // 0x8018ABF4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018ABF8: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8018ABFC: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8018AC00: addiu       $a0, $a0, 0x42D8
    ctx->r4 = ADD32(ctx->r4, 0X42D8);
    // 0x8018AC04: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x8018AC08: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018AC0C: jal         0x8009BC2C
    // 0x8018AC10: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_90;
    // 0x8018AC10: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_90:
    // 0x8018AC14: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018AC18: lwc1        $f16, -0x764($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X764);
    // 0x8018AC1C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018AC20: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8018AC24: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8018AC28: addiu       $a0, $a0, 0x42DC
    ctx->r4 = ADD32(ctx->r4, 0X42DC);
    // 0x8018AC2C: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x8018AC30: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018AC34: jal         0x8009BC2C
    // 0x8018AC38: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_91;
    // 0x8018AC38: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_91:
    // 0x8018AC3C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018AC40: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018AC44:
    // 0x8018AC44: slti        $at, $v1, 0xDD
    ctx->r1 = SIGNED(ctx->r3) < 0XDD ? 1 : 0;
    // 0x8018AC48: bne         $at, $zero, L_8018AC7C
    if (ctx->r1 != 0) {
        // 0x8018AC4C: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_8018AC7C;
    }
    // 0x8018AC4C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018AC50: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018AC54: lwc1        $f6, -0x760($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X760);
    // 0x8018AC58: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8018AC5C: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8018AC60: addiu       $a0, $a0, 0x45D0
    ctx->r4 = ADD32(ctx->r4, 0X45D0);
    // 0x8018AC64: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x8018AC68: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018AC6C: jal         0x8009BC2C
    // 0x8018AC70: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_92;
    // 0x8018AC70: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_92:
    // 0x8018AC74: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018AC78: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018AC7C:
    // 0x8018AC7C: slti        $at, $v1, 0x155
    ctx->r1 = SIGNED(ctx->r3) < 0X155 ? 1 : 0;
    // 0x8018AC80: bne         $at, $zero, L_8018ACB0
    if (ctx->r1 != 0) {
        // 0x8018AC84: addiu       $a0, $s0, 0x78
        ctx->r4 = ADD32(ctx->r16, 0X78);
            goto L_8018ACB0;
    }
    // 0x8018AC84: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x8018AC88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018AC8C: lwc1        $f4, -0x75C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X75C);
    // 0x8018AC90: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8018AC94: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8018AC98: lui         $a1, 0xC120
    ctx->r5 = S32(0XC120 << 16);
    // 0x8018AC9C: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018ACA0: jal         0x8009BC2C
    // 0x8018ACA4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_93;
    // 0x8018ACA4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_93:
    // 0x8018ACA8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018ACAC: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018ACB0:
    // 0x8018ACB0: slti        $at, $v1, 0x213
    ctx->r1 = SIGNED(ctx->r3) < 0X213 ? 1 : 0;
    // 0x8018ACB4: bne         $at, $zero, L_8018AD44
    if (ctx->r1 != 0) {
        // 0x8018ACB8: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018AD44;
    }
    // 0x8018ACB8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018ACBC: addiu       $a0, $a0, 0x33C0
    ctx->r4 = ADD32(ctx->r4, 0X33C0);
    // 0x8018ACC0: jal         0x800BA808
    // 0x8018ACC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_94;
    // 0x8018ACC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_94:
    // 0x8018ACC8: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8018ACCC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018ACD0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018ACD4: addiu       $t8, $zero, 0x16
    ctx->r24 = ADD32(0, 0X16);
    // 0x8018ACD8: swc1        $f10, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f10.u32l;
    // 0x8018ACDC: swc1        $f20, 0x48D4($at)
    MEM_W(0X48D4, ctx->r1) = ctx->f20.u32l;
    // 0x8018ACE0: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8018ACE4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018ACE8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018ACEC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018ACF0: swc1        $f18, 0x48C0($at)
    MEM_W(0X48C0, ctx->r1) = ctx->f18.u32l;
    // 0x8018ACF4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8018ACF8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018ACFC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018AD00: swc1        $f8, 0x48C4($at)
    MEM_W(0X48C4, ctx->r1) = ctx->f8.u32l;
    // 0x8018AD04: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018AD08: swc1        $f20, 0x42EC($at)
    MEM_W(0X42EC, ctx->r1) = ctx->f20.u32l;
    // 0x8018AD0C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018AD10: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018AD14: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018AD18: swc1        $f16, 0x42D8($at)
    MEM_W(0X42D8, ctx->r1) = ctx->f16.u32l;
    // 0x8018AD1C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8018AD20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018AD24: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018AD28: swc1        $f6, 0x42DC($at)
    MEM_W(0X42DC, ctx->r1) = ctx->f6.u32l;
    // 0x8018AD2C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8018AD30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018AD34: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018AD38: swc1        $f4, 0x45D0($at)
    MEM_W(0X45D0, ctx->r1) = ctx->f4.u32l;
    // 0x8018AD3C: sw          $t8, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r24;
    // 0x8018AD40: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018AD44:
    // 0x8018AD44: addiu       $at, $zero, 0x8C
    ctx->r1 = ADD32(0, 0X8C);
    // 0x8018AD48: beq         $v1, $at, L_8018AD64
    if (ctx->r3 == ctx->r1) {
        // 0x8018AD4C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8018AD64;
    }
    // 0x8018AD4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018AD50: addiu       $at, $zero, 0x1C2
    ctx->r1 = ADD32(0, 0X1C2);
    // 0x8018AD54: beq         $v1, $at, L_8018AD7C
    if (ctx->r3 == ctx->r1) {
        // 0x8018AD58: addiu       $t9, $zero, 0x64
        ctx->r25 = ADD32(0, 0X64);
            goto L_8018AD7C;
    }
    // 0x8018AD58: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8018AD5C: b           L_8018AD84
    // 0x8018AD60: nop

        goto L_8018AD84;
    // 0x8018AD60: nop

L_8018AD64:
    // 0x8018AD64: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x8018AD68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018AD6C: jal         0x8001D444
    // 0x8018AD70: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_95;
    // 0x8018AD70: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_95:
    // 0x8018AD74: b           L_8018AD84
    // 0x8018AD78: nop

        goto L_8018AD84;
    // 0x8018AD78: nop

L_8018AD7C:
    // 0x8018AD7C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AD80: sw          $t9, 0x7840($at)
    MEM_W(0X7840, ctx->r1) = ctx->r25;
L_8018AD84:
    // 0x8018AD84: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018AD88: addiu       $v0, $v0, 0x7A48
    ctx->r2 = ADD32(ctx->r2, 0X7A48);
    // 0x8018AD8C: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8018AD90: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8018AD94: swc1        $f20, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f20.u32l;
    // 0x8018AD98: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AD9C: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    // 0x8018ADA0: swc1        $f18, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f18.u32l;
    // 0x8018ADA4: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018ADA8: lwc1        $f16, 0x7D20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8018ADAC: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x8018ADB0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018ADB4: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8018ADB8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018ADBC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018ADC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8018ADC4: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8018ADC8: jal         0x80005B00
    // 0x8018ADCC: nop

    Matrix_Translate(rdram, ctx);
        goto after_96;
    // 0x8018ADCC: nop

    after_96:
    // 0x8018ADD0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018ADD4: lwc1        $f4, 0x7A58($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7A58);
    // 0x8018ADD8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018ADDC: lwc1        $f10, -0x758($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X758);
    // 0x8018ADE0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018ADE4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018ADE8: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8018ADEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018ADF0: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x8018ADF4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018ADF8: jal         0x80005E90
    // 0x8018ADFC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_97;
    // 0x8018ADFC: nop

    after_97:
    // 0x8018AE00: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018AE04: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018AE08: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8018AE0C: jal         0x80006970
    // 0x8018AE10: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    Matrix_MultVec3f(rdram, ctx);
        goto after_98;
    // 0x8018AE10: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_98:
    // 0x8018AE14: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8018AE18: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018AE1C: addiu       $v0, $v0, 0x7978
    ctx->r2 = ADD32(ctx->r2, 0X7978);
    // 0x8018AE20: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x8018AE24: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018AE28: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018AE2C: addiu       $v1, $v1, 0x7980
    ctx->r3 = ADD32(ctx->r3, 0X7980);
    // 0x8018AE30: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x8018AE34: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8018AE38: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8018AE3C: addiu       $t0, $t0, 0x7988
    ctx->r8 = ADD32(ctx->r8, 0X7988);
    // 0x8018AE40: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8018AE44: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018AE48: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018AE4C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018AE50: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x8018AE54: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8018AE58: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018AE5C: lui         $a2, 0x3BA3
    ctx->r6 = S32(0X3BA3 << 16);
    // 0x8018AE60: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x8018AE64: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8018AE68: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018AE6C: addiu       $a0, $a0, 0x79B8
    ctx->r4 = ADD32(ctx->r4, 0X79B8);
    // 0x8018AE70: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    // 0x8018AE74: lwc1        $f16, -0x754($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X754);
    // 0x8018AE78: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018AE7C: jal         0x8009BC2C
    // 0x8018AE80: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_99;
    // 0x8018AE80: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_99:
    // 0x8018AE84: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8018AE88: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AE8C: lwc1        $f10, 0x7C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018AE90: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x8018AE94: lwc1        $f4, 0x79B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x8018AE98: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AE9C: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
    // 0x8018AEA0: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x8018AEA4: lwc1        $f18, 0x7D20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8018AEA8: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8018AEAC: b           L_8018B8C8
    // 0x8018AEB0: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
        goto L_8018B8C8;
    // 0x8018AEB0: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
L_8018AEB4:
    // 0x8018AEB4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018AEB8: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8018AEBC: slti        $at, $v1, 0x456
    ctx->r1 = SIGNED(ctx->r3) < 0X456 ? 1 : 0;
    // 0x8018AEC0: bne         $at, $zero, L_8018AF98
    if (ctx->r1 != 0) {
        // 0x8018AEC4: slti        $at, $v1, 0x4D8
        ctx->r1 = SIGNED(ctx->r3) < 0X4D8 ? 1 : 0;
            goto L_8018AF98;
    }
    // 0x8018AEC4: slti        $at, $v1, 0x4D8
    ctx->r1 = SIGNED(ctx->r3) < 0X4D8 ? 1 : 0;
    // 0x8018AEC8: beq         $at, $zero, L_8018AF98
    if (ctx->r1 == 0) {
        // 0x8018AECC: addiu       $a0, $s0, 0xD0
        ctx->r4 = ADD32(ctx->r16, 0XD0);
            goto L_8018AF98;
    }
    // 0x8018AECC: addiu       $a0, $s0, 0xD0
    ctx->r4 = ADD32(ctx->r16, 0XD0);
    // 0x8018AED0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018AED4: lwc1        $f16, -0x750($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X750);
    // 0x8018AED8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018AEDC: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8018AEE0: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018AEE4: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018AEE8: jal         0x8009BC2C
    // 0x8018AEEC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_100;
    // 0x8018AEEC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_100:
    // 0x8018AEF0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018AEF4: lwc1        $f6, -0x74C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X74C);
    // 0x8018AEF8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018AEFC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018AF00: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8018AF04: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018AF08: addiu       $a0, $a0, 0x49AC
    ctx->r4 = ADD32(ctx->r4, 0X49AC);
    // 0x8018AF0C: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018AF10: jal         0x8009BC2C
    // 0x8018AF14: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_101;
    // 0x8018AF14: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_101:
    // 0x8018AF18: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018AF1C: lwc1        $f4, -0x748($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X748);
    // 0x8018AF20: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018AF24: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018AF28: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8018AF2C: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018AF30: addiu       $a0, $a0, 0x43C4
    ctx->r4 = ADD32(ctx->r4, 0X43C4);
    // 0x8018AF34: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018AF38: jal         0x8009BC2C
    // 0x8018AF3C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_102;
    // 0x8018AF3C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_102:
    // 0x8018AF40: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018AF44: lwc1        $f10, -0x744($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X744);
    // 0x8018AF48: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018AF4C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018AF50: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8018AF54: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018AF58: addiu       $a0, $a0, 0x46B8
    ctx->r4 = ADD32(ctx->r4, 0X46B8);
    // 0x8018AF5C: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018AF60: jal         0x8009BC2C
    // 0x8018AF64: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_103;
    // 0x8018AF64: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_103:
    // 0x8018AF68: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018AF6C: lwc1        $f18, -0x740($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X740);
    // 0x8018AF70: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018AF74: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018AF78: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8018AF7C: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018AF80: addiu       $a0, $a0, 0x40D0
    ctx->r4 = ADD32(ctx->r4, 0X40D0);
    // 0x8018AF84: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018AF88: jal         0x8009BC2C
    // 0x8018AF8C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_104;
    // 0x8018AF8C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_104:
    // 0x8018AF90: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018AF94: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018AF98:
    // 0x8018AF98: addiu       $at, $zero, 0x4D7
    ctx->r1 = ADD32(0, 0X4D7);
    // 0x8018AF9C: bnel        $v1, $at, L_8018AFD4
    if (ctx->r3 != ctx->r1) {
        // 0x8018AFA0: slti        $at, $v1, 0x4D9
        ctx->r1 = SIGNED(ctx->r3) < 0X4D9 ? 1 : 0;
            goto L_8018AFD4;
    }
    goto skip_10;
    // 0x8018AFA0: slti        $at, $v1, 0x4D9
    ctx->r1 = SIGNED(ctx->r3) < 0X4D9 ? 1 : 0;
    skip_10:
    // 0x8018AFA4: swc1        $f20, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f20.u32l;
    // 0x8018AFA8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018AFAC: swc1        $f20, 0x49AC($at)
    MEM_W(0X49AC, ctx->r1) = ctx->f20.u32l;
    // 0x8018AFB0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018AFB4: swc1        $f20, 0x43C4($at)
    MEM_W(0X43C4, ctx->r1) = ctx->f20.u32l;
    // 0x8018AFB8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018AFBC: swc1        $f20, 0x46B8($at)
    MEM_W(0X46B8, ctx->r1) = ctx->f20.u32l;
    // 0x8018AFC0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018AFC4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018AFC8: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8018AFCC: swc1        $f20, 0x40D0($at)
    MEM_W(0X40D0, ctx->r1) = ctx->f20.u32l;
    // 0x8018AFD0: slti        $at, $v1, 0x4D9
    ctx->r1 = SIGNED(ctx->r3) < 0X4D9 ? 1 : 0;
L_8018AFD4:
    // 0x8018AFD4: bne         $at, $zero, L_8018B014
    if (ctx->r1 != 0) {
        // 0x8018AFD8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8018B014;
    }
    // 0x8018AFD8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8018AFDC: addiu       $at, $zero, 0x4EC
    ctx->r1 = ADD32(0, 0X4EC);
    // 0x8018AFE0: beq         $v0, $at, L_8018B1E4
    if (ctx->r2 == ctx->r1) {
        // 0x8018AFE4: lui         $t6, 0x8017
        ctx->r14 = S32(0X8017 << 16);
            goto L_8018B1E4;
    }
    // 0x8018AFE4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018AFE8: addiu       $at, $zero, 0x500
    ctx->r1 = ADD32(0, 0X500);
    // 0x8018AFEC: beq         $v0, $at, L_8018B244
    if (ctx->r2 == ctx->r1) {
        // 0x8018AFF0: lui         $t9, 0x8017
        ctx->r25 = S32(0X8017 << 16);
            goto L_8018B244;
    }
    // 0x8018AFF0: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8018AFF4: addiu       $at, $zero, 0x514
    ctx->r1 = ADD32(0, 0X514);
    // 0x8018AFF8: beq         $v0, $at, L_8018B2AC
    if (ctx->r2 == ctx->r1) {
        // 0x8018AFFC: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8018B2AC;
    }
    // 0x8018AFFC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018B000: addiu       $at, $zero, 0x546
    ctx->r1 = ADD32(0, 0X546);
    // 0x8018B004: beq         $v0, $at, L_8018B2F8
    if (ctx->r2 == ctx->r1) {
        // 0x8018B008: lui         $a0, 0x1032
        ctx->r4 = S32(0X1032 << 16);
            goto L_8018B2F8;
    }
    // 0x8018B008: lui         $a0, 0x1032
    ctx->r4 = S32(0X1032 << 16);
    // 0x8018B00C: b           L_8018B318
    // 0x8018B010: slti        $at, $v1, 0x578
    ctx->r1 = SIGNED(ctx->r3) < 0X578 ? 1 : 0;
        goto L_8018B318;
    // 0x8018B010: slti        $at, $v1, 0x578
    ctx->r1 = SIGNED(ctx->r3) < 0X578 ? 1 : 0;
L_8018B014:
    // 0x8018B014: addiu       $at, $zero, 0x26A
    ctx->r1 = ADD32(0, 0X26A);
    // 0x8018B018: beq         $v0, $at, L_8018B04C
    if (ctx->r2 == ctx->r1) {
        // 0x8018B01C: addiu       $at, $zero, 0x2FD
        ctx->r1 = ADD32(0, 0X2FD);
            goto L_8018B04C;
    }
    // 0x8018B01C: addiu       $at, $zero, 0x2FD
    ctx->r1 = ADD32(0, 0X2FD);
    // 0x8018B020: beq         $v0, $at, L_8018B0B0
    if (ctx->r2 == ctx->r1) {
        // 0x8018B024: addiu       $at, $zero, 0x38F
        ctx->r1 = ADD32(0, 0X38F);
            goto L_8018B0B0;
    }
    // 0x8018B024: addiu       $at, $zero, 0x38F
    ctx->r1 = ADD32(0, 0X38F);
    // 0x8018B028: beq         $v0, $at, L_8018B114
    if (ctx->r2 == ctx->r1) {
        // 0x8018B02C: addiu       $at, $zero, 0x438
        ctx->r1 = ADD32(0, 0X438);
            goto L_8018B114;
    }
    // 0x8018B02C: addiu       $at, $zero, 0x438
    ctx->r1 = ADD32(0, 0X438);
    // 0x8018B030: beq         $v0, $at, L_8018B178
    if (ctx->r2 == ctx->r1) {
        // 0x8018B034: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8018B178;
    }
    // 0x8018B034: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018B038: addiu       $at, $zero, 0x4D8
    ctx->r1 = ADD32(0, 0X4D8);
    // 0x8018B03C: beq         $v0, $at, L_8018B184
    if (ctx->r2 == ctx->r1) {
        // 0x8018B040: lui         $t7, 0x8017
        ctx->r15 = S32(0X8017 << 16);
            goto L_8018B184;
    }
    // 0x8018B040: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018B044: b           L_8018B318
    // 0x8018B048: slti        $at, $v1, 0x578
    ctx->r1 = SIGNED(ctx->r3) < 0X578 ? 1 : 0;
        goto L_8018B318;
    // 0x8018B048: slti        $at, $v1, 0x578
    ctx->r1 = SIGNED(ctx->r3) < 0X578 ? 1 : 0;
L_8018B04C:
    // 0x8018B04C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018B050: lw          $v0, 0x78B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78B8);
    // 0x8018B054: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018B058: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018B05C: beq         $v0, $at, L_8018B074
    if (ctx->r2 == ctx->r1) {
        // 0x8018B060: addiu       $a0, $a0, 0x4B2C
        ctx->r4 = ADD32(ctx->r4, 0X4B2C);
            goto L_8018B074;
    }
    // 0x8018B060: addiu       $a0, $a0, 0x4B2C
    ctx->r4 = ADD32(ctx->r4, 0X4B2C);
    // 0x8018B064: beq         $v0, $zero, L_8018B084
    if (ctx->r2 == 0) {
        // 0x8018B068: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018B084;
    }
    // 0x8018B068: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018B06C: b           L_8018B098
    // 0x8018B070: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
        goto L_8018B098;
    // 0x8018B070: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
L_8018B074:
    // 0x8018B074: jal         0x800BA808
    // 0x8018B078: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_105;
    // 0x8018B078: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_105:
    // 0x8018B07C: b           L_8018B0A4
    // 0x8018B080: nop

        goto L_8018B0A4;
    // 0x8018B080: nop

L_8018B084:
    // 0x8018B084: addiu       $a0, $a0, 0x4C68
    ctx->r4 = ADD32(ctx->r4, 0X4C68);
    // 0x8018B088: jal         0x800BA808
    // 0x8018B08C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_106;
    // 0x8018B08C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_106:
    // 0x8018B090: b           L_8018B0A4
    // 0x8018B094: nop

        goto L_8018B0A4;
    // 0x8018B094: nop

L_8018B098:
    // 0x8018B098: addiu       $a0, $a0, -0x8D4
    ctx->r4 = ADD32(ctx->r4, -0X8D4);
    // 0x8018B09C: jal         0x800BA808
    // 0x8018B0A0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_107;
    // 0x8018B0A0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_107:
L_8018B0A4:
    // 0x8018B0A4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018B0A8: b           L_8018B314
    // 0x8018B0AC: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_8018B314;
    // 0x8018B0AC: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018B0B0:
    // 0x8018B0B0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018B0B4: lw          $v0, 0x78BC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78BC);
    // 0x8018B0B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018B0BC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018B0C0: beq         $v0, $at, L_8018B0D8
    if (ctx->r2 == ctx->r1) {
        // 0x8018B0C4: addiu       $a0, $a0, 0x4AE0
        ctx->r4 = ADD32(ctx->r4, 0X4AE0);
            goto L_8018B0D8;
    }
    // 0x8018B0C4: addiu       $a0, $a0, 0x4AE0
    ctx->r4 = ADD32(ctx->r4, 0X4AE0);
    // 0x8018B0C8: beq         $v0, $zero, L_8018B0E8
    if (ctx->r2 == 0) {
        // 0x8018B0CC: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018B0E8;
    }
    // 0x8018B0CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018B0D0: b           L_8018B0FC
    // 0x8018B0D4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
        goto L_8018B0FC;
    // 0x8018B0D4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
L_8018B0D8:
    // 0x8018B0D8: jal         0x800BA808
    // 0x8018B0DC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_108;
    // 0x8018B0DC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_108:
    // 0x8018B0E0: b           L_8018B108
    // 0x8018B0E4: nop

        goto L_8018B108;
    // 0x8018B0E4: nop

L_8018B0E8:
    // 0x8018B0E8: addiu       $a0, $a0, 0x4C1C
    ctx->r4 = ADD32(ctx->r4, 0X4C1C);
    // 0x8018B0EC: jal         0x800BA808
    // 0x8018B0F0: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_109;
    // 0x8018B0F0: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_109:
    // 0x8018B0F4: b           L_8018B108
    // 0x8018B0F8: nop

        goto L_8018B108;
    // 0x8018B0F8: nop

L_8018B0FC:
    // 0x8018B0FC: addiu       $a0, $a0, -0x8AC
    ctx->r4 = ADD32(ctx->r4, -0X8AC);
    // 0x8018B100: jal         0x800BA808
    // 0x8018B104: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_110;
    // 0x8018B104: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_110:
L_8018B108:
    // 0x8018B108: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018B10C: b           L_8018B314
    // 0x8018B110: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_8018B314;
    // 0x8018B110: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018B114:
    // 0x8018B114: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018B118: lw          $v0, 0x78B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78B4);
    // 0x8018B11C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018B120: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018B124: beq         $v0, $at, L_8018B13C
    if (ctx->r2 == ctx->r1) {
        // 0x8018B128: addiu       $a0, $a0, 0x4A94
        ctx->r4 = ADD32(ctx->r4, 0X4A94);
            goto L_8018B13C;
    }
    // 0x8018B128: addiu       $a0, $a0, 0x4A94
    ctx->r4 = ADD32(ctx->r4, 0X4A94);
    // 0x8018B12C: beq         $v0, $zero, L_8018B14C
    if (ctx->r2 == 0) {
        // 0x8018B130: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018B14C;
    }
    // 0x8018B130: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018B134: b           L_8018B160
    // 0x8018B138: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
        goto L_8018B160;
    // 0x8018B138: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
L_8018B13C:
    // 0x8018B13C: jal         0x800BA808
    // 0x8018B140: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_111;
    // 0x8018B140: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_111:
    // 0x8018B144: b           L_8018B16C
    // 0x8018B148: nop

        goto L_8018B16C;
    // 0x8018B148: nop

L_8018B14C:
    // 0x8018B14C: addiu       $a0, $a0, 0x4B7C
    ctx->r4 = ADD32(ctx->r4, 0X4B7C);
    // 0x8018B150: jal         0x800BA808
    // 0x8018B154: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_112;
    // 0x8018B154: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_112:
    // 0x8018B158: b           L_8018B16C
    // 0x8018B15C: nop

        goto L_8018B16C;
    // 0x8018B15C: nop

L_8018B160:
    // 0x8018B160: addiu       $a0, $a0, -0x880
    ctx->r4 = ADD32(ctx->r4, -0X880);
    // 0x8018B164: jal         0x800BA808
    // 0x8018B168: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_113;
    // 0x8018B168: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_113:
L_8018B16C:
    // 0x8018B16C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018B170: b           L_8018B314
    // 0x8018B174: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_8018B314;
    // 0x8018B174: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018B178:
    // 0x8018B178: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B17C: b           L_8018B314
    // 0x8018B180: sb          $t6, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = ctx->r14;
        goto L_8018B314;
    // 0x8018B180: sb          $t6, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = ctx->r14;
L_8018B184:
    // 0x8018B184: lw          $t7, 0x78B4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78B4);
    // 0x8018B188: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018B18C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018B190: blez        $t7, L_8018B314
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8018B194: lui         $a0, 0x900
        ctx->r4 = S32(0X900 << 16);
            goto L_8018B314;
    }
    // 0x8018B194: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8018B198: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8018B19C: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8018B1A0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8018B1A4: addiu       $a1, $a1, 0x49BC
    ctx->r5 = ADD32(ctx->r5, 0X49BC);
    // 0x8018B1A8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8018B1AC: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8018B1B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018B1B4: jal         0x80019218
    // 0x8018B1B8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_114;
    // 0x8018B1B8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_114:
    // 0x8018B1BC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018B1C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018B1C4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018B1C8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8018B1CC: swc1        $f8, 0x4A44($at)
    MEM_W(0X4A44, ctx->r1) = ctx->f8.u32l;
    // 0x8018B1D0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018B1D4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018B1D8: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8018B1DC: b           L_8018B314
    // 0x8018B1E0: sw          $t9, 0x4938($at)
    MEM_W(0X4938, ctx->r1) = ctx->r25;
        goto L_8018B314;
    // 0x8018B1E0: sw          $t9, 0x4938($at)
    MEM_W(0X4938, ctx->r1) = ctx->r25;
L_8018B1E4:
    // 0x8018B1E4: lw          $t6, 0x78B8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78B8);
    // 0x8018B1E8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018B1EC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018B1F0: blez        $t6, L_8018B314
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8018B1F4: lui         $a0, 0x900
        ctx->r4 = S32(0X900 << 16);
            goto L_8018B314;
    }
    // 0x8018B1F4: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8018B1F8: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8018B1FC: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8018B200: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8018B204: addiu       $a1, $a1, 0x43D4
    ctx->r5 = ADD32(ctx->r5, 0X43D4);
    // 0x8018B208: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018B20C: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8018B210: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018B214: jal         0x80019218
    // 0x8018B218: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_115;
    // 0x8018B218: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_115:
    // 0x8018B21C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018B220: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018B224: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018B228: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8018B22C: swc1        $f16, 0x445C($at)
    MEM_W(0X445C, ctx->r1) = ctx->f16.u32l;
    // 0x8018B230: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018B234: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018B238: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8018B23C: b           L_8018B314
    // 0x8018B240: sw          $t8, 0x4350($at)
    MEM_W(0X4350, ctx->r1) = ctx->r24;
        goto L_8018B314;
    // 0x8018B240: sw          $t8, 0x4350($at)
    MEM_W(0X4350, ctx->r1) = ctx->r24;
L_8018B244:
    // 0x8018B244: lw          $t9, 0x78BC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78BC);
    // 0x8018B248: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018B24C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018B250: blez        $t9, L_8018B2A0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8018B254: lui         $a0, 0x900
        ctx->r4 = S32(0X900 << 16);
            goto L_8018B2A0;
    }
    // 0x8018B254: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8018B258: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8018B25C: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8018B260: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8018B264: addiu       $a1, $a1, 0x46C8
    ctx->r5 = ADD32(ctx->r5, 0X46C8);
    // 0x8018B268: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8018B26C: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8018B270: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018B274: jal         0x80019218
    // 0x8018B278: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_116;
    // 0x8018B278: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_116:
    // 0x8018B27C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018B280: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018B284: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018B288: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8018B28C: swc1        $f6, 0x4750($at)
    MEM_W(0X4750, ctx->r1) = ctx->f6.u32l;
    // 0x8018B290: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018B294: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018B298: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8018B29C: sw          $t7, 0x4644($at)
    MEM_W(0X4644, ctx->r1) = ctx->r15;
L_8018B2A0:
    // 0x8018B2A0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B2A4: b           L_8018B314
    // 0x8018B2A8: sb          $zero, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = 0;
        goto L_8018B314;
    // 0x8018B2A8: sb          $zero, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = 0;
L_8018B2AC:
    // 0x8018B2AC: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8018B2B0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018B2B4: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8018B2B8: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8018B2BC: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8018B2C0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8018B2C4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018B2C8: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    // 0x8018B2CC: jal         0x80019218
    // 0x8018B2D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_117;
    // 0x8018B2D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_117:
    // 0x8018B2D4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8018B2D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018B2DC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018B2E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018B2E4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018B2E8: swc1        $f4, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f4.u32l;
    // 0x8018B2EC: swc1        $f10, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f10.u32l;
    // 0x8018B2F0: b           L_8018B314
    // 0x8018B2F4: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_8018B314;
    // 0x8018B2F4: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018B2F8:
    // 0x8018B2F8: jal         0x800182F4
    // 0x8018B2FC: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_118;
    // 0x8018B2FC: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_118:
    // 0x8018B300: lui         $a0, 0x1132
    ctx->r4 = S32(0X1132 << 16);
    // 0x8018B304: jal         0x800182F4
    // 0x8018B308: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_119;
    // 0x8018B308: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_119:
    // 0x8018B30C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018B310: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018B314:
    // 0x8018B314: slti        $at, $v1, 0x578
    ctx->r1 = SIGNED(ctx->r3) < 0X578 ? 1 : 0;
L_8018B318:
    // 0x8018B318: bne         $at, $zero, L_8018B3E0
    if (ctx->r1 != 0) {
        // 0x8018B31C: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8018B3E0;
    }
    // 0x8018B31C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8018B320: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8018B324: lw          $t6, -0x7CC0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CC0);
    // 0x8018B328: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B32C: sw          $v0, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r2;
    // 0x8018B330: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B334: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8018B338: bne         $v0, $t6, L_8018B3E0
    if (ctx->r2 != ctx->r14) {
        // 0x8018B33C: sw          $t9, -0x7CA4($at)
        MEM_W(-0X7CA4, ctx->r1) = ctx->r25;
            goto L_8018B3E0;
    }
    // 0x8018B33C: sw          $t9, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r25;
    // 0x8018B340: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x8018B344: sw          $t7, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r15;
    // 0x8018B348: sw          $zero, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = 0;
    // 0x8018B34C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8018B350: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018B354: sw          $t8, -0x7C84($at)
    MEM_W(-0X7C84, ctx->r1) = ctx->r24;
    // 0x8018B358: jal         0x8001DBD0
    // 0x8018B35C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    Audio_FadeOutAll(rdram, ctx);
        goto after_120;
    // 0x8018B35C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_120:
    // 0x8018B360: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8018B364: lw          $t9, 0x7CD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7CD0);
    // 0x8018B368: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018B36C: lw          $t6, 0x7CD4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7CD4);
    // 0x8018B370: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B374: sw          $t9, 0x7CF0($at)
    MEM_W(0X7CF0, ctx->r1) = ctx->r25;
    // 0x8018B378: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B37C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8018B380: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8018B384: addiu       $t8, $t8, 0x7CD0
    ctx->r24 = ADD32(ctx->r24, 0X7CD0);
    // 0x8018B388: sll         $a0, $a2, 2
    ctx->r4 = S32(ctx->r6 << 2);
    // 0x8018B38C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018B390: sw          $t6, 0x7CF4($at)
    MEM_W(0X7CF4, ctx->r1) = ctx->r14;
    // 0x8018B394: addiu       $t7, $t7, 0x7CF0
    ctx->r15 = ADD32(ctx->r15, 0X7CF0);
    // 0x8018B398: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
    // 0x8018B39C: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x8018B3A0: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x8018B3A4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8018B3A8: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x8018B3AC: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x8018B3B0: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x8018B3B4: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x8018B3B8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018B3BC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8018B3C0: jal         0x800A3F50
    // 0x8018B3C4: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    Play_CheckMedalStatus(rdram, ctx);
        goto after_121;
    // 0x8018B3C4: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    after_121:
    // 0x8018B3C8: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x8018B3CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8018B3D0: jal         0x800A6148
    // 0x8018B3D4: sb          $t9, 0x318E($at)
    MEM_B(0X318E, ctx->r1) = ctx->r25;
    Play_ClearObjectData(rdram, ctx);
        goto after_122;
    // 0x8018B3D4: sb          $t9, 0x318E($at)
    MEM_B(0X318E, ctx->r1) = ctx->r25;
    after_122:
    // 0x8018B3D8: b           L_8018B8C8
    // 0x8018B3DC: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
        goto L_8018B8C8;
    // 0x8018B3DC: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
L_8018B3E0:
    // 0x8018B3E0: slti        $at, $v1, 0x425
    ctx->r1 = SIGNED(ctx->r3) < 0X425 ? 1 : 0;
    // 0x8018B3E4: bne         $at, $zero, L_8018B440
    if (ctx->r1 != 0) {
        // 0x8018B3E8: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_8018B440;
    }
    // 0x8018B3E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B3EC: lwc1        $f18, -0x73C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X73C);
    // 0x8018B3F0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018B3F4: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8018B3F8: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018B3FC: addiu       $a0, $a0, 0x7A48
    ctx->r4 = ADD32(ctx->r4, 0X7A48);
    // 0x8018B400: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x8018B404: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018B408: jal         0x8009BC2C
    // 0x8018B40C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_123;
    // 0x8018B40C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_123:
    // 0x8018B410: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B414: lwc1        $f8, -0x738($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X738);
    // 0x8018B418: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018B41C: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8018B420: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018B424: addiu       $a0, $a0, 0x7A4C
    ctx->r4 = ADD32(ctx->r4, 0X7A4C);
    // 0x8018B428: lui         $a1, 0xC2C8
    ctx->r5 = S32(0XC2C8 << 16);
    // 0x8018B42C: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018B430: jal         0x8009BC2C
    // 0x8018B434: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_124;
    // 0x8018B434: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_124:
    // 0x8018B438: b           L_8018B4A8
    // 0x8018B43C: nop

        goto L_8018B4A8;
    // 0x8018B43C: nop

L_8018B440:
    // 0x8018B440: slti        $at, $v1, 0x303
    ctx->r1 = SIGNED(ctx->r3) < 0X303 ? 1 : 0;
    // 0x8018B444: bne         $at, $zero, L_8018B47C
    if (ctx->r1 != 0) {
        // 0x8018B448: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_8018B47C;
    }
    // 0x8018B448: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018B44C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B450: lwc1        $f16, -0x734($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X734);
    // 0x8018B454: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018B458: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8018B45C: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018B460: addiu       $a0, $a0, 0x7A48
    ctx->r4 = ADD32(ctx->r4, 0X7A48);
    // 0x8018B464: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    // 0x8018B468: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018B46C: jal         0x8009BC2C
    // 0x8018B470: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_125;
    // 0x8018B470: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_125:
    // 0x8018B474: b           L_8018B4A8
    // 0x8018B478: nop

        goto L_8018B4A8;
    // 0x8018B478: nop

L_8018B47C:
    // 0x8018B47C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8018B480: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018B484: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B488: lwc1        $f6, -0x730($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X730);
    // 0x8018B48C: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8018B490: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018B494: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8018B498: addiu       $a0, $a0, 0x7A48
    ctx->r4 = ADD32(ctx->r4, 0X7A48);
    // 0x8018B49C: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018B4A0: jal         0x8009BC2C
    // 0x8018B4A4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_126;
    // 0x8018B4A4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_126:
L_8018B4A8:
    // 0x8018B4A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B4AC: lwc1        $f4, -0x72C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X72C);
    // 0x8018B4B0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018B4B4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018B4B8: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x8018B4BC: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018B4C0: lw          $a1, 0x7A48($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7A48);
    // 0x8018B4C4: addiu       $a0, $a0, 0x7A5C
    ctx->r4 = ADD32(ctx->r4, 0X7A5C);
    // 0x8018B4C8: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018B4CC: jal         0x8009BC2C
    // 0x8018B4D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_127;
    // 0x8018B4D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_127:
    // 0x8018B4D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B4D8: lwc1        $f10, -0x728($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X728);
    // 0x8018B4DC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018B4E0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018B4E4: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x8018B4E8: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018B4EC: lw          $a1, 0x7A4C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7A4C);
    // 0x8018B4F0: addiu       $a0, $a0, 0x7A64
    ctx->r4 = ADD32(ctx->r4, 0X7A64);
    // 0x8018B4F4: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018B4F8: jal         0x8009BC2C
    // 0x8018B4FC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_128;
    // 0x8018B4FC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_128:
    // 0x8018B500: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018B504: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8018B508: slti        $at, $v1, 0x425
    ctx->r1 = SIGNED(ctx->r3) < 0X425 ? 1 : 0;
    // 0x8018B50C: bne         $at, $zero, L_8018B540
    if (ctx->r1 != 0) {
        // 0x8018B510: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_8018B540;
    }
    // 0x8018B510: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B514: lwc1        $f18, -0x724($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X724);
    // 0x8018B518: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018B51C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018B520: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018B524: addiu       $a0, $a0, 0x7A50
    ctx->r4 = ADD32(ctx->r4, 0X7A50);
    // 0x8018B528: lui         $a1, 0xC28C
    ctx->r5 = S32(0XC28C << 16);
    // 0x8018B52C: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018B530: jal         0x8009BC2C
    // 0x8018B534: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_129;
    // 0x8018B534: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_129:
    // 0x8018B538: b           L_8018B570
    // 0x8018B53C: nop

        goto L_8018B570;
    // 0x8018B53C: nop

L_8018B540:
    // 0x8018B540: slti        $at, $v1, 0x302
    ctx->r1 = SIGNED(ctx->r3) < 0X302 ? 1 : 0;
    // 0x8018B544: beq         $at, $zero, L_8018B570
    if (ctx->r1 == 0) {
        // 0x8018B548: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_8018B570;
    }
    // 0x8018B548: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018B54C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B550: lwc1        $f8, -0x720($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X720);
    // 0x8018B554: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018B558: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018B55C: addiu       $a0, $a0, 0x7A50
    ctx->r4 = ADD32(ctx->r4, 0X7A50);
    // 0x8018B560: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x8018B564: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018B568: jal         0x8009BC2C
    // 0x8018B56C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_130;
    // 0x8018B56C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_130:
L_8018B570:
    // 0x8018B570: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B574: lwc1        $f16, -0x71C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X71C);
    // 0x8018B578: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018B57C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018B580: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x8018B584: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018B588: lw          $a1, 0x7A50($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7A50);
    // 0x8018B58C: addiu       $a0, $a0, 0x7A60
    ctx->r4 = ADD32(ctx->r4, 0X7A60);
    // 0x8018B590: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018B594: jal         0x8009BC2C
    // 0x8018B598: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_131;
    // 0x8018B598: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_131:
    // 0x8018B59C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018B5A0: lw          $t6, 0x7A80($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7A80);
    // 0x8018B5A4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018B5A8: addiu       $a0, $a0, 0x7A68
    ctx->r4 = ADD32(ctx->r4, 0X7A68);
    // 0x8018B5AC: slti        $at, $t6, 0x49C
    ctx->r1 = SIGNED(ctx->r14) < 0X49C ? 1 : 0;
    // 0x8018B5B0: beq         $at, $zero, L_8018B5EC
    if (ctx->r1 == 0) {
        // 0x8018B5B4: lui         $a2, 0x3A83
        ctx->r6 = S32(0X3A83 << 16);
            goto L_8018B5EC;
    }
    // 0x8018B5B4: lui         $a2, 0x3A83
    ctx->r6 = S32(0X3A83 << 16);
    // 0x8018B5B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B5BC: lwc1        $f6, -0x718($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X718);
    // 0x8018B5C0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018B5C4: lui         $a1, 0x3ED1
    ctx->r5 = S32(0X3ED1 << 16);
    // 0x8018B5C8: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x8018B5CC: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018B5D0: ori         $a1, $a1, 0xEB85
    ctx->r5 = ctx->r5 | 0XEB85;
    // 0x8018B5D4: addiu       $a0, $a0, 0x7A68
    ctx->r4 = ADD32(ctx->r4, 0X7A68);
    // 0x8018B5D8: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018B5DC: jal         0x8009BC2C
    // 0x8018B5E0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_132;
    // 0x8018B5E0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_132:
    // 0x8018B5E4: b           L_8018B608
    // 0x8018B5E8: nop

        goto L_8018B608;
    // 0x8018B5E8: nop

L_8018B5EC:
    // 0x8018B5EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B5F0: lwc1        $f4, -0x714($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X714);
    // 0x8018B5F4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018B5F8: ori         $a2, $a2, 0x126F
    ctx->r6 = ctx->r6 | 0X126F;
    // 0x8018B5FC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8018B600: jal         0x8009BC2C
    // 0x8018B604: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_133;
    // 0x8018B604: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_133:
L_8018B608:
    // 0x8018B608: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018B60C: addiu       $v0, $v0, 0x7A48
    ctx->r2 = ADD32(ctx->r2, 0X7A48);
    // 0x8018B610: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8018B614: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8018B618: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8018B61C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018B620: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8018B624: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018B628: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
    // 0x8018B62C: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8018B630: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8018B634: nop

    // 0x8018B638: bc1fl       L_8018B650
    if (!c1cs) {
        // 0x8018B63C: c.lt.s      $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
            goto L_8018B650;
    }
    goto skip_11;
    // 0x8018B63C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    skip_11:
    // 0x8018B640: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8018B644: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
    // 0x8018B648: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8018B64C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
L_8018B650:
    // 0x8018B650: nop

    // 0x8018B654: bc1f        L_8018B664
    if (!c1cs) {
        // 0x8018B658: nop
    
            goto L_8018B664;
    }
    // 0x8018B658: nop

    // 0x8018B65C: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8018B660: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
L_8018B664:
    // 0x8018B664: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8018B668: slti        $at, $v1, 0x514
    ctx->r1 = SIGNED(ctx->r3) < 0X514 ? 1 : 0;
    // 0x8018B66C: beql        $at, $zero, L_8018B750
    if (ctx->r1 == 0) {
        // 0x8018B670: slti        $at, $v1, 0x4D8
        ctx->r1 = SIGNED(ctx->r3) < 0X4D8 ? 1 : 0;
            goto L_8018B750;
    }
    goto skip_12;
    // 0x8018B670: slti        $at, $v1, 0x4D8
    ctx->r1 = SIGNED(ctx->r3) < 0X4D8 ? 1 : 0;
    skip_12:
    // 0x8018B674: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8018B678: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8018B67C: swc1        $f20, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f20.u32l;
    // 0x8018B680: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B684: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x8018B688: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    // 0x8018B68C: lwc1        $f18, 0x7C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018B690: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8018B694: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x8018B698: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B69C: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8018B6A0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018B6A4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B6A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8018B6AC: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8018B6B0: jal         0x80005B00
    // 0x8018B6B4: nop

    Matrix_Translate(rdram, ctx);
        goto after_134;
    // 0x8018B6B4: nop

    after_134:
    // 0x8018B6B8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B6BC: lwc1        $f6, 0x7A58($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7A58);
    // 0x8018B6C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B6C4: lwc1        $f4, -0x710($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X710);
    // 0x8018B6C8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B6CC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B6D0: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8018B6D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018B6D8: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x8018B6DC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018B6E0: jal         0x80005E90
    // 0x8018B6E4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_135;
    // 0x8018B6E4: nop

    after_135:
    // 0x8018B6E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B6EC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B6F0: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8018B6F4: jal         0x80006970
    // 0x8018B6F8: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    Matrix_MultVec3f(rdram, ctx);
        goto after_136;
    // 0x8018B6F8: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_136:
    // 0x8018B6FC: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8018B700: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018B704: addiu       $v0, $v0, 0x7978
    ctx->r2 = ADD32(ctx->r2, 0X7978);
    // 0x8018B708: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8018B70C: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018B710: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018B714: addiu       $a0, $a0, 0x7980
    ctx->r4 = ADD32(ctx->r4, 0X7980);
    // 0x8018B718: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
    // 0x8018B71C: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8018B720: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018B724: addiu       $a1, $a1, 0x7988
    ctx->r5 = ADD32(ctx->r5, 0X7988);
    // 0x8018B728: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x8018B72C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8018B730: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018B734: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    // 0x8018B738: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8018B73C: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x8018B740: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018B744: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    // 0x8018B748: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8018B74C: slti        $at, $v1, 0x4D8
    ctx->r1 = SIGNED(ctx->r3) < 0X4D8 ? 1 : 0;
L_8018B750:
    // 0x8018B750: bne         $at, $zero, L_8018B784
    if (ctx->r1 != 0) {
        // 0x8018B754: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_8018B784;
    }
    // 0x8018B754: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018B758: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B75C: lwc1        $f8, -0x70C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X70C);
    // 0x8018B760: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018B764: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018B768: addiu       $a0, $a0, 0x49AC
    ctx->r4 = ADD32(ctx->r4, 0X49AC);
    // 0x8018B76C: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x8018B770: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018B774: jal         0x8009BC2C
    // 0x8018B778: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_137;
    // 0x8018B778: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_137:
    // 0x8018B77C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018B780: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018B784:
    // 0x8018B784: slti        $at, $v1, 0x4EC
    ctx->r1 = SIGNED(ctx->r3) < 0X4EC ? 1 : 0;
    // 0x8018B788: bne         $at, $zero, L_8018B7BC
    if (ctx->r1 != 0) {
        // 0x8018B78C: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_8018B7BC;
    }
    // 0x8018B78C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018B790: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B794: lwc1        $f16, -0x708($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X708);
    // 0x8018B798: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018B79C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018B7A0: addiu       $a0, $a0, 0x43C4
    ctx->r4 = ADD32(ctx->r4, 0X43C4);
    // 0x8018B7A4: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x8018B7A8: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018B7AC: jal         0x8009BC2C
    // 0x8018B7B0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_138;
    // 0x8018B7B0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_138:
    // 0x8018B7B4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018B7B8: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018B7BC:
    // 0x8018B7BC: slti        $at, $v1, 0x500
    ctx->r1 = SIGNED(ctx->r3) < 0X500 ? 1 : 0;
    // 0x8018B7C0: bne         $at, $zero, L_8018B7F4
    if (ctx->r1 != 0) {
        // 0x8018B7C4: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_8018B7F4;
    }
    // 0x8018B7C4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018B7C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B7CC: lwc1        $f6, -0x704($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X704);
    // 0x8018B7D0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018B7D4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018B7D8: addiu       $a0, $a0, 0x46B8
    ctx->r4 = ADD32(ctx->r4, 0X46B8);
    // 0x8018B7DC: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x8018B7E0: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018B7E4: jal         0x8009BC2C
    // 0x8018B7E8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_139;
    // 0x8018B7E8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_139:
    // 0x8018B7EC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018B7F0: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018B7F4:
    // 0x8018B7F4: slti        $at, $v1, 0x514
    ctx->r1 = SIGNED(ctx->r3) < 0X514 ? 1 : 0;
    // 0x8018B7F8: bne         $at, $zero, L_8018B848
    if (ctx->r1 != 0) {
        // 0x8018B7FC: addiu       $a0, $s0, 0xD0
        ctx->r4 = ADD32(ctx->r16, 0XD0);
            goto L_8018B848;
    }
    // 0x8018B7FC: addiu       $a0, $s0, 0xD0
    ctx->r4 = ADD32(ctx->r16, 0XD0);
    // 0x8018B800: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B804: lwc1        $f4, -0x700($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X700);
    // 0x8018B808: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018B80C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018B810: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x8018B814: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018B818: jal         0x8009BC2C
    // 0x8018B81C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_140;
    // 0x8018B81C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_140:
    // 0x8018B820: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B824: lwc1        $f10, -0x6FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6FC);
    // 0x8018B828: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018B82C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018B830: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018B834: addiu       $a0, $a0, 0x40D0
    ctx->r4 = ADD32(ctx->r4, 0X40D0);
    // 0x8018B838: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x8018B83C: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018B840: jal         0x8009BC2C
    // 0x8018B844: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_141;
    // 0x8018B844: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_141:
L_8018B848:
    // 0x8018B848: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B84C: lwc1        $f18, -0x6F8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6F8);
    // 0x8018B850: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018B854: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x8018B858: lui         $a2, 0x3BA3
    ctx->r6 = S32(0X3BA3 << 16);
    // 0x8018B85C: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018B860: addiu       $a0, $a0, 0x79B8
    ctx->r4 = ADD32(ctx->r4, 0X79B8);
    // 0x8018B864: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8018B868: jal         0x8009BC2C
    // 0x8018B86C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_142;
    // 0x8018B86C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_142:
    // 0x8018B870: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8018B874: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018B878: addiu       $v1, $v1, 0x79A0
    ctx->r3 = ADD32(ctx->r3, 0X79A0);
    // 0x8018B87C: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8018B880: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018B884: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B888: lwc1        $f4, 0x7C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018B88C: swc1        $f16, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f16.u32l;
    // 0x8018B890: lwc1        $f6, 0x79B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x8018B894: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B898: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018B89C: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x8018B8A0: lwc1        $f10, 0x7A60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7A60);
    // 0x8018B8A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B8A8: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8018B8AC: sub.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8018B8B0: addiu       $a0, $a0, 0x79C0
    ctx->r4 = ADD32(ctx->r4, 0X79C0);
    // 0x8018B8B4: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8018B8B8: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x8018B8BC: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8018B8C0: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
    // 0x8018B8C4: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
L_8018B8C8:
    // 0x8018B8C8: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8018B8CC: beq         $at, $zero, L_8018B90C
    if (ctx->r1 == 0) {
        // 0x8018B8D0: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_8018B90C;
    }
    // 0x8018B8D0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018B8D4: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x8018B8D8: addiu       $at, $zero, 0x3FC
    ctx->r1 = ADD32(0, 0X3FC);
    // 0x8018B8DC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018B8E0: beq         $v0, $at, L_8018B8F8
    if (ctx->r2 == ctx->r1) {
        // 0x8018B8E4: addiu       $at, $zero, 0x4C4
        ctx->r1 = ADD32(0, 0X4C4);
            goto L_8018B8F8;
    }
    // 0x8018B8E4: addiu       $at, $zero, 0x4C4
    ctx->r1 = ADD32(0, 0X4C4);
    // 0x8018B8E8: beq         $v0, $at, L_8018B904
    if (ctx->r2 == ctx->r1) {
        // 0x8018B8EC: nop
    
            goto L_8018B904;
    }
    // 0x8018B8EC: nop

    // 0x8018B8F0: b           L_8018B910
    // 0x8018B8F4: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
        goto L_8018B910;
    // 0x8018B8F4: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
L_8018B8F8:
    // 0x8018B8F8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B8FC: b           L_8018B90C
    // 0x8018B900: sb          $t7, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = ctx->r15;
        goto L_8018B90C;
    // 0x8018B900: sb          $t7, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = ctx->r15;
L_8018B904:
    // 0x8018B904: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B908: sb          $zero, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = 0;
L_8018B90C:
    // 0x8018B90C: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
L_8018B910:
    // 0x8018B910: lwc1        $f10, 0xE8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8018B914: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018B918: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018B91C: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8018B920: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B924: lwc1        $f6, -0x6F4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6F4);
    // 0x8018B928: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B92C: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8018B930: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B934: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018B938: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8018B93C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8018B940: jal         0x80005E90
    // 0x8018B944: nop

    Matrix_RotateY(rdram, ctx);
        goto after_143;
    // 0x8018B944: nop

    after_143:
    // 0x8018B948: lwc1        $f10, 0x120($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8018B94C: lwc1        $f18, 0xE4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x8018B950: lwc1        $f16, 0x4D8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4D8);
    // 0x8018B954: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B958: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8018B95C: lwc1        $f4, -0x6F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6F0);
    // 0x8018B960: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B964: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B968: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8018B96C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018B970: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8018B974: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x8018B978: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018B97C: jal         0x80005D44
    // 0x8018B980: nop

    Matrix_RotateX(rdram, ctx);
        goto after_144;
    // 0x8018B980: nop

    after_144:
    // 0x8018B984: swc1        $f20, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f20.u32l;
    // 0x8018B988: swc1        $f20, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f20.u32l;
    // 0x8018B98C: lwc1        $f16, 0x110($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X110);
    // 0x8018B990: lwc1        $f8, 0xD0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x8018B994: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B998: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B99C: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8018B9A0: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8018B9A4: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x8018B9A8: jal         0x80006A20
    // 0x8018B9AC: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_145;
    // 0x8018B9AC: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    after_145:
    // 0x8018B9B0: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8018B9B4: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8018B9B8: swc1        $f4, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f4.u32l;
    // 0x8018B9BC: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8018B9C0: lwc1        $f16, 0xC0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8018B9C4: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8018B9C8: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
    // 0x8018B9CC: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8018B9D0: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8018B9D4: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8018B9D8: swc1        $f18, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f18.u32l;
    // 0x8018B9DC: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8018B9E0: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018B9E4: swc1        $f6, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f6.u32l;
    // 0x8018B9E8: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8018B9EC: lwc1        $f10, 0xEC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8018B9F0: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8018B9F4: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    // 0x8018B9F8: lwc1        $f18, 0x12C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x8018B9FC: lwc1        $f16, 0x130($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X130);
    // 0x8018BA00: swc1        $f6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f6.u32l;
    // 0x8018BA04: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8018BA08: lwc1        $f4, 0x7C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018BA0C: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8018BA10: swc1        $f4, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f4.u32l;
    // 0x8018BA14: swc1        $f6, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f6.u32l;
    // 0x8018BA18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018BA1C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018BA20: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8018BA24: jr          $ra
    // 0x8018BA28: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8018BA28: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void Bolse_BoBase_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E870: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8018E874: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8018E878: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8018E87C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8018E880: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018E884: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x8018E888: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8018E88C: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8018E890: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8018E894: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8018E898: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8018E89C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8018E8A0: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8018E8A4: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8018E8A8: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8018E8AC: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8018E8B0: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8018E8B4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018E8B8: lwc1        $f0, 0x3F8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3F8);
    // 0x8018E8BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018E8C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018E8C4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018E8C8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018E8CC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018E8D0: jal         0x80005C34
    // 0x8018E8D4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_0;
    // 0x8018E8D4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x8018E8D8: lwc1        $f4, 0x30C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30C);
    // 0x8018E8DC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018E8E0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8018E8E4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8018E8E8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8018E8EC: lui         $s0, 0x801A
    ctx->r16 = S32(0X801A << 16);
    // 0x8018E8F0: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8018E8F4: addiu       $s0, $s0, 0x488
    ctx->r16 = ADD32(ctx->r16, 0X488);
    // 0x8018E8F8: bc1f        L_8018E928
    if (!c1cs) {
        // 0x8018E8FC: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_8018E928;
    }
    // 0x8018E8FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018E900: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8018E904: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x8018E908: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8018E90C: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8018E910: addiu       $t9, $t9, 0x2020
    ctx->r25 = ADD32(ctx->r25, 0X2020);
    // 0x8018E914: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8018E918: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8018E91C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8018E920: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8018E924: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_8018E928:
    // 0x8018E928: lw          $t1, 0x7DB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DB0);
    // 0x8018E92C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8018E930: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x8018E934: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8018E938: beq         $t2, $zero, L_8018E948
    if (ctx->r10 == 0) {
        // 0x8018E93C: lui         $fp, 0xFA00
        ctx->r30 = S32(0XFA00 << 16);
            goto L_8018E948;
    }
    // 0x8018E93C: lui         $fp, 0xFA00
    ctx->r30 = S32(0XFA00 << 16);
    // 0x8018E940: b           L_8018E94C
    // 0x8018E944: addiu       $s6, $zero, 0x80
    ctx->r22 = ADD32(0, 0X80);
        goto L_8018E94C;
    // 0x8018E944: addiu       $s6, $zero, 0x80
    ctx->r22 = ADD32(0, 0X80);
L_8018E948:
    // 0x8018E948: addiu       $s6, $zero, 0x1E
    ctx->r22 = ADD32(0, 0X1E);
L_8018E94C:
    // 0x8018E94C: lwc1        $f24, -0x664($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X664);
    // 0x8018E950: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018E954: lwc1        $f22, -0x660($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X660);
    // 0x8018E958: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018E95C: lui         $s7, 0x801A
    ctx->r23 = S32(0X801A << 16);
    // 0x8018E960: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018E964: addiu       $s7, $s7, 0x530
    ctx->r23 = ADD32(ctx->r23, 0X530);
    // 0x8018E968: lw          $t3, 0x18($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X18);
L_8018E96C:
    // 0x8018E96C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018E970: andi        $v0, $s6, 0xFF
    ctx->r2 = ctx->r22 & 0XFF;
    // 0x8018E974: beq         $t3, $zero, L_8018EAA0
    if (ctx->r11 == 0) {
        // 0x8018E978: addiu       $at, $zero, -0x100
        ctx->r1 = ADD32(0, -0X100);
            goto L_8018EAA0;
    }
    // 0x8018E978: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8018E97C: or          $s3, $v0, $at
    ctx->r19 = ctx->r2 | ctx->r1;
    // 0x8018E980: lui         $at, 0xFF38
    ctx->r1 = S32(0XFF38 << 16);
    // 0x8018E984: ori         $at, $at, 0x3800
    ctx->r1 = ctx->r1 | 0X3800;
    // 0x8018E988: lui         $s5, 0x601
    ctx->r21 = S32(0X601 << 16);
    // 0x8018E98C: addiu       $s5, $s5, -0x40D0
    ctx->r21 = ADD32(ctx->r21, -0X40D0);
    // 0x8018E990: jal         0x80005708
    // 0x8018E994: or          $s4, $v0, $at
    ctx->r20 = ctx->r2 | ctx->r1;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x8018E994: or          $s4, $v0, $at
    ctx->r20 = ctx->r2 | ctx->r1;
    after_1:
    // 0x8018E998: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018E99C: jal         0x800B8DD0
    // 0x8018E9A0: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x8018E9A0: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_2:
    // 0x8018E9A4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8018E9A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018E9AC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8018E9B0: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x8018E9B4: sw          $s3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r19;
    // 0x8018E9B8: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x8018E9BC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8018E9C0: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x8018E9C4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8018E9C8: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x8018E9CC: sw          $s4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r20;
    // 0x8018E9D0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8018E9D4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018E9D8: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8018E9DC: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8018E9E0: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8018E9E4: jal         0x80005B00
    // 0x8018E9E8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x8018E9E8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x8018E9EC: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018E9F0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018E9F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018E9F8: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8018E9FC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018EA00: jal         0x80005E90
    // 0x8018EA04: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x8018EA04: nop

    after_4:
    // 0x8018EA08: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018EA0C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018EA10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018EA14: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8018EA18: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018EA1C: jal         0x80005D44
    // 0x8018EA20: nop

    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x8018EA20: nop

    after_5:
    // 0x8018EA24: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x8018EA28: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018EA2C: jal         0x80005FE0
    // 0x8018EA30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x8018EA30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x8018EA34: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018EA38: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018EA3C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018EA40: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x8018EA44: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018EA48: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018EA4C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018EA50: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8018EA54: jal         0x80005B00
    // 0x8018EA58: nop

    Matrix_Translate(rdram, ctx);
        goto after_7;
    // 0x8018EA58: nop

    after_7:
    // 0x8018EA5C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018EA60: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018EA64: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018EA68: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8018EA6C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8018EA70: jal         0x80005C34
    // 0x8018EA74: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    Matrix_Scale(rdram, ctx);
        goto after_8;
    // 0x8018EA74: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    after_8:
    // 0x8018EA78: jal         0x80006EB8
    // 0x8018EA7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_9;
    // 0x8018EA7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x8018EA80: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8018EA84: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8018EA88: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8018EA8C: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x8018EA90: sw          $s5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r21;
    // 0x8018EA94: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8018EA98: jal         0x80005740
    // 0x8018EA9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_10;
    // 0x8018EA9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
L_8018EAA0:
    // 0x8018EAA0: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x8018EAA4: bnel        $s0, $s7, L_8018E96C
    if (ctx->r16 != ctx->r23) {
        // 0x8018EAA8: lw          $t3, 0x18($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X18);
            goto L_8018E96C;
    }
    goto skip_0;
    // 0x8018EAA8: lw          $t3, 0x18($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X18);
    skip_0:
    // 0x8018EAAC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8018EAB0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018EAB4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8018EAB8: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8018EABC: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8018EAC0: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8018EAC4: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8018EAC8: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8018EACC: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8018EAD0: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8018EAD4: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8018EAD8: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8018EADC: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x8018EAE0: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x8018EAE4: jr          $ra
    // 0x8018EAE8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8018EAE8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void Bolse_Effect397_Spawn2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190FE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80190FEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80190FF0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80190FF4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80190FF8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80190FFC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80191000: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x80191004: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x80191008: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8019100C:
    // 0x8019100C: bnel        $t6, $zero, L_80191038
    if (ctx->r14 != 0) {
        // 0x80191010: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_80191038;
    }
    goto skip_0;
    // 0x80191010: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x80191014: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80191018: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8019101C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80191020: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80191024: jal         0x80190F58
    // 0x80191028: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Bolse_Effect397_Setup2(rdram, ctx);
        goto after_0;
    // 0x80191028: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8019102C: b           L_80191048
    // 0x80191030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80191048;
    // 0x80191030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80191034: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_80191038:
    // 0x80191038: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8019103C: beql        $at, $zero, L_8019100C
    if (ctx->r1 == 0) {
        // 0x80191040: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8019100C;
    }
    goto skip_1;
    // 0x80191040: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x80191044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80191048:
    // 0x80191048: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019104C: jr          $ra
    // 0x80191050: nop

    return;
    // 0x80191050: nop

;}
RECOMP_FUNC void SectorZ_LevelCompleteCsUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019DD20: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8019DD24: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8019DD28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019DD2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019DD30: lh          $t6, 0xB8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB8);
    // 0x8019DD34: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8019DD38: sltiu       $at, $t7, 0xC
    ctx->r1 = ctx->r15 < 0XC ? 1 : 0;
    // 0x8019DD3C: beq         $at, $zero, L_8019DF14
    if (ctx->r1 == 0) {
        // 0x8019DD40: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8019DF14;
    }
    // 0x8019DD40: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8019DD44: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019DD48: addu        $at, $at, $t7
    gpr jr_addend_8019DD50 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8019DD4C: lw          $t7, 0x360($at)
    ctx->r15 = ADD32(ctx->r1, 0X360);
    // 0x8019DD50: jr          $t7
    // 0x8019DD54: nop

    switch (jr_addend_8019DD50 >> 2) {
        case 0: goto L_8019DD58; break;
        case 1: goto L_8019DD9C; break;
        case 2: goto L_8019DF14; break;
        case 3: goto L_8019DF14; break;
        case 4: goto L_8019DF14; break;
        case 5: goto L_8019DF14; break;
        case 6: goto L_8019DF14; break;
        case 7: goto L_8019DF14; break;
        case 8: goto L_8019DF14; break;
        case 9: goto L_8019DDF4; break;
        case 10: goto L_8019DE0C; break;
        case 11: goto L_8019DE94; break;
        default: switch_error(__func__, 0x8019DD50, 0x801A0360);
    }
    // 0x8019DD54: nop

L_8019DD58:
    // 0x8019DD58: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8019DD5C: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8019DD60: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8019DD64: sh          $t8, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r24;
    // 0x8019DD68: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8019DD6C: addiu       $a3, $t9, 0x5D34
    ctx->r7 = ADD32(ctx->r25, 0X5D34);
    // 0x8019DD70: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8019DD74: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8019DD78: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019DD7C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8019DD80: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8019DD84: jal         0x80019218
    // 0x8019DD88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8019DD88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8019DD8C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8019DD90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019DD94: nop

    // 0x8019DD98: swc1        $f4, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f4.u32l;
L_8019DD9C:
    // 0x8019DD9C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8019DDA0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019DDA4: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8019DDA8: lwc1        $f16, 0xF4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8019DDAC: lwc1        $f18, 0x118($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8019DDB0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019DDB4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019DDB8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8019DDBC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8019DDC0: sw          $t1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r9;
    // 0x8019DDC4: swc1        $f10, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f10.u32l;
    // 0x8019DDC8: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x8019DDCC: swc1        $f4, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f4.u32l;
    // 0x8019DDD0: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x8019DDD4: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8019DDD8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8019DDDC: addiu       $a0, $s0, 0x118
    ctx->r4 = ADD32(ctx->r16, 0X118);
    // 0x8019DDE0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8019DDE4: jal         0x8009BC2C
    // 0x8019DDE8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x8019DDE8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8019DDEC: b           L_8019DF18
    // 0x8019DDF0: lh          $t5, 0xB6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XB6);
        goto L_8019DF18;
    // 0x8019DDF0: lh          $t5, 0xB6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XB6);
L_8019DDF4:
    // 0x8019DDF4: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
    // 0x8019DDF8: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x8019DDFC: bnel        $t2, $zero, L_8019DF18
    if (ctx->r10 != 0) {
        // 0x8019DE00: lh          $t5, 0xB6($s0)
        ctx->r13 = MEM_H(ctx->r16, 0XB6);
            goto L_8019DF18;
    }
    goto skip_0;
    // 0x8019DE00: lh          $t5, 0xB6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XB6);
    skip_0:
    // 0x8019DE04: b           L_8019DF14
    // 0x8019DE08: sh          $t3, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r11;
        goto L_8019DF14;
    // 0x8019DE08: sh          $t3, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r11;
L_8019DE0C:
    // 0x8019DE0C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019DE10: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019DE14: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019DE18: addiu       $a0, $s0, 0xF4
    ctx->r4 = ADD32(ctx->r16, 0XF4);
    // 0x8019DE1C: lui         $a1, 0x4357
    ctx->r5 = S32(0X4357 << 16);
    // 0x8019DE20: lui         $a3, 0x40E0
    ctx->r7 = S32(0X40E0 << 16);
    // 0x8019DE24: jal         0x8009BC2C
    // 0x8019DE28: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x8019DE28: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8019DE2C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019DE30: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019DE34: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019DE38: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x8019DE3C: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x8019DE40: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x8019DE44: jal         0x8009BC2C
    // 0x8019DE48: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8019DE48: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8019DE4C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8019DE50: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019DE54: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019DE58: addiu       $a0, $s0, 0xF8
    ctx->r4 = ADD32(ctx->r16, 0XF8);
    // 0x8019DE5C: lui         $a1, 0x430C
    ctx->r5 = S32(0X430C << 16);
    // 0x8019DE60: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8019DE64: jal         0x8009BD38
    // 0x8019DE68: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_4;
    // 0x8019DE68: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x8019DE6C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019DE70: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019DE74: lwc1        $f4, 0xF4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8019DE78: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8019DE7C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8019DE80: nop

    // 0x8019DE84: bc1fl       L_8019DF18
    if (!c1cs) {
        // 0x8019DE88: lh          $t5, 0xB6($s0)
        ctx->r13 = MEM_H(ctx->r16, 0XB6);
            goto L_8019DF18;
    }
    goto skip_1;
    // 0x8019DE88: lh          $t5, 0xB6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XB6);
    skip_1:
    // 0x8019DE8C: b           L_8019DF14
    // 0x8019DE90: sh          $t4, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r12;
        goto L_8019DF14;
    // 0x8019DE90: sh          $t4, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r12;
L_8019DE94:
    // 0x8019DE94: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019DE98: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019DE9C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019DEA0: addiu       $a0, $s0, 0xF4
    ctx->r4 = ADD32(ctx->r16, 0XF4);
    // 0x8019DEA4: lui         $a1, 0x435A
    ctx->r5 = S32(0X435A << 16);
    // 0x8019DEA8: lui         $a3, 0x40E0
    ctx->r7 = S32(0X40E0 << 16);
    // 0x8019DEAC: jal         0x8009BD38
    // 0x8019DEB0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_5;
    // 0x8019DEB0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x8019DEB4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019DEB8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019DEBC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019DEC0: addiu       $a0, $s0, 0xF8
    ctx->r4 = ADD32(ctx->r16, 0XF8);
    // 0x8019DEC4: lui         $a1, 0x4313
    ctx->r5 = S32(0X4313 << 16);
    // 0x8019DEC8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8019DECC: jal         0x8009BD38
    // 0x8019DED0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_6;
    // 0x8019DED0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x8019DED4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019DED8: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8019DEDC: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8019DEE0: addiu       $a0, $s0, 0xFC
    ctx->r4 = ADD32(ctx->r16, 0XFC);
    // 0x8019DEE4: lui         $a1, 0x432A
    ctx->r5 = S32(0X432A << 16);
    // 0x8019DEE8: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8019DEEC: jal         0x8009BC2C
    // 0x8019DEF0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x8019DEF0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x8019DEF4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8019DEF8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019DEFC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019DF00: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x8019DF04: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x8019DF08: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8019DF0C: jal         0x8009BC2C
    // 0x8019DF10: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x8019DF10: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_8:
L_8019DF14:
    // 0x8019DF14: lh          $t5, 0xB6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XB6);
L_8019DF18:
    // 0x8019DF18: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8019DF1C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019DF20: bnel        $t5, $at, L_8019E158
    if (ctx->r13 != ctx->r1) {
        // 0x8019DF24: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8019E158;
    }
    goto skip_2;
    // 0x8019DF24: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_2:
    // 0x8019DF28: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x8019DF2C: addiu       $at, $zero, 0x122
    ctx->r1 = ADD32(0, 0X122);
    // 0x8019DF30: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8019DF34: beq         $v0, $at, L_8019DF5C
    if (ctx->r2 == ctx->r1) {
        // 0x8019DF38: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8019DF5C;
    }
    // 0x8019DF38: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8019DF3C: addiu       $at, $zero, 0x190
    ctx->r1 = ADD32(0, 0X190);
    // 0x8019DF40: beq         $v1, $at, L_8019DFC4
    if (ctx->r3 == ctx->r1) {
        // 0x8019DF44: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_8019DFC4;
    }
    // 0x8019DF44: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8019DF48: addiu       $at, $zero, 0x1AE
    ctx->r1 = ADD32(0, 0X1AE);
    // 0x8019DF4C: beq         $v1, $at, L_8019DF84
    if (ctx->r3 == ctx->r1) {
        // 0x8019DF50: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8019DF84;
    }
    // 0x8019DF50: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019DF54: b           L_8019E000
    // 0x8019DF58: slti        $at, $v0, 0x1AF
    ctx->r1 = SIGNED(ctx->r2) < 0X1AF ? 1 : 0;
        goto L_8019E000;
    // 0x8019DF58: slti        $at, $v0, 0x1AF
    ctx->r1 = SIGNED(ctx->r2) < 0X1AF ? 1 : 0;
L_8019DF5C:
    // 0x8019DF5C: lw          $t6, 0x78B4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78B4);
    // 0x8019DF60: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019DF64: addiu       $a0, $a0, 0x1584
    ctx->r4 = ADD32(ctx->r4, 0X1584);
    // 0x8019DF68: blezl       $t6, L_8019E000
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8019DF6C: slti        $at, $v0, 0x1AF
        ctx->r1 = SIGNED(ctx->r2) < 0X1AF ? 1 : 0;
            goto L_8019E000;
    }
    goto skip_3;
    // 0x8019DF6C: slti        $at, $v0, 0x1AF
    ctx->r1 = SIGNED(ctx->r2) < 0X1AF ? 1 : 0;
    skip_3:
    // 0x8019DF70: jal         0x800BA808
    // 0x8019DF74: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    Radio_PlayMessage(rdram, ctx);
        goto after_9;
    // 0x8019DF74: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_9:
    // 0x8019DF78: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019DF7C: b           L_8019DFFC
    // 0x8019DF80: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
        goto L_8019DFFC;
    // 0x8019DF80: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_8019DF84:
    // 0x8019DF84: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8019DF88: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019DF8C: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8019DF90: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8019DF94: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8019DF98: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8019DF9C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019DFA0: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8019DFA4: jal         0x80019218
    // 0x8019DFA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_10;
    // 0x8019DFA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8019DFAC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8019DFB0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019DFB4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019DFB8: swc1        $f18, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f18.u32l;
    // 0x8019DFBC: b           L_8019DFFC
    // 0x8019DFC0: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
        goto L_8019DFFC;
    // 0x8019DFC0: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_8019DFC4:
    // 0x8019DFC4: lbu         $t8, 0x7B8C($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7B8C);
    // 0x8019DFC8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019DFCC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8019DFD0: beq         $t8, $zero, L_8019DFEC
    if (ctx->r24 == 0) {
        // 0x8019DFD4: addiu       $a0, $a0, 0x160C
        ctx->r4 = ADD32(ctx->r4, 0X160C);
            goto L_8019DFEC;
    }
    // 0x8019DFD4: addiu       $a0, $a0, 0x160C
    ctx->r4 = ADD32(ctx->r4, 0X160C);
    // 0x8019DFD8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019DFDC: jal         0x800BA808
    // 0x8019DFE0: addiu       $a0, $a0, 0x15B0
    ctx->r4 = ADD32(ctx->r4, 0X15B0);
    Radio_PlayMessage(rdram, ctx);
        goto after_11;
    // 0x8019DFE0: addiu       $a0, $a0, 0x15B0
    ctx->r4 = ADD32(ctx->r4, 0X15B0);
    after_11:
    // 0x8019DFE4: b           L_8019DFF4
    // 0x8019DFE8: nop

        goto L_8019DFF4;
    // 0x8019DFE8: nop

L_8019DFEC:
    // 0x8019DFEC: jal         0x800BA808
    // 0x8019DFF0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    Radio_PlayMessage(rdram, ctx);
        goto after_12;
    // 0x8019DFF0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_12:
L_8019DFF4:
    // 0x8019DFF4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019DFF8: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_8019DFFC:
    // 0x8019DFFC: slti        $at, $v0, 0x1AF
    ctx->r1 = SIGNED(ctx->r2) < 0X1AF ? 1 : 0;
L_8019E000:
    // 0x8019E000: bne         $at, $zero, L_8019E154
    if (ctx->r1 != 0) {
        // 0x8019E004: addiu       $a0, $s0, 0xFC
        ctx->r4 = ADD32(ctx->r16, 0XFC);
            goto L_8019E154;
    }
    // 0x8019E004: addiu       $a0, $s0, 0xFC
    ctx->r4 = ADD32(ctx->r16, 0XFC);
    // 0x8019E008: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8019E00C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019E010: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019E014: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019E018: addiu       $t9, $s0, 0x114
    ctx->r25 = ADD32(ctx->r16, 0X114);
    // 0x8019E01C: swc1        $f4, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f4.u32l;
    // 0x8019E020: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8019E024: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019E028: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x8019E02C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x8019E030: jal         0x8009BC2C
    // 0x8019E034: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x8019E034: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_13:
    // 0x8019E038: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019E03C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019E040: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019E044: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8019E048: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x8019E04C: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8019E050: jal         0x8009BC2C
    // 0x8019E054: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x8019E054: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_14:
    // 0x8019E058: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019E05C: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x8019E060: slti        $at, $v0, 0x1CC
    ctx->r1 = SIGNED(ctx->r2) < 0X1CC ? 1 : 0;
    // 0x8019E064: beq         $at, $zero, L_8019E154
    if (ctx->r1 == 0) {
        // 0x8019E068: andi        $t0, $v0, 0x3
        ctx->r8 = ctx->r2 & 0X3;
            goto L_8019E154;
    }
    // 0x8019E068: andi        $t0, $v0, 0x3
    ctx->r8 = ctx->r2 & 0X3;
    // 0x8019E06C: bne         $t0, $zero, L_8019E154
    if (ctx->r8 != 0) {
        // 0x8019E070: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_8019E154;
    }
    // 0x8019E070: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019E074: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8019E078: lwc1        $f16, 0x390($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X390);
    // 0x8019E07C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019E080: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019E084: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8019E088: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019E08C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8019E090: jal         0x80005E90
    // 0x8019E094: nop

    Matrix_RotateY(rdram, ctx);
        goto after_15;
    // 0x8019E094: nop

    after_15:
    // 0x8019E098: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019E09C: lwc1        $f6, 0x394($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X394);
    // 0x8019E0A0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8019E0A4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019E0A8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019E0AC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019E0B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019E0B4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019E0B8: jal         0x80005D44
    // 0x8019E0BC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_16;
    // 0x8019E0BC: nop

    after_16:
    // 0x8019E0C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019E0C4: lwc1        $f16, 0x398($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X398);
    // 0x8019E0C8: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8019E0CC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019E0D0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019E0D4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8019E0D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019E0DC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8019E0E0: jal         0x80005FE0
    // 0x8019E0E4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_17;
    // 0x8019E0E4: nop

    after_17:
    // 0x8019E0E8: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8019E0EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019E0F0: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x8019E0F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019E0F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019E0FC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019E100: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019E104: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8019E108: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x8019E10C: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x8019E110: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x8019E114: jal         0x80006A20
    // 0x8019E118: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_18;
    // 0x8019E118: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    after_18:
    // 0x8019E11C: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019E120: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8019E124: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019E128: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8019E12C: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019E130: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019E134: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8019E138: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019E13C: lui         $a3, 0x4046
    ctx->r7 = S32(0X4046 << 16);
    // 0x8019E140: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x8019E144: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019E148: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8019E14C: jal         0x80078E50
    // 0x8019E150: nop

    Effect_Sparkle_Spawn(rdram, ctx);
        goto after_19;
    // 0x8019E150: nop

    after_19:
L_8019E154:
    // 0x8019E154: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8019E158:
    // 0x8019E158: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019E15C: lwc1        $f16, 0xF8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8019E160: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019E164: lwc1        $f6, 0x39C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X39C);
    // 0x8019E168: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8019E16C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019E170: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019E174: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019E178: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019E17C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019E180: jal         0x80005E90
    // 0x8019E184: nop

    Matrix_RotateY(rdram, ctx);
        goto after_20;
    // 0x8019E184: nop

    after_20:
    // 0x8019E188: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019E18C: lwc1        $f16, 0x3A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X3A0);
    // 0x8019E190: lwc1        $f10, 0xF4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8019E194: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019E198: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019E19C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8019E1A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019E1A4: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8019E1A8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8019E1AC: jal         0x80005D44
    // 0x8019E1B0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_21;
    // 0x8019E1B0: nop

    after_21:
    // 0x8019E1B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019E1B8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019E1BC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019E1C0: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x8019E1C4: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x8019E1C8: lwc1        $f10, 0x114($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8019E1CC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019E1D0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8019E1D4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x8019E1D8: jal         0x80006A20
    // 0x8019E1DC: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_22;
    // 0x8019E1DC: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    after_22:
    // 0x8019E1E0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8019E1E4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019E1E8: lwc1        $f10, 0xF8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8019E1EC: swc1        $f16, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f16.u32l;
    // 0x8019E1F0: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8019E1F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019E1F8: lwc1        $f6, 0xF4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8019E1FC: swc1        $f18, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
    // 0x8019E200: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8019E204: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019E208: swc1        $f4, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f4.u32l;
    // 0x8019E20C: lwc1        $f4, 0xFC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x8019E210: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8019E214: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x8019E218: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8019E21C: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x8019E220: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x8019E224: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019E228: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8019E22C: jr          $ra
    // 0x8019E230: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8019E230: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Bolse_BoBaseCore_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801918E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801918E8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801918EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801918F0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801918F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801918F8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801918FC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80191900: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80191904: jal         0x800B8DD0
    // 0x80191908: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80191908: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_0:
    // 0x8019190C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80191910: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80191914: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80191918: addiu       $t6, $t0, -0x1
    ctx->r14 = ADD32(ctx->r8, -0X1);
    // 0x8019191C: sltiu       $at, $t6, 0x10
    ctx->r1 = ctx->r14 < 0X10 ? 1 : 0;
    // 0x80191920: beq         $at, $zero, L_80191A58
    if (ctx->r1 == 0) {
        // 0x80191924: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80191A58;
    }
    // 0x80191924: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80191928: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019192C: addu        $at, $at, $t6
    gpr jr_addend_80191934 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80191930: lw          $t6, -0x36C($at)
    ctx->r14 = ADD32(ctx->r1, -0X36C);
    // 0x80191934: jr          $t6
    // 0x80191938: nop

    switch (jr_addend_80191934 >> 2) {
        case 0: goto L_8019193C; break;
        case 1: goto L_8019193C; break;
        case 2: goto L_8019193C; break;
        case 3: goto L_8019193C; break;
        case 4: goto L_8019193C; break;
        case 5: goto L_8019193C; break;
        case 6: goto L_8019193C; break;
        case 7: goto L_8019193C; break;
        case 8: goto L_801919B4; break;
        case 9: goto L_801919B4; break;
        case 10: goto L_801919B4; break;
        case 11: goto L_801919B4; break;
        case 12: goto L_801919B4; break;
        case 13: goto L_801919B4; break;
        case 14: goto L_801919B4; break;
        case 15: goto L_801919B4; break;
        default: switch_error(__func__, 0x80191934, 0x8019FC94);
    }
    // 0x80191938: nop

L_8019193C:
    // 0x8019193C: jal         0x800B8DD0
    // 0x80191940: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80191940: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_1:
    // 0x80191944: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80191948: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8019194C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80191950: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80191954: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80191958: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8019195C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191960: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80191964: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80191968: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8019196C: lwc1        $f4, -0x1140($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1140);
    // 0x80191970: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80191974: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x80191978: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8019197C: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x80191980: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x80191984: nop

    // 0x80191988: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x8019198C: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x80191990: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80191994: ori         $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 | 0XFF;
    // 0x80191998: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8019199C: lh          $t8, 0x86($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X86);
    // 0x801919A0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x801919A4: bgtzl       $t8, L_80191A5C
    if (SIGNED(ctx->r24) > 0) {
        // 0x801919A8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80191A5C;
    }
    goto skip_0;
    // 0x801919A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801919AC: b           L_80191A58
    // 0x801919B0: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
        goto L_80191A58;
    // 0x801919B0: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_801919B4:
    // 0x801919B4: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x801919B8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x801919BC: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    // 0x801919C0: addu        $a2, $a3, $t1
    ctx->r6 = ADD32(ctx->r7, ctx->r9);
    // 0x801919C4: lh          $t2, 0x8E($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X8E);
    // 0x801919C8: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x801919CC: beql        $t3, $zero, L_80191A44
    if (ctx->r11 == 0) {
        // 0x801919D0: lh          $t2, 0x76($a2)
        ctx->r10 = MEM_H(ctx->r6, 0X76);
            goto L_80191A44;
    }
    goto skip_1;
    // 0x801919D0: lh          $t2, 0x76($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X76);
    skip_1:
    // 0x801919D4: jal         0x800B8DD0
    // 0x801919D8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x801919D8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_2:
    // 0x801919DC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x801919E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801919E4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801919E8: lh          $t4, 0x8E($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X8E);
    // 0x801919EC: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x801919F0: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x801919F4: slti        $at, $t4, 0x3E9
    ctx->r1 = SIGNED(ctx->r12) < 0X3E9 ? 1 : 0;
    // 0x801919F8: bnel        $at, $zero, L_80191A28
    if (ctx->r1 != 0) {
        // 0x801919FC: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_80191A28;
    }
    goto skip_2;
    // 0x801919FC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_2:
    // 0x80191A00: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80191A04: lui         $t7, 0x4040
    ctx->r15 = S32(0X4040 << 16);
    // 0x80191A08: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80191A0C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80191A10: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80191A14: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80191A18: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80191A1C: b           L_80191A44
    // 0x80191A20: lh          $t2, 0x76($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X76);
        goto L_80191A44;
    // 0x80191A20: lh          $t2, 0x76($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X76);
    // 0x80191A24: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80191A28:
    // 0x80191A28: lui         $t1, 0xFF00
    ctx->r9 = S32(0XFF00 << 16);
    // 0x80191A2C: ori         $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 | 0XFF;
    // 0x80191A30: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80191A34: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80191A38: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80191A3C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80191A40: lh          $t2, 0x76($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X76);
L_80191A44:
    // 0x80191A44: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80191A48: bgtz        $t2, L_80191A58
    if (SIGNED(ctx->r10) > 0) {
        // 0x80191A4C: lui         $t3, 0x601
        ctx->r11 = S32(0X601 << 16);
            goto L_80191A58;
    }
    // 0x80191A4C: lui         $t3, 0x601
    ctx->r11 = S32(0X601 << 16);
    // 0x80191A50: addiu       $t3, $t3, -0x6440
    ctx->r11 = ADD32(ctx->r11, -0X6440);
    // 0x80191A54: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_80191A58:
    // 0x80191A58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80191A5C:
    // 0x80191A5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80191A60: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80191A64: jr          $ra
    // 0x80191A68: nop

    return;
    // 0x80191A68: nop

;}
