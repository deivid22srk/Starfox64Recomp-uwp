#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Fault_DisplayFloatReg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800077F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800077FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80007800: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80007804: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80007808: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8000780C: lui         $at, 0x7F80
    ctx->r1 = S32(0X7F80 << 16);
    // 0x80007810: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80007814: and         $v1, $v0, $at
    ctx->r3 = ctx->r2 & ctx->r1;
    // 0x80007818: srl         $t7, $v1, 23
    ctx->r15 = S32(U32(ctx->r3) >> 23);
    // 0x8000781C: addiu       $v1, $t7, -0x7F
    ctx->r3 = ADD32(ctx->r15, -0X7F);
    // 0x80007820: slti        $at, $v1, -0x7E
    ctx->r1 = SIGNED(ctx->r3) < -0X7E ? 1 : 0;
    // 0x80007824: bne         $at, $zero, L_80007834
    if (ctx->r1 != 0) {
        // 0x80007828: slti        $at, $v1, 0x80
        ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
            goto L_80007834;
    }
    // 0x80007828: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x8000782C: bnel        $at, $zero, L_80007840
    if (ctx->r1 != 0) {
        // 0x80007830: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_80007840;
    }
    goto skip_0;
    // 0x80007830: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    skip_0:
L_80007834:
    // 0x80007834: bne         $v0, $zero, L_80007864
    if (ctx->r2 != 0) {
        // 0x80007838: lui         $a2, 0x800D
        ctx->r6 = S32(0X800D << 16);
            goto L_80007864;
    }
    // 0x80007838: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8000783C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_80007840:
    // 0x80007840: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80007844: addiu       $a2, $a2, -0x7BBC
    ctx->r6 = ADD32(ctx->r6, -0X7BBC);
    // 0x80007848: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8000784C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80007850: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80007854: jal         0x8000762C
    // 0x80007858: sdc1        $f6, 0x10($sp)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X10, ctx->r29);
    Fault_Printf(rdram, ctx);
        goto after_0;
    // 0x80007858: sdc1        $f6, 0x10($sp)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X10, ctx->r29);
    after_0:
    // 0x8000785C: b           L_80007874
    // 0x80007860: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80007874;
    // 0x80007860: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80007864:
    // 0x80007864: addiu       $a2, $a2, -0x7BB0
    ctx->r6 = ADD32(ctx->r6, -0X7BB0);
    // 0x80007868: jal         0x8000762C
    // 0x8000786C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    Fault_Printf(rdram, ctx);
        goto after_1;
    // 0x8000786C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80007870: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80007874:
    // 0x80007874: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80007878: jr          $ra
    // 0x8000787C: nop

    return;
    // 0x8000787C: nop

;}
RECOMP_FUNC void Effect_Bubble_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078554: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80078558: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8007855C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80078560: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80078564: jal         0x800B8DD0
    // 0x80078568: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80078568: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_0:
    // 0x8007856C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80078570: jal         0x8005980C
    // 0x80078574: lwc1        $f12, 0x70($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_1;
    // 0x80078574: lwc1        $f12, 0x70($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X70);
    after_1:
    // 0x80078578: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8007857C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80078580: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80078584: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80078588: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8007858C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80078590: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80078594: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80078598: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8007859C: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x800785A0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800785A4: lh          $t0, 0x4A($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4A);
    // 0x800785A8: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800785AC: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x800785B0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800785B4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800785B8: lui         $t5, 0x658A
    ctx->r13 = S32(0X658A << 16);
    // 0x800785BC: ori         $t5, $t5, 0x99FF
    ctx->r13 = ctx->r13 | 0X99FF;
    // 0x800785C0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800785C4: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800785C8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800785CC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800785D0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800785D4: lui         $t8, 0x300
    ctx->r24 = S32(0X300 << 16);
    // 0x800785D8: addiu       $t8, $t8, 0x660
    ctx->r24 = ADD32(ctx->r24, 0X660);
    // 0x800785DC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800785E0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800785E4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800785E8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800785EC: jal         0x800B8DD0
    // 0x800785F0: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x800785F0: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_2:
    // 0x800785F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800785F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800785FC: jr          $ra
    // 0x80078600: nop

    return;
    // 0x80078600: nop

;}
RECOMP_FUNC void HUD_TeamShields_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086110: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80086114: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80086118: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8008611C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80086120: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80086124: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80086128: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    // 0x8008612C: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    // 0x80086130: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80086134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80086138: jal         0x800B8DD0
    // 0x8008613C: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8008613C: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    after_0:
    // 0x80086140: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80086144: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80086148: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8008614C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80086150: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80086154: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80086158: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8008615C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80086160: beq         $t0, $zero, L_800861C0
    if (ctx->r8 == 0) {
        // 0x80086164: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_800861C0;
    }
    // 0x80086164: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80086168: lwc1        $f0, 0x77BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X77BC);
    // 0x8008616C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80086170: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80086174: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80086178: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008617C: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80086180: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80086184: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80086188: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8008618C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80086190: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80086194: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80086198: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8008619C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800861A0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800861A4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800861A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800861AC: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800861B0: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800861B4: jal         0x800856C0
    // 0x800861B8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    HUD_ShieldGaugeBars_Draw(rdram, ctx);
        goto after_1;
    // 0x800861B8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x800861BC: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
L_800861C0:
    // 0x800861C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800861C4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800861C8: bgtz        $t0, L_80086304
    if (SIGNED(ctx->r8) > 0) {
        // 0x800861CC: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_80086304;
    }
    // 0x800861CC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800861D0: beq         $t0, $at, L_80086304
    if (ctx->r8 == ctx->r1) {
        // 0x800861D4: lui         $t9, 0x8017
        ctx->r25 = S32(0X8017 << 16);
            goto L_80086304;
    }
    // 0x800861D4: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800861D8: lw          $t9, 0x7854($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7854);
    // 0x800861DC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800861E0: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800861E4: beql        $t9, $at, L_8008620C
    if (ctx->r25 == ctx->r1) {
        // 0x800861E8: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8008620C;
    }
    goto skip_0;
    // 0x800861E8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_0:
    // 0x800861EC: lbu         $t1, 0x7830($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7830);
    // 0x800861F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800861F4: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800861F8: beql        $t1, $at, L_8008620C
    if (ctx->r9 == ctx->r1) {
        // 0x800861FC: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8008620C;
    }
    goto skip_1;
    // 0x800861FC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_1:
    // 0x80086200: lw          $t2, 0x7838($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7838);
    // 0x80086204: beq         $t2, $zero, L_80086304
    if (ctx->r10 == 0) {
        // 0x80086208: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80086304;
    }
    // 0x80086208: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_8008620C:
    // 0x8008620C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80086210: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80086214: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80086218: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008621C: lwc1        $f4, 0x77C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X77C0);
    // 0x80086220: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80086224: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80086228: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8008622C: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80086230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80086234: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x80086238: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8008623C: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80086240: jal         0x800B8DD0
    // 0x80086244: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x80086244: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80086248: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8008624C: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80086250: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80086254: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80086258: lui         $t5, 0xFFFF
    ctx->r13 = S32(0XFFFF << 16);
    // 0x8008625C: ori         $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 | 0XFF;
    // 0x80086260: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80086264: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80086268: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x8008626C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80086270: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80086274: bne         $t0, $zero, L_800862CC
    if (ctx->r8 != 0) {
        // 0x80086278: lui         $t6, 0x8018
        ctx->r14 = S32(0X8018 << 16);
            goto L_800862CC;
    }
    // 0x80086278: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008627C: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x80086280: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80086284: lw          $t7, 0x1C8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C8);
    // 0x80086288: bne         $t7, $at, L_800862CC
    if (ctx->r15 != ctx->r1) {
        // 0x8008628C: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_800862CC;
    }
    // 0x8008628C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80086290: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80086294: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80086298: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8008629C: addiu       $t1, $t1, 0x7720
    ctx->r9 = ADD32(ctx->r9, 0X7720);
    // 0x800862A0: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x800862A4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800862A8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800862AC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800862B0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800862B4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800862B8: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x800862BC: jal         0x800A1200
    // 0x800862C0: nop

    Graphics_DisplaySmallText(rdram, ctx);
        goto after_3;
    // 0x800862C0: nop

    after_3:
    // 0x800862C4: b           L_80086308
    // 0x800862C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80086308;
    // 0x800862C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800862CC:
    // 0x800862CC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800862D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800862D4: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800862D8: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800862DC: addiu       $t4, $t4, 0x7728
    ctx->r12 = ADD32(ctx->r12, 0X7728);
    // 0x800862E0: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x800862E4: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800862E8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800862EC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800862F0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800862F4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800862F8: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x800862FC: jal         0x800A1200
    // 0x80086300: nop

    Graphics_DisplaySmallText(rdram, ctx);
        goto after_4;
    // 0x80086300: nop

    after_4:
L_80086304:
    // 0x80086304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80086308:
    // 0x80086308: jal         0x800B8DD0
    // 0x8008630C: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_5;
    // 0x8008630C: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_5:
    // 0x80086310: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80086314: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80086318: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8008631C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80086320: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80086324: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80086328: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8008632C: lui         $a2, 0x3F51
    ctx->r6 = S32(0X3F51 << 16);
    // 0x80086330: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80086334: ori         $a2, $a2, 0xEB85
    ctx->r6 = ctx->r6 | 0XEB85;
    // 0x80086338: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8008633C: jal         0x80085618
    // 0x80086340: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    HUD_ShieldGaugeEdgeLeft_Draw(rdram, ctx);
        goto after_6;
    // 0x80086340: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    after_6:
    // 0x80086344: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80086348: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008634C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80086350: lwc1        $f4, 0x77C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X77C4);
    // 0x80086354: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80086358: lwc1        $f10, 0x77C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X77C8);
    // 0x8008635C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80086360: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80086364: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80086368: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8008636C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80086370: mul.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80086374: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80086378: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8008637C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80086380: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80086384: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80086388: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8008638C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80086390: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x80086394: jal         0x800855C4
    // 0x80086398: add.s       $f12, $f2, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f4.fl;
    HUD_ShieldGaugeEdgeRight_Draw(rdram, ctx);
        goto after_7;
    // 0x80086398: add.s       $f12, $f2, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f4.fl;
    after_7:
    // 0x8008639C: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800863A0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800863A4: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800863A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800863AC: jal         0x8008566C
    // 0x800863B0: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    HUD_ShieldGaugeFrame_Draw(rdram, ctx);
        goto after_8;
    // 0x800863B0: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    after_8:
    // 0x800863B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800863B8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800863BC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800863C0: jr          $ra
    // 0x800863C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800863C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void RCP_SetupDL_40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B99C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B99C4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800B99C8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B99CC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B99D0: addiu       $t8, $t8, 0x3CF0
    ctx->r24 = ADD32(ctx->r24, 0X3CF0);
    // 0x800B99D4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B99D8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B99DC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B99E0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B99E4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B99E8: jr          $ra
    // 0x800B99EC: nop

    return;
    // 0x800B99EC: nop

;}
RECOMP_FUNC void ActorEvent_ShootForward(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F254: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006F258: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x8006F25C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8006F260: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x8006F264: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006F268: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x8006F26C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8006F270: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006F274: lwc1        $f6, 0x6B94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6B94);
    // 0x8006F278: lwc1        $f4, 0x2EC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2EC);
    // 0x8006F27C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8006F280: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006F284: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8006F288: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8006F28C: jal         0x80005E90
    // 0x8006F290: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x8006F290: nop

    after_0:
    // 0x8006F294: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006F298: lwc1        $f16, 0x6B98($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6B98);
    // 0x8006F29C: lwc1        $f10, 0x2E8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x8006F2A0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8006F2A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006F2A8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8006F2AC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8006F2B0: jal         0x80005D44
    // 0x8006F2B4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x8006F2B4: nop

    after_1:
    // 0x8006F2B8: lwc1        $f4, 0x2F0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x8006F2BC: lwc1        $f6, 0xFC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x8006F2C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006F2C4: lwc1        $f10, 0x6B9C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6B9C);
    // 0x8006F2C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006F2CC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8006F2D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006F2D4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8006F2D8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8006F2DC: jal         0x80005FE0
    // 0x8006F2E0: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8006F2E0: nop

    after_2:
    // 0x8006F2E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006F2E8: lwc1        $f4, 0x6BA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6BA0);
    // 0x8006F2EC: lwc1        $f18, 0xF8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8006F2F0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8006F2F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006F2F8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8006F2FC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8006F300: jal         0x80005E90
    // 0x8006F304: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x8006F304: nop

    after_3:
    // 0x8006F308: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006F30C: lwc1        $f10, 0x6BA4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6BA4);
    // 0x8006F310: lwc1        $f8, 0xF4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8006F314: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8006F318: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006F31C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8006F320: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8006F324: jal         0x80005D44
    // 0x8006F328: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x8006F328: nop

    after_4:
    // 0x8006F32C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8006F330: lhu         $t6, 0x7828($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X7828);
    // 0x8006F334: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006F338: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8006F33C: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8006F340: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x8006F344: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8006F348: bgez        $t6, L_8006F360
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8006F34C: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_8006F360;
    }
    // 0x8006F34C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006F350: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006F354: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006F358: nop

    // 0x8006F35C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_8006F360:
    // 0x8006F360: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x8006F364: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8006F368: jal         0x80006A20
    // 0x8006F36C: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_5;
    // 0x8006F36C: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_5:
    // 0x8006F370: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006F374: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8006F378: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006F37C: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8006F380: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8006F384: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006F388: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006F38C: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8006F390: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8006F394: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8006F398: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    // 0x8006F39C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8006F3A0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006F3A4: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8006F3A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8006F3AC: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006F3B0: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8006F3B4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8006F3B8: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006F3BC: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8006F3C0: lwc1        $f4, 0x2E8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x8006F3C4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8006F3C8: lwc1        $f8, 0x2EC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2EC);
    // 0x8006F3CC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8006F3D0: lwc1        $f4, 0xFC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x8006F3D4: lwc1        $f18, 0x2F0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x8006F3D8: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8006F3DC: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8006F3E0: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8006F3E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006F3E8: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8006F3EC: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8006F3F0: jal         0x8007F04C
    // 0x8006F3F4: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    Effect_SpawnById2(rdram, ctx);
        goto after_6;
    // 0x8006F3F4: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x8006F3F8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8006F3FC: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x8006F400: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x8006F404: jr          $ra
    // 0x8006F408: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8006F408: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void AudioLoad_GetLoadTableIndex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000F794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F798: jal         0x8000F820
    // 0x8000F79C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    AudioLoad_GetLoadTable(rdram, ctx);
        goto after_0;
    // 0x8000F79C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000F7A0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F7A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F7A8: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x8000F7AC: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x8000F7B0: lw          $t7, 0x14($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X14);
    // 0x8000F7B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000F7B8: bne         $t7, $zero, L_8000F7C4
    if (ctx->r15 != 0) {
        // 0x8000F7BC: nop
    
            goto L_8000F7C4;
    }
    // 0x8000F7BC: nop

    // 0x8000F7C0: lw          $a1, 0x10($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X10);
L_8000F7C4:
    // 0x8000F7C4: jr          $ra
    // 0x8000F7C8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x8000F7C8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void AudioLoad_SyncLoadSample(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ED28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000ED2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000ED30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000ED34: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8000ED38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000ED3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000ED40: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8000ED44: bnel        $t7, $at, L_8000EE04
    if (ctx->r15 != ctx->r1) {
        // 0x8000ED48: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000EE04;
    }
    goto skip_0;
    // 0x8000ED48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8000ED4C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8000ED50: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000ED54: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000ED58: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8000ED5C: srl         $t8, $v1, 30
    ctx->r24 = S32(U32(ctx->r3) >> 30);
    // 0x8000ED60: beq         $t8, $zero, L_8000EE00
    if (ctx->r24 == 0) {
        // 0x8000ED64: and         $a0, $v0, $at
        ctx->r4 = ctx->r2 & ctx->r1;
            goto L_8000EE00;
    }
    // 0x8000ED64: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    // 0x8000ED68: sll         $a3, $t8, 24
    ctx->r7 = S32(ctx->r24 << 24);
    // 0x8000ED6C: sra         $t9, $a3, 24
    ctx->r25 = S32(SIGNED(ctx->r7) >> 24);
    // 0x8000ED70: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x8000ED74: jal         0x8000DC34
    // 0x8000ED78: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    AudioHeap_AllocPersistentSampleCache(rdram, ctx);
        goto after_0;
    // 0x8000ED78: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_0:
    // 0x8000ED7C: bne         $v0, $zero, L_8000ED8C
    if (ctx->r2 != 0) {
        // 0x8000ED80: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000ED8C;
    }
    // 0x8000ED80: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000ED84: b           L_8000EE00
    // 0x8000ED88: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000EE00;
    // 0x8000ED88: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000ED8C:
    // 0x8000ED8C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000ED90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000ED94: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8000ED98: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x8000ED9C: srl         $t0, $v1, 30
    ctx->r8 = S32(U32(ctx->r3) >> 30);
    // 0x8000EDA0: bne         $t0, $at, L_8000EDD0
    if (ctx->r8 != ctx->r1) {
        // 0x8000EDA4: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_8000EDD0;
    }
    // 0x8000EDA4: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8000EDA8: lw          $t1, 0x5C64($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X5C64);
    // 0x8000EDAC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000EDB0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000EDB4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8000EDB8: lh          $a3, 0x2($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X2);
    // 0x8000EDBC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000EDC0: jal         0x8000FB50
    // 0x8000EDC4: and         $a2, $v0, $at
    ctx->r6 = ctx->r2 & ctx->r1;
    AudioLoad_SyncDmaUnkMedium(rdram, ctx);
        goto after_1;
    // 0x8000EDC4: and         $a2, $v0, $at
    ctx->r6 = ctx->r2 & ctx->r1;
    after_1:
    // 0x8000EDC8: b           L_8000EDF0
    // 0x8000EDCC: lbu         $t2, 0x0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X0);
        goto L_8000EDF0;
    // 0x8000EDCC: lbu         $t2, 0x0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X0);
L_8000EDD0:
    // 0x8000EDD0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8000EDD4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000EDD8: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8000EDDC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000EDE0: and         $a2, $v0, $at
    ctx->r6 = ctx->r2 & ctx->r1;
    // 0x8000EDE4: jal         0x8000FA28
    // 0x8000EDE8: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    AudioLoad_SyncDma(rdram, ctx);
        goto after_2;
    // 0x8000EDE8: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_2:
    // 0x8000EDEC: lbu         $t2, 0x0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X0);
L_8000EDF0:
    // 0x8000EDF0: andi        $t3, $t2, 0xFFF3
    ctx->r11 = ctx->r10 & 0XFFF3;
    // 0x8000EDF4: sb          $t3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r11;
    // 0x8000EDF8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8000EDFC: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
L_8000EE00:
    // 0x8000EE00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000EE04:
    // 0x8000EE04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000EE08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000EE0C: jr          $ra
    // 0x8000EE10: nop

    return;
    // 0x8000EE10: nop

;}
RECOMP_FUNC void Audio_UpdatePlayerNoise(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BC20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001BC24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001BC28: jal         0x8001BA40
    // 0x8001BC2C: nop

    Audio_UpdatePlayerFreqMod(rdram, ctx);
        goto after_0;
    // 0x8001BC2C: nop

    after_0:
    // 0x8001BC30: jal         0x8001BB74
    // 0x8001BC34: nop

    Audio_UpdatePlayerReverb(rdram, ctx);
        goto after_1;
    // 0x8001BC34: nop

    after_1:
    // 0x8001BC38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001BC3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001BC40: jr          $ra
    // 0x8001BC44: nop

    return;
    // 0x8001BC44: nop

;}
RECOMP_FUNC void __osGetActiveQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024D50: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80024D54: jr          $ra
    // 0x80024D58: lw          $v0, 0x7EAC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7EAC);
    return;
    // 0x80024D58: lw          $v0, 0x7EAC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7EAC);
;}
RECOMP_FUNC void Effect_Effect376_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080360: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80080364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80080368: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008036C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80080370: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80080374: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80080378: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008037C: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80080380: lh          $t6, 0x4A($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X4A);
    // 0x80080384: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080388: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8008038C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80080390: lwc1        $f10, 0x70($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X70);
    // 0x80080394: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80080398: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008039C: swc1        $f8, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f8.u32l;
    // 0x800803A0: lwc1        $f16, 0x74D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X74D4);
    // 0x800803A4: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x800803A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800803AC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800803B0: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x800803B4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800803B8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800803BC: swc1        $f18, 0x70($a1)
    MEM_W(0X70, ctx->r5) = ctx->f18.u32l;
    // 0x800803C0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800803C4: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x800803C8: nop

    // 0x800803CC: sh          $t8, 0x4A($a1)
    MEM_H(0X4A, ctx->r5) = ctx->r24;
    // 0x800803D0: lh          $t9, 0x4A($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X4A);
    // 0x800803D4: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800803D8: nop

    // 0x800803DC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800803E0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800803E4: nop

    // 0x800803E8: bc1f        L_800803F4
    if (!c1cs) {
        // 0x800803EC: nop
    
            goto L_800803F4;
    }
    // 0x800803EC: nop

    // 0x800803F0: sh          $t0, 0x4A($a1)
    MEM_H(0X4A, ctx->r5) = ctx->r8;
L_800803F4:
    // 0x800803F4: jal         0x8007A774
    // 0x800803F8: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    Effect_CheckPlayerCollision(rdram, ctx);
        goto after_0;
    // 0x800803F8: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    after_0:
    // 0x800803FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80080400: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80080404: jr          $ra
    // 0x80080408: nop

    return;
    // 0x80080408: nop

;}
RECOMP_FUNC void Effect_Effect357_Spawn95(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800795AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800795B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800795B4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800795B8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800795BC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800795C0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800795C4: addiu       $v0, $v0, 0x3524
    ctx->r2 = ADD32(ctx->r2, 0X3524);
    // 0x800795C8: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x800795CC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_800795D0:
    // 0x800795D0: bnel        $t6, $zero, L_80079600
    if (ctx->r14 != 0) {
        // 0x800795D4: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_80079600;
    }
    goto skip_0;
    // 0x800795D4: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x800795D8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800795DC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800795E0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800795E4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800795E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800795EC: jal         0x8007905C
    // 0x800795F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Effect_Effect357_Setup(rdram, ctx);
        goto after_0;
    // 0x800795F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800795F4: b           L_8007960C
    // 0x800795F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007960C;
    // 0x800795F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800795FC: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_80079600:
    // 0x80079600: bnel        $a0, $v0, L_800795D0
    if (ctx->r4 != ctx->r2) {
        // 0x80079604: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_800795D0;
    }
    goto skip_1;
    // 0x80079604: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x80079608: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007960C:
    // 0x8007960C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80079610: jr          $ra
    // 0x80079614: nop

    return;
    // 0x80079614: nop

;}
RECOMP_FUNC void Audio_UpdatePlayerFreqMod(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BA40: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8001BA44: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8001BA48: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8001BA4C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8001BA50: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8001BA54: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8001BA58: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8001BA5C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8001BA60: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8001BA64: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8001BA68: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8001BA6C: lui         $s2, 0x8015
    ctx->r18 = S32(0X8015 << 16);
    // 0x8001BA70: lui         $s7, 0x8018
    ctx->r23 = S32(0X8018 << 16);
    // 0x8001BA74: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8001BA78: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8001BA7C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8001BA80: addiu       $s7, $s7, -0x7D80
    ctx->r23 = ADD32(ctx->r23, -0X7D80);
    // 0x8001BA84: addiu       $s2, $s2, -0x47B0
    ctx->r18 = ADD32(ctx->r18, -0X47B0);
    // 0x8001BA88: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001BA8C: addiu       $s3, $zero, 0x70
    ctx->r19 = ADD32(0, 0X70);
    // 0x8001BA90: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8001BA94: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x8001BA98: addiu       $s6, $zero, 0xFF
    ctx->r22 = ADD32(0, 0XFF);
    // 0x8001BA9C: addiu       $fp, $zero, 0x4E0
    ctx->r30 = ADD32(0, 0X4E0);
L_8001BAA0:
    // 0x8001BAA0: multu       $s1, $s3
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001BAA4: mflo        $t6
    ctx->r14 = lo;
    // 0x8001BAA8: addu        $s0, $s2, $t6
    ctx->r16 = ADD32(ctx->r18, ctx->r14);
    // 0x8001BAAC: lbu         $v0, 0x6C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X6C);
    // 0x8001BAB0: beq         $v0, $zero, L_8001BAD8
    if (ctx->r2 == 0) {
        // 0x8001BAB4: nop
    
            goto L_8001BAD8;
    }
    // 0x8001BAB4: nop

    // 0x8001BAB8: beq         $v0, $s4, L_8001BB14
    if (ctx->r2 == ctx->r20) {
        // 0x8001BABC: nop
    
            goto L_8001BB14;
    }
    // 0x8001BABC: nop

    // 0x8001BAC0: beq         $v0, $s5, L_8001BB24
    if (ctx->r2 == ctx->r21) {
        // 0x8001BAC4: nop
    
            goto L_8001BB24;
    }
    // 0x8001BAC4: nop

    // 0x8001BAC8: beql        $v0, $s6, L_8001BB30
    if (ctx->r2 == ctx->r22) {
        // 0x8001BACC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8001BB30;
    }
    goto skip_0;
    // 0x8001BACC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8001BAD0: b           L_8001BB30
    // 0x8001BAD4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_8001BB30;
    // 0x8001BAD4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8001BAD8:
    // 0x8001BAD8: jal         0x8001B014
    // 0x8001BADC: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    Audio_UpdateArwingNoise(rdram, ctx);
        goto after_0;
    // 0x8001BADC: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_0:
    // 0x8001BAE0: multu       $s1, $fp
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001BAE4: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x8001BAE8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8001BAEC: addiu       $a3, $s0, 0x64
    ctx->r7 = ADD32(ctx->r16, 0X64);
    // 0x8001BAF0: mflo        $t8
    ctx->r24 = lo;
    // 0x8001BAF4: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8001BAF8: lw          $a0, 0x47C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X47C);
    // 0x8001BAFC: jal         0x80017360
    // 0x8001BB00: lw          $a1, 0x480($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X480);
    Audio_UpdateDopplerShift(rdram, ctx);
        goto after_1;
    // 0x8001BB00: lw          $a1, 0x480($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X480);
    after_1:
    // 0x8001BB04: lwc1        $f4, 0x68($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X68);
    // 0x8001BB08: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001BB0C: b           L_8001BB2C
    // 0x8001BB10: swc1        $f6, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f6.u32l;
        goto L_8001BB2C;
    // 0x8001BB10: swc1        $f6, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f6.u32l;
L_8001BB14:
    // 0x8001BB14: jal         0x8001B454
    // 0x8001BB18: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    Audio_UpdateLandmasterNoise(rdram, ctx);
        goto after_2;
    // 0x8001BB18: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_2:
    // 0x8001BB1C: b           L_8001BB30
    // 0x8001BB20: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_8001BB30;
    // 0x8001BB20: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8001BB24:
    // 0x8001BB24: jal         0x8001B774
    // 0x8001BB28: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    Audio_UpdateBlueMarineNoise(rdram, ctx);
        goto after_3;
    // 0x8001BB28: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_3:
L_8001BB2C:
    // 0x8001BB2C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8001BB30:
    // 0x8001BB30: andi        $t9, $s1, 0xFF
    ctx->r25 = ctx->r17 & 0XFF;
    // 0x8001BB34: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x8001BB38: bne         $at, $zero, L_8001BAA0
    if (ctx->r1 != 0) {
        // 0x8001BB3C: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_8001BAA0;
    }
    // 0x8001BB3C: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8001BB40: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8001BB44: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8001BB48: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8001BB4C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8001BB50: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8001BB54: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8001BB58: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8001BB5C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8001BB60: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8001BB64: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8001BB68: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8001BB6C: jr          $ra
    // 0x8001BB70: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8001BB70: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_col1_8009893C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009893C: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80098940: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80098944: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80098948: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8009894C: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80098950: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80098954: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80098958: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8009895C: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80098960: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80098964: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80098968: div.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8009896C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80098970: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80098974: nop

    // 0x80098978: jr          $ra
    // 0x8009897C: nop

    return;
    // 0x8009897C: nop

;}
RECOMP_FUNC void Audio_SeqCmdNotQueued(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018410: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x80018414: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80018418: lbu         $a1, 0x5D44($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X5D44);
    // 0x8001841C: lbu         $v0, 0x5D48($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5D48);
    // 0x80018420: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80018424: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x80018428: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8001842C: beq         $at, $zero, L_80018468
    if (ctx->r1 == 0) {
        // 0x80018430: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80018468;
    }
    // 0x80018430: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80018434: addiu       $a3, $a3, -0x5658
    ctx->r7 = ADD32(ctx->r7, -0X5658);
L_80018438:
    // 0x80018438: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001843C: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x80018440: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80018444: bnel        $a0, $t8, L_80018458
    if (ctx->r4 != ctx->r24) {
        // 0x80018448: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80018458;
    }
    goto skip_0;
    // 0x80018448: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x8001844C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80018450: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80018454: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80018458:
    // 0x80018458: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8001845C: slt         $at, $t9, $a2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80018460: bne         $at, $zero, L_80018438
    if (ctx->r1 != 0) {
        // 0x80018464: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80018438;
    }
    // 0x80018464: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80018468:
    // 0x80018468: jr          $ra
    // 0x8001846C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8001846C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void Effect_BlueOrb_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800802B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800802BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800802C0: jal         0x8007FE88
    // 0x800802C4: nop

    Effect_EnemyShot_Update(rdram, ctx);
        goto after_0;
    // 0x800802C4: nop

    after_0:
    // 0x800802C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800802CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800802D0: jr          $ra
    // 0x800802D4: nop

    return;
    // 0x800802D4: nop

;}
RECOMP_FUNC void Versus_UpdatePlayerStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF17C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800BF180: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800BF184: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800BF188: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800BF18C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800BF190: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800BF194: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800BF198: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800BF19C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800BF1A0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800BF1A4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800BF1A8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800BF1AC: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800BF1B0: lui         $s6, 0x8018
    ctx->r22 = S32(0X8018 << 16);
    // 0x800BF1B4: lui         $fp, 0x8018
    ctx->r30 = S32(0X8018 << 16);
    // 0x800BF1B8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800BF1BC: addiu       $fp, $fp, -0x7D80
    ctx->r30 = ADD32(ctx->r30, -0X7D80);
    // 0x800BF1C0: addiu       $s6, $s6, -0x77B0
    ctx->r22 = ADD32(ctx->r22, -0X77B0);
    // 0x800BF1C4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800BF1C8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800BF1CC: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800BF1D0: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800BF1D4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800BF1D8:
    // 0x800BF1D8: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x800BF1DC: sw          $s3, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r19;
    // 0x800BF1E0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800BF1E4: addu        $v1, $t6, $s7
    ctx->r3 = ADD32(ctx->r14, ctx->r23);
    // 0x800BF1E8: lw          $t7, 0x1C8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1C8);
    // 0x800BF1EC: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800BF1F0: addiu       $t8, $zero, 0x96
    ctx->r24 = ADD32(0, 0X96);
    // 0x800BF1F4: beq         $t7, $at, L_800BF210
    if (ctx->r15 == ctx->r1) {
        // 0x800BF1F8: addu        $t9, $t9, $s2
        ctx->r25 = ADD32(ctx->r25, ctx->r18);
            goto L_800BF210;
    }
    // 0x800BF1F8: addu        $t9, $t9, $s2
    ctx->r25 = ADD32(ctx->r25, ctx->r18);
    // 0x800BF1FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BF200: sw          $zero, 0x0($s6)
    MEM_W(0X0, ctx->r22) = 0;
    // 0x800BF204: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x800BF208: b           L_800BF54C
    // 0x800BF20C: sw          $t8, -0x7808($at)
    MEM_W(-0X7808, ctx->r1) = ctx->r24;
        goto L_800BF54C;
    // 0x800BF20C: sw          $t8, -0x7808($at)
    MEM_W(-0X7808, ctx->r1) = ctx->r24;
