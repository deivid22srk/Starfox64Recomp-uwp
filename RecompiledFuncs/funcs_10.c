#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void AndJamesTrigger_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800596B0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800596B4: jr          $ra
    // 0x800596B8: nop

    return;
    // 0x800596B8: nop

;}
RECOMP_FUNC void func_tank_80046358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046358: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8004635C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80046360: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80046364: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80046368: addiu       $t7, $t7, -0x60C0
    ctx->r15 = ADD32(ctx->r15, -0X60C0);
    // 0x8004636C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80046370: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
    // 0x80046374: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80046378: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8004637C: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80046380: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80046384: addiu       $t1, $sp, 0xCC
    ctx->r9 = ADD32(ctx->r29, 0XCC);
    // 0x80046388: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8004638C: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80046390: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80046394: lwc1        $f4, 0x138($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X138);
    // 0x80046398: lwc1        $f12, 0x74($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X74);
    // 0x8004639C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800463A0: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800463A4: swc1        $f12, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->f12.u32l;
    // 0x800463A8: lwc1        $f18, 0x144($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X144);
    // 0x800463AC: addiu       $a2, $sp, 0xD4
    ctx->r6 = ADD32(ctx->r29, 0XD4);
    // 0x800463B0: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x800463B4: lwc1        $f8, 0x7940($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800463B8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800463BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800463C0: swc1        $f2, 0x248($a0)
    MEM_W(0X248, ctx->r4) = ctx->f2.u32l;
    // 0x800463C4: swc1        $f2, 0x24C($a0)
    MEM_W(0X24C, ctx->r4) = ctx->f2.u32l;
    // 0x800463C8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800463CC: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    // 0x800463D0: addiu       $a3, $sp, 0xD0
    ctx->r7 = ADD32(ctx->r29, 0XD0);
    // 0x800463D4: add.s       $f14, $f0, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x800463D8: swc1        $f16, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->f16.u32l;
    // 0x800463DC: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x800463E0: jal         0x801B6E20
    // 0x800463E4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    Ground_801B6E20(rdram, ctx);
        goto after_0;
    // 0x800463E4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_0:
    // 0x800463E8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800463EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800463F0: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800463F4: lw          $a0, 0xD8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD8);
    // 0x800463F8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800463FC: swc1        $f8, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->f8.u32l;
    // 0x80046400: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80046404: swc1        $f10, 0x248($a0)
    MEM_W(0X248, ctx->r4) = ctx->f10.u32l;
    // 0x80046408: lwc1        $f16, 0xCC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8004640C: swc1        $f16, 0x24C($a0)
    MEM_W(0X24C, ctx->r4) = ctx->f16.u32l;
    // 0x80046410: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80046414: jr          $ra
    // 0x80046418: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x80046418: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void Lib_vTable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002EA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002EA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002EA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80002EAC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80002EB0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80002EB4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80002EB8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80002EBC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80002EC0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80002EC4: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x80002EC8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80002ECC: jalr        $v0
    // 0x80002ED0: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80002ED0: nop

    after_0:
    // 0x80002ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002ED8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002EDC: jr          $ra
    // 0x80002EE0: nop

    return;
    // 0x80002EE0: nop

;}
RECOMP_FUNC void ActorEvent_SxWarpGate_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074E3C: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80074E40: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80074E44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80074E48: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80074E4C: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x80074E50: addiu       $a0, $a0, 0x3820
    ctx->r4 = ADD32(ctx->r4, 0X3820);
    // 0x80074E54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80074E58: jal         0x8009AA20
    // 0x80074E5C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    Animation_GetFrameData(rdram, ctx);
        goto after_0;
    // 0x80074E5C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x80074E60: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80074E64: lwc1        $f6, 0x150($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X150);
    // 0x80074E68: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80074E6C: addiu       $t2, $t2, 0x4660
    ctx->r10 = ADD32(ctx->r10, 0X4660);
    // 0x80074E70: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80074E74: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80074E78: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x80074E7C: lui         $a3, 0x8007
    ctx->r7 = S32(0X8007 << 16);
    // 0x80074E80: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    // 0x80074E84: lhu         $t6, 0xBE($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XBE);
    // 0x80074E88: lwc1        $f10, 0x154($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X154);
    // 0x80074E8C: addiu       $a3, $a3, 0x4C44
    ctx->r7 = ADD32(ctx->r7, 0X4C44);
    // 0x80074E90: sra         $t7, $t6, 2
    ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
    // 0x80074E94: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80074E98: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80074E9C: addiu       $a1, $a1, 0x390C
    ctx->r5 = ADD32(ctx->r5, 0X390C);
    // 0x80074EA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80074EA4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80074EA8: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x80074EAC: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80074EB0: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80074EB4: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80074EB8: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    // 0x80074EBC: lhu         $t9, 0xBE($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XBE);
    // 0x80074EC0: lwc1        $f16, 0x154($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X154);
    // 0x80074EC4: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80074EC8: sra         $t0, $t9, 2
    ctx->r8 = S32(SIGNED(ctx->r25) >> 2);
    // 0x80074ECC: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80074ED0: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80074ED4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80074ED8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80074EDC: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80074EE0: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80074EE4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80074EE8: jal         0x8009A72C
    // 0x80074EEC: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_1;
    // 0x80074EEC: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80074EF0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80074EF4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80074EF8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    // 0x80074EFC: jr          $ra
    // 0x80074F00: nop

    return;
    // 0x80074F00: nop

;}
RECOMP_FUNC void Graphics_FillRectangle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F574: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x8009F578: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x8009F57C: beq         $t6, $zero, L_8009F6C4
    if (ctx->r14 == 0) {
        // 0x8009F580: nop
    
            goto L_8009F6C4;
    }
    // 0x8009F580: nop

    // 0x8009F584: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F588: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8009F58C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009F590: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009F594: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009F598: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009F59C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F5A0: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x8009F5A4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009F5A8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009F5AC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8009F5B0: lbu         $t9, 0x1B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X1B);
    // 0x8009F5B4: lbu         $t6, 0x17($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X17);
    // 0x8009F5B8: lbu         $t8, 0x1F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X1F);
    // 0x8009F5BC: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x8009F5C0: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x8009F5C4: lbu         $t6, 0x23($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X23);
    // 0x8009F5C8: or          $t5, $t7, $t4
    ctx->r13 = ctx->r15 | ctx->r12;
    // 0x8009F5CC: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8009F5D0: or          $t7, $t5, $t9
    ctx->r15 = ctx->r13 | ctx->r25;
    // 0x8009F5D4: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8009F5D8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8009F5DC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F5E0: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x8009F5E4: ori         $t9, $t9, 0x602
    ctx->r25 = ctx->r25 | 0X602;
    // 0x8009F5E8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8009F5EC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8009F5F0: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x8009F5F4: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8009F5F8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009F5FC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F600: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x8009F604: ori         $t6, $t6, 0x402
    ctx->r14 = ctx->r14 | 0X402;
    // 0x8009F608: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009F60C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009F610: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8009F614: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8009F618: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009F61C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F620: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x8009F624: ori         $t9, $t9, 0x1402
    ctx->r25 = ctx->r25 | 0X1402;
    // 0x8009F628: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8009F62C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8009F630: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009F634: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009F638: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F63C: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x8009F640: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x8009F644: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8009F648: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8009F64C: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x8009F650: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8009F654: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009F658: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8009F65C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F660: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x8009F664: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x8009F668: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009F66C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009F670: ori         $t9, $t9, 0x4340
    ctx->r25 = ctx->r25 | 0X4340;
    // 0x8009F674: ori         $t5, $t5, 0x31D
    ctx->r13 = ctx->r13 | 0X31D;
    // 0x8009F678: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8009F67C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8009F680: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F684: andi        $t7, $a3, 0x3FF
    ctx->r15 = ctx->r7 & 0X3FF;
    // 0x8009F688: sll         $t6, $t7, 14
    ctx->r14 = S32(ctx->r15 << 14);
    // 0x8009F68C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8009F690: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8009F694: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x8009F698: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8009F69C: andi        $t6, $a1, 0x3FF
    ctx->r14 = ctx->r5 & 0X3FF;
    // 0x8009F6A0: andi        $t9, $t5, 0x3FF
    ctx->r25 = ctx->r13 & 0X3FF;
    // 0x8009F6A4: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x8009F6A8: or          $t7, $t8, $t4
    ctx->r15 = ctx->r24 | ctx->r12;
    // 0x8009F6AC: andi        $t9, $a2, 0x3FF
    ctx->r25 = ctx->r6 & 0X3FF;
    // 0x8009F6B0: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8009F6B4: sll         $t5, $t6, 14
    ctx->r13 = S32(ctx->r14 << 14);
    // 0x8009F6B8: or          $t4, $t5, $t8
    ctx->r12 = ctx->r13 | ctx->r24;
    // 0x8009F6BC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8009F6C0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_8009F6C4:
    // 0x8009F6C4: jr          $ra
    // 0x8009F6C8: nop

    return;
    // 0x8009F6C8: nop

;}
RECOMP_FUNC void Play_SpawnDebris(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A69F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A69FC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A6A00: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800A6A04: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800A6A08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A6A0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A6A10: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800A6A14: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800A6A18: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x800A6A1C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800A6A20: addiu       $a0, $a0, -0x11E4
    ctx->r4 = ADD32(ctx->r4, -0X11E4);
    // 0x800A6A24: bne         $t6, $zero, L_800A6A64
    if (ctx->r14 != 0) {
        // 0x800A6A28: lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
            goto L_800A6A64;
    }
    // 0x800A6A28: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800A6A2C: addiu       $v0, $v0, 0x5A74
    ctx->r2 = ADD32(ctx->r2, 0X5A74);
    // 0x800A6A30: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
L_800A6A34:
    // 0x800A6A34: bnel        $t7, $zero, L_800A6A5C
    if (ctx->r15 != 0) {
        // 0x800A6A38: addiu       $a0, $a0, -0x2F4
        ctx->r4 = ADD32(ctx->r4, -0X2F4);
            goto L_800A6A5C;
    }
    goto skip_0;
    // 0x800A6A38: addiu       $a0, $a0, -0x2F4
    ctx->r4 = ADD32(ctx->r4, -0X2F4);
    skip_0:
    // 0x800A6A3C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800A6A40: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800A6A44: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x800A6A48: jal         0x800A670C
    // 0x800A6A4C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Play_SetupDebris(rdram, ctx);
        goto after_0;
    // 0x800A6A4C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800A6A50: b           L_800A6A68
    // 0x800A6A54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A6A68;
    // 0x800A6A54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6A58: addiu       $a0, $a0, -0x2F4
    ctx->r4 = ADD32(ctx->r4, -0X2F4);
L_800A6A5C:
    // 0x800A6A5C: bnel        $a0, $v0, L_800A6A34
    if (ctx->r4 != ctx->r2) {
        // 0x800A6A60: lbu         $t7, 0x0($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X0);
            goto L_800A6A34;
    }
    goto skip_1;
    // 0x800A6A60: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    skip_1:
L_800A6A64:
    // 0x800A6A64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A6A68:
    // 0x800A6A68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A6A6C: jr          $ra
    // 0x800A6A70: nop

    return;
    // 0x800A6A70: nop

;}
RECOMP_FUNC void Actor_DrawAllRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DBC0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8005DBC4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8005DBC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005DBCC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005DBD0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8005DBD4: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8005DBD8: addiu       $t7, $t7, -0x308
    ctx->r15 = ADD32(ctx->r15, -0X308);
    // 0x8005DBDC: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8005DBE0: addiu       $t6, $sp, 0x50
    ctx->r14 = ADD32(ctx->r29, 0X50);
    // 0x8005DBE4: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x8005DBE8: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8005DBEC: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8005DBF0: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8005DBF4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005DBF8: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8005DBFC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8005DC00: sw          $zero, 0x15EC($at)
    MEM_W(0X15EC, ctx->r1) = 0;
    // 0x8005DC04: lbu         $t2, 0x20($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X20);
    // 0x8005DC08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005DC0C: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8005DC10: bne         $t2, $at, L_8005DE34
    if (ctx->r10 != ctx->r1) {
        // 0x8005DC14: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8005DE34;
    }
    // 0x8005DC14: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005DC18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005DC1C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005DC20: lw          $a3, 0x7D20($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X7D20);
    // 0x8005DC24: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005DC28: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005DC2C: jal         0x80005B00
    // 0x8005DC30: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x8005DC30: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_0:
    // 0x8005DC34: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005DC38: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8005DC3C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8005DC40: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x8005DC44: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8005DC48: jal         0x80005B00
    // 0x8005DC4C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x8005DC4C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_1:
    // 0x8005DC50: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005DC54: jal         0x80005708
    // 0x8005DC58: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x8005DC58: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_2:
    // 0x8005DC5C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005DC60: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8005DC64: lw          $a1, -0x4438($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4438);
    // 0x8005DC68: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005DC6C: jal         0x80005754
    // 0x8005DC70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_Mult(rdram, ctx);
        goto after_3;
    // 0x8005DC70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8005DC74: lui         $s1, 0x8016
    ctx->r17 = S32(0X8016 << 16);
    // 0x8005DC78: addiu       $s1, $s1, 0x15E0
    ctx->r17 = ADD32(ctx->r17, 0X15E0);
    // 0x8005DC7C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005DC80: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005DC84: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8005DC88: jal         0x80006970
    // 0x8005DC8C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x8005DC8C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_4:
    // 0x8005DC90: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005DC94: jal         0x80005740
    // 0x8005DC98: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_5;
    // 0x8005DC98: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_5:
    // 0x8005DC9C: lhu         $t4, 0x2($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X2);
    // 0x8005DCA0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005DCA4: lwc1        $f2, 0x62EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X62EC);
    // 0x8005DCA8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005DCAC: addiu       $at, $zero, 0xC5
    ctx->r1 = ADD32(0, 0XC5);
    // 0x8005DCB0: bnel        $t4, $at, L_8005DCD8
    if (ctx->r12 != ctx->r1) {
        // 0x8005DCB4: lwc1        $f12, 0x8($s1)
        ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
            goto L_8005DCD8;
    }
    goto skip_0;
    // 0x8005DCB4: lwc1        $f12, 0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
    skip_0:
    // 0x8005DCB8: lh          $t5, 0xE4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XE4);
    // 0x8005DCBC: slti        $at, $t5, 0x64
    ctx->r1 = SIGNED(ctx->r13) < 0X64 ? 1 : 0;
    // 0x8005DCC0: bne         $at, $zero, L_8005DCD4
    if (ctx->r1 != 0) {
        // 0x8005DCC4: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_8005DCD4;
    }
    // 0x8005DCC4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8005DCC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005DCCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005DCD0: lwc1        $f2, 0x62F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X62F0);
L_8005DCD4:
    // 0x8005DCD4: lwc1        $f12, 0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
L_8005DCD8:
    // 0x8005DCD8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8005DCDC: nop

    // 0x8005DCE0: bc1f        L_8005E094
    if (!c1cs) {
        // 0x8005DCE4: nop
    
            goto L_8005E094;
    }
    // 0x8005DCE4: nop

    // 0x8005DCE8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8005DCEC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8005DCF0: bc1f        L_8005E094
    if (!c1cs) {
        // 0x8005DCF4: nop
    
            goto L_8005E094;
    }
    // 0x8005DCF4: nop

    // 0x8005DCF8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8005DCFC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8005DD00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005DD04: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8005DD08: mul.s       $f14, $f12, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8005DD0C: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x8005DD10: abs.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = fabsf(ctx->f14.fl);
    // 0x8005DD14: add.s       $f6, $f14, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8005DD18: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8005DD1C: nop

    // 0x8005DD20: bc1f        L_8005E094
    if (!c1cs) {
        // 0x8005DD24: nop
    
            goto L_8005E094;
    }
    // 0x8005DD24: nop

    // 0x8005DD28: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8005DD2C: add.s       $f8, $f14, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8005DD30: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005DD34: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x8005DD38: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8005DD3C: nop

    // 0x8005DD40: bc1f        L_8005E094
    if (!c1cs) {
        // 0x8005DD44: nop
    
            goto L_8005E094;
    }
    // 0x8005DD44: nop

    // 0x8005DD48: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8005DD4C: lwc1        $f4, 0x62F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X62F4);
    // 0x8005DD50: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005DD54: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8005DD58: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8005DD5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005DD60: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8005DD64: jal         0x80005E90
    // 0x8005DD68: nop

    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x8005DD68: nop

    after_6:
    // 0x8005DD6C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005DD70: lwc1        $f10, 0x62F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X62F8);
    // 0x8005DD74: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8005DD78: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005DD7C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8005DD80: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8005DD84: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005DD88: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8005DD8C: jal         0x80005D44
    // 0x8005DD90: nop

    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x8005DD90: nop

    after_7:
    // 0x8005DD94: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005DD98: lwc1        $f8, 0x62FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X62FC);
    // 0x8005DD9C: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8005DDA0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005DDA4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8005DDA8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8005DDAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005DDB0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8005DDB4: jal         0x80005FE0
    // 0x8005DDB8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_8;
    // 0x8005DDB8: nop

    after_8:
    // 0x8005DDBC: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x8005DDC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005DDC4: jalr        $t9
    // 0x8005DDC8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x8005DDC8: nop

    after_9:
    // 0x8005DDCC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005DDD0: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8005DDD4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005DDD8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8005DDDC: sw          $t8, 0x15EC($at)
    MEM_W(0X15EC, ctx->r1) = ctx->r24;
    // 0x8005DDE0: lw          $t7, 0x1C8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C8);
    // 0x8005DDE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005DDE8: bne         $t7, $at, L_8005E094
    if (ctx->r15 != ctx->r1) {
        // 0x8005DDEC: nop
    
            goto L_8005E094;
    }
    // 0x8005DDEC: nop

    // 0x8005DDF0: lhu         $t1, 0x2($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X2);
    // 0x8005DDF4: addiu       $at, $zero, 0xC5
    ctx->r1 = ADD32(0, 0XC5);
    // 0x8005DDF8: bne         $t1, $at, L_8005E094
    if (ctx->r9 != ctx->r1) {
        // 0x8005DDFC: nop
    
            goto L_8005E094;
    }
    // 0x8005DDFC: nop

    // 0x8005DE00: lh          $t2, 0xE4($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XE4);
    // 0x8005DE04: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x8005DE08: bne         $t2, $at, L_8005E094
    if (ctx->r10 != ctx->r1) {
        // 0x8005DE0C: nop
    
            goto L_8005E094;
    }
    // 0x8005DE0C: nop

    // 0x8005DE10: lw          $at, 0x0($s1)
    ctx->r1 = MEM_W(ctx->r17, 0X0);
    // 0x8005DE14: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8005DE18: addiu       $t3, $t3, 0x7E98
    ctx->r11 = ADD32(ctx->r11, 0X7E98);
    // 0x8005DE1C: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x8005DE20: lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X4);
    // 0x8005DE24: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x8005DE28: lw          $at, 0x8($s1)
    ctx->r1 = MEM_W(ctx->r17, 0X8);
    // 0x8005DE2C: b           L_8005E094
    // 0x8005DE30: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
        goto L_8005E094;
    // 0x8005DE30: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
L_8005DE34:
    // 0x8005DE34: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005DE38: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8005DE3C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8005DE40: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x8005DE44: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005DE48: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8005DE4C: jal         0x80005B00
    // 0x8005DE50: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_10;
    // 0x8005DE50: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_10:
    // 0x8005DE54: lui         $s1, 0x8016
    ctx->r17 = S32(0X8016 << 16);
    // 0x8005DE58: addiu       $s1, $s1, 0x15E0
    ctx->r17 = ADD32(ctx->r17, 0X15E0);
    // 0x8005DE5C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005DE60: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005DE64: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8005DE68: jal         0x80006970
    // 0x8005DE6C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    Matrix_MultVec3f(rdram, ctx);
        goto after_11;
    // 0x8005DE6C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_11:
    // 0x8005DE70: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005DE74: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x8005DE78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005DE7C: lw          $v0, 0x1C8($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X1C8);
    // 0x8005DE80: beq         $v0, $at, L_8005DEC0
    if (ctx->r2 == ctx->r1) {
        // 0x8005DE84: nop
    
            goto L_8005DEC0;
    }
    // 0x8005DE84: nop

    // 0x8005DE88: beq         $v0, $zero, L_8005DEC0
    if (ctx->r2 == 0) {
        // 0x8005DE8C: nop
    
            goto L_8005DEC0;
    }
    // 0x8005DE8C: nop

    // 0x8005DE90: lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2);
    // 0x8005DE94: addiu       $at, $zero, 0xC5
    ctx->r1 = ADD32(0, 0XC5);
    // 0x8005DE98: bnel        $v1, $at, L_8005DEB0
    if (ctx->r3 != ctx->r1) {
        // 0x8005DE9C: addiu       $at, $zero, 0xC3
        ctx->r1 = ADD32(0, 0XC3);
            goto L_8005DEB0;
    }
    goto skip_1;
    // 0x8005DE9C: addiu       $at, $zero, 0xC3
    ctx->r1 = ADD32(0, 0XC3);
    skip_1:
    // 0x8005DEA0: lh          $t6, 0xE4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XE4);
    // 0x8005DEA4: slti        $at, $t6, 0x64
    ctx->r1 = SIGNED(ctx->r14) < 0X64 ? 1 : 0;
    // 0x8005DEA8: beq         $at, $zero, L_8005DEC0
    if (ctx->r1 == 0) {
        // 0x8005DEAC: addiu       $at, $zero, 0xC3
        ctx->r1 = ADD32(0, 0XC3);
            goto L_8005DEC0;
    }
    // 0x8005DEAC: addiu       $at, $zero, 0xC3
    ctx->r1 = ADD32(0, 0XC3);
L_8005DEB0:
    // 0x8005DEB0: bnel        $v1, $at, L_8005DEE4
    if (ctx->r3 != ctx->r1) {
        // 0x8005DEB4: lui         $at, 0x43FA
        ctx->r1 = S32(0X43FA << 16);
            goto L_8005DEE4;
    }
    goto skip_2;
    // 0x8005DEB4: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    skip_2:
    // 0x8005DEB8: lbu         $t7, 0x3C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X3C);
    // 0x8005DEBC: beq         $t7, $zero, L_8005DEE0
    if (ctx->r15 == 0) {
        // 0x8005DEC0: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8005DEE0;
    }
L_8005DEC0:
    // 0x8005DEC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005DEC4: lwc1        $f18, 0x6300($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6300);
    // 0x8005DEC8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005DECC: lwc1        $f2, 0x6304($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6304);
    // 0x8005DED0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005DED4: lwc1        $f14, 0x6308($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X6308);
    // 0x8005DED8: b           L_8005DF00
    // 0x8005DEDC: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
        goto L_8005DF00;
    // 0x8005DEDC: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
L_8005DEE0:
    // 0x8005DEE0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
L_8005DEE4:
    // 0x8005DEE4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005DEE8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005DEEC: lwc1        $f2, 0x630C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X630C);
    // 0x8005DEF0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8005DEF4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005DEF8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8005DEFC: nop

L_8005DF00:
    // 0x8005DF00: lwc1        $f12, 0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8005DF04: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8005DF08: nop

    // 0x8005DF0C: bc1f        L_8005E094
    if (!c1cs) {
        // 0x8005DF10: nop
    
            goto L_8005E094;
    }
    // 0x8005DF10: nop

    // 0x8005DF14: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8005DF18: nop

    // 0x8005DF1C: bc1f        L_8005E094
    if (!c1cs) {
        // 0x8005DF20: nop
    
            goto L_8005E094;
    }
    // 0x8005DF20: nop

    // 0x8005DF24: mul.s       $f16, $f12, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8005DF28: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8005DF2C: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x8005DF30: abs.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = fabsf(ctx->f16.fl);
    // 0x8005DF34: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8005DF38: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8005DF3C: nop

    // 0x8005DF40: bc1f        L_8005E094
    if (!c1cs) {
        // 0x8005DF44: nop
    
            goto L_8005E094;
    }
    // 0x8005DF44: nop

    // 0x8005DF48: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8005DF4C: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8005DF50: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x8005DF54: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8005DF58: nop

    // 0x8005DF5C: bc1f        L_8005E094
    if (!c1cs) {
        // 0x8005DF60: nop
    
            goto L_8005E094;
    }
    // 0x8005DF60: nop

    // 0x8005DF64: lw          $t1, 0x1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C);
    // 0x8005DF68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005DF6C: beq         $t1, $zero, L_8005E094
    if (ctx->r9 == 0) {
        // 0x8005DF70: nop
    
            goto L_8005E094;
    }
    // 0x8005DF70: nop

    // 0x8005DF74: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8005DF78: lwc1        $f10, 0x6310($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6310);
    // 0x8005DF7C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005DF80: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005DF84: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8005DF88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005DF8C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8005DF90: jal         0x80005E90
    // 0x8005DF94: nop

    Matrix_RotateY(rdram, ctx);
        goto after_12;
    // 0x8005DF94: nop

    after_12:
    // 0x8005DF98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005DF9C: lwc1        $f8, 0x6314($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6314);
    // 0x8005DFA0: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8005DFA4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005DFA8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005DFAC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8005DFB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005DFB4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8005DFB8: jal         0x80005D44
    // 0x8005DFBC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_13;
    // 0x8005DFBC: nop

    after_13:
    // 0x8005DFC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005DFC4: lwc1        $f6, 0x6318($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6318);
    // 0x8005DFC8: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8005DFCC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005DFD0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005DFD4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005DFD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005DFDC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8005DFE0: jal         0x80005FE0
    // 0x8005DFE4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_14;
    // 0x8005DFE4: nop

    after_14:
    // 0x8005DFE8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005DFEC: jal         0x80006EB8
    // 0x8005DFF0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_15;
    // 0x8005DFF0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_15:
    // 0x8005DFF4: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x8005DFF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005DFFC: jalr        $t9
    // 0x8005E000: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_16;
    // 0x8005E000: nop

    after_16:
    // 0x8005E004: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005E008: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x8005E00C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005E010: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8005E014: sw          $t2, 0x15EC($at)
    MEM_W(0X15EC, ctx->r1) = ctx->r10;
    // 0x8005E018: lw          $t3, 0x1C8($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X1C8);
    // 0x8005E01C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005E020: bne         $t3, $at, L_8005E094
    if (ctx->r11 != ctx->r1) {
        // 0x8005E024: nop
    
            goto L_8005E094;
    }
    // 0x8005E024: nop

    // 0x8005E028: lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2);
    // 0x8005E02C: addiu       $at, $zero, 0xC5
    ctx->r1 = ADD32(0, 0XC5);
    // 0x8005E030: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x8005E034: bnel        $v1, $at, L_8005E05C
    if (ctx->r3 != ctx->r1) {
        // 0x8005E038: addiu       $at, $zero, 0xC6
        ctx->r1 = ADD32(0, 0XC6);
            goto L_8005E05C;
    }
    goto skip_3;
    // 0x8005E038: addiu       $at, $zero, 0xC6
    ctx->r1 = ADD32(0, 0XC6);
    skip_3:
    // 0x8005E03C: lh          $v0, 0xE4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XE4);
    // 0x8005E040: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8005E044: bne         $at, $zero, L_8005E068
    if (ctx->r1 != 0) {
        // 0x8005E048: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8005E068;
    }
    // 0x8005E048: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8005E04C: beq         $v0, $at, L_8005E068
    if (ctx->r2 == ctx->r1) {
        // 0x8005E050: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8005E068;
    }
    // 0x8005E050: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8005E054: beq         $v0, $at, L_8005E068
    if (ctx->r2 == ctx->r1) {
        // 0x8005E058: addiu       $at, $zero, 0xC6
        ctx->r1 = ADD32(0, 0XC6);
            goto L_8005E068;
    }
    // 0x8005E058: addiu       $at, $zero, 0xC6
    ctx->r1 = ADD32(0, 0XC6);
L_8005E05C:
    // 0x8005E05C: bne         $v1, $at, L_8005E094
    if (ctx->r3 != ctx->r1) {
        // 0x8005E060: nop
    
            goto L_8005E094;
    }
    // 0x8005E060: nop

    // 0x8005E064: lh          $v0, 0xE4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XE4);
L_8005E068:
    // 0x8005E068: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E06C: lw          $at, 0x0($s1)
    ctx->r1 = MEM_W(ctx->r17, 0X0);
    // 0x8005E070: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8005E074: addiu       $t8, $t8, 0x7E98
    ctx->r24 = ADD32(ctx->r24, 0X7E98);
    // 0x8005E078: mflo        $t5
    ctx->r13 = lo;
    // 0x8005E07C: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x8005E080: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8005E084: lw          $t1, 0x4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X4);
    // 0x8005E088: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8005E08C: lw          $at, 0x8($s1)
    ctx->r1 = MEM_W(ctx->r17, 0X8);
    // 0x8005E090: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
L_8005E094:
    // 0x8005E094: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8005E098: lw          $t9, 0x15EC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X15EC);
    // 0x8005E09C: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x8005E0A0: bne         $t9, $zero, L_8005E0E0
    if (ctx->r25 != 0) {
        // 0x8005E0A4: lui         $a3, 0x8017
        ctx->r7 = S32(0X8017 << 16);
            goto L_8005E0E0;
    }
    // 0x8005E0A4: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8005E0A8: addiu       $a3, $a3, 0x78A0
    ctx->r7 = ADD32(ctx->r7, 0X78A0);
    // 0x8005E0AC: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x8005E0B0: addiu       $at, $zero, 0xBD
    ctx->r1 = ADD32(0, 0XBD);
    // 0x8005E0B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E0B8: addu        $t4, $s0, $t2
    ctx->r12 = ADD32(ctx->r16, ctx->r10);
    // 0x8005E0BC: sb          $zero, 0xCA($t4)
    MEM_B(0XCA, ctx->r12) = 0;
    // 0x8005E0C0: lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2);
    // 0x8005E0C4: beq         $v1, $at, L_8005E0D4
    if (ctx->r3 == ctx->r1) {
        // 0x8005E0C8: addiu       $at, $zero, 0x11E
        ctx->r1 = ADD32(0, 0X11E);
            goto L_8005E0D4;
    }
    // 0x8005E0C8: addiu       $at, $zero, 0x11E
    ctx->r1 = ADD32(0, 0X11E);
    // 0x8005E0CC: bne         $v1, $at, L_8005E0E0
    if (ctx->r3 != ctx->r1) {
        // 0x8005E0D0: nop
    
            goto L_8005E0E0;
    }
    // 0x8005E0D0: nop

L_8005E0D4:
    // 0x8005E0D4: jal         0x80060FBC
    // 0x8005E0D8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_17;
    // 0x8005E0D8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_17:
    // 0x8005E0DC: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
L_8005E0E0:
    // 0x8005E0E0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8005E0E4: lw          $a1, 0x78A8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X78A8);
    // 0x8005E0E8: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8005E0EC: addiu       $t3, $s0, 0x100
    ctx->r11 = ADD32(ctx->r16, 0X100);
    // 0x8005E0F0: addiu       $a3, $a3, 0x78A0
    ctx->r7 = ADD32(ctx->r7, 0X78A0);
    // 0x8005E0F4: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x8005E0F8: blez        $a1, L_8005E18C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8005E0FC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8005E18C;
    }
    // 0x8005E0FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005E100: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x8005E104: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8005E108: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005E10C: addiu       $a2, $a2, 0x1578
    ctx->r6 = ADD32(ctx->r6, 0X1578);
    // 0x8005E110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8005E114:
    // 0x8005E114: lbu         $t5, 0xCA($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0XCA);
    // 0x8005E118: beql        $t5, $zero, L_8005E180
    if (ctx->r13 == 0) {
        // 0x8005E11C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8005E180;
    }
    goto skip_4;
    // 0x8005E11C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_4:
    // 0x8005E120: multu       $v1, $t0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005E124: lw          $at, 0x0($s1)
    ctx->r1 = MEM_W(ctx->r17, 0X0);
    // 0x8005E128: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x8005E12C: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8005E130: mflo        $t8
    ctx->r24 = lo;
    // 0x8005E134: addu        $v0, $a2, $t8
    ctx->r2 = ADD32(ctx->r6, ctx->r24);
    // 0x8005E138: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x8005E13C: lw          $at, 0x8($s1)
    ctx->r1 = MEM_W(ctx->r17, 0X8);
    // 0x8005E140: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8005E144: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8005E148: sw          $at, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r1;
    // 0x8005E14C: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8005E150: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8005E154: bne         $v1, $t1, L_8005E17C
    if (ctx->r3 != ctx->r9) {
        // 0x8005E158: swc1        $f6, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
            goto L_8005E17C;
    }
    // 0x8005E158: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8005E15C: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8005E160: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8005E164: nop

    // 0x8005E168: bc1fl       L_8005E180
    if (!c1cs) {
        // 0x8005E16C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8005E180;
    }
    goto skip_5;
    // 0x8005E16C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_5:
    // 0x8005E170: sb          $zero, 0xCA($a0)
    MEM_B(0XCA, ctx->r4) = 0;
    // 0x8005E174: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8005E178: lw          $a1, 0x78A8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X78A8);
L_8005E17C:
    // 0x8005E17C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8005E180:
    // 0x8005E180: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005E184: bne         $at, $zero, L_8005E114
    if (ctx->r1 != 0) {
        // 0x8005E188: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8005E114;
    }
    // 0x8005E188: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8005E18C:
    // 0x8005E18C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8005E190: jal         0x8005F290
    // 0x8005E194: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    Object_SetSfxSourceToView(rdram, ctx);
        goto after_18;
    // 0x8005E194: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_18:
    // 0x8005E198: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8005E19C: lw          $t9, 0x15EC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X15EC);
    // 0x8005E1A0: sw          $t9, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r25;
    // 0x8005E1A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005E1A8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E1AC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8005E1B0: jr          $ra
    // 0x8005E1B4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8005E1B4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Sprite_Move(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069858: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8006985C: lw          $t6, 0x1AB8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1AB8);
    // 0x80069860: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80069864: beq         $t6, $zero, L_8006991C
    if (ctx->r14 == 0) {
        // 0x80069868: nop
    
            goto L_8006991C;
    }
    // 0x80069868: nop

    // 0x8006986C: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80069870: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80069874: lhu         $v1, 0x2($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X2);
    // 0x80069878: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8006987C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80069880: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80069884: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80069888: addiu       $at, $zero, 0xA4
    ctx->r1 = ADD32(0, 0XA4);
    // 0x8006988C: bne         $v1, $at, L_800698A8
    if (ctx->r3 != ctx->r1) {
        // 0x80069890: abs.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
            goto L_800698A8;
    }
    // 0x80069890: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80069894: lbu         $a1, 0x45($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X45);
    // 0x80069898: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8006989C: beq         $a1, $at, L_800698B0
    if (ctx->r5 == ctx->r1) {
        // 0x800698A0: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_800698B0;
    }
    // 0x800698A0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800698A4: beq         $a1, $at, L_800698B0
    if (ctx->r5 == ctx->r1) {
        // 0x800698A8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800698B0;
    }
L_800698A8:
    // 0x800698A8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800698AC: bne         $v1, $at, L_800698BC
    if (ctx->r3 != ctx->r1) {
        // 0x800698B0: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_800698BC;
    }
L_800698B0:
    // 0x800698B0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800698B4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800698B8: nop

L_800698BC:
    // 0x800698BC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800698C0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800698C4: bc1fl       L_800698DC
    if (!c1cs) {
        // 0x800698C8: sub.s       $f8, $f0, $f12
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_800698DC;
    }
    goto skip_0;
    // 0x800698C8: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    skip_0:
    // 0x800698CC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800698D0: b           L_800698EC
    // 0x800698D4: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
        goto L_800698EC;
    // 0x800698D4: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
    // 0x800698D8: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
L_800698DC:
    // 0x800698DC: lwc1        $f10, 0x6A44($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6A44);
    // 0x800698E0: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800698E4: nop

    // 0x800698E8: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
L_800698EC:
    // 0x800698EC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800698F0: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800698F4: sub.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x800698F8: lwc1        $f18, 0x2C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800698FC: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80069900: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80069904: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80069908: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8006990C: nop

    // 0x80069910: bc1f        L_8006991C
    if (!c1cs) {
        // 0x80069914: nop
    
            goto L_8006991C;
    }
    // 0x80069914: nop

    // 0x80069918: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_8006991C:
    // 0x8006991C: jr          $ra
    // 0x80069920: nop

    return;
    // 0x80069920: nop

;}
RECOMP_FUNC void ActorMissileSeek_ModeCheck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AC54: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8008AC58: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008AC5C: addiu       $a1, $a1, 0x3FE0
    ctx->r5 = ADD32(ctx->r5, 0X3FE0);
    // 0x8008AC60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008AC64: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x8008AC68: addiu       $t2, $zero, 0xBF
    ctx->r10 = ADD32(0, 0XBF);
    // 0x8008AC6C: addiu       $t1, $zero, 0xBE
    ctx->r9 = ADD32(0, 0XBE);
    // 0x8008AC70: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8008AC74: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_8008AC78:
    // 0x8008AC78: beq         $a0, $zero, L_8008AC98
    if (ctx->r4 == 0) {
        // 0x8008AC7C: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_8008AC98;
    }
    // 0x8008AC7C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8008AC80: beql        $a0, $a3, L_8008ACBC
    if (ctx->r4 == ctx->r7) {
        // 0x8008AC84: lbu         $t8, 0x0($a1)
        ctx->r24 = MEM_BU(ctx->r5, 0X0);
            goto L_8008ACBC;
    }
    goto skip_0;
    // 0x8008AC84: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    skip_0:
    // 0x8008AC88: beql        $a0, $t0, L_8008ACDC
    if (ctx->r4 == ctx->r8) {
        // 0x8008AC8C: lhu         $a2, 0x2($a1)
        ctx->r6 = MEM_HU(ctx->r5, 0X2);
            goto L_8008ACDC;
    }
    goto skip_1;
    // 0x8008AC8C: lhu         $a2, 0x2($a1)
    ctx->r6 = MEM_HU(ctx->r5, 0X2);
    skip_1:
    // 0x8008AC90: b           L_8008ACFC
    // 0x8008AC94: nop

        goto L_8008ACFC;
    // 0x8008AC94: nop

L_8008AC98:
    // 0x8008AC98: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x8008AC9C: bne         $t0, $t6, L_8008ACFC
    if (ctx->r8 != ctx->r14) {
        // 0x8008ACA0: nop
    
            goto L_8008ACFC;
    }
    // 0x8008ACA0: nop

    // 0x8008ACA4: lhu         $t7, 0x2($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X2);
    // 0x8008ACA8: bne         $t1, $t7, L_8008ACFC
    if (ctx->r9 != ctx->r15) {
        // 0x8008ACAC: nop
    
            goto L_8008ACFC;
    }
    // 0x8008ACAC: nop

    // 0x8008ACB0: b           L_8008ACFC
    // 0x8008ACB4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8008ACFC;
    // 0x8008ACB4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008ACB8: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
L_8008ACBC:
    // 0x8008ACBC: bne         $t0, $t8, L_8008ACFC
    if (ctx->r8 != ctx->r24) {
        // 0x8008ACC0: nop
    
            goto L_8008ACFC;
    }
    // 0x8008ACC0: nop

    // 0x8008ACC4: lhu         $t9, 0x2($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X2);
    // 0x8008ACC8: bne         $t2, $t9, L_8008ACFC
    if (ctx->r10 != ctx->r25) {
        // 0x8008ACCC: nop
    
            goto L_8008ACFC;
    }
    // 0x8008ACCC: nop

    // 0x8008ACD0: b           L_8008ACFC
    // 0x8008ACD4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8008ACFC;
    // 0x8008ACD4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008ACD8: lhu         $a2, 0x2($a1)
    ctx->r6 = MEM_HU(ctx->r5, 0X2);
L_8008ACDC:
    // 0x8008ACDC: beql        $t1, $a2, L_8008ACF0
    if (ctx->r9 == ctx->r6) {
        // 0x8008ACE0: lbu         $t4, 0x0($a1)
        ctx->r12 = MEM_BU(ctx->r5, 0X0);
            goto L_8008ACF0;
    }
    goto skip_2;
    // 0x8008ACE0: lbu         $t4, 0x0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X0);
    skip_2:
    // 0x8008ACE4: bne         $t2, $a2, L_8008ACFC
    if (ctx->r10 != ctx->r6) {
        // 0x8008ACE8: nop
    
            goto L_8008ACFC;
    }
    // 0x8008ACE8: nop

    // 0x8008ACEC: lbu         $t4, 0x0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X0);
L_8008ACF0:
    // 0x8008ACF0: bne         $t0, $t4, L_8008ACFC
    if (ctx->r8 != ctx->r12) {
        // 0x8008ACF4: nop
    
            goto L_8008ACFC;
    }
    // 0x8008ACF4: nop

    // 0x8008ACF8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8008ACFC:
    // 0x8008ACFC: beq         $a0, $zero, L_8008AD1C
    if (ctx->r4 == 0) {
        // 0x8008AD00: addiu       $a1, $a1, 0x2F4
        ctx->r5 = ADD32(ctx->r5, 0X2F4);
            goto L_8008AD1C;
    }
    // 0x8008AD00: addiu       $a1, $a1, 0x2F4
    ctx->r5 = ADD32(ctx->r5, 0X2F4);
    // 0x8008AD04: beql        $a0, $a3, L_8008AD40
    if (ctx->r4 == ctx->r7) {
        // 0x8008AD08: lbu         $t7, 0x0($a1)
        ctx->r15 = MEM_BU(ctx->r5, 0X0);
            goto L_8008AD40;
    }
    goto skip_3;
    // 0x8008AD08: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    skip_3:
    // 0x8008AD0C: beql        $a0, $t0, L_8008AD60
    if (ctx->r4 == ctx->r8) {
        // 0x8008AD10: lhu         $a2, 0x2($a1)
        ctx->r6 = MEM_HU(ctx->r5, 0X2);
            goto L_8008AD60;
    }
    goto skip_4;
    // 0x8008AD10: lhu         $a2, 0x2($a1)
    ctx->r6 = MEM_HU(ctx->r5, 0X2);
    skip_4:
    // 0x8008AD14: b           L_8008AD80
    // 0x8008AD18: nop

        goto L_8008AD80;
    // 0x8008AD18: nop

L_8008AD1C:
    // 0x8008AD1C: lbu         $t5, 0x0($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X0);
    // 0x8008AD20: bne         $t0, $t5, L_8008AD80
    if (ctx->r8 != ctx->r13) {
        // 0x8008AD24: nop
    
            goto L_8008AD80;
    }
    // 0x8008AD24: nop

    // 0x8008AD28: lhu         $t6, 0x2($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X2);
    // 0x8008AD2C: bne         $t1, $t6, L_8008AD80
    if (ctx->r9 != ctx->r14) {
        // 0x8008AD30: nop
    
            goto L_8008AD80;
    }
    // 0x8008AD30: nop

    // 0x8008AD34: b           L_8008AD80
    // 0x8008AD38: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8008AD80;
    // 0x8008AD38: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008AD3C: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
L_8008AD40:
    // 0x8008AD40: bne         $t0, $t7, L_8008AD80
    if (ctx->r8 != ctx->r15) {
        // 0x8008AD44: nop
    
            goto L_8008AD80;
    }
    // 0x8008AD44: nop

    // 0x8008AD48: lhu         $t8, 0x2($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X2);
    // 0x8008AD4C: bne         $t2, $t8, L_8008AD80
    if (ctx->r10 != ctx->r24) {
        // 0x8008AD50: nop
    
            goto L_8008AD80;
    }
    // 0x8008AD50: nop

    // 0x8008AD54: b           L_8008AD80
    // 0x8008AD58: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8008AD80;
    // 0x8008AD58: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008AD5C: lhu         $a2, 0x2($a1)
    ctx->r6 = MEM_HU(ctx->r5, 0X2);
L_8008AD60:
    // 0x8008AD60: beql        $t1, $a2, L_8008AD74
    if (ctx->r9 == ctx->r6) {
        // 0x8008AD64: lbu         $t9, 0x0($a1)
        ctx->r25 = MEM_BU(ctx->r5, 0X0);
            goto L_8008AD74;
    }
    goto skip_5;
    // 0x8008AD64: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    skip_5:
    // 0x8008AD68: bne         $t2, $a2, L_8008AD80
    if (ctx->r10 != ctx->r6) {
        // 0x8008AD6C: nop
    
            goto L_8008AD80;
    }
    // 0x8008AD6C: nop

    // 0x8008AD70: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
L_8008AD74:
    // 0x8008AD74: bne         $t0, $t9, L_8008AD80
    if (ctx->r8 != ctx->r25) {
        // 0x8008AD78: nop
    
            goto L_8008AD80;
    }
    // 0x8008AD78: nop

    // 0x8008AD7C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8008AD80:
    // 0x8008AD80: bne         $v0, $t3, L_8008AC78
    if (ctx->r2 != ctx->r11) {
        // 0x8008AD84: addiu       $a1, $a1, 0x2F4
        ctx->r5 = ADD32(ctx->r5, 0X2F4);
            goto L_8008AC78;
    }
    // 0x8008AD84: addiu       $a1, $a1, 0x2F4
    ctx->r5 = ADD32(ctx->r5, 0X2F4);
    // 0x8008AD88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8008AD8C: jr          $ra
    // 0x8008AD90: nop

    return;
    // 0x8008AD90: nop

;}
RECOMP_FUNC void RCP_SetupDL_64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA140: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BA144: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BA148: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BA14C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BA150: addiu       $t8, $t8, 0x43B0
    ctx->r24 = ADD32(ctx->r24, 0X43B0);
    // 0x800BA154: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BA158: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BA15C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800BA160: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA164: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BA168: jr          $ra
    // 0x800BA16C: nop

    return;
    // 0x800BA16C: nop

;}
RECOMP_FUNC void RCP_SetupDL_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA1D0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800BA1D4: addiu       $t3, $t3, 0x7E64
    ctx->r11 = ADD32(ctx->r11, 0X7E64);
    // 0x800BA1D8: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800BA1DC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BA1E0: addiu       $t8, $t8, 0x39D8
    ctx->r24 = ADD32(ctx->r24, 0X39D8);
    // 0x800BA1E4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800BA1E8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800BA1EC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800BA1F0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800BA1F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800BA1F8: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800BA1FC: lui         $t4, 0xF800
    ctx->r12 = S32(0XF800 << 16);
    // 0x800BA200: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x800BA204: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x800BA208: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800BA20C: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800BA210: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800BA214: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800BA218: andi        $t4, $a2, 0xFF
    ctx->r12 = ctx->r6 & 0XFF;
    // 0x800BA21C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800BA220: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800BA224: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800BA228: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x800BA22C: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800BA230: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800BA234: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800BA238: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x800BA23C: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x800BA240: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800BA244: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800BA248: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800BA24C: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800BA250: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800BA254: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800BA258: ori         $t6, $t6, 0xF400
    ctx->r14 = ctx->r14 | 0XF400;
    // 0x800BA25C: subu        $t2, $t5, $t7
    ctx->r10 = SUB32(ctx->r13, ctx->r15);
    // 0x800BA260: div         $zero, $t6, $t2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r10)));
    // 0x800BA264: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x800BA268: mflo        $t4
    ctx->r12 = lo;
    // 0x800BA26C: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x800BA270: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800BA274: bne         $t2, $zero, L_800BA280
    if (ctx->r10 != 0) {
        // 0x800BA278: nop
    
            goto L_800BA280;
    }
    // 0x800BA278: nop

    // 0x800BA27C: break       7
    do_break(2148246140);
L_800BA280:
    // 0x800BA280: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BA284: bne         $t2, $at, L_800BA298
    if (ctx->r10 != ctx->r1) {
        // 0x800BA288: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BA298;
    }
    // 0x800BA288: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BA28C: bne         $t6, $at, L_800BA298
    if (ctx->r14 != ctx->r1) {
        // 0x800BA290: nop
    
            goto L_800BA298;
    }
    // 0x800BA290: nop

    // 0x800BA294: break       6
    do_break(2148246164);
L_800BA298:
    // 0x800BA298: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800BA29C: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x800BA2A0: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800BA2A4: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x800BA2A8: div         $zero, $t8, $t2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r10)));
    // 0x800BA2AC: mflo        $t4
    ctx->r12 = lo;
    // 0x800BA2B0: andi        $t7, $t4, 0xFFFF
    ctx->r15 = ctx->r12 & 0XFFFF;
    // 0x800BA2B4: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x800BA2B8: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800BA2BC: bne         $t2, $zero, L_800BA2C8
    if (ctx->r10 != 0) {
        // 0x800BA2C0: nop
    
            goto L_800BA2C8;
    }
    // 0x800BA2C0: nop

    // 0x800BA2C4: break       7
    do_break(2148246212);
L_800BA2C8:
    // 0x800BA2C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BA2CC: bne         $t2, $at, L_800BA2E0
    if (ctx->r10 != ctx->r1) {
        // 0x800BA2D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BA2E0;
    }
    // 0x800BA2D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BA2D4: bne         $t8, $at, L_800BA2E0
    if (ctx->r24 != ctx->r1) {
        // 0x800BA2D8: nop
    
            goto L_800BA2E0;
    }
    // 0x800BA2D8: nop

    // 0x800BA2DC: break       6
    do_break(2148246236);
L_800BA2E0:
    // 0x800BA2E0: jr          $ra
    // 0x800BA2E4: nop

    return;
    // 0x800BA2E4: nop

;}
RECOMP_FUNC void AudioHeap_InitSampleCaches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DCD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000DCD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000DCDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000DCE0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000DCE4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000DCE8: addiu       $a0, $a0, -0x3DE0
    ctx->r4 = ADD32(ctx->r4, -0X3DE0);
    // 0x8000DCEC: jal         0x8000BF14
    // 0x8000DCF0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    AudioHeap_Alloc(rdram, ctx);
        goto after_0;
    // 0x8000DCF0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x8000DCF4: bne         $v0, $zero, L_8000DD08
    if (ctx->r2 != 0) {
        // 0x8000DCF8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000DD08;
    }
    // 0x8000DCF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000DCFC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000DD00: b           L_8000DD18
    // 0x8000DD04: sw          $zero, -0x36B8($at)
    MEM_W(-0X36B8, ctx->r1) = 0;
        goto L_8000DD18;
    // 0x8000DD04: sw          $zero, -0x36B8($at)
    MEM_W(-0X36B8, ctx->r1) = 0;
L_8000DD08:
    // 0x8000DD08: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000DD0C: addiu       $a0, $a0, -0x36C0
    ctx->r4 = ADD32(ctx->r4, -0X36C0);
    // 0x8000DD10: jal         0x8000BF6C
    // 0x8000DD14: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    AudioHeap_InitPool(rdram, ctx);
        goto after_1;
    // 0x8000DD14: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_1:
L_8000DD18:
    // 0x8000DD18: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000DD1C: addiu       $a0, $a0, -0x3DD0
    ctx->r4 = ADD32(ctx->r4, -0X3DD0);
    // 0x8000DD20: jal         0x8000BF14
    // 0x8000DD24: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    AudioHeap_Alloc(rdram, ctx);
        goto after_2;
    // 0x8000DD24: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8000DD28: bne         $v0, $zero, L_8000DD3C
    if (ctx->r2 != 0) {
        // 0x8000DD2C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000DD3C;
    }
    // 0x8000DD2C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000DD30: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000DD34: b           L_8000DD4C
    // 0x8000DD38: sw          $zero, -0x31A0($at)
    MEM_W(-0X31A0, ctx->r1) = 0;
        goto L_8000DD4C;
    // 0x8000DD38: sw          $zero, -0x31A0($at)
    MEM_W(-0X31A0, ctx->r1) = 0;
L_8000DD3C:
    // 0x8000DD3C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000DD40: addiu       $a0, $a0, -0x31A8
    ctx->r4 = ADD32(ctx->r4, -0X31A8);
    // 0x8000DD44: jal         0x8000BF6C
    // 0x8000DD48: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    AudioHeap_InitPool(rdram, ctx);
        goto after_3;
    // 0x8000DD48: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_3:
L_8000DD4C:
    // 0x8000DD4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000DD50: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000DD54: sw          $zero, -0x31B0($at)
    MEM_W(-0X31B0, ctx->r1) = 0;
    // 0x8000DD58: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000DD5C: sw          $zero, -0x2C98($at)
    MEM_W(-0X2C98, ctx->r1) = 0;
    // 0x8000DD60: jr          $ra
    // 0x8000DD64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000DD64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void CoBuilding10_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059FDC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80059FE0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80059FE4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80059FE8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80059FEC: lui         $t8, 0x603
    ctx->r24 = S32(0X603 << 16);
    // 0x80059FF0: addiu       $t8, $t8, 0x5DA0
    ctx->r24 = ADD32(ctx->r24, 0X5DA0);
    // 0x80059FF4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80059FF8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80059FFC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8005A000: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8005A004: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8005A008: jr          $ra
    // 0x8005A00C: nop

    return;
    // 0x8005A00C: nop

;}
RECOMP_FUNC void ItemGoldRing_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800685F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800685FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068600: jal         0x80068020
    // 0x80068604: nop

    ItemSupplyRing_Update(rdram, ctx);
        goto after_0;
    // 0x80068604: nop

    after_0:
    // 0x80068608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006860C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068610: jr          $ra
    // 0x80068614: nop

    return;
    // 0x80068614: nop

;}
RECOMP_FUNC void RCP_SetupDL_36(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9358: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B935C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800B9360: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B9364: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B9368: addiu       $t8, $t8, 0x3BD0
    ctx->r24 = ADD32(ctx->r24, 0X3BD0);
    // 0x800B936C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B9370: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B9374: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B9378: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B937C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B9380: jr          $ra
    // 0x800B9384: nop

    return;
    // 0x800B9384: nop

;}
RECOMP_FUNC void Matrix_RotateZ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005FE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005FE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005FE8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80005FEC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80005FF0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80005FF4: jal         0x80023090
    // 0x80005FF8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x80005FF8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80005FFC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80006000: jal         0x80023250
    // 0x80006004: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x80006004: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80006008: lbu         $t6, 0x2B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2B);
    // 0x8000600C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80006010: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80006014: bne         $t6, $at, L_800060CC
    if (ctx->r14 != ctx->r1) {
        // 0x80006018: lwc1        $f14, 0x18($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
            goto L_800060CC;
    }
    // 0x80006018: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8000601C: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80006020: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80006024: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80006028: nop

    // 0x8000602C: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80006030: nop

    // 0x80006034: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80006038: lwc1        $f12, 0x14($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8000603C: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80006040: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80006044: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80006048: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8000604C: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80006050: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80006054: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80006058: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8000605C: lwc1        $f12, 0x18($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80006060: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80006064: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80006068: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000606C: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
    // 0x80006070: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80006074: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80006078: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8000607C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80006080: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80006084: lwc1        $f12, 0x1C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80006088: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8000608C: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80006090: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80006094: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x80006098: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8000609C: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x800060A0: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800060A4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800060A8: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800060AC: nop

    // 0x800060B0: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800060B4: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x800060B8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800060BC: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x800060C0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800060C4: b           L_8000611C
    // 0x800060C8: swc1        $f18, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f18.u32l;
        goto L_8000611C;
    // 0x800060C8: swc1        $f18, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f18.u32l;
L_800060CC:
    // 0x800060CC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800060D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800060D4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800060D8: neg.s       $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = -ctx->f14.fl;
    // 0x800060DC: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x800060E0: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x800060E4: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x800060E8: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    // 0x800060EC: swc1        $f2, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f2.u32l;
    // 0x800060F0: swc1        $f2, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f2.u32l;
    // 0x800060F4: swc1        $f2, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f2.u32l;
    // 0x800060F8: swc1        $f2, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f2.u32l;
    // 0x800060FC: swc1        $f2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f2.u32l;
    // 0x80006100: swc1        $f2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f2.u32l;
    // 0x80006104: swc1        $f2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f2.u32l;
    // 0x80006108: swc1        $f2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f2.u32l;
    // 0x8000610C: swc1        $f2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f2.u32l;
    // 0x80006110: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
    // 0x80006114: swc1        $f12, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f12.u32l;
    // 0x80006118: swc1        $f12, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f12.u32l;
L_8000611C:
    // 0x8000611C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006120: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80006124: jr          $ra
    // 0x80006128: nop

    return;
    // 0x80006128: nop

;}
RECOMP_FUNC void AudioThread_SetFadeOutTimer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E720: bne         $a1, $zero, L_8001E72C
    if (ctx->r5 != 0) {
        // 0x8001E724: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_8001E72C;
    }
    // 0x8001E724: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8001E728: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8001E72C:
    // 0x8001E72C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8001E730: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x8001E734: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001E738: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8001E73C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001E740: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001E744: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8001E748: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001E74C: addiu       $t7, $t7, -0x1AC8
    ctx->r15 = ADD32(ctx->r15, -0X1AC8);
    // 0x8001E750: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001E754: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8001E758: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8001E75C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8001E760: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x8001E764: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8001E768: sh          $a1, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r5;
    // 0x8001E76C: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8001E770: jr          $ra
    // 0x8001E774: swc1        $f16, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f16.u32l;
    return;
    // 0x8001E774: swc1        $f16, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f16.u32l;
;}
RECOMP_FUNC void Audio_SequenceChannelProcessSound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013400: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80013404: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80013408: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8001340C: sll         $t7, $v0, 9
    ctx->r15 = S32(ctx->r2 << 9);
    // 0x80013410: bltz        $t7, L_80013420
    if (SIGNED(ctx->r15) < 0) {
        // 0x80013414: addiu       $t1, $zero, 0x10
        ctx->r9 = ADD32(0, 0X10);
            goto L_80013420;
    }
    // 0x80013414: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x80013418: beql        $a1, $zero, L_80013474
    if (ctx->r5 == 0) {
        // 0x8001341C: sll         $t6, $v0, 10
        ctx->r14 = S32(ctx->r2 << 10);
            goto L_80013474;
    }
    goto skip_0;
    // 0x8001341C: sll         $t6, $v0, 10
    ctx->r14 = S32(ctx->r2 << 10);
    skip_0:
L_80013420:
    // 0x80013420: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80013424: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80013428: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x8001342C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80013430: lwc1        $f10, 0x30($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80013434: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80013438: sll         $t2, $t8, 2
    ctx->r10 = S32(ctx->r24 << 2);
    // 0x8001343C: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80013440: bgez        $t2, L_80013464
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80013444: nop
    
            goto L_80013464;
    }
    // 0x80013444: nop

    // 0x80013448: lbu         $t3, 0x3($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X3);
    // 0x8001344C: andi        $t4, $t3, 0x20
    ctx->r12 = ctx->r11 & 0X20;
    // 0x80013450: beq         $t4, $zero, L_80013464
    if (ctx->r12 == 0) {
        // 0x80013454: nop
    
            goto L_80013464;
    }
    // 0x80013454: nop

    // 0x80013458: lwc1        $f16, 0x28($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8001345C: mul.s       $f0, $f16, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80013460: nop

L_80013464:
    // 0x80013464: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80013468: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001346C: swc1        $f18, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f18.u32l;
    // 0x80013470: sll         $t6, $v0, 10
    ctx->r14 = S32(ctx->r2 << 10);
L_80013474:
    // 0x80013474: bgez        $t6, L_80013494
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80013478: addiu       $t0, $zero, 0x80
        ctx->r8 = ADD32(0, 0X80);
            goto L_80013494;
    }
    // 0x80013478: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x8001347C: lbu         $t7, 0x9($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X9);
    // 0x80013480: lbu         $t8, 0xA($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA);
    // 0x80013484: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80013488: mflo        $t9
    ctx->r25 = lo;
    // 0x8001348C: sw          $t9, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r25;
    // 0x80013490: nop

L_80013494:
    // 0x80013494: lw          $v1, 0x48($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X48);
    // 0x80013498: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8001349C: beq         $v1, $zero, L_80013598
    if (ctx->r3 == 0) {
        // 0x800134A0: nop
    
            goto L_80013598;
    }
    // 0x800134A0: nop

    // 0x800134A4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800134A8: srl         $t2, $v0, 31
    ctx->r10 = S32(U32(ctx->r2) >> 31);
    // 0x800134AC: beq         $t2, $zero, L_80013598
    if (ctx->r10 == 0) {
        // 0x800134B0: nop
    
            goto L_80013598;
    }
    // 0x800134B0: nop

    // 0x800134B4: lw          $t3, 0x40($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X40);
    // 0x800134B8: sll         $t5, $v0, 5
    ctx->r13 = S32(ctx->r2 << 5);
    // 0x800134BC: beq         $t3, $zero, L_80013598
    if (ctx->r11 == 0) {
        // 0x800134C0: nop
    
            goto L_80013598;
    }
    // 0x800134C0: nop

    // 0x800134C4: bgezl       $t5, L_80013524
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800134C8: lb          $t8, 0x1($a0)
        ctx->r24 = MEM_B(ctx->r4, 0X1);
            goto L_80013524;
    }
    goto skip_1;
    // 0x800134C8: lb          $t8, 0x1($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X1);
    skip_1:
    // 0x800134CC: lwc1        $f4, 0x24($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
    // 0x800134D0: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800134D4: lwc1        $f10, 0x28($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X28);
    // 0x800134D8: lbu         $t6, 0x6($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X6);
    // 0x800134DC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800134E0: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x800134E4: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x800134E8: lwc1        $f16, 0x2C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800134EC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800134F0: swc1        $f18, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f18.u32l;
    // 0x800134F4: lbu         $t7, 0xA($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XA);
    // 0x800134F8: lw          $t2, 0x28($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X28);
    // 0x800134FC: subu        $t8, $t0, $t7
    ctx->r24 = SUB32(ctx->r8, ctx->r15);
    // 0x80013500: multu       $t6, $t8
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80013504: andi        $t7, $t5, 0xFFFB
    ctx->r15 = ctx->r13 & 0XFFFB;
    // 0x80013508: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x8001350C: mflo        $t9
    ctx->r25 = lo;
    // 0x80013510: addu        $t3, $t2, $t9
    ctx->r11 = ADD32(ctx->r10, ctx->r25);
    // 0x80013514: sra         $t4, $t3, 7
    ctx->r12 = S32(SIGNED(ctx->r11) >> 7);
    // 0x80013518: b           L_80013598
    // 0x8001351C: sb          $t4, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r12;
        goto L_80013598;
    // 0x8001351C: sb          $t4, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r12;
    // 0x80013520: lb          $t8, 0x1($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X1);
L_80013524:
    // 0x80013524: bgezl       $t8, L_80013540
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80013528: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_80013540;
    }
    goto skip_2;
    // 0x80013528: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_2:
    // 0x8001352C: lwc1        $f4, 0x24($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80013530: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80013534: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80013538: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x8001353C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80013540:
    // 0x80013540: sll         $t9, $v0, 9
    ctx->r25 = S32(ctx->r2 << 9);
    // 0x80013544: bltzl       $t9, L_80013558
    if (SIGNED(ctx->r25) < 0) {
        // 0x80013548: lwc1        $f10, 0x28($v1)
        ctx->f10.u32l = MEM_W(ctx->r3, 0X28);
            goto L_80013558;
    }
    goto skip_3;
    // 0x80013548: lwc1        $f10, 0x28($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X28);
    skip_3:
    // 0x8001354C: beql        $a1, $zero, L_8001356C
    if (ctx->r5 == 0) {
        // 0x80013550: sll         $t4, $v0, 10
        ctx->r12 = S32(ctx->r2 << 10);
            goto L_8001356C;
    }
    goto skip_4;
    // 0x80013550: sll         $t4, $v0, 10
    ctx->r12 = S32(ctx->r2 << 10);
    skip_4:
    // 0x80013554: lwc1        $f10, 0x28($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X28);
L_80013558:
    // 0x80013558: lwc1        $f16, 0x2C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8001355C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80013560: swc1        $f18, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f18.u32l;
    // 0x80013564: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80013568: sll         $t4, $v0, 10
    ctx->r12 = S32(ctx->r2 << 10);
L_8001356C:
    // 0x8001356C: bgez        $t4, L_80013598
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80013570: nop
    
            goto L_80013598;
    }
    // 0x80013570: nop

    // 0x80013574: lbu         $t7, 0xA($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XA);
    // 0x80013578: lbu         $t5, 0x6($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X6);
    // 0x8001357C: lw          $t2, 0x28($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X28);
    // 0x80013580: subu        $t6, $t0, $t7
    ctx->r14 = SUB32(ctx->r8, ctx->r15);
    // 0x80013584: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80013588: mflo        $t8
    ctx->r24 = lo;
    // 0x8001358C: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x80013590: sra         $t3, $t9, 7
    ctx->r11 = S32(SIGNED(ctx->r25) >> 7);
    // 0x80013594: sb          $t3, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r11;
L_80013598:
    // 0x80013598: bne         $a2, $t1, L_80013494
    if (ctx->r6 != ctx->r9) {
        // 0x8001359C: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80013494;
    }
    // 0x8001359C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800135A0: jr          $ra
    // 0x800135A4: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    return;
    // 0x800135A4: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
;}
RECOMP_FUNC void Camera_UpdateOnFoot360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6BFC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800B6C00: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800B6C04: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x800B6C08: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800B6C0C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800B6C10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6C14: lwc1        $f20, -0x751C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X751C);
    // 0x800B6C18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B6C1C: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x800B6C20: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800B6C24: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800B6C28: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x800B6C2C: lwc1        $f4, 0xFC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x800B6C30: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800B6C34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B6C38: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800B6C3C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800B6C40: jal         0x80005D44
    // 0x800B6C44: nop

    Matrix_RotateX(rdram, ctx);
        goto after_0;
    // 0x800B6C44: nop

    after_0:
    // 0x800B6C48: lwc1        $f8, 0x100($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X100);
    // 0x800B6C4C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800B6C50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B6C54: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800B6C58: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800B6C5C: jal         0x80005FE0
    // 0x800B6C60: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_1;
    // 0x800B6C60: nop

    after_1:
    // 0x800B6C64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6C68: lwc1        $f4, -0x7518($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7518);
    // 0x800B6C6C: lwc1        $f18, 0x134($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800B6C70: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800B6C74: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800B6C78: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B6C7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B6C80: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800B6C84: mul.s       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800B6C88: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800B6C8C: jal         0x80005E90
    // 0x800B6C90: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x800B6C90: nop

    after_2:
    // 0x800B6C94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6C98: lwc1        $f8, -0x7514($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7514);
    // 0x800B6C9C: lwc1        $f4, 0x134($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800B6CA0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800B6CA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B6CA8: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800B6CAC: nop

    // 0x800B6CB0: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800B6CB4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800B6CB8: jal         0x80005D44
    // 0x800B6CBC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_3;
    // 0x800B6CBC: nop

    after_3:
    // 0x800B6CC0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800B6CC4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B6CC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B6CCC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800B6CD0: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x800B6CD4: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x800B6CD8: lwc1        $f6, 0x8C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x800B6CDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B6CE0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800B6CE4: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x800B6CE8: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800B6CEC: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x800B6CF0: jal         0x80006A20
    // 0x800B6CF4: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_4;
    // 0x800B6CF4: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x800B6CF8: lwc1        $f18, 0x158($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X158);
    // 0x800B6CFC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B6D00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B6D04: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800B6D08: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6D0C: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800B6D10: lwc1        $f10, -0x7510($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7510);
    // 0x800B6D14: lui         $a2, 0x3D8F
    ctx->r6 = S32(0X3D8F << 16);
    // 0x800B6D18: ori         $a2, $a2, 0x5C29
    ctx->r6 = ctx->r6 | 0X5C29;
    // 0x800B6D1C: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x800B6D20: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x800B6D24: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x800B6D28: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800B6D2C: jal         0x8009BC2C
    // 0x800B6D30: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x800B6D30: nop

    after_5:
    // 0x800B6D34: lwc1        $f2, 0x74($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800B6D38: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800B6D3C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800B6D40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B6D44: lwc1        $f0, 0x68($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800B6D48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6D4C: add.s       $f20, $f2, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x800B6D50: lwc1        $f18, -0x750C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X750C);
    // 0x800B6D54: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800B6D58: add.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800B6D5C: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800B6D60: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x800B6D64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6D68: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800B6D6C: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800B6D70: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x800B6D74: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B6D78: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x800B6D7C: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800B6D80: lwc1        $f10, -0x7508($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7508);
    // 0x800B6D84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6D88: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x800B6D8C: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x800B6D90: lwc1        $f18, 0x134($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800B6D94: lwc1        $f14, 0x7C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800B6D98: lwc1        $f8, 0x78($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800B6D9C: mul.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800B6DA0: add.s       $f22, $f14, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x800B6DA4: sub.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800B6DA8: add.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x800B6DAC: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    // 0x800B6DB0: lwc1        $f18, -0x7504($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7504);
    // 0x800B6DB4: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x800B6DB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B6DBC: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800B6DC0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800B6DC4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B6DC8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800B6DCC: swc1        $f14, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f14.u32l;
    // 0x800B6DD0: add.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x800B6DD4: mul.s       $f10, $f12, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x800B6DD8: lwc1        $f18, 0xD0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x800B6DDC: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B6DE0: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800B6DE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B6DE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6DEC: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800B6DF0: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800B6DF4: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800B6DF8: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    // 0x800B6DFC: lwc1        $f18, -0x7500($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7500);
    // 0x800B6E00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6E04: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800B6E08: lwc1        $f4, -0x74FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X74FC);
    // 0x800B6E0C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800B6E10: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800B6E14: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800B6E18: jal         0x8009BC2C
    // 0x800B6E1C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x800B6E1C: nop

    after_6:
    // 0x800B6E20: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800B6E24: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B6E28: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800B6E2C: neg.s       $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = -ctx->f10.fl;
    // 0x800B6E30: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x800B6E34: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x800B6E38: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x800B6E3C: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x800B6E40: jal         0x80006A20
    // 0x800B6E44: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_7;
    // 0x800B6E44: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x800B6E48: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800B6E4C: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800B6E50: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800B6E54: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800B6E58: add.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800B6E5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6E60: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800B6E64: add.s       $f22, $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f6.fl;
    // 0x800B6E68: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
    // 0x800B6E6C: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800B6E70: add.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x800B6E74: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800B6E78: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x800B6E7C: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800B6E80: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800B6E84: lui         $a3, 0x4282
    ctx->r7 = S32(0X4282 << 16);
    // 0x800B6E88: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x800B6E8C: lwc1        $f18, -0x74F8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X74F8);
    // 0x800B6E90: jal         0x8009BC2C
    // 0x800B6E94: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x800B6E94: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_8:
    // 0x800B6E98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6E9C: lwc1        $f10, -0x74F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X74F4);
    // 0x800B6EA0: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800B6EA4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800B6EA8: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x800B6EAC: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800B6EB0: lui         $a3, 0x4282
    ctx->r7 = S32(0X4282 << 16);
    // 0x800B6EB4: jal         0x8009BC2C
    // 0x800B6EB8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x800B6EB8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x800B6EBC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6EC0: lwc1        $f8, -0x74F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X74F0);
    // 0x800B6EC4: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x800B6EC8: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800B6ECC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800B6ED0: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x800B6ED4: lui         $a3, 0x4282
    ctx->r7 = S32(0X4282 << 16);
    // 0x800B6ED8: jal         0x8009BC2C
    // 0x800B6EDC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x800B6EDC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_10:
    // 0x800B6EE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6EE4: lwc1        $f4, -0x74EC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X74EC);
    // 0x800B6EE8: lwc1        $f6, 0x12C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800B6EEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6EF0: lwc1        $f10, -0x74E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X74E8);
    // 0x800B6EF4: mul.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800B6EF8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B6EFC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B6F00: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x800B6F04: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800B6F08: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x800B6F0C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800B6F10: jal         0x8009BC2C
    // 0x800B6F14: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x800B6F14: nop

    after_11:
    // 0x800B6F18: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800B6F1C: beql        $t6, $zero, L_800B6F38
    if (ctx->r14 == 0) {
        // 0x800B6F20: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800B6F38;
    }
    goto skip_0;
    // 0x800B6F20: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x800B6F24: swc1        $f20, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f20.u32l;
    // 0x800B6F28: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800B6F2C: swc1        $f22, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f22.u32l;
    // 0x800B6F30: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    // 0x800B6F34: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800B6F38:
    // 0x800B6F38: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800B6F3C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800B6F40: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6F44: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800B6F48: jr          $ra
    // 0x800B6F4C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800B6F4C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void AudioSeq_SequenceChannelProcessScript(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800153E8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800153EC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800153F0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800153F4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800153F8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800153FC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80015400: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80015404: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80015408: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8001540C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80015410: srl         $t6, $v0, 31
    ctx->r14 = S32(U32(ctx->r2) >> 31);
    // 0x80015414: beq         $t6, $zero, L_80015FB0
    if (ctx->r14 == 0) {
        // 0x80015418: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_80015FB0;
    }
    // 0x80015418: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8001541C: bgez        $t8, L_80015454
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80015420: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80015454;
    }
    // 0x80015420: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80015424: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80015428: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
L_8001542C:
    // 0x8001542C: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80015430: beql        $a0, $zero, L_80015444
    if (ctx->r4 == 0) {
        // 0x80015434: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80015444;
    }
    goto skip_0;
    // 0x80015434: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x80015438: jal         0x80014748
    // 0x8001543C: nop

    AudioSeq_SeqLayerProcessScript(rdram, ctx);
        goto after_0;
    // 0x8001543C: nop

    after_0:
    // 0x80015440: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80015444:
    // 0x80015444: bne         $s0, $s2, L_8001542C
    if (ctx->r16 != ctx->r18) {
        // 0x80015448: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8001542C;
    }
    // 0x80015448: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8001544C: b           L_80015FB4
    // 0x80015450: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80015FB4;
    // 0x80015450: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80015454:
    // 0x80015454: lw          $s4, 0x44($s2)
    ctx->r20 = MEM_W(ctx->r18, 0X44);
    // 0x80015458: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8001545C: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80015460: bgezl       $t2, L_8001547C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80015464: lhu         $v1, 0x1A($s2)
        ctx->r3 = MEM_HU(ctx->r18, 0X1A);
            goto L_8001547C;
    }
    goto skip_1;
    // 0x80015464: lhu         $v1, 0x1A($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X1A);
    skip_1:
    // 0x80015468: lbu         $t3, 0x3($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X3);
    // 0x8001546C: andi        $t4, $t3, 0x80
    ctx->r12 = ctx->r11 & 0X80;
    // 0x80015470: bnel        $t4, $zero, L_80015FB4
    if (ctx->r12 != 0) {
        // 0x80015474: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80015FB4;
    }
    goto skip_2;
    // 0x80015474: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x80015478: lhu         $v1, 0x1A($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X1A);
L_8001547C:
    // 0x8001547C: addiu       $s1, $s2, 0x58
    ctx->r17 = ADD32(ctx->r18, 0X58);
    // 0x80015480: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x80015484: beq         $v1, $zero, L_80015498
    if (ctx->r3 == 0) {
        // 0x80015488: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80015498;
    }
    // 0x80015488: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001548C: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x80015490: sh          $t5, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r13;
    // 0x80015494: andi        $v0, $t5, 0xFFFF
    ctx->r2 = ctx->r13 & 0XFFFF;
L_80015498:
    // 0x80015498: bne         $v0, $zero, L_80015F84
    if (ctx->r2 != 0) {
        // 0x8001549C: lb          $s3, 0x4B($sp)
        ctx->r19 = MEM_B(ctx->r29, 0X4B);
            goto L_80015F84;
    }
    // 0x8001549C: lb          $s3, 0x4B($sp)
    ctx->r19 = MEM_B(ctx->r29, 0X4B);
L_800154A0:
    // 0x800154A0: jal         0x800146C0
    // 0x800154A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_1;
    // 0x800154A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800154A8: slti        $at, $v0, 0xC1
    ctx->r1 = SIGNED(ctx->r2) < 0XC1 ? 1 : 0;
    // 0x800154AC: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x800154B0: bne         $at, $zero, L_80015D50
    if (ctx->r1 != 0) {
        // 0x800154B4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80015D50;
    }
    // 0x800154B4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800154B8: addiu       $t6, $v0, -0xC1
    ctx->r14 = ADD32(ctx->r2, -0XC1);
    // 0x800154BC: sltiu       $at, $t6, 0x3F
    ctx->r1 = ctx->r14 < 0X3F ? 1 : 0;
    // 0x800154C0: beq         $at, $zero, L_800154A0
    if (ctx->r1 == 0) {
        // 0x800154C4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800154A0;
    }
    // 0x800154C4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800154C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800154CC: addu        $at, $at, $t6
    gpr jr_addend_800154D4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800154D0: lw          $t6, -0x785C($at)
    ctx->r14 = ADD32(ctx->r1, -0X785C);
    // 0x800154D4: jr          $t6
    // 0x800154D8: nop

    switch (jr_addend_800154D4 >> 2) {
        case 0: goto L_80015780; break;
        case 1: goto L_800156D8; break;
        case 2: goto L_8001579C; break;
        case 3: goto L_800157AC; break;
        case 4: goto L_800156F4; break;
        case 5: goto L_800159EC; break;
        case 6: goto L_80015A44; break;
        case 7: goto L_80015A7C; break;
        case 8: goto L_80015A7C; break;
        case 9: goto L_80015AE8; break;
        case 10: goto L_80015AF8; break;
        case 11: goto L_80015A7C; break;
        case 12: goto L_80015AC8; break;
        case 13: goto L_80015B18; break;
        case 14: goto L_80015B28; break;
        case 15: goto L_80015B54; break;
        case 16: goto L_80015B78; break;
        case 17: goto L_80015B88; break;
        case 18: goto L_80015844; break;
        case 19: goto L_800159DC; break;
        case 20: goto L_800154A0; break;
        case 21: goto L_800154A0; break;
        case 22: goto L_80015944; break;
        case 23: goto L_80015928; break;
        case 24: goto L_80015918; break;
        case 25: goto L_800158FC; break;
        case 26: goto L_800158E4; break;
        case 27: goto L_800158C8; break;
        case 28: goto L_800158AC; break;
        case 29: goto L_80015810; break;
        case 30: goto L_800157BC; break;
        case 31: goto L_800157E0; break;
        case 32: goto L_80015994; break;
        case 33: goto L_80015960; break;
        case 34: goto L_800159C8; break;
        case 35: goto L_80015BA8; break;
        case 36: goto L_80015B98; break;
        case 37: goto L_80015C00; break;
        case 38: goto L_80015C10; break;
        case 39: goto L_80015C78; break;
        case 40: goto L_80015D18; break;
        case 41: goto L_80015524; break;
        case 42: goto L_8001572C; break;
        case 43: goto L_80015CF0; break;
        case 44: goto L_80015D28; break;
        case 45: goto L_80015878; break;
        case 46: goto L_80015D38; break;
        case 47: goto L_800156C8; break;
        case 48: goto L_800156A0; break;
        case 49: goto L_80015658; break;
        case 50: goto L_80015658; break;
        case 51: goto L_80015658; break;
        case 52: goto L_80015600; break;
        case 53: goto L_800155F0; break;
        case 54: goto L_800155A8; break;
        case 55: goto L_80015570; break;
        case 56: goto L_80015600; break;
        case 57: goto L_80015600; break;
        case 58: goto L_80015600; break;
        case 59: goto L_80015534; break;
        case 60: goto L_80015514; break;
        case 61: goto L_80015F84; break;
        case 62: goto L_800154DC; break;
        default: switch_error(__func__, 0x800154D4, 0x800C87A4);
    }
    // 0x800154D8: nop

L_800154DC:
    // 0x800154DC: lbu         $a0, 0x18($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X18);
    // 0x800154E0: bne         $a0, $zero, L_800154F8
    if (ctx->r4 != 0) {
        // 0x800154E4: addiu       $v0, $a0, -0x1
        ctx->r2 = ADD32(ctx->r4, -0X1);
            goto L_800154F8;
    }
    // 0x800154E4: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x800154E8: jal         0x8001415C
    // 0x800154EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    AudioSeq_SequenceChannelDisable(rdram, ctx);
        goto after_2;
    // 0x800154EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x800154F0: b           L_80015F88
    // 0x800154F4: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
        goto L_80015F88;
    // 0x800154F4: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_800154F8:
    // 0x800154F8: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x800154FC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80015500: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x80015504: sb          $t7, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r15;
    // 0x80015508: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x8001550C: b           L_800154A0
    // 0x80015510: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
        goto L_800154A0;
    // 0x80015510: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
L_80015514:
    // 0x80015514: jal         0x80014704
    // 0x80015518: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadCompressedU16(rdram, ctx);
        goto after_3;
    // 0x80015518: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8001551C: b           L_80015F84
    // 0x80015520: sh          $v0, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r2;
        goto L_80015F84;
    // 0x80015520: sh          $v0, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r2;
L_80015524:
    // 0x80015524: lbu         $t3, 0x0($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X0);
    // 0x80015528: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x8001552C: b           L_80015F84
    // 0x80015530: sb          $t4, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r12;
        goto L_80015F84;
    // 0x80015530: sb          $t4, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r12;
L_80015534:
    // 0x80015534: jal         0x800146D4
    // 0x80015538: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_4;
    // 0x80015538: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8001553C: lbu         $t6, 0x18($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X18);
    // 0x80015540: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80015544: andi        $t3, $v0, 0xFFFF
    ctx->r11 = ctx->r2 & 0XFFFF;
    // 0x80015548: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001554C: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x80015550: sw          $t5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r13;
    // 0x80015554: lbu         $t9, 0x18($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X18);
    // 0x80015558: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x8001555C: sb          $t1, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r9;
    // 0x80015560: lw          $t2, 0x18($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X18);
    // 0x80015564: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80015568: b           L_800154A0
    // 0x8001556C: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
        goto L_800154A0;
    // 0x8001556C: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
L_80015570:
    // 0x80015570: jal         0x800146C0
    // 0x80015574: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_5;
    // 0x80015574: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80015578: lbu         $t6, 0x18($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X18);
    // 0x8001557C: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x80015580: sb          $v0, 0x14($t7)
    MEM_B(0X14, ctx->r15) = ctx->r2;
    // 0x80015584: lbu         $t8, 0x18($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X18);
    // 0x80015588: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8001558C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80015590: addu        $t1, $s1, $t9
    ctx->r9 = ADD32(ctx->r17, ctx->r25);
    // 0x80015594: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x80015598: lbu         $t2, 0x18($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X18);
    // 0x8001559C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800155A0: b           L_800154A0
    // 0x800155A4: sb          $t3, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r11;
        goto L_800154A0;
    // 0x800155A4: sb          $t3, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r11;
L_800155A8:
    // 0x800155A8: lbu         $t4, 0x18($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X18);
    // 0x800155AC: addu        $v0, $s1, $t4
    ctx->r2 = ADD32(ctx->r17, ctx->r12);
    // 0x800155B0: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x800155B4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800155B8: sb          $t7, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r15;
    // 0x800155BC: lbu         $a0, 0x18($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X18);
    // 0x800155C0: addu        $t8, $s1, $a0
    ctx->r24 = ADD32(ctx->r17, ctx->r4);
    // 0x800155C4: lbu         $t9, 0x13($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X13);
    // 0x800155C8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800155CC: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x800155D0: beq         $t9, $zero, L_800155E8
    if (ctx->r25 == 0) {
        // 0x800155D4: addiu       $t3, $a0, -0x1
        ctx->r11 = ADD32(ctx->r4, -0X1);
            goto L_800155E8;
    }
    // 0x800155D4: addiu       $t3, $a0, -0x1
    ctx->r11 = ADD32(ctx->r4, -0X1);
    // 0x800155D8: addu        $t1, $s1, $t5
    ctx->r9 = ADD32(ctx->r17, ctx->r13);
    // 0x800155DC: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800155E0: b           L_800154A0
    // 0x800155E4: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
        goto L_800154A0;
    // 0x800155E4: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
L_800155E8:
    // 0x800155E8: b           L_800154A0
    // 0x800155EC: sb          $t3, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r11;
        goto L_800154A0;
    // 0x800155EC: sb          $t3, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r11;
L_800155F0:
    // 0x800155F0: lbu         $t4, 0x18($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X18);
    // 0x800155F4: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x800155F8: b           L_800154A0
    // 0x800155FC: sb          $t6, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r14;
        goto L_800154A0;
    // 0x800155FC: sb          $t6, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r14;
L_80015600:
    // 0x80015600: jal         0x800146D4
    // 0x80015604: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_6;
    // 0x80015604: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80015608: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
    // 0x8001560C: bne         $s0, $at, L_8001561C
    if (ctx->r16 != ctx->r1) {
        // 0x80015610: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_8001561C;
    }
    // 0x80015610: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80015614: bne         $s3, $zero, L_800154A0
    if (ctx->r19 != 0) {
        // 0x80015618: nop
    
            goto L_800154A0;
    }
    // 0x80015618: nop

L_8001561C:
    // 0x8001561C: addiu       $at, $zero, 0xF9
    ctx->r1 = ADD32(0, 0XF9);
    // 0x80015620: bnel        $v1, $at, L_80015634
    if (ctx->r3 != ctx->r1) {
        // 0x80015624: addiu       $at, $zero, 0xF5
        ctx->r1 = ADD32(0, 0XF5);
            goto L_80015634;
    }
    goto skip_3;
    // 0x80015624: addiu       $at, $zero, 0xF5
    ctx->r1 = ADD32(0, 0XF5);
    skip_3:
    // 0x80015628: bgez        $s3, L_800154A0
    if (SIGNED(ctx->r19) >= 0) {
        // 0x8001562C: nop
    
            goto L_800154A0;
    }
    // 0x8001562C: nop

    // 0x80015630: addiu       $at, $zero, 0xF5
    ctx->r1 = ADD32(0, 0XF5);
L_80015634:
    // 0x80015634: bnel        $v1, $at, L_80015648
    if (ctx->r3 != ctx->r1) {
        // 0x80015638: lw          $t7, 0x18($s4)
        ctx->r15 = MEM_W(ctx->r20, 0X18);
            goto L_80015648;
    }
    goto skip_4;
    // 0x80015638: lw          $t7, 0x18($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X18);
    skip_4:
    // 0x8001563C: bltz        $s3, L_800154A0
    if (SIGNED(ctx->r19) < 0) {
        // 0x80015640: nop
    
            goto L_800154A0;
    }
    // 0x80015640: nop

    // 0x80015644: lw          $t7, 0x18($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X18);
L_80015648:
    // 0x80015648: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x8001564C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80015650: b           L_800154A0
    // 0x80015654: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
        goto L_800154A0;
    // 0x80015654: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
L_80015658:
    // 0x80015658: jal         0x800146C0
    // 0x8001565C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_7;
    // 0x8001565C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80015660: addiu       $at, $zero, 0xF3
    ctx->r1 = ADD32(0, 0XF3);
    // 0x80015664: bne         $s0, $at, L_80015674
    if (ctx->r16 != ctx->r1) {
        // 0x80015668: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_80015674;
    }
    // 0x80015668: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8001566C: bne         $s3, $zero, L_800154A0
    if (ctx->r19 != 0) {
        // 0x80015670: nop
    
            goto L_800154A0;
    }
    // 0x80015670: nop

L_80015674:
    // 0x80015674: addiu       $at, $zero, 0xF2
    ctx->r1 = ADD32(0, 0XF2);
    // 0x80015678: bnel        $v1, $at, L_8001568C
    if (ctx->r3 != ctx->r1) {
        // 0x8001567C: lw          $t5, 0x0($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X0);
            goto L_8001568C;
    }
    goto skip_5;
    // 0x8001567C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    skip_5:
    // 0x80015680: bgez        $s3, L_800154A0
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80015684: nop
    
            goto L_800154A0;
    }
    // 0x80015684: nop

    // 0x80015688: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
L_8001568C:
    // 0x8001568C: sll         $t1, $v0, 24
    ctx->r9 = S32(ctx->r2 << 24);
    // 0x80015690: sra         $t2, $t1, 24
    ctx->r10 = S32(SIGNED(ctx->r9) >> 24);
    // 0x80015694: addu        $t3, $t5, $t2
    ctx->r11 = ADD32(ctx->r13, ctx->r10);
    // 0x80015698: b           L_800154A0
    // 0x8001569C: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
        goto L_800154A0;
    // 0x8001569C: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
L_800156A0:
    // 0x800156A0: addiu       $s0, $s2, 0x7C
    ctx->r16 = ADD32(ctx->r18, 0X7C);
    // 0x800156A4: jal         0x80012964
    // 0x800156A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Audio_NotePoolClear(rdram, ctx);
        goto after_8;
    // 0x800156A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800156AC: jal         0x800146C0
    // 0x800156B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_9;
    // 0x800156B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x800156B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800156B8: jal         0x80012AC4
    // 0x800156BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    Audio_NotePoolFill(rdram, ctx);
        goto after_10;
    // 0x800156BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x800156C0: b           L_800154A0
    // 0x800156C4: nop

        goto L_800154A0;
    // 0x800156C4: nop

L_800156C8:
    // 0x800156C8: jal         0x80012964
    // 0x800156CC: addiu       $a0, $s2, 0x7C
    ctx->r4 = ADD32(ctx->r18, 0X7C);
    Audio_NotePoolClear(rdram, ctx);
        goto after_11;
    // 0x800156CC: addiu       $a0, $s2, 0x7C
    ctx->r4 = ADD32(ctx->r18, 0X7C);
    after_11:
    // 0x800156D0: b           L_800154A0
    // 0x800156D4: nop

        goto L_800154A0;
    // 0x800156D4: nop

L_800156D8:
    // 0x800156D8: jal         0x800146D4
    // 0x800156DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_12;
    // 0x800156DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x800156E0: lw          $t4, 0x18($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X18);
    // 0x800156E4: andi        $t6, $v0, 0xFFFF
    ctx->r14 = ctx->r2 & 0XFFFF;
    // 0x800156E8: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800156EC: b           L_800154A0
    // 0x800156F0: sw          $t7, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r15;
        goto L_800154A0;
    // 0x800156F0: sw          $t7, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r15;
L_800156F4:
    // 0x800156F4: beq         $s3, $s5, L_800154A0
    if (ctx->r19 == ctx->r21) {
        // 0x800156F8: nop
    
            goto L_800154A0;
    }
    // 0x800156F8: nop

    // 0x800156FC: lw          $t8, 0x34($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X34);
    // 0x80015700: sll         $t9, $s3, 1
    ctx->r25 = S32(ctx->r19 << 1);
    // 0x80015704: lw          $t4, 0x18($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X18);
    // 0x80015708: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8001570C: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x80015710: lbu         $t1, 0x1($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X1);
    // 0x80015714: sll         $t2, $t5, 8
    ctx->r10 = S32(ctx->r13 << 8);
    // 0x80015718: addu        $a3, $t1, $t2
    ctx->r7 = ADD32(ctx->r9, ctx->r10);
    // 0x8001571C: andi        $t3, $a3, 0xFFFF
    ctx->r11 = ctx->r7 & 0XFFFF;
    // 0x80015720: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x80015724: b           L_800154A0
    // 0x80015728: sw          $t6, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r14;
        goto L_800154A0;
    // 0x80015728: sw          $t6, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r14;
L_8001572C:
    // 0x8001572C: jal         0x800146C0
    // 0x80015730: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_13;
    // 0x80015730: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80015734: lbu         $t7, 0x4($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X4);
    // 0x80015738: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8001573C: lw          $v1, 0x5C68($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5C68);
    // 0x80015740: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80015744: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80015748: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x8001574C: lhu         $a3, 0x0($t9)
    ctx->r7 = MEM_HU(ctx->r25, 0X0);
    // 0x80015750: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80015754: addu        $t5, $a3, $v1
    ctx->r13 = ADD32(ctx->r7, ctx->r3);
    // 0x80015758: lbu         $t0, 0x0($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X0);
    // 0x8001575C: addu        $t1, $a3, $t0
    ctx->r9 = ADD32(ctx->r7, ctx->r8);
    // 0x80015760: subu        $t2, $t1, $v0
    ctx->r10 = SUB32(ctx->r9, ctx->r2);
    // 0x80015764: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80015768: lbu         $s0, 0x0($t3)
    ctx->r16 = MEM_BU(ctx->r11, 0X0);
    // 0x8001576C: jal         0x8000C990
    // 0x80015770: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    AudioHeap_SearchCaches(rdram, ctx);
        goto after_14;
    // 0x80015770: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_14:
    // 0x80015774: beq         $v0, $zero, L_80015780
    if (ctx->r2 == 0) {
        // 0x80015778: nop
    
            goto L_80015780;
    }
    // 0x80015778: nop

    // 0x8001577C: sb          $s0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r16;
L_80015780:
    // 0x80015780: jal         0x800146C0
    // 0x80015784: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_15;
    // 0x80015784: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80015788: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8001578C: jal         0x80015330
    // 0x80015790: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    AudioSeq_SetInstrument(rdram, ctx);
        goto after_16;
    // 0x80015790: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_16:
    // 0x80015794: b           L_800154A0
    // 0x80015798: nop

        goto L_800154A0;
    // 0x80015798: nop

L_8001579C:
    // 0x8001579C: lbu         $t4, 0x0($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X0);
    // 0x800157A0: andi        $t6, $t4, 0xFFFD
    ctx->r14 = ctx->r12 & 0XFFFD;
    // 0x800157A4: b           L_800154A0
    // 0x800157A8: sb          $t6, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r14;
        goto L_800154A0;
    // 0x800157A8: sb          $t6, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r14;
L_800157AC:
    // 0x800157AC: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x800157B0: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x800157B4: b           L_800154A0
    // 0x800157B8: sb          $t9, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r25;
        goto L_800154A0;
    // 0x800157B8: sb          $t9, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r25;
L_800157BC:
    // 0x800157BC: jal         0x800146C0
    // 0x800157C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_17;
    // 0x800157C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x800157C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800157C8: jal         0x800153C4
    // 0x800157CC: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    AudioSeq_SequenceChannelSetVolume(rdram, ctx);
        goto after_18;
    // 0x800157CC: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_18:
    // 0x800157D0: lbu         $t1, 0x1($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X1);
    // 0x800157D4: ori         $t2, $t1, 0x40
    ctx->r10 = ctx->r9 | 0X40;
    // 0x800157D8: b           L_800154A0
    // 0x800157DC: sb          $t2, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r10;
        goto L_800154A0;
    // 0x800157DC: sb          $t2, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r10;
L_800157E0:
    // 0x800157E0: jal         0x800146C0
    // 0x800157E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_19;
    // 0x800157E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
    // 0x800157E8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800157EC: lui         $at, 0x3C00
    ctx->r1 = S32(0X3C00 << 16);
    // 0x800157F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800157F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800157F8: lbu         $t4, 0x1($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X1);
    // 0x800157FC: ori         $t6, $t4, 0x40
    ctx->r14 = ctx->r12 | 0X40;
    // 0x80015800: sb          $t6, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r14;
    // 0x80015804: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80015808: b           L_800154A0
    // 0x8001580C: swc1        $f10, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f10.u32l;
        goto L_800154A0;
    // 0x8001580C: swc1        $f10, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f10.u32l;
L_80015810:
    // 0x80015810: jal         0x800146D4
    // 0x80015814: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_20;
    // 0x80015814: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x80015818: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x8001581C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80015820: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x80015824: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80015828: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001582C: lbu         $t9, 0x1($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X1);
    // 0x80015830: ori         $t5, $t9, 0x80
    ctx->r13 = ctx->r25 | 0X80;
    // 0x80015834: sb          $t5, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r13;
    // 0x80015838: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8001583C: b           L_800154A0
    // 0x80015840: swc1        $f6, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f6.u32l;
        goto L_800154A0;
    // 0x80015840: swc1        $f6, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f6.u32l;
L_80015844:
    // 0x80015844: jal         0x800146C0
    // 0x80015848: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_21;
    // 0x80015848: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x8001584C: addiu       $t1, $v0, 0x80
    ctx->r9 = ADD32(ctx->r2, 0X80);
    // 0x80015850: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x80015854: lbu         $t6, 0x1($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X1);
    // 0x80015858: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8001585C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80015860: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80015864: lwc1        $f8, -0x38D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X38D0);
    // 0x80015868: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x8001586C: sb          $t7, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r15;
    // 0x80015870: b           L_800154A0
    // 0x80015874: swc1        $f8, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f8.u32l;
        goto L_800154A0;
    // 0x80015874: swc1        $f8, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f8.u32l;
L_80015878:
    // 0x80015878: jal         0x800146C0
    // 0x8001587C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_22;
    // 0x8001587C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
    // 0x80015880: addiu       $t8, $v0, 0x80
    ctx->r24 = ADD32(ctx->r2, 0X80);
    // 0x80015884: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80015888: lbu         $t2, 0x1($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X1);
    // 0x8001588C: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x80015890: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80015894: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80015898: lwc1        $f10, -0x34D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X34D0);
    // 0x8001589C: ori         $t3, $t2, 0x80
    ctx->r11 = ctx->r10 | 0X80;
    // 0x800158A0: sb          $t3, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r11;
    // 0x800158A4: b           L_800154A0
    // 0x800158A8: swc1        $f10, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f10.u32l;
        goto L_800154A0;
    // 0x800158A8: swc1        $f10, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f10.u32l;
L_800158AC:
    // 0x800158AC: jal         0x800146C0
    // 0x800158B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_23;
    // 0x800158B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_23:
    // 0x800158B4: lbu         $t6, 0x1($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X1);
    // 0x800158B8: sb          $v0, 0x9($s2)
    MEM_B(0X9, ctx->r18) = ctx->r2;
    // 0x800158BC: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x800158C0: b           L_800154A0
    // 0x800158C4: sb          $t7, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r15;
        goto L_800154A0;
    // 0x800158C4: sb          $t7, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r15;
L_800158C8:
    // 0x800158C8: jal         0x800146C0
    // 0x800158CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_24;
    // 0x800158CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_24:
    // 0x800158D0: lbu         $t9, 0x1($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X1);
    // 0x800158D4: sb          $v0, 0xA($s2)
    MEM_B(0XA, ctx->r18) = ctx->r2;
    // 0x800158D8: ori         $t5, $t9, 0x20
    ctx->r13 = ctx->r25 | 0X20;
    // 0x800158DC: b           L_800154A0
    // 0x800158E0: sb          $t5, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r13;
        goto L_800154A0;
    // 0x800158E0: sb          $t5, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r13;
L_800158E4:
    // 0x800158E4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800158E8: lb          $v1, 0x0($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X0);
    // 0x800158EC: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x800158F0: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x800158F4: b           L_800154A0
    // 0x800158F8: sh          $v1, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = ctx->r3;
        goto L_800154A0;
    // 0x800158F8: sh          $v1, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = ctx->r3;
L_800158FC:
    // 0x800158FC: jal         0x800146D4
    // 0x80015900: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_25;
    // 0x80015900: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_25:
    // 0x80015904: lw          $t2, 0x18($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X18);
    // 0x80015908: andi        $t3, $v0, 0xFFFF
    ctx->r11 = ctx->r2 & 0XFFFF;
    // 0x8001590C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80015910: b           L_800154A0
    // 0x80015914: sw          $t4, 0x78($s2)
    MEM_W(0X78, ctx->r18) = ctx->r12;
        goto L_800154A0;
    // 0x80015914: sw          $t4, 0x78($s2)
    MEM_W(0X78, ctx->r18) = ctx->r12;
L_80015918:
    // 0x80015918: jal         0x800146C0
    // 0x8001591C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_26;
    // 0x8001591C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_26:
    // 0x80015920: b           L_800154A0
    // 0x80015924: sb          $v0, 0x74($s2)
    MEM_B(0X74, ctx->r18) = ctx->r2;
        goto L_800154A0;
    // 0x80015924: sb          $v0, 0x74($s2)
    MEM_B(0X74, ctx->r18) = ctx->r2;
L_80015928:
    // 0x80015928: jal         0x800146C0
    // 0x8001592C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_27;
    // 0x8001592C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_27:
    // 0x80015930: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80015934: sh          $t6, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r14;
    // 0x80015938: sh          $zero, 0xE($s2)
    MEM_H(0XE, ctx->r18) = 0;
    // 0x8001593C: b           L_800154A0
    // 0x80015940: sh          $zero, 0x16($s2)
    MEM_H(0X16, ctx->r18) = 0;
        goto L_800154A0;
    // 0x80015940: sh          $zero, 0x16($s2)
    MEM_H(0X16, ctx->r18) = 0;
L_80015944:
    // 0x80015944: jal         0x800146C0
    // 0x80015948: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_28;
    // 0x80015948: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_28:
    // 0x8001594C: sll         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2 << 5);
    // 0x80015950: sh          $v1, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r3;
    // 0x80015954: sh          $v1, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r3;
    // 0x80015958: b           L_800154A0
    // 0x8001595C: sh          $zero, 0x14($s2)
    MEM_H(0X14, ctx->r18) = 0;
        goto L_800154A0;
    // 0x8001595C: sh          $zero, 0x14($s2)
    MEM_H(0X14, ctx->r18) = 0;
L_80015960:
    // 0x80015960: jal         0x800146C0
    // 0x80015964: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_29;
    // 0x80015964: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_29:
    // 0x80015968: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x8001596C: sh          $t7, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r15;
    // 0x80015970: jal         0x800146C0
    // 0x80015974: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_30;
    // 0x80015974: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_30:
    // 0x80015978: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x8001597C: sh          $t8, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r24;
    // 0x80015980: jal         0x800146C0
    // 0x80015984: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_31;
    // 0x80015984: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_31:
    // 0x80015988: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x8001598C: b           L_800154A0
    // 0x80015990: sh          $t9, 0x16($s2)
    MEM_H(0X16, ctx->r18) = ctx->r25;
        goto L_800154A0;
    // 0x80015990: sh          $t9, 0x16($s2)
    MEM_H(0X16, ctx->r18) = ctx->r25;
L_80015994:
    // 0x80015994: jal         0x800146C0
    // 0x80015998: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_32;
    // 0x80015998: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_32:
    // 0x8001599C: sll         $t5, $v0, 5
    ctx->r13 = S32(ctx->r2 << 5);
    // 0x800159A0: sh          $t5, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r13;
    // 0x800159A4: jal         0x800146C0
    // 0x800159A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_33;
    // 0x800159A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_33:
    // 0x800159AC: sll         $t1, $v0, 5
    ctx->r9 = S32(ctx->r2 << 5);
    // 0x800159B0: sh          $t1, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r9;
    // 0x800159B4: jal         0x800146C0
    // 0x800159B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_34;
    // 0x800159B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_34:
    // 0x800159BC: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x800159C0: b           L_800154A0
    // 0x800159C4: sh          $t2, 0x14($s2)
    MEM_H(0X14, ctx->r18) = ctx->r10;
        goto L_800154A0;
    // 0x800159C4: sh          $t2, 0x14($s2)
    MEM_H(0X14, ctx->r18) = ctx->r10;
L_800159C8:
    // 0x800159C8: jal         0x800146C0
    // 0x800159CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_35;
    // 0x800159CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_35:
    // 0x800159D0: sll         $t3, $v0, 4
    ctx->r11 = S32(ctx->r2 << 4);
    // 0x800159D4: b           L_800154A0
    // 0x800159D8: sh          $t3, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r11;
        goto L_800154A0;
    // 0x800159D8: sh          $t3, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r11;
L_800159DC:
    // 0x800159DC: jal         0x800146C0
    // 0x800159E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_36;
    // 0x800159E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_36:
    // 0x800159E4: b           L_800154A0
    // 0x800159E8: sb          $v0, 0x4($s2)
    MEM_B(0X4, ctx->r18) = ctx->r2;
        goto L_800154A0;
    // 0x800159E8: sb          $v0, 0x4($s2)
    MEM_B(0X4, ctx->r18) = ctx->r2;
L_800159EC:
    // 0x800159EC: jal         0x800146C0
    // 0x800159F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_37;
    // 0x800159F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_37:
    // 0x800159F4: lbu         $t4, 0x4($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0X4);
    // 0x800159F8: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x800159FC: lw          $v1, 0x5C68($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5C68);
    // 0x80015A00: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x80015A04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80015A08: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80015A0C: lhu         $a3, 0x0($t7)
    ctx->r7 = MEM_HU(ctx->r15, 0X0);
    // 0x80015A10: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80015A14: addu        $t8, $a3, $v1
    ctx->r24 = ADD32(ctx->r7, ctx->r3);
    // 0x80015A18: lbu         $t0, 0x0($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X0);
    // 0x80015A1C: addu        $t9, $a3, $t0
    ctx->r25 = ADD32(ctx->r7, ctx->r8);
    // 0x80015A20: subu        $t5, $t9, $v0
    ctx->r13 = SUB32(ctx->r25, ctx->r2);
    // 0x80015A24: addu        $t1, $t5, $v1
    ctx->r9 = ADD32(ctx->r13, ctx->r3);
    // 0x80015A28: lbu         $s0, 0x0($t1)
    ctx->r16 = MEM_BU(ctx->r9, 0X0);
    // 0x80015A2C: jal         0x8000C990
    // 0x80015A30: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    AudioHeap_SearchCaches(rdram, ctx);
        goto after_38;
    // 0x80015A30: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_38:
    // 0x80015A34: beq         $v0, $zero, L_800154A0
    if (ctx->r2 == 0) {
        // 0x80015A38: nop
    
            goto L_800154A0;
    }
    // 0x80015A38: nop

    // 0x80015A3C: b           L_800154A0
    // 0x80015A40: sb          $s0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r16;
        goto L_800154A0;
    // 0x80015A40: sb          $s0, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r16;
L_80015A44:
    // 0x80015A44: andi        $t2, $s3, 0xFF
    ctx->r10 = ctx->r19 & 0XFF;
    // 0x80015A48: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80015A4C: jal         0x800146C0
    // 0x80015A50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_39;
    // 0x80015A50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_39:
    // 0x80015A54: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x80015A58: jal         0x800146D4
    // 0x80015A5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_40;
    // 0x80015A5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_40:
    // 0x80015A60: lw          $t3, 0x18($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X18);
    // 0x80015A64: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80015A68: andi        $t4, $v0, 0xFFFF
    ctx->r12 = ctx->r2 & 0XFFFF;
    // 0x80015A6C: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x80015A70: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80015A74: b           L_800154A0
    // 0x80015A78: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
        goto L_800154A0;
    // 0x80015A78: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_80015A7C:
    // 0x80015A7C: jal         0x800146C0
    // 0x80015A80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_41;
    // 0x80015A80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_41:
    // 0x80015A84: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80015A88: bne         $s0, $at, L_80015AA0
    if (ctx->r16 != ctx->r1) {
        // 0x80015A8C: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_80015AA0;
    }
    // 0x80015A8C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80015A90: subu        $s3, $s3, $v0
    ctx->r19 = SUB32(ctx->r19, ctx->r2);
    // 0x80015A94: sll         $t5, $s3, 24
    ctx->r13 = S32(ctx->r19 << 24);
    // 0x80015A98: b           L_800154A0
    // 0x80015A9C: sra         $s3, $t5, 24
    ctx->r19 = S32(SIGNED(ctx->r13) >> 24);
        goto L_800154A0;
    // 0x80015A9C: sra         $s3, $t5, 24
    ctx->r19 = S32(SIGNED(ctx->r13) >> 24);
L_80015AA0:
    // 0x80015AA0: addiu       $at, $zero, 0xCC
    ctx->r1 = ADD32(0, 0XCC);
    // 0x80015AA4: bne         $v1, $at, L_80015ABC
    if (ctx->r3 != ctx->r1) {
        // 0x80015AA8: and         $s3, $s3, $v0
        ctx->r19 = ctx->r19 & ctx->r2;
            goto L_80015ABC;
    }
    // 0x80015AA8: and         $s3, $s3, $v0
    ctx->r19 = ctx->r19 & ctx->r2;
    // 0x80015AAC: sll         $s3, $v0, 24
    ctx->r19 = S32(ctx->r2 << 24);
    // 0x80015AB0: sra         $t2, $s3, 24
    ctx->r10 = S32(SIGNED(ctx->r19) >> 24);
    // 0x80015AB4: b           L_800154A0
    // 0x80015AB8: or          $s3, $t2, $zero
    ctx->r19 = ctx->r10 | 0;
        goto L_800154A0;
    // 0x80015AB8: or          $s3, $t2, $zero
    ctx->r19 = ctx->r10 | 0;
L_80015ABC:
    // 0x80015ABC: sll         $t6, $s3, 24
    ctx->r14 = S32(ctx->r19 << 24);
    // 0x80015AC0: b           L_800154A0
    // 0x80015AC4: sra         $s3, $t6, 24
    ctx->r19 = S32(SIGNED(ctx->r14) >> 24);
        goto L_800154A0;
    // 0x80015AC4: sra         $s3, $t6, 24
    ctx->r19 = S32(SIGNED(ctx->r14) >> 24);
L_80015AC8:
    // 0x80015AC8: jal         0x800146C0
    // 0x80015ACC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_42;
    // 0x80015ACC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_42:
    // 0x80015AD0: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80015AD4: addu        $t9, $s4, $t8
    ctx->r25 = ADD32(ctx->r20, ctx->r24);
    // 0x80015AD8: jal         0x8001415C
    // 0x80015ADC: lw          $a0, 0x34($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X34);
    AudioSeq_SequenceChannelDisable(rdram, ctx);
        goto after_43;
    // 0x80015ADC: lw          $a0, 0x34($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X34);
    after_43:
    // 0x80015AE0: b           L_800154A0
    // 0x80015AE4: nop

        goto L_800154A0;
    // 0x80015AE4: nop

L_80015AE8:
    // 0x80015AE8: jal         0x800146C0
    // 0x80015AEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_44;
    // 0x80015AEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_44:
    // 0x80015AF0: b           L_800154A0
    // 0x80015AF4: sb          $v0, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r2;
        goto L_800154A0;
    // 0x80015AF4: sb          $v0, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r2;
L_80015AF8:
    // 0x80015AF8: jal         0x800146D4
    // 0x80015AFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_45;
    // 0x80015AFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_45:
    // 0x80015B00: lw          $t5, 0x18($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X18);
    // 0x80015B04: andi        $t1, $v0, 0xFFFF
    ctx->r9 = ctx->r2 & 0XFFFF;
    // 0x80015B08: addu        $t2, $t1, $s3
    ctx->r10 = ADD32(ctx->r9, ctx->r19);
    // 0x80015B0C: addu        $t3, $t5, $t2
    ctx->r11 = ADD32(ctx->r13, ctx->r10);
    // 0x80015B10: b           L_800154A0
    // 0x80015B14: lb          $s3, 0x0($t3)
    ctx->r19 = MEM_B(ctx->r11, 0X0);
        goto L_800154A0;
    // 0x80015B14: lb          $s3, 0x0($t3)
    ctx->r19 = MEM_B(ctx->r11, 0X0);
L_80015B18:
    // 0x80015B18: jal         0x800146D4
    // 0x80015B1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_46;
    // 0x80015B1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_46:
    // 0x80015B20: b           L_800154A0
    // 0x80015B24: sh          $v0, 0xC4($s2)
    MEM_H(0XC4, ctx->r18) = ctx->r2;
        goto L_800154A0;
    // 0x80015B24: sh          $v0, 0xC4($s2)
    MEM_H(0XC4, ctx->r18) = ctx->r2;
L_80015B28:
    // 0x80015B28: jal         0x800146D4
    // 0x80015B2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_47;
    // 0x80015B2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_47:
    // 0x80015B30: lw          $t4, 0x18($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X18);
    // 0x80015B34: lhu         $t7, 0xC4($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0XC4);
    // 0x80015B38: andi        $t6, $v0, 0xFFFF
    ctx->r14 = ctx->r2 & 0XFFFF;
    // 0x80015B3C: addu        $v1, $t4, $t6
    ctx->r3 = ADD32(ctx->r12, ctx->r14);
    // 0x80015B40: sra         $t9, $t7, 8
    ctx->r25 = S32(SIGNED(ctx->r15) >> 8);
    // 0x80015B44: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x80015B48: lhu         $t5, 0xC4($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0XC4);
    // 0x80015B4C: b           L_800154A0
    // 0x80015B50: sb          $t5, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r13;
        goto L_800154A0;
    // 0x80015B50: sb          $t5, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r13;
L_80015B54:
    // 0x80015B54: jal         0x800146C0
    // 0x80015B58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_48;
    // 0x80015B58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_48:
    // 0x80015B5C: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x80015B60: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80015B64: andi        $t4, $t3, 0x4
    ctx->r12 = ctx->r11 & 0X4;
    // 0x80015B68: andi        $t7, $t6, 0xFFFB
    ctx->r15 = ctx->r14 & 0XFFFB;
    // 0x80015B6C: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x80015B70: b           L_800154A0
    // 0x80015B74: sb          $t8, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r24;
        goto L_800154A0;
    // 0x80015B74: sb          $t8, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r24;
L_80015B78:
    // 0x80015B78: jal         0x800146C0
    // 0x80015B7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_49;
    // 0x80015B7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_49:
    // 0x80015B80: b           L_800154A0
    // 0x80015B84: sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
        goto L_800154A0;
    // 0x80015B84: sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
L_80015B88:
    // 0x80015B88: jal         0x800146C0
    // 0x80015B8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_50;
    // 0x80015B8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_50:
    // 0x80015B90: b           L_800154A0
    // 0x80015B94: sb          $v0, 0x75($s2)
    MEM_B(0X75, ctx->r18) = ctx->r2;
        goto L_800154A0;
    // 0x80015B94: sb          $v0, 0x75($s2)
    MEM_B(0X75, ctx->r18) = ctx->r2;
L_80015B98:
    // 0x80015B98: jal         0x800146C0
    // 0x80015B9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_51;
    // 0x80015B9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_51:
    // 0x80015BA0: b           L_800154A0
    // 0x80015BA4: sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
        goto L_800154A0;
    // 0x80015BA4: sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
L_80015BA8:
    // 0x80015BA8: beq         $s3, $s5, L_800154A0
    if (ctx->r19 == ctx->r21) {
        // 0x80015BAC: nop
    
            goto L_800154A0;
    }
    // 0x80015BAC: nop

    // 0x80015BB0: lbu         $a0, 0x18($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X18);
    // 0x80015BB4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80015BB8: lw          $t9, 0x34($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X34);
    // 0x80015BBC: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x80015BC0: addu        $t2, $s1, $t5
    ctx->r10 = ADD32(ctx->r17, ctx->r13);
    // 0x80015BC4: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x80015BC8: lbu         $t3, 0x18($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X18);
    // 0x80015BCC: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
    // 0x80015BD0: addu        $v1, $t9, $v0
    ctx->r3 = ADD32(ctx->r25, ctx->r2);
    // 0x80015BD4: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x80015BD8: sb          $t6, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r14;
    // 0x80015BDC: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x80015BE0: lbu         $t4, 0x1($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X1);
    // 0x80015BE4: lw          $t5, 0x18($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X18);
    // 0x80015BE8: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x80015BEC: addu        $a3, $t4, $t8
    ctx->r7 = ADD32(ctx->r12, ctx->r24);
    // 0x80015BF0: andi        $t9, $a3, 0xFFFF
    ctx->r25 = ctx->r7 & 0XFFFF;
    // 0x80015BF4: addu        $t1, $t5, $t9
    ctx->r9 = ADD32(ctx->r13, ctx->r25);
    // 0x80015BF8: b           L_800154A0
    // 0x80015BFC: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
        goto L_800154A0;
    // 0x80015BFC: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
L_80015C00:
    // 0x80015C00: jal         0x800146C0
    // 0x80015C04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_52;
    // 0x80015C04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_52:
    // 0x80015C08: b           L_800154A0
    // 0x80015C0C: sb          $v0, 0x8($s2)
    MEM_B(0X8, ctx->r18) = ctx->r2;
        goto L_800154A0;
    // 0x80015C0C: sb          $v0, 0x8($s2)
    MEM_B(0X8, ctx->r18) = ctx->r2;
L_80015C10:
    // 0x80015C10: jal         0x800146D4
    // 0x80015C14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_53;
    // 0x80015C14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_53:
    // 0x80015C18: lw          $t2, 0x18($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X18);
    // 0x80015C1C: andi        $t3, $v0, 0xFFFF
    ctx->r11 = ctx->r2 & 0XFFFF;
    // 0x80015C20: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x80015C24: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80015C28: addiu       $v1, $v1, 0x7
    ctx->r3 = ADD32(ctx->r3, 0X7);
    // 0x80015C2C: sb          $t6, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r14;
    // 0x80015C30: lbu         $t7, -0x6($v1)
    ctx->r15 = MEM_BU(ctx->r3, -0X6);
    // 0x80015C34: lbu         $t6, 0x1($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X1);
    // 0x80015C38: sb          $t7, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r15;
    // 0x80015C3C: lbu         $t4, -0x5($v1)
    ctx->r12 = MEM_BU(ctx->r3, -0X5);
    // 0x80015C40: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x80015C44: sb          $t4, 0x5($s2)
    MEM_B(0X5, ctx->r18) = ctx->r12;
    // 0x80015C48: lb          $t8, -0x4($v1)
    ctx->r24 = MEM_B(ctx->r3, -0X4);
    // 0x80015C4C: sh          $t8, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = ctx->r24;
    // 0x80015C50: lbu         $t9, -0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, -0X3);
    // 0x80015C54: sb          $t9, 0x9($s2)
    MEM_B(0X9, ctx->r18) = ctx->r25;
    // 0x80015C58: lbu         $t5, -0x2($v1)
    ctx->r13 = MEM_BU(ctx->r3, -0X2);
    // 0x80015C5C: sb          $t5, 0xA($s2)
    MEM_B(0XA, ctx->r18) = ctx->r13;
    // 0x80015C60: lbu         $t1, -0x1($v1)
    ctx->r9 = MEM_BU(ctx->r3, -0X1);
    // 0x80015C64: sb          $t1, 0x4($s2)
    MEM_B(0X4, ctx->r18) = ctx->r9;
    // 0x80015C68: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x80015C6C: sb          $t7, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r15;
    // 0x80015C70: b           L_800154A0
    // 0x80015C74: sb          $t2, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r10;
        goto L_800154A0;
    // 0x80015C74: sb          $t2, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r10;
L_80015C78:
    // 0x80015C78: jal         0x800146C0
    // 0x80015C7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_54;
    // 0x80015C7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_54:
    // 0x80015C80: sb          $v0, 0x3($s2)
    MEM_B(0X3, ctx->r18) = ctx->r2;
    // 0x80015C84: jal         0x800146C0
    // 0x80015C88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_55;
    // 0x80015C88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_55:
    // 0x80015C8C: sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // 0x80015C90: jal         0x800146C0
    // 0x80015C94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_56;
    // 0x80015C94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_56:
    // 0x80015C98: sb          $v0, 0x5($s2)
    MEM_B(0X5, ctx->r18) = ctx->r2;
    // 0x80015C9C: jal         0x800146C0
    // 0x80015CA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_57;
    // 0x80015CA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_57:
    // 0x80015CA4: sll         $t4, $v0, 24
    ctx->r12 = S32(ctx->r2 << 24);
    // 0x80015CA8: sra         $t8, $t4, 24
    ctx->r24 = S32(SIGNED(ctx->r12) >> 24);
    // 0x80015CAC: sh          $t8, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = ctx->r24;
    // 0x80015CB0: jal         0x800146C0
    // 0x80015CB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_58;
    // 0x80015CB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_58:
    // 0x80015CB8: sb          $v0, 0x9($s2)
    MEM_B(0X9, ctx->r18) = ctx->r2;
    // 0x80015CBC: jal         0x800146C0
    // 0x80015CC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_59;
    // 0x80015CC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_59:
    // 0x80015CC4: sb          $v0, 0xA($s2)
    MEM_B(0XA, ctx->r18) = ctx->r2;
    // 0x80015CC8: jal         0x800146C0
    // 0x80015CCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_60;
    // 0x80015CCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_60:
    // 0x80015CD0: sb          $v0, 0x4($s2)
    MEM_B(0X4, ctx->r18) = ctx->r2;
    // 0x80015CD4: jal         0x800146C0
    // 0x80015CD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_61;
    // 0x80015CD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_61:
    // 0x80015CDC: lbu         $t5, 0x1($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X1);
    // 0x80015CE0: sb          $v0, 0x7($s2)
    MEM_B(0X7, ctx->r18) = ctx->r2;
    // 0x80015CE4: ori         $t1, $t5, 0x20
    ctx->r9 = ctx->r13 | 0X20;
    // 0x80015CE8: b           L_800154A0
    // 0x80015CEC: sb          $t1, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r9;
        goto L_800154A0;
    // 0x80015CEC: sb          $t1, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r9;
L_80015CF0:
    // 0x80015CF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80015CF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80015CF8: sh          $zero, 0x12($s2)
    MEM_H(0X12, ctx->r18) = 0;
    // 0x80015CFC: sh          $zero, 0xE($s2)
    MEM_H(0XE, ctx->r18) = 0;
    // 0x80015D00: sh          $zero, 0x16($s2)
    MEM_H(0X16, ctx->r18) = 0;
    // 0x80015D04: sh          $zero, 0x10($s2)
    MEM_H(0X10, ctx->r18) = 0;
    // 0x80015D08: sh          $zero, 0xC($s2)
    MEM_H(0XC, ctx->r18) = 0;
    // 0x80015D0C: sh          $zero, 0x14($s2)
    MEM_H(0X14, ctx->r18) = 0;
    // 0x80015D10: b           L_800154A0
    // 0x80015D14: swc1        $f16, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f16.u32l;
        goto L_800154A0;
    // 0x80015D14: swc1        $f16, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f16.u32l;
L_80015D18:
    // 0x80015D18: jal         0x800146C0
    // 0x80015D1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_62;
    // 0x80015D1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_62:
    // 0x80015D20: b           L_800154A0
    // 0x80015D24: sb          $v0, 0x5($s2)
    MEM_B(0X5, ctx->r18) = ctx->r2;
        goto L_800154A0;
    // 0x80015D24: sb          $v0, 0x5($s2)
    MEM_B(0X5, ctx->r18) = ctx->r2;
L_80015D28:
    // 0x80015D28: jal         0x800146C0
    // 0x80015D2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_63;
    // 0x80015D2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_63:
    // 0x80015D30: b           L_800154A0
    // 0x80015D34: sb          $v0, 0xB($s2)
    MEM_B(0XB, ctx->r18) = ctx->r2;
        goto L_800154A0;
    // 0x80015D34: sb          $v0, 0xB($s2)
    MEM_B(0XB, ctx->r18) = ctx->r2;
L_80015D38:
    // 0x80015D38: jal         0x800146D4
    // 0x80015D3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_64;
    // 0x80015D3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_64:
    // 0x80015D40: jal         0x800146C0
    // 0x80015D44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_65;
    // 0x80015D44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_65:
    // 0x80015D48: b           L_800154A0
    // 0x80015D4C: nop

        goto L_800154A0;
    // 0x80015D4C: nop

L_80015D50:
    // 0x80015D50: andi        $t2, $v1, 0xF0
    ctx->r10 = ctx->r3 & 0XF0;
    // 0x80015D54: andi        $a0, $v1, 0xF
    ctx->r4 = ctx->r3 & 0XF;
    // 0x80015D58: sltiu       $at, $t2, 0xB1
    ctx->r1 = ctx->r10 < 0XB1 ? 1 : 0;
    // 0x80015D5C: beq         $at, $zero, L_800154A0
    if (ctx->r1 == 0) {
        // 0x80015D60: andi        $t0, $a0, 0xFF
        ctx->r8 = ctx->r4 & 0XFF;
            goto L_800154A0;
    }
    // 0x80015D60: andi        $t0, $a0, 0xFF
    ctx->r8 = ctx->r4 & 0XFF;
    // 0x80015D64: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80015D68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80015D6C: addu        $at, $at, $t2
    gpr jr_addend_80015D74 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80015D70: lw          $t2, -0x7760($at)
    ctx->r10 = ADD32(ctx->r1, -0X7760);
    // 0x80015D74: jr          $t2
    // 0x80015D78: nop

    switch (jr_addend_80015D74 >> 2) {
        case 0: goto L_80015D7C; break;
        case 1: goto L_800154A0; break;
        case 2: goto L_800154A0; break;
        case 3: goto L_800154A0; break;
        case 4: goto L_800154A0; break;
        case 5: goto L_800154A0; break;
        case 6: goto L_800154A0; break;
        case 7: goto L_800154A0; break;
        case 8: goto L_800154A0; break;
        case 9: goto L_800154A0; break;
        case 10: goto L_800154A0; break;
        case 11: goto L_800154A0; break;
        case 12: goto L_800154A0; break;
        case 13: goto L_800154A0; break;
        case 14: goto L_800154A0; break;
        case 15: goto L_800154A0; break;
        case 16: goto L_80015DBC; break;
        case 17: goto L_800154A0; break;
        case 18: goto L_800154A0; break;
        case 19: goto L_800154A0; break;
        case 20: goto L_800154A0; break;
        case 21: goto L_800154A0; break;
        case 22: goto L_800154A0; break;
        case 23: goto L_800154A0; break;
        case 24: goto L_800154A0; break;
        case 25: goto L_800154A0; break;
        case 26: goto L_800154A0; break;
        case 27: goto L_800154A0; break;
        case 28: goto L_800154A0; break;
        case 29: goto L_800154A0; break;
        case 30: goto L_800154A0; break;
        case 31: goto L_800154A0; break;
        case 32: goto L_80015F04; break;
        case 33: goto L_800154A0; break;
        case 34: goto L_800154A0; break;
        case 35: goto L_800154A0; break;
        case 36: goto L_800154A0; break;
        case 37: goto L_800154A0; break;
        case 38: goto L_800154A0; break;
        case 39: goto L_800154A0; break;
        case 40: goto L_800154A0; break;
        case 41: goto L_800154A0; break;
        case 42: goto L_800154A0; break;
        case 43: goto L_800154A0; break;
        case 44: goto L_800154A0; break;
        case 45: goto L_800154A0; break;
        case 46: goto L_800154A0; break;
        case 47: goto L_800154A0; break;
        case 48: goto L_80015F34; break;
        case 49: goto L_800154A0; break;
        case 50: goto L_800154A0; break;
        case 51: goto L_800154A0; break;
        case 52: goto L_800154A0; break;
        case 53: goto L_800154A0; break;
        case 54: goto L_800154A0; break;
        case 55: goto L_800154A0; break;
        case 56: goto L_800154A0; break;
        case 57: goto L_800154A0; break;
        case 58: goto L_800154A0; break;
        case 59: goto L_800154A0; break;
        case 60: goto L_800154A0; break;
        case 61: goto L_800154A0; break;
        case 62: goto L_800154A0; break;
        case 63: goto L_800154A0; break;
        case 64: goto L_80015F5C; break;
        case 65: goto L_800154A0; break;
        case 66: goto L_800154A0; break;
        case 67: goto L_800154A0; break;
        case 68: goto L_800154A0; break;
        case 69: goto L_800154A0; break;
        case 70: goto L_800154A0; break;
        case 71: goto L_800154A0; break;
        case 72: goto L_800154A0; break;
        case 73: goto L_800154A0; break;
        case 74: goto L_800154A0; break;
        case 75: goto L_800154A0; break;
        case 76: goto L_800154A0; break;
        case 77: goto L_800154A0; break;
        case 78: goto L_800154A0; break;
        case 79: goto L_800154A0; break;
        case 80: goto L_80015E14; break;
        case 81: goto L_800154A0; break;
        case 82: goto L_800154A0; break;
        case 83: goto L_800154A0; break;
        case 84: goto L_800154A0; break;
        case 85: goto L_800154A0; break;
        case 86: goto L_800154A0; break;
        case 87: goto L_800154A0; break;
        case 88: goto L_800154A0; break;
        case 89: goto L_800154A0; break;
        case 90: goto L_800154A0; break;
        case 91: goto L_800154A0; break;
        case 92: goto L_800154A0; break;
        case 93: goto L_800154A0; break;
        case 94: goto L_800154A0; break;
        case 95: goto L_800154A0; break;
        case 96: goto L_80015E30; break;
        case 97: goto L_800154A0; break;
        case 98: goto L_800154A0; break;
        case 99: goto L_800154A0; break;
        case 100: goto L_800154A0; break;
        case 101: goto L_800154A0; break;
        case 102: goto L_800154A0; break;
        case 103: goto L_800154A0; break;
        case 104: goto L_800154A0; break;
        case 105: goto L_800154A0; break;
        case 106: goto L_800154A0; break;
        case 107: goto L_800154A0; break;
        case 108: goto L_800154A0; break;
        case 109: goto L_800154A0; break;
        case 110: goto L_800154A0; break;
        case 111: goto L_800154A0; break;
        case 112: goto L_80015DE8; break;
        case 113: goto L_800154A0; break;
        case 114: goto L_800154A0; break;
        case 115: goto L_800154A0; break;
        case 116: goto L_800154A0; break;
        case 117: goto L_800154A0; break;
        case 118: goto L_800154A0; break;
        case 119: goto L_800154A0; break;
        case 120: goto L_800154A0; break;
        case 121: goto L_800154A0; break;
        case 122: goto L_800154A0; break;
        case 123: goto L_800154A0; break;
        case 124: goto L_800154A0; break;
        case 125: goto L_800154A0; break;
        case 126: goto L_800154A0; break;
        case 127: goto L_800154A0; break;
        case 128: goto L_80015DF8; break;
        case 129: goto L_800154A0; break;
        case 130: goto L_800154A0; break;
        case 131: goto L_800154A0; break;
        case 132: goto L_800154A0; break;
        case 133: goto L_800154A0; break;
        case 134: goto L_800154A0; break;
        case 135: goto L_800154A0; break;
        case 136: goto L_800154A0; break;
        case 137: goto L_800154A0; break;
        case 138: goto L_800154A0; break;
        case 139: goto L_800154A0; break;
        case 140: goto L_800154A0; break;
        case 141: goto L_800154A0; break;
        case 142: goto L_800154A0; break;
        case 143: goto L_800154A0; break;
        case 144: goto L_80015E3C; break;
        case 145: goto L_800154A0; break;
        case 146: goto L_800154A0; break;
        case 147: goto L_800154A0; break;
        case 148: goto L_800154A0; break;
        case 149: goto L_800154A0; break;
        case 150: goto L_800154A0; break;
        case 151: goto L_800154A0; break;
        case 152: goto L_800154A0; break;
        case 153: goto L_800154A0; break;
        case 154: goto L_800154A0; break;
        case 155: goto L_800154A0; break;
        case 156: goto L_800154A0; break;
        case 157: goto L_800154A0; break;
        case 158: goto L_800154A0; break;
        case 159: goto L_800154A0; break;
        case 160: goto L_80015E88; break;
        case 161: goto L_800154A0; break;
        case 162: goto L_800154A0; break;
        case 163: goto L_800154A0; break;
        case 164: goto L_800154A0; break;
        case 165: goto L_800154A0; break;
        case 166: goto L_800154A0; break;
        case 167: goto L_800154A0; break;
        case 168: goto L_800154A0; break;
        case 169: goto L_800154A0; break;
        case 170: goto L_800154A0; break;
        case 171: goto L_800154A0; break;
        case 172: goto L_800154A0; break;
        case 173: goto L_800154A0; break;
        case 174: goto L_800154A0; break;
        case 175: goto L_800154A0; break;
        case 176: goto L_80015EA4; break;
        default: switch_error(__func__, 0x80015D74, 0x800C88A0);
    }
    // 0x80015D78: nop

L_80015D7C:
    // 0x80015D7C: andi        $t3, $a0, 0xFF
    ctx->r11 = ctx->r4 & 0XFF;
    // 0x80015D80: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x80015D84: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x80015D88: lw          $v1, 0x48($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X48);
    // 0x80015D8C: sll         $s3, $s5, 24
    ctx->r19 = S32(ctx->r21 << 24);
    // 0x80015D90: sra         $t1, $s3, 24
    ctx->r9 = S32(SIGNED(ctx->r19) >> 24);
    // 0x80015D94: beq         $v1, $zero, L_80015DB4
    if (ctx->r3 == 0) {
        // 0x80015D98: nop
    
            goto L_80015DB4;
    }
    // 0x80015D98: nop

    // 0x80015D9C: lw          $s3, 0x0($v1)
    ctx->r19 = MEM_W(ctx->r3, 0X0);
    // 0x80015DA0: sll         $t4, $s3, 1
    ctx->r12 = S32(ctx->r19 << 1);
    // 0x80015DA4: srl         $t8, $t4, 31
    ctx->r24 = S32(U32(ctx->r12) >> 31);
    // 0x80015DA8: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x80015DAC: b           L_800154A0
    // 0x80015DB0: sra         $s3, $t9, 24
    ctx->r19 = S32(SIGNED(ctx->r25) >> 24);
        goto L_800154A0;
    // 0x80015DB0: sra         $s3, $t9, 24
    ctx->r19 = S32(SIGNED(ctx->r25) >> 24);
L_80015DB4:
    // 0x80015DB4: b           L_800154A0
    // 0x80015DB8: or          $s3, $t1, $zero
    ctx->r19 = ctx->r9 | 0;
        goto L_800154A0;
    // 0x80015DB8: or          $s3, $t1, $zero
    ctx->r19 = ctx->r9 | 0;
L_80015DBC:
    // 0x80015DBC: andi        $t3, $s0, 0xF
    ctx->r11 = ctx->r16 & 0XF;
    // 0x80015DC0: addu        $v0, $s2, $t3
    ctx->r2 = ADD32(ctx->r18, ctx->r11);
    // 0x80015DC4: sb          $s5, 0xBC($v0)
    MEM_B(0XBC, ctx->r2) = ctx->r21;
    // 0x80015DC8: lbu         $a0, 0x6($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X6);
    // 0x80015DCC: addiu       $a2, $v0, 0xBC
    ctx->r6 = ADD32(ctx->r2, 0XBC);
    // 0x80015DD0: jal         0x800105EC
    // 0x80015DD4: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    AudioLoad_SlowLoadSample(rdram, ctx);
        goto after_66;
    // 0x80015DD4: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    after_66:
    // 0x80015DD8: bne         $v0, $s5, L_800154A0
    if (ctx->r2 != ctx->r21) {
        // 0x80015DDC: nop
    
            goto L_800154A0;
    }
    // 0x80015DDC: nop

    // 0x80015DE0: b           L_800154A0
    // 0x80015DE4: nop

        goto L_800154A0;
    // 0x80015DE4: nop

L_80015DE8:
    // 0x80015DE8: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80015DEC: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x80015DF0: b           L_800154A0
    // 0x80015DF4: sb          $s3, 0xBC($t7)
    MEM_B(0XBC, ctx->r15) = ctx->r19;
        goto L_800154A0;
    // 0x80015DF4: sb          $s3, 0xBC($t7)
    MEM_B(0XBC, ctx->r15) = ctx->r19;
L_80015DF8:
    // 0x80015DF8: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x80015DFC: addu        $a1, $s2, $v1
    ctx->r5 = ADD32(ctx->r18, ctx->r3);
    // 0x80015E00: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80015E04: beq         $at, $zero, L_800154A0
    if (ctx->r1 == 0) {
        // 0x80015E08: lb          $s3, 0xBC($a1)
        ctx->r19 = MEM_B(ctx->r5, 0XBC);
            goto L_800154A0;
    }
    // 0x80015E08: lb          $s3, 0xBC($a1)
    ctx->r19 = MEM_B(ctx->r5, 0XBC);
    // 0x80015E0C: b           L_800154A0
    // 0x80015E10: sb          $s5, 0xBC($a1)
    MEM_B(0XBC, ctx->r5) = ctx->r21;
        goto L_800154A0;
    // 0x80015E10: sb          $s5, 0xBC($a1)
    MEM_B(0XBC, ctx->r5) = ctx->r21;
L_80015E14:
    // 0x80015E14: andi        $t4, $a0, 0xFF
    ctx->r12 = ctx->r4 & 0XFF;
    // 0x80015E18: addu        $t8, $s2, $t4
    ctx->r24 = ADD32(ctx->r18, ctx->r12);
    // 0x80015E1C: lb          $t9, 0xBC($t8)
    ctx->r25 = MEM_B(ctx->r24, 0XBC);
    // 0x80015E20: subu        $s3, $s3, $t9
    ctx->r19 = SUB32(ctx->r19, ctx->r25);
    // 0x80015E24: sll         $t5, $s3, 24
    ctx->r13 = S32(ctx->r19 << 24);
    // 0x80015E28: b           L_800154A0
    // 0x80015E2C: sra         $s3, $t5, 24
    ctx->r19 = S32(SIGNED(ctx->r13) >> 24);
        goto L_800154A0;
    // 0x80015E2C: sra         $s3, $t5, 24
    ctx->r19 = S32(SIGNED(ctx->r13) >> 24);
L_80015E30:
    // 0x80015E30: andi        $t2, $a0, 0xFF
    ctx->r10 = ctx->r4 & 0XFF;
    // 0x80015E34: b           L_80015F84
    // 0x80015E38: sh          $t2, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r10;
        goto L_80015F84;
    // 0x80015E38: sh          $t2, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r10;
L_80015E3C:
    // 0x80015E3C: jal         0x800146D4
    // 0x80015E40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_67;
    // 0x80015E40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_67:
    // 0x80015E44: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80015E48: andi        $a1, $a2, 0xF
    ctx->r5 = ctx->r6 & 0XF;
    // 0x80015E4C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80015E50: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80015E54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80015E58: jal         0x80013FC4
    // 0x80015E5C: sh          $v0, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r2;
    AudioSeq_SeqChannelSetLayer(rdram, ctx);
        goto after_68;
    // 0x80015E5C: sh          $v0, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r2;
    after_68:
    // 0x80015E60: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80015E64: bne         $v0, $zero, L_800154A0
    if (ctx->r2 != 0) {
        // 0x80015E68: lhu         $a3, 0x52($sp)
        ctx->r7 = MEM_HU(ctx->r29, 0X52);
            goto L_800154A0;
    }
    // 0x80015E68: lhu         $a3, 0x52($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X52);
    // 0x80015E6C: lw          $t6, 0x18($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X18);
    // 0x80015E70: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x80015E74: addu        $t8, $s2, $t4
    ctx->r24 = ADD32(ctx->r18, ctx->r12);
    // 0x80015E78: lw          $t9, 0x48($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X48);
    // 0x80015E7C: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80015E80: b           L_800154A0
    // 0x80015E84: sw          $t7, 0x50($t9)
    MEM_W(0X50, ctx->r25) = ctx->r15;
        goto L_800154A0;
    // 0x80015E84: sw          $t7, 0x50($t9)
    MEM_W(0X50, ctx->r25) = ctx->r15;
L_80015E88:
    // 0x80015E88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80015E8C: andi        $t5, $a1, 0xF
    ctx->r13 = ctx->r5 & 0XF;
    // 0x80015E90: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    // 0x80015E94: jal         0x8001410C
    // 0x80015E98: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    AudioSeq_SeqLayerFree(rdram, ctx);
        goto after_69;
    // 0x80015E98: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_69:
    // 0x80015E9C: b           L_800154A0
    // 0x80015EA0: nop

        goto L_800154A0;
    // 0x80015EA0: nop

L_80015EA4:
    // 0x80015EA4: beq         $s3, $s5, L_800154A0
    if (ctx->r19 == ctx->r21) {
        // 0x80015EA8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800154A0;
    }
    // 0x80015EA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80015EAC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80015EB0: andi        $a1, $a2, 0xF
    ctx->r5 = ctx->r6 & 0XF;
    // 0x80015EB4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80015EB8: jal         0x80013FC4
    // 0x80015EBC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    AudioSeq_SeqChannelSetLayer(rdram, ctx);
        goto after_70;
    // 0x80015EBC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_70:
    // 0x80015EC0: beq         $v0, $s5, L_800154A0
    if (ctx->r2 == ctx->r21) {
        // 0x80015EC4: lw          $a2, 0x34($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X34);
            goto L_800154A0;
    }
    // 0x80015EC4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80015EC8: lw          $t2, 0x34($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X34);
    // 0x80015ECC: sll         $t3, $s3, 1
    ctx->r11 = S32(ctx->r19 << 1);
    // 0x80015ED0: lw          $t9, 0x18($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X18);
    // 0x80015ED4: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x80015ED8: lbu         $t4, 0x0($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X0);
    // 0x80015EDC: lbu         $t6, 0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1);
    // 0x80015EE0: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x80015EE4: sll         $t8, $t4, 8
    ctx->r24 = S32(ctx->r12 << 8);
    // 0x80015EE8: addu        $t2, $s2, $t1
    ctx->r10 = ADD32(ctx->r18, ctx->r9);
    // 0x80015EEC: addu        $a3, $t6, $t8
    ctx->r7 = ADD32(ctx->r14, ctx->r24);
    // 0x80015EF0: lw          $t3, 0x48($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X48);
    // 0x80015EF4: andi        $t7, $a3, 0xFFFF
    ctx->r15 = ctx->r7 & 0XFFFF;
    // 0x80015EF8: addu        $t5, $t9, $t7
    ctx->r13 = ADD32(ctx->r25, ctx->r15);
    // 0x80015EFC: b           L_800154A0
    // 0x80015F00: sw          $t5, 0x50($t3)
    MEM_W(0X50, ctx->r11) = ctx->r13;
        goto L_800154A0;
    // 0x80015F00: sw          $t5, 0x50($t3)
    MEM_W(0X50, ctx->r11) = ctx->r13;
L_80015F04:
    // 0x80015F04: jal         0x800146D4
    // 0x80015F08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_71;
    // 0x80015F08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_71:
    // 0x80015F0C: lw          $t6, 0x18($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X18);
    // 0x80015F10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80015F14: andi        $t4, $a1, 0xF
    ctx->r12 = ctx->r5 & 0XF;
    // 0x80015F18: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x80015F1C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x80015F20: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80015F24: jal         0x80014440
    // 0x80015F28: addu        $a2, $t6, $t8
    ctx->r6 = ADD32(ctx->r14, ctx->r24);
    AudioSeq_SequenceChannelEnable(rdram, ctx);
        goto after_72;
    // 0x80015F28: addu        $a2, $t6, $t8
    ctx->r6 = ADD32(ctx->r14, ctx->r24);
    after_72:
    // 0x80015F2C: b           L_800154A0
    // 0x80015F30: nop

        goto L_800154A0;
    // 0x80015F30: nop

L_80015F34:
    // 0x80015F34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80015F38: jal         0x800146C0
    // 0x80015F3C: sb          $t0, 0x55($sp)
    MEM_B(0X55, ctx->r29) = ctx->r8;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_73;
    // 0x80015F3C: sb          $t0, 0x55($sp)
    MEM_B(0X55, ctx->r29) = ctx->r8;
    after_73:
    // 0x80015F40: lbu         $t0, 0x55($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X55);
    // 0x80015F44: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80015F48: addu        $t9, $s4, $t7
    ctx->r25 = ADD32(ctx->r20, ctx->r15);
    // 0x80015F4C: lw          $t1, 0x34($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X34);
    // 0x80015F50: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80015F54: b           L_800154A0
    // 0x80015F58: sb          $s3, 0xBC($t2)
    MEM_B(0XBC, ctx->r10) = ctx->r19;
        goto L_800154A0;
    // 0x80015F58: sb          $s3, 0xBC($t2)
    MEM_B(0XBC, ctx->r10) = ctx->r19;
L_80015F5C:
    // 0x80015F5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80015F60: jal         0x800146C0
    // 0x80015F64: sb          $t0, 0x55($sp)
    MEM_B(0X55, ctx->r29) = ctx->r8;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_74;
    // 0x80015F64: sb          $t0, 0x55($sp)
    MEM_B(0X55, ctx->r29) = ctx->r8;
    after_74:
    // 0x80015F68: lbu         $t0, 0x55($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X55);
    // 0x80015F6C: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x80015F70: addu        $t3, $s4, $t5
    ctx->r11 = ADD32(ctx->r20, ctx->r13);
    // 0x80015F74: lw          $t4, 0x34($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X34);
    // 0x80015F78: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x80015F7C: b           L_800154A0
    // 0x80015F80: lb          $s3, 0xBC($t6)
    ctx->r19 = MEM_B(ctx->r14, 0XBC);
        goto L_800154A0;
    // 0x80015F80: lb          $s3, 0xBC($t6)
    ctx->r19 = MEM_B(ctx->r14, 0XBC);
L_80015F84:
    // 0x80015F84: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_80015F88:
    // 0x80015F88: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
    // 0x80015F8C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80015F90:
    // 0x80015F90: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80015F94: beql        $a0, $zero, L_80015FA8
    if (ctx->r4 == 0) {
        // 0x80015F98: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80015FA8;
    }
    goto skip_6;
    // 0x80015F98: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_6:
    // 0x80015F9C: jal         0x80014748
    // 0x80015FA0: nop

    AudioSeq_SeqLayerProcessScript(rdram, ctx);
        goto after_75;
    // 0x80015FA0: nop

    after_75:
    // 0x80015FA4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80015FA8:
    // 0x80015FA8: bne         $s0, $s2, L_80015F90
    if (ctx->r16 != ctx->r18) {
        // 0x80015FAC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80015F90;
    }
    // 0x80015FAC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80015FB0:
    // 0x80015FB0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80015FB4:
    // 0x80015FB4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80015FB8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80015FBC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80015FC0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80015FC4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80015FC8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80015FCC: jr          $ra
    // 0x80015FD0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80015FD0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void ActorDebris_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C008: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8006C00C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8006C010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006C014: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006C018: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x8006C01C: addiu       $t6, $v0, -0x28
    ctx->r14 = ADD32(ctx->r2, -0X28);
    // 0x8006C020: sltiu       $at, $t6, 0x13
    ctx->r1 = ctx->r14 < 0X13 ? 1 : 0;
    // 0x8006C024: beq         $at, $zero, L_8006CAD8
    if (ctx->r1 == 0) {
        // 0x8006C028: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8006CAD8;
    }
    // 0x8006C028: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8006C02C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C030: addu        $at, $at, $t6
    gpr jr_addend_8006C038 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8006C034: lw          $t6, 0x6AB0($at)
    ctx->r14 = ADD32(ctx->r1, 0X6AB0);
    // 0x8006C038: jr          $t6
    // 0x8006C03C: nop

    switch (jr_addend_8006C038 >> 2) {
        case 0: goto L_8006C040; break;
        case 1: goto L_8006CAD8; break;
        case 2: goto L_8006CAD8; break;
        case 3: goto L_8006CAD8; break;
        case 4: goto L_8006CAD8; break;
        case 5: goto L_8006C2CC; break;
        case 6: goto L_8006C2F0; break;
        case 7: goto L_8006C3B8; break;
        case 8: goto L_8006C504; break;
        case 9: goto L_8006C504; break;
        case 10: goto L_8006C904; break;
        case 11: goto L_8006C504; break;
        case 12: goto L_8006C504; break;
        case 13: goto L_8006C504; break;
        case 14: goto L_8006C80C; break;
        case 15: goto L_8006C504; break;
        case 16: goto L_8006C5C4; break;
        case 17: goto L_8006C9D0; break;
        case 18: goto L_8006C6AC; break;
        default: switch_error(__func__, 0x8006C038, 0x800D6AB0);
    }
    // 0x8006C03C: nop

L_8006C040:
    // 0x8006C040: lh          $v0, 0x4A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4A);
    // 0x8006C044: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8006C048: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x8006C04C: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x8006C050: beql        $t7, $zero, L_8006C088
    if (ctx->r15 == 0) {
        // 0x8006C054: lwc1        $f4, 0x10($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
            goto L_8006C088;
    }
    goto skip_0;
    // 0x8006C054: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    skip_0:
    // 0x8006C058: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8006C05C: lwc1        $f4, 0x120($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8006C060: lwc1        $f10, 0x124($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X124);
    // 0x8006C064: lwc1        $f6, 0x74($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X74);
    // 0x8006C068: lh          $v0, 0x4A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4A);
    // 0x8006C06C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006C070: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x8006C074: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8006C078: lwc1        $f16, 0x138($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X138);
    // 0x8006C07C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006C080: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8006C084: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
L_8006C088:
    // 0x8006C088: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8006C08C: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006C090: lwc1        $f16, 0x118($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8006C094: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006C098: lwc1        $f6, 0x11C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x8006C09C: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006C0A0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006C0A4: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x8006C0A8: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x8006C0AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006C0B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006C0B4: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x8006C0B8: bne         $t0, $at, L_8006C0E4
    if (ctx->r8 != ctx->r1) {
        // 0x8006C0BC: swc1        $f8, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
            goto L_8006C0E4;
    }
    // 0x8006C0BC: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x8006C0C0: lhu         $t1, 0xBC($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XBC);
    // 0x8006C0C4: andi        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 & 0X3;
    // 0x8006C0C8: bnel        $t2, $zero, L_8006C0E8
    if (ctx->r10 != 0) {
        // 0x8006C0CC: lwc1        $f10, 0x128($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X128);
            goto L_8006C0E8;
    }
    goto skip_1;
    // 0x8006C0CC: lwc1        $f10, 0x128($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X128);
    skip_1:
    // 0x8006C0D0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006C0D4: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006C0D8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006C0DC: jal         0x8007D0E0
    // 0x8006C0E0: lw          $a3, 0x110($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X110);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_0;
    // 0x8006C0E0: lw          $a3, 0x110($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X110);
    after_0:
L_8006C0E4:
    // 0x8006C0E4: lwc1        $f10, 0x128($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X128);
L_8006C0E8:
    // 0x8006C0E8: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006C0EC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8006C0F0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006C0F4: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x8006C0F8: nop

    // 0x8006C0FC: bc1fl       L_8006D0E4
    if (!c1cs) {
        // 0x8006C100: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_2;
    // 0x8006C100: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x8006C104: lw          $t3, 0x50($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X50);
    // 0x8006C108: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x8006C10C: bnel        $at, $zero, L_8006C138
    if (ctx->r1 != 0) {
        // 0x8006C110: lh          $t4, 0x4A($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X4A);
            goto L_8006C138;
    }
    goto skip_3;
    // 0x8006C110: lh          $t4, 0x4A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4A);
    skip_3:
    // 0x8006C114: swc1        $f2, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f2.u32l;
    // 0x8006C118: swc1        $f2, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f2.u32l;
    // 0x8006C11C: swc1        $f2, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f2.u32l;
    // 0x8006C120: swc1        $f2, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f2.u32l;
    // 0x8006C124: swc1        $f2, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f2.u32l;
    // 0x8006C128: swc1        $f2, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f2.u32l;
    // 0x8006C12C: b           L_8006C2BC
    // 0x8006C130: swc1        $f2, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f2.u32l;
        goto L_8006C2BC;
    // 0x8006C130: swc1        $f2, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f2.u32l;
    // 0x8006C134: lh          $t4, 0x4A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4A);
L_8006C138:
    // 0x8006C138: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x8006C13C: beq         $t5, $zero, L_8006C1CC
    if (ctx->r13 == 0) {
        // 0x8006C140: nop
    
            goto L_8006C1CC;
    }
    // 0x8006C140: nop

    // 0x8006C144: lh          $v0, 0x46($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X46);
    // 0x8006C148: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006C14C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8006C150: beq         $v0, $at, L_8006C16C
    if (ctx->r2 == ctx->r1) {
        // 0x8006C154: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_8006C16C;
    }
    // 0x8006C154: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8006C158: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8006C15C: beq         $v0, $at, L_8006C19C
    if (ctx->r2 == ctx->r1) {
        // 0x8006C160: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8006C19C;
    }
    // 0x8006C160: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8006C164: b           L_8006C1CC
    // 0x8006C168: nop

        goto L_8006C1CC;
    // 0x8006C168: nop

L_8006C16C:
    // 0x8006C16C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8006C170: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8006C174: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x8006C178: ori         $a0, $a0, 0x24
    ctx->r4 = ctx->r4 | 0X24;
    // 0x8006C17C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8006C180: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8006C184: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8006C188: jal         0x80019218
    // 0x8006C18C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8006C18C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_1:
    // 0x8006C190: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8006C194: b           L_8006C1CC
    // 0x8006C198: nop

        goto L_8006C1CC;
    // 0x8006C198: nop

L_8006C19C:
    // 0x8006C19C: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8006C1A0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8006C1A4: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8006C1A8: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x8006C1AC: ori         $a0, $a0, 0x3031
    ctx->r4 = ctx->r4 | 0X3031;
    // 0x8006C1B0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8006C1B4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8006C1B8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8006C1BC: jal         0x80019218
    // 0x8006C1C0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8006C1C0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x8006C1C4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8006C1C8: nop

L_8006C1CC:
    // 0x8006C1CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C1D0: lwc1        $f4, 0x6AFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6AFC);
    // 0x8006C1D4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8006C1D8: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8006C1DC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8006C1E0: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x8006C1E4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8006C1E8: jal         0x8009BC2C
    // 0x8006C1EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8006C1EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8006C1F0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8006C1F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C1F8: lwc1        $f6, 0x6B00($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6B00);
    // 0x8006C1FC: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8006C200: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8006C204: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8006C208: addiu       $a0, $s0, 0x118
    ctx->r4 = ADD32(ctx->r16, 0X118);
    // 0x8006C20C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8006C210: jal         0x8009BC2C
    // 0x8006C214: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x8006C214: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x8006C218: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8006C21C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C220: lwc1        $f8, 0x6B04($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6B04);
    // 0x8006C224: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8006C228: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8006C22C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8006C230: addiu       $a0, $s0, 0x11C
    ctx->r4 = ADD32(ctx->r16, 0X11C);
    // 0x8006C234: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8006C238: jal         0x8009BC2C
    // 0x8006C23C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x8006C23C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x8006C240: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8006C244: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C248: lwc1        $f10, 0x6B08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6B08);
    // 0x8006C24C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8006C250: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x8006C254: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8006C258: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8006C25C: jal         0x8009BC2C
    // 0x8006C260: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x8006C260: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x8006C264: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8006C268: lwc1        $f12, 0xEC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8006C26C: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    // 0x8006C270: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    // 0x8006C274: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8006C278: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8006C27C: sw          $t9, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r25;
    // 0x8006C280: bc1fl       L_8006C2C0
    if (!c1cs) {
        // 0x8006C284: lh          $t2, 0x4A($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X4A);
            goto L_8006C2C0;
    }
    goto skip_4;
    // 0x8006C284: lh          $t2, 0x4A($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X4A);
    skip_4:
    // 0x8006C288: lh          $t0, 0x4A($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X4A);
    // 0x8006C28C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C290: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x8006C294: beq         $t1, $zero, L_8006C2B0
    if (ctx->r9 == 0) {
        // 0x8006C298: nop
    
            goto L_8006C2B0;
    }
    // 0x8006C298: nop

    // 0x8006C29C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C2A0: lwc1        $f16, 0x6B0C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6B0C);
    // 0x8006C2A4: mul.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8006C2A8: b           L_8006C2BC
    // 0x8006C2AC: swc1        $f18, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
        goto L_8006C2BC;
    // 0x8006C2AC: swc1        $f18, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
L_8006C2B0:
    // 0x8006C2B0: lwc1        $f4, 0x6B10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6B10);
    // 0x8006C2B4: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8006C2B8: swc1        $f6, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f6.u32l;
L_8006C2BC:
    // 0x8006C2BC: lh          $t2, 0x4A($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X4A);
L_8006C2C0:
    // 0x8006C2C0: andi        $t3, $t2, 0xFFFB
    ctx->r11 = ctx->r10 & 0XFFFB;
    // 0x8006C2C4: b           L_8006D0E0
    // 0x8006C2C8: sh          $t3, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r11;
        goto L_8006D0E0;
    // 0x8006C2C8: sh          $t3, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r11;
L_8006C2CC:
    // 0x8006C2CC: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006C2D0: lwc1        $f10, 0x114($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8006C2D4: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006C2D8: lwc1        $f4, 0x118($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8006C2DC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8006C2E0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8006C2E4: swc1        $f16, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f16.u32l;
    // 0x8006C2E8: b           L_8006D0E0
    // 0x8006C2EC: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
        goto L_8006D0E0;
    // 0x8006C2EC: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
L_8006C2F0:
    // 0x8006C2F0: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006C2F4: lwc1        $f10, 0x114($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8006C2F8: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006C2FC: lwc1        $f4, 0x118($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8006C300: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8006C304: lwc1        $f10, 0x11C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x8006C308: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006C30C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8006C310: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x8006C314: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006C318: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8006C31C: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x8006C320: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006C324: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x8006C328: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    // 0x8006C32C: lwc1        $f4, 0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8006C330: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006C334: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x8006C338: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    // 0x8006C33C: jal         0x801B6E20
    // 0x8006C340: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    Ground_801B6E20(rdram, ctx);
        goto after_7;
    // 0x8006C340: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    after_7:
    // 0x8006C344: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006C348: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8006C34C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8006C350: nop

    // 0x8006C354: bc1fl       L_8006D0E4
    if (!c1cs) {
        // 0x8006C358: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_5;
    // 0x8006C358: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_5:
    // 0x8006C35C: lw          $t4, 0x58($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X58);
    // 0x8006C360: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8006C364: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8006C368: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x8006C36C: bne         $at, $zero, L_8006C39C
    if (ctx->r1 != 0) {
        // 0x8006C370: sw          $t5, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->r13;
            goto L_8006C39C;
    }
    // 0x8006C370: sw          $t5, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r13;
    // 0x8006C374: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8006C378: nop

    // 0x8006C37C: swc1        $f2, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f2.u32l;
    // 0x8006C380: swc1        $f2, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f2.u32l;
    // 0x8006C384: swc1        $f2, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f2.u32l;
    // 0x8006C388: swc1        $f2, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f2.u32l;
    // 0x8006C38C: swc1        $f2, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f2.u32l;
    // 0x8006C390: swc1        $f2, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f2.u32l;
    // 0x8006C394: b           L_8006D0E0
    // 0x8006C398: swc1        $f2, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f2.u32l;
        goto L_8006D0E0;
    // 0x8006C398: swc1        $f2, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f2.u32l;
L_8006C39C:
    // 0x8006C39C: lwc1        $f10, 0xEC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8006C3A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C3A4: lwc1        $f18, 0x6B14($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6B14);
    // 0x8006C3A8: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8006C3AC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006C3B0: b           L_8006D0E0
    // 0x8006C3B4: swc1        $f4, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f4.u32l;
        goto L_8006D0E0;
    // 0x8006C3B4: swc1        $f4, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f4.u32l;
L_8006C3B8:
    // 0x8006C3B8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006C3BC: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8006C3C0: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006C3C4: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x8006C3C8: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006C3CC: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x8006C3D0: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    // 0x8006C3D4: jal         0x801B6E20
    // 0x8006C3D8: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    Ground_801B6E20(rdram, ctx);
        goto after_8;
    // 0x8006C3D8: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    after_8:
    // 0x8006C3DC: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8006C3E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8006C3E4: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8006C3E8: lwc1        $f0, 0x120($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8006C3EC: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006C3F0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006C3F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006C3F8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8006C3FC: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8006C400: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8006C404: nop

    // 0x8006C408: bc1fl       L_8006C444
    if (!c1cs) {
        // 0x8006C40C: lwc1        $f16, 0x10($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
            goto L_8006C444;
    }
    goto skip_6;
    // 0x8006C40C: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    skip_6:
    // 0x8006C410: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8006C414: add.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8006C418: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x8006C41C: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x8006C420: swc1        $f2, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f2.u32l;
    // 0x8006C424: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8006C428: swc1        $f2, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f2.u32l;
    // 0x8006C42C: swc1        $f2, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f2.u32l;
    // 0x8006C430: swc1        $f2, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f2.u32l;
    // 0x8006C434: swc1        $f2, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f2.u32l;
    // 0x8006C438: swc1        $f2, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f2.u32l;
    // 0x8006C43C: swc1        $f2, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f2.u32l;
    // 0x8006C440: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
L_8006C444:
    // 0x8006C444: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8006C448: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006C44C: lwc1        $f18, 0x118($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8006C450: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8006C454: lwc1        $f4, 0x11C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x8006C458: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006C45C: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8006C460: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x8006C464: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x8006C468: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8006C46C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006C470: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x8006C474: bne         $v0, $t7, L_8006C4A4
    if (ctx->r2 != ctx->r15) {
        // 0x8006C478: swc1        $f10, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
            goto L_8006C4A4;
    }
    // 0x8006C478: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x8006C47C: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x8006C480: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8006C484: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x8006C488: bnel        $t9, $zero, L_8006C4A8
    if (ctx->r25 != 0) {
        // 0x8006C48C: lw          $t0, 0x58($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X58);
            goto L_8006C4A8;
    }
    goto skip_7;
    // 0x8006C48C: lw          $t0, 0x58($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X58);
    skip_7:
    // 0x8006C490: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006C494: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006C498: jal         0x8007D0E0
    // 0x8006C49C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_9;
    // 0x8006C49C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_9:
    // 0x8006C4A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006C4A4:
    // 0x8006C4A4: lw          $t0, 0x58($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X58);
L_8006C4A8:
    // 0x8006C4A8: bnel        $v0, $t0, L_8006D0E4
    if (ctx->r2 != ctx->r8) {
        // 0x8006C4AC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_8;
    // 0x8006C4AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_8:
    // 0x8006C4B0: lw          $t1, 0x54($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X54);
    // 0x8006C4B4: bnel        $v0, $t1, L_8006C4F4
    if (ctx->r2 != ctx->r9) {
        // 0x8006C4B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8006C4F4;
    }
    goto skip_9;
    // 0x8006C4B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_9:
    // 0x8006C4BC: lh          $v0, 0x48($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X48);
    // 0x8006C4C0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8006C4C4: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8006C4C8: beq         $v0, $at, L_8006C4D8
    if (ctx->r2 == ctx->r1) {
        // 0x8006C4CC: lui         $a3, 0x4100
        ctx->r7 = S32(0X4100 << 16);
            goto L_8006C4D8;
    }
    // 0x8006C4CC: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x8006C4D0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8006C4D4: bne         $v0, $at, L_8006C4F0
    if (ctx->r2 != ctx->r1) {
        // 0x8006C4D8: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8006C4F0;
    }
L_8006C4D8:
    // 0x8006C4D8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8006C4DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006C4E0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006C4E4: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006C4E8: jal         0x8007D2C8
    // 0x8006C4EC: add.s       $f14, $f6, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f18.fl;
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_10;
    // 0x8006C4EC: add.s       $f14, $f6, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f18.fl;
    after_10:
L_8006C4F0:
    // 0x8006C4F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8006C4F4:
    // 0x8006C4F4: jal         0x80060FBC
    // 0x8006C4F8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_11;
    // 0x8006C4F8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_11:
    // 0x8006C4FC: b           L_8006D0E4
    // 0x8006C500: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8006D0E4;
    // 0x8006C500: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8006C504:
    // 0x8006C504: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
    // 0x8006C508: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8006C50C: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    // 0x8006C510: beq         $t2, $zero, L_8006C554
    if (ctx->r10 == 0) {
        // 0x8006C514: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_8006C554;
    }
    // 0x8006C514: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8006C518: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x8006C51C: jal         0x8006351C
    // 0x8006C520: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Object_CheckCollision(rdram, ctx);
        goto after_12;
    // 0x8006C520: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_12:
    // 0x8006C524: bne         $v0, $zero, L_8006C554
    if (ctx->r2 != 0) {
        // 0x8006C528: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_8006C554;
    }
    // 0x8006C528: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8006C52C: addiu       $v1, $v1, 0x7940
    ctx->r3 = ADD32(ctx->r3, 0X7940);
    // 0x8006C530: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006C534: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006C538: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8006C53C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006C540: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8006C544: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8006C548: nop

    // 0x8006C54C: bc1fl       L_8006D0E4
    if (!c1cs) {
        // 0x8006C550: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_10;
    // 0x8006C550: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_10:
L_8006C554:
    // 0x8006C554: lhu         $t3, 0xBE($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XBE);
    // 0x8006C558: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8006C55C: bnel        $t3, $zero, L_8006D0E4
    if (ctx->r11 != 0) {
        // 0x8006C560: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_11;
    // 0x8006C560: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_11:
    // 0x8006C564: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006C568: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006C56C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006C570: lwc1        $f4, 0x110($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X110);
    // 0x8006C574: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006C578: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006C57C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8006C580: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8006C584: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006C588: addiu       $t4, $s0, 0x4
    ctx->r12 = ADD32(ctx->r16, 0X4);
    // 0x8006C58C: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x8006C590: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8006C594: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8006C598: jal         0x8007B8F8
    // 0x8006C59C: nop

    Effect_Effect364_Spawn(rdram, ctx);
        goto after_13;
    // 0x8006C59C: nop

    after_13:
    // 0x8006C5A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006C5A4: jal         0x80060FBC
    // 0x8006C5A8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_14;
    // 0x8006C5A8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_14:
    // 0x8006C5AC: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x8006C5B0: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    // 0x8006C5B4: jal         0x8007A6F0
    // 0x8006C5B8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_15;
    // 0x8006C5B8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_15:
    // 0x8006C5BC: b           L_8006D0E4
    // 0x8006C5C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8006D0E4;
    // 0x8006C5C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8006C5C4:
    // 0x8006C5C4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8006C5C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C5CC: lwc1        $f6, 0x6B18($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6B18);
    // 0x8006C5D0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8006C5D4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8006C5D8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8006C5DC: addiu       $a0, $s0, 0x110
    ctx->r4 = ADD32(ctx->r16, 0X110);
    // 0x8006C5E0: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8006C5E4: jal         0x8009BC2C
    // 0x8006C5E8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x8006C5E8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_16:
    // 0x8006C5EC: lhu         $t5, 0xBC($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0XBC);
    // 0x8006C5F0: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8006C5F4: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    // 0x8006C5F8: beq         $t5, $zero, L_8006C63C
    if (ctx->r13 == 0) {
        // 0x8006C5FC: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_8006C63C;
    }
    // 0x8006C5FC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8006C600: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x8006C604: jal         0x8006351C
    // 0x8006C608: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Object_CheckCollision(rdram, ctx);
        goto after_17;
    // 0x8006C608: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_17:
    // 0x8006C60C: bne         $v0, $zero, L_8006C63C
    if (ctx->r2 != 0) {
        // 0x8006C610: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_8006C63C;
    }
    // 0x8006C610: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8006C614: addiu       $v1, $v1, 0x7940
    ctx->r3 = ADD32(ctx->r3, 0X7940);
    // 0x8006C618: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006C61C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006C620: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8006C624: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006C628: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8006C62C: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x8006C630: nop

    // 0x8006C634: bc1fl       L_8006D0E4
    if (!c1cs) {
        // 0x8006C638: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_12;
    // 0x8006C638: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_12:
L_8006C63C:
    // 0x8006C63C: lhu         $t6, 0xBE($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XBE);
    // 0x8006C640: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8006C644: bnel        $t6, $zero, L_8006D0E4
    if (ctx->r14 != 0) {
        // 0x8006C648: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_13;
    // 0x8006C648: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_13:
    // 0x8006C64C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006C650: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006C654: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006C658: lwc1        $f4, 0x110($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X110);
    // 0x8006C65C: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006C660: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006C664: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8006C668: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8006C66C: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006C670: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x8006C674: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8006C678: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8006C67C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8006C680: jal         0x8007B8F8
    // 0x8006C684: nop

    Effect_Effect364_Spawn(rdram, ctx);
        goto after_18;
    // 0x8006C684: nop

    after_18:
    // 0x8006C688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006C68C: jal         0x80060FBC
    // 0x8006C690: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_19;
    // 0x8006C690: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_19:
    // 0x8006C694: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x8006C698: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    // 0x8006C69C: jal         0x8007A6F0
    // 0x8006C6A0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_20;
    // 0x8006C6A0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_20:
    // 0x8006C6A4: b           L_8006D0E4
    // 0x8006C6A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8006D0E4;
    // 0x8006C6A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8006C6AC:
    // 0x8006C6AC: lh          $v1, 0x46($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X46);
    // 0x8006C6B0: bne         $v1, $zero, L_8006C71C
    if (ctx->r3 != 0) {
        // 0x8006C6B4: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_8006C71C;
    }
    // 0x8006C6B4: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8006C6B8: jal         0x80004EB0
    // 0x8006C6BC: sh          $t8, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r24;
    Rand_ZeroOne(rdram, ctx);
        goto after_21;
    // 0x8006C6BC: sh          $t8, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r24;
    after_21:
    // 0x8006C6C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006C6C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006C6C8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8006C6CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8006C6D0: sub.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8006C6D4: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8006C6D8: jal         0x80004EB0
    // 0x8006C6DC: swc1        $f4, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_22;
    // 0x8006C6DC: swc1        $f4, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f4.u32l;
    after_22:
    // 0x8006C6E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006C6E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006C6E8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8006C6EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006C6F0: sub.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8006C6F4: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8006C6F8: jal         0x80004EB0
    // 0x8006C6FC: swc1        $f6, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_23;
    // 0x8006C6FC: swc1        $f6, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f6.u32l;
    after_23:
    // 0x8006C700: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006C704: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8006C708: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8006C70C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006C710: sub.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8006C714: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8006C718: swc1        $f8, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f8.u32l;
L_8006C71C:
    // 0x8006C71C: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006C720: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8006C724: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006C728: lwc1        $f18, 0x118($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8006C72C: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8006C730: lwc1        $f6, 0x11C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x8006C734: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006C738: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8006C73C: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x8006C740: lhu         $t9, 0xBC($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XBC);
    // 0x8006C744: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8006C748: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x8006C74C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8006C750: beq         $t9, $zero, L_8006C79C
    if (ctx->r25 == 0) {
        // 0x8006C754: swc1        $f16, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
            goto L_8006C79C;
    }
    // 0x8006C754: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    // 0x8006C758: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8006C75C: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    // 0x8006C760: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x8006C764: jal         0x8006351C
    // 0x8006C768: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Object_CheckCollision(rdram, ctx);
        goto after_24;
    // 0x8006C768: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_24:
    // 0x8006C76C: bne         $v0, $zero, L_8006C79C
    if (ctx->r2 != 0) {
        // 0x8006C770: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_8006C79C;
    }
    // 0x8006C770: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8006C774: addiu       $v1, $v1, 0x7940
    ctx->r3 = ADD32(ctx->r3, 0X7940);
    // 0x8006C778: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006C77C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006C780: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8006C784: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006C788: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8006C78C: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8006C790: nop

    // 0x8006C794: bc1fl       L_8006D0E4
    if (!c1cs) {
        // 0x8006C798: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_14;
    // 0x8006C798: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_14:
L_8006C79C:
    // 0x8006C79C: lhu         $t0, 0xBE($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XBE);
    // 0x8006C7A0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8006C7A4: bnel        $t0, $zero, L_8006D0E4
    if (ctx->r8 != 0) {
        // 0x8006C7A8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_15;
    // 0x8006C7A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_15:
    // 0x8006C7AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8006C7B0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006C7B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006C7B8: lwc1        $f8, 0x110($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X110);
    // 0x8006C7BC: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006C7C0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006C7C4: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8006C7C8: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8006C7CC: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006C7D0: addiu       $t1, $s0, 0x4
    ctx->r9 = ADD32(ctx->r16, 0X4);
    // 0x8006C7D4: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x8006C7D8: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8006C7DC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8006C7E0: jal         0x8007B8F8
    // 0x8006C7E4: nop

    Effect_Effect364_Spawn(rdram, ctx);
        goto after_25;
    // 0x8006C7E4: nop

    after_25:
    // 0x8006C7E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006C7EC: jal         0x80060FBC
    // 0x8006C7F0: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_26;
    // 0x8006C7F0: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_26:
    // 0x8006C7F4: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x8006C7F8: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    // 0x8006C7FC: jal         0x8007A6F0
    // 0x8006C800: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_27;
    // 0x8006C800: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_27:
    // 0x8006C804: b           L_8006D0E4
    // 0x8006C808: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8006D0E4;
    // 0x8006C808: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8006C80C:
    // 0x8006C80C: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
    // 0x8006C810: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8006C814: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    // 0x8006C818: beq         $t2, $zero, L_8006C85C
    if (ctx->r10 == 0) {
        // 0x8006C81C: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_8006C85C;
    }
    // 0x8006C81C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8006C820: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x8006C824: jal         0x8006351C
    // 0x8006C828: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Object_CheckCollision(rdram, ctx);
        goto after_28;
    // 0x8006C828: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_28:
    // 0x8006C82C: bne         $v0, $zero, L_8006C85C
    if (ctx->r2 != 0) {
        // 0x8006C830: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_8006C85C;
    }
    // 0x8006C830: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8006C834: addiu       $v1, $v1, 0x7940
    ctx->r3 = ADD32(ctx->r3, 0X7940);
    // 0x8006C838: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006C83C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006C840: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8006C844: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006C848: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006C84C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8006C850: nop

    // 0x8006C854: bc1fl       L_8006D0E4
    if (!c1cs) {
        // 0x8006C858: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_16;
    // 0x8006C858: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_16:
L_8006C85C:
    // 0x8006C85C: lhu         $t3, 0xBE($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XBE);
    // 0x8006C860: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8006C864: bnel        $t3, $zero, L_8006D0E4
    if (ctx->r11 != 0) {
        // 0x8006C868: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_17;
    // 0x8006C868: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_17:
    // 0x8006C86C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006C870: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8006C874: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006C878: lwc1        $f18, 0x110($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X110);
    // 0x8006C87C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006C880: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006C884: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8006C888: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8006C88C: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006C890: addiu       $t4, $s0, 0x4
    ctx->r12 = ADD32(ctx->r16, 0X4);
    // 0x8006C894: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x8006C898: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8006C89C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8006C8A0: jal         0x8007B8F8
    // 0x8006C8A4: nop

    Effect_Effect364_Spawn(rdram, ctx);
        goto after_29;
    // 0x8006C8A4: nop

    after_29:
    // 0x8006C8A8: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8006C8AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006C8B0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8006C8B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006C8B8: lwc1        $f18, 0x110($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X110);
    // 0x8006C8BC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006C8C0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006C8C4: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8006C8C8: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8006C8CC: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006C8D0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8006C8D4: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8006C8D8: jal         0x8007B8F8
    // 0x8006C8DC: nop

    Effect_Effect364_Spawn(rdram, ctx);
        goto after_30;
    // 0x8006C8DC: nop

    after_30:
    // 0x8006C8E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006C8E4: jal         0x80060FBC
    // 0x8006C8E8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_31;
    // 0x8006C8E8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_31:
    // 0x8006C8EC: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x8006C8F0: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    // 0x8006C8F4: jal         0x8007A6F0
    // 0x8006C8F8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_32;
    // 0x8006C8F8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_32:
    // 0x8006C8FC: b           L_8006D0E4
    // 0x8006C900: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8006D0E4;
    // 0x8006C900: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8006C904:
    // 0x8006C904: lw          $t5, 0x50($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X50);
    // 0x8006C908: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006C90C: bnel        $t5, $at, L_8006C940
    if (ctx->r13 != ctx->r1) {
        // 0x8006C910: lwc1        $f4, 0x10($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
            goto L_8006C940;
    }
    goto skip_18;
    // 0x8006C910: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    skip_18:
    // 0x8006C914: lhu         $t6, 0xBC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XBC);
    // 0x8006C918: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8006C91C: bnel        $t6, $zero, L_8006C940
    if (ctx->r14 != 0) {
        // 0x8006C920: lwc1        $f4, 0x10($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
            goto L_8006C940;
    }
    goto skip_19;
    // 0x8006C920: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    skip_19:
    // 0x8006C924: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006C928: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006C92C: jal         0x8007D2C8
    // 0x8006C930: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_33;
    // 0x8006C930: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_33:
    // 0x8006C934: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8006C938: sh          $t7, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r15;
    // 0x8006C93C: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
L_8006C940:
    // 0x8006C940: lwc1        $f10, 0x114($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8006C944: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006C948: lwc1        $f6, 0x118($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8006C94C: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8006C950: lwc1        $f10, 0x11C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x8006C954: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006C958: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8006C95C: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x8006C960: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8006C964: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8006C968: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x8006C96C: addiu       $a2, $a2, -0x60D4
    ctx->r6 = ADD32(ctx->r6, -0X60D4);
    // 0x8006C970: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x8006C974: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    // 0x8006C978: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8006C97C: jal         0x8006351C
    // 0x8006C980: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Object_CheckCollision(rdram, ctx);
        goto after_34;
    // 0x8006C980: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_34:
    // 0x8006C984: beq         $v0, $zero, L_8006C9A0
    if (ctx->r2 == 0) {
        // 0x8006C988: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_8006C9A0;
    }
    // 0x8006C988: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8006C98C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006C990: lwc1        $f6, 0x6B1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6B1C);
    // 0x8006C994: lwc1        $f18, 0xE8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8006C998: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8006C99C: swc1        $f8, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f8.u32l;
L_8006C9A0:
    // 0x8006C9A0: addiu       $v1, $v1, 0x7940
    ctx->r3 = ADD32(ctx->r3, 0X7940);
    // 0x8006C9A4: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8006C9A8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006C9AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006C9B0: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8006C9B4: nop

    // 0x8006C9B8: bc1fl       L_8006D0E4
    if (!c1cs) {
        // 0x8006C9BC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_20;
    // 0x8006C9BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_20:
    // 0x8006C9C0: jal         0x80060FBC
    // 0x8006C9C4: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_35;
    // 0x8006C9C4: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_35:
    // 0x8006C9C8: b           L_8006D0E4
    // 0x8006C9CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8006D0E4;
    // 0x8006C9CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8006C9D0:
    // 0x8006C9D0: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006C9D4: lwc1        $f18, 0x114($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8006C9D8: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006C9DC: lwc1        $f4, 0x118($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8006C9E0: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006C9E4: lwc1        $f18, 0x11C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x8006C9E8: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006C9EC: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8006C9F0: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x8006C9F4: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8006C9F8: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006C9FC: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x8006CA00: addiu       $a2, $a2, -0x60D4
    ctx->r6 = ADD32(ctx->r6, -0X60D4);
    // 0x8006CA04: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x8006CA08: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x8006CA0C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8006CA10: jal         0x8006351C
    // 0x8006CA14: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Object_CheckCollision(rdram, ctx);
        goto after_36;
    // 0x8006CA14: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_36:
    // 0x8006CA18: beq         $v0, $zero, L_8006CA34
    if (ctx->r2 == 0) {
        // 0x8006CA1C: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_8006CA34;
    }
    // 0x8006CA1C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8006CA20: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CA24: lwc1        $f4, 0x6B20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6B20);
    // 0x8006CA28: lwc1        $f8, 0xE8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8006CA2C: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8006CA30: swc1        $f10, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f10.u32l;
L_8006CA34:
    // 0x8006CA34: addiu       $v1, $v1, 0x7940
    ctx->r3 = ADD32(ctx->r3, 0X7940);
    // 0x8006CA38: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8006CA3C: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006CA40: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8006CA44: nop

    // 0x8006CA48: bc1fl       L_8006D0E4
    if (!c1cs) {
        // 0x8006CA4C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_21;
    // 0x8006CA4C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_21:
    // 0x8006CA50: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x8006CA54: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8006CA58: bne         $at, $zero, L_8006CA80
    if (ctx->r1 != 0) {
        // 0x8006CA5C: addiu       $t8, $v0, 0x1
        ctx->r24 = ADD32(ctx->r2, 0X1);
            goto L_8006CA80;
    }
    // 0x8006CA5C: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8006CA60: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8006CA64: nop

    // 0x8006CA68: swc1        $f2, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f2.u32l;
    // 0x8006CA6C: swc1        $f2, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f2.u32l;
    // 0x8006CA70: swc1        $f2, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f2.u32l;
    // 0x8006CA74: swc1        $f2, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f2.u32l;
    // 0x8006CA78: b           L_8006D0E0
    // 0x8006CA7C: swc1        $f2, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f2.u32l;
        goto L_8006D0E0;
    // 0x8006CA7C: swc1        $f2, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f2.u32l;
L_8006CA80:
    // 0x8006CA80: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006CA84: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006CA88: lwc1        $f6, 0xEC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8006CA8C: sw          $t8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r24;
    // 0x8006CA90: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CA94: lwc1        $f4, 0x6B24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6B24);
    // 0x8006CA98: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8006CA9C: lwc1        $f18, 0x114($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8006CAA0: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8006CAA4: lwc1        $f8, 0x118($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8006CAA8: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8006CAAC: nop

    // 0x8006CAB0: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8006CAB4: swc1        $f10, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f10.u32l;
    // 0x8006CAB8: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8006CABC: lwc1        $f10, 0x11C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x8006CAC0: swc1        $f6, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f6.u32l;
    // 0x8006CAC4: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x8006CAC8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8006CACC: swc1        $f4, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f4.u32l;
    // 0x8006CAD0: b           L_8006D0E0
    // 0x8006CAD4: swc1        $f16, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f16.u32l;
        goto L_8006D0E0;
    // 0x8006CAD4: swc1        $f16, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f16.u32l;
L_8006CAD8:
    // 0x8006CAD8: lh          $v1, 0x46($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X46);
    // 0x8006CADC: bne         $v1, $zero, L_8006CB4C
    if (ctx->r3 != 0) {
        // 0x8006CAE0: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_8006CB4C;
    }
    // 0x8006CAE0: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x8006CAE4: jal         0x80004EB0
    // 0x8006CAE8: sh          $t9, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r25;
    Rand_ZeroOne(rdram, ctx);
        goto after_37;
    // 0x8006CAE8: sh          $t9, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r25;
    after_37:
    // 0x8006CAEC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006CAF0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006CAF4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8006CAF8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006CAFC: sub.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8006CB00: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8006CB04: jal         0x80004EB0
    // 0x8006CB08: swc1        $f4, 0x13C($s0)
    MEM_W(0X13C, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_38;
    // 0x8006CB08: swc1        $f4, 0x13C($s0)
    MEM_W(0X13C, ctx->r16) = ctx->f4.u32l;
    after_38:
    // 0x8006CB0C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006CB10: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006CB14: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8006CB18: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006CB1C: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8006CB20: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006CB24: jal         0x80004EB0
    // 0x8006CB28: swc1        $f6, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_39;
    // 0x8006CB28: swc1        $f6, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f6.u32l;
    after_39:
    // 0x8006CB2C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006CB30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006CB34: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8006CB38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006CB3C: sub.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8006CB40: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x8006CB44: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8006CB48: swc1        $f16, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f16.u32l;
L_8006CB4C:
    // 0x8006CB4C: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006CB50: lwc1        $f6, 0x13C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X13C);
    // 0x8006CB54: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006CB58: lwc1        $f10, 0x140($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X140);
    // 0x8006CB5C: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8006CB60: lwc1        $f6, 0x144($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X144);
    // 0x8006CB64: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006CB68: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8006CB6C: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x8006CB70: addiu       $at, $zero, 0x46
    ctx->r1 = ADD32(0, 0X46);
    // 0x8006CB74: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8006CB78: swc1        $f16, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f16.u32l;
    // 0x8006CB7C: bne         $v0, $at, L_8006CBE4
    if (ctx->r2 != ctx->r1) {
        // 0x8006CB80: swc1        $f8, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
            goto L_8006CBE4;
    }
    // 0x8006CB80: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x8006CB84: lhu         $t0, 0xBC($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XBC);
    // 0x8006CB88: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8006CB8C: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    // 0x8006CB90: beq         $t0, $zero, L_8006CBD0
    if (ctx->r8 == 0) {
        // 0x8006CB94: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_8006CBD0;
    }
    // 0x8006CB94: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8006CB98: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x8006CB9C: jal         0x8006351C
    // 0x8006CBA0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Object_CheckCollision(rdram, ctx);
        goto after_40;
    // 0x8006CBA0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_40:
    // 0x8006CBA4: bne         $v0, $zero, L_8006CBD0
    if (ctx->r2 != 0) {
        // 0x8006CBA8: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_8006CBD0;
    }
    // 0x8006CBA8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8006CBAC: addiu       $v1, $v1, 0x7940
    ctx->r3 = ADD32(ctx->r3, 0X7940);
    // 0x8006CBB0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006CBB4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8006CBB8: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8006CBBC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006CBC0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006CBC4: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x8006CBC8: nop

    // 0x8006CBCC: bc1f        L_8006D0E0
    if (!c1cs) {
        // 0x8006CBD0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8006D0E0;
    }
L_8006CBD0:
    // 0x8006CBD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006CBD4: jal         0x80060FBC
    // 0x8006CBD8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_41;
    // 0x8006CBD8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_41:
    // 0x8006CBDC: b           L_8006D0E4
    // 0x8006CBE0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8006D0E4;
    // 0x8006CBE0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8006CBE4:
    // 0x8006CBE4: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x8006CBE8: bnel        $v0, $at, L_8006CC90
    if (ctx->r2 != ctx->r1) {
        // 0x8006CBEC: slti        $at, $v0, 0x29
        ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
            goto L_8006CC90;
    }
    goto skip_22;
    // 0x8006CBEC: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    skip_22:
    // 0x8006CBF0: lhu         $t1, 0xBC($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XBC);
    // 0x8006CBF4: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8006CBF8: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    // 0x8006CBFC: beq         $t1, $zero, L_8006CC40
    if (ctx->r9 == 0) {
        // 0x8006CC00: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_8006CC40;
    }
    // 0x8006CC00: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8006CC04: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x8006CC08: jal         0x8006351C
    // 0x8006CC0C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Object_CheckCollision(rdram, ctx);
        goto after_42;
    // 0x8006CC0C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_42:
    // 0x8006CC10: bne         $v0, $zero, L_8006CC40
    if (ctx->r2 != 0) {
        // 0x8006CC14: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_8006CC40;
    }
    // 0x8006CC14: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8006CC18: addiu       $v1, $v1, 0x7940
    ctx->r3 = ADD32(ctx->r3, 0X7940);
    // 0x8006CC1C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006CC20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006CC24: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8006CC28: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006CC2C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8006CC30: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x8006CC34: nop

    // 0x8006CC38: bc1fl       L_8006D0E4
    if (!c1cs) {
        // 0x8006CC3C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_23;
    // 0x8006CC3C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_23:
L_8006CC40:
    // 0x8006CC40: lhu         $t2, 0xBE($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBE);
    // 0x8006CC44: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8006CC48: addiu       $t3, $s0, 0x4
    ctx->r11 = ADD32(ctx->r16, 0X4);
    // 0x8006CC4C: bnel        $t2, $zero, L_8006D0E4
    if (ctx->r10 != 0) {
        // 0x8006CC50: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_24;
    // 0x8006CC50: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_24:
    // 0x8006CC54: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006CC58: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006CC5C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006CC60: jal         0x8007D0E0
    // 0x8006CC64: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_43;
    // 0x8006CC64: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    after_43:
    // 0x8006CC68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006CC6C: jal         0x80060FBC
    // 0x8006CC70: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_44;
    // 0x8006CC70: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_44:
    // 0x8006CC74: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x8006CC78: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    // 0x8006CC7C: jal         0x8007A6F0
    // 0x8006CC80: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_45;
    // 0x8006CC80: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_45:
    // 0x8006CC84: b           L_8006D0E4
    // 0x8006CC88: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8006D0E4;
    // 0x8006CC88: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006CC8C: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
L_8006CC90:
    // 0x8006CC90: bne         $at, $zero, L_8006CC9C
    if (ctx->r1 != 0) {
        // 0x8006CC94: slti        $at, $v0, 0x2D
        ctx->r1 = SIGNED(ctx->r2) < 0X2D ? 1 : 0;
            goto L_8006CC9C;
    }
    // 0x8006CC94: slti        $at, $v0, 0x2D
    ctx->r1 = SIGNED(ctx->r2) < 0X2D ? 1 : 0;
    // 0x8006CC98: bne         $at, $zero, L_8006CCA8
    if (ctx->r1 != 0) {
        // 0x8006CC9C: addiu       $at, $zero, 0x3B
        ctx->r1 = ADD32(0, 0X3B);
            goto L_8006CCA8;
    }
L_8006CC9C:
    // 0x8006CC9C: addiu       $at, $zero, 0x3B
    ctx->r1 = ADD32(0, 0X3B);
    // 0x8006CCA0: bnel        $v0, $at, L_8006CD74
    if (ctx->r2 != ctx->r1) {
        // 0x8006CCA4: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_8006CD74;
    }
    goto skip_25;
    // 0x8006CCA4: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    skip_25:
L_8006CCA8:
    // 0x8006CCA8: lhu         $t4, 0xBC($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XBC);
    // 0x8006CCAC: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8006CCB0: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    // 0x8006CCB4: beq         $t4, $zero, L_8006CCD0
    if (ctx->r12 == 0) {
        // 0x8006CCB8: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_8006CCD0;
    }
    // 0x8006CCB8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8006CCBC: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x8006CCC0: jal         0x8006351C
    // 0x8006CCC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Object_CheckCollision(rdram, ctx);
        goto after_46;
    // 0x8006CCC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_46:
    // 0x8006CCC8: beql        $v0, $zero, L_8006CD24
    if (ctx->r2 == 0) {
        // 0x8006CCCC: lwc1        $f18, 0xC($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
            goto L_8006CD24;
    }
    goto skip_26;
    // 0x8006CCCC: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    skip_26:
L_8006CCD0:
    // 0x8006CCD0: lhu         $t5, 0xBE($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0XBE);
    // 0x8006CCD4: bnel        $t5, $zero, L_8006CD24
    if (ctx->r13 != 0) {
        // 0x8006CCD8: lwc1        $f18, 0xC($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
            goto L_8006CD24;
    }
    goto skip_27;
    // 0x8006CCD8: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    skip_27:
    // 0x8006CCDC: lwc1        $f0, 0x110($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X110);
    // 0x8006CCE0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006CCE4: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006CCE8: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8006CCEC: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006CCF0: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
    // 0x8006CCF4: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8006CCF8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8006CCFC: jal         0x8007D0E0
    // 0x8006CD00: nop

    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_47;
    // 0x8006CD00: nop

    after_47:
    // 0x8006CD04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006CD08: jal         0x80060FBC
    // 0x8006CD0C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_48;
    // 0x8006CD0C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_48:
    // 0x8006CD10: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x8006CD14: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    // 0x8006CD18: jal         0x8007A6F0
    // 0x8006CD1C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_49;
    // 0x8006CD1C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_49:
    // 0x8006CD20: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
L_8006CD24:
    // 0x8006CD24: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8006CD28: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8006CD2C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8006CD30: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8006CD34: jal         0x800A73E4
    // 0x8006CD38: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Play_CheckDynaFloorCollision(rdram, ctx);
        goto after_50;
    // 0x8006CD38: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_50:
    // 0x8006CD3C: beq         $v0, $zero, L_8006D0E0
    if (ctx->r2 == 0) {
        // 0x8006CD40: lwc1        $f14, 0x44($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
            goto L_8006D0E0;
    }
    // 0x8006CD40: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8006CD44: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006CD48: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006CD4C: addiu       $t7, $s0, 0x100
    ctx->r15 = ADD32(ctx->r16, 0X100);
    // 0x8006CD50: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8006CD54: jal         0x8007B228
    // 0x8006CD58: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    Effect_Effect381_Spawn(rdram, ctx);
        goto after_51;
    // 0x8006CD58: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_51:
    // 0x8006CD5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006CD60: jal         0x80060FBC
    // 0x8006CD64: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    Object_Kill(rdram, ctx);
        goto after_52;
    // 0x8006CD64: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_52:
    // 0x8006CD68: b           L_8006D0E4
    // 0x8006CD6C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8006D0E4;
    // 0x8006CD6C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006CD70: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
L_8006CD74:
    // 0x8006CD74: bnel        $at, $zero, L_8006CE6C
    if (ctx->r1 != 0) {
        // 0x8006CD78: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8006CE6C;
    }
    goto skip_28;
    // 0x8006CD78: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_28:
    // 0x8006CD7C: lhu         $v0, 0xBC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XBC);
    // 0x8006CD80: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x8006CD84: bne         $t8, $zero, L_8006CDA4
    if (ctx->r24 != 0) {
        // 0x8006CD88: nop
    
            goto L_8006CDA4;
    }
    // 0x8006CD88: nop

    // 0x8006CD8C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006CD90: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006CD94: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006CD98: jal         0x8007D0E0
    // 0x8006CD9C: lw          $a3, 0x110($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X110);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_53;
    // 0x8006CD9C: lw          $a3, 0x110($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X110);
    after_53:
    // 0x8006CDA0: lhu         $v0, 0xBC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XBC);
L_8006CDA4:
    // 0x8006CDA4: beq         $v0, $zero, L_8006CDF0
    if (ctx->r2 == 0) {
        // 0x8006CDA8: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_8006CDF0;
    }
    // 0x8006CDA8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8006CDAC: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8006CDB0: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    // 0x8006CDB4: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x8006CDB8: jal         0x8006351C
    // 0x8006CDBC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Object_CheckCollision(rdram, ctx);
        goto after_54;
    // 0x8006CDBC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_54:
    // 0x8006CDC0: bne         $v0, $zero, L_8006CDF0
    if (ctx->r2 != 0) {
        // 0x8006CDC4: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_8006CDF0;
    }
    // 0x8006CDC4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8006CDC8: addiu       $v1, $v1, 0x7940
    ctx->r3 = ADD32(ctx->r3, 0X7940);
    // 0x8006CDCC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006CDD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006CDD4: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8006CDD8: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006CDDC: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8006CDE0: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x8006CDE4: nop

    // 0x8006CDE8: bc1fl       L_8006D0E4
    if (!c1cs) {
        // 0x8006CDEC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_29;
    // 0x8006CDEC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_29:
L_8006CDF0:
    // 0x8006CDF0: lhu         $t9, 0xBE($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XBE);
    // 0x8006CDF4: bnel        $t9, $zero, L_8006D0E4
    if (ctx->r25 != 0) {
        // 0x8006CDF8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_30;
    // 0x8006CDF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_30:
    // 0x8006CDFC: lwc1        $f4, 0xEC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8006CE00: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006CE04: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006CE08: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006CE0C: lw          $a3, 0xE8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XE8);
    // 0x8006CE10: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8006CE14: lwc1        $f18, 0xF0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8006CE18: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8006CE1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006CE20: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8006CE24: lwc1        $f10, 0x110($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X110);
    // 0x8006CE28: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8006CE2C: addiu       $t1, $s0, 0x4
    ctx->r9 = ADD32(ctx->r16, 0X4);
    // 0x8006CE30: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8006CE34: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x8006CE38: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8006CE3C: jal         0x8007BFFC
    // 0x8006CE40: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_55;
    // 0x8006CE40: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_55:
    // 0x8006CE44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006CE48: jal         0x80060FBC
    // 0x8006CE4C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_56;
    // 0x8006CE4C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_56:
    // 0x8006CE50: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x8006CE54: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    // 0x8006CE58: jal         0x8007A6F0
    // 0x8006CE5C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_57;
    // 0x8006CE5C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_57:
    // 0x8006CE60: b           L_8006D0E4
    // 0x8006CE64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8006D0E4;
    // 0x8006CE64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006CE68: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8006CE6C:
    // 0x8006CE6C: bne         $v0, $at, L_8006CE98
    if (ctx->r2 != ctx->r1) {
        // 0x8006CE70: nop
    
            goto L_8006CE98;
    }
    // 0x8006CE70: nop

    // 0x8006CE74: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
    // 0x8006CE78: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x8006CE7C: andi        $t3, $t2, 0x7
    ctx->r11 = ctx->r10 & 0X7;
    // 0x8006CE80: bne         $t3, $zero, L_8006CE98
    if (ctx->r11 != 0) {
        // 0x8006CE84: nop
    
            goto L_8006CE98;
    }
    // 0x8006CE84: nop

    // 0x8006CE88: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006CE8C: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006CE90: jal         0x8007D0E0
    // 0x8006CE94: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_58;
    // 0x8006CE94: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_58:
L_8006CE98:
    // 0x8006CE98: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8006CE9C: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    // 0x8006CEA0: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x8006CEA4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8006CEA8: jal         0x8006351C
    // 0x8006CEAC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Object_CheckCollision(rdram, ctx);
        goto after_59;
    // 0x8006CEAC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_59:
    // 0x8006CEB0: bne         $v0, $zero, L_8006CEDC
    if (ctx->r2 != 0) {
        // 0x8006CEB4: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_8006CEDC;
    }
    // 0x8006CEB4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8006CEB8: addiu       $v1, $v1, 0x7940
    ctx->r3 = ADD32(ctx->r3, 0X7940);
    // 0x8006CEBC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006CEC0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006CEC4: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8006CEC8: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006CECC: add.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8006CED0: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x8006CED4: nop

    // 0x8006CED8: bc1f        L_8006D04C
    if (!c1cs) {
        // 0x8006CEDC: lui         $t4, 0x8017
        ctx->r12 = S32(0X8017 << 16);
            goto L_8006D04C;
    }
L_8006CEDC:
    // 0x8006CEDC: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8006CEE0: lbu         $t4, 0x7C98($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X7C98);
    // 0x8006CEE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006CEE8: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006CEEC: bne         $t4, $at, L_8006CF14
    if (ctx->r12 != ctx->r1) {
        // 0x8006CEF0: lui         $a3, 0x4000
        ctx->r7 = S32(0X4000 << 16);
            goto L_8006CF14;
    }
    // 0x8006CEF0: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8006CEF4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006CEF8: jal         0x8007D0E0
    // 0x8006CEFC: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_60;
    // 0x8006CEFC: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_60:
    // 0x8006CF00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006CF04: jal         0x80060FBC
    // 0x8006CF08: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_61;
    // 0x8006CF08: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_61:
    // 0x8006CF0C: b           L_8006D0E4
    // 0x8006CF10: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8006D0E4;
    // 0x8006CF10: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8006CF14:
    // 0x8006CF14: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006CF18: lwc1        $f8, 0x6B28($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6B28);
    // 0x8006CF1C: lwc1        $f6, 0xEC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8006CF20: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8006CF24: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8006CF28: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8006CF2C: lw          $t5, 0x50($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X50);
    // 0x8006CF30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006CF34: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8006CF38: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8006CF3C: sw          $t6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r14;
    // 0x8006CF40: swc1        $f4, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f4.u32l;
    // 0x8006CF44: lwc1        $f18, 0xEC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8006CF48: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8006CF4C: add.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x8006CF50: bne         $at, $zero, L_8006CF60
    if (ctx->r1 != 0) {
        // 0x8006CF54: swc1        $f6, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
            goto L_8006CF60;
    }
    // 0x8006CF54: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8006CF58: jal         0x80060FBC
    // 0x8006CF5C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_62;
    // 0x8006CF5C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_62:
L_8006CF60:
    // 0x8006CF60: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x8006CF64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006CF68: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8006CF6C: beq         $v0, $at, L_8006CF94
    if (ctx->r2 == ctx->r1) {
        // 0x8006CF70: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8006CF94;
    }
    // 0x8006CF70: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006CF74: beq         $v0, $at, L_8006CF94
    if (ctx->r2 == ctx->r1) {
        // 0x8006CF78: nop
    
            goto L_8006CF94;
    }
    // 0x8006CF78: nop

    // 0x8006CF7C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006CF80: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006CF84: jal         0x8006BF7C
    // 0x8006CF88: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    func_enmy2_8006BF7C(rdram, ctx);
        goto after_63;
    // 0x8006CF88: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_63:
    // 0x8006CF8C: b           L_8006D050
    // 0x8006CF90: lh          $t9, 0xB8($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XB8);
        goto L_8006D050;
    // 0x8006CF90: lh          $t9, 0xB8($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XB8);
L_8006CF94:
    // 0x8006CF94: lw          $t8, -0x7DCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DCC);
    // 0x8006CF98: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8006CF9C: bnel        $t8, $at, L_8006D050
    if (ctx->r24 != ctx->r1) {
        // 0x8006CFA0: lh          $t9, 0xB8($s0)
        ctx->r25 = MEM_H(ctx->r16, 0XB8);
            goto L_8006D050;
    }
    goto skip_31;
    // 0x8006CFA0: lh          $t9, 0xB8($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XB8);
    skip_31:
    // 0x8006CFA4: jal         0x80004EB0
    // 0x8006CFA8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_64;
    // 0x8006CFA8: nop

    after_64:
    // 0x8006CFAC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006CFB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006CFB4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006CFB8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006CFBC: sub.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8006CFC0: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006CFC4: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006CFC8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006CFCC: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8006CFD0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8006CFD4: jal         0x8007BC7C
    // 0x8006CFD8: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    Effect_Effect362_Spawn(rdram, ctx);
        goto after_65;
    // 0x8006CFD8: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    after_65:
    // 0x8006CFDC: jal         0x80004EB0
    // 0x8006CFE0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_66;
    // 0x8006CFE0: nop

    after_66:
    // 0x8006CFE4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006CFE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006CFEC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006CFF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006CFF4: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8006CFF8: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006CFFC: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006D000: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006D004: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8006D008: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8006D00C: jal         0x8007BC7C
    // 0x8006D010: add.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f16.fl;
    Effect_Effect362_Spawn(rdram, ctx);
        goto after_67;
    // 0x8006D010: add.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f16.fl;
    after_67:
    // 0x8006D014: jal         0x80004EB0
    // 0x8006D018: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_68;
    // 0x8006D018: nop

    after_68:
    // 0x8006D01C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006D020: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006D024: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006D028: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006D02C: sub.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8006D030: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006D034: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006D038: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006D03C: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8006D040: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8006D044: jal         0x8007BC7C
    // 0x8006D048: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
    Effect_Effect362_Spawn(rdram, ctx);
        goto after_69;
    // 0x8006D048: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
    after_69:
L_8006D04C:
    // 0x8006D04C: lh          $t9, 0xB8($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XB8);
L_8006D050:
    // 0x8006D050: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006D054: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8006D058: bnel        $t9, $at, L_8006D094
    if (ctx->r25 != ctx->r1) {
        // 0x8006D05C: lhu         $t2, 0xBC($s0)
        ctx->r10 = MEM_HU(ctx->r16, 0XBC);
            goto L_8006D094;
    }
    goto skip_32;
    // 0x8006D05C: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
    skip_32:
    // 0x8006D060: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x8006D064: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8006D068: bnel        $t0, $at, L_8006D0E4
    if (ctx->r8 != ctx->r1) {
        // 0x8006D06C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_33;
    // 0x8006D06C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_33:
    // 0x8006D070: lhu         $t1, 0xBC($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XBC);
    // 0x8006D074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006D078: bnel        $t1, $zero, L_8006D0E4
    if (ctx->r9 != 0) {
        // 0x8006D07C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_34;
    // 0x8006D07C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_34:
    // 0x8006D080: jal         0x80060FBC
    // 0x8006D084: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_70;
    // 0x8006D084: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_70:
    // 0x8006D088: b           L_8006D0E4
    // 0x8006D08C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8006D0E4;
    // 0x8006D08C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006D090: lhu         $t2, 0xBC($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0XBC);
L_8006D094:
    // 0x8006D094: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8006D098: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8006D09C: beq         $t3, $zero, L_8006D0B4
    if (ctx->r11 == 0) {
        // 0x8006D0A0: nop
    
            goto L_8006D0B4;
    }
    // 0x8006D0A0: nop

    // 0x8006D0A4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006D0A8: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006D0AC: jal         0x8007D24C
    // 0x8006D0B0: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    func_effect_8007D24C(rdram, ctx);
        goto after_71;
    // 0x8006D0B0: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_71:
L_8006D0B4:
    // 0x8006D0B4: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8006D0B8: lbu         $t4, 0x7C98($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X7C98);
    // 0x8006D0BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006D0C0: bnel        $t4, $at, L_8006D0E4
    if (ctx->r12 != ctx->r1) {
        // 0x8006D0C4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_35;
    // 0x8006D0C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_35:
    // 0x8006D0C8: lhu         $t5, 0xBC($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0XBC);
    // 0x8006D0CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006D0D0: bnel        $t5, $zero, L_8006D0E4
    if (ctx->r13 != 0) {
        // 0x8006D0D4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006D0E4;
    }
    goto skip_36;
    // 0x8006D0D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_36:
    // 0x8006D0D8: jal         0x80060FBC
    // 0x8006D0DC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_72;
    // 0x8006D0DC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_72:
L_8006D0E0:
    // 0x8006D0E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8006D0E4:
    // 0x8006D0E4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8006D0E8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8006D0EC: jr          $ra
    // 0x8006D0F0: nop

    return;
    // 0x8006D0F0: nop

;}
RECOMP_FUNC void ItemWingRepair_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068618: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006861C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80068620: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80068624: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80068628: jal         0x80066EF0
    // 0x8006862C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Item_CheckBounds(rdram, ctx);
        goto after_0;
    // 0x8006862C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80068630: jal         0x800671D0
    // 0x80068634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Item_SpinPickup(rdram, ctx);
        goto after_1;
    // 0x80068634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80068638: lb          $t6, 0x4C($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X4C);
    // 0x8006863C: beql        $t6, $zero, L_8006865C
    if (ctx->r14 == 0) {
        // 0x80068640: lhu         $t7, 0x48($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X48);
            goto L_8006865C;
    }
    goto skip_0;
    // 0x80068640: lhu         $t7, 0x48($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X48);
    skip_0:
    // 0x80068644: jal         0x80067A40
    // 0x80068648: nop

    Player_RepairWings(rdram, ctx);
        goto after_2;
    // 0x80068648: nop

    after_2:
    // 0x8006864C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80068650: jal         0x80060FBC
    // 0x80068654: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    Object_Kill(rdram, ctx);
        goto after_3;
    // 0x80068654: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    after_3:
    // 0x80068658: lhu         $t7, 0x48($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X48);
L_8006865C:
    // 0x8006865C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80068660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80068664: bnel        $t7, $at, L_80068678
    if (ctx->r15 != ctx->r1) {
        // 0x80068668: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80068678;
    }
    goto skip_1;
    // 0x80068668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8006866C: jal         0x80060FBC
    // 0x80068670: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    Object_Kill(rdram, ctx);
        goto after_4;
    // 0x80068670: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    after_4:
    // 0x80068674: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80068678:
    // 0x80068678: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006867C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80068680: jr          $ra
    // 0x80068684: nop

    return;
    // 0x80068684: nop

;}
RECOMP_FUNC void MeHopBot_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AD18: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006AD1C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8006AD20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006AD24: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006AD28: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8006AD2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006AD30: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8006AD34: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8006AD38: swc1        $f4, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f4.u32l;
    // 0x8006AD3C: lw          $t7, 0x78A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A0);
    // 0x8006AD40: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8006AD44: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8006AD48: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006AD4C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8006AD50: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8006AD54: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8006AD58: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x8006AD5C: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x8006AD60: lwc1        $f6, 0x74($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8006AD64: lwc1        $f10, 0x138($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X138);
    // 0x8006AD68: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006AD6C: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006AD70: sub.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8006AD74: jal         0x80005100
    // 0x8006AD78: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x8006AD78: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_0:
    // 0x8006AD7C: jal         0x8009F768
    // 0x8006AD80: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_1;
    // 0x8006AD80: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x8006AD84: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x8006AD88: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8006AD8C: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006AD90: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x8006AD94: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8006AD98: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x8006AD9C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8006ADA0: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    // 0x8006ADA4: bc1f        L_8006ADCC
    if (!c1cs) {
        // 0x8006ADA8: nop
    
            goto L_8006ADCC;
    }
    // 0x8006ADA8: nop

    // 0x8006ADAC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006ADB0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8006ADB4: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    // 0x8006ADB8: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
    // 0x8006ADBC: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
    // 0x8006ADC0: swc1        $f0, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f0.u32l;
    // 0x8006ADC4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8006ADC8: sw          $v1, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r3;
L_8006ADCC:
    // 0x8006ADCC: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x8006ADD0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006ADD4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8006ADD8: andi        $t0, $t9, 0x1F
    ctx->r8 = ctx->r25 & 0X1F;
    // 0x8006ADDC: bnel        $t0, $zero, L_8006AE34
    if (ctx->r8 != 0) {
        // 0x8006ADE0: lh          $v0, 0xB8($s0)
        ctx->r2 = MEM_H(ctx->r16, 0XB8);
            goto L_8006AE34;
    }
    goto skip_0;
    // 0x8006ADE0: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    skip_0:
    // 0x8006ADE4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006ADE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006ADEC: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8006ADF0: lhu         $t1, 0x7828($t1)
    ctx->r9 = MEM_HU(ctx->r9, 0X7828);
    // 0x8006ADF4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006ADF8: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8006ADFC: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x8006AE00: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x8006AE04: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8006AE08: bgez        $t1, L_8006AE20
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8006AE0C: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8006AE20;
    }
    // 0x8006AE0C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006AE10: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006AE14: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006AE18: nop

    // 0x8006AE1C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8006AE20:
    // 0x8006AE20: jal         0x8007F11C
    // 0x8006AE24: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Effect_ShootAtPlayer(rdram, ctx);
        goto after_2;
    // 0x8006AE24: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8006AE28: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006AE2C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8006AE30: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
L_8006AE34:
    // 0x8006AE34: beql        $v0, $zero, L_8006AE50
    if (ctx->r2 == 0) {
        // 0x8006AE38: lh          $t2, 0xB6($s0)
        ctx->r10 = MEM_H(ctx->r16, 0XB6);
            goto L_8006AE50;
    }
    goto skip_1;
    // 0x8006AE38: lh          $t2, 0xB6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XB6);
    skip_1:
    // 0x8006AE3C: beq         $v0, $v1, L_8006AEE4
    if (ctx->r2 == ctx->r3) {
        // 0x8006AE40: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8006AEE4;
    }
    // 0x8006AE40: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006AE44: b           L_8006AF54
    // 0x8006AE48: lb          $t7, 0xD0($s0)
    ctx->r15 = MEM_B(ctx->r16, 0XD0);
        goto L_8006AF54;
    // 0x8006AE48: lb          $t7, 0xD0($s0)
    ctx->r15 = MEM_B(ctx->r16, 0XD0);
    // 0x8006AE4C: lh          $t2, 0xB6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XB6);
L_8006AE50:
    // 0x8006AE50: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8006AE54: sh          $t3, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r11;
    // 0x8006AE58: lh          $v0, 0xB6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB6);
    // 0x8006AE5C: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x8006AE60: bnel        $at, $zero, L_8006AE74
    if (ctx->r1 != 0) {
        // 0x8006AE64: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_8006AE74;
    }
    goto skip_2;
    // 0x8006AE64: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    skip_2:
    // 0x8006AE68: sh          $zero, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = 0;
    // 0x8006AE6C: lh          $v0, 0xB6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB6);
    // 0x8006AE70: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
L_8006AE74:
    // 0x8006AE74: bne         $v0, $at, L_8006AF50
    if (ctx->r2 != ctx->r1) {
        // 0x8006AE78: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_8006AF50;
    }
    // 0x8006AE78: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8006AE7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006AE80: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x8006AE84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006AE88: lw          $t4, 0x50($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X50);
    // 0x8006AE8C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8006AE90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006AE94: subu        $t5, $v1, $t4
    ctx->r13 = SUB32(ctx->r3, ctx->r12);
    // 0x8006AE98: sh          $v1, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r3;
    // 0x8006AE9C: sw          $t5, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r13;
    // 0x8006AEA0: swc1        $f4, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f4.u32l;
    // 0x8006AEA4: swc1        $f6, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f6.u32l;
    // 0x8006AEA8: beq         $t5, $zero, L_8006AEC4
    if (ctx->r13 == 0) {
        // 0x8006AEAC: swc1        $f8, 0xE8($s0)
        MEM_W(0XE8, ctx->r16) = ctx->f8.u32l;
            goto L_8006AEC4;
    }
    // 0x8006AEAC: swc1        $f8, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f8.u32l;
    // 0x8006AEB0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8006AEB4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006AEB8: lwc1        $f10, 0xE8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8006AEBC: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8006AEC0: swc1        $f16, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f16.u32l;
L_8006AEC4:
    // 0x8006AEC4: lw          $t6, 0x54($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X54);
    // 0x8006AEC8: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8006AECC: beql        $t6, $zero, L_8006AF54
    if (ctx->r14 == 0) {
        // 0x8006AED0: lb          $t7, 0xD0($s0)
        ctx->r15 = MEM_B(ctx->r16, 0XD0);
            goto L_8006AF54;
    }
    goto skip_3;
    // 0x8006AED0: lb          $t7, 0xD0($s0)
    ctx->r15 = MEM_B(ctx->r16, 0XD0);
    skip_3:
    // 0x8006AED4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006AED8: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
    // 0x8006AEDC: b           L_8006AF50
    // 0x8006AEE0: swc1        $f4, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f4.u32l;
        goto L_8006AF50;
    // 0x8006AEE0: swc1        $f4, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f4.u32l;
L_8006AEE4:
    // 0x8006AEE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006AEE8: lwc1        $f8, 0xEC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8006AEEC: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8006AEF0: nop

    // 0x8006AEF4: bc1fl       L_8006AF28
    if (!c1cs) {
        // 0x8006AEF8: lh          $t2, 0xB6($s0)
        ctx->r10 = MEM_H(ctx->r16, 0XB6);
            goto L_8006AF28;
    }
    goto skip_4;
    // 0x8006AEF8: lh          $t2, 0xB6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XB6);
    skip_4:
    // 0x8006AEFC: lh          $t8, 0xB6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XB6);
    // 0x8006AF00: addiu       $t1, $zero, 0x1D
    ctx->r9 = ADD32(0, 0X1D);
    // 0x8006AF04: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8006AF08: sh          $t9, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r25;
    // 0x8006AF0C: lh          $t0, 0xB6($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XB6);
    // 0x8006AF10: slti        $at, $t0, 0x1E
    ctx->r1 = SIGNED(ctx->r8) < 0X1E ? 1 : 0;
    // 0x8006AF14: bnel        $at, $zero, L_8006AF44
    if (ctx->r1 != 0) {
        // 0x8006AF18: lw          $t5, 0x34($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X34);
            goto L_8006AF44;
    }
    goto skip_5;
    // 0x8006AF18: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    skip_5:
    // 0x8006AF1C: b           L_8006AF40
    // 0x8006AF20: sh          $t1, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r9;
        goto L_8006AF40;
    // 0x8006AF20: sh          $t1, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r9;
    // 0x8006AF24: lh          $t2, 0xB6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XB6);
L_8006AF28:
    // 0x8006AF28: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8006AF2C: sh          $t3, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r11;
    // 0x8006AF30: lh          $t4, 0xB6($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XB6);
    // 0x8006AF34: bgezl       $t4, L_8006AF44
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8006AF38: lw          $t5, 0x34($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X34);
            goto L_8006AF44;
    }
    goto skip_6;
    // 0x8006AF38: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    skip_6:
    // 0x8006AF3C: sh          $zero, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = 0;
L_8006AF40:
    // 0x8006AF40: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
L_8006AF44:
    // 0x8006AF44: beql        $t5, $zero, L_8006AF54
    if (ctx->r13 == 0) {
        // 0x8006AF48: lb          $t7, 0xD0($s0)
        ctx->r15 = MEM_B(ctx->r16, 0XD0);
            goto L_8006AF54;
    }
    goto skip_7;
    // 0x8006AF48: lb          $t7, 0xD0($s0)
    ctx->r15 = MEM_B(ctx->r16, 0XD0);
    skip_7:
    // 0x8006AF4C: sh          $zero, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = 0;
L_8006AF50:
    // 0x8006AF50: lb          $t7, 0xD0($s0)
    ctx->r15 = MEM_B(ctx->r16, 0XD0);
L_8006AF54:
    // 0x8006AF54: beql        $t7, $zero, L_8006B084
    if (ctx->r15 == 0) {
        // 0x8006AF58: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8006B084;
    }
    goto skip_8;
    // 0x8006AF58: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_8:
    // 0x8006AF5C: lh          $t6, 0xCE($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XCE);
    // 0x8006AF60: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8006AF64: addiu       $t8, $t6, -0xA
    ctx->r24 = ADD32(ctx->r14, -0XA);
    // 0x8006AF68: sh          $t8, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r24;
    // 0x8006AF6C: lh          $t9, 0xCE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XCE);
    // 0x8006AF70: blezl       $t9, L_8006AF88
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8006AF74: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8006AF88;
    }
    goto skip_9;
    // 0x8006AF74: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_9:
    // 0x8006AF78: lb          $t0, 0xD0($s0)
    ctx->r8 = MEM_B(ctx->r16, 0XD0);
    // 0x8006AF7C: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x8006AF80: bne         $at, $zero, L_8006B028
    if (ctx->r1 != 0) {
        // 0x8006AF84: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8006B028;
    }
    // 0x8006AF84: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8006AF88:
    // 0x8006AF88: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006AF8C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006AF90: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006AF94: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006AF98: jal         0x8007D2C8
    // 0x8006AF9C: add.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f18.fl;
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_3;
    // 0x8006AF9C: add.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f18.fl;
    after_3:
    // 0x8006AFA0: lwc1        $f6, 0xEC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8006AFA4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8006AFA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006AFAC: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006AFB0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006AFB4: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006AFB8: lw          $a3, 0xE8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XE8);
    // 0x8006AFBC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8006AFC0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8006AFC4: lwc1        $f8, 0xF0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8006AFC8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006AFCC: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x8006AFD0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8006AFD4: add.s       $f14, $f16, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8006AFD8: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8006AFDC: jal         0x8007BFFC
    // 0x8006AFE0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_4;
    // 0x8006AFE0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x8006AFE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006AFE8: jal         0x80060FBC
    // 0x8006AFEC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_5;
    // 0x8006AFEC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_5:
    // 0x8006AFF0: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x8006AFF4: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    // 0x8006AFF8: jal         0x8007A6F0
    // 0x8006AFFC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_6;
    // 0x8006AFFC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x8006B000: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8006B004: addiu       $v0, $v0, 0x1A98
    ctx->r2 = ADD32(ctx->r2, 0X1A98);
    // 0x8006B008: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8006B00C: lbu         $t3, 0x3C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X3C);
    // 0x8006B010: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x8006B014: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006B018: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8006B01C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8006B020: b           L_8006B080
    // 0x8006B024: sw          $t5, 0x7850($at)
    MEM_W(0X7850, ctx->r1) = ctx->r13;
        goto L_8006B080;
    // 0x8006B024: sw          $t5, 0x7850($at)
    MEM_W(0X7850, ctx->r1) = ctx->r13;
L_8006B028:
    // 0x8006B028: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8006B02C: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8006B030: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8006B034: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8006B038: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x8006B03C: sh          $t7, 0xC6($s0)
    MEM_H(0XC6, ctx->r16) = ctx->r15;
    // 0x8006B040: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8006B044: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8006B048: ori         $a0, $a0, 0x300E
    ctx->r4 = ctx->r4 | 0X300E;
    // 0x8006B04C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8006B050: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8006B054: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8006B058: jal         0x80019218
    // 0x8006B05C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x8006B05C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
    // 0x8006B060: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8006B064: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8006B068: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006B06C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006B070: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006B074: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8006B078: jal         0x8007D1E0
    // 0x8006B07C: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    Effect_FireSmoke3_Spawn(rdram, ctx);
        goto after_8;
    // 0x8006B07C: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    after_8:
L_8006B080:
    // 0x8006B080: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8006B084:
    // 0x8006B084: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8006B088: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8006B08C: jr          $ra
    // 0x8006B090: nop

    return;
    // 0x8006B090: nop

;}
RECOMP_FUNC void Display_SetSecondLight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F670: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8005F674: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8005F678: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8005F67C: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x8005F680: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005F684: lwc1        $f4, 0x63AC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X63AC);
    // 0x8005F688: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005F68C: lwc1        $f6, -0x7C94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7C94);
    // 0x8005F690: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005F694: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8005F698: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8005F69C: nop

    // 0x8005F6A0: bc1fl       L_8005F9CC
    if (!c1cs) {
        // 0x8005F6A4: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8005F9CC;
    }
    goto skip_0;
    // 0x8005F6A4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x8005F6A8: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8005F6AC: lwc1        $f10, -0x7C90($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7C90);
    // 0x8005F6B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005F6B4: lwc1        $f6, -0x7C8C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7C8C);
    // 0x8005F6B8: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8005F6BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005F6C0: lwc1        $f10, -0x7C88($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7C88);
    // 0x8005F6C4: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8005F6C8: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8005F6CC: mul.s       $f2, $f12, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8005F6D0: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8005F6D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005F6D8: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8005F6DC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8005F6E0: sub.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005F6E4: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005F6E8: lw          $t7, 0x1C8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C8);
    // 0x8005F6EC: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8005F6F0: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8005F6F4: add.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8005F6F8: bne         $v0, $t7, L_8005F710
    if (ctx->r2 != ctx->r15) {
        // 0x8005F6FC: sqrt.s      $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
            goto L_8005F710;
    }
    // 0x8005F6FC: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8005F700: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x8005F704: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005F708: b           L_8005F720
    // 0x8005F70C: div.s       $f20, $f8, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
        goto L_8005F720;
    // 0x8005F70C: div.s       $f20, $f8, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
L_8005F710:
    // 0x8005F710: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8005F714: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005F718: nop

    // 0x8005F71C: div.s       $f20, $f10, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
L_8005F720:
    // 0x8005F720: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005F724: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005F728: nop

    // 0x8005F72C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8005F730: nop

    // 0x8005F734: bc1f        L_8005F740
    if (!c1cs) {
        // 0x8005F738: nop
    
            goto L_8005F740;
    }
    // 0x8005F738: nop

    // 0x8005F73C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_8005F740:
    // 0x8005F740: lw          $t8, -0x7ED4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7ED4);
    // 0x8005F744: bnel        $v0, $t8, L_8005F754
    if (ctx->r2 != ctx->r24) {
        // 0x8005F748: swc1        $f2, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
            goto L_8005F754;
    }
    goto skip_1;
    // 0x8005F748: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    skip_1:
    // 0x8005F74C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8005F750: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
L_8005F754:
    // 0x8005F754: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    // 0x8005F758: jal         0x80005100
    // 0x8005F75C: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x8005F75C: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8005F760: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8005F764: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8005F768: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x8005F76C: lwc1        $f12, 0xA0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8005F770: add.s       $f0, $f2, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x8005F774: jal         0x80005100
    // 0x8005F778: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_1;
    // 0x8005F778: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_1:
    // 0x8005F77C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8005F780: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8005F784: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x8005F788: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    // 0x8005F78C: jal         0x80005708
    // 0x8005F790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x8005F790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8005F794: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8005F798: lw          $t0, 0x78A0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78A0);
    // 0x8005F79C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005F7A0: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x8005F7A4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8005F7A8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8005F7AC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8005F7B0: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8005F7B4: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x8005F7B8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005F7BC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8005F7C0: lwc1        $f6, 0x34($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X34);
    // 0x8005F7C4: lwc1        $f8, 0x7950($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7950);
    // 0x8005F7C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005F7CC: lwc1        $f4, 0x63B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X63B0);
    // 0x8005F7D0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8005F7D4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005F7D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005F7DC: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8005F7E0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8005F7E4: jal         0x80005FE0
    // 0x8005F7E8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x8005F7E8: nop

    after_3:
    // 0x8005F7EC: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8005F7F0: lw          $t4, 0x78A0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X78A0);
    // 0x8005F7F4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8005F7F8: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x8005F7FC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8005F800: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8005F804: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8005F808: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8005F80C: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x8005F810: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8005F814: lwc1        $f8, 0x5C($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X5C);
    // 0x8005F818: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005F81C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005F820: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8005F824: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8005F828: jal         0x80005D44
    // 0x8005F82C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x8005F82C: nop

    after_4:
    // 0x8005F830: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8005F834: lw          $t8, 0x78A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78A0);
    // 0x8005F838: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005F83C: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x8005F840: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x8005F844: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x8005F848: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8005F84C: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x8005F850: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x8005F854: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x8005F858: lwc1        $f4, 0x58($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X58);
    // 0x8005F85C: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005F860: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005F864: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005F868: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005F86C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8005F870: jal         0x80005E90
    // 0x8005F874: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x8005F874: nop

    after_5:
    // 0x8005F878: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005F87C: lw          $a1, 0x98($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X98);
    // 0x8005F880: jal         0x80005D44
    // 0x8005F884: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_6;
    // 0x8005F884: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x8005F888: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005F88C: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8005F890: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005F894: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005F898: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x8005F89C: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    // 0x8005F8A0: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x8005F8A4: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x8005F8A8: jal         0x80006A20
    // 0x8005F8AC: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_7;
    // 0x8005F8AC: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x8005F8B0: jal         0x80005740
    // 0x8005F8B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_8;
    // 0x8005F8B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8005F8B8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005F8BC: lw          $t1, -0x7CA0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7CA0);
    // 0x8005F8C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005F8C4: lwc1        $f0, -0x7C94($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7C94);
    // 0x8005F8C8: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8005F8CC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005F8D0: lw          $t2, -0x7C9C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7C9C);
    // 0x8005F8D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005F8D8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8005F8DC: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x8005F8E0: lw          $t4, -0x7C98($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7C98);
    // 0x8005F8E4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005F8E8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005F8EC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8005F8F0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005F8F4: lw          $t9, -0x7AB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7AB8);
    // 0x8005F8F8: lw          $t1, -0x7AB4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7AB4);
    // 0x8005F8FC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005F900: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8005F904: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8005F908: mul.s       $f2, $f8, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8005F90C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8005F910: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8005F914: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8005F918: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8005F91C: lw          $t9, -0x7AA8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7AA8);
    // 0x8005F920: lw          $t1, -0x7AA4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7AA4);
    // 0x8005F924: lw          $t2, -0x7AB0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7AB0);
    // 0x8005F928: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005F92C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005F930: mul.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8005F934: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8005F938: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8005F93C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8005F940: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8005F944: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8005F948: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8005F94C: lw          $a3, -0x7B1C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7B1C);
    // 0x8005F950: lw          $a2, -0x7B20($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7B20);
    // 0x8005F954: lw          $a1, -0x7B24($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7B24);
    // 0x8005F958: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005F95C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8005F960: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8005F964: mul.s       $f14, $f4, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8005F968: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8005F96C: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8005F970: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x8005F974: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8005F978: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8005F97C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8005F980: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8005F984: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8005F988: trunc.w.s   $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8005F98C: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8005F990: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8005F994: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8005F998: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8005F99C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8005F9A0: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8005F9A4: lw          $t0, -0x7AAC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7AAC);
    // 0x8005F9A8: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8005F9AC: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8005F9B0: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8005F9B4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8005F9B8: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8005F9BC: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8005F9C0: jal         0x800038AC
    // 0x8005F9C4: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    Lights_SetTwoLights(rdram, ctx);
        goto after_9;
    // 0x8005F9C4: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    after_9:
    // 0x8005F9C8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8005F9CC:
    // 0x8005F9CC: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x8005F9D0: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8005F9D4: jr          $ra
    // 0x8005F9D8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8005F9D8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void AudioThread_QueueCmdF32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E8A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E8AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E8B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001E8B4: jal         0x8001E850
    // 0x8001E8B8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    AudioThread_QueueCmd(rdram, ctx);
        goto after_0;
    // 0x8001E8B8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8001E8BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E8C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E8C4: jr          $ra
    // 0x8001E8C8: nop

    return;
    // 0x8001E8C8: nop

;}
RECOMP_FUNC void Versus_Exit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC760: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BC764: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BC768: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800BC76C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800BC770: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800BC774: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800BC778: jal         0x80006F20
    // 0x800BC77C: nop

    Memory_FreeAll(rdram, ctx);
        goto after_0;
    // 0x800BC77C: nop

    after_0:
    // 0x800BC780: jal         0x800A6148
    // 0x800BC784: nop

    Play_ClearObjectData(rdram, ctx);
        goto after_1;
    // 0x800BC784: nop

    after_1:
    // 0x800BC788: lui         $s3, 0x8017
    ctx->r19 = S32(0X8017 << 16);
    // 0x800BC78C: addiu       $s3, $s3, 0x78A8
    ctx->r19 = ADD32(ctx->r19, 0X78A8);
    // 0x800BC790: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800BC794: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BC798: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800BC79C: blez        $t6, L_800BC7D8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800BC7A0: lui         $s2, 0x8018
        ctx->r18 = S32(0X8018 << 16);
            goto L_800BC7D8;
    }
    // 0x800BC7A0: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x800BC7A4: addiu       $s2, $s2, -0x7D80
    ctx->r18 = ADD32(ctx->r18, -0X7D80);
    // 0x800BC7A8: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
L_800BC7AC:
    // 0x800BC7AC: addu        $a0, $t7, $s1
    ctx->r4 = ADD32(ctx->r15, ctx->r17);
    // 0x800BC7B0: jal         0x8001A500
    // 0x800BC7B4: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    Audio_KillSfxBySource(rdram, ctx);
        goto after_2;
    // 0x800BC7B4: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    after_2:
    // 0x800BC7B8: jal         0x8001CA24
    // 0x800BC7BC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    Audio_StopPlayerNoise(rdram, ctx);
        goto after_3;
    // 0x800BC7BC: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_3:
    // 0x800BC7C0: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800BC7C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800BC7C8: addiu       $s1, $s1, 0x4E0
    ctx->r17 = ADD32(ctx->r17, 0X4E0);
    // 0x800BC7CC: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800BC7D0: bnel        $at, $zero, L_800BC7AC
    if (ctx->r1 != 0) {
        // 0x800BC7D4: lw          $t7, 0x0($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X0);
            goto L_800BC7AC;
    }
    goto skip_0;
    // 0x800BC7D4: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    skip_0:
L_800BC7D8:
    // 0x800BC7D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800BC7DC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BC7E0: sw          $v1, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r3;
    // 0x800BC7E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BC7E8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800BC7EC: sw          $t9, 0x783C($at)
    MEM_W(0X783C, ctx->r1) = ctx->r25;
    // 0x800BC7F0: sw          $v1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r3;
    // 0x800BC7F4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BC7F8: sw          $zero, 0x7854($at)
    MEM_W(0X7854, ctx->r1) = 0;
    // 0x800BC7FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BC800: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x800BC804: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BC808: sw          $zero, 0x7AE0($at)
    MEM_W(0X7AE0, ctx->r1) = 0;
    // 0x800BC80C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BC810: sw          $zero, 0x784C($at)
    MEM_W(0X784C, ctx->r1) = 0;
    // 0x800BC814: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BC818: sw          $zero, 0x7B40($at)
    MEM_W(0X7B40, ctx->r1) = 0;
    // 0x800BC81C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800BC820: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800BC824: sh          $zero, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = 0;
    // 0x800BC828: addiu       $v0, $v0, -0x7C80
    ctx->r2 = ADD32(ctx->r2, -0X7C80);
    // 0x800BC82C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800BC830: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800BC834: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800BC838: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800BC83C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BC840: sw          $zero, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = 0;
    // 0x800BC844: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BC848: sw          $zero, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = 0;
    // 0x800BC84C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BC850: sw          $zero, 0x78E8($at)
    MEM_W(0X78E8, ctx->r1) = 0;
    // 0x800BC854: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BC858: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x800BC85C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BC860: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800BC864: sw          $t0, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r8;
    // 0x800BC868: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BC86C: sw          $v1, 0x7824($at)
    MEM_W(0X7824, ctx->r1) = ctx->r3;
    // 0x800BC870: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BC874: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800BC878: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800BC87C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800BC880: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800BC884: jr          $ra
    // 0x800BC888: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800BC888: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Aquas_CsIntroActors_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093164: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80093168: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009316C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80093170: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80093174: lh          $t6, 0xB8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB8);
    // 0x80093178: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8009317C: lw          $a1, -0x7D80($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D80);
    // 0x80093180: bnel        $t6, $zero, L_80093238
    if (ctx->r14 != 0) {
        // 0x80093184: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80093238;
    }
    goto skip_0;
    // 0x80093184: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_0:
    // 0x80093188: lh          $v1, 0xB6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB6);
    // 0x8009318C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80093190: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80093194: beq         $v1, $a0, L_800931B4
    if (ctx->r3 == ctx->r4) {
        // 0x80093198: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800931B4;
    }
    // 0x80093198: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8009319C: beq         $v0, $at, L_8009320C
    if (ctx->r2 == ctx->r1) {
        // 0x800931A0: addiu       $at, $zero, 0x2C
        ctx->r1 = ADD32(0, 0X2C);
            goto L_8009320C;
    }
    // 0x800931A0: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x800931A4: beql        $v0, $at, L_80093220
    if (ctx->r2 == ctx->r1) {
        // 0x800931A8: lw          $t9, 0x50($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X50);
            goto L_80093220;
    }
    goto skip_1;
    // 0x800931A8: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
    skip_1:
    // 0x800931AC: b           L_80093238
    // 0x800931B0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_80093238;
    // 0x800931B0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_800931B4:
    // 0x800931B4: lw          $t7, 0x1C8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1C8);
    // 0x800931B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800931BC: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800931C0: bne         $t7, $at, L_800931D0
    if (ctx->r15 != ctx->r1) {
        // 0x800931C4: nop
    
            goto L_800931D0;
    }
    // 0x800931C4: nop

    // 0x800931C8: beql        $a0, $v1, L_80093238
    if (ctx->r4 == ctx->r3) {
        // 0x800931CC: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80093238;
    }
    goto skip_2;
    // 0x800931CC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_2:
L_800931D0:
    // 0x800931D0: lw          $t8, 0x7A80($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7A80);
    // 0x800931D4: slti        $at, $t8, 0x635
    ctx->r1 = SIGNED(ctx->r24) < 0X635 ? 1 : 0;
    // 0x800931D8: bne         $at, $zero, L_800931EC
    if (ctx->r1 != 0) {
        // 0x800931DC: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_800931EC;
    }
    // 0x800931DC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800931E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800931E4: b           L_800931FC
    // 0x800931E8: swc1        $f4, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f4.u32l;
        goto L_800931FC;
    // 0x800931E8: swc1        $f4, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f4.u32l;
L_800931EC:
    // 0x800931EC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800931F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800931F4: nop

    // 0x800931F8: swc1        $f6, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f6.u32l;
L_800931FC:
    // 0x800931FC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80093200: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80093204: b           L_80093234
    // 0x80093208: swc1        $f8, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f8.u32l;
        goto L_80093234;
    // 0x80093208: swc1        $f8, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f8.u32l;
L_8009320C:
    // 0x8009320C: jal         0x801BE034
    // 0x80093210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Aquas_CsAqFishGroup_Update(rdram, ctx);
        goto after_0;
    // 0x80093210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80093214: b           L_80093238
    // 0x80093218: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_80093238;
    // 0x80093218: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8009321C: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
L_80093220:
    // 0x80093220: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80093224: slti        $at, $t0, 0x77
    ctx->r1 = SIGNED(ctx->r8) < 0X77 ? 1 : 0;
    // 0x80093228: bne         $at, $zero, L_80093234
    if (ctx->r1 != 0) {
        // 0x8009322C: sw          $t0, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->r8;
            goto L_80093234;
    }
    // 0x8009322C: sw          $t0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r8;
    // 0x80093230: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
L_80093234:
    // 0x80093234: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80093238:
    // 0x80093238: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009323C: lwc1        $f10, 0xF8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x80093240: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80093244: lwc1        $f4, 0x7FE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7FE4);
    // 0x80093248: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8009324C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80093250: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80093254: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80093258: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8009325C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80093260: jal         0x80005E90
    // 0x80093264: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x80093264: nop

    after_1:
    // 0x80093268: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8009326C: lwc1        $f10, 0x7FE8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7FE8);
    // 0x80093270: lwc1        $f8, 0xF4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x80093274: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80093278: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009327C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80093280: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80093284: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80093288: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8009328C: jal         0x80005D44
    // 0x80093290: nop

    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x80093290: nop

    after_2:
    // 0x80093294: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80093298: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009329C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800932A0: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800932A4: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800932A8: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800932AC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800932B0: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x800932B4: jal         0x80006A20
    // 0x800932B8: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_3;
    // 0x800932B8: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x800932BC: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800932C0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800932C4: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x800932C8: swc1        $f6, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f6.u32l;
    // 0x800932CC: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800932D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800932D4: lwc1        $f16, 0xF4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x800932D8: swc1        $f8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f8.u32l;
    // 0x800932DC: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800932E0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800932E4: swc1        $f10, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f10.u32l;
    // 0x800932E8: lwc1        $f10, 0xFC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x800932EC: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800932F0: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x800932F4: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x800932F8: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x800932FC: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    // 0x80093300: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80093304: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80093308: jr          $ra
    // 0x8009330C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8009330C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_tank_80043280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043280: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80043284: sw          $s7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r23;
    // 0x80043288: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8004328C: lui         $s7, 0x8014
    ctx->r23 = S32(0X8014 << 16);
    // 0x80043290: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x80043294: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80043298: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x8004329C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800432A0: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800432A4: addiu       $s7, $s7, -0x4438
    ctx->r23 = ADD32(ctx->r23, -0X4438);
    // 0x800432A8: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800432AC: sw          $s6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r22;
    // 0x800432B0: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x800432B4: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x800432B8: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x800432BC: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x800432C0: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x800432C4: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x800432C8: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x800432CC: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x800432D0: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800432D4: jal         0x80005708
    // 0x800432D8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x800432D8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_0:
    // 0x800432DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800432E0: lwc1        $f4, 0x55F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X55F0);
    // 0x800432E4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800432E8: sll         $t6, $s3, 4
    ctx->r14 = S32(ctx->r19 << 4);
    // 0x800432EC: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800432F0: sll         $t3, $s4, 4
    ctx->r11 = S32(ctx->r20 << 4);
    // 0x800432F4: addiu       $v0, $v0, 0x1FD0
    ctx->r2 = ADD32(ctx->r2, 0X1FD0);
    // 0x800432F8: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x800432FC: srl         $t4, $t3, 28
    ctx->r12 = S32(U32(ctx->r11) >> 28);
    // 0x80043300: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80043304: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80043308: lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // 0x8004330C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80043310: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80043314: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80043318: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8004331C: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x80043320: and         $t1, $s3, $v1
    ctx->r9 = ctx->r19 & ctx->r3;
    // 0x80043324: and         $t8, $s4, $v1
    ctx->r24 = ctx->r20 & ctx->r3;
    // 0x80043328: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8004332C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80043330: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80043334: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80043338: addu        $s3, $t2, $a3
    ctx->r19 = ADD32(ctx->r10, ctx->r7);
    // 0x8004333C: addu        $s4, $t9, $a3
    ctx->r20 = ADD32(ctx->r25, ctx->r7);
    // 0x80043340: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    // 0x80043344: jal         0x80005FE0
    // 0x80043348: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Matrix_RotateZ(rdram, ctx);
        goto after_1;
    // 0x80043348: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8004334C: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x80043350: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80043354: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80043358: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8004335C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80043360: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80043364: addiu       $s6, $sp, 0x80
    ctx->r22 = ADD32(ctx->r29, 0X80);
    // 0x80043368: addiu       $s5, $sp, 0x74
    ctx->r21 = ADD32(ctx->r29, 0X74);
    // 0x8004336C: addiu       $s2, $zero, 0x20
    ctx->r18 = ADD32(0, 0X20);
    // 0x80043370: swc1        $f30, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f30.u32l;
    // 0x80043374: mov.s       $f28, $f30
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 30);
    ctx->f28.fl = ctx->f30.fl;
L_80043378:
    // 0x80043378: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8004337C: mov.s       $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    ctx->f20.fl = ctx->f30.fl;
    // 0x80043380: sub.s       $f24, $f28, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f24.fl = ctx->f28.fl - ctx->f22.fl;
L_80043384:
    // 0x80043384: sub.s       $f8, $f20, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x80043388: swc1        $f24, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f24.u32l;
    // 0x8004338C: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    // 0x80043390: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80043394: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    // 0x80043398: jal         0x80006970
    // 0x8004339C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x8004339C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_2:
    // 0x800433A0: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800433A4: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800433A8: add.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f22.fl;
    // 0x800433AC: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x800433B0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800433B4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800433B8: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x800433BC: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800433C0: bltz        $v0, L_80043404
    if (SIGNED(ctx->r2) < 0) {
        // 0x800433C4: slti        $at, $v0, 0x20
        ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
            goto L_80043404;
    }
    // 0x800433C4: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x800433C8: beql        $at, $zero, L_80043408
    if (ctx->r1 == 0) {
        // 0x800433CC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80043408;
    }
    goto skip_0;
    // 0x800433CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800433D0: bltz        $v1, L_80043404
    if (SIGNED(ctx->r3) < 0) {
        // 0x800433D4: slti        $at, $v1, 0x20
        ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
            goto L_80043404;
    }
    // 0x800433D4: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x800433D8: beq         $at, $zero, L_80043404
    if (ctx->r1 == 0) {
        // 0x800433DC: sll         $t3, $s1, 6
        ctx->r11 = S32(ctx->r17 << 6);
            goto L_80043404;
    }
    // 0x800433DC: sll         $t3, $s1, 6
    ctx->r11 = S32(ctx->r17 << 6);
    // 0x800433E0: addu        $t4, $s4, $t3
    ctx->r12 = ADD32(ctx->r20, ctx->r11);
    // 0x800433E4: sll         $t5, $s0, 1
    ctx->r13 = S32(ctx->r16 << 1);
    // 0x800433E8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800433EC: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800433F0: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800433F4: addu        $t9, $s3, $t8
    ctx->r25 = ADD32(ctx->r19, ctx->r24);
    // 0x800433F8: sll         $t1, $v1, 6
    ctx->r9 = S32(ctx->r3 << 6);
    // 0x800433FC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80043400: sh          $t7, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r15;
L_80043404:
    // 0x80043404: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80043408:
    // 0x80043408: bne         $s0, $s2, L_80043384
    if (ctx->r16 != ctx->r18) {
        // 0x8004340C: add.s       $f20, $f20, $f26
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
            goto L_80043384;
    }
    // 0x8004340C: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x80043410: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80043414: bne         $s1, $s2, L_80043378
    if (ctx->r17 != ctx->r18) {
        // 0x80043418: add.s       $f28, $f28, $f26
        CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f28.fl = ctx->f28.fl + ctx->f26.fl;
            goto L_80043378;
    }
    // 0x80043418: add.s       $f28, $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f28.fl = ctx->f28.fl + ctx->f26.fl;
    // 0x8004341C: jal         0x80005740
    // 0x80043420: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_3;
    // 0x80043420: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_3:
    // 0x80043424: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80043428: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8004342C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80043430: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80043434: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80043438: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8004343C: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x80043440: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80043444: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80043448: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8004344C: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80043450: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x80043454: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x80043458: lw          $s6, 0x5C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X5C);
    // 0x8004345C: lw          $s7, 0x60($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X60);
    // 0x80043460: jr          $ra
    // 0x80043464: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80043464: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void Display_CsLevelCompleteHandleCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800578C4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800578C8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800578CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800578D0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800578D4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800578D8: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800578DC: addiu       $t7, $t7, -0x5C64
    ctx->r15 = ADD32(ctx->r15, -0X5C64);
    // 0x800578E0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800578E4: addiu       $t6, $sp, 0x4C
    ctx->r14 = ADD32(ctx->r29, 0X4C);
    // 0x800578E8: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800578EC: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800578F0: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800578F4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800578F8: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x800578FC: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80057900: lw          $v0, -0x5DE0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5DE0);
    // 0x80057904: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80057908: addiu       $a0, $s0, 0x4CC
    ctx->r4 = ADD32(ctx->r16, 0X4CC);
    // 0x8005790C: beq         $v0, $zero, L_80057934
    if (ctx->r2 == 0) {
        // 0x80057910: lui         $a2, 0x3E4C
        ctx->r6 = S32(0X3E4C << 16);
            goto L_80057934;
    }
    // 0x80057910: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80057914: beq         $v0, $at, L_800579AC
    if (ctx->r2 == ctx->r1) {
        // 0x80057918: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800579AC;
    }
    // 0x80057918: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005791C: beq         $v0, $at, L_800579AC
    if (ctx->r2 == ctx->r1) {
        // 0x80057920: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800579AC;
    }
    // 0x80057920: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80057924: beq         $v0, $at, L_800579AC
    if (ctx->r2 == ctx->r1) {
        // 0x80057928: nop
    
            goto L_800579AC;
    }
    // 0x80057928: nop

    // 0x8005792C: b           L_80057CF0
    // 0x80057930: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80057CF0;
    // 0x80057930: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80057934:
    // 0x80057934: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80057938: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8005793C: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80057940: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80057944: jal         0x8009BD38
    // 0x80057948: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_0;
    // 0x80057948: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x8005794C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80057950: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80057954: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80057958: addiu       $a0, $s0, 0x4D0
    ctx->r4 = ADD32(ctx->r16, 0X4D0);
    // 0x8005795C: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80057960: jal         0x8009BD38
    // 0x80057964: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_1;
    // 0x80057964: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x80057968: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8005796C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80057970: addiu       $v0, $v0, 0x79D8
    ctx->r2 = ADD32(ctx->r2, 0X79D8);
    // 0x80057974: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80057978: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8005797C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80057980: addiu       $v1, $v1, 0x79E8
    ctx->r3 = ADD32(ctx->r3, 0X79E8);
    // 0x80057984: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80057988: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8005798C: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80057990: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80057994: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x80057998: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8005799C: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x800579A0: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800579A4: b           L_80057CEC
    // 0x800579A8: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
        goto L_80057CEC;
    // 0x800579A8: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
L_800579AC:
    // 0x800579AC: jal         0x8009F768
    // 0x800579B0: lwc1        $f12, 0x5C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X5C);
    Math_RadToDeg(rdram, ctx);
        goto after_2;
    // 0x800579B0: lwc1        $f12, 0x5C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X5C);
    after_2:
    // 0x800579B4: lwc1        $f6, 0xE4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x800579B8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800579BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800579C0: add.s       $f14, $f0, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800579C4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800579C8: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x800579CC: nop

    // 0x800579D0: bc1fl       L_800579E0
    if (!c1cs) {
        // 0x800579D4: c.lt.s      $f14, $f20
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f14.fl < ctx->f20.fl;
            goto L_800579E0;
    }
    goto skip_0;
    // 0x800579D4: c.lt.s      $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f14.fl < ctx->f20.fl;
    skip_0:
    // 0x800579D8: sub.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x800579DC: c.lt.s      $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f14.fl < ctx->f20.fl;
L_800579E0:
    // 0x800579E0: nop

    // 0x800579E4: bc1fl       L_800579F4
    if (!c1cs) {
        // 0x800579E8: lwc1        $f12, 0x58($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
            goto L_800579F4;
    }
    goto skip_1;
    // 0x800579E8: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    skip_1:
    // 0x800579EC: add.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x800579F0: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
L_800579F4:
    // 0x800579F4: jal         0x8009F768
    // 0x800579F8: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    Math_RadToDeg(rdram, ctx);
        goto after_3;
    // 0x800579F8: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x800579FC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80057A00: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80057A04: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80057A08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80057A0C: lwc1        $f18, 0xE8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x80057A10: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80057A14: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80057A18: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80057A1C: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x80057A20: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80057A24: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80057A28: addiu       $a0, $s0, 0x4CC
    ctx->r4 = ADD32(ctx->r16, 0X4CC);
    // 0x80057A2C: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80057A30: nop

    // 0x80057A34: bc1fl       L_80057A44
    if (!c1cs) {
        // 0x80057A38: c.lt.s      $f2, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
            goto L_80057A44;
    }
    goto skip_2;
    // 0x80057A38: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    skip_2:
    // 0x80057A3C: sub.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80057A40: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
L_80057A44:
    // 0x80057A44: nop

    // 0x80057A48: bc1fl       L_80057A58
    if (!c1cs) {
        // 0x80057A4C: sub.s       $f2, $f16, $f2
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f2.fl;
            goto L_80057A58;
    }
    goto skip_3;
    // 0x80057A4C: sub.s       $f2, $f16, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f2.fl;
    skip_3:
    // 0x80057A50: add.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x80057A54: sub.s       $f2, $f16, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f2.fl;
L_80057A58:
    // 0x80057A58: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x80057A5C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80057A60: jal         0x8009BD38
    // 0x80057A64: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_4;
    // 0x80057A64: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x80057A68: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80057A6C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80057A70: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80057A74: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80057A78: addiu       $a0, $s0, 0x4D0
    ctx->r4 = ADD32(ctx->r16, 0X4D0);
    // 0x80057A7C: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x80057A80: jal         0x8009BD38
    // 0x80057A84: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_5;
    // 0x80057A84: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_5:
    // 0x80057A88: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80057A8C: lb          $t1, -0x2765($t1)
    ctx->r9 = MEM_B(ctx->r9, -0X2765);
    // 0x80057A90: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80057A94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80057A98: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80057A9C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80057AA0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80057AA4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80057AA8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80057AAC: addiu       $a0, $a0, -0x5C80
    ctx->r4 = ADD32(ctx->r4, -0X5C80);
    // 0x80057AB0: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80057AB4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80057AB8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80057ABC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80057AC0: jal         0x8009BC2C
    // 0x80057AC4: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x80057AC4: nop

    after_6:
    // 0x80057AC8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80057ACC: lb          $t2, -0x2766($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X2766);
    // 0x80057AD0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80057AD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80057AD8: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80057ADC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80057AE0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80057AE4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80057AE8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80057AEC: addiu       $a0, $a0, -0x5C7C
    ctx->r4 = ADD32(ctx->r4, -0X5C7C);
    // 0x80057AF0: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80057AF4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80057AF8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80057AFC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80057B00: jal         0x8009BC2C
    // 0x80057B04: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x80057B04: nop

    after_7:
    // 0x80057B08: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80057B0C: lw          $t3, -0x5DE0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5DE0);
    // 0x80057B10: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80057B14: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80057B18: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80057B1C: addu        $a1, $a1, $t4
    ctx->r5 = ADD32(ctx->r5, ctx->r12);
    // 0x80057B20: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80057B24: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80057B28: lw          $a1, -0x5C74($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5C74);
    // 0x80057B2C: addiu       $a0, $a0, -0x5C78
    ctx->r4 = ADD32(ctx->r4, -0X5C78);
    // 0x80057B30: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80057B34: jal         0x8009BC2C
    // 0x80057B38: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x80057B38: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_8:
    // 0x80057B3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057B40: lwc1        $f20, 0x5F74($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5F74);
    // 0x80057B44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057B48: lwc1        $f10, -0x5C78($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5C78);
    // 0x80057B4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057B50: lwc1        $f4, -0x5C80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5C80);
    // 0x80057B54: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x80057B58: lwc1        $f18, 0xE8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x80057B5C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80057B60: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80057B64: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80057B68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80057B6C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80057B70: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80057B74: jal         0x80005D44
    // 0x80057B78: nop

    Matrix_RotateX(rdram, ctx);
        goto after_9;
    // 0x80057B78: nop

    after_9:
    // 0x80057B7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057B80: lwc1        $f18, -0x5C7C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5C7C);
    // 0x80057B84: lwc1        $f10, 0xE4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x80057B88: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80057B8C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80057B90: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80057B94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80057B98: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80057B9C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80057BA0: jal         0x80005E90
    // 0x80057BA4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_10;
    // 0x80057BA4: nop

    after_10:
    // 0x80057BA8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80057BAC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80057BB0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80057BB4: jal         0x80006970
    // 0x80057BB8: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    Matrix_MultVec3f(rdram, ctx);
        goto after_11;
    // 0x80057BB8: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_11:
    // 0x80057BBC: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80057BC0: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80057BC4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80057BC8: addiu       $v0, $v0, 0x79D8
    ctx->r2 = ADD32(ctx->r2, 0X79D8);
    // 0x80057BCC: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80057BD0: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80057BD4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80057BD8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80057BDC: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x80057BE0: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80057BE4: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80057BE8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80057BEC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80057BF0: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80057BF4: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80057BF8: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x80057BFC: lwc1        $f4, 0x138($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80057C00: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80057C04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80057C08: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80057C0C: lw          $t5, 0x7DB0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DB0);
    // 0x80057C10: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80057C14: nop

    // 0x80057C18: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80057C1C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80057C20: nop

    // 0x80057C24: mul.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80057C28: jal         0x80023090
    // 0x80057C2C: nop

    __sinf_recomp(rdram, ctx);
        goto after_12;
    // 0x80057C2C: nop

    after_12:
    // 0x80057C30: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80057C34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80057C38: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80057C3C: lwc1        $f18, 0x74($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80057C40: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80057C44: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x80057C48: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80057C4C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80057C50: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80057C54: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80057C58: swc1        $f4, 0x79E8($at)
    MEM_W(0X79E8, ctx->r1) = ctx->f4.u32l;
    // 0x80057C5C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80057C60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80057C64: nop

    // 0x80057C68: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80057C6C: nop

    // 0x80057C70: mul.s       $f12, $f18, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80057C74: jal         0x80023250
    // 0x80057C78: nop

    __cosf_recomp(rdram, ctx);
        goto after_13;
    // 0x80057C78: nop

    after_13:
    // 0x80057C7C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80057C80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80057C84: lwc1        $f8, 0x78($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80057C88: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80057C8C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80057C90: addiu       $v1, $v1, 0x79E8
    ctx->r3 = ADD32(ctx->r3, 0X79E8);
    // 0x80057C94: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80057C98: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80057C9C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80057CA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80057CA4: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x80057CA8: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x80057CAC: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80057CB0: nop

    // 0x80057CB4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80057CB8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80057CBC: nop

    // 0x80057CC0: mul.s       $f12, $f8, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80057CC4: jal         0x80023090
    // 0x80057CC8: nop

    __sinf_recomp(rdram, ctx);
        goto after_14;
    // 0x80057CC8: nop

    after_14:
    // 0x80057CCC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80057CD0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80057CD4: lwc1        $f4, 0x138($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80057CD8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80057CDC: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80057CE0: addiu       $v1, $v1, 0x79E8
    ctx->r3 = ADD32(ctx->r3, 0X79E8);
    // 0x80057CE4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80057CE8: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
L_80057CEC:
    // 0x80057CEC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80057CF0:
    // 0x80057CF0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80057CF4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80057CF8: jr          $ra
    // 0x80057CFC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80057CFC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Effect_Effect381_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B0F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007B0F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007B0FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007B100: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007B104: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8007B108: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007B10C: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8007B110: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007B114: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8007B118: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8007B11C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8007B120: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x8007B124: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8007B128: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8007B12C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8007B130: jal         0x8009BC2C
    // 0x8007B134: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8007B134: nop

    after_0:
    // 0x8007B138: lh          $t6, 0x44($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X44);
    // 0x8007B13C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8007B140: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007B144: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8007B148: addiu       $t7, $t6, -0xD
    ctx->r15 = ADD32(ctx->r14, -0XD);
    // 0x8007B14C: sh          $t7, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r15;
    // 0x8007B150: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8007B154: lh          $t8, 0x44($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X44);
    // 0x8007B158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007B15C: bgez        $t8, L_8007B16C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8007B160: swc1        $f4, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
            goto L_8007B16C;
    }
    // 0x8007B160: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x8007B164: jal         0x80060FBC
    // 0x8007B168: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x8007B168: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_1:
L_8007B16C:
    // 0x8007B16C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007B170: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007B174: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007B178: jr          $ra
    // 0x8007B17C: nop

    return;
    // 0x8007B17C: nop

;}
RECOMP_FUNC void Audio_KillSfxById(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A838: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8001A83C: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x8001A840: and         $t6, $a0, $at
    ctx->r14 = ctx->r4 & ctx->r1;
    // 0x8001A844: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x8001A848: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8001A84C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8001A850: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8001A854: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001A858: addiu       $t0, $t0, -0x79A0
    ctx->r8 = ADD32(ctx->r8, -0X79A0);
    // 0x8001A85C: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x8001A860: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001A864: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001A868: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001A86C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001A870: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001A874: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001A878: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001A87C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001A880: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001A884: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001A888: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x8001A88C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8001A890: lbu         $s1, 0x2B($t1)
    ctx->r17 = MEM_BU(ctx->r9, 0X2B);
    // 0x8001A894: addiu       $s6, $zero, 0xFF
    ctx->r22 = ADD32(0, 0XFF);
    // 0x8001A898: or          $s5, $t8, $zero
    ctx->r21 = ctx->r24 | 0;
    // 0x8001A89C: beq         $s6, $s1, L_8001A944
    if (ctx->r22 == ctx->r17) {
        // 0x8001A8A0: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8001A944;
    }
    // 0x8001A8A0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001A8A4: sll         $t2, $t8, 4
    ctx->r10 = S32(ctx->r24 << 4);
    // 0x8001A8A8: subu        $t2, $t2, $t8
    ctx->r10 = SUB32(ctx->r10, ctx->r24);
    // 0x8001A8AC: sll         $t2, $t2, 6
    ctx->r10 = S32(ctx->r10 << 6);
    // 0x8001A8B0: addu        $s3, $t2, $t0
    ctx->r19 = ADD32(ctx->r10, ctx->r8);
    // 0x8001A8B4: lui         $fp, 0x602
    ctx->r30 = S32(0X602 << 16);
    // 0x8001A8B8: addiu       $s7, $zero, 0x30
    ctx->r23 = ADD32(0, 0X30);
L_8001A8BC:
    // 0x8001A8BC: multu       $s1, $s7
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A8C0: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x8001A8C4: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x8001A8C8: mflo        $t3
    ctx->r11 = lo;
    // 0x8001A8CC: addu        $s0, $s3, $t3
    ctx->r16 = ADD32(ctx->r19, ctx->r11);
    // 0x8001A8D0: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x8001A8D4: bnel        $t4, $t5, L_8001A928
    if (ctx->r12 != ctx->r13) {
        // 0x8001A8D8: andi        $s2, $s1, 0xFF
        ctx->r18 = ctx->r17 & 0XFF;
            goto L_8001A928;
    }
    goto skip_0;
    // 0x8001A8D8: andi        $s2, $s1, 0xFF
    ctx->r18 = ctx->r17 & 0XFF;
    skip_0:
    // 0x8001A8DC: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
    // 0x8001A8E0: subu        $t6, $t6, $s2
    ctx->r14 = SUB32(ctx->r14, ctx->r18);
    // 0x8001A8E4: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8001A8E8: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8001A8EC: bne         $at, $zero, L_8001A90C
    if (ctx->r1 != 0) {
        // 0x8001A8F0: addu        $s4, $s3, $t6
        ctx->r20 = ADD32(ctx->r19, ctx->r14);
            goto L_8001A90C;
    }
    // 0x8001A8F0: addu        $s4, $s3, $t6
    ctx->r20 = ADD32(ctx->r19, ctx->r14);
    // 0x8001A8F4: lbu         $t8, 0x2C($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X2C);
    // 0x8001A8F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001A8FC: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8001A900: jal         0x8001E8F0
    // 0x8001A904: or          $a0, $t9, $fp
    ctx->r4 = ctx->r25 | ctx->r30;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_0;
    // 0x8001A904: or          $a0, $t9, $fp
    ctx->r4 = ctx->r25 | ctx->r30;
    after_0:
    // 0x8001A908: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
L_8001A90C:
    // 0x8001A90C: beq         $v0, $zero, L_8001A91C
    if (ctx->r2 == 0) {
        // 0x8001A910: andi        $a0, $s5, 0xFF
        ctx->r4 = ctx->r21 & 0XFF;
            goto L_8001A91C;
    }
    // 0x8001A910: andi        $a0, $s5, 0xFF
    ctx->r4 = ctx->r21 & 0XFF;
    // 0x8001A914: jal         0x800197AC
    // 0x8001A918: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    Audio_RemoveSfxBankEntry(rdram, ctx);
        goto after_1;
    // 0x8001A918: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_1:
L_8001A91C:
    // 0x8001A91C: b           L_8001A93C
    // 0x8001A920: lbu         $s1, 0x2B($s4)
    ctx->r17 = MEM_BU(ctx->r20, 0X2B);
        goto L_8001A93C;
    // 0x8001A920: lbu         $s1, 0x2B($s4)
    ctx->r17 = MEM_BU(ctx->r20, 0X2B);
    // 0x8001A924: andi        $s2, $s1, 0xFF
    ctx->r18 = ctx->r17 & 0XFF;
L_8001A928:
    // 0x8001A928: sll         $t1, $s2, 2
    ctx->r9 = S32(ctx->r18 << 2);
    // 0x8001A92C: subu        $t1, $t1, $s2
    ctx->r9 = SUB32(ctx->r9, ctx->r18);
    // 0x8001A930: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x8001A934: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x8001A938: lbu         $s1, 0x2B($t2)
    ctx->r17 = MEM_BU(ctx->r10, 0X2B);
L_8001A93C:
    // 0x8001A93C: bne         $s6, $s1, L_8001A8BC
    if (ctx->r22 != ctx->r17) {
        // 0x8001A940: nop
    
            goto L_8001A8BC;
    }
    // 0x8001A940: nop

L_8001A944:
    // 0x8001A944: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x8001A948: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8001A94C: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8001A950: jal         0x80019290
    // 0x8001A954: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    Audio_RemoveMatchingSfxRequests(rdram, ctx);
        goto after_2;
    // 0x8001A954: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    after_2:
    // 0x8001A958: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001A95C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001A960: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A964: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001A968: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001A96C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001A970: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A974: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001A978: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001A97C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001A980: jr          $ra
    // 0x8001A984: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8001A984: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void Background_DrawStarfield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DAF0: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8003DAF4: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8003DAF8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8003DAFC: addiu       $t2, $t2, 0x7E64
    ctx->r10 = ADD32(ctx->r10, 0X7E64);
    // 0x8003DB00: lui         $s3, 0xE700
    ctx->r19 = S32(0XE700 << 16);
    // 0x8003DB04: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8003DB08: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8003DB0C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8003DB10: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8003DB14: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8003DB18: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8003DB1C: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8003DB20: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8003DB24: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8003DB28: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8003DB2C: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8003DB30: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x8003DB34: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x8003DB38: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8003DB3C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8003DB40: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8003DB44: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8003DB48: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8003DB4C: ori         $t8, $t8, 0x1402
    ctx->r24 = ctx->r24 | 0X1402;
    // 0x8003DB50: lui         $t9, 0x30
    ctx->r25 = S32(0X30 << 16);
    // 0x8003DB54: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8003DB58: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8003DB5C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8003DB60: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8003DB64: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8003DB68: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x8003DB6C: lui         $t8, 0xFFFE
    ctx->r24 = S32(0XFFFE << 16);
    // 0x8003DB70: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8003DB74: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8003DB78: ori         $t8, $t8, 0x793C
    ctx->r24 = ctx->r24 | 0X793C;
    // 0x8003DB7C: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8003DB80: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8003DB84: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8003DB88: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8003DB8C: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x8003DB90: lui         $t7, 0xF0A
    ctx->r15 = S32(0XF0A << 16);
    // 0x8003DB94: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8003DB98: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8003DB9C: ori         $t7, $t7, 0x4000
    ctx->r15 = ctx->r15 | 0X4000;
    // 0x8003DBA0: ori         $t6, $t6, 0x31D
    ctx->r14 = ctx->r14 | 0X31D;
    // 0x8003DBA4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8003DBA8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8003DBAC: lw          $s2, -0x7BF0($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X7BF0);
    // 0x8003DBB0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8003DBB4: addiu       $v0, $v0, -0x7BE0
    ctx->r2 = ADD32(ctx->r2, -0X7BE0);
    // 0x8003DBB8: beq         $s2, $zero, L_8003DE04
    if (ctx->r18 == 0) {
        // 0x8003DBBC: lui         $at, 0x43F0
        ctx->r1 = S32(0X43F0 << 16);
            goto L_8003DE04;
    }
    // 0x8003DBBC: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x8003DBC0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8003DBC4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003DBC8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003DBCC: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8003DBD0: c.le.s      $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f28.fl <= ctx->f0.fl;
    // 0x8003DBD4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8003DBD8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003DBDC: addiu       $v1, $v1, -0x7BDC
    ctx->r3 = ADD32(ctx->r3, -0X7BDC);
    // 0x8003DBE0: bc1f        L_8003DBF4
    if (!c1cs) {
        // 0x8003DBE4: lui         $t4, 0x8018
        ctx->r12 = S32(0X8018 << 16);
            goto L_8003DBF4;
    }
    // 0x8003DBE4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8003DBE8: sub.s       $f4, $f0, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f28.fl;
    // 0x8003DBEC: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8003DBF0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
L_8003DBF4:
    // 0x8003DBF4: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8003DBF8: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8003DBFC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8003DC00: c.le.s      $f30, $f2
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f30.fl <= ctx->f2.fl;
    // 0x8003DC04: lui         $ra, 0x8018
    ctx->r31 = S32(0X8018 << 16);
    // 0x8003DC08: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8003DC0C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8003DC10: bc1f        L_8003DC24
    if (!c1cs) {
        // 0x8003DC14: addiu       $s0, $s0, -0x7BD8
        ctx->r16 = ADD32(ctx->r16, -0X7BD8);
            goto L_8003DC24;
    }
    // 0x8003DC14: addiu       $s0, $s0, -0x7BD8
    ctx->r16 = ADD32(ctx->r16, -0X7BD8);
    // 0x8003DC18: sub.s       $f6, $f2, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f30.fl;
    // 0x8003DC1C: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x8003DC20: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
L_8003DC24:
    // 0x8003DC24: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8003DC28: nop

    // 0x8003DC2C: bc1fl       L_8003DC44
    if (!c1cs) {
        // 0x8003DC30: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_8003DC44;
    }
    goto skip_0;
    // 0x8003DC30: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_0:
    // 0x8003DC34: add.s       $f8, $f0, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f28.fl;
    // 0x8003DC38: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8003DC3C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003DC40: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
L_8003DC44:
    // 0x8003DC44: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8003DC48: bc1f        L_8003DC5C
    if (!c1cs) {
        // 0x8003DC4C: nop
    
            goto L_8003DC5C;
    }
    // 0x8003DC4C: nop

    // 0x8003DC50: add.s       $f10, $f2, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f30.fl;
    // 0x8003DC54: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x8003DC58: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
L_8003DC5C:
    // 0x8003DC5C: lw          $t8, 0x7834($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7834);
    // 0x8003DC60: mov.s       $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    ctx->f26.fl = ctx->f2.fl;
    // 0x8003DC64: lw          $t4, -0x7D78($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D78);
    // 0x8003DC68: lw          $t5, -0x7D70($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D70);
    // 0x8003DC6C: beq         $t8, $at, L_8003DC78
    if (ctx->r24 == ctx->r1) {
        // 0x8003DC70: lw          $ra, -0x7D68($ra)
        ctx->r31 = MEM_W(ctx->r31, -0X7D68);
            goto L_8003DC78;
    }
    // 0x8003DC70: lw          $ra, -0x7D68($ra)
    ctx->r31 = MEM_W(ctx->r31, -0X7D68);
    // 0x8003DC74: addiu       $s2, $zero, 0x3E8
    ctx->r18 = ADD32(0, 0X3E8);
L_8003DC78:
    // 0x8003DC78: sw          $ra, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r31;
    // 0x8003DC7C: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8003DC80: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
    // 0x8003DC84: jal         0x80023250
    // 0x8003DC88: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    __cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8003DC88: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    after_0:
    // 0x8003DC8C: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8003DC90: jal         0x80023090
    // 0x8003DC94: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8003DC94: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8003DC98: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8003DC9C: addiu       $t2, $t2, 0x7E64
    ctx->r10 = ADD32(ctx->r10, 0X7E64);
    // 0x8003DCA0: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8003DCA4: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8003DCA8: lw          $ra, 0x58($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X58);
    // 0x8003DCAC: lwc1        $f14, 0x70($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8003DCB0: blez        $s2, L_8003DE04
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8003DCB4: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_8003DE04;
    }
    // 0x8003DCB4: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8003DCB8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8003DCBC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8003DCC0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8003DCC4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8003DCC8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8003DCCC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003DCD0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8003DCD4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003DCD8: lui         $s1, 0xF600
    ctx->r17 = S32(0XF600 << 16);
    // 0x8003DCDC: lui         $s0, 0xF700
    ctx->r16 = S32(0XF700 << 16);
L_8003DCE0:
    // 0x8003DCE0: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8003DCE4: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8003DCE8: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8003DCEC: add.s       $f2, $f4, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x8003DCF0: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x8003DCF4: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x8003DCF8: add.s       $f12, $f6, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x8003DCFC: c.le.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl <= ctx->f2.fl;
    // 0x8003DD00: nop

    // 0x8003DD04: bc1fl       L_8003DD14
    if (!c1cs) {
        // 0x8003DD08: c.le.s      $f22, $f12
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f22.fl <= ctx->f12.fl;
            goto L_8003DD14;
    }
    goto skip_1;
    // 0x8003DD08: c.le.s      $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f22.fl <= ctx->f12.fl;
    skip_1:
    // 0x8003DD0C: sub.s       $f2, $f2, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f28.fl;
    // 0x8003DD10: c.le.s      $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f22.fl <= ctx->f12.fl;
L_8003DD14:
    // 0x8003DD14: sub.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8003DD18: bc1fl       L_8003DD28
    if (!c1cs) {
        // 0x8003DD1C: sub.s       $f12, $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f18.fl;
            goto L_8003DD28;
    }
    goto skip_2;
    // 0x8003DD1C: sub.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f18.fl;
    skip_2:
    // 0x8003DD20: sub.s       $f12, $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f30.fl;
    // 0x8003DD24: sub.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f18.fl;
L_8003DD28:
    // 0x8003DD28: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8003DD2C: nop

    // 0x8003DD30: mul.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8003DD34: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003DD38: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8003DD3C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8003DD40: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8003DD44: nop

    // 0x8003DD48: sll         $t6, $t0, 16
    ctx->r14 = S32(ctx->r8 << 16);
    // 0x8003DD4C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8003DD50: bltz        $t7, L_8003DDFC
    if (SIGNED(ctx->r15) < 0) {
        // 0x8003DD54: or          $t0, $t7, $zero
        ctx->r8 = ctx->r15 | 0;
            goto L_8003DDFC;
    }
    // 0x8003DD54: or          $t0, $t7, $zero
    ctx->r8 = ctx->r15 | 0;
    // 0x8003DD58: slti        $at, $t7, 0x140
    ctx->r1 = SIGNED(ctx->r15) < 0X140 ? 1 : 0;
    // 0x8003DD5C: beq         $at, $zero, L_8003DDFC
    if (ctx->r1 == 0) {
        // 0x8003DD60: nop
    
            goto L_8003DDFC;
    }
    // 0x8003DD60: nop

    // 0x8003DD64: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x8003DD68: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8003DD6C: nop

    // 0x8003DD70: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8003DD74: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003DD78: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8003DD7C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8003DD80: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x8003DD84: nop

    // 0x8003DD88: sll         $t9, $t1, 16
    ctx->r25 = S32(ctx->r9 << 16);
    // 0x8003DD8C: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8003DD90: blez        $t6, L_8003DDFC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8003DD94: or          $t1, $t6, $zero
        ctx->r9 = ctx->r14 | 0;
            goto L_8003DDFC;
    }
    // 0x8003DD94: or          $t1, $t6, $zero
    ctx->r9 = ctx->r14 | 0;
    // 0x8003DD98: slti        $at, $t6, 0xF0
    ctx->r1 = SIGNED(ctx->r14) < 0XF0 ? 1 : 0;
    // 0x8003DD9C: beq         $at, $zero, L_8003DDFC
    if (ctx->r1 == 0) {
        // 0x8003DDA0: andi        $a2, $t0, 0x3FF
        ctx->r6 = ctx->r8 & 0X3FF;
            goto L_8003DDFC;
    }
    // 0x8003DDA0: andi        $a2, $t0, 0x3FF
    ctx->r6 = ctx->r8 & 0X3FF;
    // 0x8003DDA4: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8003DDA8: andi        $a3, $t1, 0x3FF
    ctx->r7 = ctx->r9 & 0X3FF;
    // 0x8003DDAC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8003DDB0: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8003DDB4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8003DDB8: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8003DDBC: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8003DDC0: sll         $t7, $a2, 14
    ctx->r15 = S32(ctx->r6 << 14);
    // 0x8003DDC4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8003DDC8: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8003DDCC: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x8003DDD0: lw          $t9, 0x0($ra)
    ctx->r25 = MEM_W(ctx->r31, 0X0);
    // 0x8003DDD4: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x8003DDD8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8003DDDC: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8003DDE0: or          $t9, $t7, $s1
    ctx->r25 = ctx->r15 | ctx->r17;
    // 0x8003DDE4: or          $t7, $t7, $t8
    ctx->r15 = ctx->r15 | ctx->r24;
    // 0x8003DDE8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8003DDEC: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8003DDF0: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8003DDF4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8003DDF8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_8003DDFC:
    // 0x8003DDFC: bne         $t3, $s2, L_8003DCE0
    if (ctx->r11 != ctx->r18) {
        // 0x8003DE00: addiu       $ra, $ra, 0x4
        ctx->r31 = ADD32(ctx->r31, 0X4);
            goto L_8003DCE0;
    }
    // 0x8003DE00: addiu       $ra, $ra, 0x4
    ctx->r31 = ADD32(ctx->r31, 0X4);
L_8003DE04:
    // 0x8003DE04: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8003DE08: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8003DE0C: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8003DE10: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8003DE14: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8003DE18: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8003DE1C: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x8003DE20: ori         $t6, $t6, 0x602
    ctx->r14 = ctx->r14 | 0X602;
    // 0x8003DE24: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8003DE28: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8003DE2C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8003DE30: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8003DE34: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8003DE38: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8003DE3C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8003DE40: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8003DE44: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8003DE48: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8003DE4C: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x8003DE50: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8003DE54: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8003DE58: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8003DE5C: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8003DE60: jr          $ra
    // 0x8003DE64: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8003DE64: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void AllRange_PlayMessage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E4F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002E4FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002E500: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002E504: lw          $t6, -0x7D64($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D64);
    // 0x8002E508: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8002E50C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002E510: bne         $t6, $zero, L_8002E538
    if (ctx->r14 != 0) {
        // 0x8002E514: nop
    
            goto L_8002E538;
    }
    // 0x8002E514: nop

    // 0x8002E518: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x8002E51C: lw          $t8, 0x1C8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C8);
    // 0x8002E520: beq         $t8, $zero, L_8002E538
    if (ctx->r24 == 0) {
        // 0x8002E524: nop
    
            goto L_8002E538;
    }
    // 0x8002E524: nop

    // 0x8002E528: jal         0x800BA808
    // 0x8002E52C: nop

    Radio_PlayMessage(rdram, ctx);
        goto after_0;
    // 0x8002E52C: nop

    after_0:
    // 0x8002E530: b           L_8002E538
    // 0x8002E534: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002E538;
    // 0x8002E534: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002E538:
    // 0x8002E538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002E53C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002E540: jr          $ra
    // 0x8002E544: nop

    return;
    // 0x8002E544: nop

;}
RECOMP_FUNC void HUD_BoostGauge_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D4F0: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8008D4F4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8008D4F8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8008D4FC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8008D500: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8008D504: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8008D508: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8008D50C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8008D510: addiu       $t7, $t7, 0x2108
    ctx->r15 = ADD32(ctx->r15, 0X2108);
    // 0x8008D514: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8008D518: addiu       $t6, $sp, 0x8C
    ctx->r14 = ADD32(ctx->r29, 0X8C);
    // 0x8008D51C: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8008D520: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8008D524: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8008D528: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8008D52C: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x8008D530: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8008D534: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x8008D538: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8008D53C: addiu       $t2, $t2, 0x211C
    ctx->r10 = ADD32(ctx->r10, 0X211C);
    // 0x8008D540: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x8008D544: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x8008D548: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x8008D54C: addiu       $t1, $sp, 0x78
    ctx->r9 = ADD32(ctx->r29, 0X78);
    // 0x8008D550: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x8008D554: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x8008D558: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x8008D55C: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x8008D560: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x8008D564: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x8008D568: lw          $at, 0x10($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X10);
    // 0x8008D56C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8008D570: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    // 0x8008D574: sw          $at, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r1;
    // 0x8008D578: lw          $t9, 0x78E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78E8);
    // 0x8008D57C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8008D580: beq         $t9, $zero, L_8008D5AC
    if (ctx->r25 == 0) {
        // 0x8008D584: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8008D5AC;
    }
    // 0x8008D584: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008D588: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8008D58C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8008D590: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x8008D594: lw          $a0, 0x78A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X78A0);
    // 0x8008D598: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008D59C: swc1        $f22, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f22.u32l;
    // 0x8008D5A0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8008D5A4: b           L_8008D5E0
    // 0x8008D5A8: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
        goto L_8008D5E0;
    // 0x8008D5A8: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
L_8008D5AC:
    // 0x8008D5AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8008D5B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008D5B4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8008D5B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008D5BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008D5C0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8008D5C4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8008D5C8: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8008D5CC: swc1        $f12, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f12.u32l;
    // 0x8008D5D0: lw          $a0, 0x78A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X78A0);
    // 0x8008D5D4: swc1        $f14, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f14.u32l;
    // 0x8008D5D8: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x8008D5DC: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
L_8008D5E0:
    // 0x8008D5E0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8008D5E4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8008D5E8: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x8008D5EC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8008D5F0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8008D5F4: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x8008D5F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008D5FC: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x8008D600: lwc1        $f10, 0x2BC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X2BC);
    // 0x8008D604: lwc1        $f16, 0x7D9C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7D9C);
    // 0x8008D608: lw          $t7, 0x2B4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2B4);
    // 0x8008D60C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8008D610: mul.s       $f20, $f10, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8008D614: bne         $t7, $zero, L_8008D660
    if (ctx->r15 != 0) {
        // 0x8008D618: sll         $s0, $v1, 2
        ctx->r16 = S32(ctx->r3 << 2);
            goto L_8008D660;
    }
    // 0x8008D618: sll         $s0, $v1, 2
    ctx->r16 = S32(ctx->r3 << 2);
    // 0x8008D61C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8008D620: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008D624: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008D628: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x8008D62C: lwc1        $f18, 0x7DA0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7DA0);
    // 0x8008D630: addiu       $t0, $t0, 0x19AC
    ctx->r8 = ADD32(ctx->r8, 0X19AC);
    // 0x8008D634: sll         $s0, $v1, 2
    ctx->r16 = S32(ctx->r3 << 2);
    // 0x8008D638: addu        $s1, $s0, $t0
    ctx->r17 = ADD32(ctx->r16, ctx->r8);
    // 0x8008D63C: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x8008D640: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8008D644: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8008D648: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008D64C: lui         $a1, 0x437F
    ctx->r5 = S32(0X437F << 16);
    // 0x8008D650: jal         0x8009BC2C
    // 0x8008D654: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8008D654: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8008D658: b           L_8008D698
    // 0x8008D65C: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
        goto L_8008D698;
    // 0x8008D65C: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
L_8008D660:
    // 0x8008D660: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008D664: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008D668: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8008D66C: lwc1        $f4, 0x7DA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7DA4);
    // 0x8008D670: addiu       $t4, $t4, 0x19AC
    ctx->r12 = ADD32(ctx->r12, 0X19AC);
    // 0x8008D674: addu        $s1, $s0, $t4
    ctx->r17 = ADD32(ctx->r16, ctx->r12);
    // 0x8008D678: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x8008D67C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8008D680: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8008D684: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8008D688: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008D68C: jal         0x8009BC2C
    // 0x8008D690: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x8008D690: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8008D694: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
L_8008D698:
    // 0x8008D698: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8008D69C: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x8008D6A0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8008D6A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8008D6A8: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    // 0x8008D6AC: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8008D6B0: jal         0x800B8DD0
    // 0x8008D6B4: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x8008D6B4: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    after_2:
    // 0x8008D6B8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8008D6BC: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8008D6C0: sub.s       $f0, $f22, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f22.fl - ctx->f20.fl;
    // 0x8008D6C4: addiu       $t2, $a0, 0x8
    ctx->r10 = ADD32(ctx->r4, 0X8);
    // 0x8008D6C8: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x8008D6CC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8008D6D0: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x8008D6D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008D6D8: addu        $t1, $sp, $s0
    ctx->r9 = ADD32(ctx->r29, ctx->r16);
    // 0x8008D6DC: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8008D6E0: sll         $t8, $t9, 24
    ctx->r24 = S32(ctx->r25 << 24);
    // 0x8008D6E4: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x8008D6E8: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8008D6EC: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x8008D6F0: or          $t4, $t7, $t0
    ctx->r12 = ctx->r15 | ctx->r8;
    // 0x8008D6F4: ori         $t3, $t4, 0xFF
    ctx->r11 = ctx->r12 | 0XFF;
    // 0x8008D6F8: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x8008D6FC: lwc1        $f10, 0x7DA8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7DA8);
    // 0x8008D700: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8008D704: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8008D708: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8008D70C: addu        $t2, $sp, $s0
    ctx->r10 = ADD32(ctx->r29, ctx->r16);
    // 0x8008D710: bc1f        L_8008D744
    if (!c1cs) {
        // 0x8008D714: nop
    
            goto L_8008D744;
    }
    // 0x8008D714: nop

    // 0x8008D718: lwc1        $f16, 0x8C($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X8C);
    // 0x8008D71C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008D720: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8008D724: lwc1        $f10, 0x78($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X78);
    // 0x8008D728: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8008D72C: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8008D730: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8008D734: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8008D738: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8008D73C: jal         0x80085890
    // 0x8008D740: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    HUD_BoostGaugeCool_Draw(rdram, ctx);
        goto after_3;
    // 0x8008D740: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_3:
L_8008D744:
    // 0x8008D744: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008D748: lwc1        $f18, 0x7DAC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7DAC);
    // 0x8008D74C: addiu       $t9, $sp, 0x78
    ctx->r25 = ADD32(ctx->r29, 0X78);
    // 0x8008D750: addu        $t8, $s0, $t9
    ctx->r24 = ADD32(ctx->r16, ctx->r25);
    // 0x8008D754: c.lt.s      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.fl < ctx->f20.fl;
    // 0x8008D758: addiu       $t5, $sp, 0x8C
    ctx->r13 = ADD32(ctx->r29, 0X8C);
    // 0x8008D75C: addu        $s1, $s0, $t5
    ctx->r17 = ADD32(ctx->r16, ctx->r13);
    // 0x8008D760: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8008D764: bc1f        L_8008D794
    if (!c1cs) {
        // 0x8008D768: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8008D794;
    }
    // 0x8008D768: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8008D76C: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8008D770: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008D774: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8008D778: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8008D77C: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8008D780: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8008D784: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8008D788: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8008D78C: jal         0x800857DC
    // 0x8008D790: add.s       $f12, $f8, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f22.fl;
    HUD_BoostGaugeOverheat_Draw(rdram, ctx);
        goto after_4;
    // 0x8008D790: add.s       $f12, $f8, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f22.fl;
    after_4:
L_8008D794:
    // 0x8008D794: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8008D798: jal         0x800B8DD0
    // 0x8008D79C: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_5;
    // 0x8008D79C: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_5:
    // 0x8008D7A0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8008D7A4: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x8008D7A8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8008D7AC: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x8008D7B0: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8008D7B4: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x8008D7B8: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8008D7BC: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8008D7C0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8008D7C4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8008D7C8: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8008D7CC: jal         0x80085740
    // 0x8008D7D0: lwc1        $f14, 0x0($t3)
    ctx->f14.u32l = MEM_W(ctx->r11, 0X0);
    HUD_BoostGaugeFrame_Draw(rdram, ctx);
        goto after_6;
    // 0x8008D7D0: lwc1        $f14, 0x0($t3)
    ctx->f14.u32l = MEM_W(ctx->r11, 0X0);
    after_6:
    // 0x8008D7D4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8008D7D8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8008D7DC: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8008D7E0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8008D7E4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8008D7E8: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8008D7EC: jr          $ra
    // 0x8008D7F0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8008D7F0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void AudioSeq_AudioListPushBack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800145BC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800145C0: bne         $t6, $zero, L_800145F4
    if (ctx->r14 != 0) {
        // 0x800145C4: nop
    
            goto L_800145F4;
    }
    // 0x800145C4: nop

    // 0x800145C8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800145CC: sw          $a1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r5;
    // 0x800145D0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800145D4: sw          $a0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r4;
    // 0x800145D8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800145DC: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800145E0: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x800145E4: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800145E8: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800145EC: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
    // 0x800145F0: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
L_800145F4:
    // 0x800145F4: jr          $ra
    // 0x800145F8: nop

    return;
    // 0x800145F8: nop

;}
RECOMP_FUNC void func_tank_80043B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043B18: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80043B1C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80043B20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80043B24: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80043B28: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80043B2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80043B30: lwc1        $f4, 0x18C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18C);
    // 0x80043B34: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80043B38: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80043B3C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80043B40: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80043B44: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80043B48: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80043B4C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80043B50: jal         0x80005B00
    // 0x80043B54: nop

    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x80043B54: nop

    after_0:
    // 0x80043B58: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80043B5C: lwc1        $f16, 0x5620($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5620);
    // 0x80043B60: lwc1        $f10, 0x114($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80043B64: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80043B68: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80043B6C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80043B70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80043B74: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80043B78: jal         0x80005E90
    // 0x80043B7C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x80043B7C: nop

    after_1:
    // 0x80043B80: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80043B84: lwc1        $f6, 0x5624($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5624);
    // 0x80043B88: lwc1        $f4, 0xE4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x80043B8C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80043B90: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80043B94: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80043B98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80043B9C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80043BA0: jal         0x80005D44
    // 0x80043BA4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x80043BA4: nop

    after_2:
    // 0x80043BA8: lwc1        $f10, 0xEC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80043BAC: lwc1        $f16, 0xF0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x80043BB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80043BB4: lwc1        $f4, 0x5628($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5628);
    // 0x80043BB8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80043BBC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80043BC0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80043BC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80043BC8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80043BCC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80043BD0: jal         0x80005FE0
    // 0x80043BD4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x80043BD4: nop

    after_3:
    // 0x80043BD8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80043BDC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80043BE0: lwc1        $f8, 0xE8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x80043BE4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80043BE8: lwc1        $f18, 0x562C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X562C);
    // 0x80043BEC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80043BF0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80043BF4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80043BF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80043BFC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80043C00: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80043C04: jal         0x80005E90
    // 0x80043C08: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x80043C08: nop

    after_4:
    // 0x80043C0C: lwc1        $f6, 0x12C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x80043C10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80043C14: lwc1        $f10, 0x5630($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5630);
    // 0x80043C18: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80043C1C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80043C20: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80043C24: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80043C28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80043C2C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80043C30: jal         0x80005FE0
    // 0x80043C34: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_5;
    // 0x80043C34: nop

    after_5:
    // 0x80043C38: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80043C3C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80043C40: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80043C44: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80043C48: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80043C4C: lui         $a2, 0xC1F0
    ctx->r6 = S32(0XC1F0 << 16);
    // 0x80043C50: jal         0x80005B00
    // 0x80043C54: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_6;
    // 0x80043C54: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_6:
    // 0x80043C58: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80043C5C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80043C60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80043C64: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x80043C68: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x80043C6C: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x80043C70: lw          $t7, 0x1DC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1DC);
    // 0x80043C74: lwc1        $f2, 0x114($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80043C78: beql        $t7, $zero, L_80043E18
    if (ctx->r15 == 0) {
        // 0x80043C7C: lwc1        $f0, 0x12C($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X12C);
            goto L_80043E18;
    }
    goto skip_0;
    // 0x80043C7C: lwc1        $f0, 0x12C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X12C);
    skip_0:
    // 0x80043C80: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80043C84: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x80043C88: jal         0x80004EB0
    // 0x80043C8C: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x80043C8C: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x80043C90: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80043C94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80043C98: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80043C9C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80043CA0: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80043CA4: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80043CA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80043CAC: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80043CB0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80043CB4: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80043CB8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80043CBC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80043CC0: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80043CC4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80043CC8: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x80043CCC: lw          $t8, 0x1EC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1EC);
    // 0x80043CD0: bgezl       $t8, L_80043CEC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80043CD4: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_80043CEC;
    }
    goto skip_1;
    // 0x80043CD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_1:
    // 0x80043CD8: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80043CDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80043CE0: b           L_80043CF4
    // 0x80043CE4: sub.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f8.fl;
        goto L_80043CF4;
    // 0x80043CE4: sub.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80043CE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_80043CEC:
    // 0x80043CEC: nop

    // 0x80043CF0: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
L_80043CF4:
    // 0x80043CF4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80043CF8: jal         0x80006970
    // 0x80043CFC: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_8;
    // 0x80043CFC: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    after_8:
    // 0x80043D00: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80043D04: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x80043D08: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80043D0C: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80043D10: bne         $t9, $at, L_80043D58
    if (ctx->r25 != ctx->r1) {
        // 0x80043D14: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_80043D58;
    }
    // 0x80043D14: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043D18: lwc1        $f16, 0x74($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80043D1C: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80043D20: lwc1        $f8, 0x138($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80043D24: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80043D28: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80043D2C: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80043D30: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80043D34: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80043D38: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80043D3C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80043D40: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80043D44: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80043D48: jal         0x80043AA0
    // 0x80043D4C: nop

    func_tank_80043AA0(rdram, ctx);
        goto after_9;
    // 0x80043D4C: nop

    after_9:
    // 0x80043D50: b           L_80044110
    // 0x80043D54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80044110;
    // 0x80043D54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80043D58:
    // 0x80043D58: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x80043D5C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80043D60: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x80043D64: bnel        $t0, $zero, L_80043DB8
    if (ctx->r8 != 0) {
        // 0x80043D68: andi        $t1, $v0, 0x3
        ctx->r9 = ctx->r2 & 0X3;
            goto L_80043DB8;
    }
    goto skip_2;
    // 0x80043D68: andi        $t1, $v0, 0x3
    ctx->r9 = ctx->r2 & 0X3;
    skip_2:
    // 0x80043D6C: lwc1        $f18, 0x138($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80043D70: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80043D74: lwc1        $f10, 0xE8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x80043D78: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80043D7C: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80043D80: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80043D84: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80043D88: add.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80043D8C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80043D90: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80043D94: add.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80043D98: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80043D9C: lwc1        $f10, 0x5634($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5634);
    // 0x80043DA0: add.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80043DA4: jal         0x80189120
    // 0x80043DA8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Titania_TankTracks_Spawn(rdram, ctx);
        goto after_10;
    // 0x80043DA8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x80043DAC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043DB0: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x80043DB4: andi        $t1, $v0, 0x3
    ctx->r9 = ctx->r2 & 0X3;
L_80043DB8:
    // 0x80043DB8: bne         $t1, $zero, L_8004410C
    if (ctx->r9 != 0) {
        // 0x80043DBC: lwc1        $f16, 0x3C($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_8004410C;
    }
    // 0x80043DBC: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80043DC0: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80043DC4: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80043DC8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80043DCC: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80043DD0: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80043DD4: lwc1        $f10, 0x138($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80043DD8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80043DDC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80043DE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80043DE4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80043DE8: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80043DEC: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x80043DF0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80043DF4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80043DF8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80043DFC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80043E00: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80043E04: jal         0x8007A900
    // 0x80043E08: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    Effect_Effect359_Spawn(rdram, ctx);
        goto after_11;
    // 0x80043E08: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    after_11:
    // 0x80043E0C: b           L_80044110
    // 0x80043E10: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80044110;
    // 0x80043E10: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80043E14: lwc1        $f0, 0x12C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X12C);
L_80043E18:
    // 0x80043E18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80043E1C: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x80043E20: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80043E24: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80043E28: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80043E2C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80043E30: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80043E34: bc1fl       L_80043F9C
    if (!c1cs) {
        // 0x80043E38: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_80043F9C;
    }
    goto skip_3;
    // 0x80043E38: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_3:
    // 0x80043E3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80043E40: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80043E44: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x80043E48: jal         0x80006970
    // 0x80043E4C: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_12;
    // 0x80043E4C: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x80043E50: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80043E54: lw          $t4, -0x7DCC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7DCC);
    // 0x80043E58: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80043E5C: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80043E60: bne         $t4, $at, L_80043EBC
    if (ctx->r12 != ctx->r1) {
        // 0x80043E64: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_80043EBC;
    }
    // 0x80043E64: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043E68: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80043E6C: lw          $t5, 0x7DB0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DB0);
    // 0x80043E70: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80043E74: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80043E78: beql        $t6, $zero, L_80043F9C
    if (ctx->r14 == 0) {
        // 0x80043E7C: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_80043F9C;
    }
    goto skip_4;
    // 0x80043E7C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_4:
    // 0x80043E80: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80043E84: lwc1        $f4, 0x138($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80043E88: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80043E8C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80043E90: lwc1        $f16, 0x78($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80043E94: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80043E98: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80043E9C: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80043EA0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80043EA4: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x80043EA8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80043EAC: jal         0x80043AA0
    // 0x80043EB0: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    func_tank_80043AA0(rdram, ctx);
        goto after_13;
    // 0x80043EB0: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    after_13:
    // 0x80043EB4: b           L_80043F98
    // 0x80043EB8: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
        goto L_80043F98;
    // 0x80043EB8: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
L_80043EBC:
    // 0x80043EBC: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x80043EC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80043EC4: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x80043EC8: bnel        $t7, $zero, L_80043F24
    if (ctx->r15 != 0) {
        // 0x80043ECC: andi        $t8, $v0, 0x3
        ctx->r24 = ctx->r2 & 0X3;
            goto L_80043F24;
    }
    goto skip_5;
    // 0x80043ECC: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    skip_5:
    // 0x80043ED0: lwc1        $f18, 0x138($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80043ED4: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80043ED8: lwc1        $f10, 0xE8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x80043EDC: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80043EE0: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80043EE4: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80043EE8: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80043EEC: add.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80043EF0: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80043EF4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80043EF8: add.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80043EFC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80043F00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80043F04: add.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80043F08: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x80043F0C: jal         0x80189120
    // 0x80043F10: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Titania_TankTracks_Spawn(rdram, ctx);
        goto after_14;
    // 0x80043F10: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_14:
    // 0x80043F14: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043F18: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x80043F1C: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80043F20: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
L_80043F24:
    // 0x80043F24: bne         $t8, $zero, L_80043F98
    if (ctx->r24 != 0) {
        // 0x80043F28: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_80043F98;
    }
    // 0x80043F28: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80043F2C: lwc1        $f6, 0xD0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x80043F30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80043F34: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80043F38: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80043F3C: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80043F40: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80043F44: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80043F48: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80043F4C: bc1fl       L_80043F9C
    if (!c1cs) {
        // 0x80043F50: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_80043F9C;
    }
    goto skip_6;
    // 0x80043F50: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_6:
    // 0x80043F54: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80043F58: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80043F5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80043F60: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80043F64: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80043F68: lwc1        $f10, 0x138($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80043F6C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80043F70: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x80043F74: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80043F78: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80043F7C: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x80043F80: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80043F84: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80043F88: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80043F8C: jal         0x8007A900
    // 0x80043F90: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    Effect_Effect359_Spawn(rdram, ctx);
        goto after_15;
    // 0x80043F90: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    after_15:
    // 0x80043F94: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
L_80043F98:
    // 0x80043F98: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_80043F9C:
    // 0x80043F9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80043FA0: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x80043FA4: lui         $at, 0xC210
    ctx->r1 = S32(0XC210 << 16);
    // 0x80043FA8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80043FAC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80043FB0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80043FB4: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80043FB8: bc1fl       L_80044110
    if (!c1cs) {
        // 0x80043FBC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80044110;
    }
    goto skip_7;
    // 0x80043FBC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_7:
    // 0x80043FC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80043FC4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80043FC8: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x80043FCC: jal         0x80006970
    // 0x80043FD0: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_16;
    // 0x80043FD0: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    after_16:
    // 0x80043FD4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80043FD8: lw          $t1, -0x7DCC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7DCC);
    // 0x80043FDC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80043FE0: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80043FE4: bne         $t1, $at, L_80044040
    if (ctx->r9 != ctx->r1) {
        // 0x80043FE8: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_80044040;
    }
    // 0x80043FE8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043FEC: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80043FF0: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x80043FF4: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80043FF8: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80043FFC: bnel        $t3, $zero, L_80044110
    if (ctx->r11 != 0) {
        // 0x80044000: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80044110;
    }
    goto skip_8;
    // 0x80044000: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_8:
    // 0x80044004: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80044008: lwc1        $f6, 0x138($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8004400C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80044010: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80044014: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80044018: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8004401C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80044020: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80044024: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80044028: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8004402C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80044030: jal         0x80043AA0
    // 0x80044034: nop

    func_tank_80043AA0(rdram, ctx);
        goto after_17;
    // 0x80044034: nop

    after_17:
    // 0x80044038: b           L_80044110
    // 0x8004403C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80044110;
    // 0x8004403C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80044040:
    // 0x80044040: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x80044044: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80044048: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x8004404C: bnel        $t4, $zero, L_800440A0
    if (ctx->r12 != 0) {
        // 0x80044050: andi        $t5, $v0, 0x3
        ctx->r13 = ctx->r2 & 0X3;
            goto L_800440A0;
    }
    goto skip_9;
    // 0x80044050: andi        $t5, $v0, 0x3
    ctx->r13 = ctx->r2 & 0X3;
    skip_9:
    // 0x80044054: lwc1        $f18, 0x138($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80044058: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8004405C: lwc1        $f10, 0xE8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x80044060: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80044064: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80044068: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8004406C: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80044070: add.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80044074: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80044078: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8004407C: add.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80044080: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80044084: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80044088: add.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8004408C: jal         0x80189120
    // 0x80044090: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Titania_TankTracks_Spawn(rdram, ctx);
        goto after_18;
    // 0x80044090: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_18:
    // 0x80044094: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80044098: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x8004409C: andi        $t5, $v0, 0x3
    ctx->r13 = ctx->r2 & 0X3;
L_800440A0:
    // 0x800440A0: bne         $t5, $zero, L_8004410C
    if (ctx->r13 != 0) {
        // 0x800440A4: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_8004410C;
    }
    // 0x800440A4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800440A8: lwc1        $f8, 0xD0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x800440AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800440B0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800440B4: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800440B8: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x800440BC: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800440C0: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x800440C4: bc1fl       L_80044110
    if (!c1cs) {
        // 0x800440C8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80044110;
    }
    goto skip_10;
    // 0x800440C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_10:
    // 0x800440CC: lwc1        $f16, 0x74($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800440D0: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800440D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800440D8: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800440DC: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800440E0: lwc1        $f16, 0x138($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800440E4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800440E8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800440EC: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x800440F0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800440F4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800440F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800440FC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80044100: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80044104: jal         0x8007A900
    // 0x80044108: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    Effect_Effect359_Spawn(rdram, ctx);
        goto after_19;
    // 0x80044108: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    after_19:
L_8004410C:
    // 0x8004410C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80044110:
    // 0x80044110: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80044114: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80044118: jr          $ra
    // 0x8004411C: nop

    return;
    // 0x8004411C: nop

;}
RECOMP_FUNC void AudioHeap_ResetStep(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D104: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000D108: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000D10C: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x8000D110: addiu       $s0, $s0, 0x5C78
    ctx->r16 = ADD32(ctx->r16, 0X5C78);
    // 0x8000D114: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8000D118: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000D11C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000D120: bne         $t6, $at, L_8000D134
    if (ctx->r14 != ctx->r1) {
        // 0x8000D124: lui         $t0, 0x8015
        ctx->r8 = S32(0X8015 << 16);
            goto L_8000D134;
    }
    // 0x8000D124: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8000D128: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8000D12C: b           L_8000D13C
    // 0x8000D130: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_8000D13C;
    // 0x8000D130: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_8000D134:
    // 0x8000D134: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000D138: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_8000D13C:
    // 0x8000D13C: addiu       $t0, $t0, -0x2AD8
    ctx->r8 = ADD32(ctx->r8, -0X2AD8);
    // 0x8000D140: lbu         $t9, 0x0($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X0);
    // 0x8000D144: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x8000D148: sltiu       $at, $t1, 0x5
    ctx->r1 = ctx->r9 < 0X5 ? 1 : 0;
    // 0x8000D14C: beq         $at, $zero, L_8000D47C
    if (ctx->r1 == 0) {
        // 0x8000D150: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8000D47C;
    }
    // 0x8000D150: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8000D154: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000D158: addu        $at, $at, $t1
    gpr jr_addend_8000D160 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8000D15C: lw          $t1, -0x799C($at)
    ctx->r9 = ADD32(ctx->r1, -0X799C);
    // 0x8000D160: jr          $t1
    // 0x8000D164: nop

    switch (jr_addend_8000D160 >> 2) {
        case 0: goto L_8000D3F4; break;
        case 1: goto L_8000D3A4; break;
        case 2: goto L_8000D2D4; break;
        case 3: goto L_8000D1EC; break;
        case 4: goto L_8000D168; break;
        default: switch_error(__func__, 0x8000D160, 0x800C8664);
    }
    // 0x8000D164: nop

L_8000D168:
    // 0x8000D168: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x8000D16C: addiu       $s0, $s0, -0x1AC8
    ctx->r16 = ADD32(ctx->r16, -0X1AC8);
L_8000D170:
    // 0x8000D170: jal         0x800144E4
    // 0x8000D174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_SequencePlayerDisable(rdram, ctx);
        goto after_0;
    // 0x8000D174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000D178: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8000D17C: addiu       $t2, $t2, -0x1598
    ctx->r10 = ADD32(ctx->r10, -0X1598);
    // 0x8000D180: addiu       $s0, $s0, 0x14C
    ctx->r16 = ADD32(ctx->r16, 0X14C);
    // 0x8000D184: bne         $s0, $t2, L_8000D170
    if (ctx->r16 != ctx->r10) {
        // 0x8000D188: nop
    
            goto L_8000D170;
    }
    // 0x8000D188: nop

    // 0x8000D18C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8000D190: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8000D194: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8000D198: div         $zero, $t4, $t3
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r11)));
    // 0x8000D19C: addiu       $a3, $a3, -0x2AD4
    ctx->r7 = ADD32(ctx->r7, -0X2AD4);
    // 0x8000D1A0: mflo        $t5
    ctx->r13 = lo;
    // 0x8000D1A4: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8000D1A8: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x8000D1AC: addiu       $t6, $t6, -0x2AD8
    ctx->r14 = ADD32(ctx->r14, -0X2AD8);
    // 0x8000D1B0: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x8000D1B4: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8000D1B8: bne         $t3, $zero, L_8000D1C4
    if (ctx->r11 != 0) {
        // 0x8000D1BC: nop
    
            goto L_8000D1C4;
    }
    // 0x8000D1BC: nop

    // 0x8000D1C0: break       7
    do_break(2147537344);
L_8000D1C4:
    // 0x8000D1C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000D1C8: bne         $t3, $at, L_8000D1DC
    if (ctx->r11 != ctx->r1) {
        // 0x8000D1CC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000D1DC;
    }
    // 0x8000D1CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000D1D0: bne         $t4, $at, L_8000D1DC
    if (ctx->r12 != ctx->r1) {
        // 0x8000D1D4: nop
    
            goto L_8000D1DC;
    }
    // 0x8000D1D4: nop

    // 0x8000D1D8: break       6
    do_break(2147537368);
L_8000D1DC:
    // 0x8000D1DC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8000D1E0: sb          $t7, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r15;
    // 0x8000D1E4: b           L_8000D47C
    // 0x8000D1E8: addiu       $t0, $t0, -0x2AD8
    ctx->r8 = ADD32(ctx->r8, -0X2AD8);
        goto L_8000D47C;
    // 0x8000D1E8: addiu       $t0, $t0, -0x2AD8
    ctx->r8 = ADD32(ctx->r8, -0X2AD8);
L_8000D1EC:
    // 0x8000D1EC: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8000D1F0: addiu       $a3, $a3, -0x2AD4
    ctx->r7 = ADD32(ctx->r7, -0X2AD4);
    // 0x8000D1F4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8000D1F8: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8000D1FC: beq         $v0, $zero, L_8000D218
    if (ctx->r2 == 0) {
        // 0x8000D200: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_8000D218;
    }
    // 0x8000D200: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8000D204: jal         0x8000CEC8
    // 0x8000D208: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    AudioHeap_UpdateReverbs(rdram, ctx);
        goto after_1;
    // 0x8000D208: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    after_1:
    // 0x8000D20C: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8000D210: b           L_8000D47C
    // 0x8000D214: addiu       $t0, $t0, -0x2AD8
    ctx->r8 = ADD32(ctx->r8, -0X2AD8);
        goto L_8000D47C;
    // 0x8000D214: addiu       $t0, $t0, -0x2AD8
    ctx->r8 = ADD32(ctx->r8, -0X2AD8);
L_8000D218:
    // 0x8000D218: lw          $a2, 0x5CA0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5CA0);
    // 0x8000D21C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000D220: blezl       $a2, L_8000D290
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8000D224: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_8000D290;
    }
    goto skip_0;
    // 0x8000D224: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8000D228: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000D22C: addiu       $a1, $a1, -0x1AD0
    ctx->r5 = ADD32(ctx->r5, -0X1AD0);
    // 0x8000D230: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000D234:
    // 0x8000D234: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8000D238: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000D23C: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x8000D240: lw          $t1, 0xB0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XB0);
    // 0x8000D244: srl         $t2, $t1, 31
    ctx->r10 = S32(U32(ctx->r9) >> 31);
    // 0x8000D248: beql        $t2, $zero, L_8000D284
    if (ctx->r10 == 0) {
        // 0x8000D24C: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8000D284;
    }
    goto skip_1;
    // 0x8000D24C: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_1:
    // 0x8000D250: lbu         $t4, 0x59($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X59);
    // 0x8000D254: beql        $t4, $zero, L_8000D284
    if (ctx->r12 == 0) {
        // 0x8000D258: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8000D284;
    }
    goto skip_2;
    // 0x8000D258: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_2:
    // 0x8000D25C: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8000D260: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8000D264: swc1        $f4, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f4.u32l;
    // 0x8000D268: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8000D26C: addu        $v0, $t3, $v1
    ctx->r2 = ADD32(ctx->r11, ctx->r3);
    // 0x8000D270: lbu         $t5, 0x58($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X58);
    // 0x8000D274: ori         $t7, $t5, 0x10
    ctx->r15 = ctx->r13 | 0X10;
    // 0x8000D278: sb          $t7, 0x58($v0)
    MEM_B(0X58, ctx->r2) = ctx->r15;
    // 0x8000D27C: lw          $a2, 0x5CA0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5CA0);
    // 0x8000D280: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
L_8000D284:
    // 0x8000D284: bne         $at, $zero, L_8000D234
    if (ctx->r1 != 0) {
        // 0x8000D288: addiu       $v1, $v1, 0xC0
        ctx->r3 = ADD32(ctx->r3, 0XC0);
            goto L_8000D234;
    }
    // 0x8000D288: addiu       $v1, $v1, 0xC0
    ctx->r3 = ADD32(ctx->r3, 0XC0);
    // 0x8000D28C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_8000D290:
    // 0x8000D290: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8000D294: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x8000D298: div         $zero, $t8, $t6
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r14)));
    // 0x8000D29C: mflo        $t9
    ctx->r25 = lo;
    // 0x8000D2A0: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x8000D2A4: bne         $t6, $zero, L_8000D2B0
    if (ctx->r14 != 0) {
        // 0x8000D2A8: nop
    
            goto L_8000D2B0;
    }
    // 0x8000D2A8: nop

    // 0x8000D2AC: break       7
    do_break(2147537580);
L_8000D2B0:
    // 0x8000D2B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000D2B4: bne         $t6, $at, L_8000D2C8
    if (ctx->r14 != ctx->r1) {
        // 0x8000D2B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000D2C8;
    }
    // 0x8000D2B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000D2BC: bne         $t8, $at, L_8000D2C8
    if (ctx->r24 != ctx->r1) {
        // 0x8000D2C0: nop
    
            goto L_8000D2C8;
    }
    // 0x8000D2C0: nop

    // 0x8000D2C4: break       6
    do_break(2147537604);
L_8000D2C8:
    // 0x8000D2C8: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8000D2CC: b           L_8000D47C
    // 0x8000D2D0: sb          $t1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r9;
        goto L_8000D47C;
    // 0x8000D2D0: sb          $t1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r9;
L_8000D2D4:
    // 0x8000D2D4: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8000D2D8: addiu       $a3, $a3, -0x2AD4
    ctx->r7 = ADD32(ctx->r7, -0X2AD4);
    // 0x8000D2DC: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8000D2E0: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8000D2E4: addiu       $v1, $v1, 0x5D70
    ctx->r3 = ADD32(ctx->r3, 0X5D70);
    // 0x8000D2E8: beq         $v0, $zero, L_8000D308
    if (ctx->r2 == 0) {
        // 0x8000D2EC: lui         $a1, 0x8015
        ctx->r5 = S32(0X8015 << 16);
            goto L_8000D308;
    }
    // 0x8000D2EC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000D2F0: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x8000D2F4: jal         0x8000CEC8
    // 0x8000D2F8: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    AudioHeap_UpdateReverbs(rdram, ctx);
        goto after_2;
    // 0x8000D2F8: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    after_2:
    // 0x8000D2FC: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8000D300: b           L_8000D47C
    // 0x8000D304: addiu       $t0, $t0, -0x2AD8
    ctx->r8 = ADD32(ctx->r8, -0X2AD8);
        goto L_8000D47C;
    // 0x8000D304: addiu       $t0, $t0, -0x2AD8
    ctx->r8 = ADD32(ctx->r8, -0X2AD8);
L_8000D308:
    // 0x8000D308: addiu       $a1, $a1, 0x5D7C
    ctx->r5 = ADD32(ctx->r5, 0X5D7C);
    // 0x8000D30C: addiu       $a0, $zero, 0x1540
    ctx->r4 = ADD32(0, 0X1540);
    // 0x8000D310: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8000D314:
    // 0x8000D314: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000D318:
    // 0x8000D318: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8000D31C: addu        $t3, $t4, $v0
    ctx->r11 = ADD32(ctx->r12, ctx->r2);
    // 0x8000D320: sh          $zero, 0x0($t3)
    MEM_H(0X0, ctx->r11) = 0;
    // 0x8000D324: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8000D328: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x8000D32C: sh          $zero, 0x2($t7)
    MEM_H(0X2, ctx->r15) = 0;
    // 0x8000D330: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8000D334: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x8000D338: sh          $zero, 0x4($t6)
    MEM_H(0X4, ctx->r14) = 0;
    // 0x8000D33C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8000D340: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x8000D344: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8000D348: bne         $v0, $a0, L_8000D318
    if (ctx->r2 != ctx->r4) {
        // 0x8000D34C: sh          $zero, 0x6($t1)
        MEM_H(0X6, ctx->r9) = 0;
            goto L_8000D318;
    }
    // 0x8000D34C: sh          $zero, 0x6($t1)
    MEM_H(0X6, ctx->r9) = 0;
    // 0x8000D350: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000D354: bnel        $v1, $a1, L_8000D314
    if (ctx->r3 != ctx->r5) {
        // 0x8000D358: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8000D314;
    }
    goto skip_3;
    // 0x8000D358: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    skip_3:
    // 0x8000D35C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8000D360: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8000D364: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x8000D368: div         $zero, $t4, $t2
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r10)));
    // 0x8000D36C: mflo        $t3
    ctx->r11 = lo;
    // 0x8000D370: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x8000D374: bne         $t2, $zero, L_8000D380
    if (ctx->r10 != 0) {
        // 0x8000D378: nop
    
            goto L_8000D380;
    }
    // 0x8000D378: nop

    // 0x8000D37C: break       7
    do_break(2147537788);
L_8000D380:
    // 0x8000D380: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000D384: bne         $t2, $at, L_8000D398
    if (ctx->r10 != ctx->r1) {
        // 0x8000D388: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000D398;
    }
    // 0x8000D388: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000D38C: bne         $t4, $at, L_8000D398
    if (ctx->r12 != ctx->r1) {
        // 0x8000D390: nop
    
            goto L_8000D398;
    }
    // 0x8000D390: nop

    // 0x8000D394: break       6
    do_break(2147537812);
L_8000D398:
    // 0x8000D398: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x8000D39C: b           L_8000D47C
    // 0x8000D3A0: sb          $t5, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r13;
        goto L_8000D47C;
    // 0x8000D3A0: sb          $t5, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r13;
L_8000D3A4:
    // 0x8000D3A4: jal         0x8000D08C
    // 0x8000D3A8: nop

    AudioHeap_ClearCurrentAiBuffer(rdram, ctx);
        goto after_3;
    // 0x8000D3A8: nop

    after_3:
    // 0x8000D3AC: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8000D3B0: addiu       $a3, $a3, -0x2AD4
    ctx->r7 = ADD32(ctx->r7, -0X2AD4);
    // 0x8000D3B4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8000D3B8: beq         $v0, $zero, L_8000D3D0
    if (ctx->r2 == 0) {
        // 0x8000D3BC: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8000D3D0;
    }
    // 0x8000D3BC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8000D3C0: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8000D3C4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8000D3C8: b           L_8000D47C
    // 0x8000D3CC: addiu       $t0, $t0, -0x2AD8
    ctx->r8 = ADD32(ctx->r8, -0X2AD8);
        goto L_8000D47C;
    // 0x8000D3CC: addiu       $t0, $t0, -0x2AD8
    ctx->r8 = ADD32(ctx->r8, -0X2AD8);
L_8000D3D0:
    // 0x8000D3D0: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8000D3D4: addiu       $t8, $t8, -0x2AD8
    ctx->r24 = ADD32(ctx->r24, -0X2AD8);
    // 0x8000D3D8: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x8000D3DC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8000D3E0: jal         0x8000E290
    // 0x8000D3E4: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    AudioHeap_DiscardSampleCaches(rdram, ctx);
        goto after_4;
    // 0x8000D3E4: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    after_4:
    // 0x8000D3E8: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8000D3EC: b           L_8000D47C
    // 0x8000D3F0: addiu       $t0, $t0, -0x2AD8
    ctx->r8 = ADD32(ctx->r8, -0X2AD8);
        goto L_8000D47C;
    // 0x8000D3F0: addiu       $t0, $t0, -0x2AD8
    ctx->r8 = ADD32(ctx->r8, -0X2AD8);
L_8000D3F4:
    // 0x8000D3F4: jal         0x8000D4A8
    // 0x8000D3F8: nop

    AudioHeap_Init(rdram, ctx);
        goto after_5;
    // 0x8000D3F8: nop

    after_5:
    // 0x8000D3FC: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8000D400: addiu       $t9, $t9, -0x2AD8
    ctx->r25 = ADD32(ctx->r25, -0X2AD8);
    // 0x8000D404: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8000D408: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000D40C: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8000D410: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x8000D414: addiu       $a3, $a3, 0x5D82
    ctx->r7 = ADD32(ctx->r7, 0X5D82);
    // 0x8000D418: addiu       $a1, $a1, 0x5D7C
    ctx->r5 = ADD32(ctx->r5, 0X5D7C);
    // 0x8000D41C: addiu       $v1, $v1, 0x5D70
    ctx->r3 = ADD32(ctx->r3, 0X5D70);
    // 0x8000D420: addiu       $a0, $zero, 0x1540
    ctx->r4 = ADD32(0, 0X1540);
L_8000D424:
    // 0x8000D424: lh          $t1, 0x8($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X8);
    // 0x8000D428: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8000D42C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000D430: sh          $t1, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r9;
L_8000D434:
    // 0x8000D434: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8000D438: addu        $t2, $t4, $v0
    ctx->r10 = ADD32(ctx->r12, ctx->r2);
    // 0x8000D43C: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x8000D440: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8000D444: addu        $t5, $t3, $v0
    ctx->r13 = ADD32(ctx->r11, ctx->r2);
    // 0x8000D448: sh          $zero, 0x2($t5)
    MEM_H(0X2, ctx->r13) = 0;
    // 0x8000D44C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8000D450: addu        $t6, $t7, $v0
    ctx->r14 = ADD32(ctx->r15, ctx->r2);
    // 0x8000D454: sh          $zero, 0x4($t6)
    MEM_H(0X4, ctx->r14) = 0;
    // 0x8000D458: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8000D45C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8000D460: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8000D464: bne         $v0, $a0, L_8000D434
    if (ctx->r2 != ctx->r4) {
        // 0x8000D468: sh          $zero, 0x6($t9)
        MEM_H(0X6, ctx->r25) = 0;
            goto L_8000D434;
    }
    // 0x8000D468: sh          $zero, 0x6($t9)
    MEM_H(0X6, ctx->r25) = 0;
    // 0x8000D46C: bne         $a1, $a3, L_8000D424
    if (ctx->r5 != ctx->r7) {
        // 0x8000D470: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000D424;
    }
    // 0x8000D470: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000D474: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8000D478: addiu       $t0, $t0, -0x2AD8
    ctx->r8 = ADD32(ctx->r8, -0X2AD8);
L_8000D47C:
    // 0x8000D47C: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x8000D480: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D484: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x8000D488: beql        $at, $zero, L_8000D49C
    if (ctx->r1 == 0) {
        // 0x8000D48C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000D49C;
    }
    goto skip_4;
    // 0x8000D48C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x8000D490: b           L_8000D49C
    // 0x8000D494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000D49C;
    // 0x8000D494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000D498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000D49C:
    // 0x8000D49C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000D4A0: jr          $ra
    // 0x8000D4A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000D4A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void AudioSynth_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009B64: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80009B68: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80009B6C: lui         $s6, 0x8015
    ctx->r22 = S32(0X8015 << 16);
    // 0x80009B70: addiu       $s6, $s6, 0x5C78
    ctx->r22 = ADD32(ctx->r22, 0X5C78);
    // 0x80009B74: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80009B78: lh          $s4, 0xC($s6)
    ctx->r20 = MEM_H(ctx->r22, 0XC);
    // 0x80009B7C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80009B80: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80009B84: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80009B88: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80009B8C: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x80009B90: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80009B94: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80009B98: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80009B9C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80009BA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80009BA4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80009BA8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80009BAC: blez        $s4, L_80009BD8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80009BB0: or          $fp, $a0, $zero
        ctx->r30 = ctx->r4 | 0;
            goto L_80009BD8;
    }
    // 0x80009BB0: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
L_80009BB4:
    // 0x80009BB4: addiu       $s0, $s4, -0x1
    ctx->r16 = ADD32(ctx->r20, -0X1);
    // 0x80009BB8: jal         0x8001678C
    // 0x80009BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ProcessSequences(rdram, ctx);
        goto after_0;
    // 0x80009BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80009BC0: lh          $t6, 0xC($s6)
    ctx->r14 = MEM_H(ctx->r22, 0XC);
    // 0x80009BC4: jal         0x80009AAC
    // 0x80009BC8: subu        $a0, $t6, $s4
    ctx->r4 = SUB32(ctx->r14, ctx->r20);
    AudioSynth_SyncSampleStates(rdram, ctx);
        goto after_1;
    // 0x80009BC8: subu        $a0, $t6, $s4
    ctx->r4 = SUB32(ctx->r14, ctx->r20);
    after_1:
    // 0x80009BCC: bgtz        $s0, L_80009BB4
    if (SIGNED(ctx->r16) > 0) {
        // 0x80009BD0: or          $s4, $s0, $zero
        ctx->r20 = ctx->r16 | 0;
            goto L_80009BB4;
    }
    // 0x80009BD0: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x80009BD4: lh          $s4, 0xC($s6)
    ctx->r20 = MEM_H(ctx->r22, 0XC);
L_80009BD8:
    // 0x80009BD8: blez        $s4, L_80009CD4
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80009BDC: or          $s7, $s1, $zero
        ctx->r23 = ctx->r17 | 0;
            goto L_80009CD4;
    }
    // 0x80009BDC: or          $s7, $s1, $zero
    ctx->r23 = ctx->r17 | 0;
L_80009BE0:
    // 0x80009BE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80009BE4: lh          $s2, 0xC($s6)
    ctx->r18 = MEM_H(ctx->r22, 0XC);
    // 0x80009BE8: bne         $s4, $at, L_80009BF8
    if (ctx->r20 != ctx->r1) {
        // 0x80009BEC: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80009BF8;
    }
    // 0x80009BEC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80009BF0: b           L_80009C58
    // 0x80009BF4: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
        goto L_80009C58;
    // 0x80009BF4: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
L_80009BF8:
    // 0x80009BF8: div         $zero, $s5, $s4
    lo = S32(S64(S32(ctx->r21)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r21)) % S64(S32(ctx->r20)));
    // 0x80009BFC: bne         $s4, $zero, L_80009C08
    if (ctx->r20 != 0) {
        // 0x80009C00: nop
    
            goto L_80009C08;
    }
    // 0x80009C00: nop

    // 0x80009C04: break       7
    do_break(2147523588);
L_80009C08:
    // 0x80009C08: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80009C0C: bne         $s4, $at, L_80009C20
    if (ctx->r20 != ctx->r1) {
        // 0x80009C10: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80009C20;
    }
    // 0x80009C10: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80009C14: bne         $s5, $at, L_80009C20
    if (ctx->r21 != ctx->r1) {
        // 0x80009C18: nop
    
            goto L_80009C20;
    }
    // 0x80009C18: nop

    // 0x80009C1C: break       6
    do_break(2147523612);
L_80009C20:
    // 0x80009C20: lh          $v1, 0x10($s6)
    ctx->r3 = MEM_H(ctx->r22, 0X10);
    // 0x80009C24: mflo        $v0
    ctx->r2 = lo;
    // 0x80009C28: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80009C2C: bnel        $at, $zero, L_80009C40
    if (ctx->r1 != 0) {
        // 0x80009C30: lh          $v1, 0x12($s6)
        ctx->r3 = MEM_H(ctx->r22, 0X12);
            goto L_80009C40;
    }
    goto skip_0;
    // 0x80009C30: lh          $v1, 0x12($s6)
    ctx->r3 = MEM_H(ctx->r22, 0X12);
    skip_0:
    // 0x80009C34: b           L_80009C58
    // 0x80009C38: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
        goto L_80009C58;
    // 0x80009C38: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    // 0x80009C3C: lh          $v1, 0x12($s6)
    ctx->r3 = MEM_H(ctx->r22, 0X12);
L_80009C40:
    // 0x80009C40: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009C44: bnel        $at, $zero, L_80009C58
    if (ctx->r1 != 0) {
        // 0x80009C48: lh          $s3, 0xE($s6)
        ctx->r19 = MEM_H(ctx->r22, 0XE);
            goto L_80009C58;
    }
    goto skip_1;
    // 0x80009C48: lh          $s3, 0xE($s6)
    ctx->r19 = MEM_H(ctx->r22, 0XE);
    skip_1:
    // 0x80009C4C: b           L_80009C58
    // 0x80009C50: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
        goto L_80009C58;
    // 0x80009C50: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
    // 0x80009C54: lh          $s3, 0xE($s6)
    ctx->r19 = MEM_H(ctx->r22, 0XE);
L_80009C58:
    // 0x80009C58: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80009C5C: lb          $v0, -0x3E4D($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X3E4D);
    // 0x80009C60: blezl       $v0, L_80009CAC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80009C64: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80009CAC;
    }
    goto skip_2;
    // 0x80009C64: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    skip_2:
    // 0x80009C68: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x80009C6C: addiu       $s0, $s0, -0x45B0
    ctx->r16 = ADD32(ctx->r16, -0X45B0);
L_80009C70:
    // 0x80009C70: lbu         $t7, 0x1($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1);
    // 0x80009C74: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80009C78: subu        $a1, $s2, $s4
    ctx->r5 = SUB32(ctx->r18, ctx->r20);
    // 0x80009C7C: beql        $t7, $zero, L_80009C9C
    if (ctx->r15 == 0) {
        // 0x80009C80: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80009C9C;
    }
    goto skip_3;
    // 0x80009C80: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_3:
    // 0x80009C84: jal         0x800080C0
    // 0x80009C88: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    AudioSynth_InitNextRingBuf(rdram, ctx);
        goto after_2;
    // 0x80009C88: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_2:
    // 0x80009C8C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80009C90: lb          $v0, -0x3E4D($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X3E4D);
    // 0x80009C94: lh          $s2, 0xC($s6)
    ctx->r18 = MEM_H(ctx->r22, 0XC);
    // 0x80009C98: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80009C9C:
    // 0x80009C9C: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009CA0: bne         $at, $zero, L_80009C70
    if (ctx->r1 != 0) {
        // 0x80009CA4: addiu       $s0, $s0, 0x1D4
        ctx->r16 = ADD32(ctx->r16, 0X1D4);
            goto L_80009C70;
    }
    // 0x80009CA4: addiu       $s0, $s0, 0x1D4
    ctx->r16 = ADD32(ctx->r16, 0X1D4);
    // 0x80009CA8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
L_80009CAC:
    // 0x80009CAC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80009CB0: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x80009CB4: jal         0x8000A25C
    // 0x80009CB8: subu        $a3, $s2, $s4
    ctx->r7 = SUB32(ctx->r18, ctx->r20);
    AudioSynth_DoOneAudioUpdate(rdram, ctx);
        goto after_3;
    // 0x80009CB8: subu        $a3, $s2, $s4
    ctx->r7 = SUB32(ctx->r18, ctx->r20);
    after_3:
    // 0x80009CBC: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x80009CC0: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x80009CC4: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x80009CC8: subu        $s5, $s5, $s3
    ctx->r21 = SUB32(ctx->r21, ctx->r19);
    // 0x80009CCC: bgtz        $s4, L_80009BE0
    if (SIGNED(ctx->r20) > 0) {
        // 0x80009CD0: addu        $s7, $s7, $t8
        ctx->r23 = ADD32(ctx->r23, ctx->r24);
            goto L_80009BE0;
    }
    // 0x80009CD0: addu        $s7, $s7, $t8
    ctx->r23 = ADD32(ctx->r23, ctx->r24);
L_80009CD4:
    // 0x80009CD4: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80009CD8: lb          $v0, -0x3E4D($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X3E4D);
    // 0x80009CDC: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80009CE0: addiu       $s0, $t9, -0x45B0
    ctx->r16 = ADD32(ctx->r25, -0X45B0);
    // 0x80009CE4: blez        $v0, L_80009D30
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80009CE8: sll         $t0, $v0, 3
        ctx->r8 = S32(ctx->r2 << 3);
            goto L_80009D30;
    }
    // 0x80009CE8: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x80009CEC: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x80009CF0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80009CF4: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x80009CF8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80009CFC: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x80009D00: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80009D04: addu        $v1, $t0, $s0
    ctx->r3 = ADD32(ctx->r8, ctx->r16);
L_80009D08:
    // 0x80009D08: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x80009D0C: beq         $v0, $zero, L_80009D18
    if (ctx->r2 == 0) {
        // 0x80009D10: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_80009D18;
    }
    // 0x80009D10: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x80009D14: sb          $t1, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r9;
L_80009D18:
    // 0x80009D18: lbu         $t2, 0x3($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X3);
    // 0x80009D1C: addiu       $s0, $s0, 0x1D4
    ctx->r16 = ADD32(ctx->r16, 0X1D4);
    // 0x80009D20: sltu        $at, $s0, $v1
    ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80009D24: xori        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 ^ 0X1;
    // 0x80009D28: bne         $at, $zero, L_80009D08
    if (ctx->r1 != 0) {
        // 0x80009D2C: sb          $t3, -0x1D1($s0)
        MEM_B(-0X1D1, ctx->r16) = ctx->r11;
            goto L_80009D08;
    }
    // 0x80009D2C: sb          $t3, -0x1D1($s0)
    MEM_B(-0X1D1, ctx->r16) = ctx->r11;
L_80009D30:
    // 0x80009D30: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80009D34: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80009D38: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
    // 0x80009D3C: subu        $t5, $fp, $t4
    ctx->r13 = SUB32(ctx->r30, ctx->r12);
    // 0x80009D40: sra         $t6, $t5, 3
    ctx->r14 = S32(SIGNED(ctx->r13) >> 3);
    // 0x80009D44: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80009D48: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80009D4C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80009D50: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80009D54: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80009D58: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80009D5C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80009D60: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80009D64: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80009D68: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80009D6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80009D70: jr          $ra
    // 0x80009D74: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80009D74: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Player_UpdateHitbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A887C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800A8880: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800A8884: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x800A8888: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800A888C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A8890: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x800A8894: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A8898: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x800A889C: lw          $a2, 0x78($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X78);
    // 0x800A88A0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x800A88A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A88A8: jal         0x80005B00
    // 0x800A88AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x800A88AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x800A88B0: lw          $v0, 0x1CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1CC);
    // 0x800A88B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A88B8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800A88BC: bne         $v0, $at, L_800A8954
    if (ctx->r2 != ctx->r1) {
        // 0x800A88C0: addiu       $a2, $s0, 0x2C8
        ctx->r6 = ADD32(ctx->r16, 0X2C8);
            goto L_800A8954;
    }
    // 0x800A88C0: addiu       $a2, $s0, 0x2C8
    ctx->r6 = ADD32(ctx->r16, 0X2C8);
    // 0x800A88C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A88C8: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x800A88CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A88D0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800A88D4: swc1        $f0, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f0.u32l;
    // 0x800A88D8: swc1        $f0, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->f0.u32l;
    // 0x800A88DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A88E0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A88E4: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800A88E8: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800A88EC: jal         0x80006970
    // 0x800A88F0: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_1;
    // 0x800A88F0: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800A88F4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800A88F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A88FC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A8900: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800A8904: addiu       $a2, $s0, 0x2D4
    ctx->r6 = ADD32(ctx->r16, 0X2D4);
    // 0x800A8908: jal         0x80006970
    // 0x800A890C: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x800A890C: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x800A8910: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x800A8914: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800A8918: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A891C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A8920: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800A8924: addiu       $a2, $s0, 0x2E0
    ctx->r6 = ADD32(ctx->r16, 0X2E0);
    // 0x800A8928: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x800A892C: jal         0x80006970
    // 0x800A8930: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_3;
    // 0x800A8930: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x800A8934: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800A8938: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A893C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A8940: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800A8944: addiu       $a2, $s0, 0x2EC
    ctx->r6 = ADD32(ctx->r16, 0X2EC);
    // 0x800A8948: jal         0x80006970
    // 0x800A894C: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x800A894C: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x800A8950: lw          $v0, 0x1CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1CC);
L_800A8954:
    // 0x800A8954: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A8958: beq         $v0, $at, L_800A8968
    if (ctx->r2 == ctx->r1) {
        // 0x800A895C: addiu       $a1, $sp, 0x3C
        ctx->r5 = ADD32(ctx->r29, 0X3C);
            goto L_800A8968;
    }
    // 0x800A895C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800A8960: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A8964: bne         $v0, $at, L_800A8A04
    if (ctx->r2 != ctx->r1) {
        // 0x800A8968: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_800A8A04;
    }
L_800A8968:
    // 0x800A8968: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800A896C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A8970: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A8974: addiu       $t6, $s0, 0x2D4
    ctx->r14 = ADD32(ctx->r16, 0X2D4);
    // 0x800A8978: addiu       $t7, $s0, 0x2E0
    ctx->r15 = ADD32(ctx->r16, 0X2E0);
    // 0x800A897C: addiu       $t8, $s0, 0x2EC
    ctx->r24 = ADD32(ctx->r16, 0X2EC);
    // 0x800A8980: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800A8984: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x800A8988: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x800A898C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A8990: addiu       $a2, $s0, 0x2C8
    ctx->r6 = ADD32(ctx->r16, 0X2C8);
    // 0x800A8994: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800A8998: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800A899C: jal         0x80006970
    // 0x800A89A0: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_5;
    // 0x800A89A0: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x800A89A4: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x800A89A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A89AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A89B0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800A89B4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800A89B8: jal         0x80006970
    // 0x800A89BC: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x800A89BC: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x800A89C0: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x800A89C4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A89C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A89CC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A89D0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800A89D4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800A89D8: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x800A89DC: jal         0x80006970
    // 0x800A89E0: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_7;
    // 0x800A89E0: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x800A89E4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800A89E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A89EC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A89F0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800A89F4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800A89F8: jal         0x80006970
    // 0x800A89FC: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_8;
    // 0x800A89FC: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    after_8:
    // 0x800A8A00: lw          $v0, 0x1CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1CC);
L_800A8A04:
    // 0x800A8A04: beq         $v0, $zero, L_800A8A10
    if (ctx->r2 == 0) {
        // 0x800A8A08: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800A8A10;
    }
    // 0x800A8A08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A8A0C: bne         $v0, $at, L_800A8B90
    if (ctx->r2 != ctx->r1) {
        // 0x800A8A10: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_800A8B90;
    }
L_800A8A10:
    // 0x800A8A10: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800A8A14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A8A18: lwc1        $f18, 0x114($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800A8A1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A8A20: lwc1        $f8, -0x7AF8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7AF8);
    // 0x800A8A24: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800A8A28: addiu       $t9, $s0, 0x2C8
    ctx->r25 = ADD32(ctx->r16, 0X2C8);
    // 0x800A8A2C: addiu       $t0, $s0, 0x2D4
    ctx->r8 = ADD32(ctx->r16, 0X2D4);
    // 0x800A8A30: addiu       $t1, $s0, 0x2E0
    ctx->r9 = ADD32(ctx->r16, 0X2E0);
    // 0x800A8A34: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A8A38: addiu       $t2, $s0, 0x2EC
    ctx->r10 = ADD32(ctx->r16, 0X2EC);
    // 0x800A8A3C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x800A8A40: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x800A8A44: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800A8A48: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x800A8A4C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A8A50: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800A8A54: jal         0x80005E90
    // 0x800A8A58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_9;
    // 0x800A8A58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x800A8A5C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A8A60: lwc1        $f18, -0x7AF4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7AF4);
    // 0x800A8A64: lwc1        $f16, 0xF8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x800A8A68: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A8A6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A8A70: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A8A74: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A8A78: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A8A7C: jal         0x80005FE0
    // 0x800A8A80: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_10;
    // 0x800A8A80: nop

    after_10:
    // 0x800A8A84: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A8A88: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800A8A8C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800A8A90: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x800A8A94: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x800A8A98: lbu         $t3, 0x49D($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X49D);
    // 0x800A8A9C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x800A8AA0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800A8AA4: bnel        $v0, $t3, L_800A8AC0
    if (ctx->r2 != ctx->r11) {
        // 0x800A8AA8: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_800A8AC0;
    }
    goto skip_0;
    // 0x800A8AA8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_0:
    // 0x800A8AAC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800A8AB0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A8AB4: b           L_800A8AD0
    // 0x800A8AB8: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
        goto L_800A8AD0;
    // 0x800A8AB8: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x800A8ABC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_800A8AC0:
    // 0x800A8AC0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800A8AC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A8AC8: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x800A8ACC: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
L_800A8AD0:
    // 0x800A8AD0: lw          $t4, 0x1CC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1CC);
    // 0x800A8AD4: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x800A8AD8: bnel        $v0, $t4, L_800A8AF0
    if (ctx->r2 != ctx->r12) {
        // 0x800A8ADC: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_800A8AF0;
    }
    goto skip_1;
    // 0x800A8ADC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x800A8AE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A8AE4: nop

    // 0x800A8AE8: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x800A8AEC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_800A8AF0:
    // 0x800A8AF0: jal         0x80006970
    // 0x800A8AF4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    Matrix_MultVec3f(rdram, ctx);
        goto after_11;
    // 0x800A8AF4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_11:
    // 0x800A8AF8: lbu         $t5, 0x49C($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X49C);
    // 0x800A8AFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A8B00: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800A8B04: bne         $t5, $at, L_800A8B18
    if (ctx->r13 != ctx->r1) {
        // 0x800A8B08: lui         $at, 0xC220
        ctx->r1 = S32(0XC220 << 16);
            goto L_800A8B18;
    }
    // 0x800A8B08: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x800A8B0C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A8B10: b           L_800A8B28
    // 0x800A8B14: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
        goto L_800A8B28;
    // 0x800A8B14: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
L_800A8B18:
    // 0x800A8B18: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x800A8B1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A8B20: nop

    // 0x800A8B24: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
L_800A8B28:
    // 0x800A8B28: lw          $t6, 0x1CC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1CC);
    // 0x800A8B2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A8B30: bne         $t6, $at, L_800A8B44
    if (ctx->r14 != ctx->r1) {
        // 0x800A8B34: lui         $at, 0xC1C0
        ctx->r1 = S32(0XC1C0 << 16);
            goto L_800A8B44;
    }
    // 0x800A8B34: lui         $at, 0xC1C0
    ctx->r1 = S32(0XC1C0 << 16);
    // 0x800A8B38: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A8B3C: nop

    // 0x800A8B40: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
L_800A8B44:
    // 0x800A8B44: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A8B48: jal         0x80006970
    // 0x800A8B4C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    Matrix_MultVec3f(rdram, ctx);
        goto after_12;
    // 0x800A8B4C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_12:
    // 0x800A8B50: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x800A8B54: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800A8B58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A8B5C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A8B60: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800A8B64: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800A8B68: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x800A8B6C: jal         0x80006970
    // 0x800A8B70: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_13;
    // 0x800A8B70: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    after_13:
    // 0x800A8B74: lui         $at, 0xC1C0
    ctx->r1 = S32(0XC1C0 << 16);
    // 0x800A8B78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A8B7C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800A8B80: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800A8B84: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800A8B88: jal         0x80006970
    // 0x800A8B8C: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_14;
    // 0x800A8B8C: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    after_14:
L_800A8B90:
    // 0x800A8B90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A8B94: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800A8B98: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800A8B9C: jr          $ra
    // 0x800A8BA0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800A8BA0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Effect_WaterSpray_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AB50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007AB54: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007AB58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007AB5C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007AB60: lh          $t6, 0x4E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4E);
    // 0x8007AB64: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8007AB68: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8007AB6C: bne         $t6, $zero, L_8007ABC0
    if (ctx->r14 != 0) {
        // 0x8007AB70: addiu       $a0, $s0, 0x70
        ctx->r4 = ADD32(ctx->r16, 0X70);
            goto L_8007ABC0;
    }
    // 0x8007AB70: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x8007AB74: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007AB78: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x8007AB7C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8007AB80: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8007AB84: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x8007AB88: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8007AB8C: jal         0x8009BC2C
    // 0x8007AB90: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8007AB90: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8007AB94: lh          $t7, 0x44($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X44);
    // 0x8007AB98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007AB9C: addiu       $t8, $t7, -0x14
    ctx->r24 = ADD32(ctx->r15, -0X14);
    // 0x8007ABA0: sh          $t8, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r24;
    // 0x8007ABA4: lh          $t9, 0x44($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X44);
    // 0x8007ABA8: bgezl       $t9, L_8007ABFC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007ABAC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8007ABFC;
    }
    goto skip_0;
    // 0x8007ABAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8007ABB0: jal         0x80060FBC
    // 0x8007ABB4: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x8007ABB4: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_1:
    // 0x8007ABB8: b           L_8007ABFC
    // 0x8007ABBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8007ABFC;
    // 0x8007ABBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007ABC0:
    // 0x8007ABC0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007ABC4: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x8007ABC8: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8007ABCC: jal         0x8009BC2C
    // 0x8007ABD0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x8007ABD0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8007ABD4: lh          $t0, 0x44($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X44);
    // 0x8007ABD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007ABDC: addiu       $t1, $t0, -0xA
    ctx->r9 = ADD32(ctx->r8, -0XA);
    // 0x8007ABE0: sh          $t1, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r9;
    // 0x8007ABE4: lh          $t2, 0x44($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X44);
    // 0x8007ABE8: bgezl       $t2, L_8007ABFC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8007ABEC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8007ABFC;
    }
    goto skip_1;
    // 0x8007ABEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8007ABF0: jal         0x80060FBC
    // 0x8007ABF4: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_3;
    // 0x8007ABF4: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_3:
    // 0x8007ABF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007ABFC:
    // 0x8007ABFC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007AC00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007AC04: jr          $ra
    // 0x8007AC08: nop

    return;
    // 0x8007AC08: nop

;}
RECOMP_FUNC void AudioHeap_UpdateReverbs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CEC8: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8000CECC: lh          $t6, 0x5C78($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X5C78);
    // 0x8000CED0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000CED4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000CED8: bne         $t6, $at, L_8000CEE8
    if (ctx->r14 != ctx->r1) {
        // 0x8000CEDC: lui         $a0, 0x8015
        ctx->r4 = S32(0X8015 << 16);
            goto L_8000CEE8;
    }
    // 0x8000CEDC: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000CEE0: b           L_8000CEE8
    // 0x8000CEE4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8000CEE8;
    // 0x8000CEE4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8000CEE8:
    // 0x8000CEE8: lb          $a0, -0x3E4D($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X3E4D);
    // 0x8000CEEC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000CEF0: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8000CEF4: blez        $a0, L_8000D084
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8000CEF8: nop
    
            goto L_8000D084;
    }
    // 0x8000CEF8: nop

L_8000CEFC:
    // 0x8000CEFC: blez        $v0, L_8000D074
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000CF00: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8000D074;
    }
    // 0x8000CF00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000CF04: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x8000CF08: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x8000CF0C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000CF10: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8000CF14: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000CF18: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8000CF1C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8000CF20: addiu       $t8, $t8, -0x45B0
    ctx->r24 = ADD32(ctx->r24, -0X45B0);
    // 0x8000CF24: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000CF28: andi        $a3, $v0, 0x3
    ctx->r7 = ctx->r2 & 0X3;
    // 0x8000CF2C: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8000CF30: beq         $a3, $zero, L_8000CF88
    if (ctx->r7 == 0) {
        // 0x8000CF34: addu        $a2, $t7, $t8
        ctx->r6 = ADD32(ctx->r15, ctx->r24);
            goto L_8000CF88;
    }
    // 0x8000CF34: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x8000CF38: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8000CF3C: lhu         $a3, 0x8($a2)
    ctx->r7 = MEM_HU(ctx->r6, 0X8);
L_8000CF40:
    // 0x8000CF40: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000CF44: div         $zero, $a3, $t1
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r9)));
    // 0x8000CF48: mflo        $t9
    ctx->r25 = lo;
    // 0x8000CF4C: subu        $t2, $a3, $t9
    ctx->r10 = SUB32(ctx->r7, ctx->r25);
    // 0x8000CF50: bne         $t1, $zero, L_8000CF5C
    if (ctx->r9 != 0) {
        // 0x8000CF54: nop
    
            goto L_8000CF5C;
    }
    // 0x8000CF54: nop

    // 0x8000CF58: break       7
    do_break(2147536728);
L_8000CF5C:
    // 0x8000CF5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000CF60: bne         $t1, $at, L_8000CF74
    if (ctx->r9 != ctx->r1) {
        // 0x8000CF64: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000CF74;
    }
    // 0x8000CF64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000CF68: bne         $a3, $at, L_8000CF74
    if (ctx->r7 != ctx->r1) {
        // 0x8000CF6C: nop
    
            goto L_8000CF74;
    }
    // 0x8000CF6C: nop

    // 0x8000CF70: break       6
    do_break(2147536752);
L_8000CF74:
    // 0x8000CF74: sh          $t2, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r10;
    // 0x8000CF78: bnel        $t0, $a1, L_8000CF40
    if (ctx->r8 != ctx->r5) {
        // 0x8000CF7C: lhu         $a3, 0x8($a2)
        ctx->r7 = MEM_HU(ctx->r6, 0X8);
            goto L_8000CF40;
    }
    goto skip_0;
    // 0x8000CF7C: lhu         $a3, 0x8($a2)
    ctx->r7 = MEM_HU(ctx->r6, 0X8);
    skip_0:
    // 0x8000CF80: beql        $a1, $v0, L_8000D078
    if (ctx->r5 == ctx->r2) {
        // 0x8000CF84: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000D078;
    }
    goto skip_1;
    // 0x8000CF84: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
L_8000CF88:
    // 0x8000CF88: lhu         $a3, 0x8($a2)
    ctx->r7 = MEM_HU(ctx->r6, 0X8);
L_8000CF8C:
    // 0x8000CF8C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8000CF90: div         $zero, $a3, $t1
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r9)));
    // 0x8000CF94: mflo        $t3
    ctx->r11 = lo;
    // 0x8000CF98: subu        $t4, $a3, $t3
    ctx->r12 = SUB32(ctx->r7, ctx->r11);
    // 0x8000CF9C: bne         $t1, $zero, L_8000CFA8
    if (ctx->r9 != 0) {
        // 0x8000CFA0: nop
    
            goto L_8000CFA8;
    }
    // 0x8000CFA0: nop

    // 0x8000CFA4: break       7
    do_break(2147536804);
L_8000CFA8:
    // 0x8000CFA8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000CFAC: bne         $t1, $at, L_8000CFC0
    if (ctx->r9 != ctx->r1) {
        // 0x8000CFB0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000CFC0;
    }
    // 0x8000CFB0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000CFB4: bne         $a3, $at, L_8000CFC0
    if (ctx->r7 != ctx->r1) {
        // 0x8000CFB8: nop
    
            goto L_8000CFC0;
    }
    // 0x8000CFB8: nop

    // 0x8000CFBC: break       6
    do_break(2147536828);
L_8000CFC0:
    // 0x8000CFC0: andi        $a3, $t4, 0xFFFF
    ctx->r7 = ctx->r12 & 0XFFFF;
    // 0x8000CFC4: div         $zero, $a3, $t1
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r9)));
    // 0x8000CFC8: mflo        $t5
    ctx->r13 = lo;
    // 0x8000CFCC: subu        $t6, $a3, $t5
    ctx->r14 = SUB32(ctx->r7, ctx->r13);
    // 0x8000CFD0: sh          $t4, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r12;
    // 0x8000CFD4: bne         $t1, $zero, L_8000CFE0
    if (ctx->r9 != 0) {
        // 0x8000CFD8: nop
    
            goto L_8000CFE0;
    }
    // 0x8000CFD8: nop

    // 0x8000CFDC: break       7
    do_break(2147536860);
L_8000CFE0:
    // 0x8000CFE0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000CFE4: bne         $t1, $at, L_8000CFF8
    if (ctx->r9 != ctx->r1) {
        // 0x8000CFE8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000CFF8;
    }
    // 0x8000CFE8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000CFEC: bne         $a3, $at, L_8000CFF8
    if (ctx->r7 != ctx->r1) {
        // 0x8000CFF0: nop
    
            goto L_8000CFF8;
    }
    // 0x8000CFF0: nop

    // 0x8000CFF4: break       6
    do_break(2147536884);
L_8000CFF8:
    // 0x8000CFF8: andi        $a3, $t6, 0xFFFF
    ctx->r7 = ctx->r14 & 0XFFFF;
    // 0x8000CFFC: div         $zero, $a3, $t1
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r9)));
    // 0x8000D000: mflo        $t7
    ctx->r15 = lo;
    // 0x8000D004: subu        $t8, $a3, $t7
    ctx->r24 = SUB32(ctx->r7, ctx->r15);
    // 0x8000D008: sh          $t6, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r14;
    // 0x8000D00C: bne         $t1, $zero, L_8000D018
    if (ctx->r9 != 0) {
        // 0x8000D010: nop
    
            goto L_8000D018;
    }
    // 0x8000D010: nop

    // 0x8000D014: break       7
    do_break(2147536916);
L_8000D018:
    // 0x8000D018: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000D01C: bne         $t1, $at, L_8000D030
    if (ctx->r9 != ctx->r1) {
        // 0x8000D020: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000D030;
    }
    // 0x8000D020: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000D024: bne         $a3, $at, L_8000D030
    if (ctx->r7 != ctx->r1) {
        // 0x8000D028: nop
    
            goto L_8000D030;
    }
    // 0x8000D028: nop

    // 0x8000D02C: break       6
    do_break(2147536940);
L_8000D030:
    // 0x8000D030: andi        $a3, $t8, 0xFFFF
    ctx->r7 = ctx->r24 & 0XFFFF;
    // 0x8000D034: div         $zero, $a3, $t1
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r9)));
    // 0x8000D038: mflo        $t9
    ctx->r25 = lo;
    // 0x8000D03C: subu        $t2, $a3, $t9
    ctx->r10 = SUB32(ctx->r7, ctx->r25);
    // 0x8000D040: sh          $t8, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r24;
    // 0x8000D044: bne         $t1, $zero, L_8000D050
    if (ctx->r9 != 0) {
        // 0x8000D048: nop
    
            goto L_8000D050;
    }
    // 0x8000D048: nop

    // 0x8000D04C: break       7
    do_break(2147536972);
L_8000D050:
    // 0x8000D050: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000D054: bne         $t1, $at, L_8000D068
    if (ctx->r9 != ctx->r1) {
        // 0x8000D058: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000D068;
    }
    // 0x8000D058: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000D05C: bne         $a3, $at, L_8000D068
    if (ctx->r7 != ctx->r1) {
        // 0x8000D060: nop
    
            goto L_8000D068;
    }
    // 0x8000D060: nop

    // 0x8000D064: break       6
    do_break(2147536996);
L_8000D068:
    // 0x8000D068: sh          $t2, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r10;
    // 0x8000D06C: bnel        $a1, $v0, L_8000CF8C
    if (ctx->r5 != ctx->r2) {
        // 0x8000D070: lhu         $a3, 0x8($a2)
        ctx->r7 = MEM_HU(ctx->r6, 0X8);
            goto L_8000CF8C;
    }
    goto skip_2;
    // 0x8000D070: lhu         $a3, 0x8($a2)
    ctx->r7 = MEM_HU(ctx->r6, 0X8);
    skip_2:
L_8000D074:
    // 0x8000D074: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8000D078:
    // 0x8000D078: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000D07C: bne         $at, $zero, L_8000CEFC
    if (ctx->r1 != 0) {
        // 0x8000D080: nop
    
            goto L_8000CEFC;
    }
    // 0x8000D080: nop

L_8000D084:
    // 0x8000D084: jr          $ra
    // 0x8000D088: nop

    return;
    // 0x8000D088: nop

;}
RECOMP_FUNC void ActorAllRange_DrawBarrelRoll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035098: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003509C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800350A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800350A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800350A8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800350AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800350B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800350B4: lwc1        $f6, 0x170($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X170);
    // 0x800350B8: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x800350BC: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x800350C0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800350C4: nop

    // 0x800350C8: bc1fl       L_800352D0
    if (!c1cs) {
        // 0x800350CC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800352D0;
    }
    goto skip_0;
    // 0x800350CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800350D0: jal         0x80005708
    // 0x800350D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x800350D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800350D8: lwc1        $f8, 0x170($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X170);
    // 0x800350DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800350E0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800350E4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800350E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800350EC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800350F0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800350F4: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800350F8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800350FC: lui         $a3, 0xC1F0
    ctx->r7 = S32(0XC1F0 << 16);
    // 0x80035100: jal         0x80005B00
    // 0x80035104: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x80035104: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_1:
    // 0x80035108: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8003510C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80035110: lwc1        $f4, 0x50A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X50A8);
    // 0x80035114: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80035118: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003511C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80035120: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80035124: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80035128: jal         0x80005FE0
    // 0x8003512C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8003512C: nop

    after_2:
    // 0x80035130: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80035134: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80035138: lwc1        $f16, 0x50AC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X50AC);
    // 0x8003513C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80035140: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80035144: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80035148: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003514C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80035150: jal         0x80005D44
    // 0x80035154: nop

    Matrix_RotateX(rdram, ctx);
        goto after_3;
    // 0x80035154: nop

    after_3:
    // 0x80035158: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003515C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80035160: lwc1        $f4, 0x50B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X50B0);
    // 0x80035164: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80035168: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8003516C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80035170: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x80035174: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80035178: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003517C: lwc1        $f16, 0x58($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X58);
    // 0x80035180: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80035184: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80035188: jal         0x80005E90
    // 0x8003518C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x8003518C: nop

    after_4:
    // 0x80035190: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80035194: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x80035198: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003519C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800351A0: jal         0x80005D44
    // 0x800351A4: lw          $a1, 0x5C($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X5C);
    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x800351A4: lw          $a1, 0x5C($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X5C);
    after_5:
    // 0x800351A8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800351AC: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x800351B0: lw          $t3, 0x8C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8C);
    // 0x800351B4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800351B8: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800351BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800351C0: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800351C4: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800351C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800351CC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800351D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800351D4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800351D8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800351DC: lwc1        $f4, 0x50B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X50B4);
    // 0x800351E0: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800351E4: nop

    // 0x800351E8: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800351EC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800351F0: jal         0x80005FE0
    // 0x800351F4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x800351F4: nop

    after_6:
    // 0x800351F8: lw          $t4, 0x8C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8C);
    // 0x800351FC: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x80035200: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80035204: bgez        $t4, L_80035214
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80035208: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80035214;
    }
    // 0x80035208: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003520C: jal         0x80005D44
    // 0x80035210: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x80035210: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_7:
L_80035214:
    // 0x80035214: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80035218: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003521C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80035220: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80035224: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80035228: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003522C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80035230: jal         0x80005C34
    // 0x80035234: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_8;
    // 0x80035234: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_8:
    // 0x80035238: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8003523C: jal         0x80006EB8
    // 0x80035240: addiu       $a0, $a2, 0x7E64
    ctx->r4 = ADD32(ctx->r6, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_9;
    // 0x80035240: addiu       $a0, $a2, 0x7E64
    ctx->r4 = ADD32(ctx->r6, 0X7E64);
    after_9:
    // 0x80035244: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80035248: addiu       $a0, $a2, 0x7E64
    ctx->r4 = ADD32(ctx->r6, 0X7E64);
    // 0x8003524C: jal         0x800B8DD0
    // 0x80035250: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_10;
    // 0x80035250: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_10:
    // 0x80035254: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80035258: addiu       $a2, $a2, 0x7E64
    ctx->r6 = ADD32(ctx->r6, 0X7E64);
    // 0x8003525C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80035260: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80035264: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80035268: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8003526C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80035270: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80035274: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80035278: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8003527C: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x80035280: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80035284: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80035288: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8003528C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80035290: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x80035294: ori         $t3, $a1, 0xA000
    ctx->r11 = ctx->r5 | 0XA000;
    // 0x80035298: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8003529C: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x800352A0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800352A4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800352A8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800352AC: lui         $t6, 0x102
    ctx->r14 = S32(0X102 << 16);
    // 0x800352B0: addiu       $t6, $t6, -0x23F0
    ctx->r14 = ADD32(ctx->r14, -0X23F0);
    // 0x800352B4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800352B8: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800352BC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800352C0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800352C4: jal         0x80005740
    // 0x800352C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_11;
    // 0x800352C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x800352CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800352D0:
    // 0x800352D0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800352D4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800352D8: jr          $ra
    // 0x800352DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800352DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void SceneryRotateTowardsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066EA8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80066EAC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80066EB0: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80066EB4: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x80066EB8: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x80066EBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80066EC0: lwc1        $f6, 0x40($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X40);
    // 0x80066EC4: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80066EC8: nop

    // 0x80066ECC: bc1f        L_80066EDC
    if (!c1cs) {
        // 0x80066ED0: nop
    
            goto L_80066EDC;
    }
    // 0x80066ED0: nop

    // 0x80066ED4: lwc1        $f10, 0x694C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X694C);
    // 0x80066ED8: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
L_80066EDC:
    // 0x80066EDC: jr          $ra
    // 0x80066EE0: nop

    return;
    // 0x80066EE0: nop

;}
RECOMP_FUNC void Cutscene_AllAircraftReport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048AC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048AC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048AC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80048ACC: bne         $a0, $at, L_80048BC8
    if (ctx->r4 != ctx->r1) {
        // 0x80048AD0: sll         $t5, $a0, 2
        ctx->r13 = S32(ctx->r4 << 2);
            goto L_80048BC8;
    }
    // 0x80048AD0: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x80048AD4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80048AD8: lw          $t6, 0x78B4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78B4);
    // 0x80048ADC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80048AE0: addiu       $a0, $a0, 0x4558
    ctx->r4 = ADD32(ctx->r4, 0X4558);
    // 0x80048AE4: slti        $at, $t6, 0x40
    ctx->r1 = SIGNED(ctx->r14) < 0X40 ? 1 : 0;
    // 0x80048AE8: beq         $at, $zero, L_80048B00
    if (ctx->r1 == 0) {
        // 0x80048AEC: nop
    
            goto L_80048B00;
    }
    // 0x80048AEC: nop

    // 0x80048AF0: jal         0x800BA808
    // 0x80048AF4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_0;
    // 0x80048AF4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x80048AF8: b           L_80048CB8
    // 0x80048AFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80048CB8;
    // 0x80048AFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048B00:
    // 0x80048B00: jal         0x800A3FC4
    // 0x80048B04: nop

    Play_GetMaxShields(rdram, ctx);
        goto after_1;
    // 0x80048B04: nop

    after_1:
    // 0x80048B08: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80048B0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80048B10: lwc1        $f8, 0x5780($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5780);
    // 0x80048B14: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80048B18: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80048B1C: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x80048B20: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80048B24: addiu       $a0, $a0, 0x3558
    ctx->r4 = ADD32(ctx->r4, 0X3558);
    // 0x80048B28: lw          $t0, 0x264($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X264);
    // 0x80048B2C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80048B30: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80048B34: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80048B38: nop

    // 0x80048B3C: slt         $at, $t8, $t0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80048B40: beq         $at, $zero, L_80048B58
    if (ctx->r1 == 0) {
        // 0x80048B44: nop
    
            goto L_80048B58;
    }
    // 0x80048B44: nop

    // 0x80048B48: jal         0x800BA808
    // 0x80048B4C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_2;
    // 0x80048B4C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_2:
    // 0x80048B50: b           L_80048CB8
    // 0x80048B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80048CB8;
    // 0x80048B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048B58:
    // 0x80048B58: jal         0x800A3FC4
    // 0x80048B5C: nop

    Play_GetMaxShields(rdram, ctx);
        goto after_3;
    // 0x80048B5C: nop

    after_3:
    // 0x80048B60: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80048B64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80048B68: lwc1        $f6, 0x5784($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5784);
    // 0x80048B6C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80048B70: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80048B74: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x80048B78: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80048B7C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80048B80: lw          $t4, 0x264($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X264);
    // 0x80048B84: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80048B88: addiu       $a0, $a0, 0x359C
    ctx->r4 = ADD32(ctx->r4, 0X359C);
    // 0x80048B8C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80048B90: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80048B94: nop

    // 0x80048B98: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80048B9C: beq         $at, $zero, L_80048BB8
    if (ctx->r1 == 0) {
        // 0x80048BA0: nop
    
            goto L_80048BB8;
    }
    // 0x80048BA0: nop

    // 0x80048BA4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80048BA8: jal         0x800BA808
    // 0x80048BAC: addiu       $a0, $a0, 0x35D0
    ctx->r4 = ADD32(ctx->r4, 0X35D0);
    Radio_PlayMessage(rdram, ctx);
        goto after_4;
    // 0x80048BAC: addiu       $a0, $a0, 0x35D0
    ctx->r4 = ADD32(ctx->r4, 0X35D0);
    after_4:
    // 0x80048BB0: b           L_80048CB8
    // 0x80048BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80048CB8;
    // 0x80048BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048BB8:
    // 0x80048BB8: jal         0x800BA808
    // 0x80048BBC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_5;
    // 0x80048BBC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_5:
    // 0x80048BC0: b           L_80048CB8
    // 0x80048BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80048CB8;
    // 0x80048BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048BC8:
    // 0x80048BC8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80048BCC: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x80048BD0: lw          $v0, 0x78B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78B0);
    // 0x80048BD4: slti        $at, $v0, 0xA1
    ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
    // 0x80048BD8: bne         $at, $zero, L_80048C24
    if (ctx->r1 != 0) {
        // 0x80048BDC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80048C24;
    }
    // 0x80048BDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80048BE0: beq         $a0, $at, L_80048BFC
    if (ctx->r4 == ctx->r1) {
        // 0x80048BE4: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_80048BFC;
    }
    // 0x80048BE4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80048BE8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80048BEC: beq         $a0, $at, L_80048C10
    if (ctx->r4 == ctx->r1) {
        // 0x80048BF0: addiu       $a1, $zero, 0x1E
        ctx->r5 = ADD32(0, 0X1E);
            goto L_80048C10;
    }
    // 0x80048BF0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80048BF4: b           L_80048CB8
    // 0x80048BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80048CB8;
    // 0x80048BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048BFC:
    // 0x80048BFC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80048C00: jal         0x800BA808
    // 0x80048C04: addiu       $a0, $a0, 0x33F0
    ctx->r4 = ADD32(ctx->r4, 0X33F0);
    Radio_PlayMessage(rdram, ctx);
        goto after_6;
    // 0x80048C04: addiu       $a0, $a0, 0x33F0
    ctx->r4 = ADD32(ctx->r4, 0X33F0);
    after_6:
    // 0x80048C08: b           L_80048CB8
    // 0x80048C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80048CB8;
    // 0x80048C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048C10:
    // 0x80048C10: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80048C14: jal         0x800BA808
    // 0x80048C18: addiu       $a0, $a0, 0x341C
    ctx->r4 = ADD32(ctx->r4, 0X341C);
    Radio_PlayMessage(rdram, ctx);
        goto after_7;
    // 0x80048C18: addiu       $a0, $a0, 0x341C
    ctx->r4 = ADD32(ctx->r4, 0X341C);
    after_7:
    // 0x80048C1C: b           L_80048CB8
    // 0x80048C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80048CB8;
    // 0x80048C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048C24:
    // 0x80048C24: slti        $at, $v0, 0x41
    ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // 0x80048C28: bne         $at, $zero, L_80048C74
    if (ctx->r1 != 0) {
        // 0x80048C2C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80048C74;
    }
    // 0x80048C2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80048C30: beq         $a0, $at, L_80048C4C
    if (ctx->r4 == ctx->r1) {
        // 0x80048C34: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_80048C4C;
    }
    // 0x80048C34: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80048C38: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80048C3C: beq         $a0, $at, L_80048C60
    if (ctx->r4 == ctx->r1) {
        // 0x80048C40: addiu       $a1, $zero, 0x1E
        ctx->r5 = ADD32(0, 0X1E);
            goto L_80048C60;
    }
    // 0x80048C40: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80048C44: b           L_80048CB8
    // 0x80048C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80048CB8;
    // 0x80048C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048C4C:
    // 0x80048C4C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80048C50: jal         0x800BA808
    // 0x80048C54: addiu       $a0, $a0, 0x3448
    ctx->r4 = ADD32(ctx->r4, 0X3448);
    Radio_PlayMessage(rdram, ctx);
        goto after_8;
    // 0x80048C54: addiu       $a0, $a0, 0x3448
    ctx->r4 = ADD32(ctx->r4, 0X3448);
    after_8:
    // 0x80048C58: b           L_80048CB8
    // 0x80048C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80048CB8;
    // 0x80048C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048C60:
    // 0x80048C60: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80048C64: jal         0x800BA808
    // 0x80048C68: addiu       $a0, $a0, 0x3488
    ctx->r4 = ADD32(ctx->r4, 0X3488);
    Radio_PlayMessage(rdram, ctx);
        goto after_9;
    // 0x80048C68: addiu       $a0, $a0, 0x3488
    ctx->r4 = ADD32(ctx->r4, 0X3488);
    after_9:
    // 0x80048C6C: b           L_80048CB8
    // 0x80048C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80048CB8;
    // 0x80048C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048C74:
    // 0x80048C74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80048C78: beq         $a0, $at, L_80048C94
    if (ctx->r4 == ctx->r1) {
        // 0x80048C7C: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_80048C94;
    }
    // 0x80048C7C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80048C80: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80048C84: beq         $a0, $at, L_80048CA8
    if (ctx->r4 == ctx->r1) {
        // 0x80048C88: addiu       $a1, $zero, 0x1E
        ctx->r5 = ADD32(0, 0X1E);
            goto L_80048CA8;
    }
    // 0x80048C88: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80048C8C: b           L_80048CB8
    // 0x80048C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80048CB8;
    // 0x80048C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048C94:
    // 0x80048C94: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80048C98: jal         0x800BA808
    // 0x80048C9C: addiu       $a0, $a0, 0x34D4
    ctx->r4 = ADD32(ctx->r4, 0X34D4);
    Radio_PlayMessage(rdram, ctx);
        goto after_10;
    // 0x80048C9C: addiu       $a0, $a0, 0x34D4
    ctx->r4 = ADD32(ctx->r4, 0X34D4);
    after_10:
    // 0x80048CA0: b           L_80048CB8
    // 0x80048CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80048CB8;
    // 0x80048CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048CA8:
    // 0x80048CA8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80048CAC: jal         0x800BA808
    // 0x80048CB0: addiu       $a0, $a0, 0x350C
    ctx->r4 = ADD32(ctx->r4, 0X350C);
    Radio_PlayMessage(rdram, ctx);
        goto after_11;
    // 0x80048CB0: addiu       $a0, $a0, 0x350C
    ctx->r4 = ADD32(ctx->r4, 0X350C);
    after_11:
    // 0x80048CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048CB8:
    // 0x80048CB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048CBC: jr          $ra
    // 0x80048CC0: nop

    return;
    // 0x80048CC0: nop

;}
RECOMP_FUNC void Object_CheckCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006351C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80063520: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80063524: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80063528: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8006352C: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80063530: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80063534: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80063538: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8006353C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80063540: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80063544: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80063548: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8006354C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80063550: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80063554: lw          $v0, 0x7880($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7880);
    // 0x80063558: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006355C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80063560: bnel        $v0, $at, L_8006368C
    if (ctx->r2 != ctx->r1) {
        // 0x80063564: lui         $at, 0x44FA
        ctx->r1 = S32(0X44FA << 16);
            goto L_8006368C;
    }
    goto skip_0;
    // 0x80063564: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    skip_0:
    // 0x80063568: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x8006356C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80063570: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80063574: beq         $t6, $at, L_80063688
    if (ctx->r14 == ctx->r1) {
        // 0x80063578: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80063688;
    }
    // 0x80063578: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8006357C: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80063580: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80063584: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80063588: lw          $s0, -0x7D58($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D58);
    // 0x8006358C: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_80063590:
    // 0x80063590: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x80063594: bnel        $s3, $t7, L_80063674
    if (ctx->r19 != ctx->r15) {
        // 0x80063598: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80063674;
    }
    goto skip_1;
    // 0x80063598: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x8006359C: lhu         $a2, 0x2($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X2);
    // 0x800635A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800635A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800635A8: beq         $a2, $at, L_800635EC
    if (ctx->r6 == ctx->r1) {
        // 0x800635AC: or          $a1, $s4, $zero
        ctx->r5 = ctx->r20 | 0;
            goto L_800635EC;
    }
    // 0x800635AC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800635B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800635B4: beq         $a2, $at, L_800635EC
    if (ctx->r6 == ctx->r1) {
        // 0x800635B8: addiu       $at, $zero, 0x75
        ctx->r1 = ADD32(0, 0X75);
            goto L_800635EC;
    }
    // 0x800635B8: addiu       $at, $zero, 0x75
    ctx->r1 = ADD32(0, 0X75);
    // 0x800635BC: beq         $a2, $at, L_800635EC
    if (ctx->r6 == ctx->r1) {
        // 0x800635C0: addiu       $at, $zero, 0x8D
        ctx->r1 = ADD32(0, 0X8D);
            goto L_800635EC;
    }
    // 0x800635C0: addiu       $at, $zero, 0x8D
    ctx->r1 = ADD32(0, 0X8D);
    // 0x800635C4: beq         $a2, $at, L_800635EC
    if (ctx->r6 == ctx->r1) {
        // 0x800635C8: addiu       $at, $zero, 0x96
        ctx->r1 = ADD32(0, 0X96);
            goto L_800635EC;
    }
    // 0x800635C8: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x800635CC: beq         $a2, $at, L_800635EC
    if (ctx->r6 == ctx->r1) {
        // 0x800635D0: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_800635EC;
    }
    // 0x800635D0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x800635D4: beq         $a2, $at, L_800635EC
    if (ctx->r6 == ctx->r1) {
        // 0x800635D8: addiu       $at, $zero, 0x94
        ctx->r1 = ADD32(0, 0X94);
            goto L_800635EC;
    }
    // 0x800635D8: addiu       $at, $zero, 0x94
    ctx->r1 = ADD32(0, 0X94);
    // 0x800635DC: beq         $a2, $at, L_800635EC
    if (ctx->r6 == ctx->r1) {
        // 0x800635E0: addiu       $at, $zero, 0x8C
        ctx->r1 = ADD32(0, 0X8C);
            goto L_800635EC;
    }
    // 0x800635E0: addiu       $at, $zero, 0x8C
    ctx->r1 = ADD32(0, 0X8C);
    // 0x800635E4: bnel        $a2, $at, L_80063608
    if (ctx->r6 != ctx->r1) {
        // 0x800635E8: lwc1        $f4, 0x0($s1)
        ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
            goto L_80063608;
    }
    goto skip_2;
    // 0x800635E8: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    skip_2:
L_800635EC:
    // 0x800635EC: jal         0x8006326C
    // 0x800635F0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    Object_CheckPolyCollision(rdram, ctx);
        goto after_0;
    // 0x800635F0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_0:
    // 0x800635F4: beql        $v0, $zero, L_80063674
    if (ctx->r2 == 0) {
        // 0x800635F8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80063674;
    }
    goto skip_3;
    // 0x800635F8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_3:
    // 0x800635FC: b           L_80063C84
    // 0x80063600: addiu       $v0, $zero, 0x3E7
    ctx->r2 = ADD32(0, 0X3E7);
        goto L_80063C84;
    // 0x80063600: addiu       $v0, $zero, 0x3E7
    ctx->r2 = ADD32(0, 0X3E7);
    // 0x80063604: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
L_80063608:
    // 0x80063608: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006360C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80063610: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80063614: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80063618: nop

    // 0x8006361C: bc1fl       L_80063674
    if (!c1cs) {
        // 0x80063620: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80063674;
    }
    goto skip_4;
    // 0x80063620: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_4:
    // 0x80063624: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80063628: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006362C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80063630: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80063634: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80063638: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8006363C: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80063640: nop

    // 0x80063644: bc1fl       L_80063674
    if (!c1cs) {
        // 0x80063648: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80063674;
    }
    goto skip_5;
    // 0x80063648: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_5:
    // 0x8006364C: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x80063650: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80063654: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80063658: jal         0x80062DBC
    // 0x8006365C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Object_CheckHitboxCollision(rdram, ctx);
        goto after_1;
    // 0x8006365C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x80063660: beql        $v0, $zero, L_80063674
    if (ctx->r2 == 0) {
        // 0x80063664: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80063674;
    }
    goto skip_6;
    // 0x80063664: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_6:
    // 0x80063668: b           L_80063C84
    // 0x8006366C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80063C84;
    // 0x8006366C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80063670: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80063674:
    // 0x80063674: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80063678: bne         $s2, $at, L_80063590
    if (ctx->r18 != ctx->r1) {
        // 0x8006367C: addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
            goto L_80063590;
    }
    // 0x8006367C: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x80063680: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80063684: lw          $v0, 0x7880($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7880);
L_80063688:
    // 0x80063688: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
L_8006368C:
    // 0x8006368C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80063690: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80063694: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80063698: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x8006369C: addiu       $s0, $s0, 0x1B00
    ctx->r16 = ADD32(ctx->r16, 0X1B00);
    // 0x800636A0: bne         $v0, $zero, L_80063798
    if (ctx->r2 != 0) {
        // 0x800636A4: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80063798;
    }
    // 0x800636A4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800636A8: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
L_800636AC:
    // 0x800636AC: bnel        $s3, $t8, L_8006377C
    if (ctx->r19 != ctx->r24) {
        // 0x800636B0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8006377C;
    }
    goto skip_7;
    // 0x800636B0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_7:
    // 0x800636B4: lhu         $a2, 0x2($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X2);
    // 0x800636B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800636BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800636C0: beq         $a2, $at, L_800636F4
    if (ctx->r6 == ctx->r1) {
        // 0x800636C4: or          $a1, $s4, $zero
        ctx->r5 = ctx->r20 | 0;
            goto L_800636F4;
    }
    // 0x800636C4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800636C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800636CC: beq         $a2, $at, L_800636F4
    if (ctx->r6 == ctx->r1) {
        // 0x800636D0: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800636F4;
    }
    // 0x800636D0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800636D4: beq         $a2, $at, L_800636F4
    if (ctx->r6 == ctx->r1) {
        // 0x800636D8: nop
    
            goto L_800636F4;
    }
    // 0x800636D8: nop

    // 0x800636DC: beq         $s3, $a2, L_800636F4
    if (ctx->r19 == ctx->r6) {
        // 0x800636E0: addiu       $at, $zero, 0x27
        ctx->r1 = ADD32(0, 0X27);
            goto L_800636F4;
    }
    // 0x800636E0: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x800636E4: beq         $a2, $at, L_800636F4
    if (ctx->r6 == ctx->r1) {
        // 0x800636E8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800636F4;
    }
    // 0x800636E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800636EC: bnel        $a2, $at, L_80063710
    if (ctx->r6 != ctx->r1) {
        // 0x800636F0: lwc1        $f4, 0x0($s1)
        ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
            goto L_80063710;
    }
    goto skip_8;
    // 0x800636F0: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    skip_8:
L_800636F4:
    // 0x800636F4: jal         0x8006326C
    // 0x800636F8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    Object_CheckPolyCollision(rdram, ctx);
        goto after_2;
    // 0x800636F8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_2:
    // 0x800636FC: beql        $v0, $zero, L_8006377C
    if (ctx->r2 == 0) {
        // 0x80063700: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8006377C;
    }
    goto skip_9;
    // 0x80063700: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_9:
    // 0x80063704: b           L_80063C84
    // 0x80063708: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80063C84;
    // 0x80063708: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8006370C: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
L_80063710:
    // 0x80063710: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80063714: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80063718: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8006371C: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80063720: nop

    // 0x80063724: bc1fl       L_8006377C
    if (!c1cs) {
        // 0x80063728: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8006377C;
    }
    goto skip_10;
    // 0x80063728: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_10:
    // 0x8006372C: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80063730: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80063734: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80063738: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8006373C: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80063740: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80063744: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80063748: nop

    // 0x8006374C: bc1fl       L_8006377C
    if (!c1cs) {
        // 0x80063750: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8006377C;
    }
    goto skip_11;
    // 0x80063750: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_11:
    // 0x80063754: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x80063758: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8006375C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80063760: jal         0x80062DBC
    // 0x80063764: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Object_CheckHitboxCollision(rdram, ctx);
        goto after_3;
    // 0x80063764: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x80063768: beql        $v0, $zero, L_8006377C
    if (ctx->r2 == 0) {
        // 0x8006376C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8006377C;
    }
    goto skip_12;
    // 0x8006376C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_12:
    // 0x80063770: b           L_80063C84
    // 0x80063774: addiu       $v0, $s2, 0xA
    ctx->r2 = ADD32(ctx->r18, 0XA);
        goto L_80063C84;
    // 0x80063774: addiu       $v0, $s2, 0xA
    ctx->r2 = ADD32(ctx->r18, 0XA);
    // 0x80063778: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8006377C:
    // 0x8006377C: slti        $at, $s2, 0x32
    ctx->r1 = SIGNED(ctx->r18) < 0X32 ? 1 : 0;
    // 0x80063780: beq         $at, $zero, L_80063798
    if (ctx->r1 == 0) {
        // 0x80063784: addiu       $s0, $s0, 0x80
        ctx->r16 = ADD32(ctx->r16, 0X80);
            goto L_80063798;
    }
    // 0x80063784: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x80063788: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8006378C: lw          $t9, 0x7880($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7880);
    // 0x80063790: beql        $t9, $zero, L_800636AC
    if (ctx->r25 == 0) {
        // 0x80063794: lbu         $t8, 0x0($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X0);
            goto L_800636AC;
    }
    goto skip_13;
    // 0x80063794: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    skip_13:
L_80063798:
    // 0x80063798: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8006379C: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x800637A0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800637A4: addiu       $s0, $s0, 0x3400
    ctx->r16 = ADD32(ctx->r16, 0X3400);
    // 0x800637A8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_800637AC:
    // 0x800637AC: lbu         $t0, 0x0($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X0);
    // 0x800637B0: bnel        $s3, $t0, L_8006384C
    if (ctx->r19 != ctx->r8) {
        // 0x800637B4: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8006384C;
    }
    goto skip_14;
    // 0x800637B4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_14:
    // 0x800637B8: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800637BC: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800637C0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800637C4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800637C8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800637CC: nop

    // 0x800637D0: bc1fl       L_8006384C
    if (!c1cs) {
        // 0x800637D4: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8006384C;
    }
    goto skip_15;
    // 0x800637D4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_15:
    // 0x800637D8: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800637DC: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800637E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800637E4: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x800637E8: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800637EC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800637F0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800637F4: nop

    // 0x800637F8: bc1fl       L_8006384C
    if (!c1cs) {
        // 0x800637FC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8006384C;
    }
    goto skip_16;
    // 0x800637FC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_16:
    // 0x80063800: jal         0x800631A8
    // 0x80063804: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    Object_CheckSingleHitbox(rdram, ctx);
        goto after_4;
    // 0x80063804: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    after_4:
    // 0x80063808: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8006380C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80063810: beql        $v0, $zero, L_8006384C
    if (ctx->r2 == 0) {
        // 0x80063814: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8006384C;
    }
    goto skip_17;
    // 0x80063814: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_17:
    // 0x80063818: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x8006381C: addiu       $at, $zero, 0xA3
    ctx->r1 = ADD32(0, 0XA3);
    // 0x80063820: addiu       $v1, $zero, 0xA2
    ctx->r3 = ADD32(0, 0XA2);
    // 0x80063824: beq         $v0, $at, L_8006383C
    if (ctx->r2 == ctx->r1) {
        // 0x80063828: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8006383C;
    }
    // 0x80063828: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006382C: beql        $v1, $v0, L_80063840
    if (ctx->r3 == ctx->r2) {
        // 0x80063830: sb          $t1, 0x46($s0)
        MEM_B(0X46, ctx->r16) = ctx->r9;
            goto L_80063840;
    }
    goto skip_18;
    // 0x80063830: sb          $t1, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r9;
    skip_18:
    // 0x80063834: bne         $v1, $v0, L_80063840
    if (ctx->r3 != ctx->r2) {
        // 0x80063838: nop
    
            goto L_80063840;
    }
    // 0x80063838: nop

L_8006383C:
    // 0x8006383C: sb          $t1, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r9;
L_80063840:
    // 0x80063840: b           L_80063C84
    // 0x80063844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80063C84;
    // 0x80063844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80063848: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8006384C:
    // 0x8006384C: slti        $at, $s2, 0x28
    ctx->r1 = SIGNED(ctx->r18) < 0X28 ? 1 : 0;
    // 0x80063850: bne         $at, $zero, L_800637AC
    if (ctx->r1 != 0) {
        // 0x80063854: addiu       $s0, $s0, 0x4C
        ctx->r16 = ADD32(ctx->r16, 0X4C);
            goto L_800637AC;
    }
    // 0x80063854: addiu       $s0, $s0, 0x4C
    ctx->r16 = ADD32(ctx->r16, 0X4C);
    // 0x80063858: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8006385C: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80063860: beq         $t2, $zero, L_80063878
    if (ctx->r10 == 0) {
        // 0x80063864: nop
    
            goto L_80063878;
    }
    // 0x80063864: nop

    // 0x80063868: beq         $t2, $s3, L_80063878
    if (ctx->r10 == ctx->r19) {
        // 0x8006386C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80063878;
    }
    // 0x8006386C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80063870: bnel        $t2, $at, L_80063C84
    if (ctx->r10 != ctx->r1) {
        // 0x80063874: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80063C84;
    }
    goto skip_19;
    // 0x80063874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_19:
L_80063878:
    // 0x80063878: beq         $t3, $s3, L_80063A80
    if (ctx->r11 == ctx->r19) {
        // 0x8006387C: lui         $s0, 0x8017
        ctx->r16 = S32(0X8017 << 16);
            goto L_80063A80;
    }
    // 0x8006387C: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80063880: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80063884: addiu       $s0, $s0, -0xEF0
    ctx->r16 = ADD32(ctx->r16, -0XEF0);
    // 0x80063888: lwc1        $f18, 0x64BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X64BC);
    // 0x8006388C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80063890:
    // 0x80063890: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x80063894: bne         $s3, $t4, L_80063A68
    if (ctx->r19 != ctx->r12) {
        // 0x80063898: nop
    
            goto L_80063A68;
    }
    // 0x80063898: nop

    // 0x8006389C: lhu         $a2, 0x2($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X2);
    // 0x800638A0: addiu       $at, $zero, 0x134
    ctx->r1 = ADD32(0, 0X134);
    // 0x800638A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800638A8: beq         $a2, $at, L_800638CC
    if (ctx->r6 == ctx->r1) {
        // 0x800638AC: or          $a1, $s4, $zero
        ctx->r5 = ctx->r20 | 0;
            goto L_800638CC;
    }
    // 0x800638AC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800638B0: addiu       $at, $zero, 0x138
    ctx->r1 = ADD32(0, 0X138);
    // 0x800638B4: beq         $a2, $at, L_800638CC
    if (ctx->r6 == ctx->r1) {
        // 0x800638B8: addiu       $at, $zero, 0x139
        ctx->r1 = ADD32(0, 0X139);
            goto L_800638CC;
    }
    // 0x800638B8: addiu       $at, $zero, 0x139
    ctx->r1 = ADD32(0, 0X139);
    // 0x800638BC: beq         $a2, $at, L_800638CC
    if (ctx->r6 == ctx->r1) {
        // 0x800638C0: addiu       $at, $zero, 0x135
        ctx->r1 = ADD32(0, 0X135);
            goto L_800638CC;
    }
    // 0x800638C0: addiu       $at, $zero, 0x135
    ctx->r1 = ADD32(0, 0X135);
    // 0x800638C4: bnel        $a2, $at, L_800638E8
    if (ctx->r6 != ctx->r1) {
        // 0x800638C8: addiu       $at, $zero, 0x136
        ctx->r1 = ADD32(0, 0X136);
            goto L_800638E8;
    }
    goto skip_20;
    // 0x800638C8: addiu       $at, $zero, 0x136
    ctx->r1 = ADD32(0, 0X136);
    skip_20:
L_800638CC:
    // 0x800638CC: jal         0x8006326C
    // 0x800638D0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    Object_CheckPolyCollision(rdram, ctx);
        goto after_5;
    // 0x800638D0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_5:
    // 0x800638D4: beq         $v0, $zero, L_80063A68
    if (ctx->r2 == 0) {
        // 0x800638D8: nop
    
            goto L_80063A68;
    }
    // 0x800638D8: nop

    // 0x800638DC: b           L_80063C84
    // 0x800638E0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80063C84;
    // 0x800638E0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800638E4: addiu       $at, $zero, 0x136
    ctx->r1 = ADD32(0, 0X136);
L_800638E8:
    // 0x800638E8: bne         $a2, $at, L_80063978
    if (ctx->r6 != ctx->r1) {
        // 0x800638EC: lwc1        $f16, 0x0($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
            goto L_80063978;
    }
    // 0x800638EC: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800638F0: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800638F4: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800638F8: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800638FC: sub.s       $f0, $f4, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80063900: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80063904: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80063908: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006390C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80063910: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80063914: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80063918: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8006391C: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80063920: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80063924: mul.s       $f14, $f0, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80063928: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8006392C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80063930: mul.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80063934: nop

    // 0x80063938: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006393C: nop

    // 0x80063940: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80063944: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80063948: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8006394C: lwc1        $f8, 0x64C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X64C0);
    // 0x80063950: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80063954: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80063958: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8006395C: nop

    // 0x80063960: bc1f        L_80063A68
    if (!c1cs) {
        // 0x80063964: nop
    
            goto L_80063A68;
    }
    // 0x80063964: nop

    // 0x80063968: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8006396C: sb          $t5, 0x62($s0)
    MEM_B(0X62, ctx->r16) = ctx->r13;
    // 0x80063970: b           L_80063C84
    // 0x80063974: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80063C84;
    // 0x80063974: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80063978:
    // 0x80063978: addiu       $at, $zero, 0x13C
    ctx->r1 = ADD32(0, 0X13C);
    // 0x8006397C: bnel        $a2, $at, L_80063A04
    if (ctx->r6 != ctx->r1) {
        // 0x80063980: lwc1        $f4, 0x4($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
            goto L_80063A04;
    }
    goto skip_21;
    // 0x80063980: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    skip_21:
    // 0x80063984: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80063988: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8006398C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80063990: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80063994: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80063998: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8006399C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800639A0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800639A4: lwc1        $f4, 0x64C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X64C4);
    // 0x800639A8: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800639AC: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x800639B0: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800639B4: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800639B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800639BC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800639C0: mul.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800639C4: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800639C8: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800639CC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800639D0: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800639D4: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800639D8: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800639DC: lwc1        $f10, 0x64C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X64C8);
    // 0x800639E0: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800639E4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x800639E8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800639EC: nop

    // 0x800639F0: bc1fl       L_80063A04
    if (!c1cs) {
        // 0x800639F4: lwc1        $f4, 0x4($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
            goto L_80063A04;
    }
    goto skip_22;
    // 0x800639F4: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    skip_22:
    // 0x800639F8: b           L_80063C84
    // 0x800639FC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80063C84;
    // 0x800639FC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80063A00: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
L_80063A04:
    // 0x80063A04: sub.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80063A08: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80063A0C: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80063A10: nop

    // 0x80063A14: bc1f        L_80063A68
    if (!c1cs) {
        // 0x80063A18: nop
    
            goto L_80063A68;
    }
    // 0x80063A18: nop

    // 0x80063A1C: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80063A20: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80063A24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80063A28: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80063A2C: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80063A30: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80063A34: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80063A38: nop

    // 0x80063A3C: bc1f        L_80063A68
    if (!c1cs) {
        // 0x80063A40: nop
    
            goto L_80063A68;
    }
    // 0x80063A40: nop

    // 0x80063A44: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x80063A48: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80063A4C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80063A50: jal         0x80062DBC
    // 0x80063A54: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Object_CheckHitboxCollision(rdram, ctx);
        goto after_6;
    // 0x80063A54: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_6:
    // 0x80063A58: beq         $v0, $zero, L_80063A68
    if (ctx->r2 == 0) {
        // 0x80063A5C: nop
    
            goto L_80063A68;
    }
    // 0x80063A5C: nop

    // 0x80063A60: b           L_80063C84
    // 0x80063A64: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80063C84;
    // 0x80063A64: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80063A68:
    // 0x80063A68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80063A6C: lwc1        $f18, 0x64CC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X64CC);
    // 0x80063A70: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80063A74: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80063A78: bne         $s2, $at, L_80063890
    if (ctx->r18 != ctx->r1) {
        // 0x80063A7C: addiu       $s0, $s0, 0x408
        ctx->r16 = ADD32(ctx->r16, 0X408);
            goto L_80063890;
    }
    // 0x80063A7C: addiu       $s0, $s0, 0x408
    ctx->r16 = ADD32(ctx->r16, 0X408);
L_80063A80:
    // 0x80063A80: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80063A84: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80063A88: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80063A8C: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x80063A90: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80063A94:
    // 0x80063A94: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80063A98: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80063A9C: bnel        $at, $zero, L_80063C74
    if (ctx->r1 != 0) {
        // 0x80063AA0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80063C74;
    }
    goto skip_23;
    // 0x80063AA0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_23:
    // 0x80063AA4: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80063AA8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80063AAC: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80063AB0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80063AB4: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80063AB8: nop

    // 0x80063ABC: bc1fl       L_80063C74
    if (!c1cs) {
        // 0x80063AC0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80063C74;
    }
    goto skip_24;
    // 0x80063AC0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_24:
    // 0x80063AC4: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80063AC8: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80063ACC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80063AD0: lwc1        $f10, 0x64D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X64D0);
    // 0x80063AD4: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80063AD8: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80063ADC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80063AE0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80063AE4: nop

    // 0x80063AE8: bc1fl       L_80063C74
    if (!c1cs) {
        // 0x80063AEC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80063C74;
    }
    goto skip_25;
    // 0x80063AEC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_25:
    // 0x80063AF0: beql        $t7, $s2, L_80063C74
    if (ctx->r15 == ctx->r18) {
        // 0x80063AF4: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80063C74;
    }
    goto skip_26;
    // 0x80063AF4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_26:
    // 0x80063AF8: lh          $t8, 0x32($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X32);
    // 0x80063AFC: beql        $s3, $t8, L_80063C74
    if (ctx->r19 == ctx->r24) {
        // 0x80063B00: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80063C74;
    }
    goto skip_27;
    // 0x80063B00: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_27:
    // 0x80063B04: lhu         $a2, 0x2($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X2);
    // 0x80063B08: addiu       $at, $zero, 0xC5
    ctx->r1 = ADD32(0, 0XC5);
    // 0x80063B0C: bnel        $a2, $at, L_80063B28
    if (ctx->r6 != ctx->r1) {
        // 0x80063B10: lhu         $t0, 0xC2($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0XC2);
            goto L_80063B28;
    }
    goto skip_28;
    // 0x80063B10: lhu         $t0, 0xC2($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XC2);
    skip_28:
    // 0x80063B14: lh          $t9, 0xE4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE4);
    // 0x80063B18: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x80063B1C: bnel        $at, $zero, L_80063C74
    if (ctx->r1 != 0) {
        // 0x80063B20: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80063C74;
    }
    goto skip_29;
    // 0x80063B20: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_29:
    // 0x80063B24: lhu         $t0, 0xC2($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XC2);
L_80063B28:
    // 0x80063B28: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x80063B2C: bnel        $t0, $zero, L_80063C74
    if (ctx->r8 != 0) {
        // 0x80063B30: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80063C74;
    }
    goto skip_30;
    // 0x80063B30: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_30:
    // 0x80063B34: bne         $a2, $at, L_80063B58
    if (ctx->r6 != ctx->r1) {
        // 0x80063B38: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80063B58;
    }
    // 0x80063B38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80063B3C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80063B40: jal         0x8006326C
    // 0x80063B44: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    Object_CheckPolyCollision(rdram, ctx);
        goto after_7;
    // 0x80063B44: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_7:
    // 0x80063B48: beql        $v0, $zero, L_80063C74
    if (ctx->r2 == 0) {
        // 0x80063B4C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80063C74;
    }
    goto skip_31;
    // 0x80063B4C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_31:
    // 0x80063B50: b           L_80063C84
    // 0x80063B54: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80063C84;
    // 0x80063B54: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80063B58:
    // 0x80063B58: lwc1        $f4, 0x110($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X110);
    // 0x80063B5C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80063B60: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x80063B64: nop

    // 0x80063B68: bc1f        L_80063BD8
    if (!c1cs) {
        // 0x80063B6C: nop
    
            goto L_80063BD8;
    }
    // 0x80063B6C: nop

    // 0x80063B70: lwc1        $f6, 0x2EC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2EC);
    // 0x80063B74: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x80063B78: lw          $a3, 0x2E8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X2E8);
    // 0x80063B7C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80063B80: lwc1        $f10, 0xFC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x80063B84: lwc1        $f8, 0x2F0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x80063B88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80063B8C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80063B90: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80063B94: jal         0x80062DBC
    // 0x80063B98: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Object_CheckHitboxCollision(rdram, ctx);
        goto after_8;
    // 0x80063B98: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x80063B9C: beq         $v0, $zero, L_80063C70
    if (ctx->r2 == 0) {
        // 0x80063BA0: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80063C70;
    }
    // 0x80063BA0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80063BA4: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80063BA8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80063BAC: sb          $t1, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r9;
    // 0x80063BB0: sh          $t2, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r10;
    // 0x80063BB4: sh          $t3, 0xD2($s0)
    MEM_H(0XD2, ctx->r16) = ctx->r11;
    // 0x80063BB8: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80063BBC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80063BC0: swc1        $f6, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f6.u32l;
    // 0x80063BC4: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80063BC8: swc1        $f8, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f8.u32l;
    // 0x80063BCC: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80063BD0: b           L_80063C84
    // 0x80063BD4: swc1        $f10, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f10.u32l;
        goto L_80063C84;
    // 0x80063BD4: swc1        $f10, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f10.u32l;
L_80063BD8:
    // 0x80063BD8: beq         $t4, $s3, L_80063C70
    if (ctx->r12 == ctx->r19) {
        // 0x80063BDC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80063C70;
    }
    // 0x80063BDC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80063BE0: beq         $t4, $at, L_80063C70
    if (ctx->r12 == ctx->r1) {
        // 0x80063BE4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80063C70;
    }
    // 0x80063BE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80063BE8: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x80063BEC: jal         0x800631A8
    // 0x80063BF0: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    Object_CheckSingleHitbox(rdram, ctx);
        goto after_9;
    // 0x80063BF0: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x80063BF4: beql        $v0, $zero, L_80063C74
    if (ctx->r2 == 0) {
        // 0x80063BF8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80063C74;
    }
    goto skip_32;
    // 0x80063BF8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_32:
    // 0x80063BFC: lhu         $a2, 0x2($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X2);
    // 0x80063C00: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80063C04: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80063C08: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80063C0C: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80063C10: sb          $t5, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r13;
    // 0x80063C14: sh          $t6, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r14;
    // 0x80063C18: bne         $a2, $at, L_80063C28
    if (ctx->r6 != ctx->r1) {
        // 0x80063C1C: sh          $t7, 0xD2($s0)
        MEM_H(0XD2, ctx->r16) = ctx->r15;
            goto L_80063C28;
    }
    // 0x80063C1C: sh          $t7, 0xD2($s0)
    MEM_H(0XD2, ctx->r16) = ctx->r15;
    // 0x80063C20: lw          $t8, 0x80($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X80);
    // 0x80063C24: bne         $t8, $zero, L_80063C50
    if (ctx->r24 != 0) {
        // 0x80063C28: addiu       $at, $zero, 0xC5
        ctx->r1 = ADD32(0, 0XC5);
            goto L_80063C50;
    }
L_80063C28:
    // 0x80063C28: addiu       $at, $zero, 0xC5
    ctx->r1 = ADD32(0, 0XC5);
    // 0x80063C2C: bnel        $a2, $at, L_80063C50
    if (ctx->r6 != ctx->r1) {
        // 0x80063C30: sh          $zero, 0xCE($s0)
        MEM_H(0XCE, ctx->r16) = 0;
            goto L_80063C50;
    }
    goto skip_33;
    // 0x80063C30: sh          $zero, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = 0;
    skip_33:
    // 0x80063C34: lh          $v0, 0xE4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XE4);
    // 0x80063C38: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80063C3C: bne         $at, $zero, L_80063C50
    if (ctx->r1 != 0) {
        // 0x80063C40: slti        $at, $v0, 0x64
        ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
            goto L_80063C50;
    }
    // 0x80063C40: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x80063C44: beql        $at, $zero, L_80063C54
    if (ctx->r1 == 0) {
        // 0x80063C48: lwc1        $f4, 0x0($s1)
        ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
            goto L_80063C54;
    }
    goto skip_34;
    // 0x80063C48: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    skip_34:
    // 0x80063C4C: sh          $zero, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = 0;
L_80063C50:
    // 0x80063C50: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
L_80063C54:
    // 0x80063C54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80063C58: swc1        $f4, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f4.u32l;
    // 0x80063C5C: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80063C60: swc1        $f6, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f6.u32l;
    // 0x80063C64: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80063C68: b           L_80063C84
    // 0x80063C6C: swc1        $f8, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f8.u32l;
        goto L_80063C84;
    // 0x80063C6C: swc1        $f8, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f8.u32l;
L_80063C70:
    // 0x80063C70: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80063C74:
    // 0x80063C74: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80063C78: bne         $s2, $at, L_80063A94
    if (ctx->r18 != ctx->r1) {
        // 0x80063C7C: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_80063A94;
    }
    // 0x80063C7C: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
    // 0x80063C80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80063C84:
    // 0x80063C84: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80063C88: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80063C8C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80063C90: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80063C94: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80063C98: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80063C9C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80063CA0: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80063CA4: jr          $ra
    // 0x80063CA8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80063CA8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Display_PlayerFeatures(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055B58: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80055B5C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80055B60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80055B64: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80055B68: lw          $t6, 0x234($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X234);
    // 0x80055B6C: beql        $t6, $zero, L_80055E88
    if (ctx->r14 == 0) {
        // 0x80055B70: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80055E88;
    }
    goto skip_0;
    // 0x80055B70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80055B74: lw          $t7, 0x1C8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C8);
    // 0x80055B78: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80055B7C: beql        $t7, $at, L_80055E88
    if (ctx->r15 == ctx->r1) {
        // 0x80055B80: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80055E88;
    }
    goto skip_1;
    // 0x80055B80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80055B84: lw          $v0, 0x1CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1CC);
    // 0x80055B88: beq         $v0, $zero, L_80055BA8
    if (ctx->r2 == 0) {
        // 0x80055B8C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80055BA8;
    }
    // 0x80055B8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80055B90: beq         $v0, $at, L_80055E00
    if (ctx->r2 == ctx->r1) {
        // 0x80055B94: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80055E00;
    }
    // 0x80055B94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80055B98: beq         $v0, $at, L_80055E7C
    if (ctx->r2 == ctx->r1) {
        // 0x80055B9C: nop
    
            goto L_80055E7C;
    }
    // 0x80055B9C: nop

    // 0x80055BA0: b           L_80055E88
    // 0x80055BA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80055E88;
    // 0x80055BA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80055BA8:
    // 0x80055BA8: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80055BAC: lwc1        $f6, 0xE8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x80055BB0: lwc1        $f10, 0x134($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X134);
    // 0x80055BB4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80055BB8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80055BBC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80055BC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055BC4: lwc1        $f6, 0x5EDC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5EDC);
    // 0x80055BC8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80055BCC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80055BD0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80055BD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80055BD8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80055BDC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80055BE0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80055BE4: jal         0x80005E90
    // 0x80055BE8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x80055BE8: nop

    after_0:
    // 0x80055BEC: lwc1        $f10, 0x120($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X120);
    // 0x80055BF0: lwc1        $f16, 0xE4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x80055BF4: lwc1        $f4, 0x134($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X134);
    // 0x80055BF8: lwc1        $f8, 0x4D8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4D8);
    // 0x80055BFC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80055C00: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055C04: lwc1        $f16, 0x5EE0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5EE0);
    // 0x80055C08: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80055C0C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80055C10: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80055C14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80055C18: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80055C1C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80055C20: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80055C24: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80055C28: jal         0x80005D44
    // 0x80055C2C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x80055C2C: nop

    after_1:
    // 0x80055C30: lwc1        $f6, 0xF8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x80055C34: lwc1        $f8, 0xF0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x80055C38: lwc1        $f16, 0x134($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X134);
    // 0x80055C3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80055C40: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80055C44: lwc1        $f4, 0x5EE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5EE4);
    // 0x80055C48: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80055C4C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80055C50: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80055C54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80055C58: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80055C5C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80055C60: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80055C64: jal         0x80005FE0
    // 0x80055C68: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x80055C68: nop

    after_2:
    // 0x80055C6C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80055C70: lw          $a1, 0x84($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X84);
    // 0x80055C74: lw          $a2, 0x80($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X80);
    // 0x80055C78: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80055C7C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80055C80: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80055C84: jal         0x80005B00
    // 0x80055C88: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x80055C88: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_3:
    // 0x80055C8C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80055C90: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80055C94: lwc1        $f10, 0x194($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X194);
    // 0x80055C98: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x80055C9C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80055CA0: mul.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80055CA4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80055CA8: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80055CAC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80055CB0: nop

    // 0x80055CB4: bc1fl       L_80055CC4
    if (!c1cs) {
        // 0x80055CB8: sub.s       $f18, $f16, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
            goto L_80055CC4;
    }
    goto skip_2;
    // 0x80055CB8: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    skip_2:
    // 0x80055CBC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80055CC0: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
L_80055CC4:
    // 0x80055CC4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80055CC8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80055CCC: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80055CD0: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x80055CD4: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x80055CD8: jal         0x80006970
    // 0x80055CDC: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x80055CDC: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x80055CE0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80055CE4: jal         0x80005708
    // 0x80055CE8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_5;
    // 0x80055CE8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_5:
    // 0x80055CEC: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80055CF0: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80055CF4: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80055CF8: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80055CFC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80055D00: lwc1        $f6, 0x144($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X144);
    // 0x80055D04: lwc1        $f4, 0x138($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80055D08: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80055D0C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80055D10: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80055D14: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80055D18: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80055D1C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80055D20: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80055D24: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80055D28: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80055D2C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80055D30: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80055D34: jal         0x80005B00
    // 0x80055D38: nop

    Matrix_Translate(rdram, ctx);
        goto after_6;
    // 0x80055D38: nop

    after_6:
    // 0x80055D3C: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80055D40: lw          $t1, 0x78A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78A0);
    // 0x80055D44: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80055D48: lw          $t0, -0x7D80($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D80);
    // 0x80055D4C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80055D50: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80055D54: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80055D58: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80055D5C: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x80055D60: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x80055D64: lwc1        $f18, 0x58($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X58);
    // 0x80055D68: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80055D6C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80055D70: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80055D74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80055D78: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80055D7C: jal         0x80005E90
    // 0x80055D80: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x80055D80: nop

    after_7:
    // 0x80055D84: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80055D88: lw          $t5, 0x78A0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78A0);
    // 0x80055D8C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80055D90: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x80055D94: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80055D98: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80055D9C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80055DA0: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80055DA4: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80055DA8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80055DAC: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80055DB0: lw          $a1, 0x5C($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X5C);
    // 0x80055DB4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80055DB8: jal         0x80005D44
    // 0x80055DBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x80055DBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80055DC0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80055DC4: jal         0x80006EB8
    // 0x80055DC8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_9;
    // 0x80055DC8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_9:
    // 0x80055DCC: jal         0x8005478C
    // 0x80055DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Display_LandmasterEngineGlow_Draw(rdram, ctx);
        goto after_10;
    // 0x80055DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80055DD4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80055DD8: jal         0x80005740
    // 0x80055DDC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_11;
    // 0x80055DDC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_11:
    // 0x80055DE0: jal         0x80054914
    // 0x80055DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Display_BarrelRollShield(rdram, ctx);
        goto after_12;
    // 0x80055DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80055DE8: jal         0x80054CA4
    // 0x80055DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Display_UnusedShield(rdram, ctx);
        goto after_13;
    // 0x80055DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80055DF0: jal         0x80054E80
    // 0x80055DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Display_ArwingLaserCharge(rdram, ctx);
        goto after_14;
    // 0x80055DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80055DF8: b           L_80055E88
    // 0x80055DFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80055E88;
    // 0x80055DFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80055E00:
    // 0x80055E00: jal         0x80052D48
    // 0x80055E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Display_LandmasterThrusters(rdram, ctx);
        goto after_15;
    // 0x80055E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80055E08: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80055E0C: jal         0x80005708
    // 0x80055E10: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_16;
    // 0x80055E10: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_16:
    // 0x80055E14: lw          $t8, 0x1C4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C4);
    // 0x80055E18: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80055E1C: addiu       $t1, $t1, 0x1518
    ctx->r9 = ADD32(ctx->r9, 0X1518);
    // 0x80055E20: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80055E24: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80055E28: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80055E2C: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x80055E30: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80055E34: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80055E38: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80055E3C: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80055E40: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x80055E44: jal         0x80005B00
    // 0x80055E48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    Matrix_Translate(rdram, ctx);
        goto after_17;
    // 0x80055E48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_17:
    // 0x80055E4C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80055E50: jal         0x80006EB8
    // 0x80055E54: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_18;
    // 0x80055E54: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_18:
    // 0x80055E58: jal         0x8005478C
    // 0x80055E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Display_LandmasterEngineGlow_Draw(rdram, ctx);
        goto after_19;
    // 0x80055E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80055E60: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80055E64: jal         0x80005740
    // 0x80055E68: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_20;
    // 0x80055E68: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_20:
    // 0x80055E6C: jal         0x80055788
    // 0x80055E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Display_LandmasterLaserCharge(rdram, ctx);
        goto after_21;
    // 0x80055E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80055E74: b           L_80055E88
    // 0x80055E78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80055E88;
    // 0x80055E78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80055E7C:
    // 0x80055E7C: jal         0x80054914
    // 0x80055E80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Display_BarrelRollShield(rdram, ctx);
        goto after_22;
    // 0x80055E80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80055E84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80055E88:
    // 0x80055E88: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80055E8C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80055E90: jr          $ra
    // 0x80055E94: nop

    return;
    // 0x80055E94: nop

;}
RECOMP_FUNC void AudioHeap_AllocZeroed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BE94: lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X4);
    // 0x8000BE98: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8000BE9C: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x8000BEA0: addiu       $v0, $a1, 0xF
    ctx->r2 = ADD32(ctx->r5, 0XF);
    // 0x8000BEA4: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8000BEA8: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x8000BEAC: addu        $t0, $a2, $t6
    ctx->r8 = ADD32(ctx->r6, ctx->r14);
    // 0x8000BEB0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8000BEB4: sltu        $at, $t9, $t0
    ctx->r1 = ctx->r25 < ctx->r8 ? 1 : 0;
    // 0x8000BEB8: bne         $at, $zero, L_8000BEF4
    if (ctx->r1 != 0) {
        // 0x8000BEBC: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_8000BEF4;
    }
    // 0x8000BEBC: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8000BEC0: addu        $t1, $a2, $t6
    ctx->r9 = ADD32(ctx->r6, ctx->r14);
    // 0x8000BEC4: sltu        $at, $a2, $t1
    ctx->r1 = ctx->r6 < ctx->r9 ? 1 : 0;
    // 0x8000BEC8: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x8000BECC: beq         $at, $zero, L_8000BEFC
    if (ctx->r1 == 0) {
        // 0x8000BED0: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8000BEFC;
    }
    // 0x8000BED0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000BED4: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
L_8000BED8:
    // 0x8000BED8: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x8000BEDC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000BEE0: sltu        $at, $a1, $t3
    ctx->r1 = ctx->r5 < ctx->r11 ? 1 : 0;
    // 0x8000BEE4: bnel        $at, $zero, L_8000BED8
    if (ctx->r1 != 0) {
        // 0x8000BEE8: sb          $zero, 0x0($a1)
        MEM_B(0X0, ctx->r5) = 0;
            goto L_8000BED8;
    }
    goto skip_0;
    // 0x8000BEE8: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    skip_0:
    // 0x8000BEEC: b           L_8000BF00
    // 0x8000BEF0: lw          $t4, 0xC($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XC);
        goto L_8000BF00;
    // 0x8000BEF0: lw          $t4, 0xC($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XC);
L_8000BEF4:
    // 0x8000BEF4: jr          $ra
    // 0x8000BEF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000BEF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000BEFC:
    // 0x8000BEFC: lw          $t4, 0xC($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XC);
L_8000BF00:
    // 0x8000BF00: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000BF04: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8000BF08: sw          $t5, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r13;
    // 0x8000BF0C: jr          $ra
    // 0x8000BF10: nop

    return;
    // 0x8000BF10: nop

;}
RECOMP_FUNC void Effect_OrbRing_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083FA8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80083FAC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80083FB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80083FB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80083FB8: lhu         $t6, 0x50($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X50);
    // 0x80083FBC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80083FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80083FC4: bne         $t6, $zero, L_80083FDC
    if (ctx->r14 != 0) {
        // 0x80083FC8: addiu       $v0, $v0, -0x7D80
        ctx->r2 = ADD32(ctx->r2, -0X7D80);
            goto L_80083FDC;
    }
    // 0x80083FC8: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x80083FCC: jal         0x80060FBC
    // 0x80083FD0: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x80083FD0: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_0:
    // 0x80083FD4: b           L_80084184
    // 0x80083FD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80084184;
    // 0x80083FD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80083FDC:
    // 0x80083FDC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80083FE0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80083FE4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80083FE8: lwc1        $f4, 0x58($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X58);
    // 0x80083FEC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083FF0: lwc1        $f2, 0x76D0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X76D0);
    // 0x80083FF4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80083FF8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80083FFC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80084000: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80084004: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80084008: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008400C: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80084010: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80084014: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80084018: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x8008401C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80084020: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80084024: lwc1        $f16, 0x5C($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X5C);
    // 0x80084028: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x8008402C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80084030: lwc1        $f16, 0x68($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80084034: div.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80084038: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x8008403C: lwc1        $f18, 0x76D4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X76D4);
    // 0x80084040: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80084044: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80084048: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8008404C: jal         0x80005FE0
    // 0x80084050: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_1;
    // 0x80084050: nop

    after_1:
    // 0x80084054: lh          $t9, 0x46($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X46);
    // 0x80084058: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008405C: lwc1        $f10, 0x76D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X76D8);
    // 0x80084060: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80084064: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80084068: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8008406C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80084070: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80084074: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80084078: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8008407C: jal         0x80005FE0
    // 0x80084080: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x80084080: nop

    after_2:
    // 0x80084084: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80084088: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008408C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80084090: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80084094: lwc1        $f18, 0x6C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80084098: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x8008409C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x800840A0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800840A4: jal         0x80006A20
    // 0x800840A8: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_3;
    // 0x800840A8: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x800840AC: lwc1        $f4, 0x60($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X60);
    // 0x800840B0: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800840B4: lwc1        $f10, 0x64($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X64);
    // 0x800840B8: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800840BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800840C0: lh          $t0, 0x48($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X48);
    // 0x800840C4: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x800840C8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800840CC: swc1        $f8, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f8.u32l;
    // 0x800840D0: lwc1        $f4, 0x60($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X60);
    // 0x800840D4: addiu       $t1, $t0, 0x2
    ctx->r9 = ADD32(ctx->r8, 0X2);
    // 0x800840D8: swc1        $f18, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f18.u32l;
    // 0x800840DC: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800840E0: lwc1        $f10, 0x64($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X64);
    // 0x800840E4: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x800840E8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800840EC: lui         $a1, 0x43AF
    ctx->r5 = S32(0X43AF << 16);
    // 0x800840F0: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x800840F4: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800840F8: sh          $t1, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r9;
    // 0x800840FC: lh          $v0, 0x48($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X48);
    // 0x80084100: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80084104: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x80084108: bne         $at, $zero, L_80084118
    if (ctx->r1 != 0) {
        // 0x8008410C: swc1        $f18, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
            goto L_80084118;
    }
    // 0x8008410C: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80084110: sh          $t2, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r10;
    // 0x80084114: lh          $v0, 0x48($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X48);
L_80084118:
    // 0x80084118: lh          $t3, 0x46($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X46);
    // 0x8008411C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80084120: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80084124: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80084128: sh          $t4, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r12;
    // 0x8008412C: lwc1        $f4, 0x76DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X76DC);
    // 0x80084130: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80084134: jal         0x8009BC2C
    // 0x80084138: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x80084138: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x8008413C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80084140: lwc1        $f8, 0x76E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X76E0);
    // 0x80084144: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80084148: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008414C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80084150: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80084154: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x80084158: bc1f        L_80084178
    if (!c1cs) {
        // 0x8008415C: nop
    
            goto L_80084178;
    }
    // 0x8008415C: nop

    // 0x80084160: lhu         $t5, 0x50($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X50);
    // 0x80084164: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x80084168: slti        $at, $t5, 0x33
    ctx->r1 = SIGNED(ctx->r13) < 0X33 ? 1 : 0;
    // 0x8008416C: bne         $at, $zero, L_80084178
    if (ctx->r1 != 0) {
        // 0x80084170: nop
    
            goto L_80084178;
    }
    // 0x80084170: nop

    // 0x80084174: sh          $t6, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r14;
L_80084178:
    // 0x80084178: jal         0x8007A774
    // 0x8008417C: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    Effect_CheckPlayerCollision(rdram, ctx);
        goto after_5;
    // 0x8008417C: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    after_5:
    // 0x80084180: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80084184:
    // 0x80084184: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80084188: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8008418C: jr          $ra
    // 0x80084190: nop

    return;
    // 0x80084190: nop

;}
RECOMP_FUNC void Effect_MeFireball_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078C84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078C88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80078C8C: jal         0x8005980C
    // 0x80078C90: lwc1        $f12, 0x70($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x80078C90: lwc1        $f12, 0x70($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X70);
    after_0:
    // 0x80078C94: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80078C98: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x80078C9C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80078CA0: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80078CA4: addiu       $t8, $zero, -0x40
    ctx->r24 = ADD32(0, -0X40);
    // 0x80078CA8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80078CAC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80078CB0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80078CB4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80078CB8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80078CBC: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80078CC0: addiu       $t1, $t1, 0xA80
    ctx->r9 = ADD32(ctx->r9, 0XA80);
    // 0x80078CC4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80078CC8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80078CCC: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x80078CD0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80078CD4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80078CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80078CDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80078CE0: jr          $ra
    // 0x80078CE4: nop

    return;
    // 0x80078CE4: nop

;}
RECOMP_FUNC void RCP_SetupDL_32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA430: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BA434: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BA438: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BA43C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BA440: addiu       $t8, $t8, 0x3AB0
    ctx->r24 = ADD32(ctx->r24, 0X3AB0);
    // 0x800BA444: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BA448: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BA44C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800BA450: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA454: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BA458: jr          $ra
    // 0x800BA45C: nop

    return;
    // 0x800BA45C: nop

;}