L_800BF210:
    // 0x800BF210: lw          $t9, 0x1A18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1A18);
    // 0x800BF214: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800BF218: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800BF21C: bne         $t9, $zero, L_800BF278
    if (ctx->r25 != 0) {
        // 0x800BF220: addiu       $t4, $t4, -0x7828
        ctx->r12 = ADD32(ctx->r12, -0X7828);
            goto L_800BF278;
    }
    // 0x800BF220: addiu       $t4, $t4, -0x7828
    ctx->r12 = ADD32(ctx->r12, -0X7828);
    // 0x800BF224: lw          $v0, 0x78AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78AC);
    // 0x800BF228: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800BF22C: beq         $s3, $v0, L_800BF278
    if (ctx->r19 == ctx->r2) {
        // 0x800BF230: nop
    
            goto L_800BF278;
    }
    // 0x800BF230: nop

    // 0x800BF234: lw          $t0, -0x784C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X784C);
    // 0x800BF238: bne         $s3, $t0, L_800BF248
    if (ctx->r19 != ctx->r8) {
        // 0x800BF23C: nop
    
            goto L_800BF248;
    }
    // 0x800BF23C: nop

    // 0x800BF240: bne         $s5, $v0, L_800BF278
    if (ctx->r21 != ctx->r2) {
        // 0x800BF244: nop
    
            goto L_800BF278;
    }
    // 0x800BF244: nop

L_800BF248:
    // 0x800BF248: bne         $s5, $v0, L_800BF2F8
    if (ctx->r21 != ctx->r2) {
        // 0x800BF24C: lui         $t8, 0x8018
        ctx->r24 = S32(0X8018 << 16);
            goto L_800BF2F8;
    }
    // 0x800BF24C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800BF250: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800BF254: addiu       $v0, $v0, -0x7898
    ctx->r2 = ADD32(ctx->r2, -0X7898);
    // 0x800BF258: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800BF25C: bne         $t1, $zero, L_800BF2F8
    if (ctx->r9 != 0) {
        // 0x800BF260: nop
    
            goto L_800BF2F8;
    }
    // 0x800BF260: nop

    // 0x800BF264: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x800BF268: bne         $t2, $zero, L_800BF2F8
    if (ctx->r10 != 0) {
        // 0x800BF26C: nop
    
            goto L_800BF2F8;
    }
    // 0x800BF26C: nop

    // 0x800BF270: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x800BF274: bne         $t3, $zero, L_800BF2F8
    if (ctx->r11 != 0) {
        // 0x800BF278: lui         $t5, 0x8018
        ctx->r13 = S32(0X8018 << 16);
            goto L_800BF2F8;
    }
L_800BF278:
    // 0x800BF278: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800BF27C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BF280: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BF284: addiu       $t5, $t5, -0x7818
    ctx->r13 = ADD32(ctx->r13, -0X7818);
    // 0x800BF288: addu        $s0, $s2, $t5
    ctx->r16 = ADD32(ctx->r18, ctx->r13);
    // 0x800BF28C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800BF290: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800BF294: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800BF298: addu        $a0, $s2, $t4
    ctx->r4 = ADD32(ctx->r18, ctx->r12);
    // 0x800BF29C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800BF2A0: jal         0x8009BC2C
    // 0x800BF2A4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800BF2A4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800BF2A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800BF2AC: nop

    // 0x800BF2B0: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x800BF2B4: nop

    // 0x800BF2B8: bc1fl       L_800BF2EC
    if (!c1cs) {
        // 0x800BF2BC: lw          $t6, 0x0($fp)
        ctx->r14 = MEM_W(ctx->r30, 0X0);
            goto L_800BF2EC;
    }
    goto skip_0;
    // 0x800BF2BC: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    skip_0:
    // 0x800BF2C0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800BF2C4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800BF2C8: c.eq.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl == ctx->f8.fl;
    // 0x800BF2CC: nop

    // 0x800BF2D0: bc1fl       L_800BF2E8
    if (!c1cs) {
        // 0x800BF2D4: swc1        $f20, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
            goto L_800BF2E8;
    }
    goto skip_1;
    // 0x800BF2D4: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
    skip_1:
    // 0x800BF2D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BF2DC: b           L_800BF2E8
    // 0x800BF2E0: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
        goto L_800BF2E8;
    // 0x800BF2E0: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x800BF2E4: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
L_800BF2E8:
    // 0x800BF2E8: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
L_800BF2EC:
    // 0x800BF2EC: addu        $t7, $t6, $s7
    ctx->r15 = ADD32(ctx->r14, ctx->r23);
    // 0x800BF2F0: b           L_800BF54C
    // 0x800BF2F4: sw          $zero, 0x1D0($t7)
    MEM_W(0X1D0, ctx->r15) = 0;
        goto L_800BF54C;
    // 0x800BF2F4: sw          $zero, 0x1D0($t7)
    MEM_W(0X1D0, ctx->r15) = 0;
L_800BF2F8:
    // 0x800BF2F8: addiu       $t8, $t8, -0x7880
    ctx->r24 = ADD32(ctx->r24, -0X7880);
    // 0x800BF2FC: addu        $s0, $s2, $t8
    ctx->r16 = ADD32(ctx->r18, ctx->r24);
    // 0x800BF300: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800BF304: sw          $zero, 0x1D0($v1)
    MEM_W(0X1D0, ctx->r3) = 0;
    // 0x800BF308: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800BF30C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BF310: addiu       $t9, $t9, -0x7808
    ctx->r25 = ADD32(ctx->r25, -0X7808);
    // 0x800BF314: bne         $t0, $zero, L_800BF3AC
    if (ctx->r8 != 0) {
        // 0x800BF318: addu        $s1, $s2, $t9
        ctx->r17 = ADD32(ctx->r18, ctx->r25);
            goto L_800BF3AC;
    }
    // 0x800BF318: addu        $s1, $s2, $t9
    ctx->r17 = ADD32(ctx->r18, ctx->r25);
    // 0x800BF31C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x800BF320: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BF324: bnel        $t1, $zero, L_800BF3B0
    if (ctx->r9 != 0) {
        // 0x800BF328: lw          $v0, 0x0($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X0);
            goto L_800BF3B0;
    }
    goto skip_2;
    // 0x800BF328: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x800BF32C: lw          $a0, -0x78A4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78A4);
    // 0x800BF330: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800BF334: beq         $a0, $zero, L_800BF378
    if (ctx->r4 == 0) {
        // 0x800BF338: nop
    
            goto L_800BF378;
    }
    // 0x800BF338: nop

    // 0x800BF33C: lw          $t2, -0x78A0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X78A0);
    // 0x800BF340: beq         $t2, $zero, L_800BF378
    if (ctx->r10 == 0) {
        // 0x800BF344: nop
    
            goto L_800BF378;
    }
    // 0x800BF344: nop

    // 0x800BF348: jal         0x80004EB0
    // 0x800BF34C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x800BF34C: nop

    after_1:
    // 0x800BF350: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800BF354: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800BF358: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BF35C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800BF360: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800BF364: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x800BF368: nop

    // 0x800BF36C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800BF370: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800BF374: lw          $a0, -0x78A4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78A4);
L_800BF378:
    // 0x800BF378: beq         $a0, $zero, L_800BF3AC
    if (ctx->r4 == 0) {
        // 0x800BF37C: lui         $t6, 0x8018
        ctx->r14 = S32(0X8018 << 16);
            goto L_800BF3AC;
    }
    // 0x800BF37C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800BF380: lw          $t6, -0x78A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X78A0);
    // 0x800BF384: bnel        $t6, $zero, L_800BF3B0
    if (ctx->r14 != 0) {
        // 0x800BF388: lw          $v0, 0x0($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X0);
            goto L_800BF3B0;
    }
    goto skip_3;
    // 0x800BF388: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    skip_3:
    // 0x800BF38C: jal         0x80004EB0
    // 0x800BF390: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x800BF390: nop

    after_2:
    // 0x800BF394: add.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800BF398: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800BF39C: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800BF3A0: nop

    // 0x800BF3A4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800BF3A8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
L_800BF3AC:
    // 0x800BF3AC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_800BF3B0:
    // 0x800BF3B0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800BF3B4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BF3B8: lw          $a1, -0x78A0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X78A0);
    // 0x800BF3BC: lw          $a0, -0x78A4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78A4);
    // 0x800BF3C0: beq         $v0, $zero, L_800BF3D0
    if (ctx->r2 == 0) {
        // 0x800BF3C4: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_800BF3D0;
    }
    // 0x800BF3C4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800BF3C8: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x800BF3CC: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
L_800BF3D0:
    // 0x800BF3D0: beq         $a0, $zero, L_800BF408
    if (ctx->r4 == 0) {
        // 0x800BF3D4: sll         $t0, $s4, 2
        ctx->r8 = S32(ctx->r20 << 2);
            goto L_800BF408;
    }
    // 0x800BF3D4: sll         $t0, $s4, 2
    ctx->r8 = S32(ctx->r20 << 2);
    // 0x800BF3D8: bne         $v1, $zero, L_800BF408
    if (ctx->r3 != 0) {
        // 0x800BF3DC: sll         $t1, $s4, 2
        ctx->r9 = S32(ctx->r20 << 2);
            goto L_800BF408;
    }
    // 0x800BF3DC: sll         $t1, $s4, 2
    ctx->r9 = S32(ctx->r20 << 2);
    // 0x800BF3E0: subu        $t1, $t1, $s4
    ctx->r9 = SUB32(ctx->r9, ctx->r20);
    // 0x800BF3E4: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x800BF3E8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BF3EC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800BF3F0: lhu         $t2, -0x2768($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X2768);
    // 0x800BF3F4: andi        $t3, $t2, 0x4000
    ctx->r11 = ctx->r10 & 0X4000;
    // 0x800BF3F8: beq         $t3, $zero, L_800BF408
    if (ctx->r11 == 0) {
        // 0x800BF3FC: nop
    
            goto L_800BF408;
    }
    // 0x800BF3FC: nop

    // 0x800BF400: sw          $s5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r21;
    // 0x800BF404: or          $v1, $s5, $zero
    ctx->r3 = ctx->r21 | 0;
L_800BF408:
    // 0x800BF408: beq         $a1, $zero, L_800BF458
    if (ctx->r5 == 0) {
        // 0x800BF40C: subu        $t0, $t0, $s4
        ctx->r8 = SUB32(ctx->r8, ctx->r20);
            goto L_800BF458;
    }
    // 0x800BF40C: subu        $t0, $t0, $s4
    ctx->r8 = SUB32(ctx->r8, ctx->r20);
    // 0x800BF410: bne         $v1, $zero, L_800BF458
    if (ctx->r3 != 0) {
        // 0x800BF414: sll         $t4, $s4, 2
        ctx->r12 = S32(ctx->r20 << 2);
            goto L_800BF458;
    }
    // 0x800BF414: sll         $t4, $s4, 2
    ctx->r12 = S32(ctx->r20 << 2);
    // 0x800BF418: subu        $t4, $t4, $s4
    ctx->r12 = SUB32(ctx->r12, ctx->r20);
    // 0x800BF41C: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x800BF420: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800BF424: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x800BF428: lhu         $v0, -0x2768($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2768);
    // 0x800BF42C: andi        $t5, $v0, 0x2
    ctx->r13 = ctx->r2 & 0X2;
    // 0x800BF430: bne         $t5, $zero, L_800BF450
    if (ctx->r13 != 0) {
        // 0x800BF434: andi        $t6, $v0, 0x4
        ctx->r14 = ctx->r2 & 0X4;
            goto L_800BF450;
    }
    // 0x800BF434: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x800BF438: bne         $t6, $zero, L_800BF450
    if (ctx->r14 != 0) {
        // 0x800BF43C: andi        $t7, $v0, 0x8
        ctx->r15 = ctx->r2 & 0X8;
            goto L_800BF450;
    }
    // 0x800BF43C: andi        $t7, $v0, 0x8
    ctx->r15 = ctx->r2 & 0X8;
    // 0x800BF440: bne         $t7, $zero, L_800BF450
    if (ctx->r15 != 0) {
        // 0x800BF444: andi        $t8, $v0, 0x1
        ctx->r24 = ctx->r2 & 0X1;
            goto L_800BF450;
    }
    // 0x800BF444: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x800BF448: beq         $t8, $zero, L_800BF458
    if (ctx->r24 == 0) {
        // 0x800BF44C: nop
    
            goto L_800BF458;
    }
    // 0x800BF44C: nop

L_800BF450:
    // 0x800BF450: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x800BF454: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
L_800BF458:
    // 0x800BF458: bne         $v1, $zero, L_800BF47C
    if (ctx->r3 != 0) {
        // 0x800BF45C: sll         $t0, $t0, 1
        ctx->r8 = S32(ctx->r8 << 1);
            goto L_800BF47C;
    }
    // 0x800BF45C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x800BF460: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BF464: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800BF468: lhu         $t1, -0x2768($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2768);
    // 0x800BF46C: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x800BF470: beq         $t2, $zero, L_800BF47C
    if (ctx->r10 == 0) {
        // 0x800BF474: nop
    
            goto L_800BF47C;
    }
    // 0x800BF474: nop

    // 0x800BF478: sw          $s3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r19;
L_800BF47C:
    // 0x800BF47C: bne         $a0, $zero, L_800BF48C
    if (ctx->r4 != 0) {
        // 0x800BF480: lui         $t3, 0x8017
        ctx->r11 = S32(0X8017 << 16);
            goto L_800BF48C;
    }
    // 0x800BF480: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800BF484: beql        $a1, $zero, L_800BF49C
    if (ctx->r5 == 0) {
        // 0x800BF488: sw          $zero, 0x0($s6)
        MEM_W(0X0, ctx->r22) = 0;
            goto L_800BF49C;
    }
    goto skip_4;
    // 0x800BF488: sw          $zero, 0x0($s6)
    MEM_W(0X0, ctx->r22) = 0;
    skip_4:
L_800BF48C:
    // 0x800BF48C: lw          $t3, 0x789C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X789C);
    // 0x800BF490: bnel        $s5, $t3, L_800BF4A4
    if (ctx->r21 != ctx->r11) {
        // 0x800BF494: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_800BF4A4;
    }
    goto skip_5;
    // 0x800BF494: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_5:
    // 0x800BF498: sw          $zero, 0x0($s6)
    MEM_W(0X0, ctx->r22) = 0;
L_800BF49C:
    // 0x800BF49C: sw          $s3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r19;
    // 0x800BF4A0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_800BF4A4:
    // 0x800BF4A4: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800BF4A8: addiu       $t4, $t4, 0x7870
    ctx->r12 = ADD32(ctx->r12, 0X7870);
    // 0x800BF4AC: beq         $v1, $zero, L_800BF54C
    if (ctx->r3 == 0) {
        // 0x800BF4B0: addu        $a0, $s2, $t4
        ctx->r4 = ADD32(ctx->r18, ctx->r12);
            goto L_800BF54C;
    }
    // 0x800BF4B0: addu        $a0, $s2, $t4
    ctx->r4 = ADD32(ctx->r18, ctx->r12);
    // 0x800BF4B4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800BF4B8: addiu       $t5, $t5, -0x77E0
    ctx->r13 = ADD32(ctx->r13, -0X77E0);
    // 0x800BF4BC: beq         $v1, $s3, L_800BF4DC
    if (ctx->r3 == ctx->r19) {
        // 0x800BF4C0: addu        $a1, $s2, $t5
        ctx->r5 = ADD32(ctx->r18, ctx->r13);
            goto L_800BF4DC;
    }
    // 0x800BF4C0: addu        $a1, $s2, $t5
    ctx->r5 = ADD32(ctx->r18, ctx->r13);
    // 0x800BF4C4: beq         $v1, $s5, L_800BF4E4
    if (ctx->r3 == ctx->r21) {
        // 0x800BF4C8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800BF4E4;
    }
    // 0x800BF4C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800BF4CC: beq         $v1, $at, L_800BF4EC
    if (ctx->r3 == ctx->r1) {
        // 0x800BF4D0: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_800BF4EC;
    }
    // 0x800BF4D0: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800BF4D4: b           L_800BF4F0
    // 0x800BF4D8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_800BF4F0;
    // 0x800BF4D8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_800BF4DC:
    // 0x800BF4DC: b           L_800BF4F0
    // 0x800BF4E0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_800BF4F0;
    // 0x800BF4E0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_800BF4E4:
    // 0x800BF4E4: b           L_800BF4F0
    // 0x800BF4E8: sw          $s3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r19;
        goto L_800BF4F0;
    // 0x800BF4E8: sw          $s3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r19;
L_800BF4EC:
    // 0x800BF4EC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_800BF4F0:
    // 0x800BF4F0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800BF4F4: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800BF4F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BF4FC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BF500: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800BF504: lw          $t9, 0x78AC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78AC);
    // 0x800BF508: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x800BF50C: sll         $v0, $s4, 1
    ctx->r2 = S32(ctx->r20 << 1);
    // 0x800BF510: bnel        $s5, $t9, L_800BF544
    if (ctx->r21 != ctx->r25) {
        // 0x800BF514: lw          $t0, 0x0($fp)
        ctx->r8 = MEM_W(ctx->r30, 0X0);
            goto L_800BF544;
    }
    goto skip_6;
    // 0x800BF514: lw          $t0, 0x0($fp)
    ctx->r8 = MEM_W(ctx->r30, 0X0);
    skip_6:
    // 0x800BF518: sw          $zero, -0x77F0($at)
    MEM_W(-0X77F0, ctx->r1) = 0;
    // 0x800BF51C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BF520: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800BF524: sh          $zero, -0x77F8($at)
    MEM_H(-0X77F8, ctx->r1) = 0;
    // 0x800BF528: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BF52C: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x800BF530: sw          $zero, -0x77C8($at)
    MEM_W(-0X77C8, ctx->r1) = 0;
    // 0x800BF534: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BF538: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800BF53C: sh          $zero, 0x7C30($at)
    MEM_H(0X7C30, ctx->r1) = 0;
    // 0x800BF540: lw          $t0, 0x0($fp)
    ctx->r8 = MEM_W(ctx->r30, 0X0);
L_800BF544:
    // 0x800BF544: addu        $t1, $t0, $s7
    ctx->r9 = ADD32(ctx->r8, ctx->r23);
    // 0x800BF548: sw          $s3, 0x1D0($t1)
    MEM_W(0X1D0, ctx->r9) = ctx->r19;
L_800BF54C:
    // 0x800BF54C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800BF550: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800BF554: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800BF558: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x800BF55C: bne         $s4, $at, L_800BF1D8
    if (ctx->r20 != ctx->r1) {
        // 0x800BF560: addiu       $s7, $s7, 0x4E0
        ctx->r23 = ADD32(ctx->r23, 0X4E0);
            goto L_800BF1D8;
    }
    // 0x800BF560: addiu       $s7, $s7, 0x4E0
    ctx->r23 = ADD32(ctx->r23, 0X4E0);
    // 0x800BF564: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BF568: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800BF56C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800BF570: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800BF574: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800BF578: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800BF57C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800BF580: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800BF584: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800BF588: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800BF58C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800BF590: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800BF594: jr          $ra
    // 0x800BF598: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800BF598: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Item1up_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067B1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80067B20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80067B24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80067B28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80067B2C: jal         0x80066EF0
    // 0x80067B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Item_CheckBounds(rdram, ctx);
        goto after_0;
    // 0x80067B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80067B34: jal         0x800671D0
    // 0x80067B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Item_SpinPickup(rdram, ctx);
        goto after_1;
    // 0x80067B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80067B3C: lb          $t6, 0x4C($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X4C);
    // 0x80067B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80067B44: beql        $t6, $zero, L_80067BC0
    if (ctx->r14 == 0) {
        // 0x80067B48: lhu         $t5, 0x48($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X48);
            goto L_80067BC0;
    }
    goto skip_0;
    // 0x80067B48: lhu         $t5, 0x48($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X48);
    skip_0:
    // 0x80067B4C: jal         0x80060FBC
    // 0x80067B50: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    Object_Kill(rdram, ctx);
        goto after_2;
    // 0x80067B50: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    after_2:
    // 0x80067B54: lh          $a2, 0x4E($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X4E);
    // 0x80067B58: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80067B5C: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x80067B60: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80067B64: addu        $t8, $t8, $a2
    ctx->r24 = ADD32(ctx->r24, ctx->r6);
    // 0x80067B68: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80067B6C: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x80067B70: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x80067B74: lui         $a1, 0x4900
    ctx->r5 = S32(0X4900 << 16);
    // 0x80067B78: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80067B7C: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    // 0x80067B80: jal         0x80060F30
    // 0x80067B84: ori         $a1, $a1, 0xC024
    ctx->r5 = ctx->r5 | 0XC024;
    Object_PlayerSfx(rdram, ctx);
        goto after_3;
    // 0x80067B84: ori         $a1, $a1, 0xC024
    ctx->r5 = ctx->r5 | 0XC024;
    after_3:
    // 0x80067B88: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80067B8C: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x80067B90: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80067B94: beql        $t9, $at, L_80067BC0
    if (ctx->r25 == ctx->r1) {
        // 0x80067B98: lhu         $t5, 0x48($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X48);
            goto L_80067BC0;
    }
    goto skip_1;
    // 0x80067B98: lhu         $t5, 0x48($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X48);
    skip_1:
    // 0x80067B9C: lh          $t0, 0x4E($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X4E);
    // 0x80067BA0: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80067BA4: addiu       $t2, $t2, 0x1AA0
    ctx->r10 = ADD32(ctx->r10, 0X1AA0);
    // 0x80067BA8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80067BAC: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x80067BB0: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80067BB4: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80067BB8: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
    // 0x80067BBC: lhu         $t5, 0x48($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X48);
L_80067BC0:
    // 0x80067BC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80067BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80067BC8: bnel        $t5, $at, L_80067BDC
    if (ctx->r13 != ctx->r1) {
        // 0x80067BCC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80067BDC;
    }
    goto skip_2;
    // 0x80067BCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80067BD0: jal         0x80060FBC
    // 0x80067BD4: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    Object_Kill(rdram, ctx);
        goto after_4;
    // 0x80067BD4: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    after_4:
    // 0x80067BD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80067BDC:
    // 0x80067BDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80067BE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80067BE4: jr          $ra
    // 0x80067BE8: nop

    return;
    // 0x80067BE8: nop

;}
RECOMP_FUNC void Audio_InitNoteSub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011890: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80011894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011898: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8001189C: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    // 0x800118A0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800118A4: jal         0x80011C58
    // 0x800118A8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    Audio_NoteSetResamplingRate(rdram, ctx);
        goto after_0;
    // 0x800118A8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x800118AC: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800118B0: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800118B4: addiu       $t8, $sp, 0x24
    ctx->r24 = ADD32(ctx->r29, 0X24);
    // 0x800118B8: lbu         $t6, 0x2($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X2);
    // 0x800118BC: lwc1        $f2, 0x8($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800118C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800118C4: sb          $t6, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r14;
    // 0x800118C8: lbu         $t7, 0x0($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X0);
    // 0x800118CC: addiu       $v0, $a2, 0xB0
    ctx->r2 = ADD32(ctx->r6, 0XB0);
    // 0x800118D0: sb          $t7, 0x26($sp)
    MEM_B(0X26, ctx->r29) = ctx->r15;
    // 0x800118D4: lbu         $at, 0x3($a3)
    ctx->r1 = MEM_BU(ctx->r7, 0X3);
    // 0x800118D8: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800118DC: sb          $at, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r1;
    // 0x800118E0: lbu         $t2, 0x27($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X27);
    // 0x800118E4: andi        $t3, $t2, 0x7F
    ctx->r11 = ctx->r10 & 0X7F;
    // 0x800118E8: sb          $t3, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r11;
    // 0x800118EC: lw          $t4, 0xB0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0XB0);
    // 0x800118F0: sll         $t6, $t4, 6
    ctx->r14 = S32(ctx->r12 << 6);
    // 0x800118F4: bgezl       $t6, L_80011998
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800118F8: lw          $t4, 0x0($v0)
        ctx->r12 = MEM_W(ctx->r2, 0X0);
            goto L_80011998;
    }
    goto skip_0;
    // 0x800118F8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x800118FC: lb          $t7, 0x5CA6($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X5CA6);
    // 0x80011900: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80011904: andi        $a0, $t3, 0xFF
    ctx->r4 = ctx->r11 & 0XFF;
    // 0x80011908: bne         $t7, $at, L_80011994
    if (ctx->r15 != ctx->r1) {
        // 0x8001190C: sra         $t0, $a0, 1
        ctx->r8 = S32(SIGNED(ctx->r4) >> 1);
            goto L_80011994;
    }
    // 0x8001190C: sra         $t0, $a0, 1
    ctx->r8 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80011910: slti        $at, $t0, 0x40
    ctx->r1 = SIGNED(ctx->r8) < 0X40 ? 1 : 0;
    // 0x80011914: bne         $at, $zero, L_80011920
    if (ctx->r1 != 0) {
        // 0x80011918: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_80011920;
    }
    // 0x80011918: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8001191C: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
L_80011920:
    // 0x80011920: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x80011924: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80011928: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x8001192C: lhu         $t9, -0x2E80($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2E80);
    // 0x80011930: addiu       $v0, $a2, 0xB0
    ctx->r2 = ADD32(ctx->r6, 0XB0);
    // 0x80011934: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x80011938: negu        $t8, $v1
    ctx->r24 = SUB32(0, ctx->r3);
    // 0x8001193C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80011940: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x80011944: sb          $t9, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r25;
    // 0x80011948: lhu         $t1, -0x2E02($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0X2E02);
    // 0x8001194C: andi        $t5, $t2, 0xFFF7
    ctx->r13 = ctx->r10 & 0XFFF7;
    // 0x80011950: andi        $t3, $t5, 0xFB
    ctx->r11 = ctx->r13 & 0XFB;
    // 0x80011954: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x80011958: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
    // 0x8001195C: ori         $t0, $t3, 0x1
    ctx->r8 = ctx->r11 | 0X1;
    // 0x80011960: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x80011964: sb          $t1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r9;
    // 0x80011968: lbu         $t9, 0x27($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X27);
    // 0x8001196C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011970: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80011974: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80011978: lwc1        $f12, -0x2D80($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2D80);
    // 0x8001197C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80011980: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x80011984: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011988: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8001198C: b           L_80011B84
    // 0x80011990: lwc1        $f14, -0x2B84($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2B84);
        goto L_80011B84;
    // 0x80011990: lwc1        $f14, -0x2B84($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2B84);
L_80011994:
    // 0x80011994: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
L_80011998:
    // 0x80011998: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8001199C: lb          $v1, 0x5CA6($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X5CA6);
    // 0x800119A0: sll         $t6, $t4, 6
    ctx->r14 = S32(ctx->r12 << 6);
    // 0x800119A4: bgez        $t6, L_80011B48
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800119A8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80011B48;
    }
    // 0x800119A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800119AC: bne         $v1, $zero, L_80011B48
    if (ctx->r3 != 0) {
        // 0x800119B0: nop
    
            goto L_80011B48;
    }
    // 0x800119B0: nop

    // 0x800119B4: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800119B8: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x800119BC: sb          $zero, 0x4($v0)
    MEM_B(0X4, ctx->r2) = 0;
    // 0x800119C0: andi        $t3, $t7, 0xFFFE
    ctx->r11 = ctx->r15 & 0XFFFE;
    // 0x800119C4: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
    // 0x800119C8: lbu         $t0, 0x27($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X27);
    // 0x800119CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800119D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800119D4: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x800119D8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800119DC: lwc1        $f12, -0x2B80($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2B80);
    // 0x800119E0: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x800119E4: negu        $t1, $t9
    ctx->r9 = SUB32(0, ctx->r25);
    // 0x800119E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800119EC: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800119F0: lwc1        $f14, -0x2984($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2984);
    // 0x800119F4: slti        $at, $t0, 0x20
    ctx->r1 = SIGNED(ctx->r8) < 0X20 ? 1 : 0;
    // 0x800119F8: beq         $at, $zero, L_80011A08
    if (ctx->r1 == 0) {
        // 0x800119FC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80011A08;
    }
    // 0x800119FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80011A00: b           L_80011A1C
    // 0x80011A04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80011A1C;
    // 0x80011A04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80011A08:
    // 0x80011A08: lbu         $t2, 0x27($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X27);
    // 0x80011A0C: slti        $at, $t2, 0x61
    ctx->r1 = SIGNED(ctx->r10) < 0X61 ? 1 : 0;
    // 0x80011A10: bnel        $at, $zero, L_80011A20
    if (ctx->r1 != 0) {
        // 0x80011A14: lbu         $t7, 0x0($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X0);
            goto L_80011A20;
    }
    goto skip_1;
    // 0x80011A14: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    skip_1:
    // 0x80011A18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80011A1C:
    // 0x80011A1C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
L_80011A20:
    // 0x80011A20: sll         $t5, $a0, 3
    ctx->r13 = S32(ctx->r4 << 3);
    // 0x80011A24: andi        $t6, $t5, 0x8
    ctx->r14 = ctx->r13 & 0X8;
    // 0x80011A28: andi        $t3, $t7, 0xFFF7
    ctx->r11 = ctx->r15 & 0XFFF7;
    // 0x80011A2C: or          $t2, $t6, $t3
    ctx->r10 = ctx->r14 | ctx->r11;
    // 0x80011A30: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x80011A34: andi        $t0, $t1, 0x4
    ctx->r8 = ctx->r9 & 0X4;
    // 0x80011A38: andi        $t4, $t2, 0xFB
    ctx->r12 = ctx->r10 & 0XFB;
    // 0x80011A3C: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
    // 0x80011A40: or          $t5, $t0, $t4
    ctx->r13 = ctx->r8 | ctx->r12;
    // 0x80011A44: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    // 0x80011A48: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80011A4C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80011A50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80011A54: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x80011A58: srl         $t6, $t7, 30
    ctx->r14 = S32(U32(ctx->r15) >> 30);
    // 0x80011A5C: beq         $t6, $zero, L_80011A88
    if (ctx->r14 == 0) {
        // 0x80011A60: sll         $t8, $t3, 6
        ctx->r24 = S32(ctx->r11 << 6);
            goto L_80011A88;
    }
    // 0x80011A60: sll         $t8, $t3, 6
    ctx->r24 = S32(ctx->r11 << 6);
    // 0x80011A64: beq         $t6, $at, L_80011B84
    if (ctx->r14 == ctx->r1) {
        // 0x80011A68: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80011B84;
    }
    // 0x80011A68: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80011A6C: beq         $t6, $at, L_80011AC0
    if (ctx->r14 == ctx->r1) {
        // 0x80011A70: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_80011AC0;
    }
    // 0x80011A70: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80011A74: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80011A78: beq         $t6, $at, L_80011B04
    if (ctx->r14 == ctx->r1) {
        // 0x80011A7C: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_80011B04;
    }
    // 0x80011A7C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80011A80: b           L_80011B88
    // 0x80011A84: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
        goto L_80011B88;
    // 0x80011A84: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80011A88:
    // 0x80011A88: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80011A8C: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x80011A90: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x80011A94: andi        $t2, $t1, 0x8
    ctx->r10 = ctx->r9 & 0X8;
    // 0x80011A98: andi        $t4, $t0, 0xFFF7
    ctx->r12 = ctx->r8 & 0XFFF7;
    // 0x80011A9C: or          $t9, $t2, $t4
    ctx->r25 = ctx->r10 | ctx->r12;
    // 0x80011AA0: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x80011AA4: lbu         $t6, 0x24($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X24);
    // 0x80011AA8: andi        $t1, $t9, 0xFB
    ctx->r9 = ctx->r25 & 0XFB;
    // 0x80011AAC: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80011AB0: andi        $t8, $t3, 0x4
    ctx->r24 = ctx->r11 & 0X4;
    // 0x80011AB4: or          $t0, $t8, $t1
    ctx->r8 = ctx->r24 | ctx->r9;
    // 0x80011AB8: b           L_80011B84
    // 0x80011ABC: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
        goto L_80011B84;
    // 0x80011ABC: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
L_80011AC0:
    // 0x80011AC0: sll         $t4, $t2, 6
    ctx->r12 = S32(ctx->r10 << 6);
    // 0x80011AC4: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80011AC8: srl         $t5, $t4, 31
    ctx->r13 = S32(U32(ctx->r12) >> 31);
    // 0x80011ACC: or          $t6, $t5, $a0
    ctx->r14 = ctx->r13 | ctx->r4;
    // 0x80011AD0: sll         $t3, $t6, 3
    ctx->r11 = S32(ctx->r14 << 3);
    // 0x80011AD4: andi        $t9, $t3, 0x8
    ctx->r25 = ctx->r11 & 0X8;
    // 0x80011AD8: andi        $t1, $t8, 0xFFF7
    ctx->r9 = ctx->r24 & 0XFFF7;
    // 0x80011ADC: or          $t8, $t9, $t1
    ctx->r24 = ctx->r25 | ctx->r9;
    // 0x80011AE0: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x80011AE4: lbu         $t4, 0x24($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X24);
    // 0x80011AE8: andi        $t9, $t8, 0xFB
    ctx->r25 = ctx->r24 & 0XFB;
    // 0x80011AEC: or          $t7, $t4, $a1
    ctx->r15 = ctx->r12 | ctx->r5;
    // 0x80011AF0: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80011AF4: andi        $t3, $t6, 0x4
    ctx->r11 = ctx->r14 & 0X4;
    // 0x80011AF8: or          $t1, $t3, $t9
    ctx->r9 = ctx->r11 | ctx->r25;
    // 0x80011AFC: b           L_80011B84
    // 0x80011B00: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
        goto L_80011B84;
    // 0x80011B00: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
L_80011B04:
    // 0x80011B04: sll         $t2, $t0, 6
    ctx->r10 = S32(ctx->r8 << 6);
    // 0x80011B08: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80011B0C: srl         $t4, $t2, 31
    ctx->r12 = S32(U32(ctx->r10) >> 31);
    // 0x80011B10: xor         $t7, $t4, $a0
    ctx->r15 = ctx->r12 ^ ctx->r4;
    // 0x80011B14: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x80011B18: andi        $t8, $t6, 0x8
    ctx->r24 = ctx->r14 & 0X8;
    // 0x80011B1C: andi        $t9, $t3, 0xFFF7
    ctx->r25 = ctx->r11 & 0XFFF7;
    // 0x80011B20: or          $t3, $t8, $t9
    ctx->r11 = ctx->r24 | ctx->r25;
    // 0x80011B24: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
    // 0x80011B28: lbu         $t2, 0x24($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X24);
    // 0x80011B2C: andi        $t8, $t3, 0xFB
    ctx->r24 = ctx->r11 & 0XFB;
    // 0x80011B30: xor         $t5, $t2, $a1
    ctx->r13 = ctx->r10 ^ ctx->r5;
    // 0x80011B34: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80011B38: andi        $t6, $t7, 0x4
    ctx->r14 = ctx->r15 & 0X4;
    // 0x80011B3C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80011B40: b           L_80011B84
    // 0x80011B44: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
        goto L_80011B84;
    // 0x80011B44: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
L_80011B48:
    // 0x80011B48: bne         $v1, $at, L_80011B60
    if (ctx->r3 != ctx->r1) {
        // 0x80011B4C: lbu         $t1, 0x27($sp)
        ctx->r9 = MEM_BU(ctx->r29, 0X27);
            goto L_80011B60;
    }
    // 0x80011B4C: lbu         $t1, 0x27($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X27);
    // 0x80011B50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011B54: lwc1        $f14, -0x7940($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7940);
    // 0x80011B58: b           L_80011B84
    // 0x80011B5C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
        goto L_80011B84;
    // 0x80011B5C: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_80011B60:
    // 0x80011B60: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x80011B64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011B68: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80011B6C: lwc1        $f12, -0x2980($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2980);
    // 0x80011B70: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80011B74: negu        $t4, $t2
    ctx->r12 = SUB32(0, ctx->r10);
    // 0x80011B78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80011B7C: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80011B80: lwc1        $f14, -0x2784($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2784);
L_80011B84:
    // 0x80011B84: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80011B88:
    // 0x80011B88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80011B8C: bc1fl       L_80011B9C
    if (!c1cs) {
        // 0x80011B90: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80011B9C;
    }
    goto skip_2;
    // 0x80011B90: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_2:
    // 0x80011B94: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80011B98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80011B9C:
    // 0x80011B9C: nop

    // 0x80011BA0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80011BA4: nop

    // 0x80011BA8: bc1f        L_80011BB4
    if (!c1cs) {
        // 0x80011BAC: nop
    
            goto L_80011BB4;
    }
    // 0x80011BAC: nop

    // 0x80011BB0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80011BB4:
    // 0x80011BB4: mul.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80011BB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80011BBC: lwc1        $f0, -0x793C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X793C);
    // 0x80011BC0: lbu         $t0, 0x5($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X5);
    // 0x80011BC4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80011BC8: nop

    // 0x80011BCC: mul.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80011BD0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80011BD4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80011BD8: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80011BDC: nop

    // 0x80011BE0: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x80011BE4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80011BE8: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80011BEC: nop

    // 0x80011BF0: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x80011BF4: lbu         $t8, 0x1($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X1);
    // 0x80011BF8: sb          $t8, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r24;
    // 0x80011BFC: lbu         $t9, 0x26($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X26);
    // 0x80011C00: beq         $t9, $t0, L_80011C1C
    if (ctx->r25 == ctx->r8) {
        // 0x80011C04: nop
    
            goto L_80011C1C;
    }
    // 0x80011C04: nop

    // 0x80011C08: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x80011C0C: sb          $t9, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r25;
    // 0x80011C10: ori         $t4, $t2, 0x10
    ctx->r12 = ctx->r10 | 0X10;
    // 0x80011C14: b           L_80011C48
    // 0x80011C18: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
        goto L_80011C48;
    // 0x80011C18: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
L_80011C1C:
    // 0x80011C1C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80011C20: sll         $t3, $t5, 1
    ctx->r11 = S32(ctx->r13 << 1);
    // 0x80011C24: bgezl       $t3, L_80011C40
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80011C28: lbu         $t9, 0x0($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X0);
            goto L_80011C40;
    }
    goto skip_3;
    // 0x80011C28: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    skip_3:
    // 0x80011C2C: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80011C30: ori         $t0, $t8, 0x10
    ctx->r8 = ctx->r24 | 0X10;
    // 0x80011C34: b           L_80011C48
    // 0x80011C38: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
        goto L_80011C48;
    // 0x80011C38: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x80011C3C: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
L_80011C40:
    // 0x80011C40: andi        $t1, $t9, 0xFFEF
    ctx->r9 = ctx->r25 & 0XFFEF;
    // 0x80011C44: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
L_80011C48:
    // 0x80011C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80011C4C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80011C50: jr          $ra
    // 0x80011C54: nop

    return;
    // 0x80011C54: nop

;}
RECOMP_FUNC void ActorEvent_ApplyDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800701E0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800701E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800701E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800701EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800701F0: jal         0x800700A4
    // 0x800701F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ActorEvent_RetreatTeammate(rdram, ctx);
        goto after_0;
    // 0x800701F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800701F8: bnel        $v0, $zero, L_80070B98
    if (ctx->r2 != 0) {
        // 0x800701FC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80070B98;
    }
    goto skip_0;
    // 0x800701FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80070200: lb          $v0, 0xD0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XD0);
    // 0x80070204: beq         $v0, $zero, L_80070230
    if (ctx->r2 == 0) {
        // 0x80070208: nop
    
            goto L_80070230;
    }
    // 0x80070208: nop

    // 0x8007020C: lh          $t6, 0xB4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB4);
    // 0x80070210: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x80070214: bne         $t6, $at, L_80070230
    if (ctx->r14 != ctx->r1) {
        // 0x80070218: nop
    
            goto L_80070230;
    }
    // 0x80070218: nop

    // 0x8007021C: lh          $t7, 0xD2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XD2);
    // 0x80070220: bne         $t7, $zero, L_80070230
    if (ctx->r15 != 0) {
        // 0x80070224: nop
    
            goto L_80070230;
    }
    // 0x80070224: nop

    // 0x80070228: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x8007022C: lb          $v0, 0xD0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XD0);
L_80070230:
    // 0x80070230: beq         $v0, $zero, L_80070260
    if (ctx->r2 == 0) {
        // 0x80070234: nop
    
            goto L_80070260;
    }
    // 0x80070234: nop

    // 0x80070238: lh          $t8, 0xB4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XB4);
    // 0x8007023C: addiu       $at, $zero, 0x53
    ctx->r1 = ADD32(0, 0X53);
    // 0x80070240: bne         $t8, $at, L_80070260
    if (ctx->r24 != ctx->r1) {
        // 0x80070244: nop
    
            goto L_80070260;
    }
    // 0x80070244: nop

    // 0x80070248: lhu         $t9, 0xC2($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XC2);
    // 0x8007024C: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x80070250: bne         $at, $zero, L_80070260
    if (ctx->r1 != 0) {
        // 0x80070254: nop
    
            goto L_80070260;
    }
    // 0x80070254: nop

    // 0x80070258: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x8007025C: lb          $v0, 0xD0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XD0);
L_80070260:
    // 0x80070260: beql        $v0, $zero, L_80070AB0
    if (ctx->r2 == 0) {
        // 0x80070264: lw          $t1, 0x80($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X80);
            goto L_80070AB0;
    }
    goto skip_1;
    // 0x80070264: lw          $t1, 0x80($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X80);
    skip_1:
    // 0x80070268: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    // 0x8007026C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80070270: bnel        $v0, $at, L_80070288
    if (ctx->r2 != ctx->r1) {
        // 0x80070274: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80070288;
    }
    goto skip_2;
    // 0x80070274: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    skip_2:
    // 0x80070278: lh          $t0, 0xD2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XD2);
    // 0x8007027C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80070280: beq         $t0, $at, L_80070290
    if (ctx->r8 == ctx->r1) {
        // 0x80070284: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80070290;
    }
    // 0x80070284: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
L_80070288:
    // 0x80070288: beql        $v0, $at, L_80070AB0
    if (ctx->r2 == ctx->r1) {
        // 0x8007028C: lw          $t1, 0x80($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X80);
            goto L_80070AB0;
    }
    goto skip_3;
    // 0x8007028C: lw          $t1, 0x80($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X80);
    skip_3:
L_80070290:
    // 0x80070290: lw          $v0, 0x80($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X80);
    // 0x80070294: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80070298: bne         $at, $zero, L_800702A8
    if (ctx->r1 != 0) {
        // 0x8007029C: nop
    
            goto L_800702A8;
    }
    // 0x8007029C: nop

    // 0x800702A0: sh          $zero, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = 0;
    // 0x800702A4: lw          $v0, 0x80($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X80);
L_800702A8:
    // 0x800702A8: blez        $v0, L_800702D8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800702AC: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_800702D8;
    }
    // 0x800702AC: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800702B0: beq         $at, $zero, L_800702D8
    if (ctx->r1 == 0) {
        // 0x800702B4: sll         $t1, $v0, 2
        ctx->r9 = S32(ctx->r2 << 2);
            goto L_800702D8;
    }
    // 0x800702B4: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x800702B8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800702BC: addiu       $t2, $t2, 0x78B0
    ctx->r10 = ADD32(ctx->r10, 0X78B0);
    // 0x800702C0: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x800702C4: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800702C8: lhu         $t4, 0xD6($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XD6);
    // 0x800702CC: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x800702D0: b           L_80070318
    // 0x800702D4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
        goto L_80070318;
    // 0x800702D4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_800702D8:
    // 0x800702D8: lh          $t6, 0xB4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB4);
    // 0x800702DC: addiu       $at, $zero, 0x53
    ctx->r1 = ADD32(0, 0X53);
    // 0x800702E0: bnel        $t6, $at, L_8007030C
    if (ctx->r14 != ctx->r1) {
        // 0x800702E4: lh          $t7, 0xCE($s0)
        ctx->r15 = MEM_H(ctx->r16, 0XCE);
            goto L_8007030C;
    }
    goto skip_4;
    // 0x800702E4: lh          $t7, 0xCE($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XCE);
    skip_4:
    // 0x800702E8: lhu         $v0, 0xD6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XD6);
    // 0x800702EC: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x800702F0: beq         $v0, $at, L_80070300
    if (ctx->r2 == ctx->r1) {
        // 0x800702F4: addiu       $at, $zero, 0x1F
        ctx->r1 = ADD32(0, 0X1F);
            goto L_80070300;
    }
    // 0x800702F4: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x800702F8: bnel        $v0, $at, L_8007030C
    if (ctx->r2 != ctx->r1) {
        // 0x800702FC: lh          $t7, 0xCE($s0)
        ctx->r15 = MEM_H(ctx->r16, 0XCE);
            goto L_8007030C;
    }
    goto skip_5;
    // 0x800702FC: lh          $t7, 0xCE($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XCE);
    skip_5:
L_80070300:
    // 0x80070300: b           L_80070318
    // 0x80070304: sh          $zero, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = 0;
        goto L_80070318;
    // 0x80070304: sh          $zero, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = 0;
    // 0x80070308: lh          $t7, 0xCE($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XCE);
L_8007030C:
    // 0x8007030C: lhu         $t8, 0xD6($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XD6);
    // 0x80070310: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80070314: sh          $t9, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r25;
L_80070318:
    // 0x80070318: lh          $t0, 0xCE($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XCE);
    // 0x8007031C: bgtzl       $t0, L_80070824
    if (SIGNED(ctx->r8) > 0) {
        // 0x80070320: lh          $t6, 0xB4($s0)
        ctx->r14 = MEM_H(ctx->r16, 0XB4);
            goto L_80070824;
    }
    goto skip_6;
    // 0x80070320: lh          $t6, 0xB4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB4);
    skip_6:
    // 0x80070324: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    // 0x80070328: addiu       $at, $zero, 0x6A
    ctx->r1 = ADD32(0, 0X6A);
    // 0x8007032C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80070330: bnel        $v0, $at, L_80070370
    if (ctx->r2 != ctx->r1) {
        // 0x80070334: addiu       $at, $zero, 0x53
        ctx->r1 = ADD32(0, 0X53);
            goto L_80070370;
    }
    goto skip_7;
    // 0x80070334: addiu       $at, $zero, 0x53
    ctx->r1 = ADD32(0, 0X53);
    skip_7:
    // 0x80070338: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8007033C: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80070340: jal         0x80077240
    // 0x80070344: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    BonusText_Display(rdram, ctx);
        goto after_1;
    // 0x80070344: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_1:
    // 0x80070348: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8007034C: lw          $t1, 0x1A98($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1A98);
    // 0x80070350: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80070354: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x80070358: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x8007035C: sw          $t2, 0x1A98($at)
    MEM_W(0X1A98, ctx->r1) = ctx->r10;
    // 0x80070360: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80070364: sw          $t3, 0x7850($at)
    MEM_W(0X7850, ctx->r1) = ctx->r11;
    // 0x80070368: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    // 0x8007036C: addiu       $at, $zero, 0x53
    ctx->r1 = ADD32(0, 0X53);
L_80070370:
    // 0x80070370: beq         $v0, $at, L_800707C0
    if (ctx->r2 == ctx->r1) {
        // 0x80070374: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_800707C0;
    }
    // 0x80070374: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80070378: bne         $v0, $at, L_800703C0
    if (ctx->r2 != ctx->r1) {
        // 0x8007037C: lui         $t4, 0x8018
        ctx->r12 = S32(0X8018 << 16);
            goto L_800703C0;
    }
    // 0x8007037C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80070380: lw          $t4, -0x7DCC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7DCC);
    // 0x80070384: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80070388: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8007038C: bne         $t4, $at, L_800703C0
    if (ctx->r12 != ctx->r1) {
        // 0x80070390: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_800703C0;
    }
    // 0x80070390: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80070394: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80070398: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x8007039C: lui         $a0, 0x2901
    ctx->r4 = S32(0X2901 << 16);
    // 0x800703A0: ori         $a0, $a0, 0x8036
    ctx->r4 = ctx->r4 | 0X8036;
    // 0x800703A4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800703A8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x800703AC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800703B0: jal         0x80019218
    // 0x800703B4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x800703B4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_2:
    // 0x800703B8: b           L_800703F0
    // 0x800703BC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
        goto L_800703F0;
    // 0x800703BC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
L_800703C0:
    // 0x800703C0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800703C4: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x800703C8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800703CC: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x800703D0: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x800703D4: ori         $a0, $a0, 0x700B
    ctx->r4 = ctx->r4 | 0X700B;
    // 0x800703D8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800703DC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800703E0: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x800703E4: jal         0x80019218
    // 0x800703E8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x800703E8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x800703EC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
L_800703F0:
    // 0x800703F0: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x800703F4: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800703F8: lbu         $t8, 0x7C98($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7C98);
    // 0x800703FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80070400: lwc1        $f2, 0x6C1C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6C1C);
    // 0x80070404: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80070408: bne         $t8, $at, L_80070414
    if (ctx->r24 != ctx->r1) {
        // 0x8007040C: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80070414;
    }
    // 0x8007040C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80070410: lwc1        $f2, 0x6C20($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6C20);
L_80070414:
    // 0x80070414: jal         0x80004EB0
    // 0x80070418: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x80070418: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x8007041C: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80070420: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80070424: nop

    // 0x80070428: bc1tl       L_80070440
    if (c1cs) {
        // 0x8007042C: lh          $t0, 0x30($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X30);
            goto L_80070440;
    }
    goto skip_8;
    // 0x8007042C: lh          $t0, 0x30($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X30);
    skip_8:
    // 0x80070430: lw          $t9, 0x80($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X80);
    // 0x80070434: beql        $t9, $zero, L_800704C4
    if (ctx->r25 == 0) {
        // 0x80070438: addiu       $t2, $zero, 0xA
        ctx->r10 = ADD32(0, 0XA);
            goto L_800704C4;
    }
    goto skip_9;
    // 0x80070438: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    skip_9:
    // 0x8007043C: lh          $t0, 0x30($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X30);
L_80070440:
    // 0x80070440: bnel        $t0, $zero, L_800704C4
    if (ctx->r8 != 0) {
        // 0x80070444: addiu       $t2, $zero, 0xA
        ctx->r10 = ADD32(0, 0XA);
            goto L_800704C4;
    }
    goto skip_10;
    // 0x80070444: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    skip_10:
    // 0x80070448: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    // 0x8007044C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80070450: beq         $v0, $at, L_800704C0
    if (ctx->r2 == ctx->r1) {
        // 0x80070454: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_800704C0;
    }
    // 0x80070454: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80070458: beq         $v0, $at, L_800704C0
    if (ctx->r2 == ctx->r1) {
        // 0x8007045C: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_800704C0;
    }
    // 0x8007045C: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80070460: beql        $v0, $at, L_800704C4
    if (ctx->r2 == ctx->r1) {
        // 0x80070464: addiu       $t2, $zero, 0xA
        ctx->r10 = ADD32(0, 0XA);
            goto L_800704C4;
    }
    goto skip_11;
    // 0x80070464: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    skip_11:
    // 0x80070468: lhu         $t1, 0xD6($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XD6);
    // 0x8007046C: slti        $at, $t1, 0x1F
    ctx->r1 = SIGNED(ctx->r9) < 0X1F ? 1 : 0;
    // 0x80070470: beq         $at, $zero, L_800704C0
    if (ctx->r1 == 0) {
        // 0x80070474: addiu       $at, $zero, 0x3E
        ctx->r1 = ADD32(0, 0X3E);
            goto L_800704C0;
    }
    // 0x80070474: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80070478: beq         $v0, $at, L_800704C0
    if (ctx->r2 == ctx->r1) {
        // 0x8007047C: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800704C0;
    }
    // 0x8007047C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80070480: beq         $v0, $at, L_800704C0
    if (ctx->r2 == ctx->r1) {
        // 0x80070484: addiu       $at, $zero, 0x48
        ctx->r1 = ADD32(0, 0X48);
            goto L_800704C0;
    }
    // 0x80070484: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x80070488: beq         $v0, $at, L_800704C0
    if (ctx->r2 == ctx->r1) {
        // 0x8007048C: addiu       $at, $zero, 0x44
        ctx->r1 = ADD32(0, 0X44);
            goto L_800704C0;
    }
    // 0x8007048C: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x80070490: beq         $v0, $at, L_800704C0
    if (ctx->r2 == ctx->r1) {
        // 0x80070494: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_800704C0;
    }
    // 0x80070494: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80070498: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007049C: lwc1        $f4, 0x110($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X110);
    // 0x800704A0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800704A4: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800704A8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800704AC: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800704B0: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800704B4: jal         0x8007D2C8
    // 0x800704B8: nop

    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_5;
    // 0x800704B8: nop

    after_5:
    // 0x800704BC: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_800704C0:
    // 0x800704C0: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
L_800704C4:
    // 0x800704C4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800704C8: addiu       $t4, $zero, 0x384
    ctx->r12 = ADD32(0, 0X384);
    // 0x800704CC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800704D0: sh          $t2, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r10;
    // 0x800704D4: sh          $zero, 0xBE($s0)
    MEM_H(0XBE, ctx->r16) = 0;
    // 0x800704D8: sh          $t3, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r11;
    // 0x800704DC: sh          $t4, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r12;
    // 0x800704E0: sb          $t5, 0xC9($s0)
    MEM_B(0XC9, ctx->r16) = ctx->r13;
    // 0x800704E4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800704E8: lbu         $t6, 0x7C98($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7C98);
    // 0x800704EC: bnel        $t6, $zero, L_80070688
    if (ctx->r14 != 0) {
        // 0x800704F0: lh          $v0, 0xB4($s0)
        ctx->r2 = MEM_H(ctx->r16, 0XB4);
            goto L_80070688;
    }
    goto skip_12;
    // 0x800704F0: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    skip_12:
    // 0x800704F4: jal         0x80004EB0
    // 0x800704F8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x800704F8: nop

    after_6:
    // 0x800704FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80070500: lwc1        $f10, 0x6C24($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6C24);
    // 0x80070504: lh          $t9, 0xB4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XB4);
    // 0x80070508: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007050C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80070510: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80070514: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80070518: bne         $t9, $at, L_800705A0
    if (ctx->r25 != ctx->r1) {
        // 0x8007051C: sh          $t8, 0x4C($s0)
        MEM_H(0X4C, ctx->r16) = ctx->r24;
            goto L_800705A0;
    }
    // 0x8007051C: sh          $t8, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r24;
    // 0x80070520: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80070524: lwc1        $f4, 0xD8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XD8);
    // 0x80070528: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007052C: sh          $t0, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r8;
    // 0x80070530: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80070534: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80070538: bc1fl       L_80070578
    if (!c1cs) {
        // 0x8007053C: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_80070578;
    }
    goto skip_13;
    // 0x8007053C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_13:
    // 0x80070540: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80070544: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80070548: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8007054C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80070550: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80070554: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x80070558: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8007055C: jal         0x800A69F8
    // 0x80070560: nop

    Play_SpawnDebris(rdram, ctx);
        goto after_7;
    // 0x80070560: nop

    after_7:
    // 0x80070564: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80070568: lwc1        $f10, 0x6C28($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6C28);
    // 0x8007056C: b           L_800705A0
    // 0x80070570: swc1        $f10, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->f10.u32l;
        goto L_800705A0;
    // 0x80070570: swc1        $f10, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->f10.u32l;
    // 0x80070574: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_80070578:
    // 0x80070578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8007057C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x80070580: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80070584: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x80070588: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8007058C: jal         0x800A69F8
    // 0x80070590: nop

    Play_SpawnDebris(rdram, ctx);
        goto after_8;
    // 0x80070590: nop

    after_8:
    // 0x80070594: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80070598: lwc1        $f4, 0x6C2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6C2C);
    // 0x8007059C: swc1        $f4, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->f4.u32l;
L_800705A0:
    // 0x800705A0: addiu       $t1, $zero, 0x12C
    ctx->r9 = ADD32(0, 0X12C);
    // 0x800705A4: sh          $t1, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r9;
    // 0x800705A8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800705AC: lw          $t2, 0x7880($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7880);
    // 0x800705B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800705B4: beq         $t2, $at, L_80070664
    if (ctx->r10 == ctx->r1) {
        // 0x800705B8: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80070664;
    }
    // 0x800705B8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800705BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800705C0: lwc1        $f6, 0xE8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800705C4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800705C8: jal         0x80004EB0
    // 0x800705CC: swc1        $f10, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x800705CC: swc1        $f10, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f10.u32l;
    after_9:
    // 0x800705D0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800705D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800705D8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800705DC: lwc1        $f2, 0xF0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x800705E0: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800705E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800705E8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800705EC: nop

    // 0x800705F0: bc1f        L_80070600
    if (!c1cs) {
        // 0x800705F4: swc1        $f18, 0xEC($s0)
        MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
            goto L_80070600;
    }
    // 0x800705F4: swc1        $f18, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
    // 0x800705F8: b           L_8007060C
    // 0x800705FC: swc1        $f2, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f2.u32l;
        goto L_8007060C;
    // 0x800705FC: swc1        $f2, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f2.u32l;
L_80070600:
    // 0x80070600: lwc1        $f4, 0x6C30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6C30);
    // 0x80070604: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80070608: swc1        $f6, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f6.u32l;
L_8007060C:
    // 0x8007060C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80070610: lwc1        $f8, 0x6C34($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6C34);
    // 0x80070614: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80070618: lwc1        $f16, 0x7D20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8007061C: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80070620: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80070624: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x80070628: nop

    // 0x8007062C: bc1fl       L_80070668
    if (!c1cs) {
        // 0x80070630: lh          $v0, 0xB4($s0)
        ctx->r2 = MEM_H(ctx->r16, 0XB4);
            goto L_80070668;
    }
    goto skip_14;
    // 0x80070630: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    skip_14:
    // 0x80070634: lwc1        $f4, 0xF0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x80070638: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8007063C: nop

    // 0x80070640: bc1fl       L_80070668
    if (!c1cs) {
        // 0x80070644: lh          $v0, 0xB4($s0)
        ctx->r2 = MEM_H(ctx->r16, 0XB4);
            goto L_80070668;
    }
    goto skip_15;
    // 0x80070644: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    skip_15:
    // 0x80070648: jal         0x80004EB0
    // 0x8007064C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x8007064C: nop

    after_10:
    // 0x80070650: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80070654: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80070658: nop

    // 0x8007065C: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80070660: swc1        $f10, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f10.u32l;
L_80070664:
    // 0x80070664: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
L_80070668:
    // 0x80070668: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x8007066C: addiu       $t3, $zero, 0x3E7
    ctx->r11 = ADD32(0, 0X3E7);
    // 0x80070670: bnel        $v0, $at, L_800707C4
    if (ctx->r2 != ctx->r1) {
        // 0x80070674: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_800707C4;
    }
    goto skip_16;
    // 0x80070674: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    skip_16:
    // 0x80070678: sh          $t3, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r11;
    // 0x8007067C: b           L_800707C0
    // 0x80070680: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
        goto L_800707C0;
    // 0x80070680: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    // 0x80070684: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
L_80070688:
    // 0x80070688: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8007068C: beq         $v0, $at, L_800706AC
    if (ctx->r2 == ctx->r1) {
        // 0x80070690: addiu       $at, $zero, 0x1B
        ctx->r1 = ADD32(0, 0X1B);
            goto L_800706AC;
    }
    // 0x80070690: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80070694: beq         $v0, $at, L_800706CC
    if (ctx->r2 == ctx->r1) {
        // 0x80070698: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_800706CC;
    }
    // 0x80070698: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x8007069C: beq         $v0, $at, L_800706BC
    if (ctx->r2 == ctx->r1) {
        // 0x800706A0: addiu       $t0, $zero, 0x23
        ctx->r8 = ADD32(0, 0X23);
            goto L_800706BC;
    }
    // 0x800706A0: addiu       $t0, $zero, 0x23
    ctx->r8 = ADD32(0, 0X23);
    // 0x800706A4: b           L_8007076C
    // 0x800706A8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
        goto L_8007076C;
    // 0x800706A8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
L_800706AC:
    // 0x800706AC: jal         0x800654E4
    // 0x800706B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_enmy_800654E4(rdram, ctx);
        goto after_11;
    // 0x800706B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x800706B4: b           L_800707C0
    // 0x800706B8: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
        goto L_800707C0;
    // 0x800706B8: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
L_800706BC:
    // 0x800706BC: jal         0x8018CCF8
    // 0x800706C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Meteo_SmallRock_Spawn(rdram, ctx);
        goto after_12;
    // 0x800706C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800706C4: b           L_800707C0
    // 0x800706C8: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
        goto L_800707C0;
    // 0x800706C8: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
L_800706CC:
    // 0x800706CC: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800706D0: lwc1        $f8, 0xEC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x800706D4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800706D8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800706DC: sub.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800706E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800706E4: lwc1        $f6, 0xE8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800706E8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800706EC: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x800706F0: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800706F4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800706F8: lwc1        $f6, 0x110($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X110);
    // 0x800706FC: lwc1        $f18, 0xF0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x80070700: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80070704: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80070708: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8007070C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80070710: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80070714: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80070718: sb          $t4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r12;
    // 0x8007071C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80070720: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80070724: jal         0x8007D0E0
    // 0x80070728: nop

    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_13;
    // 0x80070728: nop

    after_13:
    // 0x8007072C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80070730: addiu       $t5, $zero, 0x2710
    ctx->r13 = ADD32(0, 0X2710);
    // 0x80070734: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x80070738: sh          $t5, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r13;
    // 0x8007073C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80070740: swc1        $f12, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f12.u32l;
    // 0x80070744: lw          $t6, 0x1A98($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1A98);
    // 0x80070748: lbu         $t7, 0x3C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X3C);
    // 0x8007074C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80070750: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x80070754: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80070758: sw          $t8, 0x1A98($at)
    MEM_W(0X1A98, ctx->r1) = ctx->r24;
    // 0x8007075C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80070760: sw          $t9, 0x7850($at)
    MEM_W(0X7850, ctx->r1) = ctx->r25;
    // 0x80070764: b           L_800707C0
    // 0x80070768: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
        goto L_800707C0;
    // 0x80070768: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
L_8007076C:
    // 0x8007076C: sh          $t0, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r8;
    // 0x80070770: jal         0x80004EB0
    // 0x80070774: sh          $t1, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r9;
    Rand_ZeroOne(rdram, ctx);
        goto after_14;
    // 0x80070774: sh          $t1, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r9;
    after_14:
    // 0x80070778: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007077C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80070780: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80070784: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80070788: sub.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8007078C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80070790: jal         0x80004EB0
    // 0x80070794: swc1        $f6, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_15;
    // 0x80070794: swc1        $f6, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f6.u32l;
    after_15:
    // 0x80070798: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007079C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800707A0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800707A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800707A8: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800707AC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800707B0: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    // 0x800707B4: mul.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800707B8: swc1        $f12, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f12.u32l;
    // 0x800707BC: swc1        $f18, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f18.u32l;
L_800707C0:
    // 0x800707C0: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
L_800707C4:
    // 0x800707C4: bne         $v0, $at, L_80070AAC
    if (ctx->r2 != ctx->r1) {
        // 0x800707C8: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_80070AAC;
    }
    // 0x800707C8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800707CC: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x800707D0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800707D4: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x800707D8: lui         $a0, 0x1100
    ctx->r4 = S32(0X1100 << 16);
    // 0x800707DC: ori         $a0, $a0, 0x55
    ctx->r4 = ctx->r4 | 0X55;
    // 0x800707E0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800707E4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800707E8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x800707EC: jal         0x80019218
    // 0x800707F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_16;
    // 0x800707F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x800707F4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800707F8: sb          $t3, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r11;
    // 0x800707FC: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80070800: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80070804: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80070808: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x8007080C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80070810: jal         0x8007C688
    // 0x80070814: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    Effect_Effect387_Spawn(rdram, ctx);
        goto after_17;
    // 0x80070814: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_17:
    // 0x80070818: b           L_80070AB0
    // 0x8007081C: lw          $t1, 0x80($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X80);
        goto L_80070AB0;
    // 0x8007081C: lw          $t1, 0x80($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X80);
    // 0x80070820: lh          $t6, 0xB4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB4);
L_80070824:
    // 0x80070824: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x80070828: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8007082C: bne         $t6, $at, L_80070878
    if (ctx->r14 != ctx->r1) {
        // 0x80070830: sh          $t5, 0xC6($s0)
        MEM_H(0XC6, ctx->r16) = ctx->r13;
            goto L_80070878;
    }
    // 0x80070830: sh          $t5, 0xC6($s0)
    MEM_H(0XC6, ctx->r16) = ctx->r13;
    // 0x80070834: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80070838: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x8007083C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80070840: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x80070844: bne         $t7, $at, L_80070878
    if (ctx->r15 != ctx->r1) {
        // 0x80070848: ori         $a0, $a0, 0x3037
        ctx->r4 = ctx->r4 | 0X3037;
            goto L_80070878;
    }
    // 0x80070848: ori         $a0, $a0, 0x3037
    ctx->r4 = ctx->r4 | 0X3037;
    // 0x8007084C: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80070850: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80070854: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x80070858: addiu       $a3, $t8, 0x5D34
    ctx->r7 = ADD32(ctx->r24, 0X5D34);
    // 0x8007085C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80070860: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80070864: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80070868: jal         0x80019218
    // 0x8007086C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_18;
    // 0x8007086C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_18:
    // 0x80070870: b           L_800708E8
    // 0x80070874: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
        goto L_800708E8;
    // 0x80070874: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
L_80070878:
    // 0x80070878: lh          $t0, 0xCE($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XCE);
    // 0x8007087C: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x80070880: ori         $a0, $a0, 0x300E
    ctx->r4 = ctx->r4 | 0X300E;
    // 0x80070884: slti        $at, $t0, 0x14
    ctx->r1 = SIGNED(ctx->r8) < 0X14 ? 1 : 0;
    // 0x80070888: beq         $at, $zero, L_800708C4
    if (ctx->r1 == 0) {
        // 0x8007088C: addiu       $a1, $s0, 0x100
        ctx->r5 = ADD32(ctx->r16, 0X100);
            goto L_800708C4;
    }
    // 0x8007088C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80070890: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80070894: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80070898: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x8007089C: addiu       $a3, $t1, 0x5D34
    ctx->r7 = ADD32(ctx->r9, 0X5D34);
    // 0x800708A0: lui         $a0, 0x2943
    ctx->r4 = S32(0X2943 << 16);
    // 0x800708A4: ori         $a0, $a0, 0x500F
    ctx->r4 = ctx->r4 | 0X500F;
    // 0x800708A8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800708AC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800708B0: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x800708B4: jal         0x80019218
    // 0x800708B8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_19;
    // 0x800708B8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_19:
    // 0x800708BC: b           L_800708E8
    // 0x800708C0: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
        goto L_800708E8;
    // 0x800708C0: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
L_800708C4:
    // 0x800708C4: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x800708C8: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x800708CC: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x800708D0: addiu       $a3, $t3, 0x5D34
    ctx->r7 = ADD32(ctx->r11, 0X5D34);
    // 0x800708D4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800708D8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800708DC: jal         0x80019218
    // 0x800708E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_20;
    // 0x800708E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_20:
    // 0x800708E4: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
L_800708E8:
    // 0x800708E8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800708EC: beq         $v0, $at, L_80070928
    if (ctx->r2 == ctx->r1) {
        // 0x800708F0: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_80070928;
    }
    // 0x800708F0: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x800708F4: beq         $v0, $at, L_80070928
    if (ctx->r2 == ctx->r1) {
        // 0x800708F8: addiu       $at, $zero, 0x53
        ctx->r1 = ADD32(0, 0X53);
            goto L_80070928;
    }
    // 0x800708F8: addiu       $at, $zero, 0x53
    ctx->r1 = ADD32(0, 0X53);
    // 0x800708FC: beq         $v0, $at, L_80070928
    if (ctx->r2 == ctx->r1) {
        // 0x80070900: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_80070928;
    }
    // 0x80070900: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80070904: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80070908: lwc1        $f4, 0x110($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X110);
    // 0x8007090C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80070910: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80070914: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80070918: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8007091C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80070920: jal         0x8007D10C
    // 0x80070924: nop

    Effect_FireSmoke2_Spawn3(rdram, ctx);
        goto after_21;
    // 0x80070924: nop

    after_21:
L_80070928:
    // 0x80070928: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007092C: lw          $v0, 0x7880($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7880);
    // 0x80070930: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80070934: beq         $v0, $at, L_80070944
    if (ctx->r2 == ctx->r1) {
        // 0x80070938: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80070944;
    }
    // 0x80070938: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007093C: bnel        $v0, $at, L_80070998
    if (ctx->r2 != ctx->r1) {
        // 0x80070940: lh          $t5, 0xD4($s0)
        ctx->r13 = MEM_H(ctx->r16, 0XD4);
            goto L_80070998;
    }
    goto skip_17;
    // 0x80070940: lh          $t5, 0xD4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XD4);
    skip_17:
L_80070944:
    // 0x80070944: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    // 0x80070948: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x8007094C: beq         $v0, $at, L_80070994
    if (ctx->r2 == ctx->r1) {
        // 0x80070950: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_80070994;
    }
    // 0x80070950: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x80070954: beql        $v0, $at, L_80070998
    if (ctx->r2 == ctx->r1) {
        // 0x80070958: lh          $t5, 0xD4($s0)
        ctx->r13 = MEM_H(ctx->r16, 0XD4);
            goto L_80070998;
    }
    goto skip_18;
    // 0x80070958: lh          $t5, 0xD4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XD4);
    skip_18:
    // 0x8007095C: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80070960: lwc1        $f18, 0xD8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XD8);
    // 0x80070964: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80070968: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007096C: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x80070970: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80070974: swc1        $f16, 0x148($s0)
    MEM_W(0X148, ctx->r16) = ctx->f16.u32l;
    // 0x80070978: bc1fl       L_80070998
    if (!c1cs) {
        // 0x8007097C: lh          $t5, 0xD4($s0)
        ctx->r13 = MEM_H(ctx->r16, 0XD4);
            goto L_80070998;
    }
    goto skip_19;
    // 0x8007097C: lh          $t5, 0xD4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XD4);
    skip_19:
    // 0x80070980: lwc1        $f4, 0x148($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X148);
    // 0x80070984: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80070988: nop

    // 0x8007098C: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80070990: swc1        $f10, 0x148($s0)
    MEM_W(0X148, ctx->r16) = ctx->f10.u32l;
L_80070994:
    // 0x80070994: lh          $t5, 0xD4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XD4);
L_80070998:
    // 0x80070998: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007099C: bnel        $t5, $at, L_80070AAC
    if (ctx->r13 != ctx->r1) {
        // 0x800709A0: sb          $zero, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = 0;
            goto L_80070AAC;
    }
    goto skip_20;
    // 0x800709A0: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    skip_20:
    // 0x800709A4: lw          $t6, 0x80($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X80);
    // 0x800709A8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800709AC: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x800709B0: beq         $at, $zero, L_80070AA8
    if (ctx->r1 == 0) {
        // 0x800709B4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80070AA8;
    }
    // 0x800709B4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800709B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800709BC: addu        $at, $at, $t7
    gpr jr_addend_800709C4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800709C0: lw          $t7, 0x6C38($at)
    ctx->r15 = ADD32(ctx->r1, 0X6C38);
    // 0x800709C4: jr          $t7
    // 0x800709C8: nop

    switch (jr_addend_800709C4 >> 2) {
        case 0: goto L_800709CC; break;
        case 1: goto L_80070A44; break;
        case 2: goto L_80070A08; break;
        case 3: goto L_80070A80; break;
        case 4: goto L_80070A98; break;
        default: switch_error(__func__, 0x800709C4, 0x800D6C38);
    }
    // 0x800709C8: nop

L_800709CC:
    // 0x800709CC: lb          $t8, 0xD0($s0)
    ctx->r24 = MEM_B(ctx->r16, 0XD0);
    // 0x800709D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800709D4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800709D8: bne         $t8, $at, L_800709F8
    if (ctx->r24 != ctx->r1) {
        // 0x800709DC: addiu       $a0, $a0, 0x36B0
        ctx->r4 = ADD32(ctx->r4, 0X36B0);
            goto L_800709F8;
    }
    // 0x800709DC: addiu       $a0, $a0, 0x36B0
    ctx->r4 = ADD32(ctx->r4, 0X36B0);
    // 0x800709E0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800709E4: addiu       $a0, $a0, 0x398C
    ctx->r4 = ADD32(ctx->r4, 0X398C);
    // 0x800709E8: jal         0x8006A7B0
    // 0x800709EC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    ActorEvent_SetMessage(rdram, ctx);
        goto after_22;
    // 0x800709EC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_22:
    // 0x800709F0: b           L_80070AAC
    // 0x800709F4: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80070AAC;
    // 0x800709F4: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_800709F8:
    // 0x800709F8: jal         0x8006A7B0
    // 0x800709FC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    ActorEvent_SetMessage(rdram, ctx);
        goto after_23;
    // 0x800709FC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_23:
    // 0x80070A00: b           L_80070AAC
    // 0x80070A04: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80070AAC;
    // 0x80070A04: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80070A08:
    // 0x80070A08: lb          $t9, 0xD0($s0)
    ctx->r25 = MEM_B(ctx->r16, 0XD0);
    // 0x80070A0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80070A10: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80070A14: bne         $t9, $at, L_80070A34
    if (ctx->r25 != ctx->r1) {
        // 0x80070A18: addiu       $a0, $a0, 0x36F8
        ctx->r4 = ADD32(ctx->r4, 0X36F8);
            goto L_80070A34;
    }
    // 0x80070A18: addiu       $a0, $a0, 0x36F8
    ctx->r4 = ADD32(ctx->r4, 0X36F8);
    // 0x80070A1C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80070A20: addiu       $a0, $a0, 0x3950
    ctx->r4 = ADD32(ctx->r4, 0X3950);
    // 0x80070A24: jal         0x8006A7B0
    // 0x80070A28: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    ActorEvent_SetMessage(rdram, ctx);
        goto after_24;
    // 0x80070A28: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_24:
    // 0x80070A2C: b           L_80070AAC
    // 0x80070A30: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80070AAC;
    // 0x80070A30: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80070A34:
    // 0x80070A34: jal         0x8006A7B0
    // 0x80070A38: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    ActorEvent_SetMessage(rdram, ctx);
        goto after_25;
    // 0x80070A38: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_25:
    // 0x80070A3C: b           L_80070AAC
    // 0x80070A40: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80070AAC;
    // 0x80070A40: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80070A44:
    // 0x80070A44: lb          $t0, 0xD0($s0)
    ctx->r8 = MEM_B(ctx->r16, 0XD0);
    // 0x80070A48: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80070A4C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80070A50: bne         $t0, $at, L_80070A70
    if (ctx->r8 != ctx->r1) {
        // 0x80070A54: addiu       $a0, $a0, 0x3724
        ctx->r4 = ADD32(ctx->r4, 0X3724);
            goto L_80070A70;
    }
    // 0x80070A54: addiu       $a0, $a0, 0x3724
    ctx->r4 = ADD32(ctx->r4, 0X3724);
    // 0x80070A58: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80070A5C: addiu       $a0, $a0, 0x3900
    ctx->r4 = ADD32(ctx->r4, 0X3900);
    // 0x80070A60: jal         0x8006A7B0
    // 0x80070A64: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    ActorEvent_SetMessage(rdram, ctx);
        goto after_26;
    // 0x80070A64: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_26:
    // 0x80070A68: b           L_80070AAC
    // 0x80070A6C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80070AAC;
    // 0x80070A6C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80070A70:
    // 0x80070A70: jal         0x8006A7B0
    // 0x80070A74: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    ActorEvent_SetMessage(rdram, ctx);
        goto after_27;
    // 0x80070A74: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_27:
    // 0x80070A78: b           L_80070AAC
    // 0x80070A7C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80070AAC;
    // 0x80070A7C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80070A80:
    // 0x80070A80: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80070A84: addiu       $a0, $a0, 0x3760
    ctx->r4 = ADD32(ctx->r4, 0X3760);
    // 0x80070A88: jal         0x8006A7B0
    // 0x80070A8C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    ActorEvent_SetMessage(rdram, ctx);
        goto after_28;
    // 0x80070A8C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_28:
    // 0x80070A90: b           L_80070AAC
    // 0x80070A94: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_80070AAC;
    // 0x80070A94: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80070A98:
    // 0x80070A98: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80070A9C: addiu       $a0, $a0, 0x37B4
    ctx->r4 = ADD32(ctx->r4, 0X37B4);
    // 0x80070AA0: jal         0x8006A7B0
    // 0x80070AA4: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    ActorEvent_SetMessage(rdram, ctx);
        goto after_29;
    // 0x80070AA4: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    after_29:
L_80070AA8:
    // 0x80070AA8: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_80070AAC:
    // 0x80070AAC: lw          $t1, 0x80($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X80);
L_80070AB0:
    // 0x80070AB0: bnel        $t1, $zero, L_80070B98
    if (ctx->r9 != 0) {
        // 0x80070AB4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80070B98;
    }
    goto skip_21;
    // 0x80070AB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_21:
    // 0x80070AB8: lw          $t2, 0x84($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X84);
    // 0x80070ABC: bnel        $t2, $zero, L_80070B98
    if (ctx->r10 != 0) {
        // 0x80070AC0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80070B98;
    }
    goto skip_22;
    // 0x80070AC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_22:
    // 0x80070AC4: lh          $t3, 0x32($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X32);
    // 0x80070AC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80070ACC: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80070AD0: beql        $t3, $at, L_80070B98
    if (ctx->r11 == ctx->r1) {
        // 0x80070AD4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80070B98;
    }
    goto skip_23;
    // 0x80070AD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_23:
    // 0x80070AD8: lbu         $t4, 0x7C98($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X7C98);
    // 0x80070ADC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80070AE0: bnel        $t4, $at, L_80070B98
    if (ctx->r12 != ctx->r1) {
        // 0x80070AE4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80070B98;
    }
    goto skip_24;
    // 0x80070AE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_24:
    // 0x80070AE8: lwc1        $f16, 0xE8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x80070AEC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80070AF0: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80070AF4: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x80070AF8: lwc1        $f8, 0xEC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80070AFC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80070B00: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x80070B04: lwc1        $f18, 0xF0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x80070B08: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x80070B0C: jal         0x8006351C
    // 0x80070B10: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    Object_CheckCollision(rdram, ctx);
        goto after_30;
    // 0x80070B10: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    after_30:
    // 0x80070B14: bne         $v0, $zero, L_80070B40
    if (ctx->r2 != 0) {
        // 0x80070B18: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_80070B40;
    }
    // 0x80070B18: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80070B1C: lwc1        $f6, 0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x80070B20: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80070B24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80070B28: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80070B2C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80070B30: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x80070B34: nop

    // 0x80070B38: bc1fl       L_80070B98
    if (!c1cs) {
        // 0x80070B3C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80070B98;
    }
    goto skip_25;
    // 0x80070B3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_25:
L_80070B40:
    // 0x80070B40: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80070B44: lwc1        $f18, 0xF0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x80070B48: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    // 0x80070B4C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80070B50: sub.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80070B54: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80070B58: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80070B5C: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x80070B60: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x80070B64: bne         $v0, $at, L_80070B80
    if (ctx->r2 != ctx->r1) {
        // 0x80070B68: sb          $t6, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = ctx->r14;
            goto L_80070B80;
    }
    // 0x80070B68: sb          $t6, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r14;
    // 0x80070B6C: addiu       $t7, $zero, 0xB6
    ctx->r15 = ADD32(0, 0XB6);
    // 0x80070B70: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x80070B74: jal         0x800654E4
    // 0x80070B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_enmy_800654E4(rdram, ctx);
        goto after_31;
    // 0x80070B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80070B7C: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
L_80070B80:
    // 0x80070B80: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80070B84: bnel        $v0, $at, L_80070B98
    if (ctx->r2 != ctx->r1) {
        // 0x80070B88: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80070B98;
    }
    goto skip_26;
    // 0x80070B88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_26:
    // 0x80070B8C: jal         0x8018CCF8
    // 0x80070B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Meteo_SmallRock_Spawn(rdram, ctx);
        goto after_32;
    // 0x80070B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80070B94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80070B98:
    // 0x80070B98: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80070B9C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80070BA0: jr          $ra
    // 0x80070BA4: nop

    return;
    // 0x80070BA4: nop

;}
RECOMP_FUNC void bzero_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028D40: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x80028D44: bne         $at, $zero, L_80028DBC
    if (ctx->r1 != 0) {
        // 0x80028D48: negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
            goto L_80028DBC;
    }
    // 0x80028D48: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x80028D4C: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x80028D50: beq         $v1, $zero, L_80028D60
    if (ctx->r3 == 0) {
        // 0x80028D54: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_80028D60;
    }
    // 0x80028D54: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x80028D58: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x80028D5C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_80028D60:
    // 0x80028D60: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x80028D64: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x80028D68: beq         $a3, $zero, L_80028D9C
    if (ctx->r7 == 0) {
        // 0x80028D6C: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_80028D9C;
    }
    // 0x80028D6C: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x80028D70: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_80028D74:
    // 0x80028D74: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80028D78: sw          $zero, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = 0;
    // 0x80028D7C: sw          $zero, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = 0;
    // 0x80028D80: sw          $zero, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = 0;
    // 0x80028D84: sw          $zero, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = 0;
    // 0x80028D88: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x80028D8C: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x80028D90: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x80028D94: bne         $a0, $a3, L_80028D74
    if (ctx->r4 != ctx->r7) {
        // 0x80028D98: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_80028D74;
    }
    // 0x80028D98: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_80028D9C:
    // 0x80028D9C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80028DA0: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x80028DA4: beq         $a3, $zero, L_80028DBC
    if (ctx->r7 == 0) {
        // 0x80028DA8: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_80028DBC;
    }
    // 0x80028DA8: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x80028DAC: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_80028DB0:
    // 0x80028DB0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80028DB4: bne         $a0, $a3, L_80028DB0
    if (ctx->r4 != ctx->r7) {
        // 0x80028DB8: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_80028DB0;
    }
    // 0x80028DB8: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_80028DBC:
    // 0x80028DBC: blez        $a1, L_80028DD4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80028DC0: nop
    
            goto L_80028DD4;
    }
    // 0x80028DC0: nop

    // 0x80028DC4: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_80028DC8:
    // 0x80028DC8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80028DCC: bne         $a0, $a1, L_80028DC8
    if (ctx->r4 != ctx->r5) {
        // 0x80028DD0: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_80028DC8;
    }
    // 0x80028DD0: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_80028DD4:
    // 0x80028DD4: jr          $ra
    // 0x80028DD8: nop

    return;
    // 0x80028DD8: nop

    // 0x80028DDC: nop

;}
RECOMP_FUNC void AudioLoad_SlowLoadSample(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800105EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800105F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800105F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800105F8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800105FC: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80010600: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80010604: jal         0x8001079C
    // 0x80010608: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    AudioLoad_GetFontSample(rdram, ctx);
        goto after_0;
    // 0x80010608: lbu         $a1, 0x2F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X2F);
    after_0:
    // 0x8001060C: bne         $v0, $zero, L_80010620
    if (ctx->r2 != 0) {
        // 0x80010610: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80010620;
    }
    // 0x80010610: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80010614: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80010618: b           L_80010788
    // 0x8001061C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80010788;
    // 0x8001061C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80010620:
    // 0x80010620: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80010624: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80010628: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8001062C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80010630: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80010634: bne         $t8, $zero, L_80010648
    if (ctx->r24 != 0) {
        // 0x80010638: addiu       $t1, $t1, 0x6D90
        ctx->r9 = ADD32(ctx->r9, 0X6D90);
            goto L_80010648;
    }
    // 0x80010638: addiu       $t1, $t1, 0x6D90
    ctx->r9 = ADD32(ctx->r9, 0X6D90);
    // 0x8001063C: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x80010640: b           L_80010788
    // 0x80010644: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80010788;
    // 0x80010644: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80010648:
    // 0x80010648: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8001064C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80010650: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80010654: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80010658: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8001065C: addu        $v1, $t1, $t3
    ctx->r3 = ADD32(ctx->r9, ctx->r11);
    // 0x80010660: lw          $t4, 0x14($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X14);
    // 0x80010664: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80010668: bnel        $t4, $at, L_80010678
    if (ctx->r12 != ctx->r1) {
        // 0x8001066C: lw          $at, 0x0($t0)
        ctx->r1 = MEM_W(ctx->r8, 0X0);
            goto L_80010678;
    }
    goto skip_0;
    // 0x8001066C: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    skip_0:
    // 0x80010670: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x80010674: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
L_80010678:
    // 0x80010678: sw          $at, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r1;
    // 0x8001067C: lw          $t6, 0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4);
    // 0x80010680: sw          $t6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r14;
    // 0x80010684: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x80010688: sw          $at, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r1;
    // 0x8001068C: lw          $t6, 0xC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XC);
    // 0x80010690: sw          $s0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r16;
    // 0x80010694: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80010698: sw          $t6, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r14;
    // 0x8001069C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800106A0: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x800106A4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800106A8: sll         $a3, $v0, 4
    ctx->r7 = S32(ctx->r2 << 4);
    // 0x800106AC: srl         $t7, $a3, 30
    ctx->r15 = S32(U32(ctx->r7) >> 30);
    // 0x800106B0: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x800106B4: sra         $a3, $t8, 24
    ctx->r7 = S32(SIGNED(ctx->r24) >> 24);
    // 0x800106B8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800106BC: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x800106C0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800106C4: jal         0x8000DBE4
    // 0x800106C8: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    AudioHeap_AllocTemporarySampleCache(rdram, ctx);
        goto after_1;
    // 0x800106C8: and         $a0, $v0, $at
    ctx->r4 = ctx->r2 & ctx->r1;
    after_1:
    // 0x800106CC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800106D0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800106D4: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x800106D8: addiu       $t1, $t1, 0x6D90
    ctx->r9 = ADD32(ctx->r9, 0X6D90);
    // 0x800106DC: bne         $v0, $zero, L_80010720
    if (ctx->r2 != 0) {
        // 0x800106E0: sw          $v0, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->r2;
            goto L_80010720;
    }
    // 0x800106E0: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x800106E4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800106E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800106EC: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x800106F0: srl         $t3, $t2, 30
    ctx->r11 = S32(U32(ctx->r10) >> 30);
    // 0x800106F4: beq         $t3, $at, L_80010708
    if (ctx->r11 == ctx->r1) {
        // 0x800106F8: srl         $t4, $v0, 28
        ctx->r12 = S32(U32(ctx->r2) >> 28);
            goto L_80010708;
    }
    // 0x800106F8: srl         $t4, $v0, 28
    ctx->r12 = S32(U32(ctx->r2) >> 28);
    // 0x800106FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80010700: bne         $t4, $at, L_80010714
    if (ctx->r12 != ctx->r1) {
        // 0x80010704: addiu       $t5, $zero, 0x3
        ctx->r13 = ADD32(0, 0X3);
            goto L_80010714;
    }
    // 0x80010704: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
L_80010708:
    // 0x80010708: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8001070C: b           L_80010788
    // 0x80010710: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80010788;
    // 0x80010710: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80010714:
    // 0x80010714: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x80010718: b           L_80010788
    // 0x8001071C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80010788;
    // 0x8001071C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80010720:
    // 0x80010720: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80010724: sw          $t6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r14;
    // 0x80010728: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8001072C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80010730: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80010734: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80010738: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x8001073C: addiu       $t9, $t8, 0xF
    ctx->r25 = ADD32(ctx->r24, 0XF);
    // 0x80010740: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80010744: and         $t2, $t9, $at
    ctx->r10 = ctx->r25 & ctx->r1;
    // 0x80010748: sw          $t2, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r10;
    // 0x8001074C: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x80010750: lw          $t4, 0x4($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X4);
    // 0x80010754: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80010758: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8001075C: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80010760: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x80010764: srl         $t7, $t6, 30
    ctx->r15 = S32(U32(ctx->r14) >> 30);
    // 0x80010768: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x8001076C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80010770: sb          $t8, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r24;
    // 0x80010774: lbu         $t9, 0x2F($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X2F);
    // 0x80010778: sb          $t9, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r25;
    // 0x8001077C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80010780: xori        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 ^ 0X1;
    // 0x80010784: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
L_80010788:
    // 0x80010788: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001078C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80010790: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80010794: jr          $ra
    // 0x80010798: nop

    return;
    // 0x80010798: nop

;}
RECOMP_FUNC void AudioHeap_InitCachePools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C0C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000C0C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000C0C8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C0CC: addiu       $a0, $a0, -0x3DF0
    ctx->r4 = ADD32(ctx->r4, -0X3DF0);
    // 0x8000C0D0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8000C0D4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8000C0D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C0DC: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8000C0E0: jal         0x8000BF14
    // 0x8000C0E4: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    AudioHeap_Alloc(rdram, ctx);
        goto after_0;
    // 0x8000C0E4: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    after_0:
    // 0x8000C0E8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8000C0EC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C0F0: addiu       $a0, $a0, -0x3DE0
    ctx->r4 = ADD32(ctx->r4, -0X3DE0);
    // 0x8000C0F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000C0F8: jal         0x8000BF6C
    // 0x8000C0FC: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    AudioHeap_InitPool(rdram, ctx);
        goto after_1;
    // 0x8000C0FC: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    after_1:
    // 0x8000C100: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8000C104: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C108: addiu       $a0, $a0, -0x3DF0
    ctx->r4 = ADD32(ctx->r4, -0X3DF0);
    // 0x8000C10C: jal         0x8000BF14
    // 0x8000C110: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    AudioHeap_Alloc(rdram, ctx);
        goto after_2;
    // 0x8000C110: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    after_2:
    // 0x8000C114: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8000C118: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C11C: addiu       $a0, $a0, -0x3DD0
    ctx->r4 = ADD32(ctx->r4, -0X3DD0);
    // 0x8000C120: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000C124: jal         0x8000BF6C
    // 0x8000C128: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    AudioHeap_InitPool(rdram, ctx);
        goto after_3;
    // 0x8000C128: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    after_3:
    // 0x8000C12C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000C130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000C134: jr          $ra
    // 0x8000C138: nop

    return;
    // 0x8000C138: nop

;}
RECOMP_FUNC void func_effect_80078AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078AE0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80078AE4: jr          $ra
    // 0x80078AE8: nop

    return;
    // 0x80078AE8: nop

;}
RECOMP_FUNC void Radio_PlayMessage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA808: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BA80C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BA810: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800BA814: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800BA818: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800BA81C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800BA820: beq         $v0, $at, L_800BA844
    if (ctx->r2 == ctx->r1) {
        // 0x800BA824: lui         $t8, 0x8018
        ctx->r24 = S32(0X8018 << 16);
            goto L_800BA844;
    }
    // 0x800BA824: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800BA828: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800BA82C: beq         $v0, $at, L_800BA84C
    if (ctx->r2 == ctx->r1) {
        // 0x800BA830: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800BA84C;
    }
    // 0x800BA830: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800BA834: beq         $v0, $at, L_800BA854
    if (ctx->r2 == ctx->r1) {
        // 0x800BA838: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_800BA854;
    }
    // 0x800BA838: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800BA83C: beq         $v0, $at, L_800BA85C
    if (ctx->r2 == ctx->r1) {
        // 0x800BA840: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_800BA85C;
    }
    // 0x800BA840: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_800BA844:
    // 0x800BA844: b           L_800BA85C
    // 0x800BA848: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_800BA85C;
    // 0x800BA848: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800BA84C:
    // 0x800BA84C: b           L_800BA85C
    // 0x800BA850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800BA85C;
    // 0x800BA850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800BA854:
    // 0x800BA854: b           L_800BA85C
    // 0x800BA858: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_800BA85C;
    // 0x800BA858: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_800BA85C:
    // 0x800BA85C: lw          $t6, 0x7834($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7834);
    // 0x800BA860: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800BA864: bne         $t6, $at, L_800BA8D4
    if (ctx->r14 != ctx->r1) {
        // 0x800BA868: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800BA8D4;
    }
    // 0x800BA868: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800BA86C: beq         $a2, $at, L_800BA884
    if (ctx->r6 == ctx->r1) {
        // 0x800BA870: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_800BA884;
    }
    // 0x800BA870: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800BA874: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800BA878: beq         $a2, $at, L_800BA884
    if (ctx->r6 == ctx->r1) {
        // 0x800BA87C: addiu       $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_800BA884;
    }
    // 0x800BA87C: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x800BA880: bne         $a2, $at, L_800BA8D4
    if (ctx->r6 != ctx->r1) {
        // 0x800BA884: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800BA8D4;
    }
L_800BA884:
    // 0x800BA884: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800BA888: bne         $a2, $at, L_800BA894
    if (ctx->r6 != ctx->r1) {
        // 0x800BA88C: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800BA894;
    }
    // 0x800BA88C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800BA890: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
L_800BA894:
    // 0x800BA894: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800BA898: bne         $a2, $at, L_800BA8A4
    if (ctx->r6 != ctx->r1) {
        // 0x800BA89C: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_800BA8A4;
    }
    // 0x800BA89C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800BA8A0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_800BA8A4:
    // 0x800BA8A4: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x800BA8A8: bnel        $a2, $at, L_800BA8B8
    if (ctx->r6 != ctx->r1) {
        // 0x800BA8AC: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_800BA8B8;
    }
    goto skip_0;
    // 0x800BA8AC: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    skip_0:
    // 0x800BA8B0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x800BA8B4: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
L_800BA8B8:
    // 0x800BA8B8: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x800BA8BC: lw          $v0, 0x78B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78B0);
    // 0x800BA8C0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800BA8C4: bgtz        $v0, L_800BA8D4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800BA8C8: nop
    
            goto L_800BA8D4;
    }
    // 0x800BA8C8: nop

    // 0x800BA8CC: bnel        $v0, $at, L_800BAADC
    if (ctx->r2 != ctx->r1) {
        // 0x800BA8D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BAADC;
    }
    goto skip_1;
    // 0x800BA8D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_800BA8D4:
    // 0x800BA8D4: lw          $t8, -0x7D64($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D64);
    // 0x800BA8D8: beql        $t8, $zero, L_800BA908
    if (ctx->r24 == 0) {
        // 0x800BA8DC: mtc1        $a2, $f4
        ctx->f4.u32l = ctx->r6;
            goto L_800BA908;
    }
    goto skip_2;
    // 0x800BA8DC: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    skip_2:
    // 0x800BA8E0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800BA8E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BA8E8: jal         0x800BA7BC
    // 0x800BA8EC: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_radio_800BA7BC(rdram, ctx);
        goto after_0;
    // 0x800BA8EC: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x800BA8F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BA8F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800BA8F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA8FC: beq         $v0, $at, L_800BAAD8
    if (ctx->r2 == ctx->r1) {
        // 0x800BA900: lw          $a2, 0x2C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X2C);
            goto L_800BAAD8;
    }
    // 0x800BA900: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800BA904: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
L_800BA908:
    // 0x800BA908: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800BA90C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800BA910: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BA914: addiu       $v0, $v0, 0x7D68
    ctx->r2 = ADD32(ctx->r2, 0X7D68);
    // 0x800BA918: sw          $a1, 0x4A70($at)
    MEM_W(0X4A70, ctx->r1) = ctx->r5;
    // 0x800BA91C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800BA920: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800BA924: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800BA928: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x800BA92C: lw          $t9, 0x79F8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X79F8);
    // 0x800BA930: lw          $v1, 0x7834($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7834);
    // 0x800BA934: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x800BA938: beq         $t9, $zero, L_800BA95C
    if (ctx->r25 == 0) {
        // 0x800BA93C: addiu       $t2, $zero, 0xB0
        ctx->r10 = ADD32(0, 0XB0);
            goto L_800BA95C;
    }
    // 0x800BA93C: addiu       $t2, $zero, 0xB0
    ctx->r10 = ADD32(0, 0XB0);
    // 0x800BA940: beq         $a2, $zero, L_800BA94C
    if (ctx->r6 == 0) {
        // 0x800BA944: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800BA94C;
    }
    // 0x800BA944: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800BA948: bne         $a2, $at, L_800BA95C
    if (ctx->r6 != ctx->r1) {
        // 0x800BA94C: lui         $at, 0x43C8
        ctx->r1 = S32(0X43C8 << 16);
            goto L_800BA95C;
    }
L_800BA94C:
    // 0x800BA94C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x800BA950: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BA954: nop

    // 0x800BA958: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_800BA95C:
    // 0x800BA95C: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x800BA960: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x800BA964: addiu       $t3, $zero, 0x55
    ctx->r11 = ADD32(0, 0X55);
    // 0x800BA968: bne         $t0, $at, L_800BA9D8
    if (ctx->r8 != ctx->r1) {
        // 0x800BA96C: addiu       $at, $zero, 0xC8
        ctx->r1 = ADD32(0, 0XC8);
            goto L_800BA9D8;
    }
    // 0x800BA96C: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x800BA970: beq         $a2, $at, L_800BA998
    if (ctx->r6 == ctx->r1) {
        // 0x800BA974: addiu       $at, $zero, 0xD2
        ctx->r1 = ADD32(0, 0XD2);
            goto L_800BA998;
    }
    // 0x800BA974: addiu       $at, $zero, 0xD2
    ctx->r1 = ADD32(0, 0XD2);
    // 0x800BA978: beq         $a2, $at, L_800BA9A8
    if (ctx->r6 == ctx->r1) {
        // 0x800BA97C: addiu       $at, $zero, 0xDC
        ctx->r1 = ADD32(0, 0XDC);
            goto L_800BA9A8;
    }
    // 0x800BA97C: addiu       $at, $zero, 0xDC
    ctx->r1 = ADD32(0, 0XDC);
    // 0x800BA980: beq         $a2, $at, L_800BA9B8
    if (ctx->r6 == ctx->r1) {
        // 0x800BA984: addiu       $at, $zero, 0xE6
        ctx->r1 = ADD32(0, 0XE6);
            goto L_800BA9B8;
    }
    // 0x800BA984: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    // 0x800BA988: beql        $a2, $at, L_800BA9CC
    if (ctx->r6 == ctx->r1) {
        // 0x800BA98C: lui         $at, 0x4387
        ctx->r1 = S32(0X4387 << 16);
            goto L_800BA9CC;
    }
    goto skip_3;
    // 0x800BA98C: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    skip_3:
    // 0x800BA990: b           L_800BA9D8
    // 0x800BA994: nop

        goto L_800BA9D8;
    // 0x800BA994: nop

L_800BA998:
    // 0x800BA998: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x800BA99C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BA9A0: b           L_800BA9D8
    // 0x800BA9A4: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
        goto L_800BA9D8;
    // 0x800BA9A4: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
L_800BA9A8:
    // 0x800BA9A8: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x800BA9AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800BA9B0: b           L_800BA9D8
    // 0x800BA9B4: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
        goto L_800BA9D8;
    // 0x800BA9B4: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_800BA9B8:
    // 0x800BA9B8: lui         $at, 0x4382
    ctx->r1 = S32(0X4382 << 16);
    // 0x800BA9BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BA9C0: b           L_800BA9D8
    // 0x800BA9C4: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
        goto L_800BA9D8;
    // 0x800BA9C4: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x800BA9C8: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
L_800BA9CC:
    // 0x800BA9CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BA9D0: nop

    // 0x800BA9D4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
L_800BA9D8:
    // 0x800BA9D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BA9DC: sw          $a0, -0x7CF8($at)
    MEM_W(-0X7CF8, ctx->r1) = ctx->r4;
    // 0x800BA9E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BA9E4: sw          $t1, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = ctx->r9;
    // 0x800BA9E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BA9EC: beq         $v1, $at, L_800BAA04
    if (ctx->r3 == ctx->r1) {
        // 0x800BA9F0: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_800BAA04;
    }
    // 0x800BA9F0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800BA9F4: beq         $v1, $at, L_800BAA60
    if (ctx->r3 == ctx->r1) {
        // 0x800BA9F8: addiu       $t4, $zero, 0xB4
        ctx->r12 = ADD32(0, 0XB4);
            goto L_800BAA60;
    }
    // 0x800BA9F8: addiu       $t4, $zero, 0xB4
    ctx->r12 = ADD32(0, 0XB4);
    // 0x800BA9FC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800BAA00: bne         $v1, $at, L_800BAABC
    if (ctx->r3 != ctx->r1) {
        // 0x800BAA04: lui         $at, 0x432E
        ctx->r1 = S32(0X432E << 16);
            goto L_800BAABC;
    }
L_800BAA04:
    // 0x800BAA04: lui         $at, 0x432E
    ctx->r1 = S32(0X432E << 16);
    // 0x800BAA08: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BAA0C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BAA10: sw          $t2, -0x78D4($at)
    MEM_W(-0X78D4, ctx->r1) = ctx->r10;
    // 0x800BAA14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BAA18: sw          $t3, -0x78D8($at)
    MEM_W(-0X78D8, ctx->r1) = ctx->r11;
    // 0x800BAA1C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x800BAA20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BAA24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BAA28: swc1        $f6, -0x78D0($at)
    MEM_W(-0X78D0, ctx->r1) = ctx->f6.u32l;
    // 0x800BAA2C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BAA30: swc1        $f0, -0x78CC($at)
    MEM_W(-0X78CC, ctx->r1) = ctx->f0.u32l;
    // 0x800BAA34: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BAA38: lwc1        $f8, -0x73FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X73FC);
    // 0x800BAA3C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BAA40: swc1        $f8, -0x78C8($at)
    MEM_W(-0X78C8, ctx->r1) = ctx->f8.u32l;
    // 0x800BAA44: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800BAA48: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BAA4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BAA50: swc1        $f10, -0x78C4($at)
    MEM_W(-0X78C4, ctx->r1) = ctx->f10.u32l;
    // 0x800BAA54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BAA58: b           L_800BAABC
    // 0x800BAA5C: swc1        $f0, -0x78C0($at)
    MEM_W(-0X78C0, ctx->r1) = ctx->f0.u32l;
        goto L_800BAABC;
    // 0x800BAA5C: swc1        $f0, -0x78C0($at)
    MEM_W(-0X78C0, ctx->r1) = ctx->f0.u32l;
L_800BAA60:
    // 0x800BAA60: lui         $at, 0x4332
    ctx->r1 = S32(0X4332 << 16);
    // 0x800BAA64: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BAA68: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BAA6C: sw          $t4, -0x78D4($at)
    MEM_W(-0X78D4, ctx->r1) = ctx->r12;
    // 0x800BAA70: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BAA74: addiu       $t5, $zero, 0x4F
    ctx->r13 = ADD32(0, 0X4F);
    // 0x800BAA78: sw          $t5, -0x78D8($at)
    MEM_W(-0X78D8, ctx->r1) = ctx->r13;
    // 0x800BAA7C: lui         $at, 0x4294
    ctx->r1 = S32(0X4294 << 16);
    // 0x800BAA80: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800BAA84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BAA88: swc1        $f16, -0x78D0($at)
    MEM_W(-0X78D0, ctx->r1) = ctx->f16.u32l;
    // 0x800BAA8C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BAA90: swc1        $f0, -0x78CC($at)
    MEM_W(-0X78CC, ctx->r1) = ctx->f0.u32l;
    // 0x800BAA94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BAA98: lwc1        $f18, -0x73F8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X73F8);
    // 0x800BAA9C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BAAA0: swc1        $f18, -0x78C8($at)
    MEM_W(-0X78C8, ctx->r1) = ctx->f18.u32l;
    // 0x800BAAA4: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x800BAAA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BAAAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BAAB0: swc1        $f4, -0x78C4($at)
    MEM_W(-0X78C4, ctx->r1) = ctx->f4.u32l;
    // 0x800BAAB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BAAB8: swc1        $f0, -0x78C0($at)
    MEM_W(-0X78C0, ctx->r1) = ctx->f0.u32l;
L_800BAABC:
    // 0x800BAABC: jal         0x800C2890
    // 0x800BAAC0: nop

    Message_IdFromPtr(rdram, ctx);
        goto after_1;
    // 0x800BAAC0: nop

    after_1:
    // 0x800BAAC4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800BAAC8: addiu       $v1, $v1, -0x7D18
    ctx->r3 = ADD32(ctx->r3, -0X7D18);
    // 0x800BAACC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800BAAD0: jal         0x8001ACDC
    // 0x800BAAD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    Audio_PlayVoice(rdram, ctx);
        goto after_2;
    // 0x800BAAD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
L_800BAAD8:
    // 0x800BAAD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BAADC:
    // 0x800BAADC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BAAE0: jr          $ra
    // 0x800BAAE4: nop

    return;
    // 0x800BAAE4: nop

;}
RECOMP_FUNC void AudioSynth_InitNextRingBuf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800080C0: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x800080C4: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x800080C8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800080CC: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x800080D0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800080D4: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x800080D8: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x800080DC: addiu       $t7, $t7, -0x45B0
    ctx->r15 = ADD32(ctx->r15, -0X45B0);
    // 0x800080E0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800080E4: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x800080E8: lbu         $t8, 0x4($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X4);
    // 0x800080EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800080F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800080F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800080F8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800080FC: beq         $t8, $at, L_80008288
    if (ctx->r24 == ctx->r1) {
        // 0x80008100: sw          $a1, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r5;
            goto L_80008288;
    }
    // 0x80008100: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80008104: lbu         $t9, 0x2($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X2);
    // 0x80008108: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x8000810C: addu        $t4, $t4, $a1
    ctx->r12 = ADD32(ctx->r12, ctx->r5);
    // 0x80008110: bnel        $t9, $zero, L_8000828C
    if (ctx->r25 != 0) {
        // 0x80008114: lbu         $t1, 0x4($a3)
        ctx->r9 = MEM_BU(ctx->r7, 0X4);
            goto L_8000828C;
    }
    goto skip_0;
    // 0x80008114: lbu         $t1, 0x4($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0X4);
    skip_0:
    // 0x80008118: lbu         $t0, 0x3($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X3);
    // 0x8000811C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80008120: addiu       $a1, $zero, 0x300
    ctx->r5 = ADD32(0, 0X300);
    // 0x80008124: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80008128: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8000812C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80008130: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80008134: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80008138: addu        $t2, $a3, $t1
    ctx->r10 = ADD32(ctx->r7, ctx->r9);
    // 0x8000813C: addu        $a2, $t2, $t4
    ctx->r6 = ADD32(ctx->r10, ctx->r12);
    // 0x80008140: addiu       $a2, $a2, 0x34
    ctx->r6 = ADD32(ctx->r6, 0X34);
    // 0x80008144: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x80008148: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8000814C: jal         0x80021740
    // 0x80008150: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80008150: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80008154: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80008158: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8000815C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80008160: lh          $t5, 0x10($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X10);
    // 0x80008164: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80008168: bgez        $t5, L_80008178
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8000816C: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_80008178;
    }
    // 0x8000816C: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x80008170: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x80008174: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_80008178:
    // 0x80008178: blezl       $t6, L_80008208
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000817C: lh          $t6, 0x12($a2)
        ctx->r14 = MEM_H(ctx->r6, 0X12);
            goto L_80008208;
    }
    goto skip_1;
    // 0x8000817C: lh          $t6, 0x12($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X12);
    skip_1:
    // 0x80008180: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80008184: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
L_80008188:
    // 0x80008188: lw          $t1, 0xC($a2)
    ctx->r9 = MEM_W(ctx->r6, 0XC);
    // 0x8000818C: lw          $t0, 0x1C($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X1C);
    // 0x80008190: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x80008194: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80008198: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8000819C: sll         $t3, $t1, 1
    ctx->r11 = S32(ctx->r9 << 1);
    // 0x800081A0: addu        $t2, $t0, $t3
    ctx->r10 = ADD32(ctx->r8, ctx->r11);
    // 0x800081A4: addu        $t4, $t2, $v0
    ctx->r12 = ADD32(ctx->r10, ctx->r2);
    // 0x800081A8: sh          $t9, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r25;
    // 0x800081AC: lw          $t5, 0x8($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X8);
    // 0x800081B0: lw          $t1, 0xC($a2)
    ctx->r9 = MEM_W(ctx->r6, 0XC);
    // 0x800081B4: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x800081B8: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x800081BC: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800081C0: sll         $t0, $t1, 1
    ctx->r8 = S32(ctx->r9 << 1);
    // 0x800081C4: addu        $t3, $t8, $t0
    ctx->r11 = ADD32(ctx->r24, ctx->r8);
    // 0x800081C8: addu        $t2, $t3, $v0
    ctx->r10 = ADD32(ctx->r11, ctx->r2);
    // 0x800081CC: sh          $t7, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r15;
    // 0x800081D0: lh          $t4, 0x10($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X10);
    // 0x800081D4: lbu         $t9, 0x4($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X4);
    // 0x800081D8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800081DC: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800081E0: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x800081E4: bgez        $t4, L_800081F4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800081E8: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_800081F4;
    }
    // 0x800081E8: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x800081EC: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x800081F0: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_800081F4:
    // 0x800081F4: slt         $at, $a0, $t5
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800081F8: bnel        $at, $zero, L_80008188
    if (ctx->r1 != 0) {
        // 0x800081FC: lw          $t7, 0x4($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X4);
            goto L_80008188;
    }
    goto skip_2;
    // 0x800081FC: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    skip_2:
    // 0x80008200: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80008204: lh          $t6, 0x12($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X12);
L_80008208:
    // 0x80008208: bgez        $t6, L_80008218
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8000820C: sra         $t1, $t6, 1
        ctx->r9 = S32(SIGNED(ctx->r14) >> 1);
            goto L_80008218;
    }
    // 0x8000820C: sra         $t1, $t6, 1
    ctx->r9 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80008210: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x80008214: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80008218:
    // 0x80008218: blezl       $t1, L_8000828C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8000821C: lbu         $t1, 0x4($a3)
        ctx->r9 = MEM_BU(ctx->r7, 0X4);
            goto L_8000828C;
    }
    goto skip_3;
    // 0x8000821C: lbu         $t1, 0x4($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0X4);
    skip_3:
    // 0x80008220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80008224: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
L_80008228:
    // 0x80008228: sll         $v1, $a1, 1
    ctx->r3 = S32(ctx->r5 << 1);
    // 0x8000822C: lw          $t7, 0x1C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X1C);
    // 0x80008230: addu        $t0, $t8, $v1
    ctx->r8 = ADD32(ctx->r24, ctx->r3);
    // 0x80008234: lh          $t3, 0x0($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X0);
    // 0x80008238: addu        $t2, $t7, $v0
    ctx->r10 = ADD32(ctx->r15, ctx->r2);
    // 0x8000823C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80008240: sh          $t3, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r11;
    // 0x80008244: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x80008248: lw          $t6, 0x20($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X20);
    // 0x8000824C: addu        $t4, $t9, $v1
    ctx->r12 = ADD32(ctx->r25, ctx->r3);
    // 0x80008250: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80008254: addu        $t1, $t6, $v0
    ctx->r9 = ADD32(ctx->r14, ctx->r2);
    // 0x80008258: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8000825C: sh          $t5, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r13;
    // 0x80008260: lh          $t0, 0x12($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X12);
    // 0x80008264: lbu         $t8, 0x4($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X4);
    // 0x80008268: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8000826C: bgez        $t0, L_8000827C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80008270: sra         $t7, $t0, 1
        ctx->r15 = S32(SIGNED(ctx->r8) >> 1);
            goto L_8000827C;
    }
    // 0x80008270: sra         $t7, $t0, 1
    ctx->r15 = S32(SIGNED(ctx->r8) >> 1);
    // 0x80008274: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x80008278: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8000827C:
    // 0x8000827C: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80008280: bnel        $at, $zero, L_80008228
    if (ctx->r1 != 0) {
        // 0x80008284: lw          $t8, 0x4($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X4);
            goto L_80008228;
    }
    goto skip_4;
    // 0x80008284: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
    skip_4:
L_80008288:
    // 0x80008288: lbu         $t1, 0x4($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0X4);
L_8000828C:
    // 0x8000828C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80008290: lbu         $t3, 0x3($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X3);
    // 0x80008294: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80008298: div         $zero, $t5, $t1
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r9)));
    // 0x8000829C: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
    // 0x800082A0: lw          $t8, 0x10($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X10);
    // 0x800082A4: subu        $t2, $t2, $t3
    ctx->r10 = SUB32(ctx->r10, ctx->r11);
    // 0x800082A8: lw          $t7, 0x18($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X18);
    // 0x800082AC: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800082B0: mflo        $v0
    ctx->r2 = lo;
    // 0x800082B4: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x800082B8: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800082BC: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800082C0: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x800082C4: addu        $t0, $t8, $v0
    ctx->r8 = ADD32(ctx->r24, ctx->r2);
    // 0x800082C8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800082CC: addu        $t9, $a3, $t2
    ctx->r25 = ADD32(ctx->r7, ctx->r10);
    // 0x800082D0: subu        $v1, $t0, $t7
    ctx->r3 = SUB32(ctx->r8, ctx->r15);
    // 0x800082D4: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x800082D8: addiu       $a2, $a2, 0x34
    ctx->r6 = ADD32(ctx->r6, 0X34);
    // 0x800082DC: bne         $t1, $zero, L_800082E8
    if (ctx->r9 != 0) {
        // 0x800082E0: nop
    
            goto L_800082E8;
    }
    // 0x800082E0: nop

    // 0x800082E4: break       7
    do_break(2147517156);
L_800082E8:
    // 0x800082E8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800082EC: bne         $t1, $at, L_80008300
    if (ctx->r9 != ctx->r1) {
        // 0x800082F0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80008300;
    }
    // 0x800082F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800082F4: bne         $t5, $at, L_80008300
    if (ctx->r13 != ctx->r1) {
        // 0x800082F8: nop
    
            goto L_80008300;
    }
    // 0x800082F8: nop

    // 0x800082FC: break       6
    do_break(2147517180);
L_80008300:
    // 0x80008300: subu        $t6, $v0, $v1
    ctx->r14 = SUB32(ctx->r2, ctx->r3);
    // 0x80008304: bgez        $v1, L_80008330
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80008308: sll         $t1, $v1, 1
        ctx->r9 = S32(ctx->r3 << 1);
            goto L_80008330;
    }
    // 0x80008308: sll         $t1, $v1, 1
    ctx->r9 = S32(ctx->r3 << 1);
    // 0x8000830C: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x80008310: sh          $t3, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r11;
    // 0x80008314: sh          $zero, 0x12($a2)
    MEM_H(0X12, ctx->r6) = 0;
    // 0x80008318: lw          $t2, 0x10($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X10);
    // 0x8000831C: sw          $t2, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r10;
    // 0x80008320: lw          $t4, 0x10($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X10);
    // 0x80008324: addu        $t9, $t4, $v0
    ctx->r25 = ADD32(ctx->r12, ctx->r2);
    // 0x80008328: b           L_80008348
    // 0x8000832C: sw          $t9, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r25;
        goto L_80008348;
    // 0x8000832C: sw          $t9, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r25;
L_80008330:
    // 0x80008330: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x80008334: sh          $t5, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r13;
    // 0x80008338: sh          $t1, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r9;
    // 0x8000833C: lw          $t8, 0x10($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X10);
    // 0x80008340: sw          $t8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r24;
    // 0x80008344: sw          $v1, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r3;
L_80008348:
    // 0x80008348: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x8000834C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80008350: sh          $t0, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r8;
    // 0x80008354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008358: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8000835C: jr          $ra
    // 0x80008360: nop

    return;
    // 0x80008360: nop

;}
RECOMP_FUNC void Effect_Effect391_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800837EC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800837F0: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800837F4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800837F8: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800837FC: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80083800: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80083804: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80083808: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x8008380C: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80083810: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80083814: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80083818: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8008381C: lh          $v0, 0x4E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X4E);
    // 0x80083820: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083824: beq         $v0, $zero, L_80083840
    if (ctx->r2 == 0) {
        // 0x80083828: nop
    
            goto L_80083840;
    }
    // 0x80083828: nop

    // 0x8008382C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80083830: beq         $v0, $at, L_80083A78
    if (ctx->r2 == ctx->r1) {
        // 0x80083834: nop
    
            goto L_80083A78;
    }
    // 0x80083834: nop

    // 0x80083838: b           L_80083B10
    // 0x8008383C: nop

        goto L_80083B10;
    // 0x8008383C: nop

L_80083840:
    // 0x80083840: lwc1        $f24, 0x7694($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X7694);
    // 0x80083844: lwc1        $f4, 0x64($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X64);
    // 0x80083848: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008384C: addiu       $a0, $s1, 0x70
    ctx->r4 = ADD32(ctx->r17, 0X70);
    // 0x80083850: c.eq.s      $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f24.fl == ctx->f4.fl;
    // 0x80083854: nop

    // 0x80083858: bc1f        L_80083894
    if (!c1cs) {
        // 0x8008385C: nop
    
            goto L_80083894;
    }
    // 0x8008385C: nop

    // 0x80083860: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80083864: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80083868: lwc1        $f2, 0x6C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x8008386C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083870: lwc1        $f6, 0x7698($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7698);
    // 0x80083874: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80083878: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8008387C: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x80083880: jal         0x8009BC2C
    // 0x80083884: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x80083884: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80083888: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008388C: b           L_800838D0
    // 0x80083890: lwc1        $f22, 0x769C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X769C);
        goto L_800838D0;
    // 0x80083890: lwc1        $f22, 0x769C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X769C);
L_80083894:
    // 0x80083894: lwc1        $f22, 0x76A0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X76A0);
    // 0x80083898: lwc1        $f2, 0x6C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x8008389C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800838A0: lwc1        $f10, 0x76A4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X76A4);
    // 0x800838A4: mul.s       $f8, $f2, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x800838A8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800838AC: addiu       $a0, $s1, 0x70
    ctx->r4 = ADD32(ctx->r17, 0X70);
    // 0x800838B0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800838B4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x800838B8: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800838BC: jal         0x8009BC2C
    // 0x800838C0: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800838C0: nop

    after_1:
    // 0x800838C4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800838C8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800838CC: nop

L_800838D0:
    // 0x800838D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800838D4: lwc1        $f18, 0x76A8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X76A8);
    // 0x800838D8: lwc1        $f2, 0x6C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x800838DC: lwc1        $f16, 0x70($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X70);
    // 0x800838E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800838E4: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800838E8: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x800838EC: nop

    // 0x800838F0: bc1fl       L_80083930
    if (!c1cs) {
        // 0x800838F4: c.eq.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl == ctx->f16.fl;
            goto L_80083930;
    }
    goto skip_0;
    // 0x800838F4: c.eq.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl == ctx->f16.fl;
    skip_0:
    // 0x800838F8: lwc1        $f20, 0x76AC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X76AC);
    // 0x800838FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083900: lwc1        $f6, 0x76B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X76B0);
    // 0x80083904: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80083908: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x8008390C: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80083910: addiu       $a0, $s1, 0x60
    ctx->r4 = ADD32(ctx->r17, 0X60);
    // 0x80083914: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80083918: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8008391C: jal         0x8009BC2C
    // 0x80083920: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80083920: nop

    after_2:
    // 0x80083924: lwc1        $f2, 0x6C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x80083928: lwc1        $f16, 0x70($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8008392C: c.eq.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl == ctx->f16.fl;
L_80083930:
    // 0x80083930: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80083934: bc1f        L_80083B10
    if (!c1cs) {
        // 0x80083938: nop
    
            goto L_80083B10;
    }
    // 0x80083938: nop

    // 0x8008393C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80083940: nop

    // 0x80083944: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80083948: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8008394C: mfc1        $s2, $f4
    ctx->r18 = (int32_t)ctx->f4.u32l;
    // 0x80083950: nop

    // 0x80083954: slti        $at, $s2, 0x5
    ctx->r1 = SIGNED(ctx->r18) < 0X5 ? 1 : 0;
    // 0x80083958: beql        $at, $zero, L_80083968
    if (ctx->r1 == 0) {
        // 0x8008395C: slti        $at, $s2, 0xB
        ctx->r1 = SIGNED(ctx->r18) < 0XB ? 1 : 0;
            goto L_80083968;
    }
    goto skip_1;
    // 0x8008395C: slti        $at, $s2, 0xB
    ctx->r1 = SIGNED(ctx->r18) < 0XB ? 1 : 0;
    skip_1:
    // 0x80083960: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
    // 0x80083964: slti        $at, $s2, 0xB
    ctx->r1 = SIGNED(ctx->r18) < 0XB ? 1 : 0;
L_80083968:
    // 0x80083968: bnel        $at, $zero, L_80083978
    if (ctx->r1 != 0) {
        // 0x8008396C: lwc1        $f0, 0x64($s1)
        ctx->f0.u32l = MEM_W(ctx->r17, 0X64);
            goto L_80083978;
    }
    goto skip_2;
    // 0x8008396C: lwc1        $f0, 0x64($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X64);
    skip_2:
    // 0x80083970: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x80083974: lwc1        $f0, 0x64($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X64);
L_80083978:
    // 0x80083978: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8008397C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80083980: c.eq.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl == ctx->f0.fl;
    // 0x80083984: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80083988: mul.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8008398C: bc1f        L_800839A4
    if (!c1cs) {
        // 0x80083990: nop
    
            goto L_800839A4;
    }
    // 0x80083990: nop

    // 0x80083994: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80083998: nop

    // 0x8008399C: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800839A0: nop

L_800839A4:
    // 0x800839A4: blez        $s2, L_80083A68
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800839A8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80083A68;
    }
    // 0x800839A8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800839AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800839B0: lwc1        $f30, 0x76B4($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X76B4);
    // 0x800839B4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800839B8: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x800839BC: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
L_800839C0:
    // 0x800839C0: jal         0x80004EB0
    // 0x800839C4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x800839C4: nop

    after_3:
    // 0x800839C8: jal         0x80004EB0
    // 0x800839CC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x800839CC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_4:
    // 0x800839D0: jal         0x80004EB0
    // 0x800839D4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x800839D4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_5:
    // 0x800839D8: jal         0x80004EB0
    // 0x800839DC: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x800839DC: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    after_6:
    // 0x800839E0: lwc1        $f16, 0x70($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X70);
    // 0x800839E4: sub.s       $f10, $f20, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f26.fl;
    // 0x800839E8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800839EC: mul.s       $f2, $f16, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f28.fl);
    // 0x800839F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800839F4: sub.s       $f6, $f22, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f26.fl;
    // 0x800839F8: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800839FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083A00: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x80083A04: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80083A08: nop

    // 0x80083A0C: mul.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80083A10: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80083A14: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80083A18: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80083A1C: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80083A20: sub.s       $f10, $f24, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f26.fl;
    // 0x80083A24: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80083A28: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80083A2C: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80083A30: lwc1        $f10, 0x76B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X76B8);
    // 0x80083A34: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80083A38: add.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80083A3C: sub.s       $f6, $f0, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x80083A40: add.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80083A44: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80083A48: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80083A4C: sub.s       $f8, $f30, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f30.fl - ctx->f4.fl;
    // 0x80083A50: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80083A54: jal         0x80081BEC
    // 0x80083A58: nop

    func_effect_80081BEC(rdram, ctx);
        goto after_7;
    // 0x80083A58: nop

    after_7:
    // 0x80083A5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80083A60: bne         $s0, $s2, L_800839C0
    if (ctx->r16 != ctx->r18) {
        // 0x80083A64: nop
    
            goto L_800839C0;
    }
    // 0x80083A64: nop

L_80083A68:
    // 0x80083A68: lh          $t8, 0x4E($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X4E);
    // 0x80083A6C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80083A70: b           L_80083B10
    // 0x80083A74: sh          $t9, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r25;
        goto L_80083B10;
    // 0x80083A74: sh          $t9, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r25;
L_80083A78:
    // 0x80083A78: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083A7C: lwc1        $f20, 0x76BC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X76BC);
    // 0x80083A80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083A84: lwc1        $f22, 0x76C0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X76C0);
    // 0x80083A88: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80083A8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80083A90: lwc1        $f18, 0x58($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X58);
    // 0x80083A94: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x80083A98: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80083A9C: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80083AA0: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80083AA4: addiu       $a0, $s1, 0x70
    ctx->r4 = ADD32(ctx->r17, 0X70);
    // 0x80083AA8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80083AAC: swc1        $f10, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f10.u32l;
    // 0x80083AB0: jal         0x8009BC2C
    // 0x80083AB4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x80083AB4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_8:
    // 0x80083AB8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80083ABC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80083AC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083AC4: lwc1        $f8, 0x76C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X76C4);
    // 0x80083AC8: lwc1        $f4, 0x70($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X70);
    // 0x80083ACC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80083AD0: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80083AD4: mul.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80083AD8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80083ADC: addiu       $a0, $s1, 0x60
    ctx->r4 = ADD32(ctx->r17, 0X60);
    // 0x80083AE0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80083AE4: jal         0x8009BC2C
    // 0x80083AE8: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x80083AE8: nop

    after_9:
    // 0x80083AEC: lh          $t0, 0x44($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X44);
    // 0x80083AF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80083AF4: addiu       $t1, $t0, -0x23
    ctx->r9 = ADD32(ctx->r8, -0X23);
    // 0x80083AF8: sh          $t1, 0x44($s1)
    MEM_H(0X44, ctx->r17) = ctx->r9;
    // 0x80083AFC: lh          $t2, 0x44($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X44);
    // 0x80083B00: bgez        $t2, L_80083B10
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80083B04: nop
    
            goto L_80083B10;
    }
    // 0x80083B04: nop

    // 0x80083B08: jal         0x80060FBC
    // 0x80083B0C: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    Object_Kill(rdram, ctx);
        goto after_10;
    // 0x80083B0C: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    after_10:
L_80083B10:
    // 0x80083B10: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80083B14: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80083B18: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80083B1C: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80083B20: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80083B24: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80083B28: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80083B2C: add.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80083B30: sub.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80083B34: lwc1        $f6, 0x48($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80083B38: jal         0x80005100
    // 0x80083B3C: sub.s       $f14, $f6, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f18.fl;
    Math_Atan2F(rdram, ctx);
        goto after_11;
    // 0x80083B3C: sub.s       $f14, $f6, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f18.fl;
    after_11:
    // 0x80083B40: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80083B44: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80083B48: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083B4C: lwc1        $f8, 0x76C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X76C8);
    // 0x80083B50: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80083B54: div.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80083B58: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x80083B5C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80083B60: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80083B64: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80083B68: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80083B6C: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80083B70: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80083B74: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80083B78: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80083B7C: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80083B80: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80083B84: jr          $ra
    // 0x80083B88: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80083B88: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void Audio_SetEnvSfxReverb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D400: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001D404: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001D408: jr          $ra
    // 0x8001D40C: sb          $a0, 0x5D60($at)
    MEM_B(0X5D60, ctx->r1) = ctx->r4;
    return;
    // 0x8001D40C: sb          $a0, 0x5D60($at)
    MEM_B(0X5D60, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void Effect_Effect357_Spawn80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007953C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80079540: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80079544: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80079548: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007954C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80079550: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80079554: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x80079558: addiu       $a0, $a0, 0x2C64
    ctx->r4 = ADD32(ctx->r4, 0X2C64);
    // 0x8007955C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_80079560:
    // 0x80079560: bnel        $t6, $zero, L_80079590
    if (ctx->r14 != 0) {
        // 0x80079564: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_80079590;
    }
    goto skip_0;
    // 0x80079564: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x80079568: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007956C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80079570: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80079574: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80079578: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007957C: jal         0x8007905C
    // 0x80079580: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Effect_Effect357_Setup(rdram, ctx);
        goto after_0;
    // 0x80079580: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80079584: b           L_800795A0
    // 0x80079588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800795A0;
    // 0x80079588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007958C: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_80079590:
    // 0x80079590: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80079594: beql        $at, $zero, L_80079560
    if (ctx->r1 == 0) {
        // 0x80079598: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_80079560;
    }
    goto skip_1;
    // 0x80079598: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007959C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800795A0:
    // 0x800795A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800795A4: jr          $ra
    // 0x800795A8: nop

    return;
    // 0x800795A8: nop

;}
RECOMP_FUNC void func_versus_800BD350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD350: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BD354: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BD358: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BD35C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BD360: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD364: lui         $a1, 0x700
    ctx->r5 = S32(0X700 << 16);
    // 0x800BD368: lui         $a2, 0x700
    ctx->r6 = S32(0X700 << 16);
    // 0x800BD36C: addiu       $t6, $zero, 0x13
    ctx->r14 = ADD32(0, 0X13);
    // 0x800BD370: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BD374: addiu       $a2, $a2, 0x4990
    ctx->r6 = ADD32(ctx->r6, 0X4990);
    // 0x800BD378: addiu       $a1, $a1, 0x44D0
    ctx->r5 = ADD32(ctx->r5, 0X44D0);
    // 0x800BD37C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BD380: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x800BD384: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x800BD388: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x800BD38C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800BD390: jal         0x8009D0BC
    // 0x800BD394: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_0;
    // 0x800BD394: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800BD398: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800BD39C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800BD3A0: jr          $ra
    // 0x800BD3A4: nop

    return;
    // 0x800BD3A4: nop

;}
RECOMP_FUNC void func_versus_800C2190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2190: jr          $ra
    // 0x800C2194: nop

    return;
    // 0x800C2194: nop

;}
RECOMP_FUNC void Effect_Sparkle_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078E50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80078E54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80078E58: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80078E5C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80078E60: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80078E64: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80078E68: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x80078E6C: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x80078E70: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_80078E74:
    // 0x80078E74: bnel        $t6, $zero, L_80078EA0
    if (ctx->r14 != 0) {
        // 0x80078E78: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_80078EA0;
    }
    goto skip_0;
    // 0x80078E78: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x80078E7C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80078E80: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80078E84: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80078E88: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80078E8C: jal         0x80078D60
    // 0x80078E90: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Effect_Sparkle_Setup(rdram, ctx);
        goto after_0;
    // 0x80078E90: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80078E94: b           L_80078EB0
    // 0x80078E98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80078EB0;
    // 0x80078E98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80078E9C: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_80078EA0:
    // 0x80078EA0: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80078EA4: beql        $at, $zero, L_80078E74
    if (ctx->r1 == 0) {
        // 0x80078EA8: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_80078E74;
    }
    goto skip_1;
    // 0x80078EA8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x80078EAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80078EB0:
    // 0x80078EB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80078EB4: jr          $ra
    // 0x80078EB8: nop

    return;
    // 0x80078EB8: nop

;}
RECOMP_FUNC void Audio_UpdateDelayedSeqCmds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018EE0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80018EE4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80018EE8: lui         $s3, 0x8015
    ctx->r19 = S32(0X8015 << 16);
    // 0x80018EEC: addiu       $s3, $s3, -0x48F8
    ctx->r19 = ADD32(ctx->r19, -0X48F8);
    // 0x80018EF0: lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X0);
    // 0x80018EF4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80018EF8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80018EFC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80018F00: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80018F04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80018F08: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80018F0C: beq         $v0, $zero, L_80018F84
    if (ctx->r2 == 0) {
        // 0x80018F10: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80018F84;
    }
    // 0x80018F10: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80018F14: lui         $s4, 0x8015
    ctx->r20 = S32(0X8015 << 16);
    // 0x80018F18: addiu       $s4, $s4, -0x48F0
    ctx->r20 = ADD32(ctx->r20, -0X48F0);
L_80018F1C:
    // 0x80018F1C: and         $t6, $v0, $v1
    ctx->r14 = ctx->r2 & ctx->r3;
    // 0x80018F20: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80018F24: beq         $t6, $zero, L_80018F68
    if (ctx->r14 == 0) {
        // 0x80018F28: or          $s0, $v1, $zero
        ctx->r16 = ctx->r3 | 0;
            goto L_80018F68;
    }
    // 0x80018F28: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x80018F2C: sll         $t7, $s1, 3
    ctx->r15 = S32(ctx->r17 << 3);
    // 0x80018F30: addu        $v0, $s4, $t7
    ctx->r2 = ADD32(ctx->r20, ctx->r15);
    // 0x80018F34: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x80018F38: beq         $v1, $zero, L_80018F48
    if (ctx->r3 == 0) {
        // 0x80018F3C: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_80018F48;
    }
    // 0x80018F3C: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x80018F40: b           L_80018F5C
    // 0x80018F44: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
        goto L_80018F5C;
    // 0x80018F44: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
L_80018F48:
    // 0x80018F48: jal         0x800182F4
    // 0x80018F4C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_0;
    // 0x80018F4C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_0:
    // 0x80018F50: lhu         $t9, 0x0($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X0);
    // 0x80018F54: xor         $t0, $t9, $s0
    ctx->r8 = ctx->r25 ^ ctx->r16;
    // 0x80018F58: sh          $t0, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r8;
L_80018F5C:
    // 0x80018F5C: xor         $v0, $s2, $s0
    ctx->r2 = ctx->r18 ^ ctx->r16;
    // 0x80018F60: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x80018F64: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80018F68:
    // 0x80018F68: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80018F6C: sll         $v1, $s0, 1
    ctx->r3 = S32(ctx->r16 << 1);
    // 0x80018F70: andi        $t2, $s1, 0xFF
    ctx->r10 = ctx->r17 & 0XFF;
    // 0x80018F74: andi        $t3, $v1, 0xFFFF
    ctx->r11 = ctx->r3 & 0XFFFF;
    // 0x80018F78: or          $s1, $t2, $zero
    ctx->r17 = ctx->r10 | 0;
    // 0x80018F7C: bne         $v0, $zero, L_80018F1C
    if (ctx->r2 != 0) {
        // 0x80018F80: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_80018F1C;
    }
    // 0x80018F80: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
L_80018F84:
    // 0x80018F84: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80018F88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80018F8C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80018F90: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80018F94: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80018F98: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80018F9C: jr          $ra
    // 0x80018FA0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80018FA0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void AudioHeap_SearchPermanentCache(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DB0C: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8000DB10: lw          $v1, -0x3844($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3844);
    // 0x8000DB14: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8000DB18: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000DB1C: blez        $v1, L_8000DB58
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000DB20: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000DB58;
    }
    // 0x8000DB20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000DB24: addiu       $a1, $a1, -0x3850
    ctx->r5 = ADD32(ctx->r5, -0X3850);
L_8000DB28:
    // 0x8000DB28: lh          $t6, 0x18($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X18);
    // 0x8000DB2C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000DB30: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000DB34: bne         $a0, $t6, L_8000DB50
    if (ctx->r4 != ctx->r14) {
        // 0x8000DB38: nop
    
            goto L_8000DB50;
    }
    // 0x8000DB38: nop

    // 0x8000DB3C: lh          $t7, 0x1A($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X1A);
    // 0x8000DB40: bne         $a2, $t7, L_8000DB50
    if (ctx->r6 != ctx->r15) {
        // 0x8000DB44: nop
    
            goto L_8000DB50;
    }
    // 0x8000DB44: nop

    // 0x8000DB48: jr          $ra
    // 0x8000DB4C: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    return;
    // 0x8000DB4C: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
L_8000DB50:
    // 0x8000DB50: bne         $at, $zero, L_8000DB28
    if (ctx->r1 != 0) {
        // 0x8000DB54: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_8000DB28;
    }
    // 0x8000DB54: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
L_8000DB58:
    // 0x8000DB58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000DB5C: jr          $ra
    // 0x8000DB60: nop

    return;
    // 0x8000DB60: nop

;}
RECOMP_FUNC void Math_FAsinF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FE00: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001FE04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001FE08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001FE0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001FE10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001FE14: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001FE18: jal         0x8001FD0C
    // 0x8001FE1C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_FAtan2F(rdram, ctx);
        goto after_0;
    // 0x8001FE1C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_0:
    // 0x8001FE20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001FE24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001FE28: jr          $ra
    // 0x8001FE2C: nop

    return;
    // 0x8001FE2C: nop

;}
RECOMP_FUNC void Audio_SeqLayerNoteDecay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001266C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80012670: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012674: jal         0x80012438
    // 0x80012678: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    Audio_SeqLayerDecayRelease(rdram, ctx);
        goto after_0;
    // 0x80012678: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x8001267C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80012684: jr          $ra
    // 0x80012688: nop

    return;
    // 0x80012688: nop

;}
RECOMP_FUNC void Effect_FireSmoke1_Spawn3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D2C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007D2CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007D2D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8007D2D4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8007D2D8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8007D2DC: jal         0x8007D008
    // 0x8007D2E0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    Effect_FireSmoke1_Spawn2(rdram, ctx);
        goto after_0;
    // 0x8007D2E0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x8007D2E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007D2E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007D2EC: jr          $ra
    // 0x8007D2F0: nop

    return;
    // 0x8007D2F0: nop

;}
RECOMP_FUNC void AudioLoad_ProcessLoads(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FF9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000FFA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000FFA4: jal         0x80010870
    // 0x8000FFA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    AudioLoad_ProcessSlowLoads(rdram, ctx);
        goto after_0;
    // 0x8000FFA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000FFAC: jal         0x8001154C
    // 0x8000FFB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    AudioLoad_ProcessSamplePreloads(rdram, ctx);
        goto after_1;
    // 0x8000FFB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8000FFB4: jal         0x80010BF0
    // 0x8000FFB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    AudioLoad_ProcessAsyncLoads(rdram, ctx);
        goto after_2;
    // 0x8000FFB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8000FFBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000FFC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000FFC4: jr          $ra
    // 0x8000FFC8: nop

    return;
    // 0x8000FFC8: nop

;}
RECOMP_FUNC void HUD_TeammateStatus_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087788: addiu       $sp, $sp, -0x130
    ctx->r29 = ADD32(ctx->r29, -0X130);
    // 0x8008778C: lui         $at, 0x42B8
    ctx->r1 = S32(0X42B8 << 16);
    // 0x80087790: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80087794: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80087798: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8008779C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800877A0: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x800877A4: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x800877A8: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x800877AC: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x800877B0: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x800877B4: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x800877B8: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x800877BC: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x800877C0: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800877C4: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x800877C8: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x800877CC: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x800877D0: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x800877D4: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x800877D8: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800877DC: addiu       $t7, $t7, 0x1D18
    ctx->r15 = ADD32(ctx->r15, 0X1D18);
    // 0x800877E0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800877E4: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800877E8: addiu       $t6, $sp, 0x120
    ctx->r14 = ADD32(ctx->r29, 0X120);
    // 0x800877EC: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800877F0: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x800877F4: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x800877F8: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800877FC: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80087800: addiu       $t2, $t2, 0x1D28
    ctx->r10 = ADD32(ctx->r10, 0X1D28);
    // 0x80087804: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x80087808: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8008780C: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x80087810: addiu       $t1, $sp, 0x114
    ctx->r9 = ADD32(ctx->r29, 0X114);
    // 0x80087814: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80087818: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x8008781C: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x80087820: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x80087824: addiu       $t8, $t8, 0x1D34
    ctx->r24 = ADD32(ctx->r24, 0X1D34);
    // 0x80087828: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x8008782C: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x80087830: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x80087834: addiu       $t9, $sp, 0x104
    ctx->r25 = ADD32(ctx->r29, 0X104);
    // 0x80087838: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x8008783C: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x80087840: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x80087844: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80087848: addiu       $t3, $t3, 0x1D40
    ctx->r11 = ADD32(ctx->r11, 0X1D40);
    // 0x8008784C: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x80087850: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    // 0x80087854: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80087858: addiu       $t4, $sp, 0xF8
    ctx->r12 = ADD32(ctx->r29, 0XF8);
    // 0x8008785C: lw          $t5, 0x4($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X4);
    // 0x80087860: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x80087864: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x80087868: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x8008786C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80087870: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    // 0x80087874: lui         $at, 0x430A
    ctx->r1 = S32(0X430A << 16);
    // 0x80087878: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8008787C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80087880: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80087884: lui         $at, 0x4308
    ctx->r1 = S32(0X4308 << 16);
    // 0x80087888: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8008788C: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x80087890: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80087894: lui         $at, 0x4306
    ctx->r1 = S32(0X4306 << 16);
    // 0x80087898: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008789C: lui         $at, 0x4312
    ctx->r1 = S32(0X4312 << 16);
    // 0x800878A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800878A4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800878A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800878AC: sub.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x800878B0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800878B4: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x800878B8: add.s       $f12, $f22, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f22.fl + ctx->f10.fl;
    // 0x800878BC: swc1        $f8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f8.u32l;
    // 0x800878C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800878C4: add.s       $f16, $f2, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800878C8: lwc1        $f26, 0x7880($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X7880);
    // 0x800878CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800878D0: sub.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800878D4: lwc1        $f24, 0x7884($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X7884);
    // 0x800878D8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x800878DC: add.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x800878E0: swc1        $f4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f4.u32l;
    // 0x800878E4: swc1        $f22, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f22.u32l;
    // 0x800878E8: sub.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x800878EC: swc1        $f10, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f10.u32l;
    // 0x800878F0: addiu       $t9, $t9, 0x78BC
    ctx->r25 = ADD32(ctx->r25, 0X78BC);
    // 0x800878F4: add.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800878F8: swc1        $f8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f8.u32l;
    // 0x800878FC: addiu       $t6, $sp, 0xF8
    ctx->r14 = ADD32(ctx->r29, 0XF8);
    // 0x80087900: add.s       $f8, $f16, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x80087904: addiu       $t7, $sp, 0x104
    ctx->r15 = ADD32(ctx->r29, 0X104);
    // 0x80087908: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8008790C: add.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80087910: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80087914: swc1        $f16, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f16.u32l;
    // 0x80087918: swc1        $f4, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f4.u32l;
    // 0x8008791C: swc1        $f8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f8.u32l;
    // 0x80087920: swc1        $f10, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f10.u32l;
    // 0x80087924: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x80087928: sw          $t7, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r15;
    // 0x8008792C: sw          $t6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r14;
    // 0x80087930: sw          $t9, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r25;
    // 0x80087934: swc1        $f16, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f16.u32l;
    // 0x80087938: addiu       $s3, $sp, 0xCC
    ctx->r19 = ADD32(ctx->r29, 0XCC);
    // 0x8008793C: addiu       $s4, $sp, 0xA8
    ctx->r20 = ADD32(ctx->r29, 0XA8);
    // 0x80087940: addiu       $fp, $sp, 0x114
    ctx->r30 = ADD32(ctx->r29, 0X114);
    // 0x80087944: addiu       $s5, $sp, 0x120
    ctx->r21 = ADD32(ctx->r29, 0X120);
    // 0x80087948: addiu       $s6, $zero, 0x28
    ctx->r22 = ADD32(0, 0X28);
    // 0x8008794C: swc1        $f14, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f14.u32l;
    // 0x80087950: swc1        $f2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f2.u32l;
    // 0x80087954: swc1        $f2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f2.u32l;
    // 0x80087958: swc1        $f2, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f2.u32l;
    // 0x8008795C: swc1        $f18, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f18.u32l;
    // 0x80087960: swc1        $f6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f6.u32l;
    // 0x80087964: swc1        $f6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f6.u32l;
    // 0x80087968: swc1        $f6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f6.u32l;
L_8008796C:
    // 0x8008796C: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80087970: lwc1        $f8, 0x4($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X4);
    // 0x80087974: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80087978: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x8008797C: sub.s       $f12, $f4, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80087980: jal         0x80086C08
    // 0x80087984: sub.s       $f14, $f8, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f20.fl;
    HUD_MsgWindowBg_Draw2(rdram, ctx);
        goto after_0;
    // 0x80087984: sub.s       $f14, $f8, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f20.fl;
    after_0:
    // 0x80087988: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8008798C: jal         0x800B8DD0
    // 0x80087990: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80087990: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_1:
    // 0x80087994: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80087998: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x8008799C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800879A0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800879A4: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x800879A8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800879AC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800879B0: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x800879B4: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x800879B8: lwc1        $f10, 0x4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800879BC: lw          $a1, 0x0($fp)
    ctx->r5 = MEM_W(ctx->r30, 0X0);
    // 0x800879C0: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x800879C4: lw          $a3, 0x0($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X0);
    // 0x800879C8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x800879CC: lwc1        $f6, 0x4($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X4);
    // 0x800879D0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800879D4: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800879D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800879DC: jal         0x8009D994
    // 0x800879E0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_2;
    // 0x800879E0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x800879E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800879E8: jal         0x800B8DD0
    // 0x800879EC: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x800879EC: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_3:
    // 0x800879F0: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x800879F4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800879F8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800879FC: lw          $s7, 0x0($t3)
    ctx->r23 = MEM_W(ctx->r11, 0X0);
    // 0x80087A00: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80087A04: bgtzl       $s7, L_80087A34
    if (SIGNED(ctx->r23) > 0) {
        // 0x80087A08: lw          $v0, 0x0($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X0);
            goto L_80087A34;
    }
    goto skip_0;
    // 0x80087A08: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    skip_0:
    // 0x80087A0C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80087A10: lui         $t6, 0x3030
    ctx->r14 = S32(0X3030 << 16);
    // 0x80087A14: ori         $t6, $t6, 0x30FF
    ctx->r14 = ctx->r14 | 0X30FF;
    // 0x80087A18: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80087A1C: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80087A20: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80087A24: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80087A28: b           L_80087A4C
    // 0x80087A2C: nop

        goto L_80087A4C;
    // 0x80087A2C: nop

    // 0x80087A30: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_80087A34:
    // 0x80087A34: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80087A38: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80087A3C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80087A40: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x80087A44: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80087A48: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_80087A4C:
    // 0x80087A4C: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    // 0x80087A50: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80087A54: lw          $t2, 0x4($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X4);
    // 0x80087A58: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80087A5C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80087A60: lwc1        $f8, 0x0($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80087A64: sll         $t1, $s1, 1
    ctx->r9 = S32(ctx->r17 << 1);
    // 0x80087A68: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80087A6C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80087A70: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80087A74: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80087A78: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    // 0x80087A7C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x80087A80: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80087A84: jal         0x8009D418
    // 0x80087A88: addu        $a1, $t2, $t1
    ctx->r5 = ADD32(ctx->r10, ctx->r9);
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_4;
    // 0x80087A88: addu        $a1, $t2, $t1
    ctx->r5 = ADD32(ctx->r10, ctx->r9);
    after_4:
    // 0x80087A8C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80087A90: bne         $s0, $s6, L_80087A4C
    if (ctx->r16 != ctx->r22) {
        // 0x80087A94: addiu       $s1, $s1, 0x370
        ctx->r17 = ADD32(ctx->r17, 0X370);
            goto L_80087A4C;
    }
    // 0x80087A94: addiu       $s1, $s1, 0x370
    ctx->r17 = ADD32(ctx->r17, 0X370);
    // 0x80087A98: lwc1        $f10, 0x0($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80087A9C: lw          $a1, 0x4($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X4);
    // 0x80087AA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80087AA4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80087AA8: lwc1        $f8, 0x0($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80087AAC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80087AB0: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80087AB4: add.s       $f6, $f8, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x80087AB8: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    // 0x80087ABC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80087AC0: addiu       $a1, $a1, 0xDC0
    ctx->r5 = ADD32(ctx->r5, 0XDC0);
    // 0x80087AC4: jal         0x8009D418
    // 0x80087AC8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_5;
    // 0x80087AC8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x80087ACC: lwc1        $f12, 0x8($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80087AD0: lwc1        $f14, 0x8($s4)
    ctx->f14.u32l = MEM_W(ctx->r20, 0X8);
    // 0x80087AD4: jal         0x80086110
    // 0x80087AD8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    HUD_TeamShields_Draw(rdram, ctx);
        goto after_6;
    // 0x80087AD8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_6:
    // 0x80087ADC: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x80087AE0: lw          $t5, 0x88($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X88);
    // 0x80087AE4: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x80087AE8: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80087AEC: addiu       $t8, $sp, 0x12C
    ctx->r24 = ADD32(ctx->r29, 0X12C);
    // 0x80087AF0: addiu       $t3, $t4, 0x4
    ctx->r11 = ADD32(ctx->r12, 0X4);
    // 0x80087AF4: addiu       $t7, $t5, 0x4
    ctx->r15 = ADD32(ctx->r13, 0X4);
    // 0x80087AF8: addiu       $t9, $t6, -0x4
    ctx->r25 = ADD32(ctx->r14, -0X4);
    // 0x80087AFC: sw          $t9, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r25;
    // 0x80087B00: sw          $t7, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r15;
    // 0x80087B04: sw          $t3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r11;
    // 0x80087B08: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x80087B0C: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x80087B10: bne         $s5, $t8, L_8008796C
    if (ctx->r21 != ctx->r24) {
        // 0x80087B14: addiu       $fp, $fp, 0x4
        ctx->r30 = ADD32(ctx->r30, 0X4);
            goto L_8008796C;
    }
    // 0x80087B14: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x80087B18: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x80087B1C: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80087B20: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x80087B24: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x80087B28: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x80087B2C: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x80087B30: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80087B34: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80087B38: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80087B3C: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80087B40: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80087B44: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80087B48: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x80087B4C: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x80087B50: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x80087B54: jr          $ra
    // 0x80087B58: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
    return;
    // 0x80087B58: addiu       $sp, $sp, 0x130
    ctx->r29 = ADD32(ctx->r29, 0X130);
;}
RECOMP_FUNC void stub_80094D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094D10: jr          $ra
    // 0x80094D14: nop

    return;
    // 0x80094D14: nop

;}
RECOMP_FUNC void Audio_GetPortamentoFreqScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013708: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001370C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80013710: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80013714: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80013718: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001371C: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80013720: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80013724: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80013728: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001372C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80013730: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80013734: nop

    // 0x80013738: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8001373C: beql        $v0, $zero, L_8001378C
    if (ctx->r2 == 0) {
        // 0x80013740: mfc1        $v0, $f16
        ctx->r2 = (int32_t)ctx->f16.u32l;
            goto L_8001378C;
    }
    goto skip_0;
    // 0x80013740: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x80013744: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80013748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001374C: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80013750: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80013754: nop

    // 0x80013758: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8001375C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80013760: nop

    // 0x80013764: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80013768: bne         $v0, $zero, L_80013780
    if (ctx->r2 != 0) {
        // 0x8001376C: nop
    
            goto L_80013780;
    }
    // 0x8001376C: nop

    // 0x80013770: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80013774: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80013778: b           L_80013798
    // 0x8001377C: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80013798;
    // 0x8001377C: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80013780:
    // 0x80013780: b           L_80013798
    // 0x80013784: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80013798;
    // 0x80013784: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80013788: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
L_8001378C:
    // 0x8001378C: nop

    // 0x80013790: bltz        $v0, L_80013780
    if (SIGNED(ctx->r2) < 0) {
        // 0x80013794: nop
    
            goto L_80013780;
    }
    // 0x80013794: nop

L_80013798:
    // 0x80013798: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001379C: sltiu       $at, $v0, 0x80
    ctx->r1 = ctx->r2 < 0X80 ? 1 : 0;
    // 0x800137A0: bnel        $at, $zero, L_800137B0
    if (ctx->r1 != 0) {
        // 0x800137A4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800137B0;
    }
    goto skip_1;
    // 0x800137A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x800137A8: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x800137AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800137B0:
    // 0x800137B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800137B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800137B8: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800137BC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800137C0: lwc1        $f18, -0x36D0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X36D0);
    // 0x800137C4: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800137C8: sub.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x800137CC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800137D0: add.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x800137D4: jr          $ra
    // 0x800137D8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800137D8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void Audio_UpdateBlueMarineNoise(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B774: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x8001B778: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x8001B77C: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8001B780: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001B784: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8001B788: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8001B78C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001B790: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x8001B794: sll         $v1, $v1, 5
    ctx->r3 = S32(ctx->r3 << 5);
    // 0x8001B798: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001B79C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8001B7A0: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x8001B7A4: lbu         $t7, 0x48C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X48C);
    // 0x8001B7A8: sll         $t2, $a2, 3
    ctx->r10 = S32(ctx->r6 << 3);
    // 0x8001B7AC: subu        $t2, $t2, $a2
    ctx->r10 = SUB32(ctx->r10, ctx->r6);
    // 0x8001B7B0: beq         $t7, $zero, L_8001B810
    if (ctx->r15 == 0) {
        // 0x8001B7B4: sll         $t2, $t2, 4
        ctx->r10 = S32(ctx->r10 << 4);
            goto L_8001B810;
    }
    // 0x8001B7B4: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x8001B7B8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8001B7BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001B7C0: lwc1        $f4, 0x490($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X490);
    // 0x8001B7C4: sll         $t8, $a2, 3
    ctx->r24 = S32(ctx->r6 << 3);
    // 0x8001B7C8: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x8001B7CC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8001B7D0: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001B7D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001B7D8: addiu       $t9, $t9, -0x47B0
    ctx->r25 = ADD32(ctx->r25, -0X47B0);
    // 0x8001B7DC: bc1f        L_8001B810
    if (!c1cs) {
        // 0x8001B7E0: sll         $t8, $t8, 4
        ctx->r24 = S32(ctx->r24 << 4);
            goto L_8001B810;
    }
    // 0x8001B7E0: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8001B7E4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8001B7E8: lwc1        $f0, -0x6F30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6F30);
    // 0x8001B7EC: lwc1        $f8, 0x28($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X28);
    // 0x8001B7F0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8001B7F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001B7F8: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8001B7FC: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x8001B800: sw          $t1, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r9;
    // 0x8001B804: swc1        $f0, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->f0.u32l;
    // 0x8001B808: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8001B80C: swc1        $f18, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->f18.u32l;
L_8001B810:
    // 0x8001B810: lbu         $t4, 0x494($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X494);
    // 0x8001B814: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001B818: addiu       $t3, $t3, -0x47B0
    ctx->r11 = ADD32(ctx->r11, -0X47B0);
    // 0x8001B81C: beq         $t4, $zero, L_8001B89C
    if (ctx->r12 == 0) {
        // 0x8001B820: addu        $t0, $t2, $t3
        ctx->r8 = ADD32(ctx->r10, ctx->r11);
            goto L_8001B89C;
    }
    // 0x8001B820: addu        $t0, $t2, $t3
    ctx->r8 = ADD32(ctx->r10, ctx->r11);
    // 0x8001B824: lw          $a1, 0x47C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X47C);
    // 0x8001B828: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8001B82C: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8001B830: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8001B834: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x8001B838: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8001B83C: ori         $a0, $a0, 0x17
    ctx->r4 = ctx->r4 | 0X17;
    // 0x8001B840: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8001B844: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8001B848: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8001B84C: sb          $a2, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r6;
    // 0x8001B850: jal         0x80019218
    // 0x8001B854: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8001B854: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_0:
    // 0x8001B858: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8001B85C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001B860: lwc1        $f0, -0x6F2C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6F2C);
    // 0x8001B864: lwc1        $f4, 0x14($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X14);
    // 0x8001B868: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001B86C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001B870: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8001B874: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8001B878: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8001B87C: sw          $t6, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r14;
    // 0x8001B880: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001B884: swc1        $f0, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f0.u32l;
    // 0x8001B888: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8001B88C: lbu         $a2, 0x3B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3B);
    // 0x8001B890: swc1        $f10, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f10.u32l;
    // 0x8001B894: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x8001B898: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
L_8001B89C:
    // 0x8001B89C: lwc1        $f0, 0x488($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X488);
    // 0x8001B8A0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001B8A4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001B8A8: sll         $t3, $a2, 3
    ctx->r11 = S32(ctx->r6 << 3);
    // 0x8001B8AC: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x8001B8B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001B8B4: subu        $t3, $t3, $a2
    ctx->r11 = SUB32(ctx->r11, ctx->r6);
    // 0x8001B8B8: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x8001B8BC: bc1f        L_8001B8CC
    if (!c1cs) {
        // 0x8001B8C0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001B8CC;
    }
    // 0x8001B8C0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001B8C4: b           L_8001B8D0
    // 0x8001B8C8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8001B8D0;
    // 0x8001B8C8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8001B8CC:
    // 0x8001B8CC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_8001B8D0:
    // 0x8001B8D0: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8001B8D4: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x8001B8D8: addiu       $t4, $t4, -0x47B0
    ctx->r12 = ADD32(ctx->r12, -0X47B0);
    // 0x8001B8DC: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x8001B8E0: bc1f        L_8001B920
    if (!c1cs) {
        // 0x8001B8E4: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8001B920;
    }
    // 0x8001B8E4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8001B8E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001B8EC: lwc1        $f0, -0x6F28($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6F28);
    // 0x8001B8F0: lwc1        $f18, 0x3C($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X3C);
    // 0x8001B8F4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8001B8F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001B8FC: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8001B900: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x8001B904: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8001B908: sw          $t8, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->r24;
    // 0x8001B90C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001B910: sb          $t9, 0x4C($t0)
    MEM_B(0X4C, ctx->r8) = ctx->r25;
    // 0x8001B914: swc1        $f0, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f0.u32l;
    // 0x8001B918: b           L_8001B938
    // 0x8001B91C: swc1        $f8, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->f8.u32l;
        goto L_8001B938;
    // 0x8001B91C: swc1        $f8, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->f8.u32l;
L_8001B920:
    // 0x8001B920: lbu         $t1, 0x4C($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X4C);
    // 0x8001B924: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001B928: beql        $t1, $zero, L_8001B93C
    if (ctx->r9 == 0) {
        // 0x8001B92C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8001B93C;
    }
    goto skip_0;
    // 0x8001B92C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x8001B930: sb          $zero, 0x4C($t0)
    MEM_B(0X4C, ctx->r8) = 0;
    // 0x8001B934: sw          $t2, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->r10;
L_8001B938:
    // 0x8001B938: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8001B93C:
    // 0x8001B93C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001B940: addiu       $a3, $a3, 0x5E58
    ctx->r7 = ADD32(ctx->r7, 0X5E58);
    // 0x8001B944: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
L_8001B948:
    // 0x8001B948: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B94C: mflo        $t5
    ctx->r13 = lo;
    // 0x8001B950: addu        $v0, $a1, $t5
    ctx->r2 = ADD32(ctx->r5, ctx->r13);
    // 0x8001B954: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x8001B958: beql        $a0, $zero, L_8001B9D4
    if (ctx->r4 == 0) {
        // 0x8001B95C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8001B9D4;
    }
    goto skip_1;
    // 0x8001B95C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x8001B960: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001B964: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8001B968: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x8001B96C: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8001B970: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8001B974: bne         $t6, $zero, L_8001B9D0
    if (ctx->r14 != 0) {
        // 0x8001B978: swc1        $f18, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
            goto L_8001B9D0;
    }
    // 0x8001B978: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x8001B97C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8001B980: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8001B984: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x8001B988: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8001B98C: nop

    // 0x8001B990: bc1tl       L_8001B9D4
    if (c1cs) {
        // 0x8001B994: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8001B9D4;
    }
    goto skip_2;
    // 0x8001B994: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x8001B998: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8001B99C: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001B9A0: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8001B9A4: mtc1        $a0, $f14
    ctx->f14.u32l = ctx->r4;
    // 0x8001B9A8: sub.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8001B9AC: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x8001B9B0: bgez        $a0, L_8001B9C8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8001B9B4: cvt.s.w     $f16, $f14
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = CVT_S_W(ctx->f14.u32l);
            goto L_8001B9C8;
    }
    // 0x8001B9B4: cvt.s.w     $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = CVT_S_W(ctx->f14.u32l);
    // 0x8001B9B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001B9BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001B9C0: nop

    // 0x8001B9C4: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8001B9C8:
    // 0x8001B9C8: div.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8001B9CC: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
L_8001B9D0:
    // 0x8001B9D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8001B9D4:
    // 0x8001B9D4: andi        $t1, $v1, 0xFF
    ctx->r9 = ctx->r3 & 0XFF;
    // 0x8001B9D8: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x8001B9DC: bne         $at, $zero, L_8001B948
    if (ctx->r1 != 0) {
        // 0x8001B9E0: or          $v1, $t1, $zero
        ctx->r3 = ctx->r9 | 0;
            goto L_8001B948;
    }
    // 0x8001B9E0: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x8001B9E4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8001B9E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001B9EC:
    // 0x8001B9EC: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B9F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001B9F4: andi        $t4, $v1, 0xFF
    ctx->r12 = ctx->r3 & 0XFF;
    // 0x8001B9F8: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x8001B9FC: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x8001BA00: mflo        $t2
    ctx->r10 = lo;
    // 0x8001BA04: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x8001BA08: lwc1        $f6, 0x0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8001BA0C: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8001BA10: bne         $at, $zero, L_8001B9EC
    if (ctx->r1 != 0) {
        // 0x8001BA14: nop
    
            goto L_8001B9EC;
    }
    // 0x8001BA14: nop

    // 0x8001BA18: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8001BA1C: nop

    // 0x8001BA20: bc1fl       L_8001BA30
    if (!c1cs) {
        // 0x8001BA24: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001BA30;
    }
    goto skip_3;
    // 0x8001BA24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8001BA28: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8001BA2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001BA30:
    // 0x8001BA30: swc1        $f2, 0x68($t0)
    MEM_W(0X68, ctx->r8) = ctx->f2.u32l;
    // 0x8001BA34: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001BA38: jr          $ra
    // 0x8001BA3C: nop

    return;
    // 0x8001BA3C: nop

;}
RECOMP_FUNC void RCP_SetupDL_48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA550: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BA554: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BA558: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BA55C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BA560: addiu       $t8, $t8, 0x3F30
    ctx->r24 = ADD32(ctx->r24, 0X3F30);
    // 0x800BA564: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BA568: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BA56C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800BA570: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA574: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BA578: jr          $ra
    // 0x800BA57C: nop

    return;
    // 0x800BA57C: nop

;}
RECOMP_FUNC void ItemSilverStar_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C9C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C9C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005C9C8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005C9CC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005C9D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005C9D4: jal         0x800B8DD0
    // 0x8005C9D8: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8005C9D8: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_0:
    // 0x8005C9DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005C9E0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005C9E4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005C9E8: lui         $t7, 0xBB00
    ctx->r15 = S32(0XBB00 << 16);
    // 0x8005C9EC: ori         $t7, $t7, 0x1
    ctx->r15 = ctx->r15 | 0X1;
    // 0x8005C9F0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8005C9F4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005C9F8: lui         $t8, 0xBB8
    ctx->r24 = S32(0XBB8 << 16);
    // 0x8005C9FC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8005CA00: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005CA04: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005CA08: lui         $t0, 0xB700
    ctx->r8 = S32(0XB700 << 16);
    // 0x8005CA0C: lui         $t1, 0xC
    ctx->r9 = S32(0XC << 16);
    // 0x8005CA10: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005CA14: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8005CA18: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8005CA1C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8005CA20: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8005CA24: jal         0x8005980C
    // 0x8005CA28: lwc1        $f12, 0x68($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X68);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_1;
    // 0x8005CA28: lwc1        $f12, 0x68($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X68);
    after_1:
    // 0x8005CA2C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005CA30: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005CA34: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005CA38: lui         $t5, 0x102
    ctx->r13 = S32(0X102 << 16);
    // 0x8005CA3C: addiu       $t5, $t5, -0x6360
    ctx->r13 = ADD32(ctx->r13, -0X6360);
    // 0x8005CA40: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8005CA44: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005CA48: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8005CA4C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8005CA50: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8005CA54: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005CA58: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x8005CA5C: lui         $t8, 0xC
    ctx->r24 = S32(0XC << 16);
    // 0x8005CA60: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8005CA64: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8005CA68: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8005CA6C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005CA70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005CA74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005CA78: jr          $ra
    // 0x8005CA7C: nop

    return;
    // 0x8005CA7C: nop

;}
RECOMP_FUNC void RCP_SetupDL_55(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9E80: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B9E84: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800B9E88: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B9E8C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B9E90: addiu       $t8, $t8, 0x4128
    ctx->r24 = ADD32(ctx->r24, 0X4128);
    // 0x800B9E94: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B9E98: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B9E9C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B9EA0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B9EA4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B9EA8: jr          $ra
    // 0x800B9EAC: nop

    return;
    // 0x800B9EAC: nop

;}
RECOMP_FUNC void RCP_SetupDL_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B95E8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B95EC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800B95F0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B95F4: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B95F8: addiu       $t8, $t8, 0x36C0
    ctx->r24 = ADD32(ctx->r24, 0X36C0);
    // 0x800B95FC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B9600: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B9604: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B9608: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B960C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B9610: jr          $ra
    // 0x800B9614: nop

    return;
    // 0x800B9614: nop

;}
RECOMP_FUNC void Effect_Effect394_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080D04: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80080D08: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80080D0C: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80080D10: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80080D14: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80080D18: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80080D1C: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80080D20: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80080D24: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80080D28: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80080D2C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80080D30: lhu         $t6, 0x7A($s5)
    ctx->r14 = MEM_HU(ctx->r21, 0X7A);
    // 0x80080D34: sltiu       $at, $t6, 0x13
    ctx->r1 = ctx->r14 < 0X13 ? 1 : 0;
    // 0x80080D38: beq         $at, $zero, L_800815B0
    if (ctx->r1 == 0) {
        // 0x80080D3C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800815B0;
    }
    // 0x80080D3C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80080D40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80080D44: addu        $at, $at, $t6
    gpr jr_addend_80080D4C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80080D48: lw          $t6, 0x752C($at)
    ctx->r14 = ADD32(ctx->r1, 0X752C);
    // 0x80080D4C: jr          $t6
    // 0x80080D50: nop

    switch (jr_addend_80080D4C >> 2) {
        case 0: goto L_80080D54; break;
        case 1: goto L_80080DB4; break;
        case 2: goto L_800815B0; break;
        case 3: goto L_800815B0; break;
        case 4: goto L_800815B0; break;
        case 5: goto L_800815B0; break;
        case 6: goto L_800815B0; break;
        case 7: goto L_800815B0; break;
        case 8: goto L_800815B0; break;
        case 9: goto L_800815B0; break;
        case 10: goto L_80080EB0; break;
        case 11: goto L_80080F54; break;
        case 12: goto L_80080FE4; break;
        case 13: goto L_80081034; break;
        case 14: goto L_800810CC; break;
        case 15: goto L_8008115C; break;
        case 16: goto L_800811F4; break;
        case 17: goto L_80081368; break;
        case 18: goto L_80081538; break;
        default: switch_error(__func__, 0x80080D4C, 0x800D752C);
    }
    // 0x80080D50: nop

L_80080D54:
    // 0x80080D54: lh          $a1, 0x44($s5)
    ctx->r5 = MEM_H(ctx->r21, 0X44);
    // 0x80080D58: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
    // 0x80080D5C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80080D60: beq         $s0, $a1, L_80080D70
    if (ctx->r16 == ctx->r5) {
        // 0x80080D64: nop
    
            goto L_80080D70;
    }
    // 0x80080D64: nop

    // 0x80080D68: jal         0x800B8DD0
    // 0x80080D6C: addiu       $a0, $s3, 0x7E64
    ctx->r4 = ADD32(ctx->r19, 0X7E64);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80080D6C: addiu       $a0, $s3, 0x7E64
    ctx->r4 = ADD32(ctx->r19, 0X7E64);
    after_0:
L_80080D70:
    // 0x80080D70: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80080D74: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x80080D78: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80080D7C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80080D80: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80080D84: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80080D88: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x80080D8C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80080D90: lw          $t9, 0x74($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X74);
    // 0x80080D94: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80080D98: lh          $t1, 0x44($s5)
    ctx->r9 = MEM_H(ctx->r21, 0X44);
    // 0x80080D9C: beql        $s0, $t1, L_800815B4
    if (ctx->r16 == ctx->r9) {
        // 0x80080DA0: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800815B4;
    }
    goto skip_0;
    // 0x80080DA0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80080DA4: jal         0x800B8DD0
    // 0x80080DA8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80080DA8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x80080DAC: b           L_800815B4
    // 0x80080DB0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800815B4;
    // 0x80080DB0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80080DB4:
    // 0x80080DB4: lh          $t2, 0x48($s5)
    ctx->r10 = MEM_H(ctx->r21, 0X48);
    // 0x80080DB8: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80080DBC: bnel        $t2, $zero, L_80080DD0
    if (ctx->r10 != 0) {
        // 0x80080DC0: lh          $a1, 0x44($s5)
        ctx->r5 = MEM_H(ctx->r21, 0X44);
            goto L_80080DD0;
    }
    goto skip_1;
    // 0x80080DC0: lh          $a1, 0x44($s5)
    ctx->r5 = MEM_H(ctx->r21, 0X44);
    skip_1:
    // 0x80080DC4: lh          $t3, 0x46($s5)
    ctx->r11 = MEM_H(ctx->r21, 0X46);
    // 0x80080DC8: sh          $t3, 0x48($s5)
    MEM_H(0X48, ctx->r21) = ctx->r11;
    // 0x80080DCC: lh          $a1, 0x44($s5)
    ctx->r5 = MEM_H(ctx->r21, 0X44);
L_80080DD0:
    // 0x80080DD0: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
    // 0x80080DD4: beql        $s0, $a1, L_80080DE8
    if (ctx->r16 == ctx->r5) {
        // 0x80080DD8: lh          $t4, 0x46($s5)
        ctx->r12 = MEM_H(ctx->r21, 0X46);
            goto L_80080DE8;
    }
    goto skip_2;
    // 0x80080DD8: lh          $t4, 0x46($s5)
    ctx->r12 = MEM_H(ctx->r21, 0X46);
    skip_2:
    // 0x80080DDC: jal         0x800B8DD0
    // 0x80080DE0: addiu       $a0, $s3, 0x7E64
    ctx->r4 = ADD32(ctx->r19, 0X7E64);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x80080DE0: addiu       $a0, $s3, 0x7E64
    ctx->r4 = ADD32(ctx->r19, 0X7E64);
    after_2:
    // 0x80080DE4: lh          $t4, 0x46($s5)
    ctx->r12 = MEM_H(ctx->r21, 0X46);
L_80080DE8:
    // 0x80080DE8: lh          $t5, 0x48($s5)
    ctx->r13 = MEM_H(ctx->r21, 0X48);
    // 0x80080DEC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80080DF0: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80080DF4: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80080DF8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80080DFC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80080E00: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80080E04: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x80080E08: addiu       $t0, $zero, -0x100
    ctx->r8 = ADD32(0, -0X100);
    // 0x80080E0C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80080E10: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80080E14: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80080E18: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80080E1C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80080E20: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80080E24: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80080E28: nop

    // 0x80080E2C: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x80080E30: bnel        $at, $zero, L_80080E40
    if (ctx->r1 != 0) {
        // 0x80080E34: slti        $at, $a1, 0x20
        ctx->r1 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
            goto L_80080E40;
    }
    goto skip_3;
    // 0x80080E34: slti        $at, $a1, 0x20
    ctx->r1 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
    skip_3:
    // 0x80080E38: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80080E3C: slti        $at, $a1, 0x20
    ctx->r1 = SIGNED(ctx->r5) < 0X20 ? 1 : 0;
L_80080E40:
    // 0x80080E40: beq         $at, $zero, L_80080E58
    if (ctx->r1 == 0) {
        // 0x80080E44: nop
    
            goto L_80080E58;
    }
    // 0x80080E44: nop

    // 0x80080E48: jal         0x80060FBC
    // 0x80080E4C: addiu       $a1, $s5, 0x80
    ctx->r5 = ADD32(ctx->r21, 0X80);
    Object_Kill(rdram, ctx);
        goto after_3;
    // 0x80080E4C: addiu       $a1, $s5, 0x80
    ctx->r5 = ADD32(ctx->r21, 0X80);
    after_3:
    // 0x80080E50: b           L_80080E94
    // 0x80080E54: lh          $t5, 0x44($s5)
    ctx->r13 = MEM_H(ctx->r21, 0X44);
        goto L_80080E94;
    // 0x80080E54: lh          $t5, 0x44($s5)
    ctx->r13 = MEM_H(ctx->r21, 0X44);
L_80080E58:
    // 0x80080E58: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80080E5C: andi        $t9, $a1, 0xFF
    ctx->r25 = ctx->r5 & 0XFF;
    // 0x80080E60: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x80080E64: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80080E68: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x80080E6C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80080E70: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80080E74: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80080E78: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x80080E7C: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80080E80: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x80080E84: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80080E88: lw          $t4, 0x74($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X74);
    // 0x80080E8C: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80080E90: lh          $t5, 0x44($s5)
    ctx->r13 = MEM_H(ctx->r21, 0X44);
L_80080E94:
    // 0x80080E94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80080E98: beql        $s0, $t5, L_800815B4
    if (ctx->r16 == ctx->r13) {
        // 0x80080E9C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800815B4;
    }
    goto skip_4;
    // 0x80080E9C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_4:
    // 0x80080EA0: jal         0x800B8DD0
    // 0x80080EA4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x80080EA4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_4:
    // 0x80080EA8: b           L_800815B4
    // 0x80080EAC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800815B4;
    // 0x80080EAC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80080EB0:
    // 0x80080EB0: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80080EB4: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x80080EB8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80080EBC: jal         0x800B8DD0
    // 0x80080EC0: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    RCP_SetupDL(rdram, ctx);
        goto after_5;
    // 0x80080EC0: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    after_5:
    // 0x80080EC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80080EC8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80080ECC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80080ED0: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x80080ED4: addiu       $t0, $zero, -0x100
    ctx->r8 = ADD32(0, -0X100);
    // 0x80080ED8: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80080EDC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80080EE0: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80080EE4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80080EE8: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x80080EEC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80080EF0: lh          $t8, 0x48($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X48);
    // 0x80080EF4: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80080EF8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80080EFC: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80080F00: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x80080F04: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80080F08: lw          $a3, 0x70($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X70);
    // 0x80080F0C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80080F10: jal         0x80005C34
    // 0x80080F14: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_6;
    // 0x80080F14: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x80080F18: jal         0x80006EB8
    // 0x80080F1C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x80080F1C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x80080F20: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80080F24: lui         $t5, 0xA00
    ctx->r13 = S32(0XA00 << 16);
    // 0x80080F28: addiu       $t5, $t5, 0x0
    ctx->r13 = ADD32(ctx->r13, 0X0);
    // 0x80080F2C: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x80080F30: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x80080F34: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80080F38: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80080F3C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80080F40: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80080F44: jal         0x800B8DD0
    // 0x80080F48: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_8;
    // 0x80080F48: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_8:
    // 0x80080F4C: b           L_800815B4
    // 0x80080F50: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800815B4;
    // 0x80080F50: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80080F54:
    // 0x80080F54: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80080F58: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x80080F5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80080F60: jal         0x800B8DD0
    // 0x80080F64: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    RCP_SetupDL(rdram, ctx);
        goto after_9;
    // 0x80080F64: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_9:
    // 0x80080F68: jal         0x8005980C
    // 0x80080F6C: lwc1        $f12, 0x70($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_10;
    // 0x80080F6C: lwc1        $f12, 0x70($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X70);
    after_10:
    // 0x80080F70: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80080F74: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80080F78: lui         $at, 0x783C
    ctx->r1 = S32(0X783C << 16);
    // 0x80080F7C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80080F80: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x80080F84: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80080F88: lh          $t8, 0x44($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X44);
    // 0x80080F8C: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80080F90: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80080F94: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80080F98: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x80080F9C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80080FA0: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80080FA4: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x80080FA8: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80080FAC: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x80080FB0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80080FB4: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80080FB8: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80080FBC: lui         $t6, 0x102
    ctx->r14 = S32(0X102 << 16);
    // 0x80080FC0: addiu       $t6, $t6, 0x3750
    ctx->r14 = ADD32(ctx->r14, 0X3750);
    // 0x80080FC4: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80080FC8: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x80080FCC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80080FD0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80080FD4: jal         0x800B8DD0
    // 0x80080FD8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_11;
    // 0x80080FD8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_11:
    // 0x80080FDC: b           L_800815B4
    // 0x80080FE0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800815B4;
    // 0x80080FE0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80080FE4:
    // 0x80080FE4: jal         0x8005980C
    // 0x80080FE8: lwc1        $f12, 0x70($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_12;
    // 0x80080FE8: lwc1        $f12, 0x70($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X70);
    after_12:
    // 0x80080FEC: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80080FF0: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x80080FF4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80080FF8: jal         0x800B8DD0
    // 0x80080FFC: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_13;
    // 0x80080FFC: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_13:
    // 0x80081000: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80081004: lui         $t9, 0x901
    ctx->r25 = S32(0X901 << 16);
    // 0x80081008: addiu       $t9, $t9, 0x3C20
    ctx->r25 = ADD32(ctx->r25, 0X3C20);
    // 0x8008100C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80081010: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x80081014: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80081018: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8008101C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80081020: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081024: jal         0x800B8DD0
    // 0x80081028: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_14;
    // 0x80081028: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_14:
    // 0x8008102C: b           L_800815B4
    // 0x80081030: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800815B4;
    // 0x80081030: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80081034:
    // 0x80081034: jal         0x8005980C
    // 0x80081038: lwc1        $f12, 0x70($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_15;
    // 0x80081038: lwc1        $f12, 0x70($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X70);
    after_15:
    // 0x8008103C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80081040: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x80081044: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081048: jal         0x800B8DD0
    // 0x8008104C: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    RCP_SetupDL(rdram, ctx);
        goto after_16;
    // 0x8008104C: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_16:
    // 0x80081050: addiu       $t0, $zero, -0x100
    ctx->r8 = ADD32(0, -0X100);
    // 0x80081054: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80081058: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x8008105C: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80081060: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80081064: sw          $t1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r9;
    // 0x80081068: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8008106C: lh          $t3, 0x44($s5)
    ctx->r11 = MEM_H(ctx->r21, 0X44);
    // 0x80081070: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80081074: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081078: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8008107C: or          $t5, $t4, $t0
    ctx->r13 = ctx->r12 | ctx->r8;
    // 0x80081080: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80081084: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80081088: lui         $t8, 0x242D
    ctx->r24 = S32(0X242D << 16);
    // 0x8008108C: ori         $t8, $t8, 0x1C00
    ctx->r24 = ctx->r24 | 0X1C00;
    // 0x80081090: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80081094: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x80081098: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8008109C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800810A0: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800810A4: lui         $t2, 0x102
    ctx->r10 = S32(0X102 << 16);
    // 0x800810A8: addiu       $t2, $t2, 0x3750
    ctx->r10 = ADD32(ctx->r10, 0X3750);
    // 0x800810AC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800810B0: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x800810B4: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800810B8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800810BC: jal         0x800B8DD0
    // 0x800810C0: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_17;
    // 0x800810C0: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_17:
    // 0x800810C4: b           L_800815B4
    // 0x800810C8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800815B4;
    // 0x800810C8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800810CC:
    // 0x800810CC: jal         0x8005980C
    // 0x800810D0: lwc1        $f12, 0x70($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_18;
    // 0x800810D0: lwc1        $f12, 0x70($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X70);
    after_18:
    // 0x800810D4: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800810D8: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x800810DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800810E0: jal         0x800B8DD0
    // 0x800810E4: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    RCP_SetupDL(rdram, ctx);
        goto after_19;
    // 0x800810E4: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_19:
    // 0x800810E8: addiu       $t0, $zero, -0x100
    ctx->r8 = ADD32(0, -0X100);
    // 0x800810EC: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800810F0: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800810F4: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x800810F8: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800810FC: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x80081100: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80081104: lh          $t5, 0x44($s5)
    ctx->r13 = MEM_H(ctx->r21, 0X44);
    // 0x80081108: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008110C: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80081110: or          $t7, $t6, $t0
    ctx->r15 = ctx->r14 | ctx->r8;
    // 0x80081114: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80081118: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8008111C: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x80081120: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80081124: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x80081128: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8008112C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80081130: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80081134: lui         $t3, 0x102
    ctx->r11 = S32(0X102 << 16);
    // 0x80081138: addiu       $t3, $t3, 0x3750
    ctx->r11 = ADD32(ctx->r11, 0X3750);
    // 0x8008113C: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80081140: sw          $t1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r9;
    // 0x80081144: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80081148: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8008114C: jal         0x800B8DD0
    // 0x80081150: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_20;
    // 0x80081150: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_20:
    // 0x80081154: b           L_800815B4
    // 0x80081158: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800815B4;
    // 0x80081158: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8008115C:
    // 0x8008115C: jal         0x8005980C
    // 0x80081160: lwc1        $f12, 0x70($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_21;
    // 0x80081160: lwc1        $f12, 0x70($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X70);
    after_21:
    // 0x80081164: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80081168: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x8008116C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081170: jal         0x800B8DD0
    // 0x80081174: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    RCP_SetupDL(rdram, ctx);
        goto after_22;
    // 0x80081174: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_22:
    // 0x80081178: addiu       $t0, $zero, -0x100
    ctx->r8 = ADD32(0, -0X100);
    // 0x8008117C: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80081180: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80081184: lui         $t1, 0xFB00
    ctx->r9 = S32(0XFB00 << 16);
    // 0x80081188: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8008118C: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x80081190: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80081194: lh          $t6, 0x4A($s5)
    ctx->r14 = MEM_H(ctx->r21, 0X4A);
    // 0x80081198: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8008119C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800811A0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800811A4: or          $t8, $t7, $t0
    ctx->r24 = ctx->r15 | ctx->r8;
    // 0x800811A8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800811AC: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800811B0: lui         $t2, 0x242D
    ctx->r10 = S32(0X242D << 16);
    // 0x800811B4: ori         $t2, $t2, 0x1C00
    ctx->r10 = ctx->r10 | 0X1C00;
    // 0x800811B8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800811BC: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x800811C0: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800811C4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800811C8: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800811CC: lui         $t5, 0x102
    ctx->r13 = S32(0X102 << 16);
    // 0x800811D0: addiu       $t5, $t5, 0x3750
    ctx->r13 = ADD32(ctx->r13, 0X3750);
    // 0x800811D4: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800811D8: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x800811DC: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800811E0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800811E4: jal         0x800B8DD0
    // 0x800811E8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_23;
    // 0x800811E8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_23:
    // 0x800811EC: b           L_800815B4
    // 0x800811F0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800815B4;
    // 0x800811F0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800811F4:
    // 0x800811F4: jal         0x8005980C
    // 0x800811F8: lwc1        $f12, 0x70($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_24;
    // 0x800811F8: lwc1        $f12, 0x70($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X70);
    after_24:
    // 0x800811FC: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80081200: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80081204: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80081208: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x8008120C: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x80081210: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80081214: lui         $t8, 0x6060
    ctx->r24 = S32(0X6060 << 16);
    // 0x80081218: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x8008121C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80081220: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x80081224: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80081228: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8008122C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80081230: lui         $a1, 0x4208
    ctx->r5 = S32(0X4208 << 16);
    // 0x80081234: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80081238: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8008123C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80081240: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80081244: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x80081248: jal         0x80005B00
    // 0x8008124C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_25;
    // 0x8008124C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_25:
    // 0x80081250: jal         0x80005708
    // 0x80081254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_26;
    // 0x80081254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80081258: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008125C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80081260: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80081264: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80081268: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8008126C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80081270: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80081274: jal         0x80005C34
    // 0x80081278: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_27;
    // 0x80081278: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_27:
    // 0x8008127C: jal         0x80006EB8
    // 0x80081280: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_28;
    // 0x80081280: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_28:
    // 0x80081284: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80081288: lui         $s4, 0x103
    ctx->r20 = S32(0X103 << 16);
    // 0x8008128C: addiu       $s4, $s4, -0xA20
    ctx->r20 = ADD32(ctx->r20, -0XA20);
    // 0x80081290: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80081294: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x80081298: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8008129C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800812A0: sw          $s4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r20;
    // 0x800812A4: jal         0x80005740
    // 0x800812A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_29;
    // 0x800812A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x800812AC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800812B0: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
    // 0x800812B4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_800812B8:
    // 0x800812B8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800812BC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800812C0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800812C4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800812C8: jal         0x80005B00
    // 0x800812CC: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_30;
    // 0x800812CC: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_30:
    // 0x800812D0: lui         $a1, 0x3F49
    ctx->r5 = S32(0X3F49 << 16);
    // 0x800812D4: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x800812D8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800812DC: jal         0x80005FE0
    // 0x800812E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_31;
    // 0x800812E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_31:
    // 0x800812E4: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x800812E8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800812EC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800812F0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800812F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800812F8: jal         0x80005B00
    // 0x800812FC: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_32;
    // 0x800812FC: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_32:
    // 0x80081300: jal         0x80005708
    // 0x80081304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_33;
    // 0x80081304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80081308: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8008130C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80081310: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80081314: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80081318: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8008131C: jal         0x80005C34
    // 0x80081320: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_34;
    // 0x80081320: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_34:
    // 0x80081324: jal         0x80006EB8
    // 0x80081328: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_35;
    // 0x80081328: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_35:
    // 0x8008132C: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80081330: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80081334: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80081338: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x8008133C: sw          $s4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r20;
    // 0x80081340: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80081344: jal         0x80005740
    // 0x80081348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_36;
    // 0x80081348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x8008134C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80081350: bnel        $s2, $s1, L_800812B8
    if (ctx->r18 != ctx->r17) {
        // 0x80081354: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_800812B8;
    }
    goto skip_5;
    // 0x80081354: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_5:
    // 0x80081358: lwc1        $f6, 0x18($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X18);
    // 0x8008135C: add.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x80081360: b           L_800815B0
    // 0x80081364: swc1        $f10, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->f10.u32l;
        goto L_800815B0;
    // 0x80081364: swc1        $f10, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->f10.u32l;
L_80081368:
    // 0x80081368: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008136C: lhu         $v0, -0x2756($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2756);
    // 0x80081370: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80081374: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80081378: andi        $t9, $v0, 0x800
    ctx->r25 = ctx->r2 & 0X800;
    // 0x8008137C: beq         $t9, $zero, L_80081398
    if (ctx->r25 == 0) {
        // 0x80081380: andi        $t1, $v0, 0x400
        ctx->r9 = ctx->r2 & 0X400;
            goto L_80081398;
    }
    // 0x80081380: andi        $t1, $v0, 0x400
    ctx->r9 = ctx->r2 & 0X400;
    // 0x80081384: lw          $v1, 0x18E4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X18E4);
    // 0x80081388: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008138C: blez        $v1, L_80081398
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80081390: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_80081398;
    }
    // 0x80081390: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80081394: sw          $v1, 0x18E4($at)
    MEM_W(0X18E4, ctx->r1) = ctx->r3;
L_80081398:
    // 0x80081398: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8008139C: beq         $t1, $zero, L_800813C0
    if (ctx->r9 == 0) {
        // 0x800813A0: lw          $v1, 0x18E4($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X18E4);
            goto L_800813C0;
    }
    // 0x800813A0: lw          $v1, 0x18E4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X18E4);
    // 0x800813A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800813A8: sw          $v1, 0x18E4($at)
    MEM_W(0X18E4, ctx->r1) = ctx->r3;
    // 0x800813AC: slti        $at, $v1, 0xC
    ctx->r1 = SIGNED(ctx->r3) < 0XC ? 1 : 0;
    // 0x800813B0: beq         $at, $zero, L_800813C0
    if (ctx->r1 == 0) {
        // 0x800813B4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800813C0;
    }
    // 0x800813B4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800813B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800813BC: sw          $v1, 0x18E4($at)
    MEM_W(0X18E4, ctx->r1) = ctx->r3;
L_800813C0:
    // 0x800813C0: lw          $t2, 0x40($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X40);
    // 0x800813C4: lw          $t3, 0x7DB0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7DB0);
    // 0x800813C8: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800813CC: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x800813D0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800813D4: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800813D8: bne         $t5, $zero, L_8008140C
    if (ctx->r13 != 0) {
        // 0x800813DC: lui         $t1, 0xFA00
        ctx->r9 = S32(0XFA00 << 16);
            goto L_8008140C;
    }
    // 0x800813DC: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x800813E0: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800813E4: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x800813E8: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800813EC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800813F0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800813F4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800813F8: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x800813FC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80081400: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80081404: b           L_80081428
    // 0x80081408: nop

        goto L_80081428;
    // 0x80081408: nop

L_8008140C:
    // 0x8008140C: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80081410: lui         $t2, 0x6060
    ctx->r10 = S32(0X6060 << 16);
    // 0x80081414: ori         $t2, $t2, 0xFFFF
    ctx->r10 = ctx->r10 | 0XFFFF;
    // 0x80081418: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8008141C: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x80081420: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80081424: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_80081428:
    // 0x80081428: jal         0x8005980C
    // 0x8008142C: lwc1        $f12, 0x70($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_37;
    // 0x8008142C: lwc1        $f12, 0x70($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X70);
    after_37:
    // 0x80081430: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80081434: lui         $s4, 0x103
    ctx->r20 = S32(0X103 << 16);
    // 0x80081438: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x8008143C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80081440: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80081444: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80081448: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x8008144C: addiu       $s2, $s2, 0x1534
    ctx->r18 = ADD32(ctx->r18, 0X1534);
    // 0x80081450: addiu       $s4, $s4, -0xA20
    ctx->r20 = ADD32(ctx->r20, -0XA20);
    // 0x80081454: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80081458:
    // 0x80081458: jal         0x80005708
    // 0x8008145C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_38;
    // 0x8008145C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x80081460: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80081464: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80081468: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8008146C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80081470: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80081474: jal         0x80005B00
    // 0x80081478: lui         $a2, 0xC270
    ctx->r6 = S32(0XC270 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_39;
    // 0x80081478: lui         $a2, 0xC270
    ctx->r6 = S32(0XC270 << 16);
    after_39:
    // 0x8008147C: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80081480: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80081484: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80081488: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008148C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80081490: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80081494: jal         0x80005C34
    // 0x80081498: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_40;
    // 0x80081498: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_40:
    // 0x8008149C: jal         0x80006EB8
    // 0x800814A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_41;
    // 0x800814A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_41:
    // 0x800814A4: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800814A8: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x800814AC: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x800814B0: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
    // 0x800814B4: sw          $s4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r20;
    // 0x800814B8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800814BC: jal         0x80005740
    // 0x800814C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_42;
    // 0x800814C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x800814C4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800814C8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800814CC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800814D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800814D4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800814D8: jal         0x80005B00
    // 0x800814DC: lui         $a2, 0xC2F0
    ctx->r6 = S32(0XC2F0 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_43;
    // 0x800814DC: lui         $a2, 0xC2F0
    ctx->r6 = S32(0XC2F0 << 16);
    after_43:
    // 0x800814E0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800814E4: lw          $v1, 0x18E4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X18E4);
    // 0x800814E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800814EC: lwc1        $f18, 0x7578($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7578);
    // 0x800814F0: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800814F4: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x800814F8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800814FC: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x80081500: addu        $t1, $t9, $s1
    ctx->r9 = ADD32(ctx->r25, ctx->r17);
    // 0x80081504: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80081508: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8008150C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80081510: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80081514: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80081518: jal         0x80005FE0
    // 0x8008151C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_44;
    // 0x8008151C: nop

    after_44:
    // 0x80081520: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80081524: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80081528: bne         $s1, $at, L_80081458
    if (ctx->r17 != ctx->r1) {
        // 0x8008152C: nop
    
            goto L_80081458;
    }
    // 0x8008152C: nop

    // 0x80081530: b           L_800815B4
    // 0x80081534: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800815B4;
    // 0x80081534: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80081538:
    // 0x80081538: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8008153C: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x80081540: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081544: jal         0x800B8DD0
    // 0x80081548: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    RCP_SetupDL(rdram, ctx);
        goto after_45;
    // 0x80081548: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_45:
    // 0x8008154C: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80081550: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80081554: addiu       $t4, $zero, -0x4101
    ctx->r12 = ADD32(0, -0X4101);
    // 0x80081558: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8008155C: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x80081560: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80081564: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80081568: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8008156C: lui         $t7, 0xEF0F
    ctx->r15 = S32(0XEF0F << 16);
    // 0x80081570: ori         $t7, $t7, 0xFF
    ctx->r15 = ctx->r15 | 0XFF;
    // 0x80081574: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80081578: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
    // 0x8008157C: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x80081580: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80081584: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80081588: jal         0x8005980C
    // 0x8008158C: lwc1        $f12, 0x70($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_46;
    // 0x8008158C: lwc1        $f12, 0x70($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X70);
    after_46:
    // 0x80081590: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80081594: lui         $t1, 0x102
    ctx->r9 = S32(0X102 << 16);
    // 0x80081598: addiu       $t1, $t1, 0x4AC0
    ctx->r9 = ADD32(ctx->r9, 0X4AC0);
    // 0x8008159C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800815A0: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800815A4: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800815A8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800815AC: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
L_800815B0:
    // 0x800815B0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800815B4:
    // 0x800815B4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800815B8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800815BC: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800815C0: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800815C4: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x800815C8: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x800815CC: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x800815D0: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x800815D4: jr          $ra
    // 0x800815D8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800815D8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void BonusText_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007729C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800772A0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800772A4: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800772A8: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800772AC: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800772B0: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800772B4: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800772B8: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800772BC: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800772C0: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x800772C4: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800772C8: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800772CC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800772D0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800772D4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800772D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800772DC: lwc1        $f22, 0x72C0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X72C0);
    // 0x800772E0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800772E4: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x800772E8: lui         $s4, 0x8017
    ctx->r20 = S32(0X8017 << 16);
    // 0x800772EC: lui         $s3, 0x8017
    ctx->r19 = S32(0X8017 << 16);
    // 0x800772F0: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x800772F4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800772F8: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800772FC: addiu       $s2, $s2, -0x7D80
    ctx->r18 = ADD32(ctx->r18, -0X7D80);
    // 0x80077300: addiu       $s3, $s3, 0x7880
    ctx->r19 = ADD32(ctx->r19, 0X7880);
    // 0x80077304: addiu       $s4, $s4, 0x7D08
    ctx->r20 = ADD32(ctx->r20, 0X7D08);
    // 0x80077308: addiu       $s0, $s0, 0x6438
    ctx->r16 = ADD32(ctx->r16, 0X6438);
    // 0x8007730C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80077310: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x80077314: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
L_80077318:
    // 0x80077318: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8007731C: beql        $t6, $zero, L_800773C4
    if (ctx->r14 == 0) {
        // 0x80077320: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800773C4;
    }
    goto skip_0;
    // 0x80077320: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80077324: lhu         $v0, 0x18($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X18);
    // 0x80077328: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x8007732C: beq         $v0, $zero, L_8007733C
    if (ctx->r2 == 0) {
        // 0x80077330: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8007733C;
    }
    // 0x80077330: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80077334: sh          $t7, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r15;
    // 0x80077338: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
L_8007733C:
    // 0x8007733C: bnel        $v0, $zero, L_8007734C
    if (ctx->r2 != 0) {
        // 0x80077340: lw          $t8, 0x0($s3)
        ctx->r24 = MEM_W(ctx->r19, 0X0);
            goto L_8007734C;
    }
    goto skip_1;
    // 0x80077340: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    skip_1:
    // 0x80077344: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80077348: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
L_8007734C:
    // 0x8007734C: bnel        $t8, $zero, L_8007736C
    if (ctx->r24 != 0) {
        // 0x80077350: lw          $v0, 0x0($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X0);
            goto L_8007736C;
    }
    goto skip_2;
    // 0x80077350: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    skip_2:
    // 0x80077354: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80077358: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8007735C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80077360: b           L_8007739C
    // 0x80077364: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
        goto L_8007739C;
    // 0x80077364: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x80077368: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_8007736C:
    // 0x8007736C: lw          $t9, 0x1C8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C8);
    // 0x80077370: bnel        $s6, $t9, L_800773A0
    if (ctx->r22 != ctx->r25) {
        // 0x80077374: lhu         $t1, 0x18($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0X18);
            goto L_800773A0;
    }
    goto skip_3;
    // 0x80077374: lhu         $t1, 0x18($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X18);
    skip_3:
    // 0x80077378: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8007737C: lwc1        $f16, 0xC0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC0);
    // 0x80077380: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80077384: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80077388: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x8007738C: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80077390: lwc1        $f6, 0xC8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC8);
    // 0x80077394: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80077398: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
L_8007739C:
    // 0x8007739C: lhu         $t1, 0x18($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X18);
L_800773A0:
    // 0x800773A0: slti        $at, $t1, 0x2D
    ctx->r1 = SIGNED(ctx->r9) < 0X2D ? 1 : 0;
    // 0x800773A4: beql        $at, $zero, L_800773C4
    if (ctx->r1 == 0) {
        // 0x800773A8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800773C4;
    }
    goto skip_4;
    // 0x800773A8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_4:
    // 0x800773AC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800773B0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800773B4: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x800773B8: jal         0x8009BC2C
    // 0x800773BC: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800773BC: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    after_0:
    // 0x800773C0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800773C4:
    // 0x800773C4: bne         $s1, $s5, L_80077318
    if (ctx->r17 != ctx->r21) {
        // 0x800773C8: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_80077318;
    }
    // 0x800773C8: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x800773CC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800773D0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800773D4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800773D8: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800773DC: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800773E0: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800773E4: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800773E8: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800773EC: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800773F0: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800773F4: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800773F8: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800773FC: jr          $ra
    // 0x80077400: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80077400: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void AudioHeap_AllocPersistentSampleCache(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DC34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000DC38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000DC3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000DC40: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8000DC44: jal         0x8000E208
    // 0x8000DC48: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    AudioHeap_AllocPersistentSampleCacheEntry(rdram, ctx);
        goto after_0;
    // 0x8000DC48: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8000DC4C: beq         $v0, $zero, L_8000DC70
    if (ctx->r2 == 0) {
        // 0x8000DC50: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_8000DC70;
    }
    // 0x8000DC50: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000DC54: sb          $t6, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r14;
    // 0x8000DC58: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8000DC5C: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x8000DC60: lb          $t8, 0x27($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X27);
    // 0x8000DC64: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x8000DC68: b           L_8000DC74
    // 0x8000DC6C: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
        goto L_8000DC74;
    // 0x8000DC6C: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
L_8000DC70:
    // 0x8000DC70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000DC74:
    // 0x8000DC74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000DC78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000DC7C: jr          $ra
    // 0x8000DC80: nop

    return;
    // 0x8000DC80: nop

;}
RECOMP_FUNC void Audio_GetSfxPan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016CDC: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80016CE0: lbu         $t7, 0x5D20($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X5D20);
    // 0x80016CE4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80016CE8: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x80016CEC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80016CF0: beq         $t7, $at, L_80016EB8
    if (ctx->r15 == ctx->r1) {
        // 0x80016CF4: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_80016EB8;
    }
    // 0x80016CF4: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80016CF8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80016CFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016D00: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80016D04: c.le.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl <= ctx->f12.fl;
    // 0x80016D08: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80016D0C: bc1fl       L_80016D20
    if (!c1cs) {
        // 0x80016D10: neg.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
            goto L_80016D20;
    }
    goto skip_0;
    // 0x80016D10: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    skip_0:
    // 0x80016D14: b           L_80016D20
    // 0x80016D18: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_80016D20;
    // 0x80016D18: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80016D1C: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
L_80016D20:
    // 0x80016D20: c.le.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl <= ctx->f14.fl;
    // 0x80016D24: nop

    // 0x80016D28: bc1fl       L_80016D3C
    if (!c1cs) {
        // 0x80016D2C: neg.s       $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = -ctx->f14.fl;
            goto L_80016D3C;
    }
    goto skip_1;
    // 0x80016D2C: neg.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = -ctx->f14.fl;
    skip_1:
    // 0x80016D30: b           L_80016D3C
    // 0x80016D34: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_80016D3C;
    // 0x80016D34: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x80016D38: neg.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = -ctx->f14.fl;
L_80016D3C:
    // 0x80016D3C: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80016D40: nop

    // 0x80016D44: bc1fl       L_80016D68
    if (!c1cs) {
        // 0x80016D48: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80016D68;
    }
    goto skip_2;
    // 0x80016D48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_2:
    // 0x80016D4C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80016D50: nop

    // 0x80016D54: bc1fl       L_80016D68
    if (!c1cs) {
        // 0x80016D58: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80016D68;
    }
    goto skip_3;
    // 0x80016D58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_3:
    // 0x80016D5C: jr          $ra
    // 0x80016D60: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    return;
    // 0x80016D60: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x80016D64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80016D68:
    // 0x80016D68: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80016D6C: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80016D70: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80016D74: nop

    // 0x80016D78: bc1fl       L_80016D8C
    if (!c1cs) {
        // 0x80016D7C: lui         $at, 0x4496
        ctx->r1 = S32(0X4496 << 16);
            goto L_80016D8C;
    }
    goto skip_4;
    // 0x80016D7C: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    skip_4:
    // 0x80016D80: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80016D84: nop

    // 0x80016D88: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
L_80016D8C:
    // 0x80016D8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80016D90: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80016D94: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80016D98: nop

    // 0x80016D9C: bc1fl       L_80016DB0
    if (!c1cs) {
        // 0x80016DA0: c.eq.s      $f12, $f8
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl == ctx->f8.fl;
            goto L_80016DB0;
    }
    goto skip_5;
    // 0x80016DA0: c.eq.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl == ctx->f8.fl;
    skip_5:
    // 0x80016DA4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80016DA8: nop

    // 0x80016DAC: c.eq.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl == ctx->f8.fl;
L_80016DB0:
    // 0x80016DB0: nop

    // 0x80016DB4: bc1fl       L_80016DE4
    if (!c1cs) {
        // 0x80016DB8: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80016DE4;
    }
    goto skip_6;
    // 0x80016DB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_6:
    // 0x80016DBC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80016DC0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80016DC4: c.eq.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl == ctx->f10.fl;
    // 0x80016DC8: nop

    // 0x80016DCC: bc1fl       L_80016DE4
    if (!c1cs) {
        // 0x80016DD0: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80016DE4;
    }
    goto skip_7;
    // 0x80016DD0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_7:
    // 0x80016DD4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80016DD8: b           L_80016E8C
    // 0x80016DDC: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
        goto L_80016E8C;
    // 0x80016DDC: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80016DE0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80016DE4:
    // 0x80016DE4: nop

    // 0x80016DE8: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80016DEC: nop

    // 0x80016DF0: bc1fl       L_80016E30
    if (!c1cs) {
        // 0x80016DF4: c.lt.s      $f12, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
            goto L_80016E30;
    }
    goto skip_8;
    // 0x80016DF4: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    skip_8:
    // 0x80016DF8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80016DFC: lui         $at, 0x4516
    ctx->r1 = S32(0X4516 << 16);
    // 0x80016E00: bc1fl       L_80016E30
    if (!c1cs) {
        // 0x80016E04: c.lt.s      $f12, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
            goto L_80016E30;
    }
    goto skip_9;
    // 0x80016E04: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    skip_9:
    // 0x80016E08: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80016E0C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80016E10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80016E14: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80016E18: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80016E1C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80016E20: div.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80016E24: b           L_80016E88
    // 0x80016E28: sub.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f6.fl;
        goto L_80016E88;
    // 0x80016E28: sub.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80016E2C: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
L_80016E30:
    // 0x80016E30: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80016E34: bc1fl       L_80016E74
    if (!c1cs) {
        // 0x80016E38: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80016E74;
    }
    goto skip_10;
    // 0x80016E38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_10:
    // 0x80016E3C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80016E40: nop

    // 0x80016E44: bc1fl       L_80016E74
    if (!c1cs) {
        // 0x80016E48: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80016E74;
    }
    goto skip_11;
    // 0x80016E48: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_11:
    // 0x80016E4C: lui         $at, 0x4516
    ctx->r1 = S32(0X4516 << 16);
    // 0x80016E50: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80016E54: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80016E58: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80016E5C: sub.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80016E60: sub.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80016E64: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80016E68: b           L_80016E88
    // 0x80016E6C: div.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
        goto L_80016E88;
    // 0x80016E6C: div.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80016E70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80016E74:
    // 0x80016E74: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80016E78: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80016E7C: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80016E80: div.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80016E84: add.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f10.fl;
L_80016E88:
    // 0x80016E88: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
L_80016E8C:
    // 0x80016E8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80016E90: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80016E94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80016E98: mul.s       $f4, $f14, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80016E9C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80016EA0: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80016EA4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80016EA8: nop

    // 0x80016EAC: sll         $t9, $v0, 24
    ctx->r25 = S32(ctx->r2 << 24);
    // 0x80016EB0: jr          $ra
    // 0x80016EB4: sra         $v0, $t9, 24
    ctx->r2 = S32(SIGNED(ctx->r25) >> 24);
    return;
    // 0x80016EB4: sra         $v0, $t9, 24
    ctx->r2 = S32(SIGNED(ctx->r25) >> 24);
L_80016EB8:
    // 0x80016EB8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80016EBC: beq         $a2, $at, L_80016EDC
    if (ctx->r6 == ctx->r1) {
        // 0x80016EC0: addiu       $v0, $zero, 0x40
        ctx->r2 = ADD32(0, 0X40);
            goto L_80016EDC;
    }
    // 0x80016EC0: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x80016EC4: andi        $v0, $a2, 0x1
    ctx->r2 = ctx->r6 & 0X1;
    // 0x80016EC8: sll         $t1, $v0, 7
    ctx->r9 = S32(ctx->r2 << 7);
    // 0x80016ECC: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x80016ED0: sll         $t2, $t1, 24
    ctx->r10 = S32(ctx->r9 << 24);
    // 0x80016ED4: jr          $ra
    // 0x80016ED8: sra         $v0, $t2, 24
    ctx->r2 = S32(SIGNED(ctx->r10) >> 24);
    return;
    // 0x80016ED8: sra         $v0, $t2, 24
    ctx->r2 = S32(SIGNED(ctx->r10) >> 24);
L_80016EDC:
    // 0x80016EDC: jr          $ra
    // 0x80016EE0: nop

    return;
    // 0x80016EE0: nop

;}
RECOMP_FUNC void Texture_BlendRGBA16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1558: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A155C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A1560: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x800A1564: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800A1568: lui         $t3, 0xFF
    ctx->r11 = S32(0XFF << 16);
    // 0x800A156C: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x800A1570: addiu       $t2, $t2, 0x1FD0
    ctx->r10 = ADD32(ctx->r10, 0X1FD0);
    // 0x800A1574: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800A1578: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x800A157C: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x800A1580: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x800A1584: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800A1588: sll         $t7, $a2, 4
    ctx->r15 = S32(ctx->r6 << 4);
    // 0x800A158C: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x800A1590: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A1594: addu        $t5, $t2, $t9
    ctx->r13 = ADD32(ctx->r10, ctx->r25);
    // 0x800A1598: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800A159C: and         $t7, $a2, $t3
    ctx->r15 = ctx->r6 & ctx->r11;
    // 0x800A15A0: sll         $t9, $a3, 4
    ctx->r25 = S32(ctx->r7 << 4);
    // 0x800A15A4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A15A8: srl         $t5, $t9, 28
    ctx->r13 = S32(U32(ctx->r25) >> 28);
    // 0x800A15AC: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800A15B0: addu        $v0, $t8, $t4
    ctx->r2 = ADD32(ctx->r24, ctx->r12);
    // 0x800A15B4: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x800A15B8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800A15BC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800A15C0: and         $t9, $a3, $t3
    ctx->r25 = ctx->r7 & ctx->r11;
    // 0x800A15C4: addu        $t5, $t8, $t9
    ctx->r13 = ADD32(ctx->r24, ctx->r25);
    // 0x800A15C8: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800A15CC: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x800A15D0: addu        $v1, $t5, $t4
    ctx->r3 = ADD32(ctx->r13, ctx->r12);
    // 0x800A15D4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A15D8: addu        $t5, $t2, $t9
    ctx->r13 = ADD32(ctx->r10, ctx->r25);
    // 0x800A15DC: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x800A15E0: and         $t8, $t6, $t3
    ctx->r24 = ctx->r14 & ctx->r11;
    // 0x800A15E4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800A15E8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800A15EC: addu        $a0, $t9, $t4
    ctx->r4 = ADD32(ctx->r25, ctx->r12);
    // 0x800A15F0: blez        $a1, L_800A1898
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800A15F4: or          $t1, $a1, $zero
        ctx->r9 = ctx->r5 | 0;
            goto L_800A1898;
    }
    // 0x800A15F4: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
    // 0x800A15F8: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x800A15FC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800A1600: lui         $at, 0x4500
    ctx->r1 = S32(0X4500 << 16);
    // 0x800A1604: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800A1608: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A160C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A1610: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800A1614: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800A1618: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_800A161C:
    // 0x800A161C: lhu         $a0, 0x0($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X0);
    // 0x800A1620: lhu         $v1, 0x0($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X0);
    // 0x800A1624: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800A1628: sra         $t7, $a0, 6
    ctx->r15 = S32(SIGNED(ctx->r4) >> 6);
    // 0x800A162C: andi        $t8, $t7, 0x1F
    ctx->r24 = ctx->r15 & 0X1F;
    // 0x800A1630: sra         $t5, $a0, 11
    ctx->r13 = S32(SIGNED(ctx->r4) >> 11);
    // 0x800A1634: andi        $t6, $t5, 0x1F
    ctx->r14 = ctx->r13 & 0X1F;
    // 0x800A1638: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800A163C: sra         $t9, $a0, 1
    ctx->r25 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800A1640: sra         $t7, $v1, 1
    ctx->r15 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800A1644: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800A1648: andi        $t5, $t9, 0x1F
    ctx->r13 = ctx->r25 & 0X1F;
    // 0x800A164C: andi        $t8, $t7, 0x1F
    ctx->r24 = ctx->r15 & 0X1F;
    // 0x800A1650: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x800A1654: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800A1658: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A165C: sra         $t9, $v1, 11
    ctx->r25 = S32(SIGNED(ctx->r3) >> 11);
    // 0x800A1660: andi        $t5, $t9, 0x1F
    ctx->r13 = ctx->r25 & 0X1F;
    // 0x800A1664: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x800A1668: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800A166C: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A1670: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800A1674: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800A1678: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800A167C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800A1680: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A1684: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A1688: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800A168C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800A1690: sra         $t5, $v1, 6
    ctx->r13 = S32(SIGNED(ctx->r3) >> 6);
    // 0x800A1694: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800A1698: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A169C: div.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800A16A0: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800A16A4: add.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x800A16A8: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800A16AC: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800A16B0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A16B4: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800A16B8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A16BC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A16C0: nop

    // 0x800A16C4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A16C8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A16CC: nop

    // 0x800A16D0: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800A16D4: beql        $t7, $zero, L_800A1724
    if (ctx->r15 == 0) {
        // 0x800A16D8: mfc1        $t7, $f10
        ctx->r15 = (int32_t)ctx->f10.u32l;
            goto L_800A1724;
    }
    goto skip_0;
    // 0x800A16D8: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x800A16DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A16E0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800A16E4: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A16E8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A16EC: nop

    // 0x800A16F0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A16F4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A16F8: nop

    // 0x800A16FC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x800A1700: bne         $t7, $zero, L_800A1718
    if (ctx->r15 != 0) {
        // 0x800A1704: nop
    
            goto L_800A1718;
    }
    // 0x800A1704: nop

    // 0x800A1708: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800A170C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A1710: b           L_800A1730
    // 0x800A1714: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_800A1730;
    // 0x800A1714: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_800A1718:
    // 0x800A1718: b           L_800A1730
    // 0x800A171C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_800A1730;
    // 0x800A171C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800A1720: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
L_800A1724:
    // 0x800A1724: nop

    // 0x800A1728: bltz        $t7, L_800A1718
    if (SIGNED(ctx->r15) < 0) {
        // 0x800A172C: nop
    
            goto L_800A1718;
    }
    // 0x800A172C: nop

L_800A1730:
    // 0x800A1730: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A1734: andi        $t6, $t5, 0x1F
    ctx->r14 = ctx->r13 & 0X1F;
    // 0x800A1738: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800A173C: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x800A1740: andi        $t9, $t8, 0xF800
    ctx->r25 = ctx->r24 & 0XF800;
    // 0x800A1744: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A1748: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A174C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800A1750: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800A1754: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800A1758: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800A175C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800A1760: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800A1764: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A1768: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A176C: nop

    // 0x800A1770: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A1774: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A1778: nop

    // 0x800A177C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800A1780: beql        $t8, $zero, L_800A17D0
    if (ctx->r24 == 0) {
        // 0x800A1784: mfc1        $t8, $f10
        ctx->r24 = (int32_t)ctx->f10.u32l;
            goto L_800A17D0;
    }
    goto skip_1;
    // 0x800A1784: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x800A1788: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A178C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A1790: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A1794: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A1798: nop

    // 0x800A179C: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A17A0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A17A4: nop

    // 0x800A17A8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800A17AC: bne         $t8, $zero, L_800A17C4
    if (ctx->r24 != 0) {
        // 0x800A17B0: nop
    
            goto L_800A17C4;
    }
    // 0x800A17B0: nop

    // 0x800A17B4: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800A17B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A17BC: b           L_800A17DC
    // 0x800A17C0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800A17DC;
    // 0x800A17C0: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800A17C4:
    // 0x800A17C4: b           L_800A17DC
    // 0x800A17C8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800A17DC;
    // 0x800A17C8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800A17CC: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
L_800A17D0:
    // 0x800A17D0: nop

    // 0x800A17D4: bltz        $t8, L_800A17C4
    if (SIGNED(ctx->r24) < 0) {
        // 0x800A17D8: nop
    
            goto L_800A17C4;
    }
    // 0x800A17D8: nop

L_800A17DC:
    // 0x800A17DC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A17E0: or          $t5, $t8, $zero
    ctx->r13 = ctx->r24 | 0;
    // 0x800A17E4: andi        $t6, $t5, 0x7C0
    ctx->r14 = ctx->r13 & 0X7C0;
    // 0x800A17E8: add.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f16.fl;
    // 0x800A17EC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800A17F0: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800A17F4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800A17F8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A17FC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A1800: nop

    // 0x800A1804: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A1808: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A180C: nop

    // 0x800A1810: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800A1814: beql        $t5, $zero, L_800A1864
    if (ctx->r13 == 0) {
        // 0x800A1818: mfc1        $t5, $f6
        ctx->r13 = (int32_t)ctx->f6.u32l;
            goto L_800A1864;
    }
    goto skip_2;
    // 0x800A1818: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x800A181C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A1820: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800A1824: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A1828: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A182C: nop

    // 0x800A1830: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A1834: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A1838: nop

    // 0x800A183C: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800A1840: bne         $t5, $zero, L_800A1858
    if (ctx->r13 != 0) {
        // 0x800A1844: nop
    
            goto L_800A1858;
    }
    // 0x800A1844: nop

    // 0x800A1848: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x800A184C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A1850: b           L_800A1870
    // 0x800A1854: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_800A1870;
    // 0x800A1854: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_800A1858:
    // 0x800A1858: b           L_800A1870
    // 0x800A185C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_800A1870;
    // 0x800A185C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800A1860: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
L_800A1864:
    // 0x800A1864: nop

    // 0x800A1868: bltz        $t5, L_800A1858
    if (SIGNED(ctx->r13) < 0) {
        // 0x800A186C: nop
    
            goto L_800A1858;
    }
    // 0x800A186C: nop

L_800A1870:
    // 0x800A1870: or          $t9, $t5, $zero
    ctx->r25 = ctx->r13 | 0;
    // 0x800A1874: andi        $t6, $t9, 0x3E
    ctx->r14 = ctx->r25 & 0X3E;
    // 0x800A1878: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A187C: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800A1880: or          $t5, $t8, $a0
    ctx->r13 = ctx->r24 | ctx->r4;
    // 0x800A1884: andi        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 & 0X1;
    // 0x800A1888: or          $t6, $t5, $t7
    ctx->r14 = ctx->r13 | ctx->r15;
    // 0x800A188C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800A1890: bne         $t0, $t1, L_800A161C
    if (ctx->r8 != ctx->r9) {
        // 0x800A1894: sh          $t6, -0x2($a3)
        MEM_H(-0X2, ctx->r7) = ctx->r14;
            goto L_800A161C;
    }
    // 0x800A1894: sh          $t6, -0x2($a3)
    MEM_H(-0X2, ctx->r7) = ctx->r14;
L_800A1898:
    // 0x800A1898: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x800A189C: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x800A18A0: jr          $ra
    // 0x800A18A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800A18A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
