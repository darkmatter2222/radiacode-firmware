/* firmware/rc-110/fw4.14 - flash.bin, Cortex-M4 (ARMv7E-M), Ghidra headless decompilation, one block per function */

/* ===== FUN_08010190 @ 08010190 ===== */

undefined8 FUN_08010190(void)

{
  uint *puVar1;
  ushort uVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = DAT_08010d40;
  uVar4 = *DAT_08010c08 & 0xffff;
  while (uVar4 != (*DAT_08010c08 & 0xffff)) {
    uVar4 = *DAT_08010c08 & 0xffff;
  }
  uVar2 = *DAT_08010c60 + (short)uVar4;
  if (uVar2 < (ushort)*DAT_08010d40) {
    uVar4 = *DAT_08010d40;
    puVar1 = DAT_08010d40 + 1;
    *DAT_08010d40 = uVar4 + 0x10000;
    puVar3[1] = *puVar1 + (uint)(0xfffeffff < uVar4);
  }
  *(ushort *)puVar3 = uVar2;
  return *(undefined8 *)puVar3;
}



/* ===== FUN_080101d4 @ 080101d4 ===== */

void FUN_080101d4(int param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_08010d9c;
  if (param_1 == 0) {
    *(uint *)(DAT_08010c70 + 0x54) = *(uint *)(DAT_08010c70 + 0x54) & 0xfffffeff;
    FUN_08015b44();
    *puVar1 = *puVar1 & 0xfffffffe;
    FUN_0802086a(0);
    return;
  }
  *(uint *)(DAT_08010c70 + 0x54) = *(uint *)(DAT_08010c70 + 0x54) | 0x100;
  FUN_08015b44(1);
  *puVar1 = *puVar1 | 1;
  return;
}



/* ===== FUN_0801020c @ 0801020c ===== */

void FUN_0801020c(uint param_1)

{
  uint uVar1;
  
  *(uint *)(DAT_08010c70 + 0x54) = *(uint *)(DAT_08010c70 + 0x54) & 0xfffffbff | (param_1 & 1) << 10
  ;
  if (param_1 == 0) {
    uVar1 = *DAT_08010d9c & 0xfffffffb;
  }
  else {
    uVar1 = *DAT_08010d9c | 4;
  }
  *DAT_08010d9c = uVar1;
  return;
}



/* ===== FUN_0801022e @ 0801022e ===== */

void FUN_0801022e(int param_1)

{
  *(undefined1 *)(param_1 + 0x18) = 1;
  FUN_08015b2a(1);
  *(undefined1 *)(param_1 + 0x1c) = 1;
  return;
}



/* ===== FUN_08010242 @ 08010242 ===== */

void FUN_08010242(int param_1)

{
  *(undefined1 *)(param_1 + 0x18) = 0;
  FUN_08015b2a(0);
  *(undefined1 *)(param_1 + 0x1c) = 0;
  FUN_08016890(param_1,0xf0000);
  return;
}



/* ===== FUN_08010262 @ 08010262 ===== */

void FUN_08010262(int param_1)

{
  if (*(char *)(param_1 + 0x1d) == '\0') {
    return;
  }
  FUN_08016996(0x1009);
  FUN_0801022e(param_1);
  return;
}



/* ===== FUN_080103b2 @ 080103b2 ===== */

/* WARNING: Removing unreachable block (ram,0x0802585c) */
/* WARNING: Removing unreachable block (ram,0x08025866) */

void FUN_080103b2(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  puVar1 = (undefined4 *)FUN_08018234(0x14);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = DAT_08010dcc;
    puVar1[3] = 0xffffffff;
    *(undefined1 *)(puVar1 + 2) = 0;
    puVar1[4] = 0;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08010dd4;
  }
  FUN_08018258(param_1,puVar1);
  iVar3 = DAT_08018ebc;
  iVar9 = (int)*(char *)(param_1 + 0x15);
  iVar2 = *(int *)(DAT_08018ebc + 0x28);
  if (iVar2 == 0) {
    iVar8 = 0;
  }
  else {
    iVar8 = *(int *)(iVar2 + 0x10);
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  iVar7 = iVar9;
  if (0 < iVar8) {
    iVar7 = *(int *)(param_1 + 0xc) / iVar8;
  }
  if ((0 < iVar7) && (iVar7 < iVar9)) {
    iVar9 = iVar7;
  }
  *(char *)(param_1 + 0x16) = (char)iVar9;
  if (iVar2 == 0) {
    return;
  }
  iVar3 = *(int *)(iVar3 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar3 + 9) = 1;
  *(undefined1 *)(iVar3 + 10) = 1;
  cVar6 = *(char *)(param_1 + 0x17);
  iVar3 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar2 = *(char *)(param_1 + 0x16) + -1;
    iVar8 = (int)cVar6;
    bVar10 = SBORROW4(iVar3,iVar8);
    iVar9 = iVar3 - iVar8;
    if (iVar8 <= iVar3) {
      iVar3 = iVar3 - iVar2;
      bVar10 = SBORROW4((int)cVar6,iVar3);
      iVar9 = cVar6 - iVar3;
    }
    if (iVar9 < 0 != bVar10) {
      cVar6 = (char)iVar3;
    }
    *(char *)(param_1 + 0x17) = cVar6;
    iVar3 = *(int *)(param_1 + 0x10);
    piVar4 = (int *)(DAT_080258a8 + cVar6 * 4 + 0x28);
    iVar9 = 0;
    piVar5 = piVar4;
    while( true ) {
      iVar8 = *piVar5;
      *(int *)(iVar8 + 0xc) = iVar9;
      *(undefined1 *)(iVar8 + 10) = 1;
      if (piVar4 + iVar2 <= piVar5) break;
      iVar9 = *(int *)(*piVar5 + 0x10) + iVar3 + iVar9;
      piVar5 = piVar5 + 1;
    }
  }
  return;
}



/* ===== FUN_08010c64 @ 08010c64 ===== */

void FUN_08010c64(undefined4 param_1)

{
  FUN_08015fd0(0x2c,&DAT_08010dc8);
  FUN_08016c18(param_1,0,3);
  return;
}



/* ===== FUN_080111e4 @ 080111e4 ===== */

void FUN_080111e4(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08011e2c;
  uVar3 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar3 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar3);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar3 & 0xcfff | 8);
  if ((int)((uint)*(byte *)(DAT_08011e60 + 0x58) << 0x19) < 0) {
    iVar2 = 0x18c;
  }
  else {
    iVar2 = 0x188;
  }
  FUN_08019d62(*(undefined4 *)(*piVar1 + iVar2));
  return;
}



/* ===== FUN_080112cc @ 080112cc ===== */

void FUN_080112cc(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08011e2c;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)(*piVar1 + 0x8c));
  return;
}



/* ===== FUN_080114fa @ 080114fa ===== */

void FUN_080114fa(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08011e2c;
  uVar3 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar3 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar3);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar3 & 0xcfff | 8);
  if ((int)((uint)*(byte *)(DAT_08011e60 + 0x54) << 0x1f) < 0) {
    iVar2 = 0xc;
  }
  else {
    iVar2 = 0x18;
  }
  FUN_08019d62(*(undefined4 *)(*piVar1 + iVar2));
  return;
}



/* ===== FUN_08011596 @ 08011596 ===== */

void FUN_08011596(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08011e2c;
  uVar3 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar3 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar3);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar3 & 0xcfff | 8);
  if (*(int *)(DAT_08011e60 + 0x54) << 0x1c < 0) {
    iVar2 = 0x19c;
  }
  else {
    iVar2 = 0x1a0;
  }
  FUN_08019d62(*(undefined4 *)(*piVar1 + iVar2));
  return;
}



/* ===== FUN_08011650 @ 08011650 ===== */

void FUN_08011650(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08011e2c;
  uVar3 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar3 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar3);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar3 & 0xcfff | 8);
  if (*(int *)(DAT_08011e60 + 0x54) << 0x1d < 0) {
    iVar2 = 0x3c;
  }
  else {
    iVar2 = 0x44;
  }
  FUN_08019d62(*(undefined4 *)(*piVar1 + iVar2));
  return;
}



/* ===== FUN_08011858 @ 08011858 ===== */

void FUN_08011858(int *param_1,uint param_2)

{
  ulonglong uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  byte local_19 [13];
  
  pbVar6 = local_19 + 1;
  if (DAT_08012404 < param_2) {
    param_2 = DAT_08012404;
  }
  while( true ) {
    uVar1 = (ulonglong)param_2 * (ulonglong)DAT_08012408 >> 0x23;
    uVar7 = (uint)uVar1;
    *pbVar6 = (char)param_2 + (char)uVar1 * -10;
    if (uVar7 == 0) break;
    pbVar6 = pbVar6 + 1;
    param_2 = uVar7;
  }
  iVar4 = (int)pbVar6 - (int)(local_19 + 1);
  if (pbVar6 == local_19 + 1) {
    *param_1 = 0x30;
    param_1[1] = 0x2e;
    param_1[2] = *pbVar6 + 0x30;
    piVar3 = param_1 + 3;
  }
  else {
    *param_1 = *pbVar6 + 0x30;
    if (iVar4 == 1 || iVar4 == 4) {
      iVar8 = 0x2e;
    }
    else {
      pbVar6 = pbVar6 + -1;
      iVar8 = *pbVar6 + 0x30;
    }
    param_1[1] = iVar8;
    if (iVar4 == 2 || iVar4 == 5) {
      iVar8 = 0x2e;
    }
    else {
      pbVar6 = pbVar6 + -1;
      iVar8 = *pbVar6 + 0x30;
    }
    param_1[2] = iVar8;
    piVar3 = param_1 + 3;
    if (iVar4 != 1 && iVar4 != 3) {
      piVar3 = param_1 + 4;
      param_1[3] = pbVar6[-1] + 0x30;
    }
  }
  piVar2 = DAT_08011e2c;
  *piVar3 = 0x20;
  if (iVar4 < 4) {
    uVar5 = *(undefined4 *)(*piVar2 + 0x3c);
  }
  else {
    uVar5 = *(undefined4 *)(*piVar2 + 0x40);
  }
  FUN_0801a2bc(piVar3 + 1,uVar5);
  return;
}



/* ===== FUN_080118f8 @ 080118f8 ===== */

void FUN_080118f8(int *param_1,uint param_2)

{
  ulonglong uVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  byte *pbVar7;
  uint uVar8;
  int iVar9;
  byte local_19 [13];
  
  if (DAT_08012404 < param_2) {
    param_2 = DAT_08012404;
  }
  pbVar7 = local_19 + 1;
  uVar4 = param_2 * 6;
  while( true ) {
    uVar1 = (ulonglong)uVar4 * (ulonglong)DAT_08012408 >> 0x23;
    uVar8 = (uint)uVar1;
    *pbVar7 = (char)uVar4 + (char)uVar1 * -10;
    if (uVar8 == 0) break;
    pbVar7 = pbVar7 + 1;
    uVar4 = uVar8;
  }
  iVar5 = (int)pbVar7 - (int)(local_19 + 1);
  *param_1 = *pbVar7 + 0x30;
  piVar3 = param_1 + 1;
  if (pbVar7 != local_19 + 1) {
    if (iVar5 == 3 || iVar5 == 6) {
      iVar9 = 0x2e;
    }
    else {
      pbVar7 = pbVar7 + -1;
      iVar9 = *pbVar7 + 0x30;
    }
    param_1[1] = iVar9;
    piVar3 = param_1 + 2;
    if (iVar5 != 1) {
      if (iVar5 == 4) {
        iVar9 = 0x2e;
      }
      else {
        pbVar7 = pbVar7 + -1;
        iVar9 = *pbVar7 + 0x30;
      }
      param_1[2] = iVar9;
      piVar3 = param_1 + 3;
      if (iVar5 != 2 && iVar5 != 5) {
        piVar3 = param_1 + 4;
        param_1[3] = pbVar7[-1] + 0x30;
      }
    }
  }
  piVar2 = DAT_08011e2c;
  *piVar3 = 0x20;
  iVar9 = *piVar2;
  if (iVar5 < 6) {
    if (iVar5 < 3) {
      uVar6 = *(undefined4 *)(iVar9 + 0x44);
    }
    else {
      uVar6 = *(undefined4 *)(iVar9 + 0x48);
    }
  }
  else {
    uVar6 = *(undefined4 *)(iVar9 + 0x4c);
  }
  FUN_0801a2bc(piVar3 + 1,uVar6);
  return;
}



/* ===== FUN_08011ccc @ 08011ccc ===== */

void FUN_08011ccc(int *param_1,uint param_2)

{
  ulonglong uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  int iVar10;
  byte local_1a [14];
  
  pbVar7 = local_1a + 2;
  while( true ) {
    uVar1 = (ulonglong)param_2 * (ulonglong)DAT_08012408 >> 0x23;
    uVar3 = (uint)uVar1;
    *pbVar7 = (char)param_2 + (char)uVar1 * -10;
    if (uVar3 == 0) break;
    pbVar7 = pbVar7 + 1;
    param_2 = uVar3;
  }
  iVar4 = (int)pbVar7 - (int)(local_1a + 2);
  if ((int)((uint)*(byte *)(DAT_08011e60 + 0x54) << 0x1f) < 0) {
    if (iVar4 < 2) {
      iVar10 = 0x30;
      pbVar8 = pbVar7;
    }
    else {
      pbVar8 = pbVar7 + -1;
      iVar10 = *pbVar7 + 0x30;
    }
    *param_1 = iVar10;
    if (iVar4 < 3) {
      iVar10 = 0x2e;
      pbVar9 = pbVar8;
    }
    else {
      pbVar9 = pbVar8 + -1;
      iVar10 = *pbVar8 + 0x30;
    }
    param_1[1] = iVar10;
    pbVar8 = pbVar9;
    if (iVar4 == 3) {
      iVar10 = 0x2e;
    }
    else if (pbVar7 == local_1a + 2) {
      iVar10 = 0x30;
    }
    else {
      pbVar8 = pbVar9 + -1;
      iVar10 = *pbVar9 + 0x30;
    }
    param_1[2] = iVar10;
    piVar6 = param_1 + 3;
    if (iVar4 != 4) {
      piVar6 = param_1 + 4;
      param_1[3] = *pbVar8 + 0x30;
    }
    piVar2 = DAT_08011e2c;
    *piVar6 = 0x20;
    uVar5 = *(undefined4 *)(*piVar2 + 0x24);
  }
  else {
    *param_1 = *pbVar7 + 0x30;
    piVar6 = param_1 + 1;
    if (pbVar7 != local_1a + 2) {
      if (iVar4 == 3) {
        iVar10 = 0x2e;
      }
      else {
        pbVar7 = pbVar7 + -1;
        iVar10 = *pbVar7 + 0x30;
      }
      param_1[1] = iVar10;
      piVar6 = param_1 + 2;
      if (iVar4 != 1) {
        if (iVar4 == 4) {
          iVar10 = 0x2e;
        }
        else {
          pbVar7 = pbVar7 + -1;
          iVar10 = *pbVar7 + 0x30;
        }
        param_1[2] = iVar10;
        piVar6 = param_1 + 3;
        if (iVar4 != 2) {
          piVar6 = param_1 + 4;
          param_1[3] = pbVar7[-1] + 0x30;
        }
      }
    }
    piVar2 = DAT_08011e2c;
    *piVar6 = 0x20;
    if (iVar4 < 3) {
      uVar5 = *(undefined4 *)(*piVar2 + 0x30);
    }
    else {
      uVar5 = *(undefined4 *)(*piVar2 + 0x34);
    }
  }
  FUN_0801a2bc(piVar6 + 1,uVar5);
  return;
}



/* ===== FUN_08011ff4 @ 08011ff4 ===== */

void FUN_08011ff4(int *param_1,uint param_2)

{
  ulonglong uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  byte local_19 [13];
  
  pbVar7 = local_19 + 1;
  while( true ) {
    uVar1 = (ulonglong)param_2 * (ulonglong)DAT_08012408 >> 0x23;
    uVar3 = (uint)uVar1;
    *pbVar7 = (char)param_2 + (char)uVar1 * -10;
    if (uVar3 == 0) break;
    pbVar7 = pbVar7 + 1;
    param_2 = uVar3;
  }
  iVar4 = (int)pbVar7 - (int)(local_19 + 1);
  if ((int)((uint)*(byte *)(DAT_08012bb4 + 0x54) << 0x1f) < 0) {
    if (iVar4 < 2) {
      iVar9 = 0x30;
      pbVar6 = pbVar7;
    }
    else {
      pbVar6 = pbVar7 + -1;
      iVar9 = *pbVar7 + 0x30;
    }
    *param_1 = iVar9;
    if ((iVar4 < 3) || (iVar4 == 5 || iVar4 == 8)) {
      iVar9 = 0x2e;
      pbVar8 = pbVar6;
    }
    else {
      pbVar8 = pbVar6 + -1;
      iVar9 = *pbVar6 + 0x30;
    }
    param_1[1] = iVar9;
    pbVar6 = pbVar8;
    if (pbVar7 == local_19 + 1) {
      iVar9 = 0x30;
    }
    else if (iVar4 == 3 || iVar4 == 6) {
      iVar9 = 0x2e;
    }
    else {
      pbVar6 = pbVar8 + -1;
      iVar9 = *pbVar8 + 0x30;
    }
    param_1[2] = iVar9;
    if (iVar4 == 4 || iVar4 == 7) {
      iVar9 = 0x2e;
      pbVar7 = pbVar6;
    }
    else {
      pbVar7 = pbVar6 + -1;
      iVar9 = *pbVar6 + 0x30;
    }
    param_1[3] = iVar9;
    piVar5 = param_1 + 4;
    if (2 < iVar4) {
      piVar5 = param_1 + 5;
      param_1[4] = *pbVar7 + 0x30;
    }
    if (iVar4 < 5) {
      iVar4 = 4;
    }
    else if (iVar4 < 8) {
      iVar4 = 8;
    }
    else {
      iVar4 = 0xc;
    }
  }
  else {
    *param_1 = *pbVar7 + 0x30;
    piVar5 = param_1 + 1;
    if (pbVar7 != local_19 + 1) {
      if (iVar4 == 3 || iVar4 == 6) {
        iVar9 = 0x2e;
        pbVar6 = pbVar7 + -1;
      }
      else {
        pbVar6 = pbVar7 + -2;
        iVar9 = pbVar7[-1] + 0x30;
      }
      param_1[1] = iVar9;
      piVar5 = param_1 + 2;
      if (iVar4 != 1) {
        piVar5 = param_1 + 3;
        if (iVar4 == 4 || iVar4 == 7) {
          iVar9 = 0x2e;
          pbVar7 = pbVar6;
        }
        else {
          pbVar7 = pbVar6 + -1;
          iVar9 = *pbVar6 + 0x30;
        }
        param_1[2] = iVar9;
        if (iVar4 != 2) {
          if (iVar4 == 5 || iVar4 == 8) {
            iVar9 = 0x2e;
            pbVar6 = pbVar7;
          }
          else {
            pbVar6 = pbVar7 + -1;
            iVar9 = *pbVar7 + 0x30;
          }
          *piVar5 = iVar9;
          piVar5 = param_1 + 5;
          param_1[4] = *pbVar6 + 0x30;
          if (2 < iVar4) {
            if (iVar4 < 6) {
              iVar4 = 0x14;
            }
            else {
              iVar4 = 0x18;
            }
            goto LAB_08012102;
          }
        }
      }
    }
    iVar4 = 0x10;
  }
LAB_08012102:
  piVar2 = DAT_08012a80;
  *piVar5 = 0x20;
  FUN_0801a2bc(piVar5 + 1,*(undefined4 *)(*piVar2 + iVar4));
  return;
}



/* ===== FUN_08012250 @ 08012250 ===== */

void FUN_08012250(undefined4 param_1)

{
  FUN_08015fd0(0x2b,&DAT_08012524);
  FUN_08016c18(param_1,0,3);
  return;
}



/* ===== FUN_0801227a @ 0801227a ===== */

/* WARNING: Removing unreachable block (ram,0x0802585c) */
/* WARNING: Removing unreachable block (ram,0x08025866) */

void FUN_0801227a(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  puVar1 = (undefined4 *)FUN_08018234(0x18);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = PTR_DAT_080123f8;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xe;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)(puVar1 + 2) = 0x39;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08012e48;
    puVar1[5] = 2;
  }
  FUN_08018258(param_1,puVar1);
  puVar1 = (undefined4 *)FUN_08018234(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = PTR_DAT_080123f8;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xe;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)(puVar1 + 2) = 0x46;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08012ff8;
    puVar1[5] = 2;
  }
  FUN_08018258(param_1,puVar1);
  puVar1 = (undefined4 *)FUN_08018234(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = PTR_DAT_080123f8;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xe;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)(puVar1 + 2) = 0x1f;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08012880;
    puVar1[5] = 2;
  }
  FUN_08018258(param_1,puVar1);
  puVar1 = (undefined4 *)FUN_08018234(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = PTR_DAT_080123f8;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xe;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)(puVar1 + 2) = 0x20;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08011cc8;
    puVar1[5] = 2;
  }
  FUN_08018258(param_1,puVar1);
  iVar3 = DAT_08018ebc;
  iVar9 = (int)*(char *)(param_1 + 0x15);
  iVar2 = *(int *)(DAT_08018ebc + 0x28);
  if (iVar2 == 0) {
    iVar8 = 2;
  }
  else {
    iVar8 = *(int *)(iVar2 + 0x10) + 2;
  }
  *(undefined4 *)(param_1 + 0x10) = 2;
  iVar7 = iVar9;
  if (0 < iVar8) {
    iVar7 = (*(int *)(param_1 + 0xc) + 2) / iVar8;
  }
  if ((0 < iVar7) && (iVar7 < iVar9)) {
    iVar9 = iVar7;
  }
  *(char *)(param_1 + 0x16) = (char)iVar9;
  if (iVar2 == 0) {
    return;
  }
  iVar3 = *(int *)(iVar3 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar3 + 9) = 1;
  *(undefined1 *)(iVar3 + 10) = 1;
  cVar6 = *(char *)(param_1 + 0x17);
  iVar3 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar2 = *(char *)(param_1 + 0x16) + -1;
    iVar8 = (int)cVar6;
    bVar10 = SBORROW4(iVar3,iVar8);
    iVar9 = iVar3 - iVar8;
    if (iVar8 <= iVar3) {
      iVar3 = iVar3 - iVar2;
      bVar10 = SBORROW4((int)cVar6,iVar3);
      iVar9 = cVar6 - iVar3;
    }
    if (iVar9 < 0 != bVar10) {
      cVar6 = (char)iVar3;
    }
    *(char *)(param_1 + 0x17) = cVar6;
    iVar3 = *(int *)(param_1 + 0x10);
    piVar4 = (int *)(DAT_080258a8 + cVar6 * 4 + 0x28);
    iVar9 = 0;
    piVar5 = piVar4;
    while( true ) {
      iVar8 = *piVar5;
      *(int *)(iVar8 + 0xc) = iVar9;
      *(undefined1 *)(iVar8 + 10) = 1;
      if (piVar4 + iVar2 <= piVar5) break;
      iVar9 = *(int *)(*piVar5 + 0x10) + iVar3 + iVar9;
      piVar5 = piVar5 + 1;
    }
  }
  return;
}



/* ===== FUN_0801231e @ 0801231e ===== */

void FUN_0801231e(int param_1)

{
  byte bVar1;
  int *piVar2;
  undefined4 uVar3;
  byte bVar4;
  uint uVar5;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar2 = DAT_08012a80;
  uVar5 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar5 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar5);
  FUN_08019d62(*(undefined4 *)(*piVar2 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar5 & 0xcfff | 8);
  bVar1 = *(byte *)(DAT_08012bb4 + 0x58) >> 2;
  bVar4 = bVar1 & 3;
  if ((bVar1 & 3) == 0) {
    uVar3 = *(undefined4 *)(*piVar2 + 0x11c);
  }
  else if (bVar4 == 2) {
    uVar3 = *(undefined4 *)(*piVar2 + 0x124);
  }
  else {
    if (1 < bVar4) {
      return;
    }
    uVar3 = *(undefined4 *)(*piVar2 + 0x120);
  }
  FUN_08019d62(uVar3);
  return;
}



/* ===== FUN_0801240c @ 0801240c ===== */

/* WARNING: Removing unreachable block (ram,0x0802585c) */
/* WARNING: Removing unreachable block (ram,0x08025866) */

void FUN_0801240c(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  
  piVar1 = (int *)FUN_08018234(0x18);
  iVar3 = DAT_08012a84;
  if (piVar1 != (int *)0x0) {
    *piVar1 = DAT_08012a84 + 8;
    *(undefined1 *)(piVar1 + 2) = 0x3a;
    piVar1[4] = 0xe;
    *(undefined1 *)((int)piVar1 + 9) = 0;
    piVar1[3] = -1;
    piVar1[1] = param_1;
    *(undefined1 *)((int)piVar1 + 10) = 1;
    *piVar1 = DAT_08013000;
    piVar1[5] = 2;
  }
  FUN_08018258(param_1);
  piVar1 = (int *)FUN_08018234(0x18);
  if (piVar1 != (int *)0x0) {
    *piVar1 = iVar3 + 8;
    *(undefined1 *)(piVar1 + 2) = 0x3e;
    piVar1[4] = 0xe;
    *(undefined1 *)((int)piVar1 + 9) = 0;
    piVar1[3] = -1;
    piVar1[1] = param_1;
    *(undefined1 *)((int)piVar1 + 10) = 1;
    *piVar1 = DAT_08013004;
    piVar1[5] = 2;
  }
  FUN_08018258(param_1,piVar1);
  piVar1 = (int *)FUN_08018234(0x18);
  if (piVar1 != (int *)0x0) {
    *piVar1 = iVar3 + 8;
    *(undefined1 *)(piVar1 + 2) = 0x45;
    piVar1[4] = 0xe;
    *(undefined1 *)((int)piVar1 + 9) = 0;
    piVar1[3] = -1;
    piVar1[1] = param_1;
    *(undefined1 *)((int)piVar1 + 10) = 1;
    *piVar1 = DAT_08013090;
    piVar1[5] = 2;
  }
  FUN_08018258(param_1,piVar1);
  piVar1 = (int *)FUN_08018234(0x18);
  if (piVar1 != (int *)0x0) {
    *piVar1 = iVar3 + 8;
    *(undefined1 *)(piVar1 + 2) = 0x1f;
    piVar1[4] = 0xe;
    *(undefined1 *)((int)piVar1 + 9) = 0;
    piVar1[3] = -1;
    piVar1[1] = param_1;
    *(undefined1 *)((int)piVar1 + 10) = 1;
    *piVar1 = DAT_08012880;
    piVar1[5] = 2;
  }
  FUN_08018258(param_1,piVar1);
  piVar1 = (int *)FUN_08018234(0x18);
  if (piVar1 != (int *)0x0) {
    *piVar1 = iVar3 + 8;
    *(undefined1 *)(piVar1 + 2) = 0x20;
    piVar1[4] = 0xe;
    *(undefined1 *)((int)piVar1 + 9) = 0;
    piVar1[3] = -1;
    piVar1[1] = param_1;
    *(undefined1 *)((int)piVar1 + 10) = 1;
    *piVar1 = DAT_08012884;
    piVar1[5] = 2;
  }
  FUN_08018258(param_1,piVar1);
  iVar3 = DAT_08018ebc;
  iVar8 = (int)*(char *)(param_1 + 0x15);
  iVar2 = *(int *)(DAT_08018ebc + 0x28);
  if (iVar2 == 0) {
    iVar7 = 2;
  }
  else {
    iVar7 = *(int *)(iVar2 + 0x10) + 2;
  }
  *(undefined4 *)(param_1 + 0x10) = 2;
  iVar6 = iVar8;
  if (0 < iVar7) {
    iVar6 = (*(int *)(param_1 + 0xc) + 2) / iVar7;
  }
  if ((0 < iVar6) && (iVar6 < iVar8)) {
    iVar8 = iVar6;
  }
  *(char *)(param_1 + 0x16) = (char)iVar8;
  if (iVar2 == 0) {
    return;
  }
  iVar3 = *(int *)(iVar3 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar3 + 9) = 1;
  *(undefined1 *)(iVar3 + 10) = 1;
  cVar5 = *(char *)(param_1 + 0x17);
  iVar3 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar2 = *(char *)(param_1 + 0x16) + -1;
    iVar7 = (int)cVar5;
    bVar9 = SBORROW4(iVar3,iVar7);
    iVar8 = iVar3 - iVar7;
    if (iVar7 <= iVar3) {
      iVar3 = iVar3 - iVar2;
      bVar9 = SBORROW4((int)cVar5,iVar3);
      iVar8 = cVar5 - iVar3;
    }
    if (iVar8 < 0 != bVar9) {
      cVar5 = (char)iVar3;
    }
    *(char *)(param_1 + 0x17) = cVar5;
    iVar3 = *(int *)(param_1 + 0x10);
    piVar4 = (int *)(DAT_080258a8 + cVar5 * 4 + 0x28);
    iVar8 = 0;
    piVar1 = piVar4;
    while( true ) {
      iVar7 = *piVar1;
      *(int *)(iVar7 + 0xc) = iVar8;
      *(undefined1 *)(iVar7 + 10) = 1;
      if (piVar4 + iVar2 <= piVar1) break;
      iVar8 = *(int *)(*piVar1 + 0x10) + iVar3 + iVar8;
      piVar1 = piVar1 + 1;
    }
  }
  return;
}



/* ===== FUN_08012606 @ 08012606 ===== */

void FUN_08012606(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08012a80;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(DAT_08012bb4 + 5) * 4 + 0xfc));
  return;
}



/* ===== FUN_08012692 @ 08012692 ===== */

void FUN_08012692(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  
  *(undefined1 *)(param_1 + 10) = 0;
  uVar3 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar3 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar3);
  FUN_08019d62(*(undefined4 *)(*DAT_08012a80 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar3 & 0xcfff | 8);
  piVar2 = DAT_080133f4;
  bVar1 = *(byte *)(DAT_08012bb4 + 1);
  DAT_080133f4[1] = 0;
  *piVar2 = bVar1 + 0x30;
  FUN_08019d62(piVar2,param_4);
  return;
}



/* ===== FUN_080126f6 @ 080126f6 ===== */

void FUN_080126f6(undefined4 param_1,uint param_2)

{
  uint uVar1;
  
  if ((param_2 & 7) == 1) {
    uVar1 = *(byte *)(DAT_08012bb4 + 1) + 1;
    if (9 < uVar1) {
      uVar1 = 0;
    }
    *(char *)(DAT_08012bb4 + 1) = (char)uVar1;
    FUN_0801b57c(1);
    FUN_0801a1be(param_1);
    *(uint *)(DAT_08012df8 + 0x10) = *(uint *)(DAT_08012df8 + 0x10) | 7;
  }
  return;
}



/* ===== FUN_080128cc @ 080128cc ===== */

void FUN_080128cc(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08012a80;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)
                (*piVar1 + ((*(uint *)(DAT_08012bb4 + 0x54) & 0x1fffff) >> 0x14) * 4 + 0x188));
  return;
}



/* ===== FUN_08012982 @ 08012982 ===== */

void FUN_08012982(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08012a80;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)(*piVar1 + ((*(uint *)(DAT_08012bb4 + 0x54) & 0xff) >> 7) * 4 + 0x188)
              );
  return;
}



/* ===== FUN_08012a88 @ 08012a88 ===== */

void FUN_08012a88(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08013664;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)
                (*piVar1 + ((*(uint *)(DAT_080137e0 + 0x54) & 0x7ff) >> 10) * 4 + 0x188));
  return;
}



/* ===== FUN_08012bb8 @ 08012bb8 ===== */

void FUN_08012bb8(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08013664;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)
                (*piVar1 + ((*(uint *)(DAT_080137e0 + 0x58) & 0xffff) >> 0xf) * 4 + 0x188));
  return;
}



/* ===== FUN_08012c0c @ 08012c0c ===== */

undefined4 FUN_08012c0c(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  if ((param_2 & 7) == 1) {
    uVar2 = *(uint *)(DAT_080137e0 + 0x58) >> 0x10 & 1 ^ 1;
    *(uint *)(DAT_080137e0 + 0x58) = *(uint *)(DAT_080137e0 + 0x58) & 0xfffeffff | uVar2 << 0x10;
    if (uVar2 == 0) {
      uVar2 = *DAT_080134d0 & 0xffffdfff;
    }
    else {
      uVar2 = *DAT_080134d0 | 0x2000;
    }
    *DAT_080134d0 = uVar2;
    uVar1 = FUN_0801862e();
    uVar3 = FUN_08010190();
    FUN_08018a4c((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),uVar1,3);
    FUN_0801a1be(param_1);
    *(uint *)(DAT_08012df8 + 0x10) = *(uint *)(DAT_08012df8 + 0x10) | 7;
  }
  return param_4;
}



/* ===== FUN_08012c68 @ 08012c68 ===== */

void FUN_08012c68(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08013664;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)
                (*piVar1 + ((*(uint *)(DAT_080137e0 + 0x58) & 0x1ffff) >> 0x10) * 4 + 0x188));
  return;
}



/* ===== FUN_08012d9c @ 08012d9c ===== */

void FUN_08012d9c(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08013664;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)
                (*piVar1 + ((*(uint *)(DAT_080137e0 + 0x54) & 0x3fffff) >> 0x15) * 4 + 0x188));
  return;
}



/* ===== FUN_08012e4c @ 08012e4c ===== */

/* WARNING: Removing unreachable block (ram,0x0802585c) */
/* WARNING: Removing unreachable block (ram,0x08025866) */

void FUN_08012e4c(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  
  iVar2 = FUN_08018234(0x18);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0801b9a0(iVar2,0x24,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  iVar2 = FUN_08018234(0x18);
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = FUN_0801b9b8(iVar2,0x27,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  iVar2 = FUN_08018234(0x18);
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = FUN_0801b9d0(iVar2,0x28,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  iVar2 = FUN_08018234(0x18);
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = FUN_0801b9e8(iVar2,0x29,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  puVar1 = (undefined4 *)FUN_08018234(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = PTR_DAT_080123f8;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xe;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)(puVar1 + 2) = 0x1f;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08012880;
    puVar1[5] = 2;
  }
  FUN_08018258(param_1,puVar1);
  puVar1 = (undefined4 *)FUN_08018234(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = PTR_DAT_080123f8;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xe;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)(puVar1 + 2) = 0x20;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08011cc8;
    puVar1[5] = 2;
  }
  FUN_08018258(param_1,puVar1);
  iVar2 = DAT_08018ebc;
  iVar10 = (int)*(char *)(param_1 + 0x15);
  iVar4 = *(int *)(DAT_08018ebc + 0x28);
  if (iVar4 == 0) {
    iVar9 = 2;
  }
  else {
    iVar9 = *(int *)(iVar4 + 0x10) + 2;
  }
  *(undefined4 *)(param_1 + 0x10) = 2;
  iVar8 = iVar10;
  if (0 < iVar9) {
    iVar8 = (*(int *)(param_1 + 0xc) + 2) / iVar9;
  }
  if ((0 < iVar8) && (iVar8 < iVar10)) {
    iVar10 = iVar8;
  }
  *(char *)(param_1 + 0x16) = (char)iVar10;
  if (iVar4 == 0) {
    return;
  }
  iVar2 = *(int *)(iVar2 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar2 + 9) = 1;
  *(undefined1 *)(iVar2 + 10) = 1;
  cVar7 = *(char *)(param_1 + 0x17);
  iVar2 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar4 = *(char *)(param_1 + 0x16) + -1;
    iVar9 = (int)cVar7;
    bVar11 = SBORROW4(iVar2,iVar9);
    iVar10 = iVar2 - iVar9;
    if (iVar9 <= iVar2) {
      iVar2 = iVar2 - iVar4;
      bVar11 = SBORROW4((int)cVar7,iVar2);
      iVar10 = cVar7 - iVar2;
    }
    if (iVar10 < 0 != bVar11) {
      cVar7 = (char)iVar2;
    }
    *(char *)(param_1 + 0x17) = cVar7;
    iVar2 = *(int *)(param_1 + 0x10);
    piVar5 = (int *)(DAT_080258a8 + cVar7 * 4 + 0x28);
    iVar10 = 0;
    piVar6 = piVar5;
    while( true ) {
      iVar9 = *piVar6;
      *(int *)(iVar9 + 0xc) = iVar10;
      *(undefined1 *)(iVar9 + 10) = 1;
      if (piVar5 + iVar4 <= piVar6) break;
      iVar10 = *(int *)(*piVar6 + 0x10) + iVar2 + iVar10;
      piVar6 = piVar6 + 1;
    }
  }
  return;
}



/* ===== FUN_08012eb8 @ 08012eb8 ===== */

void FUN_08012eb8(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08013664;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)(*piVar1 + ((*(uint *)(DAT_080137e0 + 0x58) & 0x3f) >> 5) * 4 + 0x94))
  ;
  return;
}



/* ===== FUN_080131d8 @ 080131d8 ===== */

void FUN_080131d8(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08013664;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)
                (*piVar1 + ((*(uint *)(DAT_080137e0 + 0x54) & 0xffffff) >> 0x17) * 4 + 0x188));
  return;
}



/* ===== FUN_08013278 @ 08013278 ===== */

/* WARNING: Removing unreachable block (ram,0x0802585c) */
/* WARNING: Removing unreachable block (ram,0x08025866) */

void FUN_08013278(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  
  iVar2 = FUN_08018234(0x18);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0801ba78(iVar2,0x50,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  iVar2 = FUN_08018234(0x18);
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = FUN_0801ba90(iVar2,0x52,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  puVar1 = (undefined4 *)FUN_08018234(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = PTR_DAT_080123f8;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xe;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)(puVar1 + 2) = 0x1f;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08012880;
    puVar1[5] = 2;
  }
  FUN_08018258(param_1,puVar1);
  puVar1 = (undefined4 *)FUN_08018234(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = PTR_DAT_080123f8;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xe;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)(puVar1 + 2) = 0x20;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08011cc8;
    puVar1[5] = 2;
  }
  FUN_08018258(param_1,puVar1);
  iVar2 = DAT_08018ebc;
  iVar10 = (int)*(char *)(param_1 + 0x15);
  iVar4 = *(int *)(DAT_08018ebc + 0x28);
  if (iVar4 == 0) {
    iVar9 = 2;
  }
  else {
    iVar9 = *(int *)(iVar4 + 0x10) + 2;
  }
  *(undefined4 *)(param_1 + 0x10) = 2;
  iVar8 = iVar10;
  if (0 < iVar9) {
    iVar8 = (*(int *)(param_1 + 0xc) + 2) / iVar9;
  }
  if ((0 < iVar8) && (iVar8 < iVar10)) {
    iVar10 = iVar8;
  }
  *(char *)(param_1 + 0x16) = (char)iVar10;
  if (iVar4 == 0) {
    return;
  }
  iVar2 = *(int *)(iVar2 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar2 + 9) = 1;
  *(undefined1 *)(iVar2 + 10) = 1;
  cVar7 = *(char *)(param_1 + 0x17);
  iVar2 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar4 = *(char *)(param_1 + 0x16) + -1;
    iVar9 = (int)cVar7;
    bVar11 = SBORROW4(iVar2,iVar9);
    iVar10 = iVar2 - iVar9;
    if (iVar9 <= iVar2) {
      iVar2 = iVar2 - iVar4;
      bVar11 = SBORROW4((int)cVar7,iVar2);
      iVar10 = cVar7 - iVar2;
    }
    if (iVar10 < 0 != bVar11) {
      cVar7 = (char)iVar2;
    }
    *(char *)(param_1 + 0x17) = cVar7;
    iVar2 = *(int *)(param_1 + 0x10);
    piVar5 = (int *)(DAT_080258a8 + cVar7 * 4 + 0x28);
    iVar10 = 0;
    piVar6 = piVar5;
    while( true ) {
      iVar9 = *piVar6;
      *(int *)(iVar9 + 0xc) = iVar10;
      *(undefined1 *)(iVar9 + 10) = 1;
      if (piVar5 + iVar4 <= piVar6) break;
      iVar10 = *(int *)(*piVar6 + 0x10) + iVar2 + iVar10;
      piVar6 = piVar6 + 1;
    }
  }
  return;
}



/* ===== FUN_080132b0 @ 080132b0 ===== */

void FUN_080132b0(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08013664;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)
                (*piVar1 + ((*(uint *)(DAT_080137e0 + 0x54) & 0x1fff) >> 0xc) * 4 + 0x188));
  return;
}



/* ===== FUN_08013354 @ 08013354 ===== */

void FUN_08013354(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08013664;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)
                (*piVar1 + ((*(uint *)(DAT_080137e0 + 0x54) & 0x1ffffff) >> 0x18) * 4 + 0x188));
  return;
}



/* ===== FUN_080133f8 @ 080133f8 ===== */

/* WARNING: Removing unreachable block (ram,0x0802585c) */
/* WARNING: Removing unreachable block (ram,0x08025866) */

void FUN_080133f8(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  
  iVar2 = FUN_08018234(0x18);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0801baa8(iVar2,0x50,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  iVar2 = FUN_08018234(0x18);
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = FUN_0801bac0(iVar2,0x52,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  puVar1 = (undefined4 *)FUN_08018234(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = PTR_DAT_080123f8;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xe;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)(puVar1 + 2) = 0x1f;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08012880;
    puVar1[5] = 2;
  }
  FUN_08018258(param_1,puVar1);
  puVar1 = (undefined4 *)FUN_08018234(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = PTR_DAT_080123f8;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xe;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)(puVar1 + 2) = 0x20;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08011cc8;
    puVar1[5] = 2;
  }
  FUN_08018258(param_1,puVar1);
  iVar2 = DAT_08018ebc;
  iVar10 = (int)*(char *)(param_1 + 0x15);
  iVar4 = *(int *)(DAT_08018ebc + 0x28);
  if (iVar4 == 0) {
    iVar9 = 2;
  }
  else {
    iVar9 = *(int *)(iVar4 + 0x10) + 2;
  }
  *(undefined4 *)(param_1 + 0x10) = 2;
  iVar8 = iVar10;
  if (0 < iVar9) {
    iVar8 = (*(int *)(param_1 + 0xc) + 2) / iVar9;
  }
  if ((0 < iVar8) && (iVar8 < iVar10)) {
    iVar10 = iVar8;
  }
  *(char *)(param_1 + 0x16) = (char)iVar10;
  if (iVar4 == 0) {
    return;
  }
  iVar2 = *(int *)(iVar2 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar2 + 9) = 1;
  *(undefined1 *)(iVar2 + 10) = 1;
  cVar7 = *(char *)(param_1 + 0x17);
  iVar2 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar4 = *(char *)(param_1 + 0x16) + -1;
    iVar9 = (int)cVar7;
    bVar11 = SBORROW4(iVar2,iVar9);
    iVar10 = iVar2 - iVar9;
    if (iVar9 <= iVar2) {
      iVar2 = iVar2 - iVar4;
      bVar11 = SBORROW4((int)cVar7,iVar2);
      iVar10 = cVar7 - iVar2;
    }
    if (iVar10 < 0 != bVar11) {
      cVar7 = (char)iVar2;
    }
    *(char *)(param_1 + 0x17) = cVar7;
    iVar2 = *(int *)(param_1 + 0x10);
    piVar5 = (int *)(DAT_080258a8 + cVar7 * 4 + 0x28);
    iVar10 = 0;
    piVar6 = piVar5;
    while( true ) {
      iVar9 = *piVar6;
      *(int *)(iVar9 + 0xc) = iVar10;
      *(undefined1 *)(iVar9 + 10) = 1;
      if (piVar5 + iVar4 <= piVar6) break;
      iVar10 = *(int *)(*piVar6 + 0x10) + iVar2 + iVar10;
      piVar6 = piVar6 + 1;
    }
  }
  return;
}



/* ===== FUN_08013430 @ 08013430 ===== */

void FUN_08013430(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08013664;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)
                (*piVar1 + ((*(uint *)(DAT_080137e0 + 0x54) & 0x3fff) >> 0xd) * 4 + 0x188));
  return;
}



/* ===== FUN_080134d4 @ 080134d4 ===== */

void FUN_080134d4(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08013664;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)
                (*piVar1 + ((*(uint *)(DAT_080137e0 + 0x54) & 0x3ffffff) >> 0x19) * 4 + 0x188));
  return;
}



/* ===== FUN_08013570 @ 08013570 ===== */

/* WARNING: Removing unreachable block (ram,0x0802585c) */
/* WARNING: Removing unreachable block (ram,0x08025866) */

void FUN_08013570(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  
  iVar2 = FUN_08018234(0x18);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0801bad8(iVar2,0x2d,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  iVar2 = FUN_08018234(0x18);
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = FUN_0801baf0(iVar2,0x2e,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  iVar2 = FUN_08018234(0x18);
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = FUN_0801bb08(iVar2,0x2f,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  puVar1 = (undefined4 *)FUN_08018234(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = PTR_DAT_080123f8;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xe;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)(puVar1 + 2) = 0x1f;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08012880;
    puVar1[5] = 2;
  }
  FUN_08018258(param_1,puVar1);
  puVar1 = (undefined4 *)FUN_08018234(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = PTR_DAT_080123f8;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xe;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)(puVar1 + 2) = 0x20;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08011cc8;
    puVar1[5] = 2;
  }
  FUN_08018258(param_1,puVar1);
  iVar2 = DAT_08018ebc;
  iVar10 = (int)*(char *)(param_1 + 0x15);
  iVar4 = *(int *)(DAT_08018ebc + 0x28);
  if (iVar4 == 0) {
    iVar9 = 2;
  }
  else {
    iVar9 = *(int *)(iVar4 + 0x10) + 2;
  }
  *(undefined4 *)(param_1 + 0x10) = 2;
  iVar8 = iVar10;
  if (0 < iVar9) {
    iVar8 = (*(int *)(param_1 + 0xc) + 2) / iVar9;
  }
  if ((0 < iVar8) && (iVar8 < iVar10)) {
    iVar10 = iVar8;
  }
  *(char *)(param_1 + 0x16) = (char)iVar10;
  if (iVar4 == 0) {
    return;
  }
  iVar2 = *(int *)(iVar2 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar2 + 9) = 1;
  *(undefined1 *)(iVar2 + 10) = 1;
  cVar7 = *(char *)(param_1 + 0x17);
  iVar2 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar4 = *(char *)(param_1 + 0x16) + -1;
    iVar9 = (int)cVar7;
    bVar11 = SBORROW4(iVar2,iVar9);
    iVar10 = iVar2 - iVar9;
    if (iVar9 <= iVar2) {
      iVar2 = iVar2 - iVar4;
      bVar11 = SBORROW4((int)cVar7,iVar2);
      iVar10 = cVar7 - iVar2;
    }
    if (iVar10 < 0 != bVar11) {
      cVar7 = (char)iVar2;
    }
    *(char *)(param_1 + 0x17) = cVar7;
    iVar2 = *(int *)(param_1 + 0x10);
    piVar5 = (int *)(DAT_080258a8 + cVar7 * 4 + 0x28);
    iVar10 = 0;
    piVar6 = piVar5;
    while( true ) {
      iVar9 = *piVar6;
      *(int *)(iVar9 + 0xc) = iVar10;
      *(undefined1 *)(iVar9 + 10) = 1;
      if (piVar5 + iVar4 <= piVar6) break;
      iVar10 = *(int *)(*piVar6 + 0x10) + iVar2 + iVar10;
      piVar6 = piVar6 + 1;
    }
  }
  return;
}



/* ===== FUN_08013668 @ 08013668 ===== */

/* WARNING: Removing unreachable block (ram,0x0802585c) */
/* WARNING: Removing unreachable block (ram,0x08025866) */

void FUN_08013668(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  
  iVar2 = FUN_08018234(0x18);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0801bb20(iVar2,0x50,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  iVar2 = FUN_08018234(0x18);
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = FUN_0801bb38(iVar2,0x52,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  puVar1 = (undefined4 *)FUN_08018234(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = PTR_DAT_080123f8;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xe;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)(puVar1 + 2) = 0x1f;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08012880;
    puVar1[5] = 2;
  }
  FUN_08018258(param_1,puVar1);
  puVar1 = (undefined4 *)FUN_08018234(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = PTR_DAT_080123f8;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xe;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)(puVar1 + 2) = 0x20;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08011cc8;
    puVar1[5] = 2;
  }
  FUN_08018258(param_1,puVar1);
  iVar2 = DAT_08018ebc;
  iVar10 = (int)*(char *)(param_1 + 0x15);
  iVar4 = *(int *)(DAT_08018ebc + 0x28);
  if (iVar4 == 0) {
    iVar9 = 2;
  }
  else {
    iVar9 = *(int *)(iVar4 + 0x10) + 2;
  }
  *(undefined4 *)(param_1 + 0x10) = 2;
  iVar8 = iVar10;
  if (0 < iVar9) {
    iVar8 = (*(int *)(param_1 + 0xc) + 2) / iVar9;
  }
  if ((0 < iVar8) && (iVar8 < iVar10)) {
    iVar10 = iVar8;
  }
  *(char *)(param_1 + 0x16) = (char)iVar10;
  if (iVar4 == 0) {
    return;
  }
  iVar2 = *(int *)(iVar2 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar2 + 9) = 1;
  *(undefined1 *)(iVar2 + 10) = 1;
  cVar7 = *(char *)(param_1 + 0x17);
  iVar2 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar4 = *(char *)(param_1 + 0x16) + -1;
    iVar9 = (int)cVar7;
    bVar11 = SBORROW4(iVar2,iVar9);
    iVar10 = iVar2 - iVar9;
    if (iVar9 <= iVar2) {
      iVar2 = iVar2 - iVar4;
      bVar11 = SBORROW4((int)cVar7,iVar2);
      iVar10 = cVar7 - iVar2;
    }
    if (iVar10 < 0 != bVar11) {
      cVar7 = (char)iVar2;
    }
    *(char *)(param_1 + 0x17) = cVar7;
    iVar2 = *(int *)(param_1 + 0x10);
    piVar5 = (int *)(DAT_080258a8 + cVar7 * 4 + 0x28);
    iVar10 = 0;
    piVar6 = piVar5;
    while( true ) {
      iVar9 = *piVar6;
      *(int *)(iVar9 + 0xc) = iVar10;
      *(undefined1 *)(iVar9 + 10) = 1;
      if (piVar5 + iVar4 <= piVar6) break;
      iVar10 = *(int *)(*piVar6 + 0x10) + iVar2 + iVar10;
      piVar6 = piVar6 + 1;
    }
  }
  return;
}



/* ===== FUN_080136a0 @ 080136a0 ===== */

void FUN_080136a0(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08014200;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)
                (*piVar1 + ((*(uint *)(DAT_08014438 + 0x54) & 0x7fff) >> 0xe) * 4 + 0x188));
  return;
}



/* ===== FUN_08013740 @ 08013740 ===== */

void FUN_08013740(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08014200;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)
                (*piVar1 + ((*(uint *)(DAT_08014438 + 0x54) & 0x7ffffff) >> 0x1a) * 4 + 0x188));
  return;
}



/* ===== FUN_080138d2 @ 080138d2 ===== */

void FUN_080138d2(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08014200;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)
                (*piVar1 + ((*(int *)(DAT_08014438 + 0x54) << 4) >> 0x1f) * -4 + 0x188));
  return;
}



/* ===== FUN_08013972 @ 08013972 ===== */

/* WARNING: Removing unreachable block (ram,0x0802585c) */
/* WARNING: Removing unreachable block (ram,0x08025866) */

void FUN_08013972(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  
  iVar2 = FUN_08018234(0x18);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0801bb80(iVar2,0x50,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  iVar2 = FUN_08018234(0x18);
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = FUN_0801bb98(iVar2,0x52,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  puVar1 = (undefined4 *)FUN_08018234(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = PTR_DAT_080123f8;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xe;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)(puVar1 + 2) = 0x1f;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08012880;
    puVar1[5] = 2;
  }
  FUN_08018258(param_1,puVar1);
  puVar1 = (undefined4 *)FUN_08018234(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = PTR_DAT_080123f8;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xe;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)(puVar1 + 2) = 0x20;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08011cc8;
    puVar1[5] = 2;
  }
  FUN_08018258(param_1,puVar1);
  iVar2 = DAT_08018ebc;
  iVar10 = (int)*(char *)(param_1 + 0x15);
  iVar4 = *(int *)(DAT_08018ebc + 0x28);
  if (iVar4 == 0) {
    iVar9 = 2;
  }
  else {
    iVar9 = *(int *)(iVar4 + 0x10) + 2;
  }
  *(undefined4 *)(param_1 + 0x10) = 2;
  iVar8 = iVar10;
  if (0 < iVar9) {
    iVar8 = (*(int *)(param_1 + 0xc) + 2) / iVar9;
  }
  if ((0 < iVar8) && (iVar8 < iVar10)) {
    iVar10 = iVar8;
  }
  *(char *)(param_1 + 0x16) = (char)iVar10;
  if (iVar4 == 0) {
    return;
  }
  iVar2 = *(int *)(iVar2 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar2 + 9) = 1;
  *(undefined1 *)(iVar2 + 10) = 1;
  cVar7 = *(char *)(param_1 + 0x17);
  iVar2 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar4 = *(char *)(param_1 + 0x16) + -1;
    iVar9 = (int)cVar7;
    bVar11 = SBORROW4(iVar2,iVar9);
    iVar10 = iVar2 - iVar9;
    if (iVar9 <= iVar2) {
      iVar2 = iVar2 - iVar4;
      bVar11 = SBORROW4((int)cVar7,iVar2);
      iVar10 = cVar7 - iVar2;
    }
    if (iVar10 < 0 != bVar11) {
      cVar7 = (char)iVar2;
    }
    *(char *)(param_1 + 0x17) = cVar7;
    iVar2 = *(int *)(param_1 + 0x10);
    piVar5 = (int *)(DAT_080258a8 + cVar7 * 4 + 0x28);
    iVar10 = 0;
    piVar6 = piVar5;
    while( true ) {
      iVar9 = *piVar6;
      *(int *)(iVar9 + 0xc) = iVar10;
      *(undefined1 *)(iVar9 + 10) = 1;
      if (piVar5 + iVar4 <= piVar6) break;
      iVar10 = *(int *)(*piVar6 + 0x10) + iVar2 + iVar10;
      piVar6 = piVar6 + 1;
    }
  }
  return;
}



/* ===== FUN_080139aa @ 080139aa ===== */

void FUN_080139aa(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08014200;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)
                (*piVar1 + ((*(int *)(DAT_08014438 + 0x54) << 0xf) >> 0x1f) * -4 + 0x188));
  return;
}



/* ===== FUN_08013a4c @ 08013a4c ===== */

void FUN_08013a4c(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08014200;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)
                (*piVar1 + ((*(int *)(DAT_08014438 + 0x54) << 3) >> 0x1f) * -4 + 0x188));
  return;
}



/* ===== FUN_08013cd0 @ 08013cd0 ===== */

void FUN_08013cd0(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08014200;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)
                (*piVar1 + ((*(int *)(DAT_080149ac + 0x54) << 2) >> 0x1f) * -4 + 0x188));
  return;
}



/* ===== FUN_08013e58 @ 08013e58 ===== */

void FUN_08013e58(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08014200;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)
                (*piVar1 + ((*(int *)(DAT_080149ac + 0x54) << 1) >> 0x1f) * -4 + 0x188));
  return;
}



/* ===== FUN_08013ef8 @ 08013ef8 ===== */

/* WARNING: Removing unreachable block (ram,0x0802585c) */
/* WARNING: Removing unreachable block (ram,0x08025866) */

void FUN_08013ef8(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  
  iVar2 = FUN_08018234(0x18);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0801bc58(iVar2,0x50,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  iVar2 = FUN_08018234(0x18);
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = FUN_0801bc70(iVar2,0x52,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  puVar1 = (undefined4 *)FUN_08018234(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = PTR_DAT_080123f8;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xe;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)(puVar1 + 2) = 0x1f;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08012880;
    puVar1[5] = 2;
  }
  FUN_08018258(param_1,puVar1);
  puVar1 = (undefined4 *)FUN_08018234(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = PTR_DAT_080123f8;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xe;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)(puVar1 + 2) = 0x20;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08011cc8;
    puVar1[5] = 2;
  }
  FUN_08018258(param_1,puVar1);
  iVar2 = DAT_08018ebc;
  iVar10 = (int)*(char *)(param_1 + 0x15);
  iVar4 = *(int *)(DAT_08018ebc + 0x28);
  if (iVar4 == 0) {
    iVar9 = 2;
  }
  else {
    iVar9 = *(int *)(iVar4 + 0x10) + 2;
  }
  *(undefined4 *)(param_1 + 0x10) = 2;
  iVar8 = iVar10;
  if (0 < iVar9) {
    iVar8 = (*(int *)(param_1 + 0xc) + 2) / iVar9;
  }
  if ((0 < iVar8) && (iVar8 < iVar10)) {
    iVar10 = iVar8;
  }
  *(char *)(param_1 + 0x16) = (char)iVar10;
  if (iVar4 == 0) {
    return;
  }
  iVar2 = *(int *)(iVar2 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar2 + 9) = 1;
  *(undefined1 *)(iVar2 + 10) = 1;
  cVar7 = *(char *)(param_1 + 0x17);
  iVar2 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar4 = *(char *)(param_1 + 0x16) + -1;
    iVar9 = (int)cVar7;
    bVar11 = SBORROW4(iVar2,iVar9);
    iVar10 = iVar2 - iVar9;
    if (iVar9 <= iVar2) {
      iVar2 = iVar2 - iVar4;
      bVar11 = SBORROW4((int)cVar7,iVar2);
      iVar10 = cVar7 - iVar2;
    }
    if (iVar10 < 0 != bVar11) {
      cVar7 = (char)iVar2;
    }
    *(char *)(param_1 + 0x17) = cVar7;
    iVar2 = *(int *)(param_1 + 0x10);
    piVar5 = (int *)(DAT_080258a8 + cVar7 * 4 + 0x28);
    iVar10 = 0;
    piVar6 = piVar5;
    while( true ) {
      iVar9 = *piVar6;
      *(int *)(iVar9 + 0xc) = iVar10;
      *(undefined1 *)(iVar9 + 10) = 1;
      if (piVar5 + iVar4 <= piVar6) break;
      iVar10 = *(int *)(*piVar6 + 0x10) + iVar2 + iVar10;
      piVar6 = piVar6 + 1;
    }
  }
  return;
}



/* ===== FUN_08013f30 @ 08013f30 ===== */

void FUN_08013f30(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08014200;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)
                (*piVar1 + ((*(int *)(DAT_080149ac + 0x54) << 0xc) >> 0x1f) * -4 + 0x188));
  return;
}



/* ===== FUN_08013fce @ 08013fce ===== */

void FUN_08013fce(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08014200;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar2);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar2 & 0xcfff | 8);
  FUN_08019d62(*(undefined4 *)(*piVar1 + (*(int *)(DAT_080149ac + 0x54) >> 0x1f) * -4 + 0x188));
  return;
}



/* ===== FUN_08014066 @ 08014066 ===== */

void FUN_08014066(undefined4 param_1)

{
  ulonglong uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined1 auStack_20 [4];
  char acStack_1c [6];
  char acStack_16 [2];
  
  FUN_08015fca(0x2d);
  FUN_0801bc88(param_1,*(undefined4 *)(*DAT_08014200 + 0xd8),0);
  uVar2 = *(uint *)(DAT_08014438 + 0x40);
  if (DAT_080149b8 < *(uint *)(DAT_08014438 + 0x40)) {
    uVar2 = DAT_080149b8;
  }
  pcVar5 = acStack_1c + 5;
  if (acStack_1c <= acStack_1c + 5) {
    for (; acStack_1c <= pcVar5; pcVar5 = pcVar5 + -1) {
      uVar1 = (ulonglong)uVar2 * (ulonglong)DAT_080149c4 >> 0x23;
      *pcVar5 = (char)uVar2 + (char)uVar1 * -10;
      uVar2 = (uint)uVar1;
    }
  }
  while (iVar3 = FUN_0801d3c0(param_1,auStack_20), iVar3 != 0) {
    puVar4 = (undefined4 *)FUN_08018234(0x1c);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      pcVar5 = pcVar5 + 1;
      FUN_0801d428(puVar4,param_1,auStack_20,*pcVar5);
      *puVar4 = DAT_080149c8;
    }
    FUN_08018258(param_1,puVar4);
  }
  FUN_08016c18(param_1,0,1);
  return;
}



/* ===== FUN_08014204 @ 08014204 ===== */

void FUN_08014204(undefined4 param_1)

{
  ulonglong uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined1 auStack_20 [4];
  char acStack_1c [7];
  char cStack_15;
  
  FUN_08015fca(0x2e);
  FUN_0801bc88(param_1,*(undefined4 *)(*DAT_080149c0 + 0xdc),0);
  uVar2 = *(uint *)(DAT_08014438 + 0x44);
  if (DAT_080149b8 < *(uint *)(DAT_08014438 + 0x44)) {
    uVar2 = DAT_080149b8;
  }
  pcVar5 = acStack_1c + 6;
  uVar2 = uVar2 * 6;
  if (acStack_1c <= acStack_1c + 6) {
    for (; acStack_1c <= pcVar5; pcVar5 = pcVar5 + -1) {
      uVar1 = (ulonglong)uVar2 * (ulonglong)DAT_080149c4 >> 0x23;
      *pcVar5 = (char)uVar2 + (char)uVar1 * -10;
      uVar2 = (uint)uVar1;
    }
  }
  while (iVar3 = FUN_0801d3c0(param_1,auStack_20), iVar3 != 0) {
    puVar4 = (undefined4 *)FUN_08018234(0x1c);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      pcVar5 = pcVar5 + 1;
      FUN_0801d428(puVar4,param_1,auStack_20,*pcVar5);
      *puVar4 = DAT_080149c8;
    }
    FUN_08018258(param_1,puVar4);
  }
  FUN_08016c18(param_1,0,1);
  return;
}



/* ===== FUN_080142ea @ 080142ea ===== */

void FUN_080142ea(undefined4 param_1)

{
  ulonglong uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined1 auStack_20 [4];
  char acStack_1c [5];
  char acStack_17 [3];
  
  FUN_08015fca(0x2d);
  iVar3 = DAT_080149ac;
  if ((int)((uint)*(byte *)(DAT_080149ac + 0x54) << 0x1f) < 0) {
    uVar5 = *(undefined4 *)(*DAT_080149c0 + 200);
  }
  else {
    uVar5 = *(undefined4 *)(*DAT_080149c0 + 0xcc);
  }
  FUN_0801bc88(param_1,uVar5,0);
  pcVar6 = acStack_1c + 4;
  uVar2 = *(uint *)(iVar3 + 0x30);
  if (acStack_1c <= acStack_1c + 4) {
    for (; acStack_1c <= pcVar6; pcVar6 = pcVar6 + -1) {
      uVar1 = (ulonglong)uVar2 * (ulonglong)DAT_080149c4 >> 0x23;
      *pcVar6 = (char)uVar2 + (char)uVar1 * -10;
      uVar2 = (uint)uVar1;
    }
  }
  while (iVar3 = FUN_0801d3c0(param_1,auStack_20), iVar3 != 0) {
    puVar4 = (undefined4 *)FUN_08018234(0x1c);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      pcVar6 = pcVar6 + 1;
      FUN_0801d428(puVar4,param_1,auStack_20,*pcVar6);
      *puVar4 = DAT_080149c8;
    }
    FUN_08018258(param_1,puVar4);
  }
  FUN_08016c18(param_1,0,1);
  return;
}



/* ===== FUN_0801466c @ 0801466c ===== */

/* WARNING: Removing unreachable block (ram,0x0802585c) */
/* WARNING: Removing unreachable block (ram,0x08025866) */

void FUN_0801466c(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  
  iVar2 = FUN_08018234(0x18);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0801d800(iVar2,0x5c,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  iVar2 = FUN_08018234(0x18);
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = FUN_0801d818(iVar2,0x5d,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  iVar2 = FUN_08018234(0x18);
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = FUN_0801d830(iVar2,0x5e,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  iVar2 = FUN_08018234(0x18);
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = FUN_0801d848(iVar2,0x5f,0xe,param_1);
  }
  FUN_08018258(param_1,uVar3);
  puVar1 = (undefined4 *)FUN_08018234(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = PTR_DAT_080123f8;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xe;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)(puVar1 + 2) = 0x1f;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08012880;
    puVar1[5] = 2;
  }
  FUN_08018258(param_1,puVar1);
  puVar1 = (undefined4 *)FUN_08018234(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = PTR_DAT_080123f8;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xe;
    *(undefined1 *)((int)puVar1 + 9) = 0;
    *(undefined1 *)(puVar1 + 2) = 0x20;
    puVar1[1] = param_1;
    *(undefined1 *)((int)puVar1 + 10) = 1;
    *puVar1 = DAT_08011cc8;
    puVar1[5] = 2;
  }
  FUN_08018258(param_1,puVar1);
  iVar2 = DAT_08018ebc;
  iVar10 = (int)*(char *)(param_1 + 0x15);
  iVar4 = *(int *)(DAT_08018ebc + 0x28);
  if (iVar4 == 0) {
    iVar9 = 2;
  }
  else {
    iVar9 = *(int *)(iVar4 + 0x10) + 2;
  }
  *(undefined4 *)(param_1 + 0x10) = 2;
  iVar8 = iVar10;
  if (0 < iVar9) {
    iVar8 = (*(int *)(param_1 + 0xc) + 2) / iVar9;
  }
  if ((0 < iVar8) && (iVar8 < iVar10)) {
    iVar10 = iVar8;
  }
  *(char *)(param_1 + 0x16) = (char)iVar10;
  if (iVar4 == 0) {
    return;
  }
  iVar2 = *(int *)(iVar2 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar2 + 9) = 1;
  *(undefined1 *)(iVar2 + 10) = 1;
  cVar7 = *(char *)(param_1 + 0x17);
  iVar2 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar4 = *(char *)(param_1 + 0x16) + -1;
    iVar9 = (int)cVar7;
    bVar11 = SBORROW4(iVar2,iVar9);
    iVar10 = iVar2 - iVar9;
    if (iVar9 <= iVar2) {
      iVar2 = iVar2 - iVar4;
      bVar11 = SBORROW4((int)cVar7,iVar2);
      iVar10 = cVar7 - iVar2;
    }
    if (iVar10 < 0 != bVar11) {
      cVar7 = (char)iVar2;
    }
    *(char *)(param_1 + 0x17) = cVar7;
    iVar2 = *(int *)(param_1 + 0x10);
    piVar5 = (int *)(DAT_080258a8 + cVar7 * 4 + 0x28);
    iVar10 = 0;
    piVar6 = piVar5;
    while( true ) {
      iVar9 = *piVar6;
      *(int *)(iVar9 + 0xc) = iVar10;
      *(undefined1 *)(iVar9 + 10) = 1;
      if (piVar5 + iVar4 <= piVar6) break;
      iVar10 = *(int *)(*piVar6 + 0x10) + iVar2 + iVar10;
      piVar6 = piVar6 + 1;
    }
  }
  return;
}



/* ===== FUN_080146d8 @ 080146d8 ===== */

void FUN_080146d8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  *(undefined1 *)(param_1 + 10) = 0;
  uVar1 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar1 = 0x3001;
  }
  FUN_08019780(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_080197c8(uVar1);
  FUN_08019d62(*(undefined4 *)(*DAT_080149c0 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_080197c8(uVar1 & 0xcfff | 8);
  FUN_08019d56("2BDDP-110",param_4);
  return;
}



/* ===== FUN_0801484e @ 0801484e ===== */

void FUN_0801484e(undefined4 param_1)

{
  FUN_08015fd0(0x61,&DAT_080149b4);
  FUN_08016c18(param_1,0,3);
  return;
}



/* ===== FUN_08014874 @ 08014874 ===== */

void FUN_08014874(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 in_r3;
  
  iVar1 = DAT_080149b0;
  *(undefined1 *)(DAT_080149b0 + 0x14) = 0;
  puVar2 = (undefined4 *)FUN_08018234(0x1c);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    FUN_08018300(puVar2,0);
    *puVar2 = DAT_080149e8;
  }
  FUN_08018338(iVar1,puVar2,in_r3);
  return;
}



/* ===== FUN_08014898 @ 08014898 ===== */

undefined4 FUN_08014898(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DAT_080149b0;
  FUN_0801f6e8(DAT_080149b0,param_1);
  return *(undefined4 *)(iVar1 + 0x10);
}



/* ===== FUN_080148ac @ 080148ac ===== */

void FUN_080148ac(void)

{
  int iVar1;
  
  iVar1 = DAT_080149b0;
  if ('\x02' < *(char *)(DAT_080149b0 + 0x14)) {
    return;
  }
  if (*(char *)(DAT_080149b0 + 0x1d) != '\0') {
    FUN_08016996(0x1009);
  }
  FUN_0801022e(iVar1);
  return;
}



/* ===== FUN_080148d6 @ 080148d6 ===== */

void FUN_080148d6(void)

{
  *(undefined1 *)(DAT_080149b0 + 0x1a) = 1;
  return;
}



/* ===== FUN_080148de @ 080148de ===== */

void FUN_080148de(void)

{
  *(undefined2 *)(DAT_080149b0 + 0x1a) = 0;
  return;
}



/* ===== FUN_080148e6 @ 080148e6 ===== */

void FUN_080148e6(void)

{
  int iVar1;
  
  iVar1 = DAT_080149b0;
  if ((*(char *)(DAT_080149b0 + 0x1c) != '\0') && (*(char *)(DAT_080149b0 + 0x1d) == '\0')) {
    FUN_08016996(0x1009);
  }
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  return;
}



/* ===== FUN_0801496a @ 0801496a ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0801496a(void)

{
  if (*(char *)(DAT_080149b0 + 0x14) < 1) {
    return 0;
  }
  return *(undefined1 *)(*(int *)(_DAT_080149ec + *(char *)(DAT_080149b0 + 0x14) * 4 + -4) + 4);
}



/* ===== FUN_08014986 @ 08014986 ===== */

void FUN_08014986(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = DAT_080149b0;
  *(undefined4 *)(DAT_080149b0 + 0x24) = param_1;
  FUN_0801827c(iVar1,0);
  iVar2 = FUN_08018234(0xa4);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0801f898();
  }
  FUN_08018338(iVar1,uVar3);
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 7;
  return;
}



/* ===== FUN_08014bd8 @ 08014bd8 ===== */

int FUN_08014bd8(int *param_1)

{
  int iVar1;
  
  (**(code **)(*param_1 + 0x14))(param_1,(int)*DAT_08015994);
  iVar1 = param_1[3];
  if (*(int *)(iVar1 + 0xc) != 0) {
    FUN_0801fb10();
  }
  FUN_080197c8(*(undefined2 *)(iVar1 + 8));
  return iVar1;
}



/* ===== FUN_08014bfe @ 08014bfe ===== */

void FUN_08014bfe(int *param_1,int param_2)

{
  char *pcVar1;
  
  pcVar1 = DAT_08015994;
  param_1[3] = param_2;
  (**(code **)(*param_1 + 0x14))(param_1,(int)*pcVar1);
  if (*(int *)(param_2 + 0xc) != 0) {
    FUN_0801fb10();
  }
  FUN_080197c8(*(undefined2 *)(param_2 + 8));
  return;
}



/* ===== FUN_08014c24 @ 08014c24 ===== */

void FUN_08014c24(int param_1)

{
  FUN_08014bfe(param_1,&LAB_080153ec);
  *(undefined1 *)(param_1 + 0x10) = 0xff;
  return;
}



/* ===== FUN_08014c38 @ 08014c38 ===== */

void FUN_08014c38(int param_1)

{
  FUN_08014bfe(param_1,&DAT_08014c5c);
  FUN_0801fb94(**(undefined1 **)(param_1 + 0xc));
  *(undefined1 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 0x15) = 0;
  *(undefined **)(param_1 + 0x1c) = PTR_DAT_080159e4;
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x10);
  return;
}



/* ===== FUN_08014eec @ 08014eec ===== */

void FUN_08014eec(int param_1)

{
  FUN_08014bfe(param_1,&DAT_08014f10);
  FUN_0801fb94(**(undefined1 **)(param_1 + 0xc));
  *(undefined1 *)(param_1 + 0x15) = 0x1f;
  *(undefined1 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x1c) = DAT_08015c08;
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x10);
  return;
}



/* ===== FUN_08014f9a @ 08014f9a ===== */

void FUN_08014f9a(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_0801554c;
  FUN_0801fb94(**(undefined1 **)(param_1 + 0xc));
  FUN_0801fe10(DAT_0801565c);
  FUN_0801fca0(DAT_08015654);
  FUN_0801fcdc(iVar1 + 0x10);
  FUN_0801fd0c(iVar1 + 8);
  FUN_0801fd38(iVar1);
  iVar1 = DAT_080155e4;
  FUN_0801fe26(DAT_080155e4 + 4);
  FUN_0801fe64(iVar1 + 0xc);
  return;
}



/* ===== FUN_08014fe4 @ 08014fe4 ===== */

undefined4 FUN_08014fe4(int param_1)

{
  int iVar1;
  byte *pbVar2;
  undefined4 uVar3;
  uint extraout_r1;
  uint uVar4;
  undefined4 extraout_r3;
  byte unaff_r5;
  uint uVar5;
  
  iVar1 = DAT_0801554c;
  FUN_0801fb94(**(undefined1 **)(param_1 + 0xc));
  FUN_0801fe90(DAT_0801565c);
  FUN_0801fd68(DAT_08015654);
  FUN_0801fd86(iVar1 + 0x10);
  FUN_0801fda4(iVar1 + 8);
  FUN_0801fdd8(iVar1);
  iVar1 = DAT_080155e4;
  FUN_0801feae(DAT_080155e4 + 4);
  pbVar2 = *(byte **)(iVar1 + 0x10);
  uVar5 = 0;
  uVar4 = extraout_r1;
  if (pbVar2 != (byte *)0x0) {
    unaff_r5 = *pbVar2;
    uVar5 = (uint)unaff_r5;
    uVar4 = (uint)*(byte *)(iVar1 + 0xf);
  }
  if (pbVar2 != (byte *)0x0 && uVar5 != uVar4) {
    if (uVar5 < *(ushort *)(DAT_0801ff00 + 8)) {
      uVar3 = FUN_0802c16c();
      FUN_0802c188(*(undefined1 *)(iVar1 + 0xd),*(undefined1 *)(iVar1 + 0xe),uVar3);
    }
    *(byte *)(iVar1 + 0xf) = unaff_r5;
  }
  return extraout_r3;
}



/* ===== FUN_0801502e @ 0801502e ===== */

void FUN_0801502e(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  FUN_08014bfe(param_1,&LAB_080152ac);
  FUN_0801fb94(**(undefined1 **)(param_1 + 0xc));
  puVar1 = DAT_0801554c;
  DAT_0801554c[0x1d] = (char)((*(byte *)(DAT_0801566c + 0x59) & 3) >> 1);
  iVar2 = DAT_080155e4;
  *(undefined1 *)(DAT_080155e4 + 0x15) = 0;
  *(undefined1 *)(iVar2 + 0x16) = 0;
  *(undefined1 **)(iVar2 + 0x18) = puVar1 + 0x1d;
  puVar3 = DAT_08015658;
  *(undefined1 *)(iVar2 + 0x17) = *(undefined1 *)(iVar2 + 0x14);
  *(undefined1 *)(puVar3 + 1) = 0x11;
  *(undefined1 *)((int)puVar3 + 5) = 10;
  puVar3[3] = puVar1 + 0x74;
  puVar3[2] = *puVar3;
  puVar3 = DAT_08015654;
  *(undefined1 *)((int)DAT_08015654 + 5) = 9;
  *(undefined1 *)(puVar3 + 1) = 0x3b;
  puVar3[3] = puVar1 + 0x8c;
  puVar3[2] = *puVar3;
  puVar1[0x12] = 0;
  puVar1[0x11] = 0x4a;
  *(undefined1 **)(puVar1 + 0x14) = puVar1 + 0x1a;
  puVar1[0x13] = puVar1[0x10];
  puVar1[9] = 0x57;
  puVar1[10] = 0;
  *(undefined1 **)(puVar1 + 0xc) = puVar1 + 0x18;
  puVar1[0xb] = puVar1[8];
  puVar1[1] = 0x62;
  puVar1[2] = 0;
  *(undefined1 **)(puVar1 + 4) = puVar1 + 0x19;
  puVar1[3] = *puVar1;
  *(undefined1 *)(iVar2 + 5) = 0x6b;
  *(undefined1 *)(iVar2 + 6) = 10;
  *(undefined1 **)(iVar2 + 8) = puVar1 + 0x1c;
  *(undefined1 *)(iVar2 + 0xd) = 0x7b;
  *(undefined1 *)(iVar2 + 7) = *(undefined1 *)(iVar2 + 4);
  *(undefined1 *)(iVar2 + 0xe) = 0;
  *(undefined1 **)(iVar2 + 0x10) = puVar1 + 0x1b;
  *(undefined1 *)(iVar2 + 0xf) = *(undefined1 *)(iVar2 + 0xc);
  return;
}



/* ===== FUN_080151a8 @ 080151a8 ===== */

void FUN_080151a8(int param_1)

{
  FUN_08014bfe(param_1,&DAT_080151cc);
  FUN_0801fb94(**(undefined1 **)(param_1 + 0xc));
  *(undefined1 *)(param_1 + 0x224) = 0;
  *(undefined1 *)(param_1 + 0x225) = 0xff;
  return;
}



/* ===== FUN_08015694 @ 08015694 ===== */

undefined4 FUN_08015694(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *unaff_r4;
  
  piVar1 = param_1;
  if (*DAT_08016140 != 0) {
    piVar1 = (int *)(uint)*(byte *)((int)param_1 + 10);
    unaff_r4 = param_1;
  }
  if (*DAT_08016140 == 0 || piVar1 == param_2) {
switchD_080156c8_default:
    return param_4;
  }
  iVar3 = *unaff_r4;
  while (iVar3 != 0) {
    iVar4 = *(int *)(iVar3 + 8);
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined4 *)(iVar3 + 4) = 0;
    iVar3 = iVar4;
  }
  unaff_r4[1] = 0;
  *unaff_r4 = 0;
  *(char *)((int)unaff_r4 + 10) = (char)param_2;
  iVar3 = DAT_08016148;
  switch(param_2) {
  case (int *)0x0:
    iVar3 = DAT_08016144;
    break;
  case (int *)0x1:
    FUN_08020304(unaff_r4,DAT_08016148 + 0xa4);
    iVar3 = iVar3 + 0xb8;
    break;
  case (int *)0x2:
    FUN_08020304(unaff_r4,DAT_08016148 + 0xa4);
    FUN_08020304(unaff_r4,DAT_08016150);
    FUN_08020304(unaff_r4,iVar3 + 0x40);
    iVar3 = iVar3 + 0x138;
    break;
  case (int *)0x3:
    FUN_08020304(unaff_r4,DAT_08016148 + 0x78);
    FUN_08020304(unaff_r4,DAT_08016150);
    FUN_08020304(unaff_r4,iVar3 + 0x138);
    iVar3 = iVar3 + 0x1c4;
    break;
  case (int *)0x4:
    FUN_08020304(unaff_r4,DAT_0801614c);
    FUN_08020304(unaff_r4,DAT_08016150);
    FUN_08020304(unaff_r4,iVar3 + 500);
    iVar3 = iVar3 + 0x50;
    break;
  case (int *)0x5:
    FUN_08020304(unaff_r4,DAT_08016148 + 0xa4);
    FUN_08020304(unaff_r4,iVar3 + 0xd8);
    FUN_08020304(unaff_r4,iVar3 + 0xf8);
    FUN_08020304(unaff_r4,iVar3 + 0x118);
    FUN_08020304(unaff_r4,iVar3 + 0x138);
    iVar3 = iVar3 + 0x20;
    break;
  case (int *)0x6:
    FUN_08020304(unaff_r4,DAT_08016148 + 0x78);
    FUN_08020304(unaff_r4,iVar3 + 0xd8);
    FUN_08020304(unaff_r4,iVar3 + 0xf8);
    FUN_08020304(unaff_r4,iVar3 + 0x118);
    FUN_08020304(unaff_r4,iVar3 + 0x138);
    iVar3 = iVar3 + 0x1c4;
    break;
  case (int *)0x7:
    FUN_08020304(unaff_r4,DAT_0801614c);
    FUN_08020304(unaff_r4,iVar3 + 0xd8);
    FUN_08020304(unaff_r4,iVar3 + 0xf8);
    FUN_08020304(unaff_r4,iVar3 + 0x118);
    FUN_08020304(unaff_r4,iVar3 + 500);
    iVar3 = iVar3 + 0x50;
    break;
  case (int *)0x8:
    FUN_08020304(unaff_r4,DAT_08016148 + 0xa4);
    FUN_08020304(unaff_r4,iVar3 + 0x160);
    FUN_08020304(unaff_r4,iVar3 + 0x180);
    FUN_08020304(unaff_r4,iVar3 + 0x30);
    iVar3 = iVar3 + 0x138;
    break;
  case (int *)0x9:
    FUN_08020304(unaff_r4,DAT_08016148 + 0x78);
    FUN_08020304(unaff_r4,iVar3 + 0x160);
    FUN_08020304(unaff_r4,iVar3 + 0x180);
    FUN_08020304(unaff_r4,iVar3 + 0x138);
    iVar3 = iVar3 + 0x1c4;
    break;
  case (int *)0xa:
    FUN_08020304(unaff_r4,DAT_0801614c);
    FUN_08020304(unaff_r4,iVar3 + 0x160);
    FUN_08020304(unaff_r4,iVar3 + 0x180);
    FUN_08020304(unaff_r4,iVar3 + 500);
    iVar3 = iVar3 + 0x50;
    break;
  case (int *)0xb:
    FUN_08020304(unaff_r4,DAT_08016148 + 0xa4);
    FUN_08020304(unaff_r4,DAT_08016154);
    FUN_08020304(unaff_r4,iVar3 + 0x1a0);
    iVar3 = iVar3 + 0x138;
    break;
  case (int *)0xc:
    FUN_08020304(unaff_r4,DAT_08016148 + 0x78);
    FUN_08020304(unaff_r4,DAT_08016154);
    FUN_08020304(unaff_r4,iVar3 + 0x138);
    iVar3 = iVar3 + 0x1c4;
    break;
  case (int *)0xd:
    FUN_08020304(unaff_r4,DAT_0801614c);
    FUN_08020304(unaff_r4,DAT_08016154);
    FUN_08020304(unaff_r4,iVar3 + 500);
    iVar3 = iVar3 + 0x50;
    break;
  case (int *)0xe:
    FUN_08020304(unaff_r4,DAT_08016148 + 0xa4);
    iVar3 = iVar3 + 0x60;
    break;
  case (int *)0xf:
    FUN_08020304(unaff_r4,DAT_08016148 + 0xa4);
    iVar3 = iVar3 + 0x214;
    goto LAB_0801597c;
  case (int *)0x10:
    FUN_08020304(unaff_r4,DAT_08016148 + 0xa4);
    iVar3 = iVar3 + 0x234;
LAB_0801597c:
    FUN_08020304(unaff_r4,iVar3);
    iVar3 = DAT_08016158;
    break;
  default:
    goto switchD_080156c8_default;
  }
  uVar2 = FUN_08020304(unaff_r4,iVar3,param_4);
  return uVar2;
}



/* ===== FUN_08015998 @ 08015998 ===== */

void FUN_08015998(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = FUN_0801496a();
  iVar1 = DAT_0801615c;
  FUN_08015694(DAT_0801615c,uVar2);
  uVar3 = (*(byte *)(DAT_08016160 + 0x58) & 0xf) >> 2;
  *(byte *)(DAT_08016160 + 0x58) = *(byte *)(DAT_08016160 + 0x58) & 0xf3 | (byte)(uVar3 << 2);
  if (uVar3 == 1) {
    *(undefined1 *)(iVar1 + 9) = 1;
  }
  else if (uVar3 == 2) {
    *(undefined1 *)(iVar1 + 9) = 0;
    return;
  }
  return;
}



/* ===== FUN_080159d8 @ 080159d8 ===== */

void FUN_080159d8(void)

{
  FUN_08015694(DAT_0801615c,0);
  return;
}



/* ===== FUN_080159dc @ 080159dc ===== */

void FUN_080159dc(undefined4 param_1)

{
  FUN_08015694(DAT_0801615c,param_1);
  return;
}



/* ===== FUN_080159f0 @ 080159f0 ===== */

void FUN_080159f0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  if ((param_1 == 4 || param_1 == 7) || (param_1 == 10 || param_1 == 0xd)) {
    *param_2 = 0x13;
    *param_3 = 0x30;
    return;
  }
  if (param_1 == 0xe) {
    *param_2 = 0x80;
    *param_3 = 0x30;
    return;
  }
  *param_3 = 0;
  *param_2 = 0;
  return;
}



/* ===== FUN_08015a28 @ 08015a28 ===== */

undefined4 FUN_08015a28(void)

{
  undefined4 *puVar1;
  undefined4 in_r3;
  int *piVar2;
  
  puVar1 = DAT_0801615c;
  if (*DAT_08016140 == 0) {
    return 0;
  }
  if (*DAT_08015fe0 != *(char *)((int)DAT_0801615c + 9)) {
    FUN_0801b6f4();
    piVar2 = (int *)*puVar1;
    *(undefined1 *)(puVar1 + 2) = 1;
    for (; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[2]) {
      (**(code **)(*piVar2 + 0x14))(piVar2,(int)*(char *)((int)puVar1 + 9));
    }
  }
  piVar2 = (int *)*puVar1;
  if (*(char *)(puVar1 + 2) == '\0') {
    for (; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[2]) {
      (**(code **)(*piVar2 + 0x10))(piVar2);
    }
  }
  else {
    *(undefined1 *)(puVar1 + 2) = 0;
    for (; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[2]) {
      (**(code **)(*piVar2 + 0xc))(piVar2);
    }
  }
  return in_r3;
}



/* ===== FUN_08015a94 @ 08015a94 ===== */

void FUN_08015a94(void)

{
  *(undefined1 *)(DAT_0801615c + 9) = 1;
  return;
}



/* ===== FUN_08015a9e @ 08015a9e ===== */

void FUN_08015a9e(void)

{
  *(undefined1 *)(DAT_0801615c + 9) = 0;
  return;
}



/* ===== FUN_08015aa8 @ 08015aa8 ===== */

void FUN_08015aa8(float param_1)

{
  short *psVar1;
  short sVar2;
  
  psVar1 = DAT_08016164;
  if (param_1 < DAT_08015d24) {
    param_1 = DAT_08015d24;
  }
  else if (DAT_08015d28 <= param_1) {
    param_1 = DAT_08015d2c;
  }
  *(undefined1 *)(DAT_08016164 + 1) = 0xb0;
  if ((int)((uint)*(byte *)(DAT_08015c10 + 0x54) << 0x1e) < 0) {
    *(undefined1 *)((int)psVar1 + 3) = 0x46;
    sVar2 = FUN_08020334(param_1 * DAT_08015d30);
    sVar2 = sVar2 + 0x20;
  }
  else {
    *(undefined1 *)((int)psVar1 + 3) = 0x43;
    sVar2 = FUN_08020334(param_1);
  }
  *psVar1 = sVar2;
  return;
}



/* ===== FUN_08015b04 @ 08015b04 ===== */

uint FUN_08015b04(uint param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = 1;
  }
  while( true ) {
    if ((0 < (int)param_1) || ((int)param_1 < 0)) {
      param_1 = 0;
    }
    if (*(int *)(DAT_08016168 + param_1 * 4) != 0) break;
    param_1 = iVar1 + param_1;
  }
  return param_1 & 0xff;
}



/* ===== FUN_08015b2a @ 08015b2a ===== */

void FUN_08015b2a(undefined1 param_1)

{
  *(undefined1 *)(DAT_08016148 + 0x19) = param_1;
  return;
}



/* ===== FUN_08015b32 @ 08015b32 ===== */

undefined4 FUN_08015b32(void)

{
  return DAT_0801616c;
}



/* ===== FUN_08015b38 @ 08015b38 ===== */

void FUN_08015b38(undefined1 param_1)

{
  *(undefined1 *)(DAT_08016148 + 0x18) = param_1;
  return;
}



/* ===== FUN_08015b44 @ 08015b44 ===== */

void FUN_08015b44(undefined1 param_1)

{
  *(undefined1 *)(DAT_08016148 + 0x1a) = param_1;
  return;
}



/* ===== FUN_08015b4c @ 08015b4c ===== */

void FUN_08015b4c(float param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = DAT_08016148;
  uVar3 = (uint)*(byte *)(DAT_08016148 + 0x1b);
  iVar4 = (int)(param_1 + 0.5);
  switch(param_2) {
  case 0:
  case 3:
    iVar2 = (iVar4 + -5) * 9;
    iVar2 = (int)((ulonglong)((longlong)iVar2 * (longlong)DAT_08016170) >> 0x20) + iVar2;
    uVar3 = (iVar2 >> 6) - (iVar2 >> 0x1f);
    if ((int)uVar3 < 0) {
      uVar3 = 0;
    }
    else if (9 < (int)uVar3) {
      uVar3 = 9;
    }
    break;
  case 1:
    iVar4 = -1;
    uVar3 = 10;
    break;
  case 2:
    iVar4 = -1;
    uVar3 = 0xb;
  }
  *(char *)(DAT_08016148 + 0x1c) = (char)iVar4;
  *(char *)(iVar1 + 0x1b) = (char)uVar3;
  return;
}



/* ===== FUN_08015bae @ 08015bae ===== */

void FUN_08015bae(undefined1 param_1)

{
  *(undefined1 *)(DAT_08016148 + 0x1d) = param_1;
  return;
}



/* ===== FUN_08015bb6 @ 08015bb6 ===== */

undefined8 FUN_08015bb6(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    uVar1 = param_1 >> 1;
    if (uVar1 < 100) break;
    param_1 = (uint)((ulonglong)uVar1 * (ulonglong)DAT_08016174 >> 0x22);
    iVar2 = iVar2 + 1;
  }
  uVar1 = (param_1 & 1) + uVar1;
  if (99 < uVar1) {
    uVar1 = (uint)((ulonglong)uVar1 * (ulonglong)DAT_08016174 >> 0x23);
    iVar2 = iVar2 + 1;
  }
  return CONCAT44(iVar2,uVar1);
}



/* ===== FUN_08015bd6 @ 08015bd6 ===== */

undefined8 FUN_08015bd6(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    uVar1 = param_1 >> 1;
    if (uVar1 < 1000) break;
    param_1 = (uint)((ulonglong)uVar1 * (ulonglong)DAT_08016174 >> 0x22);
    iVar2 = iVar2 + 1;
  }
  uVar1 = (param_1 & 1) + uVar1;
  if (999 < uVar1) {
    uVar1 = (uint)((ulonglong)uVar1 * (ulonglong)DAT_08016174 >> 0x23);
    iVar2 = iVar2 + 1;
  }
  return CONCAT44(iVar2,uVar1);
}



/* ===== FUN_08015c14 @ 08015c14 ===== */

undefined4
FUN_08015c14(float param_1,float param_2,uint *param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  float fVar1;
  undefined1 uVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  if (*(int *)(DAT_08016160 + 0x54) << 0x1d < 0) {
    cVar4 = '\x0f';
  }
  else {
    cVar4 = '\x11';
  }
  if (0.0 <= param_1) {
    if (param_1 < DAT_08015f04) {
      uVar6 = VectorFloatToUnsigned(param_2 * DAT_08015f08 + 0.5,3);
      param_3[3] = uVar6;
      if (cVar4 == '\x0f') {
        uVar5 = VectorFloatToUnsigned(param_1,3);
      }
      else {
        param_1 = param_1 * 6.0;
        uVar5 = VectorFloatToUnsigned(param_1 / 10.0,3);
      }
      uVar6 = FUN_080160bc(uVar5,DAT_08016178,0x10);
      fVar1 = DAT_08015f0c;
      param_3[1] = uVar6;
      uVar5 = VectorFloatToUnsigned(param_1 * fVar1,3);
      uVar7 = FUN_08015bd6(uVar5);
      iVar3 = (int)(uVar7 >> 0x20);
      if (cVar4 == '\x0f') {
        uVar6 = (uint)(byte)(&DAT_080161ac)[iVar3];
        if (0x2ffffffff < uVar7) {
          cVar4 = '\x10';
        }
      }
      else {
        uVar6 = (uint)(byte)(&DAT_080161b4)[iVar3];
        if (uVar7 < 0x500000000) {
          if (0x1ffffffff < uVar7) {
            cVar4 = '\x12';
          }
        }
        else {
          cVar4 = '\x13';
        }
      }
      *(char *)(param_3 + 2) = cVar4;
      *param_3 = uVar6 & 0xf | (int)uVar7 << 4;
    }
    else {
      if (cVar4 == '\x0f') {
        *param_3 = 0x325;
        uVar2 = 0x10;
      }
      else {
        *param_3 = 0x1e4;
        uVar2 = 0x13;
      }
      *(undefined1 *)(param_3 + 2) = uVar2;
      param_3[3] = 0;
      param_3[1] = 0x50;
    }
  }
  else {
    *param_3 = 0;
    *(char *)(param_3 + 2) = cVar4;
    param_3[3] = 0x3de;
  }
  return param_6;
}



/* ===== FUN_08015d0a @ 08015d0a ===== */

undefined4 FUN_08015d0a(float param_1,float param_2)

{
  float fVar1;
  uint *puVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 in_r3;
  char cVar5;
  undefined4 uVar6;
  uint uVar7;
  ulonglong uVar8;
  
  puVar2 = DAT_0801617c;
  if (-1 < (int)((uint)*(byte *)(DAT_08016160 + 0x54) << 0x1b)) {
    return 0;
  }
  if (*(int *)(DAT_08016160 + 0x54) << 0x1d < 0) {
    cVar5 = '\x0f';
  }
  else {
    cVar5 = '\x11';
  }
  if (0.0 <= param_1) {
    if (param_1 < DAT_08015f04) {
      uVar7 = VectorFloatToUnsigned(param_2 * DAT_08015f08 + 0.5,3);
      DAT_0801617c[3] = uVar7;
      if (cVar5 == '\x0f') {
        uVar6 = VectorFloatToUnsigned(param_1,3);
      }
      else {
        param_1 = param_1 * 6.0;
        uVar6 = VectorFloatToUnsigned(param_1 / 10.0,3);
      }
      uVar7 = FUN_080160bc(uVar6,DAT_08016178,0x10);
      fVar1 = DAT_08015f0c;
      puVar2[1] = uVar7;
      uVar6 = VectorFloatToUnsigned(param_1 * fVar1,3);
      uVar8 = FUN_08015bd6(uVar6);
      iVar4 = (int)(uVar8 >> 0x20);
      if (cVar5 == '\x0f') {
        uVar7 = (uint)(byte)(&DAT_080161ac)[iVar4];
        if (0x2ffffffff < uVar8) {
          cVar5 = '\x10';
        }
      }
      else {
        uVar7 = (uint)(byte)(&DAT_080161b4)[iVar4];
        if (uVar8 < 0x500000000) {
          if (0x1ffffffff < uVar8) {
            cVar5 = '\x12';
          }
        }
        else {
          cVar5 = '\x13';
        }
      }
      *(char *)(puVar2 + 2) = cVar5;
      *puVar2 = uVar7 & 0xf | (int)uVar8 << 4;
    }
    else {
      if (cVar5 == '\x0f') {
        *DAT_0801617c = 0x325;
        uVar3 = 0x10;
      }
      else {
        *DAT_0801617c = 0x1e4;
        uVar3 = 0x13;
      }
      *(undefined1 *)(puVar2 + 2) = uVar3;
      puVar2[3] = 0;
      puVar2[1] = 0x50;
    }
  }
  else {
    *DAT_0801617c = 0;
    *(char *)(puVar2 + 2) = cVar5;
    puVar2[3] = 0x3de;
  }
  return in_r3;
}



/* ===== FUN_08015d38 @ 08015d38 ===== */

void FUN_08015d38(float param_1,float param_2,char param_3)

{
  longlong lVar1;
  longlong lVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  undefined1 uVar6;
  char cVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  
  puVar3 = DAT_0801617c;
  iVar5 = DAT_08016160;
  if ((int)((uint)*(byte *)(DAT_08016160 + 0x54) << 0x1b) < 0) {
    return;
  }
  if ((int)((uint)*(byte *)(DAT_08016160 + 0x54) << 0x1f) < 0) {
    cVar7 = '\t';
  }
  else {
    cVar7 = '\f';
  }
  if (param_1 < 0.0) {
    *DAT_0801617c = 0;
    *(char *)(puVar3 + 2) = cVar7;
    puVar3[3] = 0x3de;
    puVar3[1] = 0xffffffff;
    return;
  }
  if (DAT_0801601c <= param_1) {
    if (cVar7 == '\f') {
      *DAT_0801617c = 0x285;
      uVar6 = 0xd;
    }
    else {
      *DAT_0801617c = 0x44;
      uVar6 = 10;
    }
    *(undefined1 *)(puVar3 + 2) = uVar6;
    puVar3[3] = 0;
    puVar3[1] = 0x50;
    return;
  }
  uVar10 = VectorFloatToUnsigned(param_1 * DAT_08016048,3);
  uVar9 = VectorFloatToUnsigned(param_2 * DAT_08015f08 + 0.5,3);
  DAT_0801617c[3] = uVar9;
  uVar9 = FUN_080160bc(uVar10 >> 1,DAT_08016178,0x10);
  puVar3[1] = uVar9;
  if (param_3 == '\0') {
    if ((cVar7 == '\f') || (*(int *)(iVar5 + 0x54) << 0x1c < 0)) {
      uVar10 = VectorFloatToUnsigned(param_1 * DAT_08016074,3);
    }
    uVar11 = FUN_08015bd6(uVar10);
    uVar10 = (uint)(uVar11 >> 0x20);
    uVar9 = (int)uVar11 << 4;
    if (cVar7 != '\f') {
      if (*(int *)(iVar5 + 0x54) << 0x1c < 0) {
        iVar5 = (int)((ulonglong)((longlong)(int)(uVar10 + 1) * (longlong)DAT_08016184) >> 0x20);
        uVar4 = uVar10 + 1 + (iVar5 - (iVar5 >> 0x1f)) * -3 + 1;
        goto joined_r0x08015ece;
      }
      iVar5 = (int)((ulonglong)((longlong)(int)uVar10 * (longlong)DAT_08016184) >> 0x20);
      uVar4 = uVar10 + (iVar5 - (iVar5 >> 0x1f)) * -3 + 1;
      if (uVar11 < 0x300000000) goto LAB_08015ef0;
      goto LAB_08015eee;
    }
    iVar5 = (int)((ulonglong)((longlong)(int)uVar10 * (longlong)DAT_08016184) >> 0x20);
    uVar4 = uVar10 + (iVar5 - (iVar5 >> 0x1f)) * -3 + 1;
  }
  else {
    uVar8 = VectorFloatToUnsigned(param_1 * DAT_08016074,3);
    uVar11 = FUN_08015bb6(uVar8);
    uVar10 = (uint)(uVar11 >> 0x20);
    uVar9 = (uint)uVar11;
    if (cVar7 != '\f') {
      lVar1 = (ulonglong)(uVar10 + 1) * (ulonglong)DAT_08016180;
      uVar4 = (uint)((ulonglong)lVar1 >> 0x21) * 3;
      if (uVar10 + 1 == uVar4) {
        lVar2 = (ulonglong)(uVar9 + 5) * (ulonglong)DAT_08016174;
        uVar4 = (uint)lVar2;
        uVar9 = (uint)((ulonglong)lVar2 >> 0x23);
      }
      uVar4 = FUN_0802036c(uVar10,uVar4,(int)lVar1);
      uVar9 = uVar9 << 4;
joined_r0x08015ece:
      if (uVar11 < 0x500000000) {
        if (uVar10 < 2) {
          cVar7 = '\b';
        }
        goto LAB_08015ef0;
      }
LAB_08015eee:
      cVar7 = '\n';
      goto LAB_08015ef0;
    }
    uVar8 = (undefined4)((ulonglong)uVar10 * (ulonglong)DAT_08016180);
    if (uVar10 == (uint)((ulonglong)uVar10 * (ulonglong)DAT_08016180 >> 0x21) * 3) {
      lVar1 = (ulonglong)(uVar9 + 5) * (ulonglong)DAT_08016174;
      uVar8 = (undefined4)lVar1;
      uVar9 = (uint)((ulonglong)lVar1 >> 0x23);
    }
    uVar4 = FUN_0802036c(uVar10 + 2,uVar8);
    uVar9 = uVar9 << 4;
  }
  if (uVar11 < 0x600000000) {
    if (2 < uVar10) {
      cVar7 = '\r';
    }
  }
  else {
    cVar7 = '\x0e';
  }
LAB_08015ef0:
  *(char *)(puVar3 + 2) = cVar7;
  *puVar3 = uVar9 | uVar4 & 0xf;
  return;
}



/* ===== FUN_08015f14 @ 08015f14 ===== */

void FUN_08015f14(uint param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  uint uVar5;
  char cVar6;
  ulonglong uVar7;
  
  puVar1 = DAT_08016188;
  DAT_08016188[3] = param_2;
  if ((int)((uint)*(byte *)(DAT_08016160 + 0x54) << 0x1f) < 0) {
    cVar6 = '\x01';
  }
  else {
    cVar6 = '\x04';
  }
  if ((int)param_1 < 0) {
    *(char *)(puVar1 + 2) = cVar6;
    *puVar1 = 0;
    puVar1[1] = 0xffffffff;
    return;
  }
  if (DAT_0801618c <= param_1) {
    if (cVar6 == '\x04') {
      *puVar1 = 0xa6;
      uVar4 = 7;
    }
    else {
      *puVar1 = 0xa7;
      uVar4 = 3;
    }
    *(undefined1 *)(puVar1 + 2) = uVar4;
    puVar1[1] = 0x50;
    return;
  }
  iVar2 = (int)((ulonglong)((longlong)(int)param_1 * (longlong)DAT_08016190) >> 0x20);
  uVar3 = FUN_080160bc((iVar2 >> 5) - (iVar2 >> 0x1f),DAT_08016178,0x10,
                       (int)((longlong)(int)param_1 * (longlong)DAT_08016190));
  if (0x50 < (int)uVar3) {
    uVar3 = 0x50;
  }
  puVar1[1] = uVar3;
  uVar7 = FUN_08015bd6(param_1 << 1);
  iVar2 = (int)(uVar7 >> 0x20);
  uVar3 = (uint)uVar7;
  if (cVar6 == '\x04') {
    if (iVar2 == 0) {
      uVar4 = 4;
      if (uVar3 < 10) {
        uVar5 = 1;
      }
      else if (uVar3 < 100) {
        uVar5 = 2;
      }
      else {
        uVar5 = 5;
      }
      goto LAB_08015fc0;
    }
    uVar5 = (uint)(byte)(&DAT_080161bc)[iVar2];
    if (uVar7 < 0x400000000) {
      uVar4 = 5;
    }
    else {
      uVar4 = 6;
    }
  }
  else {
    uVar5 = (uint)(byte)(&DAT_080161c4)[iVar2];
    if (uVar7 < 0x600000000) {
      if (uVar7 < 0x300000000) {
        uVar4 = 1;
      }
      else {
        uVar4 = 2;
      }
    }
    else {
      uVar4 = 3;
    }
  }
  uVar5 = uVar5 & 0xf;
LAB_08015fc0:
  *(undefined1 *)(puVar1 + 2) = uVar4;
  *puVar1 = uVar5 | uVar3 << 4;
  return;
}



/* ===== FUN_08015fca @ 08015fca ===== */

void FUN_08015fca(undefined1 param_1)

{
  *DAT_08016138 = param_1;
  return;
}



/* ===== FUN_08015fd0 @ 08015fd0 ===== */

char * FUN_08015fd0(char param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = DAT_0801613c;
  cVar1 = *DAT_0801613c;
  DAT_0801613c[1] = param_1;
  *pcVar2 = cVar1 + '\x01';
  pcVar2 = pcVar2 + 2;
  cVar1 = *param_2;
  pcVar3 = pcVar2;
  while( true ) {
    param_2 = param_2 + 1;
    *pcVar3 = cVar1;
    if (cVar1 == '\0') break;
    cVar1 = *param_2;
    pcVar3 = pcVar3 + 1;
  }
  return pcVar2;
}



/* ===== FUN_08015fe4 @ 08015fe4 ===== */

void FUN_08015fe4(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_08016150;
  FUN_080203a8(DAT_08016150 + 0x7c,0x1a4);
  iVar1 = DAT_08016148;
  *(undefined1 *)(iVar2 + 0x220) = 1;
  *(undefined4 *)(iVar1 + 0x74) = 0;
  return;
}



/* ===== FUN_08016008 @ 08016008 ===== */

void FUN_08016008(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_080203b0(DAT_08016194,param_1,param_2);
  *(undefined4 *)(DAT_08016148 + 0x74) = param_3;
  return;
}



/* ===== FUN_08016020 @ 08016020 ===== */

void FUN_08016020(void)

{
  undefined1 *puVar1;
  
  puVar1 = DAT_08016198;
  *DAT_08016198 = 1;
  puVar1[4] = 1;
  return;
}



/* ===== FUN_08016030 @ 08016030 ===== */

void FUN_08016030(uint param_1)

{
  if (3 < param_1) {
    param_1 = 3;
  }
  *(uint *)(DAT_08016150 + 0x24c) = (uint)(ushort)(&DAT_080161a4)[param_1];
  return;
}



/* ===== FUN_08016078 @ 08016078 ===== */

void FUN_08016078(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  
  iVar1 = DAT_08016150;
  puVar2 = (undefined4 *)(DAT_08016150 + 0x240);
  *(undefined4 *)(DAT_08016150 + 0x244) = 0;
  *puVar2 = 0;
  *(undefined4 *)(iVar1 + 0x254) = 0;
  puVar3 = (undefined1 *)(iVar1 + 0x25c);
  *(undefined4 *)(iVar1 + 0x248) = 0;
  *(undefined4 *)(iVar1 + 600) = 0xffffffff;
  if (puVar3 < (undefined1 *)(iVar1 + 0x330)) {
    for (; puVar3 < (undefined1 *)(iVar1 + 0x330); puVar3 = puVar3 + 2) {
      *puVar3 = 0;
    }
  }
  *(undefined1 *)(iVar1 + 0x250) = 1;
  return;
}



/* ===== FUN_080160ae @ 080160ae ===== */

int * FUN_080160ae(int param_1,int param_2,undefined4 param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  char cVar10;
  uint in_fpscr;
  float fVar11;
  float fVar12;
  
  piVar1 = DAT_0801619c;
  iVar2 = DAT_0801619c[3];
  uVar3 = DAT_0801619c[5];
  piVar7 = DAT_0801619c + 4;
  DAT_0801619c[3] = param_1 + iVar2;
  uVar6 = param_2 + *piVar7;
  piVar1[4] = uVar6;
  if (uVar6 < uVar3) {
    return param_4;
  }
  fVar11 = (float)VectorUnsignedToFloat(param_1 + iVar2,(byte)(in_fpscr >> 0x16) & 3);
  fVar12 = (float)VectorUnsignedToFloat(uVar6,(byte)(in_fpscr >> 0x16) & 3);
  fVar12 = (fVar11 * DAT_08020664) / fVar12;
  FUN_08015c14(fVar12,DAT_08020668,DAT_0802066c);
  iVar2 = piVar1[2];
  piVar1[3] = 0;
  piVar1[4] = 0;
  if (iVar2 == 0) {
    piVar1[7] = 0;
  }
  fVar11 = (float)FUN_08029d88(fVar12);
  if (iVar2 < 0x6a) {
    piVar1[2] = iVar2 + 1;
  }
  iVar2 = piVar1[1] + 1;
  if (0x69 < iVar2) {
    iVar2 = 0;
  }
  piVar1[1] = iVar2;
  *(float *)(*piVar1 + iVar2 * 4) = fVar11;
  uVar3 = 0;
  if ((float)piVar1[7] == 0.0) {
    if (fVar11 <= 0.0) {
      piVar1[8] = -1;
    }
    else {
      piVar1[8] = iVar2;
      piVar1[7] = (int)(31.0 / fVar11);
      uVar3 = 0x1f;
    }
  }
  else {
    uVar3 = FUN_0802c7aa(fVar11,piVar1);
  }
  cVar10 = (char)uVar3;
  if (cVar10 == '\x1f') {
    piVar1[8] = iVar2;
LAB_0802064e:
    piVar7 = piVar1 + 9;
    piVar9 = (int *)((int)piVar1 + 0x26);
    while (piVar9 < piVar1 + 0x3e) {
      pcVar4 = (char *)((int)piVar7 + 1);
      iVar2 = *piVar9;
      *(char *)piVar7 = (char)iVar2;
      piVar7 = piVar9;
      piVar9 = (int *)((int)piVar9 + 2);
      if ((char)iVar2 != *pcVar4) {
        *(undefined1 *)(piVar1 + 6) = 1;
      }
    }
    *(char *)piVar7 = cVar10;
    if (uVar3 != *(byte *)((int)piVar7 + 1)) {
      *(undefined1 *)(piVar1 + 6) = 1;
    }
    return piVar1;
  }
  if ((char)(cVar10 + -0x1f) < '\x01') {
    if (piVar1[8] != iVar2) goto LAB_0802064e;
    piVar1[7] = 0;
    piVar1[8] = -1;
    iVar8 = piVar1[1];
    iVar2 = FUN_0802c7d2(piVar1);
    fVar11 = DAT_08020668;
    while( true ) {
      fVar12 = *(float *)(*piVar1 + iVar8 * 4);
      if (fVar11 < fVar12) {
        piVar1[8] = iVar8;
        fVar11 = fVar12;
      }
      if (iVar8 == iVar2) break;
      iVar8 = iVar8 + -1;
      if (iVar8 < 0) {
        iVar8 = 0x69;
      }
    }
    if (0.0 < fVar11) {
      piVar1[7] = (int)(31.0 / fVar11);
    }
  }
  else {
    piVar1[8] = iVar2;
    piVar1[7] = (int)(31.0 / fVar11);
  }
  iVar2 = piVar1[1];
  iVar8 = (iVar2 - piVar1[2]) + 1;
  pcVar4 = (char *)((int)piVar1 + 0xf6);
  if (iVar8 < 0) {
    iVar8 = (iVar2 - piVar1[2]) + 0x6b;
  }
  while( true ) {
    fVar11 = *(float *)(*piVar1 + iVar2 * 4);
    if (fVar11 <= 0.0) {
      cVar10 = '\0';
    }
    else {
      cVar10 = (char)(int)((float)piVar1[7] * fVar11);
      if (cVar10 == '\0') {
        cVar10 = '\x01';
      }
    }
    pcVar5 = pcVar4 + -2;
    *pcVar4 = cVar10;
    if (iVar2 == iVar8) break;
    iVar2 = iVar2 + -1;
    pcVar4 = pcVar5;
    if (iVar2 < 0) {
      iVar2 = 0x69;
    }
  }
  *(undefined1 *)(piVar1 + 6) = 1;
  return piVar1;
}



/* ===== FUN_080160bc @ 080160bc ===== */

uint FUN_080160bc(uint param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  iVar1 = -LZCOUNT(param_1);
  uVar2 = iVar1 + 0x1f;
  if (uVar2 < 7) {
    param_1 = param_1 << (7 - uVar2 & 0xff);
  }
  else if ((7 < uVar2) &&
          (param_1 = param_1 >> (iVar1 + 0x17U & 0xff), param_1 = (param_1 & 1) + (param_1 >> 1),
          0xff < param_1)) {
    param_1 = param_1 >> 1;
    uVar2 = iVar1 + 0x20;
  }
  return (((uint)*(byte *)(param_1 + DAT_080161a0 + -0x80) + uVar2 * 0x100) * param_2 >>
         (param_3 + 7U & 0xff)) + 1 >> 1;
}



/* ===== FUN_08016112 @ 08016112 ===== */

void FUN_08016112(void)

{
  if ((*(byte *)(DAT_08016160 + 0x58) & 0xf) >> 2 == 0) {
    *(undefined1 *)(DAT_0801615c + 9) = 1;
  }
  return;
}



/* ===== FUN_08016126 @ 08016126 ===== */

void FUN_08016126(void)

{
  if ((*(byte *)(DAT_08016160 + 0x58) & 0xf) >> 2 == 0) {
    *(undefined1 *)(DAT_0801615c + 9) = 0;
  }
  return;
}



/* ===== FUN_080161d2 @ 080161d2 ===== */

void FUN_080161d2(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0x3c;
  FUN_08016890(param_1,0);
  return;
}



/* ===== FUN_080161dc @ 080161dc ===== */

void FUN_080161dc(undefined4 param_1)

{
  FUN_0802086a(0xb);
  FUN_08020c66(DAT_0801680c);
  FUN_080168b4(param_1);
  return;
}



/* ===== FUN_080161f8 @ 080161f8 ===== */

longlong FUN_080161f8(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10) + -1;
  *(int *)(param_1 + 0x10) = iVar1;
  if (iVar1 < 0) {
    FUN_0802086a(0xb);
    FUN_08020c66(DAT_0801680c);
    FUN_080168b4(param_1);
    FUN_08018132(2);
    return (ulonglong)param_4 << 0x20;
  }
  if (iVar1 * -0x80000000 < 0) {
    FUN_080165b8(DAT_08016808);
  }
  *(int *)(param_1 + 8) = param_2 + 0x8000;
  return CONCAT44(param_4,param_1);
}



/* ===== FUN_080163be @ 080163be ===== */

void FUN_080163be(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_r7;
  
  iVar2 = DAT_08016810;
  puVar1 = DAT_08016808;
  uVar3 = (uint)(*(int *)(DAT_08016810 + 0x54) << 0x17 < 0);
  if (*(int *)(DAT_08016810 + 0x54) << 0x16 < 0) {
    uVar3 = uVar3 | 2;
  }
  if (*(int *)(DAT_08016810 + 0x54) << 0x15 < 0) {
    uVar3 = uVar3 | 4;
  }
  if (*(int *)(DAT_08016810 + 0x54) << 0x14 < 0) {
    uVar3 = uVar3 | 0x200;
  }
  if (*(int *)(DAT_08016810 + 0x54) << 0x13 < 0) {
    uVar3 = uVar3 | 0x400;
  }
  if (*(int *)(DAT_08016810 + 0x54) << 0x12 < 0) {
    uVar3 = uVar3 | 0x800;
  }
  if (*(int *)(DAT_08016810 + 0x54) << 0x11 < 0) {
    uVar3 = uVar3 | 8;
  }
  if (*(int *)(DAT_08016810 + 0x54) << 0x10 < 0) {
    uVar3 = uVar3 | 0x10;
  }
  if (*(int *)(DAT_08016810 + 0x54) << 0xf < 0) {
    uVar3 = uVar3 | 0x20;
  }
  if (*(int *)(DAT_08016810 + 0x54) << 0xe < 0) {
    uVar3 = uVar3 | 0x40;
  }
  if (*(int *)(DAT_08016810 + 0x54) << 0xd < 0) {
    uVar3 = uVar3 | 0x80;
  }
  if (*(int *)(DAT_08016810 + 0x54) << 0xc < 0) {
    uVar3 = uVar3 | 0x100;
  }
  if (*(int *)(DAT_08016810 + 0x58) << 0x10 < 0) {
    uVar3 = uVar3 | 0x1000;
  }
  if (*(int *)(DAT_08016810 + 0x58) << 0xf < 0) {
    uVar3 = uVar3 | 0x2000;
  }
  *DAT_08016808 = uVar3;
  uVar3 = (uint)(*(int *)(iVar2 + 0x54) << 0xb < 0);
  if (*(int *)(iVar2 + 0x54) << 10 < 0) {
    uVar3 = uVar3 | 2;
  }
  if (*(int *)(iVar2 + 0x54) << 9 < 0) {
    uVar3 = uVar3 | 4;
  }
  if (*(int *)(iVar2 + 0x54) << 8 < 0) {
    uVar3 = uVar3 | 0x200;
  }
  if (*(int *)(iVar2 + 0x54) << 7 < 0) {
    uVar3 = uVar3 | 0x400;
  }
  if (*(int *)(iVar2 + 0x54) << 6 < 0) {
    uVar3 = uVar3 | 0x800;
  }
  if (*(int *)(iVar2 + 0x54) << 5 < 0) {
    uVar3 = uVar3 | 8;
  }
  if (*(int *)(iVar2 + 0x54) << 4 < 0) {
    uVar3 = uVar3 | 0x10;
  }
  if (*(int *)(iVar2 + 0x54) << 3 < 0) {
    uVar3 = uVar3 | 0x20;
  }
  if (*(int *)(iVar2 + 0x54) << 2 < 0) {
    uVar3 = uVar3 | 0x40;
  }
  if (*(int *)(iVar2 + 0x54) << 1 < 0) {
    uVar3 = uVar3 | 0x80;
  }
  if (*(int *)(iVar2 + 0x54) < 0) {
    uVar3 = uVar3 | 0x100;
  }
  puVar1[1] = uVar3;
  iVar2 = *(int *)(iVar2 + 0x54);
  puVar1[3] = 0;
  puVar1[2] = (uint)(iVar2 << 0x18 < 0);
  puVar1[4] = 200;
  puVar1[5] = 800;
  FUN_08016700();
  FUN_08021014(DAT_08016814,4,unaff_r7);
  return;
}



/* ===== FUN_080163c4 @ 080163c4 ===== */

undefined4 FUN_080163c4(uint param_1)

{
  int iVar1;
  
  iVar1 = DAT_08016808;
  if (param_1 == 0) {
    FUN_08021134(DAT_08016808,2);
    FUN_0802086a(4);
    FUN_0802086a(5);
    FUN_0802086a(6);
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    FUN_08021014(DAT_08016814,2);
  }
  else if (param_1 == 2) {
    FUN_08016820(DAT_08016808);
  }
  else {
    if (1 < param_1) {
      return 0;
    }
    FUN_08016682(DAT_08016808);
  }
  return 1;
}



/* ===== FUN_0801642e @ 0801642e ===== */

void FUN_0801642e(int param_1)

{
  if ((int)(*(uint *)(param_1 + 4) << 0x1f) < 0) {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffffe;
    FUN_08020c66(DAT_0801680c);
    return;
  }
  return;
}



/* ===== FUN_0801643e @ 0801643e ===== */

/* WARNING: Removing unreachable block (ram,0x0802119a) */
/* WARNING: Removing unreachable block (ram,0x080211a0) */

void FUN_0801643e(int param_1)

{
  undefined4 *puVar1;
  
  if ((int)(*(uint *)(param_1 + 8) << 0x1f) < 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffffe;
    puVar1 = DAT_080211dc;
    *DAT_080211dc = 0;
    puVar1[1] = 0;
    *DAT_080211e0 = 0;
    return;
  }
  return;
}



/* ===== FUN_08016454 @ 08016454 ===== */

undefined4 FUN_08016454(byte *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar3 = param_2 & 0xc;
  if (uVar3 == 4) {
    FUN_0801b57c(0);
  }
  else if (uVar3 == 8) {
    FUN_0801b5d4();
  }
  else if (uVar3 == 0xc) {
    FUN_0801b5ec();
  }
  uVar1 = FUN_0802092a();
  uVar3 = *(uint *)(DAT_0801680c + 0x18) & 0xff;
  if (uVar3 < (uVar1 & 0xff)) {
    uVar3 = uVar1 & 0xff;
  }
  if (uVar3 < 2) {
    if (((param_1[4] & 3) == 3) && ((int)(param_2 << 0x1e) < 0)) {
      FUN_08020be8(DAT_0801680c,2);
    }
    if (((*param_1 & 3) == 3) && ((int)(param_2 << 0x1f) < 0)) {
      FUN_08020730(3,2,0);
    }
  }
  if ((param_2 & 0x300) == 0) {
    return param_4;
  }
  FUN_0802086a(4);
  FUN_0802086a(5);
  FUN_0802086a(6);
  uVar2 = DAT_08016814;
  if ((int)(param_2 << 0x16) < 0) {
    param_1[0x1c] = 0;
    param_1[0x1d] = 0;
    param_1[0x1e] = 0;
    param_1[0x1f] = 0;
    uVar4 = 3;
  }
  else {
    param_1[0x1c] = 0;
    param_1[0x1d] = 0;
    param_1[0x1e] = 0;
    param_1[0x1f] = 0;
    uVar4 = 2;
  }
  uVar2 = FUN_08021014(uVar2,uVar4,param_4);
  return uVar2;
}



/* ===== FUN_08016538 @ 08016538 ===== */

void FUN_08016538(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_0802092a();
  uVar2 = *(uint *)(DAT_0801680c + 0x18) & 0xff;
  if (uVar2 < (uVar1 & 0xff)) {
    uVar2 = uVar1 & 0xff;
  }
  if (uVar2 < 8) {
    if ((int)((uint)(byte)param_1[1] << 0x1f) < 0) {
      FUN_08020c00(DAT_0801680c,8);
    }
    if ((*param_1 & 0x2001) == 0x2001) {
      FUN_08020730(9,8,0);
      return;
    }
  }
  return;
}



/* ===== FUN_0801657c @ 0801657c ===== */

void FUN_0801657c(uint *param_1)

{
  byte bVar1;
  
  param_1[6] = 0;
  param_1[7] = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  FUN_08021014(DAT_08016814,4);
  bVar1 = FUN_0802092a();
  if ((bVar1 < 8) && ((*param_1 & 0x2001) == 0x2001)) {
    FUN_08020730(10,8,0);
    return;
  }
  return;
}



/* ===== FUN_080165b8 @ 080165b8 ===== */

undefined4 FUN_080165b8(byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = FUN_0802092a();
  uVar3 = *(uint *)(DAT_0801680c + 0x18) & 0xff;
  if (uVar3 < (uVar2 & 0xff)) {
    uVar3 = uVar2 & 0xff;
  }
  if (uVar3 < 7) {
    uVar3 = param_1[4] & 1;
    if ((param_1[4] & 1) != 0) {
      uVar3 = FUN_08020c20(DAT_0801680c,7);
    }
    uVar2 = *param_1 & 1;
    if ((*param_1 & 1) != 0) {
      uVar2 = FUN_08020730(0xb,7,0);
    }
    if ((*(int *)(param_1 + 0x18) != 0) && (uVar3 != 0 || uVar2 != 0)) {
      param_1[0x1c] = 0;
      param_1[0x1d] = 0;
      param_1[0x1e] = 0;
      param_1[0x1f] = 0;
      uVar1 = FUN_08021014(DAT_08016814,0,param_4);
      return uVar1;
    }
  }
  return param_4;
}



/* ===== FUN_0801664a @ 0801664a ===== */

void FUN_0801664a(uint *param_1,uint param_2)

{
  byte bVar1;
  
  param_1[3] = param_1[3] & ~(1 << (param_2 & 0xff));
  if (((param_2 == 2) && (bVar1 = FUN_0802092a(), bVar1 < 3)) && ((*param_1 & 0x1001) == 0x1001)) {
    FUN_08020730(8,3,0);
    return;
  }
  return;
}



/* ===== FUN_08016682 @ 08016682 ===== */

void FUN_08016682(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_0802092a();
  uVar2 = *(uint *)(DAT_0801680c + 0x18) & 0xff;
  if (uVar2 < (uVar1 & 0xff)) {
    uVar2 = uVar1 & 0xff;
  }
  if (uVar2 < 9) {
    FUN_08020c20(DAT_0801680c,9);
    FUN_08020730(0xc,9,0);
    if (*(int *)(param_1 + 0x18) != 0) {
      *(undefined4 *)(param_1 + 0x1c) = 0;
      FUN_08021014(DAT_08016814);
      return;
    }
  }
  return;
}



/* ===== FUN_080166ba @ 080166ba ===== */

void FUN_080166ba(byte *param_1)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = FUN_0802092a();
  if (((bVar1 < 8) && ((int)((uint)*param_1 << 0x1f) < 0)) &&
     (iVar2 = FUN_08020730(0xd,8,0), *(int *)(param_1 + 0x18) != 0 && iVar2 != 0)) {
    param_1[0x1c] = 0;
    param_1[0x1d] = 0;
    param_1[0x1e] = 0;
    param_1[0x1f] = 0;
    FUN_08021014(DAT_08016814,0);
    return;
  }
  return;
}



/* ===== FUN_08016700 @ 08016700 ===== */

void FUN_08016700(int param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined1 *)(param_1 + 0x20) = 0;
  return;
}



/* ===== FUN_0801670c @ 0801670c ===== */

longlong FUN_0801670c(uint *param_1,uint param_2,int param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  bool bVar6;
  
  if (param_3 == 0) {
    param_1[6] = param_1[6] & ~(1 << (param_2 & 0xff));
    return (ulonglong)param_4 << 0x20;
  }
  puVar5 = (uint *)(DAT_08016818 + param_2 * 0x18 + (param_3 + -1) * 8);
  uVar4 = *puVar5;
  cVar1 = (char)param_3 + '\x03';
  if ((*param_1 & uVar4) == uVar4) {
    iVar2 = FUN_08020730(cVar1,cVar1,DAT_0801681c);
  }
  else {
    iVar2 = 0;
  }
  uVar4 = puVar5[1];
  if ((param_1[1] & uVar4) == uVar4) {
    iVar3 = FUN_08020c38(DAT_0801680c,cVar1,param_3,DAT_0801681c);
  }
  else {
    iVar3 = 0;
  }
  bVar6 = iVar3 != 0 || iVar2 != 0;
  if (bVar6) {
    param_1[7] = iVar3 + iVar2;
    param_1[6] = 1 << (param_2 & 0xff) | param_1[6];
  }
  return CONCAT44(param_4,(uint)bVar6);
}



/* ===== FUN_08016798 @ 08016798 ===== */

void FUN_08016798(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & ~(1 << (param_2 & 0xff));
  return;
}



/* ===== FUN_080167aa @ 080167aa ===== */

undefined4 FUN_080167aa(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  
  bVar1 = FUN_0802092a();
  uVar3 = *(uint *)(DAT_0801680c + 0x18) & 0xff;
  if (uVar3 < bVar1) {
    uVar3 = (uint)bVar1;
  }
  if (uVar3 < 4) {
    uVar2 = FUN_0801670c(param_1,param_2,param_3);
    return uVar2;
  }
  return 0;
}



/* ===== FUN_080167d8 @ 080167d8 ===== */

undefined4 FUN_080167d8(uint *param_1,int param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  iVar2 = DAT_08016818 + param_2 * 0x18 + param_3 * 8;
  puVar1 = (uint *)(iVar2 - 8);
  uVar3 = *puVar1;
  bVar4 = (*param_1 & uVar3) != uVar3;
  if (bVar4) {
    puVar1 = *(uint **)(iVar2 + -4);
    param_1 = (uint *)(param_1[1] & (uint)puVar1);
  }
  if (bVar4 && param_1 != puVar1) {
    return 1;
  }
  return 0;
}



/* ===== FUN_08016820 @ 08016820 ===== */

undefined4 FUN_08016820(void)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 unaff_r7;
  
  iVar2 = FUN_08020914(0x10);
  if (iVar2 != 0) {
    uVar3 = FUN_0802086a(0x10,unaff_r7);
    return uVar3;
  }
  bVar1 = FUN_0802092a();
  if (bVar1 < 9) {
    uVar3 = FUN_08020730(0x10,9,0,unaff_r7);
    return uVar3;
  }
  return unaff_r7;
}



/* ===== FUN_0801684e @ 0801684e ===== */

void FUN_0801684e(void)

{
  FUN_08020914(10);
  return;
}



/* ===== FUN_08016854 @ 08016854 ===== */

uint FUN_08016854(void)

{
  uint *puVar1;
  ushort uVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = DAT_08016984;
  uVar4 = *DAT_0801697c & 0xffff;
  while (uVar4 != (*DAT_0801697c & 0xffff)) {
    uVar4 = *DAT_0801697c & 0xffff;
  }
  uVar2 = *DAT_08016980 + (short)uVar4;
  if (uVar2 < (ushort)*DAT_08016984) {
    uVar4 = *DAT_08016984;
    puVar1 = DAT_08016984 + 1;
    *DAT_08016984 = uVar4 + 0x10000;
    puVar3[1] = *puVar1 + (uint)(0xfffeffff < uVar4);
  }
  *(ushort *)puVar3 = uVar2;
  return *puVar3;
}



/* ===== FUN_08016890 @ 08016890 ===== */

void FUN_08016890(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = FUN_08016854();
  *(int *)(param_1 + 8) = param_2 + iVar2;
  uVar1 = DAT_08016988;
  FUN_080211e8(DAT_08016988,param_1);
  FUN_0802120c(uVar1,param_1,param_4);
  return;
}



/* ===== FUN_080168b4 @ 080168b4 ===== */

void FUN_080168b4(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *DAT_08016988;
  if (iVar1 != 0) {
    if (iVar1 == param_1) {
      *DAT_08016988 = *(int *)(param_1 + 4);
    }
    else {
      do {
        iVar2 = iVar1;
        iVar1 = *(int *)(iVar2 + 4);
        if (iVar1 == 0) goto LAB_080168d2;
      } while (iVar1 != param_1);
      *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar1 + 4);
    }
  }
LAB_080168d2:
  *(undefined1 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}



/* ===== FUN_080168da @ 080168da ===== */

longlong FUN_080168da(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0x14);
  iVar2 = *(int *)(param_1 + 0x10) + -1;
  *(int *)(param_1 + 0x10) = iVar2;
  *(undefined4 **)(param_1 + 0x14) = puVar1 + 2;
  *(int *)(param_1 + 8) = puVar1[1] + param_2;
  if ((code *)*puVar1 != (code *)0x0) {
    (*(code *)*puVar1)();
  }
  if (iVar2 < 1) {
    return (ulonglong)param_4 << 0x20;
  }
  return CONCAT44(param_4,param_1);
}



/* ===== FUN_08016904 @ 08016904 ===== */

void FUN_08016904(int param_1,undefined4 *param_2,int param_3)

{
  if (param_3 != 0) {
    if ((code *)*param_2 != (code *)0x0) {
      (*(code *)*param_2)();
    }
    if (param_3 + -1 != 0) {
      FUN_08016890(param_1,param_2[1]);
      *(int *)(param_1 + 0x10) = param_3 + -1;
      *(undefined4 **)(param_1 + 0x14) = param_2 + 2;
    }
  }
  return;
}



/* ===== FUN_0801692a @ 0801692a ===== */

void FUN_0801692a(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  if (param_3 == 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x14) = param_2;
  *(int *)(param_1 + 0x10) = param_3;
  FUN_08016890(param_1,param_4);
  return;
}



/* ===== FUN_08016936 @ 08016936 ===== */

undefined4 FUN_08016936(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 in_r3;
  
  piVar1 = DAT_08016988;
  while( true ) {
    iVar2 = FUN_08016854();
    piVar3 = (int *)*piVar1;
    if ((piVar3 == (int *)0x0) || (iVar2 - piVar3[2] < 0)) break;
    *piVar1 = piVar3[1];
    piVar3[1] = 0;
    *(undefined1 *)(piVar3 + 3) = 0;
    iVar2 = (**(code **)(*piVar3 + 8))();
    if (iVar2 != 0) {
      FUN_0802120c(piVar1,iVar2);
    }
  }
  return in_r3;
}



/* ===== FUN_08016968 @ 08016968 ===== */

bool FUN_08016968(void)

{
  return *DAT_08016988 != 0;
}



/* ===== FUN_08016972 @ 08016972 ===== */

undefined4 FUN_08016972(void)

{
  return *(undefined4 *)(*DAT_08016988 + 8);
}



/* ===== FUN_0801698c @ 0801698c ===== */

void FUN_0801698c(void)

{
  int iVar1;
  
  iVar1 = DAT_08016a04;
  *(undefined4 *)(DAT_08016a04 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  return;
}



/* ===== FUN_08016996 @ 08016996 ===== */

undefined4 FUN_08016996(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_08016a04;
  iVar2 = *(int *)(DAT_08016a04 + 0x20) + 1;
  if (iVar2 == 0x10) {
    iVar2 = 0;
  }
  if (*(int *)(DAT_08016a04 + 0x24) == iVar2) {
    return 1;
  }
  *(undefined2 *)(DAT_08016a04 + iVar2 * 2) = param_1;
  *(int *)(iVar1 + 0x20) = iVar2;
  return 0;
}



/* ===== FUN_080169b6 @ 080169b6 ===== */

undefined2 FUN_080169b6(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_08016a04;
  if (*(int *)(DAT_08016a04 + 0x24) == *(int *)(DAT_08016a04 + 0x20)) {
    return 0;
  }
  iVar2 = *(int *)(DAT_08016a04 + 0x24) + 1;
  if (iVar2 == 0x10) {
    iVar2 = 0;
  }
  *(int *)(DAT_08016a04 + 0x24) = iVar2;
  return *(undefined2 *)(iVar1 + iVar2 * 2);
}



/* ===== FUN_080169d4 @ 080169d4 ===== */

undefined4 FUN_080169d4(void)

{
  if (*(int *)(DAT_08016a04 + 0x24) == *(int *)(DAT_08016a04 + 0x20)) {
    return 0;
  }
  return 1;
}



/* ===== FUN_080169e6 @ 080169e6 ===== */

undefined4 FUN_080169e6(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_r7;
  
  iVar1 = FUN_080169b6();
  if (iVar1 == 0) {
    return unaff_r7;
  }
  uVar2 = FUN_08014898();
  uVar2 = FUN_08016454(DAT_08016a08,uVar2,unaff_r7);
  return uVar2;
}



/* ===== FUN_08016a0c @ 08016a0c ===== */

undefined4 FUN_08016a0c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if ('\x01' < *(char *)(param_1 + 0x14)) {
    cVar1 = *(char *)(param_1 + 0x14) + -1;
    *(char *)(param_1 + 0x14) = cVar1;
    iVar2 = DAT_08016a64;
    iVar4 = (int)cVar1;
    piVar3 = *(int **)(DAT_08016a64 + iVar4 * 4);
    (**(code **)(*piVar3 + 0xc))(piVar3,1);
    FUN_0802124c(piVar3);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 4))(piVar3);
    }
    *(undefined4 *)(iVar2 + iVar4 * 4) = 0;
    piVar3 = *(int **)(iVar2 + iVar4 * 4 + -4);
    FUN_0802128c(piVar3);
    (**(code **)(*piVar3 + 8))(piVar3,1);
    *(undefined1 *)(param_1 + 0x17) = *(undefined1 *)(param_1 + 0x16);
  }
  return param_4;
}



/* ===== FUN_08016a90 @ 08016a90 ===== */

void FUN_08016a90(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  
  piVar1 = DAT_08016b58;
  if (param_1 != 0) {
    puVar2 = (undefined4 *)*DAT_08016b58;
    if ((undefined4 *)*DAT_08016b58 == (undefined4 *)0x0) {
      *DAT_08016b58 = (int)(DAT_08016b58 + 2);
LAB_08016aba:
      piVar1[2] = 0;
      piVar1[3] = param_1;
    }
    else {
      while ((puVar2[1] & 0xff00) != 0) {
        if ((undefined4 *)*puVar2 == (undefined4 *)0x0) {
          *puVar2 = DAT_08016b58 + 2;
          goto LAB_08016aba;
        }
        puVar2 = (undefined4 *)*puVar2;
      }
    }
  }
  return;
}



/* ===== FUN_08016ac0 @ 08016ac0 ===== */

void FUN_08016ac0(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = DAT_08016b58;
  puVar2 = DAT_08016b58 + 4;
  puVar3 = (undefined4 *)*DAT_08016b58;
  if ((undefined4 *)*DAT_08016b58 == (undefined4 *)0x0) {
    *DAT_08016b58 = puVar2;
  }
  else {
    while( true ) {
      if ((puVar3[1] & 0xff00) == (param_1 & 0xff00 | 0x100)) {
        return;
      }
      if ((undefined4 *)*puVar3 == (undefined4 *)0x0) break;
      puVar3 = (undefined4 *)*puVar3;
    }
    *puVar3 = puVar2;
  }
  *puVar2 = 0;
  puVar1[5] = param_1 | 0x100;
  return;
}



/* ===== FUN_08016ace @ 08016ace ===== */

void FUN_08016ace(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = DAT_08016b58;
  puVar2 = DAT_08016b58 + 6;
  puVar3 = (undefined4 *)*DAT_08016b58;
  if ((undefined4 *)*DAT_08016b58 == (undefined4 *)0x0) {
    *DAT_08016b58 = puVar2;
  }
  else {
    while( true ) {
      if ((puVar3[1] & 0xff00) == (param_1 & 0xff00 | 0x200)) {
        return;
      }
      if ((undefined4 *)*puVar3 == (undefined4 *)0x0) break;
      puVar3 = (undefined4 *)*puVar3;
    }
    *puVar3 = puVar2;
  }
  *puVar2 = 0;
  puVar1[7] = param_1 | 0x200;
  return;
}



/* ===== FUN_08016adc @ 08016adc ===== */

void FUN_08016adc(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = DAT_08016b58;
  puVar2 = DAT_08016b58 + 10;
  puVar3 = (undefined4 *)*DAT_08016b58;
  if ((undefined4 *)*DAT_08016b58 == (undefined4 *)0x0) {
    *DAT_08016b58 = puVar2;
  }
  else {
    while( true ) {
      if ((puVar3[1] & 0xff00) == (param_1 & 0xff00 | 0x400)) {
        return;
      }
      if ((undefined4 *)*puVar3 == (undefined4 *)0x0) break;
      puVar3 = (undefined4 *)*puVar3;
    }
    *puVar3 = puVar2;
  }
  *puVar2 = 0;
  puVar1[0xb] = param_1 | 0x400;
  return;
}



/* ===== FUN_08016aea @ 08016aea ===== */

void FUN_08016aea(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = DAT_08016b58;
  puVar2 = DAT_08016b58 + 0xc;
  puVar3 = (undefined4 *)*DAT_08016b58;
  if ((undefined4 *)*DAT_08016b58 == (undefined4 *)0x0) {
    *DAT_08016b58 = puVar2;
  }
  else {
    while( true ) {
      if ((puVar3[1] & 0xff00) == (param_1 & 0xff00 | 0x500)) {
        return;
      }
      if ((undefined4 *)*puVar3 == (undefined4 *)0x0) break;
      puVar3 = (undefined4 *)*puVar3;
    }
    *puVar3 = puVar2;
  }
  *puVar2 = 0;
  puVar1[0xd] = param_1 | 0x500;
  return;
}



/* ===== FUN_08016af8 @ 08016af8 ===== */

void FUN_08016af8(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = DAT_08016b58;
  puVar2 = DAT_08016b58 + 0xe;
  puVar3 = (undefined4 *)*DAT_08016b58;
  if ((undefined4 *)*DAT_08016b58 == (undefined4 *)0x0) {
    *DAT_08016b58 = puVar2;
  }
  else {
    while( true ) {
      if ((puVar3[1] & 0xff00) == (param_1 & 0xff00 | 0xf00)) {
        return;
      }
      if ((undefined4 *)*puVar3 == (undefined4 *)0x0) break;
      puVar3 = (undefined4 *)*puVar3;
    }
    *puVar3 = puVar2;
  }
  *puVar2 = 0;
  puVar1[0xf] = param_1 | 0xf00;
  return;
}



/* ===== FUN_08016b06 @ 08016b06 ===== */

void FUN_08016b06(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = DAT_08016b58;
  puVar2 = DAT_08016b58 + 0x10;
  puVar3 = (undefined4 *)*DAT_08016b58;
  if ((undefined4 *)*DAT_08016b58 == (undefined4 *)0x0) {
    *DAT_08016b58 = puVar2;
  }
  else {
    while( true ) {
      if ((puVar3[1] & 0xff00) == (param_1 & 0xff00 | 0x600)) {
        return;
      }
      if ((undefined4 *)*puVar3 == (undefined4 *)0x0) break;
      puVar3 = (undefined4 *)*puVar3;
    }
    *puVar3 = puVar2;
  }
  *puVar2 = 0;
  puVar1[0x11] = param_1 | 0x600;
  return;
}



/* ===== FUN_08016b14 @ 08016b14 ===== */

void FUN_08016b14(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = DAT_08016b58;
  puVar2 = DAT_08016b58 + 0x12;
  puVar3 = (undefined4 *)*DAT_08016b58;
  if ((undefined4 *)*DAT_08016b58 == (undefined4 *)0x0) {
    *DAT_08016b58 = puVar2;
  }
  else {
    while( true ) {
      if ((puVar3[1] & 0xff00) == (param_1 & 0xff00 | 0x700)) {
        return;
      }
      if ((undefined4 *)*puVar3 == (undefined4 *)0x0) break;
      puVar3 = (undefined4 *)*puVar3;
    }
    *puVar3 = puVar2;
  }
  *puVar2 = 0;
  puVar1[0x13] = param_1 | 0x700;
  return;
}



/* ===== FUN_08016b2a @ 08016b2a ===== */

void FUN_08016b2a(void)

{
  *(undefined1 *)(DAT_08016b58 + 4) = 0;
  return;
}



/* ===== FUN_08016b32 @ 08016b32 ===== */

undefined4 FUN_08016b32(void)

{
  undefined4 *puVar1;
  undefined4 in_r3;
  undefined4 *unaff_r4;
  
  puVar1 = DAT_08016b58;
  if (*(char *)(DAT_08016b58 + 1) != '\0') {
    unaff_r4 = (undefined4 *)*DAT_08016b58;
  }
  if (*(char *)(DAT_08016b58 + 1) != '\0' && unaff_r4 != (undefined4 *)0x0) {
    FUN_08014986(unaff_r4[1]);
    *(undefined1 *)(puVar1 + 1) = 0;
    *puVar1 = *unaff_r4;
    *unaff_r4 = 0;
  }
  return in_r3;
}



/* ===== FUN_08016b5c @ 08016b5c ===== */

undefined4 FUN_08016b5c(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar1 = DAT_08016bd0;
  if (param_2 + 1 < (int)*(char *)(param_1 + 0x14)) {
    puVar4 = (undefined4 *)(DAT_08016bd0 + *(char *)(param_1 + 0x14) * 4 + -4);
    puVar5 = (undefined4 *)(DAT_08016bd0 + param_2 * 4);
    if (puVar5 < puVar4) {
      for (; puVar5 < puVar4; puVar4 = puVar4 + -1) {
        piVar2 = (int *)*puVar4;
        (**(code **)(*piVar2 + 0xc))(piVar2,1);
        FUN_0802124c(piVar2);
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 4))(piVar2);
        }
        *puVar4 = 0;
      }
    }
    *(char *)(param_1 + 0x14) = (char)param_2 + '\x01';
    iVar3 = *(int *)(iVar1 + param_2 * 4);
    FUN_080159dc(*(undefined1 *)(iVar3 + 4));
    *(undefined1 *)(iVar3 + 0x14) = 1;
    piVar2 = *(int **)(iVar1 + param_2 * 4);
    (**(code **)(*piVar2 + 8))(piVar2,1);
    *(undefined1 *)(param_1 + 0x17) = *(undefined1 *)(param_1 + 0x16);
  }
  return param_4;
}



/* ===== FUN_08016bd4 @ 08016bd4 ===== */

int FUN_08016bd4(undefined1 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 *local_24;
  int local_20;
  int local_1c;
  undefined4 *local_18;
  undefined4 uStack_14;
  undefined4 uStack_4;
  
  local_18 = &uStack_4;
  local_1c = 0;
  if (param_2 == 0) {
    local_24 = (undefined1 *)0x0;
    local_20 = 0;
  }
  else {
    local_20 = param_2 + -1;
    local_24 = param_1;
  }
  uStack_14 = param_4;
  uStack_4 = param_4;
  iVar1 = FUN_0802129c((int)&DAT_08016c14 + DAT_08016c14,&local_24,param_3,&local_18,0);
  if (local_24 != (undefined1 *)0x0) {
    *local_24 = 0;
  }
  if (-1 < iVar1) {
    iVar1 = local_1c;
  }
  return iVar1;
}



/* ===== FUN_08016c18 @ 08016c18 ===== */

undefined4 FUN_08016c18(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_10;
  
  local_10._2_2_ = (undefined2)((uint)param_4 >> 0x10);
  switch(param_3) {
  case 1:
    local_10 = CONCAT22(local_10._2_2_,0x7f4a);
    puVar1 = (undefined4 *)FUN_08018234(0x1c);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      FUN_0801d428(puVar1,param_1,&local_10,100);
      *puVar1 = DAT_08016e0c;
    }
    FUN_08018258(param_1,puVar1);
    local_10 = CONCAT22((short)((uint)local_10 >> 0x10),0x3500);
    puVar1 = (undefined4 *)FUN_08018234(0x1c);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      FUN_0801d428(puVar1,param_1,&local_10,0x65);
      *puVar1 = DAT_08016e10;
    }
    break;
  case 2:
    local_10 = CONCAT22(local_10._2_2_,0x7f4a);
    puVar1 = (undefined4 *)FUN_08018234(0x1c);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      FUN_0801d428(puVar1,param_1,&local_10,0x67);
      *puVar1 = DAT_08016e14;
    }
    FUN_08018258(param_1,puVar1);
    local_10 = CONCAT22((short)((uint)local_10 >> 0x10),0x3500);
    puVar1 = (undefined4 *)FUN_08018234(0x1c);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      FUN_0801d428(puVar1,param_1,&local_10,0x68);
      *puVar1 = DAT_08016e18;
    }
    break;
  case 3:
    local_10 = CONCAT22(local_10._2_2_,0x7f4a);
    puVar1 = (undefined4 *)FUN_08018234(0x1c);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      FUN_0801d428(puVar1,param_1,&local_10,0x68);
      *puVar1 = DAT_08016e18;
    }
    FUN_08018258(param_1,puVar1);
    local_10 = CONCAT22((short)((uint)local_10 >> 0x10),0x3500);
    puVar1 = (undefined4 *)FUN_08018234(0x1c);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      FUN_0801d428(puVar1,param_1,&local_10,0x67);
      *puVar1 = DAT_08016e14;
    }
    break;
  case 4:
    local_10 = CONCAT22(local_10._2_2_,0x7f4a);
    puVar1 = (undefined4 *)FUN_08018234(0x1c);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      FUN_0801d428(puVar1,param_1,&local_10,0x69);
      *puVar1 = DAT_08016e1c;
    }
    FUN_08018258(param_1,puVar1);
    local_10 = CONCAT22((short)((uint)local_10 >> 0x10),0x3500);
    puVar1 = (undefined4 *)FUN_08018234(0x1c);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      FUN_0801d428(puVar1,param_1,&local_10,0x6a);
      *puVar1 = DAT_08016e20;
    }
    break;
  case 5:
    local_10 = CONCAT22(local_10._2_2_,0x5b25);
    puVar1 = (undefined4 *)FUN_08018234(0x1c);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      FUN_0801d428(puVar1,param_1,&local_10,0x6a);
      *puVar1 = DAT_08016e20;
    }
    break;
  default:
    local_10 = CONCAT22(local_10._2_2_,0x5b25);
    puVar1 = (undefined4 *)FUN_08018234(0x1c);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      FUN_0801d428(puVar1,param_1,&local_10,0x66);
      *puVar1 = DAT_08016e24;
    }
  }
  FUN_08018258(param_1,puVar1);
  iVar2 = DAT_08016e28;
  if (*(int *)(DAT_08016e28 + 0x28) != 0) {
    *(undefined1 *)(param_1 + 0x16) = *(undefined1 *)(param_1 + 0x15);
    *(undefined1 *)(param_1 + 0x17) = 0;
    *(undefined1 *)(param_1 + 0x18) = 0;
    iVar2 = *(int *)(iVar2 + 0x28);
    *(undefined1 *)(iVar2 + 9) = 1;
    *(undefined1 *)(iVar2 + 10) = 1;
  }
  return local_10;
}



/* ===== FUN_08016e74 @ 08016e74 ===== */

void FUN_08016e74(int param_1,int param_2,uint param_3)

{
  *(uint *)(param_1 + (uint)(byte)(&DAT_08016e8c)[param_2] + 4) =
       param_3 | *(uint *)(param_1 + (uint)(byte)(&DAT_08016e8c)[param_2] + 4) & 0xffff0000;
  return;
}



/* ===== FUN_08016e94 @ 08016e94 ===== */

void FUN_08016e94(uint *param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  
  bVar2 = (byte)param_2;
  bVar3 = (byte)((uint)param_2 >> 8);
  bVar4 = (byte)((uint)param_2 >> 0x10);
  bVar1 = (byte)((uint)param_2 >> 0x18);
  uVar5 = (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1 |
                          bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                       bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18 |
          (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1 |
                          bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                       bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
          (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1 |
                          bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                       bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
          (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1 |
                          bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                       bVar1 >> 6 & 1) << 1 | bVar1 >> 7);
  *param_1 = param_3 << (LZCOUNT(uVar5) << 1) | *param_1 & ~(3 << (LZCOUNT(uVar5) << 1));
  return;
}



/* ===== FUN_08016eb8 @ 08016eb8 ===== */

void FUN_08016eb8(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  
  bVar2 = (byte)param_2;
  bVar3 = (byte)((uint)param_2 >> 8);
  bVar4 = (byte)((uint)param_2 >> 0x10);
  bVar1 = (byte)((uint)param_2 >> 0x18);
  uVar5 = (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1 |
                          bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                       bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18 |
          (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1 |
                          bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                       bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
          (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1 |
                          bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                       bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
          (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1 |
                          bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                       bVar1 >> 6 & 1) << 1 | bVar1 >> 7);
  *(uint *)(param_1 + 0xc) =
       param_3 << (LZCOUNT(uVar5) << 1) | *(uint *)(param_1 + 0xc) & ~(3 << (LZCOUNT(uVar5) << 1));
  return;
}



/* ===== FUN_08016edc @ 08016edc ===== */

uint FUN_08016edc(void)

{
  uint uVar1;
  
  uVar1 = *DAT_080179a4 & 0xffff;
  while (uVar1 != (*DAT_080179a4 & 0xffff)) {
    uVar1 = *DAT_080179a4 & 0xffff;
  }
  return uVar1 + *DAT_08017bf8 & 0xffff;
}



/* ===== FUN_08016efc @ 08016efc ===== */

undefined8 FUN_08016efc(void)

{
  uint *puVar1;
  uint *puVar2;
  ushort uVar3;
  uint uVar4;
  
  uVar3 = FUN_08016edc();
  puVar2 = DAT_08017bfc;
  if (uVar3 < (ushort)*DAT_08017bfc) {
    uVar4 = *DAT_08017bfc;
    puVar1 = DAT_08017bfc + 1;
    *DAT_08017bfc = uVar4 + 0x10000;
    puVar2[1] = *puVar1 + (uint)(0xfffeffff < uVar4);
  }
  *(ushort *)puVar2 = uVar3;
  return *(undefined8 *)puVar2;
}



/* ===== FUN_08016f26 @ 08016f26 ===== */

undefined4 FUN_08016f26(int param_1,int param_2)

{
  if (param_2 < 5) {
    if (param_2 == 2) {
      return 0x6000;
    }
    return 0;
  }
  if (*(char *)(param_1 + 0xe) == '\x02') {
    return 0x4000;
  }
  return 0x2000;
}



/* ===== FUN_08016fbc @ 08016fbc ===== */

void FUN_08016fbc(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_0801f62c();
  iVar1 = DAT_08017b20;
  if (iVar2 < 1) {
    FUN_08016e94(DAT_08017b20,0x800,2);
    FUN_08016eb8(iVar1,0x800,0);
    return;
  }
  *(undefined4 *)(DAT_08017b20 + 0x18) = 0x800;
  return;
}



/* ===== FUN_08016fec @ 08016fec ===== */

void FUN_08016fec(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_08017b20;
  *(undefined4 *)(DAT_08017b20 + 0x28) = 0x800;
  iVar1 = FUN_0801f62c();
  if (iVar1 < 1) {
    FUN_08016e94(iVar2,0x800,1);
    FUN_08016eb8(iVar2,0x800,2);
    FUN_08016e94(iVar2,0x800,3);
    iVar2 = 0x50;
    do {
      if (-1 < *DAT_08017d18 << 0x1c) {
        return;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}



/* ===== FUN_08017038 @ 08017038 ===== */

void FUN_08017038(undefined4 param_1)

{
  ushort uVar1;
  uint uVar2;
  ushort *puVar3;
  uint in_fpscr;
  float fVar4;
  int iVar5;
  
  puVar3 = DAT_08017b78;
  fVar4 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  uVar1 = *DAT_08017b78;
  iVar5 = (int)(DAT_080172d8 - fVar4 * DAT_080172d4);
  uVar2 = UnsignedSaturate(iVar5,0xc);
  UnsignedDoesSaturate(iVar5,0xc);
  if (uVar1 == uVar2) {
    return;
  }
  if (uVar2 == 0xfff) {
    DAT_08017b7c[4] = 0x400;
  }
  if (uVar1 == 0xfff) {
    *DAT_08017b7c = 0x400;
  }
  *puVar3 = (ushort)uVar2;
  if (*DAT_08017c08 << 2 < 0) {
    *DAT_08017de8 = uVar2 | *DAT_08017de8 & 0xfffff000;
  }
  return;
}



/* ===== FUN_080170a4 @ 080170a4 ===== */

void FUN_080170a4(void)

{
  float fVar1;
  int iVar2;
  
  iVar2 = DAT_08017908;
  if (*(int *)(DAT_08017908 + 0x18) == 0) {
    fVar1 = (float)FUN_0801d030(DAT_08017908 + 0xc,2);
    iVar2 = (int)(fVar1 + 0.5);
  }
  else {
    FUN_0801d030(DAT_08017908,2);
    fVar1 = (float)FUN_0801d030(iVar2 + 0xc,2);
    iVar2 = *(int *)(iVar2 + 0x18) - (int)(fVar1 + 0.5);
  }
  FUN_08017038(iVar2);
  return;
}



/* ===== FUN_080170fc @ 080170fc ===== */

void FUN_080170fc(float param_1)

{
  uint uVar1;
  float fVar2;
  
  fVar2 = 20.0 - ABS(param_1 + -20.0);
  if (0.0 <= fVar2) {
    if ((DAT_080173ac <= fVar2) &&
       (uVar1 = *(uint *)(DAT_08017c0c + 8) | 0x40000, *(uint *)(DAT_08017c0c + 8) = uVar1,
       (int)(uVar1 << 0xc) < 0)) {
      DAT_08017e7c[4] = 0x2000;
    }
  }
  else {
    uVar1 = *(uint *)(DAT_08017c0c + 8) & 0xfffbffff;
    *(uint *)(DAT_08017c0c + 8) = uVar1;
    if ((int)(uVar1 << 0xc) < 0) {
      *DAT_08017e7c = 0x2000;
      return;
    }
  }
  return;
}



/* ===== FUN_08017164 @ 08017164 ===== */

int FUN_08017164(void)

{
  uint in_fpscr;
  float fVar1;
  
  fVar1 = (float)VectorUnsignedToFloat((uint)*DAT_08017b78,(byte)(in_fpscr >> 0x16) & 3);
  return (int)(DAT_080174c4 - fVar1 * DAT_080173b0);
}



/* ===== FUN_080171f8 @ 080171f8 ===== */

uint FUN_080171f8(void)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar4;
  
  FUN_08022640();
  puVar1 = DAT_08017d1c;
  DAT_08017d1c[3] = DAT_08017d1c[3] | 0x40000000;
  puVar2 = DAT_08017d20;
  DAT_08017d20[4] = DAT_08017d20[4] & 0xfffffffe;
  puVar1[3] = puVar1[3] & 0xbfffffff;
  puVar1[3] = puVar1[3] | 0x40000000;
  uVar4 = puVar1[3];
  *puVar2 = *puVar2 & 0xfffffffe;
  puVar1[3] = puVar1[3] & 0xbfffffff;
  puVar3 = DAT_08017dec;
  *puVar1 = *puVar1 & 0xffffdfff;
  *puVar3 = 0x200;
  FUN_08018b8a();
  UNRECOVERED_JUMPTABLE = *(code **)(DAT_0801790c + 0x74);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    return uVar4 & 0x40000000;
  }
                    /* WARNING: Could not recover jumptable at 0x08017270. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(2,UNRECOVERED_JUMPTABLE,uVar4 & 0x40000000);
  return uVar4;
}



/* ===== FUN_08017274 @ 08017274 ===== */

void FUN_08017274(void)

{
  FUN_080226e8(DAT_0801790c);
  FUN_0801b6e8();
  FUN_08016890(DAT_0801d7f0,0);
  return;
}



/* ===== FUN_0801728a @ 0801728a ===== */

void FUN_0801728a(void)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  
  FUN_0801d5b6();
  FUN_080159d8();
  FUN_0801b76a();
  uVar3 = DAT_08022780;
  puVar2 = DAT_0802277c;
  uVar1 = DAT_0801790c;
  DAT_0802277c[1] = DAT_0802277c[1] & DAT_08022780 | 0x10;
  *puVar2 = *puVar2 & 0xfffffffb;
  puVar2[1] = uVar3 & puVar2[1] | 2;
  puVar2 = DAT_08022784;
  *DAT_08022784 = *DAT_08022784 & 0xfffffffe;
  *puVar2 = *puVar2 & 0xfffffffd;
  FUN_080168b4(uVar1);
  *DAT_08022788 = 0;
  return;
}



/* ===== FUN_080172a4 @ 080172a4 ===== */

undefined4 FUN_080172a4(void)

{
  undefined4 unaff_r7;
  
  FUN_0801b55a(1);
  FUN_0801b57c(0);
  FUN_080184d4();
  *DAT_08017b7c = 0x100;
  return unaff_r7;
}



/* ===== FUN_080172bc @ 080172bc ===== */

undefined4 FUN_080172bc(void)

{
  undefined4 unaff_r7;
  
  FUN_0801b55a(0);
  FUN_080184e0();
  *DAT_08017dec = 0x100;
  return unaff_r7;
}



/* ===== FUN_080172dc @ 080172dc ===== */

void FUN_080172dc(void)

{
  uint *puVar1;
  
  *DAT_08017dec = 0x800;
  *DAT_08017c08 = *DAT_08017c08 | 0x20000000;
  puVar1 = DAT_08017eac;
  DAT_08017eac[0xf] = DAT_08017eac[0xf] & 0xfff8ffff | 0x20000;
  *puVar1 = *puVar1 | 0x10000;
  puVar1[0xf] = puVar1[0xf] & 0xfffffff8 | 1;
  *puVar1 = *puVar1 | 1;
  return;
}



/* ===== FUN_0801732e @ 0801732e ===== */

void FUN_0801732e(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  
  puVar2 = DAT_08017eac;
  *DAT_08017eac = *DAT_08017eac & 0xfffeffff;
  puVar2[0xf] = puVar2[0xf] & 0xfff8ffff | 0x30000;
  *puVar2 = *puVar2 & 0xfffffffe;
  puVar2[0xf] = puVar2[0xf] & 0xfffffff8 | 3;
  puVar1 = DAT_08017b7c;
  *DAT_08017c08 = *DAT_08017c08 & 0xdfffffff;
  *puVar1 = 0x800;
  return;
}



/* ===== FUN_08017372 @ 08017372 ===== */

void FUN_08017372(void)

{
  *DAT_08017de8 = (uint)*DAT_08017b78 | *DAT_08017de8 & 0xfffff000;
  *DAT_08017b7c = 0x400;
  return;
}



/* ===== FUN_08017392 @ 08017392 ===== */

void FUN_08017392(void)

{
  *DAT_08017dec = 0x400;
  *DAT_08017eb0 = *DAT_08017eb0 | 0xfff;
  return;
}



/* ===== FUN_080173b4 @ 080173b4 ===== */

void FUN_080173b4(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  undefined4 *puVar4;
  int iVar5;
  uint in_r3;
  uint local_10;
  
  iVar5 = FUN_0801f62c();
  puVar3 = DAT_08017d1c;
  local_10 = in_r3;
  if (iVar5 < 1) {
    *DAT_08017d1c = *DAT_08017d1c | 2;
    local_10 = *puVar3 & 2;
    *DAT_08017eb4 = *DAT_08017eb4 | 1;
    FUN_08016eb8(DAT_08017b20,0x400,0);
  }
  iVar5 = FUN_0801f62c();
  puVar3 = DAT_08017d1c;
  uVar2 = DAT_08017b20;
  if (iVar5 < 1) {
    *DAT_08017d1c = *DAT_08017d1c | 2;
    local_10 = *puVar3 & 2;
    DAT_08017eb4[1] = DAT_08017eb4[1] | 1;
    FUN_08016e94(uVar2,0x800,2);
    FUN_08016eb8(uVar2,0x800,0);
  }
  puVar4 = DAT_08017eb8;
  *DAT_08017eb8 = 8;
  uVar1 = DAT_08017ebc;
  puVar4[1] = puVar4[1] | 8;
  puVar4[2] = puVar4[2] & uVar1 | 0x80000000;
  iVar5 = DAT_08017ec0;
  do {
  } while ((int)puVar4[2] < 0);
  *(undefined4 *)(DAT_08017ec0 + 4) = 0x10;
  *(undefined4 *)(iVar5 + 4) = 0x80;
  *(undefined4 *)(iVar5 + 4) = 0x20;
  *(undefined4 *)(iVar5 + 4) = 0x40;
  *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 8;
  *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 2;
  *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 4;
  FUN_08016e74(iVar5,1,0x80);
  *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | 1;
  uVar1 = DAT_08017b18;
  puVar4[2] = puVar4[2] & DAT_08017b18 | 1;
  puVar4[2] = puVar4[2] & uVar1 | 8;
  puVar4[2] = uVar1 & puVar4[2] | 4;
  FUN_0801927e();
  FUN_08016fbc(local_10);
  return;
}



/* ===== FUN_080174c8 @ 080174c8 ===== */

uint FUN_080174c8(undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint local_10;
  
  FUN_08016fec();
  thunk_FUN_0801b1be();
  puVar1 = DAT_0801800c;
  uVar4 = DAT_08017b18;
  DAT_0801800c[1] = DAT_0801800c[1] & DAT_08017b18 | 0x10;
  puVar1[1] = puVar1[1] & uVar4 | 0x20;
  *puVar1 = *puVar1 & 0xfffffffb;
  puVar1[1] = uVar4 & puVar1[1] | 2;
  puVar1 = DAT_08018010;
  *DAT_08018010 = *DAT_08018010 & 0xfffffffe;
  *puVar1 = *puVar1 & 0xfffffff7;
  *puVar1 = *puVar1 & 0xfffffffd;
  *puVar1 = *puVar1 & 0xfffffffb;
  iVar2 = FUN_0801f62c();
  puVar1 = DAT_08017d1c;
  local_10 = param_3;
  if (iVar2 < 1) {
    *DAT_08017d1c = *DAT_08017d1c | 2;
    local_10 = *puVar1 & 2;
    FUN_08016eb8(DAT_08017b20,0x400,2);
    *DAT_08017eb4 = *DAT_08017eb4 & 0xfffffffe;
  }
  iVar3 = FUN_0801f62c();
  iVar2 = DAT_08017b20;
  if (iVar3 < 1) {
    *DAT_08017d1c = *DAT_08017d1c | 2;
    *(undefined4 *)(iVar2 + 0x28) = 0x800;
    FUN_08016e94(iVar2,0x800,1);
    FUN_08016eb8(iVar2,0x800,2);
    uVar4 = FUN_08016e94(iVar2,0x800,3);
    return uVar4;
  }
  return local_10;
}



/* ===== FUN_08017636 @ 08017636 ===== */

undefined4 FUN_08017636(void)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 extraout_r3;
  undefined4 uVar4;
  
  iVar3 = DAT_08018170;
  FUN_080227c8(DAT_08018170);
  do {
  } while (*(int *)(iVar3 + 0x10) << 0x1f < 0);
  *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) & 0xfffffffd;
  *(uint *)(iVar3 + 4) = *(uint *)(iVar3 + 4) | 2;
  puVar1 = DAT_08018198;
  *DAT_08018198 = *DAT_08018198 & 0xfffffffe;
  puVar1[9] = 0;
  iVar3 = DAT_08018018;
  *(undefined4 *)(DAT_08018018 + 0x28) = 0x100;
  FUN_08016e94(iVar3,0x100,1);
  *DAT_08017c08 = *DAT_08017c08 & 0xfffffffd;
  puVar1 = DAT_08018014;
  *DAT_08018014 = *DAT_08018014 & 0xfffffff7;
  puVar1[5] = 8;
  uVar2 = DAT_0801973c;
  uVar4 = *(undefined4 *)(DAT_08019754 + *(int *)(DAT_08019754 + 0x1c) * 4 + 0xc);
  FUN_08026000(uVar4);
  FUN_08026014(uVar2,uVar4);
  uVar4 = DAT_08019740;
  while (iVar3 = FUN_080259a0(uVar2), iVar3 != 0) {
    FUN_080259e0(uVar4,uVar2);
    FUN_0801b1d8(uVar2);
    FUN_08025a20(uVar2);
  }
  FUN_08026036(uVar4,0);
  FUN_0801b1d0();
  *(uint *)(DAT_08019768 + 8) = *(uint *)(DAT_08019768 + 8) & 0xfffffbf7 | 8;
  return extraout_r3;
}



/* ===== FUN_0801769c @ 0801769c ===== */

int FUN_0801769c(int param_1)

{
  int unaff_r7;
  
  if (-1 < *(int *)(DAT_08017c0c + 8) << 0xb) {
    return param_1;
  }
  *DAT_080181ac = (short)param_1;
  if (param_1 < 0) {
    param_1 = FUN_08019722();
  }
  *DAT_080181b0 = (int)(short)param_1 | *DAT_080181b0 & 0xfffff000;
  return unaff_r7;
}



/* ===== FUN_080176ce @ 080176ce ===== */

undefined8 FUN_080176ce(void)

{
  short sVar1;
  int iVar2;
  undefined4 unaff_r7;
  
  iVar2 = (int)*DAT_080181ac;
  if (iVar2 < 0) {
    sVar1 = FUN_08019722();
    return CONCAT44(unaff_r7,(int)sVar1);
  }
  return CONCAT44(iVar2,iVar2);
}



/* ===== FUN_080176e8 @ 080176e8 ===== */

void FUN_080176e8(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  float fVar6;
  
  iVar1 = DAT_0801790c;
  iVar3 = param_1 - *(uint *)(DAT_0801790c + 0x78);
  if (-1 < iVar3) {
    uVar2 = *(uint *)(DAT_0801790c + 0x78);
    if (1 < iVar3) {
      uVar2 = param_1;
    }
    param_1 = uVar2;
  }
  if (param_1 < 0xe47) {
    if (param_1 < 0xdfc) {
      if (param_1 < 0xd93) {
        fVar4 = DAT_08017a88;
        if (param_1 < 0xce5) goto LAB_080177d4;
        fVar5 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        fVar4 = DAT_08017a90;
        fVar6 = DAT_08017a8c;
      }
      else {
        fVar5 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        fVar4 = DAT_08017a84;
        fVar6 = DAT_08017a80;
      }
    }
    else {
      fVar5 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      if (param_1 < 0xe29) {
        fVar4 = DAT_08017a7c;
        fVar6 = DAT_080179a0;
        goto LAB_08017794;
      }
      fVar4 = DAT_0801799c;
      fVar6 = DAT_08017998;
    }
  }
  else if (param_1 < 0xf14) {
    fVar5 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    if (param_1 < 0xe7e) {
      fVar4 = DAT_08017994;
      fVar6 = DAT_08017990;
      goto LAB_08017794;
    }
    fVar4 = DAT_0801798c;
    fVar6 = DAT_08017988;
  }
  else {
    if (param_1 < 0x101d) {
      fVar5 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      fVar4 = DAT_08017984;
      fVar6 = DAT_08017980;
LAB_08017794:
      fVar4 = fVar4 + fVar5 * fVar6;
      goto LAB_080177d4;
    }
    fVar4 = DAT_08017974;
    if (0x1067 < param_1) goto LAB_080177d4;
    fVar5 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    fVar4 = DAT_0801797c;
    fVar6 = DAT_08017978;
  }
  fVar4 = fVar4 + fVar5 * fVar6;
LAB_080177d4:
  *(uint *)(DAT_0801790c + 0x78) = param_1;
  *(float *)(iVar1 + 0x70) = fVar4;
  return;
}



/* ===== FUN_080177de @ 080177de ===== */

void FUN_080177de(undefined1 param_1)

{
  undefined4 uVar1;
  undefined4 unaff_r7;
  
  *(undefined1 *)(DAT_080181b4 + 0x11) = param_1;
  uVar1 = FUN_08016f26();
  FUN_0801856e(uVar1,unaff_r7);
  return;
}



/* ===== FUN_080177f4 @ 080177f4 ===== */

void FUN_080177f4(void)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  FUN_080177de(4);
  iVar1 = DAT_080181b4;
  *(undefined1 **)(DAT_080181b4 + 0x74) = &LAB_080179a8_1;
  FUN_0802297c(iVar1 + 0x40,7);
  FUN_08016538(DAT_080181b8);
  uVar4 = FUN_08016efc();
  uVar3 = (undefined4)((ulonglong)uVar4 >> 0x20);
  uVar2 = FUN_0801862e();
  FUN_08018a4c((int)uVar4,uVar3,uVar2,1);
  FUN_08018a4c((int)uVar4,uVar3,uVar2,3);
  return;
}



/* ===== FUN_0801780c @ 0801780c ===== */

void FUN_0801780c(void)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  iVar1 = DAT_080181b4;
  *(undefined1 *)(DAT_080181b4 + 0x11) = 6;
  FUN_08016f26(iVar1,6);
  FUN_0801856e();
  *(undefined **)(iVar1 + 0x74) = &DAT_08017b81;
  FUN_080228e6();
  FUN_0802297c(iVar1 + 0x40,7);
  FUN_08016538(DAT_080181b8);
  uVar4 = FUN_08016efc();
  uVar3 = (undefined4)((ulonglong)uVar4 >> 0x20);
  uVar2 = FUN_0801862e();
  FUN_08018a4c((int)uVar4,uVar3,uVar2,1);
  FUN_08018a4c((int)uVar4,uVar3,uVar2,3);
  return;
}



/* ===== FUN_0801786c @ 0801786c ===== */

void FUN_0801786c(uint param_1)

{
  int iVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  
  puVar3 = DAT_080181c0;
  piVar2 = DAT_080181bc;
  iVar1 = DAT_0801790c;
  if (param_1 == 1) {
    FUN_08016996(0x1003);
LAB_08017884:
    FUN_080177f4();
  }
  else {
    if (param_1 == 0) goto LAB_08017888;
    if (param_1 == 3) {
      if (*DAT_080181bc == 0x5a5a) {
        *DAT_080181c0 = *DAT_080181c0 | 0x100;
        *piVar2 = 0;
        *puVar3 = *puVar3 & 0xfffffeff;
        FUN_08016996(0x1003);
        if (0xe74 < *(ushort *)(iVar1 + 0x38)) {
          FUN_0801780c();
          goto LAB_08017888;
        }
        goto LAB_08017884;
      }
      iVar4 = FUN_08022b5c(0x40);
      if (iVar4 == 0) {
        *(undefined1 *)(iVar1 + 0x11) = 3;
        FUN_08016f26(iVar1,3);
        FUN_0801856e();
        *(undefined **)(iVar1 + 0x74) = &DAT_08017911;
        goto LAB_08017888;
      }
      iVar4 = *(int *)(iVar1 + 0x7c) + -1;
      *(int *)(iVar1 + 0x7c) = iVar4;
      if (0 < iVar4) {
        return;
      }
    }
    else if (2 < param_1) goto LAB_08017888;
    FUN_08017e80();
  }
LAB_08017888:
  *(undefined4 *)(DAT_0801790c + 0x7c) = 8;
  return;
}



/* ===== FUN_08017d24 @ 08017d24 ===== */

undefined4 FUN_08017d24(undefined4 param_1)

{
  float fVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  
  iVar3 = FUN_0801d062(0x42,&local_38,9,param_1);
  puVar2 = DAT_080181e4;
  fVar1 = DAT_08017ea8;
  if (iVar3 != 0) {
    DAT_080181e4[6] = 0;
    puVar2[3] = local_38 + (local_34 + local_30 * fVar1) * fVar1;
    puVar2[4] = local_2c + (local_28 + local_24 * fVar1) * fVar1;
    puVar2[5] = local_20 + (local_1c + local_18 * fVar1) * fVar1;
    return 0;
  }
  iVar3 = FUN_0801d062(0x41,DAT_080181e4 + 6,1,param_1);
  if (iVar3 != 0) {
    puVar2[6] = puVar2[6] << 1;
    iVar3 = FUN_0801d062(0x30,puVar2,3,param_1);
    if ((iVar3 != 0) && (iVar3 = FUN_0801d062(0x40,puVar2 + 3,3,param_1), iVar3 != 0)) {
      return 0;
    }
  }
  uVar4 = DAT_080181e8[1];
  uVar5 = DAT_080181e8[2];
  uVar6 = DAT_080181e8[3];
  uVar7 = DAT_080181e8[4];
  uVar8 = DAT_080181e8[5];
  uVar9 = DAT_080181e8[6];
  *puVar2 = *DAT_080181e8;
  puVar2[1] = uVar4;
  puVar2[2] = uVar5;
  puVar2[3] = uVar6;
  puVar2[4] = uVar7;
  puVar2[5] = uVar8;
  puVar2[6] = uVar9;
  return 1;
}



/* ===== FUN_08017ddc @ 08017ddc ===== */

undefined2 FUN_08017ddc(int param_1)

{
  return *(undefined2 *)(DAT_080181b4 + param_1 * 2 + 0x34);
}



/* ===== FUN_08017df0 @ 08017df0 ===== */

void FUN_08017df0(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  puVar2 = DAT_080181ec;
  iVar3 = DAT_080181b4;
  *DAT_080181ec = *DAT_080181ec | 0x800;
  puVar2[2] = puVar2[2] | 0x8000;
  FUN_0802297c(iVar3 + 0x40,2);
  puVar1 = DAT_080181f0;
  *DAT_08018014 = *DAT_08018014 | 0x70;
  *puVar1 = 0;
  *(undefined1 *)(iVar3 + 0x11) = 0;
  FUN_08016f26(iVar3);
  FUN_0801856e();
  puVar1 = DAT_08017e7c;
  *(undefined4 *)(iVar3 + 0x74) = DAT_080181d4;
  uVar4 = *(uint *)(DAT_080181f4 + 8);
  *(uint *)(DAT_080181f4 + 8) = uVar4 | 0x80000;
  puVar2 = DAT_080181f8;
  if ((int)(uVar4 << 0xd) < 0) {
    puVar1[4] = 0x2000;
  }
  else {
    *puVar1 = 0x2000;
  }
  *puVar2 = *puVar2 | 0x800000;
  iVar3 = FUN_08017d24(DAT_080181fc);
  if (iVar3 == 0) {
    return;
  }
  FUN_08016a90(0x19);
  return;
}



/* ===== FUN_08017e80 @ 08017e80 ===== */

void FUN_08017e80(void)

{
  int iVar1;
  
  iVar1 = DAT_080181b4;
  *(undefined1 *)(DAT_080181b4 + 0x11) = 1;
  FUN_08016f26(iVar1,1);
  FUN_0801856e();
  *(undefined4 *)(iVar1 + 0x74) = DAT_08018200;
  FUN_0802297c(iVar1 + 0x40,0);
  return;
}



/* ===== FUN_08017ec4 @ 08017ec4 ===== */

void FUN_08017ec4(void)

{
  uint *puVar1;
  int *piVar2;
  uint *puVar3;
  uint *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  ushort uVar7;
  int iVar8;
  int *unaff_r4;
  uint uVar9;
  bool bVar10;
  
  disableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  iVar8 = FUN_08022b8c();
  bVar10 = iVar8 != 0;
  if (!bVar10) {
    iVar8 = DAT_080181f0[1];
    unaff_r4 = DAT_080181f0;
  }
  if (bVar10 || iVar8 != 0) goto LAB_08018006;
  uVar7 = FUN_08016edc();
  puVar3 = DAT_08018204;
  if (uVar7 < (ushort)*DAT_08018204) {
    uVar9 = *DAT_08018204;
    puVar1 = DAT_08018204 + 1;
    *DAT_08018204 = uVar9 + 0x10000;
    puVar3[1] = *puVar1 + (uint)(0xfffeffff < uVar9);
  }
  *(ushort *)puVar3 = uVar7;
  uVar9 = *puVar3;
  iVar8 = FUN_08016968();
  if (iVar8 == 0) {
LAB_08017f1c:
    iVar8 = 0x4000;
  }
  else {
    iVar8 = FUN_08016972();
    iVar8 = iVar8 - uVar9;
    if (iVar8 < 5) goto LAB_08018006;
    if (0x4000 < iVar8) goto LAB_08017f1c;
  }
  piVar2 = DAT_0801820c;
  uVar9 = (uVar9 + iVar8) - (uint)*DAT_08018208 & 0xffff;
  if ((DAT_0801820c[5] & 0xffffU) != uVar9) {
    DAT_0801820c[1] = DAT_0801820c[1] | 8;
    piVar2[5] = uVar9;
    do {
    } while (-1 < *piVar2 << 0x1c);
  }
  piVar2[1] = piVar2[1] | 1;
  *DAT_08018210 = 2;
  puVar6 = DAT_08018218;
  piVar5 = DAT_08018214;
  puVar4 = DAT_080181ec;
  puVar1 = DAT_080181e0;
  puVar3 = DAT_080181c0;
  piVar2 = DAT_08018140;
  DataSynchronizationBarrier(0xf);
  *DAT_08018214 = 0;
  do {
    *puVar6 = 7;
    if (*unaff_r4 == 0) {
      if (*piVar2 == 0) {
        puVar4[2] = puVar4[2] & 0xfffffffc | 1;
        *puVar4 = *puVar4 & 0xfffffffe;
        do {
        } while ((*puVar4 >> 1 & 1) != 0);
        *puVar3 = *puVar3 & 0xfffffff8;
        *puVar1 = *puVar1 | 4;
        DataSynchronizationBarrier(0xf);
        InstructionSynchronizationBarrier(0xf);
        WaitForInterrupt();
        *puVar1 = *puVar1 & 0xfffffffb;
        *puVar4 = *puVar4 | 1;
        do {
        } while (-1 < (int)(*puVar4 << 0x1e));
        puVar4[2] = puVar4[2] & 0xfffffffc;
        do {
        } while ((puVar4[2] & 0xc) != 0);
      }
    }
    else {
      DataSynchronizationBarrier(0xf);
      WaitForInterrupt();
    }
    DataSynchronizationBarrier(0xf);
    enableIRQinterrupts();
    disableIRQinterrupts();
    InstructionSynchronizationBarrier(0xf);
    DataSynchronizationBarrier(0xf);
  } while (*piVar5 == 0);
  *DAT_0801821c = 2;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
LAB_08018006:
  enableIRQinterrupts();
  return;
}



/* ===== FUN_0801801c @ 0801801c ===== */

void FUN_0801801c(void)

{
  byte bVar1;
  bool bVar2;
  ushort *puVar3;
  undefined1 uVar4;
  uint uVar5;
  undefined2 *puVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined2 uVar11;
  float fVar12;
  
  iVar10 = DAT_080181b4;
  if (*(char *)(DAT_080181b4 + 0x10) == '\0') {
    return;
  }
  *(undefined1 *)(DAT_080181b4 + 0x10) = 0;
  uVar5 = DAT_08018224;
  iVar7 = DAT_08018220;
  *(short *)(iVar10 + 0x38) =
       (short)((ulonglong)((uint)*(ushort *)(DAT_08018220 + 4) * 0x1e7b + 0xfff) *
               (ulonglong)DAT_08018224 + (ulonglong)DAT_08018224 >> 0x2c);
  puVar3 = DAT_0801822c;
  *(short *)(iVar10 + 0x3a) =
       (short)((ulonglong)((uint)*(ushort *)(iVar7 + 6) * 0x4d5f + DAT_08018228) * (ulonglong)uVar5
               + (ulonglong)uVar5 >> 0x2c);
  uVar5 = ((uint)*puVar3 * 3000) / (uint)*(ushort *)(iVar7 + 8);
  *(short *)(iVar10 + 0x3c) = (short)uVar5;
  *(short *)(iVar10 + 0x3e) =
       (short)((int)(*(ushort *)(iVar7 + 10) * uVar5 * 0x50 - *(int *)(iVar10 + 100)) /
              *(int *)(iVar10 + 0x68));
  puVar6 = (undefined2 *)FUN_08022f76();
  if (puVar6 == (undefined2 *)0x0) {
    uVar11 = 0xce4;
  }
  else {
    uVar11 = *puVar6;
  }
  iVar7 = FUN_08022f24();
  if (iVar7 != 0) {
    fVar12 = *(float *)(iVar7 + 4);
    if (((0.0 <= fVar12) && (*(char *)(iVar10 + 0x12) == -1)) ||
       ((fVar12 < 0.0 && (*(char *)(iVar10 + 0x12) == '\x01')))) {
      *(undefined1 *)(iVar10 + 0x14) = 0;
    }
    if (0.0 <= fVar12) {
      uVar4 = 1;
    }
    else {
      uVar4 = 0xff;
    }
    *(undefined1 *)(iVar10 + 0x12) = uVar4;
  }
  uVar8 = FUN_08023410(iVar10 + 0x14,uVar11);
  *(short *)(iVar10 + 0x36) = (short)uVar8;
  if (*(code **)(iVar10 + 0x74) != (code *)0x0) {
    (**(code **)(iVar10 + 0x74))(3);
  }
  bVar1 = *(byte *)(iVar10 + 0x11);
  iVar9 = FUN_08016f26(iVar10,bVar1);
  FUN_080176e8(uVar8);
  if ((*(float *)(iVar7 + 4) < 0.0) || (4 < bVar1)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  fVar12 = *(float *)(iVar10 + 0x70);
  iVar10 = FUN_08018144();
  if (4 < iVar10) {
    if ((iVar9 == 0x4000) && (DAT_0801866c <= fVar12)) {
      fVar12 = DAT_08018670;
    }
    FUN_0801856e(iVar9);
  }
  iVar10 = DAT_08018684;
  *(float *)(DAT_08018684 + 0x30) = fVar12;
  if (bVar2) {
    FUN_08015b4c(fVar12,(*(uint *)(iVar10 + 0x10) & 0x7fff) >> 0xd);
    *(int *)(iVar10 + 0x34) = iVar9;
    return;
  }
  FUN_08015b4c(fVar12,*(uint *)(iVar10 + 0x34) >> 0xd);
  return;
}



/* ===== FUN_08018132 @ 08018132 ===== */

void FUN_08018132(void)

{
                    /* WARNING: Could not recover jumptable at 0x0801813a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  if (*(code **)(DAT_080181b4 + 0x74) == (code *)0x0) {
    return;
  }
  (**(code **)(DAT_080181b4 + 0x74))();
  return;
}



/* ===== FUN_08018144 @ 08018144 ===== */

undefined1 FUN_08018144(void)

{
  return *(undefined1 *)(DAT_080181b4 + 0x11);
}



/* ===== FUN_0801814a @ 0801814a ===== */

undefined4 FUN_0801814a(void)

{
  char cVar1;
  
  cVar1 = *(char *)(DAT_080181b4 + 0x11);
  if ((cVar1 == '\x04' || cVar1 == '\x02') || cVar1 == '\x06') {
    if (*(int *)(DAT_080181b4 + 0x50) <= *(int *)(DAT_080181b4 + 0x54)) {
      return 1;
    }
  }
  else if (*(int *)(DAT_080181b4 + 0x50) < *(int *)(DAT_080181b4 + 0x54)) {
    return 1;
  }
  return 0;
}



/* ===== FUN_08018174 @ 08018174 ===== */

undefined4 FUN_08018174(void)

{
  byte bVar1;
  
  bVar1 = *(byte *)(DAT_080181b4 + 0xe);
  if (bVar1 == 1) {
    return 1;
  }
  if (bVar1 != 0) {
    if (bVar1 == 3) {
      return 3;
    }
    if (bVar1 < 3) {
      return 2;
    }
  }
  return 0;
}



/* ===== FUN_0801819c @ 0801819c ===== */

void FUN_0801819c(void)

{
  *(undefined1 *)(DAT_080181b4 + 0x10) = 1;
  *DAT_08018230 = 0;
  return;
}



/* ===== FUN_08018234 @ 08018234 ===== */

void FUN_08018234(undefined4 param_1)

{
  int iVar1;
  
  while (iVar1 = FUN_0802352c(param_1), iVar1 == 0) {
    if ((code *)*DAT_08018254 == (code *)0x0) {
      thunk_FUN_0802df14();
    }
    else {
      (*(code *)*DAT_08018254)();
    }
  }
  return;
}



/* ===== FUN_08018258 @ 08018258 ===== */

undefined4 FUN_08018258(int param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x15);
  if (cVar1 == 0x10) {
    return 0;
  }
  *(undefined4 *)(DAT_08018278 + cVar1 * 4 + 0x28) = param_2;
  *(char *)(param_1 + 0x15) = cVar1 + '\x01';
  return 1;
}



/* ===== FUN_0801827c @ 0801827c ===== */

void FUN_0801827c(int param_1)

{
  int *piVar1;
  
  if (*(char *)(param_1 + 0x14) < 1) {
    return;
  }
  piVar1 = *(int **)(DAT_080182a4 + *(char *)(param_1 + 0x14) * 4 + -4);
  (**(code **)(*piVar1 + 0xc))(piVar1);
  FUN_0802124c(piVar1);
  return;
}



/* ===== FUN_080182a8 @ 080182a8 ===== */

void FUN_080182a8(int param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_2 + 1 < (int)*(char *)(param_1 + 0x14)) {
    puVar2 = (undefined4 *)(DAT_080182fc + *(char *)(param_1 + 0x14) * 4 + -4);
    puVar3 = (undefined4 *)(DAT_080182fc + param_2 * 4);
    if (puVar3 < puVar2) {
      for (; puVar3 < puVar2; puVar2 = puVar2 + -1) {
        piVar1 = (int *)*puVar2;
        (**(code **)(*piVar1 + 0xc))(piVar1,1);
        FUN_0802124c(piVar1);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 4))(piVar1);
        }
        *puVar2 = 0;
      }
    }
    *(char *)(param_1 + 0x14) = (char)param_2 + '\x01';
  }
  return;
}



/* ===== FUN_08018300 @ 08018300 ===== */

undefined8
FUN_08018300(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_08018334;
  *(char *)(param_1 + 1) = (char)param_2;
  FUN_080159dc(param_2);
  FUN_080159f0(param_2,param_1 + 2,param_1 + 3);
  param_1[4] = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  *(undefined1 *)((int)param_1 + 0x17) = 0;
  *(undefined1 *)((int)param_1 + 0x16) = 0;
  *(undefined1 *)((int)param_1 + 0x15) = 0;
  *(undefined1 *)(param_1 + 5) = 1;
  return CONCAT44(param_4,param_1);
}



/* ===== FUN_08018338 @ 08018338 ===== */

undefined4 FUN_08018338(int param_1,int *param_2)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x14);
  if (cVar1 < 8) {
    *(int **)(DAT_08018368 + cVar1 * 4) = param_2;
    *(char *)(param_1 + 0x14) = cVar1 + '\x01';
    (**(code **)(*param_2 + 8))(param_2,0);
    *(undefined1 *)(param_1 + 0x17) = *(undefined1 *)(param_1 + 0x16);
    return 1;
  }
  return 0;
}



/* ===== FUN_0801836c @ 0801836c ===== */

void FUN_0801836c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x18) == '\0') {
    iVar2 = FUN_08016854();
    *(int *)(param_1 + 8) = iVar2 + 0xf0000;
    uVar1 = DAT_08016988;
    FUN_080211e8(DAT_08016988,param_1);
    FUN_0802120c(uVar1,param_1,param_4);
    return;
  }
  return;
}



/* ===== FUN_0801837c @ 0801837c ===== */

uint FUN_0801837c(void)

{
  uint uVar1;
  
  uVar1 = *DAT_08018674 & 0xffff;
  while (uVar1 != (*DAT_08018674 & 0xffff)) {
    uVar1 = *DAT_08018674 & 0xffff;
  }
  return uVar1 + *DAT_08018678 & 0xffff;
}



/* ===== FUN_08018398 @ 08018398 ===== */

undefined8 FUN_08018398(void)

{
  uint *puVar1;
  uint *puVar2;
  ushort uVar3;
  uint uVar4;
  
  uVar3 = FUN_0801837c();
  puVar2 = DAT_0801867c;
  if (uVar3 < (ushort)*DAT_0801867c) {
    uVar4 = *DAT_0801867c;
    puVar1 = DAT_0801867c + 1;
    *DAT_0801867c = uVar4 + 0x10000;
    puVar2[1] = *puVar1 + (uint)(0xfffeffff < uVar4);
  }
  *(ushort *)puVar2 = uVar3;
  return *(undefined8 *)puVar2;
}



/* ===== FUN_080183c0 @ 080183c0 ===== */

undefined8 FUN_080183c0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_080183d8(param_1,0);
  *(int *)(param_1 + 8) = param_2 + 0x1e0000;
  return CONCAT44(param_4,param_1);
}



/* ===== FUN_080183d8 @ 080183d8 ===== */

void FUN_080183d8(int param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  ushort uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint in_fpscr;
  float fVar9;
  float fVar10;
  undefined8 uVar11;
  
  uVar4 = FUN_0801837c();
  puVar2 = DAT_0801867c;
  if (uVar4 < (ushort)*DAT_0801867c) {
    uVar6 = *DAT_0801867c;
    puVar1 = DAT_0801867c + 1;
    *DAT_0801867c = uVar6 + 0x10000;
    puVar2[1] = *puVar1 + (uint)(0xfffeffff < uVar6);
  }
  iVar3 = DAT_08018680;
  *(ushort *)puVar2 = uVar4;
  uVar6 = *puVar2;
  iVar7 = *(int *)(iVar3 + 0x10);
  fVar9 = (float)FUN_0802313a();
  uVar8 = *(uint *)(param_1 + 0x10);
  if (param_2 == 0) {
    if ((*(char *)(param_1 + 0x18) != '\0') &&
       (((int)(uVar6 - *(int *)(param_1 + 0x1c)) < 0xf0000 ||
        (((((uint)(iVar7 - *(int *)(param_1 + 0x20)) < 10 &&
           (in_fpscr = in_fpscr & 0xfffffff, ABS(fVar9 - *(float *)(param_1 + 0x24)) < DAT_08018664)
           ) && (ABS(*(float *)(DAT_08018684 + 0x30) - *(float *)(param_1 + 0x28)) < 1.0)) &&
         (((*(uint *)(param_1 + 0x2c) ^ uVar8) & 0x6000) == 0)))))) {
      return;
    }
  }
  else {
    if (param_2 == 2) goto LAB_0801849a;
    if (1 < param_2) {
      return;
    }
  }
  *(undefined1 *)(param_1 + 0x18) = 1;
  *(uint *)(param_1 + 0x1c) = uVar6;
  *(int *)(param_1 + 0x20) = iVar7;
  *(float *)(param_1 + 0x24) = fVar9;
  uVar5 = *(undefined4 *)(DAT_08018684 + 0x30);
  *(uint *)(param_1 + 0x2c) = uVar8;
  *(undefined4 *)(param_1 + 0x28) = uVar5;
  uVar8 = uVar8 | 0x1000;
LAB_0801849a:
  uVar11 = FUN_08018398();
  fVar10 = (float)VectorUnsignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
  FUN_080189ac(fVar10 * DAT_08018668,fVar9,*(undefined4 *)(DAT_08018684 + 0x30),(int)uVar11,
               (int)((ulonglong)uVar11 >> 0x20),*(undefined4 *)(iVar3 + 0x18),uVar8 & 0xffff);
  return;
}



/* ===== FUN_080184d4 @ 080184d4 ===== */

void FUN_080184d4(void)

{
  FUN_08016890(DAT_08018684,0x10000);
  return;
}



/* ===== FUN_080184e0 @ 080184e0 ===== */

void FUN_080184e0(void)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  undefined4 in_r3;
  uint uVar6;
  uint uVar7;
  uint in_fpscr;
  undefined4 uVar8;
  float fVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined8 uVar12;
  
  uVar5 = FUN_0801837c();
  puVar2 = DAT_0801867c;
  if (uVar5 < (ushort)*DAT_0801867c) {
    uVar6 = *DAT_0801867c;
    puVar1 = DAT_0801867c + 1;
    *DAT_0801867c = uVar6 + 0x10000;
    puVar2[1] = *puVar1 + (uint)(0xfffeffff < uVar6);
  }
  *(ushort *)puVar2 = uVar5;
  iVar4 = DAT_08018684;
  iVar3 = DAT_08018680;
  uVar6 = *puVar2;
  uVar11 = *(undefined4 *)(DAT_08018680 + 0x10);
  uVar8 = FUN_0802313a();
  uVar7 = *(uint *)(iVar4 + 0x10);
  uVar10 = *(undefined4 *)(iVar4 + 0x30);
  *(uint *)(iVar4 + 0x1c) = uVar6;
  *(undefined1 *)(iVar4 + 0x18) = 1;
  *(undefined4 *)(iVar4 + 0x20) = uVar11;
  *(undefined4 *)(iVar4 + 0x24) = uVar8;
  *(undefined4 *)(iVar4 + 0x28) = uVar10;
  *(uint *)(iVar4 + 0x2c) = uVar7;
  uVar12 = FUN_08018398();
  fVar9 = (float)VectorUnsignedToFloat(uVar11,(byte)(in_fpscr >> 0x16) & 3);
  FUN_080189ac(fVar9 * DAT_08018668,uVar8,uVar10,(int)uVar12,(int)((ulonglong)uVar12 >> 0x20),
               *(undefined4 *)(iVar3 + 0x18),uVar7 & 0xffff | 0x1000);
  *(undefined1 *)(iVar4 + 0x18) = 0;
  FUN_080168b4(iVar4,in_r3);
  return;
}



/* ===== FUN_08018568 @ 08018568 ===== */

void FUN_08018568(undefined4 param_1)

{
  FUN_080183d8(DAT_08018684,param_1);
  return;
}



/* ===== FUN_0801856e @ 0801856e ===== */

undefined4 FUN_0801856e(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  bool bVar5;
  undefined8 uVar6;
  
  uVar3 = *(uint *)(DAT_08018684 + 0x10);
  bVar5 = (uVar3 & 0x6000) == 0x4000;
  uVar1 = param_1 >> 0xd & 3;
  uVar2 = uVar1 << 0xd;
  *(uint *)(DAT_08018684 + 0x10) = uVar3 & 0xffff9fff | uVar2;
  if (bVar5 == (uVar1 == 2)) {
    return param_4;
  }
  if (bVar5) {
    uVar4 = 8;
  }
  else {
    uVar4 = 7;
  }
  uVar6 = FUN_08018398();
  uVar4 = FUN_08018a4c((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar3 & 0x9fff | uVar2,uVar4);
  return uVar4;
}



/* ===== FUN_08018620 @ 08018620 ===== */

void FUN_08018620(uint param_1,uint param_2)

{
  *(uint *)(DAT_08018684 + 0x10) = param_1 & param_2 | *(uint *)(DAT_08018684 + 0x10) & ~param_1;
  return;
}



/* ===== FUN_0801862e @ 0801862e ===== */

undefined4 FUN_0801862e(void)

{
  return *(undefined4 *)(DAT_08018684 + 0x10);
}



/* ===== FUN_08018634 @ 08018634 ===== */

uint FUN_08018634(uint param_1,uint param_2)

{
  return ~-(uint)((param_1 & (param_2 ^ *(uint *)(DAT_08018684 + 0x10))) == 0) >> 0x1f;
}



/* ===== FUN_08018646 @ 08018646 ===== */

void FUN_08018646(uint param_1)

{
  *(uint *)(DAT_08018684 + 0x14) = param_1 | *(uint *)(DAT_08018684 + 0x14);
  return;
}



/* ===== FUN_08018650 @ 08018650 ===== */

void FUN_08018650(uint param_1)

{
  *(uint *)(DAT_08018684 + 0x14) = *(uint *)(DAT_08018684 + 0x14) & ~param_1;
  return;
}



/* ===== FUN_0801865c @ 0801865c ===== */

undefined4 FUN_0801865c(void)

{
  return *(undefined4 *)(DAT_08018684 + 0x14);
}



/* ===== FUN_080186c0 @ 080186c0 ===== */

int FUN_080186c0(uint param_1,int param_2,uint param_3,int param_4)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  
  bVar5 = param_2 < 0;
  if (bVar5) {
    bVar6 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -param_2 - (uint)bVar6;
  }
  uVar3 = -param_4 + 6;
  uVar4 = DAT_08018d14 / param_3 >> (uVar3 & 0xff);
  lVar1 = (ulonglong)uVar4 * (ulonglong)param_1 +
          CONCAT44(uVar4 * param_2,0x8000 >> (-param_4 + 7U & 0xff));
  iVar2 = FUN_08024968((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),0xf - uVar3);
  if (bVar5) {
    iVar2 = -iVar2;
  }
  return iVar2;
}



/* ===== FUN_08018712 @ 08018712 ===== */

undefined8 FUN_08018712(void)

{
  uint *puVar1;
  ushort uVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = DAT_08018d20;
  uVar4 = *DAT_08018d18 & 0xffff;
  while (uVar4 != (*DAT_08018d18 & 0xffff)) {
    uVar4 = *DAT_08018d18 & 0xffff;
  }
  uVar2 = *DAT_08018d1c + (short)uVar4;
  if (uVar2 < (ushort)*DAT_08018d20) {
    uVar4 = *DAT_08018d20;
    puVar1 = DAT_08018d20 + 1;
    *DAT_08018d20 = uVar4 + 0x10000;
    puVar3[1] = *puVar1 + (uint)(0xfffeffff < uVar4);
  }
  *(ushort *)puVar3 = uVar2;
  return *(undefined8 *)puVar3;
}



/* ===== FUN_08018756 @ 08018756 ===== */

undefined4 FUN_08018756(undefined4 param_1,int param_2,undefined4 param_3)

{
  if (*(char *)(param_2 + 8) == '\b') {
    return 0;
  }
  FUN_0802498c(param_1,param_2 + 10,param_3);
  return param_3;
}



/* ===== FUN_08018770 @ 08018770 ===== */

undefined4 FUN_08018770(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  
  puVar1 = DAT_08018d0c;
  *DAT_08018d0c = *DAT_08018d0c | 4;
  FUN_0802498c(puVar1 + 0xc,param_1,0x19);
  *(undefined2 *)(puVar1 + 0xe) = 0;
  return param_4;
}



/* ===== FUN_08018794 @ 08018794 ===== */

void FUN_08018794(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 local_1c;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined2 local_10;
  undefined4 uStack_c;
  
  uStack_c = param_4;
  local_1c = FUN_08018712();
  local_14 = 7;
  local_13 = 0;
  local_12 = 0x11;
  local_11 = 0;
  local_10 = FUN_0801862e();
  FUN_08024a32(DAT_08018d0c,&local_1c,param_1,0,0,0,0);
  return;
}



/* ===== FUN_080187dc @ 080187dc ===== */

void FUN_080187dc(undefined4 param_1,undefined4 param_2)

{
  undefined8 local_1c;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined2 local_10;
  
  local_1c = FUN_08018712();
  local_14 = 7;
  local_13 = 0;
  local_12 = 0x11;
  local_11 = 0;
  local_10 = FUN_0801862e();
  FUN_08024a32(DAT_08018d0c,&local_1c,param_1,param_2,0,0,0);
  return;
}



/* ===== FUN_08018826 @ 08018826 ===== */

void FUN_08018826(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 local_24;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined2 local_18;
  undefined4 uStack_14;
  
  uStack_14 = param_4;
  local_24 = FUN_08018712();
  local_1c = 7;
  local_1b = 0;
  local_1a = 0x11;
  local_19 = 0;
  local_18 = FUN_0801862e();
  FUN_08024a32(DAT_08018d0c,&local_24,param_1,param_2,param_3,0,0);
  return;
}



/* ===== FUN_08018872 @ 08018872 ===== */

void FUN_08018872(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 local_24;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined2 local_18;
  
  local_24 = FUN_08018712();
  local_1c = 7;
  local_1b = 0;
  local_1a = 0x11;
  local_19 = 0;
  local_18 = FUN_0801862e();
  FUN_08024a32(DAT_08018d0c,&local_24,param_1,param_2,param_3,param_4,0);
  return;
}



/* ===== FUN_080188b2 @ 080188b2 ===== */

void FUN_080188b2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined8 local_24;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined2 local_18;
  
  local_24 = FUN_08018712();
  local_1c = 7;
  local_1b = 0;
  local_1a = 0x11;
  local_19 = 0;
  local_18 = FUN_0801862e();
  FUN_08024a32(DAT_08018d0c,&local_24,param_1,param_2,param_3,param_4,param_5);
  return;
}



/* ===== FUN_08018900 @ 08018900 ===== */

undefined4 FUN_08018900(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_08018d10;
  if (DAT_08018d10[2] == 0x80) {
    DAT_08018d10[2] = 0x7f;
  }
  piVar1[2] = piVar1[2] + 1;
  iVar2 = piVar1[1] + 1;
  if (0x7f < iVar2) {
    iVar2 = 0;
  }
  piVar1[1] = iVar2;
  FUN_0802498c(*piVar1 + iVar2 * 0x12,param_1,0x12);
  iVar2 = *piVar1 + piVar1[1] * 0x12;
  *(undefined1 *)(iVar2 + 8) = 1;
  *(undefined1 *)(iVar2 + 9) = 0;
  return param_4;
}



/* ===== FUN_0801894a @ 0801894a ===== */

void FUN_0801894a(undefined4 param_1)

{
  FUN_08024a9c(DAT_08018d24,param_1,10);
  return;
}



/* ===== FUN_08018958 @ 08018958 ===== */

void FUN_08018958(undefined4 param_1)

{
  FUN_08024a9c(DAT_08018d24,param_1,4);
  return;
}



/* ===== FUN_0801895e @ 0801895e ===== */

void FUN_0801895e(int param_1)

{
  char cVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar2 = DAT_08018d0c;
  cVar1 = *(char *)(param_1 + 10);
  if (cVar1 != '\x03' && cVar1 != '\x06') {
    FUN_08024a9c(DAT_08018d24,param_1,7);
    return;
  }
  puVar3 = DAT_08018d0c + 1;
  if (cVar1 == '\x03') {
    *DAT_08018d0c = *DAT_08018d0c | 1;
  }
  else {
    if (cVar1 != '\x06') {
      return;
    }
    *DAT_08018d0c = *DAT_08018d0c | 2;
    puVar3 = (uint *)((int)puVar2 + 0x1a);
  }
  FUN_0802498c(puVar3,param_1,0x16);
  *(undefined1 *)(puVar3 + 2) = 7;
  *(undefined1 *)((int)puVar3 + 9) = 0;
  return;
}



/* ===== FUN_080189ac @ 080189ac ===== */

void FUN_080189ac(undefined4 param_1,float param_2,float param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,ushort param_7)

{
  float fVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_16;
  undefined4 local_12;
  undefined2 local_e;
  undefined2 local_c;
  ushort local_a;
  
  fVar1 = (param_2 + 20.0) * DAT_08018c54;
  if (DAT_08018c58 <= fVar1) {
    fVar1 = DAT_08018c5c;
  }
  else if (fVar1 < DAT_08018c60) {
    fVar1 = DAT_08018c60;
  }
  param_3 = param_3 * DAT_08018c54;
  local_e = (undefined2)(int)fVar1;
  if (param_3 < 0.0) {
    param_3 = DAT_08018c64;
  }
  else if (DAT_08018c58 <= param_3) {
    param_3 = DAT_08018c5c;
  }
  local_c = (undefined2)(int)param_3;
  local_a = param_7 & 0xf0d8;
  local_20 = param_4;
  local_1c = param_5;
  local_16 = param_6;
  local_12 = param_1;
  FUN_08024a9c(DAT_08018d24,&local_20,3);
  return;
}



/* ===== FUN_08018a4c @ 08018a4c ===== */

void FUN_08018a4c(undefined4 param_1,undefined4 param_2,ushort param_3,int param_4)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_16;
  undefined1 local_15;
  ushort local_14;
  
  local_16 = (undefined1)param_4;
  local_14 = param_3;
  if ((param_4 != 3 && param_4 != 6) && (param_4 != 0x11 && param_4 != 0x12)) {
    local_14 = param_3 | 0x1000;
  }
  local_15 = 0;
  local_20 = param_1;
  local_1c = param_2;
  FUN_0801895e(&local_20);
  return;
}



/* ===== FUN_08018a78 @ 08018a78 ===== */

void FUN_08018a78(undefined4 param_1,float param_2,undefined4 param_3,undefined4 param_4,
                 undefined1 param_5)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_16;
  undefined1 local_15;
  ushort uStack_14;
  undefined4 uStack_12;
  undefined2 uStack_e;
  
  local_15 = 3;
  if (DAT_08018d08 <= param_2 * DAT_08018d04) {
    uStack_e = 0x3de;
  }
  else {
    uStack_e = (undefined2)(int)(param_2 * DAT_08018d04);
  }
  local_20 = param_3;
  local_1c = param_4;
  local_16 = param_5;
  uStack_12 = param_1;
  uStack_14 = FUN_0801862e();
  uStack_14 = uStack_14 | 0x1000;
  FUN_0801895e(&local_20);
  return;
}



/* ===== FUN_08018ab8 @ 08018ab8 ===== */

void FUN_08018ab8(undefined4 param_1,float param_2,undefined4 param_3,undefined4 param_4,
                 undefined1 param_5)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_16;
  undefined1 local_15;
  ushort local_14;
  undefined4 local_12;
  undefined2 local_e;
  
  local_15 = 0xc;
  if (DAT_08018d08 <= param_2 * DAT_08018d04) {
    local_e = 0x3de;
  }
  else {
    local_e = (undefined2)(int)(param_2 * DAT_08018d04);
  }
  local_20 = param_3;
  local_1c = param_4;
  local_16 = param_5;
  local_12 = param_1;
  local_14 = FUN_0801862e();
  local_14 = local_14 | 0x1000;
  FUN_0801895e(&local_20);
  return;
}



/* ===== FUN_08018b10 @ 08018b10 ===== */

void FUN_08018b10(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined1 param_5)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_16;
  undefined1 local_15;
  ushort uStack_14;
  undefined4 local_12;
  undefined4 local_e;
  
  local_15 = 0x30;
  local_20 = param_2;
  local_1c = param_3;
  local_16 = param_5;
  local_12 = param_4;
  local_e = param_1;
  uStack_14 = FUN_0801862e();
  uStack_14 = uStack_14 | 0x1000;
  FUN_0801895e(&local_20);
  return;
}



/* ===== FUN_08018b34 @ 08018b34 ===== */

void FUN_08018b34(float param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  float fVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_16;
  undefined1 local_15;
  ushort uStack_14;
  undefined2 local_12;
  
  fVar1 = (param_1 + 20.0) * DAT_08018c54;
  local_15 = 0x40;
  if (DAT_08018c58 <= fVar1) {
    fVar1 = DAT_08018c5c;
  }
  else if (fVar1 < DAT_08018c60) {
    fVar1 = DAT_08018c60;
  }
  local_12 = (undefined2)(int)fVar1;
  local_20 = param_2;
  local_1c = param_3;
  local_16 = param_4;
  uStack_14 = FUN_0801862e();
  uStack_14 = uStack_14 | 0x1000;
  FUN_0801895e(&local_20);
  return;
}



/* ===== FUN_08018b8a @ 08018b8a ===== */

void FUN_08018b8a(void)

{
  int iVar1;
  
  iVar1 = DAT_08018d10;
  while (0 < *(int *)(iVar1 + 0x14)) {
    FUN_08018d2c(iVar1 + 0xc);
  }
  return;
}



/* ===== FUN_08018c68 @ 08018c68 ===== */

undefined4 FUN_08018c68(char *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char cVar5;
  bool bVar6;
  
  pcVar4 = param_1 + param_2;
  cVar5 = *param_1;
  do {
    if (*param_1 != cVar5) {
      return 0;
    }
    uVar2 = (uint)(byte)param_1[2];
    bVar6 = SBORROW4(uVar2,8);
    iVar3 = uVar2 - 8;
    if (uVar2 < 9) {
      bVar6 = SBORROW4(*(int *)(param_1 + 3),DAT_08018d28);
      iVar3 = *(int *)(param_1 + 3) - DAT_08018d28;
    }
    if (iVar3 < 0 == bVar6) {
      return 0;
    }
    uVar2 = (uint)(byte)param_1[2];
    if (uVar2 == 2) {
      uVar2 = 10;
LAB_08018ca0:
      uVar2 = (uint)(byte)(&DAT_08018e49)[uVar2 * 2];
    }
    else if (uVar2 < 0xb) {
      if (uVar2 != 7) goto LAB_08018ca0;
      if (param_1[1] != '\0') goto LAB_08018cd0;
      cVar1 = param_1[8];
      if (cVar1 == '\0') {
        uVar2 = 4;
      }
      else if (cVar1 == '\x03' || cVar1 == '\f') {
        uVar2 = 10;
      }
      else if (cVar1 == '0') {
        uVar2 = 0xc;
      }
      else {
        if (cVar1 != '@') goto LAB_08018cd0;
        uVar2 = 6;
      }
    }
    else {
LAB_08018cd0:
      uVar2 = 0;
    }
    if (uVar2 == 0) {
      return 0;
    }
    if (param_1[1] == '\0') {
      iVar3 = uVar2 + 7;
    }
    else {
      if (param_1[1] != '\x01') {
        return 0;
      }
      if (*(ushort *)(param_1 + 7) < 2) {
        return 0;
      }
      iVar3 = *(ushort *)(param_1 + 7) * uVar2 + 0xd;
    }
    param_1 = param_1 + iVar3;
    if (param_1 == pcVar4) {
      return 1;
    }
    cVar5 = cVar5 + '\x01';
    if (pcVar4 < param_1) {
      return 0;
    }
  } while( true );
}



/* ===== FUN_08018d2c @ 08018d2c ===== */

void FUN_08018d2c(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_08025194();
  switch(*(undefined1 *)(iVar1 + 8)) {
  case 3:
    uVar2 = (uint)*(ushort *)(iVar1 + 0x16);
    break;
  case 4:
    uVar2 = (uint)*(ushort *)(iVar1 + 0xe);
    break;
  case 5:
  case 6:
  case 10:
    uVar2 = (uint)*(ushort *)(iVar1 + 0x18);
    break;
  case 7:
    if (1 < *(byte *)(iVar1 + 10) - 0x11) {
      uVar2 = (uint)*(ushort *)(iVar1 + 0xc);
      break;
    }
    goto LAB_08018d6a;
  case 8:
    uVar2 = (uint)*(ushort *)(iVar1 + 10);
    break;
  default:
    goto switchD_08018d3c_caseD_9;
  }
  if ((uVar2 >> 0xc & 1) != 0) {
LAB_08018d6a:
    *(undefined1 *)(iVar1 + 9) = 0;
    switch(*(undefined1 *)(iVar1 + 8)) {
    case 3:
      *(ushort *)(iVar1 + 0x16) = *(ushort *)(iVar1 + 0x16) | 0x8000;
      break;
    case 4:
      *(ushort *)(iVar1 + 0xe) = *(ushort *)(iVar1 + 0xe) | 0x8000;
      break;
    case 5:
    case 6:
    case 10:
      *(ushort *)(iVar1 + 0x18) = *(ushort *)(iVar1 + 0x18) | 0x8000;
      break;
    case 7:
      *(ushort *)(iVar1 + 0xc) = *(ushort *)(iVar1 + 0xc) | 0x8000;
      break;
    case 8:
      *(ushort *)(iVar1 + 10) = *(ushort *)(iVar1 + 10) | 0x8000;
    }
    FUN_080251b2();
  }
switchD_08018d3c_caseD_9:
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  return;
}



/* ===== FUN_08018dbc @ 08018dbc ===== */

void FUN_08018dbc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 auStack_48 [8];
  char local_40;
  ushort local_3e;
  undefined4 local_3c;
  undefined4 local_38;
  undefined2 local_34;
  undefined2 local_32;
  uint local_22;
  undefined4 local_1e;
  undefined4 local_1a;
  undefined2 local_16;
  undefined2 local_14;
  
  FUN_0802578a();
  while ((*(int *)(param_1 + 8) != 0x20 && (iVar1 = FUN_08025322(), iVar1 == 0))) {
    iVar1 = FUN_08025274(auStack_48);
    if (iVar1 == 0) {
      if (local_40 == '\x02') {
        local_22 = (uint)local_3e;
        local_1e = local_3c;
        local_1a = local_38;
        local_16 = local_34;
        local_14 = local_32;
        FUN_0802498c(&local_3e,&local_22,0x10);
        local_40 = '\n';
      }
      FUN_08025800(param_1,auStack_48,local_40);
    }
  }
  FUN_080257b6();
  FUN_08024f28(param_1,param_2,param_3);
  return;
}



/* ===== FUN_08018ec0 @ 08018ec0 ===== */

undefined4 * FUN_08018ec0(undefined4 *param_1)

{
  FUN_080258ac(param_1,0x10);
  *param_1 = DAT_08018ed4;
  return param_1;
}



/* ===== FUN_08018ed8 @ 08018ed8 ===== */

/* WARNING: Removing unreachable block (ram,0x0802585c) */
/* WARNING: Removing unreachable block (ram,0x08025866) */

int FUN_08018ed8(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  
  iVar6 = DAT_08018f38;
  cVar1 = *(char *)(param_1 + 0x18);
  iVar2 = (int)cVar1;
  if (iVar2 < 1) {
    cVar1 = *(char *)(param_1 + 0x15);
  }
  cVar1 = cVar1 + -1;
  iVar7 = (int)cVar1;
  if (iVar7 != iVar2) {
    iVar2 = *(int *)(DAT_08018f38 + 0x28 + iVar2 * 4);
    *(undefined1 *)(iVar2 + 9) = 0;
    *(undefined1 *)(iVar2 + 10) = 1;
    iVar6 = *(int *)(iVar6 + 0x28 + iVar7 * 4);
    *(undefined1 *)(iVar6 + 9) = 1;
    *(undefined1 *)(iVar6 + 10) = 1;
    *(char *)(param_1 + 0x18) = cVar1;
    *(undefined1 *)(param_1 + 0x14) = 1;
    cVar5 = *(char *)(param_1 + 0x17);
    if ((iVar7 < cVar5) || ((char)(*(char *)(param_1 + 0x16) + cVar5 + -1) < cVar1)) {
      iVar6 = (int)cVar1;
      if (0 < *(char *)(param_1 + 0x16)) {
        iVar7 = *(char *)(param_1 + 0x16) + -1;
        iVar8 = (int)cVar5;
        bVar9 = SBORROW4(iVar6,iVar8);
        iVar2 = iVar6 - iVar8;
        if (iVar8 <= iVar6) {
          iVar6 = iVar6 - iVar7;
          bVar9 = SBORROW4((int)cVar5,iVar6);
          iVar2 = cVar5 - iVar6;
        }
        if (iVar2 < 0 != bVar9) {
          cVar5 = (char)iVar6;
        }
        *(char *)(param_1 + 0x17) = cVar5;
        param_1 = *(int *)(param_1 + 0x10);
        piVar3 = (int *)(DAT_080258a8 + cVar5 * 4 + 0x28);
        iVar6 = 0;
        piVar4 = piVar3;
        while( true ) {
          iVar2 = *piVar4;
          *(int *)(iVar2 + 0xc) = iVar6;
          *(undefined1 *)(iVar2 + 10) = 1;
          if (piVar3 + iVar7 <= piVar4) break;
          iVar6 = *(int *)(*piVar4 + 0x10) + param_1 + iVar6;
          piVar4 = piVar4 + 1;
        }
      }
      return param_1;
    }
  }
  return param_4;
}



/* ===== FUN_08018f3c @ 08018f3c ===== */

/* WARNING: Removing unreachable block (ram,0x0802585c) */
/* WARNING: Removing unreachable block (ram,0x08025866) */

void FUN_08018f3c(int param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int *piVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  
  iVar9 = DAT_08018fa4;
  cVar6 = *(char *)(param_1 + 0x17);
  iVar7 = (int)cVar6;
  cVar1 = *(char *)(param_1 + 0x16);
  cVar2 = *(char *)(param_1 + 0x18);
  cVar3 = cVar2 + '\x01';
  if (cVar3 == *(char *)(param_1 + 0x15)) {
    cVar3 = '\0';
  }
  iVar10 = (int)cVar3;
  if (iVar10 != cVar2) {
    iVar8 = *(int *)(DAT_08018fa4 + 0x28 + cVar2 * 4);
    *(undefined1 *)(iVar8 + 9) = 0;
    *(undefined1 *)(iVar8 + 10) = 1;
    bVar11 = SBORROW4(iVar10,iVar7);
    iVar8 = iVar10 - iVar7;
    iVar9 = *(int *)(iVar9 + 0x28 + iVar10 * 4);
    *(undefined1 *)(iVar9 + 9) = 1;
    *(undefined1 *)(iVar9 + 10) = 1;
    if (iVar7 <= iVar10) {
      iVar8 = (int)(char)(cVar1 + cVar6 + -1);
      bVar11 = SBORROW4(iVar8,(int)cVar3);
      iVar8 = iVar8 - cVar3;
    }
    *(char *)(param_1 + 0x18) = cVar3;
    *(undefined1 *)(param_1 + 0x14) = 1;
    if (iVar8 < 0 != bVar11) {
      iVar9 = (int)cVar3;
      if (0 < *(char *)(param_1 + 0x16)) {
        iVar10 = *(char *)(param_1 + 0x16) + -1;
        iVar8 = (int)cVar6;
        bVar11 = SBORROW4(iVar9,iVar8);
        iVar7 = iVar9 - iVar8;
        if (iVar8 <= iVar9) {
          iVar9 = iVar9 - iVar10;
          bVar11 = SBORROW4((int)cVar6,iVar9);
          iVar7 = cVar6 - iVar9;
        }
        if (iVar7 < 0 != bVar11) {
          cVar6 = (char)iVar9;
        }
        *(char *)(param_1 + 0x17) = cVar6;
        iVar9 = *(int *)(param_1 + 0x10);
        piVar4 = (int *)(DAT_080258a8 + cVar6 * 4 + 0x28);
        iVar7 = 0;
        piVar5 = piVar4;
        while( true ) {
          iVar8 = *piVar5;
          *(int *)(iVar8 + 0xc) = iVar7;
          *(undefined1 *)(iVar8 + 10) = 1;
          if (piVar4 + iVar10 <= piVar5) break;
          iVar7 = *(int *)(*piVar5 + 0x10) + iVar9 + iVar7;
          piVar5 = piVar5 + 1;
        }
      }
      return;
    }
  }
  return;
}



/* ===== FUN_080190aa @ 080190aa ===== */

undefined8 FUN_080190aa(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  
  bVar3 = param_2 < 0;
  if (bVar3) {
    bVar4 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -param_2 - (uint)bVar4;
  }
  uVar2 = (uint)((ulonglong)param_1 * 0x7d);
  iVar1 = param_2 * 0x7d + (int)((ulonglong)param_1 * 0x7d >> 0x20) + (uint)(0xfffff7ff < uVar2);
  uVar2 = uVar2 + 0x800 >> 0xc | iVar1 * 0x100000;
  iVar1 = iVar1 >> 0xc;
  if (bVar3) {
    bVar3 = uVar2 != 0;
    uVar2 = -uVar2;
    iVar1 = -iVar1 - (uint)bVar3;
  }
  return CONCAT44(iVar1,uVar2);
}



/* ===== FUN_080190e2 @ 080190e2 ===== */

undefined8 FUN_080190e2(void)

{
  uint *puVar1;
  ushort uVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = DAT_0801974c;
  uVar4 = *DAT_08019744 & 0xffff;
  while (uVar4 != (*DAT_08019744 & 0xffff)) {
    uVar4 = *DAT_08019744 & 0xffff;
  }
  uVar2 = *DAT_08019748 + (short)uVar4;
  if (uVar2 < (ushort)*DAT_0801974c) {
    uVar4 = *DAT_0801974c;
    puVar1 = DAT_0801974c + 1;
    *DAT_0801974c = uVar4 + 0x10000;
    puVar3[1] = *puVar1 + (uint)(0xfffeffff < uVar4);
  }
  *(ushort *)puVar3 = uVar2;
  return *(undefined8 *)puVar3;
}



/* ===== FUN_08019126 @ 08019126 ===== */

undefined4
FUN_08019126(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  short *psVar5;
  short *psVar6;
  short *psVar7;
  
  iVar1 = DAT_08019754;
  uVar2 = *DAT_08019750 & 0xffff;
  if (0x80 < uVar2) {
    uVar2 = *DAT_08019750 & 0xffff;
  }
  if (uVar2 < 0x81) {
    if (uVar2 == 0) {
      uVar2 = 0x80;
    }
    psVar7 = (short *)(uVar2 * -2 + DAT_08019754 + 0x128);
    psVar5 = (short *)*param_1;
    if ((short *)*param_1 != psVar7) {
      do {
        psVar6 = psVar5 + 1;
        iVar3 = (int)*psVar5 - *(int *)(iVar1 + 0x20);
        if (-1 < iVar3) {
          iVar3 = (int)((ulonglong)((longlong)iVar3 * (longlong)DAT_08019758) >> 0x20);
          iVar3 = iVar3 - (iVar3 >> 0x1f);
          if (0x3ff < iVar3) {
            iVar3 = 0x3ff;
          }
          piVar4 = *(int **)(iVar1 + *(int *)(iVar1 + 0x1c) * 4 + 0xc);
          (**(code **)(*piVar4 + 8))(piVar4,iVar3,1);
        }
        if ((short *)(iVar1 + 0x128) <= psVar6) {
          psVar6 = (short *)(iVar1 + 0x28);
        }
        psVar5 = psVar6;
      } while (psVar6 != psVar7);
      *param_1 = psVar7;
    }
  }
  return param_4;
}



/* ===== FUN_0801919c @ 0801919c ===== */

void FUN_0801919c(void)

{
  short sVar1;
  char *pcVar2;
  uint *puVar3;
  int iVar4;
  
  puVar3 = DAT_08019760;
  pcVar2 = DAT_08019754;
  sVar1 = *DAT_0801975c;
  if (-1 < sVar1) {
    pcVar2[0x20] = '\0';
    pcVar2[0x21] = '\0';
    pcVar2[0x22] = '\0';
    pcVar2[0x23] = '\0';
    iVar4 = sVar1 + 0x2a5;
    if (0xfff < iVar4) {
      iVar4 = 0xfff;
    }
    *DAT_08019760 = (int)(short)iVar4 | *DAT_08019760 & 0xfffff000;
    return;
  }
  iVar4 = *(int *)(DAT_08019754 + 0x24);
  *(int *)(DAT_08019754 + 0x20) = iVar4;
  *puVar3 = (int)(short)((short)iVar4 + 0x2a5) | *puVar3 & 0xfffff000;
  if (*pcVar2 == '\0') {
    iVar4 = iVar4 + 1;
    if (0xff < iVar4) {
      iVar4 = 0xff;
      *pcVar2 = '\x01';
    }
  }
  else {
    iVar4 = iVar4 + -1;
    if (iVar4 < 0) {
      iVar4 = 0;
      *pcVar2 = '\0';
    }
  }
  *(int *)(pcVar2 + 0x24) = iVar4;
  return;
}



/* ===== FUN_0801920c @ 0801920c ===== */

undefined4 FUN_0801920c(void)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 in_r3;
  
  iVar5 = DAT_08019768;
  pbVar4 = DAT_08019764;
  iVar3 = DAT_08019740;
  uVar2 = DAT_0801973c;
  while (iVar6 = FUN_080259a0(uVar2), iVar6 != 0) {
    FUN_080259e0(iVar3,uVar2);
    FUN_0801b1d8(uVar2);
    FUN_08025a20(uVar2);
    if ((*(uint *)(iVar5 + 4) & 0x7ffff) >> 0x10 == 0) {
      bVar1 = *pbVar4;
      *pbVar4 = bVar1 + 1;
      if (-1 < (int)((uint)bVar1 << 0x1f)) {
        uVar7 = FUN_08025a30(*(undefined4 *)(iVar3 + 0x10),*(undefined4 *)(iVar3 + 0x14),1000,0);
        FUN_08016008(iVar3 + 0x34,0x400,uVar7);
      }
    }
    else {
      *pbVar4 = 0;
    }
  }
  *DAT_0801976c = 0;
  return in_r3;
}



/* ===== FUN_0801927e @ 0801927e ===== */

void FUN_0801927e(void)

{
  undefined1 *puVar1;
  
  puVar1 = DAT_08019754;
  *(undefined4 *)(DAT_08019754 + 0x20) = 0;
  *(undefined4 *)(puVar1 + 0x24) = 0;
  *puVar1 = 0;
  FUN_0801919c();
  *(undefined1 **)(puVar1 + 4) = puVar1 + 0x28;
  *(undefined4 *)(puVar1 + 8) = 0;
  return;
}



/* ===== thunk_FUN_0801b1be @ 080192a2 ===== */

void thunk_FUN_0801b1be(void)

{
  return;
}



/* ===== FUN_08019426 @ 08019426 ===== */

void FUN_08019426(void)

{
  char *pcVar1;
  undefined1 auStack_38 [6];
  undefined1 local_32;
  undefined1 local_31;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  pcVar1 = DAT_08019740;
  if (*DAT_08019740 != '\0') {
    local_18 = *(undefined4 *)(DAT_08019740 + 0x18);
    local_14 = *(undefined4 *)(DAT_08019740 + 0x1c);
    local_31 = 0;
    local_20 = *(undefined4 *)(DAT_08019740 + 0x10);
    local_1c = *(undefined4 *)(DAT_08019740 + 0x14);
    local_30 = *(undefined4 *)(DAT_08019740 + 8);
    local_2c = *(undefined4 *)(DAT_08019740 + 0xc);
    FUN_080190e2();
    local_28 = FUN_080190aa();
    local_32 = 2;
    local_10 = 0;
    local_c = 0;
    FUN_08025e76(0,auStack_38,pcVar1 + 0x34);
  }
  return;
}



/* ===== FUN_0801947c @ 0801947c ===== */

void FUN_0801947c(void)

{
  FUN_08019126(DAT_08019770);
  return;
}



/* ===== FUN_080194ea @ 080194ea ===== */

int FUN_080194ea(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  
  iVar2 = DAT_08019740;
  if (param_2 < 8) {
    iVar2 = 0;
  }
  else {
    uVar4 = *(uint *)(DAT_08019740 + 0x18) + *(uint *)(DAT_08019740 + 0x10);
    uVar8 = uVar4 - *(uint *)(DAT_08019740 + 0x20);
    uVar3 = FUN_08025a74(uVar8 + 500,
                         (((*(int *)(DAT_08019740 + 0x14) + *(int *)(DAT_08019740 + 0x1c) +
                           (uint)CARRY4(*(uint *)(DAT_08019740 + 0x18),
                                        *(uint *)(DAT_08019740 + 0x10))) -
                          *(int *)(DAT_08019740 + 0x24)) -
                         (uint)(uVar4 < *(uint *)(DAT_08019740 + 0x20))) +
                         (uint)(0xfffffe0b < uVar8),1000,0);
    piVar5 = (int *)(iVar2 + 0x34);
    piVar9 = (int *)(iVar2 + 0x2034);
    *param_1 = uVar3;
    piVar1 = DAT_08019778;
    piVar6 = (int *)(iVar2 + 0x1034);
    param_1[1] = 0;
    piVar7 = piVar6;
    piVar11 = piVar1;
    if ((int *)(iVar2 + 0x34U) < piVar6) {
      for (; piVar5 < piVar6; piVar5 = piVar5 + 1) {
        iVar2 = *piVar5;
        iVar10 = *piVar7;
        *piVar11 = (iVar2 + iVar10) - *piVar9;
        *piVar9 = iVar2 + iVar10;
        piVar7 = piVar7 + 1;
        piVar9 = piVar9 + 1;
        piVar11 = piVar11 + 1;
      }
    }
    iVar2 = FUN_0802667c(param_1 + 2,piVar1,0x400);
    if (iVar2 == 0) {
      iVar2 = -1;
    }
    else {
      iVar2 = (iVar2 - (int)(param_1 + 2)) + 8;
    }
  }
  return iVar2;
}



/* ===== FUN_08019704 @ 08019704 ===== */

void FUN_08019704(void)

{
  undefined2 uVar1;
  undefined8 uVar2;
  
  FUN_08025f80(DAT_08019740);
  uVar1 = FUN_0801862e();
  uVar2 = FUN_080190e2();
  FUN_08018a4c((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),uVar1,0x13);
  return;
}



/* ===== FUN_08019722 @ 08019722 ===== */

int FUN_08019722(void)

{
  return (int)**(short **)(*(int *)(DAT_08019754 + *(int *)(DAT_08019754 + 0x1c) * 4 + 0xc) + 4);
}



/* ===== FUN_08019780 @ 08019780 ===== */

void FUN_08019780(char param_1,char param_2)

{
  byte bVar1;
  int *piVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  
  piVar2 = DAT_080197c4;
  pbVar5 = (byte *)*DAT_080197c4;
  bVar4 = *pbVar5;
  bVar1 = pbVar5[1];
  bVar3 = bVar4 + param_1;
  if ((byte)(bVar4 + param_1) < bVar4) {
    bVar3 = bVar4;
  }
  if (pbVar5[2] < bVar3) {
    bVar3 = pbVar5[2];
  }
  bVar4 = bVar1 + param_2;
  if ((byte)(bVar1 + param_2) < bVar1) {
    bVar4 = bVar1;
  }
  pbVar5[6] = bVar3;
  if (pbVar5[3] < bVar4) {
    bVar4 = pbVar5[3];
  }
  *(byte *)(*piVar2 + 7) = bVar4;
  *(byte *)(*piVar2 + 4) = bVar3;
  *(byte *)(*piVar2 + 5) = bVar4;
  return;
}



/* ===== FUN_080197c8 @ 080197c8 ===== */

undefined2 FUN_080197c8(undefined2 param_1)

{
  undefined2 uVar1;
  
  uVar1 = *(undefined2 *)(*DAT_080197d4 + 0x10);
  *(undefined2 *)(*DAT_080197d4 + 0x10) = param_1;
  return uVar1;
}



/* ===== FUN_080197d8 @ 080197d8 ===== */

undefined4 FUN_080197d8(int *param_1)

{
  char cVar1;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  short sVar11;
  bool bVar12;
  
  piVar2 = DAT_08019d80;
  iVar5 = DAT_08019d7c;
  sVar11 = 0;
  puVar3 = (uint *)param_1[2];
  if (puVar3 != (uint *)0x0) {
    cVar1 = *(char *)(DAT_08019d7c + 0x7b);
    if (cVar1 == '\0') {
      uVar6 = (uint)(byte)*puVar3;
    }
    else {
      uVar6 = *puVar3;
    }
    if (uVar6 != 0) {
      puVar7 = (undefined1 *)*DAT_08019d80;
      uVar6 = (uint)*(ushort *)(puVar7 + 0x10);
      if ((int)(uVar6 << 0x1c) < 0) {
        if (cVar1 == '\0') goto LAB_08019814;
        do {
          uVar6 = *puVar3;
          while( true ) {
            if ((uVar6 != 0x20 && uVar6 != 9) && uVar6 != 0xd) goto LAB_08019838;
            if (cVar1 != '\0') break;
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_08019814:
            uVar6 = (uint)(byte)*puVar3;
          }
          puVar3 = puVar3 + 1;
        } while( true );
      }
      bVar12 = (uVar6 & 0xc) != 4;
      if (bVar12) {
        uVar6 = uVar6 & 0x30;
      }
      if (!bVar12 || uVar6 == 0x20) {
LAB_08019838:
        puVar7[4] = *puVar7;
      }
      *param_1 = (int)puVar3;
      param_1[1] = (int)puVar3;
      iVar10 = 0;
      *(undefined2 *)(param_1 + 3) = 0;
      bVar12 = true;
LAB_08019862:
      if (*(char *)(iVar5 + 0x7b) == '\0') {
        uVar6 = (uint)(byte)*puVar3;
      }
      else {
        uVar6 = *puVar3;
      }
      if (uVar6 == 0 || uVar6 == 10) goto LAB_08019928;
      if (uVar6 == 0xd) {
        puVar7 = (undefined1 *)*piVar2;
        if ((puVar7[0x10] & 0xc) != 0) {
LAB_080198a0:
          uVar6 = 0x20;
LAB_080198ca:
          iVar10 = param_1[1];
          sVar11 = (short)param_1[3];
          goto LAB_080198d2;
        }
        if (!bVar12) goto LAB_08019928;
        puVar7[4] = *puVar7;
      }
      else {
        if (uVar6 == 9) {
          if ((*(byte *)(*piVar2 + 0x10) & 0xc) != 0) goto LAB_080198a0;
          sVar11 = (short)param_1[3];
          iVar10 = param_1[1];
          iVar9 = FUN_0802689e(sVar11 + (ushort)*(byte *)(*piVar2 + 4) & 0xff);
          uVar6 = (iVar9 - (uint)*(byte *)(*piVar2 + 4)) - (uint)*(ushort *)(param_1 + 3) & 0xffff;
        }
        else {
          if (uVar6 == 0x20) goto LAB_080198ca;
LAB_080198d2:
          uVar6 = FUN_08026a38(uVar6);
        }
        pbVar8 = (byte *)*piVar2;
        uVar4 = (uint)pbVar8[2];
        if ((uVar4 - *pbVar8) + 1 <= uVar6) {
          *(ushort *)(param_1 + 3) = ((ushort)pbVar8[2] - (ushort)*pbVar8) + 1;
          if (*(char *)(iVar5 + 0x7b) == '\0') {
            puVar3 = (uint *)((int)puVar3 + 1);
          }
          else {
            puVar3 = puVar3 + 1;
          }
          goto LAB_08019928;
        }
        if ((int)((uint)*(ushort *)(pbVar8 + 0x10) << 0x16) < 0) {
          if ((*(ushort *)(pbVar8 + 0x10) & 0xc) == 8) {
            iVar9 = uVar6 - 1;
          }
          else {
            iVar9 = 0;
          }
          if (uVar4 < iVar9 + (uint)pbVar8[4] + (uint)*(ushort *)(param_1 + 3)) goto LAB_08019928;
        }
        else if (uVar4 < (uVar6 + *(ushort *)(param_1 + 3) + (uint)pbVar8[4]) - 1) {
          if ((iVar10 == 0) || ((pbVar8[0x10] & 0xc0) != 0x40)) goto LAB_08019928;
          param_1[1] = iVar10;
          *(short *)(param_1 + 3) = sVar11;
          if (sVar11 == 0) {
            iVar9 = iVar10;
            if (*(char *)(iVar5 + 0x7b) != '\0') goto LAB_0801997e;
          }
          else {
            if (*(char *)(iVar5 + 0x7b) != '\0') {
              iVar9 = iVar10 + 4;
LAB_0801997e:
              puVar3 = (uint *)(iVar9 + 4);
LAB_08019928:
              param_1[2] = (int)puVar3;
              cVar1 = *(char *)(iVar5 + 0x7b);
              if (cVar1 == '\0') {
                uVar6 = (uint)(byte)*(uint *)*param_1;
              }
              else {
                uVar6 = *(uint *)*param_1;
              }
              if (uVar6 != 0) {
                if (cVar1 == '\0') {
                  uVar6 = (uint)(byte)*puVar3;
                }
                else {
                  uVar6 = *puVar3;
                }
                if ((uVar6 != 0) || ((*(byte *)(*piVar2 + 0x10) & 0xc) == 0xc)) {
                  if (cVar1 == '\0') {
                    uVar6 = (uint)(byte)*(uint *)param_1[1];
                  }
                  else {
                    uVar6 = *(uint *)param_1[1];
                  }
                  if (uVar6 == 0x20 || uVar6 == 9) {
                    if (param_1[1] != *param_1 && iVar10 != 0) {
                      param_1[1] = iVar10;
                      *(short *)(param_1 + 3) = sVar11;
                    }
                  }
                }
                if (cVar1 == '\0') goto LAB_080199e0;
LAB_080199c4:
                uVar6 = *(uint *)param_1[2];
                do {
                  if (-1 < (int)((uint)*(byte *)(*piVar2 + 0x10) << 0x18)) {
                    if (uVar6 == 0) {
                      return 1;
                    }
                    if (uVar6 == 0xd) {
                      return 2;
                    }
                    if (uVar6 != 10 && uVar6 != 9) {
                      return 3;
                    }
LAB_08019a04:
                    if (cVar1 == '\0') {
                      iVar5 = param_1[2] + 1;
                    }
                    else {
                      iVar5 = param_1[2] + 4;
                    }
                    param_1[2] = iVar5;
                    return 3;
                  }
                  if (uVar6 == 0) {
                    return 1;
                  }
                  if (uVar6 == 10) goto LAB_08019a04;
                  if (cVar1 != '\0') goto code_r0x080199d6;
                  param_1[2] = param_1[2] + 1;
LAB_080199e0:
                  uVar6 = (uint)*(byte *)param_1[2];
                } while( true );
              }
              goto LAB_08019984;
            }
            iVar9 = iVar10 + 1;
          }
          puVar3 = (uint *)(iVar9 + 1);
          goto LAB_08019928;
        }
        *(short *)(param_1 + 3) = (short)uVar6 + (short)param_1[3];
      }
      param_1[1] = (int)puVar3;
      if (*(char *)(iVar5 + 0x7b) == '\0') {
        puVar3 = (uint *)((int)puVar3 + 1);
      }
      else {
        puVar3 = puVar3 + 1;
      }
      bVar12 = false;
      goto LAB_08019862;
    }
  }
LAB_08019984:
  return 0;
code_r0x080199d6:
  param_1[2] = param_1[2] + 4;
  goto LAB_080199c4;
}



/* ===== FUN_08019a16 @ 08019a16 ===== */

undefined4 FUN_08019a16(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  ushort uVar2;
  char cVar3;
  int *piVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  byte bVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  char cVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  bool bVar19;
  
  if (param_1[2] != 0) {
    FUN_08026858();
    piVar4 = DAT_08019d80;
    uVar6 = FUN_08026a50(*(undefined4 *)(*DAT_08019d80 + 0xc));
    pcVar5 = DAT_08019d84;
    if (uVar6 != 0) {
      iVar11 = *piVar4;
      uVar2 = *(ushort *)(iVar11 + 0x10);
      bVar19 = (uVar2 & 0x8001) != 0x8000;
      uVar17 = ((uint)*(byte *)(iVar11 + 3) - (uint)*(byte *)(iVar11 + 1)) + 1 & 0xff;
      if ((*DAT_08019d84 == '\0') || ((int)uVar6 <= (int)uVar17)) {
        cVar3 = (char)uVar6;
        if ((uVar2 & 0x30) == 0x30 || (uVar2 & 0x30) == 0x20) {
          uVar16 = (uint)*(byte *)(iVar11 + 4);
          uVar18 = 0;
          iVar11 = param_1[2];
          while( true ) {
            uVar7 = FUN_080197d8(param_1);
            if (uVar7 < 2) break;
            ((undefined1 *)*piVar4)[4] = *(undefined1 *)*piVar4;
            if (uVar7 == 3) {
              uVar18 = uVar18 + 1;
            }
          }
          param_1[2] = iVar11;
          if (uVar7 == 1) {
            uVar18 = uVar18 + 1;
          }
          *(char *)(*piVar4 + 4) = (char)uVar16;
          iVar15 = (uVar18 & 0xffff) * uVar6;
          iVar11 = *piVar4;
          if ((*(byte *)(iVar11 + 0x10) & 0x30) == 0x30) {
            *(char *)(iVar11 + 5) = *(char *)(iVar11 + 1) + cVar3 + -1;
            if (iVar15 < (int)uVar17) {
              *(char *)(*piVar4 + 5) =
                   *(char *)(*piVar4 + 5) + (char)((uVar17 - uVar6 * uVar18 & 0xff) >> 1);
            }
          }
          else if ((int)uVar17 < iVar15) {
            *(char *)(iVar11 + 5) =
                 ((char)(uVar17 - 1) + *(char *)(iVar11 + 1)) - cVar3 * (char)((uVar17 - 1) / uVar6)
            ;
            if (*pcVar5 == '\0') {
              uVar17 = ((uVar17 + uVar6) - 1) / uVar6;
            }
            else {
              uVar17 = (int)uVar17 / (int)uVar6;
              *(char *)(*piVar4 + 5) = *(char *)(*piVar4 + 5) + cVar3;
            }
            for (uVar18 = uVar18 - uVar17; (uVar18 & 0xffff) != 0; uVar18 = uVar18 - 1) {
              FUN_080197d8(param_1);
            }
          }
          else {
            *(char *)(iVar11 + 5) = *(char *)(iVar11 + 3) - cVar3 * ((char)uVar18 + -1);
          }
        }
        else if ((uVar2 & 0x30) == 0x10) {
          *(byte *)(iVar11 + 5) = *(byte *)(iVar11 + 1) + cVar3 + -1;
        }
        iVar11 = FUN_080197d8(param_1);
        puVar8 = (undefined1 *)*piVar4;
        if ((((int)((uint)*(ushort *)(puVar8 + 0x10) << 0x15) < 0) &&
            ((int)uVar6 <= (int)(uint)(byte)puVar8[5])) && (bVar19)) {
          if ((int)((uint)*(ushort *)(puVar8 + 0x10) << 0x1f) < 0) {
            uVar12 = 0xffff;
          }
          else {
            uVar12 = 0;
          }
          FUN_08026a64(*puVar8,puVar8[1],puVar8[2],(byte)puVar8[5] - uVar6 & 0xff,uVar12);
        }
        if (iVar11 == 0) {
          puVar8 = (undefined1 *)*piVar4;
          uVar17 = (uint)*(ushort *)(puVar8 + 0x10);
          if (((*(ushort *)(puVar8 + 0x10) & 0x3000) != 0) && (bVar19)) {
            uVar18 = (uint)(byte)puVar8[5];
            if ((int)(uVar17 << 0x1f) < 0) {
              uVar12 = 0xffff;
            }
            else {
              uVar12 = 0;
            }
            uVar16 = (uint)(byte)puVar8[3];
            if (uVar18 <= (byte)puVar8[3]) {
              uVar16 = uVar18;
            }
            if ((int)(uVar17 << 0x12) < 0) {
              cVar14 = puVar8[2];
            }
            else {
              cVar14 = puVar8[4] + -1;
            }
            bVar10 = puVar8[1];
            if ((int)(uVar6 + bVar10) <= (int)uVar18) {
              bVar10 = (puVar8[5] - cVar3) + 1;
            }
            if ((int)(uVar17 << 0x13) < 0) {
              uVar1 = *puVar8;
            }
            else {
              uVar1 = puVar8[4];
            }
            FUN_08026a64(uVar1,bVar10,cVar14,uVar16,uVar12);
          }
LAB_08019cca:
          puVar8 = (undefined1 *)*piVar4;
          if ((int)((uint)*(ushort *)(puVar8 + 0x10) << 0x14) < 0) {
            if (((byte)puVar8[5] < (byte)puVar8[3]) && (bVar19)) {
              if ((int)((uint)*(ushort *)(puVar8 + 0x10) << 0x1f) < 0) {
                uVar12 = 0xffff;
              }
              else {
                uVar12 = 0;
              }
              FUN_08026a64(*puVar8,puVar8[5] + 1,puVar8[2],puVar8[3],uVar12);
            }
          }
          piVar4 = DAT_080269bc;
          iVar11 = *DAT_080269bc;
          if (*(byte *)(iVar11 + 2) < *(byte *)(iVar11 + 4)) {
            *(byte *)(iVar11 + 4) = *(byte *)(iVar11 + 2);
          }
          iVar11 = *piVar4;
          if (*(byte *)(iVar11 + 3) < *(byte *)(iVar11 + 5)) {
            *(byte *)(iVar11 + 5) = *(byte *)(iVar11 + 3);
          }
          *(undefined1 *)(*piVar4 + 6) = *(undefined1 *)(*piVar4 + 4);
          *(undefined1 *)(*piVar4 + 7) = *(undefined1 *)(*piVar4 + 5);
          uVar12 = FUN_0802ad48();
          return uVar12;
        }
LAB_08019b84:
        pbVar9 = (byte *)*piVar4;
        if ((*(ushort *)(pbVar9 + 0x10) & 0xc) == 0xc) {
          bVar10 = *pbVar9;
          uVar17 = ((uint)pbVar9[2] - (uint)bVar10) + 1;
          if (*(ushort *)(param_1 + 3) < uVar17) {
            bVar10 = bVar10 + (char)(uVar17 - *(ushort *)(param_1 + 3) >> 1);
          }
        }
        else {
          if ((*(ushort *)(pbVar9 + 0x10) & 0xc) != 8) goto LAB_08019bc8;
          bVar10 = *pbVar9;
          if ((uint)*(ushort *)(param_1 + 3) < ((uint)pbVar9[2] - (uint)bVar10) + 1) {
            bVar10 = (pbVar9[2] + 1) - (char)*(ushort *)(param_1 + 3);
          }
        }
        pbVar9[4] = bVar10;
LAB_08019bc8:
        pbVar9 = (byte *)*piVar4;
        if ((int)((uint)*(ushort *)(pbVar9 + 0x10) << 0x13) < 0) {
          if ((*pbVar9 < pbVar9[4]) && (bVar19)) {
            uVar17 = (uint)pbVar9[5];
            bVar10 = pbVar9[1];
            if ((int)((uint)*(ushort *)(pbVar9 + 0x10) << 0x1f) < 0) {
              uVar12 = 0xffff;
            }
            else {
              uVar12 = 0;
            }
            uVar18 = (uint)pbVar9[3];
            if (uVar17 <= pbVar9[3]) {
              uVar18 = uVar17;
            }
            if ((int)(uVar6 + bVar10) <= (int)uVar17) {
              bVar10 = (pbVar9[5] - cVar3) + 1;
            }
            FUN_08026a64(*pbVar9,bVar10,pbVar9[4] - 1,uVar18,uVar12);
          }
        }
        iVar15 = DAT_08019d7c;
        if (*(char *)(DAT_08019d7c + 0x7b) == '\0') goto LAB_08019c3e;
        do {
          uVar17 = *(uint *)*param_1;
          while( true ) {
            if (((*(byte *)(*piVar4 + 0x10) & 0xc) != 0) && (uVar17 == 0xd || uVar17 == 9)) {
              uVar17 = 0x20;
            }
            FUN_080268c2(uVar17);
            iVar13 = *param_1;
            if (iVar13 == param_1[1]) {
              iVar15 = *piVar4;
              if ((int)((uint)*(ushort *)(iVar15 + 0x10) << 0x12) < 0) {
                if ((*(byte *)(iVar15 + 4) <= *(byte *)(iVar15 + 2)) && (bVar19)) {
                  uVar17 = (uint)*(byte *)(iVar15 + 5);
                  bVar10 = *(byte *)(iVar15 + 1);
                  if ((int)((uint)*(ushort *)(iVar15 + 0x10) << 0x1f) < 0) {
                    uVar12 = 0xffff;
                  }
                  else {
                    uVar12 = 0;
                  }
                  uVar18 = (uint)*(byte *)(iVar15 + 3);
                  if (uVar17 <= *(byte *)(iVar15 + 3)) {
                    uVar18 = uVar17;
                  }
                  if ((int)(uVar6 + bVar10) <= (int)uVar17) {
                    bVar10 = (*(byte *)(iVar15 + 5) - cVar3) + 1;
                  }
                  FUN_08026a64(*(byte *)(iVar15 + 4),bVar10,*(byte *)(iVar15 + 2),uVar18,uVar12);
                }
              }
              if (((iVar11 == 3) && (iVar11 = FUN_080267dc(uVar6), iVar11 != 0)) ||
                 (iVar11 = FUN_080197d8(param_1), iVar11 == 0)) goto LAB_08019cca;
              goto LAB_08019b84;
            }
            if (*(char *)(iVar15 + 0x7b) != '\0') break;
            *param_1 = iVar13 + 1;
LAB_08019c3e:
            uVar17 = (uint)*(byte *)*param_1;
          }
          *param_1 = iVar13 + 4;
        } while( true );
      }
    }
  }
  return param_4;
}



/* ===== FUN_08019d56 @ 08019d56 ===== */

void FUN_08019d56(undefined4 param_1)

{
  undefined1 auStack_18 [8];
  undefined4 local_10;
  
  *(undefined1 *)(DAT_08019d7c + 0x7b) = 0;
  local_10 = param_1;
  FUN_08019a16(auStack_18);
  return;
}



/* ===== FUN_08019d62 @ 08019d62 ===== */

void FUN_08019d62(undefined4 param_1)

{
  undefined1 auStack_18 [8];
  undefined4 local_10;
  
  *(undefined1 *)(DAT_08019d7c + 0x7b) = 1;
  local_10 = param_1;
  FUN_08019a16(auStack_18);
  return;
}



/* ===== FUN_08019d88 @ 08019d88 ===== */

longlong FUN_08019d88(int param_1)

{
  uint unaff_r7;
  
  if (param_1 == 0) {
    FUN_080231c0();
  }
  else {
    FUN_080231a8();
  }
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08019d9c @ 08019d9c ===== */

void FUN_08019d9c(void)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  puVar2 = DAT_0801a148;
  *DAT_0801a148 = 0;
  iVar3 = DAT_0801a14c;
  bVar1 = *(byte *)(DAT_0801a14c + 0x1a);
  if (bVar1 != 0) {
    if ((int)((uint)bVar1 << 0x18) < 0) {
      FUN_08016ace(bVar1 & 0x7f);
    }
    else {
      FUN_080231c0();
      FUN_080231a8();
    }
    *(undefined1 *)(iVar3 + 0x1a) = 0;
    return;
  }
  if (((*(char *)(DAT_0801a14c + 0x18) == '\0') || (iVar5 = FUN_0802322e(), iVar5 != 0)) ||
     (iVar5 = FUN_0802327e(), iVar5 != 0)) {
    return;
  }
  if (*(char *)(iVar3 + 0x18) != '\x05') {
    FUN_0802705a();
    FUN_08027738(DAT_0801a158);
    FUN_08029514();
    if ((*(char *)(iVar3 + 0xd) == '\x01') && (*(char *)(DAT_0801a15c + 0xb) != '\x01')) {
      FUN_08019fe6();
    }
    if (*DAT_0801a160 << 0x12 < 0) {
      *puVar2 = 1;
      return;
    }
    return;
  }
  local_20 = 0;
  local_30 = 0;
  local_24 = 0;
  local_28 = 0;
  local_2c = 0;
  local_34 = 0;
  local_38 = 0;
  iVar5 = FUN_08026c44(0,400,0x1e0);
  if (iVar5 == 0) {
    local_34._0_2_ = CONCAT11(9,(undefined1)local_34);
    FUN_0802498c((int)&local_34 + 2,"RadiaCode-110",0xd);
    local_28 = CONCAT13(0x23,(undefined3)local_28);
    piVar6 = (int *)FUN_0801f648();
    if (*piVar6 == 0) {
      iVar5 = FUN_08026e28(&local_24,"RC-110-%06.6X",*DAT_0801a150);
    }
    else {
      iVar5 = piVar6[1];
      FUN_0802498c(&local_24,*piVar6,iVar5);
    }
    local_34 = CONCAT31(local_34._1_3_,(char)(iVar5 + 0x10U) + -1);
    iVar7 = FUN_08026dda(10);
    if (iVar7 == 0) {
      iVar7 = FUN_08026ed8(iVar5 + 0x10U & 0xff,&local_34);
    }
    if (iVar7 != 0) goto LAB_08019ed8;
    FUN_080249ac(&local_34,&DAT_0801a1b8,3);
    uVar4 = local_30;
    local_34._3_1_ = '\x03';
    local_30._3_1_ = SUB41(uVar4,3);
    local_30._0_3_ = CONCAT12(DAT_0801a1bd,CONCAT11(DAT_0801a1bc,0xff));
    local_38 = *(uint *)(iVar3 + 0x10) & 0xfffff;
    FUN_0802498c((int)&local_30 + 3,&local_38,3);
    local_34 = CONCAT13(local_34._3_1_ + '\x03',(undefined3)local_34);
    local_2c = CONCAT13(7,CONCAT12(0x11,(undefined2)local_2c));
    FUN_0802498c(&local_28,DAT_0801a154,0x10);
    iVar5 = FUN_08026f2a(0x1c,&local_34);
  }
  if (iVar5 == 0) {
    *(undefined1 *)(iVar3 + 0x18) = 6;
    return;
  }
LAB_08019ed8:
  *(undefined1 *)(iVar3 + 0x18) = 0;
  *puVar2 = 1;
  if (*(char *)(iVar3 + 0x1a) == '\0') {
    *(undefined1 *)(iVar3 + 0x1a) = 2;
  }
  FUN_080187dc("BLE: error #0x%0.2X!",2);
  return;
}



/* ===== FUN_08019f26 @ 08019f26 ===== */

uint FUN_08019f26(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = DAT_0801a14c;
  if (param_1 == 1) {
    FUN_08029718();
    *(undefined1 *)(iVar2 + 0x19) = 100;
  }
  else {
    *(undefined1 *)(DAT_0801a14c + 0x19) = 0x32;
  }
  puVar3 = DAT_0801a164;
  puVar1 = DAT_0801a148;
  *(undefined1 *)(iVar2 + 0x18) = 0;
  *puVar1 = 0;
  puVar1 = DAT_0801a168;
  DAT_0801a168[4] = 4;
  *puVar3 = *puVar3 & 0xffffdfff;
  puVar3[5] = 0x2000;
  *puVar3 = *puVar3 | 0x2000;
  do {
  } while ((uint)(*DAT_0801a16c - *DAT_0801a16c) < 5000);
  *puVar1 = 4;
  FUN_08027036();
  FUN_080294c8();
  *(undefined1 *)(iVar2 + 0xd) = 0;
  puVar3 = DAT_0801a170;
  *DAT_0801a170 = *DAT_0801a170 | 0x8000;
  return *puVar3 & 0x8000;
}



/* ===== FUN_08019fc2 @ 08019fc2 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08019fc2(undefined4 param_1,undefined1 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  FUN_080294c8();
  iVar2 = DAT_0801a14c;
  *(undefined1 *)(DAT_0801a14c + 0xd) = 0;
  *(undefined1 *)(iVar2 + 0xc) = param_2;
  FUN_080297d4();
  puVar1 = DAT_0801a148;
  *(undefined1 *)(iVar2 + 0x18) = 0;
  *puVar1 = 0;
  if (*DAT_08023328 == '\0') {
    uVar3 = 0x4000;
  }
  else {
    uVar3 = 0x50000;
  }
  FUN_08016890(_DAT_0802334c,uVar3);
  return;
}



/* ===== FUN_08019fe6 @ 08019fe6 ===== */

undefined4 FUN_08019fe6(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 in_r3;
  
  iVar1 = DAT_0801a14c;
  iVar2 = FUN_08029878(*(undefined2 *)(DAT_0801a14c + 4),6,10,0);
  if (iVar2 == 0) {
    *(undefined1 *)(iVar1 + 0xd) = 2;
    return 500;
  }
  FUN_08023160(0x41,500,in_r3);
  uVar3 = FUN_08018826(DAT_08023340,0x41,*(undefined2 *)(DAT_0802333c + 6));
  return uVar3;
}



/* ===== FUN_0801a00e @ 0801a00e ===== */

ushort FUN_0801a00e(void)

{
  ushort uVar1;
  int iVar2;
  undefined1 uStack_c;
  undefined1 uStack_b;
  ushort local_a;
  short local_8;
  undefined1 auStack_6 [2];
  
  iVar2 = FUN_08026e68(&uStack_b,&local_8,&uStack_c,auStack_6,&local_a);
  if (iVar2 == 0) {
    uVar1 = local_a & 0xff | local_8 << 8;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* ===== FUN_0801a062 @ 0801a062 ===== */

undefined4 FUN_0801a062(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 in_r3;
  undefined1 auStack_14 [2];
  undefined1 auStack_12 [2];
  undefined1 auStack_10 [4];
  undefined4 uStack_c;
  
  uStack_c = in_r3;
  piVar2 = (int *)FUN_0801f648();
  iVar1 = DAT_0801a14c;
  if (*piVar2 == 0) {
    FUN_080249ac(DAT_0801a14c + 0x10,DAT_0801a150,6);
  }
  else {
    iVar3 = FUN_0801f648();
    iVar4 = 0;
    if (*(char *)(iVar3 + 0xf) != '\0') {
      iVar4 = 0x32;
    }
    *(uint *)(iVar1 + 0x10) =
         *(uint *)(iVar3 + 8) & 0xfffff | (iVar4 + (uint)*(ushort *)(iVar3 + 0x10)) * 0x100000;
    *(undefined1 *)(iVar1 + 0x14) = *(undefined1 *)(iVar3 + 0xd);
    *(undefined1 *)(iVar1 + 0x15) = *(undefined1 *)(iVar3 + 0xc);
  }
  iVar4 = FUN_080298d6(0,6,iVar1 + 0x10);
  if (iVar4 != 0) {
    return 1;
  }
  iVar4 = FUN_08029ae2();
  if (iVar4 != 0) {
    return 2;
  }
  iVar4 = FUN_08026d62(1,0,7,auStack_10,auStack_12,auStack_14);
  if (iVar4 != 0) {
    return 3;
  }
  iVar4 = FUN_08026cea(1,1,0,0,7,0x10,0,DAT_0801a178,0);
  if (iVar4 != 0) {
    return 4;
  }
  iVar4 = (*(code *)**(undefined4 **)(iVar1 + 0x20))();
  if (iVar4 != 0) {
    return 5;
  }
  iVar4 = FUN_08029934(1,7);
  if (iVar4 != 0) {
    return 6;
  }
  iVar4 = FUN_0801a00e();
  *(short *)(iVar1 + 0x1c) = (short)iVar4;
  if (iVar4 == 0) {
    return 7;
  }
  FUN_0801d224((*(uint *)(DAT_0801a17c + 0x58) & 0x7fff) >> 0xd);
  *(undefined1 *)(iVar1 + 0x18) = 5;
  return 0;
}



/* ===== FUN_0801a1be @ 0801a1be ===== */

void FUN_0801a1be(int param_1)

{
  *(undefined1 *)(param_1 + 10) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x14) = 1;
  return;
}



/* ===== FUN_0801a1c8 @ 0801a1c8 ===== */

void FUN_0801a1c8(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)(DAT_0801a1f8 + *(char *)(param_1 + 0x17) * 4 + 0x28);
  piVar2 = piVar1 + *(char *)(param_1 + 0x16);
  if (piVar1 < piVar2) {
    for (; piVar1 < piVar2; piVar1 = piVar1 + 1) {
      *(undefined1 *)(*piVar1 + 10) = 1;
    }
  }
  *(undefined1 *)(param_1 + 0x14) = 1;
  return;
}



/* ===== FUN_0801a1fc @ 0801a1fc ===== */

undefined4 * FUN_0801a1fc(undefined4 *param_1)

{
  FUN_080258ac(param_1,0xf);
  *param_1 = DAT_0801a210;
  return param_1;
}



/* ===== FUN_0801a214 @ 0801a214 ===== */

undefined4 * FUN_0801a214(undefined4 *param_1)

{
  FUN_080258ac(param_1,0x10);
  *param_1 = DAT_0801a228;
  return param_1;
}



/* ===== FUN_0801a22c @ 0801a22c ===== */

undefined4 * FUN_0801a22c(undefined4 *param_1)

{
  FUN_080258ac(param_1,0xf);
  *param_1 = DAT_0801a240;
  return param_1;
}



/* ===== FUN_0801a244 @ 0801a244 ===== */

undefined4 * FUN_0801a244(undefined4 *param_1)

{
  FUN_080258ac(param_1,0xf);
  *param_1 = DAT_0801a258;
  return param_1;
}



/* ===== FUN_0801a25c @ 0801a25c ===== */

undefined4 * FUN_0801a25c(undefined4 *param_1)

{
  FUN_080258ac(param_1,0xf);
  *param_1 = DAT_0801a270;
  return param_1;
}



/* ===== FUN_0801a274 @ 0801a274 ===== */

undefined4 * FUN_0801a274(undefined4 *param_1)

{
  FUN_080258ac(param_1,0xf);
  *param_1 = DAT_0801a288;
  return param_1;
}



/* ===== FUN_0801a28c @ 0801a28c ===== */

undefined4 * FUN_0801a28c(undefined4 *param_1)

{
  FUN_080258ac(param_1,0xf);
  *param_1 = DAT_0801a2a0;
  return param_1;
}



/* ===== FUN_0801a2a4 @ 0801a2a4 ===== */

undefined4 * FUN_0801a2a4(undefined4 *param_1)

{
  FUN_080258ac(param_1,0xf);
  *param_1 = DAT_0801a2b8;
  return param_1;
}



/* ===== FUN_0801a2bc @ 0801a2bc ===== */

void FUN_0801a2bc(int *param_1,int *param_2)

{
  int iVar1;
  
  do {
    iVar1 = *param_2;
    *param_1 = iVar1;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  } while (iVar1 != 0);
  return;
}



/* ===== FUN_0801a2cc @ 0801a2cc ===== */

undefined4 * FUN_0801a2cc(undefined4 *param_1)

{
  FUN_080258ac(param_1,0xf);
  *param_1 = DAT_0801a2e0;
  return param_1;
}



/* ===== FUN_0801a2e4 @ 0801a2e4 ===== */

undefined4 * FUN_0801a2e4(undefined4 *param_1)

{
  FUN_080258ac(param_1,0xf);
  *param_1 = DAT_0801a2f8;
  return param_1;
}



/* ===== FUN_0801a2fc @ 0801a2fc ===== */

undefined4 * FUN_0801a2fc(undefined4 *param_1)

{
  FUN_080258ac(param_1,0x10);
  *param_1 = DAT_0801a310;
  return param_1;
}



/* ===== FUN_0801a32a @ 0801a32a ===== */

undefined8 FUN_0801a32a(void)

{
  uint *puVar1;
  ushort uVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = DAT_0801b0cc;
  uVar4 = *DAT_0801af90 & 0xffff;
  while (uVar4 != (*DAT_0801af90 & 0xffff)) {
    uVar4 = *DAT_0801af90 & 0xffff;
  }
  uVar2 = *DAT_0801af94 + (short)uVar4;
  if (uVar2 < (ushort)*DAT_0801b0cc) {
    uVar4 = *DAT_0801b0cc;
    puVar1 = DAT_0801b0cc + 1;
    *DAT_0801b0cc = uVar4 + 0x10000;
    puVar3[1] = *puVar1 + (uint)(0xfffeffff < uVar4);
  }
  *(ushort *)puVar3 = uVar2;
  return *(undefined8 *)puVar3;
}



/* ===== FUN_0801a36e @ 0801a36e ===== */

float FUN_0801a36e(float *param_1,uint param_2)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  if (param_2 < 0x33) {
    fVar1 = param_1[param_2 * 2 + 3];
  }
  else {
    fVar2 = (float)VectorUnsignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
    fVar1 = (float)FUN_08029d88(fVar2);
    fVar1 = (fVar2 - *param_1 * fVar1) + param_1[1];
  }
  return fVar1;
}



/* ===== FUN_0801a3a2 @ 0801a3a2 ===== */

float FUN_0801a3a2(float *param_1,uint param_2)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  if (param_2 < 0x33) {
    fVar1 = param_1[param_2 * 2 + 4];
  }
  else {
    fVar2 = (float)VectorUnsignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
    fVar1 = (float)FUN_08029d88(fVar2);
    fVar1 = fVar2 + *param_1 * fVar1 + param_1[2];
  }
  return fVar1;
}



/* ===== FUN_0801a3de @ 0801a3de ===== */

void FUN_0801a3de(int *param_1)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  undefined8 local_20;
  int local_16;
  ushort local_12;
  uint uStack_10;
  
  iVar1 = DAT_0801b0d0;
  uStack_10 = *(int *)(DAT_0801b0d0 + 0x20) - *param_1;
  if (uStack_10 < 10) {
    return;
  }
  iVar3 = *(int *)(DAT_0801b0d0 + 0x20);
  *param_1 = iVar3;
  param_1[1] = *(int *)(iVar1 + 0x28);
  uVar2 = FUN_0801862e();
  local_20 = FUN_0801a32a();
  local_12 = uVar2 & 0xf303 | 0x1000;
  local_16 = iVar3;
  FUN_08018958(&local_20);
  return;
}



/* ===== FUN_0801a42e @ 0801a42e ===== */

bool FUN_0801a42e(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint in_fpscr;
  float fVar3;
  float fVar4;
  float fVar5;
  
  iVar2 = *param_1;
  iVar1 = *param_2;
  if ((uint)(iVar1 * param_1[6]) < (uint)(iVar2 * param_2[6])) {
    fVar3 = (float)FUN_0801a36e(param_3,iVar2);
    fVar4 = (float)VectorSignedToFloat(param_2[6],(byte)(in_fpscr >> 0x16) & 3);
    fVar4 = fVar4 * fVar3;
    fVar3 = (float)FUN_0801a3a2(param_3,iVar1);
    iVar1 = param_1[6];
  }
  else {
    fVar3 = (float)FUN_0801a36e(param_3,iVar1);
    fVar4 = (float)VectorSignedToFloat(param_1[6],(byte)(in_fpscr >> 0x16) & 3);
    fVar4 = fVar4 * fVar3;
    fVar3 = (float)FUN_0801a3a2(param_3,iVar2);
    iVar1 = param_2[6];
  }
  fVar5 = (float)VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
  return fVar4 < fVar5 * fVar3;
}



/* ===== FUN_0801a4ac @ 0801a4ac ===== */

void FUN_0801a4ac(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = DAT_0801b1e8;
  piVar1 = DAT_0801b0c8;
  uVar3 = *(uint *)(param_1 + 0x30);
  if (0 < param_3) {
    do {
      FUN_08029da6(param_2,uVar3);
      uVar3 = uVar3 + 0xc;
      if (*piVar1 + 0x1800U <= uVar3) {
        uVar3 = uVar3 + iVar2;
      }
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}



/* ===== FUN_0801a4e0 @ 0801a4e0 ===== */

uint * FUN_0801a4e0(int param_1,uint *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  longlong lVar11;
  longlong lVar12;
  
  puVar5 = (uint *)(*(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x18) * 0xc);
  puVar4 = (uint *)*DAT_0801b0c8;
  if (puVar4 + 0x600 <= puVar5) {
    puVar5 = puVar5 + -0x600;
  }
  if (0 < param_3) {
    do {
      uVar3 = param_2[6];
      puVar6 = puVar5 + -3;
      if (puVar6 < puVar4) {
        puVar6 = puVar5 + 0x5fd;
      }
      uVar1 = param_2[8];
      uVar2 = *puVar6;
      uVar7 = uVar1 + *param_2;
      lVar11 = (ulonglong)(uVar2 & 0xffffff) * (ulonglong)uVar3;
      uVar9 = (uint)lVar11;
      param_2[8] = uVar7 - uVar9;
      param_2[9] = ((param_2[9] + (uint)CARRY4(uVar1,*param_2)) -
                   ((uVar2 & 0xffffff) * ((int)uVar3 >> 0x1f) + (int)((ulonglong)lVar11 >> 0x20))) -
                   (uint)(uVar7 < uVar9);
      uVar1 = param_2[10];
      uVar2 = param_2[0xb];
      uVar7 = param_2[2];
      uVar9 = param_2[3];
      uVar8 = uVar1 + uVar7;
      lVar11 = FUN_08029e44(puVar6[1]);
      uVar10 = (uint)(lVar11 * (int)uVar3);
      param_2[10] = uVar8 - uVar10;
      param_2[0xb] = ((uVar2 + uVar9 + CARRY4(uVar1,uVar7)) -
                     (int)((ulonglong)(lVar11 * (int)uVar3) >> 0x20)) - (uint)(uVar8 < uVar10);
      param_2[6] = uVar3 + 1;
      *param_2 = (*puVar6 & 0xffffff) + *param_2;
      lVar11 = *(longlong *)(param_2 + 2);
      lVar12 = FUN_08029e90(puVar6[1]);
      *(longlong *)(param_2 + 2) = lVar12 + lVar11;
      lVar11 = *(longlong *)(param_2 + 4);
      lVar12 = FUN_08029e90(puVar6[2]);
      *(longlong *)(param_2 + 4) = lVar12 + lVar11;
      param_3 = param_3 + -1;
      puVar5 = puVar6;
    } while (param_3 != 0);
  }
  return puVar4;
}



/* ===== FUN_0801a5c2 @ 0801a5c2 ===== */

void FUN_0801a5c2(uint *param_1,uint *param_2,uint param_3,undefined4 param_4)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint local_58 [2];
  uint local_50;
  int iStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  uint local_40;
  uint local_38;
  int iStack_34;
  uint local_30;
  int iStack_2c;
  undefined4 uStack_28;
  
  uStack_28 = param_4;
  FUN_08029eca(local_58);
  uVar4 = param_1[6];
  uVar3 = uVar4;
  if ((int)param_3 < (int)uVar4) {
    uVar3 = param_3;
  }
  uVar9 = param_1[0xc] + uVar3 * 0xc;
  local_58[0] = 0;
  local_50 = 0;
  iStack_4c = 0;
  local_48 = 0;
  uStack_44 = 0;
  iVar5 = uVar4 - uVar3;
  local_40 = 0;
  local_38 = 0;
  iStack_34 = 0;
  local_30 = 0;
  iStack_2c = 0;
  if (*DAT_0801b0c8 + 0x1800U <= uVar9) {
    uVar9 = uVar9 - 0x1800;
  }
  if ((int)uVar3 < iVar5) {
    FUN_0801a4ac(param_1,local_58);
    uVar3 = param_1[8];
    uVar10 = param_1[6];
    uVar4 = uVar3 - local_38;
    lVar1 = (ulonglong)*param_1 * (ulonglong)local_40;
    uVar6 = (uint)lVar1;
    lVar2 = (ulonglong)local_58[0] * (ulonglong)uVar10 +
            CONCAT44(local_58[0] * ((int)uVar10 >> 0x1f),uVar4 - uVar6);
    param_1[8] = (uint)lVar2;
    param_1[9] = ((((param_1[9] - iStack_34) - (uint)(uVar3 < local_38)) -
                  (*param_1 * ((int)local_40 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20))) -
                 (uint)(uVar4 < uVar6)) + (int)((ulonglong)lVar2 >> 0x20);
    uVar3 = param_1[10];
    uVar6 = uVar3 - local_30;
    lVar1 = (ulonglong)param_1[2] * (ulonglong)local_40;
    uVar7 = (uint)lVar1;
    uVar8 = uVar6 - uVar7;
    uVar4 = (uint)((ulonglong)local_50 * (ulonglong)uVar10);
    param_1[10] = uVar8 + uVar4;
    param_1[0xb] = ((((param_1[0xb] - iStack_2c) - (uint)(uVar3 < local_30)) -
                    (param_1[3] * local_40 +
                    param_1[2] * ((int)local_40 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20))) -
                   (uint)(uVar6 < uVar7)) +
                   iStack_4c * uVar10 +
                   local_50 * ((int)uVar10 >> 0x1f) +
                   (int)((ulonglong)local_50 * (ulonglong)uVar10 >> 0x20) +
                   (uint)CARRY4(uVar8,uVar4);
    FUN_08029eda(param_1,local_58);
    FUN_08029f14(param_2,local_58);
  }
  else {
    FUN_080249ac(param_2,param_1,0x30);
    if (iVar5 != 0) {
      FUN_0801a4e0(param_1,local_58,iVar5);
      uVar10 = param_2[6];
      uVar3 = param_2[8];
      lVar1 = (ulonglong)*param_2 * (ulonglong)local_40 +
              CONCAT44(*param_2 * ((int)local_40 >> 0x1f),uVar3 - local_38);
      uVar4 = (uint)lVar1;
      uVar6 = (uint)((ulonglong)local_58[0] * (ulonglong)uVar10);
      param_2[8] = uVar4 - uVar6;
      param_2[9] = ((((param_2[9] - iStack_34) - (uint)(uVar3 < local_38)) +
                    (int)((ulonglong)lVar1 >> 0x20)) -
                   (local_58[0] * ((int)uVar10 >> 0x1f) +
                   (int)((ulonglong)local_58[0] * (ulonglong)uVar10 >> 0x20))) -
                   (uint)(uVar4 < uVar6);
      uVar6 = param_2[10];
      uVar4 = uVar6 - local_30;
      lVar1 = (ulonglong)param_2[2] * (ulonglong)local_40;
      uVar7 = (uint)lVar1;
      uVar3 = uVar4 + uVar7;
      uVar8 = (uint)((ulonglong)local_50 * (ulonglong)uVar10);
      param_2[10] = uVar3 - uVar8;
      param_2[0xb] = ((((param_2[0xb] - iStack_2c) - (uint)(uVar6 < local_30)) +
                      param_2[3] * local_40 +
                      param_2[2] * ((int)local_40 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20) +
                      (uint)CARRY4(uVar4,uVar7)) -
                     (iStack_4c * uVar10 +
                     local_50 * ((int)uVar10 >> 0x1f) +
                     (int)((ulonglong)local_50 * (ulonglong)uVar10 >> 0x20))) -
                     (uint)(uVar3 < uVar8);
      FUN_08029eda(param_2,local_58);
    }
    FUN_080249ac(param_1,local_58,0x30);
  }
  param_1[0xc] = uVar9;
  return;
}



/* ===== FUN_0801a78a @ 0801a78a ===== */

longlong FUN_0801a78a(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 0x40);
  iVar1 = FUN_08029fcc(param_1,param_2,uVar2);
  if (iVar1 == 0) {
    return (ulonglong)param_4 << 0x20;
  }
  iVar1 = FUN_08029fcc(param_1 + 0x20,iVar1,uVar2);
  return CONCAT44(param_4,(uint)(iVar1 != 0));
}



/* ===== FUN_0801a7ae @ 0801a7ae ===== */

undefined8 FUN_0801a7ae(uint *param_1,float *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  
  uVar3 = param_1[8];
  uVar2 = *param_1;
  uVar1 = uVar2;
  if (uVar3 < uVar2) {
    uVar1 = uVar3;
    uVar3 = uVar2;
  }
  if (uVar1 < 0x40) {
    uVar1 = (uint)*(byte *)((int)param_2 + uVar1 + 8);
  }
  else {
    uVar6 = VectorUnsignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
    fVar4 = (float)FUN_0802a008(uVar6);
    fVar5 = (float)FUN_08029d88(uVar6);
    fVar5 = *param_2 + param_2[1] * fVar4 + fVar5;
    uVar1 = VectorFloatToUnsigned(fVar5 * fVar5,3);
  }
  return CONCAT44(param_4,~-(uint)(uVar1 < uVar3) >> 0x1f);
}



/* ===== FUN_0801a814 @ 0801a814 ===== */

void FUN_0801a814(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  float fVar4;
  
  FUN_08029fcc(param_1,param_2,0x200);
  iVar2 = DAT_0801b1e8;
  piVar1 = DAT_0801b0c8;
  while( true ) {
    fVar4 = (float)FUN_0802a0ec(param_1);
    if ((*(float *)(param_1 + 0x20) <= fVar4) || (*(int *)(param_1 + 0x18) < 2)) break;
    uVar3 = *(int *)(param_1 + 0x1c) + 0xc;
    if (*piVar1 + 0x1800U <= uVar3) {
      uVar3 = uVar3 + iVar2;
    }
    *(uint *)(param_1 + 0x1c) = uVar3;
    FUN_0802a0a8(param_1);
  }
  return;
}



/* ===== FUN_0801a860 @ 0801a860 ===== */

undefined4 FUN_0801a860(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  longlong lVar6;
  
  FUN_08029fcc(param_1,param_2,0x200);
  iVar5 = param_1[9] - param_1[8];
  iVar3 = iVar5;
  if (iVar5 < 0) {
    iVar3 = -iVar5;
  }
  if (iVar3 < 2) {
    param_1[8] = param_1[9];
  }
  else {
    if (iVar5 < 1) {
      iVar3 = -2;
    }
    else {
      iVar3 = 2;
    }
    param_1[8] = iVar3 + param_1[8];
  }
  while ((uint)param_1[8] < (uint)param_1[6]) {
    uVar2 = param_1[7] + 0xc;
    if (*DAT_0801b0c8 + 0x1800U <= uVar2) {
      uVar2 = param_1[7] - 0x17f4;
    }
    param_1[7] = uVar2;
    FUN_0802a0a8(param_1);
  }
  while ((uint)param_1[6] < (uint)param_1[8]) {
    puVar4 = (uint *)(param_1[7] + -0xc);
    if (puVar4 < (uint *)*DAT_0801b0c8) {
      puVar4 = (uint *)(param_1[7] + 0x17f4);
    }
    param_1[6] = param_1[6] + 1;
    param_1[7] = (int)puVar4;
    *param_1 = (*puVar4 & 0xffffff) + *param_1;
    lVar1 = *(longlong *)(param_1 + 2);
    lVar6 = FUN_08029e90(puVar4[1]);
    *(longlong *)(param_1 + 2) = lVar6 + lVar1;
    lVar1 = *(longlong *)(param_1 + 4);
    lVar6 = FUN_08029e90(puVar4[2]);
    *(longlong *)(param_1 + 4) = lVar6 + lVar1;
  }
  return param_4;
}



/* ===== FUN_0801a910 @ 0801a910 ===== */

undefined8
FUN_0801a910(byte *param_1,uint *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  byte bVar1;
  int iVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined4 local_20;
  
  bVar1 = *param_1;
  if (bVar1 == 0) {
    iVar2 = *(int *)(param_1 + 0xf8);
    *(int *)(param_1 + 0xf8) = iVar2 + 1;
    local_20 = param_3;
    if (0x3f < iVar2 + 1) {
      FUN_0802a154(param_1 + 8,(int)*param_2 >> 0x18);
      *(uint **)(param_1 + 0x38) = param_2;
      *(uint *)(param_1 + 8) = *param_2 & 0xffffff;
      uVar4 = FUN_08029e90(param_2[1]);
      *(undefined8 *)(param_1 + 0x10) = uVar4;
      uVar4 = FUN_08029e90(param_2[2]);
      *(undefined8 *)(param_1 + 0x18) = uVar4;
      param_1[0x20] = 1;
      param_1[0x21] = 0;
      param_1[0x22] = 0;
      param_1[0x23] = 0;
      *param_1 = 1;
      param_1[1] = 1;
      return CONCAT44(param_4,param_3);
    }
  }
  else {
    if (bVar1 == 2) {
      FUN_0802a19c(param_1 + 8);
      param_1[1] = 4;
      uVar3 = extraout_r1_00;
    }
    else {
      if (1 < bVar1) {
        return CONCAT44(param_4,param_3);
      }
      FUN_0802a19c(param_1 + 8);
      uVar3 = extraout_r1;
    }
    local_20 = param_5;
    FUN_0801aba4(param_1,uVar3,param_3,param_4);
  }
  return CONCAT44(param_4,local_20);
}



/* ===== FUN_0801a998 @ 0801a998 ===== */

undefined8 FUN_0801a998(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  longlong lVar1;
  longlong lVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  int local_38;
  int local_34;
  
  uVar8 = DAT_0801b258;
  puVar11 = (uint *)(param_1 + 0x88);
  iVar14 = param_1 + 0xc0;
  if (*(int *)(param_1 + 0xa0) == 0) {
    FUN_080249ac(puVar11,iVar14,0x31);
    *(undefined4 *)(param_1 + 0xc0) = 0;
    *(undefined4 *)(param_1 + 200) = 0;
    *(undefined4 *)(param_1 + 0xcc) = 0;
    *(undefined4 *)(param_1 + 0xd0) = 0;
    *(undefined4 *)(param_1 + 0xd4) = 0;
    *(undefined4 *)(param_1 + 0xd8) = 0;
    *(undefined4 *)(param_1 + 0xe0) = 0;
    *(undefined4 *)(param_1 + 0xe4) = 0;
    *(undefined4 *)(param_1 + 0xe8) = 0;
    *(undefined4 *)(param_1 + 0xec) = 0;
    *(undefined1 *)(param_1 + 0xf0) = 0;
    if (*(char *)(param_1 + 0xb8) == '\0') {
      iVar14 = *(int *)(param_1 + 0xa0);
      goto joined_r0x0801aa4e;
    }
LAB_0801aa50:
    uVar8 = 0;
  }
  else {
    iVar4 = FUN_0801a42e(puVar11,iVar14,DAT_0801b258);
    iVar5 = FUN_0801a42e(puVar11,param_1 + 0x50,uVar8);
    if (iVar4 == 0) {
      local_38 = *(int *)(param_1 + 0xa0);
      local_34 = *(int *)(param_1 + 0xd8);
      piVar6 = &local_34;
      if (*(int *)(param_1 + 0xa0) < *(int *)(param_1 + 0xd8)) {
        piVar6 = &local_38;
      }
      *(int *)(param_1 + 0x100) = *piVar6;
      uVar7 = *(uint *)(param_1 + 0xa0);
      if ((iVar5 == 0) || (0x10 < (int)uVar7)) {
        if ((3 < (int)uVar7) &&
           (((iVar5 == 0 && ((int)uVar7 <= *(int *)(param_1 + 0xd8) * 2)) ||
            (*(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 4, iVar5 == 0)))) {
          fVar17 = (float)FUN_0802a1f0(param_1 + 0x50);
          fVar18 = (float)FUN_0802a1f0(puVar11);
          fVar19 = (float)FUN_0802a1f0(iVar14);
          if (fVar19 <= fVar17) {
            if (fVar17 < fVar18 && (fVar17 < fVar18 && fVar18 < fVar19)) goto LAB_0801ab78;
          }
          else if (fVar19 < fVar18 && (fVar19 < fVar18 && fVar18 < fVar17)) {
LAB_0801ab78:
            *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 1;
          }
        }
        bVar3 = *(byte *)(param_1 + 1);
        if ((bVar3 & 5) == 5) {
          bVar3 = bVar3 & 0xfd;
        }
        else {
          bVar3 = bVar3 | 2;
        }
        *(byte *)(param_1 + 1) = bVar3;
      }
      else {
        uVar9 = *(uint *)(param_1 + 0xa8);
        uVar16 = *(uint *)(param_1 + 0x68);
        lVar2 = (ulonglong)*puVar11 * (ulonglong)uVar16 +
                CONCAT44(*puVar11 * ((int)uVar16 >> 0x1f),uVar9 + *(uint *)(param_1 + 0x70));
        uVar10 = (uint)lVar2;
        lVar1 = (ulonglong)*(uint *)(param_1 + 0x50) * (ulonglong)uVar7;
        uVar15 = (uint)lVar1;
        *(uint *)(param_1 + 0xa8) = uVar10 - uVar15;
        *(uint *)(param_1 + 0xac) =
             ((*(int *)(param_1 + 0xac) +
               *(int *)(param_1 + 0x74) + (uint)CARRY4(uVar9,*(uint *)(param_1 + 0x70)) +
              (int)((ulonglong)lVar2 >> 0x20)) -
             (*(uint *)(param_1 + 0x50) * ((int)uVar7 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20))) -
             (uint)(uVar10 < uVar15);
        uVar9 = *(uint *)(param_1 + 0xb0);
        uVar15 = uVar9 + *(uint *)(param_1 + 0x78);
        lVar1 = (ulonglong)*(uint *)(param_1 + 0x90) * (ulonglong)uVar16;
        uVar12 = (uint)lVar1;
        uVar10 = uVar15 + uVar12;
        lVar2 = (ulonglong)*(uint *)(param_1 + 0x58) * (ulonglong)uVar7;
        uVar13 = (uint)lVar2;
        *(uint *)(param_1 + 0xb0) = uVar10 - uVar13;
        *(uint *)(param_1 + 0xb4) =
             ((*(int *)(param_1 + 0xb4) +
               *(int *)(param_1 + 0x7c) + (uint)CARRY4(uVar9,*(uint *)(param_1 + 0x78)) +
              *(int *)(param_1 + 0x94) * uVar16 +
              *(uint *)(param_1 + 0x90) * ((int)uVar16 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20) +
              (uint)CARRY4(uVar15,uVar12)) -
             (*(int *)(param_1 + 0x5c) * uVar7 +
             *(uint *)(param_1 + 0x58) * ((int)uVar7 >> 0x1f) + (int)((ulonglong)lVar2 >> 0x20))) -
             (uint)(uVar10 < uVar13);
        FUN_0802a1ba(puVar11,param_1 + 0x50);
        *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 4;
      }
    }
    else {
      FUN_08029f14(puVar11,iVar14);
      *(undefined4 *)(param_1 + 0xc0) = 0;
      *(undefined4 *)(param_1 + 200) = 0;
      *(undefined4 *)(param_1 + 0xcc) = 0;
      *(undefined4 *)(param_1 + 0xd0) = 0;
      *(undefined4 *)(param_1 + 0xd4) = 0;
      *(undefined4 *)(param_1 + 0xd8) = 0;
      *(undefined4 *)(param_1 + 0xe0) = 0;
      *(undefined4 *)(param_1 + 0xe4) = 0;
      *(undefined4 *)(param_1 + 0xe8) = 0;
      *(undefined4 *)(param_1 + 0xec) = 0;
      *(undefined1 *)(param_1 + 0xf0) = 0;
      iVar14 = *(int *)(param_1 + 0xa0);
      if ((iVar5 == 0) && (*(int *)(param_1 + 0x68) * 2 <= iVar14)) {
        *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 1;
      }
joined_r0x0801aa4e:
      if (iVar14 < 0xc0) goto LAB_0801aa50;
      *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 2;
    }
    uVar8 = 1;
  }
  return CONCAT44(param_4,uVar8);
}



/* ===== FUN_0801aba4 @ 0801aba4 ===== */

void FUN_0801aba4(int param_1,undefined4 param_2,uint param_3,int param_4,ushort param_5)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  undefined4 extraout_r1;
  uint *puVar4;
  undefined4 extraout_r1_00;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  uint in_fpscr;
  float fVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  uint local_58;
  uint local_54;
  int local_50;
  uint local_48;
  int iStack_44;
  
  fVar1 = DAT_0801ae88;
  local_50 = param_1 + 0x88;
  local_48 = param_3;
  iStack_44 = param_4;
  while( true ) {
    if (*(int *)(param_1 + 0x20) < *(int *)(param_1 + 0x40)) {
      return;
    }
    FUN_0801a5c2(param_1 + 8,param_1 + 0xc0);
    *(undefined1 *)(param_1 + 0xf0) = *(undefined1 *)(param_1 + 0x3c);
    *(undefined1 *)(param_1 + 0x3c) = 0;
    iVar2 = FUN_0801a998(param_1);
    if (iVar2 == 0) break;
    uVar6 = *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0xd8) + 0x40;
    if ((int)((uint)*(byte *)(param_1 + 1) << 0x1f) < 0) {
      *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xfe;
      uVar7 = *(uint *)(param_1 + 0xfc);
      uVar5 = uVar6 + *(int *)(param_1 + 0xa0);
      bVar9 = local_48 < uVar5 * 0x4000;
      uVar3 = local_48 + uVar5 * -0x4000;
      iVar2 = iStack_44 - (((int)uVar5 >> 0x1f) << 0xe | uVar5 >> 0x12);
      fVar10 = (float)FUN_0802a32c(local_50,(int)uVar7 / 2);
      uVar5 = VectorFloatToUnsigned(fVar10 + 0.5,3);
      if (*(int *)(param_1 + 0xa0) < 1) {
        fVar10 = DAT_0801ae8c;
      }
      else {
        fVar10 = (float)VectorUnsignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
        fVar14 = (float)VectorSignedToFloat(*(int *)(param_1 + 0xa0),(byte)(in_fpscr >> 0x16) & 3);
        fVar10 = (fVar10 * 2.0) / fVar14;
      }
      uVar11 = FUN_0802a218(local_50,DAT_0801b258);
      uVar12 = FUN_0802a278(local_50,(int)uVar7 / 2);
      uVar13 = FUN_0802a0ec(local_50);
      local_54 = (uint)param_5;
      local_58 = uVar5;
      FUN_0801ae90(fVar10,uVar11,uVar12,uVar13,param_1,extraout_r1_00,uVar3 + uVar7 * 0x1000,
                   (iVar2 - (uint)bVar9) +
                   (((int)uVar7 >> 0x1f) << 0xc | uVar7 >> 0x14) +
                   (uint)CARRY4(uVar3,uVar7 * 0x1000));
    }
    if ((int)((uint)*(byte *)(param_1 + 1) << 0x1e) < 0) {
      *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xfd;
      iVar2 = *(int *)(param_1 + 0xa0);
      uVar3 = *(uint *)(param_1 + 0x88);
      if (iVar2 < 1) {
        fVar10 = DAT_0801ae8c;
      }
      else {
        fVar10 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
        fVar14 = (float)VectorSignedToFloat(iVar2,(byte)(in_fpscr >> 0x16) & 3);
        fVar10 = (fVar10 * 2.0) / fVar14;
      }
      uVar11 = FUN_0802a218(local_50,DAT_0801b258);
      fVar14 = (float)FUN_0802a3a4(*(undefined4 *)(param_1 + 0x90),*(undefined4 *)(param_1 + 0x94));
      fVar15 = *(float *)(DAT_0801af8c + 4);
      fVar16 = (float)VectorUnsignedToFloat
                                (*(undefined4 *)(param_1 + 0xa0),(byte)(in_fpscr >> 0x16) & 3);
      uVar12 = FUN_0802a0ec(local_50);
      local_54 = (uint)param_5;
      uVar5 = iVar2 + uVar6 * 2;
      uVar7 = ((int)uVar5 >> 0x1f) << 0xd | uVar5 >> 0x13;
      local_58 = uVar3;
      FUN_0801ae90(fVar10,uVar11,fVar14 / (fVar15 * fVar1 * fVar16),uVar12,param_1,uVar7,
                   local_48 + uVar5 * -0x2000,
                   (iStack_44 - uVar7) - (uint)(local_48 < uVar5 * 0x2000));
    }
    if ((int)((uint)*(byte *)(param_1 + 1) << 0x1d) < 0) {
      *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xfb | 1;
      uVar3 = *(uint *)(param_1 + 0x100);
      bVar9 = local_48 < uVar6 * 0x4000;
      uVar5 = local_48 + uVar6 * -0x4000;
      iVar2 = iStack_44 - (((int)uVar6 >> 0x1f) << 0xe | uVar6 >> 0x12);
      iVar8 = *(int *)(param_1 + 0xa0) - (int)uVar3 / 2;
      fVar10 = (float)FUN_0802a32c(local_50,iVar8);
      uVar6 = VectorFloatToUnsigned(fVar10 + 0.5,3);
      if (*(int *)(param_1 + 0xa0) < 1) {
        fVar10 = DAT_0801ae8c;
      }
      else {
        fVar10 = (float)VectorUnsignedToFloat(uVar6,(byte)(in_fpscr >> 0x16) & 3);
        fVar14 = (float)VectorSignedToFloat(*(int *)(param_1 + 0xa0),(byte)(in_fpscr >> 0x16) & 3);
        fVar10 = (fVar10 * 2.0) / fVar14;
      }
      uVar11 = FUN_0802a218(local_50,DAT_0801b258);
      uVar12 = FUN_0802a278(local_50,iVar8);
      uVar13 = FUN_0802a0ec(local_50);
      local_54 = (uint)param_5;
      local_58 = uVar6;
      FUN_0801ae90(fVar10,uVar11,uVar12,uVar13,param_1,extraout_r1,uVar5 + uVar3 * -0x1000,
                   ((iVar2 - (uint)bVar9) - (((int)uVar3 >> 0x1f) << 0xc | uVar3 >> 0x14)) -
                   (uint)(uVar5 < uVar3 * 0x1000));
    }
    FUN_080249ac(param_1 + 0x50,local_50,0x31);
    FUN_080249ac(local_50,param_1 + 0xc0,0x31);
    local_58 = *(uint *)(param_1 + 0xa0);
    local_54 = *(uint *)(param_1 + 0x68);
    if ((int)*(uint *)(param_1 + 0xa0) < (int)*(uint *)(param_1 + 0x68)) {
      puVar4 = &local_58;
    }
    else {
      puVar4 = &local_54;
    }
    *(uint *)(param_1 + 0xfc) = *puVar4;
    *(undefined4 *)(param_1 + 0xc0) = 0;
    *(undefined4 *)(param_1 + 200) = 0;
    *(undefined4 *)(param_1 + 0xcc) = 0;
    *(undefined4 *)(param_1 + 0xd0) = 0;
    *(undefined4 *)(param_1 + 0xd4) = 0;
    *(undefined4 *)(param_1 + 0xd8) = 0;
    *(undefined4 *)(param_1 + 0xe0) = 0;
    *(undefined4 *)(param_1 + 0xe4) = 0;
    *(undefined4 *)(param_1 + 0xe8) = 0;
    *(undefined4 *)(param_1 + 0xec) = 0;
    *(undefined1 *)(param_1 + 0xf0) = 0;
  }
  return;
}



/* ===== FUN_0801ae90 @ 0801ae90 ===== */

void FUN_0801ae90(float param_1,undefined4 param_2,float param_3,float param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                 ushort param_10)

{
  uint uVar1;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_36;
  float local_32;
  float local_2e;
  undefined2 local_2a;
  ushort local_28;
  
  param_10 = param_10 & 0xfcfc;
  uVar1 = FUN_0801b0d4(param_3,param_4);
  if (uVar1 == 1) {
    param_10 = param_10 | 1;
  }
  else if (uVar1 != 0) {
    if (uVar1 == 3) {
      param_10 = param_10 | 3;
      if (DAT_0801b1e0 <= param_3) {
        param_3 = DAT_0801b1e4;
      }
    }
    else if (uVar1 < 3) {
      param_10 = param_10 | 2;
    }
  }
  uVar1 = FUN_0801b00c(param_1,param_2);
  local_32 = param_1;
  if (uVar1 == 1) {
    param_10 = param_10 | 0x100;
  }
  else if (uVar1 != 0) {
    if (uVar1 == 3) {
      param_10 = param_10 | 0x300;
      if (DAT_0801b21c <= param_1) {
        local_32 = DAT_0801b228;
      }
    }
    else if (uVar1 < 3) {
      param_10 = param_10 | 0x200;
    }
  }
  local_36 = param_9;
  if (DAT_0801b248 <= param_4 * DAT_0801b22c) {
    local_2a = 0x3de;
  }
  else {
    local_2a = (undefined2)(int)(param_4 * DAT_0801b22c);
  }
  local_28 = param_10 & 0xf303 | 0x1000;
  local_40 = param_7;
  local_3c = param_8;
  local_2e = param_3;
  FUN_0801894a(&local_40);
  return;
}



/* ===== FUN_0801af98 @ 0801af98 ===== */

undefined4 FUN_0801af98(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  param_1[2] = 0;
  iVar1 = *param_1 + param_1[1] * 0xc;
  uVar2 = iVar1 + 0xc;
  if (*param_1 + 0x1800U <= uVar2) {
    uVar2 = iVar1 - 0x17f4;
  }
  param_1[0xb] = uVar2;
  param_1[4] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0x15] = uVar2;
  param_1[0xe] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x16] = 0;
  uVar3 = 0;
  FUN_0802a3ec(param_1 + 0x18);
  uVar4 = 0x40;
  param_1 = param_1 + 0x5a;
  do {
    param_1[7] = uVar2;
    FUN_08029eca(param_1);
    param_1[0xf] = uVar2;
    FUN_08029eca(param_1 + 8);
    param_1[0x10] = uVar4;
    uVar3 = uVar3 + 1;
    uVar4 = uVar4 >> 1;
    param_1 = param_1 + 0x12;
  } while (uVar3 < 7);
  return param_4;
}



/* ===== FUN_0801b00c @ 0801b00c ===== */

undefined4 FUN_0801b00c(float param_1,float param_2)

{
  uint uVar1;
  uint in_fpscr;
  float fVar2;
  float fVar3;
  
  uVar1 = in_fpscr & 0xfffffff;
  if (!NAN(param_1) && !NAN(DAT_0801b21c)) {
    return 3;
  }
  if (!NAN(param_2) && !NAN(DAT_0801b24c)) {
    return 0xffffffff;
  }
  param_1 = param_1 * 10.0;
  fVar3 = (float)VectorUnsignedToFloat
                           (*(undefined4 *)(DAT_0801b0d0 + 0x44),(byte)(uVar1 >> 0x16) & 3);
  if (DAT_0801b250 <= param_2) {
    fVar2 = (1.0 - param_2 * 0.5) * param_1;
    uVar1 = uVar1 | (uint)(fVar2 < fVar3) << 0x1f;
    if (SUB41(uVar1 >> 0x1f,0) == (NAN(fVar2) || NAN(fVar3))) {
      return 2;
    }
    fVar3 = (float)VectorUnsignedToFloat
                             (*(undefined4 *)(DAT_0801b0d0 + 0x40),(byte)(uVar1 >> 0x16) & 3);
    if (fVar2 < fVar3) {
      if (fVar3 <= (param_2 * 0.5 * 2.0 + 1.0) * param_1) {
        return 0xffffffff;
      }
      return 0;
    }
  }
  else {
    uVar1 = uVar1 | (uint)(param_1 < fVar3) << 0x1f;
    if (SUB41(uVar1 >> 0x1f,0) == (NAN(param_1) || NAN(fVar3))) {
      return 2;
    }
    fVar3 = (float)VectorUnsignedToFloat
                             (*(undefined4 *)(DAT_0801b0d0 + 0x40),(byte)(uVar1 >> 0x16) & 3);
    if (param_1 < fVar3) {
      return 0;
    }
  }
  return 1;
}



/* ===== FUN_0801b0d4 @ 0801b0d4 ===== */

longlong FUN_0801b0d4(float param_1,float param_2)

{
  int iVar1;
  uint unaff_r7;
  uint in_fpscr;
  float fVar2;
  float fVar3;
  
  iVar1 = FUN_08018634(0x300);
  if ((iVar1 == 0) || (in_fpscr = in_fpscr & 0xfffffff, !NAN(param_1) && !NAN(DAT_0801b1e0))) {
    return CONCAT44(unaff_r7,3);
  }
  if (!NAN(param_2) && !NAN(DAT_0801b24c)) {
LAB_0801b1b2:
    return CONCAT44(unaff_r7,0xffffffff);
  }
  param_1 = param_1 * DAT_0801b254;
  fVar2 = (float)VectorUnsignedToFloat
                           (*(undefined4 *)(DAT_0801b25c + 0x34),(byte)(in_fpscr >> 0x16) & 3);
  if (DAT_0801b250 <= param_2) {
    fVar3 = (1.0 - param_2 * 0.5) * param_1;
    in_fpscr = in_fpscr | (uint)(fVar3 < fVar2) << 0x1f;
    if (SUB41(in_fpscr >> 0x1f,0) == (NAN(fVar3) || NAN(fVar2))) goto LAB_0801b16e;
    fVar2 = (float)VectorUnsignedToFloat
                             (*(undefined4 *)(DAT_0801b25c + 0x30),(byte)(in_fpscr >> 0x16) & 3);
    if (fVar3 < fVar2) {
      if ((param_2 * 0.5 * 2.0 + 1.0) * param_1 < fVar2) goto LAB_0801b1aa;
      goto LAB_0801b1b2;
    }
  }
  else {
    in_fpscr = in_fpscr | (uint)(param_1 < fVar2) << 0x1f;
    if (SUB41(in_fpscr >> 0x1f,0) == (NAN(param_1) || NAN(fVar2))) {
LAB_0801b16e:
      return CONCAT44(unaff_r7,2);
    }
    fVar2 = (float)VectorUnsignedToFloat
                             (*(undefined4 *)(DAT_0801b25c + 0x30),(byte)(in_fpscr >> 0x16) & 3);
    if (param_1 < fVar2) {
LAB_0801b1aa:
      return (ulonglong)unaff_r7 << 0x20;
    }
  }
  return CONCAT44(unaff_r7,1);
}



/* ===== FUN_0801b1be @ 0801b1be ===== */

void FUN_0801b1be(void)

{
  return;
}



/* ===== FUN_0801b1d0 @ 0801b1d0 ===== */

void FUN_0801b1d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  ushort uVar3;
  undefined4 in_r3;
  undefined4 uVar4;
  undefined8 uStack_20;
  undefined4 uStack_16;
  ushort uStack_12;
  undefined4 uStack_10;
  
  puVar2 = DAT_0801b264;
  iVar1 = DAT_0801b0d0;
  uVar4 = *(undefined4 *)(DAT_0801b0d0 + 0x20);
  *DAT_0801b264 = uVar4;
  puVar2[1] = *(undefined4 *)(iVar1 + 0x28);
  uStack_10 = in_r3;
  uVar3 = FUN_0801862e();
  uStack_20 = FUN_0801a32a();
  uStack_12 = uVar3 & 0xf303 | 0x1000;
  uStack_16 = uVar4;
  FUN_08018958(&uStack_20);
  return;
}



/* ===== FUN_0801b1d8 @ 0801b1d8 ===== */

void FUN_0801b1d8(undefined4 param_1)

{
  FUN_0802a474(DAT_0801b260,param_1);
  return;
}



/* ===== FUN_0801b1ec @ 0801b1ec ===== */

void FUN_0801b1ec(void)

{
  int iVar1;
  undefined2 uVar2;
  undefined8 uVar3;
  
  iVar1 = DAT_0801b25c;
  *(undefined4 *)(DAT_0801b25c + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  FUN_08015f14(0);
  uVar2 = FUN_0801862e();
  uVar3 = FUN_0801a32a();
  FUN_08018a4c((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),uVar2,4);
  FUN_08018568(1);
  return;
}



/* ===== FUN_0801b220 @ 0801b220 ===== */

void FUN_0801b220(void)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  undefined4 in_r3;
  float fVar5;
  float fVar6;
  undefined4 local_18;
  float local_14;
  float local_10;
  undefined4 uStack_c;
  
  iVar1 = DAT_0801b268;
  local_18 = *(undefined4 *)(DAT_0802aa20 + 0x48);
  local_14 = *(float *)(DAT_0802aa20 + 0x4c) * 4.0;
  local_10 = *(float *)(DAT_0802aa20 + 0x50) * 16.0;
  uStack_c = in_r3;
  FUN_0802ec28(DAT_0801b268 + 0x14,0x100,&local_18);
  pfVar2 = (float *)(iVar1 + 0x14);
  pfVar4 = (float *)(iVar1 + 0x414);
  pfVar3 = pfVar2;
  fVar5 = DAT_0802aa18;
  if (pfVar2 < pfVar4) {
    while ((pfVar3 < pfVar4 && (fVar5 == 0.0))) {
      fVar5 = *pfVar3;
      pfVar3 = pfVar3 + 1;
    }
  }
  for (; pfVar3 < pfVar4; pfVar3 = pfVar3 + 1) {
    fVar6 = *pfVar3;
    if ((fVar6 != 0.0) && (fVar6 < fVar5)) {
      fVar5 = fVar6;
    }
  }
  if (fVar5 != 0.0) {
    fVar6 = *(float *)(iVar1 + 4);
    pfVar3 = (float *)(iVar1 + 0x14);
    if (pfVar2 < pfVar4) {
      for (; pfVar3 < pfVar4; pfVar3 = pfVar3 + 1) {
        *pfVar3 = *pfVar3 * (fVar6 / fVar5);
      }
    }
    *(float *)(iVar1 + 8) = fVar5 * DAT_0802aa1c;
  }
  return;
}



/* ===== FUN_0801b270 @ 0801b270 ===== */

uint FUN_0801b270(void)

{
  uint *puVar1;
  ushort uVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = DAT_0801b4cc;
  uVar4 = *DAT_0801b4c4 & 0xffff;
  while (uVar4 != (*DAT_0801b4c4 & 0xffff)) {
    uVar4 = *DAT_0801b4c4 & 0xffff;
  }
  uVar2 = *DAT_0801b4c8 + (short)uVar4;
  if (uVar2 < (ushort)*DAT_0801b4cc) {
    uVar4 = *DAT_0801b4cc;
    puVar1 = DAT_0801b4cc + 1;
    *DAT_0801b4cc = uVar4 + 0x10000;
    puVar3[1] = *puVar1 + (uint)(0xfffeffff < uVar4);
  }
  *(ushort *)puVar3 = uVar2;
  return *puVar3;
}



/* ===== FUN_0801b2ac @ 0801b2ac ===== */

undefined8 FUN_0801b2ac(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_0801b65c();
  if (iVar1 == 0) {
    uVar2 = FUN_0801b2d0();
    *(byte *)(param_1 + 0xd) = (byte)~(byte)(-(uint)(uVar2 < 0x1f) >> 0x18) >> 7;
  }
  *(int *)(param_1 + 8) = param_2 + 0x8000;
  return CONCAT44(param_4,param_1);
}



/* ===== FUN_0801b2d0 @ 0801b2d0 ===== */

undefined4 FUN_0801b2d0(void)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint in_fpscr;
  float fVar6;
  float fVar7;
  undefined2 uStack_1c;
  undefined4 uStack_18;
  
  uVar2 = DAT_0801b4d8;
  puVar1 = DAT_0801b4d4;
  if (*(char *)(DAT_0801b4d0 + 0x10) == '\0') {
    return 0;
  }
  uStack_18 = 0;
  uStack_1c = 0;
  *DAT_0801b4d4 = *DAT_0801b4d4 | 0x800000;
  iVar3 = FUN_0802ab2e(uVar2,0xa6,0xd,&uStack_18,3);
  iVar4 = FUN_0802ab2e(uVar2,0xa6,5,(int)&uStack_1c + 1,1);
  iVar5 = FUN_0802ab2e(uVar2,0xa6,4,&uStack_1c,1);
  *puVar1 = *puVar1 & 0xff7fffff;
  if (iVar5 == 0 && (iVar4 == 0 && iVar3 == 0)) {
    fVar6 = (float)VectorUnsignedToFloat(uStack_18,(byte)(in_fpscr >> 0x16) & 3);
    fVar7 = (float)VectorUnsignedToFloat
                             ((uint)*(ushort *)(&LAB_0801b4f0 + (uint)((byte)uStack_1c >> 4) * 2) *
                              (uint)(byte)(&DAT_0801b4e8)[uStack_1c._1_1_],
                              (byte)(in_fpscr >> 0x16) & 3);
    uStack_18 = VectorFloatToUnsigned((fVar6 * DAT_0801b4c0) / fVar7,3);
  }
  else {
    FUN_08016adc(2);
  }
  return uStack_18;
}



/* ===== FUN_0801b2da @ 0801b2da ===== */

undefined4 FUN_0801b2da(void)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint in_fpscr;
  float fVar6;
  float fVar7;
  undefined2 local_1c;
  undefined4 local_18;
  
  uVar2 = DAT_0801b4d8;
  puVar1 = DAT_0801b4d4;
  local_18 = 0;
  local_1c = 0;
  *DAT_0801b4d4 = *DAT_0801b4d4 | 0x800000;
  iVar3 = FUN_0802ab2e(uVar2,0xa6,0xd,&local_18,3);
  iVar4 = FUN_0802ab2e(uVar2,0xa6,5,(int)&local_1c + 1,1);
  iVar5 = FUN_0802ab2e(uVar2,0xa6,4,&local_1c,1);
  *puVar1 = *puVar1 & 0xff7fffff;
  if (iVar5 == 0 && (iVar4 == 0 && iVar3 == 0)) {
    fVar6 = (float)VectorUnsignedToFloat(local_18,(byte)(in_fpscr >> 0x16) & 3);
    fVar7 = (float)VectorUnsignedToFloat
                             ((uint)*(ushort *)(&LAB_0801b4f0 + (uint)((byte)local_1c >> 4) * 2) *
                              (uint)(byte)(&DAT_0801b4e8)[local_1c._1_1_],
                              (byte)(in_fpscr >> 0x16) & 3);
    local_18 = VectorFloatToUnsigned((fVar6 * DAT_0801b4c0) / fVar7,3);
  }
  else {
    FUN_08016adc(2);
  }
  return local_18;
}



/* ===== FUN_0801b390 @ 0801b390 ===== */

undefined8 FUN_0801b390(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  int local_14;
  
  iVar4 = *DAT_0801b4dc;
  iVar3 = DAT_0801b4dc[1];
  local_14 = 0;
  do {
    uVar5 = FUN_0801b270(param_1,iVar3);
    puVar2 = DAT_0801b4d8;
    puVar1 = DAT_0801b4d4;
    iVar3 = (int)((ulonglong)uVar5 >> 0x20);
    param_1 = (int)uVar5 - (iVar4 + 0xccd);
  } while (param_1 < 1);
  *DAT_0801b4d4 = *DAT_0801b4d4 | 0x800000;
  *puVar2 = *puVar2 | 1;
  iVar3 = FUN_0802aa70(puVar2,0xa6,0,&local_14);
  if (iVar3 == 0) {
    iVar3 = FUN_0801b270();
    do {
      iVar4 = FUN_0801b270();
    } while (iVar4 - (iVar3 + 0x148) < 1);
    iVar4 = FUN_0802ab2e(puVar2,0xa6,6,&local_14);
    iVar3 = iVar4;
    if (iVar4 == 0) {
      iVar3 = local_14;
    }
    if (iVar4 == 0 && iVar3 == 0xb1) {
      local_14 = 2;
      iVar3 = FUN_0802aa70(puVar2,0xa6,0,&local_14);
      if (iVar3 == 0) {
        *(undefined1 *)(DAT_0801b4d0 + 0x10) = 1;
      }
    }
  }
  *puVar1 = *puVar1 & 0xff7fffff;
  if (*(char *)(DAT_0801b4d0 + 0x10) == '\0') {
    FUN_08016adc(1);
    return CONCAT44(local_14,1);
  }
  if ((*(byte *)(DAT_0801b4e0 + 0x58) & 3) == 2) {
    FUN_08016890(DAT_0801b4d0,0x28f);
  }
  return CONCAT44(local_14,1);
}



/* ===== FUN_0801b498 @ 0801b498 ===== */

void FUN_0801b498(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 in_r3;
  
  iVar2 = DAT_0801b4d0;
  if (*(char *)(DAT_0801b4d0 + 0x10) == '\0') {
    return;
  }
  iVar3 = FUN_08016854();
  *(int *)(iVar2 + 8) = iVar3 + 0x28f;
  uVar1 = DAT_08016988;
  FUN_080211e8(DAT_08016988,iVar2);
  FUN_0802120c(uVar1,iVar2,in_r3);
  return;
}



/* ===== FUN_0801b4aa @ 0801b4aa ===== */

void FUN_0801b4aa(void)

{
  FUN_080168b4(DAT_0801b4d0);
  return;
}



/* ===== FUN_0801b4b0 @ 0801b4b0 ===== */

uint FUN_0801b4b0(void)

{
  return ~-(uint)(*(char *)(DAT_0801b4d0 + 0xd) == '\0') >> 0x1f;
}



/* ===== FUN_0801b4fc @ 0801b4fc ===== */

void FUN_0801b4fc(uint *param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  
  bVar2 = (byte)param_2;
  bVar3 = (byte)((uint)param_2 >> 8);
  bVar4 = (byte)((uint)param_2 >> 0x10);
  bVar1 = (byte)((uint)param_2 >> 0x18);
  uVar5 = (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1 |
                          bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                       bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18 |
          (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1 |
                          bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                       bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
          (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1 |
                          bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                       bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
          (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1 |
                          bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                       bVar1 >> 6 & 1) << 1 | bVar1 >> 7);
  *param_1 = param_3 << (LZCOUNT(uVar5) << 1) | *param_1 & ~(3 << (LZCOUNT(uVar5) << 1));
  return;
}



/* ===== FUN_0801b520 @ 0801b520 ===== */

void FUN_0801b520(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  
  bVar2 = (byte)param_2;
  bVar3 = (byte)((uint)param_2 >> 8);
  bVar4 = (byte)((uint)param_2 >> 0x10);
  bVar1 = (byte)((uint)param_2 >> 0x18);
  uVar5 = (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1 |
                          bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                       bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18 |
          (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1 |
                          bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                       bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
          (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1 |
                          bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                       bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
          (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1 |
                          bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                       bVar1 >> 6 & 1) << 1 | bVar1 >> 7);
  *(uint *)(param_1 + 0xc) =
       param_3 << (LZCOUNT(uVar5) << 1) | *(uint *)(param_1 + 0xc) & ~(3 << (LZCOUNT(uVar5) << 1));
  return;
}



/* ===== FUN_0801b544 @ 0801b544 ===== */

void FUN_0801b544(int param_1)

{
  undefined4 *puVar1;
  
  FUN_080148ac();
  puVar1 = DAT_0801b860;
  *DAT_0801b85c = 0;
  *puVar1 = 0;
  *(undefined1 *)(param_1 + 0xd) = 0;
  return;
}



/* ===== FUN_0801b55a @ 0801b55a ===== */

void FUN_0801b55a(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = DAT_0801b864;
  if (param_1 == 0) {
    FUN_080168b4(DAT_0801b864);
    puVar1 = DAT_0801b860;
    *DAT_0801b85c = 0;
    *puVar1 = 0;
    *(undefined1 *)(iVar2 + 0xd) = 0;
  }
  *(bool *)(iVar2 + 0x10) = param_1 != 0;
  return;
}



/* ===== FUN_0801b57c @ 0801b57c ===== */

void FUN_0801b57c(int param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar4 = DAT_0801b868;
  iVar3 = DAT_0801b864;
  uVar5 = (uint)*(byte *)(DAT_0801b868 + 5);
  if (5 < uVar5) {
    uVar5 = 5;
    *(undefined1 *)(DAT_0801b868 + 5) = 5;
  }
  FUN_08016890(iVar3,*(undefined4 *)(&DAT_0801b8b0 + uVar5 * 4));
  if ((*(char *)(iVar3 + 0x10) != '\0') &&
     ((param_1 != 0 ||
      (((*(byte *)(iVar4 + 0x58) & 3) != 0 &&
       (((*(byte *)(iVar4 + 0x58) & 3) != 2 || (iVar6 = FUN_0801b4b0(), iVar6 == 0)))))))) {
    puVar2 = DAT_0801b860;
    puVar1 = DAT_0801b85c;
    uVar5 = (uint)*(byte *)(iVar4 + 1);
    if (9 < uVar5) {
      uVar5 = 9;
      *(undefined1 *)(iVar4 + 1) = 9;
    }
    *puVar1 = (uint)*(ushort *)(&DAT_0801b89c + uVar5 * 2);
    *puVar2 = 1;
    *(undefined1 *)(iVar3 + 0xd) = 1;
  }
  return;
}



/* ===== FUN_0801b5d4 @ 0801b5d4 ===== */

void FUN_0801b5d4(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = DAT_0801b864;
  FUN_080168b4(DAT_0801b864);
  puVar1 = DAT_0801b860;
  *DAT_0801b85c = 0;
  *puVar1 = 0;
  *(undefined1 *)(iVar2 + 0xd) = 0;
  return;
}



/* ===== FUN_0801b5ec @ 0801b5ec ===== */

undefined4 FUN_0801b5ec(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  undefined4 in_r3;
  bool bVar8;
  
  iVar4 = DAT_0801b868;
  iVar3 = DAT_0801b864;
  if (*(char *)(DAT_0801b864 + 0xd) != '\0') {
    FUN_080168b4(DAT_0801b864);
    puVar2 = DAT_0801b860;
    *DAT_0801b85c = 0;
    *puVar2 = 0;
    *(undefined1 *)(iVar3 + 0xd) = 0;
    return in_r3;
  }
  uVar6 = (uint)*(byte *)(DAT_0801b868 + 5);
  if (5 < uVar6) {
    uVar6 = 5;
    *(undefined1 *)(DAT_0801b868 + 5) = 5;
  }
  FUN_08016890(iVar3,*(undefined4 *)(&DAT_0801b8b0 + uVar6 * 4));
  bVar8 = *(char *)(iVar3 + 0x10) == '\0';
  bVar5 = 0;
  if (!bVar8) {
    bVar5 = *(byte *)(iVar4 + 0x58) & 3;
    bVar8 = bVar5 == 0;
  }
  if ((!bVar8) && ((bVar5 != 2 || (iVar7 = FUN_0801b4b0(), iVar7 == 0)))) {
    puVar2 = DAT_0801b860;
    puVar1 = DAT_0801b85c;
    uVar6 = (uint)*(byte *)(iVar4 + 1);
    if (9 < uVar6) {
      uVar6 = 9;
      *(undefined1 *)(iVar4 + 1) = 9;
    }
    *puVar1 = (uint)*(ushort *)(&DAT_0801b89c + uVar6 * 2);
    *puVar2 = 1;
    *(undefined1 *)(iVar3 + 0xd) = 1;
  }
  return in_r3;
}



/* ===== FUN_0801b65c @ 0801b65c ===== */

uint FUN_0801b65c(void)

{
  return ~-(uint)(*(char *)(DAT_0801b864 + 0xd) == '\0') >> 0x1f;
}



/* ===== FUN_0801b66e @ 0801b66e ===== */

void FUN_0801b66e(void)

{
  *DAT_0801b870 = 0x40;
  return;
}



/* ===== FUN_0801b676 @ 0801b676 ===== */

void FUN_0801b676(void)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 in_r3;
  
  uVar2 = DAT_0801b878;
  puVar1 = DAT_0801b874;
  *DAT_0801b874 = *DAT_0801b874 | 0x4000;
  uVar3 = *puVar1;
  FUN_0801b4fc(uVar2,1,2,uVar3 & 0x4000);
  FUN_0801b4fc(uVar2,2,2);
  FUN_0801b4fc(uVar2,0x10,2);
  *DAT_0801b87c = *DAT_0801b87c | 0x40;
  FUN_0802acc0();
  FUN_0802adec(1,uVar3 & 0x4000,in_r3);
  return;
}



/* ===== FUN_0801b6c4 @ 0801b6c4 ===== */

void FUN_0801b6c4(undefined1 param_1)

{
  int *piVar1;
  
  piVar1 = DAT_0801b880;
  do {
  } while (*DAT_0801b880 << 0x18 < 0);
  *DAT_0801b86c = 0x20;
  *(undefined1 *)(piVar1 + 1) = param_1;
  return;
}



/* ===== FUN_0801b6d2 @ 0801b6d2 ===== */

void FUN_0801b6d2(undefined1 param_1)

{
  int *piVar1;
  
  piVar1 = DAT_0801b880;
  do {
  } while (*DAT_0801b880 << 0x18 < 0);
  *DAT_0801b870 = 0x20;
  *(undefined1 *)(piVar1 + 1) = param_1;
  return;
}



/* ===== FUN_0801b6e8 @ 0801b6e8 ===== */

void FUN_0801b6e8(void)

{
  FUN_0801692a(DAT_0801b888,DAT_0801b884,5,0);
  return;
}



/* ===== FUN_0801b6f4 @ 0801b6f4 ===== */

void FUN_0801b6f4(int param_1)

{
  undefined4 uVar1;
  undefined4 unaff_r7;
  
  *DAT_0801b88c = (char)param_1;
  if (param_1 == 0) {
    thunk_FUN_0801b6c4(0xc0);
    uVar1 = 0xa1;
  }
  else {
    thunk_FUN_0801b6c4(200);
    uVar1 = 0xa0;
  }
  thunk_FUN_0801b6c4(uVar1,unaff_r7);
  return;
}



/* ===== FUN_0801b716 @ 0801b716 ===== */

void FUN_0801b716(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = DAT_0801b878;
  FUN_0801b520(DAT_0801b878,1,0);
  FUN_0801b520(iVar1,2,0);
  FUN_0801b520(iVar1,0x10,0);
  piVar2 = DAT_0801b880;
  do {
  } while (*DAT_0801b880 << 0x18 < 0);
  *(undefined4 *)(iVar1 + 0x28) = 0x20;
  *(undefined1 *)(piVar2 + 1) = 0xa4;
  FUN_0802af42();
  FUN_0801fb94(0);
  FUN_0802af5c(0,0,0x7f,0x2f);
  FUN_0802006c();
  *DAT_0801b890 = 1;
  return;
}



/* ===== FUN_0801b76a @ 0801b76a ===== */

void FUN_0801b76a(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_0801b890;
  FUN_080168b4(DAT_0801b890 + 1);
  *puVar2 = 0;
  FUN_0802af30();
  iVar1 = DAT_0801b878;
  *(undefined4 *)(DAT_0801b878 + 0x28) = 0x20;
  *(undefined4 *)(iVar1 + 0x28) = 0x40;
  FUN_0801b520(iVar1,1,2);
  FUN_0801b520(iVar1,2,2);
  FUN_0801b520(iVar1,0x10,2);
  *DAT_0801b87c = *DAT_0801b87c & 0xffffffbf;
  *DAT_0801b874 = *DAT_0801b874 & 0xffffbfff;
  return;
}



/* ===== FUN_0801b8c8 @ 0801b8c8 ===== */

undefined4 * FUN_0801b8c8(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801b8dc;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801b9a0 @ 0801b9a0 ===== */

undefined4 * FUN_0801b9a0(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801b9b4;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801b9b8 @ 0801b9b8 ===== */

undefined4 * FUN_0801b9b8(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801b9cc;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801b9d0 @ 0801b9d0 ===== */

undefined4 * FUN_0801b9d0(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801b9e4;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801b9e8 @ 0801b9e8 ===== */

undefined4 * FUN_0801b9e8(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801b9fc;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801ba78 @ 0801ba78 ===== */

undefined4 * FUN_0801ba78(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801ba8c;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801ba90 @ 0801ba90 ===== */

undefined4 * FUN_0801ba90(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801baa4;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801baa8 @ 0801baa8 ===== */

undefined4 * FUN_0801baa8(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801babc;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801bac0 @ 0801bac0 ===== */

undefined4 * FUN_0801bac0(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801bad4;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801bad8 @ 0801bad8 ===== */

undefined4 * FUN_0801bad8(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801baec;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801baf0 @ 0801baf0 ===== */

undefined4 * FUN_0801baf0(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801bb04;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801bb08 @ 0801bb08 ===== */

undefined4 * FUN_0801bb08(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801bb1c;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801bb20 @ 0801bb20 ===== */

undefined4 * FUN_0801bb20(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801bb34;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801bb38 @ 0801bb38 ===== */

undefined4 * FUN_0801bb38(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801bb4c;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801bb80 @ 0801bb80 ===== */

undefined4 * FUN_0801bb80(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801bb94;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801bb98 @ 0801bb98 ===== */

undefined4 * FUN_0801bb98(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801bbac;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801bbb0 @ 0801bbb0 ===== */

undefined4 * FUN_0801bbb0(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801bbc4;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801bc58 @ 0801bc58 ===== */

undefined4 * FUN_0801bc58(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801bc6c;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801bc70 @ 0801bc70 ===== */

undefined4 * FUN_0801bc70(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801bc84;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801bc88 @ 0801bc88 ===== */

undefined4 FUN_0801bc88(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  char cVar5;
  
  *(undefined1 *)(param_1 + 0x9f) = 0;
  *(int **)(param_1 + 0xa0) = param_2;
  cVar5 = '\0';
  piVar4 = (int *)(param_1 + 0x1c);
LAB_0801bcac:
  while( true ) {
    piVar3 = param_2;
    param_2 = piVar3 + 1;
    iVar2 = *piVar3;
    if (iVar2 == 0x3c) goto LAB_0801bca0;
    if (iVar2 != 0x3e) break;
    if (*param_2 == 0x3e) goto LAB_0801bca6;
  }
  if (iVar2 == 0) {
    *piVar4 = 0;
    bVar1 = FUN_0802b054(param_1 + 0x1c);
    if (bVar1 < 0x81) {
      if (param_3 == 0) {
        cVar5 = (char)(0x80 - bVar1 >> 1);
      }
      else if (0 < param_3) {
        cVar5 = -0x80 - bVar1;
      }
    }
    else {
      bVar1 = 0x80;
    }
    *(char *)(param_1 + 0x9e) = cVar5;
    *(undefined1 *)(param_1 + 0x9c) = *(undefined1 *)(param_1 + 0x9e);
    *(byte *)(param_1 + 0x9d) = bVar1 + cVar5 + -1;
    return param_4;
  }
  goto LAB_0801bca8;
LAB_0801bca0:
  if (*param_2 == 0x3c) {
LAB_0801bca6:
    param_2 = piVar3 + 2;
LAB_0801bca8:
    *piVar4 = iVar2;
    piVar4 = piVar4 + 1;
  }
  goto LAB_0801bcac;
}



/* ===== FUN_0801bcfa @ 0801bcfa ===== */

longlong FUN_0801bcfa(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = *(int *)(param_1 + 0x10);
  iVar5 = *(int *)(param_1 + 0x14);
  if (iVar5 != iVar2) {
    if (iVar2 < iVar5) {
      iVar4 = 1;
      iVar1 = *(int *)(param_1 + 0x1c);
    }
    else {
      iVar4 = -1;
      iVar1 = *(int *)(param_1 + 0x20);
    }
    puVar3 = (undefined4 *)(iVar1 + iVar2 * 8);
    if (*(char *)(param_1 + 0x18) != '\0') goto LAB_0801bd2e;
    while( true ) {
      if ((code *)*puVar3 != (code *)0x0) {
        (*(code *)*puVar3)();
      }
      iVar1 = puVar3[1];
      if (iVar1 != 0) {
        *(int *)(param_1 + 0x10) = iVar2;
        *(undefined1 *)(param_1 + 0x18) = 1;
        *(int *)(param_1 + 8) = iVar1 + param_2;
        return CONCAT44(param_4,param_1);
      }
LAB_0801bd2e:
      iVar2 = iVar2 + iVar4;
      if (iVar2 == iVar5) break;
      puVar3 = puVar3 + iVar4 * 2;
    }
    *(int *)(param_1 + 0x10) = iVar2;
  }
  *(undefined1 *)(param_1 + 0x18) = 0;
  return (ulonglong)param_4 << 0x20;
}



/* ===== FUN_0801bd70 @ 0801bd70 ===== */

void FUN_0801bd70(int param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_0801c824;
  if (param_1 == 0) {
    *(uint *)(DAT_0801c820 + 0xcc) = *(uint *)(DAT_0801c820 + 0xcc) & 0xfffffeff;
    FUN_08015b44();
    *puVar1 = *puVar1 & 0xfffffffe;
    FUN_0802086a(0);
    return;
  }
  *(uint *)(DAT_0801c820 + 0xcc) = *(uint *)(DAT_0801c820 + 0xcc) | 0x100;
  FUN_08015b44(1);
  *puVar1 = *puVar1 | 1;
  return;
}



/* ===== FUN_0801bdae @ 0801bdae ===== */

undefined1 FUN_0801bdae(undefined1 *param_1)

{
  return *param_1;
}



/* ===== FUN_0801c09e @ 0801c09e ===== */

undefined4 FUN_0801c09e(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0801c820;
  if (param_1 == DAT_0801c820) {
    *(int *)(DAT_0801c820 + 100) = param_2;
    iVar2 = FUN_0801c998(DAT_0801cac4,iVar1 + 0xc,2);
    if (iVar2 != param_2) {
      *(undefined4 *)(iVar1 + 100) = 0xffffffff;
      *(undefined4 *)(param_1 + 0xc) = 0;
      return 0;
    }
  }
  return 1;
}



/* ===== FUN_0801c102 @ 0801c102 ===== */

undefined4 FUN_0801c102(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar1 = DAT_0801c820;
  if (param_1 == DAT_0801c820) {
    *(int *)(DAT_0801c820 + 0x6c) = param_2;
    iVar2 = FUN_0801c998(DAT_0801c994,iVar1 + 0x10,8);
    if (iVar2 != param_2) {
      *(undefined4 *)(iVar1 + 0x6c) = 0xffffffff;
      uVar3 = DAT_0801cbec[1];
      uVar4 = DAT_0801cbec[2];
      uVar5 = DAT_0801cbec[3];
      *(undefined4 *)(param_1 + 0x10) = *DAT_0801cbec;
      *(undefined4 *)(param_1 + 0x14) = uVar3;
      *(undefined4 *)(param_1 + 0x18) = uVar4;
      *(undefined4 *)(param_1 + 0x1c) = uVar5;
      return 0;
    }
  }
  return 1;
}



/* ===== FUN_0801c168 @ 0801c168 ===== */

undefined4 FUN_0801c168(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar1 = DAT_0801c820;
  if (param_1 == DAT_0801c820) {
    *(int *)(DAT_0801c820 + 0x70) = param_2;
    iVar2 = FUN_0801c998(DAT_0801c994,iVar1 + 0x20,8);
    if (iVar2 != param_2) {
      *(undefined4 *)(iVar1 + 0x70) = 0xffffffff;
      uVar3 = DAT_0801cac8[1];
      uVar4 = DAT_0801cac8[2];
      uVar5 = DAT_0801cac8[3];
      *(undefined4 *)(param_1 + 0x20) = *DAT_0801cac8;
      *(undefined4 *)(param_1 + 0x24) = uVar3;
      *(undefined4 *)(param_1 + 0x28) = uVar4;
      *(undefined4 *)(param_1 + 0x2c) = uVar5;
      return 0;
    }
  }
  return 1;
}



/* ===== FUN_0801c1f8 @ 0801c1f8 ===== */

longlong FUN_0801c1f8(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar1 = DAT_0801c820;
  if (param_1 == DAT_0801c820) {
    *(int *)(DAT_0801c820 + 0x68) = param_2;
    iVar2 = FUN_0801c998(DAT_0801c994,iVar1 + 0x30,0xc);
    if (iVar2 != param_2) {
      *(undefined4 *)(iVar1 + 0x68) = 0xffffffff;
      uVar3 = DAT_0801cbf0[1];
      uVar4 = DAT_0801cbf0[2];
      uVar5 = DAT_0801cbf0[3];
      uVar6 = DAT_0801cbf0[4];
      uVar7 = DAT_0801cbf0[5];
      *(undefined4 *)(param_1 + 0x30) = *DAT_0801cbf0;
      *(undefined4 *)(param_1 + 0x34) = uVar3;
      *(undefined4 *)(param_1 + 0x38) = uVar4;
      *(undefined4 *)(param_1 + 0x3c) = uVar5;
      *(undefined4 *)(param_1 + 0x40) = uVar6;
      *(undefined4 *)(param_1 + 0x44) = uVar7;
      return (ulonglong)param_4 << 0x20;
    }
  }
  return CONCAT44(param_4,1);
}



/* ===== FUN_0801c828 @ 0801c828 ===== */

void FUN_0801c828(int param_1)

{
  char *pcVar1;
  uint *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  
  puVar2 = DAT_0801d334;
  pcVar1 = DAT_0801c994;
  puVar4 = (undefined2 *)(param_1 + 0xc);
  if (*DAT_0801c994 != '\x02') {
    *DAT_0801c994 = '\x02';
    puVar2[2] = puVar2[2] & 0xffffff9f;
    puVar2[2] = puVar2[2] & 0xffffff7f;
    puVar2[5] = 0x8005;
    puVar2[2] = puVar2[2] & 0xffffffe7 | 8;
    puVar2[4] = 0xffffffff;
  }
  puVar2[2] = puVar2[2] | 1;
  puVar3 = (undefined2 *)(param_1 + 0x10);
  if (puVar4 < puVar3) {
    for (; puVar4 < puVar3; puVar4 = puVar4 + 1) {
      *(undefined2 *)puVar2 = *puVar4;
    }
  }
  *(uint *)(param_1 + 100) = *puVar2 & 0xffff;
  puVar4 = (undefined2 *)(param_1 + 0x30);
  if (*pcVar1 != '\x02') {
    *pcVar1 = '\x02';
    puVar2[2] = puVar2[2] & 0xffffff9f;
    puVar2[2] = puVar2[2] & 0xffffff7f;
    puVar2[5] = 0x8005;
    puVar2[2] = puVar2[2] & 0xffffffe7 | 8;
    puVar2[4] = 0xffffffff;
  }
  puVar2[2] = puVar2[2] | 1;
  puVar5 = (undefined2 *)(param_1 + 0x48);
  if (puVar4 < puVar5) {
    for (; puVar4 < puVar5; puVar4 = puVar4 + 1) {
      *(undefined2 *)puVar2 = *puVar4;
    }
  }
  *(uint *)(param_1 + 0x68) = *puVar2 & 0xffff;
  puVar4 = (undefined2 *)(param_1 + 0x10);
  if (*pcVar1 != '\x02') {
    *pcVar1 = '\x02';
    puVar2[2] = puVar2[2] & 0xffffff9f;
    puVar2[2] = puVar2[2] & 0xffffff7f;
    puVar2[5] = 0x8005;
    puVar2[2] = puVar2[2] & 0xffffffe7 | 8;
    puVar2[4] = 0xffffffff;
  }
  puVar2[2] = puVar2[2] | 1;
  if (puVar3 < (undefined2 *)(param_1 + 0x20)) {
    for (; puVar4 < (undefined2 *)(param_1 + 0x20); puVar4 = puVar4 + 1) {
      *(undefined2 *)puVar2 = *puVar4;
    }
  }
  *(uint *)(param_1 + 0x6c) = *puVar2 & 0xffff;
  puVar4 = (undefined2 *)(param_1 + 0x48);
  if (*pcVar1 != '\x02') {
    *pcVar1 = '\x02';
    puVar2[2] = puVar2[2] & 0xffffff9f;
    puVar2[2] = puVar2[2] & 0xffffff7f;
    puVar2[5] = 0x8005;
    puVar2[2] = puVar2[2] & 0xffffffe7 | 8;
    puVar2[4] = 0xffffffff;
  }
  puVar2[2] = puVar2[2] | 1;
  if (puVar5 < (undefined2 *)(param_1 + 0x54)) {
    for (; puVar4 < (undefined2 *)(param_1 + 0x54); puVar4 = puVar4 + 1) {
      *(undefined2 *)puVar2 = *puVar4;
    }
  }
  *(uint *)(param_1 + 0x74) = *puVar2 & 0xffff;
  return;
}



/* ===== FUN_0801c998 @ 0801c998 ===== */

uint FUN_0801c998(char *param_1,undefined2 *param_2,int param_3)

{
  uint *puVar1;
  undefined2 *puVar2;
  
  puVar1 = DAT_0801d334;
  if (*param_1 != '\x02') {
    *param_1 = '\x02';
    puVar1[2] = puVar1[2] & 0xffffff9f;
    puVar1[2] = puVar1[2] & 0xffffff7f;
    puVar1[5] = 0x8005;
    puVar1[2] = puVar1[2] & 0xffffffe7 | 8;
    puVar1[4] = 0xffffffff;
  }
  puVar1[2] = puVar1[2] | 1;
  puVar2 = param_2 + param_3;
  if (param_2 < puVar2) {
    for (; param_2 < puVar2; param_2 = param_2 + 1) {
      *(undefined2 *)puVar1 = *param_2;
    }
  }
  return *puVar1 & 0xffff;
}



/* ===== FUN_0801c9f4 @ 0801c9f4 ===== */

uint FUN_0801c9f4(char *param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = DAT_0801d334;
  if (*param_1 != '\x03') {
    *param_1 = '\x03';
    puVar1[2] = puVar1[2] & 0xffffff9f;
    puVar1[2] = puVar1[2] & 0xffffff7f;
    puVar1[5] = 7;
    puVar1[2] = puVar1[2] & 0xffffffe7 | 0x10;
    puVar1[4] = 0xffffffff;
  }
  puVar1[2] = puVar1[2] | 1;
  *(char *)puVar1 = (char)(param_2 >> 0x10);
  *(char *)puVar1 = (char)(param_2 >> 0x18);
  *(char *)puVar1 = (char)(param_2 & 0xffff00ff);
  return param_2 & 0xffff00ff | (*puVar1 & 0xff) << 8;
}



/* ===== FUN_0801ca4c @ 0801ca4c ===== */

undefined8 FUN_0801ca4c(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_18;
  int local_14;
  
  iVar2 = DAT_0801d348;
  uVar5 = 1;
  bVar1 = true;
  local_14 = param_1;
  if (DAT_0801d34c <= *(uint *)(DAT_0801d348 + 0x60)) {
    *(undefined4 *)(DAT_0801d348 + 0x60) = DAT_0801d350;
    iVar3 = FUN_08025636();
    if (iVar3 != 0) {
      FUN_08016b06(4);
    }
    local_14 = DAT_0801d354;
    uVar5 = 0;
    bVar1 = false;
  }
  FUN_080254a0(*(undefined4 *)(iVar2 + 0x60),4,&local_14);
  FUN_0802543c(*(undefined4 *)(iVar2 + 0x60),4,&local_18);
  if (local_18 != local_14) {
    local_14 = 0;
    FUN_080254a0(*(undefined4 *)(iVar2 + 0x60),4,&local_14);
    if (bVar1) {
      uVar4 = 5;
    }
    else {
      uVar4 = 0;
    }
    FUN_08016b06(uVar4);
  }
  *(int *)(iVar2 + 0x60) = *(int *)(iVar2 + 0x60) + 4;
  return CONCAT44(local_18,uVar5);
}



/* ===== FUN_0801cacc @ 0801cacc ===== */

undefined4 FUN_0801cacc(void)

{
  ushort *puVar1;
  undefined4 uVar2;
  int iVar3;
  ushort *puVar4;
  undefined4 uVar5;
  uint *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  undefined4 in_r3;
  code *pcVar10;
  char *pcVar11;
  ushort *puVar12;
  
  iVar3 = DAT_0801d348;
  uVar2 = DAT_0801cbf4;
  pcVar11 = (char *)(DAT_0801d348 + 0x5c);
  *(float *)(DAT_0801d348 + 0xc4) = *(float *)(DAT_0801d348 + 0xc4) * 4.0;
  *(float *)(iVar3 + 200) = *(float *)(iVar3 + 200) * 16.0;
  FUN_0802578a();
  if (*pcVar11 == '\0') {
    FUN_080249ac(iVar3,uVar2,0x5c);
    FUN_0801d0d8(iVar3);
    FUN_0801c828(iVar3);
    *(undefined4 *)(iVar3 + 0x60) = DAT_0801d358;
    FUN_0801ca4c(0);
  }
  uVar5 = DAT_0801d360;
  puVar4 = DAT_0801d35c;
  puVar1 = puVar4;
  while (puVar12 = puVar1 + 6, *puVar12 != 0xffff) {
    pcVar10 = *(code **)(puVar1 + 8);
    puVar1 = puVar12;
    if (pcVar10 != (code *)0x0) {
      iVar8 = (*pcVar10)(iVar3 + 0x78);
      iVar9 = (*pcVar10)(iVar3);
      if (iVar8 != iVar9) {
        FUN_0801c9f4(uVar5,(uint)*puVar12 | iVar8 << 0x10);
        iVar8 = FUN_0801ca4c();
        if (iVar8 == 0) {
          if (*pcVar11 == '\0') goto LAB_0801cb9e;
          *pcVar11 = '\0';
          FUN_080249ac(iVar3,uVar2,0x5c);
          FUN_0801d0d8(iVar3);
          FUN_0801c828(iVar3);
          puVar1 = puVar4;
        }
      }
    }
  }
  FUN_080249ac(iVar3,iVar3 + 0x78,0x5c);
  FUN_0801c828(iVar3);
  *pcVar11 = '\x01';
LAB_0801cb9e:
  FUN_080257b6();
  FUN_0802b0e4(uVar5,0);
  puVar7 = DAT_0801d368;
  puVar6 = DAT_0801d364;
  *(float *)(iVar3 + 0xc4) = *(float *)(iVar3 + 0xc4) * 0.25;
  *(float *)(iVar3 + 200) = *(float *)(iVar3 + 200) * DAT_0801ce24;
  *puVar6 = *puVar6 | 0x100;
  *puVar7 = 0;
  *puVar6 = *puVar6 & 0xfffffeff;
  return in_r3;
}



/* ===== FUN_0801cbf8 @ 0801cbf8 ===== */

void FUN_0801cbf8(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iVar6;
  undefined1 uVar7;
  uint *puVar8;
  uint *puVar9;
  code *pcVar10;
  undefined4 in_r3;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined1 *puVar14;
  
  puVar5 = DAT_0801d370;
  uVar2 = DAT_0801d360;
  iVar3 = DAT_0801d35c;
  uVar11 = DAT_0801d350;
  iVar1 = DAT_0801d348;
  puVar14 = (undefined1 *)(DAT_0801d348 + 0x5c);
  if ((*DAT_0801d368 & 0xfffffff0) == DAT_0801d36c) {
    iVar3 = 0x19;
    puVar8 = DAT_0801d370;
    puVar9 = DAT_0801d374;
    do {
      *puVar8 = *puVar9;
      iVar3 = iVar3 + -1;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
    } while (iVar3 != 0);
    FUN_080249ac(iVar1 + 0x78,DAT_0801d32c,0x5c);
    FUN_0801d0d8(iVar1 + 0x78);
    uVar11 = puVar5[5];
    uVar12 = puVar5[6];
    uVar13 = puVar5[7];
    *(uint *)(iVar1 + 0x88) = puVar5[4];
    *(uint *)(iVar1 + 0x8c) = uVar11;
    *(uint *)(iVar1 + 0x90) = uVar12;
    *(uint *)(iVar1 + 0x94) = uVar13;
    *puVar14 = 0;
    goto LAB_0801cd22;
  }
  FUN_080249ac(DAT_0801d348,DAT_0801d32c,0x5c);
  FUN_0801d0d8(iVar1);
  FUN_0801c828(iVar1);
  uVar12 = DAT_0801d350;
  *puVar14 = 1;
  *(uint *)(iVar1 + 0x60) = uVar12;
  FUN_0802578a();
  do {
    uVar12 = uVar11 & 0xfff;
    if (((uVar12 == 0) &&
        (FUN_0802543c(uVar11,0x1000,puVar5), uVar13 = DAT_0801d378, uVar11 == DAT_0801d350)) &&
       (uVar12 = 4, uVar11 = DAT_0801d378, (*puVar5 & 0xfffffff0) != DAT_0801d36c)) {
      *puVar14 = 0;
      uVar11 = uVar13;
      break;
    }
    uVar13 = *(uint *)((int)puVar5 + uVar12);
    if (uVar13 != 0) {
      if (uVar13 == 0xffffffff) {
        puVar5 = (uint *)((int)puVar5 + uVar12);
        goto LAB_0801cd96;
      }
      uVar12 = FUN_0801c9f4(uVar2,uVar13);
      if (uVar12 == uVar13) {
        uVar12 = uVar13 & 0xff;
        if (uVar12 < 0x5b) {
          if (*(ushort *)(iVar3 + uVar12 * 0xc) != uVar12) {
            FUN_08016b06(1,uVar13 >> 0x10);
            break;
          }
          pcVar10 = *(code **)(iVar3 + uVar12 * 0xc + 8);
          if ((pcVar10 != (code *)0x0) && (iVar6 = (*pcVar10)(iVar1), iVar6 == 0)) {
            *puVar14 = 0;
            uVar4 = 2;
            goto LAB_0801cde2;
          }
        }
      }
      else {
        *puVar14 = 0;
        uVar4 = 3;
LAB_0801cde2:
        FUN_08016b06(uVar4);
      }
    }
    uVar11 = uVar11 + 4;
  } while (uVar11 < DAT_0801d384);
  goto LAB_0801cce6;
LAB_0801cd96:
  if (0xffc < uVar12) goto code_r0x0801cd9a;
  if (*puVar5 != 0xffffffff) goto LAB_0801cdb0;
  uVar12 = uVar12 + 4;
  puVar5 = puVar5 + 1;
  goto LAB_0801cd96;
code_r0x0801cd9a:
  if ((0x1000 - uVar12 != 0) &&
     (uVar12 = (0x1000 - uVar12) * 8, *puVar5 >> (uVar12 & 0xff) != 0xffffffffU >> (uVar12 & 0xff)))
  {
LAB_0801cdb0:
    *puVar14 = 0;
  }
LAB_0801cce6:
  FUN_080257b6();
  *(uint *)(iVar1 + 0x60) = uVar11;
  FUN_080249ac(iVar1 + 0x78,iVar1,0x5c);
  FUN_0802b0e4(uVar2,0);
  *(float *)(iVar1 + 0xc4) = *(float *)(iVar1 + 0xc4) * 0.25;
  *(float *)(iVar1 + 200) = *(float *)(iVar1 + 200) * DAT_0801ce24;
LAB_0801cd22:
  *(undefined1 *)(iVar1 + 0xd8) = 0;
  iVar3 = FUN_08015b04(*(undefined1 *)(iVar1 + 0x78),1);
  *(char *)(iVar1 + 0x78) = (char)iVar3;
  *DAT_0801d380 = *(undefined4 *)(DAT_0801d37c + iVar3 * 4);
  FUN_0801bd70((*(uint *)(iVar1 + 0xcc) & 0x1ff) >> 8);
  FUN_0801d248(*(undefined4 *)(iVar1 + 0xa8));
  FUN_0801d26e(*(undefined4 *)(iVar1 + 0xac));
  FUN_0801d298(*(undefined4 *)(iVar1 + 0xb0));
  FUN_0801d2bc(*(undefined4 *)(iVar1 + 0xb4));
  FUN_0801d2e4(*(undefined4 *)(iVar1 + 0xb8));
  FUN_0801d308(*(undefined4 *)(iVar1 + 0xbc));
  if ((int)((uint)*(byte *)(iVar1 + 0xcc) << 0x1f) < 0) {
    *(undefined1 *)(iVar1 + 0xe4) = 0xb;
    uVar7 = 3;
  }
  else {
    *(undefined1 *)(iVar1 + 0xe4) = 0xe;
    uVar7 = 6;
  }
  *(undefined1 *)(iVar1 + 0xf8) = uVar7;
  uVar11 = FUN_08016030((*(uint *)(iVar1 + 0xd0) & 0x1fff) >> 10);
  *(uint *)(iVar1 + 0xd0) = *(uint *)(iVar1 + 0xd0) & 0xffffe3ff | (uVar11 & 7) << 10;
  FUN_0801b220(in_r3);
  return;
}



/* ===== FUN_0801ce28 @ 0801ce28 ===== */

void FUN_0801ce28(void)

{
  uint *puVar1;
  ushort uVar2;
  int iVar3;
  uint *puVar4;
  undefined2 uVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  uint uVar9;
  int local_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  iVar3 = DAT_0801d348;
  iVar7 = DAT_0801d32c;
  uVar9 = *(uint *)(DAT_0801d32c + 0x58);
  puVar8 = (undefined1 *)(DAT_0801d348 + 0x78);
  *(uint *)(DAT_0801d348 + 0xd0) =
       *(uint *)(DAT_0801d348 + 0xd0) & 0xffffffdf | (uVar9 >> 5 & 1) << 5;
  FUN_0801bd70((*(uint *)(iVar7 + 0x54) & 0x1ff) >> 8);
  if (*(int *)(iVar3 + 0xa8) == 0x28) {
LAB_0801ce64:
    if (*(int *)(iVar3 + 0xac) != 0x78) goto LAB_0801ce6a;
  }
  else {
    *(undefined4 *)(iVar3 + 0xa8) = 0x28;
    if (0x27 < *(uint *)(iVar3 + 0xac)) goto LAB_0801ce64;
    *(undefined4 *)(iVar3 + 0xac) = 0x28;
LAB_0801ce6a:
    *(undefined4 *)(iVar3 + 0xac) = 0x78;
    if (0x78 < *(uint *)(iVar3 + 0xa8)) {
      *(undefined4 *)(iVar3 + 0xa8) = 0x78;
    }
  }
  uVar6 = DAT_0801d388;
  if (*(uint *)(iVar3 + 0xb0) != DAT_0801d388) {
    *(uint *)(iVar3 + 0xb0) = DAT_0801d388;
    if (*(uint *)(iVar3 + 0xb4) < uVar6) {
      *(uint *)(iVar3 + 0xb4) = uVar6;
      goto LAB_0801ce9c;
    }
  }
  if (*(uint *)(iVar3 + 0xb4) != uVar6) {
    *(uint *)(iVar3 + 0xb4) = uVar6;
    if (uVar6 < *(uint *)(iVar3 + 0xb0)) {
      *(uint *)(iVar3 + 0xb0) = uVar6;
    }
  }
LAB_0801ce9c:
  *(undefined4 *)(iVar3 + 0xb8) = 200;
  if (*(uint *)(iVar3 + 0xbc) < 200) {
    *(undefined4 *)(iVar3 + 0xbc) = 200;
  }
  *(undefined4 *)(iVar3 + 0xbc) = 600;
  uVar6 = FUN_08016030((uVar9 & 0x1fff) >> 10);
  *(uint *)(iVar3 + 0xd0) = *(uint *)(iVar3 + 0xd0) & 0xffffe3ff | (uVar6 & 7) << 10;
  FUN_0801d224((uVar9 & 0x7fff) >> 0xd);
  local_34 = *(undefined4 *)(iVar3 + 0x88);
  uStack_30 = *(undefined4 *)(iVar3 + 0x8c);
  uStack_2c = *(undefined4 *)(iVar3 + 0x90);
  uStack_28 = *(undefined4 *)(iVar3 + 0x94);
  local_44 = *(undefined4 *)(iVar3 + 0x98);
  uStack_40 = *(undefined4 *)(iVar3 + 0x9c);
  uStack_3c = *(undefined4 *)(iVar3 + 0xa0);
  uStack_38 = *(undefined4 *)(iVar3 + 0xa4);
  FUN_080249ac(puVar8,iVar7,0x5c);
  FUN_0801d0d8(puVar8);
  iVar7 = FUN_0801d062(0x50,&local_48,1,DAT_0801d38c);
  if ((iVar7 != 0) && (iVar7 = FUN_08022d22(), iVar7 != local_48)) {
    FUN_08022ce0(local_48);
  }
  *(undefined4 *)(iVar3 + 0x88) = local_34;
  *(undefined4 *)(iVar3 + 0x8c) = uStack_30;
  *(undefined4 *)(iVar3 + 0x90) = uStack_2c;
  *(undefined4 *)(iVar3 + 0x94) = uStack_28;
  *(undefined4 *)(iVar3 + 0x98) = local_44;
  *(undefined4 *)(iVar3 + 0x9c) = uStack_40;
  *(undefined4 *)(iVar3 + 0xa0) = uStack_3c;
  *(undefined4 *)(iVar3 + 0xa4) = uStack_38;
  iVar7 = FUN_08015b04(*puVar8,1);
  *puVar8 = (char)iVar7;
  *DAT_0801d380 = *(undefined4 *)(DAT_0801d37c + iVar7 * 4);
  if ((int)((uint)*(byte *)(iVar3 + 0xcc) << 0x1f) < 0) {
    *(undefined1 *)(iVar3 + 0xe4) = 0xb;
    *(undefined1 *)(iVar3 + 0xf8) = 3;
  }
  else {
    *(undefined1 *)(iVar3 + 0xe4) = 0xe;
    *(undefined1 *)(iVar3 + 0xf8) = 6;
  }
  *(uint *)(iVar3 + 0xdc) = *(uint *)(iVar3 + 0xdc) & DAT_0801d390 | 8;
  uVar5 = FUN_0801862e();
  puVar4 = DAT_0801d39c;
  uVar9 = *DAT_0801d394 & 0xffff;
  while (uVar9 != (*DAT_0801d394 & 0xffff)) {
    uVar9 = *DAT_0801d394 & 0xffff;
  }
  uVar2 = *DAT_0801d398 + (short)uVar9;
  if (uVar2 < (ushort)*DAT_0801d39c) {
    uVar9 = *DAT_0801d39c;
    puVar1 = DAT_0801d39c + 1;
    *DAT_0801d39c = uVar9 + 0x10000;
    puVar4[1] = *puVar1 + (uint)(0xfffeffff < uVar9);
  }
  *(ushort *)puVar4 = uVar2;
  FUN_08018a4c(*puVar4,puVar4[1],uVar5,3);
  return;
}



/* ===== FUN_0801cfc6 @ 0801cfc6 ===== */

undefined8 FUN_0801cfc6(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = DAT_0801d38c;
  while (*piVar1 != -1) {
    iVar2 = iVar2 + 4;
    piVar1 = piVar1 + 1;
  }
  if (iVar2 < param_2) {
    param_2 = iVar2;
  }
  FUN_0802498c(param_1,DAT_0801d38c,param_2);
  return CONCAT44(param_4,param_2);
}



/* ===== FUN_0801cff0 @ 0801cff0 ===== */

undefined8
FUN_0801cff0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_10;
  
  if (-1 < *(int *)(DAT_0801d348 + 0xdc) << 0xb) {
    return CONCAT44(param_4,0xffffffff);
  }
  *param_1 = DAT_0801d3a0;
  local_10 = param_4;
  FUN_08017d24(param_1);
  iVar1 = FUN_0801d062(0x10,&local_10,1,param_1);
  if (iVar1 != 0) {
    FUN_080230f4(local_10);
  }
  return CONCAT44(local_10,param_2);
}



/* ===== FUN_0801d030 @ 0801d030 ===== */

float FUN_0801d030(float param_1,float *param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  
  if (param_3 < 0) {
    return DAT_0801d304;
  }
  fVar2 = param_2[param_3];
  pfVar1 = param_2 + param_3 + -1;
  if (param_2 <= pfVar1) {
    for (; param_2 <= pfVar1; pfVar1 = pfVar1 + -1) {
      fVar2 = *pfVar1 + fVar2 * param_1;
    }
  }
  return fVar2;
}



/* ===== FUN_0801d062 @ 0801d062 ===== */

uint FUN_0801d062(uint param_1,undefined4 param_2,uint param_3,int *param_4)

{
  ushort *puVar1;
  uint uVar2;
  
  puVar1 = (ushort *)(param_4 + 1);
  if (*param_4 == DAT_0801d3a0) {
    while( true ) {
      if (puVar1[1] == 0xffff) break;
      uVar2 = (uint)*puVar1;
      if (puVar1[1] == param_1) {
        if (param_3 < uVar2) {
          return 0;
        }
        FUN_0802498c(param_2,puVar1 + 2,uVar2 << 2);
        return uVar2;
      }
      puVar1 = puVar1 + 2 + uVar2 * 2;
    }
  }
  return 0;
}



/* ===== FUN_0801d09c @ 0801d09c ===== */

uint FUN_0801d09c(uint param_1,undefined4 param_2,uint param_3)

{
  ushort *puVar1;
  uint uVar2;
  
  puVar1 = (ushort *)(DAT_0801d38c + 1);
  if (*DAT_0801d38c == DAT_0801d3a0) {
    for (; puVar1[1] != 0xffff; puVar1 = puVar1 + uVar2 * 2 + 2) {
      uVar2 = (uint)*puVar1;
      if (puVar1[1] == param_1) {
        if (param_3 < uVar2) {
          return 0;
        }
        FUN_0802498c(param_2,puVar1 + 2,uVar2 << 2);
        return uVar2;
      }
    }
  }
  return 0;
}



/* ===== FUN_0801d0d8 @ 0801d0d8 ===== */

undefined4 FUN_0801d0d8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_0801d062(0x20,param_1 + 0x48,3,DAT_0801d38c);
  if (iVar1 == 0) {
    FUN_08016a90(0x19);
    uVar2 = DAT_0801d3a4[1];
    uVar3 = DAT_0801d3a4[2];
    *(undefined4 *)(param_1 + 0x48) = *DAT_0801d3a4;
    *(undefined4 *)(param_1 + 0x4c) = uVar2;
    *(undefined4 *)(param_1 + 0x50) = uVar3;
  }
  if (param_1 == DAT_0801d3a8) {
    *(float *)(param_1 + 0x4c) = *(float *)(param_1 + 0x4c) * 0.25;
    *(float *)(param_1 + 0x50) = *(float *)(param_1 + 0x50) * DAT_0801d330;
    FUN_0801b220();
    uVar2 = FUN_08016020(param_4);
    return uVar2;
  }
  return param_4;
}



/* ===== FUN_0801d134 @ 0801d134 ===== */

undefined4 FUN_0801d134(int param_1)

{
  return *(undefined4 *)(DAT_0801d348 + param_1 * 4 + 0xc0);
}



/* ===== FUN_0801d150 @ 0801d150 ===== */

longlong FUN_0801d150(float *param_1,int param_2)

{
  bool bVar1;
  uint unaff_r7;
  float fVar2;
  
  if (param_2 < 1) {
    FUN_0801d0d8(DAT_0801d3a8);
    return (ulonglong)unaff_r7 << 0x20;
  }
  if ((param_2 == 0xc) && (ABS(*param_1) < DAT_0801d338)) {
    fVar2 = 1.0;
    bVar1 = 1.0 <= param_1[1];
    if (bVar1) {
      fVar2 = param_1[2];
    }
    if (((bVar1 && (bVar1 && 0.0 <= fVar2)) &&
        (fVar2 = *param_1 + (param_1[1] + fVar2 * DAT_0801d33c) * DAT_0801d33c,
        DAT_0801d340 <= fVar2)) && (fVar2 < DAT_0801d344)) {
      FUN_0802498c(DAT_0801d3ac,param_1,0xc);
      FUN_0801b220();
      FUN_08016020();
      return CONCAT44(unaff_r7,0xc);
    }
  }
  return CONCAT44(unaff_r7,0xffffffff);
}



/* ===== FUN_0801d1de @ 0801d1de ===== */

undefined4 FUN_0801d1de(float param_1)

{
  undefined4 unaff_r7;
  
  FUN_08029d88(DAT_0801d3ac[2] * (2.0 / DAT_0801d3ac[1]) *
               (param_1 - *DAT_0801d3ac) * (2.0 / DAT_0801d3ac[1]) + 1.0);
  return unaff_r7;
}



/* ===== FUN_0801d224 @ 0801d224 ===== */

ulonglong FUN_0801d224(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint unaff_r7;
  
  uVar2 = *(uint *)(DAT_0801d348 + 0xd0);
  if (3 < param_1) {
    param_1 = 3;
  }
  *(uint *)(DAT_0801d348 + 0xd0) = uVar2 & 0xffff9fff | (param_1 & 3) << 0xd;
  if (-1 < (int)(uVar2 << 0x19)) {
    return (ulonglong)param_1;
  }
  if (*(char *)(DAT_0801a14c + 0x18) == '\0') {
    return (ulonglong)unaff_r7 << 0x20;
  }
  iVar1 = FUN_08029934(1,param_1 + 4 & 0xff);
  return CONCAT44(unaff_r7,~-(uint)(iVar1 == 0) >> 0x1f);
}



/* ===== FUN_0801d248 @ 0801d248 ===== */

void FUN_0801d248(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar2 = DAT_0801d3b0;
  if (param_1 != *DAT_0801d3b0) {
    if (param_1 == 0) {
      param_1 = 1;
    }
    else if (40000 < param_1) {
      param_1 = 40000;
    }
    puVar1 = DAT_0801d3b0 + 1;
    *DAT_0801d3b0 = param_1;
    if (param_1 < *puVar1) {
      param_1 = *puVar1;
    }
    puVar2[1] = param_1;
  }
  return;
}



/* ===== FUN_0801d26e @ 0801d26e ===== */

void FUN_0801d26e(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_0801d3b0;
  if (param_1 != DAT_0801d3b0[1]) {
    if (param_1 == 0) {
      param_1 = 1;
    }
    else if (40000 < param_1) {
      param_1 = 40000;
    }
    uVar2 = *(uint *)(DAT_0801d348 + 0xa8);
    DAT_0801d3b0[1] = param_1;
    if (uVar2 < param_1) {
      param_1 = uVar2;
    }
    *puVar1 = param_1;
  }
  return;
}



/* ===== FUN_0801d298 @ 0801d298 ===== */

void FUN_0801d298(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar2 = DAT_0801d3b4;
  if (param_1 != *DAT_0801d3b4) {
    if (param_1 == 0) {
      param_1 = 1;
    }
    else if (DAT_0801d388 < param_1) {
      param_1 = DAT_0801d388;
    }
    puVar1 = DAT_0801d3b4 + 1;
    *DAT_0801d3b4 = param_1;
    if (param_1 < *puVar1) {
      param_1 = *puVar1;
    }
    puVar2[1] = param_1;
  }
  return;
}



/* ===== FUN_0801d2bc @ 0801d2bc ===== */

void FUN_0801d2bc(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_0801d3b4;
  if (param_1 != DAT_0801d3b4[1]) {
    if (param_1 == 0) {
      param_1 = 1;
    }
    else if (DAT_0801d388 < param_1) {
      param_1 = DAT_0801d388;
    }
    uVar2 = *(uint *)(DAT_0801d348 + 0xb0);
    DAT_0801d3b4[1] = param_1;
    if (uVar2 < param_1) {
      param_1 = uVar2;
    }
    *puVar1 = param_1;
  }
  return;
}



/* ===== FUN_0801d2e4 @ 0801d2e4 ===== */

void FUN_0801d2e4(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar2 = DAT_0801d3bc;
  if (param_1 == 0) {
    param_1 = 1;
  }
  else if (DAT_0801d3b8 < param_1) {
    param_1 = DAT_0801d3b8;
  }
  puVar1 = DAT_0801d3bc + 1;
  *DAT_0801d3bc = param_1;
  if (param_1 < *puVar1) {
    param_1 = *puVar1;
  }
  puVar2[1] = param_1;
  return;
}



/* ===== FUN_0801d308 @ 0801d308 ===== */

void FUN_0801d308(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_0801d3bc;
  if (param_1 == 0) {
    param_1 = 1;
  }
  else if (DAT_0801d3b8 < param_1) {
    param_1 = DAT_0801d3b8;
  }
  uVar2 = *(uint *)(DAT_0801d348 + 0xb8);
  DAT_0801d3bc[1] = param_1;
  if (uVar2 < param_1) {
    param_1 = uVar2;
  }
  *puVar1 = param_1;
  return;
}



/* ===== FUN_0801d3c0 @ 0801d3c0 ===== */

undefined8 FUN_0801d3c0(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  char cVar5;
  int *piVar6;
  int *piVar7;
  int local_20 [2];
  
  local_20[0] = 0;
  local_20[1] = 0;
  cVar5 = *(char *)(param_1 + 0x9e);
  bVar4 = cVar5 - 1;
  piVar6 = *(int **)(param_1 + 0xa0);
  do {
    while( true ) {
      piVar7 = piVar6 + 1;
      iVar2 = *piVar6;
      if (iVar2 != 0x3c) break;
      if (*piVar7 == 0x3c) goto LAB_0801d3f6;
      *param_2 = cVar5;
      piVar6 = piVar7;
    }
    if (iVar2 == 0x3e) {
      if (*piVar7 != 0x3e) {
        param_2[1] = bVar4;
        *(int **)(param_1 + 0xa0) = piVar7;
        *(byte *)(param_1 + 0x9e) = bVar4 + 1;
        uVar3 = 1;
LAB_0801d406:
        return CONCAT44(local_20[0],uVar3);
      }
LAB_0801d3f6:
      piVar7 = piVar6 + 2;
    }
    else {
      uVar3 = 0;
      if (iVar2 == 0) goto LAB_0801d406;
    }
    local_20[0] = iVar2;
    cVar1 = FUN_0802b054(local_20);
    bVar4 = (cVar5 + cVar1) - 1;
    if (*(byte *)(param_1 + 0x9d) < bVar4) {
      bVar4 = *(byte *)(param_1 + 0x9d);
    }
    cVar5 = bVar4 + 1;
    piVar6 = piVar7;
  } while( true );
}



/* ===== FUN_0801d428 @ 0801d428 ===== */

void FUN_0801d428(undefined4 *param_1,undefined4 param_2,undefined2 *param_3,undefined4 param_4)

{
  *param_1 = DAT_0801d454;
  param_1[1] = param_2;
  param_1[3] = 0xffffffff;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[4] = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801d458;
  *(undefined1 *)((int)param_1 + 0x16) = 0;
  *(undefined1 *)((int)param_1 + 0x17) = 0;
  *(undefined2 *)(param_1 + 5) = *param_3;
  param_1[6] = param_4;
  return;
}



/* ===== FUN_0801d45c @ 0801d45c ===== */

undefined4 * FUN_0801d45c(undefined4 *param_1)

{
  FUN_0801d428();
  *param_1 = DAT_0801d46c;
  return param_1;
}



/* ===== FUN_0801d470 @ 0801d470 ===== */

undefined4 * FUN_0801d470(undefined4 *param_1)

{
  FUN_0801d428();
  *param_1 = DAT_0801d480;
  return param_1;
}



/* ===== FUN_0801d484 @ 0801d484 ===== */

undefined4 FUN_0801d484(void)

{
  uint *puVar1;
  uint *puVar2;
  undefined2 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 in_r3;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  puVar2 = DAT_0801d7d8;
  puVar1 = DAT_0801d7d4;
  *DAT_0801d7d4 = *DAT_0801d7d4 | 0x100;
  puVar2[9] = 0xca;
  puVar2[9] = 0x53;
  disableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  FUN_0802b3aa(puVar2);
  do {
    uVar9 = puVar2[10];
  } while ((uVar9 & 0xffff) == (puVar2[10] & 0xffff));
  *DAT_0801d7dc = *DAT_0801d7dc & 0xfffffff9 | 4;
  uVar6 = *puVar2 & DAT_0801d7e0;
  uVar8 = puVar2[1] & DAT_0801d7e4;
  uVar4 = (uVar8 >> 0x14) << 4;
  enableIRQinterrupts();
  puVar2[9] = 0xff;
  puVar3 = DAT_0801d7e8;
  *puVar1 = *puVar1 & 0xfffffeff;
  *(uint *)(puVar3 + 10) = (uVar6 >> 8 & 0xf) + ((uVar6 >> 8 & 0xff) >> 4) * 10 & 0xff;
  *(uint *)(puVar3 + 0xc) = (uVar6 >> 0x10 & 0xf) + (uVar6 >> 0x14) * 10 & 0xff;
  *(uint *)(puVar3 + 0xe) =
       ((uVar8 << 0x10 & 0xf0000) >> 0x10) + ((uVar8 << 0x10 & 0xff0000) >> 0x14) * 10 & 0xff;
  *(uint *)(puVar3 + 8) = (uVar6 & 0xf) + ((uVar6 & 0xff) >> 4) * 10 & 0xff;
  *(uint *)(puVar3 + 0x10) =
       (((uVar8 & 0x1f00 | uVar4) >> 8 & 0xf) + ((uVar8 & 0x1f00 | uVar4 & 0xff00) >> 0xc) * 10 &
       0xff) - 1;
  *(uint *)(puVar3 + 0x12) = (((uVar8 & 0xfffff) >> 0x10) + ((uVar4 & 0xff) >> 4) * 10 & 0xff) + 100
  ;
  uVar4 = FUN_0802b440(puVar3 + 8);
  iVar7 = *(int *)(DAT_0801d7ec + 8) << 8;
  uVar8 = iVar7 >> 8;
  uVar6 = uVar4 + uVar8;
  uVar10 = (0xff - (uVar9 & 0xffff)) * 0x80;
  uVar9 = uVar6 * 0x8000;
  iVar5 = uVar10 + uVar9;
  iVar7 = (((iVar7 >> 0x1f) + (uint)CARRY4(uVar4,uVar8)) * 0x8000 | uVar6 >> 0x11) +
          (uint)CARRY4(uVar10,uVar9);
  *(int *)(puVar3 + 4) = iVar5;
  *(int *)(puVar3 + 6) = iVar7;
  *(int *)(puVar3 + 0x20) = iVar5;
  *(int *)(puVar3 + 0x22) = iVar7;
  *(int *)(puVar3 + 0x24) = iVar5;
  *(int *)(puVar3 + 0x26) = iVar7;
  *puVar3 = (short)iVar5;
  return in_r3;
}



/* ===== FUN_0801d5b6 @ 0801d5b6 ===== */

void FUN_0801d5b6(void)

{
  FUN_080168b4(DAT_0801d7f0);
  return;
}



/* ===== FUN_0801d5bc @ 0801d5bc ===== */

void FUN_0801d5bc(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  ushort uVar2;
  uint *puVar3;
  undefined4 uVar4;
  short *psVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  char local_30;
  char local_2f;
  undefined1 local_2e;
  char local_2d;
  uint local_2c;
  undefined1 auStack_28 [4];
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined4 uStack_20;
  
  psVar5 = DAT_0801d7e8;
  if (param_2 != 0 || param_1 != 0) {
    uVar7 = *DAT_0801d7f4 & 0xffff;
    while (uVar7 != (*DAT_0801d7f4 & 0xffff)) {
      uVar7 = *DAT_0801d7f4 & 0xffff;
    }
    uVar2 = *DAT_0801d7e8 + (short)uVar7;
    if (uVar2 < (ushort)DAT_0801d7e8[4]) {
      uVar7 = *(uint *)(DAT_0801d7e8 + 4);
      piVar1 = (int *)(DAT_0801d7e8 + 6);
      *(uint *)(DAT_0801d7e8 + 4) = uVar7 + 0x10000;
      *(uint *)(psVar5 + 6) = *piVar1 + (uint)(0xfffeffff < uVar7);
    }
    psVar5[4] = uVar2;
    uVar7 = *(uint *)(psVar5 + 4);
    iVar10 = (param_2 - *(int *)(psVar5 + 6)) - (uint)(param_1 < uVar7);
    if (-1 < iVar10) {
      uVar8 = param_1 - uVar7 & DAT_0801d7f8;
      uVar9 = uVar8 + 0x10000;
      iVar10 = iVar10 + (uint)(0xfffeffff < uVar8);
      *(uint *)(psVar5 + 4) = uVar7 + uVar9;
      *(uint *)(psVar5 + 6) = *(int *)(psVar5 + 6) + iVar10 + (uint)CARRY4(uVar7,uVar9);
      uVar8 = *(uint *)(psVar5 + 0x20);
      uVar7 = *(uint *)(psVar5 + 0x24);
      *(uint *)(psVar5 + 0x20) = uVar8 + uVar9;
      *(uint *)(psVar5 + 0x22) = *(int *)(psVar5 + 0x22) + iVar10 + (uint)CARRY4(uVar8,uVar9);
      *(uint *)(psVar5 + 0x24) = uVar7 + uVar9;
      *(uint *)(psVar5 + 0x26) = *(int *)(psVar5 + 0x26) + iVar10 + (uint)CARRY4(uVar7,uVar9);
      uVar4 = DAT_0801d7d8;
      puVar3 = DAT_0801d7d4;
      local_2c = param_1 >> 0xf | param_2 << 0x11;
      *(uint *)(DAT_0801d7ec + 8) = *(uint *)(DAT_0801d7ec + 8) & 0xff000000;
      uStack_20 = param_4;
      puVar6 = (undefined4 *)FUN_0802b510(&local_2c);
      local_24 = (undefined1)puVar6[2];
      local_23 = (undefined1)puVar6[1];
      local_22 = (undefined1)*puVar6;
      local_2d = (char)puVar6[5] + -100;
      local_2f = (char)puVar6[4] + '\x01';
      local_30 = (char)puVar6[6] + '\x01';
      local_2e = (undefined1)puVar6[3];
      *puVar3 = *puVar3 | 0x100;
      FUN_0802b1ca(uVar4,0,auStack_28);
      FUN_0802b2aa(uVar4,0,&local_30);
      *puVar3 = *puVar3 & 0xfffffeff;
    }
  }
  return;
}



/* ===== FUN_0801d6e2 @ 0801d6e2 ===== */

void FUN_0801d6e2(char *param_1,uint param_2)

{
  char cVar1;
  
  param_1[5] = '\0';
  param_1[4] = ((byte)(param_2 >> 8) & 0xf) + 0x30;
  param_1[3] = ((byte)(param_2 >> 0xc) & 0xf) + 0x30;
  if ((int)(param_2 << 0x1f) < 0) {
    cVar1 = ':';
  }
  else {
    cVar1 = ' ';
  }
  param_1[2] = cVar1;
  param_1[1] = ((byte)(param_2 >> 0x10) & 0xf) + 0x30;
  *param_1 = (char)((param_2 >> 0x10 & 0xff) >> 4) + '0';
  return;
}



/* ===== FUN_0801d724 @ 0801d724 ===== */

undefined4 FUN_0801d724(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  puVar2 = DAT_0801d7d8;
  puVar1 = DAT_0801d7d4;
  *DAT_0801d7d4 = *DAT_0801d7d4 | 0x100;
  puVar2[9] = 0xca;
  puVar2[9] = 0x53;
  disableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  FUN_0802b3aa(puVar2);
  uVar5 = *puVar2 & DAT_0801d7e0;
  FUN_0802b1ca(puVar2,0,param_1);
  iVar3 = DAT_0801d7ec;
  enableIRQinterrupts();
  *puVar1 = *puVar1 & 0xfffffeff;
  uVar4 = *(uint *)(iVar3 + 8);
  *(uint *)(iVar3 + 8) =
       uVar4 & 0xff000000 |
       uVar4 + (((((uVar5 >> 0x10 & 0xf) + ((uVar5 >> 0x10 & 0xff) >> 4) * 10 & 0xff) * 0x3c +
                 ((uVar5 >> 8 & 0xf) + ((uVar5 >> 8 & 0xff) >> 4) * 10 & 0xff)) * 0x3c +
                ((uVar5 & 0xf) + ((uVar5 & 0xff) >> 4) * 10 & 0xff)) - (uint)*(byte *)(param_1 + 6))
               + ((uint)*(byte *)(param_1 + 5) + (uint)*(byte *)(param_1 + 4) * 0x3c) * -0x3c &
       0xffffff;
  return param_4;
}



/* ===== FUN_0801d800 @ 0801d800 ===== */

undefined4 * FUN_0801d800(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801d814;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801d818 @ 0801d818 ===== */

undefined4 * FUN_0801d818(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801d82c;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801d830 @ 0801d830 ===== */

undefined4 * FUN_0801d830(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801d844;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801d848 @ 0801d848 ===== */

undefined4 * FUN_0801d848(undefined4 *param_1)

{
  FUN_080258d0();
  *param_1 = DAT_0801d85c;
  param_1[5] = 2;
  return param_1;
}



/* ===== FUN_0801d860 @ 0801d860 ===== */

uint FUN_0801d860(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  param_1 = param_1 & 7;
  if (7 - param_1 < 5) {
    uVar1 = (1 << (7 - param_1 & 0xff)) - 1;
  }
  else {
    uVar1 = 0xf;
  }
  if (param_1 + 4 < 7) {
    param_1 = 0;
  }
  else {
    param_1 = param_1 - 3;
  }
  return (1 << (param_1 & 0xff)) - 1U & param_3 | (param_2 & uVar1) << (param_1 & 0xff);
}



/* ===== FUN_0801d898 @ 0801d898 ===== */

void FUN_0801d898(int param_1,int param_2,uint param_3)

{
  *(uint *)(param_1 + (uint)(byte)(&DAT_0801d918)[param_2]) =
       param_3 | DAT_0801d9ec & *(uint *)(param_1 + (uint)(byte)(&DAT_0801d918)[param_2]);
  return;
}



/* ===== FUN_0801d8b0 @ 0801d8b0 ===== */

void FUN_0801d8b0(int param_1,int param_2,uint param_3)

{
  *(uint *)(param_1 + (uint)(byte)(&DAT_0801d918)[param_2]) =
       param_3 | *(uint *)(param_1 + (uint)(byte)(&DAT_0801d918)[param_2]) & 0xffffffdf;
  return;
}



/* ===== FUN_0801d8c0 @ 0801d8c0 ===== */

void FUN_0801d8c0(int param_1,int param_2,uint param_3)

{
  *(uint *)(param_1 + (uint)(byte)(&DAT_0801d918)[param_2]) =
       param_3 | *(uint *)(param_1 + (uint)(byte)(&DAT_0801d918)[param_2]) & 0xffffffbf;
  return;
}



/* ===== FUN_0801d8d8 @ 0801d8d8 ===== */

void FUN_0801d8d8(int param_1,int param_2,uint param_3)

{
  *(uint *)(param_1 + (uint)(byte)(&DAT_0801d918)[param_2]) =
       param_3 | *(uint *)(param_1 + (uint)(byte)(&DAT_0801d918)[param_2]) & 0xffffff7f;
  return;
}



/* ===== FUN_0801d8e8 @ 0801d8e8 ===== */

void FUN_0801d8e8(int param_1,int param_2,uint param_3)

{
  *(uint *)(param_1 + (uint)(byte)(&DAT_0801d918)[param_2]) =
       param_3 | *(uint *)(param_1 + (uint)(byte)(&DAT_0801d918)[param_2]) & 0xfffffcff;
  return;
}



/* ===== FUN_0801d8f8 @ 0801d8f8 ===== */

void FUN_0801d8f8(int param_1,int param_2,uint param_3)

{
  *(uint *)(param_1 + (uint)(byte)(&DAT_0801d918)[param_2]) =
       param_3 | *(uint *)(param_1 + (uint)(byte)(&DAT_0801d918)[param_2]) & 0xfffff3ff;
  return;
}



/* ===== FUN_0801d908 @ 0801d908 ===== */

void FUN_0801d908(int param_1,int param_2,uint param_3)

{
  *(uint *)(param_1 + (uint)(byte)(&DAT_0801d918)[param_2]) =
       param_3 | *(uint *)(param_1 + (uint)(byte)(&DAT_0801d918)[param_2]) & 0xffffcfff;
  return;
}



/* ===== FUN_0801d920 @ 0801d920 ===== */

uint FUN_0801d920(uint param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_0801d9f0;
  *DAT_0801d9f0 = *DAT_0801d9f0 | param_1;
  return param_1 & *puVar1;
}



/* ===== FUN_0801d924 @ 0801d924 ===== */

uint FUN_0801d924(uint param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_0801e5c0;
  *DAT_0801e5c0 = *DAT_0801e5c0 | param_1;
  return param_1 & *puVar1;
}



/* ===== FUN_0801d93c @ 0801d93c ===== */

uint FUN_0801d93c(uint param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_0801d9f4;
  *DAT_0801d9f4 = *DAT_0801d9f4 | param_1;
  return param_1 & *puVar1;
}



/* ===== FUN_0801d940 @ 0801d940 ===== */

uint FUN_0801d940(uint param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_0801d9f8;
  *DAT_0801d9f8 = *DAT_0801d9f8 | param_1;
  return param_1 & *puVar1;
}



/* ===== FUN_0801d944 @ 0801d944 ===== */

void FUN_0801d944(int param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = (byte)(param_2 >> 0x10);
  bVar1 = (byte)(param_2 >> 0x18);
  *(uint *)(DAT_0801d9fc + (param_2 & 0xff) * 4) =
       param_1 <<
       LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1 |
                               bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                            bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18 |
               (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1 |
                               bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                            bVar1 >> 6 & 1) << 1 | bVar1 >> 7) << 0x10) |
       *(uint *)(DAT_0801d9fc + (param_2 & 0xff) * 4) & ~(param_2 >> 0x10);
  return;
}



/* ===== FUN_0801d968 @ 0801d968 ===== */

void FUN_0801d968(uint *param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  
  bVar2 = (byte)param_2;
  bVar3 = (byte)((uint)param_2 >> 8);
  bVar4 = (byte)((uint)param_2 >> 0x10);
  bVar1 = (byte)((uint)param_2 >> 0x18);
  uVar5 = (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1 |
                          bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                       bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18 |
          (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1 |
                          bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                       bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
          (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1 |
                          bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                       bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
          (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1 |
                          bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                       bVar1 >> 6 & 1) << 1 | bVar1 >> 7);
  *param_1 = param_3 << (LZCOUNT(uVar5) << 1) | *param_1 & ~(3 << (LZCOUNT(uVar5) << 1));
  return;
}



/* ===== FUN_0801d98c @ 0801d98c ===== */

void FUN_0801d98c(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  
  bVar2 = (byte)param_2;
  bVar3 = (byte)((uint)param_2 >> 8);
  bVar4 = (byte)((uint)param_2 >> 0x10);
  bVar1 = (byte)((uint)param_2 >> 0x18);
  uVar5 = (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1 |
                          bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                       bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18 |
          (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1 |
                          bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                       bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
          (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1 |
                          bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                       bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
          (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1 |
                          bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                       bVar1 >> 6 & 1) << 1 | bVar1 >> 7);
  *(uint *)(param_1 + 0xc) =
       param_3 << (LZCOUNT(uVar5) << 1) | *(uint *)(param_1 + 0xc) & ~(3 << (LZCOUNT(uVar5) << 1));
  return;
}



/* ===== FUN_0801d9b0 @ 0801d9b0 ===== */

uint FUN_0801d9b0(void)

{
  uint *puVar1;
  ushort uVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = DAT_0801da08;
  uVar4 = *DAT_0801da00 & 0xffff;
  while (uVar4 != (*DAT_0801da00 & 0xffff)) {
    uVar4 = *DAT_0801da00 & 0xffff;
  }
  uVar2 = *DAT_0801da04 + (short)uVar4;
  if (uVar2 < (ushort)*DAT_0801da08) {
    uVar4 = *DAT_0801da08;
    puVar1 = DAT_0801da08 + 1;
    *DAT_0801da08 = uVar4 + 0x10000;
    puVar3[1] = *puVar1 + (uint)(0xfffeffff < uVar4);
  }
  *(ushort *)puVar3 = uVar2;
  return *puVar3;
}



/* ===== FUN_0801da0c @ 0801da0c ===== */

void FUN_0801da0c(void)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined1 *puVar12;
  char cVar13;
  undefined2 uVar14;
  uint uVar15;
  int iVar16;
  undefined4 uVar17;
  undefined1 uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  uint local_98;
  uint3 local_94;
  undefined1 uStack_91;
  uint local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  uint local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60 [15];
  
  FUN_0801d940(1);
  FUN_0801d93c(0x10000000);
  iVar16 = DAT_0801e5cc;
  puVar2 = DAT_0801e5c4;
  *DAT_0801e5c4 = *DAT_0801e5c4 & 0xf8ff | DAT_0801e5c8;
  FUN_0801f4f8();
  *DAT_0801e5d0 = *DAT_0801e5d0 & 0xfffffeff;
  _local_94 = 0;
  local_90 = 0;
  local_8c = 0;
  FUN_080203a8(&local_88,0x18);
  FUN_0801d924(0x10);
  FUN_0801d924(4);
  FUN_0801d924(0x80);
  FUN_0801d924(1);
  FUN_0801d924(2);
  FUN_0801d924(8);
  FUN_080203a8(&local_70,0x18);
  FUN_0801d924(0x80);
  local_70 = 3;
  local_6c = 0;
  local_60[0] = 2;
  FUN_0802b52c(iVar16,&local_70);
  for (local_98 = 10; 0 < (int)local_98; local_98 = local_98 - 1) {
  }
  uVar21 = *(uint *)(iVar16 + 0x10);
  FUN_0801d98c(iVar16,1,1);
  FUN_0801d98c(iVar16,2,1);
  puVar1 = DAT_0801e5c0;
  for (local_98 = 10; 0 < (int)local_98; local_98 = local_98 - 1) {
  }
  uVar15 = *(uint *)(iVar16 + 0x10);
  local_6c = 3;
  local_60[0] = 0;
  FUN_0802b52c(iVar16,&local_70);
  *puVar1 = *puVar1 & 0xffffff7f;
  uVar20 = uVar21 * 2 + (uint)((~uVar15 & 1) != 0) & 3;
  uVar18 = 0xff;
  if (((uVar20 != 3) && (uVar21 = (~uVar15 & 3) >> 1 | uVar21 & 2, uVar21 != 3)) &&
     (iVar19 = uVar21 * 3 + uVar20, uVar18 = (undefined1)iVar19, iVar19 == 0)) {
    *(undefined1 *)(DAT_0801e5d4 + 0x14) = 0xff;
    FUN_0801d924(0x80);
    local_70 = 1;
    local_6c = 0;
    local_60[0] = 2;
    FUN_0802b52c(iVar16,&local_70);
    *(undefined4 *)(iVar16 + 0x18) = 2;
    local_70 = 2;
    local_6c = 1;
    local_64 = 0;
    local_60[0] = 0;
    FUN_0802b52c(iVar16,&local_70);
    for (local_98 = 10; 0 < (int)local_98; local_98 = local_98 - 1) {
    }
    uVar21 = *(uint *)(iVar16 + 0x10);
    FUN_0801d98c(iVar16,1,1);
    *(undefined4 *)(iVar16 + 0x28) = 2;
    for (local_98 = 10; 0 < (int)local_98; local_98 = local_98 - 1) {
    }
    uVar15 = *(uint *)(iVar16 + 0x10);
    local_70 = 3;
    local_6c = 3;
    local_60[0] = 0;
    FUN_0802b52c(iVar16,&local_70);
    *puVar1 = *puVar1 & 0xffffff7f;
    if ((uVar21 & 3) == 3 && (uVar15 & 3) == 0) {
      uVar18 = 9;
    }
    else {
      uVar18 = 0;
    }
  }
  iVar3 = DAT_0801e5e0;
  iVar19 = DAT_0801e5dc;
  iVar16 = DAT_0801e5d8;
  *(undefined4 *)(DAT_0801e5d8 + 0x28) = 0x4000;
  *(undefined4 *)(iVar19 + 0x18) = 0x800;
  *(undefined4 *)(iVar19 + 0x28) = 0x764;
  *(undefined4 *)(DAT_0801e5e4 + 0x18) = 0x1000;
  *(undefined4 *)(iVar16 + 0x28) = 0x2000;
  *(undefined4 *)(iVar16 + 0x18) = 0x40;
  local_88 = 0xf06;
  local_84 = 3;
  *(undefined1 *)(DAT_0801e5d4 + 0x14) = uVar18;
  local_78 = 0;
  FUN_0802b52c(DAT_0801e5e4,&local_88);
  local_88 = 0x288;
  local_84 = 3;
  local_78 = 0;
  FUN_0802b52c(iVar3,&local_88);
  local_88 = 0x8528;
  local_84 = 3;
  local_78 = 0;
  FUN_0802b52c(&DAT_48000000,&local_88);
  local_88 = 0x8a;
  local_84 = 3;
  local_78 = 0;
  FUN_0802b52c(iVar16,&local_88);
  local_88 = 0x1000;
  local_84 = 1;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  FUN_0802b52c(DAT_0801e5e4,&local_88);
  local_88 = 0x1000;
  local_84 = 0;
  local_78 = 1;
  FUN_0802b52c(iVar16,&local_88);
  local_88 = 0x6000;
  local_84 = 1;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  FUN_0802b52c(iVar16,&local_88);
  local_88 = 0x800;
  local_84 = 1;
  local_7c = 1;
  local_80 = 0;
  local_78 = 0;
  FUN_0802b52c(DAT_0801e5dc,&local_88);
  local_88 = 0x760;
  local_7c = 0;
  FUN_0802b52c(DAT_0801e5dc,&local_88);
  local_88 = 0x1088;
  local_84 = 3;
  local_78 = 0;
  FUN_0802b52c(DAT_0801e5dc,&local_88);
  local_88 = 0x200;
  local_84 = 0;
  local_78 = 0;
  FUN_0802b52c(&DAT_48000000,&local_88);
  local_88 = 0x1800;
  local_84 = 2;
  local_80 = 3;
  local_7c = 0;
  local_78 = 2;
  local_74 = 10;
  FUN_0802b52c(&DAT_48000000,&local_88);
  local_84 = 1;
  local_80 = 2;
  local_88 = 0x40;
  local_7c = 0;
  local_78 = 1;
  FUN_0802b52c(iVar16,&local_88);
  puVar4 = DAT_0801e5e8;
  local_84 = 1;
  local_88 = 4;
  local_7c = 0;
  local_78 = 0;
  local_80 = 2;
  FUN_0802b52c(DAT_0801e5dc,&local_88);
  FUN_0801d944(4,DAT_0801e5ec);
  puVar4[2] = puVar4[2] & 0xffffff0f | 0x40;
  puVar4[2] = puVar4[2] & 0xfffff0ff | 0x400;
  puVar4[4] = puVar4[4] & 0xffffff0f | 0x20;
  puVar4[1] = puVar4[1] & 0xffffff0f;
  puVar4[1] = puVar4[1] & 0xfffff0ff;
  puVar4[1] = puVar4[1] & 0xfffffff0 | 4;
  local_90 = 0;
  _local_94 = 0x10;
  local_8c._0_3_ = 0x10001;
  FUN_0802b640(&local_94);
  _local_94 = 0x20;
  local_90 = 0;
  local_8c._0_3_ = 0x10001;
  FUN_0802b640(&local_94);
  _local_94 = 0x40;
  local_90 = 0;
  local_8c._0_3_ = 0x10001;
  FUN_0802b640(&local_94);
  _local_94 = 0x2000;
  local_90 = 0;
  local_8c._0_3_ = 0x10001;
  FUN_0802b640(&local_94);
  _local_94 = 2;
  local_90 = 0;
  local_8c._0_3_ = 0x10001;
  FUN_0802b640(&local_94);
  _local_94 = 4;
  local_90 = 0;
  local_8c._0_3_ = 0x10001;
  FUN_0802b640(&local_94);
  _local_94 = 1;
  local_8c = CONCAT13(local_8c._3_1_,0x10001);
  local_90 = 0;
  local_8c = CONCAT22(local_8c._2_2_,1);
  FUN_0802b640(&local_94);
  FUN_0801d98c(DAT_0801e5e4,0x10,2);
  FUN_0801d98c(DAT_0801e5e4,0x20,2);
  FUN_0801d98c(DAT_0801e5e4,0x40,2);
  FUN_0801d98c(iVar3,0x2000,2);
  FUN_0801d98c(&DAT_48000000,2,2);
  FUN_0801d98c(&DAT_48000000,4,2);
  FUN_0801d98c(DAT_0801e5e4,1,1);
  FUN_0801d968(DAT_0801e5e4,0x10,0);
  FUN_0801d968(DAT_0801e5e4,0x20,0);
  FUN_0801d968(DAT_0801e5e4,0x40,0);
  FUN_0801d968(iVar3,0x2000,0);
  *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) & 0xf3ffffff | 0x8000000;
  *(uint *)(iVar3 + 4) = *(uint *)(iVar3 + 4) & 0xffffdfff;
  *(undefined4 *)(iVar3 + 0x18) = 0x2000;
  FUN_0801d968(&DAT_48000000,2,0);
  FUN_0801d968(&DAT_48000000,4,0);
  FUN_0801d968(DAT_0801e5e4,1,0);
  cVar13 = FUN_0801d860((*puVar2 & 0x7ff) >> 8,3,0);
  puVar9 = DAT_0801ee50;
  *DAT_0801e5f0 = cVar13 << 4;
  *puVar9 = 0x80;
  cVar13 = FUN_0801d860((*puVar2 & 0x7ff) >> 8,3,0);
  DAT_0801e5f0[1] = cVar13 << 4;
  *DAT_0801ee50 = 0x100;
  cVar13 = FUN_0801d860((*puVar2 & 0x7ff) >> 8,3,2);
  DAT_0801e5f0[3] = cVar13 << 4;
  *DAT_0801ee50 = 0x400;
  cVar13 = FUN_0801d860((*puVar2 & 0x7ff) >> 8,3,2);
  DAT_0801e5f0[0x10] = cVar13 << 4;
  *DAT_0801ee50 = 0x800000;
  cVar13 = FUN_0801d860((*puVar2 & 0x7ff) >> 8,2,0);
  puVar9 = DAT_0801ee50;
  *DAT_0801ee54 = cVar13 << 4;
  puVar9[1] = 0x100;
  FUN_0801d920(1);
  FUN_0801d920(2);
  cVar13 = FUN_0801d860((*puVar2 & 0x7ff) >> 8,3,3);
  DAT_0801e5f0[4] = cVar13 << 4;
  *DAT_0801ee50 = 0x800;
  cVar13 = FUN_0801d860((*puVar2 & 0x7ff) >> 8,1,0);
  puVar9 = DAT_0801ee50;
  DAT_0801e5f0[5] = cVar13 << 4;
  *puVar9 = 0x1000;
  iVar19 = DAT_0801e5f4;
  *(undefined4 *)(DAT_0801e5f4 + 0x10) = DAT_0801e5f8;
  local_98 = 0;
  _local_94 = 0;
  local_90 = 0;
  FUN_080203a8(&local_74,0x18);
  local_60[5] = 0;
  local_60[6] = 0;
  local_60[7] = 0;
  local_60[8] = 0;
  local_60[1] = 0;
  local_60[2] = 0;
  local_60[3] = 0;
  local_60[4] = 0;
  FUN_080203a8(&local_8c,0x18);
  FUN_0801d924(0x2000);
  FUN_0801d924(4);
  FUN_0801d924(2);
  local_8c = 0x24;
  local_88 = 3;
  local_7c = 0;
  FUN_0802b52c(iVar3,&local_8c);
  local_8c = 1;
  local_88 = 3;
  local_7c = 0;
  FUN_0802b52c(iVar16,&local_8c);
  puVar5 = DAT_0801e5fc;
  *(uint *)(iVar3 + 0x2c) = *(uint *)(iVar3 + 0x2c) | 0x24;
  *(uint *)(iVar16 + 0x2c) = *(uint *)(iVar16 + 0x2c) | 1;
  *puVar5 = *puVar5 & 0xfffffff0;
  FUN_0801d898(iVar19,0,0);
  FUN_0801d908(iVar19,0,0);
  FUN_0801d8b0(iVar19,0,0x20);
  FUN_0801d8c0(iVar19,0,0);
  FUN_0801d8d8(iVar19,0,0x80);
  FUN_0801d8e8(iVar19,0,0x100);
  FUN_0801d8f8(iVar19,0,0x400);
  cVar13 = FUN_0801d860((*puVar2 & 0x7ff) >> 8,0,0);
  DAT_0801e5f0[0xb] = cVar13 << 4;
  *DAT_0801ee50 = 0x40000;
  uVar15 = DAT_0801e604;
  iVar6 = DAT_0801e600;
  local_98 = 0;
  _local_94 = 0;
  local_90 = 0;
  FUN_0802b7de(DAT_0801e600,&local_98);
  local_74 = 0;
  local_6c = 0;
  local_70 = 5;
  local_64 = 3;
  local_68 = 0;
  local_60[0] = 0;
  FUN_0802b808(iVar6,&local_74);
  iVar7 = DAT_0801e608;
  *(uint *)(DAT_0801e608 + 8) = *(uint *)(DAT_0801e608 + 8) & 0xfe3fffff | 0xc00000;
  local_60[5] = 0;
  local_60[6] = 0;
  FUN_0802b798(iVar7,local_60 + 5);
  local_60[3] = 0;
  local_60[4] = 0;
  FUN_0802b870(iVar6,local_60 + 1);
  *(uint *)(iVar6 + 0x10) = *(uint *)(iVar6 + 0x10) & DAT_0801e60c;
  *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) & DAT_0801e610;
  *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) & uVar15 | 0x10000000;
  *(uint *)(iVar6 + 0x30) = *(uint *)(iVar6 + 0x30) & 0xfffff83f | 0xc0;
  *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) & 0xfffff1ff | 0x800;
  puVar5 = DAT_0801e614;
  *DAT_0801e614 = *DAT_0801e614 & 0xfffffff7;
  *(uint *)(iVar6 + 0x30) = *(uint *)(iVar6 + 0x30) & 0xfffe0fff | 0x3000;
  *puVar5 = *puVar5 & 0xfffffff7;
  *(uint *)(iVar6 + 0x30) = *(uint *)(iVar6 + 0x30) & 0xff83ffff | 0x380000;
  *(uint *)(iVar6 + 0x18) = *(uint *)(iVar6 + 0x18) & 0xffff8fff | 0x4000;
  *puVar5 = *puVar5 & 0xffffbfff;
  *(uint *)(iVar6 + 0x30) = *(uint *)(iVar6 + 0x30) & 0xe0ffffff | 0xf000000;
  *(uint *)(iVar6 + 0x18) = *(uint *)(iVar6 + 0x18) & 0xfffc7fff | 0x20000;
  *puVar5 = *puVar5 & 0xffff7fff;
  *(uint *)(iVar6 + 0x34) = *(uint *)(iVar6 + 0x34) & 0xffffffe0;
  *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) & 0xfffffff8 | 6;
  *puVar5 = *puVar5 & 0xfffffffe;
  *(uint *)(iVar6 + 0x34) = *(uint *)(iVar6 + 0x34) & 0xfffff83f | 0x440;
  *(uint *)(iVar6 + 0x18) = *(uint *)(iVar6 + 0x18) & 0xff1fffff | 0xc00000;
  *puVar5 = *puVar5 & 0xfffdffff;
  uVar17 = DAT_0801e618;
  *puVar1 = *puVar1 & 0xffffdfff;
  *(undefined4 *)(iVar19 + 0x24) = uVar17;
  *(undefined4 *)(iVar19 + 0x28) = DAT_0801e61c;
  local_98 = 0;
  _local_94 = 0;
  local_90 = 0;
  FUN_080203a8(&local_7c,0x18);
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  FUN_080203a8(&local_64,0x18);
  FUN_0801d924(0x2000);
  FUN_0801d924(1);
  local_64 = 1;
  local_60[0] = 3;
  local_60[3] = 0;
  FUN_0802b52c(&DAT_48000000,&local_64);
  uVar21 = DAT_4800002c;
  DAT_4800002c = uVar21 | 1;
  *DAT_0801e5fc = *DAT_0801e5fc & 0xffffff0f;
  FUN_0801d898(iVar19,1,0);
  FUN_0801d908(iVar19,1,0);
  FUN_0801d8b0(iVar19,1,0x20);
  FUN_0801d8c0(iVar19,1,0);
  FUN_0801d8d8(iVar19,1,0x80);
  FUN_0801d8e8(iVar19,1,0x100);
  FUN_0801d8f8(iVar19,1,0x400);
  cVar13 = FUN_0801d860((*puVar2 & 0x7ff) >> 8,0,1);
  iVar19 = DAT_0801e620;
  DAT_0801e5f0[0xb] = cVar13 << 4;
  *DAT_0801ee50 = 0x40000;
  local_98 = 0;
  _local_94 = 0;
  local_90 = 0;
  FUN_0802b7de(iVar19,&local_98);
  local_7c = 0x7c0;
  local_6c = 3;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_68 = 0;
  FUN_0802b808(iVar19,&local_7c);
  local_8c = 0x50;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  FUN_0802b870(iVar19,&local_8c);
  *(uint *)(iVar19 + 0xc) = *(uint *)(iVar19 + 0xc) & DAT_0801e624 | 0x80000000;
  *(uint *)(iVar19 + 0x10) = *(uint *)(iVar19 + 0x10) & DAT_0801e60c;
  *(uint *)(iVar19 + 0x4c) = *(uint *)(iVar19 + 0x4c) & 0xffffff3f | 0x40;
  *(uint *)(iVar19 + 4) = *(uint *)(iVar19 + 4) & 0xffffffdf;
  *(uint *)(iVar19 + 4) = *(uint *)(iVar19 + 4) & 0xffffffbf;
  *(uint *)(iVar19 + 0xc) = *(uint *)(iVar19 + 0xc) & 0xfffff3ff | 0x400;
  *(uint *)(iVar19 + 8) = *(uint *)(iVar19 + 8) & DAT_0801e610;
  *(uint *)(iVar19 + 8) = uVar15 & *(uint *)(iVar19 + 8) | 0x10000000;
  *(uint *)(iVar19 + 0x30) = *(uint *)(iVar19 + 0x30) & 0xfffff83f | 0x140;
  *(uint *)(iVar19 + 0x14) = *(uint *)(iVar19 + 0x14) & 0xfffc7fff | 0x10000;
  *(uint *)(iVar19 + 0x4c) = *(uint *)(iVar19 + 0x4c) & 0xffffe0ff | 0x500;
  *DAT_0801e628 = *DAT_0801e628 & 0xffffffdf;
  *(uint *)(iVar19 + 0x60) = *(uint *)(iVar19 + 0x60) & DAT_0801e62c | DAT_0801e630;
  *puVar1 = *puVar1 & 0xffffdfff;
  iVar19 = FUN_0801f62c();
  if (iVar19 < 1) {
    FUN_080203a8(&local_7c,0x18);
    FUN_080203a8(&local_94,0x18);
    FUN_0801d924(4);
    FUN_0801d924(2);
    _local_94 = 0x10;
    local_90 = 3;
    local_84 = 0;
    FUN_0802b52c(iVar3,&local_94);
    _local_94 = 4;
    local_90 = 3;
    local_84 = 0;
    FUN_0802b52c(iVar16,&local_94);
    _local_94 = 0x400;
    local_8c = 0;
    local_88 = 0;
    local_90 = 2;
    local_84 = 2;
    local_80 = 0xc;
    FUN_0802b52c(iVar16,&local_94);
    iVar19 = DAT_0801e634;
    local_7c = 0;
    local_74 = 0x70;
    local_78 = 0x80;
    local_6c = 0x8000;
    local_70 = 0;
    local_68 = 0;
    FUN_0802b8b4(DAT_0801e634,&local_7c);
    puVar5 = DAT_0801e638;
    *(uint *)(iVar19 + 4) = *(uint *)(iVar19 + 4) & 0xfffffdff;
    puVar8 = DAT_0801e640;
    for (local_98 = (short)(ushort)((ulonglong)*puVar5 * (ulonglong)DAT_0801e63c >> 0x34) * 200;
        local_98 != 0; local_98 = local_98 - 1) {
    }
    DAT_0801e640[1] = DAT_0801e640[1] & 0xffdfffff;
    *puVar8 = *puVar8 & 0xffdfffff;
  }
  FUN_080203a8(&local_7c,0x18);
  FUN_080203a8(&local_94,0x18);
  FUN_0801d924(2);
  _local_94 = 0x800;
  iVar19 = FUN_0801f62c();
  if (iVar19 < 1) {
    local_90 = 2;
    local_84 = 2;
  }
  else {
    local_90 = 1;
    local_84 = 0;
  }
  local_8c = 0;
  local_88 = 0;
  local_80 = 0xc;
  FUN_0802b52c(iVar16,&local_94);
  *(undefined4 *)(iVar16 + 0x28) = 0x800;
  FUN_0801d968(iVar16,0x800,1);
  iVar19 = FUN_0801f62c();
  if (iVar19 < 1) {
    _local_94 = 0x18;
    local_90 = 3;
    local_84 = 0;
    FUN_0802b52c(iVar16,&local_94);
    puVar8 = DAT_0801f4cc;
    local_7c = 4;
    local_74 = 0x60;
    local_78 = 0;
    local_6c = 0;
    local_68 = 0;
    local_70 = 0x20000;
    FUN_0802b8b4(DAT_0801f4cc,&local_7c);
    puVar5 = DAT_0801e638;
    *puVar8 = *puVar8 & 0xfffffdff;
    puVar8 = DAT_0801f4d0;
    for (local_98 = (short)(ushort)((ulonglong)*puVar5 * (ulonglong)DAT_0801e63c >> 0x34) * 200;
        local_98 != 0; local_98 = local_98 - 1) {
    }
    DAT_0801f4d0[1] = DAT_0801f4d0[1] & 0xffbfffff;
    *puVar8 = *puVar8 & 0xffbfffff;
  }
  FUN_080203a8(&local_98,0x18);
  FUN_0801d93c(0x20000000);
  cVar13 = FUN_0801d860((*puVar2 & 0x7ff) >> 8,0,0);
  uVar17 = DAT_0801f4dc;
  puVar8 = DAT_0801f4d8;
  puVar5 = DAT_0801f4d4;
  DAT_0801ee54[0xe] = cVar13 << 4;
  DAT_0801ee50[1] = 0x400000;
  local_98 = 0x38;
  _local_94 = 0;
  local_8c = 2;
  local_88 = 1;
  local_84 = 0;
  FUN_0802b8f0(puVar5,DAT_0801f4e0,&local_98);
  uVar10 = DAT_0801f4e4;
  *puVar5 = *puVar5 & 0xfffffffb;
  FUN_0802b8f0(puVar5,uVar10,&local_98);
  *puVar5 = *puVar5 & 0xfffbffff;
  puVar5[2] = puVar5[2] & 0xfffff000;
  puVar5[5] = puVar5[5] & 0xfffff000;
  uVar21 = DAT_0801f4e8;
  puVar1[3] = puVar1[3] & 0xdfffffff;
  FUN_080203a8(&local_80,0x1c);
  FUN_080203a8(&local_98,0x18);
  FUN_0801d924(2);
  local_98 = 0x300;
  local_90 = 1;
  local_8c = 1;
  _local_94 = 2;
  local_88 = 0;
  local_84 = 4;
  FUN_0802b52c(iVar16,&local_98);
  FUN_0801d93c(0x200000);
  puVar8[1] = puVar8[1] | 0x2000000;
  puVar8[3] = puVar8[3] & 0xffff7fff;
  *puVar8 = *puVar8 & 0xfff7ffff;
  *puVar8 = *puVar8 & 0xfffdffff;
  local_80 = 0;
  local_7c = uVar17;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  FUN_0802b954(puVar8,&local_80);
  puVar8[3] = puVar8[3] & uVar21;
  *puVar4 = *puVar4 | 0x100000;
  puVar1[3] = puVar1[3] & 0xffdfffff;
  FUN_080203a8(&local_80,0x1c);
  FUN_080203a8(&local_98,0x18);
  FUN_0801d924(4);
  local_98 = 3;
  _local_94 = 2;
  local_90 = 0;
  local_8c = 1;
  local_88 = 1;
  local_84 = 4;
  FUN_0802b52c(iVar3,&local_98);
  FUN_0801d93c(0x800000);
  puVar5 = DAT_0801f4ec;
  DAT_0801f4ec[1] = DAT_0801f4ec[1] | 0x2000000;
  puVar5[3] = puVar5[3] & 0xffff7fff;
  *puVar5 = *puVar5 & 0xfff7ffff;
  *puVar5 = *puVar5 & 0xfffdffff;
  local_80 = 0;
  local_7c = uVar17;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  FUN_0802b954(puVar5,&local_80);
  puVar5[3] = uVar21 & puVar5[3];
  puVar8 = DAT_0801f4f4;
  puVar5 = DAT_0801f4f0;
  puVar1[3] = puVar1[3] & 0xff7fffff;
  local_98 = 0;
  _local_94 = 0;
  local_90 = 0;
  local_8c = 0;
  FUN_080203a8(&local_88,0x18);
  FUN_0801d93c(0x40000000);
  FUN_0801d924(1);
  local_88 = 8;
  local_84 = 3;
  local_78 = 0;
  FUN_0802b52c(&DAT_48000000,&local_88);
  uVar21 = DAT_4800002c;
  DAT_4800002c = uVar21 | 8;
  local_98 = 0;
  _local_94 = 0xc;
  local_90 = 0x400;
  FUN_0802b9c0(puVar5,&local_98);
  *puVar5 = *puVar5 | 0x80000000;
  *puVar5 = *puVar5 & 0xffffbfff;
  puVar1[3] = puVar1[3] & 0xbfffffff;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  FUN_080203a8(&local_98,0x18);
  FUN_0801d93c(0x40000000);
  FUN_0801d924(1);
  FUN_0801d924(2);
  local_98 = 0xc0;
  _local_94 = 3;
  local_88 = 0;
  FUN_0802b52c(&DAT_48000000,&local_98);
  local_98 = 1;
  _local_94 = 3;
  local_88 = 0;
  FUN_0802b52c(iVar16,&local_98);
  *(uint *)(iVar16 + 0x2c) = *(uint *)(iVar16 + 0x2c) | 1;
  local_80 = 3;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  FUN_0802b9c0(puVar8,&local_80);
  iVar19 = DAT_0801f64c;
  *puVar5 = *puVar5 | 0x80000000;
  *puVar8 = *puVar8 & 0xffffbfff;
  puVar1[3] = puVar1[3] & 0xbfffffff;
  FUN_080203a8(&local_80,0x28);
  FUN_080203a8(&local_98,0x18);
  FUN_0801d940(0x1000);
  FUN_0801d924(0x10);
  local_98 = 0xa000;
  local_90 = 0;
  local_8c = 0;
  _local_94 = 2;
  local_88 = 1;
  local_84 = 5;
  FUN_0802b52c(DAT_0801f650,&local_98);
  local_98 = 0x4000;
  local_90 = 0;
  local_8c = 0;
  _local_94 = 2;
  local_88 = 2;
  local_84 = 5;
  FUN_0802b52c(DAT_0801f650,&local_98);
  local_80 = 0;
  local_7c = 0x104;
  local_78 = 0x700;
  local_74 = 0;
  local_6c = 0x200;
  local_70 = 0;
  local_60[1] = 7;
  local_68 = 0;
  local_64 = 0;
  local_60[0] = 0;
  FUN_0802b9fc(iVar19,&local_80);
  *(uint *)(iVar19 + 4) = *(uint *)(iVar19 + 4) & 0xffffffef;
  *(uint *)(iVar19 + 4) = *(uint *)(iVar19 + 4) & 0xfffffff7;
  *(uint *)(iVar19 + 4) = *(uint *)(iVar19 + 4) | 0x1000;
  iVar19 = DAT_0801f654;
  puVar1[5] = puVar1[5] & 0xffffefff;
  FUN_080203a8(&local_80,0x28);
  FUN_080203a8(&local_98,0x18);
  FUN_0801d93c(0x4000);
  FUN_0801d924(8);
  _local_94 = 2;
  local_98 = 0x13;
  local_8c = 0;
  local_90 = 2;
  local_88 = 2;
  local_84 = 5;
  FUN_0802b52c(DAT_0801f658,&local_98);
  local_80 = 0;
  local_7c = 0x104;
  local_78 = 0x700;
  local_74 = 0;
  local_6c = 0x40000;
  local_70 = 0;
  local_60[1] = 7;
  local_68 = 0;
  local_64 = 0;
  local_60[0] = 0;
  FUN_0802b9fc(iVar19,&local_80);
  *(uint *)(iVar19 + 4) = *(uint *)(iVar19 + 4) & 0xffffffef;
  *(uint *)(iVar19 + 4) = *(uint *)(iVar19 + 4) | 8;
  puVar1[3] = puVar1[3] & 0xffffbfff;
  FUN_080203a8(&local_80,0x28);
  FUN_080203a8(&local_98,0x18);
  FUN_0801d93c(0x8000);
  FUN_0801d924(4);
  _local_94 = 2;
  local_90 = 2;
  local_98 = 0x1400;
  local_8c = 0;
  local_88 = 1;
  local_84 = 6;
  FUN_0802b52c(iVar3,&local_98);
  _local_94 = 2;
  local_98 = 0x800;
  local_8c = 0;
  local_90 = 2;
  local_88 = 2;
  local_84 = 6;
  FUN_0802b52c(iVar3,&local_98);
  puVar8 = DAT_0801f660;
  puVar5 = DAT_0801f65c;
  local_80 = 0;
  local_7c = 0x104;
  local_78 = 0x700;
  local_74 = 0;
  local_70 = 1;
  local_6c = 0x200;
  local_64 = 0;
  local_60[0] = 0;
  local_60[1] = 7;
  local_68 = 0x28;
  FUN_0802b9fc(DAT_0801f65c,&local_80);
  puVar5[1] = puVar5[1] & 0xffffffef;
  puVar5[1] = puVar5[1] & 0xfffffff7;
  puVar5[1] = puVar5[1] | 0x1000;
  *puVar5 = *puVar5 | 0x40;
  FUN_0801d98c(iVar3,0x400,0);
  FUN_0801d98c(iVar3,0x1000,0);
  FUN_080203a8(local_60,0x14);
  FUN_080203a8(&local_80,0x20);
  FUN_080203a8(&local_98,0x18);
  FUN_0801d93c(2);
  FUN_0801d924(0x10);
  local_98 = 8;
  local_90 = 0;
  local_8c = 0;
  local_88 = 0;
  _local_94 = 2;
  local_84 = 2;
  FUN_0802b52c(DAT_0801f650,&local_98);
  local_60[0] = local_60[0] & 0xffff0000;
  local_60[2] = 0xbf;
  local_60[1] = 0;
  local_60[3] = 0;
  FUN_0802ba70(puVar8,local_60);
  *puVar8 = *puVar8 & 0xffffff7f;
  puVar8[2] = puVar8[2] & DAT_0801f664;
  puVar8[6] = puVar8[6] | 0x800;
  local_7c = 0;
  local_80 = 0x70;
  local_78 = 0;
  local_74 = 1;
  local_70 = 0;
  FUN_0802bb2c(puVar8,0x10,&local_80);
  puVar8[6] = puVar8[6] & 0xfffffbff;
  puVar8[7] = puVar8[7] | 8;
  local_74 = 0x90;
  local_70 = 2;
  FUN_0802bb2c(puVar8,0x100,&local_80);
  puVar8[7] = puVar8[7] & 0xfffffffb;
  puVar8[7] = puVar8[7] | 0x800;
  local_74 = 1;
  local_70 = 0;
  FUN_0802bb2c(puVar8,0x1000,&local_80);
  puVar8[7] = puVar8[7] & 0xfffffbff;
  *puVar8 = *puVar8 | 8;
  puVar8[2] = puVar8[2] & 0xfffffff7;
  puVar8[2] = puVar8[2] & 0xffffbfff;
  puVar8[2] = puVar8[2] & 0xffff40ff;
  puVar8[2] = puVar8[2] & 0xffffff8f | 0x50;
  puVar8[2] = puVar8[2] & DAT_0801f668 | 6;
  puVar8[6] = puVar8[6] & 0xffffff0f;
  puVar8[8] = puVar8[8] & 0xfffffff5;
  puVar8[3] = puVar8[3] & 0xffffffbf;
  puVar8[3] = puVar8[3] & 0xffffbfff;
  puVar8[1] = puVar8[1] & 0xffffff8f;
  puVar8[2] = puVar8[2] & 0xffffff7f;
  puVar8[6] = puVar8[6] & 0xfffff7ff;
  puVar8[7] = puVar8[7] & 0xfffffff7;
  puVar8[7] = puVar8[7] & 0xfffff7ff;
  puVar8[8] = puVar8[8] | 0x1110;
  puVar1[3] = puVar1[3] & 0xfffffffd;
  FUN_0801d924(4);
  FUN_0801d924(2);
  local_98 = 0x100;
  local_90 = 0;
  local_8c = 0;
  _local_94 = 2;
  local_88 = 2;
  local_84 = 2;
  FUN_0802b52c(iVar3,&local_98);
  local_98 = 0x20;
  local_90 = 0;
  local_8c = 0;
  local_88 = 0;
  _local_94 = 2;
  local_84 = 2;
  FUN_0802b52c(iVar16,&local_98);
  FUN_080203a8(local_60,0x14);
  FUN_080203a8(&local_80,0x20);
  FUN_080203a8(&local_98,0x18);
  FUN_0801d93c(4);
  iVar19 = DAT_0801f670;
  puVar5 = DAT_0801f66c;
  local_60[0] = CONCAT22(local_60[0]._2_2_,0x2f);
  local_60[2] = 999;
  local_60[1] = 0;
  local_60[3] = 0;
  FUN_0802ba70(DAT_0801f66c,local_60);
  *puVar5 = *puVar5 | 0x80;
  puVar5[2] = puVar5[2] & DAT_0801f664;
  puVar5[6] = puVar5[6] | 0x800;
  local_80 = 0x70;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 2;
  FUN_0802bb2c(puVar5,0x10,&local_80);
  puVar5[6] = puVar5[6] & 0xfffffbff;
  puVar5[7] = puVar5[7] | 8;
  FUN_0802bb2c(puVar5,0x100,&local_80);
  puVar5[7] = puVar5[7] & 0xfffffffb;
  puVar5[7] = puVar5[7] | 0x800;
  FUN_0802bb2c(puVar5,0x1000,&local_80);
  puVar5[7] = puVar5[7] & 0xfffffbff;
  puVar5[2] = puVar5[2] & 0xfffffff7;
  puVar5[2] = puVar5[2] & 0xffffbfff;
  puVar5[2] = puVar5[2] & 0xffff40ff;
  puVar5[1] = puVar5[1] & 0xffffff8f;
  puVar5[2] = puVar5[2] & 0xffffff7f;
  puVar5[6] = puVar5[6] & 0xfffff7ff;
  puVar5[7] = puVar5[7] & 0xfffffff7;
  *puVar5 = *puVar5 | 1;
  puVar5[8] = puVar5[8] | 0x1110;
  FUN_0801d924(8);
  local_98 = 0xe000;
  local_90 = 0;
  local_8c = 0;
  _local_94 = 2;
  local_88 = 2;
  local_84 = 2;
  FUN_0802b52c(DAT_0801f658,&local_98);
  *(undefined4 *)(iVar19 + 0x10) = DAT_0801f674;
  FUN_080203a8(&local_80,0x14);
  FUN_080203a8(local_60 + 7,0x20);
  FUN_080203a8(&local_6c,0x28);
  FUN_080203a8(&local_98,0x18);
  FUN_0801d940(0x10000);
  puVar5 = DAT_0801f678;
  local_80 = local_80 & 0xffff0000;
  local_7c = 0;
  local_74 = 0;
  local_70 = 0;
  local_78 = 0xff;
  FUN_0802ba70(DAT_0801f678,&local_80);
  *puVar5 = *puVar5 | 0x80;
  puVar5[2] = puVar5[2] & DAT_0801f664;
  puVar5[6] = puVar5[6] | 0x800;
  local_60[7] = 0x70;
  local_60[8] = 0;
  local_60[9] = 0;
  local_60[10] = 0;
  local_60[0xb] = 2;
  local_60[0xc] = 0;
  local_60[0xd] = 0;
  local_60[0xe] = 0;
  FUN_0802bb2c(puVar5,0x10,local_60 + 7);
  puVar5[6] = puVar5[6] & 0xfffffbff;
  puVar5[1] = puVar5[1] & 0xffffff8f | 0x20;
  puVar5[2] = puVar5[2] & 0xffffff7f;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60[0] = (local_60[0] >> 8 & 0xff) << 8;
  local_60[6] = 0;
  local_60[1] = 0x2000;
  FUN_0802be0a(puVar5,&local_6c);
  *puVar5 = *puVar5 | 1;
  puVar5[8] = puVar5[8] | 0x10;
  puVar5[0xe] = 0;
  puVar5[0x11] = puVar5[0x11] & 0xffff7fff;
  FUN_0801d924(2);
  local_98 = 0x8000;
  local_90 = 0;
  local_8c = 0;
  _local_94 = 2;
  local_88 = 2;
  local_84 = 0xe;
  FUN_0802b52c(iVar16,&local_98);
  FUN_080203a8(&local_98,0x14);
  FUN_0801d93c(1);
  local_98 = CONCAT22(local_98._2_2_,0x2f);
  _local_94 = 0;
  local_90 = 0xffffffff;
  local_8c = 0;
  FUN_0802ba70(0x40000000,&local_98);
  uVar21 = DAT_40000000;
  DAT_40000000 = uVar21 | 0x80;
  uVar21 = DAT_40000008;
  DAT_40000008 = uVar21 & DAT_0801f664;
  uVar21 = DAT_40000004;
  DAT_40000004 = uVar21 & 0xffffff8f | 0x20;
  uVar21 = DAT_40000008;
  DAT_40000008 = uVar21 & 0xffffff7f;
  uVar21 = DAT_40000000;
  DAT_40000000 = uVar21 | 1;
  FUN_0801d93c(0x80000000);
  cVar13 = FUN_0801d860((*puVar2 & 0x7ff) >> 8,3,3);
  *(char *)(DAT_0801f67c + 0x19) = cVar13 << 4;
  DAT_0801f680[2] = 2;
  puVar5 = DAT_0801f684;
  DAT_0801f684[2] = DAT_0801f684[2] & 0xfffffffe;
  puVar5[2] = puVar5[2] & 0xfffff1ff;
  puVar5[2] = puVar5[2] & 0xffdfffff;
  puVar5[2] = puVar5[2] & 0xffbfffff;
  puVar5[2] = puVar5[2] & 0xff7fffff;
  puVar5[2] = puVar5[2] & 0xfff9ffff;
  puVar5[7] = puVar5[7] & 0xfffffffc;
  puVar5[7] = puVar5[7] & 0xfffffffc;
  *DAT_0801f688 = 2;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  *puVar5 = *puVar5 | 1;
  puVar5[1] = puVar5[1] | 1;
  puVar5[3] = puVar5[3] | 1;
  do {
  } while (-1 < (int)(puVar5[3] << 0x1f));
  puVar5[5] = 0xffff;
  puVar9 = DAT_0801f68c;
  iVar16 = DAT_0801f67c;
  puVar1[4] = puVar1[4] | 0x20;
  local_98 = puVar1[4] & 0x20;
  cVar13 = FUN_0801d860((*puVar2 & 0x7ff) >> 8,1,0);
  *(char *)(iVar16 + 0x1a) = cVar13 << 4;
  puVar5 = DAT_0801f690;
  DAT_0801f680[2] = 4;
  *puVar5 = *puVar5 & 0xfffffffe;
  *puVar5 = *puVar5 & 0xfffff1ff;
  *puVar5 = *puVar5 & 0xffdfffff;
  *puVar5 = *puVar5 & 0xffbfffff;
  *puVar5 = *puVar5 & 0xff7fffff;
  *puVar5 = *puVar5 & 0xfff9ffff;
  puVar5[5] = puVar5[5] & 0xfffffffc;
  *puVar9 = 0xcccc;
  *puVar9 = 0x5555;
  puVar9[1] = 3;
  puVar9[2] = 0xfff;
  do {
  } while ((puVar9[3] & 7) != 0);
  *puVar9 = 0xaaaa;
  FUN_0801d920(0x1000);
  puVar8 = DAT_0801f698;
  puVar5 = DAT_0801f694;
  *DAT_0801f694 = *DAT_0801f694 & 0xffffff9f;
  uVar21 = DAT_0801f69c;
  *puVar5 = *puVar5 & 0xffffff7f;
  puVar5[3] = uVar21;
  *puVar5 = *puVar5 & 0xffffffe7;
  puVar5[2] = 0xffffffff;
  FUN_080203a8(&local_98,0x14);
  FUN_0801d93c(8);
  cVar13 = FUN_0801d860((*puVar2 & 0x7ff) >> 8,0,0);
  *(char *)(iVar16 + 10) = cVar13 << 4;
  DAT_0801f680[1] = 0x40000;
  local_98 = local_98 & 0xffff0000;
  _local_94 = 0;
  local_90 = 0;
  local_8c = 0;
  FUN_0802ba70(puVar8,&local_98);
  *puVar8 = *puVar8 & 0xffffff7f;
  *puVar8 = *puVar8 | 8;
  puVar8[2] = puVar8[2] & 0xffffff8f | 0x30;
  puVar8[2] = puVar8[2] & DAT_0801f664 | 7;
  puVar8[3] = puVar8[3] & 0xffffffbf;
  puVar8[3] = puVar8[3] & 0xffffbfff;
  puVar8[1] = puVar8[1] & 0xffffff8f | 0x20;
  puVar8[2] = puVar8[2] & 0xffffff7f;
  *puVar8 = *puVar8 & 0xfffffffb;
  puVar8[4] = 0xfffffffe;
  puVar8[3] = puVar8[3] | 1;
  FUN_080203a8(&local_98,0x14);
  FUN_0801d940(0x2000);
  *DAT_0801f6a0 = *DAT_0801f6a0 & 0xfffffff0 | 7;
  FUN_0801d898(iVar19,0,0x10);
  FUN_0801d908(iVar19,0,0x3000);
  FUN_0801d8b0(iVar19,0,0x20);
  FUN_0801d8c0(iVar19,0,0);
  FUN_0801d8d8(iVar19,0,0x80);
  FUN_0801d8e8(iVar19,0,0x100);
  FUN_0801d8f8(iVar19,0,0);
  puVar5 = DAT_0801f6a4;
  local_98 = local_98 & 0xffff0000;
  _local_94 = 0;
  local_8c = 0;
  local_88 = 0;
  local_90 = 2999;
  FUN_0802ba70(DAT_0801f6a4,&local_98);
  *puVar5 = *puVar5 | 0x80;
  puVar5[2] = puVar5[2] & DAT_0801f664;
  puVar5[1] = puVar5[1] & 0xffffff8f | 0x20;
  puVar5[1] = puVar5[1] & 0xff0fffff | 0x200000;
  puVar5[2] = puVar5[2] & 0xffffff7f;
  FUN_080203a8(&local_98,0x14);
  FUN_0801d93c(0x10);
  cVar13 = FUN_0801d860((*puVar2 & 0x7ff) >> 8,0,0);
  *(char *)(iVar16 + 0xe) = cVar13 << 4;
  puVar5 = DAT_0801f6a8;
  DAT_0801f680[1] = 0x400000;
  local_98 = CONCAT22(local_98._2_2_,0x2f);
  _local_94 = 0;
  local_90 = 10000;
  FUN_0802ba70(puVar5,&local_98);
  *puVar5 = *puVar5 & 0xffffff7f;
  puVar5[1] = puVar5[1] & 0xffffff8f | 0x20;
  puVar5[2] = puVar5[2] & 0xffffff7f;
  *puVar5 = *puVar5 | 8;
  puVar5[4] = 0xfffffffe;
  puVar5[3] = puVar5[3] | 1;
  puVar5 = DAT_0801f6b0;
  iVar16 = DAT_0801f6ac;
  if (-1 < *(int *)(DAT_0801f6ac + 0xc) << 0x1b) {
    *DAT_0801f6b0 = *DAT_0801f6b0 | 0x100;
    local_98 = 0;
    _local_94 = 0;
    local_90 = 0;
    puVar1[0x11] = puVar1[0x11] | 0x8000;
    local_8c = 0;
    local_88 = 0x7f;
    local_84 = 0xff;
    FUN_0802b17c(iVar16,&local_8c);
    local_90 = local_90 & 0xff000000;
    FUN_0802b1ca(iVar16,1,&local_94);
    local_98 = 0x20010103;
    FUN_0802b2aa(iVar16,1,&local_98);
    *puVar5 = *puVar5 & 0xfffffeff;
  }
  puVar12 = DAT_0801f6b8;
  puVar11 = DAT_0801f6b4;
  puVar4[1] = puVar4[1] & 0xffff0fff | 0x4000;
  _local_94 = 0;
  local_98 = 8;
  local_90 = 0x10101;
  FUN_0802b640(&local_98);
  cVar13 = FUN_0801d860((*puVar2 & 0x7ff) >> 8,0,1);
  *(char *)(DAT_0801f6bc + 2) = cVar13 << 4;
  *DAT_0801f680 = 0x200;
  uVar21 = DAT_0801f6c0;
  puVar1[7] = puVar1[7] & 0xfffffeff;
  puVar1[8] = puVar1[8] & uVar21;
  *puVar11 = 0;
  iVar16 = FUN_0802beb0(puVar12);
  if (iVar16 - 0xdU < 2) {
    puVar11[1] = iVar16;
    FUN_0802498c(&local_98,puVar12 + iVar16 + -6,6);
    local_94 = (uint3)(ushort)local_94;
    uVar17 = thunk_FUN_0802c02a(&local_98);
    puVar11[2] = uVar17;
    iVar16 = DAT_0801f6c4;
    FUN_0802498c(&local_98,DAT_0801f6c4,3);
    local_98 = local_98 & 0xffffff;
    uVar14 = thunk_FUN_0802c02a(&local_98);
    *(undefined2 *)(puVar11 + 4) = uVar14;
    *(bool *)((int)puVar11 + 0xf) = *(char *)(iVar16 + 3) != '-';
    *(undefined1 *)(puVar11 + 3) = *puVar12;
    *(undefined1 *)((int)puVar11 + 0xd) = puVar12[1];
    *(undefined1 *)((int)puVar11 + 0xe) = 0;
    *puVar11 = puVar12;
  }
  FUN_0801d484();
  iVar16 = FUN_0801d9b0();
  do {
    iVar19 = FUN_0801d9b0();
  } while (iVar19 - (iVar16 + 0x666) < 1);
  FUN_08025726();
  FUN_0801cbf8();
  FUN_08023180();
  FUN_0801698c();
  FUN_08022b20();
  FUN_080251ac();
  FUN_0801d5bc();
  FUN_0802260a();
  FUN_08023056();
  FUN_0801b390();
  FUN_0801f63a();
  thunk_FUN_08022c0a();
  FUN_08022ea0();
  FUN_08017df0();
  thunk_FUN_080277e4();
  FUN_08014874();
  FUN_08020670();
  FUN_080163be();
  FUN_08018794("Start Main loop");
  do {
    do {
      *puVar9 = 0xaaaa;
      FUN_08022b6e();
      FUN_08016936();
      FUN_0801801c();
      FUN_080228d4();
      FUN_08019d9c();
      FUN_0801920c();
      FUN_080169e6();
      FUN_08022656();
      FUN_08015a28();
      FUN_08016b32();
      FUN_08020692();
      iVar16 = FUN_080169d4();
    } while (iVar16 != 0);
    *puVar9 = 0xaaaa;
    FUN_08017ec4();
  } while( true );
}



/* ===== FUN_0801f4f8 @ 0801f4f8 ===== */

undefined4 FUN_0801f4f8(void)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 in_r3;
  
  puVar2 = DAT_0801f6c8;
  *DAT_0801f6c8 = *DAT_0801f6c8 & 0xfffffff8 | 2;
  puVar1 = DAT_0801f6b0;
  do {
  } while ((*puVar2 & 7) != 2);
  *DAT_0801f6b0 = *DAT_0801f6b0 & 0xfffff9ff | 0x200;
  puVar2 = DAT_0801f6cc;
  *DAT_0801f6cc = *DAT_0801f6cc | 0x100;
  puVar3 = DAT_0801f6d0;
  do {
  } while (-1 < (int)(*puVar2 << 0x15));
  DAT_0801f6d0[3] = DAT_0801f6d0[3] | 1;
  do {
  } while (-1 < (int)(puVar3[3] << 0x1e));
  *puVar2 = *puVar2 | 1;
  do {
  } while (-1 < (int)(*puVar2 << 0x1e));
  *puVar2 = *puVar2 | 8;
  *puVar2 = *puVar2 & 0xffffff0f | 0xb0;
  puVar2[1] = puVar2[1] & 0xffff00ff;
  *puVar1 = *puVar1 | 0x100;
  puVar3[2] = puVar3[2] & 0xffffffe7 | 8;
  puVar3[2] = puVar3[2] | 1;
  do {
  } while (-1 < (int)(puVar3[2] << 0x1e));
  *puVar2 = *puVar2 | 4;
  if ((puVar3[2] & 0x300) != 0x100) {
    puVar3[2] = puVar3[2] | 0x10000;
    puVar3[2] = puVar3[2] & 0xfffeffff;
    puVar3[2] = puVar3[2] & 0xfffffcff | 0x100;
  }
  puVar3[2] = puVar3[2] | 0x8000;
  puVar2[2] = puVar2[2] & 0xfffffffc;
  uVar4 = DAT_0801f6d4;
  do {
  } while ((puVar2[2] & 0xc) != 0);
  puVar2[2] = puVar2[2] & 0xffffff0f;
  puVar2[2] = puVar2[2] & 0xfffff8ff | 0x400;
  puVar2[2] = puVar2[2] & 0xffffc7ff | 0x2000;
  FUN_0802c034(uVar4);
  FUN_0802c072(uVar4);
  *puVar3 = *puVar3 & 0xffffcfff;
  *puVar3 = *puVar3 & 0xfffcffff;
  *puVar3 = *puVar3 | 0x300000;
  *puVar3 = *puVar3 | 0xc0000;
  *puVar3 = *puVar3 | 0x30000000;
  return in_r3;
}



/* ===== FUN_0801f62c @ 0801f62c ===== */

int FUN_0801f62c(void)

{
  int iVar1;
  
  iVar1 = (int)*(char *)(DAT_0801f6b4 + 0x14);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  return iVar1;
}



/* ===== FUN_0801f63a @ 0801f63a ===== */

int FUN_0801f63a(void)

{
  int iVar1;
  
  iVar1 = (int)*(char *)(DAT_0801f6b4 + 0x14);
  if (-1 < iVar1) {
    iVar1 = iVar1 + 10;
  }
  return iVar1;
}



/* ===== FUN_0801f648 @ 0801f648 ===== */

undefined4 FUN_0801f648(void)

{
  return DAT_0801f6b4;
}



/* ===== FUN_0801f6e8 @ 0801f6e8 ===== */

undefined4 FUN_0801f6e8(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (*(char *)(param_1 + 0x14) < 1) {
    return param_4;
  }
  iVar2 = *(char *)(param_1 + 0x14) + -1;
  piVar6 = *(int **)(DAT_0801f888 + iVar2 * 4);
  if ((param_2 & 0x7000) == 0x1000) {
    param_2 = param_2 & 0x8fff;
    (**(code **)(*piVar6 + 0x18))(piVar6,param_2);
    uVar4 = DAT_0801f88c;
    if (param_2 == 2) {
      FUN_08016b2a();
      uVar4 = FUN_08016b5c(DAT_0801f88c,0,param_4);
      return uVar4;
    }
    if (param_2 != 6) {
      return param_4;
    }
    FUN_080182a8(DAT_0801f88c,0);
    puVar3 = (undefined4 *)FUN_08018234(0x1c);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      FUN_08018300(puVar3,1);
      *puVar3 = DAT_0801f890;
    }
    uVar4 = FUN_08018338(uVar4,puVar3,param_4);
    return uVar4;
  }
  if ((param_2 & 0x7000) != 0x2000) {
    return param_4;
  }
  uVar7 = 0;
  if (0 < iVar2) {
    FUN_0801836c(param_1);
  }
  switch(param_2 & 7) {
  case 0:
    uVar7 = 0x20;
    break;
  case 1:
    *(undefined1 *)(param_1 + 0x16) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    uVar7 = 0x10;
    *(undefined1 *)(param_1 + 0x1b) = *(undefined1 *)(param_1 + 0x1a);
    break;
  case 2:
    uVar7 = 0x40;
    *(undefined1 *)(param_1 + 0x16) = 1;
    break;
  case 3:
    uVar7 = 0x30;
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  }
  pcVar1 = DAT_0801f894;
  if (*(char *)(param_1 + 0x17) == '\0') {
    *(undefined1 *)(param_1 + 0x17) = *(undefined1 *)(param_1 + 0x16);
    return param_4;
  }
  uVar7 = uVar7 | *(uint *)(param_1 + 0x10);
  *(uint *)(param_1 + 0x10) = uVar7;
  if (*pcVar1 == '\0') {
    if ((param_2 & 0x30) == 0) {
      param_2 = param_2 & 0xffffffcf | 0x10;
    }
    else if ((param_2 & 0x30) == 0x10) {
      param_2 = param_2 & 0xffffffcf;
    }
  }
  if (*(char *)(param_1 + 0x1b) == '\0') {
    uVar5 = param_2 & 0x30;
    if (uVar5 == 0) {
      if (*(char *)(param_1 + 0x18) == '\0') {
        if ((param_2 & 7) == 1) {
          *(uint *)(param_1 + 0x10) = uVar7 | 4;
        }
        (**(code **)(*piVar6 + 0x14))(piVar6,param_2);
        goto LAB_0801f868;
      }
    }
    else {
      if (uVar5 != 0x10) {
        if (uVar5 == 0x20) {
          if ((param_2 & 7) == 1) {
            *(undefined1 *)(param_1 + 0x19) = *(undefined1 *)(param_1 + 0x18);
            if (*(char *)(param_1 + 0x18) == '\0') {
              uVar5 = 4;
            }
            else {
              uVar5 = 8;
            }
            *(uint *)(param_1 + 0x10) = uVar7 | uVar5;
          }
          (**(code **)(*piVar6 + 0x1c))(piVar6,param_2);
        }
        goto LAB_0801f868;
      }
      if (*(char *)(param_1 + 0x18) == '\0') {
        if ((param_2 & 7) == 1) {
          *(uint *)(param_1 + 0x10) = uVar7 | 4;
        }
        (**(code **)(*piVar6 + 0x10))(piVar6,param_2);
        goto LAB_0801f868;
      }
    }
    uVar7 = uVar7 | 0x80;
  }
  else {
    if ((param_2 & 0x37) != 0x21) goto LAB_0801f868;
    *(undefined1 *)(param_1 + 0x17) = 0;
    uVar7 = uVar7 | 0x104;
  }
  *(uint *)(param_1 + 0x10) = uVar7;
LAB_0801f868:
  if ((param_2 & 7) == 0) {
    *(undefined1 *)(param_1 + 0x1e) = 0;
    return param_4;
  }
  if ((param_2 & 7) == 1) {
    *(undefined1 *)(param_1 + 0x1e) = 1;
    return param_4;
  }
  return param_4;
}



/* ===== FUN_0801f898 @ 0801f898 ===== */

undefined4 * FUN_0801f898(undefined4 *param_1)

{
  FUN_080258ac(param_1,0x10);
  *param_1 = DAT_0801f8ac;
  return param_1;
}



/* ===== FUN_0801fb10 @ 0801fb10 ===== */

undefined4 FUN_0801fb10(undefined1 *param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  byte bVar4;
  int iVar5;
  
  puVar2 = DAT_0801fb90;
  piVar1 = DAT_0801fb8c;
  iVar5 = *DAT_0801fb8c;
  uVar3 = *(undefined4 *)(iVar5 + 0xc);
  if (param_1 == (undefined1 *)0x0) {
    *(undefined1 **)(iVar5 + 0xc) = DAT_0801fb90;
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(puVar2 + 0xc);
    *(undefined1 *)(iVar5 + 0x12) = *puVar2;
    param_1 = puVar2;
  }
  else {
    *(undefined1 **)(iVar5 + 0xc) = param_1;
    *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(param_1 + 0xc);
    *(undefined1 *)(iVar5 + 0x12) = *param_1;
  }
  *(undefined1 *)(*piVar1 + 0x13) = param_1[1];
  iVar5 = *piVar1;
  if ((uint)*(byte *)(iVar5 + 5) < ((uint)*(byte *)(iVar5 + 0x13) + (uint)*(byte *)(iVar5 + 1)) - 1)
  {
    *(byte *)(iVar5 + 5) = *(byte *)(iVar5 + 0x13) + *(byte *)(iVar5 + 1) + -1;
    iVar5 = *piVar1;
    if (*(byte *)(iVar5 + 3) < *(byte *)(iVar5 + 5)) {
      *(byte *)(iVar5 + 5) = *(byte *)(iVar5 + 3);
    }
  }
  iVar5 = *piVar1;
  bVar4 = *(byte *)(iVar5 + 4);
  if (*(byte *)(iVar5 + 2) < *(byte *)(iVar5 + 4)) {
    bVar4 = *(byte *)(iVar5 + 2);
  }
  *(byte *)(iVar5 + 6) = bVar4;
  *(undefined1 *)(*piVar1 + 7) = *(undefined1 *)(*piVar1 + 5);
  return uVar3;
}



/* ===== FUN_0801fb74 @ 0801fb74 ===== */

undefined1 FUN_0801fb74(int param_1)

{
  if (param_1 == 0) {
    param_1 = DAT_0801fb90;
  }
  return *(undefined1 *)(param_1 + 1);
}



/* ===== FUN_0801fb7c @ 0801fb7c ===== */

undefined2 FUN_0801fb7c(int param_1)

{
  if (param_1 == 0) {
    param_1 = DAT_0801fb90;
  }
  return *(undefined2 *)(param_1 + 2);
}



/* ===== FUN_0801fb84 @ 0801fb84 ===== */

undefined2 FUN_0801fb84(int param_1)

{
  if (param_1 == 0) {
    param_1 = DAT_0801fb90;
  }
  return *(undefined2 *)(param_1 + 8);
}



/* ===== FUN_0801fb94 @ 0801fb94 ===== */

undefined1 FUN_0801fb94(uint param_1)

{
  int iVar1;
  int unaff_r5;
  undefined1 uVar2;
  bool bVar3;
  
  iVar1 = *DAT_0801fbec;
  uVar2 = iVar1 != DAT_0801fbf0;
  if ((bool)uVar2) {
    unaff_r5 = DAT_0801fbf0 + 0x14;
  }
  if ((bool)uVar2 && iVar1 != unaff_r5) {
    uVar2 = 2;
    bVar3 = iVar1 != DAT_0801fbf0 + 0x28;
    if (bVar3) {
      uVar2 = 3;
      unaff_r5 = DAT_0801fbf0 + 0x3c;
    }
    if (bVar3 && iVar1 != unaff_r5) {
      uVar2 = 4;
      bVar3 = iVar1 != DAT_0801fbf0 + 0x50;
      if (bVar3) {
        uVar2 = 5;
        unaff_r5 = DAT_0801fbf0 + 100;
      }
      if (bVar3 && iVar1 != unaff_r5) {
        uVar2 = 0;
      }
    }
  }
  if (5 < param_1) {
    param_1 = 5;
  }
  *DAT_0801fbec = DAT_0801fbf0 + param_1 * 0x14;
  return uVar2;
}



/* ===== FUN_0801fbf4 @ 0801fbf4 ===== */

void FUN_0801fbf4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 auStack_18 [12];
  undefined4 uStack_c;
  
  uStack_c = param_4;
  FUN_0801d6e2(auStack_18);
  FUN_08019780(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
  FUN_08019d56(auStack_18);
  return;
}



/* ===== FUN_0801fc12 @ 0801fc12 ===== */

void FUN_0801fc12(uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int unaff_r9;
  
  while( true ) {
    puVar1 = param_1 + 1;
    uVar3 = *param_1;
    if (uVar3 == 0) break;
    param_1 = param_1 + 2;
    puVar4 = (undefined4 *)*puVar1;
    if ((int)puVar4 << 0x1f < 0) {
      puVar4 = (undefined4 *)(unaff_r9 + -1 + (int)puVar4);
    }
    do {
      puVar5 = puVar4;
      uVar2 = uVar3;
      puVar4 = puVar5 + 1;
      *puVar5 = 0;
      uVar3 = uVar2 - 4;
    } while (3 < uVar2 - 4);
    if ((int)(uVar2 << 0x1e) < 0) {
      *(undefined2 *)puVar4 = 0;
      puVar4 = (undefined4 *)((int)puVar5 + 6);
    }
    if ((int)(uVar2 << 0x1f) < 0) {
      *(undefined1 *)puVar4 = 0;
    }
  }
  return;
}



/* ===== FUN_0801fc4c @ 0801fc4c ===== */

void FUN_0801fc4c(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  short local_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  local_44 = *DAT_0801fc98;
  uStack_40 = DAT_0801fc98[1];
  uStack_3c = DAT_0801fc98[2];
  uStack_38 = DAT_0801fc98[3];
  uStack_34 = DAT_0801fc98[4];
  uStack_30 = DAT_0801fc98[5];
  uStack_2c = DAT_0801fc98[6];
  uStack_28 = DAT_0801fc98[7];
  uVar1 = param_2 >> 0x18;
  uStack_24 = param_4;
  if (uVar1 == 0x43 || uVar1 == 0x46) {
    local_48 = (short)param_2;
    FUN_0802c0e8(&local_44,8,DAT_0801fc9c,(int)local_48,param_2 >> 0x10 & 0xff,uVar1);
  }
  FUN_08019780(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
  FUN_08019d62(&local_44);
  return;
}



/* ===== FUN_0801fca0 @ 0801fca0 ===== */

undefined4 FUN_0801fca0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(undefined4 **)(param_1 + 0xc) != (undefined4 *)0x0) {
    uVar1 = **(undefined4 **)(param_1 + 0xc);
    FUN_0802c124(param_1,uVar1);
    *(undefined4 *)(param_1 + 8) = uVar1;
  }
  return param_4;
}



/* ===== FUN_0801fcdc @ 0801fcdc ===== */

undefined4 FUN_0801fcdc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*(char **)(param_1 + 4) != (char *)0x0) {
    cVar1 = **(char **)(param_1 + 4);
    if (1 < *(ushort *)(DAT_0801fd08 + 8)) {
      uVar2 = FUN_0802c16c(~-(uint)(cVar1 == '\0') >> 0x1f);
      FUN_0802c188(*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2),uVar2);
    }
    *(char *)(param_1 + 3) = cVar1;
  }
  return param_4;
}



/* ===== FUN_0801fd0c @ 0801fd0c ===== */

undefined4 FUN_0801fd0c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  undefined4 uVar2;
  
  if (*(byte **)(param_1 + 4) != (byte *)0x0) {
    bVar1 = **(byte **)(param_1 + 4);
    if ((ushort)bVar1 < *(ushort *)(DAT_0801fd34 + 8)) {
      uVar2 = FUN_0802c16c();
      FUN_0802c188(*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2),uVar2);
    }
    *(byte *)(param_1 + 3) = bVar1;
  }
  return param_4;
}



/* ===== FUN_0801fd38 @ 0801fd38 ===== */

undefined4 FUN_0801fd38(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*(char **)(param_1 + 4) != (char *)0x0) {
    cVar1 = **(char **)(param_1 + 4);
    if (1 < *(ushort *)(DAT_0801fd64 + 8)) {
      uVar2 = FUN_0802c16c(~-(uint)(cVar1 == '\0') >> 0x1f);
      FUN_0802c188(*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2),uVar2);
    }
    *(char *)(param_1 + 3) = cVar1;
  }
  return param_4;
}



/* ===== FUN_0801fd68 @ 0801fd68 ===== */

undefined4 FUN_0801fd68(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int unaff_r5;
  
  piVar1 = *(int **)(param_1 + 0xc);
  iVar2 = 0;
  if (piVar1 != (int *)0x0) {
    unaff_r5 = *piVar1;
    iVar2 = *(int *)(param_1 + 8);
  }
  if (piVar1 != (int *)0x0 && unaff_r5 != iVar2) {
    FUN_0802c124(param_1,unaff_r5);
    *(int *)(param_1 + 8) = unaff_r5;
  }
  return param_4;
}



/* ===== FUN_0801fd86 @ 0801fd86 ===== */

undefined4 FUN_0801fd86(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  uint unaff_r5;
  
  pbVar1 = *(byte **)(param_1 + 4);
  if (pbVar1 != (byte *)0x0) {
    unaff_r5 = (uint)*pbVar1;
    param_2 = (uint)*(byte *)(param_1 + 3);
  }
  if (pbVar1 != (byte *)0x0 && unaff_r5 != param_2) {
    FUN_0802c1e4(param_1,unaff_r5);
    *(char *)(param_1 + 3) = (char)unaff_r5;
  }
  return param_4;
}



/* ===== FUN_0801fda4 @ 0801fda4 ===== */

undefined4 FUN_0801fda4(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  undefined4 uVar2;
  byte unaff_r5;
  uint uVar3;
  
  pbVar1 = *(byte **)(param_1 + 4);
  uVar3 = 0;
  if (pbVar1 != (byte *)0x0) {
    unaff_r5 = *pbVar1;
    uVar3 = (uint)unaff_r5;
    param_2 = (uint)*(byte *)(param_1 + 3);
  }
  if (pbVar1 != (byte *)0x0 && uVar3 != param_2) {
    if (uVar3 < *(ushort *)(DAT_0801fdd4 + 8)) {
      uVar2 = FUN_0802c16c();
      FUN_0802c188(*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2),uVar2);
    }
    *(byte *)(param_1 + 3) = unaff_r5;
  }
  return param_4;
}



/* ===== FUN_0801fdd8 @ 0801fdd8 ===== */

undefined4 FUN_0801fdd8(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  undefined4 uVar2;
  uint unaff_r5;
  
  pbVar1 = *(byte **)(param_1 + 4);
  if (pbVar1 != (byte *)0x0) {
    unaff_r5 = (uint)*pbVar1;
    param_2 = (uint)*(byte *)(param_1 + 3);
  }
  if (pbVar1 != (byte *)0x0 && unaff_r5 != param_2) {
    if (1 < *(ushort *)(DAT_0801fe0c + 8)) {
      uVar2 = FUN_0802c16c(~-(uint)(unaff_r5 == 0) >> 0x1f);
      FUN_0802c188(*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2),uVar2);
    }
    *(char *)(param_1 + 3) = (char)unaff_r5;
  }
  return param_4;
}



/* ===== FUN_0801fe10 @ 0801fe10 ===== */

undefined4 FUN_0801fe10(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(undefined4 **)(param_1 + 0xc) != (undefined4 *)0x0) {
    uVar1 = **(undefined4 **)(param_1 + 0xc);
    FUN_0802c214(param_1,uVar1);
    *(undefined4 *)(param_1 + 8) = uVar1;
  }
  return param_4;
}



/* ===== FUN_0801fe26 @ 0801fe26 ===== */

undefined4 FUN_0801fe26(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  
  if (*(char **)(param_1 + 4) != (char *)0x0) {
    cVar1 = **(char **)(param_1 + 4);
    FUN_0802c28c(param_1,(int)cVar1);
    *(char *)(param_1 + 3) = cVar1;
  }
  return param_4;
}



/* ===== FUN_0801fe64 @ 0801fe64 ===== */

undefined4 FUN_0801fe64(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  undefined4 uVar2;
  
  if (*(byte **)(param_1 + 4) != (byte *)0x0) {
    bVar1 = **(byte **)(param_1 + 4);
    if ((ushort)bVar1 < *(ushort *)(DAT_0801fe8c + 8)) {
      uVar2 = FUN_0802c16c();
      FUN_0802c188(*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2),uVar2);
    }
    *(byte *)(param_1 + 3) = bVar1;
  }
  return param_4;
}



/* ===== FUN_0801fe90 @ 0801fe90 ===== */

undefined4 FUN_0801fe90(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int unaff_r5;
  
  piVar1 = *(int **)(param_1 + 0xc);
  iVar2 = 0;
  if (piVar1 != (int *)0x0) {
    unaff_r5 = *piVar1;
    iVar2 = *(int *)(param_1 + 8);
  }
  if (piVar1 != (int *)0x0 && unaff_r5 != iVar2) {
    FUN_0802c214(param_1,unaff_r5);
    *(int *)(param_1 + 8) = unaff_r5;
  }
  return param_4;
}



/* ===== FUN_0801feae @ 0801feae ===== */

undefined4 FUN_0801feae(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  int unaff_r5;
  
  pcVar1 = *(char **)(param_1 + 4);
  if (pcVar1 != (char *)0x0) {
    unaff_r5 = (int)*pcVar1;
    param_2 = (int)*(char *)(param_1 + 3);
  }
  if (pcVar1 != (char *)0x0 && unaff_r5 != param_2) {
    FUN_0802c28c(param_1,unaff_r5);
    *(char *)(param_1 + 3) = (char)unaff_r5;
  }
  return param_4;
}



/* ===== FUN_0801ff04 @ 0801ff04 ===== */

void FUN_0801ff04(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < *(ushort *)(DAT_0801ff28 + 8)) {
    uVar1 = FUN_0802c16c();
    FUN_0802c188(*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2),uVar1);
    return;
  }
  return;
}



/* ===== FUN_0801ff2c @ 0801ff2c ===== */

void FUN_0801ff2c(int param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 local_28;
  undefined1 local_27;
  char local_26;
  undefined1 local_25;
  int local_24;
  undefined1 auStack_20 [20];
  
  uVar2 = (uint)((ulonglong)param_2 * (ulonglong)DAT_0801ffc4 >> 0x28) + 1 >> 1;
  if (uVar2 == 0) {
    local_24 = *DAT_0801ffc8;
  }
  else if (uVar2 < 10) {
    local_24 = uVar2 + 0x30;
  }
  else {
    local_24 = 0x30;
  }
  FUN_0801a2bc(auStack_20,*(undefined4 *)(*(int *)(DAT_0801ffcc + 0x70) + 0x50));
  uVar3 = FUN_080197c8(0x2184);
  FUN_0802c2fc(&local_26,&local_27,&local_25,&local_28);
  cVar1 = *(char *)(param_1 + 4) + local_26;
  FUN_0802af5c(cVar1,local_27,*(char *)(param_1 + 0x10) + cVar1,local_28);
  FUN_08019780(0,*(undefined1 *)(param_1 + 5));
  FUN_08019d62(&local_24);
  FUN_0802af5c(local_26,local_27,local_25,local_28);
  FUN_080197c8(uVar3);
  return;
}



/* ===== FUN_0801ffd0 @ 0801ffd0 ===== */

undefined4 FUN_0801ffd0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(undefined4 **)(param_1 + 0xc) != (undefined4 *)0x0) {
    uVar1 = **(undefined4 **)(param_1 + 0xc);
    FUN_0802c330(param_1,uVar1);
    *(undefined4 *)(param_1 + 8) = uVar1;
  }
  return param_4;
}



/* ===== FUN_0801ffe6 @ 0801ffe6 ===== */

undefined8 FUN_0801ffe6(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 local_18;
  undefined1 local_17;
  char local_16;
  undefined1 local_15;
  undefined4 uStack_14;
  
  local_18 = (undefined1)param_3;
  local_17 = (undefined1)((uint)param_3 >> 8);
  local_16 = (char)((uint)param_3 >> 0x10);
  local_15 = (undefined1)((uint)param_3 >> 0x18);
  uStack_14 = param_4;
  uVar2 = FUN_080197c8(0x2184);
  FUN_0802c2fc(&local_16,&local_17,&local_15,&local_18);
  cVar1 = *(char *)(param_1 + 4) + local_16;
  FUN_0802af5c(cVar1,local_17,*(char *)(param_1 + 0x10) + cVar1,local_18);
  FUN_08019780(0,*(undefined1 *)(param_1 + 5));
  FUN_08019d62(param_2);
  FUN_0802af5c(local_16,local_17,local_15,local_18);
  FUN_080197c8(uVar2);
  return CONCAT44(uStack_14,CONCAT13(local_15,CONCAT12(local_16,CONCAT11(local_17,local_18))));
}



/* ===== FUN_0802006c @ 0802006c ===== */

undefined8 FUN_0802006c(void)

{
  int *piVar1;
  char cVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 in_r3;
  
  piVar1 = DAT_080200d8;
  *DAT_080200d4 = 0;
  puVar3 = (undefined1 *)*piVar1;
  if ((int)((uint)(byte)puVar3[0x10] << 0x1f) < 0) {
    uVar5 = 0xffff;
  }
  else {
    uVar5 = 0;
  }
  FUN_08026a64(*puVar3,puVar3[1],puVar3[2],puVar3[3]);
  FUN_0802ad48();
  ((undefined1 *)*piVar1)[4] = *(undefined1 *)*piVar1;
  cVar2 = FUN_0801fb74(*(undefined4 *)(*piVar1 + 0xc));
  *(char *)(*piVar1 + 5) = cVar2 + *(char *)(*piVar1 + 1) + -1;
  if (0x7f < *(byte *)(*piVar1 + 4)) {
    *(undefined1 *)(*piVar1 + 4) = 0x7f;
  }
  iVar4 = *piVar1;
  if (*(byte *)(iVar4 + 3) < *(byte *)(iVar4 + 5)) {
    *(byte *)(iVar4 + 5) = *(byte *)(iVar4 + 3);
  }
  ((undefined1 *)*piVar1)[6] = *(undefined1 *)*piVar1;
  *(undefined1 *)(*piVar1 + 7) = *(undefined1 *)(*piVar1 + 1);
  return CONCAT44(in_r3,uVar5);
}



/* ===== FUN_080200dc @ 080200dc ===== */

void FUN_080200dc(char param_1,char param_2)

{
  int *piVar1;
  
  piVar1 = DAT_08020240;
  ((char *)*DAT_08020240)[6] = *(char *)*DAT_08020240 + param_1;
  *(char *)(*piVar1 + 7) = *(char *)(*piVar1 + 1) + param_2;
  return;
}



/* ===== FUN_080200f6 @ 080200f6 ===== */

void FUN_080200f6(char param_1,char param_2,undefined4 param_3,uint param_4)

{
  int *piVar1;
  undefined1 *puVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  char *pcVar9;
  uint local_18;
  
  piVar1 = DAT_08020240;
  pcVar9 = (char *)*DAT_08020240;
  bVar6 = pcVar9[6];
  bVar8 = pcVar9[7];
  bVar4 = *pcVar9 + param_1;
  pcVar9[6] = bVar4;
  puVar2 = DAT_08020244;
  bVar3 = pcVar9[1] + param_2;
  *(byte *)(*piVar1 + 7) = bVar3;
  *puVar2 = 0;
  bVar7 = 0;
  if (bVar6 != bVar4) {
    bVar7 = bVar3;
  }
  if (bVar6 != bVar4 && bVar8 != bVar7) {
    FUN_08020188(bVar6,bVar8,bVar4);
    local_18 = param_4;
  }
  else {
    pbVar5 = (byte *)*piVar1;
    if (bVar6 < *pbVar5) {
      bVar6 = *pbVar5;
    }
    if (pbVar5[2] < bVar4) {
      bVar4 = pbVar5[2];
    }
    if (bVar8 < pbVar5[1]) {
      bVar8 = pbVar5[1];
    }
    if (pbVar5[3] < bVar3) {
      bVar3 = pbVar5[3];
    }
    bVar7 = bVar6;
    if (bVar4 < bVar6) {
      bVar7 = bVar4;
      bVar4 = bVar6;
    }
    bVar6 = bVar3;
    if (bVar3 < bVar8) {
      bVar6 = bVar8;
      bVar8 = bVar3;
    }
    local_18 = pbVar5[0x10] & 1 ^ 1;
    FUN_0802c630(bVar7,bVar8,bVar4,bVar6);
  }
  FUN_0802ad48(local_18);
  return;
}



/* ===== FUN_08020188 @ 08020188 ===== */

void FUN_08020188(uint param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  short sVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  bool bVar15;
  
  param_3 = param_3 - param_1;
  param_4 = param_4 - param_2;
  if (param_3 < 0) {
    param_3 = -param_3;
    iVar8 = -1;
  }
  else {
    iVar8 = 1;
  }
  if (param_4 < 0) {
    param_4 = -param_4;
    iVar6 = -1;
  }
  else {
    iVar6 = 1;
  }
  if (param_3 < param_4) {
    iVar4 = param_4;
    param_4 = param_3;
    iVar12 = 0;
    iVar13 = iVar6;
  }
  else {
    iVar13 = 0;
    iVar4 = param_3;
    iVar12 = iVar8;
  }
  iVar11 = (int)(short)((short)(param_4 * 2) - (short)iVar4);
  iVar14 = iVar11 - iVar4;
  for (sVar10 = 0; sVar10 <= iVar4; sVar10 = sVar10 + 1) {
    pbVar7 = (byte *)*DAT_08020240;
    uVar5 = (uint)*pbVar7;
    uVar9 = param_1 & 0xff;
    bVar15 = uVar5 <= uVar9;
    if (bVar15) {
      uVar9 = (uint)pbVar7[2];
      uVar5 = param_1 & 0xff;
    }
    if (bVar15 && uVar5 <= uVar9) {
      uVar5 = (uint)pbVar7[1];
      uVar9 = param_2 & 0xff;
      bVar15 = uVar5 <= uVar9;
      if (bVar15) {
        uVar9 = (uint)pbVar7[3];
        uVar5 = param_2 & 0xff;
      }
      if (bVar15 && uVar5 <= uVar9) {
        FUN_0802c6ac(param_1 & 0xff,param_2 & 0xff,pbVar7[0x10] & 1 ^ 1);
      }
    }
    iVar1 = iVar12;
    iVar2 = param_4 * 2;
    iVar3 = iVar13;
    if (-1 < (short)iVar11) {
      iVar1 = iVar8;
      iVar2 = iVar14;
      iVar3 = iVar6;
    }
    param_2 = param_2 + iVar3;
    iVar11 = iVar2 + iVar11;
    param_1 = param_1 + iVar1;
  }
  return;
}



/* ===== FUN_08020248 @ 08020248 ===== */

undefined4 FUN_08020248(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(byte **)(param_1 + 0xc) != (byte *)0x0) {
    uVar1 = *(undefined4 *)(*(int *)(DAT_0802026c + 0x70) + (uint)**(byte **)(param_1 + 0xc) * 4);
    FUN_08019780(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
    FUN_08019d62(uVar1);
    *(undefined4 *)(param_1 + 8) = uVar1;
  }
  return param_4;
}



/* ===== FUN_08020270 @ 08020270 ===== */

undefined8 FUN_08020270(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  undefined1 local_10;
  char local_f [3];
  undefined4 local_c;
  
  local_10 = (undefined1)param_3;
  local_f[0] = (char)((uint)param_3 >> 8);
  local_f[1] = (char)((uint)param_3 >> 0x10);
  local_f[2] = (char)((uint)param_3 >> 0x18);
  local_c = param_4;
  if ((param_2 & 0xff) != 0) {
    pcVar3 = local_f;
    cVar1 = (char)(param_2 >> 8);
    if (cVar1 != '\0') {
      local_f[0] = -0x60;
      pcVar3 = local_f + 2;
      cVar2 = (char)(param_2 >> 0x10);
      local_f[1] = cVar1;
      if (cVar2 != '\0') {
        local_f[2] = 0xa0;
        local_c = CONCAT31((int3)((uint)param_4 >> 8),cVar2);
        pcVar3 = (char *)((int)&local_c + 1);
      }
    }
    *pcVar3 = '\0';
    local_10 = (char)param_2;
    FUN_08019780(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
    FUN_08019d56(&local_10);
  }
  return CONCAT44(local_c,CONCAT13(local_f[2],CONCAT12(local_f[1],CONCAT11(local_f[0],local_10))));
}



/* ===== FUN_080202d4 @ 080202d4 ===== */

undefined4 FUN_080202d4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (*(byte **)(param_1 + 0xc) != (byte *)0x0) {
    iVar1 = *(int *)(*(int *)(DAT_08020300 + 0x70) + (uint)**(byte **)(param_1 + 0xc) * 4);
    if (iVar1 != *(int *)(param_1 + 8)) {
      FUN_08019780(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
      FUN_08019d62(iVar1);
      *(int *)(param_1 + 8) = iVar1;
    }
  }
  return param_4;
}



/* ===== FUN_08020304 @ 08020304 ===== */

void FUN_08020304(int *param_1,int *param_2)

{
  if (param_2 != (int *)0x0) {
    if (param_1[1] == 0) {
      param_1[1] = (int)param_2;
      *param_1 = (int)param_2;
      param_2[2] = 0;
      param_2[1] = 0;
    }
    else {
      param_2[1] = param_1[1];
      *(int **)(param_1[1] + 8) = param_2;
      param_1[1] = (int)param_2;
      param_2[2] = 0;
    }
    (**(code **)(*param_2 + 8))(param_2);
    *(undefined1 *)(param_1 + 2) = 1;
  }
  return;
}



/* ===== FUN_08020334 @ 08020334 ===== */

uint FUN_08020334(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar3 = ((param_1 & 0x7fffffff) >> 0x17) - 0x7e;
  if (iVar3 < 0) {
    return 0;
  }
  uVar5 = (int)param_1 >> 0x1f;
  uVar4 = 0x20 - iVar3;
  if (uVar4 == 0 || 0x20 < iVar3) {
    return ~uVar5 ^ 0x80000000;
  }
  uVar2 = param_1 << 8 | 0x80000000;
  uVar1 = uVar4 & 0xff;
  return (uVar2 >> (uVar4 & 0xff)) + uVar5 +
         (uint)(uVar1 == 0 && (param_1 & 0x1000000) != 0 ||
               uVar1 != 0 && (uVar2 >> uVar1 - 1 & 1) != 0) ^ uVar5;
}



/* ===== FUN_0802036c @ 0802036c ===== */

undefined1 FUN_0802036c(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = (int)((ulonglong)((longlong)param_1 * (longlong)DAT_0802038c) >> 0x20);
  uVar2 = param_1 + (iVar3 - (iVar3 >> 0x1f)) * -3 + 4;
  uVar1 = (undefined1)uVar2;
  if ((uVar2 & 0xff) == 6) {
    uVar1 = 4;
  }
  return uVar1;
}



/* ===== FUN_080203a8 @ 080203a8 ===== */

undefined4 * FUN_080203a8(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  do {
    uVar3 = param_2;
    if (0xf < uVar3) {
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      param_1[3] = 0;
      param_1 = param_1 + 4;
    }
    param_2 = uVar3 - 0x10;
  } while (0xf < uVar3 && uVar3 - 0x10 != 0);
  if ((uVar3 & 8) != 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1 = param_1 + 2;
  }
  puVar2 = param_1;
  if ((int)(uVar3 << 0x1d) < 0) {
    puVar2 = param_1 + 1;
    *param_1 = 0;
  }
  puVar1 = puVar2;
  if ((uVar3 & 2) != 0) {
    puVar1 = (undefined4 *)((int)puVar2 + 2);
    *(undefined2 *)puVar2 = 0;
  }
  puVar2 = puVar1;
  if ((int)(uVar3 << 0x1f) < 0) {
    puVar2 = (undefined4 *)((int)puVar1 + 1);
    *(undefined1 *)puVar1 = 0;
  }
  return puVar2;
}



/* ===== FUN_080203b0 @ 080203b0 ===== */

undefined4 FUN_080203b0(byte *param_1,int *param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  byte *pbVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  uint in_fpscr;
  float fVar14;
  float fVar15;
  
  puVar8 = DAT_08020500;
  uVar11 = 0xffffffff;
  bVar1 = *(byte *)(DAT_08020504 + ((*DAT_08020500 & 0x1ff) >> 7));
  uVar10 = 0;
  iVar9 = 0;
  puVar13 = (uint *)(param_1 + 0x6c);
  do {
    if (param_3 < 1) break;
    uVar2 = 0;
    uVar12 = 0;
    piVar6 = param_2;
    do {
      param_2 = piVar6;
      if (bVar1 <= uVar12) break;
      param_2 = piVar6 + 1;
      uVar12 = uVar12 + 1;
      param_3 = param_3 + -1;
      uVar2 = uVar2 + *piVar6;
      piVar6 = param_2;
    } while (0 < param_3);
    if (uVar10 <= uVar2) {
      uVar10 = uVar2;
    }
    if ((uVar2 < uVar11) && (uVar2 != 0)) {
      uVar11 = uVar2;
    }
    iVar9 = iVar9 + 1;
    *puVar13 = uVar2;
    puVar13 = puVar13 + 1;
  } while (iVar9 < 0x69);
  if (iVar9 < 0x69) {
    FUN_08025ca4(param_1 + iVar9 * 4 + 0x6c,(0x69 - iVar9) * 4);
  }
  if (uVar10 == 0) {
    uVar5 = FUN_080203a8(param_1 + 0x6c,0x1a4);
    param_1[0x210] = 1;
    return uVar5;
  }
  if (-1 < (int)((uint)*(byte *)((int)puVar8 + 1) << 0x1e)) {
    fVar14 = (float)VectorUnsignedToFloat(uVar10,(byte)(in_fpscr >> 0x16) & 3);
    puVar8 = (uint *)(param_1 + 0x6c);
    iVar9 = 0x69;
    pbVar7 = param_1;
    do {
      fVar15 = (float)VectorUnsignedToFloat(*puVar8,(byte)(in_fpscr >> 0x16) & 3);
      uVar10 = VectorFloatToUnsigned(fVar15 * (27.0 / fVar14) + 0.5,3);
      *puVar8 = uVar10;
      if (uVar10 != *pbVar7) {
        param_1[0x210] = 1;
      }
      puVar8 = puVar8 + 1;
      pbVar7 = pbVar7 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    return param_4;
  }
  iVar3 = FUN_080160bc(uVar10,0x10000,0);
  iVar9 = 0;
  if (uVar11 != 0) {
    iVar9 = FUN_080160bc(uVar11,0x10000,0);
    iVar3 = iVar3 - iVar9;
  }
  fVar14 = (float)VectorUnsignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
  puVar8 = (uint *)(param_1 + 0x6c);
  iVar3 = 0x69;
  pbVar7 = param_1;
  do {
    uVar10 = 0;
    if (*puVar8 != 0) {
      iVar4 = FUN_080160bc(*puVar8,0x10000,0);
      fVar15 = (float)VectorUnsignedToFloat(iVar4 - iVar9,(byte)(in_fpscr >> 0x16) & 3);
      uVar10 = VectorFloatToUnsigned(fVar15 * (27.0 / fVar14) + 1.5,3);
      *puVar8 = uVar10;
    }
    if (uVar10 != *pbVar7) {
      param_1[0x210] = 1;
    }
    puVar8 = puVar8 + 1;
    pbVar7 = pbVar7 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return param_4;
}



/* ===== FUN_08020670 @ 08020670 ===== */

void FUN_08020670(void)

{
  undefined1 *puVar1;
  
  puVar1 = DAT_08020b50;
  *DAT_08020b50 = 0;
  *(undefined4 *)(puVar1 + 0xc) = 0;
  *(undefined4 *)(puVar1 + 0x10) = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  *(undefined4 *)(puVar1 + 4) = 0;
  *(undefined4 *)(puVar1 + 8) = 0;
  *(undefined4 *)(puVar1 + 0x24) = 0;
  *(undefined4 *)(puVar1 + 0x28) = 0;
  *(undefined4 *)(puVar1 + 0x38) = 1000;
  *(undefined4 *)(puVar1 + 0x30) = 1000;
  return;
}



/* ===== FUN_08020692 @ 08020692 ===== */

void FUN_08020692(void)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = DAT_08020b50;
  while( true ) {
    disableIRQinterrupts();
    pcVar2 = *(code **)(iVar1 + 4);
    *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(iVar1 + 8) = 0;
    enableIRQinterrupts();
    if (pcVar2 == (code *)0x0) break;
    (*pcVar2)();
  }
  return;
}



/* ===== FUN_08020730 @ 08020730 ===== */

undefined4 FUN_08020730(int param_1,int param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  
  puVar5 = DAT_08020b60;
  puVar2 = DAT_08020b50;
  if (param_1 != 0) {
    DAT_08020b60[3] = DAT_08020b60[3] & 0xfffffffe;
    *puVar2 = 1;
    iVar3 = DAT_08020b58;
    uVar1 = (undefined1)param_1;
    if (puVar2[1] == '\0') {
      *DAT_08020b54 = 1;
      *(int *)(puVar2 + 0xc) = param_2;
      *(undefined4 *)(puVar2 + 0x14) = 0;
      *(undefined4 *)(puVar2 + 0x18) = 0;
      *(undefined4 *)(puVar2 + 0x1c) = 0;
      *(undefined4 *)(puVar2 + 0x20) = 0;
      puVar2[1] = uVar1;
      *(undefined4 *)(puVar2 + 0x24) = param_3;
      puVar2[2] = 0;
      *(undefined4 *)(puVar2 + 0x10) = 0;
      *(undefined4 *)(puVar2 + 0x2c) = *(undefined4 *)(iVar3 + param_1 * 8 + 4);
      *(undefined4 *)(puVar2 + 0x3c) = 1000;
      *(undefined4 *)(puVar2 + 0x34) = 1000;
      puVar4 = DAT_08020b5c;
      DAT_08020b5c[0xb] = 2999;
      *puVar4 = *puVar4 | 1;
      *puVar5 = *puVar5 & 0xfffffffe;
      puVar5[9] = 0;
      puVar5[4] = 0xfffffffe;
      puVar5[3] = puVar5[3] | 1;
      puVar5[0xb] = 1;
      *puVar5 = *puVar5 | 1;
      *puVar2 = 0;
      return 1;
    }
    if (*(char *)(DAT_08020b58 + (uint)(byte)puVar2[1] * 8) == '\x03') {
      if (*(int *)(puVar2 + 0x10) < param_2) {
        puVar2[2] = 0;
        *(int *)(puVar2 + 0x10) = param_2;
        *(int *)(puVar2 + 0xc) = param_2;
        *(undefined4 *)(puVar2 + 0x28) = param_3;
        puVar2[2] = uVar1;
        *puVar2 = 0;
        puVar5[3] = puVar5[3] | 1;
        return 1;
      }
    }
    else if (*(int *)(puVar2 + 0xc) < param_2) {
      *(int *)(puVar2 + 0xc) = param_2;
      *(undefined4 *)(puVar2 + 0x24) = param_3;
      puVar2[1] = uVar1;
      *(undefined4 *)(puVar2 + 0x3c) = *(undefined4 *)(puVar2 + 0x38);
      *(undefined4 *)(puVar2 + 0x34) = *(undefined4 *)(puVar2 + 0x30);
      *(undefined4 *)(puVar2 + 0x14) = 0;
      *(undefined4 *)(puVar2 + 0x18) = 0;
      *(undefined4 *)(puVar2 + 0x1c) = 0;
      *(undefined4 *)(puVar2 + 0x20) = 0;
      puVar2[2] = 0;
      *(undefined4 *)(puVar2 + 0x10) = 0;
      puVar4 = DAT_08020b5c;
      *(undefined4 *)(puVar2 + 0x2c) = *(undefined4 *)(iVar3 + param_1 * 8 + 4);
      puVar4[0xb] = 2999;
      *puVar4 = *puVar4 | 1;
      *puVar5 = *puVar5 & 0xfffffffe;
      puVar5[9] = 0;
      puVar5[4] = 0xfffffffe;
      puVar5[3] = puVar5[3] | 1;
      puVar5[0xb] = 1;
      *puVar5 = *puVar5 | 1;
      *puVar2 = 0;
      return 1;
    }
    *puVar2 = 0;
    puVar5[3] = puVar5[3] | 1;
  }
  return 0;
}



/* ===== FUN_0802086a @ 0802086a ===== */

void FUN_0802086a(uint param_1)

{
  bool bVar1;
  int iVar2;
  uint *puVar3;
  bool bVar4;
  
  iVar2 = DAT_08020b50;
  bVar1 = false;
  if (param_1 == 0) {
    bVar4 = true;
    bVar1 = true;
  }
  else {
    bVar4 = param_1 == *(byte *)(DAT_08020b50 + 1);
    if (param_1 == *(byte *)(DAT_08020b50 + 2)) {
      bVar1 = true;
    }
  }
  if (((*(char *)(DAT_08020b50 + 2) == '\0') || (0x10 < *(byte *)(DAT_08020b50 + 2))) || (bVar1)) {
    *(undefined1 *)(DAT_08020b50 + 2) = 0;
    *(undefined4 *)(iVar2 + 0x10) = 0;
    *(undefined4 *)(iVar2 + 0x28) = 0;
    if (bVar4) {
      *DAT_08020b64 = *DAT_08020b64 & 0xffff7fff;
      puVar3 = DAT_08020b5c;
      *DAT_08020b5c = *DAT_08020b5c & 0xfffffffe;
      puVar3[3] = puVar3[3] & 0xfffffeff;
      DataSynchronizationBarrier(0xf);
      DataMemoryBarrier(0x1f);
      *DAT_08020b68 = *DAT_08020b68 & 0xfffffffe;
      DataSynchronizationBarrier(0xf);
      DataMemoryBarrier(0x1f);
      *(undefined1 *)(iVar2 + 1) = 0;
      *(undefined4 *)(iVar2 + 0xc) = 0;
      *(undefined4 *)(iVar2 + 0x24) = 0;
      *(undefined4 *)(iVar2 + 0x2c) = 0;
      *DAT_08020b54 = 0;
      return;
    }
  }
  else if (bVar4) {
    *(undefined1 *)(DAT_08020b50 + 1) = *(undefined1 *)(DAT_08020b50 + 2);
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 0x10);
    *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar2 + 0x28);
    *(undefined1 *)(iVar2 + 2) = 0;
    *(undefined4 *)(iVar2 + 0x10) = 0;
    *(undefined4 *)(iVar2 + 0x28) = 0;
    *(undefined4 *)(iVar2 + 0x2c) =
         *(undefined4 *)(DAT_08020b58 + (uint)*(byte *)(iVar2 + 2) * 8 + 4);
  }
  return;
}



/* ===== FUN_08020914 @ 08020914 ===== */

undefined4 FUN_08020914(uint param_1)

{
  uint uVar1;
  bool bVar2;
  
  bVar2 = param_1 != *(byte *)(DAT_08020b50 + 1);
  uVar1 = DAT_08020b50;
  if (bVar2) {
    uVar1 = (uint)*(byte *)(DAT_08020b50 + 2);
  }
  if (bVar2 && param_1 != uVar1) {
    return 0;
  }
  return 1;
}



/* ===== FUN_0802092a @ 0802092a ===== */

undefined4 FUN_0802092a(void)

{
  return *(undefined4 *)(DAT_08020b50 + 0xc);
}



/* ===== FUN_08020934 @ 08020934 ===== */

undefined8 FUN_08020934(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  undefined *puVar9;
  uint local_20;
  uint local_1c;
  
  puVar5 = DAT_08020b6c;
  puVar2 = DAT_08020b5c;
  DAT_08020b6c[0x11] = DAT_08020b6c[0x11] & 0xffff7fff;
  *puVar2 = *puVar2 & 0xfffffffe;
  puVar2[3] = puVar2[3] & 0xfffffeff;
  puVar4 = DAT_08020b68;
  DataSynchronizationBarrier(0xf);
  DataMemoryBarrier(0x1f);
  *DAT_08020b68 = *DAT_08020b68 & 0xfffffffe;
  iVar1 = DAT_08020b50;
  DataSynchronizationBarrier(0xf);
  DataMemoryBarrier(0x1f);
  iVar8 = *(int *)(DAT_08020b50 + 0x2c);
  local_20 = param_3;
  local_1c = param_4;
  if (iVar8 == 0) {
    *(undefined1 *)(DAT_08020b50 + 1) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *DAT_08020b54 = 0;
    if (*(int *)(iVar1 + 4) == 0) {
      *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(iVar1 + 0x24);
    }
    else {
      *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 0x24);
    }
    *(undefined4 *)(iVar1 + 0x24) = 0;
    puVar9 = (undefined *)0x0;
  }
  else if (*(char *)(DAT_08020b50 + 1) == '\0') {
    puVar9 = (undefined *)0x0;
  }
  else {
    local_1c = (((uint)((*(int *)(iVar8 + 4) + 1) * 1000) / *(uint *)(DAT_08020b50 + 0x38)) * 1000)
               / *(uint *)(DAT_08020b50 + 0x3c) - 1;
    local_20 = ((DAT_08020b70 / *(uint *)(DAT_08020b50 + 0x30)) * 1000) /
               *(uint *)(DAT_08020b50 + 0x34);
    if (local_20 < 0xff) {
      local_20 = 0xff;
    }
    iVar6 = (**(code **)(iVar8 + 0x1c))(iVar8,&local_20,&local_1c);
    puVar2[0xb] = local_1c;
    puVar3 = DAT_08020b60;
    *DAT_08020b60 = *DAT_08020b60 & 0xfffffffe;
    puVar3[9] = 0;
    puVar3[0xb] = *(uint *)(iVar8 + 8);
    *puVar5 = *puVar5 & 0xfffffffe;
    puVar5[0xb] = local_20;
    if (iVar6 != 0) {
      puVar4[1] = *(uint *)(iVar8 + 0xc) | puVar4[1] & 0xffff0000;
      *puVar4 = *puVar4 | 1;
      puVar2[3] = puVar2[3] | 0x100;
      puVar5[0x11] = puVar5[0x11] | 0x8000;
    }
    *puVar2 = *puVar2 | 1;
    piVar7 = *(int **)(iVar8 + 0x14);
    if (piVar7 == (int *)0x0) {
      puVar9 = *(undefined **)(iVar8 + 0x10);
      if (puVar9 == &UNK_08020b88) {
        puVar9 = (undefined *)(*(int *)(iVar1 + 0x2c) + 0x20);
      }
      else if (((puVar9 == (undefined *)0x0) && (*(char *)(iVar1 + 2) != '\0')) &&
              (*(byte *)(iVar1 + 2) < 0x11)) {
        *(undefined1 *)(iVar1 + 1) = *(undefined1 *)(iVar1 + 2);
        *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar1 + 0x10);
        iVar8 = DAT_08020b74;
        *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar1 + 0x28);
        puVar9 = *(undefined **)(iVar8 + (uint)*(byte *)(iVar1 + 2) * 8);
        *(undefined1 *)(iVar1 + 2) = 0;
        *(undefined4 *)(iVar1 + 0x10) = 0;
        *(undefined4 *)(iVar1 + 0x28) = 0;
      }
    }
    else {
      if (*piVar7 == 0) {
        iVar6 = *(int *)(iVar8 + 0x18);
      }
      else {
        iVar6 = *piVar7 + -1;
      }
      *piVar7 = iVar6;
      if (iVar6 == 0) {
        *(undefined4 *)(iVar1 + 0x3c) = *(undefined4 *)(iVar1 + 0x38);
        puVar9 = (undefined *)(*(int *)(iVar1 + 0x2c) + 0x20);
        *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(iVar1 + 0x30);
      }
      else {
        puVar9 = *(undefined **)(iVar8 + 0x10);
      }
    }
  }
  puVar2 = DAT_08020b60;
  DAT_08020b60[4] = 0xfffffffe;
  *puVar2 = *puVar2 | 1;
  *puVar5 = *puVar5 | 1;
  *(undefined **)(iVar1 + 0x2c) = puVar9;
  return CONCAT44(local_1c,local_20);
}



/* ===== FUN_08020ab6 @ 08020ab6 ===== */

undefined4 FUN_08020ab6(undefined4 *param_1)

{
  FUN_080249ac(DAT_08020b78 + 0x300,DAT_08020b78,0x300);
  *DAT_08020b7c = *param_1;
  DataSynchronizationBarrier(0xf);
  DataMemoryBarrier(0x1f);
  return 1;
}



/* ===== FUN_08020b84 @ 08020b84 ===== */

undefined4 FUN_08020b84(void)

{
  return 0;
}



/* ===== FUN_08020bae @ 08020bae ===== */

void FUN_08020bae(void)

{
  *DAT_08020c80 = 0x4000;
  return;
}



/* ===== FUN_08020bb2 @ 08020bb2 ===== */

void FUN_08020bb2(void)

{
  *DAT_08020c84 = 0x4000;
  return;
}



/* ===== FUN_08020bbc @ 08020bbc ===== */

void FUN_08020bbc(void)

{
  int iVar1;
  
  iVar1 = DAT_08020c7c;
  *DAT_08020c84 = 0x4000;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  return;
}



/* ===== FUN_08020be8 @ 08020be8 ===== */

longlong FUN_08020be8(int param_1,int param_2)

{
  uint unaff_r7;
  
  if (*(int *)(param_1 + 0x18) < param_2) {
    *(int *)(param_1 + 0x18) = param_2;
    FUN_0801692a(param_1,&UNK_08020c8c,2,0);
    return CONCAT44(unaff_r7,1);
  }
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08020c00 @ 08020c00 ===== */

longlong FUN_08020c00(int param_1,int param_2)

{
  uint unaff_r7;
  
  if (*(int *)(param_1 + 0x18) < param_2) {
    *(int *)(param_1 + 0x18) = param_2;
    FUN_0801692a(param_1,&DAT_08020c9c,2,0);
    return CONCAT44(unaff_r7,1);
  }
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08020c20 @ 08020c20 ===== */

longlong FUN_08020c20(int param_1,int param_2)

{
  uint unaff_r7;
  
  if (*(int *)(param_1 + 0x18) < param_2) {
    *(int *)(param_1 + 0x18) = param_2;
    FUN_0801692a(param_1,&UNK_08020cac,4,0x4000);
    return CONCAT44(unaff_r7,1);
  }
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08020c38 @ 08020c38 ===== */

undefined4 FUN_08020c38(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  if (param_3 == 1) {
    puVar2 = &LAB_08020ccc;
    uVar1 = 4;
  }
  else {
    if (1 < param_3 - 2U) {
      return 0;
    }
    uVar1 = 6;
    puVar2 = DAT_08020c88;
  }
  *(undefined4 *)(param_1 + 0x1c) = param_4;
  *(undefined4 *)(param_1 + 0x18) = param_2;
  FUN_0801692a(param_1,puVar2,uVar1,0);
  return 1;
}



/* ===== FUN_08020c66 @ 08020c66 ===== */

undefined4 FUN_08020c66(void)

{
  int iVar1;
  undefined4 unaff_r7;
  
  FUN_080168b4();
  iVar1 = DAT_08020c7c;
  *DAT_08020c84 = 0x4000;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  return unaff_r7;
}



/* ===== FUN_08020d00 @ 08020d00 ===== */

void FUN_08020d00(int param_1)

{
  char cVar1;
  char *pcVar2;
  char cVar3;
  bool bVar4;
  
  if (*(char *)(param_1 + 0xc) != '\0') {
    return;
  }
  pcVar2 = (char *)FUN_08015b32();
  cVar3 = '\0';
  if (*pcVar2 == ' ') {
    cVar1 = pcVar2[1];
    cVar3 = '\x02';
    bVar4 = cVar1 == ' ';
    if (bVar4) {
      cVar3 = '\x04';
      cVar1 = pcVar2[2];
    }
    if (bVar4 && cVar1 == ' ') {
      return;
    }
  }
  pcVar2[3] = cVar3 + '\x01';
  FUN_08016890(param_1,0x4000);
  return;
}



/* ===== FUN_08020d38 @ 08020d38 ===== */

void FUN_08020d38(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_1 + 0xd) = 0;
  FUN_080148de();
  FUN_08018650(8);
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined1 *)(param_1 + 0x15) = 0;
  *(undefined1 *)(param_1 + 0x17) = 0;
  *(undefined1 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 0x16) = 0;
  uVar1 = DAT_08021124;
  FUN_08016798(DAT_08021124);
  *(undefined1 *)(param_1 + 0x19) = 0;
  *(undefined1 *)(param_1 + 0x1a) = 0;
  *(undefined1 *)(param_1 + 0x1b) = 0;
  *(undefined1 *)(param_1 + 0x1c) = 0;
  FUN_08016798(uVar1,1);
  *(undefined1 *)(param_1 + 0x1e) = 0;
  *(undefined1 *)(param_1 + 0x1f) = 0;
  *(undefined1 *)(param_1 + 0x20) = 0;
  *(undefined1 *)(param_1 + 0x21) = 0;
  FUN_08016798(uVar1,2,param_4);
  return;
}



/* ===== FUN_08020d8e @ 08020d8e ===== */

undefined4 FUN_08020d8e(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == 0) {
    uVar1 = 0x300;
    iVar2 = 8;
  }
  else if (param_2 == 2) {
    uVar1 = 0x18;
    iVar2 = 3;
  }
  else {
    if (1 < param_2) {
      return param_4;
    }
    uVar1 = 3;
    iVar2 = 0;
  }
  iVar3 = param_2 * 5 + param_1;
  if (-1 < param_3) {
    FUN_08018620(uVar1,param_3 << iVar2);
    iVar2 = (int)*(char *)(iVar3 + 0x14);
    *(char *)(iVar3 + 0x14) = (char)param_3;
    if (param_3 != iVar2) {
      if (param_3 < iVar2) {
        if ((*(byte *)(iVar3 + 0x17) == 1) && (*(char *)(iVar3 + 0x15) = (char)param_3, param_3 < 1)
           ) {
          *(undefined1 *)(iVar3 + 0x17) = 0;
          FUN_08016798(DAT_08021124,param_2);
        }
      }
      else {
        if (param_3 < *(char *)(iVar3 + 0x15)) {
          param_3 = (int)*(char *)(iVar3 + 0x15);
        }
        *(char *)(iVar3 + 0x15) = (char)param_3;
        if (*(byte *)(iVar3 + 0x17) < 3) {
          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
        }
        *(undefined1 *)(iVar3 + 0x17) = 3;
        *(undefined1 *)(iVar3 + 0x18) = 1;
      }
    }
  }
  *(undefined1 *)(iVar3 + 0x16) = *(undefined1 *)(iVar3 + 0x15);
  return param_4;
}



/* ===== FUN_08020e16 @ 08020e16 ===== */

void FUN_08020e16(int param_1)

{
  char cVar1;
  char *pcVar2;
  undefined1 uVar3;
  
  uVar3 = 0;
  pcVar2 = (char *)(param_1 + 0x14);
  do {
    if ((char *)(param_1 + 0x23) <= pcVar2) goto LAB_08020e2c;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 5;
  } while (cVar1 < '\x01');
  uVar3 = 1;
LAB_08020e2c:
  *(undefined1 *)(DAT_08021124 + 0x20) = uVar3;
  return;
}



/* ===== FUN_08020e34 @ 08020e34 ===== */

void FUN_08020e34(int param_1)

{
  uint uVar1;
  
  uVar1 = param_1 + 0x14;
  if (uVar1 < param_1 + 0x23U) {
    for (; uVar1 < param_1 + 0x23U; uVar1 = uVar1 + 5) {
      if (2 < *(byte *)(uVar1 + 3)) {
        *(undefined1 *)(uVar1 + 3) = 2;
      }
    }
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



/* ===== FUN_08020e5c @ 08020e5c ===== */

void FUN_08020e5c(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(param_1 + 0x14);
  if (puVar1 < (undefined1 *)(param_1 + 0x23)) {
    for (; puVar1 < (undefined1 *)(param_1 + 0x23); puVar1 = puVar1 + 5) {
      if (puVar1[3] != '\0') {
        puVar1[1] = *puVar1;
        puVar1[2] = 0;
        puVar1[3] = 1;
      }
    }
  }
  *(undefined1 *)(param_1 + 0xd) = 0;
  FUN_080148de();
  FUN_08018650(8);
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



/* ===== FUN_08020e98 @ 08020e98 ===== */

int FUN_08020e98(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  
  cVar1 = -1;
  iVar2 = 0;
  cVar3 = '\x02';
  param_1 = param_1 + 10;
  do {
    if (((param_2 <= (int)(uint)*(byte *)(param_1 + 0x17)) && (-1 < *(char *)(param_1 + 0x16))) &&
       (iVar4 = (int)*(char *)(param_1 + 0x16) + (uint)*(byte *)(param_1 + 0x17) * 4, iVar2 < iVar4)
       ) {
      iVar2 = iVar4;
      cVar1 = cVar3;
    }
    cVar3 = cVar3 + -1;
    param_1 = param_1 + -5;
  } while (-1 < cVar3);
  return (int)cVar1;
}



/* ===== FUN_08020ed0 @ 08020ed0 ===== */

undefined4 FUN_08020ed0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  char cVar5;
  
  puVar1 = (uint *)FUN_08015b32();
  if (-1 < (int)((uint)*(byte *)((int)puVar1 + 3) << 0x1f)) {
    uVar2 = *puVar1;
    *(char *)puVar1 = *(char *)(param_1 + 0x14) + ' ';
    cVar5 = *(char *)(param_1 + 0x19);
    if (cVar5 != '\0') {
      cVar5 = cVar5 + '\x03';
    }
    *(char *)((int)puVar1 + 1) = cVar5 + ' ';
    cVar5 = *(char *)(param_1 + 0x1e);
    if (cVar5 != '\0') {
      cVar5 = cVar5 + '\x06';
    }
    *(char *)((int)puVar1 + 2) = cVar5 + ' ';
    if ((*puVar1 & 0xffffff) != (uVar2 & 0xffffff)) {
      if ((*puVar1 & 0xffffff) == DAT_08021128) {
        if (*(char *)(DAT_0802112c + 0xc) != '\0') {
          FUN_080168b4();
        }
      }
      else {
        FUN_08020d00();
      }
    }
  }
  puVar3 = puVar1 + 1;
  if ('\0' < *(char *)(param_1 + 0x1f)) {
    puVar3 = (uint *)((int)puVar1 + 5);
    *(char *)(puVar1 + 1) = *(char *)(param_1 + 0x1f) + '&';
  }
  puVar4 = puVar3;
  if ('\0' < *(char *)(param_1 + 0x1a)) {
    puVar4 = (uint *)((int)puVar3 + 1);
    *(char *)puVar3 = *(char *)(param_1 + 0x1a) + '#';
  }
  puVar3 = puVar4;
  if ('\0' < *(char *)(param_1 + 0x15)) {
    puVar3 = (uint *)((int)puVar4 + 1);
    *(char *)puVar4 = *(char *)(param_1 + 0x15) + ' ';
  }
  puVar4 = puVar3;
  if (puVar3 == puVar1 + 1) {
    puVar4 = (uint *)((int)puVar3 + 1);
    *(char *)puVar3 = ' ';
  }
  *(char *)puVar4 = '\0';
  return param_4;
}



/* ===== FUN_08020f68 @ 08020f68 ===== */

void FUN_08020f68(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  FUN_08020e16();
  uVar4 = DAT_08021124;
  do {
    if (*(int *)(param_1 + 0x10) < 1) {
LAB_08020fc2:
      FUN_08020ed0(param_1);
      return;
    }
    uVar3 = FUN_08020e98(param_1,3);
    if ((int)uVar3 < 0) {
      return;
    }
    FUN_080148e6();
    iVar6 = param_1 + uVar3 * 5;
    cVar1 = *(char *)(iVar6 + 0x16);
    iVar5 = (int)cVar1;
    if (iVar5 < 1) goto LAB_08020fc2;
    if ((0 < *(char *)(param_1 + 0xd)) && (iVar5 <= *(char *)(param_1 + 0xd))) {
      FUN_08020e34(param_1);
      goto LAB_08020fc2;
    }
    iVar2 = FUN_080167d8(uVar4,uVar3,iVar5);
    if (iVar2 == 0) {
      iVar5 = FUN_080167aa(uVar4,uVar3,iVar5);
      if (iVar5 != 0) {
        FUN_080148d6();
        if (*(char *)(param_1 + 0xc) != '\0') {
          FUN_080168b4(param_1);
        }
        *(char *)(param_1 + 0xd) = cVar1;
        FUN_08020e34(param_1);
        if (uVar3 == 0) {
          uVar4 = 0xc;
        }
        else if (uVar3 == 2) {
          uVar4 = 10;
        }
        else {
          if (1 < uVar3) {
            return;
          }
          uVar4 = 9;
        }
        FUN_08018650(7);
        FUN_08018646(uVar4);
      }
      goto LAB_08020fc2;
    }
    *(char *)(iVar6 + 0x16) = cVar1 + -1;
  } while( true );
}



/* ===== FUN_08021014 @ 08021014 ===== */

undefined4 FUN_08021014(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  FUN_08018650(7);
  switch(param_2) {
  case 0:
    if (*(char *)(param_1 + 0xd) < '\x01') {
      return param_4;
    }
    uVar1 = 0x20000;
    break;
  case 1:
    if (*(int *)(DAT_08021130 + 0x58) << 0x1a < 0) {
      *(undefined1 *)(param_1 + 0xd) = 0;
      FUN_080148de();
      uVar1 = FUN_08018650(8,param_4);
      return uVar1;
    }
    uVar1 = 0x28000;
    break;
  case 3:
  case 4:
    FUN_08020e5c(param_1);
  case 2:
    *(undefined1 *)(param_1 + 0xd) = 0;
    FUN_080148de();
    FUN_08018650(8);
    if (*(char *)(param_1 + 0xc) == '\0') {
      return param_4;
    }
    uVar1 = FUN_080168b4(param_1,param_4);
    return uVar1;
  default:
    return param_4;
  }
  uVar1 = FUN_08016890(param_1,uVar1,param_4);
  return uVar1;
}



/* ===== FUN_0802108c @ 0802108c ===== */

longlong FUN_0802108c(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  FUN_080148de();
  uVar4 = DAT_08021124;
  do {
    uVar2 = FUN_08020e98(param_1,2);
    if ((int)uVar2 < 0) {
LAB_0802110c:
      return (ulonglong)param_4 << 0x20;
    }
    iVar6 = param_1 + uVar2 * 5;
    cVar1 = *(char *)(iVar6 + 0x16);
    iVar5 = (int)cVar1;
    if (iVar5 < 1) goto LAB_0802110c;
    iVar3 = FUN_080167d8(uVar4,uVar2,iVar5);
    if (iVar3 == 0) {
      FUN_080148d6();
      iVar5 = FUN_080167aa(uVar4,uVar2,iVar5);
      if (iVar5 == 0) {
        *(int *)(param_1 + 8) = param_2 + 0x8000;
        return CONCAT44(param_4,param_1);
      }
      *(char *)(param_1 + 0xd) = cVar1;
      FUN_08020e34(param_1);
      if (uVar2 == 0) {
        uVar4 = 0xc;
      }
      else if (uVar2 == 2) {
        uVar4 = 10;
      }
      else {
        if (1 < uVar2) goto LAB_0802110c;
        uVar4 = 9;
      }
      FUN_08018650(7);
      FUN_08018646(uVar4);
      goto LAB_0802110c;
    }
    *(char *)(iVar6 + 0x16) = cVar1 + -1;
  } while( true );
}



/* ===== FUN_08021134 @ 08021134 ===== */

uint FUN_08021134(undefined4 param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = FUN_0802092a();
  uVar2 = *(uint *)(DAT_08021154 + 0x18) & 0xff;
  if (uVar2 < bVar1) {
    uVar2 = (uint)bVar1;
  }
  return -(uint)(uVar2 < param_2) >> 0x1f;
}



/* ===== FUN_08021158 @ 08021158 ===== */

void FUN_08021158(uint param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = DAT_080211dc;
  if (param_2 + param_1 != 0) {
    if (999 < param_1) {
      param_1 = 999;
    }
    if (999 < param_2) {
      param_2 = 999;
    }
    *DAT_080211dc = param_2;
    puVar1[1] = param_1;
    *DAT_080211e0 = 1;
    puVar1 = DAT_080211e4;
    DAT_080211e4[4] = 0xfffffffe;
    puVar1[3] = puVar1[3] | 1;
    *puVar1 = *puVar1 | 1;
  }
  return;
}



/* ===== FUN_080211b8 @ 080211b8 ===== */

uint FUN_080211b8(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  
  puVar1 = DAT_080211dc;
  *DAT_080211dc = 0;
  puVar1[1] = 0;
  *DAT_080211e0 = 0;
  puVar2 = DAT_080211e4;
  *DAT_080211e4 = *DAT_080211e4 & 0xfffffffe;
  puVar2[4] = 0xfffffffe;
  return puVar2[4];
}



/* ===== FUN_080211e8 @ 080211e8 ===== */

void FUN_080211e8(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if (iVar1 == param_2) {
      *param_1 = *(int *)(param_2 + 4);
    }
    else {
      do {
        iVar2 = iVar1;
        iVar1 = *(int *)(iVar2 + 4);
        if (iVar1 == 0) goto LAB_08021204;
      } while (iVar1 != param_2);
      *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar1 + 4);
    }
  }
LAB_08021204:
  *(undefined1 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 4) = 0;
  return;
}



/* ===== FUN_0802120c @ 0802120c ===== */

void FUN_0802120c(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  *(undefined1 *)(param_2 + 0xc) = 1;
  iVar2 = 0;
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 8) - *(int *)(param_2 + 8) < 1) {
      do {
        iVar2 = iVar1;
        iVar1 = *(int *)(iVar2 + 4);
        if (iVar1 == 0) {
          *(undefined4 *)(param_2 + 4) = 0;
          *(int *)(iVar2 + 4) = param_2;
          return;
        }
      } while (*(int *)(iVar1 + 8) - *(int *)(param_2 + 8) < 1);
      *(int *)(param_2 + 4) = iVar1;
      *(int *)(iVar2 + 4) = param_2;
      return;
    }
    iVar2 = *param_1;
  }
  *(int *)(param_2 + 4) = iVar2;
  *param_1 = param_2;
  return;
}



/* ===== FUN_0802124c @ 0802124c ===== */

void FUN_0802124c(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  if (0 < *(char *)(param_1 + 0x15)) {
    piVar1 = (int *)(DAT_08021288 + *(char *)(param_1 + 0x15) * 4 + 0x24);
    piVar2 = (int *)(DAT_08021288 + 0x28);
    if (piVar2 <= piVar1) {
      for (; piVar2 <= piVar1; piVar1 = piVar1 + -1) {
        if ((int *)*piVar1 != (int *)0x0) {
          (**(code **)(*(int *)*piVar1 + 4))();
        }
        *piVar1 = 0;
      }
    }
    *(undefined1 *)(param_1 + 0x15) = 0;
  }
  return;
}



/* ===== FUN_0802128c @ 0802128c ===== */

void FUN_0802128c(int param_1)

{
  FUN_080159dc(*(undefined1 *)(param_1 + 4));
  *(undefined1 *)(param_1 + 0x14) = 1;
  return;
}



/* ===== FUN_0802129c @ 0802129c ===== */

int FUN_0802129c(code *param_1,int param_2,byte *param_3,int *param_4,undefined1 param_5)

{
  byte bVar1;
  short sVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  code *pcVar6;
  int iVar7;
  undefined2 *puVar8;
  undefined1 *puVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined *puVar14;
  uint extraout_r1;
  uint uVar15;
  char *pcVar16;
  char *pcVar17;
  undefined4 *puVar18;
  ulonglong *puVar19;
  uint extraout_r2;
  uint *puVar20;
  char *pcVar21;
  char cVar22;
  short sVar23;
  int iVar24;
  uint uVar25;
  byte *pbVar26;
  byte *pbVar27;
  uint uVar28;
  undefined8 uVar29;
  ulonglong uVar30;
  undefined8 uVar31;
  undefined4 local_f0;
  undefined4 uStack_ec;
  int local_e8;
  uint local_e4;
  undefined8 local_e0;
  int local_d8;
  char *local_d4;
  char *local_d0;
  int local_cc;
  uint local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  uint local_b8;
  int local_b4;
  uint local_b0;
  int local_ac;
  ushort local_a8;
  byte local_a6;
  undefined1 local_a5;
  byte *local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  char acStack_94 [31];
  char acStack_75 [60];
  char cStack_39;
  uint local_38;
  uint uStack_34;
  uint local_30;
  uint uStack_2c;
  code *local_28;
  
  local_f0 = 0;
  uStack_ec = 0;
  local_b4 = 0;
  local_a0 = &local_a6;
  local_a5 = param_5;
  local_d8 = param_2;
  local_28 = param_1;
  do {
    for (; *param_3 != 0x25; param_3 = param_3 + iVar7) {
      iVar7 = FUN_0802c96a(param_3,0xffffffff,&local_f0);
      pcVar6 = local_28;
      if (iVar7 == 0) {
        return local_b4;
      }
      if (iVar7 < 0) {
        iVar7 = 1;
      }
      else {
        iVar11 = iVar7;
        pbVar26 = param_3;
        do {
          local_d8 = (*pcVar6)(local_d8,*pbVar26);
          if (local_d8 == 0) {
            return -1;
          }
          local_b4 = local_b4 + 1;
          iVar11 = iVar11 + -1;
          pbVar26 = pbVar26 + 1;
        } while (iVar11 != 0);
      }
      local_28 = pcVar6;
    }
    local_a8 = 0;
    local_cc = 0;
    local_c8 = 0;
    local_c4 = 0;
    local_c0 = 0;
    local_bc = 0;
    local_b8 = 0;
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            while( true ) {
              pbVar26 = param_3 + 1;
              bVar1 = *pbVar26;
              if (bVar1 != 0x20) break;
              local_a8 = local_a8 | 1;
              param_3 = pbVar26;
            }
            if (bVar1 != 0x23) break;
            local_a8 = local_a8 | 8;
            param_3 = pbVar26;
          }
          if (bVar1 != 0x2b) break;
          local_a8 = local_a8 | 2;
          param_3 = pbVar26;
        }
        if (bVar1 != 0x2d) break;
        local_a8 = local_a8 | 4;
        param_3 = pbVar26;
      }
      if (bVar1 != 0x30) break;
      local_a8 = local_a8 | 0x10;
      param_3 = pbVar26;
    }
    if (bVar1 == 0x2a) {
      local_ac = *(int *)*param_4;
      *param_4 = (int)((int *)*param_4 + 1);
      if (local_ac < 0) {
        local_ac = -local_ac;
        local_a8 = local_a8 | 4;
      }
      pbVar26 = param_3 + 2;
    }
    else {
      local_ac = 0;
      for (; *pbVar26 - 0x30 < 10; pbVar26 = pbVar26 + 1) {
        if (local_ac < DAT_08021f60) {
          local_ac = (uint)*pbVar26 + local_ac * 10 + -0x30;
        }
      }
    }
    if (*pbVar26 == 0x2e) {
      bVar1 = pbVar26[1];
      if (bVar1 == 0x2a) {
        local_b0 = *(uint *)*param_4;
        *param_4 = (int)((uint *)*param_4 + 1);
        pbVar26 = pbVar26 + 2;
      }
      else {
        if (bVar1 == 0x2d) {
          cVar22 = '-';
          pbVar26 = pbVar26 + 2;
        }
        else {
          cVar22 = '\0';
          pbVar26 = pbVar26 + 1;
        }
        local_b0 = 0;
        for (; *pbVar26 - 0x30 < 10; pbVar26 = pbVar26 + 1) {
          if ((cVar22 == '\0') && ((int)local_b0 < DAT_08021f60)) {
            local_b0 = ((uint)*pbVar26 + local_b0 * 10) - 0x30;
          }
        }
      }
    }
    else {
      local_b0 = 0xffffffff;
    }
    iVar7 = FUN_0802c98c("hjltzL",*pbVar26);
    uVar12 = local_b0;
    local_a6 = 0;
    pbVar27 = pbVar26;
    if (iVar7 != 0) {
      pbVar27 = pbVar26 + 1;
      local_a6 = *pbVar26;
    }
    if (local_a6 == 0x68) {
      if (*pbVar27 == 0x68) {
        local_a6 = 0x62;
        goto LAB_0802143a;
      }
    }
    else {
      bVar1 = local_a6;
      if (local_a6 == 0x6c) {
        bVar1 = *pbVar27;
      }
      if (local_a6 == 0x6c && bVar1 == 0x6c) {
        local_a6 = 0x71;
LAB_0802143a:
        pbVar27 = pbVar27 + 1;
      }
    }
    local_d0 = acStack_75 + 1;
    param_3 = pbVar27 + 1;
    bVar1 = *pbVar27;
    uVar28 = (uint)bVar1;
    if (uVar28 == 0x25) {
      local_cc = 1;
LAB_080214b4:
      acStack_75[1] = 0x25;
      goto LAB_0802150e;
    }
    if ((uVar28 == 0x41) || (uVar28 - 0x45 < 3)) {
LAB_08021718:
      puVar19 = (ulonglong *)(*param_4 + 7U & 0xfffffff8);
      *param_4 = (int)puVar19;
      local_e0._0_4_ = (uint)*puVar19;
      local_e0._4_4_ = *(uint *)((int)puVar19 + 4);
      uVar30 = *puVar19;
      *param_4 = (int)(puVar19 + 1);
      if ((int)local_e0._4_4_ < 0) {
        cVar22 = '-';
LAB_08021754:
        acStack_75[local_cc + 1] = cVar22;
        local_cc = local_cc + 1;
      }
      else {
        if ((int)((uint)local_a8 << 0x1e) < 0) {
          cVar22 = '+';
          goto LAB_08021754;
        }
        if ((int)((uint)local_a8 << 0x1f) < 0) {
          cVar22 = ' ';
          goto LAB_08021754;
        }
      }
      local_d4 = acStack_75 + local_cc + 1;
      pcVar21 = (char *)&local_9c;
      if ((uVar28 | 0x20) != 0x61) {
        if ((int)local_b0 < 0) {
          local_b0 = 6;
        }
        else {
          if (local_b0 == 0) {
            uVar12 = uVar28 | 0x20;
          }
          if (local_b0 == 0 && uVar12 == 0x67) {
            local_b0 = 1;
          }
        }
      }
      iVar7 = (int)(local_e0._4_4_ << 1) >> 0x15;
      local_38 = (uint)local_e0;
      uStack_34 = local_e0._4_4_;
      if ((iVar7 == -1) && ((local_e0._4_4_ & 0xfffff) != 0)) {
        if (uVar28 - 0x61 < 0x1a) {
          puVar14 = &DAT_08022350;
        }
        else {
          puVar14 = &DAT_08022354;
        }
      }
      else {
        if ((iVar7 != -1) || ((local_e0._4_4_ & 0xfffff) != 0)) {
          uVar12 = local_e0._4_4_ & 0x7fffffff;
          local_30 = (uint)local_e0;
          uStack_2c = local_e0._4_4_;
          if (uVar12 < 0x100000) {
            local_e8 = 0;
            if (uVar12 != 0 || (uint)local_e0 != 0) {
              uVar30 = FUN_0802ca3c((uint)local_e0,local_e0._4_4_,&local_e8);
            }
          }
          else {
            local_e8 = DAT_08022300 + (uVar12 >> 0x14);
            uVar30 = CONCAT44(DAT_08022304 & local_e0._4_4_ | DAT_08022308,(uint)local_e0);
          }
          uVar12 = (uint)(uVar30 >> 0x20);
          if ((uVar28 | 0x20) == 0x61) {
            *local_d4 = '0';
            if (uVar28 == 0x61) {
              cVar22 = 'x';
            }
            else {
              cVar22 = 'X';
            }
            local_d4[1] = cVar22;
            local_cc = local_cc + 2;
            local_d4 = local_d4 + 2;
          }
          uVar25 = local_38;
          local_e0 = uVar30;
          if ((uVar30 & 0x7fffffff00000000) == 0 && (int)uVar30 == 0) {
            uVar12 = 0;
            iVar7 = 0;
          }
          else {
            uVar15 = uVar28 | 0x20;
            if (uVar15 == 0x61) {
              if ((int)local_b0 < 0) {
                local_e4 = 0x21;
              }
              else {
                local_e4 = local_b0 + 1;
              }
              cVar22 = 0xfffffffe < local_e4;
              iVar7 = local_e4 + 1;
              FUN_0802caac(local_38,uStack_34,0,0);
              local_9c = CONCAT31(local_9c._1_3_,(char)extraout_r2);
              if (cVar22 == '\0') {
                uVar12 = uVar12 ^ 0x80000000;
              }
              uVar30 = CONCAT44(uVar12,(int)uVar30);
              local_e8 = local_e8 + -4;
              pbVar26 = (byte *)((int)&local_9c + 1);
              if (0 < iVar7) {
                uStack_2c = DAT_0802230c;
                local_38 = 0x7ff;
                local_30 = extraout_r2;
                do {
                  uVar12 = (uint)(uVar30 >> 0x20);
                  iVar11 = (int)uVar30;
                  cVar22 = '\x01';
                  FUN_0802cadc(iVar11,uVar12,0,0);
                  if (cVar22 != '\0') break;
                  uVar25 = (extraout_r1 & 0x7fffffff) >> 0x14;
                  iVar24 = uVar25 + 0x1c;
                  if ((uVar25 == 0) || (iVar24 == 0)) {
                    if (!((uVar30 & 0x7fffffff00000000) == 0 && iVar11 == 0)) {
                      uVar30 = FUN_0802cb0c(iVar11,uVar12,0x1c);
                    }
                  }
                  else if (iVar24 < (int)local_38) {
                    uVar30 = CONCAT44(extraout_r1 & 0x800fffff | iVar24 * 0x100000,iVar11);
                  }
                  else {
                    uVar30 = CONCAT44(uVar12 & 0x80000000 | uStack_2c & 0x7fffffff,local_30);
                  }
                  iVar11 = FUN_0802cc48();
                  iVar7 = iVar7 + -7;
                  if (0 < iVar7) {
                    uVar29 = FUN_0802cc84();
                    uVar30 = FUN_0802cca8((int)uVar30,(int)(uVar30 >> 0x20),(int)uVar29,
                                          (int)((ulonglong)uVar29 >> 0x20));
                  }
                  pbVar26 = pbVar26 + 7;
                  iVar24 = 7;
                  while ((0 < iVar11 && (iVar24 = iVar24 + -1, -1 < iVar24))) {
                    pbVar26 = pbVar26 + -1;
                    *pbVar26 = (byte)iVar11 & 0xf;
                    iVar11 = iVar11 >> 4;
                  }
                  while (iVar24 = iVar24 + -1, -1 < iVar24) {
                    pbVar26 = pbVar26 + -1;
                    *pbVar26 = 0;
                  }
                  pbVar26 = pbVar26 + 7;
                } while (0 < iVar7);
              }
              uVar25 = (int)pbVar26 - ((int)&local_9c + 1);
              uVar12 = local_e4;
              if ((int)uVar25 <= (int)local_e4) {
                uVar12 = uVar25;
              }
              pcVar21 = (char *)((int)&local_9c + 1);
              if (-1 < (int)uVar12) {
                if (((int)uVar12 < (int)uVar25) && (7 < (byte)acStack_94[uVar12 - 7])) {
                  cVar22 = '\x0f';
                }
                else {
                  cVar22 = '\0';
                }
                uVar25 = uVar12;
                pcVar16 = acStack_94 + (uVar12 - 8);
                while( true ) {
                  if (*pcVar16 != cVar22) break;
                  uVar12 = uVar12 - 1;
                  uVar25 = uVar25 - 1;
                  pcVar16 = pcVar16 + -1;
                }
                if (cVar22 == '\x0f') {
                  acStack_94[uVar25 - 8] = acStack_94[uVar25 - 8] + '\x01';
                }
                if ((int)(uVar25 - 1) < 0) {
                  local_e8 = local_e8 + 4;
                  pcVar21 = (char *)&local_9c;
                  uVar12 = uVar12 + 1;
                }
                iVar7 = uVar12 - 1;
                if (-1 < iVar7) {
                  pcVar16 = pcVar21 + iVar7;
                  do {
                    cVar22 = *pcVar16 + '0';
                    if (0x39 < (byte)(*pcVar16 + 0x30U)) {
                      cVar22 = (bVar1 - 0x3a) + cVar22;
                    }
                    iVar7 = iVar7 + -1;
                    *pcVar16 = cVar22;
                    pcVar16 = pcVar16 + -1;
                  } while (-1 < iVar7);
                }
              }
              if ((int)local_b0 < 0) {
                local_b0 = uVar12 - 1;
              }
            }
            else {
              local_e8 = (local_e8 * 0x7597) / DAT_08022310;
              uVar12 = uStack_34 & 0x7fffffff;
              if (7 - local_e8 == 0 || 7 < local_e8) {
                uVar29 = FUN_080222b8(0,DAT_08022314,-(7 - local_e8));
                uVar29 = FUN_0802cd8c(uVar25,uVar12,(int)uVar29,(int)((ulonglong)uVar29 >> 0x20));
              }
              else {
                uVar29 = FUN_080222b8(local_38,uVar12);
              }
              if (uVar15 == 0x66) {
                iVar7 = local_e8 + 10;
              }
              else {
                iVar7 = 6;
              }
              iVar7 = iVar7 + local_b0;
              if (0x14 < iVar7) {
                iVar7 = 0x14;
              }
              local_9c = CONCAT31(local_9c._1_3_,0x30);
              local_38 = 0;
              uStack_34 = DAT_08022318;
              pcVar21 = (char *)((int)&local_9c + 1);
              while (0 < iVar7) {
                while( true ) {
                  uVar13 = (undefined4)((ulonglong)uVar29 >> 0x20);
                  uVar25 = FUN_0802cfd4((int)uVar29,uVar13);
                  iVar11 = 4;
                  uVar12 = uVar25;
                  pcVar16 = pcVar21 + 8;
                  do {
                    pcVar21 = pcVar16;
                    cVar22 = (char)(uVar12 / 10);
                    pcVar21[-1] = (char)uVar12 + cVar22 * -10 + '0';
                    uVar12 = (uVar12 / 10) / 10;
                    iVar11 = iVar11 + -1;
                    pcVar21[-2] = cVar22 + (char)uVar12 * -10 + '0';
                    pcVar16 = pcVar21 + -2;
                  } while (iVar11 != 0);
                  iVar7 = iVar7 + -8;
                  pcVar21 = pcVar21 + 6;
                  if (iVar7 < 1) break;
                  uVar31 = FUN_0802cffc(uVar25);
                  uVar29 = FUN_0802cca8((int)uVar29,uVar13,(int)uVar31,
                                        (int)((ulonglong)uVar31 >> 0x20));
                  uVar29 = FUN_0802d018((int)uVar29,(int)((ulonglong)uVar29 >> 0x20),local_38,
                                        uStack_34);
                }
              }
              iVar7 = (int)pcVar21 - ((int)&local_9c + 1);
              for (pcVar21 = (char *)((int)&local_9c + 1); *pcVar21 == '0'; pcVar21 = pcVar21 + 1) {
                local_e8 = local_e8 + -1;
                iVar7 = iVar7 + -1;
              }
              if (uVar15 == 0x66) {
                iVar11 = local_e8 + 1;
              }
              else if (uVar15 == 0x65) {
                iVar11 = 1;
              }
              else {
                iVar11 = 0;
              }
              uVar12 = iVar11 + local_b0;
              if (iVar7 < (int)uVar12) {
                uVar12 = iVar7 - 1;
              }
              if (-1 < (int)uVar12) {
                if (((int)uVar12 < iVar7) && (0x34 < (byte)pcVar21[uVar12])) {
                  cVar22 = '9';
                }
                else {
                  cVar22 = '0';
                }
                uVar25 = uVar12;
                pcVar16 = pcVar21 + -1 + uVar12;
                while( true ) {
                  uVar25 = uVar25 - 1;
                  if (*pcVar16 != cVar22) break;
                  uVar12 = uVar12 - 1;
                  pcVar16 = pcVar16 + -1;
                }
                if (cVar22 == '9') {
                  pcVar21[uVar25] = pcVar21[uVar25] + '\x01';
                }
                if ((int)uVar25 < 0) {
                  local_e8 = local_e8 + 1;
                  uVar12 = uVar12 + 1;
                  pcVar21 = pcVar21 + -1;
                }
              }
            }
            iVar7 = local_e8;
          }
          iVar11 = FUN_0802c97e();
          cVar22 = **(char **)(iVar11 + 0x24);
          if ((short)uVar12 < 1) {
            uVar12 = 1;
            pcVar21 = "0";
          }
          sVar2 = (short)uVar12;
          uVar25 = local_b0;
          if ((uVar28 | 0x20) == 0x66) {
LAB_08021ba4:
            sVar23 = (short)(iVar7 + 1);
            iVar11 = (int)sVar23;
            if (iVar11 < 1) {
              local_d4[local_c8] = '0';
              if ((0 < (int)uVar25) ||
                 (uVar28 = local_c8 + 1, (int)((uint)(byte)local_a8 << 0x1c) < 0)) {
                local_d4[local_c8 + 1] = cVar22;
                uVar28 = local_c8 + 2;
              }
              local_c8 = uVar28;
              if ((int)(uVar25 + iVar11) < 0 != SCARRY4(uVar25,iVar11)) {
                sVar23 = -(short)uVar25;
              }
              local_bc = -(int)sVar23;
              uVar25 = uVar25 + (int)sVar23;
              if ((int)uVar25 < (int)sVar2) {
                uVar12 = uVar25;
              }
              iVar7 = (int)(short)uVar12;
              local_c4 = iVar7;
              FUN_0802498c(local_d4 + local_c8,pcVar21,iVar7);
              local_b8 = uVar25 - iVar7;
            }
            else if (sVar2 < sVar23) {
              FUN_0802498c(local_d4 + local_c8,pcVar21,(int)sVar2);
              local_c8 = (int)sVar2 + local_c8;
              local_bc = iVar11 - sVar2;
              if ((0 < (int)uVar25) || ((int)((uint)(byte)local_a8 << 0x1c) < 0)) {
                local_d4[local_c8] = cVar22;
                local_c4 = local_c4 + 1;
              }
              local_b8 = uVar25;
            }
            else {
              FUN_0802498c(local_d4 + local_c8,pcVar21);
              uVar12 = uVar12 - (iVar7 + 1);
              iVar7 = local_c8 + iVar11;
              if ((int)uVar25 < 1) {
                local_c8 = iVar7;
                if ((int)((uint)(byte)local_a8 << 0x1c) < 0) goto LAB_08021d72;
              }
              else {
LAB_08021d72:
                local_c8 = iVar7 + 1;
                local_d4[iVar7] = cVar22;
              }
              if ((int)uVar25 < (int)(short)uVar12) {
                uVar12 = uVar25;
              }
              sVar2 = (short)uVar12;
              FUN_0802498c(local_d4 + local_c8,pcVar21 + iVar11,(int)sVar2);
              local_c8 = (int)sVar2 + local_c8;
              local_bc = uVar25 - (int)sVar2;
            }
          }
          else {
            sVar23 = (short)iVar7;
            if ((uVar28 | 0x20) == 0x67) {
              if ((-5 < sVar23) && ((int)sVar23 < (int)local_b0)) {
                if ((-1 < (int)((uint)(byte)local_a8 << 0x1c)) && ((int)sVar2 < (int)local_b0)) {
                  uVar25 = (int)sVar2;
                }
                uVar25 = uVar25 - (int)(short)(sVar23 + 1);
                if ((int)uVar25 < 0) {
                  uVar25 = 0;
                }
                goto LAB_08021ba4;
              }
              if (((int)sVar2 < (int)local_b0) && (-1 < (int)((uint)(byte)local_a8 << 0x1c))) {
                uVar25 = (int)sVar2;
              }
              uVar25 = uVar25 - 1;
              if ((int)uVar25 < 0) {
                uVar25 = 0;
              }
              if (uVar28 == 0x67) {
                uVar28 = 0x65;
              }
              else {
                uVar28 = 0x45;
              }
            }
            else if (uVar28 == 0x61) {
              uVar28 = 0x70;
            }
            else if (uVar28 == 0x41) {
              uVar28 = 0x50;
            }
            uVar15 = local_c8 + 1;
            local_d4[local_c8] = *pcVar21;
            if ((0 < (int)uVar25) || ((int)((uint)(byte)local_a8 << 0x1c) < 0)) {
              local_c8 = local_c8 + 2;
              local_d4[uVar15] = cVar22;
              uVar15 = local_c8;
              if (0 < (int)uVar25) {
                uVar15 = uVar12 - 1;
                if ((int)uVar25 < (int)(short)(uVar12 - 1)) {
                  uVar15 = uVar25;
                }
                sVar2 = (short)uVar15;
                FUN_0802498c(local_d4 + local_c8,pcVar21 + 1,(int)sVar2);
                local_bc = uVar25 - (int)sVar2;
                uVar15 = (int)sVar2 + local_c8;
              }
            }
            local_c8 = uVar15;
            pcVar21 = local_d4 + local_c8;
            *pcVar21 = (char)uVar28;
            if (sVar23 < 0) {
              pcVar21[1] = '-';
              iVar7 = -(int)sVar23;
            }
            else {
              pcVar21[1] = '+';
            }
            pcVar16 = pcVar21 + 2;
            iVar11 = 0;
            puVar20 = &local_38;
            while (0 < (short)iVar7) {
              iVar24 = (int)(short)iVar7 / 10;
              *(char *)puVar20 = (char)iVar7 + (char)iVar24 * -10;
              iVar11 = iVar11 + 1;
              puVar20 = (uint *)((int)puVar20 + 1);
              iVar7 = iVar24;
            }
            pcVar17 = pcVar16;
            if ((iVar11 < 2) && ((uVar28 | 0x20) == 0x65)) {
              pcVar17 = pcVar21 + 3;
              *pcVar16 = '0';
            }
            pcVar21 = pcVar17;
            if (iVar11 == 0) {
              pcVar21 = pcVar17 + 1;
              *pcVar17 = '0';
            }
            else {
              for (; 0 < iVar11; iVar11 = iVar11 + -1) {
                *pcVar21 = acStack_75[iVar11 + 0x3c] + '0';
                pcVar21 = pcVar21 + 1;
              }
            }
            local_c4 = (int)pcVar21 - (int)(local_d4 + local_c8);
          }
          if ((((byte)local_a8 & 0x14) == 0x10) &&
             (iVar7 = local_b8 + local_c4 + local_bc + local_c8 + local_cc, iVar7 < local_ac)) {
            iVar7 = local_ac - iVar7;
            uVar30 = local_e0;
LAB_080215fe:
            local_e0 = uVar30;
            local_c0 = iVar7;
          }
          goto LAB_0802150e;
        }
        if (uVar28 - 0x61 < 0x1a) {
          puVar14 = &DAT_08022358;
        }
        else {
          puVar14 = &DAT_0802235c;
        }
      }
      local_c8 = 3;
      FUN_0802498c(local_d4,puVar14,3);
    }
    else {
      if (uVar28 == 0x53) {
        local_a6 = 0x6c;
LAB_080214be:
        puVar18 = *(undefined4 **)*param_4;
        *param_4 = (int)((undefined4 *)*param_4 + 1);
        if (puVar18 == (undefined4 *)0x0) {
          if (local_a0[1] != 0) {
            pcVar21 = "printf_s: bad %ls argument";
            goto LAB_08021506;
          }
          puVar18 = (undefined4 *)&DAT_08021fa8;
        }
LAB_08021556:
        iVar7 = FUN_080220ee(local_28,&local_e0,puVar18);
        if (iVar7 < 0) {
          return -1;
        }
        goto LAB_0802150e;
      }
      if (uVar28 == 0x58) goto LAB_08021dcc;
      if (uVar28 == 0x61) goto LAB_08021718;
      if (uVar28 == 99) {
        if (local_a6 != 0x6c) {
          local_cc = 1;
          uVar13 = *(undefined4 *)*param_4;
          *param_4 = (int)((undefined4 *)*param_4 + 1);
          acStack_75[1] = (char)uVar13;
          goto LAB_0802150e;
        }
        local_9c = *(undefined4 *)*param_4;
        *param_4 = (int)((undefined4 *)*param_4 + 1);
        local_b0 = 0xffffffff;
        local_98 = 0;
        puVar18 = &local_9c;
        goto LAB_08021556;
      }
      if (uVar28 != 100) {
        if (uVar28 - 0x65 < 3) goto LAB_08021718;
        if (uVar28 == 0x69) goto LAB_08021e62;
        if (uVar28 == 0x6e) {
          if (local_a0[1] == 0) {
            if (local_a6 == 0x62) {
              puVar9 = *(undefined1 **)*param_4;
              *param_4 = (int)((undefined4 *)*param_4 + 1);
              if (puVar9 != (undefined1 *)0x0) {
                *puVar9 = (char)local_b4;
                goto LAB_0802150e;
              }
              pcVar21 = "printf: bad %n argument";
            }
            else if (local_a6 == 0x68) {
              puVar8 = *(undefined2 **)*param_4;
              *param_4 = (int)((undefined4 *)*param_4 + 1);
              if (puVar8 != (undefined2 *)0x0) {
                *puVar8 = (short)local_b4;
                goto LAB_0802150e;
              }
              pcVar21 = "printf: bad %n argument";
            }
            else if (local_a6 == 0x6a) {
              piVar10 = *(int **)*param_4;
              *param_4 = (int)((int *)*param_4 + 1);
              if (piVar10 != (int *)0x0) {
LAB_080216bc:
                *piVar10 = local_b4;
                piVar10[1] = local_b4 >> 0x1f;
                goto LAB_0802150e;
              }
              pcVar21 = "printf: bad %n argument";
            }
            else if (local_a6 == 0x6c) {
              piVar10 = *(int **)*param_4;
              *param_4 = (int)((int *)*param_4 + 1);
              if (piVar10 != (int *)0x0) goto LAB_0802164c;
              pcVar21 = "printf: bad %n argument";
            }
            else if (local_a6 == 0x71) {
              piVar10 = *(int **)*param_4;
              *param_4 = (int)((int *)*param_4 + 1);
              if (piVar10 != (int *)0x0) goto LAB_080216bc;
              pcVar21 = "printf: bad %n argument";
            }
            else if (local_a6 == 0x74) {
              piVar10 = *(int **)*param_4;
              *param_4 = (int)((int *)*param_4 + 1);
              if (piVar10 != (int *)0x0) goto LAB_0802164c;
              pcVar21 = "printf: bad %n argument";
            }
            else if (local_a6 == 0x7a) {
              piVar10 = *(int **)*param_4;
              *param_4 = (int)((int *)*param_4 + 1);
              if (piVar10 != (int *)0x0) goto LAB_0802164c;
              pcVar21 = "printf: bad %n argument";
            }
            else {
              piVar10 = *(int **)*param_4;
              *param_4 = (int)((int *)*param_4 + 1);
              if (piVar10 != (int *)0x0) {
LAB_0802164c:
                *piVar10 = local_b4;
                goto LAB_0802150e;
              }
              pcVar21 = "printf: bad %n argument";
            }
          }
          else {
            pcVar21 = "printf_s: %n disallowed";
          }
LAB_08021506:
          iVar7 = FUN_0802c9a4(pcVar21);
          if (iVar7 != -1) {
            return -1;
          }
          goto LAB_0802150e;
        }
        if (uVar28 == 0x6f) {
LAB_08021dcc:
          if (local_a6 == 0x62) {
            uVar12 = *(uint *)*param_4;
            *param_4 = (int)((uint *)*param_4 + 1);
            local_e0._0_4_ = uVar12 & 0xff;
LAB_08021e2c:
            local_e0._4_4_ = 0;
          }
          else {
            if (local_a6 == 0x68) {
              uVar12 = *(uint *)*param_4;
              *param_4 = (int)((uint *)*param_4 + 1);
              local_e0._0_4_ = uVar12 & 0xffff;
              goto LAB_08021e2c;
            }
            if ((local_a6 != 0x6a) && ((local_a6 == 0x6c || (local_a6 != 0x71)))) {
              local_e0._0_4_ = *(uint *)*param_4;
              *param_4 = (int)((uint *)*param_4 + 1);
              goto LAB_08021e2c;
            }
            puVar20 = (uint *)(*param_4 + 7U & 0xfffffff8);
            *param_4 = (int)puVar20;
            local_e0._0_4_ = *puVar20;
            local_e0._4_4_ = puVar20[1];
            *param_4 = (int)(puVar20 + 2);
          }
          if ((((int)((uint)(byte)local_a8 << 0x1c) < 0) &&
              (local_e0._4_4_ != 0 || (uint)local_e0 != 0)) && ((uVar28 | 0x20) == 0x78)) {
            acStack_75[local_cc + 1] = '0';
            acStack_75[local_cc + 2] = bVar1;
            local_cc = local_cc + 2;
          }
          goto LAB_08021ef0;
        }
        if (uVar28 != 0x70) {
          if (uVar28 == 0x73) {
            if (local_a6 == 0x6c) goto LAB_080214be;
            pcVar21 = *(char **)*param_4;
            *param_4 = (int)((undefined4 *)*param_4 + 1);
            local_d4 = pcVar21;
            if (pcVar21 == (char *)0x0) {
              if (local_a0[1] != 0) {
                pcVar21 = "printf_s: bad %s argument";
                goto LAB_08021506;
              }
              local_d4 = "";
            }
            else {
              if ((int)local_b0 < 0) {
                uVar12 = FUN_0802beb0(pcVar21);
              }
              else {
                iVar7 = FUN_0802c9e4(pcVar21,0,local_b0);
                if (iVar7 != 0) {
                  uVar12 = iVar7 - (int)pcVar21;
                }
              }
              local_c8 = uVar12;
            }
          }
          else {
            if ((uVar28 == 0x75) || (uVar28 == 0x78)) goto LAB_08021dcc;
            acStack_75[1] = 0x25;
            local_cc = 1;
            if (uVar28 != 0) {
              local_cc = 2;
              acStack_75[2] = bVar1;
              goto LAB_080214b4;
            }
          }
          goto LAB_0802150e;
        }
        uVar12 = *(uint *)*param_4;
        *param_4 = (int)((uint *)*param_4 + 1);
        uVar30 = (ulonglong)uVar12;
        uVar5 = (ulonglong)uVar12;
        uVar4 = (ulonglong)uVar12;
        uVar3 = (ulonglong)uVar12;
        local_e0 = (ulonglong)uVar12;
        iVar7 = 0x3c;
        if ((uVar12 != 0) || (local_b0 != 0)) {
          do {
            uVar28 = (uVar12 & 0xf) + 0x30;
            iVar7 = iVar7 + -1;
            cVar22 = (char)uVar28;
            if (0x39 < uVar28) {
              cVar22 = (char)(uVar12 & 0xf) + 'W';
            }
            uVar12 = uVar12 >> 4;
            local_d0[iVar7] = cVar22;
          } while ((uVar12 != 0) && (acStack_75 + 1 < local_d0 + iVar7));
        }
        local_d4 = local_d0 + iVar7;
        local_c8 = 0x3c - iVar7;
        if ((int)local_c8 < (int)local_b0) {
          local_a8 = local_a8 & 0xffef;
          local_c0 = local_b0 - local_c8;
          goto LAB_0802150e;
        }
        local_e0 = uVar3;
        if (-1 < (int)local_b0) goto LAB_0802150e;
        local_e0 = uVar4;
        if (((byte)local_a8 & 0x14) != 0x10) goto LAB_0802150e;
        iVar7 = ((local_ac - local_cc) - local_c0) - local_c8;
        local_e0 = uVar5;
        if (iVar7 < 1) goto LAB_0802150e;
        goto LAB_080215fe;
      }
LAB_08021e62:
      if (local_a6 == 0x62) {
        uVar13 = *(undefined4 *)*param_4;
        *param_4 = (int)((undefined4 *)*param_4 + 1);
        local_e0._0_4_ = (uint)(char)uVar13;
LAB_08021ec2:
        local_e0._4_4_ = (int)(uint)local_e0 >> 0x1f;
      }
      else {
        if (local_a6 == 0x68) {
          uVar13 = *(undefined4 *)*param_4;
          *param_4 = (int)((undefined4 *)*param_4 + 1);
          local_e0._0_4_ = (uint)(short)uVar13;
          goto LAB_08021ec2;
        }
        if ((local_a6 != 0x6a) && ((local_a6 == 0x6c || (local_a6 != 0x71)))) {
          local_e0._0_4_ = *(uint *)*param_4;
          *param_4 = (int)((uint *)*param_4 + 1);
          goto LAB_08021ec2;
        }
        puVar20 = (uint *)(*param_4 + 7U & 0xfffffff8);
        *param_4 = (int)puVar20;
        local_e0._0_4_ = *puVar20;
        local_e0._4_4_ = puVar20[1];
        *param_4 = (int)(puVar20 + 2);
      }
      if ((int)local_e0._4_4_ < 0) {
        cVar22 = '-';
LAB_08021ee8:
        acStack_75[local_cc + 1] = cVar22;
        local_cc = local_cc + 1;
      }
      else {
        if ((int)((uint)local_a8 << 0x1e) < 0) {
          cVar22 = '+';
          goto LAB_08021ee8;
        }
        if ((int)((uint)local_a8 << 0x1f) < 0) {
          cVar22 = ' ';
          goto LAB_08021ee8;
        }
      }
LAB_08021ef0:
      local_d4 = acStack_75 + local_cc + 1;
      FUN_080221ae(&local_e0,uVar28);
      local_e0 = CONCAT44(local_e0._4_4_,(uint)local_e0);
    }
LAB_0802150e:
    iVar7 = FUN_08021fe2(local_28,&local_e0,acStack_75 + 1);
    if (iVar7 < 0) {
      return -1;
    }
  } while( true );
}



/* ===== FUN_08021fe2 @ 08021fe2 ===== */

longlong FUN_08021fe2(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint local_20;
  undefined4 uStack_1c;
  
  iVar2 = (((((*(int *)(param_2 + 0x34) - *(int *)(param_2 + 0x14)) - *(int *)(param_2 + 0x20)) -
            *(int *)(param_2 + 0x18)) - *(int *)(param_2 + 0x24)) - *(int *)(param_2 + 0x1c)) -
          *(int *)(param_2 + 0x28);
  local_20 = param_3;
  uStack_1c = param_4;
  if ((-1 < (int)((uint)*(byte *)(param_2 + 0x38) << 0x1d)) &&
     (local_20._1_3_ = (undefined3)(param_3 >> 8), local_20 = CONCAT31(local_20._1_3_,0x20),
     0 < iVar2)) {
    iVar3 = iVar2;
    do {
      iVar1 = FUN_08022320(param_1,param_2,&local_20,1);
      if (iVar1 != 0) goto LAB_080220e6;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  iVar3 = FUN_08022320(param_1,param_2,param_3,*(undefined4 *)(param_2 + 0x14));
  if (iVar3 == 0) {
    local_20 = CONCAT31(local_20._1_3_,0x30);
    iVar3 = *(int *)(param_2 + 0x20);
    if (0 < iVar3) {
      do {
        iVar1 = FUN_08022320(param_1,param_2,&local_20,1);
        if (iVar1 != 0) goto LAB_080220e6;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    iVar3 = FUN_08022320(param_1,param_2,*(undefined4 *)(param_2 + 0xc),
                         *(undefined4 *)(param_2 + 0x18));
    if (iVar3 == 0) {
      local_20 = CONCAT31(local_20._1_3_,0x30);
      iVar3 = *(int *)(param_2 + 0x24);
      if (0 < iVar3) {
        do {
          iVar1 = FUN_08022320(param_1,param_2,&local_20,1);
          if (iVar1 != 0) goto LAB_080220e6;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      iVar3 = FUN_08022320(param_1,param_2,*(int *)(param_2 + 0xc) + *(int *)(param_2 + 0x18),
                           *(undefined4 *)(param_2 + 0x1c));
      if (iVar3 == 0) {
        local_20 = CONCAT31(local_20._1_3_,0x30);
        iVar3 = *(int *)(param_2 + 0x28);
        if (0 < iVar3) {
          do {
            iVar1 = FUN_08022320(param_1,param_2,&local_20,1);
            if (iVar1 != 0) goto LAB_080220e6;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        if (((int)((uint)*(byte *)(param_2 + 0x38) << 0x1d) < 0) &&
           (local_20 = CONCAT31(local_20._1_3_,0x20), 0 < iVar2)) {
          do {
            iVar3 = FUN_08022320(param_1,param_2,&local_20,1);
            if (iVar3 != 0) goto LAB_080220e6;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
        return (ulonglong)local_20 << 0x20;
      }
    }
  }
LAB_080220e6:
  return CONCAT44(local_20,0xffffffff);
}



/* ===== FUN_080220ee @ 080220ee ===== */

int FUN_080220ee(undefined4 param_1,int param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_b0 [4];
  undefined4 local_ac;
  undefined4 uStack_a8;
  undefined1 auStack_a4 [128];
  undefined4 uStack_24;
  
  iVar4 = *(int *)(param_2 + 0x30);
  if (iVar4 < 0) {
    iVar4 = 0x7fffffff;
  }
  uStack_24 = param_4;
  iVar1 = FUN_0802d1ba();
  local_ac = 0;
  uStack_a8 = 0;
  if ((uint)(iVar1 + *(int *)(param_2 + 0x34)) < 0x81) {
    iVar1 = 0;
    for (; 0 < iVar4; iVar4 = iVar4 - iVar2) {
      iVar2 = FUN_0802c97a(auStack_b0,*param_3,&local_ac);
      if ((iVar2 < 0) || ((*param_3 == 0 && (iVar2 = iVar2 + -1, iVar2 < 0)))) {
        iVar1 = -1;
        goto LAB_080221a8;
      }
      if (iVar4 < iVar2) break;
      if (0x80 < (uint)(iVar2 + *(int *)(param_2 + 0x14))) {
        *(undefined4 *)(param_2 + 0x34) = 0;
        iVar1 = FUN_08021fe2(param_1,param_2,auStack_a4);
        if (iVar1 < 0) break;
        *(undefined4 *)(param_2 + 0x14) = 0;
      }
      iVar3 = *(int *)(param_2 + 0x14);
      FUN_0802498c(auStack_a4 + iVar3,auStack_b0,iVar2);
      *(int *)(param_2 + 0x14) = iVar2 + iVar3;
      if (*param_3 == 0) break;
      param_3 = param_3 + 1;
    }
    if (iVar1 == 0) {
      iVar1 = FUN_08021fe2(param_1,param_2,auStack_a4);
    }
    if (iVar1 == 0) {
      *(undefined4 *)(param_2 + 0x14) = 0;
      *(undefined4 *)(param_2 + 0x34) = 0;
    }
  }
  else {
    iVar1 = -1;
  }
LAB_080221a8:
  return iVar1;
}



/* ===== FUN_080221ae @ 080221ae ===== */

undefined8 FUN_080221ae(int *param_1,uint param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int extraout_r2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  bool bVar8;
  longlong lVar9;
  undefined4 local_24;
  int local_20;
  
  iVar6 = param_1[4];
  if (param_2 == 0x6f) {
    iVar4 = 8;
  }
  else if ((param_2 | 0x20) == 0x78) {
    iVar4 = 0x10;
  }
  else {
    iVar4 = 10;
  }
  iVar5 = 0x3c;
  iVar2 = *param_1;
  iVar3 = param_1[1];
  if ((param_2 == 100 || param_2 == 0x69) && (iVar3 < 0)) {
    bVar8 = iVar2 != 0;
    iVar2 = -iVar2;
    iVar3 = -iVar3 - (uint)bVar8;
  }
  lVar9 = CONCAT44(iVar3,iVar2);
  if ((iVar3 == 0 && iVar2 == 0) && (param_1[0xc] == 0)) {
    local_24 = param_3;
    local_20 = param_4;
    if ((iVar4 == 8) && ((int)((uint)*(byte *)(param_1 + 0xe) << 0x1c) < 0)) {
      *(undefined1 *)(iVar6 + 0x3b) = 0x30;
      iVar5 = 0x3b;
    }
  }
  else {
    local_24 = CONCAT31((int3)((uint)param_3 >> 8),(char)param_2);
    do {
      iVar2 = iVar5;
      uVar7 = (undefined4)((ulonglong)lVar9 >> 0x20);
      FUN_08025a74((int)lVar9,uVar7,iVar4,0);
      cVar1 = (char)(extraout_r2 + 0x30U);
      local_20 = iVar2 + -1;
      if (0x39 < (extraout_r2 + 0x30U & 0xff)) {
        cVar1 = (char)param_2 + -0x51 + cVar1;
      }
      *(char *)(iVar6 + local_20) = cVar1;
      lVar9 = FUN_08025a74((int)lVar9,uVar7,iVar4,0);
      iVar5 = local_20;
    } while ((lVar9 != 0) && ((uint)param_1[3] < (uint)(iVar6 + local_20)));
    if ((iVar4 == 8) &&
       (((int)((uint)*(byte *)(param_1 + 0xe) << 0x1c) < 0 && (*(char *)(iVar6 + local_20) != '0')))
       ) {
      iVar5 = iVar2 + -2;
      *(undefined1 *)(iVar6 + iVar5) = 0x30;
    }
  }
  iVar4 = 0x3c - iVar5;
  param_1[6] = iVar4;
  param_1[3] = iVar6 + iVar5;
  iVar6 = param_1[0xc];
  if (iVar4 < iVar6) {
    param_1[8] = iVar6 - iVar4;
    *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) & 0xffef;
    return CONCAT44(local_20,local_24);
  }
  if ((iVar6 < 0) && ((*(byte *)(param_1 + 0xe) & 0x14) == 0x10)) {
    iVar4 = ((param_1[0xd] - param_1[5]) - param_1[8]) - iVar4;
    if (0 < iVar4) {
      param_1[8] = iVar4;
    }
  }
  return CONCAT44(local_20,local_24);
}



/* ===== FUN_080222b8 @ 080222b8 ===== */

undefined8 FUN_080222b8(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar3 = CONCAT44(param_2,param_1);
  uVar1 = 0;
  uVar2 = DAT_0802231c;
  for (; param_3 != 0; param_3 = param_3 >> 1) {
    if (param_3 << 0x1f < 0) {
      uVar3 = FUN_0802d018((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),uVar1,uVar2);
    }
    uVar4 = FUN_0802d018(uVar1,uVar2,uVar1,uVar2);
    uVar2 = (undefined4)((ulonglong)uVar4 >> 0x20);
    uVar1 = (undefined4)uVar4;
  }
  return uVar3;
}



/* ===== FUN_08022320 @ 08022320 ===== */

longlong FUN_08022320(code *param_1,int param_2,undefined1 *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_4;
  while( true ) {
    if (uVar2 == 0) {
      return (ulonglong)param_4 << 0x20;
    }
    iVar1 = (*param_1)(*(undefined4 *)(param_2 + 8),*param_3);
    *(int *)(param_2 + 8) = iVar1;
    if (iVar1 == 0) break;
    *(int *)(param_2 + 0x2c) = *(int *)(param_2 + 0x2c) + 1;
    uVar2 = uVar2 - 1;
    param_3 = param_3 + 1;
  }
  return CONCAT44(param_4,0xffffffff);
}



/* ===== FUN_080223c8 @ 080223c8 ===== */

void FUN_080223c8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0802ab2e(DAT_080226d0,0x30,param_2,param_3,1);
  return;
}



/* ===== FUN_080223dc @ 080223dc ===== */

void FUN_080223dc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0802aa70(DAT_080226d0,0x30,param_2,param_3,1);
  return;
}



/* ===== FUN_080223f0 @ 080223f0 ===== */

uint FUN_080223f0(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 local_2c;
  undefined4 uStack_28;
  
  uVar2 = DAT_080226d0;
  local_2c = param_3;
  uStack_28 = param_4;
  uVar4 = FUN_0802ab2e(DAT_080226d0,0x30,0x25,&local_2c,1);
  local_2c = local_2c & 0xffffffc7 | 0xc4;
  uVar5 = FUN_0802aa70(uVar2,0x30,0x25,&local_2c,1);
  uVar3 = FUN_0802ab2e(uVar2,0x30,0x20,&local_2c,1);
  local_2c._1_3_ = CONCAT21(local_2c._2_2_,uVar3);
  local_2c._0_1_ = 0x60;
  uVar6 = FUN_0802aa70(uVar2,0x30,0x20,&local_2c,1);
  uVar7 = FUN_0802ab2e(uVar2,0x30,0x30,&local_2c,1);
  local_2c = CONCAT31(local_2c._1_3_,(undefined1)local_2c) | 0xe0;
  uVar8 = FUN_0802aa70(uVar2,0x30,0x30,&local_2c,1);
  uVar9 = FUN_0802ab2e(uVar2,0x30,0x3f,&local_2c,1);
  local_2c = local_2c | 0x21;
  uVar10 = FUN_0802aa70(uVar2,0x30,0x3f,&local_2c,1);
  uVar11 = FUN_0802ab2e(uVar2,0x30,0x23,&local_2c,1);
  local_2c = local_2c | 0x80;
  uVar12 = FUN_0802aa70(uVar2,0x30,0x23,&local_2c,1);
  uVar1 = local_2c >> 8;
  uVar13 = FUN_0802ab2e(uVar2,0x30,0x23,&local_2c,1);
  return uVar13 | uVar11 | uVar10 | uVar9 | uVar4 | uVar5 | uVar1 & 0xff | uVar6 | uVar7 | uVar8 |
                  uVar12;
}



/* ===== FUN_08022518 @ 08022518 ===== */

byte FUN_08022518(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint local_1c;
  undefined4 uStack_18;
  
  puVar2 = DAT_080226d4;
  puVar1 = DAT_080226d0;
  *(undefined1 *)(param_1 + 5) = 0;
  *puVar2 = *puVar2 | 0x200000;
  uVar3 = *puVar2;
  uVar4 = *puVar1;
  *puVar1 = uVar4 | 1;
  local_1c = param_3;
  uStack_18 = param_4;
  uVar4 = FUN_080223c8(param_1,0xf,&local_1c,uVar4 | 1,uVar3 & 0x200000);
  uVar3 = uVar4;
  if (uVar4 == 0) {
    uVar3 = local_1c & 0xff;
  }
  if (uVar4 == 0 && uVar3 == 0x44) {
    local_1c = CONCAT31(local_1c._1_3_,0x40);
    uVar4 = FUN_080223dc(param_1,0x21,&local_1c);
    uVar3 = 0;
    if (uVar4 == 0) {
      do {
        uVar4 = FUN_0802ab2e(puVar1,0x30,0x21,&local_1c,1);
        uVar3 = uVar3 | uVar4;
        uVar4 = uVar3;
      } while ((int)(local_1c << 0x19) < 0);
    }
    if (uVar4 == 0) {
      uVar4 = FUN_080223f0(param_1);
    }
  }
  *puVar2 = *puVar2 & 0xffdfffff;
  return (byte)~(byte)(-(uint)(uVar4 == 0) >> 0x18) >> 7;
}



/* ===== FUN_080225a6 @ 080225a6 ===== */

byte FUN_080225a6(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  uint local_18;
  uint local_14;
  undefined4 uStack_10;
  
  local_18 = param_2 & 0xffffff00;
  local_14 = param_3;
  uStack_10 = param_4;
  FUN_08016fec();
  puVar1 = DAT_080226d4;
  *DAT_080226d4 = *DAT_080226d4 | 0x200000;
  local_14 = *puVar1 & 0x200000;
  iVar2 = FUN_080223dc(param_1,0x20,&local_18);
  *DAT_080226d0 = *DAT_080226d0 & 0xfffffffe;
  *puVar1 = *puVar1 & 0xffdfffff;
  FUN_08016fbc();
  puVar1 = DAT_080226d8;
  *DAT_080226d8 = *DAT_080226d8 & 0xfffffffd;
  *puVar1 = *puVar1 & 0xfffffffb;
  return (byte)~(byte)(-(uint)(iVar2 == 0) >> 0x18) >> 7;
}



/* ===== FUN_0802260a @ 0802260a ===== */

void FUN_0802260a(void)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  iVar1 = DAT_080226dc;
  if (*(char *)(DAT_080226dc + 4) == '\0') {
    iVar3 = FUN_08022518(DAT_080226dc);
    bVar2 = (byte)(-(uint)(iVar3 == 0) >> 0x1f);
  }
  else {
    bVar2 = 1;
  }
  *(byte *)(iVar1 + 4) = bVar2;
  return;
}



/* ===== FUN_08022640 @ 08022640 ===== */

void FUN_08022640(void)

{
  return;
}



/* ===== FUN_08022656 @ 08022656 ===== */

void FUN_08022656(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  int local_18;
  uint local_14;
  undefined4 uStack_10;
  
  iVar2 = DAT_080226dc;
  if (*(char *)(DAT_080226dc + 5) != '\0') {
    if (*DAT_080226e4 == '\0') {
      local_18 = param_2;
      local_14 = param_3;
      uStack_10 = param_4;
      FUN_08016fec();
      puVar1 = DAT_080226d4;
      *DAT_080226d4 = *DAT_080226d4 | 0x200000;
      local_14 = *puVar1 & 0x200000;
      FUN_080223c8(iVar2,0x3a,&local_18);
      *puVar1 = *puVar1 & 0xffdfffff;
      FUN_08016fbc();
      if ((local_18 << 0x19 < 0) || (*(char *)(iVar2 + 5) == '\x02')) {
        if (local_18 << 0x1e < 0) {
          FUN_08016126();
        }
        else if (local_18 << 0x1f < 0) {
          FUN_08016112();
        }
      }
      *(undefined1 *)(iVar2 + 5) = 0;
      return;
    }
    *(undefined1 *)(DAT_080226dc + 5) = 2;
  }
  return;
}



/* ===== FUN_080226e8 @ 080226e8 ===== */

void FUN_080226e8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_08022734;
  iVar1 = DAT_08022730;
  *DAT_0802272c = *DAT_0802272c & DAT_08022738 | 1;
  *(undefined4 *)(iVar1 + 4) = 2;
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | 2;
  *(undefined4 *)(iVar1 + 0x14) = uVar2;
  FUN_08016e74(iVar1,0,6);
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | 1;
  FUN_08016890(param_1,0x4000,param_4);
  return;
}



/* ===== FUN_0802278c @ 0802278c ===== */

undefined4 FUN_0802278c(int param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_080228c4;
  if (param_1 == DAT_080228c0) {
    *DAT_080228c4 = *DAT_080228c4 | 0x80000000;
    *puVar1 = *puVar1 & 0x7fffffff;
    return 0;
  }
  if (param_1 == DAT_080228c8) {
    DAT_080228c4[1] = DAT_080228c4[1] | 0x20;
    puVar1[1] = puVar1[1] & 0xffffffdf;
    return 0;
  }
  return 1;
}



/* ===== FUN_080227c8 @ 080227c8 ===== */

void FUN_080227c8(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_30 [4];
  
  uVar3 = 0;
  disableIRQinterrupts();
  if (param_1 == DAT_080228c0) {
    uVar3 = *DAT_080228cc >> 0x10 & 0xc | 0xc0000;
  }
  else if (param_1 == DAT_080228c8) {
    uVar3 = *DAT_080228cc >> 0x10 & 0x30 | 0x300000;
  }
  iVar7 = param_1[2];
  iVar5 = param_1[3];
  iVar4 = param_1[5];
  iVar2 = param_1[6];
  iVar6 = param_1[8];
  FUN_0802278c(param_1);
  FUN_0802d1c4(local_30);
  if (iVar2 == 0 && iVar4 == 0) goto LAB_080228a2;
  if (param_1 == DAT_080228c0) {
    uVar1 = *DAT_080228cc & 0xfff3ffff;
LAB_08022842:
    *DAT_080228cc = uVar1;
  }
  else if (param_1 == DAT_080228c8) {
    uVar1 = *DAT_080228cc & 0xffcfffff;
    goto LAB_08022842;
  }
  if (iVar4 != 0) {
    param_1[4] = param_1[4] | 1;
    param_1[5] = iVar4;
    do {
      local_30[0] = local_30[0] + -1;
      if (*param_1 << 0x1c < 0) break;
    } while (local_30[0] != 0);
    param_1[1] = param_1[1] | 8;
  }
  if (iVar2 != 0) {
    param_1[4] = param_1[4] | 1;
    param_1[6] = iVar2;
    FUN_0802d1c4(local_30);
    do {
      local_30[0] = local_30[0] + -1;
      if (*param_1 << 0x1b < 0) break;
    } while (local_30[0] != 0);
    param_1[1] = param_1[1] | 0x10;
  }
  *DAT_080228cc = *DAT_080228cc & ~(uVar3 & 0xffff0000) | uVar3 << 0x10;
LAB_080228a2:
  param_1[4] = param_1[4] & 0xfffffffe;
  param_1[2] = iVar7;
  param_1[3] = iVar5;
  param_1[8] = iVar6;
  enableIRQinterrupts();
  return;
}



/* ===== thunk_FUN_080277e4 @ 080228d0 ===== */

void thunk_FUN_080277e4(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = DAT_08028220;
  iVar2 = *DAT_080281ec;
  *(int *)*DAT_08028220 = *(int *)(iVar2 + 8) + 4;
  *(undefined4 *)puVar1[1] = *(undefined4 *)(iVar2 + 4);
  *(undefined1 *)puVar1[2] = 0;
  *(undefined1 *)puVar1[3] = 0;
  *(undefined4 *)puVar1[4] = 0;
  *(undefined4 *)puVar1[5] = 0;
  *(short *)puVar1[6] = (short)*(undefined4 *)(iVar2 + 0x10) + -4;
  *(short *)puVar1[7] = (short)*(undefined4 *)(iVar2 + 0xc) + -4;
  return;
}



/* ===== FUN_080228d4 @ 080228d4 ===== */

undefined4 * FUN_080228d4(void)

{
  char cVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  bool bVar7;
  
  piVar2 = DAT_08022960;
  if (*(int *)*DAT_0802295c != 5) {
    return DAT_0802295c;
  }
  if (((code *)DAT_08022960[6] != (code *)0x0) && (*(char *)DAT_08022960[4] == '\0')) {
    (*(code *)DAT_08022960[6])(DAT_08022960);
    piVar2[6] = 0;
  }
  cVar1 = *(char *)piVar2[3];
  bVar7 = cVar1 == '\x01';
  if (bVar7) {
    cVar1 = *(char *)piVar2[4];
  }
  if (bVar7 && cVar1 == '\0') {
    *(char *)piVar2[3] = cVar1;
    FUN_080297fc(*(undefined1 *)*piVar2);
    iVar4 = *piVar2;
    puVar5 = *(uint **)(iVar4 + 4);
    piVar2[1] = (int)(puVar5 + 1);
    puVar3 = DAT_08028204;
    uVar6 = *puVar5;
    *DAT_08028204 = uVar6 & 0x1f000000;
    piVar2[2] = *(int *)(iVar4 + 8) + 4;
    puVar5 = DAT_0802821c;
    if (-1 < (int)((uint)(byte)puVar3[1] << 0x1e)) {
      puVar5 = (uint *)&UNK_080277cc;
    }
    for (; *puVar5 != (uVar6 & 0xe0ffffff) && *puVar5 != 0; puVar5 = puVar5 + 2) {
    }
    (*(code *)puVar5[1])(piVar2);
    FUN_0802782a(piVar2);
    if ((code *)piVar2[5] != (code *)0x0) {
      (*(code *)piVar2[5])(piVar2);
      piVar2[5] = 0;
    }
    (**(code **)(*piVar2 + 0x14))(piVar2);
    return (undefined4 *)0x1;
  }
  return (undefined4 *)0x0;
}



/* ===== FUN_080228e6 @ 080228e6 ===== */

uint FUN_080228e6(void)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint unaff_r7;
  
  puVar1 = DAT_08022968;
  if (*DAT_08022964 != 0) {
    return (uint)*DAT_08022964;
  }
  *DAT_08022964 = 1;
  (*(code *)*puVar1)();
  puVar1 = DAT_08022974;
  uVar2 = (*DAT_0802296c & 0x7ff) >> 8;
  if (7 - uVar2 < 5) {
    uVar3 = (1 << (7 - uVar2 & 0xff)) - 1U & 2;
  }
  else {
    uVar3 = 2;
  }
  if (6 < uVar2 + 4) {
    uVar3 = uVar3 << (uVar2 - 3 & 0xff);
  }
  *DAT_08022970 = (char)(uVar3 << 4);
  *puVar1 = 1;
  return unaff_r7;
}



/* ===== FUN_0802297c @ 0802297c ===== */

undefined4 FUN_0802297c(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14);
  if (iVar2 != param_2) {
    *(int *)(param_1 + 0x14) = param_2;
    if ((*(char *)(param_1 + 0x18) == '\0') ||
       (*(int *)(param_1 + 0x10) < iVar2 != *(int *)(param_1 + 0x10) < param_2)) {
      uVar1 = FUN_08016890(param_1,0,param_4);
      return uVar1;
    }
  }
  return param_4;
}



/* ===== FUN_080229ac @ 080229ac ===== */

uint FUN_080229ac(void)

{
  uint *puVar1;
  ushort uVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = DAT_08022bdc;
  uVar4 = *DAT_08022bd4 & 0xffff;
  while (uVar4 != (*DAT_08022bd4 & 0xffff)) {
    uVar4 = *DAT_08022bd4 & 0xffff;
  }
  uVar2 = *DAT_08022bd8 + (short)uVar4;
  if (uVar2 < (ushort)*DAT_08022bdc) {
    uVar4 = *DAT_08022bdc;
    puVar1 = DAT_08022bdc + 1;
    *DAT_08022bdc = uVar4 + 0x10000;
    puVar3[1] = *puVar1 + (uint)(0xfffeffff < uVar4);
  }
  *(ushort *)puVar3 = uVar2;
  return *puVar3;
}



/* ===== FUN_080229e8 @ 080229e8 ===== */

uint FUN_080229e8(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 != 0) {
    if (*(uint *)(param_1 + 0x10) != 0) {
      return *(uint *)(param_1 + 0x10) & param_2;
    }
    for (uVar1 = 0x10; (param_2 & uVar1) == 0; uVar1 = uVar1 << 1) {
    }
    if ((param_2 & ~uVar1) == 0) {
      return param_2;
    }
  }
  return 0;
}



/* ===== FUN_08022a0a @ 08022a0a ===== */

undefined4 FUN_08022a0a(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_2 == 0x10) {
    uVar2 = 0;
  }
  else if (param_2 == 0x20) {
    uVar2 = 0x10;
  }
  else {
    if (param_2 != 0x40) {
      return 1;
    }
    uVar2 = 0x20;
  }
  uVar2 = param_3 | 0x2000 | uVar2;
  if (*(char *)(param_1 + 0x20) != '\0') {
    uVar2 = uVar2 | 0x100;
  }
  uVar1 = FUN_08016996(uVar2);
  return uVar1;
}



/* ===== FUN_08022a3c @ 08022a3c ===== */

int FUN_08022a3c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  *(int *)(param_1 + 8) = param_2 + 0x28f;
  uVar3 = *(uint *)(param_1 + 0x1c);
  if ((uVar3 == 0) && (uVar3 = *DAT_08022be0 & 0x70, (int)(uVar3 << 0x19) < 0)) {
    uVar3 = 0x40;
  }
  *(uint *)(param_1 + 0x14) = uVar3;
  iVar1 = FUN_080229e8(param_1);
  iVar4 = *(int *)(param_1 + 0x10);
  *(int *)(param_1 + 0x10) = iVar1;
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
    if ((iVar4 != 0) && (iVar1 = FUN_08022a0a(param_1,iVar4,2), iVar1 == 0)) {
      *(undefined1 *)(param_1 + 0x20) = 0;
      *(undefined1 *)(param_1 + 0x21) = 0;
    }
    return 0;
  }
  iVar2 = *(int *)(param_1 + 0x18);
  if (*(char *)(param_1 + 0x21) == '\0') {
    if ((iVar4 == iVar1) && (iVar2 < 0)) {
      *(undefined4 *)(param_1 + 0x18) = 0x32;
      iVar1 = FUN_08022a0a(param_1,iVar1,1);
      if (iVar1 == 0) {
        *(undefined1 *)(param_1 + 0x20) = 0;
        return param_1;
      }
      return param_1;
    }
    if ((iVar2 < 1) || (iVar2 = iVar2 + -1, iVar2 != 0)) goto LAB_08022ae4;
    iVar1 = FUN_08022a0a(param_1);
    if (iVar1 != 0) {
      return param_1;
    }
    if (*(int *)(param_1 + 0x1c) != 0) {
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *(undefined1 *)(param_1 + 0x20) = 1;
    }
    *(undefined1 *)(param_1 + 0x21) = 1;
  }
  else {
    iVar2 = iVar2 + -1;
    if (iVar2 != 0) goto LAB_08022ae4;
    iVar1 = FUN_08022a0a(param_1,iVar1,3);
    if (iVar1 != 0) {
      return param_1;
    }
  }
  iVar2 = 10;
LAB_08022ae4:
  *(int *)(param_1 + 0x18) = iVar2;
  return param_1;
}



/* ===== FUN_08022aea @ 08022aea ===== */

void FUN_08022aea(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((*DAT_08022be0 & 0x50) == 0x50) {
    iVar2 = *(int *)(param_1 + 0x24);
    iVar1 = FUN_080229ac();
    if (0 < iVar1 - iVar2) {
      *DAT_08022be4 = 0x5555;
      DAT_08022be4[2] = 0;
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  else {
    iVar1 = FUN_080229ac();
    *(int *)(param_1 + 0x24) = iVar1 + 0x50000;
  }
  return;
}



/* ===== FUN_08022b20 @ 08022b20 ===== */

void FUN_08022b20(void)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  
  iVar1 = DAT_08022be8;
  *(undefined4 *)(DAT_08022be8 + 0x18) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined2 *)(iVar1 + 0x20) = 0;
  *(undefined1 *)(iVar1 + 0x22) = 0;
  iVar3 = FUN_080229ac();
  *(int *)(iVar1 + 0x24) = iVar3 + 0x50000;
  puVar2 = DAT_08022bec;
  DAT_08022bec[5] = 0x40;
  *puVar2 = *puVar2 | 0x40;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0xffffffff;
  *(undefined1 *)(iVar1 + 0x21) = 0;
  *(undefined1 *)(iVar1 + 0x22) = 0;
  iVar3 = FUN_080229ac();
  *(int *)(iVar1 + 0x24) = iVar3 + 0x50000;
  FUN_08016890(iVar1,0);
  return;
}



/* ===== FUN_08022b5c @ 08022b5c ===== */

uint FUN_08022b5c(uint param_1)

{
  return param_1 & *(uint *)(DAT_08022be8 + 0x14);
}



/* ===== FUN_08022b64 @ 08022b64 ===== */

undefined1 FUN_08022b64(void)

{
  int iVar1;
  
  iVar1 = DAT_08022be8;
  *(undefined1 *)(DAT_08022be8 + 0x22) = 1;
  return *(undefined1 *)(iVar1 + 0x22);
}



/* ===== FUN_08022b6e @ 08022b6e ===== */

void FUN_08022b6e(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_08022be8;
  FUN_08022aea(DAT_08022be8);
  if ((*(char *)(iVar1 + 0x22) == '\0') ||
     (*(undefined1 *)(iVar1 + 0x22) = 0, *(char *)(iVar1 + 0xc) != '\0')) {
    return;
  }
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0xffffffff;
  *(undefined1 *)(iVar1 + 0x21) = 0;
  *(undefined1 *)(iVar1 + 0x22) = 0;
  iVar2 = FUN_080229ac();
  *(int *)(iVar1 + 0x24) = iVar2 + 0x50000;
  FUN_08016890(iVar1,0);
  return;
}



/* ===== FUN_08022b8c @ 08022b8c ===== */

undefined1 FUN_08022b8c(void)

{
  return *(undefined1 *)(DAT_08022be8 + 0x22);
}



/* ===== FUN_08022b94 @ 08022b94 ===== */

undefined4 FUN_08022b94(uint param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_08022be8;
  if (*(char *)(DAT_08022be8 + 0x20) != '\0') {
    return 1;
  }
  if (param_1 == 1) {
    iVar3 = 0x40;
    goto LAB_08022bbc;
  }
  if (param_1 != 0) {
    if (param_1 == 3) {
      iVar3 = 0x20;
      goto LAB_08022bbc;
    }
    if (param_1 < 3) {
      iVar3 = 0x10;
      goto LAB_08022bbc;
    }
  }
  iVar3 = 0;
LAB_08022bbc:
  piVar1 = (int *)(DAT_08022be8 + 0x10);
  *(int *)(DAT_08022be8 + 0x1c) = iVar3;
  if (iVar3 != *piVar1) {
    *(undefined1 *)(iVar2 + 0x20) = 1;
    *(undefined1 *)(iVar2 + 0x22) = 1;
  }
  return 0;
}



/* ===== FUN_08022bf0 @ 08022bf0 ===== */

uint FUN_08022bf0(uint param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_08022d88;
  *DAT_08022d88 = *DAT_08022d88 | param_1;
  return param_1 & *puVar1;
}



/* ===== thunk_FUN_08022c0a @ 08022c06 ===== */

undefined8 thunk_FUN_08022c0a(void)

{
  undefined4 uVar1;
  undefined4 in_r3;
  undefined4 uVar2;
  undefined1 uStack_c;
  undefined1 uStack_b;
  undefined2 uStack_a;
  
  uStack_c = (undefined1)in_r3;
  uStack_b = (undefined1)((uint)in_r3 >> 8);
  uStack_a = (undefined2)((uint)in_r3 >> 0x10);
  FUN_08022bf0(0x800000);
  uVar1 = DAT_08022d8c;
  uStack_b = 0;
  FUN_0802aa70(DAT_08022d8c,0x5e,3,&uStack_b,1);
  uStack_c = 0;
  uVar2 = 1;
  FUN_0802aa70(uVar1,0x5e,4,&uStack_c);
  *DAT_08022d88 = *DAT_08022d88 & 0xff7fffff;
  return CONCAT26(uStack_a,CONCAT15(uStack_b,CONCAT14(uStack_c,uVar2)));
}



/* ===== FUN_08022c0a @ 08022c0a ===== */

undefined8 FUN_08022c0a(void)

{
  undefined4 uVar1;
  undefined4 in_r3;
  undefined4 uVar2;
  undefined1 local_c;
  undefined1 local_b;
  undefined2 uStack_a;
  
  local_c = (undefined1)in_r3;
  local_b = (undefined1)((uint)in_r3 >> 8);
  uStack_a = (undefined2)((uint)in_r3 >> 0x10);
  FUN_08022bf0(0x800000);
  uVar1 = DAT_08022d8c;
  local_b = 0;
  FUN_0802aa70(DAT_08022d8c,0x5e,3,&local_b,1);
  local_c = 0;
  uVar2 = 1;
  FUN_0802aa70(uVar1,0x5e,4,&local_c);
  *DAT_08022d88 = *DAT_08022d88 & 0xff7fffff;
  return CONCAT26(uStack_a,CONCAT15(local_b,CONCAT14(local_c,uVar2)));
}



/* ===== FUN_08022c84 @ 08022c84 ===== */

void FUN_08022c84(undefined4 param_1)

{
  uint *puVar1;
  undefined4 uStack_10;
  
  puVar1 = DAT_08022d88;
  *DAT_08022d88 = *DAT_08022d88 | 0x800000;
  uStack_10 = param_1;
  FUN_0802aa70(DAT_08022d8c,0x5e,2,&uStack_10,1);
  *puVar1 = *puVar1 & 0xff7fffff;
  return;
}



/* ===== FUN_08022cb8 @ 08022cb8 ===== */

ulonglong FUN_08022cb8(void)

{
  uint *puVar1;
  undefined4 uVar2;
  uint in_r3;
  uint local_14;
  
  uVar2 = DAT_08022d8c;
  puVar1 = DAT_08022d88;
  *DAT_08022d88 = *DAT_08022d88 | 0x800000;
  local_14 = in_r3 & 0xffffff00;
  FUN_0802aa70(uVar2,0x5e,5,&local_14);
  FUN_0802ac24(uVar2,0x5e,&local_14,1);
  *puVar1 = *puVar1 & 0xff7fffff;
  return CONCAT44(1,local_14) & 0xffffffff000000ff;
}



/* ===== FUN_08022ce0 @ 08022ce0 ===== */

undefined8 FUN_08022ce0(undefined4 param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uStack_14;
  
  uVar2 = DAT_08022d8c;
  puVar1 = DAT_08022d88;
  *DAT_08022d88 = *DAT_08022d88 | 0x800000;
  uStack_14 = param_1;
  FUN_0802aa70(uVar2,0x5e,2,&uStack_14,1);
  uVar3 = 1;
  FUN_0802aa70(uVar2,0x5e,1,&uStack_14);
  *puVar1 = *puVar1 & 0xff7fffff;
  return CONCAT44(uStack_14,uVar3);
}



/* ===== FUN_08022d22 @ 08022d22 ===== */

ulonglong FUN_08022d22(void)

{
  uint *puVar1;
  undefined4 uVar2;
  uint in_r3;
  uint uStack_14;
  
  uVar2 = DAT_08022d8c;
  puVar1 = DAT_08022d88;
  *DAT_08022d88 = *DAT_08022d88 | 0x800000;
  uStack_14 = in_r3 & 0xffffff00;
  FUN_0802aa70(uVar2,0x5e,6,&uStack_14);
  FUN_0802ac24(uVar2,0x5e,&uStack_14,1);
  *puVar1 = *puVar1 & 0xff7fffff;
  return CONCAT44(1,uStack_14) & 0xffffffff000000ff;
}



/* ===== FUN_08022d3e @ 08022d3e ===== */

ulonglong FUN_08022d3e(void)

{
  uint *puVar1;
  undefined4 uVar2;
  undefined4 in_r3;
  undefined4 local_14;
  
  uVar2 = DAT_08022d8c;
  puVar1 = DAT_08022d88;
  *DAT_08022d88 = *DAT_08022d88 | 0x800000;
  local_14 = CONCAT31((int3)((uint)in_r3 >> 8),1);
  FUN_0802aa70(uVar2,0x5e,6,&local_14);
  FUN_0802ac24(uVar2,0x5e,&local_14,1);
  *puVar1 = *puVar1 & 0xff7fffff;
  return CONCAT44(1,local_14) & 0xffffffff000000ff;
}



/* ===== FUN_08022d90 @ 08022d90 ===== */

uint FUN_08022d90(int param_1,undefined4 param_2)

{
  char cVar1;
  
  switch(param_2) {
  case 0:
    cVar1 = '\0';
    break;
  case 1:
    if (*(char *)(param_1 + 0x15) == '\0') {
      cVar1 = '\x02';
    }
    else if (*(char *)(param_1 + 0x15) == '\x01') {
      cVar1 = '\x04';
    }
    else {
      cVar1 = '\x03';
    }
    break;
  case 2:
    cVar1 = '\x05';
    break;
  case 3:
    cVar1 = '\x06';
    break;
  default:
    cVar1 = '\t';
  }
  if ((*(char *)(param_1 + 0x14) == '\0') && (*(char *)(param_1 + 0x14) = cVar1, cVar1 != '\0')) {
    FUN_08016b14();
  }
  return ~-(uint)(*(char *)(param_1 + 0x14) == '\0') >> 0x1f;
}



/* ===== FUN_08022dde @ 08022dde ===== */

longlong FUN_08022dde(int param_1,int param_2,uint param_3)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int unaff_r8;
  uint local_20;
  
  puVar1 = DAT_08022f94;
  piVar3 = *(int **)(param_1 + 0x10);
  local_20 = param_3;
  if (piVar3 == (int *)0x0) goto LAB_08022e78;
  if ('\0' < (char)piVar3[1]) goto LAB_08022e7e;
  *DAT_08022f94 = *DAT_08022f94 | 0x800000;
  local_20 = *puVar1 & 0x800000;
  if (*(char *)(param_1 + 0x15) == '\0') {
    unaff_r8 = (**(code **)(*piVar3 + 4))(piVar3);
    iVar2 = unaff_r8;
    if (unaff_r8 < 1) {
      iVar2 = (int)(char)piVar3[1];
    }
    if (iVar2 < 1) {
      *(undefined1 *)(param_1 + 0x15) = 1;
      (**(code **)(*piVar3 + 0x10))(piVar3,param_1 + 0x28);
      goto LAB_08022e3a;
    }
  }
  else {
    if (*(char *)(param_1 + 0x15) == '\x01') {
LAB_08022e3a:
      (**(code **)(*piVar3 + 0xc))(piVar3,param_1 + 0x1c);
      if (*(int *)(param_1 + 0x18) != 0) {
        (**(code **)(*piVar3 + 0x10))(piVar3,param_1 + 0x28);
        (**(code **)(param_1 + 0x18))();
        unaff_r8 = 0x8000;
        goto LAB_08022e64;
      }
    }
    unaff_r8 = 0x28000;
  }
LAB_08022e64:
  *puVar1 = *puVar1 & 0xff7fffff;
  iVar2 = FUN_08022d90(param_1,(int)(char)piVar3[1]);
  if (iVar2 == 0) {
LAB_08022e7e:
    *(int *)(param_1 + 8) = param_2 + unaff_r8;
    return CONCAT44(local_20,param_1);
  }
LAB_08022e78:
  return (ulonglong)local_20 << 0x20;
}



/* ===== FUN_08022e88 @ 08022e88 ===== */

undefined8 FUN_08022e88(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_0802d90c();
  iVar2 = (**(code **)*puVar1)();
  if (iVar2 != 0) {
    *(undefined4 **)(param_1 + 0x10) = puVar1;
  }
  return CONCAT44(param_4,(uint)(iVar2 != 0));
}



/* ===== FUN_08022ea0 @ 08022ea0 ===== */

uint FUN_08022ea0(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = DAT_08022f98;
  puVar1 = DAT_08022f94;
  *(undefined4 *)(DAT_08022f98 + 0x10) = 0;
  *(undefined2 *)(iVar2 + 0x14) = 0;
  *puVar1 = *puVar1 | 0x800000;
  uVar3 = *puVar1 & 0x800000;
  iVar4 = FUN_08022e88(iVar2);
  *puVar1 = *puVar1 & 0xff7fffff;
  if (iVar4 != 0) {
    uVar3 = FUN_08016890(iVar2,0x199a,uVar3);
    return uVar3;
  }
  if (*(char *)(iVar2 + 0x14) == '\0') {
    *(undefined1 *)(iVar2 + 0x14) = 1;
    uVar3 = FUN_08016b14(1,uVar3);
    return uVar3;
  }
  return uVar3;
}



/* ===== FUN_08022f24 @ 08022f24 ===== */

ulonglong FUN_08022f24(undefined4 param_1,undefined4 param_2,uint param_3)

{
  char cVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  bool bVar7;
  uint local_18;
  
  iVar3 = DAT_08022f98;
  puVar2 = DAT_08022f94;
  piVar6 = *(int **)(DAT_08022f98 + 0x10);
  local_18 = param_3;
  if (piVar6 != (int *)0x0) {
    cVar1 = *(char *)(DAT_08022f98 + 0x15);
    bVar7 = cVar1 == '\x01';
    if (bVar7) {
      cVar1 = *(char *)(DAT_08022f98 + 0x14);
    }
    if (bVar7 && cVar1 == '\0') {
      *DAT_08022f94 = *DAT_08022f94 | 0x800000;
      uVar5 = *puVar2;
      local_18 = uVar5 & 0x800000;
      (**(code **)(*piVar6 + 0xc))(piVar6,iVar3 + 0x1c);
      *puVar2 = *puVar2 & 0xff7fffff;
      iVar4 = FUN_08022d90(iVar3,(int)(char)piVar6[1]);
      if (iVar4 == 0) {
        return CONCAT44(uVar5,iVar3 + 0x1c) & 0x800000ffffffff;
      }
    }
  }
  return (ulonglong)local_18 << 0x20;
}



/* ===== FUN_08022f76 @ 08022f76 ===== */

void FUN_08022f76(void)

{
  FUN_0802d91c(DAT_08022f98);
  return;
}



/* ===== FUN_08022f7c @ 08022f7c ===== */

bool FUN_08022f7c(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0802d91c(DAT_08022f98);
  if (iVar1 != 0) {
    *param_1 = (int)*(short *)(iVar1 + 6);
  }
  return iVar1 != 0;
}



/* ===== FUN_08022fa0 @ 08022fa0 ===== */

undefined8 FUN_08022fa0(void)

{
  uint *puVar1;
  ushort uVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = DAT_08023150;
  uVar4 = *DAT_08023148 & 0xffff;
  while (uVar4 != (*DAT_08023148 & 0xffff)) {
    uVar4 = *DAT_08023148 & 0xffff;
  }
  uVar2 = *DAT_0802314c + (short)uVar4;
  if (uVar2 < (ushort)*DAT_08023150) {
    uVar4 = *DAT_08023150;
    puVar1 = DAT_08023150 + 1;
    *DAT_08023150 = uVar4 + 0x10000;
    puVar3[1] = *puVar1 + (uint)(0xfffeffff < uVar4);
  }
  *(ushort *)puVar3 = uVar2;
  return *(undefined8 *)puVar3;
}



/* ===== FUN_08022fe0 @ 08022fe0 ===== */

int FUN_08022fe0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined8 uVar4;
  
  iVar1 = FUN_0802d974();
  if (iVar1 == 0) {
    if (*(float *)(param_1 + 0x1c) < -20.0) {
      uVar3 = 0x80;
    }
    else if (*(float *)(param_1 + 0x1c) < DAT_08023144) {
      uVar3 = 0x40;
    }
    else {
      uVar3 = 0xc0;
    }
  }
  else {
    uVar3 = 0;
  }
  iVar1 = FUN_08018634(0xc0,uVar3);
  if (iVar1 != 0) {
    FUN_08018620(0xc0,uVar3);
    if (uVar3 >> 6 == 2) {
      uVar4 = FUN_08022fa0();
      uVar2 = 0xf;
    }
    else {
      if (uVar3 >> 6 != 3) goto LAB_0802304c;
      uVar4 = FUN_08022fa0();
      uVar2 = 0x10;
    }
    FUN_08018b34(*(undefined4 *)(param_1 + 0x1c),(int)uVar4,(int)((ulonglong)uVar4 >> 0x20),uVar2);
  }
LAB_0802304c:
  *(int *)(param_1 + 8) = param_2 + 0x8000;
  return param_1;
}



/* ===== FUN_08023056 @ 08023056 ===== */

undefined4 FUN_08023056(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 in_r3;
  
  iVar1 = DAT_08023154;
  iVar2 = FUN_0801d09c(0x10,DAT_08023154 + 0x30,1);
  if (iVar2 == 0) {
    FUN_08016a90(0x19);
    *(undefined4 *)(iVar1 + 0x30) = 0;
  }
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0x2c) = 0;
  puVar3 = (undefined4 *)FUN_0802dd38();
  iVar2 = (**(code **)*puVar3)();
  if (iVar2 != 0) {
    puVar3 = (undefined4 *)FUN_0802df00();
    iVar2 = (**(code **)*puVar3)();
    if (iVar2 != 0) {
      FUN_08016aea(1);
      *(uint *)(DAT_08023158 + 8) = *(uint *)(DAT_08023158 + 8) & 0xfff7ffff;
      *DAT_0802315c = 0x2000;
      return in_r3;
    }
  }
  *(undefined4 **)(iVar1 + 0x38) = puVar3;
  uVar4 = FUN_08016890(iVar1,0x199a,in_r3);
  return uVar4;
}



/* ===== FUN_080230be @ 080230be ===== */

undefined4 FUN_080230be(void)

{
  int iVar1;
  int iVar2;
  undefined4 in_r3;
  int *piVar3;
  
  iVar1 = DAT_08023154;
  piVar3 = *(int **)(DAT_08023154 + 0x38);
  FUN_080168b4(DAT_08023154);
  if (piVar3 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar3 + 4))(piVar3);
    *(undefined4 *)(iVar1 + 0x38) = 0;
    if (iVar2 != 0) {
      FUN_08016aea(2);
      *(uint *)(DAT_08023158 + 8) = *(uint *)(DAT_08023158 + 8) & 0xfff7ffff;
      *DAT_0802315c = 0x2000;
    }
  }
  return in_r3;
}



/* ===== FUN_080230f4 @ 080230f4 ===== */

void FUN_080230f4(undefined4 param_1)

{
  *(undefined4 *)(DAT_08023154 + 0x30) = param_1;
  return;
}



/* ===== FUN_080230fc @ 080230fc ===== */

undefined4 FUN_080230fc(void)

{
  return *(undefined4 *)(DAT_08023154 + 0x18);
}



/* ===== FUN_08023104 @ 08023104 ===== */

void FUN_08023104(void)

{
  int iVar1;
  float fVar2;
  
  iVar1 = DAT_08023154;
  fVar2 = *(float *)(DAT_08023154 + 0x1c);
  *(float *)(DAT_08023154 + 0x20) = fVar2 + *(float *)(DAT_08023154 + 0x28);
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(float *)(iVar1 + 0x24) = fVar2 + *(float *)(iVar1 + 0x2c);
  *(undefined4 *)(iVar1 + 0x2c) = 0;
  return;
}



/* ===== FUN_0802312a @ 0802312a ===== */

undefined4 FUN_0802312a(void)

{
  return *(undefined4 *)(DAT_08023154 + 0x20);
}



/* ===== FUN_08023132 @ 08023132 ===== */

undefined4 FUN_08023132(void)

{
  return *(undefined4 *)(DAT_08023154 + 0x24);
}



/* ===== FUN_0802313a @ 0802313a ===== */

undefined4 FUN_0802313a(void)

{
  return *(undefined4 *)(DAT_08023154 + 0x1c);
}



/* ===== FUN_08023160 @ 08023160 ===== */

void FUN_08023160(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_0802332c;
  puVar1 = DAT_08023328;
  *DAT_08023328 = 0;
  *puVar2 = 1;
  if (puVar1[2] == '\0') {
    puVar1[2] = (char)param_1;
  }
  FUN_080187dc("BLE: error #0x%0.2X!",param_1,param_4);
  return;
}



/* ===== FUN_08023180 @ 08023180 ===== */

void FUN_08023180(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 unaff_r7;
  
  FUN_08018794("BLE: Hardware initialization");
  puVar1 = DAT_0802332c;
  *DAT_08023328 = 0;
  *puVar1 = 0;
  FUN_08016904(DAT_08023330,&DAT_080233d8,4);
  iVar2 = DAT_08027528;
  uVar3 = FUN_08026fd0(unaff_r7);
  *(undefined4 *)(iVar2 + 8) = uVar3;
  *(undefined4 *)(iVar2 + 4) = 0;
  return;
}



/* ===== FUN_080231a8 @ 080231a8 ===== */

void FUN_080231a8(void)

{
  undefined4 unaff_r7;
  
  FUN_08018794("BLE: Start");
  FUN_08016904(DAT_08023334,&DAT_080233f8,3,unaff_r7);
  return;
}



/* ===== FUN_080231c0 @ 080231c0 ===== */

void FUN_080231c0(void)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  
  FUN_08018794("BLE: Stop");
  FUN_080168b4(DAT_08023330);
  FUN_080168b4(DAT_08023334);
  puVar3 = DAT_0801a174;
  iVar1 = DAT_0801a14c;
  *DAT_0801a164 = *DAT_0801a164 & 0xffffdfff;
  *(undefined1 *)(iVar1 + 0x18) = 0;
  *DAT_0801a148 = 0;
  puVar2 = DAT_0801a170;
  *puVar3 = 4;
  *puVar2 = *puVar2 & 0xffff7fff;
  return;
}



/* ===== FUN_080231de @ 080231de ===== */

void FUN_080231de(void)

{
  FUN_08019f26(1);
  return;
}



/* ===== FUN_080231e4 @ 080231e4 ===== */

undefined4 FUN_080231e4(void)

{
  undefined4 uVar1;
  undefined4 unaff_r7;
  
  FUN_08029736();
  FUN_0802705a();
  if (*DAT_08023328 == '\x02') {
    return unaff_r7;
  }
  FUN_08023160(0x85);
  FUN_080168b4(DAT_08023330);
  uVar1 = FUN_08018794("BLE: Init sequence error!",unaff_r7);
  return uVar1;
}



/* ===== FUN_080231fc @ 080231fc ===== */

undefined4 FUN_080231fc(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_r7;
  
  iVar1 = FUN_0802966a();
  if (iVar1 == 0) {
    return unaff_r7;
  }
  FUN_08023160(0x84);
  FUN_080168b4(DAT_08023330);
  uVar2 = FUN_08018794("BLE: Init sequence error!",unaff_r7);
  return uVar2;
}



/* ===== FUN_08023222 @ 08023222 ===== */

void FUN_08023222(void)

{
  FUN_08019d88((*(uint *)(DAT_08023338 + 0x58) & 0x7f) >> 6);
  return;
}



/* ===== FUN_0802322e @ 0802322e ===== */

uint FUN_0802322e(void)

{
  return ~-(uint)(*(char *)(DAT_08023330 + 0xc) == '\0') >> 0x1f;
}



/* ===== FUN_08023232 @ 08023232 ===== */

void FUN_08023232(void)

{
  undefined4 unaff_r7;
  
  FUN_080168b4(DAT_08023330);
  FUN_08019f26(0,unaff_r7);
  return;
}



/* ===== FUN_0802327e @ 0802327e ===== */

uint FUN_0802327e(void)

{
  return ~-(uint)(*(char *)(DAT_08023334 + 0xc) == '\0') >> 0x1f;
}



/* ===== FUN_080232a8 @ 080232a8 ===== */

longlong FUN_080232a8(void)

{
  uint unaff_r7;
  
  if (*DAT_08023328 == '\a') {
    *DAT_08023344 = *DAT_08023344 | 4;
  }
  else {
    FUN_08023160(8);
  }
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080232e8 @ 080232e8 ===== */

void FUN_080232e8(void)

{
  FUN_080168b4(DAT_08023348);
  return;
}



/* ===== FUN_080232ee @ 080232ee ===== */

longlong FUN_080232ee(void)

{
  uint unaff_r7;
  
  if (*DAT_08023328 == '\0') {
    *DAT_08023328 = '\x05';
    FUN_08027036();
  }
  else {
    FUN_08023160(9);
  }
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08023320 @ 08023320 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08023320(void)

{
  FUN_080168b4(_DAT_0802334c);
  return;
}



/* ===== FUN_08023410 @ 08023410 ===== */

int FUN_08023410(char *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  if (*param_1 == '\0') {
    *param_1 = '\x01';
    piVar3 = *(int **)(param_1 + 0xc);
    piVar5 = piVar3 + 3;
    if (piVar3 < piVar5) {
      for (; piVar3 < piVar5; piVar3 = piVar3 + 1) {
        *piVar3 = param_2;
      }
    }
    param_1[0x10] = '\0';
    param_1[0x11] = '\0';
    param_1[0x12] = '\0';
    param_1[0x13] = '\0';
    *(int *)(param_1 + 8) = param_2;
    *(int *)(param_1 + 4) = param_2 << 7;
    return param_2;
  }
  iVar4 = *(int *)(param_1 + 0x10) + 1;
  if (2 < iVar4) {
    iVar4 = 0;
  }
  *(int *)(param_1 + 0x10) = iVar4;
  *(int *)(*(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x10) * 4) = param_2;
  iVar4 = *(int *)(param_1 + 0x14);
  iVar6 = *(int *)(param_1 + 0x18);
  iVar1 = *(int *)(param_1 + 0x1c);
  if (iVar4 < iVar6) {
    if ((iVar4 < iVar1) && (iVar4 = iVar6, iVar1 < iVar6)) {
LAB_0802346c:
      iVar4 = iVar1;
    }
  }
  else if ((iVar1 <= iVar4) && (iVar4 = iVar6, iVar6 < iVar1)) goto LAB_0802346c;
  iVar4 = (iVar4 + *(int *)(param_1 + 4)) - *(int *)(param_1 + 8);
  *(int *)(param_1 + 4) = iVar4;
  if (iVar4 < 0) {
    uVar2 = 0;
    param_1[4] = '\0';
    param_1[5] = '\0';
    param_1[6] = '\0';
    param_1[7] = '\0';
  }
  else {
    if (iVar4 <= DAT_080234a0) {
      *(int *)(param_1 + 8) = (int)(iVar4 + ((uint)(iVar4 >> 6) >> 0x19)) >> 7;
      goto LAB_0802349a;
    }
    *(int *)(param_1 + 4) = DAT_080234a0;
    uVar2 = 0x1194;
  }
  *(undefined4 *)(param_1 + 8) = uVar2;
LAB_0802349a:
  return *(int *)(param_1 + 8);
}



/* ===== FUN_080234a4 @ 080234a4 ===== */

void FUN_080234a4(int param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(param_1 + 0x1c0);
  while ((param_2 < *puVar1 || (*puVar1 + puVar1[1] <= param_2))) {
    puVar1 = (uint *)puVar1[2];
    if (puVar1 == (uint *)0x0) {
      return;
    }
  }
  return;
}



/* ===== FUN_080234be @ 080234be ===== */

undefined4 FUN_080234be(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_08023520;
  if (*DAT_08023520 == 0) {
    DAT_08023520[1] = 0x1000;
    piVar1[3] = -1;
    piVar1[4] = -1;
    iVar2 = DAT_08023524;
    piVar1[2] = 0x10000;
    piVar1[5] = 4;
    *(undefined4 *)(iVar2 + 0x1bc) = 4;
    *piVar1 = DAT_08023528;
  }
  return 1;
}



/* ===== FUN_080234ea @ 080234ea ===== */

void FUN_080234ea(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if ((param_2 + 8U & 7) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 8 - (param_2 + 8U) & 7;
  }
  param_2 = param_2 + uVar1;
  uVar1 = param_3 - uVar1;
  *(int *)(param_1 + 0x18) = param_2;
  *(uint *)(param_1 + 0xc) = uVar1;
  *(uint *)(param_2 + 4) = uVar1 | 1;
  *(undefined4 *)(param_2 + 4 + uVar1) = 0x28;
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(DAT_08023520 + 0x10);
  return;
}



/* ===== FUN_0802352c @ 0802352c ===== */

uint * FUN_0802352c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  uint *puVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  uint *puVar14;
  uint uVar15;
  uint *puVar16;
  uint *puVar17;
  uint uVar18;
  uint *unaff_r8;
  uint *puVar19;
  uint *puVar20;
  int *piVar21;
  bool bVar22;
  int *local_34;
  
  puVar19 = DAT_080235b4;
  if (0xf4 < param_1) {
    if (param_1 < 0xffffffc0) {
      uVar15 = param_1 + 0xb & 0xfffffff8;
      if (DAT_080235b4[1] != 0) {
        uVar11 = 0;
        uVar9 = param_1 + 0xb >> 8;
        uVar1 = -uVar15;
        if (uVar9 == 0) {
          uVar9 = 0;
        }
        else if (uVar9 < 0x10000) {
          uVar10 = uVar9 - 0x100 >> 0x10 & 8;
          iVar7 = uVar9 << uVar10;
          uVar9 = iVar7 - 0x1000U >> 0x10 & 4;
          iVar7 = iVar7 << uVar9;
          uVar12 = iVar7 - 0x4000U >> 0x10 & 2;
          iVar7 = (((0xe - uVar10) - uVar9) - uVar12) + ((uint)(iVar7 << uVar12) >> 0xf);
          uVar9 = (uVar15 >> (iVar7 + 7U & 0xff) & 1) + iVar7 * 2;
        }
        else {
          uVar9 = 0x1f;
        }
        unaff_r8 = DAT_080235b4 + 0x4c;
        if (unaff_r8[uVar9] != 0) {
          uVar10 = uVar15;
          if (uVar9 != 0x1f) {
            uVar10 = uVar15 << (0x19 - (uVar9 >> 1) & 0xff);
          }
          uVar12 = unaff_r8[uVar9];
          uVar18 = 0;
          do {
            uVar8 = uVar12;
            uVar12 = (*(uint *)(uVar8 + 4) & 0xfffffff8) - uVar15;
            if (uVar12 < uVar1) {
              uVar1 = uVar12;
              uVar11 = uVar8;
              if (uVar12 == 0) goto LAB_08023a22;
            }
            uVar2 = *(uint *)(uVar8 + 0x14);
            uVar12 = *(uint *)(uVar8 + 0x10 + ((int)uVar10 >> 0x1f) * -4);
            uVar8 = uVar18;
            if (uVar2 != 0 && uVar2 != uVar12) {
              uVar8 = uVar2;
            }
            if (uVar12 == 0) goto LAB_08023a22;
            uVar10 = uVar10 << 1;
            uVar18 = uVar8;
          } while( true );
        }
        goto LAB_08023a28;
      }
    }
    else {
      uVar15 = 0xffffffff;
    }
    goto LAB_08023d34;
  }
  if (param_1 < 0xb) {
    uVar15 = 0x10;
  }
  else {
    uVar15 = param_1 + 0xb & 0xfffffff8;
  }
  uVar11 = uVar15 >> 3;
  uVar1 = *DAT_080235b4 >> (uVar11 & 0xff);
  if ((uVar1 & 3) != 0) {
    uVar11 = (~uVar1 & 1) + uVar11;
    puVar14 = DAT_080235b4 + uVar11 * 2 + 10;
    uVar15 = uVar11 * 8;
    puVar16 = (uint *)puVar14[2];
    if ((puVar16[1] & 0xfffffff8) != uVar15) {
      FUN_0802df14();
    }
    puVar20 = (uint *)puVar16[2];
    if (puVar16 == puVar14) {
      FUN_0802df14();
    }
    if (puVar16 == puVar20) {
      FUN_0802df14();
    }
    if ((puVar16[1] & 0xfffffff8) != uVar15) {
      FUN_0802df14();
    }
    if (puVar14 == puVar20) {
      *puVar19 = *puVar19 & ~(1 << (uVar11 & 0xff));
    }
    else if ((puVar20 < (uint *)puVar19[4]) || ((uint *)puVar20[3] != puVar16)) {
      FUN_0802df14();
    }
    else {
      puVar14[2] = (uint)puVar20;
      puVar20[3] = (uint)puVar14;
    }
    puVar16[1] = uVar15 | 3;
    puVar16[uVar11 * 2 + 1] = puVar16[uVar11 * 2 + 1] | 1;
    return puVar16 + 2;
  }
  if (uVar15 <= DAT_080235b4[2]) goto LAB_08023d34;
  if (uVar1 != 0) {
    iVar7 = 1 << (uVar11 & 0xff);
    uVar1 = uVar1 << (uVar11 & 0xff) & (iVar7 * 2 | iVar7 * -2);
    uVar12 = (uVar1 & -uVar1) - 1;
    uVar1 = uVar12 >> 0xc & 0x10;
    uVar12 = uVar12 >> uVar1;
    uVar11 = uVar12 >> 5 & 8;
    uVar12 = uVar12 >> uVar11;
    uVar9 = uVar12 >> 2 & 4;
    uVar12 = uVar12 >> uVar9;
    uVar10 = uVar12 >> 1 & 2;
    uVar12 = uVar12 >> uVar10;
    uVar18 = -((int)(uVar12 << 0x1e) >> 0x1f);
    uVar1 = (uVar12 >> (uVar18 & 0xff)) + uVar18 + uVar10 + uVar9 + uVar11 + uVar1;
    puVar14 = DAT_080235b4 + uVar1 * 2 + 10;
    uVar11 = uVar1 * 8;
    puVar16 = (uint *)puVar14[2];
    if ((puVar16[1] & 0xfffffff8) != uVar11) {
      FUN_0802df14();
    }
    puVar20 = (uint *)puVar16[2];
    if (puVar16 == puVar14) {
      FUN_0802df14();
    }
    if (puVar16 == puVar20) {
      FUN_0802df14();
    }
    if ((puVar16[1] & 0xfffffff8) != uVar11) {
      FUN_0802df14();
    }
    if (puVar14 == puVar20) {
      *puVar19 = *puVar19 & ~(1 << (uVar1 & 0xff));
    }
    else if ((puVar20 < (uint *)puVar19[4]) || ((uint *)puVar20[3] != puVar16)) {
      FUN_0802df14();
    }
    else {
      puVar14[2] = (uint)puVar20;
      puVar20[3] = (uint)puVar14;
    }
    uVar11 = uVar11 - uVar15;
    puVar16[1] = uVar15 | 3;
    *(uint *)((int)puVar16 + uVar15 + 4) = uVar11 | 1;
    *(uint *)((int)puVar16 + uVar15 + uVar11) = uVar11;
    uVar1 = puVar19[2];
    uVar9 = uVar1 >> 3;
    if (0x1f < uVar9) {
      FUN_0802df14();
    }
    if (uVar1 != 0) {
      uVar10 = puVar19[5];
      puVar14 = puVar19 + uVar9 * 2 + 10;
      if (uVar1 < 0x10) {
        FUN_0802df14();
      }
      if ((int)((*puVar19 >> (uVar9 & 0xff)) << 0x1f) < 0) {
        puVar20 = (uint *)puVar14[2];
        if (puVar20 < (uint *)puVar19[4]) {
          FUN_0802df14();
          puVar20 = puVar14;
        }
      }
      else {
        *puVar19 = 1 << (uVar9 & 0xff) | *puVar19;
        puVar20 = puVar14;
      }
      puVar14[2] = uVar10;
      puVar20[3] = uVar10;
      *(uint **)(uVar10 + 8) = puVar20;
      *(uint **)(uVar10 + 0xc) = puVar14;
    }
    puVar19[2] = uVar11;
    puVar19[5] = (int)puVar16 + uVar15;
    return puVar16 + 2;
  }
  uVar1 = DAT_080235b4[1];
  if (uVar1 != 0) {
    uVar1 = (uVar1 & -uVar1) - 1;
    uVar11 = uVar1 >> 0xc & 0x10;
    uVar1 = uVar1 >> uVar11;
    uVar9 = uVar1 >> 5 & 8;
    uVar1 = uVar1 >> uVar9;
    uVar10 = uVar1 >> 2 & 4;
    uVar1 = uVar1 >> uVar10;
    uVar12 = uVar1 >> 1 & 2;
    uVar1 = uVar1 >> uVar12;
    uVar18 = -((int)(uVar1 << 0x1e) >> 0x1f);
    uVar1 = DAT_080235b4
            [(uVar1 >> (uVar18 & 0xff)) + uVar18 + uVar12 + uVar10 + uVar9 + uVar11 + 0x4c];
    uVar11 = uVar1;
    uVar9 = (*(uint *)(uVar1 + 4) & 0xfffffff8) - uVar15;
    while ((uVar10 = *(uint *)(uVar1 + 0x10), uVar10 != 0 ||
           (uVar10 = *(uint *)(uVar1 + 0x14), uVar10 != 0))) {
      uVar12 = (*(uint *)(uVar10 + 4) & 0xfffffff8) - uVar15;
      uVar1 = uVar10;
      if (uVar12 < uVar9) {
        uVar11 = uVar10;
        uVar9 = uVar12;
      }
    }
    if (uVar11 < DAT_080235b4[4]) goto LAB_08023958;
    uVar1 = uVar15 + uVar9;
    if ((*(uint *)(uVar11 + 4) & 0xfffffff8) != uVar1) {
      FUN_0802df14();
    }
    uVar10 = uVar11 + uVar15;
    if (uVar10 <= uVar11) goto LAB_08023958;
    uVar12 = *(uint *)(uVar11 + 0xc);
    uVar18 = *(uint *)(uVar11 + 0x18);
    if (uVar12 == uVar11) {
      uVar12 = *(uint *)(uVar11 + 0x14);
      puVar16 = (uint *)(uVar11 + 0x14);
      if (uVar12 == 0) {
        puVar16 = (uint *)(uVar11 + 0x10);
        uVar12 = *puVar16;
        if (uVar12 == 0) goto LAB_0802383c;
      }
      while( true ) {
        puVar14 = (uint *)(uVar12 + 0x14);
        uVar8 = *puVar14;
        bVar22 = uVar8 == 0;
        if (bVar22) {
          puVar14 = (uint *)(uVar12 + 0x10);
          uVar8 = *puVar14;
        }
        if (bVar22 && uVar8 == 0) break;
        uVar12 = *puVar14;
        puVar16 = puVar14;
      }
      if (puVar16 < (uint *)puVar19[4]) goto LAB_08023838;
      *puVar16 = 0;
    }
    else {
      uVar2 = *(uint *)(uVar11 + 8);
      uVar8 = puVar19[4];
      if (uVar8 <= uVar2) {
        bVar22 = *(uint *)(uVar2 + 0xc) == uVar11;
        if (bVar22) {
          uVar8 = *(uint *)(uVar12 + 8);
        }
        if (bVar22 && uVar8 == uVar11) {
          *(uint *)(uVar2 + 0xc) = uVar12;
          *(uint *)(uVar12 + 8) = uVar2;
          goto LAB_0802383c;
        }
      }
LAB_08023838:
      FUN_0802df14();
    }
LAB_0802383c:
    if (uVar18 != 0) {
      if (uVar11 == puVar19[*(int *)(uVar11 + 0x1c) + 0x4c]) {
        puVar19[*(int *)(uVar11 + 0x1c) + 0x4c] = uVar12;
        if (uVar12 == 0) {
          puVar19[1] = puVar19[1] & ~(1 << (*(uint *)(uVar11 + 0x1c) & 0xff));
          goto LAB_080238aa;
        }
      }
      else if (uVar18 < puVar19[4]) {
        FUN_0802df14();
      }
      else if (*(uint *)(uVar18 + 0x10) == uVar11) {
        *(uint *)(uVar18 + 0x10) = uVar12;
      }
      else {
        *(uint *)(uVar18 + 0x14) = uVar12;
      }
      if (uVar12 != 0) {
        uVar8 = puVar19[4];
        if (uVar12 < uVar8) {
LAB_080238a6:
          FUN_0802df14();
        }
        else {
          *(uint *)(uVar12 + 0x18) = uVar18;
          uVar18 = *(uint *)(uVar11 + 0x10);
          if (uVar18 != 0) {
            if (uVar18 < uVar8) {
              FUN_0802df14();
            }
            else {
              *(uint *)(uVar12 + 0x10) = uVar18;
              *(uint *)(uVar18 + 0x18) = uVar12;
            }
          }
          uVar18 = *(uint *)(uVar11 + 0x14);
          if (uVar18 != 0) {
            if (uVar18 < puVar19[4]) goto LAB_080238a6;
            *(uint *)(uVar12 + 0x14) = uVar18;
            *(uint *)(uVar18 + 0x18) = uVar12;
          }
        }
      }
    }
LAB_080238aa:
    if (uVar9 < 0x10) {
      *(uint *)(uVar11 + 4) = uVar1 | 3;
      *(uint *)(uVar11 + 4 + uVar1) = *(uint *)(uVar11 + 4 + uVar1) | 1;
    }
    else {
      *(uint *)(uVar11 + 4) = uVar15 | 3;
      *(uint *)(uVar11 + 4 + uVar15) = uVar9 | 1;
      *(uint *)(uVar10 + uVar9) = uVar9;
      uVar1 = puVar19[2];
      uVar12 = uVar1 >> 3;
      if (0x1f < uVar12) {
        FUN_0802df14();
      }
      if (uVar1 != 0) {
        uVar18 = puVar19[5];
        puVar16 = puVar19 + uVar12 * 2 + 10;
        if (uVar1 < 0x10) {
          FUN_0802df14();
        }
        if ((int)((*puVar19 >> (uVar12 & 0xff)) << 0x1f) < 0) {
          puVar14 = (uint *)puVar16[2];
          if (puVar14 < (uint *)puVar19[4]) {
            FUN_0802df14();
            puVar14 = puVar16;
          }
        }
        else {
          *puVar19 = 1 << (uVar12 & 0xff) | *puVar19;
          puVar14 = puVar16;
        }
        puVar16[2] = uVar18;
        puVar14[3] = uVar18;
        *(uint **)(uVar18 + 8) = puVar14;
        *(uint **)(uVar18 + 0xc) = puVar16;
      }
      puVar19[2] = uVar9;
      puVar19[5] = uVar10;
    }
joined_r0x08023d30:
    unaff_r8 = (uint *)0x0;
    if ((uint *)(uVar11 + 8) != (uint *)0x0) {
      return (uint *)(uVar11 + 8);
    }
    goto LAB_08023d34;
  }
  goto LAB_08023d76;
LAB_0802400c:
  while( true ) {
    puVar4 = puVar20 + 5;
    uVar9 = *puVar4;
    bVar22 = uVar9 == 0;
    if (bVar22) {
      puVar4 = puVar20 + 4;
      uVar9 = *puVar4;
    }
    if (bVar22 && uVar9 == 0) break;
    puVar20 = (uint *)*puVar4;
    puVar17 = puVar4;
  }
  if (puVar17 < (uint *)puVar19[4]) {
LAB_0802402c:
    FUN_0802df14();
  }
  else {
    *puVar17 = 0;
  }
LAB_08024030:
  if (uVar11 != 0) {
    if (puVar16 == (uint *)puVar19[puVar16[7] + 0x4c]) {
      puVar19[puVar16[7] + 0x4c] = (uint)puVar20;
      if (puVar20 == (uint *)0x0) {
        puVar19[1] = puVar19[1] & ~(1 << (puVar16[7] & 0xff));
        goto LAB_080240a8;
      }
    }
    else if (uVar11 < puVar19[4]) {
      FUN_0802df14();
    }
    else if (*(uint **)(uVar11 + 0x10) == puVar16) {
      *(uint **)(uVar11 + 0x10) = puVar20;
    }
    else {
      *(uint **)(uVar11 + 0x14) = puVar20;
    }
    if (puVar20 != (uint *)0x0) {
      puVar17 = (uint *)puVar19[4];
      if (puVar17 <= puVar20) {
        puVar20[6] = uVar11;
        puVar4 = (uint *)puVar16[4];
        if (puVar4 != (uint *)0x0) {
          if (puVar4 < puVar17) {
            FUN_0802df14();
          }
          else {
            puVar20[4] = (uint)puVar4;
            puVar4[6] = (uint)puVar20;
          }
        }
        uVar11 = puVar16[5];
        if (uVar11 == 0) goto LAB_080240a8;
        if (puVar19[4] <= uVar11) {
          puVar20[5] = uVar11;
          *(uint **)(uVar11 + 0x18) = puVar20;
          goto LAB_080240a8;
        }
      }
LAB_080240a4:
      FUN_0802df14();
    }
  }
LAB_080240a8:
  puVar16 = (uint *)((int)puVar16 + (uVar15 & 0xfffffff8));
  uVar1 = uVar1 + (uVar15 & 0xfffffff8);
LAB_080240ae:
  puVar16[1] = puVar16[1] & 0xfffffffe;
  puVar14[1] = uVar1 | 1;
  uVar15 = uVar1 >> 3;
  *(uint *)((int)puVar14 + uVar1) = uVar1;
  if (uVar15 < 0x20) {
    puVar16 = puVar19 + uVar15 * 2 + 10;
    if (uVar1 < 0x10) {
      FUN_0802df14();
    }
    if ((int)((*puVar19 >> (uVar15 & 0xff)) << 0x1f) < 0) {
      puVar20 = (uint *)puVar16[2];
      if (puVar20 < (uint *)puVar19[4]) {
        FUN_0802df14();
        puVar20 = puVar16;
      }
    }
    else {
      *puVar19 = 1 << (uVar15 & 0xff) | *puVar19;
      puVar20 = puVar16;
    }
    puVar16[2] = (uint)puVar14;
    puVar20[3] = (uint)puVar14;
    puVar14[2] = (uint)puVar20;
    puVar14[3] = (uint)puVar16;
  }
  else {
    uVar15 = uVar1 >> 8;
    if (uVar15 == 0) {
      uVar15 = 0;
    }
    else if (uVar15 < 0x10000) {
      uVar11 = uVar15 - 0x100 >> 0x10 & 8;
      iVar7 = uVar15 << uVar11;
      uVar15 = iVar7 - 0x1000U >> 0x10 & 4;
      iVar7 = iVar7 << uVar15;
      uVar9 = iVar7 - 0x4000U >> 0x10 & 2;
      iVar7 = (((0xe - uVar11) - uVar15) - uVar9) + ((uint)(iVar7 << uVar9) >> 0xf);
      uVar15 = (uVar1 >> (iVar7 + 7U & 0xff) & 1) + iVar7 * 2;
    }
    else {
      uVar15 = 0x1f;
    }
    puVar14[7] = uVar15;
    puVar14[5] = 0;
    puVar16 = puVar19 + uVar15 + 0x4c;
    puVar14[4] = 0;
    if ((int)((puVar19[1] >> (uVar15 & 0xff)) << 0x1f) < 0) {
      uVar11 = *puVar16;
      if (uVar15 == 0x1f) {
        uVar15 = uVar1;
      }
      else {
        uVar15 = uVar1 << (0x19 - (uVar15 >> 1) & 0xff);
      }
      while ((*(uint *)(uVar11 + 4) & 0xfffffff8) != uVar1) {
        puVar16 = (uint *)(uVar11 + 0x10 + ((int)uVar15 >> 0x1f) * -4);
        if (*puVar16 == 0) {
          if (puVar16 < (uint *)puVar19[4]) goto LAB_080241ea;
          *puVar16 = (uint)puVar14;
          puVar14[6] = uVar11;
          goto LAB_080241ca;
        }
        uVar15 = uVar15 << 1;
        uVar11 = *puVar16;
      }
      uVar15 = *(uint *)(uVar11 + 8);
      if (uVar11 < puVar19[4] || uVar15 < puVar19[4]) {
LAB_080241ea:
        FUN_0802df14();
      }
      else {
        *(uint **)(uVar15 + 0xc) = puVar14;
        *(uint **)(uVar11 + 8) = puVar14;
        puVar14[2] = uVar15;
        puVar14[3] = uVar11;
        puVar14[6] = 0;
      }
    }
    else {
      puVar19[1] = 1 << (uVar15 & 0xff) | puVar19[1];
      *puVar16 = (uint)puVar14;
      puVar14[6] = (uint)puVar16;
LAB_080241ca:
      puVar14[3] = (uint)puVar14;
      puVar14[2] = (uint)puVar14;
    }
  }
LAB_080241ee:
  return (uint *)(local_34 + 2);
LAB_08023a22:
  if (uVar8 == 0) {
    if (uVar11 == 0) {
LAB_08023a28:
      iVar7 = 1 << (uVar9 & 0xff);
      uVar9 = DAT_080235b4[1] & (iVar7 * 2 | iVar7 * -2);
      if (uVar9 == 0) goto LAB_08023d34;
      uVar18 = (uVar9 & -uVar9) - 1;
      uVar9 = uVar18 >> 0xc & 0x10;
      uVar18 = uVar18 >> uVar9;
      uVar10 = uVar18 >> 5 & 8;
      uVar18 = uVar18 >> uVar10;
      uVar12 = uVar18 >> 2 & 4;
      uVar18 = uVar18 >> uVar12;
      uVar8 = uVar18 >> 1 & 2;
      uVar18 = uVar18 >> uVar8;
      uVar2 = -((int)(uVar18 << 0x1e) >> 0x1f);
      uVar8 = unaff_r8[(uVar18 >> (uVar2 & 0xff)) + uVar8 + uVar12 + uVar10 + uVar9 + uVar2];
      goto LAB_08023a92;
    }
  }
  else {
LAB_08023a92:
    for (; uVar8 != 0; uVar8 = *(uint *)(uVar8 + 0x14)) {
      while( true ) {
        uVar9 = (*(uint *)(uVar8 + 4) & 0xfffffff8) - uVar15;
        if (uVar9 < uVar1) {
          uVar11 = uVar8;
          uVar1 = uVar9;
        }
        if (*(uint *)(uVar8 + 0x10) == 0) break;
        uVar8 = *(uint *)(uVar8 + 0x10);
      }
    }
  }
  if ((uVar11 == 0) || (DAT_080235b4[2] - uVar15 <= uVar1)) goto LAB_08023d34;
  if (DAT_080235b4[4] <= uVar11) {
    if ((*(uint *)(uVar11 + 4) & 0xfffffff8) != uVar15 + uVar1) {
      FUN_0802df14();
    }
    uVar9 = uVar11 + uVar15;
    if (uVar11 < uVar9) {
      uVar10 = *(uint *)(uVar11 + 0xc);
      uVar12 = *(uint *)(uVar11 + 0x18);
      if (uVar10 == uVar11) {
        uVar10 = *(uint *)(uVar11 + 0x14);
        puVar16 = (uint *)(uVar11 + 0x14);
        if (uVar10 == 0) {
          puVar16 = (uint *)(uVar11 + 0x10);
          uVar10 = *puVar16;
          if (uVar10 == 0) goto LAB_08023b28;
        }
        while( true ) {
          puVar14 = (uint *)(uVar10 + 0x14);
          uVar18 = *puVar14;
          bVar22 = uVar18 == 0;
          if (bVar22) {
            puVar14 = (uint *)(uVar10 + 0x10);
            uVar18 = *puVar14;
          }
          if (bVar22 && uVar18 == 0) break;
          uVar10 = *puVar14;
          puVar16 = puVar14;
        }
        if (puVar16 < (uint *)puVar19[4]) goto LAB_08023b24;
        *puVar16 = 0;
      }
      else {
        uVar8 = *(uint *)(uVar11 + 8);
        uVar18 = puVar19[4];
        if (uVar18 <= uVar8) {
          bVar22 = *(uint *)(uVar8 + 0xc) == uVar11;
          if (bVar22) {
            uVar18 = *(uint *)(uVar10 + 8);
          }
          if (bVar22 && uVar18 == uVar11) {
            *(uint *)(uVar8 + 0xc) = uVar10;
            *(uint *)(uVar10 + 8) = uVar8;
            goto LAB_08023b28;
          }
        }
LAB_08023b24:
        FUN_0802df14();
      }
LAB_08023b28:
      if (uVar12 != 0) {
        if (uVar11 == unaff_r8[*(int *)(uVar11 + 0x1c)]) {
          unaff_r8[*(int *)(uVar11 + 0x1c)] = uVar10;
          if (uVar10 == 0) {
            puVar19[1] = puVar19[1] & ~(1 << (*(uint *)(uVar11 + 0x1c) & 0xff));
            goto LAB_08023b98;
          }
        }
        else if (uVar12 < puVar19[4]) {
          FUN_0802df14();
        }
        else if (*(uint *)(uVar12 + 0x10) == uVar11) {
          *(uint *)(uVar12 + 0x10) = uVar10;
        }
        else {
          *(uint *)(uVar12 + 0x14) = uVar10;
        }
        if (uVar10 != 0) {
          uVar18 = puVar19[4];
          if (uVar10 < uVar18) {
LAB_08023b94:
            FUN_0802df14();
          }
          else {
            *(uint *)(uVar10 + 0x18) = uVar12;
            uVar12 = *(uint *)(uVar11 + 0x10);
            if (uVar12 != 0) {
              if (uVar12 < uVar18) {
                FUN_0802df14();
              }
              else {
                *(uint *)(uVar10 + 0x10) = uVar12;
                *(uint *)(uVar12 + 0x18) = uVar10;
              }
            }
            uVar12 = *(uint *)(uVar11 + 0x14);
            if (uVar12 != 0) {
              if (uVar12 < puVar19[4]) goto LAB_08023b94;
              *(uint *)(uVar10 + 0x14) = uVar12;
              *(uint *)(uVar12 + 0x18) = uVar10;
            }
          }
        }
      }
LAB_08023b98:
      if (uVar1 < 0x10) {
        uVar1 = uVar1 + uVar15;
        *(uint *)(uVar11 + 4) = uVar1 | 3;
        *(uint *)(uVar11 + 4 + uVar1) = *(uint *)(uVar11 + 4 + uVar1) | 1;
      }
      else {
        *(uint *)(uVar11 + 4) = uVar15 | 3;
        *(uint *)(uVar11 + 4 + uVar15) = uVar1 | 1;
        uVar10 = uVar1 >> 3;
        *(uint *)(uVar9 + uVar1) = uVar1;
        if (uVar10 < 0x20) {
          puVar16 = puVar19 + uVar10 * 2 + 10;
          if ((int)((*puVar19 >> (uVar10 & 0xff)) << 0x1f) < 0) {
            puVar14 = (uint *)puVar16[2];
            if (puVar14 < (uint *)puVar19[4]) {
              FUN_0802df14();
              puVar14 = puVar16;
            }
          }
          else {
            *puVar19 = 1 << (uVar10 & 0xff) | *puVar19;
            puVar14 = puVar16;
          }
          puVar16[2] = uVar9;
          puVar14[3] = uVar9;
          *(uint **)(uVar11 + 8 + uVar15) = puVar14;
          *(uint **)(uVar11 + 0xc + uVar15) = puVar16;
        }
        else {
          uVar10 = uVar1 >> 8;
          if (uVar10 == 0) {
            uVar10 = 0;
          }
          else if (uVar10 < 0x10000) {
            uVar12 = uVar10 - 0x100 >> 0x10 & 8;
            iVar7 = uVar10 << uVar12;
            uVar10 = iVar7 - 0x1000U >> 0x10 & 4;
            iVar7 = iVar7 << uVar10;
            uVar18 = iVar7 - 0x4000U >> 0x10 & 2;
            iVar7 = (((0xe - uVar12) - uVar10) - uVar18) + ((uint)(iVar7 << uVar18) >> 0xf);
            uVar10 = (uVar1 >> (iVar7 + 7U & 0xff) & 1) + iVar7 * 2;
          }
          else {
            uVar10 = 0x1f;
          }
          *(uint *)(uVar9 + 0x1c) = uVar10;
          *(undefined4 *)(uVar11 + 0x14 + uVar15) = 0;
          puVar16 = unaff_r8 + uVar10;
          *(undefined4 *)(uVar11 + 0x10 + uVar15) = 0;
          if ((int)((puVar19[1] >> (uVar10 & 0xff)) << 0x1f) < 0) {
            uVar12 = *puVar16;
            if (uVar10 == 0x1f) {
              uVar10 = uVar1;
            }
            else {
              uVar10 = uVar1 << (0x19 - (uVar10 >> 1) & 0xff);
            }
            while ((*(uint *)(uVar12 + 4) & 0xfffffff8) != uVar1) {
              puVar16 = (uint *)(uVar12 + 0x10 + ((int)uVar10 >> 0x1f) * -4);
              if (*puVar16 == 0) {
                if (puVar16 < (uint *)puVar19[4]) goto LAB_08023d28;
                *puVar16 = uVar9;
                *(uint *)(uVar9 + 0x18) = uVar12;
                *(uint *)(uVar11 + 0xc + uVar15) = uVar9;
                *(uint *)(uVar11 + 8 + uVar15) = uVar9;
                goto joined_r0x08023d30;
              }
              uVar10 = uVar10 << 1;
              uVar12 = *puVar16;
            }
            uVar1 = *(uint *)(uVar12 + 8);
            if (uVar12 < puVar19[4] || uVar1 < puVar19[4]) {
LAB_08023d28:
              FUN_0802df14();
            }
            else {
              *(uint *)(uVar1 + 0xc) = uVar9;
              *(uint *)(uVar12 + 8) = uVar9;
              *(uint *)(uVar11 + 8 + uVar15) = uVar1;
              *(uint *)(uVar11 + 0xc + uVar15) = uVar12;
              *(undefined4 *)(uVar9 + 0x18) = 0;
            }
          }
          else {
            puVar19[1] = 1 << (uVar10 & 0xff) | puVar19[1];
            *puVar16 = uVar9;
            *(uint **)(uVar9 + 0x18) = puVar16;
            *(uint *)(uVar11 + 0xc + uVar15) = uVar9;
            *(uint *)(uVar11 + 8 + uVar15) = uVar9;
          }
        }
      }
      goto joined_r0x08023d30;
    }
  }
LAB_08023958:
  unaff_r8 = puVar19 + 0x4c;
  FUN_0802df14();
LAB_08023d34:
  uVar1 = puVar19[2];
  if (uVar15 <= uVar1) {
    uVar11 = uVar1 - uVar15;
    uVar9 = puVar19[5];
    if (uVar11 < 0x10) {
      puVar19[2] = 0;
      puVar19[5] = 0;
      *(uint *)(uVar9 + 4) = uVar1 | 3;
      *(uint *)(uVar9 + 4 + uVar1) = *(uint *)(uVar9 + 4 + uVar1) | 1;
    }
    else {
      uVar1 = uVar9 + uVar15;
      puVar19[5] = uVar1;
      puVar19[2] = uVar11;
      *(uint *)(uVar1 + 4) = uVar11 | 1;
      *(uint *)(uVar1 + uVar11) = uVar11;
      *(uint *)(uVar9 + 4) = uVar15 | 3;
    }
    return (uint *)(uVar9 + 8);
  }
LAB_08023d76:
  puVar16 = DAT_08024938;
  uVar1 = puVar19[3];
  if (uVar15 < uVar1) {
LAB_080243ee:
    uVar11 = puVar19[6];
    puVar19[3] = uVar1 - uVar15;
    puVar19[6] = uVar11 + uVar15;
    *(uint *)(uVar11 + uVar15 + 4) = uVar1 - uVar15 | 1;
    *(uint *)(uVar11 + 4) = uVar15 | 3;
    puVar19 = (uint *)(uVar11 + 8);
  }
  else {
    if (*DAT_08024938 == 0) {
      FUN_080234be();
    }
    uVar1 = puVar16[2];
    uVar1 = uVar1 + uVar15 + 0x2f & ~(uVar1 - 1);
    if (uVar15 < uVar1) {
      puVar14 = puVar19 + 0x6c;
      if ((puVar19[0x6e] == 0) ||
         ((uVar1 = uVar1 + *puVar14, *puVar14 < uVar1 && (uVar1 <= puVar19[0x6e])))) {
        piVar3 = (int *)FUN_0802df1c();
        if (piVar3 != (int *)0x0) {
          unaff_r8 = (uint *)*piVar3;
        }
        if (piVar3 != (int *)0x0 && piVar3 != (int *)0xffffffff) {
          uVar1 = *puVar14 + (int)unaff_r8;
          *puVar14 = uVar1;
          if (puVar19[0x6d] < uVar1) {
            puVar19[0x6d] = uVar1;
          }
          piVar13 = (int *)puVar19[6];
          if (piVar13 == (int *)0x0) {
            if (((int *)puVar19[4] == (int *)0x0) || (piVar3 < (int *)puVar19[4])) {
              puVar19[4] = (uint)piVar3;
            }
            puVar19[0x70] = (uint)piVar3;
            puVar19[0x71] = (uint)unaff_r8;
            puVar19[0x73] = 0;
            puVar19[9] = *puVar16;
            puVar19[8] = 0xffffffff;
            puVar16 = puVar19 + 10;
            uVar1 = 0;
            do {
              puVar16[3] = (uint)puVar16;
              puVar16[2] = (uint)puVar16;
              puVar16[5] = (uint)(puVar16 + 2);
              puVar16[4] = (uint)(puVar16 + 2);
              uVar1 = uVar1 + 2;
              puVar16 = puVar16 + 4;
            } while (uVar1 < 0x20);
            puVar16 = unaff_r8 + -10;
            piVar13 = piVar3;
LAB_08023e5c:
            FUN_080234ea(puVar19,piVar13,puVar16);
          }
          else {
            puVar14 = puVar19 + 0x70;
            for (puVar16 = puVar14; puVar16 != (uint *)0x0; puVar16 = (uint *)puVar16[2]) {
              if (piVar3 == (int *)(puVar16[1] + *puVar16)) {
                if (((-1 < (int)((uint)(byte)puVar16[3] << 0x1c)) && ((int *)*puVar16 <= piVar13))
                   && (piVar13 < (int *)((int)*puVar16 + puVar16[1]))) {
                  puVar16[1] = puVar16[1] + (int)unaff_r8;
                  puVar16 = (uint *)((int)unaff_r8 + puVar19[3]);
                  goto LAB_08023e5c;
                }
                break;
              }
            }
            if (piVar3 < (int *)puVar19[4]) {
              puVar19[4] = (uint)piVar3;
            }
            for (; puVar14 != (uint *)0x0; puVar14 = (uint *)puVar14[2]) {
              if (*puVar14 == (int)piVar3 + (int)unaff_r8) {
                if (-1 < (int)((uint)(byte)puVar14[3] << 0x1c)) {
                  puVar16 = (uint *)*puVar14;
                  *puVar14 = (uint)piVar3;
                  puVar14[1] = puVar14[1] + (int)unaff_r8;
                  if (((uint)(piVar3 + 2) & 7) == 0) {
                    local_34 = piVar3;
                  }
                  else {
                    local_34 = (int *)((int)piVar3 + (8U - (int)(piVar3 + 2) & 7));
                  }
                  if (((uint)(puVar16 + 2) & 7) != 0) {
                    puVar16 = (uint *)((int)puVar16 + (8U - (int)(puVar16 + 2) & 7));
                  }
                  puVar14 = (uint *)((int)local_34 + uVar15);
                  uVar1 = (int)puVar16 + (-uVar15 - (int)local_34);
                  local_34[1] = uVar15 | 3;
                  if (puVar16 <= puVar14) {
                    FUN_0802df14();
                  }
                  if (-1 < (int)((uint)(byte)puVar16[1] << 0x1f)) {
                    FUN_0802df14();
                  }
                  if (uVar1 < 0x10) {
                    FUN_0802df14();
                  }
                  if (puVar16 == (uint *)puVar19[6]) {
                    uVar15 = puVar19[3];
                    puVar19[3] = uVar1 + uVar15;
                    puVar19[6] = (uint)puVar14;
                    puVar14[1] = uVar1 + uVar15 | 1;
                    goto LAB_080241ee;
                  }
                  if (puVar16 == (uint *)puVar19[5]) {
                    uVar1 = uVar1 + puVar19[2];
                    puVar19[2] = uVar1;
                    puVar19[5] = (uint)puVar14;
                    puVar14[1] = uVar1 | 1;
                    *(uint *)((int)puVar14 + uVar1) = uVar1;
                    goto LAB_080241ee;
                  }
                  uVar15 = puVar16[1];
                  if ((uVar15 & 3) != 1) goto LAB_080240ae;
                  uVar11 = uVar15 >> 3;
                  if (0x1f < uVar11) {
                    uVar11 = puVar16[6];
                    puVar20 = (uint *)puVar16[3];
                    if (puVar20 == puVar16) {
                      puVar20 = (uint *)puVar16[5];
                      puVar17 = puVar16 + 5;
                      if (puVar20 != (uint *)0x0) goto LAB_0802400c;
                      puVar17 = puVar16 + 4;
                      puVar20 = (uint *)*puVar17;
                      if (puVar20 != (uint *)0x0) goto LAB_0802400c;
                      goto LAB_08024030;
                    }
                    puVar4 = (uint *)puVar16[2];
                    puVar17 = (uint *)puVar19[4];
                    if (puVar4 < puVar17) goto LAB_0802402c;
                    if ((uint *)puVar4[3] == puVar16) {
                      puVar17 = (uint *)puVar20[2];
                    }
                    if ((uint *)puVar4[3] != puVar16 || puVar17 != puVar16) goto LAB_0802402c;
                    puVar4[3] = (uint)puVar20;
                    puVar20[2] = (uint)puVar4;
                    goto LAB_08024030;
                  }
                  puVar20 = (uint *)puVar16[2];
                  puVar17 = (uint *)puVar16[3];
                  if (puVar16 == puVar17) {
                    FUN_0802df14();
                  }
                  if (puVar16 == puVar20) {
                    FUN_0802df14();
                  }
                  if ((puVar16[1] & 0xfffffff8) != uVar11 * 8) {
                    FUN_0802df14();
                  }
                  if ((puVar20 != puVar19 + uVar11 * 2 + 10) &&
                     ((puVar20 < (uint *)puVar19[4] || ((uint *)puVar20[3] != puVar16))))
                  goto LAB_080240a4;
                  if (puVar17 == puVar20) {
                    *puVar19 = *puVar19 & ~(1 << (uVar11 & 0xff));
                    goto LAB_080240a8;
                  }
                  if ((puVar17 != puVar19 + uVar11 * 2 + 10) &&
                     ((puVar17 < (uint *)puVar19[4] || ((uint *)puVar17[2] != puVar16))))
                  goto LAB_080240a4;
                  puVar20[3] = (uint)puVar17;
                  puVar17[2] = (uint)puVar20;
                  goto LAB_080240a8;
                }
                break;
              }
            }
            piVar5 = (int *)FUN_080234a4(puVar19,piVar13);
            piVar5 = (int *)(piVar5[1] + *piVar5);
            if (((int)piVar5 - 0x27U & 7) == 0) {
              uVar1 = 0;
            }
            else {
              uVar1 = 8 - ((int)piVar5 - 0x27U) & 7;
            }
            piVar21 = (int *)((int)piVar5 + (uVar1 - 0x2f));
            if (piVar21 < piVar13 + 4) {
              piVar21 = piVar13;
            }
            piVar6 = piVar21 + 6;
            local_34 = (int *)0x0;
            FUN_080234ea(puVar19,piVar3,unaff_r8 + -10);
            if (((uint)(piVar21 + 2) & 7) != 0) {
              FUN_0802df14();
            }
            piVar21[1] = 0x1b;
            uVar1 = puVar19[0x71];
            uVar11 = puVar19[0x72];
            uVar9 = puVar19[0x73];
            piVar21[2] = puVar19[0x70];
            piVar21[3] = uVar1;
            piVar21[4] = uVar11;
            piVar21[5] = uVar9;
            puVar19[0x73] = 0;
            puVar19[0x72] = (uint)(piVar21 + 2);
            puVar19[0x70] = (uint)piVar3;
            puVar19[0x71] = (uint)unaff_r8;
            while( true ) {
              local_34 = (int *)((int)local_34 + 1);
              piVar6[1] = 7;
              if (piVar5 <= piVar6 + 2) break;
              piVar6 = piVar6 + 1;
            }
            if ((int)local_34 < 2) {
              FUN_0802df14();
            }
            if (piVar21 != piVar13) {
              uVar11 = (int)piVar21 - (int)piVar13;
              *(uint *)((int)piVar13 + uVar11 + 4) =
                   *(uint *)((int)piVar13 + uVar11 + 4) & 0xfffffffe;
              piVar13[1] = uVar11 | 1;
              uVar1 = uVar11 >> 3;
              *(uint *)((int)piVar13 + uVar11) = uVar11;
              if (uVar1 < 0x20) {
                puVar16 = puVar19 + uVar1 * 2 + 10;
                if (uVar11 < 0x10) {
                  FUN_0802df14();
                }
                if ((int)((*puVar19 >> (uVar1 & 0xff)) << 0x1f) < 0) {
                  puVar14 = (uint *)puVar16[2];
                  if (puVar14 < (uint *)puVar19[4]) {
                    FUN_0802df14();
                    puVar14 = puVar16;
                  }
                }
                else {
                  *puVar19 = *puVar19 | 1 << (uVar1 & 0xff);
                  puVar14 = puVar16;
                }
                puVar16[2] = (uint)piVar13;
                puVar14[3] = (uint)piVar13;
                piVar13[2] = (int)puVar14;
                piVar13[3] = (int)puVar16;
              }
              else {
                uVar1 = uVar11 >> 8;
                if (uVar1 == 0) {
                  uVar1 = 0;
                }
                else if (uVar1 < 0x10000) {
                  uVar9 = uVar1 - 0x100 >> 0x10 & 8;
                  iVar7 = uVar1 << uVar9;
                  uVar1 = iVar7 - 0x1000U >> 0x10 & 4;
                  iVar7 = iVar7 << uVar1;
                  uVar10 = iVar7 - 0x4000U >> 0x10 & 2;
                  iVar7 = (((0xe - uVar9) - uVar1) - uVar10) + ((uint)(iVar7 << uVar10) >> 0xf);
                  uVar1 = (uVar11 >> (iVar7 + 7U & 0xff) & 1) + iVar7 * 2;
                }
                else {
                  uVar1 = 0x1f;
                }
                puVar16 = puVar19 + uVar1 + 0x4c;
                piVar13[7] = uVar1;
                piVar13[5] = 0;
                piVar13[4] = 0;
                if ((int)((puVar19[1] >> (uVar1 & 0xff)) << 0x1f) < 0) {
                  uVar9 = *puVar16;
                  if (uVar1 == 0x1f) {
                    uVar1 = uVar11;
                  }
                  else {
                    uVar1 = uVar11 << (0x19 - (uVar1 >> 1) & 0xff);
                  }
                  while ((*(uint *)(uVar9 + 4) & 0xfffffff8) != uVar11) {
                    puVar16 = (uint *)(uVar9 + 0x10 + ((int)uVar1 >> 0x1f) * -4);
                    if (*puVar16 == 0) {
                      if (puVar16 < (uint *)puVar19[4]) goto LAB_080243e4;
                      *puVar16 = (uint)piVar13;
                      piVar13[6] = uVar9;
                      goto LAB_080243c4;
                    }
                    uVar1 = uVar1 << 1;
                    uVar9 = *puVar16;
                  }
                  uVar1 = *(uint *)(uVar9 + 8);
                  if (uVar9 < puVar19[4] || uVar1 < puVar19[4]) {
LAB_080243e4:
                    FUN_0802df14();
                  }
                  else {
                    *(int **)(uVar1 + 0xc) = piVar13;
                    *(int **)(uVar9 + 8) = piVar13;
                    piVar13[2] = uVar1;
                    piVar13[3] = uVar9;
                    piVar13[6] = 0;
                  }
                }
                else {
                  puVar19[1] = 1 << (uVar1 & 0xff) | puVar19[1];
                  *puVar16 = (uint)piVar13;
                  piVar13[6] = (int)puVar16;
LAB_080243c4:
                  piVar13[3] = (int)piVar13;
                  piVar13[2] = (int)piVar13;
                }
              }
            }
          }
          uVar1 = puVar19[3];
          if (uVar15 < uVar1) goto LAB_080243ee;
        }
      }
    }
    puVar19 = (uint *)0x0;
  }
  return puVar19;
}



/* ===== FUN_08024420 @ 08024420 ===== */

void FUN_08024420(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  bool bVar13;
  
  puVar1 = DAT_0802493c;
  puVar10 = (uint *)(param_1 + -8);
  puVar6 = (uint *)DAT_0802493c[4];
  if ((puVar10 < puVar6) || (uVar2 = *(uint *)(param_1 + -4), (uVar2 & 3) == 1)) goto LAB_0802492c;
  uVar12 = uVar2 & 0xfffffff8;
  puVar7 = (uint *)(uVar2 << 0x1f);
  puVar11 = (uint *)((int)puVar10 + uVar12);
  if ((int)puVar7 < 0) goto LAB_080244c6;
  uVar9 = *puVar10;
  if ((uVar2 & 3) == 0) {
    return;
  }
  puVar10 = (uint *)((int)puVar10 - uVar9);
  uVar12 = uVar12 + uVar9;
  if (puVar10 < puVar6) goto LAB_0802492c;
  if (puVar10 == (uint *)DAT_0802493c[5]) {
    if ((puVar11[1] & 3) == 3) {
      DAT_0802493c[2] = uVar12;
      puVar11[1] = puVar11[1] & 0xfffffffe;
      puVar10[1] = uVar12 | 1;
      goto LAB_08024660;
    }
    goto LAB_080244c6;
  }
  uVar9 = uVar9 >> 3;
  if (uVar9 < 0x20) {
    puVar7 = (uint *)puVar10[3];
    puVar6 = (uint *)puVar10[2];
    if (puVar10 == puVar7) {
      FUN_0802df14();
    }
    if (puVar10 == puVar6) {
      FUN_0802df14();
    }
    if ((puVar10[1] & 0xfffffff8) != uVar9 * 8) {
      FUN_0802df14();
    }
    if ((puVar6 == puVar1 + uVar9 * 2 + 10) ||
       (((uint *)puVar1[4] <= puVar6 && ((uint *)puVar6[3] == puVar10)))) {
      if (puVar7 == puVar6) {
        *puVar1 = *puVar1 & ~(1 << (uVar9 & 0xff));
      }
      else {
        if ((puVar7 != puVar1 + uVar9 * 2 + 10) &&
           ((puVar7 < (uint *)puVar1[4] || ((uint *)puVar7[2] != puVar10)))) goto LAB_08024556;
        puVar6[3] = (uint)puVar7;
        puVar7[2] = (uint)puVar6;
      }
      goto LAB_080244c6;
    }
    goto LAB_08024556;
  }
  puVar4 = (uint *)puVar10[3];
  uVar2 = puVar10[6];
  if (puVar4 == puVar10) {
    puVar4 = (uint *)puVar10[5];
    puVar7 = puVar10 + 5;
    if (puVar4 == (uint *)0x0) {
      puVar7 = puVar10 + 4;
      puVar4 = (uint *)*puVar7;
      if (puVar4 == (uint *)0x0) goto LAB_080245b4;
    }
    while( true ) {
      puVar3 = puVar4 + 5;
      uVar9 = *puVar3;
      bVar13 = uVar9 == 0;
      if (bVar13) {
        puVar3 = puVar4 + 4;
        uVar9 = *puVar3;
      }
      if (bVar13 && uVar9 == 0) break;
      puVar4 = (uint *)*puVar3;
      puVar7 = puVar3;
    }
    if (puVar7 < puVar6) goto LAB_080245b0;
    *puVar7 = 0;
  }
  else {
    puVar3 = (uint *)puVar10[2];
    if (puVar6 <= puVar3) {
      if ((uint *)puVar3[3] == puVar10) {
        puVar7 = (uint *)puVar4[2];
      }
      if ((uint *)puVar3[3] == puVar10 && puVar7 == puVar10) {
        puVar3[3] = (uint)puVar4;
        puVar4[2] = (uint)puVar3;
        goto LAB_080245b4;
      }
    }
LAB_080245b0:
    FUN_0802df14();
  }
LAB_080245b4:
  if (uVar2 != 0) {
    if (puVar10 == (uint *)puVar1[puVar10[7] + 0x4c]) {
      puVar1[puVar10[7] + 0x4c] = (uint)puVar4;
      if (puVar4 == (uint *)0x0) {
        puVar1[1] = puVar1[1] & ~(1 << (puVar10[7] & 0xff));
        goto LAB_080244c6;
      }
    }
    else if (uVar2 < puVar1[4]) {
      FUN_0802df14();
    }
    else if (*(uint **)(uVar2 + 0x10) == puVar10) {
      *(uint **)(uVar2 + 0x10) = puVar4;
    }
    else {
      *(uint **)(uVar2 + 0x14) = puVar4;
    }
    if (puVar4 != (uint *)0x0) {
      puVar6 = (uint *)puVar1[4];
      if (puVar4 < puVar6) {
LAB_08024556:
        FUN_0802df14();
      }
      else {
        puVar4[6] = uVar2;
        puVar7 = (uint *)puVar10[4];
        if (puVar7 != (uint *)0x0) {
          if (puVar7 < puVar6) {
            FUN_0802df14();
          }
          else {
            puVar4[4] = (uint)puVar7;
            puVar7[6] = (uint)puVar4;
          }
        }
        uVar2 = puVar10[5];
        if (uVar2 != 0) {
          if (uVar2 < puVar1[4]) goto LAB_08024556;
          puVar4[5] = uVar2;
          *(uint **)(uVar2 + 0x18) = puVar4;
        }
      }
    }
  }
LAB_080244c6:
  if ((puVar11 <= puVar10) || (uVar2 = puVar11[1], -1 < (int)(uVar2 << 0x1f))) {
LAB_0802492c:
    FUN_0802df14();
    return;
  }
  if ((int)(uVar2 << 0x1e) < 0) {
    puVar11[1] = uVar2 & 0xfffffffe;
    puVar10[1] = uVar12 | 1;
    *(uint *)((int)puVar10 + uVar12) = uVar12;
    goto LAB_080247e6;
  }
  if (puVar11 == (uint *)puVar1[6]) {
    puVar1[6] = (uint)puVar10;
    uVar12 = uVar12 + puVar1[3];
    puVar1[3] = uVar12;
    puVar10[1] = uVar12 | 1;
    if (puVar10 == (uint *)puVar1[5]) {
      puVar1[5] = 0;
      puVar1[2] = 0;
    }
    if (uVar12 <= puVar1[7]) {
      return;
    }
    if (*DAT_08024938 == 0) {
      FUN_080234be();
    }
    if (puVar1[6] == 0) {
      return;
    }
    if (0x28 < puVar1[3]) {
      FUN_080234a4(puVar1);
    }
    if (puVar1[7] < puVar1[3]) {
      puVar1[7] = 0xffffffff;
      return;
    }
    return;
  }
  if (puVar11 == (uint *)puVar1[5]) {
    puVar1[5] = (uint)puVar10;
    uVar12 = uVar12 + puVar1[2];
    puVar1[2] = uVar12;
    puVar10[1] = uVar12 | 1;
LAB_08024660:
    *(uint *)((int)puVar10 + uVar12) = uVar12;
    return;
  }
  uVar12 = uVar12 + (uVar2 & 0xfffffff8);
  uVar2 = uVar2 >> 3;
  if (uVar2 < 0x20) {
    puVar7 = (uint *)puVar11[3];
    puVar6 = (uint *)puVar11[2];
    if (puVar11 == puVar7) {
      FUN_0802df14();
    }
    if (puVar11 == puVar6) {
      FUN_0802df14();
    }
    if ((puVar11[1] & 0xfffffff8) != uVar2 * 8) {
      FUN_0802df14();
    }
    if ((puVar6 != puVar1 + uVar2 * 2 + 10) &&
       ((puVar6 < (uint *)puVar1[4] || ((uint *)puVar6[3] != puVar11)))) goto LAB_080247ba;
    if (puVar7 == puVar6) {
      *puVar1 = *puVar1 & ~(1 << (uVar2 & 0xff));
    }
    else {
      if ((puVar7 != puVar1 + uVar2 * 2 + 10) &&
         ((puVar7 < (uint *)puVar1[4] || ((uint *)puVar7[2] != puVar11)))) goto LAB_080247ba;
      puVar6[3] = (uint)puVar7;
      puVar7[2] = (uint)puVar6;
    }
  }
  else {
    puVar6 = (uint *)puVar11[3];
    uVar2 = puVar11[6];
    if (puVar6 == puVar11) {
      puVar6 = (uint *)puVar11[5];
      puVar7 = puVar11 + 5;
      if (puVar6 == (uint *)0x0) {
        puVar7 = puVar11 + 4;
        puVar6 = (uint *)*puVar7;
        if (puVar6 == (uint *)0x0) goto LAB_0802474a;
      }
      while( true ) {
        puVar4 = puVar6 + 5;
        uVar9 = *puVar4;
        bVar13 = uVar9 == 0;
        if (bVar13) {
          puVar4 = puVar6 + 4;
          uVar9 = *puVar4;
        }
        if (bVar13 && uVar9 == 0) break;
        puVar6 = (uint *)*puVar4;
        puVar7 = puVar4;
      }
      if (puVar7 < (uint *)puVar1[4]) goto LAB_08024746;
      *puVar7 = 0;
    }
    else {
      puVar4 = (uint *)puVar11[2];
      puVar7 = (uint *)puVar1[4];
      if (puVar7 <= puVar4) {
        if ((uint *)puVar4[3] == puVar11) {
          puVar7 = (uint *)puVar6[2];
        }
        if ((uint *)puVar4[3] == puVar11 && puVar7 == puVar11) {
          puVar4[3] = (uint)puVar6;
          puVar6[2] = (uint)puVar4;
          goto LAB_0802474a;
        }
      }
LAB_08024746:
      FUN_0802df14();
    }
LAB_0802474a:
    if (uVar2 != 0) {
      if (puVar11 == (uint *)puVar1[puVar11[7] + 0x4c]) {
        puVar1[puVar11[7] + 0x4c] = (uint)puVar6;
        if (puVar6 == (uint *)0x0) {
          puVar1[1] = puVar1[1] & ~(1 << (puVar11[7] & 0xff));
          goto LAB_080247be;
        }
      }
      else if (uVar2 < puVar1[4]) {
        FUN_0802df14();
      }
      else if (*(uint **)(uVar2 + 0x10) == puVar11) {
        *(uint **)(uVar2 + 0x10) = puVar6;
      }
      else {
        *(uint **)(uVar2 + 0x14) = puVar6;
      }
      if (puVar6 != (uint *)0x0) {
        puVar7 = (uint *)puVar1[4];
        if (puVar6 < puVar7) {
LAB_080247ba:
          FUN_0802df14();
        }
        else {
          puVar6[6] = uVar2;
          puVar4 = (uint *)puVar11[4];
          if (puVar4 != (uint *)0x0) {
            if (puVar4 < puVar7) {
              FUN_0802df14();
            }
            else {
              puVar6[4] = (uint)puVar4;
              puVar4[6] = (uint)puVar6;
            }
          }
          uVar2 = puVar11[5];
          if (uVar2 != 0) {
            if (uVar2 < puVar1[4]) goto LAB_080247ba;
            puVar6[5] = uVar2;
            *(uint **)(uVar2 + 0x18) = puVar6;
          }
        }
      }
    }
  }
LAB_080247be:
  puVar10[1] = uVar12 | 1;
  *(uint *)((int)puVar10 + uVar12) = uVar12;
  if (puVar10 == (uint *)puVar1[5]) {
    puVar1[2] = uVar12;
    return;
  }
LAB_080247e6:
  uVar2 = uVar12 >> 3;
  if (uVar2 < 0x20) {
    puVar6 = puVar1 + uVar2 * 2 + 10;
    if (uVar12 < 0x10) {
      FUN_0802df14();
    }
    if ((int)((*puVar1 >> (uVar2 & 0xff)) << 0x1f) < 0) {
      puVar7 = (uint *)puVar6[2];
      if (puVar7 < (uint *)puVar1[4]) {
        FUN_0802df14();
        puVar7 = puVar6;
      }
    }
    else {
      *puVar1 = 1 << (uVar2 & 0xff) | *puVar1;
      puVar7 = puVar6;
    }
    puVar6[2] = (uint)puVar10;
    puVar7[3] = (uint)puVar10;
    puVar10[2] = (uint)puVar7;
    puVar10[3] = (uint)puVar6;
  }
  else {
    uVar2 = uVar12 >> 8;
    if (uVar2 == 0) {
      uVar2 = 0;
    }
    else if (uVar2 < 0x10000) {
      uVar9 = uVar2 - 0x100 >> 0x10 & 8;
      iVar5 = uVar2 << uVar9;
      uVar2 = iVar5 - 0x1000U >> 0x10 & 4;
      iVar5 = iVar5 << uVar2;
      uVar8 = iVar5 - 0x4000U >> 0x10 & 2;
      iVar5 = (((0xe - uVar9) - uVar2) - uVar8) + ((uint)(iVar5 << uVar8) >> 0xf);
      uVar2 = (uVar12 >> (iVar5 + 7U & 0xff) & 1) + iVar5 * 2;
    }
    else {
      uVar2 = 0x1f;
    }
    puVar6 = puVar1 + uVar2 + 0x4c;
    puVar10[7] = uVar2;
    puVar10[5] = 0;
    puVar10[4] = 0;
    if ((int)((puVar1[1] >> (uVar2 & 0xff)) << 0x1f) < 0) {
      uVar9 = *puVar6;
      if (uVar2 == 0x1f) {
        uVar2 = uVar12;
      }
      else {
        uVar2 = uVar12 << (0x19 - (uVar2 >> 1) & 0xff);
      }
      while ((*(uint *)(uVar9 + 4) & 0xfffffff8) != uVar12) {
        puVar6 = (uint *)(uVar9 + 0x10 + ((int)uVar2 >> 0x1f) * -4);
        if (*puVar6 == 0) {
          if (puVar6 < (uint *)puVar1[4]) goto LAB_0802490c;
          *puVar6 = (uint)puVar10;
          puVar10[6] = uVar9;
          goto LAB_080248ec;
        }
        uVar2 = uVar2 << 1;
        uVar9 = *puVar6;
      }
      uVar2 = *(uint *)(uVar9 + 8);
      if (uVar9 < puVar1[4] || uVar2 < puVar1[4]) {
LAB_0802490c:
        FUN_0802df14();
      }
      else {
        *(uint **)(uVar2 + 0xc) = puVar10;
        *(uint **)(uVar9 + 8) = puVar10;
        puVar10[2] = uVar2;
        puVar10[3] = uVar9;
        puVar10[6] = 0;
      }
    }
    else {
      puVar1[1] = 1 << (uVar2 & 0xff) | puVar1[1];
      *puVar6 = (uint)puVar10;
      puVar10[6] = (uint)puVar6;
LAB_080248ec:
      puVar10[3] = (uint)puVar10;
      puVar10[2] = (uint)puVar10;
    }
    uVar2 = puVar1[8];
    puVar1[8] = uVar2 - 1;
    if (uVar2 - 1 == 0) {
      for (uVar2 = puVar1[0x72]; uVar2 != 0; uVar2 = *(uint *)(uVar2 + 8)) {
      }
      puVar1[8] = 0xffffffff;
    }
  }
  return;
}



/* ===== thunk_FUN_0802df14 @ 08024940 ===== */

void thunk_FUN_0802df14(void)

{
  FUN_0802f2cc(1);
  return;
}



/* ===== FUN_08024968 @ 08024968 ===== */

undefined8 FUN_08024968(uint param_1,uint param_2,byte param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)param_3;
  if (uVar3 < 0x20) {
    uVar1 = param_2 >> (uVar3 & 0x1f) | param_2 << 0x20 - (uVar3 & 0x1f);
    uVar2 = (uVar1 << uVar3) >> uVar3;
    return CONCAT44((int)(uVar2 << uVar3) >> uVar3,param_1 >> uVar3 ^ uVar1 ^ uVar2);
  }
  return CONCAT44((int)param_2 >> 0x1f,(int)param_2 >> (uVar3 - 0x20 & 0xff));
}



/* ===== FUN_0802498c @ 0802498c ===== */

void FUN_0802498c(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  bool bVar13;
  
  while( true ) {
    if (param_3 == 0) {
      return;
    }
    if (((uint)param_2 & 3) == 0) break;
    param_3 = param_3 - 1;
    *(undefined1 *)param_1 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  if (((uint)param_1 & 3) != 0) {
    uVar7 = param_3 - 4;
    if (3 < param_3) {
      puVar5 = param_2;
      if (((uint)param_1 & 1) == 0) {
        do {
          param_2 = puVar5 + 1;
          uVar9 = *puVar5;
          puVar3 = (undefined2 *)((int)param_1 + 2);
          *(short *)param_1 = (short)uVar9;
          bVar13 = 3 < uVar7;
          uVar7 = uVar7 - 4;
          param_1 = param_1 + 1;
          *puVar3 = (short)((uint)uVar9 >> 0x10);
          puVar5 = param_2;
        } while (bVar13);
      }
      else {
        do {
          param_2 = puVar5 + 1;
          uVar9 = *puVar5;
          *(char *)param_1 = (char)uVar9;
          puVar4 = (undefined1 *)((int)param_1 + 3);
          *(short *)((int)param_1 + 1) = (short)((uint)uVar9 >> 8);
          bVar13 = 3 < uVar7;
          uVar7 = uVar7 - 4;
          param_1 = param_1 + 1;
          *puVar4 = (char)((uint)uVar9 >> 0x18);
          puVar5 = param_2;
        } while (bVar13);
      }
    }
    iVar8 = uVar7 + 4;
    do {
      bVar13 = iVar8 != 0;
      iVar8 = iVar8 + -1;
      puVar5 = param_1;
      if (bVar13) {
        puVar5 = (undefined4 *)((int)param_1 + 1);
        *(undefined1 *)param_1 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + 1);
      }
      param_1 = puVar5;
    } while (bVar13 && iVar8 != 0);
    return;
  }
  while (uVar7 = param_3 - 0x10, 0xf < param_3) {
    uVar9 = *param_2;
    uVar10 = param_2[1];
    uVar11 = param_2[2];
    uVar12 = param_2[3];
    param_2 = param_2 + 4;
    *param_1 = uVar9;
    param_1[1] = uVar10;
    param_1[2] = uVar11;
    param_1[3] = uVar12;
    param_1 = param_1 + 4;
    param_3 = uVar7;
  }
  if ((uVar7 & 8) != 0) {
    uVar9 = *param_2;
    uVar10 = param_2[1];
    param_2 = param_2 + 2;
    *param_1 = uVar9;
    param_1[1] = uVar10;
    param_1 = param_1 + 2;
  }
  puVar1 = param_1;
  puVar5 = param_2;
  if ((int)(param_3 << 0x1d) < 0) {
    puVar5 = param_2 + 1;
    puVar1 = param_1 + 1;
    *param_1 = *param_2;
  }
  puVar2 = puVar1;
  puVar6 = puVar5;
  if ((uVar7 & 2) != 0) {
    puVar6 = (undefined4 *)((int)puVar5 + 2);
    puVar2 = (undefined4 *)((int)puVar1 + 2);
    *(undefined2 *)puVar1 = *(undefined2 *)puVar5;
  }
  if ((int)(param_3 << 0x1f) < 0) {
    *(undefined1 *)puVar2 = *(undefined1 *)puVar6;
  }
  return;
}



/* ===== FUN_080249ac @ 080249ac ===== */

void FUN_080249ac(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  while (uVar1 = param_3 - 0x10, 0xf < param_3) {
    uVar6 = *param_2;
    uVar7 = param_2[1];
    uVar8 = param_2[2];
    uVar9 = param_2[3];
    param_2 = param_2 + 4;
    *param_1 = uVar6;
    param_1[1] = uVar7;
    param_1[2] = uVar8;
    param_1[3] = uVar9;
    param_1 = param_1 + 4;
    param_3 = uVar1;
  }
  if ((uVar1 & 8) != 0) {
    uVar6 = *param_2;
    uVar7 = param_2[1];
    param_2 = param_2 + 2;
    *param_1 = uVar6;
    param_1[1] = uVar7;
    param_1 = param_1 + 2;
  }
  puVar2 = param_1;
  puVar4 = param_2;
  if ((int)(param_3 << 0x1d) < 0) {
    puVar4 = param_2 + 1;
    puVar2 = param_1 + 1;
    *param_1 = *param_2;
  }
  puVar3 = puVar2;
  puVar5 = puVar4;
  if ((uVar1 & 2) != 0) {
    puVar5 = (undefined4 *)((int)puVar4 + 2);
    puVar3 = (undefined4 *)((int)puVar2 + 2);
    *(undefined2 *)puVar2 = *(undefined2 *)puVar4;
  }
  if ((int)(param_3 << 0x1f) < 0) {
    *(undefined1 *)puVar3 = *(undefined1 *)puVar5;
  }
  return;
}



/* ===== FUN_08024a32 @ 08024a32 ===== */

uint FUN_08024a32(uint *param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,
                 uint param_6,uint param_7)

{
  uint uVar1;
  uint *puVar2;
  
  if (param_1[0x16] == 0) {
    *param_1 = *param_1 | 8;
  }
  FUN_0802498c(param_1 + 0x17,param_2,0xe);
  uVar1 = param_1[0x16];
  if (uVar1 == 8) {
    param_1[0x1b] = param_1[0x1b] + 1;
  }
  else if ((int)uVar1 < 8) {
    param_1[0x16] = uVar1 + 1;
  }
  uVar1 = param_1[0x15] + 1;
  if (7 < (int)uVar1) {
    uVar1 = 0;
  }
  param_1[0x15] = uVar1;
  puVar2 = (uint *)(param_1[0x14] + param_1[0x15] * 0x20);
  uVar1 = param_1[0x18];
  *puVar2 = param_1[0x17];
  puVar2[1] = uVar1;
  puVar2[2] = param_3;
  puVar2[3] = param_4;
  puVar2[4] = param_5;
  puVar2[5] = param_6;
  puVar2[6] = param_7;
  return param_4;
}



/* ===== FUN_08024a9c @ 08024a9c ===== */

undefined4 FUN_08024a9c(int param_1,undefined4 param_2,undefined4 param_3)

{
  while (0x1c < *(int *)(param_1 + 8)) {
    FUN_08018d2c(param_1);
  }
  FUN_08025800(param_1,param_2,param_3);
  return 0;
}



/* ===== FUN_08024bc8 @ 08024bc8 ===== */

longlong FUN_08024bc8(uint *param_1,uint param_2,char *param_3,uint param_4)

{
  char *pcVar1;
  undefined1 uVar2;
  char cVar3;
  undefined2 uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  
  switch(param_2) {
  case 0:
  case 1:
    puVar9 = (uint *)((int)param_1 + param_2 * 0x16 + 4);
    break;
  case 2:
    uVar4 = FUN_0801862e();
    *(undefined2 *)((int)param_1 + 0x46) = uVar4;
    puVar9 = param_1 + 0xc;
    uVar2 = FUN_0801865c();
    *(undefined1 *)(param_1 + 0x12) = uVar2;
    break;
  case 3:
    puVar9 = param_1 + 0x17;
    break;
  default:
    goto switchD_08024bda_default;
  }
  pcVar1 = DAT_08024cac;
  uVar5 = FUN_0802df48(DAT_08024cac + 1,puVar9);
  if ((0 < (int)uVar5) && (1 < (int)((param_4 - 0xd) / uVar5))) {
    uVar7 = 1 << (param_2 & 0xff);
    if ((*param_1 & uVar7) != 0) {
      *param_1 = *param_1 & ~uVar7;
      uVar7 = *puVar9 - *DAT_08024cb0;
      iVar8 = (puVar9[1] - DAT_08024cb0[1]) - (uint)(*puVar9 < *DAT_08024cb0);
      if (iVar8 < 0) {
        uVar10 = -uVar7;
        iVar11 = -iVar8 - (uint)(uVar7 != 0);
      }
      else {
        uVar10 = uVar7;
        iVar11 = iVar8;
      }
      if ((iVar11 < 0xa4) && ((iVar11 < 0xa3 || (uVar10 < DAT_08024cb4)))) {
        uVar6 = FUN_080186c0(uVar7,iVar8,10000,4);
        *(undefined4 *)(param_3 + 3) = uVar6;
        param_3[2] = *(char *)(DAT_08024cb8 + (uint)(byte)puVar9[2] * 2);
        cVar3 = *pcVar1 + '\x01';
        *pcVar1 = cVar3;
        *param_3 = cVar3;
        param_3[1] = '\0';
        FUN_0802498c(param_3 + 7,(int)puVar9 + 10,uVar5);
        return CONCAT44(param_4,param_3 + 7 + (uVar5 - (int)param_3));
      }
    }
  }
switchD_08024bda_default:
  return (ulonglong)param_4 << 0x20;
}



/* ===== FUN_08024cbc @ 08024cbc ===== */

char * FUN_08024cbc(int *param_1,char *param_2,int param_3)

{
  longlong lVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  uint *puVar12;
  int iVar13;
  int iVar14;
  
  puVar6 = DAT_08024f14;
  while( true ) {
    iVar11 = param_1[2];
    if (iVar11 < 1) {
      return (char *)0x0;
    }
    iVar13 = *param_1;
    iVar14 = (param_1[1] - iVar11) + 1;
    if (iVar14 < 0) {
      iVar14 = (param_1[1] - iVar11) + 0x81;
    }
    puVar12 = (uint *)(iVar13 + iVar14 * 0x12);
    uVar3 = *puVar6;
    uVar4 = *puVar12 - uVar3;
    iVar8 = (puVar12[1] - puVar6[1]) - (uint)(*puVar12 < uVar3);
    if (iVar8 < 0) {
      uVar3 = -uVar4;
      iVar9 = -iVar8 - (uint)(uVar4 != 0);
    }
    else {
      uVar3 = uVar4;
      iVar9 = iVar8;
    }
    if ((iVar9 < 0xa4) && ((iVar9 < 0xa3 || (uVar3 < DAT_08024f18)))) break;
    param_1[2] = iVar11 + -1;
  }
  uVar5 = FUN_080186c0(uVar4,iVar8,10000,4);
  pcVar10 = DAT_08024f1c;
  iVar11 = FUN_0802df48(DAT_08024f1c + 1,puVar12);
  if (iVar11 < 1) {
    param_1[2] = param_1[2] + -1;
    return (char *)0x0;
  }
  if (param_3 - 0xdU < (uint)(iVar11 << 1)) {
    return (char *)0x0;
  }
  *(undefined4 *)(param_2 + 3) = uVar5;
  cVar2 = *pcVar10 + '\x01';
  *pcVar10 = cVar2;
  *param_2 = cVar2;
  cVar2 = *(char *)(DAT_08024f20 + (uint)*(byte *)(iVar13 + 8 + iVar14 * 0x12) * 2);
  param_2[2] = cVar2;
  iVar13 = DAT_08024f20;
  if ((cVar2 != '\a') && (1 < param_1[2])) {
    puVar6 = (uint *)((int)puVar12 + 0x12);
    if ((uint *)(*param_1 + 0x900) <= puVar6) {
      puVar6 = (uint *)((int)puVar12 - 0x8ee);
    }
    if (*(char *)(DAT_08024f20 + (uint)(byte)puVar6[2] * 2) == cVar2) {
      uVar3 = *puVar6 - *puVar12;
      iVar14 = (puVar6[1] - puVar12[1]) - (uint)(*puVar6 < *puVar12);
      if ((((-1 < iVar14) && (iVar14 < 0x148)) && ((iVar14 < 0x147 || (uVar3 < DAT_08024f24)))) &&
         (lVar1 = (ulonglong)uVar3 * 0x19, uVar3 = (uint)lVar1,
         iVar14 = iVar14 * 0x19 + (int)((ulonglong)lVar1 >> 0x20) + (uint)(0xffffefff < uVar3),
         -1 < iVar14 >> 0xd)) {
        *(uint *)(param_2 + 9) = uVar3 + 0x1000 >> 0xd | iVar14 * 0x80000;
        param_2[1] = '\x01';
        FUN_0802498c(param_2 + 0xd,(int)puVar12 + 10,iVar11);
        param_1[2] = param_1[2] + -1;
        param_2[7] = '\x01';
        param_2[8] = '\0';
        pcVar10 = param_2 + 0xd + iVar11;
        do {
          FUN_0802498c(pcVar10,(int)puVar6 + 10,iVar11);
          uVar3 = *puVar6;
          uVar4 = puVar6[1];
          pcVar10 = pcVar10 + iVar11;
          iVar14 = param_1[2];
          param_1[2] = iVar14 + -1;
          *(short *)(param_2 + 7) = *(short *)(param_2 + 7) + 1;
          if ((iVar14 + -1 < 1) || (param_2 + (param_3 - iVar11) <= pcVar10)) break;
          puVar12 = (uint *)((int)puVar6 + 0x12);
          if ((uint *)(*param_1 + 0x900) <= puVar12) {
            puVar12 = (uint *)((int)puVar6 - 0x8ee);
          }
          if (*(char *)(iVar13 + (uint)(byte)puVar12[2] * 2) != cVar2) break;
          uVar7 = *puVar12 - uVar3;
          iVar14 = (puVar12[1] - uVar4) - (uint)(*puVar12 < uVar3);
          if (((iVar14 < 0) || (0x147 < iVar14)) || ((0x146 < iVar14 && (DAT_08024f24 <= uVar7)))) {
            uVar3 = 0xffffffff;
            iVar14 = -1;
          }
          else {
            lVar1 = (ulonglong)uVar7 * 0x19;
            uVar3 = (uint)lVar1;
            iVar14 = iVar14 * 0x19 + (int)((ulonglong)lVar1 >> 0x20) + (uint)(0xffffefff < uVar3);
            uVar3 = uVar3 + 0x1000 >> 0xd | iVar14 * 0x80000;
            iVar14 = iVar14 >> 0xd;
          }
          puVar6 = puVar12;
        } while (iVar14 == 0 && *(uint *)(param_2 + 9) == uVar3);
        return pcVar10 + -(int)param_2;
      }
    }
  }
  param_2[1] = '\0';
  FUN_0802498c(param_2 + 7,(int)puVar12 + 10,iVar11);
  param_1[2] = param_1[2] + -1;
  return param_2 + 7 + (iVar11 - (int)param_2);
}



/* ===== FUN_08024f28 @ 08024f28 ===== */

char * FUN_08024f28(int *param_1,char *param_2,int param_3)

{
  longlong lVar1;
  char cVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  char *pcVar14;
  
  puVar7 = DAT_08025180;
  while( true ) {
    iVar10 = param_1[2];
    if (iVar10 < 1) {
      return (char *)0x0;
    }
    iVar13 = *param_1;
    iVar9 = (param_1[1] - iVar10) + 1;
    if (iVar9 < 0) {
      iVar9 = (param_1[1] - iVar10) + 0x21;
    }
    puVar3 = (uint *)(iVar13 + iVar9 * 0x1a);
    uVar11 = *puVar3;
    uVar4 = *puVar7;
    uVar5 = uVar11 - uVar4;
    iVar8 = (puVar3[1] - puVar7[1]) - (uint)(uVar11 < uVar4);
    if (iVar8 < 0) {
      iVar12 = -iVar8 - (uint)(uVar5 != 0);
      uVar4 = -uVar5;
    }
    else {
      iVar12 = iVar8;
      uVar4 = uVar5;
    }
    if ((iVar12 < 0xa4) && ((iVar12 < 0xa3 || (uVar4 < DAT_08025184)))) break;
    param_1[2] = iVar10 + -1;
  }
  uVar6 = FUN_080186c0(uVar5,iVar8,10000,4);
  pcVar14 = DAT_08025188;
  puVar7 = (uint *)(iVar13 + iVar9 * 0x1a);
  iVar10 = FUN_0802df48(DAT_08025188 + 1,puVar7);
  if (iVar10 < 1) {
    param_1[2] = param_1[2] + -1;
    return (char *)0x0;
  }
  if (param_3 - 0xdU < (uint)(iVar10 << 1)) {
    return (char *)0x0;
  }
  *(undefined4 *)(param_2 + 3) = uVar6;
  cVar2 = *pcVar14 + '\x01';
  *pcVar14 = cVar2;
  *param_2 = cVar2;
  cVar2 = *(char *)(DAT_0802518c + (uint)*(byte *)(iVar13 + 8 + iVar9 * 0x1a) * 2);
  param_2[2] = cVar2;
  if ((cVar2 != '\a') && (1 < param_1[2])) {
    puVar3 = (uint *)((int)puVar7 + 0x1a);
    if ((uint *)(*param_1 + 0x340) <= puVar3) {
      puVar3 = (uint *)((int)puVar7 + -0x326);
    }
    if (*(char *)(DAT_0802518c + (uint)(byte)puVar3[2] * 2) == cVar2) {
      uVar4 = *puVar3 - *puVar7;
      iVar9 = (puVar3[1] - puVar7[1]) - (uint)(*puVar3 < *puVar7);
      if ((((-1 < iVar9) && (iVar9 < 0x148)) && ((iVar9 < 0x147 || (uVar4 < DAT_08025190)))) &&
         (lVar1 = (ulonglong)uVar4 * 0x19, uVar4 = (uint)lVar1,
         iVar9 = iVar9 * 0x19 + (int)((ulonglong)lVar1 >> 0x20) + (uint)(0xffffefff < uVar4),
         -1 < iVar9 >> 0xd)) {
        *(uint *)(param_2 + 9) = uVar4 + 0x1000 >> 0xd | iVar9 * 0x80000;
        param_2[1] = '\x01';
        iVar9 = FUN_08018756(param_2 + 0xd,puVar7,iVar10);
        pcVar14 = param_2 + 0xd + iVar9;
        param_1[2] = param_1[2] + -1;
        param_2[7] = '\x01';
        iVar9 = DAT_0802518c;
        param_2[8] = '\0';
        do {
          if ((char)puVar3[2] != '\b') {
            FUN_0802498c(pcVar14,(int)puVar3 + 10,iVar10);
            pcVar14 = pcVar14 + iVar10;
          }
          uVar4 = *puVar3;
          uVar5 = puVar3[1];
          iVar13 = param_1[2];
          param_1[2] = iVar13 + -1;
          *(short *)(param_2 + 7) = *(short *)(param_2 + 7) + 1;
          if ((iVar13 + -1 < 1) || (param_2 + (param_3 - iVar10) <= pcVar14)) break;
          puVar7 = (uint *)((int)puVar3 + 0x1a);
          if ((uint *)(*param_1 + 0x340) <= puVar7) {
            puVar7 = (uint *)((int)puVar3 + -0x326);
          }
          if (*(char *)(iVar9 + (uint)(byte)puVar7[2] * 2) != cVar2) break;
          uVar11 = *puVar7 - uVar4;
          iVar13 = (puVar7[1] - uVar5) - (uint)(*puVar7 < uVar4);
          if (((iVar13 < 0) || (0x147 < iVar13)) || ((0x146 < iVar13 && (DAT_08025190 <= uVar11))))
          {
            uVar4 = 0xffffffff;
            iVar13 = -1;
          }
          else {
            lVar1 = (ulonglong)uVar11 * 0x19;
            uVar4 = (uint)lVar1;
            iVar13 = iVar13 * 0x19 + (int)((ulonglong)lVar1 >> 0x20) + (uint)(0xffffefff < uVar4);
            uVar4 = uVar4 + 0x1000 >> 0xd | iVar13 * 0x80000;
            iVar13 = iVar13 >> 0xd;
          }
          puVar3 = puVar7;
        } while (iVar13 == 0 && *(uint *)(param_2 + 9) == uVar4);
        return pcVar14 + -(int)param_2;
      }
    }
  }
  param_2[1] = '\0';
  iVar10 = FUN_08018756(param_2 + 7,puVar7,iVar10);
  param_1[2] = param_1[2] + -1;
  return param_2 + 7 + (iVar10 - (int)param_2);
}



/* ===== FUN_08025194 @ 08025194 ===== */

int FUN_08025194(int *param_1)

{
  int iVar1;
  
  iVar1 = (param_1[1] - param_1[2]) + 1;
  if (iVar1 < 0) {
    iVar1 = (param_1[1] - param_1[2]) + 0x21;
  }
  return *param_1 + iVar1 * 0x1a;
}



/* ===== FUN_080251ac @ 080251ac ===== */

undefined8 FUN_080251ac(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 in_r3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  short local_48 [2];
  uint local_44;
  int local_40;
  undefined4 uStack_28;
  
  iVar3 = DAT_08025330;
  uVar4 = 0;
  uStack_28 = in_r3;
  FUN_0802578a();
  uVar7 = 0x2000000;
  iVar5 = 0;
  uVar11 = 0;
  uVar9 = DAT_0802e170;
  do {
    FUN_0802543c(uVar9,0x1e,local_48);
    uVar2 = DAT_0802e170;
    if ((((local_48[0] != -1) && (local_40 != -1 || local_44 != 0xffffffff)) && (iVar5 <= local_40))
       && ((iVar5 < local_40 || (uVar4 < local_44)))) {
      uVar4 = local_44;
      iVar5 = local_40;
      uVar7 = uVar9;
    }
    uVar11 = uVar11 + 1;
    uVar9 = uVar9 + 0x1000;
  } while (uVar11 < 2000);
  if (0x1ffffff < uVar7) {
    *(uint *)(iVar3 + 4) = DAT_0802e170;
    *(uint *)(iVar3 + 8) = uVar2;
    *(undefined4 *)(iVar3 + 0xc) = 0;
    goto LAB_0802e12c;
  }
  iVar8 = 1999;
  bVar1 = false;
  uVar6 = 1;
  uVar9 = uVar7;
  uVar11 = uVar7;
  do {
    uVar10 = uVar9 - 0x1000;
    if ((int)uVar10 < (int)uVar2) {
      uVar10 = uVar9 + 0x7cf000;
    }
    FUN_0802543c(uVar10,0x1e,local_48);
    if ((local_48[0] == -1) || (local_40 == -1 && local_44 == 0xffffffff)) {
      if (!bVar1) {
        bVar1 = true;
      }
    }
    else {
      if (!bVar1) {
        if ((local_40 <= iVar5) && ((local_40 < iVar5 || (local_44 < uVar4)))) {
          uVar6 = uVar6 + 1;
          uVar4 = local_44;
          iVar5 = local_40;
          uVar11 = uVar10;
          goto LAB_0802e08e;
        }
        bVar1 = true;
      }
      FUN_08025636(uVar10);
    }
LAB_0802e08e:
    iVar8 = iVar8 + -1;
    uVar9 = uVar10;
  } while (iVar8 != 0);
  *(undefined4 *)(iVar3 + 4) = 0x2000000;
  *(undefined4 *)(iVar3 + 8) = 0x2000000;
  if (uVar6 < 3) {
    *(undefined4 *)(iVar3 + 0xc) = 0;
    if (1 < uVar6) goto LAB_0802e0ba;
  }
  else {
    *(uint *)(iVar3 + 0xc) = (uVar6 - 2) * 0xff0;
LAB_0802e0ba:
    iVar5 = DAT_0802e174;
    iVar8 = uVar6 - 1;
    do {
      FUN_0802f2e0(iVar3,uVar11);
      if ((uint)(*(int *)(iVar3 + 8) + iVar5) < 0x7d0000) break;
      FUN_08025636(uVar11);
      uVar11 = uVar7 + 0x1000;
      if (0x1ffffff < uVar7 + 0x1000) {
        uVar11 = uVar2;
      }
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  iVar5 = FUN_0802f2e0(iVar3,uVar7);
  if (iVar5 == 0x1000) {
    uVar4 = uVar7 + 0x1000;
    if (0x1ffffff < uVar7 + 0x1000) {
      uVar4 = uVar2;
    }
    *(uint *)(iVar3 + 4) = uVar4;
  }
  if ((*(uint *)(iVar3 + 8) < 0x2000000) && (0x1d < *(uint *)(iVar3 + 0xc))) {
    uVar4 = *(uint *)(iVar3 + 4);
    if (uVar4 == *(uint *)(iVar3 + 8)) {
      *(undefined4 *)(iVar3 + 0xc) = DAT_0802e178;
    }
    iVar3 = uVar4 - 0x1e;
    if (((uVar4 & 0xfff) == 0) && (iVar3 = uVar4 - 0x2e, iVar3 < (int)uVar2)) {
      iVar3 = uVar4 + 0x7cffd2;
    }
    FUN_0802543c(iVar3,0x1e,local_48);
    FUN_080257b6();
    return CONCAT44(local_40,local_44);
  }
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 4);
  *(undefined4 *)(iVar3 + 0xc) = 0;
LAB_0802e12c:
  FUN_080257b6();
  return 0;
}



/* ===== FUN_080251b2 @ 080251b2 ===== */

void FUN_080251b2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  undefined2 local_30;
  undefined2 local_2e;
  undefined1 auStack_2c [28];
  undefined4 uStack_10;
  
  puVar2 = DAT_08025330;
  if ((((*(uint *)(DAT_08025330 + 4) & 0xfff) == 0) &&
      ((*(uint *)(DAT_08025330 + 4) & 0xfffff000) == (*(uint *)(DAT_08025330 + 8) & 0xfffff000))) &&
     (piVar1 = (int *)(DAT_08025330 + 0xc), 0 < *piVar1)) {
    *DAT_08025330 = 1;
    uVar4 = *(int *)(puVar2 + 8) + 0x1000;
    if (0x1ffffff < uVar4) {
      uVar4 = DAT_08025334;
    }
    *(int *)(puVar2 + 0xc) = *(int *)(puVar2 + 8) + (*piVar1 - *(int *)(puVar2 + 4)) + -0xff0;
    *(uint *)(puVar2 + 8) = uVar4 & 0xfffff000;
  }
  uStack_10 = param_4;
  FUN_0802498c(auStack_2c,param_1,0x1a);
  local_2e = FUN_0802e17c(puVar2,param_1);
  local_30 = 0xa5;
  FUN_0802578a();
  iVar3 = FUN_080254a0(*(undefined4 *)(puVar2 + 4),0x1e,&local_30);
  FUN_080257b6();
  if (iVar3 != 0) {
    FUN_08016ac0();
    return;
  }
  iVar3 = *(int *)(puVar2 + 4);
  uVar4 = iVar3 + 0x1e;
  *(uint *)(puVar2 + 4) = uVar4;
  if ((uVar4 & 0xfff) == 0) {
    if (0x1ffffff < uVar4) {
      *(uint *)(puVar2 + 4) = DAT_08025334;
    }
  }
  else if (0x1000 - (uVar4 & 0xfff) < 0x1e) {
    uVar4 = iVar3 + 0x101e;
    if (0x1ffffff < uVar4) {
      uVar4 = DAT_08025334;
    }
    *(uint *)(puVar2 + 4) = uVar4 & 0xfffff000;
  }
  *(int *)(puVar2 + 0xc) = *(int *)(puVar2 + 0xc) + 0x1e;
  return;
}



/* ===== FUN_08025274 @ 08025274 ===== */

undefined4 FUN_08025274(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  short local_30;
  ushort local_2e;
  undefined1 auStack_2c [28];
  
  iVar1 = DAT_08025330;
  uVar4 = 1;
  if (*(int *)(DAT_08025330 + 0xc) == 0) {
    return 1;
  }
  FUN_0802543c(*(undefined4 *)(DAT_08025330 + 8),0x1e,&local_30);
  if ((local_30 == 0xa5) && (uVar2 = FUN_0802e17c(iVar1,auStack_2c), local_2e == uVar2)) {
    FUN_0802498c(param_1,auStack_2c,0x1a);
    uVar4 = 0;
    local_30 = 0;
    FUN_08025544(*(undefined4 *)(iVar1 + 8),2,&local_30);
  }
  iVar3 = *(int *)(iVar1 + 8);
  uVar2 = iVar3 + 0x1e;
  *(uint *)(iVar1 + 8) = uVar2;
  if ((uVar2 & 0xfff) == 0) {
    if (0x1ffffff < uVar2) {
      *(uint *)(iVar1 + 8) = DAT_08025334;
    }
  }
  else {
    if (0x1d < 0x1000 - (uVar2 & 0xfff)) goto LAB_0802530c;
    uVar2 = iVar3 + 0x101e;
    if (0x1ffffff < uVar2) {
      uVar2 = DAT_08025334;
    }
    *(uint *)(iVar1 + 8) = uVar2 & 0xfffff000;
  }
  uVar2 = *(int *)(iVar1 + 8) - 0x1000;
  if ((int)uVar2 < (int)DAT_08025334) {
    uVar2 = *(int *)(iVar1 + 8) + 0x7cf000;
  }
  FUN_08025636(uVar2 & 0xfffff000);
LAB_0802530c:
  if (*(int *)(iVar1 + 8) == *(int *)(iVar1 + 4)) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(iVar1 + 0xc) + -0x1e;
  }
  *(int *)(iVar1 + 0xc) = iVar3;
  return uVar4;
}



/* ===== FUN_08025322 @ 08025322 ===== */

uint FUN_08025322(void)

{
  return -(uint)(*(int *)(DAT_08025330 + 0xc) == 0) >> 0x1f;
}



/* ===== FUN_08025338 @ 08025338 ===== */

uint FUN_08025338(uint param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_080257dc;
  *DAT_080257dc = *DAT_080257dc | param_1;
  return param_1 & *puVar1;
}



/* ===== FUN_08025350 @ 08025350 ===== */

void FUN_08025350(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  
  bVar2 = (byte)param_2;
  bVar3 = (byte)((uint)param_2 >> 8);
  bVar4 = (byte)((uint)param_2 >> 0x10);
  bVar1 = (byte)((uint)param_2 >> 0x18);
  uVar5 = (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1 |
                          bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                       bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18 |
          (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1 |
                          bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                       bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
          (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1 |
                          bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                       bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
          (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1 |
                          bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                       bVar1 >> 6 & 1) << 1 | bVar1 >> 7);
  *(uint *)(param_1 + 0xc) =
       param_3 << (LZCOUNT(uVar5) << 1) | *(uint *)(param_1 + 0xc) & ~(3 << (LZCOUNT(uVar5) << 1));
  return;
}



/* ===== FUN_08025374 @ 08025374 ===== */

void FUN_08025374(uint param_1)

{
  do {
  } while ((uint)(*DAT_080257e0 - *DAT_080257e0) < param_1);
  return;
}



/* ===== FUN_08025384 @ 08025384 ===== */

void FUN_08025384(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_080257e4;
  DAT_080257e4[4] = 0x1000;
  FUN_08025374(2);
  FUN_0802e21a(DAT_080257e8,param_1,0,0);
  FUN_08025374(2);
  *puVar1 = 0x1000;
  return;
}



/* ===== FUN_080253a8 @ 080253a8 ===== */

void FUN_080253a8(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_080257e4;
  DAT_080257e4[4] = 0x1000;
  FUN_08025374(2);
  FUN_0802e1e0(DAT_080257e8,5,param_1,1);
  FUN_08025374(2);
  *puVar1 = 0x1000;
  return;
}



/* ===== FUN_080253c4 @ 080253c4 ===== */

longlong FUN_080253c4(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint local_10;
  
  puVar2 = DAT_080257e4;
  local_10 = 0;
  DAT_080257e4[4] = 0x1000;
  FUN_08025374(2);
  FUN_0802e1e0(DAT_080257e8,0x9f,&local_10,3);
  FUN_08025374(2);
  *puVar2 = 0x1000;
  uVar3 = (local_10 & 0xff) << 0x10 | ((local_10 & 0xffffff) >> 8 & 0xff) << 8 |
          (local_10 & 0xffffff) >> 0x10;
  uVar1 = DAT_080257f0;
  if (uVar3 != DAT_080257f0) {
    uVar1 = DAT_080257f4;
  }
  if (uVar3 != DAT_080257f0 && uVar3 != uVar1) {
    return CONCAT44(uVar3,1);
  }
  return (ulonglong)uVar3 << 0x20;
}



/* ===== FUN_08025410 @ 08025410 ===== */

void FUN_08025410(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_080257e4;
  DAT_080257e4[4] = 0x1000;
  FUN_08025374(2);
  FUN_0802e1e0(DAT_080257e8,0x70,param_1,1);
  FUN_08025374(2);
  *puVar1 = 0x1000;
  return;
}



/* ===== FUN_0802543c @ 0802543c ===== */

undefined8 FUN_0802543c(uint param_1,int param_2,undefined1 *param_3)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined4 uStack_20;
  uint local_1c;
  
  uVar3 = DAT_080257e8;
  puVar1 = DAT_080257e4;
  if (param_2 != 0) {
    if (0x1ffffff < param_1) {
      uVar3 = 1;
      goto LAB_0802549c;
    }
    if (0x2000000 < param_2 + param_1) {
      uVar3 = 2;
      goto LAB_0802549c;
    }
    local_1c = param_1 << 0x18 | (param_1 >> 8 & 0xff) << 0x10 | (param_1 >> 0x10 & 0xff) << 8 |
               param_1 >> 0x18;
    DAT_080257e4[4] = 0x1000;
    FUN_08025374(2);
    FUN_0802e21a(uVar3,0x13,&local_1c,4);
    uVar2 = FUN_0802e1e0(uVar3,0xaa,param_3 + 1,param_2 + -1);
    *param_3 = uVar2;
    FUN_08025374(2);
    *puVar1 = 0x1000;
  }
  uVar3 = 0;
LAB_0802549c:
  return CONCAT44(uStack_20,uVar3);
}



/* ===== FUN_080254a0 @ 080254a0 ===== */

longlong FUN_080254a0(uint param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  
  iVar1 = 0;
  if (param_2 == 0) {
LAB_080254e2:
    return (ulonglong)param_4 << 0x20;
  }
  if (0x1ffffff < param_1) {
    return CONCAT44(param_4,3);
  }
  if (0x2000000 < param_2 + param_1) {
    return CONCAT44(param_4,4);
  }
  uVar3 = 0;
  if ((param_1 & 0xff) != 0) {
    uVar3 = 0x100 - (param_1 & 0xff);
    if (param_2 <= uVar3) {
      uVar3 = param_2;
    }
    iVar1 = FUN_08025544(param_1,uVar3);
    if (iVar1 != 0) goto LAB_08025542;
    if (uVar3 == param_2) goto LAB_080254e2;
  }
  param_1 = uVar3 + param_1;
  param_3 = param_3 + uVar3;
  uVar2 = uVar3 + 0x100;
  while (uVar2 <= param_2) {
    if ((((param_1 & 0xfff) == 0) && (iVar1 = FUN_08025636(param_1), iVar1 != 0)) ||
       (iVar1 = FUN_08025544(param_1,0x100,param_3), iVar1 != 0)) goto LAB_08025542;
    param_1 = param_1 + 0x100;
    param_3 = param_3 + 0x100;
    uVar2 = uVar3 + 0x200;
    uVar3 = uVar3 + 0x100;
  }
  if ((uVar3 < param_2) && (((param_1 & 0xfff) != 0 || (iVar1 = FUN_08025636(param_1), iVar1 == 0)))
     ) {
    lVar4 = FUN_08025544(param_1,param_2 - uVar3,param_3,param_4);
    return lVar4;
  }
LAB_08025542:
  return CONCAT44(param_4,iVar1);
}



/* ===== FUN_08025544 @ 08025544 ===== */

undefined8 FUN_08025544(uint param_1,int param_2,undefined1 *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_20;
  uint local_1c;
  
  local_1c = param_1;
  FUN_080253a8((int)&local_20 + 1);
  if (((int)((local_20 >> 8) << 0x1f) < 0) ||
     (iVar4 = FUN_080255e6(), uVar5 = DAT_080257e8, puVar2 = DAT_080257e4, iVar4 != 0)) {
    return CONCAT44(local_20,8);
  }
  local_1c = local_1c << 0x18 | (local_1c >> 8 & 0xff) << 0x10 | (local_1c >> 0x10 & 0xff) << 8 |
             local_1c >> 0x18;
  DAT_080257e4[4] = 0x1000;
  FUN_08025374(2);
  FUN_0802e21a(uVar5,0x12,&local_1c,4);
  FUN_0802e21a(uVar5,*param_3,param_3 + 1,param_2 + -1);
  FUN_08025374(2);
  piVar1 = DAT_080257e0;
  *puVar2 = 0x1000;
  uVar3 = DAT_080257ec;
  iVar4 = *piVar1;
  do {
    if (uVar3 <= (uint)(*piVar1 - iVar4)) {
      return CONCAT44(local_20,9);
    }
    FUN_080253a8((int)&local_20 + 1);
  } while ((int)((local_20 >> 8) << 0x1f) < 0);
  FUN_08025410(&local_20);
  FUN_08025384(0x50);
  if ((local_20 & 0x7e) == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = 10;
  }
  return CONCAT44(local_20,uVar5);
}



/* ===== FUN_080255e6 @ 080255e6 ===== */

longlong FUN_080255e6(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint local_20;
  undefined4 uStack_1c;
  
  local_20 = param_3;
  uStack_1c = param_4;
  FUN_08025384(6);
  uVar3 = DAT_080257e8;
  puVar2 = DAT_080257e4;
  piVar1 = DAT_080257e0;
  iVar4 = *DAT_080257e0;
  do {
    if (100 < (uint)(*piVar1 - iVar4)) {
      return CONCAT44(local_20,1);
    }
    puVar2[4] = 0x1000;
    FUN_08025374(2);
    FUN_0802e1e0(uVar3,5,&local_20,1);
    FUN_08025374(2);
    *puVar2 = 0x1000;
  } while (-1 < (int)(local_20 << 0x1e));
  return (ulonglong)local_20 << 0x20;
}



/* ===== FUN_08025636 @ 08025636 ===== */

longlong FUN_08025636(uint param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_18;
  uint local_14;
  
  if (0x1ffffff < param_1) {
    return CONCAT44(param_3,0xb);
  }
  local_18 = param_3;
  local_14 = param_4;
  FUN_080253a8((int)&local_18 + 1);
  if (((int)((local_18 >> 8) << 0x1f) < 0) ||
     (iVar4 = FUN_080255e6(), puVar2 = DAT_080257e4, iVar4 != 0)) {
    return CONCAT44(local_18,0xc);
  }
  local_14 = param_1 << 0x18 | (param_1 >> 8 & 0xff) << 0x10 | (param_1 >> 0x10 & 0xff) << 8 |
             param_1 >> 0x18;
  DAT_080257e4[4] = 0x1000;
  FUN_08025374(2);
  uVar3 = DAT_080257ec;
  FUN_0802e21a(DAT_080257e8,0x21,&local_14,4);
  FUN_08025374(2);
  *puVar2 = 0x1000;
  piVar1 = DAT_080257e0;
  iVar4 = *DAT_080257e0;
  do {
    if (uVar3 <= (uint)(*piVar1 - iVar4)) {
      return CONCAT44(local_18,0xd);
    }
    FUN_080253a8((int)&local_18 + 1);
  } while ((int)((local_18 >> 8) << 0x1f) < 0);
  FUN_08025410(&local_18);
  FUN_08025384(0x50);
  if ((local_18 & 0x7e) == 0) {
    return (ulonglong)local_18 << 0x20;
  }
  return CONCAT44(local_18,0xe);
}



/* ===== FUN_080256c4 @ 080256c4 ===== */

longlong FUN_080256c4(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_18 = param_3;
  uStack_14 = param_4;
  FUN_080253a8((int)&local_18 + 1);
  if (((int)((local_18 >> 8) << 0x1f) < 0) || (iVar3 = FUN_080255e6(), iVar3 != 0)) {
    return CONCAT44(local_18,0xf);
  }
  FUN_08025384(199);
  uVar2 = DAT_080257ec;
  piVar1 = DAT_080257e0;
  iVar3 = *DAT_080257e0;
  do {
    if (uVar2 <= (uint)(*piVar1 - iVar3)) {
      return CONCAT44(local_18,0x10);
    }
    FUN_080253a8((int)&local_18 + 1);
  } while ((int)((local_18 >> 8) << 0x1f) < 0);
  FUN_08025410(&local_18);
  FUN_08025384(0x50);
  if ((local_18 & 0x7e) == 0) {
    return (ulonglong)local_18 << 0x20;
  }
  return CONCAT44(local_18,0x11);
}



/* ===== FUN_08025726 @ 08025726 ===== */

void FUN_08025726(void)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_08025338(0x1000);
  uVar1 = DAT_080257fc;
  *DAT_080257e8 = *DAT_080257e8 | 0x40;
  FUN_08025350(uVar1,0x2000,0);
  FUN_08025350(uVar1,0x8000,0);
  FUN_08025384(0x66);
  FUN_08025384(0x99);
  do {
  } while ((uint)(*DAT_080257e0 - *DAT_080257e0) < 500);
  *(undefined4 *)(DAT_080257f8 + 4) = 0;
  FUN_0802578a();
  iVar2 = FUN_080253c4();
  if (iVar2 != 0) {
    FUN_08016ac0(1);
  }
  FUN_080257b6();
  return;
}



/* ===== FUN_0802578a @ 0802578a ===== */

undefined4 FUN_0802578a(void)

{
  undefined4 unaff_r7;
  
  FUN_08025338(0x1000);
  FUN_08025384(0xab);
  do {
  } while ((uint)(*DAT_080257e0 - *DAT_080257e0) < 0x32);
  FUN_08025384(0xb7);
  *(int *)(DAT_080257f8 + 4) = *(int *)(DAT_080257f8 + 4) + 1;
  return unaff_r7;
}



/* ===== FUN_080257b6 @ 080257b6 ===== */

undefined4 FUN_080257b6(void)

{
  int iVar1;
  undefined4 unaff_r7;
  
  if (*(int *)(DAT_080257f8 + 4) == 0) {
    return 0;
  }
  iVar1 = *(int *)(DAT_080257f8 + 4) + -1;
  *(int *)(DAT_080257f8 + 4) = iVar1;
  if (iVar1 == 0) {
    FUN_08025384(0xb9);
    *DAT_080257dc = *DAT_080257dc & 0xffffefff;
  }
  return unaff_r7;
}



/* ===== FUN_08025800 @ 08025800 ===== */

bool FUN_08025800(int *param_1,undefined4 param_2,undefined1 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[2];
  if (iVar1 == 0x20) {
    param_1[2] = 0x1f;
  }
  param_1[2] = param_1[2] + 1;
  iVar2 = param_1[1] + 1;
  if (0x1f < iVar2) {
    iVar2 = 0;
  }
  param_1[1] = iVar2;
  FUN_0802498c(iVar2 * 0x1a + *param_1,param_2,0x1a);
  iVar2 = *param_1 + param_1[1] * 0x1a;
  *(undefined1 *)(iVar2 + 8) = param_3;
  *(undefined1 *)(iVar2 + 9) = 0;
  return iVar1 == 0x20;
}



/* ===== FUN_080258ac @ 080258ac ===== */

undefined4 * FUN_080258ac(undefined4 *param_1)

{
  FUN_08018300();
  *param_1 = DAT_080258cc;
  *(undefined1 *)((int)param_1 + 0x9e) = 0;
  *(undefined1 *)((int)param_1 + 0x9d) = 0;
  *(undefined1 *)(param_1 + 0x27) = 0;
  param_1[0x28] = 0;
  *(undefined1 *)((int)param_1 + 0x9f) = 0;
  return param_1;
}



/* ===== FUN_080258d0 @ 080258d0 ===== */

void FUN_080258d0(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_080258f0;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 10) = 1;
  return;
}



/* ===== FUN_080259a0 @ 080259a0 ===== */

longlong FUN_080259a0(uint *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if ((int)param_1[0x404] < 1) {
    return (ulonglong)param_4 << 0x20;
  }
  iVar1 = param_1[0x403] - param_1[0x404];
  iVar2 = iVar1 + 1;
  if (iVar2 < 0) {
    iVar2 = iVar1 + 5;
  }
  piVar3 = *(int **)(param_1[0x402] + iVar2 * 4);
  (**(code **)(*piVar3 + 0x10))(piVar3,param_1);
  param_1[0x404] = param_1[0x404] - 1;
  return CONCAT44(param_4,~-(uint)(*param_1 < 500) >> 0x1f);
}



/* ===== FUN_080259e0 @ 080259e0 ===== */

void FUN_080259e0(int param_1,uint *param_2)

{
  int *piVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  
  piVar1 = (int *)(param_1 + 0x34);
  puVar3 = param_2 + 2;
  if (piVar1 < (int *)(param_1 + 0x1034U)) {
    for (; piVar1 < (int *)(param_1 + 0x1034U); piVar1 = piVar1 + 1) {
      *piVar1 = *puVar3 + *piVar1;
      puVar3 = puVar3 + 1;
    }
  }
  uVar4 = *(uint *)(param_1 + 0x10);
  uVar2 = *param_2;
  *(uint *)(param_1 + 0x10) = uVar4 + uVar2;
  *(uint *)(param_1 + 0x14) =
       ((int)uVar2 >> 0x1f) + *(int *)(param_1 + 0x14) + (uint)CARRY4(uVar4,uVar2);
  *(uint *)(param_1 + 0x28) = param_2[1] + *(int *)(param_1 + 0x28);
  return;
}



/* ===== FUN_08025a20 @ 08025a20 ===== */

void FUN_08025a20(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  FUN_08025ca4(param_1 + 2,0x1000);
  return;
}



/* ===== FUN_08025a30 @ 08025a30 ===== */

uint FUN_08025a30(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  
  uVar11 = param_4 & 0x80000000;
  if ((int)uVar11 < 0) {
    bVar13 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(uint)bVar13 - param_4;
  }
  uVar11 = uVar11 ^ (int)param_2 >> 0x20;
  if (uVar11 != 0) {
    if ((int)param_2 < 0) {
      bVar13 = param_1 != 0;
      param_1 = -param_1;
      param_2 = -(uint)bVar13 - param_2;
    }
    uVar1 = FUN_08025a74(param_1,param_2);
    if ((uVar11 & 0x80000000) != 0) {
      uVar1 = -uVar1;
    }
    return uVar1;
  }
  if (param_4 != 0) {
    if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
      return 0;
    }
    if (0xffff < param_4) {
      uVar1 = param_2 / param_4;
      param_2 = param_2 - param_4 * uVar1;
      uVar11 = (uint)((ulonglong)param_3 * (ulonglong)uVar1 >> 0x20);
      if (param_2 <= uVar11 &&
          (uint)((uint)((ulonglong)param_3 * (ulonglong)uVar1) <= param_1) <= param_2 - uVar11) {
        uVar1 = uVar1 - 1;
      }
      return uVar1;
    }
    uVar11 = LZCOUNT(param_4) - 0xf;
    uVar7 = LZCOUNT(param_4) - LZCOUNT(param_2);
    uVar1 = param_3 << (uVar11 & 0xff);
    uVar11 = 0x20 - uVar11 & 0x1f;
    uVar11 = ((param_4 ^ param_3) >> uVar11 | (param_4 ^ param_3) << 0x20 - uVar11) ^ uVar1;
    uVar10 = uVar7 - 0xf;
    if (uVar7 < 0xf || uVar10 == 0) {
LAB_08025b18:
      uVar7 = LZCOUNT(param_2) + -0xf + uVar7;
      uVar10 = param_1 << (uVar7 & 0xff);
      uVar7 = 0x20 - uVar7 & 0x1f;
      uVar7 = ((param_2 ^ param_1) >> uVar7 | (param_2 ^ param_1) << 0x20 - uVar7) ^ uVar10;
      uVar2 = uVar7 / uVar11;
      uVar7 = uVar7 - uVar11 * uVar2;
      uVar11 = (uint)((ulonglong)uVar1 * (ulonglong)uVar2 >> 0x20);
      if (uVar7 <= uVar11 &&
          (uint)((uint)((ulonglong)uVar1 * (ulonglong)uVar2) <= uVar10) <= uVar7 - uVar11) {
        uVar2 = uVar2 - 1;
      }
      return uVar2;
    }
LAB_08025ba6:
    uVar2 = param_1 << LZCOUNT(param_2);
    uVar7 = 0x20U - LZCOUNT(param_2) & 0x1f;
    uVar3 = ((param_2 ^ param_1) >> uVar7 | (param_2 ^ param_1) << 0x20 - uVar7) ^ uVar2;
    uVar12 = uVar3 / uVar11;
    uVar3 = uVar3 - uVar11 * uVar12;
    uVar5 = (uint)((ulonglong)uVar1 * (ulonglong)uVar12);
    uVar8 = (uint)((ulonglong)uVar1 * (ulonglong)uVar12 >> 0x20);
    uVar7 = uVar2 - uVar5;
    uVar4 = (uVar3 - uVar8) - (uint)(uVar5 > uVar2);
    if (uVar3 <= uVar8 && (uint)(uVar5 <= uVar2) <= uVar3 - uVar8) {
      uVar12 = uVar12 - 1;
      bVar13 = CARRY4(uVar7,uVar1);
      uVar7 = uVar7 + uVar1;
      uVar4 = uVar4 + uVar11 + (uint)bVar13;
    }
    if (0xe < uVar10) {
      uVar10 = uVar10 - 0xf;
      uVar3 = uVar4 << 0xf | uVar7 >> 0x11;
      uVar9 = uVar3 / uVar11;
      uVar3 = uVar3 - uVar11 * uVar9;
      uVar5 = (uint)((ulonglong)uVar1 * (ulonglong)uVar9);
      uVar8 = (uint)((ulonglong)uVar1 * (ulonglong)uVar9 >> 0x20);
      uVar2 = uVar7 * 0x8000;
      uVar7 = uVar2 - uVar5;
      uVar4 = (uVar3 - uVar8) - (uint)(uVar5 > uVar2);
      if (uVar3 <= uVar8 && (uint)(uVar5 <= uVar2) <= uVar3 - uVar8) {
        uVar9 = uVar9 - 1;
        bVar13 = CARRY4(uVar7,uVar1);
        uVar7 = uVar7 + uVar1;
        uVar4 = uVar4 + uVar11 + (uint)bVar13;
      }
      uVar12 = uVar9 | uVar12 << 0xf;
    }
    if (uVar10 == 0) {
      return uVar12;
    }
    uVar3 = uVar7 << (uVar10 & 0xff);
    uVar2 = 0x20 - uVar10 & 0x1f;
    uVar7 = ((uVar4 ^ uVar7) >> uVar2 | (uVar4 ^ uVar7) << 0x20 - uVar2) ^ uVar3;
    uVar2 = uVar7 / uVar11;
    uVar7 = uVar7 - uVar11 * uVar2;
    uVar11 = (uint)((ulonglong)uVar1 * (ulonglong)uVar2 >> 0x20);
    if (uVar7 <= uVar11 &&
        (uint)((uint)((ulonglong)uVar1 * (ulonglong)uVar2) <= uVar3) <= uVar7 - uVar11) {
      uVar2 = uVar2 - 1;
    }
    return uVar12 << (uVar10 & 0xff) | uVar2;
  }
  if (param_2 == 0) {
    if (2 < param_3) {
      return param_1 / param_3;
    }
  }
  else {
    if (0xffff < param_3) {
      if (param_3 < 0x1000000) {
        uVar1 = (param_2 - param_3 * (param_2 / param_3)) * 0x100 | param_1 >> 0x18;
        uVar7 = uVar1 / param_3;
        uVar11 = uVar7 | param_1 << 8;
        uVar1 = (uVar1 - param_3 * uVar7) * 0x100 | uVar11 >> 0x18;
        uVar7 = uVar1 / param_3;
        uVar11 = uVar7 | uVar11 << 8;
        uVar1 = (uVar1 - param_3 * uVar7) * 0x100 | uVar11 >> 0x18;
        uVar7 = uVar1 / param_3;
        uVar11 = uVar7 | uVar11 << 8;
        return ((uVar1 - param_3 * uVar7) * 0x100 | uVar11 >> 0x18) / param_3 | uVar11 << 8;
      }
      uVar1 = 0xf - LZCOUNT(param_3);
      iVar6 = LZCOUNT(param_3) - LZCOUNT(param_2);
      uVar11 = param_3 >> (uVar1 & 0xff);
      uVar1 = uVar1 & 0x1f;
      uVar7 = iVar6 + 0x20;
      uVar1 = (param_3 >> uVar1 | param_3 << 0x20 - uVar1) ^ uVar11;
      uVar10 = iVar6 + 0x11;
      if (uVar7 < 0xf || uVar10 == 0) goto LAB_08025b18;
      goto LAB_08025ba6;
    }
    if (2 < param_3) {
      uVar11 = (param_2 - param_3 * (param_2 / param_3)) * 0x10000 | param_1 >> 0x10;
      uVar1 = uVar11 / param_3;
      return (param_1 & 0xffff | (uVar11 - param_3 * uVar1) * 0x10000) / param_3 | uVar1 << 0x10;
    }
  }
  if (param_3 == 0) {
    return param_1;
  }
  if (param_3 == 2) {
    return (uint)((param_2 & 1) != 0) << 0x1f | param_1 >> 1;
  }
  return param_1;
}



/* ===== FUN_08025a74 @ 08025a74 ===== */

ulonglong FUN_08025a74(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  
  if (param_4 != 0) {
    if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
      return 0;
    }
    if (0xffff < param_4) {
      uVar11 = param_2 / param_4;
      param_2 = param_2 - param_4 * uVar11;
      uVar4 = (uint)((ulonglong)param_3 * (ulonglong)uVar11 >> 0x20);
      if (param_2 <= uVar4 &&
          (uint)((uint)((ulonglong)param_3 * (ulonglong)uVar11) <= param_1) <= param_2 - uVar4) {
        uVar11 = uVar11 - 1;
      }
      return (ulonglong)uVar11;
    }
    uVar4 = LZCOUNT(param_4) - 0xf;
    uVar7 = LZCOUNT(param_4) - LZCOUNT(param_2);
    uVar11 = param_3 << (uVar4 & 0xff);
    uVar4 = 0x20 - uVar4 & 0x1f;
    uVar4 = ((param_4 ^ param_3) >> uVar4 | (param_4 ^ param_3) << 0x20 - uVar4) ^ uVar11;
    uVar10 = uVar7 - 0xf;
    if (uVar7 < 0xf || uVar10 == 0) {
LAB_08025b18:
      uVar7 = LZCOUNT(param_2) + -0xf + uVar7;
      uVar10 = param_1 << (uVar7 & 0xff);
      uVar7 = 0x20 - uVar7 & 0x1f;
      uVar7 = ((param_2 ^ param_1) >> uVar7 | (param_2 ^ param_1) << 0x20 - uVar7) ^ uVar10;
      uVar1 = uVar7 / uVar4;
      uVar7 = uVar7 - uVar4 * uVar1;
      uVar4 = (uint)((ulonglong)uVar11 * (ulonglong)uVar1 >> 0x20);
      if (uVar7 <= uVar4 &&
          (uint)((uint)((ulonglong)uVar11 * (ulonglong)uVar1) <= uVar10) <= uVar7 - uVar4) {
        uVar1 = uVar1 - 1;
      }
      return (ulonglong)uVar1;
    }
LAB_08025ba6:
    uVar1 = param_1 << LZCOUNT(param_2);
    uVar7 = 0x20U - LZCOUNT(param_2) & 0x1f;
    uVar2 = ((param_2 ^ param_1) >> uVar7 | (param_2 ^ param_1) << 0x20 - uVar7) ^ uVar1;
    uVar12 = uVar2 / uVar4;
    uVar2 = uVar2 - uVar4 * uVar12;
    uVar5 = (uint)((ulonglong)uVar11 * (ulonglong)uVar12);
    uVar8 = (uint)((ulonglong)uVar11 * (ulonglong)uVar12 >> 0x20);
    uVar7 = uVar1 - uVar5;
    uVar3 = (uVar2 - uVar8) - (uint)(uVar5 > uVar1);
    if (uVar2 <= uVar8 && (uint)(uVar5 <= uVar1) <= uVar2 - uVar8) {
      uVar12 = uVar12 - 1;
      bVar13 = CARRY4(uVar7,uVar11);
      uVar7 = uVar7 + uVar11;
      uVar3 = uVar3 + uVar4 + (uint)bVar13;
    }
    if (0xe < uVar10) {
      uVar10 = uVar10 - 0xf;
      uVar2 = uVar3 << 0xf | uVar7 >> 0x11;
      uVar9 = uVar2 / uVar4;
      uVar2 = uVar2 - uVar4 * uVar9;
      uVar5 = (uint)((ulonglong)uVar11 * (ulonglong)uVar9);
      uVar8 = (uint)((ulonglong)uVar11 * (ulonglong)uVar9 >> 0x20);
      uVar1 = uVar7 * 0x8000;
      uVar7 = uVar1 - uVar5;
      uVar3 = (uVar2 - uVar8) - (uint)(uVar5 > uVar1);
      if (uVar2 <= uVar8 && (uint)(uVar5 <= uVar1) <= uVar2 - uVar8) {
        uVar9 = uVar9 - 1;
        bVar13 = CARRY4(uVar7,uVar11);
        uVar7 = uVar7 + uVar11;
        uVar3 = uVar3 + uVar4 + (uint)bVar13;
      }
      uVar12 = uVar9 | uVar12 << 0xf;
    }
    if (uVar10 == 0) {
      return (ulonglong)uVar12;
    }
    uVar2 = uVar7 << (uVar10 & 0xff);
    uVar1 = 0x20 - uVar10 & 0x1f;
    uVar7 = ((uVar3 ^ uVar7) >> uVar1 | (uVar3 ^ uVar7) << 0x20 - uVar1) ^ uVar2;
    uVar1 = uVar7 / uVar4;
    uVar7 = uVar7 - uVar4 * uVar1;
    uVar4 = (uint)((ulonglong)uVar11 * (ulonglong)uVar1 >> 0x20);
    if (uVar7 <= uVar4 &&
        (uint)((uint)((ulonglong)uVar11 * (ulonglong)uVar1) <= uVar2) <= uVar7 - uVar4) {
      uVar1 = uVar1 - 1;
    }
    return CONCAT44(uVar12 >> (0x20 - uVar10 & 0xff),uVar12 << (uVar10 & 0xff) | uVar1);
  }
  if (param_2 == 0) {
    if (2 < param_3) {
      return (ulonglong)(param_1 / param_3);
    }
  }
  else {
    if (0xffff < param_3) {
      if (param_3 < 0x1000000) {
        uVar11 = (param_2 - param_3 * (param_2 / param_3)) * 0x100 | param_1 >> 0x18;
        uVar7 = uVar11 / param_3;
        uVar4 = uVar7 | param_1 << 8;
        uVar11 = (uVar11 - param_3 * uVar7) * 0x100 | uVar4 >> 0x18;
        uVar7 = uVar11 / param_3;
        uVar4 = uVar7 | uVar4 << 8;
        uVar11 = (uVar11 - param_3 * uVar7) * 0x100 | uVar4 >> 0x18;
        uVar7 = uVar11 / param_3;
        uVar4 = uVar7 | uVar4 << 8;
        return CONCAT44(param_2 / param_3,
                        ((uVar11 - param_3 * uVar7) * 0x100 | uVar4 >> 0x18) / param_3 | uVar4 << 8)
        ;
      }
      uVar11 = 0xf - LZCOUNT(param_3);
      iVar6 = LZCOUNT(param_3) - LZCOUNT(param_2);
      uVar4 = param_3 >> (uVar11 & 0xff);
      uVar11 = uVar11 & 0x1f;
      uVar7 = iVar6 + 0x20;
      uVar11 = (param_3 >> uVar11 | param_3 << 0x20 - uVar11) ^ uVar4;
      uVar10 = iVar6 + 0x11;
      if (uVar7 < 0xf || uVar10 == 0) goto LAB_08025b18;
      goto LAB_08025ba6;
    }
    if (2 < param_3) {
      uVar4 = (param_2 - param_3 * (param_2 / param_3)) * 0x10000 | param_1 >> 0x10;
      uVar11 = uVar4 / param_3;
      return CONCAT44(param_2 / param_3,
                      (param_1 & 0xffff | (uVar4 - param_3 * uVar11) * 0x10000) / param_3 |
                      uVar11 << 0x10);
    }
  }
  if (param_3 == 0) {
    return CONCAT44(param_2,param_1);
  }
  if (param_3 == 2) {
    return CONCAT44(param_2 >> 1,(uint)((param_2 & 1) != 0) << 0x1f | param_1 >> 1);
  }
  return CONCAT44(param_2,param_1);
}



/* ===== FUN_08025ca4 @ 08025ca4 ===== */

undefined4 * FUN_08025ca4(int param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = (undefined4 *)(param_1 + param_2);
  uVar3 = (uint)puVar1 & 3;
  if (uVar3 != 0) {
    uVar2 = param_2 - uVar3;
    if (param_2 < uVar3) {
      if (uVar2 + uVar3 != 0) {
        puVar1 = (undefined4 *)((int)puVar1 + -1);
        *(undefined1 *)puVar1 = 0;
      }
      if (((uVar2 + uVar3) * 0x40000000 & 0x80000000) != 0) {
        puVar1 = (undefined4 *)((int)puVar1 + -1);
        *(undefined1 *)puVar1 = 0;
      }
      return puVar1;
    }
    uVar3 = (uint)puVar1 & 2;
    if ((int)puVar1 * -0x80000000 < 0) {
      puVar1 = (undefined4 *)((int)puVar1 + -1);
      *(undefined1 *)puVar1 = 0;
    }
    param_2 = uVar2;
    if (uVar3 != 0) {
      puVar1 = (undefined4 *)((int)puVar1 + -2);
      *(undefined2 *)puVar1 = 0;
    }
  }
  do {
    uVar3 = param_2;
    if (0xf < uVar3) {
      puVar1[-1] = 0;
      puVar1[-2] = 0;
      puVar1[-3] = 0;
      puVar1[-4] = 0;
      puVar1 = puVar1 + -4;
    }
    param_2 = uVar3 - 0x10;
  } while (0xf < uVar3 && uVar3 - 0x10 != 0);
  if ((uVar3 & 8) != 0) {
    puVar1[-1] = 0;
    puVar1[-2] = 0;
    puVar1 = puVar1 + -2;
  }
  if ((int)(uVar3 << 0x1d) < 0) {
    puVar1 = puVar1 + -1;
    *puVar1 = 0;
  }
  if ((uVar3 & 2) != 0) {
    puVar1 = (undefined4 *)((int)puVar1 + -2);
    *(undefined2 *)puVar1 = 0;
  }
  if ((int)(uVar3 << 0x1f) < 0) {
    puVar1 = (undefined4 *)((int)puVar1 + -1);
    *(undefined1 *)puVar1 = 0;
  }
  return puVar1;
}



/* ===== FUN_08025caa @ 08025caa ===== */

void FUN_08025caa(int *param_1)

{
  if ((char)param_1[2] == '\0') {
    *(undefined1 *)((int)param_1 + 9) = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[3] = 0;
                    /* WARNING: Could not recover jumptable at 0x08025cbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0xc))();
    return;
  }
  return;
}



/* ===== FUN_08025cc0 @ 08025cc0 ===== */

void FUN_08025cc0(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_08025f68;
  if (0 < param_1) {
    do {
      *puVar1 = *param_2;
      param_1 = param_1 + -1;
      param_2 = param_2 + 1;
    } while (param_1 != 0);
  }
  return;
}



/* ===== FUN_08025cd2 @ 08025cd2 ===== */

undefined4 FUN_08025cd2(int param_1,uint *param_2,int *param_3)

{
  byte bVar1;
  bool bVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int *piVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  uint *puVar12;
  
  if (param_1 != 0) {
    return 0x18;
  }
  FUN_0802578a();
  iVar5 = DAT_08025f6c;
  iVar4 = FUN_0802543c(DAT_08025f6c,0x30,param_2);
  FUN_080257b6();
  if (iVar4 != 0) {
    return 2;
  }
  bVar1 = *(byte *)((int)param_2 + 6);
  if (bVar1 != 0) {
    if (bVar1 == 2) {
      if (0x3f4 < (ushort)param_2[1]) {
        return 0x17;
      }
      FUN_0802578a();
      puVar3 = DAT_08025f70;
      iVar5 = FUN_0802543c(DAT_08025f74,(uint)(ushort)param_2[1] << 2,DAT_08025f70);
      bVar2 = false;
      if (iVar5 == 0) {
        iVar5 = FUN_0802543c(DAT_08025f78,0x1000,param_3 + 0x400);
        uVar11 = 0;
        if (iVar5 == 0) goto LAB_08025df4;
      }
      uVar11 = 2;
      bVar2 = true;
LAB_08025df4:
      FUN_080257b6();
      if (bVar2) {
        return uVar11;
      }
      FUN_0802e2c0();
      puVar12 = DAT_08025f68;
      *DAT_08025f68 = param_2[1];
      iVar5 = 5;
      puVar8 = param_2;
      do {
        *puVar12 = puVar8[2];
        iVar5 = iVar5 + -1;
        *puVar12 = puVar8[3];
        puVar8 = puVar8 + 2;
      } while (iVar5 != 0);
      FUN_08025cc0((short)param_2[1],puVar3);
      puVar8 = (uint *)(param_3 + 0x400);
      iVar5 = 0x100;
      do {
        *puVar12 = *puVar8;
        iVar5 = iVar5 + -1;
        *puVar12 = puVar8[1];
        puVar6 = puVar8 + 3;
        *puVar12 = puVar8[2];
        puVar8 = puVar8 + 4;
        *puVar12 = *puVar6;
      } while (iVar5 != 0);
      uVar10 = *puVar12;
      if (uVar10 == 0xffffffff) {
        uVar10 = 0;
      }
      if (uVar10 != *param_2) {
        return 0x19;
      }
      iVar5 = FUN_080266ec(param_3,puVar3,0x400);
      if (iVar5 < 0) {
        return 0x1a;
      }
      return uVar11;
    }
    if (1 < bVar1) {
      return 0x18;
    }
    if (bVar1 != 0) {
      if (bVar1 != 1) {
        return 0x17;
      }
      iVar4 = 0x28;
      goto LAB_08025d16;
    }
  }
  iVar4 = 0x20;
LAB_08025d16:
  if ((short)param_2[1] != 0x200) {
    return 0x17;
  }
  FUN_0802578a();
  FUN_0802e2c0();
  puVar3 = DAT_08025f70;
  iVar5 = FUN_0802543c(iVar5 + iVar4,0x800,DAT_08025f70);
  if (iVar5 == 0) {
    FUN_08025cc0(iVar4 - 4U >> 2,param_2 + 1);
    puVar12 = DAT_08025f68;
    iVar5 = 0x80;
    puVar8 = puVar3;
    do {
      *puVar12 = *puVar8;
      iVar5 = iVar5 + -1;
      *puVar12 = puVar8[1];
      puVar6 = puVar8 + 3;
      *puVar12 = puVar8[2];
      puVar8 = puVar8 + 4;
      *puVar12 = *puVar6;
    } while (iVar5 != 0);
    uVar10 = *puVar12;
    if (uVar10 == 0xffffffff) {
      uVar10 = 0;
    }
    uVar11 = 0;
    if (uVar10 != *param_2) {
      uVar11 = 0x19;
    }
  }
  else {
    uVar11 = 2;
  }
  FUN_080257b6();
  puVar12 = puVar3;
  do {
    piVar7 = param_3 + 4;
    puVar8 = puVar12 + 1;
    uVar9 = *puVar12;
    uVar10 = uVar9 & 3;
    if (param_3 < piVar7) {
      for (; param_3 < piVar7; param_3 = param_3 + 1) {
        *param_3 = (uint)(0 < (int)uVar10) + (uVar9 >> 2);
        uVar10 = uVar10 - 1;
      }
    }
    puVar12 = puVar8;
  } while (puVar8 < puVar3 + 0x200);
  return uVar11;
}



/* ===== FUN_08025e76 @ 08025e76 ===== */

undefined8 FUN_08025e76(uint param_1,int *param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  bool bVar8;
  
  iVar4 = DAT_08025f70;
  bVar8 = param_1 == 0;
  if (bVar8) {
    param_1 = (uint)*(byte *)((int)param_2 + 6);
  }
  if (!bVar8 || param_1 != 2) {
    return CONCAT44(param_4,0x17);
  }
  iVar3 = FUN_0802667c(DAT_08025f70,param_3,0x400);
  if (iVar3 == 0) {
    iVar3 = 0x17;
  }
  else {
    uVar6 = (iVar3 - iVar4) + 3 >> 2;
    if (uVar6 < 0x3f5) {
      *(short *)(param_2 + 1) = (short)uVar6;
      FUN_0802578a();
      uVar2 = DAT_08025f6c;
      iVar3 = FUN_08025636(DAT_08025f6c);
      if ((iVar3 == 0) && (iVar3 = FUN_080254a0(DAT_08025f74,uVar6 << 2,iVar4), iVar3 == 0)) {
        piVar7 = (int *)(param_3 + 0x1000);
        iVar3 = FUN_080254a0(DAT_08025f78,0x1000,piVar7);
        if ((iVar3 == 0) && (iVar3 = FUN_08025544(DAT_08025f7c,0x2c,param_2 + 1), iVar3 == 0)) {
          FUN_0802e2c0();
          piVar1 = DAT_08025f68;
          *DAT_08025f68 = param_2[1];
          iVar3 = 5;
          piVar5 = param_2;
          do {
            *piVar1 = piVar5[2];
            iVar3 = iVar3 + -1;
            *piVar1 = piVar5[3];
            piVar5 = piVar5 + 2;
          } while (iVar3 != 0);
          FUN_08025cc0(uVar6,iVar4);
          iVar4 = 0x100;
          do {
            *piVar1 = *piVar7;
            iVar4 = iVar4 + -1;
            *piVar1 = piVar7[1];
            piVar5 = piVar7 + 3;
            *piVar1 = piVar7[2];
            piVar7 = piVar7 + 4;
            *piVar1 = *piVar5;
          } while (iVar4 != 0);
          iVar4 = *piVar1;
          if (iVar4 == -1) {
            iVar4 = 0;
          }
          *param_2 = iVar4;
          iVar3 = FUN_08025544(uVar2,4,param_2);
        }
      }
      FUN_080257b6();
    }
    else {
      iVar3 = 4;
    }
  }
  return CONCAT44(param_4,iVar3);
}



/* ===== FUN_08025f80 @ 08025f80 ===== */

undefined4 FUN_08025f80(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  undefined8 uVar7;
  
  FUN_080190e2();
  uVar7 = FUN_080190aa();
  *(undefined8 *)(param_1 + 8) = uVar7;
  iVar1 = *(uint *)(param_1 + 0x18) + *(uint *)(param_1 + 0x10);
  iVar3 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x14) +
          (uint)CARRY4(*(uint *)(param_1 + 0x18),*(uint *)(param_1 + 0x10));
  *(int *)(param_1 + 0x18) = iVar1;
  *(int *)(param_1 + 0x1c) = iVar3;
  *(int *)(param_1 + 0x20) = iVar1;
  *(int *)(param_1 + 0x24) = iVar3;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  iVar1 = *(int *)(param_1 + 0x28) + *(int *)(param_1 + 0x2c);
  *(int *)(param_1 + 0x2c) = iVar1;
  *(int *)(param_1 + 0x30) = iVar1;
  piVar2 = (int *)(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x28) = 0;
  piVar6 = (int *)(param_1 + 0x2034);
  piVar4 = (int *)(param_1 + 0x1034);
  piVar5 = piVar4;
  if (piVar2 < piVar4) {
    for (; piVar2 < piVar4; piVar2 = piVar2 + 1) {
      iVar1 = *piVar5;
      iVar3 = *piVar2;
      *piVar5 = iVar3 + iVar1;
      *piVar6 = iVar3 + iVar1;
      *piVar2 = 0;
      piVar5 = piVar5 + 1;
      piVar6 = piVar6 + 1;
    }
  }
  return param_4;
}



/* ===== FUN_08026000 @ 08026000 ===== */

void FUN_08026000(int param_1)

{
  if (*(char *)(param_1 + 9) != '\0') {
    *(undefined1 *)(param_1 + 9) = 0;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) * 0x7d >> 7;
  }
  return;
}



/* ===== FUN_08026014 @ 08026014 ===== */

void FUN_08026014(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x100c) + 1;
  if (3 < iVar1) {
    iVar1 = 0;
  }
  *(int *)(param_1 + 0x100c) = iVar1;
  *(int *)(param_1 + 0x1010) = *(int *)(param_1 + 0x1010) + 1;
  *(undefined4 *)(*(int *)(param_1 + 0x1008) + *(int *)(param_1 + 0x100c) * 4) = param_2;
  return;
}



/* ===== FUN_08026036 @ 08026036 ===== */

void FUN_08026036(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 auStack_40 [6];
  undefined1 local_3a;
  undefined1 local_39;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  
  if (*param_1 != '\0') {
    local_39 = 0;
    local_20 = *(undefined4 *)(param_1 + 0x18);
    local_1c = *(undefined4 *)(param_1 + 0x1c);
    local_28 = *(undefined4 *)(param_1 + 0x10);
    local_24 = *(undefined4 *)(param_1 + 0x14);
    local_38 = *(undefined4 *)(param_1 + 8);
    local_34 = *(undefined4 *)(param_1 + 0xc);
    uStack_10 = param_4;
    FUN_080190e2();
    local_30 = FUN_080190aa();
    local_18 = 0;
    local_14 = 0;
    local_3a = 2;
    FUN_08025e76(param_2,auStack_40,param_1 + 0x34);
  }
  return;
}



/* ===== FUN_08026090 @ 08026090 ===== */

void FUN_08026090(int param_1,undefined2 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x1c) = param_3;
  *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(param_1 + 0xe);
  *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(param_1 + 0x10);
  *(undefined2 *)(param_1 + 0x10) = param_2;
  return;
}



/* ===== FUN_080260ae @ 080260ae ===== */

undefined4 * FUN_080260ae(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = param_2 + 3;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  if (param_2 < puVar1) {
    for (; param_2 < puVar1; param_2 = param_2 + 1) {
      FUN_0802e2f8(param_1,*param_2);
    }
  }
  return param_2;
}



/* ===== FUN_080260d4 @ 080260d4 ===== */

undefined4 FUN_080260d4(int param_1)

{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  ushort uVar4;
  byte bVar5;
  
  bVar5 = (byte)*(ushort *)(param_1 + 0xc);
  if (bVar5 == 5) {
    uVar3 = 6;
  }
  else {
    bVar1 = (byte)*(ushort *)(param_1 + 0xe);
    if (bVar1 != 5) {
      if (bVar5 < bVar1) {
        bVar5 = bVar1;
      }
      bVar1 = (byte)*(undefined2 *)(param_1 + 0x10);
      if ((bVar1 != 5) && (bVar5 < bVar1)) {
        bVar5 = bVar1;
      }
    }
    if (bVar5 == 0) {
      return 0;
    }
    if (bVar5 == 1) {
      return 1;
    }
    uVar4 = *(ushort *)(param_1 + 0xc) >> 8;
    uVar2 = *(ushort *)(param_1 + 0xe) >> 8;
    if (uVar2 != 5) {
      if (uVar4 < uVar2) {
        uVar4 = uVar2;
      }
      uVar2 = *(ushort *)(param_1 + 0x10) >> 8;
      if ((uVar2 != 5) && (uVar4 < uVar2)) {
        uVar4 = uVar2;
      }
    }
    if (uVar4 == 1) {
      return 2;
    }
    if (uVar4 != 0) {
      if (uVar4 == 3) {
        return 4;
      }
      if (uVar4 < 3) {
        return 3;
      }
    }
    uVar3 = 5;
  }
  return uVar3;
}



/* ===== FUN_08026158 @ 08026158 ===== */

uint FUN_08026158(int param_1)

{
  if (*(byte *)(param_1 + 0xc) != 1) {
    if (1 < *(byte *)(param_1 + 0xc)) {
      return 1;
    }
    if ((char)*(undefined2 *)(param_1 + 0xe) == '\0') {
      return -(uint)((char)*(undefined2 *)(param_1 + 0x10) == '\0') >> 0x1f;
    }
  }
  return 0;
}



/* ===== FUN_0802617a @ 0802617a ===== */

undefined4 FUN_0802617a(int param_1)

{
  ushort uVar1;
  bool bVar2;
  
  uVar1 = *(ushort *)(param_1 + 0xc) & 0xff;
  bVar2 = uVar1 != 0;
  if (!bVar2) {
    uVar1 = *(ushort *)(param_1 + 0xe) & 0xff;
  }
  if (((bVar2 || uVar1 != 0) || ((char)*(undefined2 *)(param_1 + 0x10) != '\0')) &&
     (*(ushort *)(param_1 + 0xc) >> 8 == 1)) {
    return 0;
  }
  return 1;
}



/* ===== FUN_0802619e @ 0802619e ===== */

undefined4 FUN_0802619e(int param_1)

{
  ushort uVar1;
  byte bVar2;
  
  bVar2 = (byte)*(ushort *)(param_1 + 0xc);
  if (bVar2 < 2) {
    bVar2 = *(byte *)(param_1 + 0xe);
  }
  if (bVar2 < 2) {
    bVar2 = *(byte *)(param_1 + 0x10);
  }
  if (1 < bVar2) {
    uVar1 = *(ushort *)(param_1 + 0xc) >> 8;
    if (uVar1 == 2) {
      return 0;
    }
    if (uVar1 < 3) {
      uVar1 = *(ushort *)(param_1 + 0xe) >> 8;
      if (uVar1 < 2) {
        uVar1 = *(ushort *)(param_1 + 0x10) >> 8;
      }
      if (1 < uVar1) {
        return 0;
      }
    }
  }
  return 1;
}



/* ===== FUN_080261d0 @ 080261d0 ===== */

undefined4 FUN_080261d0(int param_1)

{
  ushort uVar1;
  byte bVar2;
  
  bVar2 = (byte)*(ushort *)(param_1 + 0xc);
  if (bVar2 < 2) {
    bVar2 = *(byte *)(param_1 + 0xe);
  }
  if (bVar2 < 2) {
    bVar2 = *(byte *)(param_1 + 0x10);
  }
  if (1 < bVar2) {
    uVar1 = *(ushort *)(param_1 + 0xc) >> 8;
    if (uVar1 == 3) {
      return 0;
    }
    if (uVar1 < 4) {
      uVar1 = *(ushort *)(param_1 + 0xe) >> 8;
      if (uVar1 < 3) {
        uVar1 = *(ushort *)(param_1 + 0x10) >> 8;
      }
      if (2 < uVar1) {
        return 0;
      }
    }
  }
  return 1;
}



/* ===== FUN_08026202 @ 08026202 ===== */

undefined4 FUN_08026202(int param_1)

{
  ushort uVar1;
  byte bVar2;
  bool bVar3;
  
  bVar2 = (byte)*(ushort *)(param_1 + 0xc);
  if (bVar2 != 5) {
    if (bVar2 < 2) {
      bVar2 = *(byte *)(param_1 + 0xe);
    }
    if (bVar2 < 2) {
      bVar2 = *(byte *)(param_1 + 0x10);
    }
    if (1 < bVar2) {
      uVar1 = *(ushort *)(param_1 + 0xc) >> 8;
      bVar3 = uVar1 == 4;
      if (!bVar3) {
        uVar1 = *(ushort *)(param_1 + 0xe) >> 8;
      }
      if ((bVar3 || uVar1 == 4) || (3 < *(ushort *)(param_1 + 0x10) >> 8)) {
        return 0;
      }
    }
  }
  return 1;
}



/* ===== FUN_08026236 @ 08026236 ===== */

void FUN_08026236(undefined4 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort *puVar5;
  int iVar6;
  uint *puVar7;
  
  puVar5 = (ushort *)*param_1;
  *puVar5 = (ushort)(param_2 << 4) | 6;
  puVar7 = (uint *)param_1[1];
  do {
    iVar1 = param_2 + -1;
    if (param_2 < 4) {
      FUN_08026090(param_1,0x505,0);
    }
    else {
      uVar2 = *puVar7;
      if (uVar2 == 0) {
        uVar3 = 0;
      }
      else if (uVar2 < 0x100) {
        uVar3 = 1;
      }
      else {
        uVar3 = 4;
      }
      iVar6 = uVar2 - param_1[7];
      if (iVar6 < 0) {
        iVar6 = -iVar6;
      }
      if (iVar6 < 0x80) {
        uVar4 = 0x100;
      }
      else if (iVar6 < 0x8000) {
        uVar4 = 0x200;
      }
      else if (iVar6 < 0x800000) {
        uVar4 = 0x300;
      }
      else {
        uVar4 = 0x400;
      }
      param_1[2] = param_1[5];
      param_1[5] = param_1[6];
      puVar7 = puVar7 + 1;
      param_1[6] = param_1[7];
      param_1[7] = uVar2;
      *(undefined2 *)(param_1 + 3) = *(undefined2 *)((int)param_1 + 0xe);
      *(undefined2 *)((int)param_1 + 0xe) = *(undefined2 *)(param_1 + 4);
      *(ushort *)(param_1 + 4) = uVar3 | uVar4;
    }
    param_2 = iVar1;
  } while ((char)*(undefined2 *)(param_1 + 3) == '\0');
  *puVar5 = (*puVar5 & 0xfff0) + (short)iVar1 * -0x10;
  *param_1 = puVar5 + 1;
  param_1[1] = puVar7;
  return;
}



/* ===== FUN_080262e8 @ 080262e8 ===== */

void FUN_080262e8(undefined4 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort *puVar5;
  int iVar6;
  ushort *puVar7;
  ushort *puVar8;
  uint *puVar9;
  
  puVar5 = (ushort *)*param_1;
  *puVar5 = (ushort)(param_2 << 4) | 6;
  puVar9 = (uint *)param_1[1];
  puVar7 = puVar5 + 1;
  do {
    puVar8 = (ushort *)((int)puVar7 + 1);
    *(char *)puVar7 = (char)param_1[5];
    iVar1 = param_2 + -1;
    if (param_2 < 4) {
      FUN_08026090(param_1,0x505,0);
    }
    else {
      uVar2 = *puVar9;
      if (uVar2 == 0) {
        uVar3 = 0;
      }
      else if (uVar2 < 0x100) {
        uVar3 = 1;
      }
      else {
        uVar3 = 4;
      }
      iVar6 = uVar2 - param_1[7];
      if (iVar6 < 0) {
        iVar6 = -iVar6;
      }
      if (iVar6 < 0x80) {
        uVar4 = 0x100;
      }
      else if (iVar6 < 0x8000) {
        uVar4 = 0x200;
      }
      else if (iVar6 < 0x800000) {
        uVar4 = 0x300;
      }
      else {
        uVar4 = 0x400;
      }
      param_1[2] = param_1[5];
      param_1[5] = param_1[6];
      puVar9 = puVar9 + 1;
      param_1[6] = param_1[7];
      param_1[7] = uVar2;
      *(undefined2 *)(param_1 + 3) = *(undefined2 *)((int)param_1 + 0xe);
      *(undefined2 *)((int)param_1 + 0xe) = *(undefined2 *)(param_1 + 4);
      *(ushort *)(param_1 + 4) = uVar3 | uVar4;
    }
    iVar6 = FUN_08026158(param_1);
    puVar7 = puVar8;
    param_2 = iVar1;
  } while (iVar6 == 0);
  *puVar5 = (*puVar5 & 0xfff0 | 1) + (short)iVar1 * -0x10;
  *param_1 = puVar8;
  param_1[1] = puVar9;
  return;
}



/* ===== FUN_0802639a @ 0802639a ===== */

void FUN_0802639a(undefined4 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort *puVar5;
  int iVar6;
  ushort *puVar7;
  ushort *puVar8;
  uint *puVar9;
  
  puVar5 = (ushort *)*param_1;
  *puVar5 = (ushort)(param_2 << 4) | 6;
  puVar9 = (uint *)param_1[1];
  puVar7 = puVar5 + 1;
  do {
    puVar8 = (ushort *)((int)puVar7 + 1);
    *(char *)puVar7 = (char)param_1[5] - (char)param_1[2];
    iVar1 = param_2 + -1;
    if (param_2 < 4) {
      FUN_08026090(param_1,0x505,0);
    }
    else {
      uVar2 = *puVar9;
      if (uVar2 == 0) {
        uVar3 = 0;
      }
      else if (uVar2 < 0x100) {
        uVar3 = 1;
      }
      else {
        uVar3 = 4;
      }
      iVar6 = uVar2 - param_1[7];
      if (iVar6 < 0) {
        iVar6 = -iVar6;
      }
      if (iVar6 < 0x80) {
        uVar4 = 0x100;
      }
      else if (iVar6 < 0x8000) {
        uVar4 = 0x200;
      }
      else if (iVar6 < 0x800000) {
        uVar4 = 0x300;
      }
      else {
        uVar4 = 0x400;
      }
      param_1[2] = param_1[5];
      param_1[5] = param_1[6];
      puVar9 = puVar9 + 1;
      param_1[6] = param_1[7];
      param_1[7] = uVar2;
      *(undefined2 *)(param_1 + 3) = *(undefined2 *)((int)param_1 + 0xe);
      *(undefined2 *)((int)param_1 + 0xe) = *(undefined2 *)(param_1 + 4);
      *(ushort *)(param_1 + 4) = uVar3 | uVar4;
    }
    iVar6 = FUN_0802617a(param_1);
    puVar7 = puVar8;
    param_2 = iVar1;
  } while (iVar6 == 0);
  *puVar5 = (*puVar5 & 0xfff0 | 2) + (short)iVar1 * -0x10;
  *param_1 = puVar8;
  param_1[1] = puVar9;
  return;
}



/* ===== FUN_0802645c @ 0802645c ===== */

void FUN_0802645c(undefined4 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort *puVar5;
  int iVar6;
  ushort *puVar7;
  ushort *puVar8;
  uint *puVar9;
  
  puVar5 = (ushort *)*param_1;
  *puVar5 = (ushort)(param_2 << 4) | 6;
  puVar9 = (uint *)param_1[1];
  puVar7 = puVar5 + 1;
  do {
    puVar8 = puVar7 + 1;
    *puVar7 = (short)param_1[5] - (short)param_1[2];
    iVar1 = param_2 + -1;
    if (param_2 < 4) {
      FUN_08026090(param_1,0x505,0);
    }
    else {
      uVar2 = *puVar9;
      if (uVar2 == 0) {
        uVar3 = 0;
      }
      else if (uVar2 < 0x100) {
        uVar3 = 1;
      }
      else {
        uVar3 = 4;
      }
      iVar6 = uVar2 - param_1[7];
      if (iVar6 < 0) {
        iVar6 = -iVar6;
      }
      if (iVar6 < 0x80) {
        uVar4 = 0x100;
      }
      else if (iVar6 < 0x8000) {
        uVar4 = 0x200;
      }
      else if (iVar6 < 0x800000) {
        uVar4 = 0x300;
      }
      else {
        uVar4 = 0x400;
      }
      param_1[2] = param_1[5];
      param_1[5] = param_1[6];
      puVar9 = puVar9 + 1;
      param_1[6] = param_1[7];
      param_1[7] = uVar2;
      *(undefined2 *)(param_1 + 3) = *(undefined2 *)((int)param_1 + 0xe);
      *(undefined2 *)((int)param_1 + 0xe) = *(undefined2 *)(param_1 + 4);
      *(ushort *)(param_1 + 4) = uVar3 | uVar4;
    }
    iVar6 = FUN_0802619e(param_1);
    puVar7 = puVar8;
    param_2 = iVar1;
  } while (iVar6 == 0);
  *puVar5 = (*puVar5 & 0xfff0 | 3) + (short)iVar1 * -0x10;
  *param_1 = puVar8;
  param_1[1] = puVar9;
  return;
}



/* ===== FUN_08026512 @ 08026512 ===== */

void FUN_08026512(undefined4 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort *puVar5;
  int iVar6;
  ushort *puVar7;
  ushort *puVar8;
  uint *puVar9;
  
  puVar5 = (ushort *)*param_1;
  *puVar5 = (ushort)(param_2 << 4) | 6;
  puVar9 = (uint *)param_1[1];
  puVar7 = puVar5 + 1;
  do {
    puVar8 = (ushort *)((int)puVar7 + 3);
    *(undefined4 *)puVar7 = param_1[5] - param_1[2];
    iVar1 = param_2 + -1;
    if (param_2 < 4) {
      FUN_08026090(param_1,0x505,0);
    }
    else {
      uVar2 = *puVar9;
      if (uVar2 == 0) {
        uVar3 = 0;
      }
      else if (uVar2 < 0x100) {
        uVar3 = 1;
      }
      else {
        uVar3 = 4;
      }
      iVar6 = uVar2 - param_1[7];
      if (iVar6 < 0) {
        iVar6 = -iVar6;
      }
      if (iVar6 < 0x80) {
        uVar4 = 0x100;
      }
      else if (iVar6 < 0x8000) {
        uVar4 = 0x200;
      }
      else if (iVar6 < 0x800000) {
        uVar4 = 0x300;
      }
      else {
        uVar4 = 0x400;
      }
      param_1[2] = param_1[5];
      param_1[5] = param_1[6];
      puVar9 = puVar9 + 1;
      param_1[6] = param_1[7];
      param_1[7] = uVar2;
      *(undefined2 *)(param_1 + 3) = *(undefined2 *)((int)param_1 + 0xe);
      *(undefined2 *)((int)param_1 + 0xe) = *(undefined2 *)(param_1 + 4);
      *(ushort *)(param_1 + 4) = uVar3 | uVar4;
    }
    iVar6 = FUN_080261d0(param_1);
    puVar7 = puVar8;
    param_2 = iVar1;
  } while (iVar6 == 0);
  *puVar5 = (*puVar5 & 0xfff0 | 4) + (short)iVar1 * -0x10;
  *param_1 = puVar8;
  param_1[1] = puVar9;
  return;
}



/* ===== FUN_080265c8 @ 080265c8 ===== */

void FUN_080265c8(undefined4 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort *puVar5;
  int iVar6;
  ushort *puVar7;
  ushort *puVar8;
  uint *puVar9;
  
  puVar5 = (ushort *)*param_1;
  *puVar5 = (ushort)(param_2 << 4) | 6;
  puVar9 = (uint *)param_1[1];
  puVar7 = puVar5 + 1;
  do {
    puVar8 = puVar7 + 2;
    *(undefined4 *)puVar7 = param_1[5];
    iVar1 = param_2 + -1;
    if (param_2 < 4) {
      FUN_08026090(param_1,0x505,0);
    }
    else {
      uVar2 = *puVar9;
      if (uVar2 == 0) {
        uVar3 = 0;
      }
      else if (uVar2 < 0x100) {
        uVar3 = 1;
      }
      else {
        uVar3 = 4;
      }
      iVar6 = uVar2 - param_1[7];
      if (iVar6 < 0) {
        iVar6 = -iVar6;
      }
      if (iVar6 < 0x80) {
        uVar4 = 0x100;
      }
      else if (iVar6 < 0x8000) {
        uVar4 = 0x200;
      }
      else if (iVar6 < 0x800000) {
        uVar4 = 0x300;
      }
      else {
        uVar4 = 0x400;
      }
      param_1[2] = param_1[5];
      param_1[5] = param_1[6];
      puVar9 = puVar9 + 1;
      param_1[6] = param_1[7];
      param_1[7] = uVar2;
      *(undefined2 *)(param_1 + 3) = *(undefined2 *)((int)param_1 + 0xe);
      *(undefined2 *)((int)param_1 + 0xe) = *(undefined2 *)(param_1 + 4);
      *(ushort *)(param_1 + 4) = uVar3 | uVar4;
    }
    iVar6 = FUN_08026202(param_1);
    puVar7 = puVar8;
    param_2 = iVar1;
  } while (iVar6 == 0);
  *puVar5 = (*puVar5 & 0xfff0 | 5) + (short)iVar1 * -0x10;
  *param_1 = puVar8;
  param_1[1] = puVar9;
  return;
}



/* ===== FUN_0802667c @ 0802667c ===== */

longlong FUN_0802667c(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_080267d4;
  *DAT_080267d4 = param_1;
  uVar2 = FUN_080260ae(puVar1);
  puVar1[1] = uVar2;
  do {
    uVar2 = FUN_080260d4(puVar1);
    switch(uVar2) {
    case 0:
      param_3 = FUN_08026236(puVar1,param_3);
      break;
    case 1:
      param_3 = FUN_080262e8(puVar1,param_3);
      break;
    case 2:
      param_3 = FUN_0802639a(puVar1,param_3);
      break;
    case 3:
      param_3 = FUN_0802645c(puVar1,param_3);
      break;
    case 4:
      param_3 = FUN_08026512(puVar1,param_3);
      break;
    case 5:
      param_3 = FUN_080265c8(puVar1,param_3);
      break;
    case 6:
      return CONCAT44(param_4,*puVar1);
    default:
      return (ulonglong)param_4 << 0x20;
    }
  } while( true );
}



/* ===== FUN_080266ec @ 080266ec ===== */

undefined4 FUN_080266ec(int param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  iVar2 = DAT_080267d8;
  *(undefined4 *)(DAT_080267d8 + 4) = 0;
  *(undefined4 *)(iVar2 + 8) = param_2;
  if (param_3 < 1) {
    return 0;
  }
  puVar3 = *(ushort **)(iVar2 + 8);
  *(ushort **)(iVar2 + 8) = puVar3 + 1;
  uVar1 = *puVar3;
  uVar4 = (uint)(uVar1 >> 4);
  if ((uVar4 != 0) && (-1 < (int)(param_3 - uVar4))) {
    uVar6 = uVar1 & 0xf;
    if (uVar6 < 6) {
                    /* WARNING: Could not recover jumptable at 0x08026718. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar5 = (*(code *)(&switchD_08026718::switchdataD_0802671c +
                        (uint)(&switchD_08026718::switchdataD_0802671c)[uVar6] * 2))
                        (param_1 + uVar4 * 4);
      return uVar5;
    }
  }
  return 0xffffffff;
}



/* ===== FUN_080267dc @ 080267dc ===== */

undefined4 FUN_080267dc(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  piVar1 = DAT_080269bc;
  if (param_1 == 0) {
    param_1 = FUN_08026a50(*(undefined4 *)(*DAT_080269bc + 0xc));
  }
  iVar3 = *piVar1;
  uVar5 = (uint)*(byte *)(iVar3 + 5);
  uVar6 = (uint)*(byte *)(iVar3 + 3);
  if ((int)uVar6 < (int)(param_1 + uVar5)) {
    if ((int)((uint)*(byte *)(iVar3 + 0x10) << 0x1e) < 0) {
      if ((*DAT_080269c0 != '\0') || (uVar6 <= uVar5)) {
        return 1;
      }
      *(byte *)(iVar3 + 5) = (char)param_1 + *(byte *)(iVar3 + 5);
    }
    else {
      if (*DAT_080269c0 == '\0') {
        param_1 = (param_1 + uVar5) - uVar6;
        *(byte *)(iVar3 + 5) = *(byte *)(iVar3 + 3);
      }
      puVar2 = (undefined1 *)*piVar1;
      if ((int)((uint)(byte)puVar2[0x10] << 0x1f) < 0) {
        uVar4 = 0xffff;
      }
      else {
        uVar4 = 0;
      }
      FUN_0802e354(*puVar2,puVar2[1],puVar2[2],puVar2[3],param_1 & 0xff,uVar4,param_4);
    }
  }
  else {
    FUN_0802ad48();
    *(char *)(*piVar1 + 5) = (char)param_1 + *(char *)(*piVar1 + 5);
  }
  ((undefined1 *)*piVar1)[4] = *(undefined1 *)*piVar1;
  return 0;
}



/* ===== FUN_08026858 @ 08026858 ===== */

void FUN_08026858(void)

{
  int *piVar1;
  
  piVar1 = DAT_080269bc;
  *DAT_080269c4 = 0;
  *DAT_080269c0 = (byte)((ushort)*(undefined2 *)(*piVar1 + 0x10) >> 8) & 1 ^ 1;
  return;
}



/* ===== FUN_0802689e @ 0802689e ===== */

uint FUN_0802689e(int param_1)

{
  return ((uint)((ulonglong)(param_1 - (uint)*(byte *)*DAT_080269bc & 0xff) *
                 (ulonglong)DAT_080269c8 + (ulonglong)DAT_080269c8 >> 0x24) + 1) * 0x15 +
         (uint)*(byte *)*DAT_080269bc & 0xff;
}



/* ===== FUN_080268c2 @ 080268c2 ===== */

undefined4 FUN_080268c2(int param_1)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  char cVar7;
  undefined4 uVar8;
  byte *pbVar9;
  
  piVar2 = DAT_080269bc;
  if (param_1 != 10 && param_1 != 0xd) {
    pbVar9 = (byte *)*DAT_080269bc;
    if (param_1 == 9) {
      uVar3 = FUN_0802689e(pbVar9[4]);
      if (uVar3 != *pbVar9) {
        iVar4 = FUN_08026a50(*(undefined4 *)(pbVar9 + 0xc));
        iVar5 = *piVar2;
        bVar6 = *(byte *)(iVar5 + 1);
        if ((int)((uint)*(byte *)(iVar5 + 0x10) << 0x1f) < 0) {
          uVar8 = 0xffff;
        }
        else {
          uVar8 = 0;
        }
        bVar1 = *(byte *)(iVar5 + 5);
        if ((int)(iVar4 + (uint)bVar6) <= (int)(uint)bVar1) {
          bVar6 = (bVar1 - (char)iVar4) + 1;
        }
        FUN_08026a64(*(undefined1 *)(iVar5 + 4),bVar6,uVar3,(uint)bVar1,uVar8);
        *(char *)(*piVar2 + 4) = (char)uVar3;
      }
    }
    else {
      iVar4 = FUN_08026a50(*(undefined4 *)(pbVar9 + 0xc));
      iVar5 = *piVar2;
      if (*(byte *)(iVar5 + 2) < *(byte *)(iVar5 + 4)) {
        *(byte *)(iVar5 + 4) = *(byte *)(iVar5 + 2) + 1;
      }
      else {
        pbVar9 = (byte *)FUN_080269cc(param_1,*(undefined4 *)(iVar5 + 0xc),
                                      *(undefined4 *)(iVar5 + 8));
        if (pbVar9 != (byte *)0x0) {
          iVar5 = *piVar2;
          bVar6 = *pbVar9;
          if ((-1 < (int)((uint)*(ushort *)(iVar5 + 0x10) << 0x16)) &&
             ((uint)*(byte *)(iVar5 + 2) < ((uint)bVar6 + (uint)*(byte *)(iVar5 + 4)) - 1)) {
            return 1;
          }
          uVar8 = FUN_0801fb7c(*(undefined4 *)(iVar5 + 0xc));
          iVar5 = *piVar2;
          bVar1 = *(byte *)(iVar5 + 5);
          if ((int)((uint)bVar1 - (uint)*(byte *)(iVar5 + 1)) < iVar4) {
            cVar7 = *(byte *)(iVar5 + 1) + ((char)iVar4 - bVar1) + -1;
          }
          else {
            cVar7 = '\0';
          }
          FUN_0802e698(*(undefined1 *)(iVar5 + 4),(bVar1 + 1) - iVar4 & 0xff,
                       *(undefined1 *)(iVar5 + 2),*(undefined1 *)(iVar5 + 3),pbVar9,cVar7,uVar8);
          iVar4 = *piVar2;
          if ((uint)*(byte *)(iVar4 + 2) < (uint)bVar6 + (uint)*(byte *)(iVar4 + 4)) {
            *(byte *)(iVar4 + 4) = *(byte *)(iVar4 + 2);
          }
          else {
            *(byte *)(iVar4 + 4) = bVar6 + *(byte *)(iVar4 + 4);
          }
        }
      }
    }
  }
  return 0;
}



/* ===== FUN_080269cc @ 080269cc ===== */

longlong FUN_080269cc(uint param_1,int param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint unaff_lr;
  
  if (param_3 == (uint *)0x0) {
    uVar1 = FUN_0801fb84(param_2);
    if (param_1 <= uVar1) {
LAB_08026a1c:
      return CONCAT44(param_4,*(int *)(param_2 + 4) +
                              (ushort)(*(short *)(param_2 + 2) + 2) * param_1);
    }
  }
  else if (*param_3 != 0) {
    do {
      uVar5 = 0;
      uVar1 = *param_3;
      do {
        while( true ) {
          uVar2 = uVar1 >> 1;
          iVar3 = uVar2 + (uVar5 & 0xffff);
          uVar4 = param_3[iVar3 * 3 + 2];
          if (uVar4 <= param_1) {
            unaff_lr = param_3[iVar3 * 3 + 3];
          }
          if (uVar4 <= param_1 && param_1 <= unaff_lr) {
            param_1 = (param_3[iVar3 * 3 + 4] + param_1) - uVar4;
            goto LAB_08026a1c;
          }
          if (uVar2 == 0) goto LAB_080269e6;
          if (uVar4 <= param_1) break;
          uVar1 = uVar2;
        }
        uVar1 = uVar1 - uVar2;
        uVar5 = uVar5 + uVar2;
      } while (uVar1 != 0);
LAB_080269e6:
      if (param_1 == param_3[1]) break;
      param_1 = param_3[1];
    } while( true );
  }
  return (ulonglong)param_4 << 0x20;
}



/* ===== FUN_08026a38 @ 08026a38 ===== */

undefined8 FUN_08026a38(undefined4 param_1)

{
  byte *pbVar1;
  uint uVar2;
  undefined4 unaff_r7;
  
  pbVar1 = (byte *)FUN_080269cc(param_1,*(undefined4 *)(*DAT_08026a4c + 0xc),
                                *(undefined4 *)(*DAT_08026a4c + 8));
  uVar2 = 0;
  if (pbVar1 != (byte *)0x0) {
    uVar2 = (uint)*pbVar1;
  }
  return CONCAT44(unaff_r7,uVar2);
}



/* ===== FUN_08026a50 @ 08026a50 ===== */

undefined1 FUN_08026a50(int param_1)

{
  if (param_1 == 0) {
    return *(undefined1 *)(DAT_08026a60 + 1);
  }
  if (param_1 == 0) {
    param_1 = DAT_0801fb90;
  }
  return *(undefined1 *)(param_1 + 1);
}



/* ===== FUN_08026a64 @ 08026a64 ===== */

void FUN_08026a64(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  int iVar7;
  byte bVar8;
  uint uVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  uint uVar13;
  byte bVar14;
  uint uVar15;
  byte bVar16;
  uint uVar17;
  uint uVar18;
  
  uVar15 = (uint)*DAT_08026c20;
  uVar17 = (uint)*DAT_08026c28;
  uVar13 = (uint)*DAT_08026c2c;
  uVar9 = (uint)*DAT_08026c30;
  *DAT_08026c24 = 0;
  puVar6 = DAT_08026c34;
  pbVar4 = DAT_08026c28;
  uVar18 = param_1;
  if (uVar13 < uVar17) {
LAB_08026a9c:
    uVar17 = uVar18;
    uVar13 = param_1;
  }
  else if ((int)param_1 < (int)uVar17) {
    uVar17 = param_1;
  }
  else {
    uVar18 = uVar17;
    if ((int)uVar13 < (int)param_1) goto LAB_08026a9c;
  }
  uVar18 = param_2;
  if (uVar15 < uVar9) {
LAB_08026ab4:
    uVar9 = uVar18;
    uVar15 = param_2;
  }
  else if ((int)param_2 < (int)uVar9) {
    uVar9 = param_2;
  }
  else {
    uVar18 = uVar9;
    if ((int)uVar15 < (int)param_2) goto LAB_08026ab4;
  }
  uVar18 = param_3;
  if (uVar13 < uVar17) {
LAB_08026acc:
    bVar16 = (byte)uVar18;
    uVar13 = param_3;
  }
  else {
    bVar16 = (byte)uVar17;
    if ((int)param_3 < (int)uVar17) {
      bVar16 = (byte)param_3;
    }
    else {
      uVar18 = uVar17;
      if ((int)uVar13 < (int)param_3) goto LAB_08026acc;
    }
  }
  bVar12 = (byte)uVar13;
  uVar13 = param_4;
  if (uVar9 <= uVar15) {
    bVar8 = (byte)uVar9;
    if ((int)param_4 < (int)uVar9) {
      bVar8 = (byte)param_4;
      goto LAB_08026ae6;
    }
    uVar13 = uVar9;
    if ((int)param_4 <= (int)uVar15) goto LAB_08026ae6;
  }
  bVar8 = (byte)uVar13;
  uVar15 = param_4;
LAB_08026ae6:
  bVar14 = (byte)uVar15;
  uVar9 = param_3;
  if (param_5 != 0) {
    uVar9 = 0xffff;
  }
  uVar2 = (undefined1)param_5;
  if (param_5 == 0 || param_5 == uVar9) {
    *DAT_08026c34 = uVar2;
    uVar3 = (undefined1)(param_5 >> 8);
    puVar6[1] = uVar3;
    puVar6[2] = uVar2;
    puVar6[3] = uVar3;
    puVar6[4] = uVar2;
    puVar6[5] = uVar3;
    puVar6[6] = uVar2;
    puVar6[7] = uVar3;
  }
  else {
    *DAT_08026c2c = bVar12;
    *pbVar4 = bVar16;
    *DAT_08026c20 = bVar14;
    *DAT_08026c30 = bVar8;
    FUN_0802ae94(DAT_08026c34,0,param_5 & 0xff);
    FUN_0802ae94(DAT_08026c34,1,param_5 >> 8);
    FUN_0802ae94(DAT_08026c34,2,param_5 & 0xff);
    FUN_0802ae94(DAT_08026c34,3,param_5 >> 8);
    FUN_0802ae94(DAT_08026c34,4,param_5 & 0xff);
    FUN_0802ae94(DAT_08026c34,5,param_5 >> 8);
    FUN_0802ae94(DAT_08026c34,6,param_5 & 0xff);
    FUN_0802ae94(DAT_08026c34,7,param_5 >> 8);
    bVar14 = *DAT_08026c20;
    bVar8 = *DAT_08026c30;
    bVar16 = *DAT_08026c28;
    bVar12 = *DAT_08026c2c;
  }
  bVar1 = *(byte *)(DAT_08026c38 + (param_4 & 7));
  bVar10 = *(byte *)(DAT_08026c3c + (param_2 & 7));
  for (param_2 = param_2 >> 3; iVar7 = DAT_08026c40, pbVar5 = DAT_08026c28, pbVar4 = DAT_08026c20,
      uVar9 = param_4 >> 3 & 0xff, param_2 <= uVar9; param_2 = param_2 + 1 & 0xff) {
    uVar13 = param_1 & 0xff;
    if (param_2 == uVar9) {
      bVar10 = bVar10 & bVar1;
    }
    uVar9 = param_1 + param_2 * 0x80;
    if (uVar13 <= param_3) {
      do {
        bVar11 = DAT_08026c34[uVar13 & 7];
        if (bVar10 != 0xff) {
          bVar11 = bVar11 & bVar10 | ~bVar10 & *(byte *)(iVar7 + (uVar9 & 0xffff));
        }
        *(byte *)(iVar7 + (uVar9 & 0xffff)) = bVar11;
        uVar13 = uVar13 + 1;
        uVar9 = uVar9 + 1;
      } while ((uVar13 & 0xff) <= param_3);
    }
    bVar10 = 0xff;
  }
  *DAT_08026c2c = bVar12;
  *pbVar5 = bVar16;
  *pbVar4 = bVar14;
  *DAT_08026c30 = bVar8;
  return;
}



/* ===== FUN_08026c44 @ 08026c44 ===== */

undefined1
FUN_08026c44(undefined1 param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,
            undefined1 param_5,int param_6,undefined4 param_7,int param_8,undefined4 param_9,
            undefined2 param_10,undefined2 param_11)

{
  int iVar1;
  undefined1 local_148 [4];
  undefined2 local_144;
  undefined2 local_142;
  undefined1 *local_13c;
  uint local_138;
  undefined1 *local_134;
  undefined4 local_130;
  undefined1 local_12c;
  undefined2 local_12b;
  undefined2 local_129;
  undefined1 local_127;
  undefined1 local_126;
  undefined1 local_125;
  undefined1 uStack_124;
  undefined2 auStack_123 [125];
  undefined4 uStack_28;
  
  local_127 = (undefined1)param_4;
  local_126 = param_5;
  local_125 = (undefined1)param_6;
  local_148[0] = 0;
  local_12c = param_1;
  local_12b = param_2;
  local_129 = param_3;
  uStack_28 = param_4;
  FUN_0802e734(&uStack_124,param_7,param_6);
  *(char *)((int)auStack_123 + param_6 + -1) = (char)param_8;
  iVar1 = param_8 + param_6 + -300;
  FUN_0802e734((int)auStack_123 + param_6,param_9,param_8);
  *(undefined2 *)((int)auStack_123 + iVar1 + 300) = param_10;
  *(undefined2 *)((int)auStack_123 + iVar1 + 0x12e) = param_11;
  FUN_0802e740(&local_144,0,0x18);
  local_144 = 0x3f;
  local_142 = 0x83;
  local_13c = &local_12c;
  local_130 = 1;
  local_138 = param_8 + param_6 + 0xdU & 0xff;
  local_134 = local_148;
  iVar1 = FUN_0802720c(&local_144,0);
  if (iVar1 < 0) {
    local_148[0] = 0xff;
  }
  return local_148[0];
}



/* ===== FUN_08026cea @ 08026cea ===== */

undefined1
FUN_08026cea(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
            undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined4 param_8,
            undefined1 param_9)

{
  int iVar1;
  undefined1 local_138 [4];
  undefined2 local_134;
  undefined2 local_132;
  undefined1 *local_12c;
  undefined4 local_128;
  undefined1 *local_124;
  undefined4 local_120;
  undefined1 local_11c;
  undefined1 local_11b;
  undefined1 local_11a;
  undefined1 local_119;
  undefined1 local_118;
  undefined1 local_117;
  undefined1 local_116;
  undefined4 local_115;
  undefined1 local_111;
  
  local_115 = param_8;
  local_138[0] = 0;
  local_118 = param_5;
  local_117 = param_6;
  local_116 = param_7;
  local_111 = param_9;
  local_11c = param_1;
  local_11b = param_2;
  local_11a = param_3;
  local_119 = param_4;
  FUN_0802e740(&local_134,0,0x18);
  local_132 = 0x86;
  local_134 = 0x3f;
  local_128 = 0xc;
  local_12c = &local_11c;
  local_120 = 1;
  local_124 = local_138;
  iVar1 = FUN_0802720c(&local_134,0);
  if (iVar1 < 0) {
    local_138[0] = 0xff;
  }
  return local_138[0];
}



/* ===== FUN_08026d62 @ 08026d62 ===== */

char FUN_08026d62(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined2 *param_4,
                 undefined2 *param_5,undefined2 *param_6)

{
  int iVar1;
  char local_138;
  undefined2 local_137;
  undefined2 local_135;
  undefined2 local_133;
  undefined2 local_130;
  undefined2 local_12e;
  undefined1 *local_128;
  undefined4 local_124;
  undefined1 *local_120;
  undefined4 local_11c;
  undefined1 local_118;
  undefined1 local_117;
  undefined1 local_116;
  
  FUN_0802e740(&local_138,0,7);
  local_118 = param_1;
  local_117 = param_2;
  local_116 = param_3;
  FUN_0802e740(&local_130,0,0x18);
  local_12e = 0x8a;
  local_130 = 0x3f;
  local_124 = 3;
  local_128 = &local_118;
  local_11c = 7;
  local_120 = &local_138;
  iVar1 = FUN_0802720c(&local_130,0);
  if (iVar1 < 0) {
    local_138 = -1;
  }
  else if (local_138 == '\0') {
    *param_4 = local_137;
    *param_5 = local_135;
    *param_6 = local_133;
    local_138 = '\0';
  }
  return local_138;
}



/* ===== FUN_08026dda @ 08026dda ===== */

undefined1 FUN_08026dda(undefined1 param_1)

{
  int iVar1;
  undefined1 local_128 [4];
  undefined2 local_124;
  undefined2 local_122;
  undefined1 *local_11c;
  undefined4 local_118;
  undefined1 *local_114;
  undefined4 local_110;
  undefined1 local_10c [260];
  
  local_128[0] = 0;
  local_10c[0] = param_1;
  FUN_0802e740(&local_124,0,0x18);
  local_124 = 0x3f;
  local_122 = 0x8f;
  local_11c = local_10c;
  local_118 = 1;
  local_110 = 1;
  local_114 = local_128;
  iVar1 = FUN_0802720c(&local_124,0);
  if (iVar1 < 0) {
    local_128[0] = 0xff;
  }
  return local_128[0];
}



/* ===== FUN_08026e28 @ 08026e28 ===== */

int FUN_08026e28(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 *local_1c;
  undefined4 *local_18;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_18 = &uStack_8;
  local_1c = param_1;
  uStack_8 = param_3;
  uStack_4 = param_4;
  iVar1 = FUN_0802129c((int)&DAT_08026e64 + DAT_08026e64,&local_1c,param_2,&local_18,0);
  *local_1c = 0;
  if (-1 < iVar1) {
    iVar1 = (int)local_1c - (int)param_1;
  }
  return iVar1;
}



/* ===== FUN_08026e68 @ 08026e68 ===== */

char FUN_08026e68(undefined1 *param_1,undefined2 *param_2,undefined1 *param_3,undefined2 *param_4,
                 undefined2 *param_5)

{
  int iVar1;
  char local_38;
  undefined1 local_37;
  undefined2 local_36;
  undefined1 local_34;
  undefined2 local_33;
  undefined2 local_31;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined1 *local_1c;
  undefined4 local_18;
  
  FUN_0802e740(&local_38,0,9);
  FUN_0802e740(&local_2c,0,0x18);
  local_2a = 1;
  local_2c = 4;
  local_18 = 9;
  local_1c = &local_38;
  iVar1 = FUN_0802720c(&local_2c,0);
  if (iVar1 < 0) {
    local_38 = -1;
  }
  else if (local_38 == '\0') {
    *param_1 = local_37;
    *param_2 = local_36;
    *param_3 = local_34;
    *param_4 = local_33;
    *param_5 = local_31;
    local_38 = '\0';
  }
  return local_38;
}



/* ===== FUN_08026ed8 @ 08026ed8 ===== */

undefined1 FUN_08026ed8(undefined1 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_128 [4];
  undefined2 local_124;
  undefined2 local_122;
  undefined1 *local_11c;
  undefined4 local_118;
  undefined1 *local_114;
  undefined4 local_110;
  undefined1 local_10c;
  undefined1 auStack_10b [259];
  
  local_128[0] = 0;
  local_10c = param_1;
  FUN_0802e734(auStack_10b,param_2,0x1f);
  FUN_0802e740(&local_124,0,0x18);
  local_124 = 8;
  local_122 = 8;
  local_118 = 0x20;
  local_11c = &local_10c;
  local_110 = 1;
  local_114 = local_128;
  iVar1 = FUN_0802720c(&local_124,0);
  if (iVar1 < 0) {
    local_128[0] = 0xff;
  }
  return local_128[0];
}



/* ===== FUN_08026f2a @ 08026f2a ===== */

undefined1 FUN_08026f2a(undefined1 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_128 [4];
  undefined2 local_124;
  undefined2 local_122;
  undefined1 *local_11c;
  undefined4 local_118;
  undefined1 *local_114;
  undefined4 local_110;
  undefined1 local_10c;
  undefined1 auStack_10b [259];
  
  local_128[0] = 0;
  local_10c = param_1;
  FUN_0802e734(auStack_10b,param_2,0x1f);
  FUN_0802e740(&local_124,0,0x18);
  local_122 = 9;
  local_124 = 8;
  local_118 = 0x20;
  local_11c = &local_10c;
  local_110 = 1;
  local_114 = local_128;
  iVar1 = FUN_0802720c(&local_124,0);
  if (iVar1 < 0) {
    local_128[0] = 0xff;
  }
  return local_128[0];
}



/* ===== FUN_08026f7e @ 08026f7e ===== */

undefined1 FUN_08026f7e(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  int iVar1;
  undefined1 local_128 [4];
  undefined2 local_124;
  undefined2 local_122;
  undefined1 *local_11c;
  undefined4 local_118;
  undefined1 *local_114;
  undefined4 local_110;
  undefined1 local_10c;
  undefined1 local_10b;
  undefined1 local_10a;
  
  local_128[0] = 0;
  local_10c = param_1;
  local_10b = param_2;
  local_10a = param_3;
  FUN_0802e740(&local_124,0,0x18);
  local_122 = 0x1e;
  local_124 = 8;
  local_118 = 3;
  local_11c = &local_10c;
  local_110 = 1;
  local_114 = local_128;
  iVar1 = FUN_0802720c(&local_124,0);
  if (iVar1 < 0) {
    local_128[0] = 0xff;
  }
  return local_128[0];
}



/* ===== FUN_08026fd0 @ 08026fd0 ===== */

uint FUN_08026fd0(void)

{
  uint *puVar1;
  ushort uVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = DAT_08027518;
  uVar4 = *DAT_08027510 & 0xffff;
  while (uVar4 != (*DAT_08027510 & 0xffff)) {
    uVar4 = *DAT_08027510 & 0xffff;
  }
  uVar2 = *DAT_08027514 + (short)uVar4;
  if (uVar2 < (ushort)*DAT_08027518) {
    uVar4 = *DAT_08027518;
    puVar1 = DAT_08027518 + 1;
    *DAT_08027518 = uVar4 + 0x10000;
    puVar3[1] = *puVar1 + (uint)(0xfffeffff < uVar4);
  }
  *(ushort *)puVar3 = uVar2;
  return *puVar3;
}



/* ===== FUN_08027012 @ 08027012 ===== */

void FUN_08027012(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_08027520;
  puVar1 = DAT_0802751c;
  *DAT_0802751c = 0;
  *puVar2 = 1;
  if (puVar1[2] == '\0') {
    puVar1[2] = (char)param_1;
  }
  FUN_080187dc("BLE: error #0x%0.2X!",param_1,param_4);
  return;
}



/* ===== FUN_08027036 @ 08027036 ===== */

void FUN_08027036(void)

{
  int iVar1;
  
  iVar1 = DAT_08027524;
  *(int *)(DAT_08027524 + 0x53c) = DAT_08027524;
  *(int *)(iVar1 + 0x540) = iVar1;
  *(undefined4 *)(iVar1 + 0x544) = 0;
  return;
}



/* ===== FUN_0802705a @ 0802705a ===== */

void FUN_0802705a(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_0802752c;
  *DAT_08027528 = 0x20;
  iVar2 = FUN_08027088();
  while( true ) {
    iVar3 = piVar1[1];
    if (iVar3 == *piVar1) {
      iVar2 = piVar1[2];
    }
    if (iVar3 == *piVar1 && iVar2 == 0) break;
    FUN_08027428(iVar3 + 6);
    iVar2 = FUN_0802740a();
  }
  return;
}



/* ===== FUN_08027088 @ 08027088 ===== */

/* WARNING: Removing unreachable block (ram,0x08027178) */
/* WARNING: Removing unreachable block (ram,0x080271a6) */

void FUN_08027088(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  byte *pbVar5;
  int *piVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  int iVar9;
  int *piVar10;
  char *pcVar11;
  uint uVar12;
  char *pcVar13;
  int iVar14;
  undefined1 auStack_30 [4];
  int *local_2c;
  undefined1 *local_28;
  
  piVar6 = DAT_08027530;
  iVar4 = DAT_08027524;
  local_28 = auStack_30;
  iVar14 = *DAT_08027530;
  uVar12 = 0;
  piVar10 = (int *)(DAT_08027524 + 0x53c);
  local_2c = DAT_08027534;
  while( true ) {
    if (-1 < *local_2c << 0x12) {
      return;
    }
    if (*(int *)(iVar4 + 0x544) != 0) {
      return;
    }
    iVar9 = *piVar10;
    DAT_08027538[4] = 0x40;
    do {
    } while ((uint)(*piVar6 - *piVar6) < 2);
    FUN_0802e1e0(DAT_0802753c,0xb,auStack_30,4);
    pcVar11 = (char *)(uint)*(ushort *)(local_28 + 2);
    pcVar13 = (char *)0x0;
    if (pcVar11 != (char *)0x0) {
      if (pcVar11 < (char *)0x81) {
        uVar7 = FUN_0802e1e0(DAT_0802753c,0xb,iVar9 + 7,pcVar11 + -1);
        *(undefined1 *)(iVar9 + 6) = uVar7;
        pcVar13 = pcVar11;
      }
      else {
        pcVar13 = (char *)(0x80 - (int)pcVar11);
      }
    }
    do {
    } while ((uint)(*piVar6 - *piVar6) < 2);
    *DAT_08027538 = 0x40;
    pbVar5 = DAT_08027528;
    if ((int)pcVar13 < 0) break;
    uVar12 = uVar12 + 1;
    if (pcVar13 != (char *)0x0) {
      *(short *)(*piVar10 + 4) = (short)*piVar6 - (short)iVar14;
      iVar14 = *(int *)(pbVar5 + 4);
      *(char *)(*piVar10 + 1) = (char)iVar14;
      *(int *)(pbVar5 + 4) = iVar14 + 1;
      *(byte *)*piVar10 = (byte)uVar12 | *pbVar5;
      *pbVar5 = 0;
      iVar14 = FUN_08026fd0();
      *(short *)(*piVar10 + 2) = (short)((iVar14 - *(int *)(pbVar5 + 8)) * 0x7d + 0x800U >> 0xc);
      *(int *)(pbVar5 + 8) = iVar14;
      iVar14 = *piVar10;
      pcVar11 = (char *)(iVar14 + 6);
      cVar1 = *pcVar11;
      if (cVar1 == '\x04') {
        pcVar11 = (char *)(*(byte *)(iVar14 + 8) + 3);
      }
      if (cVar1 == '\x04' && pcVar13 == pcVar11) {
        *piVar10 = iVar14 + 0x86;
        if (piVar10 <= (int *)(iVar14 + 0x86)) {
          *piVar10 = iVar4;
        }
        *(uint *)(iVar4 + 0x544) = (uint)(*piVar10 == *(int *)(iVar4 + 0x540));
        puVar3 = DAT_08027520;
        puVar2 = DAT_0802751c;
        if (*(int *)(iVar4 + 0x544) != 0) {
          *DAT_0802751c = 0;
          *puVar3 = 1;
          if (puVar2[2] == '\0') {
            puVar2[2] = 0xb3;
          }
          FUN_080187dc("BLE: error #0x%0.2X!",0xb3);
        }
        return;
      }
      uVar8 = 0x32;
      goto LAB_080271c0;
    }
    if (6 < uVar12) {
      uVar8 = 0x31;
      goto LAB_080271c0;
    }
    do {
    } while ((uint)(*piVar6 - *piVar6) < 0x14);
  }
  uVar8 = 0x30;
LAB_080271c0:
  FUN_08027012(uVar8);
  return;
}



/* ===== FUN_0802720c @ 0802720c ===== */

/* WARNING: Removing unreachable block (ram,0x080273f8) */

int FUN_0802720c(short *param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  uint *puVar3;
  undefined4 uVar4;
  short *psVar5;
  ushort uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined1 *puVar13;
  int iVar14;
  bool bVar15;
  ushort local_37;
  undefined1 local_35;
  short *local_34;
  ushort local_30 [2];
  uint local_2c;
  uint local_28;
  
  if (*DAT_0802751c == '\0') {
    return 0xf2;
  }
  iVar12 = 0;
  uVar6 = param_1[1] & 0x3ffU | *param_1 << 10;
  *DAT_08027528 = 0x40;
  uVar4 = DAT_0802753c;
  puVar3 = DAT_08027534;
  piVar2 = DAT_08027530;
  puVar13 = *(undefined1 **)(param_1 + 4);
  uVar7 = *(uint *)(param_1 + 6);
  local_34 = param_1;
  local_28 = param_2;
  if ((uVar7 & 0xff) < 0x7c) {
    local_2c = uVar7 & 0xff;
    iVar14 = *DAT_08027530;
    local_37 = uVar6;
    local_35 = (char)uVar7;
LAB_0802726a:
    uVar7 = local_2c;
    if ((uint)(*piVar2 - iVar14) < 0x4e21) {
      DAT_08027538[4] = 0x40;
      iVar12 = 0;
      do {
      } while ((uint)(*piVar2 - *piVar2) < 2);
      do {
        if ((int)(*puVar3 << 0x12) < 0) {
          FUN_0802e1e0(uVar4,10,local_30,4);
          if (uVar7 + 4 <= (uint)local_30[0]) {
            FUN_0802e21a(uVar4,1,&local_37,3);
            if (uVar7 != 0) {
              FUN_0802e21a(uVar4,*puVar13,puVar13 + 1,uVar7 - 1);
            }
            iVar12 = 1;
          }
          goto LAB_080272f4;
        }
      } while ((uint)(*piVar2 - *piVar2) < 0x2711);
      do {
      } while ((uint)(*piVar2 - *piVar2) < 2);
      *DAT_08027538 = 0x40;
      iVar12 = -1;
      goto LAB_0802731c;
    }
    goto LAB_0802732a;
  }
  iVar12 = -3;
  goto LAB_08027336;
  while ((uint)(*piVar2 - *piVar2) < 0x1389) {
LAB_080272f4:
    if ((*puVar3 >> 0xd & 1) == 0) goto LAB_0802730c;
  }
  iVar12 = -2;
LAB_0802730c:
  do {
  } while ((uint)(*piVar2 - *piVar2) < 2);
  *DAT_08027538 = 0x40;
LAB_0802731c:
  do {
  } while ((uint)(*piVar2 - *piVar2) < 0x14);
  if (iVar12 != 0) goto LAB_0802732a;
  goto LAB_0802726a;
LAB_0802732a:
  psVar5 = local_34;
  piVar1 = DAT_0802752c;
  if (iVar12 == 0) {
    iVar12 = -4;
  }
  else if (-1 < iVar12) {
    if (DAT_0802751c[1] == 0) {
      uVar7 = 1000;
    }
    else {
      uVar7 = (short)(ushort)(byte)DAT_0802751c[1] * 1000;
    }
    iVar12 = *piVar2;
    if ((local_28 & 0xff) != 0) {
      do {
      } while ((uint)(*piVar2 - iVar12) <= uVar7);
      return 2;
    }
    iVar14 = 0;
    do {
      do {
        if (uVar7 < (uint)(*piVar2 - iVar12)) goto LAB_080273ee;
        iVar8 = FUN_08027088();
        iVar11 = piVar1[1];
        if (iVar11 == *piVar1) {
          iVar8 = piVar1[2];
        }
      } while (iVar11 == *piVar1 && iVar8 == 0);
      pcVar9 = (char *)(iVar11 + 9);
      uVar10 = (uint)*(byte *)(iVar11 + 8);
      if (*(char *)(iVar11 + 7) == '\x0e') {
        if (*(ushort *)(iVar11 + 10) != uVar6) goto LAB_080273c8;
        pcVar9 = (char *)(iVar11 + 0xc);
        uVar10 = uVar10 - 3;
        iVar14 = 2;
LAB_080273cc:
        if (*(uint *)(psVar5 + 10) <= uVar10) {
          uVar10 = *(uint *)(psVar5 + 10);
        }
        *(uint *)(psVar5 + 10) = uVar10;
        FUN_0802e734(*(undefined4 *)(psVar5 + 8),pcVar9);
      }
      else {
        if (*(char *)(iVar11 + 7) == '\x0f') {
          bVar15 = *(ushort *)(iVar11 + 0xb) != uVar6;
          if (!bVar15) {
            iVar14 = *(int *)(psVar5 + 2);
          }
          if ((bVar15 || iVar14 != 0xf) || (*pcVar9 != '\0')) {
            iVar14 = 0xf3;
          }
          else {
            iVar14 = 1;
          }
          goto LAB_080273cc;
        }
LAB_080273c8:
        if (iVar14 != 0) goto LAB_080273cc;
        FUN_08027428(iVar11 + 6);
      }
      FUN_0802740a();
    } while (iVar14 == 0);
LAB_080273ee:
    if (iVar14 == 0) {
      return 0xf4;
    }
    return iVar14;
  }
LAB_08027336:
  FUN_08027012(0x20U - iVar12 & 0xff);
  return iVar12;
}



/* ===== FUN_0802740a @ 0802740a ===== */

void FUN_0802740a(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_08027524;
  piVar2 = (int *)(DAT_08027524 + 0x540);
  iVar4 = DAT_08027524 + 0x53c;
  iVar3 = *piVar2;
  *piVar2 = iVar3 + 0x86;
  if (iVar3 + 0x86 == iVar4) {
    *piVar2 = iVar1;
  }
  *(undefined4 *)(iVar1 + 0x544) = 0;
  return;
}



/* ===== FUN_08027428 @ 08027428 ===== */

undefined8 FUN_08027428(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  ushort uVar1;
  ushort uVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  ushort *puVar6;
  uint uVar7;
  undefined4 uVar8;
  uint unaff_r6;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  uint local_18;
  
  puVar4 = DAT_08027520;
  puVar3 = DAT_0802751c;
  uVar8 = 0;
  uVar5 = (uint)*(byte *)(param_1 + 1);
  if (uVar5 == 0x3e) {
    uVar7 = 0;
    puVar6 = DAT_08027540;
    do {
      uVar5 = (uint)*(byte *)(param_1 + 3);
      if (uVar5 != *puVar6) {
        uVar7 = uVar7 + 1;
        unaff_r6 = (uint)puVar6[4];
      }
      if (uVar5 == *puVar6 || uVar5 == unaff_r6) {
        param_1 = param_1 + 4;
        puVar6 = DAT_08027540;
        goto LAB_080274a2;
      }
      uVar7 = uVar7 + 1;
      puVar6 = puVar6 + 8;
    } while (uVar7 < 10);
LAB_080274de:
    *DAT_0802751c = 0;
    *puVar4 = 1;
    if (puVar3[2] == '\0') {
      puVar3[2] = 0x10;
    }
    FUN_080187dc("BLE: error #0x%0.2X!",0x10);
    local_18 = (uint)*(byte *)(param_1 + 4);
    FUN_080188b2(DAT_0802754c,*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2),
                 *(undefined1 *)(param_1 + 3));
  }
  else {
    uVar7 = 0;
    if (uVar5 == 0xff) {
      if (*(ushort *)(param_1 + 3) != *DAT_08027544) {
        uVar7 = 1;
        puVar6 = DAT_08027544 + 4;
        do {
          uVar2 = *(ushort *)(param_1 + 3);
          uVar1 = *puVar6;
          bVar10 = uVar2 == uVar1;
          if (!bVar10) {
            uVar7 = uVar7 + 1;
            uVar1 = puVar6[4];
          }
          bVar11 = uVar2 == uVar1;
          if (!bVar10 && !bVar11) {
            uVar7 = uVar7 + 1;
            uVar1 = puVar6[8];
          }
          if ((bVar10 || bVar11) || uVar2 == uVar1) goto LAB_08027494;
          uVar7 = uVar7 + 1;
          puVar6 = puVar6 + 0xc;
        } while (uVar7 < 0x2b);
        goto LAB_080274de;
      }
LAB_08027494:
      param_1 = param_1 + 5;
      puVar6 = DAT_08027544;
    }
    else {
      if (uVar5 != *DAT_08027548) {
        uVar9 = (uint)DAT_08027548[4];
        uVar7 = 1;
        bVar10 = uVar5 != uVar9;
        if (bVar10) {
          uVar7 = 2;
          uVar9 = (uint)DAT_08027548[8];
        }
        if (bVar10 && uVar5 != uVar9) {
          uVar9 = (uint)DAT_08027548[0xc];
          uVar7 = 3;
          bVar10 = uVar5 != uVar9;
          if (bVar10) {
            uVar7 = 4;
            uVar9 = (uint)DAT_08027548[0x10];
          }
          if (bVar10 && uVar5 != uVar9) {
            uVar7 = 5;
            uVar9 = param_4;
            if (uVar5 != DAT_08027548[0x14]) {
              uVar7 = 6;
              uVar9 = (uint)DAT_08027548[0x18];
            }
            if (uVar5 != DAT_08027548[0x14] && uVar5 != uVar9) goto LAB_080274de;
          }
        }
      }
      param_1 = param_1 + 3;
      puVar6 = DAT_08027548;
    }
LAB_080274a2:
    uVar8 = 1;
    (**(code **)(puVar6 + uVar7 * 4 + 2))(param_1);
    local_18 = param_4;
  }
  return CONCAT44(local_18,uVar8);
}



/* ===== FUN_0802757a @ 0802757a ===== */

uint FUN_0802757a(void)

{
  uint uVar1;
  
  uVar1 = *DAT_08027a48 & 0xffff;
  while (uVar1 != (*DAT_08027a48 & 0xffff)) {
    uVar1 = *DAT_08027a48 & 0xffff;
  }
  return uVar1 + *DAT_080281f0 & 0xffff;
}



/* ===== FUN_0802759a @ 0802759a ===== */

undefined8 FUN_0802759a(void)

{
  uint *puVar1;
  uint *puVar2;
  ushort uVar3;
  uint uVar4;
  
  uVar3 = FUN_0802757a();
  puVar2 = DAT_080281f4;
  if (uVar3 < (ushort)*DAT_080281f4) {
    uVar4 = *DAT_080281f4;
    puVar1 = DAT_080281f4 + 1;
    *DAT_080281f4 = uVar4 + 0x10000;
    puVar2[1] = *puVar1 + (uint)(0xfffeffff < uVar4);
  }
  *(ushort *)puVar2 = uVar3;
  return *(undefined8 *)puVar2;
}



/* ===== FUN_080275c4 @ 080275c4 ===== */

void FUN_080275c4(int param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_080281fc;
  if (param_1 == 0) {
    *(uint *)(DAT_080281f8 + 0x54) = *(uint *)(DAT_080281f8 + 0x54) & 0xfffffeff;
    FUN_08015b44();
    *puVar1 = *puVar1 & 0xfffffffe;
    FUN_0802086a(0);
    return;
  }
  *(uint *)(DAT_080281f8 + 0x54) = *(uint *)(DAT_080281f8 + 0x54) | 0x100;
  FUN_08015b44(1);
  *puVar1 = *puVar1 | 1;
  return;
}



/* ===== FUN_080275fc @ 080275fc ===== */

void FUN_080275fc(uint param_1)

{
  *(uint *)(DAT_080281f8 + 0x54) =
       *(uint *)(DAT_080281f8 + 0x54) & 0xffefffff | (param_1 & 1) << 0x14;
  if (param_1 != 0) {
    *(uint *)(DAT_080281fc + 4) = *(uint *)(DAT_080281fc + 4) | 1;
    return;
  }
  if ((int)(*(uint *)(DAT_080281fc + 4) << 0x1f) < 0) {
    *(uint *)(DAT_080281fc + 4) = *(uint *)(DAT_080281fc + 4) & 0xfffffffe;
    FUN_08020c66(DAT_0801680c);
    return;
  }
  return;
}



/* ===== FUN_08027620 @ 08027620 ===== */

void FUN_08027620(uint param_1)

{
  *(byte *)(DAT_080281f8 + 0x58) =
       *(byte *)(DAT_080281f8 + 0x58) & 0xf3 | (byte)((param_1 & 3) << 2);
  if (param_1 == 1) {
    FUN_08015a94();
    return;
  }
  if (param_1 == 2) {
    FUN_08015a9e();
    return;
  }
  return;
}



/* ===== FUN_08027642 @ 08027642 ===== */

int FUN_08027642(int *param_1)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  
  pbVar3 = *(byte **)(*param_1 + 8);
  uVar4 = *(uint *)(*param_1 + 0x10);
  uVar1 = *(int *)pbVar3 + 4U;
  if (uVar4 < *(int *)pbVar3 + 4U) {
    uVar1 = uVar4;
  }
  pbVar5 = pbVar3 + uVar1;
  iVar2 = 0;
  if (pbVar3 < pbVar5) {
    for (; pbVar3 < pbVar5; pbVar3 = pbVar3 + 1) {
      iVar2 = iVar2 + (uint)*pbVar3;
    }
  }
  return iVar2;
}



/* ===== FUN_08027668 @ 08027668 ===== */

void FUN_08027668(int *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar5 = *(uint **)(*param_1 + 8);
  uVar4 = *puVar5;
  if (uVar4 < 0xc) {
    uVar2 = DAT_08028200;
    uVar1 = uVar4;
  }
  else {
    uVar1 = puVar5[1];
    if (uVar1 == (*DAT_08028204 | DAT_08028208)) {
      uVar1 = puVar5[2];
      if (uVar1 == 1) {
        uVar1 = puVar5[3];
        if (uVar4 - uVar1 != 0xc) {
          FUN_08018872(DAT_08028214,param_2);
          return;
        }
        if ((uVar1 == 0) || (iVar3 = FUN_08018c68(puVar5 + 4,uVar1), iVar3 != 0)) {
          return;
        }
        FUN_080187dc(DAT_08028218,param_2);
        return;
      }
      uVar2 = DAT_08028210;
    }
    else {
      uVar2 = DAT_0802820c;
    }
  }
  FUN_08018826(uVar2,param_2,uVar1);
  return;
}



/* ===== FUN_080276e2 @ 080276e2 ===== */

void FUN_080276e2(int param_1)

{
  undefined4 uVar1;
  
  FUN_08027668(param_1,1);
  uVar1 = FUN_08027642(param_1);
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  return;
}



/* ===== FUN_080276f8 @ 080276f8 ===== */

void FUN_080276f8(int param_1)

{
  int iVar1;
  
  FUN_08027668(param_1,2);
  iVar1 = FUN_08027642(param_1);
  if (iVar1 == *(int *)(param_1 + 0x1c)) {
    return;
  }
  FUN_08018826("CRC Error: 0x%08X != 0x%08X");
  return;
}



/* ===== FUN_08027738 @ 08027738 ===== */

undefined4 FUN_08027738(int *param_1)

{
  char cVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  bool bVar6;
  
  if (((code *)param_1[6] != (code *)0x0) && (*(char *)param_1[4] == '\0')) {
    (*(code *)param_1[6])(param_1);
    param_1[6] = 0;
  }
  cVar1 = *(char *)param_1[3];
  bVar6 = cVar1 == '\x01';
  if (bVar6) {
    cVar1 = *(char *)param_1[4];
  }
  if (bVar6 && cVar1 == '\0') {
    *(char *)param_1[3] = cVar1;
    FUN_080297fc(*(undefined1 *)*param_1);
    iVar3 = *param_1;
    puVar4 = *(uint **)(iVar3 + 4);
    param_1[1] = (int)(puVar4 + 1);
    puVar2 = DAT_08028204;
    uVar5 = *puVar4;
    *DAT_08028204 = uVar5 & 0x1f000000;
    param_1[2] = *(int *)(iVar3 + 8) + 4;
    puVar4 = DAT_0802821c;
    if (-1 < (int)((uint)(byte)puVar2[1] << 0x1e)) {
      puVar4 = (uint *)&UNK_080277cc;
    }
    for (; *puVar4 != (uVar5 & 0xe0ffffff) && *puVar4 != 0; puVar4 = puVar4 + 2) {
    }
    (*(code *)puVar4[1])(param_1);
    FUN_0802782a(param_1);
    if ((code *)param_1[5] != (code *)0x0) {
      (*(code *)param_1[5])(param_1);
      param_1[5] = 0;
    }
    (**(code **)(*param_1 + 0x14))(param_1);
    return 1;
  }
  return 0;
}



/* ===== FUN_080277e4 @ 080277e4 ===== */

void FUN_080277e4(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = DAT_08028220;
  iVar2 = *DAT_080281ec;
  *(int *)*DAT_08028220 = *(int *)(iVar2 + 8) + 4;
  *(undefined4 *)puVar1[1] = *(undefined4 *)(iVar2 + 4);
  *(undefined1 *)puVar1[2] = 0;
  *(undefined1 *)puVar1[3] = 0;
  *(undefined4 *)puVar1[4] = 0;
  *(undefined4 *)puVar1[5] = 0;
  *(short *)puVar1[6] = (short)*(undefined4 *)(iVar2 + 0x10) + -4;
  *(short *)puVar1[7] = (short)*(undefined4 *)(iVar2 + 0xc) + -4;
  return;
}



/* ===== FUN_0802782a @ 0802782a ===== */

void FUN_0802782a(int *param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = *(uint **)(*param_1 + 8);
  iVar3 = param_1[2];
  param_1[2] = (int)(puVar1 + 1);
  uVar2 = iVar3 - (int)(puVar1 + 1);
  if (*(uint *)(*param_1 + 0x10) < uVar2) {
    puVar1[1] = DAT_08028224;
    uVar2 = 4;
  }
  *puVar1 = uVar2;
  puVar1[1] = puVar1[1] | *DAT_08028204;
  return;
}



/* ===== FUN_0802785a @ 0802785a ===== */

void FUN_0802785a(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  int *piVar2;
  char *pcVar3;
  
  FUN_0802782a();
  puVar1 = DAT_08028228;
  pcVar3 = (char *)*param_1;
  if (*pcVar3 == '\x02') {
    piVar2 = *(int **)(pcVar3 + 8);
    DAT_08028228[5] = *piVar2 + 4;
    param_1[2] = piVar2;
    *(undefined1 *)param_1[4] = 1;
    *puVar1 = *puVar1 | 4;
    while (*(char *)param_1[4] != '\0') {
      *puVar1 = *puVar1 | 4;
      FUN_08029514();
    }
  }
  else {
    (**(code **)(pcVar3 + 0x14))(param_1);
    do {
    } while (*(char *)param_1[4] != '\0');
  }
  FUN_0802c050(0x14,param_4);
  return;
}



/* ===== FUN_080278b2 @ 080278b2 ===== */

void FUN_080278b2(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = DAT_0802822c;
  (*(code *)DAT_0802822c[6])();
  *(undefined4 *)*puVar1 = **(undefined4 **)(*param_1 + 8);
  UNRECOVERED_JUMPTABLE = (code *)puVar1[5];
                    /* WARNING: Could not recover jumptable at 0x080278ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(UNRECOVERED_JUMPTABLE,param_4);
  return;
}



/* ===== FUN_08027918 @ 08027918 ===== */

undefined8
FUN_08027918(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  char *pcVar8;
  
  iVar2 = DAT_08028238;
  piVar4 = (int *)param_1[1];
  param_1[1] = piVar4 + 1;
  uVar3 = DAT_0802823c;
  uVar6 = DAT_08028230;
  if (*piVar4 == iVar2) {
    *(uint *)(DAT_08028204 + 4) = *(uint *)(DAT_08028204 + 4) | 2;
    puVar5 = (undefined4 *)param_1[2];
    *puVar5 = DAT_08028240;
    puVar5[1] = uVar3;
    param_1[2] = puVar5 + 3;
    puVar7 = (undefined1 *)*param_1;
    puVar5[2] = *(uint *)(puVar7 + 0x10) | (*(int *)(puVar7 + 0xc) + -0x20) * 0x10000;
    puVar5 = (undefined4 *)param_1[2];
    param_1[2] = puVar5 + 1;
    uVar6 = FUN_080297e4(*puVar7);
    *puVar5 = uVar6;
    cVar1 = *(char *)*param_1;
    if (cVar1 == '\x01') {
      puVar7 = (undefined1 *)param_1[4];
      *puVar7 = 0;
      return CONCAT44(puVar7,param_4);
    }
    pcVar8 = (char *)*param_1;
    if (cVar1 == '\x02') {
      FUN_080294fa();
      pcVar8 = DAT_08028244;
      if (DAT_08028244[0xd] == '\0') {
        DAT_08028244[0xd] = '\x01';
        return CONCAT44(pcVar8,param_4);
      }
    }
  }
  else {
    pcVar8 = (char *)param_1[2];
    param_1[2] = pcVar8 + 4;
    *(undefined4 *)pcVar8 = uVar6;
  }
  return CONCAT44(pcVar8,param_4);
}



/* ===== FUN_080279a0 @ 080279a0 ===== */

void FUN_080279a0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  
  iVar4 = DAT_08028238;
  piVar5 = *(int **)(param_1 + 4);
  *(int **)(param_1 + 4) = piVar5 + 1;
  uVar3 = DAT_08028248;
  uVar2 = DAT_08028230;
  uVar1 = DAT_080281fc;
  if (*piVar5 != iVar4) {
    puVar6 = *(undefined4 **)(param_1 + 8);
    *(undefined4 **)(param_1 + 8) = puVar6 + 1;
    *puVar6 = uVar2;
    return;
  }
  puVar6 = *(undefined4 **)(param_1 + 8);
  *(undefined4 **)(param_1 + 8) = puVar6 + 1;
  *puVar6 = uVar3;
  FUN_0802785a(param_1,puVar6);
  FUN_08018b8a();
  FUN_08019426();
  FUN_0801cacc();
  FUN_080166ba(uVar1);
  *DAT_0802824c = 0xaaaa;
  do {
    iVar4 = FUN_0801684e(uVar1);
  } while (iVar4 != 0);
  *DAT_08028250 = *DAT_08028250 | 0x100;
  *DAT_08028254 = 0x55aa;
  DAT_08028254[1] = 0x5a5a;
  *DAT_08028250 = *DAT_08028250 & 0xfffffeff;
  DataSynchronizationBarrier(0xf);
  *DAT_08028258 = *DAT_08028258 & 0x700 | DAT_0802825c;
  DataSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_08027a4c @ 08027a4c ===== */

int FUN_08027a4c(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  ulonglong uVar1;
  byte *pbVar2;
  uint *puVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  bool bVar10;
  byte bVar11;
  longlong lVar12;
  undefined1 local_78 [4];
  undefined4 local_74;
  uint local_70;
  uint local_6c;
  int local_68;
  undefined1 auStack_50 [4];
  undefined4 local_4c;
  uint local_48;
  uint local_44;
  undefined4 uStack_28;
  
  puVar3 = DAT_08028dd8;
  puVar7 = DAT_08028cf0;
  pbVar2 = DAT_080281f8;
  uStack_28 = param_4;
  if (param_2 == 0x500) {
    iVar6 = FUN_0801814a();
    uVar8 = (uint)(iVar6 != 0);
    if (-1 < *(int *)(DAT_080288f4 + 8) << 0x1a) {
      uVar8 = uVar8 | 2;
    }
    if (*DAT_080288f8 << 0x17 < 0) {
      uVar8 = uVar8 | 4;
    }
    if (*DAT_080288f8 << 0x18 < 0) {
      uVar8 = uVar8 | 8;
    }
    if (*DAT_080288f8 << 0xb < 0) {
      uVar8 = uVar8 | 0x10;
    }
    if (*(int *)(DAT_080288f4 + 8) << 0xc < 0) {
      uVar8 = uVar8 | 0x20;
    }
    if (*(int *)(DAT_080288f4 + 8) << 0x15 < 0) {
      uVar8 = uVar8 | 0x40;
    }
    puVar7 = (uint *)param_1[2];
    param_1[2] = (int)(puVar7 + 1);
    *puVar7 = uVar8;
    return 1;
  }
  if (param_2 == 0x502) {
    uVar8 = (uint)*DAT_080281f8;
LAB_08027ee6:
    puVar7 = (uint *)param_1[2];
    param_1[2] = (int)(puVar7 + 1);
    *puVar7 = uVar8;
    return 1;
  }
  if (param_2 == 0x503) {
    puVar9 = (undefined4 *)param_1[2];
    param_1[2] = (int)(puVar9 + 1);
    uVar4 = FUN_0801814a();
    goto LAB_0802813a;
  }
  if (param_2 == 0x504) {
    puVar7 = (uint *)param_1[2];
    param_1[2] = (int)(puVar7 + 1);
    lVar12 = FUN_0802759a();
    uVar1 = lVar12 - *DAT_08028928;
    bVar10 = (longlong)uVar1 < 0;
    if (bVar10) {
      uVar1 = CONCAT44(-(int)(uVar1 >> 0x20) - (uint)((int)uVar1 != 0),-(int)uVar1);
    }
    lVar12 = (uVar1 & 0xffffffff) * 0x7d;
    uVar8 = (uint)lVar12;
    uVar8 = uVar8 + 0x800 >> 0xc |
            ((int)(uVar1 >> 0x20) * 0x7d + (int)((ulonglong)lVar12 >> 0x20) +
            (uint)(0xfffff7ff < uVar8)) * 0x100000;
    if (bVar10) {
      uVar8 = -uVar8;
    }
    *puVar7 = uVar8;
    return 1;
  }
  if (param_2 == 0x510) {
    uVar8 = (uint)(-1 < *(int *)(DAT_080288f4 + 8) << 0x1a);
    if (*(int *)(DAT_080288f4 + 8) << 0x19 < 0) {
      uVar8 = uVar8 | 2;
    }
    uVar8 = uVar8 | ((*(byte *)(DAT_080288f8 + 1) & 0xf) >> 2) << 4 |
                    (*(byte *)(DAT_080288f8 + 1) & 3) << 2;
    if (*(int *)(DAT_080288f4 + 8) << 0x18 < 0) {
      uVar8 = uVar8 | 0x20;
    }
    puVar5 = (uint *)param_1[2];
    param_1[2] = (int)(puVar5 + 1);
    goto LAB_0802816c;
  }
  if (param_2 == 0x511) {
    uVar8 = (uint)DAT_080281f8[1];
  }
  else if (param_2 == 0x512) {
    uVar8 = (uint)DAT_080281f8[2];
  }
  else if (param_2 == 0x513) {
    uVar8 = (uint)DAT_080281f8[5];
  }
  else {
    if (param_2 == 0x514) {
      uVar8 = *(uint *)(DAT_080288f4 + 8) >> 5 & 1 ^ 1;
      goto LAB_08028146;
    }
    if (param_2 == 0x515) {
      uVar8 = (*(byte *)(DAT_080288f8 + 1) & 0xf) >> 2;
    }
    else if (param_2 == 0x516) {
      uVar8 = (*(uint *)(DAT_080288f4 + 8) & 0x7f) >> 6;
    }
    else {
      if (param_2 == 0x520) {
        uVar8 = (uint)(*DAT_080288f8 << 0x16 < 0);
        if (*DAT_080288f8 << 0x15 < 0) {
          uVar8 = uVar8 | 2;
        }
        if (*DAT_080288f8 << 0x14 < 0) {
          uVar8 = uVar8 | 0x400;
        }
        if (*DAT_080288f8 << 0x13 < 0) {
          uVar8 = uVar8 | 0x800;
        }
        if (*DAT_080288f8 << 0x12 < 0) {
          uVar8 = uVar8 | 0x1000;
        }
        if (*DAT_080288f8 << 0x11 < 0) {
          uVar8 = uVar8 | 4;
        }
        if (*DAT_080288f8 << 0x10 < 0) {
          uVar8 = uVar8 | 8;
        }
        if (*DAT_080288f8 << 0xf < 0) {
          uVar8 = uVar8 | 0x10;
        }
        if (*DAT_080288f8 << 0xe < 0) {
          uVar8 = uVar8 | 0x20;
        }
        if (*DAT_080288f8 << 0xd < 0) {
          uVar8 = uVar8 | 0x40;
        }
        if (*DAT_080288f8 << 0xc < 0) {
          uVar8 = uVar8 | 0x80;
        }
        if (DAT_080288f8[1] << 0x10 < 0) {
          uVar8 = uVar8 | 0x100;
        }
        if (DAT_080288f8[1] << 0xf < 0) {
          uVar8 = uVar8 | 0x200;
        }
        goto LAB_08027ee6;
      }
      if (param_2 == 0x521) {
        uVar8 = (uint)DAT_080281f8[4];
      }
      else if (param_2 == 0x522) {
        uVar8 = (*(uint *)(DAT_080281f8 + 0x54) & 0x1ff) >> 8;
      }
      else {
        if (param_2 == 0x530) {
          uVar8 = (uint)(*DAT_080288f8 << 10 < 0);
          if (*DAT_080288f8 << 9 < 0) {
            uVar8 = uVar8 | 2;
          }
          if (*DAT_080288f8 << 8 < 0) {
            uVar8 = uVar8 | 0x400;
          }
          if (*DAT_080288f8 << 7 < 0) {
            uVar8 = uVar8 | 0x800;
          }
          if (*DAT_080288f8 << 6 < 0) {
            uVar8 = uVar8 | 0x1000;
          }
          if (*DAT_080288f8 << 5 < 0) {
            uVar8 = uVar8 | 4;
          }
          if (*DAT_080288f8 << 4 < 0) {
            uVar8 = uVar8 | 8;
          }
          if (*DAT_080288f8 << 3 < 0) {
            uVar8 = uVar8 | 0x10;
          }
          if (*DAT_080288f8 << 2 < 0) {
            uVar8 = uVar8 | 0x20;
          }
          if (*DAT_080288f8 << 1 < 0) {
            uVar8 = uVar8 | 0x40;
          }
          puVar5 = (uint *)param_1[2];
          if (*DAT_080288f8 < 0) {
            uVar8 = uVar8 | 0x80;
          }
          param_1[2] = (int)(puVar5 + 1);
          goto LAB_0802816c;
        }
        if (param_2 == 0x531) {
          uVar8 = *(uint *)(DAT_080281f8 + 0x54);
        }
        else {
          if (param_2 == 0x5e0) {
            uVar8 = (DAT_080288f8[1] & 0x3fU) >> 5;
            goto LAB_0802801c;
          }
          if (param_2 == 0x603) {
            uVar8 = (*(uint *)(DAT_080288f4 + 8) & 0x7ff) >> 10;
            goto LAB_0802801c;
          }
          if (param_2 == 0x700) {
            uVar8 = (DAT_080288f8[1] & 0x7fffU) >> 0xd;
            goto LAB_0802801c;
          }
          if (param_2 == 0x8000) {
            puVar5 = (uint *)param_1[2];
            param_1[2] = (int)(puVar5 + 1);
            uVar8 = *(uint *)(pbVar2 + 0x30);
LAB_0802816c:
            *puVar5 = uVar8;
            return 1;
          }
          if (param_2 == 0x8001) {
            puVar5 = (uint *)param_1[2];
            param_1[2] = (int)(puVar5 + 1);
            uVar8 = *(uint *)(pbVar2 + 0x34);
            goto LAB_0802816c;
          }
          if (param_2 == 0x8002) {
            uVar8 = (uint)((ulonglong)*(uint *)(DAT_080281f8 + 0x38) * (ulonglong)DAT_08028b3c >>
                          0x26);
            goto LAB_08027ee6;
          }
          if (param_2 == 0x8003) {
            uVar8 = *(uint *)(DAT_080281f8 + 0x3c);
            puVar7 = (uint *)param_1[2];
            uVar1 = (ulonglong)DAT_08028b3c;
            param_1[2] = (int)(puVar7 + 1);
            *puVar7 = (uint)(uVar8 * uVar1 >> 0x26);
            return 1;
          }
          if (param_2 == 0x8004) {
            bVar11 = DAT_080281f8[0x54];
            puVar5 = (uint *)param_1[2];
            param_1[2] = (int)(puVar5 + 1);
            uVar8 = bVar11 & 1;
            goto LAB_0802816c;
          }
          if (param_2 == 0x8005) {
            uVar8 = (*(uint *)(DAT_080281f8 + 0x54) & 0x7f) >> 5;
            goto LAB_0802801c;
          }
          if (param_2 == 0x8008) {
            puVar5 = (uint *)param_1[2];
            param_1[2] = (int)(puVar5 + 1);
            uVar8 = *(uint *)(pbVar2 + 0x40);
            goto LAB_0802816c;
          }
          if (param_2 == 0x8009) {
            puVar5 = (uint *)param_1[2];
            param_1[2] = (int)(puVar5 + 1);
            uVar8 = *(uint *)(pbVar2 + 0x44);
            goto LAB_0802816c;
          }
          if (param_2 == 0x800c) {
            uVar8 = (*(uint *)(DAT_080281f8 + 0x54) & 0xf) >> 3;
            goto LAB_0802801c;
          }
          if (param_2 == 0x8010) {
            puVar9 = (undefined4 *)param_1[2];
            param_1[2] = (int)(puVar9 + 1);
            uVar4 = FUN_0801d134(0);
LAB_0802813a:
            *puVar9 = uVar4;
            return 1;
          }
          if (param_2 == 0x8011) {
            puVar9 = (undefined4 *)param_1[2];
            param_1[2] = (int)(puVar9 + 1);
            uVar4 = FUN_0801d134(1);
            goto LAB_0802813a;
          }
          if (param_2 == 0x8012) {
            puVar9 = (undefined4 *)param_1[2];
            param_1[2] = (int)(puVar9 + 1);
            uVar4 = FUN_0801d134(2);
            goto LAB_0802813a;
          }
          if (param_2 == 0x8013) {
            uVar8 = *(uint *)(DAT_080281f8 + 0x54);
            puVar5 = (uint *)param_1[2];
            param_1[2] = (int)(puVar5 + 1);
            uVar8 = uVar8 >> 2 & 1 ^ 1;
            goto LAB_0802816c;
          }
          if (param_2 == 0x8014) {
            puVar5 = (uint *)param_1[2];
            param_1[2] = (int)(puVar5 + 1);
            uVar8 = *(uint *)(pbVar2 + 0x38);
            goto LAB_0802816c;
          }
          if (param_2 == 0x8015) {
            puVar5 = (uint *)param_1[2];
            param_1[2] = (int)(puVar5 + 1);
            uVar8 = *(uint *)(pbVar2 + 0x3c);
            goto LAB_0802816c;
          }
          if (param_2 == 0x8016) {
            uVar8 = (DAT_080281f8[0x54] & 3) >> 1;
            goto LAB_0802801c;
          }
          if (param_2 == 0x8024) {
            puVar9 = (undefined4 *)param_1[2];
            param_1[2] = (int)(puVar9 + 1);
            uVar4 = FUN_08023104();
            goto LAB_0802813a;
          }
          if (param_2 == 0x8033) {
            puVar9 = (undefined4 *)param_1[2];
            param_1[2] = (int)(puVar9 + 1);
            uVar4 = FUN_080230fc();
            goto LAB_0802813a;
          }
          if (param_2 == 0x8034) {
            puVar9 = (undefined4 *)param_1[2];
            param_1[2] = (int)(puVar9 + 1);
            uVar4 = FUN_0802312a();
            goto LAB_0802813a;
          }
          if (param_2 == 0x8035) {
            puVar9 = (undefined4 *)param_1[2];
            param_1[2] = (int)(puVar9 + 1);
            uVar4 = FUN_08023132();
            goto LAB_0802813a;
          }
          if (param_2 == 0xc000) {
            puVar9 = (undefined4 *)param_1[2];
            param_1[2] = (int)(puVar9 + 1);
            uVar4 = FUN_08017164();
            goto LAB_0802813a;
          }
          if (param_2 == 0xc001) {
            puVar9 = (undefined4 *)param_1[2];
            param_1[2] = (int)(puVar9 + 1);
            uVar4 = FUN_080176ce();
            goto LAB_0802813a;
          }
          if (param_2 != 0xc002) {
            if (param_2 == 0xc004) {
              FUN_0801f63a();
              puVar9 = (undefined4 *)param_1[2];
              param_1[2] = (int)(puVar9 + 1);
              uVar4 = FUN_08022cb8();
            }
            else if (param_2 == 0xc005) {
              FUN_0801f63a();
              puVar9 = (undefined4 *)param_1[2];
              param_1[2] = (int)(puVar9 + 1);
              uVar4 = FUN_08022d22();
            }
            else if (param_2 == 0xc006) {
              FUN_0801f63a();
              puVar9 = (undefined4 *)param_1[2];
              param_1[2] = (int)(puVar9 + 1);
              uVar4 = FUN_08022d3e();
            }
            else {
              if (param_2 != 0xc200) {
                param_2 = param_2 + -0xc300;
                if (param_2 == 0) {
                  iVar6 = FUN_08022f7c(param_1[2]);
                  if (iVar6 == 0) {
                    return 0;
                  }
                  param_1[2] = param_1[2] + 4;
                  return iVar6;
                }
                iVar6 = param_2 - DAT_08028260;
                if (param_2 == DAT_08028260) {
                  puVar5 = (uint *)param_1[2];
                  param_1[2] = (int)(puVar5 + 1);
                  uVar8 = *puVar7;
                  goto LAB_0802816c;
                }
                if (iVar6 == 1) {
                  puVar5 = (uint *)param_1[2];
                  param_1[2] = (int)(puVar5 + 1);
                }
                else {
                  if (iVar6 == 2) {
                    puVar5 = (uint *)param_1[2];
                    param_1[2] = (int)(puVar5 + 1);
                    uVar8 = puVar7[2];
                    goto LAB_0802816c;
                  }
                  if (iVar6 == 4) {
                    puVar7 = (uint *)param_1[2];
                    param_1[2] = (int)(puVar7 + 1);
                    FUN_0802e754(local_78);
                    uVar8 = (uint)(local_68 != 0xaa);
                    local_74 = 0;
                    FUN_0802e754(local_78);
                    local_4c = 1;
                    FUN_0802e754(auStack_50);
                    bVar11 = local_70 <= local_6c;
                    if (local_48 <= local_44) {
                      bVar11 = bVar11 | 2;
                    }
                    if (bVar11 != 0) {
                      uVar8 = uVar8 | 2;
                    }
                    *puVar7 = uVar8;
                    return 1;
                  }
                  if (iVar6 == 5) {
                    uVar8 = DAT_0802823c;
LAB_08028146:
                    puVar7 = (uint *)param_1[2];
                    param_1[2] = (int)(puVar7 + 1);
                    *puVar7 = uVar8;
                    return 1;
                  }
                  if (iVar6 == 6) {
                    uVar8 = *DAT_08028d50;
                    goto LAB_08028146;
                  }
                  if (iVar6 == 7) {
                    uVar8 = *(uint *)(*param_1 + 0xc);
                    goto LAB_08028146;
                  }
                  if (iVar6 == 8) {
                    uVar8 = *(uint *)(*param_1 + 0x10);
                    goto LAB_08028146;
                  }
                  if (iVar6 == 9) {
                    puVar9 = (undefined4 *)param_1[2];
                    uVar4 = *(undefined4 *)*DAT_08028d54;
                    param_1[2] = (int)(puVar9 + 1);
                    *puVar9 = uVar4;
                    return 1;
                  }
                  if (iVar6 == 10) {
                    uVar8 = DAT_08028d58;
                    goto LAB_08028146;
                  }
                  if (iVar6 == 0xb) {
                    uVar8 = *(uint *)(DAT_08028204 + 4);
                    goto LAB_08028146;
                  }
                  if (iVar6 == 0xc) {
                    puVar9 = (undefined4 *)param_1[2];
                    param_1[2] = (int)(puVar9 + 1);
                    uVar4 = FUN_08017ddc(4);
                    goto LAB_0802813a;
                  }
                  if (iVar6 == 0xd) {
                    puVar9 = (undefined4 *)param_1[2];
                    param_1[2] = (int)(puVar9 + 1);
                    uVar4 = FUN_08017ddc(5);
                    goto LAB_0802813a;
                  }
                  if (iVar6 == 0xe) {
                    puVar9 = (undefined4 *)param_1[2];
                    param_1[2] = (int)(puVar9 + 1);
                    uVar4 = FUN_0801f63a();
                    goto LAB_0802813a;
                  }
                  if (iVar6 == 0x10) {
                    uVar8 = (uint)*DAT_08028dd4;
                    if (*DAT_08028dd4 == 0) {
                      return 0;
                    }
                    goto LAB_08028146;
                  }
                  if (iVar6 == 0x1000) {
                    puVar5 = (uint *)param_1[2];
                    param_1[2] = (int)(puVar5 + 1);
                    uVar8 = *puVar3;
                    goto LAB_0802816c;
                  }
                  if (iVar6 != 0x1001) {
                    return 0;
                  }
                  puVar5 = (uint *)param_1[2];
                  param_1[2] = (int)(puVar5 + 1);
                  puVar7 = puVar3;
                }
                uVar8 = puVar7[1];
                goto LAB_0802816c;
              }
              puVar9 = (undefined4 *)param_1[2];
              param_1[2] = (int)(puVar9 + 1);
              uVar4 = FUN_08018174();
            }
            goto LAB_0802813a;
          }
          uVar8 = *(uint *)(DAT_080288f4 + 8);
        }
        uVar8 = (uVar8 & 0x1fffff) >> 0x14;
      }
    }
  }
LAB_0802801c:
  puVar7 = (uint *)param_1[2];
  param_1[2] = (int)(puVar7 + 1);
  *puVar7 = uVar8;
  return 1;
}



/* ===== FUN_0802817a @ 0802817a ===== */

void FUN_0802817a(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  uVar1 = DAT_08028e94;
  puVar2 = *(undefined4 **)(param_1 + 4);
  puVar4 = *(undefined4 **)(param_1 + 8);
  *(undefined4 **)(param_1 + 4) = puVar2 + 1;
  uVar3 = *puVar2;
  *puVar4 = uVar1;
  *(undefined4 **)(param_1 + 8) = puVar4 + 2;
  uVar1 = FUN_08027a4c(param_1,uVar3);
  puVar4[1] = uVar1;
  return;
}



/* ===== FUN_0802819c @ 0802819c ===== */

void FUN_0802819c(int param_1)

{
  undefined4 uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  
  uVar1 = DAT_08028ec4;
  puVar2 = *(uint **)(param_1 + 4);
  *(uint **)(param_1 + 4) = puVar2 + 1;
  uVar6 = 0;
  uVar5 = *puVar2;
  puVar3 = *(undefined4 **)(param_1 + 8);
  puVar7 = *(undefined4 **)(param_1 + 4);
  *puVar3 = uVar1;
  *(undefined4 **)(param_1 + 8) = puVar3 + 2;
  uVar8 = 0;
  if (uVar5 != 0) {
    do {
      iVar4 = FUN_08027a4c(param_1,*puVar7);
      if (iVar4 != 0) {
        uVar6 = uVar6 | 1 << (uVar8 & 0xff);
      }
      uVar8 = uVar8 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar8 < uVar5);
  }
  puVar3[1] = uVar6;
  return;
}



/* ===== FUN_08028264 @ 08028264 ===== */

undefined4 FUN_08028264(undefined4 param_1,int param_2,uint param_3)

{
  undefined1 uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  undefined4 *puVar5;
  undefined2 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  undefined4 uVar18;
  byte bVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  undefined8 uVar23;
  
  puVar4 = DAT_08029004;
  puVar3 = DAT_080288f8;
  iVar2 = DAT_080288f4;
  if (param_2 == 0x500) {
    if (-1 < (int)(param_3 << 0x1f)) {
      param_3 = param_3 & 0xfffffffd;
    }
    if ((int)(param_3 << 0x1f) < 0) {
      uVar18 = 1;
    }
    else {
      uVar18 = 2;
    }
    FUN_08018132(uVar18);
    iVar2 = DAT_080288f4;
    *(uint *)(DAT_080288f4 + 8) =
         *(uint *)(DAT_080288f4 + 8) & 0xffffffdf | (param_3 >> 1 & 1 ^ 1) << 5;
    FUN_080275c4(param_3 >> 2 & 1);
    puVar3 = DAT_08029004;
    if ((int)(param_3 << 0x1c) < 0) {
      *DAT_080288f8 = *DAT_080288f8 | 0x80;
      puVar3[2] = puVar3[2] | 1;
    }
    else {
      *DAT_080288f8 = *DAT_080288f8 & 0xffffff7f;
      FUN_0801643e();
    }
    FUN_080275fc(param_3 >> 4 & 1);
    puVar5 = DAT_08029008;
    uVar20 = *(uint *)(iVar2 + 8);
    if ((int)(param_3 << 0x1a) < 0) {
      *(uint *)(iVar2 + 8) = uVar20 | 0x80000;
      if ((int)(uVar20 << 0xd) < 0) {
        puVar5[4] = 0x2000;
        goto LAB_080287cc;
      }
    }
    else {
      *(uint *)(iVar2 + 8) = uVar20 & 0xfff7ffff;
    }
    *puVar5 = 0x2000;
    goto LAB_080287cc;
  }
  uVar1 = (undefined1)param_3;
  if (param_2 == 0x502) {
    iVar7 = FUN_08015b04(param_3 & 0xff,1);
    iVar2 = DAT_0802900c;
    *DAT_0802892c = (char)iVar7;
    *DAT_08029010 = *(undefined4 *)(iVar2 + iVar7 * 4);
    return 1;
  }
  if (param_2 == 0x503) {
    if (param_3 == 0) {
      uVar18 = 2;
    }
    else {
      uVar18 = 1;
    }
    FUN_08018132(uVar18);
    return 1;
  }
  if (param_2 == 0x504) {
    if (param_3 == 0) {
      uVar23 = FUN_0802759a();
      *DAT_08028928 = uVar23;
      return 1;
    }
    return 1;
  }
  if (param_2 == 0x510) {
    uVar21 = *(uint *)(DAT_080288f4 + 8);
    uVar20 = (param_3 & 1 ^ 1) << 5;
    *(uint *)(DAT_080288f4 + 8) = uVar21 & 0xffffffdf | uVar20;
    *(uint *)(iVar2 + 8) = uVar21 & 0xffffff9f | uVar20 | (param_3 >> 1 & 1) << 6;
    uVar20 = (param_3 & 0xf) >> 2;
    if (uVar20 != ((byte)DAT_080288f8[1] & 3)) {
      *(byte *)(DAT_080288f8 + 1) = (byte)DAT_080288f8[1] & 0xfc | (byte)uVar20;
      if (uVar20 == 0) {
        FUN_0801b5d4();
LAB_08028480:
        FUN_0801b4aa();
      }
      else if (uVar20 == 2) {
        FUN_0801b498();
      }
      else if (uVar20 < 2) goto LAB_08028480;
    }
    param_3 = (param_3 & 0x3f) >> 4;
LAB_080284c6:
    FUN_08027620(param_3);
  }
  else {
    if (param_2 == 0x511) {
      if ((byte)DAT_0802892c[1] == param_3) {
        return 1;
      }
      DAT_0802892c[1] = uVar1;
      FUN_0801b57c(1);
      return 1;
    }
    if (param_2 == 0x512) {
      DAT_0802892c[2] = uVar1;
      return 1;
    }
    if (param_2 == 0x513) {
      DAT_0802892c[5] = uVar1;
      return 1;
    }
    if (param_2 == 0x514) {
      uVar20 = *(uint *)(DAT_080288f4 + 8) & 0xffffffdf | (param_3 & 1 ^ 1) << 5;
    }
    else {
      if (param_2 == 0x515) {
        param_3 = param_3 & 0xff;
        goto LAB_080284c6;
      }
      if (param_2 == 0x516) {
        uVar20 = *(uint *)(DAT_080288f4 + 8) & 0xffffffbf | (param_3 & 1) << 6;
      }
      else {
        if (param_2 == 0x520) {
          uVar21 = *DAT_080288f8;
          uVar20 = (param_3 & 1) << 9;
          *DAT_080288f8 = uVar21 & 0xfffffdff | uVar20;
          if ((param_3 & 1) == 0) {
            uVar22 = *puVar4 & 0xfffffffd;
          }
          else {
            uVar22 = *puVar4 | 2;
          }
          uVar9 = param_3 >> 1 & 1;
          *puVar4 = uVar22;
          uVar22 = uVar9 << 10;
          *puVar3 = uVar21 & 0xfffff9ff | uVar20 | uVar22;
          if (uVar9 == 0) {
            uVar9 = *puVar4 & 0xfffffffb;
          }
          else {
            uVar9 = *puVar4 | 4;
          }
          uVar10 = param_3 >> 10 & 1;
          *puVar4 = uVar9;
          uVar9 = uVar10 << 0xb;
          *puVar3 = uVar21 & 0xfffff1ff | uVar20 | uVar22 | uVar9;
          if (uVar10 == 0) {
            uVar10 = *puVar4 & 0xfffffdff;
          }
          else {
            uVar10 = *puVar4 | 0x200;
          }
          uVar11 = param_3 >> 0xb & 1;
          *puVar4 = uVar10;
          uVar10 = uVar11 << 0xc;
          *puVar3 = uVar21 & 0xffffe1ff | uVar20 | uVar22 | uVar9 | uVar10;
          if (uVar11 == 0) {
            uVar11 = *puVar4 & 0xfffffbff;
          }
          else {
            uVar11 = *puVar4 | 0x400;
          }
          uVar12 = param_3 >> 0xc & 1;
          *puVar4 = uVar11;
          uVar11 = uVar12 << 0xd;
          *puVar3 = uVar21 & 0xffffc1ff | uVar20 | uVar22 | uVar9 | uVar10 | uVar11;
          if (uVar12 == 0) {
            uVar12 = *puVar4 & 0xfffff7ff;
          }
          else {
            uVar12 = *puVar4 | 0x800;
          }
          uVar13 = param_3 >> 2 & 1;
          *puVar4 = uVar12;
          uVar12 = uVar13 << 0xe;
          *puVar3 = uVar21 & 0xffff81ff | uVar20 | uVar22 | uVar9 | uVar10 | uVar11 | uVar12;
          if (uVar13 == 0) {
            uVar13 = *puVar4 & 0xfffffff7;
          }
          else {
            uVar13 = *puVar4 | 8;
          }
          uVar14 = param_3 >> 3 & 1;
          *puVar4 = uVar13;
          uVar13 = uVar14 << 0xf;
          *puVar3 = uVar21 & 0xffff01ff | uVar20 | uVar22 | uVar9 | uVar10 | uVar11 | uVar12 |
                    uVar13;
          if (uVar14 == 0) {
            uVar14 = *puVar4 & 0xffffffef;
          }
          else {
            uVar14 = *puVar4 | 0x10;
          }
          uVar15 = param_3 >> 4 & 1;
          *puVar4 = uVar14;
          uVar14 = uVar15 << 0x10;
          *puVar3 = uVar21 & 0xfffe01ff | uVar20 | uVar22 | uVar9 | uVar10 | uVar11 | uVar12 |
                    uVar13 | uVar14;
          if (uVar15 == 0) {
            uVar15 = *puVar4 & 0xffffffdf;
          }
          else {
            uVar15 = *puVar4 | 0x20;
          }
          uVar16 = param_3 >> 5 & 1;
          *puVar4 = uVar15;
          uVar15 = uVar16 << 0x11;
          *puVar3 = uVar21 & 0xfffc01ff | uVar20 | uVar22 | uVar9 | uVar10 | uVar11 | uVar12 |
                    uVar13 | uVar14 | uVar15;
          if (uVar16 == 0) {
            uVar16 = *puVar4 & 0xffffffbf;
          }
          else {
            uVar16 = *puVar4 | 0x40;
          }
          uVar17 = param_3 >> 6 & 1;
          *puVar4 = uVar16;
          uVar16 = uVar17 << 0x12;
          *puVar3 = uVar21 & 0xfff801ff | uVar20 | uVar22 | uVar9 | uVar10 | uVar11 | uVar12 |
                    uVar13 | uVar14 | uVar15 | uVar16;
          if (uVar17 == 0) {
            uVar17 = *puVar4 & 0xffffff7f;
          }
          else {
            uVar17 = *puVar4 | 0x80;
          }
          uVar8 = param_3 >> 7 & 1;
          *puVar4 = uVar17;
          *puVar3 = uVar21 & 0xfff001ff | uVar20 | uVar22 | uVar9 | uVar10 | uVar11 | uVar12 |
                    uVar13 | uVar14 | uVar15 | uVar16 | uVar8 << 0x13;
          if (uVar8 == 0) {
            uVar20 = *puVar4 & 0xfffffeff;
          }
          else {
            uVar20 = *puVar4 | 0x100;
          }
          *puVar4 = uVar20;
          uVar22 = puVar3[1];
          uVar21 = param_3 >> 8 & 1;
          uVar20 = uVar21 << 0xf;
          puVar3[1] = uVar22 & 0xffff7fff | uVar20;
          if (uVar21 == 0) {
            uVar21 = *puVar4 & 0xffffefff;
          }
          else {
            uVar21 = *puVar4 | 0x1000;
          }
          uVar9 = param_3 >> 9 & 1;
          *puVar4 = uVar21;
          puVar3[1] = uVar22 & 0xfffe7fff | uVar20 | uVar9 << 0x10;
          if (uVar9 == 0) {
            uVar20 = *puVar4 & 0xffffdfff;
          }
          else {
            uVar20 = *puVar4 | 0x2000;
          }
          *puVar4 = uVar20;
LAB_080287cc:
          uVar6 = FUN_0801862e();
          uVar23 = FUN_0802759a();
          FUN_08018a4c((int)uVar23,(int)((ulonglong)uVar23 >> 0x20),uVar6,3);
          return 1;
        }
        if (param_2 == 0x521) {
          DAT_0802892c[4] = uVar1;
          return 1;
        }
        if (param_2 == 0x522) {
          FUN_080275c4(param_3);
          goto LAB_080287cc;
        }
        if (param_2 == 0x530) {
          uVar21 = *DAT_080288f8;
          uVar20 = (param_3 & 1) << 0x15;
          *DAT_080288f8 = uVar21 & 0xffdfffff | uVar20;
          if ((param_3 & 1) == 0) {
            uVar22 = puVar4[1] & 0xfffffffd;
          }
          else {
            uVar22 = puVar4[1] | 2;
          }
          uVar9 = param_3 >> 1 & 1;
          puVar4[1] = uVar22;
          uVar22 = uVar9 << 0x16;
          *puVar3 = uVar21 & 0xff9fffff | uVar20 | uVar22;
          if (uVar9 == 0) {
            uVar9 = puVar4[1] & 0xfffffffb;
          }
          else {
            uVar9 = puVar4[1] | 4;
          }
          uVar10 = param_3 >> 10 & 1;
          puVar4[1] = uVar9;
          uVar9 = uVar10 << 0x17;
          *puVar3 = uVar21 & 0xff1fffff | uVar20 | uVar22 | uVar9;
          if (uVar10 == 0) {
            uVar10 = puVar4[1] & 0xfffffdff;
          }
          else {
            uVar10 = puVar4[1] | 0x200;
          }
          uVar11 = param_3 >> 0xb & 1;
          puVar4[1] = uVar10;
          uVar10 = uVar11 << 0x18;
          *puVar3 = uVar21 & 0xfe1fffff | uVar20 | uVar22 | uVar9 | uVar10;
          if (uVar11 == 0) {
            uVar11 = puVar4[1] & 0xfffffbff;
          }
          else {
            uVar11 = puVar4[1] | 0x400;
          }
          uVar12 = param_3 >> 0xc & 1;
          puVar4[1] = uVar11;
          uVar11 = uVar12 << 0x19;
          *puVar3 = uVar21 & 0xfc1fffff | uVar20 | uVar22 | uVar9 | uVar10 | uVar11;
          if (uVar12 == 0) {
            uVar12 = puVar4[1] & 0xfffff7ff;
          }
          else {
            uVar12 = puVar4[1] | 0x800;
          }
          uVar13 = param_3 >> 2 & 1;
          puVar4[1] = uVar12;
          uVar12 = uVar13 << 0x1a;
          *puVar3 = uVar21 & 0xf81fffff | uVar20 | uVar22 | uVar9 | uVar10 | uVar11 | uVar12;
          if (uVar13 == 0) {
            uVar13 = puVar4[1] & 0xfffffff7;
          }
          else {
            uVar13 = puVar4[1] | 8;
          }
          uVar14 = param_3 >> 3 & 1;
          puVar4[1] = uVar13;
          uVar13 = uVar14 << 0x1b;
          *puVar3 = uVar21 & 0xf01fffff | uVar20 | uVar22 | uVar9 | uVar10 | uVar11 | uVar12 |
                    uVar13;
          if (uVar14 == 0) {
            uVar14 = puVar4[1] & 0xffffffef;
          }
          else {
            uVar14 = puVar4[1] | 0x10;
          }
          uVar15 = param_3 >> 4 & 1;
          puVar4[1] = uVar14;
          uVar14 = uVar15 << 0x1c;
          *puVar3 = uVar21 & 0xe01fffff | uVar20 | uVar22 | uVar9 | uVar10 | uVar11 | uVar12 |
                    uVar13 | uVar14;
          if (uVar15 == 0) {
            uVar15 = puVar4[1] & 0xffffffdf;
          }
          else {
            uVar15 = puVar4[1] | 0x20;
          }
          uVar16 = param_3 >> 5 & 1;
          puVar4[1] = uVar15;
          uVar15 = uVar16 << 0x1d;
          *puVar3 = uVar21 & 0xc01fffff | uVar20 | uVar22 | uVar9 | uVar10 | uVar11 | uVar12 |
                    uVar13 | uVar14 | uVar15;
          if (uVar16 == 0) {
            uVar16 = puVar4[1] & 0xffffffbf;
          }
          else {
            uVar16 = puVar4[1] | 0x40;
          }
          uVar17 = param_3 >> 6 & 1;
          puVar4[1] = uVar16;
          uVar16 = uVar17 << 0x1e;
          *puVar3 = uVar21 & 0x801fffff | uVar20 | uVar22 | uVar9 | uVar10 | uVar11 | uVar12 |
                    uVar13 | uVar14 | uVar15 | uVar16;
          if (uVar17 == 0) {
            uVar17 = puVar4[1] & 0xffffff7f;
          }
          else {
            uVar17 = puVar4[1] | 0x80;
          }
          puVar4[1] = uVar17;
          *puVar3 = uVar21 & 0x1fffff | uVar20 | uVar22 | uVar9 | uVar10 | uVar11 | uVar12 | uVar13
                    | uVar14 | uVar15 | uVar16 | (param_3 >> 7) << 0x1f;
          if ((param_3 >> 7 & 1) == 0) {
            uVar20 = puVar4[1] & 0xfffffeff;
          }
          else {
            uVar20 = puVar4[1] | 0x100;
          }
          puVar4[1] = uVar20;
          return 1;
        }
        if (param_2 == 0x531) {
          FUN_080275fc(param_3);
          goto LAB_080287cc;
        }
        if (param_2 == 0x5e0) {
          DAT_080288f8[1] = DAT_080288f8[1] & 0xffffffdf | (param_3 & 1) << 5;
          return 1;
        }
        if (param_2 == 0x5e1) {
          uVar18 = FUN_080163c4(param_3);
          return uVar18;
        }
        if (param_2 == 0x700) {
          FUN_0801d224(param_3);
          return 1;
        }
        if (param_2 == 0x8000) {
          FUN_0801d248(param_3);
          return 1;
        }
        if (param_2 == 0x8001) {
          FUN_0801d26e(param_3);
          return 1;
        }
        if (param_2 == 0x8002) {
          param_3 = param_3 * 100;
LAB_08028812:
          FUN_0801d298(param_3);
          return 1;
        }
        if (param_2 == 0x8003) {
          param_3 = param_3 * 100;
LAB_0802881c:
          FUN_0801d2bc(param_3);
          return 1;
        }
        if (param_2 == 0x8004) {
          uVar20 = *DAT_080288f8 & 0xfffffffe | param_3 & 1;
LAB_0802884e:
          *DAT_080288f8 = uVar20;
          return 1;
        }
        if (param_2 == 0x8005) {
          uVar20 = *DAT_080288f8 & 0xffffff9f | (param_3 & 3) << 5;
          goto LAB_0802884e;
        }
        if (param_2 == 0x8007) {
          FUN_0801b1ec(param_3);
          return 1;
        }
        if (param_2 == 0x8008) {
          if (param_3 == 0) {
            param_3 = *(uint *)(DAT_080292b4 + 0x40);
          }
          FUN_0801d2e4(param_3);
          return 1;
        }
        if (param_2 == 0x8009) {
          if (param_3 == 0) {
            param_3 = *(uint *)(DAT_080292b4 + 0x44);
          }
          FUN_0801d308(param_3);
          return 1;
        }
        if (param_2 == 0x800c) {
          uVar20 = *DAT_080288f8 & 0xfffffff7 | (param_3 & 1) << 3;
          goto LAB_0802884e;
        }
        if (param_2 == 0x8013) {
          uVar20 = 0;
          if (param_3 == 0) {
            uVar20 = 4;
          }
          uVar20 = uVar20 | *DAT_080288f8 & 0xfffffffb;
          goto LAB_0802884e;
        }
        if (param_2 == 0x8014) goto LAB_08028812;
        if (param_2 == 0x8015) goto LAB_0802881c;
        if (param_2 == 0x8016) {
          bVar19 = 0;
          if (param_3 == 1) {
            bVar19 = 2;
          }
          *(byte *)DAT_080288f8 = bVar19 | (byte)*DAT_080288f8 & 0xfd;
          return 1;
        }
        if (param_2 == 0xc000) {
          if (*(int *)(DAT_080288f4 + 8) << 0xb < 0) {
            FUN_08017038(param_3);
            return 1;
          }
          return 1;
        }
        if (param_2 == 0xc001) {
          FUN_0801769c((int)(short)param_3);
          return 1;
        }
        if (param_2 != 0xc002) {
          if (param_2 == 0xc004) {
            if (*(int *)(DAT_080288f4 + 8) << 0xb < 0) {
              FUN_0801f63a();
              FUN_08022c84(param_3);
              return 1;
            }
            return 1;
          }
          if (param_2 != 0xc005) {
            return 0;
          }
          if (*(int *)(DAT_080288f4 + 8) << 0xb < 0) {
            FUN_0801f63a();
            FUN_08022ce0(param_3);
            return 1;
          }
          return 1;
        }
        if (param_3 == 0) {
          *DAT_080292b8 = 0xffff;
        }
        uVar20 = *(uint *)(DAT_080288f4 + 8) & 0xffefffff | (param_3 & 1) << 0x14;
      }
    }
    *(uint *)(DAT_080288f4 + 8) = uVar20;
  }
  return 1;
}



/* ===== FUN_080288fc @ 080288fc ===== */

undefined4 FUN_080288fc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  uVar1 = DAT_080292bc;
  puVar2 = *(undefined4 **)(param_1 + 4);
  puVar6 = *(undefined4 **)(param_1 + 8);
  *(undefined4 **)(param_1 + 4) = puVar2 + 1;
  puVar4 = *(undefined4 **)(param_1 + 4);
  uVar3 = *puVar2;
  *(undefined4 **)(param_1 + 4) = puVar4 + 1;
  uVar5 = *puVar4;
  *puVar6 = uVar1;
  *(undefined4 **)(param_1 + 8) = puVar6 + 2;
  uVar1 = FUN_08028264(param_1,uVar3,uVar5);
  puVar6[1] = uVar1;
  return param_4;
}



/* ===== FUN_08028930 @ 08028930 ===== */

undefined4 FUN_08028930(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  
  uVar1 = DAT_080292c0;
  puVar3 = *(uint **)(param_1 + 4);
  *(uint **)(param_1 + 4) = puVar3 + 1;
  uVar7 = 0;
  uVar6 = *puVar3;
  puVar4 = *(undefined4 **)(param_1 + 8);
  puVar5 = *(undefined4 **)(param_1 + 4);
  *puVar4 = uVar1;
  puVar9 = puVar5 + uVar6;
  *(undefined4 **)(param_1 + 8) = puVar4 + 2;
  uVar8 = 0;
  if (uVar6 != 0) {
    do {
      iVar2 = FUN_08028264(param_1,*puVar5,*puVar9);
      if (iVar2 != 0) {
        uVar7 = uVar7 | 1 << (uVar8 & 0xff);
      }
      uVar8 = uVar8 + 1;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    } while (uVar8 < uVar6);
  }
  puVar4[1] = uVar7;
  return param_4;
}



/* ===== FUN_08028984 @ 08028984 ===== */

longlong FUN_08028984(int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  uint *puVar7;
  uint *puVar6;
  int *piVar8;
  int iVar9;
  int *piVar10;
  undefined *puVar11;
  uint *puVar12;
  uint *puVar13;
  uint unaff_r7;
  uint uVar14;
  uint uVar15;
  undefined1 *puVar16;
  undefined8 uVar17;
  longlong lVar18;
  int *local_4c;
  undefined1 auStack_48 [32];
  int *piStack_28;
  int *piStack_18;
  
  piVar10 = DAT_080292d8;
  puVar11 = DAT_080292d4;
  uVar4 = DAT_080292d0;
  puVar12 = DAT_08019778;
  iVar3 = DAT_08019740;
  puVar6 = DAT_08018d0c;
  uVar14 = 0;
  piStack_18 = param_4;
  if (param_2 == 2) {
    uVar14 = 0xcb8;
    puVar11 = DAT_080292c4;
LAB_080289d6:
    if ((int)param_4 < (int)uVar14) {
      return ZEXT48(piStack_18) << 0x20;
    }
    if ((puVar11 != (undefined *)0x0) && (0 < (int)uVar14)) {
      FUN_0802498c(param_3,puVar11,uVar14);
    }
    return CONCAT44(piStack_18,uVar14);
  }
  if (param_2 == 8) {
    uVar14 = FUN_0802beb0(DAT_080292d4);
    if (0x20 < uVar14) {
      uVar14 = 0x20;
    }
    goto LAB_080289d6;
  }
  if (param_2 == 0xd) {
    puVar11 = &UNK_08028d18;
    goto LAB_080289d6;
  }
  if (param_2 == 0xf) {
    iVar3 = 0;
    piVar10 = param_3;
    local_4c = param_4;
    piStack_28 = param_4;
LAB_08024ad6:
    do {
      if ((int)puVar6[0x16] < 1) {
LAB_08024b44:
        return CONCAT44(param_3,iVar3);
      }
      iVar2 = puVar6[0x15] - puVar6[0x16];
      iVar9 = iVar2 + 1;
      if (iVar9 < 0) {
        iVar9 = iVar2 + 9;
      }
      puVar12 = (uint *)(puVar6[0x14] + iVar9 * 0x20);
      uVar14 = *puVar12 - *DAT_08024bb4;
      param_3 = (int *)((puVar12[1] - DAT_08024bb4[1]) - (uint)(*puVar12 < *DAT_08024bb4));
      if ((int)param_3 < 0) {
        uVar15 = -uVar14;
        piVar5 = (int *)(-(int)param_3 - (uint)(uVar14 != 0));
      }
      else {
        uVar15 = uVar14;
        piVar5 = param_3;
      }
      if ((0xa3 < (int)piVar5) || ((0xa2 < (int)piVar5 && (DAT_08024bb8 <= uVar15)))) {
        puVar6[0x1b] = puVar6[0x1b] + 1;
        piVar5 = local_4c;
LAB_08024baa:
        local_4c = piVar5;
        puVar6[0x16] = puVar6[0x16] - 1;
        goto LAB_08024ad6;
      }
      uVar4 = FUN_080186c0(uVar14,param_3,10000,4);
      if (puVar6[0x1b] == 0) {
        puVar16 = (undefined1 *)puVar12[2];
      }
      else {
        FUN_08016bd4(auStack_48,0x1f,DAT_08024bbc);
        puVar16 = auStack_48;
      }
      if ((int)local_4c < 0x100) {
        uVar17 = FUN_08018712();
        param_3 = (int *)((ulonglong)uVar17 >> 0x20);
        *(undefined8 *)(puVar6 + 0x17) = uVar17;
        *puVar6 = *puVar6 | 8;
        goto LAB_08024b44;
      }
      iVar2 = FUN_08016bd4(piVar10,10,DAT_08024bc0,uVar4);
      iVar9 = FUN_08016bd4((int)piVar10 + iVar2,0xf3,puVar16,puVar12[3],puVar12[4],puVar12[5],
                           puVar12[6]);
      iVar9 = (int)piVar10 + iVar2 + iVar9;
      iVar2 = FUN_08016bd4(iVar9,3,DAT_08024bc4);
      piVar8 = (int *)(iVar9 + iVar2);
      iVar3 = iVar3 + ((int)piVar8 - (int)piVar10);
      piVar5 = (int *)((int)local_4c - ((int)piVar8 - (int)piVar10));
      param_3 = local_4c;
      piVar10 = piVar8;
      if (puVar6[0x1b] == 0) goto LAB_08024baa;
      puVar6[0x1b] = 0;
      local_4c = piVar5;
    } while( true );
  }
  if (param_2 == 0xf0) {
LAB_08028a82:
    lVar18 = FUN_0801cfc6(param_3,param_4,param_4);
    return lVar18;
  }
  if (param_2 == 0xf1) {
    if ((param_4 == (int *)0x0) || (((uint)param_4 & 3) != 0)) {
      piVar10 = (int *)0xffffffff;
    }
    else {
      iVar3 = *DAT_080292d8;
      for (iVar2 = (int)param_4 >> 2; iVar2 != 0; iVar2 = iVar2 + -1) {
        *param_3 = iVar3;
        iVar3 = iVar3 + 1;
        param_3 = param_3 + 1;
      }
      *piVar10 = iVar3;
      puVar6 = DAT_080292dc;
      *DAT_080292dc = *DAT_080292dc | 0x100;
      *DAT_080292e0 = *piVar10 + -1;
      *puVar6 = *puVar6 & 0xfffffeff;
      piVar10 = param_4;
    }
    return CONCAT44(param_4,piVar10);
  }
  if (param_2 == 0x100) {
    piStack_28 = (int *)DAT_080292d0;
    *(undefined4 *)(param_1 + 0x14) = DAT_080292cc;
    if (0x400 < (int)param_4) {
      param_4 = (int *)0x400;
    }
    *(undefined4 *)(param_1 + 0x18) = uVar4;
    iVar3 = DAT_08018d10;
    puVar6 = DAT_08018d0c;
    iVar2 = 0;
    do {
      if (*puVar6 == 0) {
LAB_08018c12:
        iVar9 = FUN_08024cbc(iVar3,param_3,param_4);
        if ((iVar9 == 0) && (iVar9 = FUN_08024f28(iVar3 + 0xc,param_3,param_4), iVar9 == 0)) {
          iVar9 = FUN_08018dbc(iVar3 + 0x18,param_3,param_4);
        }
      }
      else {
        iVar1 = FUN_08024bc8(puVar6,0,param_3,param_4);
        iVar9 = 0;
        piVar10 = param_4;
        piVar5 = param_3;
        if (iVar1 != 0) {
          piVar10 = (int *)((int)param_4 - iVar1);
          piVar5 = (int *)((int)param_3 + iVar1);
          iVar9 = iVar1;
        }
        iVar1 = FUN_08024bc8(puVar6,1,piVar5,piVar10);
        if (iVar1 != 0) {
          iVar9 = iVar1 + iVar9;
          piVar10 = (int *)((int)piVar10 - iVar1);
          piVar5 = (int *)((int)piVar5 + iVar1);
        }
        iVar1 = FUN_08024bc8(puVar6,2,piVar5,piVar10);
        if (iVar1 != 0) {
          iVar9 = iVar1 + iVar9;
          piVar10 = (int *)((int)piVar10 - iVar1);
          piVar5 = (int *)((int)piVar5 + iVar1);
        }
        iVar1 = FUN_08024bc8(puVar6,3,piVar5,piVar10);
        if (iVar1 != 0) {
          iVar9 = iVar1 + iVar9;
        }
        if (iVar9 == 0) goto LAB_08018c12;
      }
      if (iVar9 == 0) break;
      iVar2 = iVar9 + iVar2;
      param_3 = (int *)((int)param_3 + iVar9);
      param_4 = (int *)((int)param_4 - iVar9);
    } while (iVar2 < 0x400);
    return CONCAT44(piStack_28,iVar2);
  }
  if (param_2 == 0x101) {
    uVar14 = 0x1242;
    puVar11 = DAT_080292c8;
    goto LAB_080289d6;
  }
  if (param_2 == 0x200) {
    if ((int)param_4 < 0x14) {
      return ZEXT48(param_4) << 0x20;
    }
    iVar2 = FUN_08025a30(*(uint *)(DAT_08019740 + 0x10) + 500,
                         *(int *)(DAT_08019740 + 0x14) +
                         (uint)(0xfffffe0b < *(uint *)(DAT_08019740 + 0x10)),1000,0);
    *param_3 = iVar2;
    FUN_0802498c(param_3 + 1,DAT_0801977c,0xc);
    param_3[4] = 0;
    iVar3 = FUN_0802667c(param_3 + 5,iVar3 + 0x34,0x400);
  }
  else {
    if (param_2 == 0x202) {
      FUN_0802498c(param_3,DAT_0801d3ac,0xc);
      return CONCAT44(unaff_r7,0xc);
    }
    if (param_2 == 0x203) goto LAB_08028a82;
    if (param_2 != 0x205) {
      if (param_2 == 0x206) {
        lVar18 = FUN_080194ea(param_3,param_4,param_4);
        return lVar18;
      }
      if (param_2 != 0x207) {
        if (param_2 == 0x208) {
          uVar14 = 0x80000000;
          puVar13 = DAT_08019778 + 0x400;
          puVar6 = DAT_08019778;
          do {
            puVar7 = puVar6 + 1;
            *puVar6 = uVar14;
            if (uVar14 < 0x201) {
              if (uVar14 < 0x21) {
                if (uVar14 != 0) {
                  uVar14 = uVar14 - 4;
                }
              }
              else {
                uVar14 = uVar14 - 0x20;
              }
            }
            else {
              uVar14 = uVar14 >> 1;
            }
            puVar6 = puVar7;
          } while (puVar7 < puVar13);
          iVar3 = FUN_0802667c(param_3,puVar12,0x400);
          if (iVar3 == 0) {
            return CONCAT44(param_4,0xffffffff);
          }
          return CONCAT44(param_4,iVar3 - (int)param_3);
        }
        if (param_2 != 0x220) {
          return CONCAT44(param_4,0xffffffff);
        }
        if ((int)param_4 < 0x10) {
          return (ulonglong)unaff_r7 << 0x20;
        }
        FUN_0802498c(param_3,DAT_0801b26c,0x10);
        return CONCAT44(unaff_r7,0x10);
      }
      if ((int)param_4 < 8) {
        return ZEXT48(param_4) << 0x20;
      }
      iVar2 = FUN_08025a74(*(uint *)(DAT_08019740 + 0x18) + 500,
                           *(int *)(DAT_08019740 + 0x1c) +
                           (uint)(0xfffffe0b < *(uint *)(DAT_08019740 + 0x18)),1000,0);
      *param_3 = iVar2;
      param_3[1] = 0;
      iVar3 = FUN_0802667c(param_3 + 2,iVar3 + 0x1034,0x400);
      if (iVar3 != 0) {
        return CONCAT44(piStack_18,(iVar3 - (int)(param_3 + 2)) + 8);
      }
      goto LAB_08019664;
    }
    if ((int)param_4 < 0x14) {
      return ZEXT48(param_4) << 0x20;
    }
    uVar14 = *(uint *)(DAT_08019740 + 0x18) + *(uint *)(DAT_08019740 + 0x10);
    iVar2 = FUN_08025a74(uVar14 + 500,
                         *(int *)(DAT_08019740 + 0x14) + *(int *)(DAT_08019740 + 0x1c) +
                         (uint)CARRY4(*(uint *)(DAT_08019740 + 0x18),*(uint *)(DAT_08019740 + 0x10))
                         + (uint)(0xfffffe0b < uVar14),1000,0);
    *param_3 = iVar2;
    FUN_0802498c(param_3 + 1,DAT_0801977c,0xc);
    param_3[4] = 0;
    *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x18) + *(uint *)(iVar3 + 0x10);
    *(uint *)(iVar3 + 0x24) =
         *(int *)(iVar3 + 0x14) + *(int *)(iVar3 + 0x1c) +
         (uint)CARRY4(*(uint *)(iVar3 + 0x18),*(uint *)(iVar3 + 0x10));
    *(int *)(iVar3 + 0x30) = *(int *)(iVar3 + 0x28) + *(int *)(iVar3 + 0x2c);
    puVar6 = DAT_08019778;
    piVar5 = (int *)(iVar3 + 0x34);
    puVar12 = (uint *)(iVar3 + 0x2034);
    piVar8 = (int *)(iVar3 + 0x1034);
    piVar10 = piVar8;
    puVar13 = DAT_08019778;
    if ((int *)(iVar3 + 0x34U) < piVar8) {
      for (; piVar5 < piVar8; piVar5 = piVar5 + 1) {
        iVar3 = *piVar5;
        iVar2 = *piVar10;
        *puVar12 = iVar3 + iVar2;
        *puVar13 = iVar3 + iVar2;
        piVar10 = piVar10 + 1;
        puVar12 = puVar12 + 1;
        puVar13 = puVar13 + 1;
      }
    }
    iVar3 = FUN_0802667c(param_3 + 5,puVar6,0x400);
  }
  if (iVar3 != 0) {
    return CONCAT44(piStack_18,(iVar3 - (int)(param_3 + 5)) + 0x14);
  }
LAB_08019664:
  return CONCAT44(piStack_18,0xffffffff);
}



/* ===== FUN_08028b40 @ 08028b40 ===== */

void FUN_08028b40(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  
  uVar1 = DAT_080292e8;
  puVar2 = (uint *)param_1[1];
  param_1[1] = (int)(puVar2 + 1);
  puVar5 = (undefined4 *)param_1[2];
  uVar3 = *puVar2;
  puVar9 = (undefined4 *)param_1[1];
  puVar2 = puVar5 + 1;
  *puVar5 = uVar1;
  piVar7 = puVar5 + 3;
  param_1[2] = (int)piVar7;
  piVar6 = puVar5 + 2;
  uVar10 = 0;
  iVar8 = *(int *)(*param_1 + 8) + (*(int *)(*param_1 + 0x10) - (int)piVar7);
  uVar11 = 0;
  if (uVar3 != 0) {
    do {
      iVar4 = FUN_08028984(param_1,*puVar9,piVar7,iVar8,puVar2,uVar3,param_4);
      if (0 < iVar4) {
        *piVar6 = iVar4;
        piVar6 = (int *)((int)piVar7 + iVar4);
        piVar7 = piVar6 + 1;
        uVar10 = 1 << (uVar11 & 0xff) | uVar10;
        param_1[2] = (int)piVar7;
        iVar8 = (iVar8 - iVar4) + -4;
      }
      uVar11 = uVar11 + 1;
      puVar9 = puVar9 + 1;
    } while (uVar11 < uVar3);
    if (uVar10 != 0) {
      iVar8 = -4;
      goto LAB_08028bc4;
    }
  }
  iVar8 = -8;
LAB_08028bc4:
  param_1[2] = iVar8 + param_1[2];
  *puVar2 = uVar10;
  return;
}



/* ===== FUN_08028bd6 @ 08028bd6 ===== */

undefined4 FUN_08028bd6(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint *puVar6;
  int *piVar7;
  uint uVar8;
  
  piVar2 = *(int **)(param_1 + 4);
  *(int **)(param_1 + 4) = piVar2 + 1;
  puVar6 = *(uint **)(param_1 + 4);
  iVar3 = *piVar2;
  *(uint **)(param_1 + 4) = puVar6 + 1;
  piVar1 = DAT_080292d8;
  piVar2 = DAT_08028dd8;
  uVar8 = *puVar6;
  piVar7 = *(int **)(param_1 + 4);
  if (iVar3 == 0xf1) {
    if ((uVar8 != 0) && ((uVar8 & 3) == 0)) {
      iVar3 = *piVar7;
      uVar8 = (int)uVar8 >> 2;
      for (uVar4 = uVar8; uVar4 != 0; uVar4 = uVar4 - 1) {
        if (iVar3 != *piVar7) {
          *DAT_080292d8 = iVar3;
          uVar8 = 0xfffffffe;
          goto LAB_08028c76;
        }
        iVar3 = iVar3 + 1;
        piVar7 = piVar7 + 1;
      }
      *DAT_080292d8 = iVar3;
      puVar6 = DAT_080292dc;
      *DAT_080292dc = *DAT_080292dc | 0x100;
      *piVar2 = *piVar1;
      *puVar6 = *puVar6 & 0xfffffeff;
      goto LAB_08028c76;
    }
LAB_08028c72:
    uVar8 = 0xffffffff;
  }
  else {
    if (iVar3 != 0x200) {
      if (iVar3 == 0x202) {
        uVar8 = FUN_0801d150(piVar7,uVar8);
        goto LAB_08028c76;
      }
      if (iVar3 == 0x204) {
        uVar8 = FUN_0801cff0(piVar7,uVar8);
        goto LAB_08028c76;
      }
      if (iVar3 != 0x207) goto LAB_08028c72;
    }
    FUN_08019704(0,puVar6);
  }
LAB_08028c76:
  puVar5 = *(undefined4 **)(param_1 + 8);
  *puVar5 = DAT_080292ec;
  *(undefined4 **)(param_1 + 8) = puVar5 + 2;
  puVar5[1] = ~uVar8 >> 0x1f;
  return param_4;
}



/* ===== FUN_08028c8c @ 08028c8c ===== */

undefined4 FUN_08028c8c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined1 *puVar8;
  
  puVar1 = DAT_08028d50;
  puVar3 = *(undefined4 **)(param_1 + 8);
  *puVar3 = DAT_080292f0;
  *(undefined4 **)(param_1 + 8) = puVar3 + 2;
  piVar2 = DAT_080292f4;
  puVar3[1] = *puVar1;
  puVar6 = *(undefined1 **)(param_1 + 8);
  if ((int)((uint)*DAT_080292f8 << 0x1a) < 0) {
    iVar5 = *(int *)piVar2[5];
    if (iVar5 == 0) goto LAB_08028cea;
  }
  else {
    iVar5 = 3;
  }
  iVar7 = 0;
  do {
    puVar8 = *(undefined1 **)(*piVar2 + iVar7);
    iVar4 = FUN_0802beb0(puVar8);
    *puVar6 = (char)iVar4;
    for (; puVar6 = puVar6 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar8;
      puVar8 = puVar8 + 1;
    }
    iVar5 = iVar5 + -1;
    iVar7 = iVar7 + 4;
  } while (iVar5 != 0);
LAB_08028cea:
  *(undefined1 **)(param_1 + 8) = puVar6;
  return param_4;
}



/* ===== FUN_08028d5c @ 08028d5c ===== */

void FUN_08028d5c(int param_1)

{
  int *piVar1;
  undefined1 uVar2;
  ushort uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined4 *puVar11;
  
  puVar4 = *(undefined4 **)(param_1 + 8);
  *puVar4 = DAT_08029308;
  piVar1 = DAT_0802930c;
  *(undefined4 **)(param_1 + 8) = puVar4 + 2;
  puVar4[1] = *(undefined4 *)*piVar1;
  puVar9 = *(undefined1 **)(*piVar1 + 4);
  puVar10 = *(undefined1 **)(param_1 + 8);
  uVar2 = FUN_0802beb0(puVar9);
  puVar4 = (undefined4 *)(puVar10 + 1);
  *puVar10 = uVar2;
  uVar3 = FUN_0802beb0(puVar9);
  if (uVar3 != 0) {
    uVar5 = (uint)uVar3;
    puVar11 = puVar4;
    do {
      puVar4 = (undefined4 *)((int)puVar11 + 1);
      *(undefined1 *)puVar11 = *puVar9;
      uVar5 = uVar5 - 1;
      puVar9 = puVar9 + 1;
      puVar11 = puVar4;
    } while (uVar5 != 0);
  }
  *puVar4 = DAT_08029310;
  puVar9 = (undefined1 *)((int)puVar4 + 5);
  *(undefined1 *)(puVar4 + 1) = 0x15;
  iVar6 = 7;
  puVar10 = &DAT_08029388;
  do {
    *puVar9 = *puVar10;
    iVar6 = iVar6 + -1;
    puVar8 = puVar10 + 2;
    puVar7 = puVar9 + 2;
    puVar9[1] = puVar10[1];
    puVar10 = puVar10 + 3;
    puVar9 = puVar9 + 3;
    *puVar7 = *puVar8;
  } while (iVar6 != 0);
  *(undefined1 **)(param_1 + 8) = puVar9;
  return;
}



/* ===== FUN_08028ddc @ 08028ddc ===== */

undefined8 FUN_08028ddc(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint *puVar7;
  int *piVar8;
  uint local_20;
  undefined4 uStack_1c;
  
  uVar2 = DAT_08029314;
  puVar6 = *(undefined4 **)(param_1 + 8);
  *(undefined4 **)(param_1 + 8) = puVar6 + 1;
  *puVar6 = uVar2;
  puVar7 = *(uint **)(param_1 + 4);
  *(uint **)(param_1 + 4) = puVar7 + 1;
  uVar4 = *puVar7;
  if (1 < uVar4) {
    puVar6 = *(undefined4 **)(param_1 + 8);
    *(undefined4 **)(param_1 + 8) = puVar6 + 1;
    *puVar6 = 0xc;
    return CONCAT44(param_4,param_3);
  }
  piVar8 = *(int **)(&LAB_080293a0 + uVar4 * 4);
  iVar5 = *piVar8;
  if (iVar5 != DAT_08029318) {
    puVar6 = *(undefined4 **)(param_1 + 8);
    *(undefined4 **)(param_1 + 8) = puVar6 + 1;
    *puVar6 = 0xb;
    return CONCAT44(param_4,param_3);
  }
  puVar6 = *(undefined4 **)(param_1 + 8);
  *(undefined4 **)(param_1 + 8) = puVar6 + 1;
  *puVar6 = 0;
  local_20 = param_3;
  uStack_1c = param_4;
  uVar3 = FUN_0802757a(iVar5,0,puVar6);
  puVar7 = DAT_0802931c;
  if (uVar3 < (ushort)*DAT_0802931c) {
    uVar4 = *DAT_0802931c;
    puVar1 = DAT_0802931c + 1;
    *DAT_0802931c = uVar4 + 0x10000;
    puVar7[1] = *puVar1 + (uint)(0xfffeffff < uVar4);
  }
  *(ushort *)puVar7 = uVar3;
  puVar1 = DAT_08029320;
  uVar4 = *puVar7;
  *DAT_08029320 = uVar4;
  puVar1[1] = 0;
  puVar7 = *(uint **)(param_1 + 8);
  *(uint **)(param_1 + 8) = puVar7 + 1;
  *puVar7 = uVar4;
  local_20 = piVar8[1] & 0x7ff;
  FUN_08028e98(param_1,&local_20,4);
  FUN_08028e98(param_1,piVar8,local_20);
  return CONCAT44(uStack_1c,local_20);
}



/* ===== FUN_08028e98 @ 08028e98 ===== */

void FUN_08028e98(int param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = DAT_08029324;
  piVar2 = DAT_08029320;
  pbVar1 = *(byte **)(param_1 + 8);
  for (; param_3 != 0; param_3 = param_3 + -1) {
    iVar4 = iVar3 * *piVar2 + 1;
    *piVar2 = iVar4;
    *pbVar1 = *param_2 ^ (byte)((uint)iVar4 >> 0x10);
    pbVar1 = pbVar1 + 1;
    param_2 = param_2 + 1;
  }
  *(byte **)(param_1 + 8) = pbVar1;
  return;
}



/* ===== FUN_08029014 @ 08029014 ===== */

void FUN_08029014(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  uint *puVar5;
  
  uVar2 = DAT_08029344;
  pcVar4 = *(char **)(param_1 + 8);
  *(char **)(param_1 + 8) = pcVar4 + 4;
  *(undefined4 *)pcVar4 = uVar2;
  puVar5 = *(uint **)(param_1 + 4);
  *(uint **)(param_1 + 4) = puVar5 + 1;
  uVar1 = *puVar5;
  if (3 < uVar1) {
    uVar1 = 2;
    goto LAB_0802906a;
  }
  uVar2 = 1;
  if (uVar1 != 1) {
    if (uVar1 == 0) {
LAB_08029058:
      uVar2 = 0;
    }
    else {
      if (uVar1 == 3) {
        if (*DAT_08029348 != '\0') {
LAB_08029050:
          uVar2 = 2;
          pcVar4 = DAT_08029348;
          goto LAB_0802905a;
        }
      }
      else {
        if (2 < uVar1) goto LAB_08029058;
        if (*DAT_08029348 == '\0') goto LAB_08029050;
      }
      uVar2 = 3;
      pcVar4 = DAT_08029348;
    }
  }
LAB_0802905a:
  iVar3 = FUN_08022b94(uVar2,pcVar4,puVar5);
  uVar1 = ~-(uint)(iVar3 == 0) >> 0x1f;
LAB_0802906a:
  puVar5 = *(uint **)(param_1 + 8);
  *(uint **)(param_1 + 8) = puVar5 + 1;
  *puVar5 = uVar1;
  return;
}



/* ===== FUN_080290f4 @ 080290f4 ===== */

undefined8 FUN_080290f4(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  
  uVar2 = DAT_08029358;
  if ((int)((uint)*DAT_080292f8 << 0x1a) < 0) {
    puVar5 = (undefined4 *)param_1[1];
    puVar10 = (undefined4 *)param_1[2];
    param_1[1] = (int)(puVar5 + 1);
    puVar3 = (undefined4 *)param_1[1];
    uVar1 = *puVar5;
    param_1[1] = (int)(puVar3 + 1);
    puVar6 = (uint *)param_1[1];
    uVar4 = *puVar3;
    param_1[1] = (int)(puVar6 + 1);
    uVar7 = *puVar6;
    iVar8 = param_1[1];
    param_1[2] = (int)(puVar10 + 1);
    *puVar10 = uVar2;
    iVar9 = *(int *)(*param_1 + 0xc);
    if (iVar9 - 0x20U < uVar7) {
      uVar2 = 0x13;
    }
    else if (uVar7 == 0) {
      uVar2 = (*(code *)DAT_0802935c[1])(*(undefined4 *)(*param_1 + 4),iVar9,uVar1);
    }
    else {
      uVar2 = (*(code *)*DAT_0802935c)(uVar1,uVar4,uVar7,iVar8);
    }
  }
  else {
    uVar2 = DAT_0802934c;
  }
  puVar3 = (undefined4 *)param_1[2];
  param_1[2] = (int)(puVar3 + 1);
  *puVar3 = uVar2;
  return CONCAT44(puVar3,param_4);
}



/* ===== FUN_0802922c @ 0802922c ===== */

void FUN_0802922c(int param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  puVar1 = *(uint **)(param_1 + 4);
  *(uint **)(param_1 + 4) = puVar1 + 1;
  puVar4 = *(uint **)(param_1 + 4);
  uVar7 = *puVar1;
  *(uint **)(param_1 + 4) = puVar4 + 1;
  puVar1 = *(uint **)(param_1 + 4);
  uVar2 = *puVar4;
  *(uint **)(param_1 + 4) = puVar1 + 1;
  puVar4 = *(uint **)(param_1 + 4);
  uVar5 = *puVar1;
  *(uint **)(param_1 + 4) = puVar4 + 1;
  iVar3 = FUN_08026f7e(uVar2 & 0xff,uVar5 & 0xff,*puVar4 & 0xff,puVar1);
  if (iVar3 == 0) {
    iVar3 = FUN_08029934(1,uVar7 & 0xff);
  }
  puVar6 = *(undefined4 **)(param_1 + 8);
  *puVar6 = DAT_08029370;
  *(undefined4 **)(param_1 + 8) = puVar6 + 2;
  puVar6[1] = iVar3;
  return;
}



/* ===== FUN_0802927c @ 0802927c ===== */

undefined4 FUN_0802927c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  puVar1 = *(uint **)(param_1 + 4);
  *(uint **)(param_1 + 4) = puVar1 + 1;
  uVar4 = *puVar1;
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 4;
  iVar2 = FUN_08029982(uVar4 & 0xff,0);
  if (iVar2 == 0) {
    iVar2 = FUN_08029934(1,uVar4 & 0xff);
  }
  puVar3 = *(undefined4 **)(param_1 + 8);
  *puVar3 = DAT_08029374;
  *(undefined4 **)(param_1 + 8) = puVar3 + 2;
  puVar3[1] = iVar2;
  return param_4;
}



/* ===== FUN_080294c8 @ 080294c8 ===== */

undefined4 FUN_080294c8(void)

{
  uint *puVar1;
  int iVar2;
  undefined4 in_r3;
  
  iVar2 = DAT_080295d4;
  puVar1 = DAT_080295d0;
  **(undefined1 **)(DAT_080295d4 + 0xc) = 0;
  puVar1[4] = 0;
  puVar1[3] = 0;
  FUN_08023320();
  **(undefined1 **)(iVar2 + 0x10) = 0;
  puVar1[5] = 0;
  *puVar1 = *puVar1 & 0xfffffffb;
  FUN_080232e8();
  *puVar1 = *puVar1 & 0xfffffffd;
  return in_r3;
}



/* ===== FUN_080294fa @ 080294fa ===== */

void FUN_080294fa(void)

{
  uint *puVar1;
  uint uVar2;
  
  **(undefined1 **)(DAT_080295d4 + 0x10) = 0;
  puVar1 = DAT_080295d0;
  uVar2 = *DAT_080295d0;
  DAT_080295d0[5] = 0;
  *puVar1 = uVar2 & 0xfffffffb;
  FUN_080232e8();
  return;
}



/* ===== FUN_08029514 @ 08029514 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_08029514(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined2 *puVar1;
  uint *puVar2;
  char *pcVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 unaff_r7;
  int iVar10;
  undefined4 unaff_lr;
  
  pcVar3 = DAT_080295dc;
  iVar8 = DAT_080295d4;
  puVar2 = DAT_080295d0;
  if (*DAT_080295dc == '\a') {
    uVar6 = *DAT_080295d0;
    iVar10 = *(int *)(DAT_080295d4 + 8);
    if (((int)(uVar6 << 0x1e) < 0) && ((int)(uVar6 << 0x1d) < 0)) {
      uVar9 = DAT_080295d0[5];
      puVar1 = (undefined2 *)((int)DAT_080295d0 + 6);
      *DAT_080295d0 = uVar6 & 0xfffffffb;
      if (0x14 < uVar9) {
        uVar9 = 0x14;
      }
      iVar7 = FUN_08029c90((short)puVar2[1],*puVar1,0,uVar9 & 0xff);
      puVar4 = _DAT_080295e0;
      if (iVar7 == 100) {
        *pcVar3 = '\b';
        iVar8 = 10000;
      }
      else {
        if (iVar7 != 0) {
          if (iVar7 < 0xf2) {
            FUN_08016af8();
            *pcVar3 = '\0';
            *puVar4 = 1;
            if (pcVar3[2] == '\0') {
              pcVar3[2] = ' ';
            }
            uVar6 = 0x20;
          }
          else {
            *pcVar3 = '\0';
            *puVar4 = 1;
            if (pcVar3[2] == '\0') {
              pcVar3[2] = (char)(0x20U - iVar7);
            }
            uVar6 = 0x20U - iVar7 & 0xff;
          }
          FUN_080187dc("BLE: error #0x%0.2X!",uVar6);
          puVar2[5] = 0;
          iVar8 = FUN_080232e8(iVar10,param_4);
          return iVar8;
        }
        *(uint *)(iVar8 + 8) = (uVar9 & 0xff) + iVar10;
        uVar6 = puVar2[5] - (uVar9 & 0xff);
        puVar2[5] = uVar6;
        if (uVar6 == 0) {
          FUN_080232e8();
          **(undefined1 **)(iVar8 + 0x10) = 0;
          return iVar10;
        }
        iVar8 = 5;
      }
      uVar5 = FUN_08025a30(iVar8 * 0x2000 + 0x7d,0xffffff82 < (uint)(iVar8 * 0x2000),0xfa,0,unaff_r7
                           ,unaff_lr);
      iVar8 = FUN_08016890(DAT_08023348,uVar5,unaff_r7);
      return iVar8;
    }
  }
  return param_3;
}



/* ===== FUN_0802962c @ 0802962c ===== */

longlong FUN_0802962c(int param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  
  iVar1 = FUN_080299d0(param_2);
  if (iVar1 != 0) {
    return CONCAT44(param_4,1);
  }
  uVar3 = 0;
  if (param_3 != 0) {
    do {
      if (param_3 - uVar3 < 0x40) {
        sVar2 = (short)param_3 - (short)uVar3;
      }
      else {
        sVar2 = 0x40;
      }
      iVar1 = FUN_08029a18(param_2,sVar2,param_1);
      if (iVar1 != 0) {
        return CONCAT44(param_4,2);
      }
      uVar3 = uVar3 + 0x40;
      param_2 = param_2 + 0x40;
      param_1 = param_1 + 0x40;
    } while (uVar3 < param_3);
  }
  return (ulonglong)param_4 << 0x20;
}



/* ===== FUN_0802966a @ 0802966a ===== */

undefined8 FUN_0802966a(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 in_r3;
  
  iVar4 = FUN_08029746();
  if (iVar4 == 0) {
    iVar5 = FUN_080296f0();
    iVar1 = DAT_080297a0;
    iVar4 = DAT_0802979c;
    if (iVar5 == 6) {
      uVar7 = 0;
      iVar5 = DAT_0802979c;
      do {
        iVar6 = FUN_08029a76(iVar1 + uVar7,0x40,iVar5);
        if (iVar6 != 0) goto LAB_080296c2;
        uVar7 = uVar7 + 0x40;
        iVar5 = iVar5 + 0x40;
      } while (uVar7 < 0x800);
      FUN_0802498c(iVar4 + 0x100,DAT_080297a4,0xe);
      iVar4 = FUN_0802962c(iVar4,iVar1,0x800);
      if ((iVar4 == 0) && (iVar4 = FUN_080296f0(), iVar4 == 0)) {
        iVar4 = 0;
        goto LAB_080296ec;
      }
LAB_080296c2:
      iVar4 = 3;
    }
    else {
      iVar4 = 0;
      if (iVar5 == 0) goto LAB_080296ec;
      iVar4 = 2;
    }
  }
  else {
    iVar4 = 1;
  }
  puVar3 = DAT_080297ac;
  puVar2 = DAT_080297a8;
  *DAT_080297a8 = 0;
  *puVar3 = 1;
  uVar7 = iVar4 + 4U | 0x80;
  if (puVar2[2] == '\0') {
    puVar2[2] = (char)uVar7;
  }
  FUN_080187dc("BLE: error #0x%0.2X!",uVar7);
LAB_080296ec:
  return CONCAT44(in_r3,iVar4);
}



/* ===== FUN_080296f0 @ 080296f0 ===== */

undefined4 FUN_080296f0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_48 [64];
  
  iVar1 = FUN_08029a76(DAT_080297b0,0xe,auStack_48);
  if (iVar1 != 0) {
    return 3;
  }
  iVar1 = FUN_0802e888(auStack_48,DAT_080297a4,0xe);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 6;
  }
  return uVar2;
}



/* ===== FUN_08029718 @ 08029718 ===== */

void FUN_08029718(void)

{
  uint *puVar1;
  
  puVar1 = DAT_08029798;
  DAT_08029798[6] = 0x1000;
  *puVar1 = *puVar1 & 0xfcffffff | 0x1000000;
  puVar1[1] = puVar1[1] & 0xffffefff;
  return;
}



/* ===== FUN_08029736 @ 08029736 ===== */

void FUN_08029736(void)

{
  *DAT_08029798 = *DAT_08029798 & 0xfcffffff | 0x2000000;
  return;
}



/* ===== FUN_08029746 @ 08029746 ===== */

undefined4 FUN_08029746(void)

{
  int *piVar1;
  char *pcVar2;
  
  pcVar2 = DAT_080297a8;
  if (*DAT_080297a8 != '\x02') {
    FUN_08019f26(1);
    piVar1 = DAT_08029794;
    do {
    } while ((uint)(*DAT_08029794 - *DAT_08029794) < DAT_080297b4);
    *DAT_08029798 = *DAT_08029798 & 0xfcffffff | 0x2000000;
    do {
    } while ((uint)(*piVar1 - *piVar1) < DAT_080297b8);
    FUN_0802705a();
    if (*pcVar2 != '\x02') {
      return 1;
    }
  }
  pcVar2[1] = 'd';
  return 0;
}



/* ===== FUN_080297d4 @ 080297d4 ===== */

void FUN_080297d4(void)

{
  int iVar1;
  
  iVar1 = DAT_08029870;
  if (*(char *)(DAT_08029870 + 0xd) == '\x02') {
    FUN_0801664a(DAT_08029874,2);
    *(undefined1 *)(iVar1 + 0xd) = 0;
    FUN_08015b38(0);
    FUN_080168b4(iVar1);
    return;
  }
  return;
}



/* ===== FUN_080297e4 @ 080297e4 ===== */

uint FUN_080297e4(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)(DAT_08029870 + 0xd);
  if (param_1 == uVar2) {
    uVar1 = 1;
  }
  else {
    uVar1 = -(uint)(uVar2 == 0) >> 0x1f;
  }
  return uVar1 | uVar2 << 8;
}



/* ===== FUN_080297fc @ 080297fc ===== */

uint FUN_080297fc(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint *puVar2;
  byte bVar3;
  uint uVar4;
  undefined4 uVar5;
  bool bVar6;
  
  iVar1 = DAT_08029870;
  if (*(byte *)(DAT_08029870 + 0xd) != param_1) {
    if (*(byte *)(DAT_08029870 + 0xd) != 0) {
      return param_4;
    }
    *(char *)(DAT_08029870 + 0xd) = (char)param_1;
  }
  FUN_08015b38(param_1);
  if (*(char *)(iVar1 + 0xc) == '\0') {
    FUN_08018568(2);
  }
  if (param_1 == 1) {
    uVar5 = 0x28000;
  }
  else if (param_1 == 2) {
    uVar5 = 0x1e0000;
  }
  else {
    uVar5 = 0;
  }
  FUN_08016890(iVar1,uVar5);
  puVar2 = DAT_08029874;
  uVar4 = 1 << (param_1 & 0xff);
  bVar6 = (DAT_08029874[3] & uVar4) == 0;
  if (bVar6) {
    uVar4 = uVar4 | DAT_08029874[3];
    DAT_08029874[3] = uVar4;
  }
  if (bVar6 && param_1 == 2) {
    bVar3 = FUN_0802092a();
    uVar4 = (uint)bVar3;
    if ((uVar4 < 3) && (uVar4 = 0x1001, (*puVar2 & 0x1001) == 0x1001)) {
      uVar4 = FUN_08020730(7,3,0);
      return uVar4;
    }
  }
  return uVar4;
}



/* ===== FUN_08029844 @ 08029844 ===== */

void FUN_08029844(uint param_1)

{
  int iVar1;
  
  iVar1 = DAT_08029870;
  if (param_1 == *(byte *)(DAT_08029870 + 0xd)) {
    FUN_0801664a(DAT_08029874);
    *(undefined1 *)(iVar1 + 0xd) = 0;
    FUN_08015b38(0);
    FUN_080168b4(iVar1);
    return;
  }
  return;
}



/* ===== FUN_08029878 @ 08029878 ===== */

undefined1
FUN_08029878(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,
            undefined2 param_5)

{
  int iVar1;
  undefined1 local_130 [4];
  undefined2 local_12c;
  undefined2 local_12a;
  undefined4 local_128;
  undefined2 *local_124;
  undefined4 local_120;
  undefined1 *local_11c;
  undefined4 local_118;
  undefined2 local_114;
  undefined2 local_112;
  undefined2 local_110;
  undefined2 local_10e;
  undefined2 local_10c;
  undefined4 uStack_10;
  
  local_10e = (undefined2)param_4;
  local_10c = param_5;
  local_130[0] = 0;
  local_114 = param_1;
  local_112 = param_2;
  local_110 = param_3;
  uStack_10 = param_4;
  FUN_0802e740(&local_12c,0,0x18);
  local_12c = 0x3f;
  local_128 = 0xf;
  local_12a = 0x181;
  local_120 = 10;
  local_124 = &local_114;
  local_118 = 1;
  local_11c = local_130;
  iVar1 = FUN_0802720c(&local_12c,0);
  if (iVar1 < 0) {
    local_130[0] = 0xff;
  }
  return local_130[0];
}



/* ===== FUN_080298d6 @ 080298d6 ===== */

undefined1 FUN_080298d6(undefined1 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 local_128 [4];
  undefined2 local_124;
  undefined2 local_122;
  undefined1 *local_11c;
  uint local_118;
  undefined1 *local_114;
  undefined4 local_110;
  undefined1 local_10c;
  undefined1 local_10b;
  undefined1 auStack_10a [258];
  
  local_128[0] = 0;
  local_10b = (undefined1)param_2;
  local_10c = param_1;
  FUN_0802e734(auStack_10a,param_3,param_2);
  FUN_0802e740(&local_124,0,0x18);
  local_124 = 0x3f;
  local_122 = 0xc;
  local_11c = &local_10c;
  local_118 = param_2 + 2U & 0xff;
  local_110 = 1;
  local_114 = local_128;
  iVar1 = FUN_0802720c(&local_124,0);
  if (iVar1 < 0) {
    local_128[0] = 0xff;
  }
  return local_128[0];
}



/* ===== FUN_08029934 @ 08029934 ===== */

undefined1 FUN_08029934(undefined1 param_1,undefined1 param_2)

{
  int iVar1;
  undefined1 local_128 [4];
  undefined2 local_124;
  undefined2 local_122;
  undefined1 *local_11c;
  undefined4 local_118;
  undefined1 *local_114;
  undefined4 local_110;
  undefined1 local_10c;
  undefined1 local_10b;
  
  local_128[0] = 0;
  local_10c = param_1;
  local_10b = param_2;
  FUN_0802e740(&local_124,0,0x18);
  local_122 = 0xf;
  local_124 = 0x3f;
  local_118 = 2;
  local_11c = &local_10c;
  local_110 = 1;
  local_114 = local_128;
  iVar1 = FUN_0802720c(&local_124,0);
  if (iVar1 < 0) {
    local_128[0] = 0xff;
  }
  return local_128[0];
}



/* ===== FUN_08029982 @ 08029982 ===== */

undefined1 FUN_08029982(undefined1 param_1,undefined1 param_2)

{
  int iVar1;
  undefined1 local_128 [4];
  undefined2 local_124;
  undefined2 local_122;
  undefined1 *local_11c;
  undefined4 local_118;
  undefined1 *local_114;
  undefined4 local_110;
  undefined1 local_10c;
  undefined1 local_10b;
  
  local_128[0] = 0;
  local_10c = param_1;
  local_10b = param_2;
  FUN_0802e740(&local_124,0,0x18);
  local_122 = 0x15;
  local_124 = 0x3f;
  local_118 = 2;
  local_11c = &local_10c;
  local_110 = 1;
  local_114 = local_128;
  iVar1 = FUN_0802720c(&local_124,0);
  if (iVar1 < 0) {
    local_128[0] = 0xff;
  }
  return local_128[0];
}



/* ===== FUN_080299d0 @ 080299d0 ===== */

undefined1 FUN_080299d0(undefined4 param_1)

{
  int iVar1;
  undefined1 local_128 [4];
  undefined2 local_124;
  undefined2 local_122;
  undefined4 *local_11c;
  undefined4 local_118;
  undefined1 *local_114;
  undefined4 local_110;
  undefined4 local_10c [65];
  
  local_128[0] = 0;
  local_10c[0] = param_1;
  FUN_0802e740(&local_124,0,0x18);
  local_122 = 0x26;
  local_124 = 0x3f;
  local_118 = 4;
  local_11c = local_10c;
  local_110 = 1;
  local_114 = local_128;
  iVar1 = FUN_0802720c(&local_124,0);
  if (iVar1 < 0) {
    local_128[0] = 0xff;
  }
  return local_128[0];
}



/* ===== FUN_08029a18 @ 08029a18 ===== */

undefined1 FUN_08029a18(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 local_128 [4];
  undefined2 local_124;
  undefined2 local_122;
  undefined4 *local_11c;
  uint local_118;
  undefined1 *local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined2 local_108;
  undefined1 auStack_106 [254];
  
  local_128[0] = 0;
  local_108 = (undefined2)param_2;
  local_10c = param_1;
  FUN_0802e734(auStack_106,param_3,param_2);
  FUN_0802e740(&local_124,0,0x18);
  local_124 = 0x3f;
  local_122 = 0x27;
  local_11c = &local_10c;
  local_118 = param_2 + 6U & 0xff;
  local_110 = 1;
  local_114 = local_128;
  iVar1 = FUN_0802720c(&local_124,0);
  if (iVar1 < 0) {
    local_128[0] = 0xff;
  }
  return local_128[0];
}



/* ===== FUN_08029a76 @ 08029a76 ===== */

char FUN_08029a76(undefined4 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined2 local_1b0;
  undefined2 local_1ae;
  undefined4 *local_1a8;
  undefined4 local_1a4;
  char *local_1a0;
  int local_19c;
  char local_198;
  undefined1 auStack_197 [127];
  undefined4 local_118;
  undefined2 local_114;
  undefined4 uStack_14;
  
  uStack_14 = param_4;
  FUN_0802e740(&local_198,0,0x80);
  local_118 = param_1;
  local_114 = param_2;
  FUN_0802e740(&local_1b0,0,0x18);
  local_1b0 = 0x3f;
  local_1ae = 0x28;
  local_1a8 = &local_118;
  local_1a4 = 6;
  local_1a0 = &local_198;
  local_19c = 0x80;
  iVar1 = FUN_0802720c(&local_1b0,0);
  if (iVar1 < 0) {
    local_198 = -1;
  }
  else if (local_198 == '\0') {
    FUN_0802e734(param_3,auStack_197,local_19c + -1);
    local_198 = '\0';
  }
  return local_198;
}



/* ===== FUN_08029ae2 @ 08029ae2 ===== */

undefined1 FUN_08029ae2(void)

{
  int iVar1;
  undefined1 local_20 [4];
  undefined2 local_1c;
  undefined2 local_1a;
  undefined1 *local_c;
  undefined4 local_8;
  
  local_20[0] = 0;
  FUN_0802e740(&local_1c,0,0x18);
  local_1a = 0x101;
  local_1c = 0x3f;
  local_8 = 1;
  local_c = local_20;
  iVar1 = FUN_0802720c(&local_1c,0);
  if (iVar1 < 0) {
    local_20[0] = 0xff;
  }
  return local_20[0];
}



/* ===== FUN_08029b22 @ 08029b22 ===== */

char FUN_08029b22(int param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4,
                 undefined2 *param_5)

{
  int iVar1;
  int iVar2;
  char local_138;
  undefined2 local_137;
  undefined2 local_134;
  undefined2 local_132;
  undefined1 *local_12c;
  int local_128;
  undefined1 *local_124;
  undefined4 local_120;
  undefined1 local_11c;
  undefined1 auStack_11b [259];
  
  if (param_1 == 1) {
    iVar1 = 2;
  }
  else if (param_1 == 2) {
    iVar1 = 0x10;
  }
  else {
    iVar1 = 0;
  }
  FUN_0802e740(&local_138,0,3);
  local_11c = (undefined1)param_1;
  if (param_1 == 1) {
    iVar2 = 2;
  }
  else {
    if (param_1 != 2) {
      return 'G';
    }
    iVar2 = 0x10;
  }
  FUN_0802e734(auStack_11b,param_2,iVar2);
  auStack_11b[iVar1] = param_3;
  auStack_11b[iVar1 + 1] = param_4;
  FUN_0802e740(&local_134,0,0x18);
  local_134 = 0x3f;
  local_132 = 0x102;
  local_12c = &local_11c;
  local_128 = iVar2 + 3;
  local_120 = 3;
  local_124 = &local_138;
  iVar1 = FUN_0802720c(&local_134,0);
  if (iVar1 < 0) {
    local_138 = -1;
  }
  else if (local_138 == '\0') {
    *param_5 = local_137;
    local_138 = '\0';
  }
  return local_138;
}



/* ===== FUN_08029bc8 @ 08029bc8 ===== */

char FUN_08029bc8(undefined2 param_1,int param_2,undefined4 param_3,undefined2 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
                 undefined1 param_9,undefined2 *param_10)

{
  int iVar1;
  int iVar2;
  char local_148;
  undefined2 local_147;
  undefined2 local_144;
  undefined2 local_142;
  undefined2 *local_13c;
  int local_138;
  undefined1 *local_134;
  undefined4 local_130;
  undefined2 local_12c;
  undefined1 local_12a;
  undefined2 local_129;
  undefined1 local_127 [255];
  undefined4 local_28;
  
  if (param_2 == 1) {
    iVar1 = 2;
  }
  else if (param_2 == 2) {
    iVar1 = 0x10;
  }
  else {
    iVar1 = 0;
  }
  local_28 = param_3;
  FUN_0802e740(&local_148,0,3);
  local_12a = (undefined1)param_2;
  if (param_2 == 1) {
    iVar2 = 2;
  }
  else {
    if (param_2 != 2) {
      return 'G';
    }
    iVar2 = 0x10;
  }
  local_12c = param_1;
  FUN_0802e734(&local_129,local_28,iVar2);
  *(undefined2 *)(local_127 + iVar1 + -2) = param_4;
  local_127[iVar1] = param_5;
  local_127[iVar1 + 1] = param_6;
  local_127[iVar1 + 2] = param_7;
  local_127[iVar1 + 3] = param_8;
  local_127[iVar1 + 4] = param_9;
  FUN_0802e740(&local_144,0,0x18);
  local_144 = 0x3f;
  local_13c = &local_12c;
  local_138 = iVar2 + 10;
  local_142 = 0x104;
  local_130 = 3;
  local_134 = &local_148;
  iVar1 = FUN_0802720c(&local_144,0);
  if (iVar1 < 0) {
    local_148 = -1;
  }
  else if (local_148 == '\0') {
    *param_10 = local_147;
    local_148 = '\0';
  }
  return local_148;
}



/* ===== FUN_08029c90 @ 08029c90 ===== */

byte FUN_08029c90(undefined2 param_1,undefined2 param_2,undefined1 param_3,int param_4,
                 undefined4 param_5)

{
  byte bVar1;
  byte local_130 [4];
  undefined2 local_12c;
  undefined2 local_12a;
  undefined2 *local_124;
  uint local_120;
  undefined1 *local_11c;
  undefined4 local_118;
  undefined2 local_114;
  undefined2 local_112;
  undefined1 local_110;
  undefined1 local_10f;
  undefined1 auStack_10e [254];
  
  local_130[0] = 0;
  local_10f = (undefined1)param_4;
  local_114 = param_1;
  local_112 = param_2;
  local_110 = param_3;
  FUN_0802e734(auStack_10e,param_5,param_4);
  FUN_0802e740(&local_12c,0,0x18);
  local_12c = 0x3f;
  local_12a = 0x106;
  local_124 = &local_114;
  local_120 = param_4 + 6U & 0xff;
  local_118 = 1;
  local_11c = local_130;
  bVar1 = FUN_0802720c(&local_12c,0);
  if (0xf1 < bVar1) {
    local_130[0] = bVar1;
  }
  return local_130[0];
}



/* ===== FUN_08029d14 @ 08029d14 ===== */

int * FUN_08029d14(int *param_1)

{
  *param_1 = (int)(param_1 + 0xd8);
  param_1[1] = 0;
  FUN_08029eca(param_1 + 4);
  param_1[0xb] = 0;
  param_1[4] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[0xc] = DAT_08029d80;
  param_1[10] = 0;
  FUN_08029eca(param_1 + 0xe);
  param_1[0x15] = 0;
  param_1[0xe] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 1;
  FUN_0802e8f0(param_1 + 0x18);
  FUN_0802e930(param_1 + 0x5a,DAT_08029d84,0x48,7);
  FUN_0801af98(param_1);
  return param_1;
}



/* ===== FUN_08029d88 @ 08029d88 ===== */

float FUN_08029d88(float param_1)

{
  if (0.0 <= param_1) {
    return SQRT(param_1);
  }
  return NAN;
}



/* ===== FUN_08029da6 @ 08029da6 ===== */

undefined4 FUN_08029da6(uint *param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong lVar8;
  
  uVar4 = param_1[6];
  lVar1 = (ulonglong)(*param_2 & 0xffffff) * (ulonglong)uVar4 +
          CONCAT44((*param_2 & 0xffffff) * ((int)uVar4 >> 0x1f),param_1[8]);
  uVar2 = (uint)lVar1;
  param_1[8] = uVar2 - *param_1;
  param_1[9] = (param_1[9] + (int)((ulonglong)lVar1 >> 0x20)) - (uint)(uVar2 < *param_1);
  uVar5 = param_1[10];
  uVar6 = param_1[0xb];
  uVar7 = FUN_08029e44(param_2[1]);
  lVar1 = (uVar7 & 0xffffffff) * (ulonglong)uVar4;
  uVar3 = (uint)lVar1;
  uVar2 = uVar5 + uVar3;
  param_1[10] = uVar2 - param_1[2];
  param_1[0xb] = ((uVar6 + (int)(uVar7 >> 0x20) * uVar4 +
                           (int)uVar7 * ((int)uVar4 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20) +
                           (uint)CARRY4(uVar5,uVar3)) - param_1[3]) - (uint)(uVar2 < param_1[2]);
  param_1[6] = uVar4 + 1;
  *param_1 = (*param_2 & 0xffffff) + *param_1;
  lVar1 = *(longlong *)(param_1 + 2);
  lVar8 = FUN_08029e90(param_2[1]);
  *(longlong *)(param_1 + 2) = lVar8 + lVar1;
  lVar1 = *(longlong *)(param_1 + 4);
  lVar8 = FUN_08029e90(param_2[2]);
  *(longlong *)(param_1 + 4) = lVar8 + lVar1;
  return param_4;
}



/* ===== FUN_08029e44 @ 08029e44 ===== */

ulonglong FUN_08029e44(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar3 = (param_1 & 0x7fffffff) >> 0x17;
  iVar4 = uVar3 - 0x7e;
  if (iVar4 != 0 && 0x7d < uVar3) {
    uVar2 = (int)param_1 >> 0x1f;
    iVar1 = -iVar4;
    uVar5 = iVar1 + 0x20;
    uVar3 = param_1 << 8 | 0x80000000;
    if (uVar5 != 0 && iVar4 < 0x21) {
      return CONCAT44(uVar2,(uVar3 >> (uVar5 & 0xff)) + uVar2 ^ uVar2);
    }
    uVar6 = iVar1 + 0x40;
    if (uVar6 != 0 && -0x21 < (int)uVar5) {
      uVar5 = uVar3 << (0x20 - uVar6 & 0xff) ^ uVar2;
      return CONCAT44(((uVar3 >> (uVar6 & 0xff) ^ uVar2) - uVar2) - (uint)(uVar5 < uVar2),
                      uVar5 - uVar2);
    }
    if (iVar1 != -0x81) {
      return CONCAT44(~uVar2,~uVar2) ^ 0x8000000000000000;
    }
  }
  return 0;
}



/* ===== FUN_08029e90 @ 08029e90 ===== */

ulonglong FUN_08029e90(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if ((CARRY4(param_1,param_1)) || (iVar3 = ((param_1 & 0x7fffffff) >> 0x17) - 0x7f, iVar3 < 0)) {
    return 0;
  }
  uVar1 = param_1 << 8 | 0x80000000;
  if (iVar3 < 0x20) {
    return (ulonglong)(uVar1 >> (0x1fU - iVar3 & 0xff));
  }
  uVar4 = 0x3f - iVar3;
  if ((int)uVar4 < 0) {
    return CONCAT44((int)uVar1 >> 0x1f,(int)uVar1 >> 0x1f);
  }
  uVar2 = uVar1 >> (uVar4 & 0xff);
  return CONCAT44(uVar2,(uVar1 >> (uVar4 & 0x1f) | uVar1 << 0x20 - (uVar4 & 0x1f)) ^ uVar2);
}



/* ===== FUN_08029eca @ 08029eca ===== */

void FUN_08029eca(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  return;
}



/* ===== FUN_08029eda @ 08029eda ===== */

void FUN_08029eda(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  *param_1 = *param_1 - *param_2;
  uVar3 = param_1[2];
  uVar1 = param_2[2];
  iVar2 = param_2[3];
  param_1[2] = uVar3 - uVar1;
  param_1[3] = (param_1[3] - iVar2) - (uint)(uVar3 < uVar1);
  uVar3 = param_1[4];
  uVar1 = param_2[4];
  iVar2 = param_2[5];
  param_1[4] = uVar3 - uVar1;
  param_1[5] = (param_1[5] - iVar2) - (uint)(uVar3 < uVar1);
  param_1[6] = param_1[6] - param_2[6];
  return;
}



/* ===== FUN_08029f14 @ 08029f14 ===== */

void FUN_08029f14(uint *param_1,uint *param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
  uVar5 = param_1[8];
  uVar7 = param_2[8];
  uVar11 = param_2[9];
  uVar4 = param_2[6];
  uVar3 = *param_1;
  uVar14 = param_1[6];
  uVar6 = uVar5 + uVar7;
  uVar8 = (uint)((ulonglong)uVar3 * (ulonglong)uVar4);
  lVar1 = (ulonglong)*param_2 * (ulonglong)uVar14 +
          CONCAT44(*param_2 * ((int)uVar14 >> 0x1f),uVar6 - uVar8);
  param_1[8] = (uint)lVar1;
  param_1[9] = (((param_1[9] + uVar11 + CARRY4(uVar5,uVar7)) -
                (uVar3 * ((int)uVar4 >> 0x1f) + (int)((ulonglong)uVar3 * (ulonglong)uVar4 >> 0x20)))
               - (uint)(uVar6 < uVar8)) + (int)((ulonglong)lVar1 >> 0x20);
  uVar5 = param_1[10];
  uVar11 = param_2[10];
  uVar12 = param_2[0xb];
  uVar9 = uVar5 + uVar11;
  lVar1 = (ulonglong)param_1[2] * (ulonglong)uVar4;
  uVar7 = (uint)lVar1;
  uVar8 = uVar9 - uVar7;
  uVar10 = param_2[2];
  uVar13 = param_2[3];
  lVar2 = (ulonglong)uVar10 * (ulonglong)uVar14;
  uVar6 = (uint)lVar2;
  param_1[10] = uVar8 + uVar6;
  param_1[0xb] = (((param_1[0xb] + uVar12 + CARRY4(uVar5,uVar11)) -
                  (param_1[3] * uVar4 +
                  param_1[2] * ((int)uVar4 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20))) -
                 (uint)(uVar9 < uVar7)) +
                 uVar13 * uVar14 + uVar10 * ((int)uVar14 >> 0x1f) + (int)((ulonglong)lVar2 >> 0x20)
                 + (uint)CARRY4(uVar8,uVar6);
  param_1[6] = uVar4 + uVar14;
  *param_1 = *param_2 + uVar3;
  uVar5 = param_1[2];
  uVar3 = param_2[2];
  uVar4 = param_2[3];
  param_1[2] = uVar5 + uVar3;
  param_1[3] = uVar4 + param_1[3] + (uint)CARRY4(uVar5,uVar3);
  uVar5 = param_1[4];
  uVar3 = param_2[4];
  uVar4 = param_2[5];
  param_1[4] = uVar5 + uVar3;
  param_1[5] = uVar4 + param_1[5] + (uint)CARRY4(uVar5,uVar3);
  return;
}



/* ===== FUN_08029fcc @ 08029fcc ===== */

undefined8 FUN_08029fcc(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  
  FUN_0802e958();
  if (param_3 < *(int *)(param_1 + 0x18)) {
    iVar2 = *(int *)(param_1 + 0x1c);
    uVar1 = iVar2 + 0xc;
    if (*DAT_0802a004 + 0x1800U <= uVar1) {
      uVar1 = iVar2 - 0x17f4;
    }
    *(uint *)(param_1 + 0x1c) = uVar1;
    FUN_0802a0a8(param_1,iVar2);
  }
  else {
    iVar2 = 0;
  }
  return CONCAT44(param_4,iVar2);
}



/* ===== FUN_0802a008 @ 0802a008 ===== */

float FUN_0802a008(float param_1)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  bVar3 = param_1 < 0.0;
  if ((uint)((int)param_1 * 2) < 0xff000000) {
    if (param_1 != 0.0 && !bVar3) {
      if ((uint)param_1 >> 0x17 == 0) {
        uVar2 = (uint)(param_1 * DAT_0802a0a4[3]) >> 0x17;
        param_1 = (float)((int)(param_1 * DAT_0802a0a4[3]) + (uVar2 - 0x7e) * -0x800000);
        iVar1 = uVar2 - 0x95;
      }
      else {
        iVar1 = ((uint)param_1 >> 0x17) - 0x7e;
        param_1 = (float)((int)param_1 + iVar1 * -0x800000);
      }
      if (param_1 < *DAT_0802a0a4) {
        iVar1 = iVar1 + -1;
        param_1 = param_1 * DAT_0802a0a4[2];
      }
      fVar4 = (float)VectorSignedToFloat(iVar1,(byte)((in_fpscr & 0xfffffff) >> 0x16) & 3);
      fVar5 = param_1 - DAT_0802a0a4[1];
      fVar6 = fVar5 / (param_1 + DAT_0802a0a4[1]);
      fVar7 = fVar6 * fVar6;
      return (DAT_0802a0a4[0x10] * fVar5 -
             DAT_0802a0a4[0xf] *
             (fVar5 - (DAT_0802a0a4[6] + (DAT_0802a0a4[5] + DAT_0802a0a4[4] * fVar7) * fVar7) *
                      fVar7) * fVar6) + DAT_0802a0a4[0xf] * fVar5 + fVar4;
    }
    if (!bVar3) {
      return -INFINITY;
    }
  }
  else {
    if (0xff000000 < (uint)((int)param_1 * 2)) {
      return param_1;
    }
    bVar3 = (int)param_1 < 0;
  }
  if (bVar3) {
    param_1 = NAN;
  }
  return param_1;
}



/* ===== FUN_0802a0a8 @ 0802a0a8 ===== */

undefined4 FUN_0802a0a8(int *param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  *param_1 = *param_1 - (*param_2 & 0xffffff);
  uVar1 = param_1[2];
  iVar2 = param_1[3];
  uVar3 = FUN_08029e90(param_2[1]);
  param_1[2] = uVar1 - (uint)uVar3;
  param_1[3] = (iVar2 - (int)((ulonglong)uVar3 >> 0x20)) - (uint)(uVar1 < (uint)uVar3);
  uVar1 = param_1[4];
  iVar2 = param_1[5];
  uVar3 = FUN_08029e90(param_2[2]);
  param_1[4] = uVar1 - (uint)uVar3;
  param_1[5] = (iVar2 - (int)((ulonglong)uVar3 >> 0x20)) - (uint)(uVar1 < (uint)uVar3);
  param_1[6] = param_1[6] + -1;
  return param_4;
}



/* ===== FUN_0802a0ec @ 0802a0ec ===== */

float FUN_0802a0ec(int param_1)

{
  undefined4 uVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  
  iVar3 = *(int *)(param_1 + 8);
  iVar4 = *(int *)(param_1 + 0xc);
  if ((iVar4 == 0 && iVar3 == 0) || (*(int *)(param_1 + 0x14) == 0 && *(int *)(param_1 + 0x10) == 0)
     ) {
    return 1.0;
  }
  fVar6 = *DAT_0802a150 * DAT_0802a14c;
  uVar1 = FUN_0802a3a4();
  fVar5 = (float)FUN_08029d88(uVar1);
  fVar2 = (float)FUN_0802a3a4(iVar3,iVar4);
  return (fVar6 * fVar5) / fVar2;
}



/* ===== FUN_0802a154 @ 0802a154 ===== */

void FUN_0802a154(int param_1,int param_2)

{
  int iVar1;
  byte *pbVar2;
  
  pbVar2 = (byte *)(param_1 + 0x34);
  if (param_2 - *(int *)(param_1 + 0x3c) < 0) {
    *pbVar2 = 1;
    iVar1 = *(int *)(param_1 + 0x40) + -1;
    *(int *)(param_1 + 0x40) = iVar1;
    if (0 < iVar1) {
      return;
    }
  }
  else if (param_2 == *(int *)(param_1 + 0x3c)) goto LAB_0802a17c;
  *(int *)(param_1 + 0x3c) = param_2;
  *(uint *)(param_1 + 0x38) = (uint)*(ushort *)(DAT_0802a198 + param_2 * 2 + 2);
LAB_0802a17c:
  *pbVar2 = (byte)~(byte)(-(uint)(*pbVar2 == 0 && *(int *)(param_1 + 0x3c) < 0) >> 0x18) >> 7;
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x38) << 1;
  return;
}



/* ===== FUN_0802a19c @ 0802a19c ===== */

void FUN_0802a19c(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0802a154(param_1,*param_2 >> 0x18);
  FUN_08029da6(param_1,param_2,param_4);
  return;
}



/* ===== FUN_0802a1ba @ 0802a1ba ===== */

void FUN_0802a1ba(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  param_1[6] = param_2[6] + param_1[6];
  *param_1 = *param_2 + *param_1;
  uVar3 = param_1[2];
  uVar1 = param_2[2];
  iVar2 = param_2[3];
  param_1[2] = uVar3 + uVar1;
  param_1[3] = iVar2 + param_1[3] + (uint)CARRY4(uVar3,uVar1);
  uVar3 = param_1[4];
  uVar1 = param_2[4];
  iVar2 = param_2[5];
  param_1[4] = uVar3 + uVar1;
  param_1[5] = iVar2 + param_1[5] + (uint)CARRY4(uVar3,uVar1);
  return;
}



/* ===== FUN_0802a1f0 @ 0802a1f0 ===== */

float FUN_0802a1f0(undefined4 *param_1)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  if ((int)param_1[6] < 1) {
    return DAT_0802a214;
  }
  fVar1 = (float)VectorUnsignedToFloat(*param_1,(byte)(in_fpscr >> 0x16) & 3);
  fVar2 = (float)VectorSignedToFloat(param_1[6],(byte)(in_fpscr >> 0x16) & 3);
  return fVar1 / fVar2;
}



/* ===== FUN_0802a218 @ 0802a218 ===== */

float FUN_0802a218(uint *param_1,float *param_2)

{
  uint uVar1;
  uint in_fpscr;
  float fVar2;
  float fVar3;
  float fVar4;
  
  uVar1 = *param_1;
  if (uVar1 < 0x33) {
    fVar2 = param_2[uVar1 * 2 + 3];
    fVar3 = param_2[uVar1 * 2 + 4];
  }
  else {
    fVar4 = (float)VectorUnsignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
    fVar2 = (float)FUN_08029d88(fVar4);
    fVar3 = fVar4 + *param_2 * fVar2 + param_2[2];
    fVar2 = (fVar4 - *param_2 * fVar2) + param_2[1];
  }
  return (fVar3 - fVar2) / (fVar3 + fVar2);
}



/* ===== FUN_0802a278 @ 0802a278 ===== */

float FUN_0802a278(int param_1,int param_2)

{
  ulonglong uVar1;
  longlong lVar2;
  float fVar3;
  uint uVar4;
  float fVar5;
  uint in_fpscr;
  float fVar6;
  int iVar7;
  
  iVar7 = *(int *)(param_1 + 0x18);
  fVar3 = (float)FUN_0802a3a4(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
  if (0 < iVar7) {
    if (1 < iVar7) {
      uVar4 = (param_2 * 2 - iVar7) + 1;
      uVar1 = (ulonglong)uVar4 * (ulonglong)*(uint *)(param_1 + 0x28);
      lVar2 = (uVar1 & 0xffffffff) * 3;
      fVar5 = (float)FUN_0802ea58((int)lVar2,
                                  (((int)uVar4 >> 0x1f) * *(uint *)(param_1 + 0x28) +
                                  uVar4 * *(int *)(param_1 + 0x2c) + (int)(uVar1 >> 0x20)) * 3 +
                                  (int)((ulonglong)lVar2 >> 0x20));
      fVar6 = (float)VectorSignedToFloat((iVar7 + -1) * (iVar7 + 1),(byte)(in_fpscr >> 0x16) & 3);
      fVar3 = fVar5 / fVar6 + fVar3;
    }
    in_fpscr = in_fpscr & 0xfffffff;
    if (0.0 <= fVar3) goto LAB_0802a2ec;
  }
  fVar3 = DAT_0802a320;
LAB_0802a2ec:
  FUN_08029e90(fVar3);
  fVar3 = (float)FUN_0802a3a4();
  fVar5 = (float)VectorUnsignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
  return fVar3 / (*(float *)(DAT_0802a328 + 4) * DAT_0802a324 * fVar5);
}



/* ===== FUN_0802a32c @ 0802a32c ===== */

undefined4 FUN_0802a32c(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint in_fpscr;
  
  iVar4 = param_1[6];
  VectorUnsignedToFloat(*param_1,(byte)(in_fpscr >> 0x16) & 3);
  if ((0 < iVar4) && (1 < iVar4)) {
    uVar3 = (param_2 * 2 - iVar4) + 1;
    uVar1 = (ulonglong)uVar3 * (ulonglong)(uint)param_1[8];
    lVar2 = (uVar1 & 0xffffffff) * 3;
    FUN_0802ea58((int)lVar2,
                 (((int)uVar3 >> 0x1f) * param_1[8] + uVar3 * param_1[9] + (int)(uVar1 >> 0x20)) * 3
                 + (int)((ulonglong)lVar2 >> 0x20));
    VectorSignedToFloat((iVar4 + -1) * (iVar4 + 1),(byte)(in_fpscr >> 0x16) & 3);
  }
  return param_4;
}



/* ===== FUN_0802a3a4 @ 0802a3a4 ===== */

undefined8 FUN_0802a3a4(uint param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (param_2 == 0) {
    iVar5 = 0;
    iVar4 = 0;
    if (param_1 != 0) {
      uVar3 = param_1 << LZCOUNT(param_1);
      bVar1 = (uVar3 & 0x100) != 0;
      uVar2 = uVar3 * 0x1000000;
      iVar5 = (uVar2 + 0x80000000) - (uint)!bVar1;
      iVar4 = (0x9d - LZCOUNT(param_1)) * 0x800000 +
              (uVar3 >> 8) + (uint)(0x80000000 < uVar2 || uVar2 + 0x80000000 < (uint)bVar1);
    }
    return CONCAT44(iVar5,iVar4);
  }
  uVar2 = param_1 << LZCOUNT(param_2);
  iVar5 = -LZCOUNT(param_2);
  uVar3 = iVar5 + 0x20U & 0x1f;
  uVar3 = ((param_2 ^ param_1) >> uVar3 | (param_2 ^ param_1) << 0x20 - uVar3) ^ uVar2;
  if (uVar2 != 0) {
    uVar3 = uVar3 | 1;
  }
  iVar5 = (iVar5 + 0xbd) * 0x800000;
  return CONCAT44(iVar5,iVar5 + (uVar3 >> 8) +
                                (uint)(0x80000000 < uVar3 * 0x1000000 ||
                                      uVar3 * 0x1000000 + 0x80000000 < (uint)((uVar3 & 0x100) != 0))
                 );
}



/* ===== FUN_0802a3ec @ 0802a3ec ===== */

void FUN_0802a3ec(undefined1 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  param_1[0x3c] = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  param_1[0x80] = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  param_1[0xb8] = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0xe0) = 0;
  *(undefined4 *)(param_1 + 0xe4) = 0;
  *(undefined4 *)(param_1 + 0xe8) = 0;
  *(undefined4 *)(param_1 + 0xec) = 0;
  param_1[0xf0] = 0;
  return;
}



/* ===== FUN_0802a474 @ 0802a474 ===== */

undefined4 FUN_0802a474(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  longlong lVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;
  uint *puVar5;
  float fVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  uint in_fpscr;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  longlong lVar28;
  uint local_84 [3];
  longlong local_78;
  float local_6e;
  float local_6a;
  undefined2 local_66;
  undefined2 local_64;
  undefined2 local_62;
  undefined1 local_60;
  int local_5c;
  int local_58;
  float local_52;
  float local_4e;
  
  FUN_0802eab0(param_1,local_84,param_2);
  iVar13 = DAT_0802a930;
  iVar10 = *param_2;
  FUN_080160ae(local_84[0] & 0xffffff,iVar10);
  FUN_0801a814(param_1 + 4,local_84);
  FUN_0801a860(param_1 + 0xe,local_84);
  uVar11 = 0;
  piVar12 = param_1 + 0x5a;
  do {
    iVar4 = FUN_0801a78a(piVar12,local_84);
    if ((iVar4 != 0) && (iVar4 = FUN_0801a7ae(piVar12,iVar13), iVar4 == 0)) {
      puVar5 = (uint *)piVar12[7];
      if ((int)*puVar5 >> 0x18 < (int)uVar11) {
        *puVar5 = *puVar5 & 0xffffff | uVar11 << 0x18;
      }
      if (piVar12[6] < param_1[10]) {
        iVar4 = piVar12[1];
        iVar16 = piVar12[2];
        iVar17 = piVar12[3];
        iVar18 = piVar12[4];
        iVar19 = piVar12[5];
        iVar20 = piVar12[6];
        iVar21 = piVar12[7];
        param_1[4] = *piVar12;
        param_1[5] = iVar4;
        param_1[6] = iVar16;
        param_1[7] = iVar17;
        param_1[8] = iVar18;
        param_1[9] = iVar19;
        param_1[10] = iVar20;
        param_1[0xb] = iVar21;
      }
    }
    uVar11 = uVar11 + 1;
    piVar12 = piVar12 + 0x12;
    iVar13 = iVar13 + 0x48;
  } while (uVar11 < 7);
  iVar13 = param_1[1] + 1;
  if (0x1ff < iVar13) {
    iVar13 = 0;
  }
  param_1[1] = iVar13;
  FUN_0802498c(*param_1 + param_1[1] * 0xc,local_84,0xc);
  if (param_1[10] < 1) {
    fVar22 = DAT_0802a828;
  }
  else {
    fVar22 = (float)VectorUnsignedToFloat(param_1[4],(byte)(in_fpscr >> 0x16) & 3);
    fVar25 = (float)VectorSignedToFloat(param_1[10],(byte)(in_fpscr >> 0x16) & 3);
    fVar22 = (fVar22 * 2.0) / fVar25;
  }
  lVar28 = FUN_0801a32a();
  iVar16 = (int)((ulonglong)lVar28 >> 0x20);
  uVar11 = (uint)lVar28;
  fVar6 = (float)FUN_0802a3a4(param_1[6],param_1[7]);
  iVar13 = DAT_0802a938;
  fVar25 = DAT_0802a810;
  fVar26 = (float)VectorUnsignedToFloat(param_1[10],(byte)(in_fpscr >> 0x16) & 3);
  fVar6 = fVar6 / (*(float *)(DAT_0802a934 + 4) * DAT_0802a810 * fVar26);
  fVar26 = (float)FUN_0802a0ec(param_1 + 4);
  fVar23 = (float)FUN_0802a218(param_1 + 4,DAT_0802a93c);
  FUN_08015d0a(fVar22,fVar23);
  iVar4 = FUN_0801b00c(fVar22,fVar23);
  FUN_08020d8e(iVar13,0,iVar4);
  if (iVar4 == 3) {
    fVar22 = DAT_0802a814;
  }
  FUN_08015d38(fVar6,fVar26,iVar4 == 3);
  iVar4 = FUN_0801b0d4(fVar6,fVar26);
  FUN_08020d8e(iVar13,1,iVar4);
  if ((iVar4 == 3) &&
     (uVar7 = in_fpscr & 0xfffffff | (uint)(fVar6 < DAT_0802a918) << 0x1f,
     in_fpscr = uVar7 | (uint)(NAN(fVar6) || NAN(DAT_0802a918)) << 0x1c,
     (byte)(uVar7 >> 0x1f) == ((byte)(in_fpscr >> 0x1c) & 1))) {
    fVar6 = DAT_0802a91c;
  }
  fVar24 = (float)VectorUnsignedToFloat(iVar10,(byte)(in_fpscr >> 0x16) & 3);
  local_78 = FUN_08029e90(fVar6 * DAT_0802a920 * fVar24);
  iVar4 = DAT_0802a940;
  lVar1 = local_78 + (ulonglong)*(uint *)(DAT_0802a940 + 0x24);
  uVar7 = (uint)lVar1;
  iVar17 = (int)((ulonglong)lVar1 >> 0x20);
  uVar14 = iVar10 + *(int *)(DAT_0802a940 + 0x2c);
  *(uint *)(DAT_0802a940 + 0x2c) = uVar14;
  if (uVar14 < 1000) {
    if (iVar17 == 0) {
      *(uint *)(iVar4 + 0x24) = uVar7;
    }
    else {
      *(uint *)(iVar4 + 0x24) = uVar7 & 0xffffff;
      *(uint *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + (uVar7 >> 0x18 | iVar17 * 0x100);
    }
  }
  else {
    *(uint *)(iVar4 + 0x24) = uVar7 & 0xffffff;
    *(uint *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + (uVar7 >> 0x18 | iVar17 * 0x100);
    uVar7 = (uint)((ulonglong)uVar14 * (ulonglong)DAT_0802a944 >> 0x29);
    *(uint *)(iVar4 + 0x28) = uVar7 + *(int *)(iVar4 + 0x28);
    *(uint *)(iVar4 + 0x2c) = uVar14 + uVar7 * -1000;
    FUN_0801a3de(DAT_0802a948);
  }
  lVar1 = local_78 + (ulonglong)*(uint *)(iVar4 + 0x14);
  uVar7 = (uint)lVar1;
  uVar14 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar15 = iVar10 + *(int *)(iVar4 + 0x1c);
  *(uint *)(iVar4 + 0x1c) = uVar15;
  if (uVar15 < 1000) {
    if (uVar14 == 0) {
      *(uint *)(iVar4 + 0x14) = uVar7;
    }
    else {
      *(uint *)(iVar4 + 0x14) = uVar7 & 0xffffff;
      *(uint *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + (uVar7 >> 0x18 | uVar14 * 0x100);
    }
  }
  else {
    *(uint *)(iVar4 + 0x14) = uVar7 & 0xffffff;
    uVar2 = DAT_0802a94c;
    uVar8 = uVar7 >> 0x18 | uVar14 * 0x100;
    uVar7 = uVar8 + *(uint *)(iVar4 + 0x10);
    uVar9 = (uint)((ulonglong)uVar15 * (ulonglong)DAT_0802a944 >> 0x29);
    iVar10 = uVar9 + *(int *)(iVar4 + 0x18);
    *(int *)(iVar4 + 0x18) = iVar10;
    *(uint *)(iVar4 + 0x1c) = uVar15 + uVar9 * -1000;
    if (((uVar14 >> 0x18) + (uint)CARRY4(uVar8,*(uint *)(iVar4 + 0x10)) == 0) && (uVar7 < uVar2)) {
      if (*(uint *)(iVar4 + 0x3c) < uVar7) {
        iVar17 = 2;
      }
      else if (*(uint *)(iVar4 + 0x38) < uVar7) {
        iVar17 = 1;
      }
      else {
        iVar17 = 0;
      }
    }
    else {
      iVar17 = 3;
    }
    FUN_08020d8e(iVar13,2,iVar17);
    uVar14 = DAT_0802a94c;
    if (iVar17 == 3) {
      *(undefined4 *)(iVar4 + 0x14) = 0;
      uVar7 = uVar14;
    }
    *(uint *)(iVar4 + 0x10) = uVar7;
    FUN_08015f14(uVar7,iVar10);
  }
  FUN_08020f68(iVar13);
  uVar3 = FUN_0801862e();
  iVar10 = param_1[2];
  param_1[2] = iVar10 + 1;
  if (-1 < (iVar10 + 1) * -0x80000000) {
    iVar10 = FUN_0802ec00(param_1 + 4);
    fVar24 = fVar26 * DAT_0802a924;
    local_78 = lVar28 - iVar10;
    uVar7 = in_fpscr & 0xfffffff | (uint)(fVar24 < DAT_0802a928) << 0x1f;
    in_fpscr = uVar7 | (uint)(NAN(fVar24) || NAN(DAT_0802a928)) << 0x1c;
    if (NAN(fVar23 * DAT_0802a924) || NAN(DAT_0802a928)) {
      local_66 = (undefined2)(int)(fVar23 * DAT_0802a924);
    }
    else {
      local_66 = 0x3de;
    }
    if ((byte)(uVar7 >> 0x1f) == ((byte)(in_fpscr >> 0x1c) & 1)) {
      local_64 = 0x3de;
    }
    else {
      local_64 = (undefined2)(int)fVar24;
    }
    local_62 = 0;
    local_60 = 0;
    local_6e = fVar22;
    local_6a = fVar6;
    FUN_08018770(&local_78);
  }
  uVar7 = FUN_0802ec00(param_1 + 0xe);
  iVar10 = param_1[0x14];
  if (iVar10 < 1) {
    fVar24 = DAT_0802a828;
  }
  else {
    fVar24 = (float)VectorUnsignedToFloat(param_1[0xe],(byte)(in_fpscr >> 0x16) & 3);
    fVar27 = (float)VectorSignedToFloat(iVar10,(byte)(in_fpscr >> 0x16) & 3);
    fVar24 = (fVar24 * 2.0) / fVar27;
  }
  local_4e = (float)FUN_0802a3a4(param_1[0x10],param_1[0x11]);
  fVar27 = (float)VectorUnsignedToFloat(iVar10,(byte)(in_fpscr >> 0x16) & 3);
  local_5c = uVar11 - uVar7;
  local_4e = local_4e / (*(float *)(DAT_0802a934 + 4) * fVar25 * fVar27);
  local_58 = (iVar16 - ((int)uVar7 >> 0x1f)) - (uint)(uVar11 < uVar7);
  local_52 = fVar24;
  FUN_08018900(&local_5c);
  FUN_0801a910(param_1 + 0x18,param_1[0x61],uVar11,iVar16,uVar3 | 0x1000);
  if (*(char *)(iVar13 + 0x18) == '\0') {
    iVar10 = 0;
  }
  else {
    *(undefined1 *)(iVar13 + 0x18) = 0;
    iVar10 = (int)*(char *)(iVar13 + 0x14);
  }
  if (0 < iVar10) {
    FUN_08018a78(fVar22,fVar23,uVar11,iVar16,iVar10 + 0x13U & 0xff);
  }
  if (*(char *)(iVar13 + 0x1d) == '\0') {
    iVar10 = 0;
  }
  else {
    *(undefined1 *)(iVar13 + 0x1d) = 0;
    iVar10 = (int)*(char *)(iVar13 + 0x19);
  }
  if (0 < iVar10) {
    FUN_08018ab8(fVar6,fVar26,uVar11,iVar16,iVar10 + 8U & 0xff);
  }
  if (*(char *)(iVar13 + 0x22) == '\0') {
    iVar13 = 0;
  }
  else {
    *(undefined1 *)(iVar13 + 0x22) = 0;
    iVar13 = (int)*(char *)(iVar13 + 0x1e);
  }
  if (0 < iVar13) {
    fVar22 = (float)VectorUnsignedToFloat
                              (*(undefined4 *)(iVar4 + 0x10),(byte)(in_fpscr >> 0x16) & 3);
    FUN_08018b10(fVar22 * DAT_0802a92c,uVar11,iVar16,*(undefined4 *)(iVar4 + 0x18),
                 iVar13 + 0xbU & 0xff);
  }
  return param_4;
}



/* ===== FUN_0802aa24 @ 0802aa24 ===== */

void FUN_0802aa24(uint *param_1)

{
  int *piVar1;
  
  *param_1 = *param_1 & 0xfffffffe;
  piVar1 = DAT_0802acb8;
  do {
  } while ((uint)(*DAT_0802acb8 - *DAT_0802acb8) < 2);
  *param_1 = *param_1 | 1;
  do {
  } while ((uint)(*piVar1 - *piVar1) < 2);
  return;
}



/* ===== FUN_0802aa4c @ 0802aa4c ===== */

void FUN_0802aa4c(int param_1)

{
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x4000;
  do {
    if (500 < (uint)(*DAT_0802acb8 - *DAT_0802acb8)) {
      return;
    }
  } while (-1 < *(int *)(param_1 + 0x18) << 0x1a);
  return;
}



/* ===== FUN_0802aa70 @ 0802aa70 ===== */

ulonglong FUN_0802aa70(int param_1,uint param_2,undefined4 param_3,byte *param_4,int param_5)

{
  byte *pbVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  piVar2 = DAT_0802acb8;
  do {
  } while ((uint)(*DAT_0802acb8 - *DAT_0802acb8) < 0x14);
  FUN_0802aa24(param_1);
  *(uint *)(param_1 + 4) = param_2 | *(uint *)(param_1 + 4) & 0xfffffc00;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffbff;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xff00ffff | (param_5 + 1) * 0x10000;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfeffffff;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x2000000;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x2000;
  *(undefined4 *)(param_1 + 0x28) = param_3;
  piVar3 = DAT_0802acbc;
  pbVar1 = param_4;
  iVar4 = param_5;
  do {
    if (iVar4 == 0) {
      do {
      } while (-1 < *(int *)(param_1 + 0x18) << 0x1a);
      if (*(int *)(param_1 + 0x18) << 0x1b < 0) {
        uVar5 = 0x80;
      }
      else {
        uVar5 = 0;
      }
      return CONCAT44(param_4,uVar5);
    }
    piVar3[1] = 500;
    iVar6 = *piVar2;
    *piVar3 = iVar6;
    do {
      if (500 < (uint)(*piVar2 - iVar6)) {
        *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x4000;
        goto LAB_0802ab14;
      }
    } while (-1 < *(int *)(param_1 + 0x18) << 0x1f);
    iVar4 = iVar4 + -1;
    *(uint *)(param_1 + 0x28) = (uint)*pbVar1;
    pbVar1 = pbVar1 + 1;
  } while( true );
  while (-1 < *(int *)(param_1 + 0x18) << 0x1a) {
LAB_0802ab14:
    if (500 < (uint)(*piVar2 - *piVar2)) break;
  }
  return CONCAT44(param_4,(param_5 + 4) - iVar4) & 0xffffffff000000ff;
}



/* ===== FUN_0802ab2e @ 0802ab2e ===== */

ulonglong FUN_0802ab2e(int param_1,uint param_2,undefined4 param_3,undefined1 *param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  
  piVar1 = DAT_0802acb8;
  if (param_5 == 0) {
LAB_0802ac14:
    return ZEXT48(param_4) << 0x20;
  }
  do {
  } while ((uint)(*DAT_0802acb8 - *DAT_0802acb8) < 0x14);
  FUN_0802aa24();
  piVar2 = DAT_0802acbc;
  *(uint *)(param_1 + 4) = param_2 | *(uint *)(param_1 + 4) & 0xfffffc00;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffbff;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xff00ffff | 0x10000;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfeffffff;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfdffffff;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x2000;
  *(undefined4 *)(param_1 + 0x28) = param_3;
  piVar2[1] = 500;
  iVar3 = *piVar1;
  *piVar2 = iVar3;
  do {
    if (500 < (uint)(*piVar1 - iVar3)) break;
    if (*(int *)(param_1 + 0x18) << 0x19 < 0) {
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x400;
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xff00ffff | param_5 << 0x10;
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x2000000;
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x2000;
      iVar3 = param_5;
      puVar4 = param_4;
      do {
        piVar2[1] = 500;
        iVar5 = *piVar1;
        *piVar2 = iVar5;
        do {
          if (500 < (uint)(*piVar1 - iVar5)) {
            return CONCAT44(param_4,(param_5 + 4) - iVar3) & 0xffffffff000000ff;
          }
        } while (-1 < *(int *)(param_1 + 0x18) << 0x1d);
        iVar3 = iVar3 + -1;
        *puVar4 = (char)*(undefined4 *)(param_1 + 0x24);
        puVar4 = puVar4 + 1;
      } while (iVar3 != 0);
      do {
      } while (-1 < *(int *)(param_1 + 0x18) << 0x1a);
      goto LAB_0802ac14;
    }
  } while (-1 < *(int *)(param_1 + 0x18) << 0x1b);
  FUN_0802aa4c(param_1);
  return CONCAT44(param_4,1);
}



/* ===== FUN_0802ac24 @ 0802ac24 ===== */

uint FUN_0802ac24(int param_1,uint param_2,undefined1 *param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = DAT_0802acb8;
  if (param_4 != 0) {
    do {
    } while ((uint)(*DAT_0802acb8 - *DAT_0802acb8) < 0x14);
    FUN_0802aa24(param_1);
    piVar2 = DAT_0802acbc;
    *(uint *)(param_1 + 4) = param_2 | *(uint *)(param_1 + 4) & 0xfffffc00;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x400;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xff00ffff | param_4 << 0x10;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfeffffff;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x2000000;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x2000;
    iVar3 = param_4;
    do {
      piVar2[1] = 500;
      iVar4 = *piVar1;
      *piVar2 = iVar4;
      do {
        if (500 < (uint)(*piVar1 - iVar4)) {
          return (param_4 + 4) - iVar3 & 0xff;
        }
      } while (-1 < *(int *)(param_1 + 0x18) << 0x1d);
      iVar3 = iVar3 + -1;
      *param_3 = (char)*(undefined4 *)(param_1 + 0x24);
      param_3 = param_3 + 1;
    } while (iVar3 != 0);
    do {
    } while (-1 < *(int *)(param_1 + 0x18) << 0x1a);
  }
  return 0;
}



/* ===== FUN_0802acc0 @ 0802acc0 ===== */

undefined8 FUN_0802acc0(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 in_r3;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  
  iVar4 = FUN_0802aeba();
  puVar3 = DAT_0802ad44;
  puVar2 = DAT_0802ad40;
  if (iVar4 == 0) {
    iVar5 = 6;
    puVar6 = DAT_0802ad40 + 0x78;
    puVar7 = DAT_0802ad40;
    do {
      *(undefined1 **)(puVar2 + 0x7c) = puVar7;
      *puVar7 = 0;
      *(undefined1 *)(*(int *)(puVar2 + 0x7c) + 1) = 0;
      *(undefined1 *)(*(int *)(puVar2 + 0x7c) + 2) = 0x7f;
      *(undefined1 *)(*(int *)(puVar2 + 0x7c) + 3) = 0x2f;
      *(undefined1 *)(*(int *)(puVar2 + 0x7c) + 6) = 0;
      *(undefined1 *)(*(int *)(puVar2 + 0x7c) + 7) = 0;
      *(undefined1 *)(*(int *)(puVar2 + 0x7c) + 4) = 0;
      *(undefined1 *)(*(int *)(puVar2 + 0x7c) + 5) = 7;
      cVar1 = puVar3[1];
      *(char *)(*(int *)(puVar2 + 0x7c) + 5) = cVar1 + -1;
      iVar8 = *(int *)(puVar2 + 0x7c);
      *(undefined2 *)(iVar8 + 0x10) = 0;
      *(undefined1 **)(iVar8 + 0xc) = puVar3;
      iVar5 = iVar5 + -1;
      *(undefined4 *)(iVar8 + 8) = *(undefined4 *)(puVar3 + 0xc);
      *(undefined1 *)(iVar8 + 0x12) = *puVar3;
      *(char *)(*(int *)(puVar2 + 0x7c) + 0x13) = cVar1;
      puVar7 = puVar7 + 0x14;
    } while (iVar5 != 0);
    *(undefined1 **)(puVar2 + 0x7c) = puVar2;
    *puVar6 = 0;
    puVar2[0x7b] = 0;
  }
  return CONCAT44(in_r3,iVar4);
}



/* ===== FUN_0802ad48 @ 0802ad48 ===== */

uint FUN_0802ad48(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  uint in_r3;
  uint uVar8;
  undefined1 *puVar9;
  uint uVar10;
  
  pbVar4 = DAT_0802ae20;
  pbVar3 = DAT_0802ae1c;
  if (*DAT_0802ae14 != 0) {
    return (uint)*DAT_0802ae14;
  }
  *DAT_0802ae18 = 0;
  pbVar6 = DAT_0802ae28;
  pbVar5 = DAT_0802ae24;
  bVar2 = *pbVar3;
  if ((bVar2 <= *pbVar4) && (bVar1 = *DAT_0802ae24, *DAT_0802ae28 <= bVar1)) {
    if (0x2f < *pbVar4) {
      *pbVar4 = 0x2f;
    }
    if (0x7f < bVar1) {
      *pbVar5 = 0x7f;
    }
    *pbVar3 = bVar2 >> 3;
    iVar7 = DAT_0802ae2c;
    *pbVar4 = *pbVar4 >> 3;
    for (uVar10 = (uint)*pbVar3; uVar10 <= *pbVar4; uVar10 = uVar10 + 1 & 0xff) {
      FUN_0802ae34(*pbVar6,(uVar10 & 0x1f) << 3);
      bVar2 = (*pbVar5 - *pbVar6) + 1;
      if (bVar2 != 0) {
        uVar8 = (uint)bVar2;
        puVar9 = (undefined1 *)(iVar7 + (uint)*pbVar6 + uVar10 * 0x80);
        do {
          FUN_0802ae82(*puVar9);
          uVar8 = uVar8 - 1;
          puVar9 = puVar9 + 1;
        } while (uVar8 != 0);
      }
    }
    *pbVar6 = 1;
    *pbVar3 = 1;
    *pbVar5 = 0;
    *pbVar4 = 0;
  }
  return in_r3;
}



/* ===== FUN_0802ad52 @ 0802ad52 ===== */

undefined4 FUN_0802ad52(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  undefined4 in_r3;
  uint uVar8;
  undefined1 *puVar9;
  uint uVar10;
  
  pbVar4 = DAT_0802ae20;
  pbVar3 = DAT_0802ae1c;
  *DAT_0802ae18 = 0;
  pbVar6 = DAT_0802ae28;
  pbVar5 = DAT_0802ae24;
  bVar2 = *pbVar3;
  if ((bVar2 <= *pbVar4) && (bVar1 = *DAT_0802ae24, *DAT_0802ae28 <= bVar1)) {
    if (0x2f < *pbVar4) {
      *pbVar4 = 0x2f;
    }
    if (0x7f < bVar1) {
      *pbVar5 = 0x7f;
    }
    *pbVar3 = bVar2 >> 3;
    iVar7 = DAT_0802ae2c;
    *pbVar4 = *pbVar4 >> 3;
    for (uVar10 = (uint)*pbVar3; uVar10 <= *pbVar4; uVar10 = uVar10 + 1 & 0xff) {
      FUN_0802ae34(*pbVar6,(uVar10 & 0x1f) << 3);
      bVar2 = (*pbVar5 - *pbVar6) + 1;
      if (bVar2 != 0) {
        uVar8 = (uint)bVar2;
        puVar9 = (undefined1 *)(iVar7 + (uint)*pbVar6 + uVar10 * 0x80);
        do {
          FUN_0802ae82(*puVar9);
          uVar8 = uVar8 - 1;
          puVar9 = puVar9 + 1;
        } while (uVar8 != 0);
      }
    }
    *pbVar6 = 1;
    *pbVar3 = 1;
    *pbVar5 = 0;
    *pbVar4 = 0;
  }
  return in_r3;
}



/* ===== FUN_0802adec @ 0802adec ===== */

undefined4 FUN_0802adec(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  
  if (*DAT_0802ae14 == 0) {
    uVar2 = 1;
    bVar1 = (byte)(-(uint)(param_1 == 0) >> 0x1f);
  }
  else {
    uVar2 = 0;
    if (param_1 != 0) {
      *DAT_0802ae14 = 0;
      FUN_0802ad48();
      return 0;
    }
    bVar1 = 1;
  }
  *DAT_0802ae14 = bVar1;
  return uVar2;
}



/* ===== thunk_FUN_0801b6c4 @ 0802ae30 ===== */

void thunk_FUN_0801b6c4(undefined1 param_1)

{
  int *piVar1;
  
  piVar1 = DAT_0801b880;
  do {
  } while (*DAT_0801b880 << 0x18 < 0);
  *DAT_0801b86c = 0x20;
  *(undefined1 *)(piVar1 + 1) = param_1;
  return;
}



/* ===== FUN_0802ae34 @ 0802ae34 ===== */

undefined4 FUN_0802ae34(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte *pbVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  pbVar2 = DAT_0802af48;
  bVar1 = DAT_0802af48[1];
  DAT_0802af48[1] = (byte)param_2;
  if ((param_2 & 0xf8) != (bVar1 & 0xf8)) {
    FUN_0801b6c4(param_2 >> 3 | 0xb0);
  }
  pcVar3 = DAT_0802af4c;
  if (*pbVar2 == param_1) {
    return param_4;
  }
  *pbVar2 = (byte)param_1;
  if (*pcVar3 == '\0') {
    param_1 = param_1 + 4;
  }
  FUN_0801b6c4((param_1 & 0xff) >> 4 | 0x10);
  uVar4 = FUN_0801b6c4(param_1 & 0xf,param_4);
  return uVar4;
}



/* ===== FUN_0802ae82 @ 0802ae82 ===== */

undefined4 FUN_0802ae82(void)

{
  undefined4 unaff_r7;
  
  FUN_0801b6d2();
  *DAT_0802af48 = *DAT_0802af48 + '\x01';
  return unaff_r7;
}



/* ===== FUN_0802ae94 @ 0802ae94 ===== */

void FUN_0802ae94(byte *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  
  uVar2 = 0x80;
  bVar1 = (&DAT_0802af54)[param_2 & 7];
  do {
    if ((param_3 & uVar2) == 0) {
      bVar3 = *param_1 & ~bVar1;
    }
    else {
      bVar3 = *param_1 | bVar1;
    }
    uVar2 = uVar2 >> 1;
    *param_1 = bVar3;
    param_1 = param_1 + 1;
  } while (uVar2 != 0);
  return;
}



/* ===== FUN_0802aeba @ 0802aeba ===== */

uint FUN_0802aeba(void)

{
  undefined1 *puVar1;
  
  puVar1 = DAT_0802af50;
  *DAT_0802af50 = 0;
  puVar1[2] = 0;
  puVar1[1] = 0x7f;
  puVar1[3] = 0x2f;
  puVar1[4] = 0;
  puVar1[5] = 0;
  if (puVar1[5] == '\0') {
    FUN_0801b6c4(0xe2);
    FUN_0802c050(2);
    FUN_0801b6c4(0x40);
    FUN_0801b6c4(0xa2);
    FUN_0801b6c4(0xa6);
    FUN_0801b6c4(0x23);
    puVar1[6] = 0x3c;
    FUN_0801b6c4(0x81);
    FUN_0801b6c4(0x26);
    FUN_0801b6c4(0x2f);
    FUN_0801b6c4(200);
    FUN_0801b6c4(0xa0);
    return ~-(uint)(puVar1[5] == '\0') >> 0x1f;
  }
  return 1;
}



/* ===== FUN_0802af30 @ 0802af30 ===== */

undefined4 FUN_0802af30(void)

{
  undefined4 unaff_r7;
  
  FUN_0801b6c4(0xae);
  return unaff_r7;
}



/* ===== FUN_0802af42 @ 0802af42 ===== */

void FUN_0802af42(void)

{
  FUN_0801b6c4(0xaf);
  return;
}



/* ===== FUN_0802af5c @ 0802af5c ===== */

uint FUN_0802af5c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  undefined1 uVar1;
  char cVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  piVar3 = DAT_0802afc8;
  if (0x7f < param_1) {
    param_1 = 0x7f;
  }
  if (0x7f < param_3) {
    param_3 = 0x7f;
  }
  if (0x2f < param_2) {
    param_2 = 0x2f;
  }
  uVar6 = param_4;
  if (0x2f < param_4) {
    uVar6 = 0x2f;
  }
  uVar7 = param_3;
  if (param_1 < param_3) {
    uVar7 = param_1;
  }
  uVar8 = uVar6;
  if (param_2 < uVar6) {
    uVar8 = param_2;
  }
  uVar1 = (undefined1)uVar7;
  *(undefined1 *)*DAT_0802afc8 = uVar1;
  cVar2 = (char)uVar8;
  *(char *)(*piVar3 + 1) = cVar2;
  *(char *)(*piVar3 + 2) = (char)param_3;
  *(char *)(*piVar3 + 3) = (char)uVar6;
  *(undefined1 *)(*piVar3 + 4) = uVar1;
  if (*(int *)(*piVar3 + 0xc) == 0) {
    cVar4 = '\a';
  }
  else {
    cVar4 = FUN_0801fb74();
    cVar4 = cVar4 + -1;
  }
  *(char *)(*piVar3 + 5) = cVar4 + cVar2;
  iVar5 = *piVar3;
  if (*(byte *)(iVar5 + 3) < *(byte *)(iVar5 + 5)) {
    *(byte *)(iVar5 + 5) = *(byte *)(iVar5 + 3);
  }
  *(undefined1 *)(*piVar3 + 6) = uVar1;
  *(char *)(*piVar3 + 7) = cVar2;
  return param_4;
}



/* ===== FUN_0802b054 @ 0802b054 ===== */

ushort FUN_0802b054(uint *param_1)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  ushort uVar4;
  ushort uVar5;
  
  *(undefined1 *)(DAT_0802b064 + 0x7b) = 1;
  iVar1 = DAT_0802b064;
  if (param_1 == (uint *)0x0) {
    return 0;
  }
  uVar5 = 0;
  uVar4 = 0;
  if (*(char *)(DAT_0802b064 + 0x7b) == '\0') goto LAB_0802b036;
  do {
    uVar2 = *param_1;
    while( true ) {
      if (uVar2 == 0) {
        if (uVar5 <= uVar4) {
          uVar5 = uVar4;
        }
        return uVar5;
      }
      if (uVar2 == 9) {
        uVar5 = uVar5 + 8;
      }
      else if (uVar2 == 10 || uVar2 == 0xd) {
        if (uVar5 < uVar4) {
          uVar5 = uVar4;
        }
        uVar4 = uVar5;
        uVar5 = 0;
      }
      else {
        pbVar3 = (byte *)FUN_080269cc(uVar2,*(undefined4 *)(*DAT_0802b068 + 0xc),
                                      *(undefined4 *)(*DAT_0802b068 + 8));
        if (pbVar3 != (byte *)0x0) {
          uVar5 = uVar5 + *pbVar3;
        }
      }
      if (*(char *)(iVar1 + 0x7b) != '\0') break;
      param_1 = (uint *)((int)param_1 + 1);
LAB_0802b036:
      uVar2 = (uint)(byte)*param_1;
    }
    param_1 = param_1 + 1;
  } while( true );
}



/* ===== FUN_0802b0e4 @ 0802b0e4 ===== */

void FUN_0802b0e4(byte *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_0802b148;
  if (param_2 != *param_1) {
    *param_1 = (byte)param_2;
    *puVar1 = *puVar1 & 0xffffff9f;
    *puVar1 = *puVar1 & 0xffffff7f;
    if (param_2 == 2) {
      puVar1[3] = 0x8005;
      uVar2 = *puVar1 & 0xffffffe7 | 8;
    }
    else if (param_2 == 3) {
      puVar1[3] = 7;
      uVar2 = *puVar1 & 0xffffffe7 | 0x10;
    }
    else {
      puVar1[3] = DAT_0802b14c;
      uVar2 = *puVar1 & 0xffffffe7;
    }
    *puVar1 = uVar2;
    puVar1[2] = 0xffffffff;
  }
  *puVar1 = *puVar1 | 1;
  return;
}



/* ===== FUN_0802b150 @ 0802b150 ===== */

void FUN_0802b150(int param_1,int param_2,uint param_3,uint param_4,uint param_5)

{
  *(uint *)(param_1 + 4) =
       param_3 & 0xff |
       (param_4 & 0xff) << 8 |
       (param_5 & 0xff) << 0x10 | *(uint *)(param_1 + 4) & DAT_0802b42c | param_2 << 0xd;
  return;
}



/* ===== FUN_0802b17c @ 0802b17c ===== */

bool FUN_0802b17c(int param_1,uint *param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x24) = 0xca;
  *(undefined4 *)(param_1 + 0x24) = 0x53;
  iVar1 = FUN_0802b35c();
  if (iVar1 != 1) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffffffbf | *param_2;
    *(uint *)(param_1 + 0x10) = param_2[2] | *(uint *)(param_1 + 0x10) & 0xffff8000;
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xff80ffff | param_2[1] << 0x10;
    *(undefined4 *)(param_1 + 0xc) = 0xffffff7f;
  }
  *(undefined4 *)(param_1 + 0x24) = 0xff;
  return iVar1 == 1;
}



/* ===== FUN_0802b1ca @ 0802b1ca ===== */

undefined4 FUN_0802b1ca(uint *param_1,int param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar6 = 1;
  if (param_2 == 0) {
    if (-1 < (int)(param_1[2] << 0x19)) {
      *param_3 = 0;
    }
  }
  else if (-1 < (int)(param_1[2] << 0x19)) {
    *param_3 = 0;
  }
  param_1[9] = 0xca;
  param_1[9] = 0x53;
  iVar1 = FUN_0802b35c(param_1);
  if (iVar1 != 1) {
    uVar2 = (uint)*(byte *)((int)param_3 + 6);
    uVar3 = (uint)*(byte *)((int)param_3 + 5);
    uVar4 = (uint)(byte)param_3[1];
    if (param_2 == 0) {
      uVar7 = (uint)((ulonglong)uVar3 * (ulonglong)DAT_0802b434 >> 0x23);
      uVar8 = (uint)((ulonglong)uVar4 * (ulonglong)DAT_0802b434 >> 0x23);
      uVar5 = (uint)((ulonglong)uVar2 * (ulonglong)DAT_0802b434 >> 0x23);
      *param_1 = *param_3 | DAT_0802b430 & *param_1 |
                 ((uVar4 + uVar8 * -10 | uVar8 << 4) & 0xff) << 0x10 |
                 ((uVar3 + uVar7 * -10 | uVar7 << 4) & 0xff) << 8 |
                 (uVar2 + uVar5 * -10 | uVar5 << 4) & 0xff;
    }
    else {
      *param_1 = uVar2 | *param_3 | DAT_0802b430 & *param_1 | uVar4 << 0x10 | uVar3 << 8;
    }
    *DAT_0802b438 = 0xffffff7f;
    if ((int)(param_1[2] << 0x1a) < 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_0802b3aa(param_1);
    }
  }
  param_1[9] = 0xff;
  return uVar6;
}



/* ===== FUN_0802b2aa @ 0802b2aa ===== */

undefined8 FUN_0802b2aa(int param_1,int param_2,undefined1 *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint local_20;
  
  uVar5 = 1;
  if ((param_2 == 0) && ((int)((uint)(byte)param_3[1] << 0x1b) < 0)) {
    param_3[1] = (param_3[1] & 0xef) + 10;
  }
  *(undefined4 *)(param_1 + 0x24) = 0xca;
  *(undefined4 *)(param_1 + 0x24) = 0x53;
  iVar1 = FUN_0802b35c();
  local_20 = param_4;
  if (iVar1 != 1) {
    uVar2 = (uint)(byte)param_3[2];
    uVar3 = (uint)(byte)param_3[1];
    local_20 = (uint)(byte)param_3[3];
    if (param_2 == 0) {
      uVar4 = (uint)((ulonglong)uVar3 * (ulonglong)DAT_0802b434 >> 0x23);
      uVar6 = (uint)((ulonglong)local_20 * (ulonglong)DAT_0802b434 >> 0x23);
      local_20 = (local_20 + uVar6 * -10 | uVar6 << 4) & 0xff;
      uVar6 = (uint)((ulonglong)uVar2 * (ulonglong)DAT_0802b434 >> 0x23);
      uVar3 = (uVar3 + uVar4 * -10 | uVar4 << 4) & 0xff;
      uVar2 = (uVar2 + uVar6 * -10 | uVar6 << 4) & 0xff;
    }
    FUN_0802b150(param_1,*param_3,uVar2,uVar3);
    *DAT_0802b438 = 0xffffff7f;
    if (*(int *)(param_1 + 8) << 0x1a < 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_0802b3aa(param_1);
    }
  }
  *(undefined4 *)(param_1 + 0x24) = 0xff;
  return CONCAT44(local_20,uVar5);
}



/* ===== FUN_0802b35c @ 0802b35c ===== */

undefined4 FUN_0802b35c(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int local_4;
  
  local_4 = 1000;
  uVar2 = 0;
  if (-1 < *(int *)(param_1 + 0xc) << 0x19) {
    *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
    uVar1 = *(uint *)(param_1 + 0xc) >> 6 & 1;
    while ((local_4 != 0 && (uVar1 == 0))) {
      if (*DAT_0802b43c << 0xf < 0) {
        local_4 = local_4 + -1;
      }
      uVar1 = *(uint *)(param_1 + 0xc) >> 6 & 1;
      if (local_4 == 0) {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}



/* ===== FUN_0802b3aa @ 0802b3aa ===== */

undefined8 FUN_0802b3aa(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int local_c;
  
  piVar1 = DAT_0802b43c;
  local_c = 1000;
  iVar3 = 0;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0x80 | 0xffffff5f;
  uVar2 = *(uint *)(param_1 + 0xc) >> 5 & 1;
  while (local_c != 0 && uVar2 != 0) {
    if (*piVar1 << 0xf < 0) {
      local_c = local_c + -1;
    }
    uVar2 = *(uint *)(param_1 + 0xc) >> 5 & 1;
    if (local_c == 0) {
      iVar3 = 1;
    }
  }
  if (iVar3 == 0) {
    local_c = 1000;
    uVar2 = *(uint *)(param_1 + 0xc) >> 5 & 1;
    while ((local_c != 0 && (uVar2 == 0))) {
      if (*piVar1 << 0xf < 0) {
        local_c = local_c + -1;
      }
      uVar2 = *(uint *)(param_1 + 0xc) >> 5 & 1;
      if (local_c == 0) {
        iVar3 = 1;
      }
    }
  }
  return CONCAT44(local_c,iVar3);
}



/* ===== FUN_0802b440 @ 0802b440 ===== */

undefined8 FUN_0802b440(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = param_1[4] / 0xc;
  iVar2 = param_1[4] % 0xc;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xc;
    iVar1 = iVar1 + -1;
  }
  if (iVar1 < 0) {
    if (param_1[5] < -0x80000000 - iVar1) {
LAB_0802b4fe:
      return CONCAT44(param_4,0xffffffff);
    }
  }
  else if ((0 < iVar1) && (0x7fffffff - iVar1 < param_1[5])) goto LAB_0802b4fe;
  iVar3 = param_1[5];
  iVar2 = FUN_0802ed54(iVar1 + iVar3,iVar2);
  iVar4 = *param_1 / DAT_0802b508;
  iVar2 = (DAT_0802b508 *
           (DAT_0802b50c +
           iVar4 + param_1[2] / 0x18 + param_1[3] + (iVar1 + iVar3) * 0x16d + iVar2 +
                   param_1[1] / 0x5a0) + (param_1[2] % 0x18) * 0xe10 + (param_1[1] % 0x5a0) * 0x3c +
          *param_1) - DAT_0802b508 * iVar4;
  FUN_0802edc0(param_1,iVar2,param_1[8]);
  if (0 < param_1[8]) {
    iVar2 = iVar2 + -0xe10;
  }
  iVar1 = FUN_0802eecc();
  return CONCAT44(param_4,iVar2 - iVar1);
}



/* ===== FUN_0802b510 @ 0802b510 ===== */

void FUN_0802b510(undefined4 *param_1)

{
  FUN_0802edc0(0,*param_1,0xffffffff);
  return;
}



/* ===== FUN_0802b52c @ 0802b52c ===== */

undefined4 FUN_0802b52c(uint *param_1,uint *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar5 = *param_2;
  bVar2 = (byte)uVar5;
  bVar3 = (byte)(uVar5 >> 8);
  bVar4 = (byte)(uVar5 >> 0x10);
  bVar1 = (byte)(uVar5 >> 0x18);
  for (uVar5 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1)
                                        << 1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                     bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) <<
                       0x18 | (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 |
                                               bVar3 >> 2 & 1) << 1 | bVar3 >> 3 & 1) << 1 |
                                             bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                                           bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
                       (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1)
                                        << 1 | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 |
                                     bVar4 >> 5 & 1) << 1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8
                       | (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1
                                          ) << 1 | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 |
                                       bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7));
      *param_2 >> (uVar5 & 0xff) != 0; uVar5 = uVar5 + 1) {
    uVar6 = *param_2 & 1 << (uVar5 & 0xff);
    if (uVar6 != 0) {
      bVar2 = (byte)uVar6;
      bVar3 = (byte)(uVar6 >> 8);
      bVar4 = (byte)(uVar6 >> 0x10);
      bVar1 = (byte)(uVar6 >> 0x18);
      uVar7 = (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1 |
                              bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                           bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18 |
              (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1 |
                              bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                           bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
              (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1 |
                              bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                           bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
              (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1 |
                              bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                           bVar1 >> 6 & 1) << 1 | bVar1 >> 7);
      if (param_2[1] == 1 || param_2[1] == 2) {
        param_1[2] = param_2[2] << (LZCOUNT(uVar7) << 1) |
                     param_1[2] & ~(3 << (LZCOUNT(uVar7) << 1));
        param_1[1] = *param_2 * param_2[3] | param_1[1] & ~*param_2;
      }
      param_1[3] = param_2[4] << (LZCOUNT(uVar7) << 1) | param_1[3] & ~(3 << (LZCOUNT(uVar7) << 1));
      if (param_2[1] == 2) {
        if (uVar6 < 0x100) {
          param_1[8] = param_1[8] & ~(0xf << (LZCOUNT(uVar7) << 2)) |
                       param_2[5] << (LZCOUNT(uVar7) << 2);
        }
        else {
          uVar6 = (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1
                                  | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) <<
                                1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x18 |
                  (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1
                                  | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) <<
                                1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 0x10 |
                  (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1
                                  | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) <<
                                1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7) << 8;
          param_1[9] = param_2[5] << (LZCOUNT(uVar6) << 2) |
                       param_1[9] & ~(0xf << (LZCOUNT(uVar6) << 2));
        }
      }
      *param_1 = param_2[1] << (LZCOUNT(uVar7) << 1) | *param_1 & ~(3 << (LZCOUNT(uVar7) << 1));
    }
  }
  return 0;
}



/* ===== FUN_0802b640 @ 0802b640 ===== */

uint FUN_0802b640(uint *param_1)

{
  byte bVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar2 = DAT_0802b794;
  uVar4 = *param_1;
  uVar3 = 0;
  if ((char)param_1[2] == '\0') {
    *DAT_0802b794 = *DAT_0802b794 & ~uVar4;
    puVar2[1] = puVar2[1] & ~*param_1;
    puVar2[8] = puVar2[8] & ~param_1[1];
    puVar2[9] = puVar2[9] & ~param_1[1];
    return 0;
  }
  if (uVar4 != 0) {
    bVar1 = *(byte *)((int)param_1 + 9);
    if (bVar1 == 0) {
      DAT_0802b794[1] = DAT_0802b794[1] & ~uVar4;
      *puVar2 = *puVar2 | *param_1;
    }
    else {
      if (bVar1 == 2) {
        uVar4 = uVar4 | *DAT_0802b794;
      }
      else {
        if (1 < bVar1) {
          uVar3 = 1;
          goto LAB_0802b690;
        }
        uVar4 = *DAT_0802b794 & ~uVar4;
      }
      *DAT_0802b794 = uVar4;
      puVar2[1] = puVar2[1] | *param_1;
    }
LAB_0802b690:
    puVar2 = DAT_0802b794;
    bVar1 = *(byte *)((int)param_1 + 10);
    if (bVar1 != 0) {
      if (bVar1 == 1) {
        DAT_0802b794[3] = DAT_0802b794[3] & ~*param_1;
        puVar2[2] = puVar2[2] | *param_1;
      }
      else if (bVar1 == 0) {
LAB_0802b6d4:
        uVar3 = uVar3 | 2;
      }
      else {
        if (bVar1 == 3) {
          uVar4 = DAT_0802b794[2] | *param_1;
        }
        else {
          if (2 < bVar1) goto LAB_0802b6d4;
          uVar4 = DAT_0802b794[2] & ~*param_1;
        }
        DAT_0802b794[2] = uVar4;
        puVar2[3] = puVar2[3] | *param_1;
      }
    }
  }
  puVar2 = DAT_0802b794;
  uVar4 = param_1[1];
  if (uVar4 == 0) {
    return uVar3;
  }
  bVar1 = *(byte *)((int)param_1 + 9);
  if (bVar1 == 0) {
    DAT_0802b794[9] = DAT_0802b794[9] & ~uVar4;
    puVar2[8] = puVar2[8] | param_1[1];
  }
  else {
    if (bVar1 == 2) {
      uVar4 = uVar4 | DAT_0802b794[8];
    }
    else {
      if (1 < bVar1) {
        uVar3 = uVar3 | 4;
        goto LAB_0802b71e;
      }
      uVar4 = DAT_0802b794[8] & ~uVar4;
    }
    DAT_0802b794[8] = uVar4;
    puVar2[9] = puVar2[9] | param_1[1];
  }
LAB_0802b71e:
  puVar2 = DAT_0802b794;
  bVar1 = *(byte *)((int)param_1 + 10);
  if (bVar1 == 0) {
    return uVar3;
  }
  if (bVar1 == 1) {
    DAT_0802b794[0xb] = DAT_0802b794[0xb] & ~param_1[1];
    puVar2[10] = puVar2[10] | param_1[1];
    return uVar3;
  }
  if (bVar1 == 0) {
LAB_0802b764:
    uVar3 = 1;
  }
  else {
    if (bVar1 == 3) {
      uVar4 = DAT_0802b794[10] | param_1[1];
    }
    else {
      if (2 < bVar1) goto LAB_0802b764;
      uVar4 = DAT_0802b794[10] & ~param_1[1];
    }
    DAT_0802b794[10] = uVar4;
    puVar2[0xb] = puVar2[0xb] | param_1[1];
  }
  return uVar3;
}



/* ===== FUN_0802b798 @ 0802b798 ===== */

undefined4 FUN_0802b798(int param_1,uint *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((int)((*DAT_0802b858 | *DAT_0802b85c | *DAT_0802b860) << 0x1f) < 0) {
    uVar1 = 1;
  }
  else if (param_2[1] == 0) {
    *(uint *)(param_1 + 8) = *param_2 | DAT_0802b864 & *(uint *)(param_1 + 8);
  }
  else {
    *(uint *)(param_1 + 8) =
         param_2[1] | *param_2 | DAT_0802b864 & *(uint *)(param_1 + 8) | param_2[2] | param_2[3];
  }
  return uVar1;
}



/* ===== FUN_0802b7de @ 0802b7de ===== */

undefined4 FUN_0802b7de(int param_1,uint *param_2)

{
  if (*(int *)(param_1 + 8) << 0x1f < 0) {
    return 1;
  }
  *(uint *)(param_1 + 0xc) =
       *(uint *)(param_1 + 0xc) & DAT_0802b868 | *param_2 | param_2[1] | param_2[2];
  return 0;
}



/* ===== FUN_0802b808 @ 0802b808 ===== */

undefined4 FUN_0802b808(int param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 8) << 0x1f < 0) {
    uVar1 = 1;
  }
  else {
    if (param_2[1] == 0) {
      uVar2 = *param_2 | DAT_0802b86c & *(uint *)(param_1 + 0xc);
    }
    else {
      uVar2 = *param_2 | DAT_0802b86c & *(uint *)(param_1 + 0xc) | param_2[2];
    }
    *(uint *)(param_1 + 0xc) = param_2[5] | param_2[4] | param_2[3] | uVar2;
    *(uint *)(param_1 + 0x30) = param_2[1] | *(uint *)(param_1 + 0x30) & 0xfffffff0;
  }
  return uVar1;
}



/* ===== FUN_0802b870 @ 0802b870 ===== */

undefined4 FUN_0802b870(int param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 8) << 0x1f < 0) {
    uVar1 = 1;
  }
  else {
    if (param_2[1] == 0) {
      uVar2 = *(uint *)(param_1 + 0xc) & 0xfdefffff;
    }
    else {
      uVar2 = *(uint *)(param_1 + 0xc) & 0xfdefffff | param_2[2];
    }
    *(uint *)(param_1 + 0xc) = param_2[3] | uVar2;
    *(uint *)(param_1 + 0x4c) = param_2[1] | *param_2 | *(uint *)(param_1 + 0x4c) & 0xffffff00;
  }
  return uVar1;
}



/* ===== FUN_0802b8b4 @ 0802b8b4 ===== */

undefined4 FUN_0802b8b4(uint *param_1,uint *param_2)

{
  if ((int)*param_1 < 0) {
    return 1;
  }
  *param_1 = *param_1 & DAT_0802b8ec | *param_2 | param_2[1] | param_2[2] | param_2[3] | param_2[4]
             | param_2[5];
  return 0;
}



/* ===== FUN_0802b8f0 @ 0802b8f0 ===== */

bool FUN_0802b8f0(uint *param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  bool bVar2;
  
  param_2 = param_2 & 0x10;
  uVar1 = 1 << param_2;
  bVar2 = (*param_1 & uVar1) == uVar1;
  if (!bVar2) {
    if (param_3[1] == 0) {
      *param_1 = *param_3 << param_2 | *param_1 & ~(0xf8 << param_2);
    }
    else {
      *param_1 = (param_3[1] | *param_3 | param_3[2]) << param_2 | *param_1 & ~(0xff8 << param_2);
    }
    param_1[0xf] = (param_3[3] | param_3[4] | param_3[5]) << param_2 |
                   param_1[0xf] & ~(7 << param_2);
  }
  return bVar2;
}



/* ===== FUN_0802b954 @ 0802b954 ===== */

undefined4 FUN_0802b954(uint *param_1,uint *param_2)

{
  *param_1 = *param_1 & 0xfffffffe;
  *param_1 = *param_1 & 0xffffe0ff | param_2[2] | param_2[3] << 8;
  param_1[4] = param_2[1];
  *param_1 = *param_1 | 1;
  param_1[2] = param_1[2] & 0xffff7fff;
  param_1[2] = param_2[6] | param_2[4] | param_1[2] & 0xfffff800;
  if (param_2[4] != 0) {
    param_1[2] = param_1[2] | 0x8000;
  }
  *param_1 = *param_1 & 0xffcfffff | *param_2;
  param_1[1] = param_1[1] & 0xffff7fff | param_2[5];
  return 0;
}



/* ===== FUN_0802b9c0 @ 0802b9c0 ===== */

undefined4 FUN_0802b9c0(uint *param_1,byte *param_2)

{
  uint uVar1;
  
  if (*(uint *)(param_2 + 4) == 0xc) {
    uVar1 = *(uint *)(param_2 + 8) | *param_2 & 2 | DAT_0802b9f8 & *param_1 | 0x20c;
  }
  else {
    uVar1 = *(uint *)(param_2 + 8) | *param_2 & 2 | DAT_0802b9f8 & *param_1 | *(uint *)(param_2 + 4)
            | *(uint *)(param_2 + 0xc);
  }
  *param_1 = uVar1;
  return 0;
}



/* ===== FUN_0802b9fc @ 0802b9fc ===== */

undefined4 FUN_0802b9fc(uint *param_1,uint *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (-1 < (int)(*param_1 << 0x19)) {
    *param_1 = *param_1 & DAT_0802ba68 | *param_2 | param_2[1] | param_2[3] | param_2[4] |
               param_2[5] | param_2[6] | param_2[7] | param_2[8];
    param_1[1] = param_1[1] & DAT_0802ba6c | param_2[2] | param_2[5] >> 0x10;
    if (param_2[2] < 0x800) {
      param_1[1] = param_1[1] | 0x1000;
    }
    if (param_2[8] == 0x2000) {
      param_1[4] = (uint)(ushort)param_2[9];
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* ===== FUN_0802ba70 @ 0802ba70 ===== */

undefined4 FUN_0802ba70(uint *param_1,ushort *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *unaff_r5;
  bool bVar4;
  
  puVar1 = DAT_0802be80;
  uVar3 = *param_1;
  if (param_1 == DAT_0802be80 || param_1 == &DAT_40000000) {
LAB_0802baa2:
    uVar3 = uVar3 & 0xffffff8f | *(uint *)(param_2 + 2);
    if (param_1 != DAT_0802be80 && param_1 != &DAT_40000000) {
      bVar4 = param_1 != DAT_0802be84;
      if (bVar4) {
        unaff_r5 = DAT_0802be88;
      }
      puVar2 = DAT_0802be84;
      if (bVar4 && param_1 != unaff_r5) {
        puVar2 = DAT_0802be8c;
      }
      if ((bVar4 && param_1 != unaff_r5) && param_1 != puVar2) goto LAB_0802baca;
    }
LAB_0802baea:
    uVar3 = uVar3 & 0xfffffcff | *(uint *)(param_2 + 6);
  }
  else {
    if (param_1 != DAT_0802be84) {
      unaff_r5 = DAT_0802be88;
    }
    if (param_1 == DAT_0802be84 || param_1 == unaff_r5) goto LAB_0802baa2;
    if (param_1 != DAT_0802be8c) {
      unaff_r5 = DAT_0802be90;
    }
    puVar2 = DAT_0802be8c;
    if (param_1 == DAT_0802be8c || param_1 == unaff_r5) goto LAB_0802baa2;
LAB_0802baca:
    if (param_1 != DAT_0802be90) {
      puVar2 = DAT_0802be94;
    }
    if (param_1 == DAT_0802be90 || param_1 == puVar2) goto LAB_0802baea;
    if (param_1 != DAT_0802be98) {
      puVar2 = DAT_0802be9c;
    }
    if (param_1 == DAT_0802be98 || param_1 == puVar2) goto LAB_0802baea;
  }
  *param_1 = uVar3;
  param_1[0xb] = *(uint *)(param_2 + 4);
  puVar2 = puVar1;
  if (param_1 != puVar1) {
    puVar2 = DAT_0802be90;
  }
  param_1[10] = (uint)*param_2;
  if (param_1 != puVar1 && param_1 != puVar2) {
    bVar4 = param_1 != DAT_0802be94;
    if (bVar4) {
      puVar2 = DAT_0802be98;
    }
    puVar1 = DAT_0802be94;
    if (bVar4 && param_1 != puVar2) {
      puVar1 = DAT_0802be9c;
    }
    if ((bVar4 && param_1 != puVar2) && param_1 != puVar1) goto LAB_0802bb22;
  }
  param_1[0xc] = *(uint *)(param_2 + 8);
LAB_0802bb22:
  param_1[5] = param_1[5] | 1;
  return 0;
}



/* ===== FUN_0802bb2c @ 0802bb2c ===== */

longlong FUN_0802bb2c(uint param_1,int param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint unaff_r7;
  bool bVar7;
  
  uVar3 = DAT_0802bea8;
  uVar1 = DAT_0802bea0;
  if (param_2 != 1) {
    if (param_2 == 0x10) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffffef;
      uVar4 = *(uint *)(param_1 + 4);
      uVar2 = *param_3;
      uVar6 = *(uint *)(param_1 + 0x18) & DAT_0802bea4;
      uVar3 = (*(uint *)(param_1 + 0x20) & 0xffffffdf | param_3[4] << 4) & 0xffffffef |
              param_3[1] << 4;
      uVar1 = param_3[1];
      if (param_1 != DAT_0802be80) {
        uVar1 = DAT_0802be90;
      }
      if (param_1 == DAT_0802be80 || param_1 == uVar1) {
LAB_0802bc32:
        uVar3 = (uVar3 & 0xffffff7f | param_3[5] << 6) & 0xffffffbf | param_3[2] << 6;
        uVar4 = (uVar4 & 0xfffffbff | param_3[6] << 2) & 0xfffff7ff | param_3[7] << 3;
      }
      else {
        bVar7 = param_1 != DAT_0802be94;
        if (bVar7) {
          uVar1 = DAT_0802be98;
        }
        uVar5 = DAT_0802be94;
        if (bVar7 && param_1 != uVar1) {
          uVar5 = DAT_0802be9c;
        }
        if ((!bVar7 || param_1 == uVar1) || param_1 == uVar5) goto LAB_0802bc32;
      }
      *(uint *)(param_1 + 4) = uVar4;
      *(uint *)(param_1 + 0x18) = uVar6 | uVar2 << 8;
      *(uint *)(param_1 + 0x38) = param_3[3];
    }
    else {
      if (param_2 == 0x100) {
        *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffeff;
        uVar5 = *(uint *)(param_1 + 4);
        uVar6 = *param_3;
        uVar2 = (*(uint *)(param_1 + 0x20) & 0xfffffdff | param_3[4] << 8) & 0xfffffeff |
                param_3[1] << 8;
        uVar4 = param_3[1];
        if (param_1 != DAT_0802be80) {
          uVar4 = DAT_0802be90;
        }
        uVar3 = DAT_0802be80;
        if (param_1 == DAT_0802be80 || param_1 == uVar4) {
LAB_0802bcb6:
          uVar2 = (uVar2 & 0xfffff7ff | param_3[5] << 10) & 0xfffffbff | param_3[2] << 10;
          uVar5 = (uVar5 & 0xffffefff | param_3[6] << 4) & 0xffffdfff | param_3[7] << 5;
        }
        else {
          bVar7 = param_1 != DAT_0802be94;
          if (bVar7) {
            uVar4 = DAT_0802be98;
          }
          uVar3 = DAT_0802be94;
          if (bVar7 && param_1 != uVar4) {
            uVar3 = DAT_0802be9c;
          }
          if ((!bVar7 || param_1 == uVar4) || param_1 == uVar3) goto LAB_0802bcb6;
        }
        *(uint *)(param_1 + 4) = uVar5;
        *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & uVar1 | uVar6;
        *(uint *)(param_1 + 0x3c) = param_3[3];
        *(uint *)(param_1 + 0x20) = uVar2;
        goto LAB_0802be02;
      }
      if (param_2 == 0x1000) {
        *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffefff;
        uVar6 = *(uint *)(param_1 + 4);
        uVar2 = *param_3;
        uVar4 = *(uint *)(param_1 + 0x1c) & DAT_0802bea4;
        uVar3 = (*(uint *)(param_1 + 0x20) & 0xffffdfff | param_3[4] << 0xc) & 0xffffefff |
                param_3[1] << 0xc;
        uVar1 = param_3[1];
        if (param_1 != DAT_0802be80) {
          uVar1 = DAT_0802be90;
        }
        if (param_1 == DAT_0802be80 || param_1 == uVar1) {
LAB_0802bd34:
          uVar6 = uVar6 & 0xffffbfff | param_3[6] << 6;
        }
        else {
          bVar7 = param_1 != DAT_0802be94;
          if (bVar7) {
            uVar1 = DAT_0802be98;
          }
          uVar5 = DAT_0802be94;
          if (bVar7 && param_1 != uVar1) {
            uVar5 = DAT_0802be9c;
          }
          if ((!bVar7 || param_1 == uVar1) || param_1 == uVar5) goto LAB_0802bd34;
        }
        *(uint *)(param_1 + 4) = uVar6;
        *(uint *)(param_1 + 0x1c) = uVar4 | uVar2 << 8;
        *(uint *)(param_1 + 0x40) = param_3[3];
      }
      else {
        if (param_2 == 0x10000) {
          *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffeffff;
          uVar4 = *param_3;
          uVar2 = param_3[4];
          uVar6 = param_3[1];
          uVar1 = uVar6;
          if (param_1 != DAT_0802be80) {
            uVar1 = DAT_0802be90;
          }
          if (param_1 == DAT_0802be80 || param_1 == uVar1) {
LAB_0802bd8c:
            *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffeffff | param_3[6] << 8;
          }
          else {
            bVar7 = param_1 != DAT_0802be94;
            if (bVar7) {
              uVar1 = DAT_0802be98;
            }
            uVar5 = DAT_0802be94;
            if (bVar7 && param_1 != uVar1) {
              uVar5 = DAT_0802be9c;
            }
            if ((!bVar7 || param_1 == uVar1) || param_1 == uVar5) goto LAB_0802bd8c;
          }
          *(uint *)(param_1 + 0x54) = *(uint *)(param_1 + 0x54) & uVar3 | uVar4;
          uVar3 = *(uint *)(param_1 + 0x58);
          *(uint *)(param_1 + 0x58) = param_3[3];
          *(uint *)(param_1 + 0x20) =
               (*(uint *)(param_1 + 0x20) & 0xfffdffff | uVar2 << 0x10) & 0xfffeffff | uVar6 << 0x10
          ;
          goto LAB_0802be02;
        }
        if (param_2 != 0x100000) {
          return CONCAT44(param_2,1);
        }
        *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffefffff;
        uVar6 = *param_3;
        uVar4 = *(uint *)(param_1 + 0x54) & DAT_0802beac;
        uVar3 = (*(uint *)(param_1 + 0x20) & 0xffdfffff | param_3[4] << 0x14) & 0xffefffff |
                param_3[1] << 0x14;
        uVar1 = param_3[1];
        if (param_1 != DAT_0802be80) {
          uVar1 = DAT_0802be90;
        }
        if (param_1 == DAT_0802be80 || param_1 == uVar1) {
LAB_0802bdec:
          *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffbffff | param_3[6] << 10;
        }
        else {
          bVar7 = param_1 != DAT_0802be94;
          if (bVar7) {
            uVar1 = DAT_0802be98;
          }
          uVar2 = DAT_0802be94;
          if (bVar7 && param_1 != uVar1) {
            uVar2 = DAT_0802be9c;
          }
          if ((!bVar7 || param_1 == uVar1) || param_1 == uVar2) goto LAB_0802bdec;
        }
        *(uint *)(param_1 + 0x54) = uVar4 | uVar6 << 8;
        *(uint *)(param_1 + 0x5c) = param_3[3];
      }
    }
    *(uint *)(param_1 + 0x20) = uVar3;
    goto LAB_0802be02;
  }
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffe;
  uVar6 = *(uint *)(param_1 + 4);
  uVar4 = *param_3;
  if (param_1 != DAT_0802be80) {
    unaff_r7 = DAT_0802be90;
  }
  uVar2 = param_3[1] | (*(uint *)(param_1 + 0x20) & 0xfffffffd | param_3[4]) & 0xfffffffe;
  if (param_1 == DAT_0802be80 || param_1 == unaff_r7) {
LAB_0802bbac:
    uVar3 = param_3[7];
    uVar2 = (uVar2 & 0xfffffff7 | param_3[5] << 2) & 0xfffffffb | param_3[2] << 2;
    uVar6 = (uVar6 & 0xfffffeff | param_3[6]) & 0xfffffdff | uVar3 << 1;
  }
  else {
    bVar7 = param_1 != DAT_0802be94;
    uVar3 = DAT_0802be80;
    if (bVar7) {
      uVar3 = DAT_0802be98;
    }
    uVar5 = DAT_0802be94;
    if (bVar7 && param_1 != uVar3) {
      uVar5 = DAT_0802be9c;
    }
    if ((!bVar7 || param_1 == uVar3) || param_1 == uVar5) goto LAB_0802bbac;
  }
  *(uint *)(param_1 + 4) = uVar6;
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & uVar1 | uVar4;
  *(uint *)(param_1 + 0x34) = param_3[3];
  *(uint *)(param_1 + 0x20) = uVar2;
LAB_0802be02:
  return (ulonglong)uVar3 << 0x20;
}



/* ===== FUN_0802be0a @ 0802be0a ===== */

undefined4 FUN_0802be0a(uint param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  
  uVar2 = ((((((uint)(byte)param_2[3] | param_2[2] & 0xfffffbff | param_2[1]) & 0xfffff7ff |
             *param_2) & 0xffffefff | (uint)*(ushort *)((int)param_2 + 0xe)) & 0xffffdfff |
           param_2[4]) & 0xffffbfff | param_2[9]) & 0xffff7fff | param_2[9];
  bVar3 = param_1 == DAT_0802be80;
  uVar1 = param_2[4];
  if (!bVar3) {
    uVar1 = DAT_0802be90;
  }
  bVar4 = bVar3 || param_1 == uVar1;
  if (bVar3 || param_1 == uVar1) {
    uVar2 = uVar2 & 0xfff0ffff | param_2[5];
    bVar4 = param_1 == DAT_0802be80;
  }
  if ((bVar4) || (param_1 == DAT_0802be90)) {
    uVar2 = ((uVar2 & 0xff0fffff | param_2[8]) & 0xfeffffff | param_2[6]) & 0xfdffffff | param_2[7];
  }
  *(uint *)(param_1 + 0x44) = uVar2;
  return 0;
}



/* ===== FUN_0802beb0 @ 0802beb0 ===== */

int FUN_0802beb0(uint *param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar2 = param_1;
  while (((uint)puVar2 & 3) != 0) {
    puVar1 = (uint *)((int)puVar2 + 1);
    uVar4 = *puVar2;
    puVar2 = puVar1;
    if ((char)uVar4 == '\0') goto LAB_0802bee2;
  }
  uVar4 = *puVar2;
  while( true ) {
    uVar4 = uVar4 + 0xfefefeff & ~uVar4;
    uVar3 = uVar4 & 0x80808080;
    if (uVar3 != 0) break;
    puVar2 = puVar2 + 1;
    uVar4 = *puVar2;
  }
  puVar1 = (uint *)((int)puVar2 +
                   ((uint)LZCOUNT((uVar4 & 0x80) << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 |
                                  (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18) >> 3) + 1);
LAB_0802bee2:
  return (int)puVar1 - (int)((int)param_1 + 1);
}



/* ===== FUN_0802bee8 @ 0802bee8 ===== */

uint FUN_0802bee8(char *param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  char cVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  uint unaff_r11;
  bool bVar12;
  bool bVar13;
  
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  pcVar7 = param_1;
  while (iVar4 = FUN_0802eed0(*pcVar7), iVar2 = DAT_0802bfa0, iVar4 != 0) {
    pcVar7 = pcVar7 + 1;
  }
  cVar1 = *pcVar7;
  if (cVar1 == '-' || cVar1 == '+') {
    cVar6 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  }
  else {
    cVar6 = '+';
  }
  if ((((int)param_3 < 0) || (param_3 == 1)) || (0x24 < (int)param_3)) {
    if (param_2 == (undefined4 *)0x0) {
      return 0;
    }
    *param_2 = param_1;
    return 0;
  }
  pcVar8 = pcVar7;
  if ((int)param_3 < 1) {
    if (*pcVar7 != '0') {
      param_3 = 10;
      goto LAB_0802bf7e;
    }
    if ((byte)(pcVar7[1] | 0x20U) != 0x78) {
      param_3 = 8;
      goto LAB_0802bf7e;
    }
    param_3 = 0x10;
  }
  else {
    bVar12 = param_3 == 0x10;
    if (bVar12) {
      cVar1 = *pcVar7;
    }
    bVar13 = bVar12 && cVar1 == '0';
    if (bVar12 && cVar1 == '0') {
      bVar13 = (byte)(pcVar7[1] | 0x20U) == 0x78;
    }
    if (!bVar13) goto LAB_0802bf7e;
  }
  pcVar7 = pcVar7 + 2;
  pcVar8 = pcVar7;
LAB_0802bf7e:
  for (; *pcVar7 == '0'; pcVar7 = pcVar7 + 1) {
  }
  cVar1 = (char)DAT_0802bfa0;
  pcVar9 = pcVar7;
  uVar3 = 0;
  uVar11 = 0;
  while( true ) {
    uVar10 = uVar3;
    uVar5 = FUN_0802eee4(*pcVar9);
    iVar4 = FUN_0802c9e4(iVar2 + 0x802bfc8,uVar5,param_3);
    if (iVar4 == 0) break;
    unaff_r11 = iVar4 - (uint)(byte)(cVar1 - 0x38) & 0xff;
    pcVar9 = pcVar9 + 1;
    uVar3 = param_3 * uVar10 + unaff_r11;
    uVar11 = uVar10;
  }
  if (pcVar8 == pcVar9) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_1;
    }
    return 0;
  }
  if (((int)(pcVar9 + (-(uint)*(byte *)((int)&DAT_0802bfa0 + param_3 + iVar2) - (int)pcVar7)) < 0)
     || ((((int)(pcVar9 + (-(uint)*(byte *)((int)&DAT_0802bfa0 + param_3 + iVar2) - (int)pcVar7)) <
           1 && (unaff_r11 <= uVar10)) && ((uVar10 - unaff_r11) / param_3 == uVar11)))) {
    if (cVar6 == '-') {
      uVar10 = -uVar10;
    }
  }
  else {
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 1;
    }
    uVar10 = 0xffffffff;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = pcVar9;
  }
  return uVar10;
}



/* ===== thunk_FUN_0802c02a @ 0802c028 ===== */

void thunk_FUN_0802c02a(undefined4 param_1)

{
  FUN_0802bee8(param_1,0,10,0);
  return;
}



/* ===== FUN_0802c02a @ 0802c02a ===== */

void FUN_0802c02a(undefined4 param_1)

{
  FUN_0802bee8(param_1,0,10,0);
  return;
}



/* ===== FUN_0802c034 @ 0802c034 ===== */

void FUN_0802c034(uint param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0802c07c;
  DAT_0802c07c[1] = (uint)((ulonglong)param_1 * (ulonglong)DAT_0802c078 >> 0x29) - 1;
  puVar1[2] = 0;
  *puVar1 = 5;
  return;
}



/* ===== FUN_0802c050 @ 0802c050 ===== */

void FUN_0802c050(int param_1)

{
  if (param_1 == -1) goto LAB_0802c064;
  for (param_1 = param_1 + 1; param_1 != 0; param_1 = param_1 + -1) {
LAB_0802c064:
    do {
    } while (-1 < *DAT_0802c07c << 0xf);
  }
  return;
}



/* ===== FUN_0802c072 @ 0802c072 ===== */

void FUN_0802c072(undefined4 param_1)

{
  *DAT_0802c080 = param_1;
  return;
}



/* ===== FUN_0802c0a0 @ 0802c0a0 ===== */

int FUN_0802c0a0(int param_1)

{
  FUN_0802eef8(param_1,param_1 + 0xf8);
  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  FUN_080203a8(param_1 + 0x24,0xd4);
  *(undefined1 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(uint *)(param_1 + 0x14) =
       (uint)*(ushort *)(DAT_0802c0e0 + ((*(uint *)(DAT_0802c0e4 + 0x58) & 0x1fff) >> 10) * 2);
  return param_1;
}



/* ===== FUN_0802c0e8 @ 0802c0e8 ===== */

void FUN_0802c0e8(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *local_1c;
  undefined4 *local_18;
  int local_14;
  undefined4 uStack_4;
  
  local_1c = &uStack_4;
  if (param_2 == 0) {
    local_18 = (undefined4 *)0x0;
    local_14 = 0;
  }
  else {
    local_14 = param_2 + -1;
    local_18 = param_1;
  }
  uStack_4 = param_4;
  FUN_0802ef04((int)&DAT_0802c120 + DAT_0802c120,&local_18,param_3,&local_1c,0);
  if (local_18 != (undefined4 *)0x0) {
    *local_18 = 0;
  }
  return;
}



/* ===== FUN_0802c124 @ 0802c124 ===== */

undefined4 FUN_0802c124(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  byte bVar3;
  undefined4 local_10;
  
  if ((int)((param_2 >> 0x18) << 0x1f) < 0) {
    uVar1 = param_2 >> 0x19;
    if (2 < uVar1) {
      uVar1 = 2;
    }
    bVar3 = (byte)(param_2 >> ((uVar1 & 0x1f) << 3));
  }
  else {
    bVar3 = 0x20;
  }
  local_10._2_2_ = (undefined2)((uint)param_4 >> 0x10);
  local_10._0_2_ = (ushort)bVar3;
  uVar2 = FUN_0801fb10(DAT_0802c168);
  FUN_08019780(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
  FUN_08019d56(&local_10);
  FUN_0801fb10(uVar2);
  return local_10;
}



/* ===== FUN_0802c16c @ 0802c16c ===== */

/* WARNING: Removing unreachable block (ram,0x080269d4) */
/* WARNING: Removing unreachable block (ram,0x080269ee) */
/* WARNING: Removing unreachable block (ram,0x080269f8) */
/* WARNING: Removing unreachable block (ram,0x08026a0e) */
/* WARNING: Removing unreachable block (ram,0x08026a14) */
/* WARNING: Removing unreachable block (ram,0x08026a16) */
/* WARNING: Removing unreachable block (ram,0x080269da) */
/* WARNING: Removing unreachable block (ram,0x080269dc) */
/* WARNING: Removing unreachable block (ram,0x080269e0) */
/* WARNING: Removing unreachable block (ram,0x080269e6) */
/* WARNING: Removing unreachable block (ram,0x080269ec) */
/* WARNING: Removing unreachable block (ram,0x080269f6) */
/* WARNING: Removing unreachable block (ram,0x080269d8) */

longlong FUN_0802c16c(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  
  bVar2 = param_2 == 0;
  if (bVar2) {
    param_2 = *(uint *)(*DAT_0802c184 + 0xc);
  }
  if (bVar2 && param_2 == 0) {
    return (ulonglong)param_2 << 0x20;
  }
  uVar1 = FUN_0801fb84(param_2);
  if (uVar1 < param_1) {
    return (ulonglong)param_4 << 0x20;
  }
  return CONCAT44(param_4,*(int *)(param_2 + 4) + (ushort)(*(short *)(param_2 + 2) + 2) * param_1);
}



/* ===== FUN_0802c188 @ 0802c188 ===== */

void FUN_0802c188(char param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  uint unaff_r7;
  bool bVar6;
  
  pbVar4 = (byte *)*DAT_0802c1dc;
  bVar1 = *pbVar4;
  uVar5 = (uint)pbVar4[1];
  bVar2 = bVar1 + param_1;
  uVar3 = uVar5 + param_2;
  if (param_3 != 0) {
    bVar6 = bVar1 <= bVar2;
    if (bVar6) {
      bVar1 = pbVar4[2];
    }
    if (bVar6 && bVar2 <= bVar1) {
      bVar6 = uVar5 <= (uVar3 & 0xff);
      if (bVar6) {
        uVar5 = (uint)pbVar4[3];
        unaff_r7 = uVar3 & 0xff;
      }
      if (bVar6 && unaff_r7 <= uVar5) {
        *DAT_0802c1e0 = 0;
        FUN_0802e698(bVar2,uVar3 & 0xff,pbVar4[2],pbVar4[3],param_3,0,0);
        FUN_0802ad48();
        return;
      }
    }
  }
  return;
}



/* ===== FUN_0802c1e4 @ 0802c1e4 ===== */

void FUN_0802c1e4(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(ushort *)(DAT_0802c210 + 8) < 2) {
    return;
  }
  uVar1 = FUN_0802c16c(~-(uint)(param_2 == 0) >> 0x1f,DAT_0802c210);
  FUN_0802c188(*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2),uVar1);
  return;
}



/* ===== FUN_0802c214 @ 0802c214 ===== */

void FUN_0802c214(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 auStack_20 [12];
  
  uVar6 = DAT_0802c280;
  uVar1 = DAT_0802c27c;
  FUN_08019780(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
  uVar2 = (uint)((ulonglong)param_2 * (ulonglong)DAT_0802c27c >> 0x25);
  uVar5 = (uint)((ulonglong)uVar2 * (ulonglong)uVar1 >> 0x25);
  uVar1 = (uint)((ulonglong)uVar5 * (ulonglong)uVar6 >> 0x24);
  uVar3 = uVar2 + uVar5 * -0x3c & 0xff;
  uVar6 = uVar5 + uVar1 * -0x18 & 0xff;
  if (uVar1 == 0) {
    uVar4 = DAT_0802c284;
    uVar1 = uVar6;
    uVar6 = uVar3;
    uVar3 = param_2 + uVar2 * -0x3c & 0xff;
  }
  else {
    uVar4 = DAT_0802c288;
  }
  FUN_08016bd4(auStack_20,0xc,uVar4,uVar1,uVar6,uVar3);
  FUN_08019d56(auStack_20);
  return;
}



/* ===== FUN_0802c28c @ 0802c28c ===== */

undefined8 FUN_0802c28c(int param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  char local_18;
  char cStack_17;
  char cStack_16;
  undefined1 uStack_15;
  undefined4 uStack_14;
  
  uVar5 = *DAT_0802c2f4;
  local_18 = (char)uVar5;
  cStack_17 = (char)((uint)uVar5 >> 8);
  cStack_16 = (char)((uint)uVar5 >> 0x10);
  uStack_15 = (undefined1)((uint)uVar5 >> 0x18);
  if (param_2 < 0x65) {
    puVar4 = DAT_0802c2f4;
    if (param_2 < 0) goto LAB_0802c2e4;
  }
  else {
    param_2 = 100;
  }
  puVar4 = (undefined4 *)((longlong)param_2 * (longlong)DAT_0802c2f8);
  iVar3 = (int)((ulonglong)((longlong)param_2 * (longlong)DAT_0802c2f8) >> 0x20);
  param_3 = (iVar3 >> 2) - (iVar3 >> 0x1f);
  cVar1 = (char)param_3;
  cStack_16 = (char)param_2 + cVar1 * -10 + '0';
  if (cVar1 != '\0') {
    cVar2 = (char)((longlong)(int)cVar1 * (longlong)DAT_0802c2f8 >> 0x22) -
            (char)((longlong)(int)cVar1 * (longlong)DAT_0802c2f8 >> 0x3f);
    cStack_17 = cVar1 + cVar2 * -10 + '0';
    param_3 = (int)cVar2;
    if (param_3 != 0) {
      local_18 = cVar2 + '0';
    }
  }
LAB_0802c2e4:
  uStack_14 = param_4;
  FUN_08019780(*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2),param_3,puVar4);
  FUN_08019d56(&local_18);
  return CONCAT44(uStack_14,CONCAT13(uStack_15,CONCAT12(cStack_16,CONCAT11(cStack_17,local_18))));
}



/* ===== FUN_0802c2fc @ 0802c2fc ===== */

void FUN_0802c2fc(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3,undefined1 *param_4)

{
  if (param_1 != (undefined1 *)0x0) {
    *param_1 = *(undefined1 *)*DAT_0802c32c;
  }
  if (param_2 != (undefined1 *)0x0) {
    *param_2 = *(undefined1 *)(*DAT_0802c32c + 1);
  }
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = *(undefined1 *)(*DAT_0802c32c + 2);
  }
  if (param_4 != (undefined1 *)0x0) {
    *param_4 = *(undefined1 *)(*DAT_0802c32c + 3);
  }
  return;
}



/* ===== FUN_0802c330 @ 0802c330 ===== */

undefined8 FUN_0802c330(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  longlong lVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  char local_18;
  char local_17;
  char local_16;
  char local_15;
  uint local_14;
  
  iVar4 = (int)param_2 >> 4;
  local_14 = param_4 & 0xffffff00;
  cVar2 = (char)iVar4;
  switch(param_2 & 0xf) {
  case 1:
    iVar4 = (int)((ulonglong)((longlong)iVar4 * (longlong)DAT_0802c484) >> 0x20);
    iVar4 = (iVar4 >> 2) - (iVar4 >> 0x1f);
    cVar3 = (char)iVar4;
    local_15 = cVar2 + cVar3 * -10 + '0';
    lVar1 = (longlong)iVar4 * (longlong)DAT_0802c484;
    local_18 = (char)(lVar1 >> 0x22) - (char)(lVar1 >> 0x3f);
    local_16 = cVar3 + local_18 * -10 + '0';
    local_18 = local_18 + '0';
    local_17 = '.';
    break;
  case 2:
    iVar4 = (int)((ulonglong)((longlong)iVar4 * (longlong)DAT_0802c484) >> 0x20);
    iVar4 = (iVar4 >> 2) - (iVar4 >> 0x1f);
    cVar3 = (char)iVar4;
    local_15 = cVar2 + cVar3 * -10 + '0';
    local_16 = '.';
    lVar1 = (longlong)iVar4 * (longlong)DAT_0802c484;
    local_18 = (char)(lVar1 >> 0x22) - (char)(lVar1 >> 0x3f);
    local_17 = cVar3 + local_18 * -10 + '0';
    local_18 = local_18 + '0';
    break;
  case 3:
    local_15 = ' ';
    iVar4 = (int)((ulonglong)((longlong)iVar4 * (longlong)DAT_0802c484) >> 0x20);
    iVar4 = (iVar4 >> 2) - (iVar4 >> 0x1f);
    cVar3 = (char)iVar4;
    local_16 = cVar2 + cVar3 * -10 + '0';
    lVar1 = (longlong)iVar4 * (longlong)DAT_0802c484;
    local_18 = (char)(lVar1 >> 0x22) - (char)(lVar1 >> 0x3f);
    local_17 = cVar3 + local_18 * -10 + '0';
    local_18 = local_18 + '0';
    break;
  case 4:
    local_17 = (char)((longlong)iVar4 * (longlong)DAT_0802c484 >> 0x22) -
               (char)((longlong)iVar4 * (longlong)DAT_0802c484 >> 0x3f);
    local_15 = cVar2 + local_17 * -10 + '0';
    local_17 = local_17 + '0';
    local_16 = '.';
    local_18 = '>';
    break;
  case 5:
    local_15 = ' ';
    local_17 = (char)((longlong)iVar4 * (longlong)DAT_0802c484 >> 0x22) -
               (char)((longlong)iVar4 * (longlong)DAT_0802c484 >> 0x3f);
    local_16 = cVar2 + local_17 * -10 + '0';
    local_17 = local_17 + '0';
    local_18 = '>';
    break;
  default:
    local_15 = '-';
    local_16 = '-';
    local_17 = '-';
    local_18 = ' ';
  }
  FUN_08019780(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
  FUN_08019d56(&local_18);
  return CONCAT44(local_14,CONCAT13(local_15,CONCAT12(local_16,CONCAT11(local_17,local_18))));
}



/* ===== FUN_0802c488 @ 0802c488 ===== */

void FUN_0802c488(int param_1,uint param_2,uint param_3,int param_4)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  byte bVar10;
  uint uVar11;
  
  pbVar4 = DAT_0802c690;
  pbVar3 = DAT_0802c68c;
  pbVar2 = DAT_0802c688;
  uVar9 = (uint)*DAT_0802c68c;
  uVar11 = (uint)*DAT_0802c690;
  bVar8 = (byte)param_1;
  if ((uint)*DAT_0802c688 < (uint)*DAT_0802c684) {
    *DAT_0802c684 = bVar8;
LAB_0802c4bc:
    *pbVar2 = bVar8;
  }
  else if (param_1 < (int)(uint)*DAT_0802c684) {
    *DAT_0802c684 = bVar8;
  }
  else if ((int)(uint)*DAT_0802c688 < param_1) goto LAB_0802c4bc;
  iVar5 = DAT_0802c698;
  uVar6 = param_2;
  if (uVar11 < uVar9) {
LAB_0802c4d4:
    uVar9 = uVar6;
    uVar11 = param_2;
  }
  else if ((int)param_2 < (int)uVar9) {
    uVar9 = param_2;
  }
  else {
    uVar6 = uVar9;
    if ((int)uVar11 < (int)param_2) goto LAB_0802c4d4;
  }
  uVar6 = param_3;
  if (uVar9 <= uVar11) {
    if ((int)param_3 < (int)uVar9) {
      uVar9 = param_3;
      goto LAB_0802c4ec;
    }
    uVar6 = uVar9;
    if ((int)param_3 <= (int)uVar11) goto LAB_0802c4ec;
  }
  uVar9 = uVar6;
  uVar11 = param_3;
LAB_0802c4ec:
  bVar8 = (byte)uVar9;
  bVar10 = (byte)uVar11;
  uVar9 = param_1 + (param_2 >> 3) * 0x80;
  bVar7 = *(byte *)(DAT_0802c694 + (param_2 & 7));
  bVar1 = *(byte *)(DAT_0802c69c + (param_3 & 7));
  for (param_2 = param_2 & 0xfff8; uVar9 = uVar9 & 0xffff, param_2 <= (param_3 & 0xf8);
      param_2 = param_2 + 8 & 0xffff) {
    if (param_2 == (param_3 & 0xf8)) {
      bVar7 = bVar7 & bVar1;
    }
    if (param_4 == 0) {
      if (bVar7 == 0xff) {
        bVar7 = 0;
      }
      else {
        bVar7 = *(byte *)(iVar5 + uVar9) & ~bVar7;
      }
    }
    else if (bVar7 != 0xff) {
      bVar7 = bVar7 | *(byte *)(iVar5 + uVar9);
    }
    *(byte *)(iVar5 + uVar9) = bVar7;
    uVar9 = uVar9 + 0x80;
    bVar7 = 0xff;
  }
  if (*DAT_0802c6a0 == '\0') {
    *pbVar4 = bVar10;
    *pbVar3 = bVar8;
    FUN_0802ad48();
    bVar8 = *pbVar3;
    bVar10 = *pbVar4;
  }
  *pbVar4 = bVar10;
  *pbVar3 = bVar8;
  return;
}



/* ===== FUN_0802c56e @ 0802c56e ===== */

void FUN_0802c56e(uint param_1,uint param_2,uint param_3,int param_4)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  uint uVar11;
  
  pbVar3 = DAT_0802c690;
  pbVar2 = DAT_0802c688;
  pbVar1 = DAT_0802c684;
  uVar8 = (uint)*DAT_0802c684;
  uVar11 = (uint)*DAT_0802c688;
  uVar9 = param_1;
  if (uVar11 < uVar8) {
LAB_0802c592:
    uVar8 = uVar9;
    uVar11 = param_1;
  }
  else if ((int)param_1 < (int)uVar8) {
    uVar8 = param_1;
  }
  else {
    uVar9 = uVar8;
    if ((int)uVar11 < (int)param_1) goto LAB_0802c592;
  }
  uVar9 = param_3;
  if (uVar11 < uVar8) {
LAB_0802c5a8:
    bVar7 = (byte)uVar9;
    uVar11 = param_3;
  }
  else {
    bVar7 = (byte)uVar8;
    if ((int)param_3 < (int)uVar8) {
      bVar7 = (byte)param_3;
    }
    else {
      uVar9 = uVar8;
      if ((int)uVar11 < (int)param_3) goto LAB_0802c5a8;
    }
  }
  bVar10 = (byte)uVar11;
  bVar5 = (byte)param_2;
  if ((uint)*DAT_0802c690 < (uint)*DAT_0802c68c) {
    *DAT_0802c68c = bVar5;
  }
  else {
    if ((int)param_2 < (int)(uint)*DAT_0802c68c) {
      *DAT_0802c68c = bVar5;
      goto LAB_0802c5d2;
    }
    if ((int)param_2 <= (int)(uint)*DAT_0802c690) goto LAB_0802c5d2;
  }
  *pbVar3 = bVar5;
LAB_0802c5d2:
  iVar4 = DAT_0802c698;
  uVar8 = param_1 + (param_2 >> 3) * 0x80;
  bVar5 = *(byte *)(DAT_0802c6a4 + (param_2 & 7));
  uVar9 = param_1;
  if (param_4 == 0) {
    bVar5 = ~bVar5;
  }
  while (uVar9 <= param_3) {
    uVar8 = uVar8 & 0xffff;
    bVar6 = *(byte *)(iVar4 + uVar8);
    if (param_4 == 0) {
      bVar6 = bVar6 & bVar5;
    }
    else {
      bVar6 = bVar6 | bVar5;
    }
    *(byte *)(iVar4 + uVar8) = bVar6;
    param_1 = param_1 + 1;
    uVar8 = uVar8 + 1;
    uVar9 = param_1 & 0xff;
  }
  if (*DAT_0802c6a0 == '\0') {
    *pbVar2 = bVar10;
    *pbVar1 = bVar7;
    FUN_0802ad48();
    bVar7 = *pbVar1;
    bVar10 = *pbVar2;
  }
  *pbVar2 = bVar10;
  *pbVar1 = bVar7;
  return;
}



/* ===== FUN_0802c630 @ 0802c630 ===== */

void FUN_0802c630(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  *DAT_0802c6a8 = 0;
  if (param_1 != param_3) {
    FUN_0802c56e(param_1,param_2,param_3,param_5);
  }
  if ((param_2 == param_4) || (FUN_0802c488(param_1,param_2,param_4,param_5), param_1 == param_3)) {
    return;
  }
  FUN_0802c56e(param_1,param_4,param_3,param_5);
  FUN_0802c488(param_3,param_2,param_4,param_5);
  return;
}



/* ===== FUN_0802c6ac @ 0802c6ac ===== */

int FUN_0802c6ac(uint param_1,uint param_2,int param_3)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  byte bVar11;
  uint uVar12;
  uint uVar13;
  
  pbVar5 = DAT_0802c750;
  pbVar4 = DAT_0802c74c;
  pbVar3 = DAT_0802c748;
  pbVar2 = DAT_0802c744;
  bVar6 = *DAT_0802c744;
  uVar7 = (uint)bVar6;
  uVar8 = (uint)*DAT_0802c748;
  bVar11 = *DAT_0802c74c;
  uVar12 = (uint)bVar11;
  uVar10 = (uint)*DAT_0802c750;
  *DAT_0802c754 = 0;
  bVar1 = *(byte *)(DAT_0802c758 + (param_2 & 7));
  iVar9 = param_1 + (param_2 >> 3) * 0x80;
  if (param_3 == 0) {
    *(byte *)(DAT_0802c75c + iVar9) = *(byte *)(DAT_0802c75c + iVar9) & ~bVar1;
  }
  else {
    *(byte *)(DAT_0802c75c + iVar9) = bVar1 | *(byte *)(DAT_0802c75c + iVar9);
  }
  uVar13 = param_1;
  if (uVar10 < uVar12) {
LAB_0802c71a:
    bVar11 = (byte)uVar13;
    uVar10 = param_1;
  }
  else if ((int)param_1 < (int)uVar12) {
    bVar11 = (byte)param_1;
  }
  else {
    uVar13 = uVar12;
    if ((int)uVar10 < (int)param_1) goto LAB_0802c71a;
  }
  uVar12 = param_2;
  if (uVar7 <= uVar8) {
    if ((int)param_2 < (int)uVar7) {
      bVar6 = (byte)param_2;
      goto LAB_0802c732;
    }
    uVar12 = uVar7;
    if ((int)param_2 <= (int)uVar8) goto LAB_0802c732;
  }
  bVar6 = (byte)uVar12;
  uVar8 = param_2;
LAB_0802c732:
  *pbVar5 = (byte)uVar10;
  *pbVar4 = bVar11;
  *pbVar3 = (byte)uVar8;
  *pbVar2 = bVar6;
  return iVar9;
}



/* ===== FUN_0802c7aa @ 0802c7aa ===== */

int FUN_0802c7aa(float param_1,int param_2)

{
  char cVar1;
  
  if (param_1 <= 0.0) {
    return 0;
  }
  cVar1 = (char)(int)(*(float *)(param_2 + 0x1c) * param_1);
  if (cVar1 == '\0') {
    cVar1 = '\x01';
  }
  return (int)cVar1;
}



/* ===== FUN_0802c7d2 @ 0802c7d2 ===== */

int FUN_0802c7d2(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 4) - *(int *)(param_1 + 8);
  iVar2 = iVar1 + 1;
  if (iVar2 < 0) {
    iVar2 = iVar1 + 0x6b;
  }
  return iVar2;
}



/* ===== FUN_0802c8c0 @ 0802c8c0 ===== */

undefined4 FUN_0802c8c0(void)

{
  return DAT_0802c984;
}



/* ===== FUN_0802c8c4 @ 0802c8c4 ===== */

void FUN_0802c8c4(byte *param_1,int param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  uint unaff_r6;
  
  iVar1 = *(int *)(param_3 + 4);
  pbVar2 = (byte *)(param_3 + iVar1);
  for (; iVar1 < 4; iVar1 = iVar1 + 1) {
    if (param_2 != 0) {
      *pbVar2 = *param_1;
      unaff_r6 = (uint)*param_1;
      param_1 = param_1 + 1;
      pbVar2 = pbVar2 + 1;
    }
    if (param_2 == 0 || unaff_r6 == 0) break;
    param_2 = param_2 + -1;
  }
  *(int *)(param_3 + 4) = iVar1;
  return;
}



/* ===== FUN_0802c8ec @ 0802c8ec ===== */

undefined8 FUN_0802c8ec(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_2 != 0) {
    FUN_0802c8c4();
    iVar1 = (**(code **)(param_4 + 0x34))(param_3,*(undefined4 *)(param_3 + 4));
    if (iVar1 != -2) {
      if (iVar1 == -1) {
        return CONCAT44(param_4,0xffffffff);
      }
      *(undefined4 *)(param_3 + 4) = 0;
      return CONCAT44(param_4,iVar1);
    }
  }
  return CONCAT44(param_4,0xfffffffe);
}



/* ===== FUN_0802c918 @ 0802c918 ===== */

undefined8 FUN_0802c918(int param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  if (param_3 != 0) {
    FUN_0802c8c4(param_2,param_3,param_4);
    if (param_1 == 0) {
      iVar1 = (**(code **)(param_5 + 0x34))(param_4);
    }
    else {
      iVar1 = (**(code **)(param_5 + 0x38))(param_1,param_4,*(undefined4 *)(param_4 + 4));
    }
    if (iVar1 != -2) {
      if (iVar1 == -1) {
        return CONCAT44(param_4,0xffffffff);
      }
      *(undefined4 *)(param_4 + 4) = 0;
      return CONCAT44(param_4,iVar1);
    }
  }
  return CONCAT44(param_4,0xfffffffe);
}



/* ===== FUN_0802c96a @ 0802c96a ===== */

void FUN_0802c96a(void)

{
  FUN_0802c8ec();
  return;
}



/* ===== FUN_0802c96e @ 0802c96e ===== */

void FUN_0802c96e(void)

{
  FUN_0802c918();
  return;
}



/* ===== FUN_0802c97a @ 0802c97a ===== */

void FUN_0802c97a(void)

{
                    /* WARNING: Could not recover jumptable at 0x0802c968. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(DAT_0802c984 + 0x3c))();
  return;
}



/* ===== FUN_0802c97e @ 0802c97e ===== */

undefined4 FUN_0802c97e(void)

{
  return DAT_0802c988;
}



/* ===== FUN_0802c98c @ 0802c98c ===== */

char * FUN_0802c98c(char *param_1,char param_2)

{
  char cVar1;
  
  cVar1 = *param_1;
  while ((cVar1 != '\0' && (cVar1 != param_2))) {
    param_1 = param_1 + 1;
    cVar1 = *param_1;
  }
  if (cVar1 != param_2) {
    param_1 = (char *)0x0;
  }
  return param_1;
}



/* ===== FUN_0802c9a4 @ 0802c9a4 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0802c9a4(char *param_1)

{
  undefined4 unaff_r7;
  
  if (param_1 == (char *)0x0) {
    param_1 = "constraint handler: bad message";
  }
  if ((code *)*_DAT_0802c9c0 == (code *)0x0) {
    FUN_0802df14(param_1);
  }
  else {
    (*(code *)*_DAT_0802c9c0)(param_1,0,0x22);
  }
  return CONCAT44(unaff_r7,0x22);
}



/* ===== FUN_0802c9e4 @ 0802c9e4 ===== */

char * FUN_0802c9e4(uint *param_1,char param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  
  while (((uint)param_1 & 3) != 0) {
    bVar6 = param_3 == 0;
    param_3 = param_3 - 1;
    bVar5 = param_3 == 0;
    if (bVar6) goto LAB_0802ca34;
    puVar1 = (uint *)((int)param_1 + 1);
    uVar2 = *param_1;
    param_1 = puVar1;
    if (param_2 == (char)uVar2) goto LAB_0802ca38;
  }
  uVar2 = param_3 - 8;
  if (7 < param_3) {
    uVar2 = param_3 - 4;
    puVar1 = param_1;
    do {
      param_1 = puVar1;
      bVar5 = 3 < uVar2;
      uVar2 = uVar2 - 4;
      uVar4 = uVar2;
      if (bVar5) {
        uVar4 = *param_1 ^ CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
        uVar4 = uVar4 + 0xfefefeff & ~uVar4 & 0x80808080;
      }
      puVar1 = param_1 + 1;
    } while (uVar4 == 0);
  }
  iVar3 = uVar2 + 8;
  puVar1 = param_1;
  do {
    param_1 = (uint *)((int)puVar1 + 1);
    bVar6 = iVar3 != 0;
    iVar3 = iVar3 + -1;
    bVar5 = iVar3 == 0;
    if (bVar6) {
      bVar5 = param_2 == (char)*puVar1;
    }
    puVar1 = param_1;
  } while (bVar6 && !bVar5);
LAB_0802ca34:
  puVar1 = param_1;
  if (!bVar5) {
    puVar1 = (uint *)0x1;
  }
LAB_0802ca38:
  return (char *)((int)puVar1 + -1);
}



/* ===== FUN_0802ca3c @ 0802ca3c ===== */

void FUN_0802ca3c(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 extraout_r2;
  
  FUN_0802ca48();
  *param_3 = extraout_r2;
  return;
}



/* ===== FUN_0802ca48 @ 0802ca48 ===== */

undefined8 FUN_0802ca48(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (param_2 & 0x7fffffff) >> 0x14;
  if (uVar3 == 0) {
    if (param_1 != 0 || (param_2 & 0x7fffffff) != 0) {
      uVar3 = param_2 & ~(param_2 & 0x80000000);
      iVar1 = LZCOUNT(uVar3);
      if (uVar3 == 0) {
        iVar1 = LZCOUNT(param_1) + 0x20;
      }
      uVar2 = iVar1 - 0xb;
      if (0x1f < uVar2) {
        uVar3 = param_1 << (iVar1 - 0x2bU & 0xff);
      }
      else {
        uVar3 = uVar3 << (uVar2 & 0xff);
      }
      uVar3 = uVar3 | param_2 & 0x80000000;
      if (0x1f >= uVar2) {
        uVar3 = uVar3 | param_1 >> (0x20 - uVar2 & 0xff);
      }
      return CONCAT44(uVar3 + 0x3fd00000,param_1 << (uVar2 & 0xff));
    }
  }
  else if (param_2 << 1 < 0xffe00000) {
    return CONCAT44(param_2 + (uVar3 - 0x3fe) * -0x100000,param_1);
  }
  return CONCAT44(param_2,param_1);
}



/* ===== FUN_0802caac @ 0802caac ===== */

void FUN_0802caac(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = param_2 * 2;
  if (uVar1 < 0xffe00001) {
    uVar1 = param_4 * 2;
  }
  if ((uVar1 < 0xffe00001) && ((int)(param_2 | param_4) < 0)) {
    return;
  }
  return;
}



/* ===== FUN_0802cadc @ 0802cadc ===== */

void FUN_0802cadc(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = param_2 * 2;
  if (uVar1 < 0xffe00001) {
    uVar1 = param_4 * 2;
  }
  if ((uVar1 < 0xffe00001) && ((int)(param_2 | param_4) < 0)) {
    return;
  }
  return;
}



/* ===== FUN_0802cb0c @ 0802cb0c ===== */

longlong FUN_0802cb0c(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  if ((int)param_3 < 0) {
    uVar7 = -param_3;
    uVar6 = param_2 >> 0x14 & 0x7ff;
    if (uVar6 != 0) {
      if (uVar6 == 0x7ff) goto LAB_0802cb82;
      if (uVar7 < uVar6) {
        return CONCAT44(param_2 + param_3 * 0x100000,param_1);
      }
      uVar7 = (uVar7 - uVar6) + 1;
      param_2 = param_2 & ~(uVar6 << 0x14) | 0x100000;
    }
    if (param_1 == 0 && (param_2 & 0x7fffffff) == 0) goto LAB_0802cb82;
    uVar6 = param_2 & 0x80000000;
    if ((int)uVar7 < 0x36) {
      param_2 = param_2 ^ uVar6;
      uVar8 = uVar7 - 0x20;
      if ((int)uVar7 < 0x20) {
        uVar2 = uVar7 & 0xff;
        uVar5 = param_1 >> (uVar7 & 0xff) | param_2 << (0x20 - uVar7 & 0xff);
        uVar3 = uVar7 & 0xff;
        uVar8 = param_2 >> (uVar7 & 0xff);
        uVar1 = 0x20 - uVar7 & 0xff;
        bVar9 = uVar1 == 0 &&
                (uVar3 == 0 &&
                 (uVar2 == 0 && 0x1f < uVar7 || uVar2 != 0 && (param_1 >> uVar2 - 1 & 1) != 0) ||
                uVar3 != 0 && (param_2 >> uVar3 - 1 & 1) != 0) ||
                uVar1 != 0 && (param_1 << uVar1 - 1 & 0x80000000) != 0;
        param_1 = param_1 << uVar1;
      }
      else {
        uVar7 = param_1 >> (uVar8 & 0xff);
        if ((param_1 & 0x7fffffff) != 0) {
          uVar7 = uVar7 | 1;
        }
        uVar5 = param_2 >> (uVar8 & 0xff);
        uVar8 = 0x20 - uVar8 & 0xff;
        bVar9 = uVar8 == 0 && (param_1 & 0x80000000) != 0 ||
                uVar8 != 0 && (param_2 << uVar8 - 1 & 0x80000000) != 0;
        param_1 = uVar7 | param_2 << uVar8;
        uVar8 = 0;
      }
      bVar9 = 0x80000000 < param_1 || param_1 + 0x80000000 < (uint)bVar9;
      iVar4 = uVar5 + bVar9;
      uVar6 = uVar8 + uVar6 + CARRY4(uVar5,(uint)bVar9);
      if (param_1 == 0) {
        return CONCAT44(uVar6,iVar4);
      }
    }
    else {
      iVar4 = 0;
    }
    goto code_r0x0802cb38;
  }
  uVar7 = param_2 >> 0x14 & 0x7ff;
  if (uVar7 != 0) {
    if (uVar7 == 0x7ff) goto LAB_0802cb82;
    uVar7 = uVar7 + param_3;
LAB_0802cb20:
    if (uVar7 < 0x7ff) {
      return CONCAT44(param_2 + param_3 * 0x100000,param_1);
    }
    uVar6 = param_2 & 0x80000000 | 0x7ff00000;
    iVar4 = 0;
code_r0x0802cb38:
    return CONCAT44(uVar6,iVar4);
  }
  if (param_1 == 0 && (param_2 & 0x7fffffff) == 0) goto LAB_0802cb82;
  uVar7 = param_2 & 0x80000000;
  param_2 = param_2 ^ uVar7;
  if (param_2 == 0) {
    uVar6 = LZCOUNT(param_1) + 0x15;
    if (uVar6 < 0x20) goto LAB_0802cb50;
    if (0x1f < param_3) {
      param_3 = param_3 - 0x20;
      uVar6 = LZCOUNT(param_1) - 0xb;
      if (param_3 <= uVar6) {
        return (ulonglong)(param_1 << (param_3 & 0xff) | uVar7) << 0x20;
      }
      param_3 = param_3 - uVar6;
      param_2 = param_1 << (uVar6 & 0xff) | uVar7;
      param_1 = 0;
      uVar7 = param_3 + 1;
      goto LAB_0802cb20;
    }
  }
  else {
    uVar6 = LZCOUNT(param_2) - 0xb;
LAB_0802cb50:
    if (uVar6 < param_3) {
      param_3 = param_3 - uVar6;
      param_2 = (param_2 << (uVar6 & 0xff) | uVar7) + (param_1 >> (0x20 - uVar6 & 0xff));
      param_1 = param_1 << (uVar6 & 0xff);
      uVar7 = param_3 + 1;
      goto LAB_0802cb20;
    }
  }
  param_2 = param_2 << (param_3 & 0xff) | uVar7 | param_1 >> (0x20 - param_3 & 0xff);
  param_1 = param_1 << (param_3 & 0xff);
LAB_0802cb82:
  return CONCAT44(param_2,param_1);
}



/* ===== FUN_0802cc48 @ 0802cc48 ===== */

uint FUN_0802cc48(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = (param_2 & 0x7fffffff) >> 0x14;
  iVar2 = uVar1 - 0x3fe;
  if (iVar2 == 0 || uVar1 < 0x3fe) {
    return 0;
  }
  uVar3 = -iVar2 + 0x20;
  uVar1 = (int)param_2 >> 0x1f;
  if (uVar3 != 0 && iVar2 < 0x21) {
    return ((param_2 << 0xb | param_1 >> 0x15 | 0x80000000) >> (uVar3 & 0xff)) + uVar1 ^ uVar1;
  }
  uVar3 = 0;
  if (-iVar2 != -0x401) {
    uVar3 = ~uVar1 ^ 0x80000000;
  }
  return uVar3;
}



/* ===== FUN_0802cc84 @ 0802cc84 ===== */

undefined8 FUN_0802cc84(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = (int)param_1 >> 0x1f;
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = (param_1 ^ uVar3) - uVar3;
    iVar4 = LZCOUNT(iVar1);
    uVar2 = iVar1 << iVar4;
    uVar3 = (uVar3 << 0x1f | (0x420 - (iVar4 + 3)) * 0x100000) + (uVar2 >> 0xb);
    iVar1 = uVar2 << 0x15;
  }
  return CONCAT44(uVar3,iVar1);
}



/* ===== FUN_0802cca8 @ 0802cca8 ===== */

longlong FUN_0802cca8(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  
  if ((int)(param_2 ^ param_4) < 0) {
    param_4 = param_4 ^ 0x80000000;
    uVar6 = param_1 - param_3;
    iVar10 = (param_2 - param_4) - (uint)(param_3 > param_1);
    if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
      bVar11 = param_1 < uVar6;
      param_1 = param_1 - uVar6;
      param_2 = (param_2 - iVar10) - (uint)bVar11;
      bVar11 = CARRY4(param_3,uVar6);
      param_3 = param_3 + uVar6;
      param_4 = param_4 + iVar10 + (uint)bVar11;
    }
    if (param_2 << 1 < 0xffe00000 && 0x1fffff < param_4 * 2) {
      uVar6 = (param_2 >> 0x14) - (param_4 >> 0x14);
      if (0x35 < (int)uVar6) goto LAB_0802cd82;
      param_4 = (param_4 << 0xb | 0x80000000) >> 0xb;
    }
    else {
      if (0xffdfffff < param_2 << 1) {
        return CONCAT44(param_2,param_1);
      }
      if (param_3 == 0 && (param_4 & 0x7fffffff) == 0) {
LAB_0802cd82:
        return CONCAT44(param_2,param_1);
      }
      if (param_2 * 2 < 0x200001 && param_2 * -2 != -0x200000) {
        bVar11 = CARRY4(param_1,param_3);
        param_1 = param_1 + param_3;
        param_2 = param_2 + (param_4 & 0x7fffffff) + (uint)bVar11;
        goto LAB_0802cd82;
      }
      param_4 = param_4 & 0x7fffffff;
      uVar6 = (param_2 >> 0x14) - 1;
      if (0x34 < (int)uVar6) goto LAB_0802cd82;
    }
    uVar3 = (int)(param_2 << 0xb | 0x80000000) >> 0xb;
    uVar7 = uVar6 - 0x20;
    if (uVar7 == 0 || (int)uVar6 < 0x20) {
      uVar4 = param_3 >> (uVar6 & 0xff);
      uVar8 = (param_3 >> (uVar6 & 0x1f) | param_3 << 0x20 - (uVar6 & 0x1f)) ^ uVar4;
      uVar7 = param_4 >> (uVar6 & 0x1f) | param_4 << 0x20 - (uVar6 & 0x1f);
      uVar5 = (uVar7 << (uVar6 & 0xff)) >> (uVar6 & 0xff);
      uVar4 = uVar4 ^ uVar7 ^ uVar5;
      uVar6 = param_1 + uVar4;
      uVar7 = uVar3 + uVar5 + (uint)CARRY4(param_1,uVar4);
      if (!CARRY4(uVar3,uVar5) && !CARRY4(uVar3 + uVar5,(uint)CARRY4(param_1,uVar4)))
      goto LAB_0802cd38;
    }
    else {
      uVar4 = param_4 >> (uVar7 & 0xff);
      uVar8 = (param_4 >> (uVar7 & 0x1f) | param_4 << 0x20 - (uVar7 & 0x1f)) ^ uVar4;
      if (param_3 != 0) {
        uVar8 = uVar8 | 1;
      }
      uVar6 = param_1 + uVar4;
      uVar7 = uVar3 + CARRY4(param_1,uVar4);
      if (!CARRY4(uVar3,(uint)CARRY4(param_1,uVar4))) goto LAB_0802cd38;
    }
    uVar3 = uVar7 & 1;
    uVar7 = uVar7 >> 1;
    bVar2 = (byte)uVar6;
    uVar6 = (uint)(uVar3 != 0) << 0x1f | uVar6 >> 1;
    uVar3 = uVar8 & 1;
    uVar8 = (uint)(bVar2 & 1) << 0x1f | uVar8 >> 1;
    if (uVar3 != 0) {
      uVar8 = uVar8 | 1;
    }
LAB_0802cd38:
    bVar11 = 0x80000000 < uVar8 || uVar8 + 0x80000000 < (uint)((uVar6 & 1) != 0);
    uVar3 = uVar7 + 0x100000 + (param_2 & 0xfff00000) + (uint)CARRY4(uVar6,(uint)bVar11);
    if (uVar3 * 2 < 0xffe00000) {
      return CONCAT44(uVar3,uVar6 + bVar11);
    }
    return (ulonglong)(uVar3 & 0xfff00000) << 0x20;
  }
  uVar6 = param_1 - param_3;
  if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
    uVar3 = (param_2 - param_4) - (uint)(param_3 > param_1) ^ 0x80000000;
    bVar11 = param_1 < uVar6;
    param_1 = param_1 - uVar6;
    param_2 = (param_2 - uVar3) - (uint)bVar11;
    bVar11 = CARRY4(param_3,uVar6);
    param_3 = param_3 + uVar6;
    param_4 = param_4 + uVar3 + (uint)bVar11;
  }
  uVar6 = param_2;
  if (param_2 << 1 < 0xffe00000 && 0x1fffff < param_4 * 2) {
    uVar3 = param_2 >> 0x14;
    uVar7 = uVar3 - (param_4 >> 0x14);
    if (0x36 < (int)uVar7) goto LAB_0802f23e;
    uVar4 = param_4 << 0xb | 0x80000000;
    if ((int)uVar7 < 2) {
      uVar4 = uVar4 | param_3 >> 0x15;
      if (uVar7 == 1) {
        param_3 = param_3 << 10;
        uVar4 = uVar4 >> 1;
      }
      else {
        param_3 = param_3 << 0xb;
      }
      uVar7 = param_1 >> 0x15;
      uVar6 = param_1 * 0x800;
      param_1 = uVar6 - param_3;
      uVar7 = ((param_2 << 0xb | 0x80000000 | uVar7) - uVar4) - (uint)(uVar6 < param_3);
      uVar6 = uVar3 << 0x14;
      if (-1 < (int)uVar7) {
        if (uVar7 == 0) {
          iVar10 = LZCOUNT(param_1);
          uVar7 = param_1 << iVar10;
          uVar6 = 0;
          if (uVar7 == 0) goto LAB_0802f23e;
          param_1 = 0;
          iVar10 = iVar10 + 0x20;
        }
        else {
          iVar10 = LZCOUNT(uVar7);
          uVar7 = uVar7 << iVar10 | param_1 >> (0x20U - iVar10 & 0xff);
          param_1 = param_1 << iVar10;
        }
        uVar4 = -((int)param_2 >> 0x1f) | uVar3 << 0x15;
        uVar6 = uVar4 + iVar10 * -0x200000;
        uVar5 = uVar6 & 0xfffffffe;
        uVar3 = ((int)param_2 >> 0x1f) * -0x80000000;
        uVar6 = uVar6 >> 1 | uVar3;
        if (uVar4 < (uint)(iVar10 * 0x200000) || uVar5 == 0) {
          uVar5 = 0x200000 - uVar5 >> 0x15;
          uVar6 = uVar7 >> (uVar5 & 0x1f);
          uVar4 = uVar7 << 0x20 - (uVar5 & 0x1f);
          uVar7 = uVar7 >> (uVar5 & 0xff);
          param_1 = param_1 >> (uVar5 & 0xff) ^ (uVar6 | uVar4) ^ uVar7;
          uVar6 = uVar3;
        }
      }
      uVar3 = param_1 >> 0xb | uVar7 << 0x15;
      bVar11 = (param_1 >> 10 & 1) != 0 && (param_1 >> 0xb & 1) != 0;
      param_1 = uVar3 + bVar11;
      uVar6 = uVar6 + ((uVar7 & 0x7fffffff) >> 0xb) + (uint)CARRY4(uVar3,(uint)bVar11);
      goto LAB_0802f23e;
    }
    uVar4 = uVar4 >> 0xb;
LAB_0802f1d4:
    uVar3 = param_2 >> 0x14;
    uVar6 = (param_2 << 0xb | 0x80000000) >> 0xb;
    uVar5 = uVar7 - 0x20;
    if (uVar5 == 0 || (int)uVar7 < 0x20) {
      uVar5 = param_3 >> (uVar7 & 0xff);
      uVar9 = (param_3 >> (uVar7 & 0x1f) | param_3 << 0x20 - (uVar7 & 0x1f)) ^ uVar5;
      uVar8 = uVar4 >> (uVar7 & 0xff);
      uVar4 = uVar5 ^ (uVar4 >> (uVar7 & 0x1f) | uVar4 << 0x20 - (uVar7 & 0x1f)) ^ uVar8;
      uVar7 = (param_1 - uVar4) - (uint)(uVar9 != 0);
      uVar6 = (uVar6 - uVar8) - (uint)(param_1 <= uVar4 && (uint)(uVar9 == 0) <= param_1 - uVar4);
    }
    else {
      uVar8 = uVar4 >> (uVar5 & 0xff);
      uVar9 = (param_3 | param_3 << 0x10) >> 0x10 | uVar4 << (0x20 - uVar5 & 0xff);
      uVar7 = (param_1 - uVar8) - (uint)(uVar9 != 0);
      uVar6 = uVar6 - (param_1 <= uVar8 && (uint)(uVar9 == 0) <= param_1 - uVar8);
    }
    uVar4 = -uVar9;
    if (((uVar6 & 0x100000) == 0) && (uVar3 = uVar3 - 1, (uVar3 & 0x7ff) != 0)) {
      bVar1 = (uVar4 & 0x80000000) != 0;
      uVar4 = uVar9 * -2;
      uVar5 = uVar7 * 2;
      bVar11 = CARRY4(uVar7,uVar7);
      uVar7 = uVar7 * 2 + (uint)bVar1;
      uVar6 = uVar6 * 2 + (uint)(bVar11 || CARRY4(uVar5,(uint)bVar1));
    }
    bVar11 = 0x80000000 < uVar4 || uVar4 + 0x80000000 < (uint)((uVar7 & 1) != 0);
    param_1 = uVar7 + bVar11;
    uVar6 = (uVar6 & 0xffefffff) + uVar3 * 0x100000 + (uint)CARRY4(uVar7,(uint)bVar11);
  }
  else {
    if (0xffdfffff < param_2 * 2) {
      if (param_2 * 2 != 0xffe00000 || 0xffdfffff < param_4 << 1) {
        uVar6 = 0xffffffff;
      }
      goto LAB_0802f23e;
    }
    uVar4 = param_4 & 0x7fffffff;
    if (param_3 != 0 || (param_4 & 0x7fffffff) != 0) {
      if (0x400000 < param_2 * 2 || param_2 * -2 == -0x400000) {
        uVar7 = (param_2 >> 0x14) - 1;
        if (0x34 < (int)uVar7) goto LAB_0802f23e;
        goto LAB_0802f1d4;
      }
      bVar11 = param_1 < param_3;
      param_1 = param_1 - param_3;
      uVar6 = (param_2 - uVar4) - (uint)bVar11;
    }
    if (param_1 == 0 && (uVar6 & 0x7fffffff) == 0) {
      uVar6 = 0;
    }
  }
LAB_0802f23e:
  return CONCAT44(uVar6,param_1);
}



/* ===== FUN_0802cd8c @ 0802cd8c ===== */

ulonglong FUN_0802cd8c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint unaff_r7;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  undefined1 in_CY;
  bool bVar14;
  
  uVar12 = (param_2 ^ param_4) & 0x80000000;
  uVar5 = param_2 >> 0x14 & 0x7ff;
  bVar14 = uVar5 == 0;
  if (!bVar14) {
    unaff_r7 = param_4 >> 0x14 & 0x7ff;
    bVar14 = unaff_r7 == 0;
  }
  if (!bVar14) {
    in_CY = 0x7fe < uVar5;
    bVar14 = uVar5 == 0x7ff;
  }
  if (!bVar14) {
    in_CY = 0x7fe < unaff_r7;
    bVar14 = unaff_r7 == 0x7ff;
  }
  if (bVar14) {
    if (uVar5 != 0x7ff) {
      unaff_r7 = param_4 >> 0x14 & 0x7ff;
    }
    if (uVar5 == 0x7ff || unaff_r7 == 0x7ff) {
      uVar5 = param_2 * 2;
      if (uVar5 < 0xffe00001) {
        uVar5 = param_4 * 2;
      }
      if (uVar5 == 0xffe00000) {
        uVar5 = param_2 << 1;
      }
      if (uVar5 < 0xffe00000) {
        if ((param_4 & 0x7fffffff) != 0x7ff00000) {
          uVar12 = uVar12 | 0x7ff00000;
        }
      }
      else {
        uVar12 = 0xffffffff;
      }
      return (ulonglong)uVar12 << 0x20;
    }
    bVar1 = (param_2 & 0x7fffffff) == 0;
    bVar14 = param_1 == 0 && bVar1;
    uVar8 = 0;
    if (param_1 != 0 || !bVar1) {
      uVar8 = param_3 | param_4 << 1;
      bVar14 = uVar8 == 0;
    }
    if (bVar14) {
      if (param_1 != 0 || (param_2 & 0x7fffffff) != 0) {
        return CONCAT44(param_2 ^ param_4,uVar8) & 0x80000000ffffffff | 0x7ff0000000000000;
      }
      if (param_3 == 0 && (param_4 & 0x7fffffff) == 0) {
        uVar12 = ~uVar8;
      }
      return CONCAT44(uVar12,uVar8);
    }
    if (unaff_r7 == 0) {
      uVar3 = param_3 * 2;
      iVar4 = param_4 * 2 + (uint)CARRY4(param_3,param_3);
      iVar11 = LZCOUNT(iVar4);
      if (iVar4 == 0) {
        iVar11 = LZCOUNT(uVar3) + 0x20;
      }
      uVar8 = iVar11 - 0xb;
      if (uVar8 < 0x20) {
        param_4 = iVar4 << (uVar8 & 0xff) | uVar3 >> (0x20 - uVar8 & 0xff);
      }
      else {
        param_4 = uVar3 << (iVar11 - 0x2bU & 0xff);
      }
      param_3 = uVar3 << (uVar8 & 0xff);
      if (uVar5 != 0) {
        iVar4 = uVar5 + uVar8 + -1;
        goto LAB_0802cdac;
      }
    }
    else {
      uVar8 = -unaff_r7;
    }
    param_2 = param_2 & 0x7fffffff;
    iVar4 = LZCOUNT(param_2);
    if (param_2 == 0) {
      iVar4 = LZCOUNT(param_1) + 0x20;
    }
    uVar5 = iVar4 - 0xb;
    if (uVar5 < 0x20) {
      param_2 = param_2 << (uVar5 & 0xff) | param_1 >> (0x20 - uVar5 & 0xff);
    }
    else {
      param_2 = param_1 << (iVar4 - 0x2bU & 0xff);
    }
    param_1 = param_1 << (uVar5 & 0xff);
    iVar4 = uVar8 - uVar5;
  }
  else {
    iVar4 = (uVar5 - unaff_r7) - (uint)!(bool)in_CY;
  }
LAB_0802cdac:
  param_2 = param_2 & 0xfffff;
  param_4 = param_4 & 0xfffff;
  uVar5 = param_1 - param_3;
  iVar11 = (param_2 - param_4) - (uint)(param_3 > param_1);
  uVar8 = param_4 | 0x100000;
  if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
    iVar4 = iVar4 + -1;
    uVar3 = uVar5 & 0x80000000;
    uVar2 = uVar5 * 2;
    uVar5 = uVar2 + param_3;
    iVar11 = iVar11 * 2 + (uint)(uVar3 != 0) + uVar8 + (uint)CARRY4(uVar2,param_3);
  }
  uVar2 = iVar11 << 0xb | uVar5 >> 0x15;
  uVar7 = uVar2 / uVar8;
  uVar2 = uVar2 - uVar8 * uVar7;
  uVar9 = (uint)((ulonglong)param_3 * (ulonglong)uVar7);
  uVar6 = (uint)((ulonglong)param_3 * (ulonglong)uVar7 >> 0x20);
  uVar5 = uVar5 * 0x800;
  uVar3 = uVar5 - uVar9;
  iVar11 = (uVar2 - uVar6) - (uint)(uVar9 > uVar5);
  if (uVar2 <= uVar6 && (uint)(uVar9 <= uVar5) <= uVar2 - uVar6) {
    uVar7 = uVar7 - 1;
    bVar14 = CARRY4(uVar3,param_3);
    uVar3 = uVar3 + param_3;
    iVar11 = iVar11 + uVar8 + (uint)bVar14;
  }
  uVar2 = iVar11 << 0xb | uVar3 >> 0x15;
  uVar13 = uVar2 / uVar8;
  uVar2 = uVar2 - uVar8 * uVar13;
  uVar9 = (uint)((ulonglong)param_3 * (ulonglong)uVar13);
  uVar6 = (uint)((ulonglong)param_3 * (ulonglong)uVar13 >> 0x20);
  uVar3 = uVar3 * 0x800;
  uVar5 = uVar3 - uVar9;
  iVar11 = (uVar2 - uVar6) - (uint)(uVar9 > uVar3);
  if (uVar2 <= uVar6 && (uint)(uVar9 <= uVar3) <= uVar2 - uVar6) {
    uVar13 = uVar13 - 1;
    bVar14 = CARRY4(uVar5,param_3);
    uVar5 = uVar5 + param_3;
    iVar11 = iVar11 + uVar8 + (uint)bVar14;
  }
  uVar2 = iVar11 << 10 | uVar5 >> 0x16;
  uVar9 = uVar2 / uVar8;
  uVar2 = uVar2 - uVar8 * uVar9;
  uVar10 = (uint)((ulonglong)param_3 * (ulonglong)uVar9);
  uVar6 = (uint)((ulonglong)param_3 * (ulonglong)uVar9 >> 0x20);
  uVar5 = uVar5 * 0x400;
  uVar3 = uVar5 - uVar10;
  iVar11 = (uVar2 - uVar6) - (uint)(uVar10 > uVar5);
  if (uVar2 <= uVar6 && (uint)(uVar10 <= uVar5) <= uVar2 - uVar6) {
    uVar9 = uVar9 - 1;
    bVar14 = CARRY4(uVar3,param_3);
    uVar3 = uVar3 + param_3;
    iVar11 = iVar11 + uVar8 + (uint)bVar14;
  }
  uVar2 = iVar11 << 0xb | uVar3 >> 0x15;
  uVar9 = uVar7 << 0x15 | uVar13 << 10 | uVar9;
  uVar7 = uVar2 / uVar8;
  uVar2 = uVar2 - uVar8 * uVar7;
  uVar13 = (uint)((ulonglong)param_3 * (ulonglong)uVar7);
  uVar6 = (uint)((ulonglong)param_3 * (ulonglong)uVar7 >> 0x20);
  uVar3 = uVar3 * 0x800;
  uVar5 = uVar3 - uVar13;
  iVar11 = (uVar2 - uVar6) - (uint)(uVar13 > uVar3);
  if (uVar2 <= uVar6 && (uint)(uVar13 <= uVar3) <= uVar2 - uVar6) {
    uVar7 = uVar7 - 1;
    bVar14 = CARRY4(uVar5,param_3);
    uVar5 = uVar5 + param_3;
    iVar11 = iVar11 + uVar8 + (uint)bVar14;
  }
  uVar3 = iVar11 << 0xb | uVar5 >> 0x15;
  uVar6 = uVar3 / uVar8;
  uVar3 = uVar3 - uVar8 * uVar6;
  uVar8 = (uint)((ulonglong)param_3 * (ulonglong)uVar6);
  uVar2 = (uint)((ulonglong)param_3 * (ulonglong)uVar6 >> 0x20);
  uVar5 = uVar5 * 0x800;
  uVar6 = uVar6 - (uVar3 <= uVar2 && (uint)(uVar8 <= uVar5) <= uVar3 - uVar2);
  if (uVar3 - uVar2 != (uint)(uVar8 > uVar5) || uVar5 != uVar8) {
    uVar6 = uVar6 | 1;
  }
  uVar5 = (uVar6 & 0xffc007ff | (uVar7 & 0x7ff) << 0xb) >> 2;
  iVar11 = iVar4 + 0x400;
  if (iVar11 != 0 && -0x401 < iVar4) {
    bVar14 = 0x80000000 < uVar6 * 0x40000000 ||
             uVar6 * 0x40000000 + 0x80000000 < (uint)((uVar6 & 4) != 0);
    uVar8 = uVar9 * 0x100000;
    uVar3 = (uVar9 >> 0xc) +
            iVar11 * 0x100000 + (uint)(CARRY4(uVar5,uVar8) || CARRY4(uVar5 + uVar8,(uint)bVar14));
    if ((int)(uVar3 + 0x100000) < 0) {
      return (ulonglong)(uVar12 | 0x7ff00000) << 0x20;
    }
    return CONCAT44(uVar3 | uVar12,uVar5 + uVar8 + bVar14);
  }
  uVar2 = (uVar6 & 3) << 0x1d;
  uVar5 = uVar5 | uVar9 << 0x14;
  uVar8 = uVar9 >> 0xc | 0x100000;
  uVar3 = -iVar11 + 1;
  uVar6 = -iVar11 - 0x1f;
  if ((int)uVar3 < 0x20) {
    uVar13 = uVar3 & 0xff;
    uVar10 = uVar3 & 0xff;
    uVar6 = uVar8 >> (uVar3 & 0xff);
    uVar7 = uVar5 >> (uVar3 & 0xff) | uVar8 << (0x20 - uVar3 & 0xff);
    uVar9 = 0x20 - uVar3 & 0xff;
    bVar14 = uVar9 == 0 &&
             (uVar10 == 0 &&
              (uVar13 == 0 && 0x1f < uVar3 || uVar13 != 0 && (uVar5 >> uVar13 - 1 & 1) != 0) ||
             uVar10 != 0 && (uVar8 >> uVar10 - 1 & 1) != 0) ||
             uVar9 != 0 && (uVar5 << uVar9 - 1 & 0x80000000) != 0;
    uVar2 = uVar2 | uVar5 << uVar9;
  }
  else {
    if (0x34 < (int)uVar3) {
      return (ulonglong)uVar12 << 0x20;
    }
    uVar7 = uVar8 >> (uVar6 & 0xff);
    uVar3 = 0x20 - uVar6 & 0xff;
    bVar14 = uVar3 != 0 && (uVar8 << uVar3 - 1 & 0x80000000) != 0;
    uVar2 = (uVar2 | uVar5 << 1) >> 1 | uVar5 >> (uVar6 & 0xff) | uVar8 << uVar3;
    uVar6 = 0;
  }
  bVar14 = 0x80000000 < uVar2 || uVar2 + 0x80000000 < (uint)bVar14;
  return CONCAT44(uVar6 + uVar12 + CARRY4(uVar7,(uint)bVar14),uVar7 + bVar14);
}



/* ===== FUN_0802cfd4 @ 0802cfd4 ===== */

uint FUN_0802cfd4(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (!CARRY4(param_2,param_2)) {
    uVar2 = (param_2 & 0x7fffffff) >> 0x14;
    uVar1 = param_1 >> 0x15 | param_2 << 0xb | 0x80000000;
    if (-2 < (int)(uVar2 - 0x400)) {
      uVar2 = 0x1f - (uVar2 - 0x3ff);
      if ((int)uVar2 < 0) {
        uVar1 = (int)uVar1 >> 0x1f;
      }
      else {
        uVar1 = uVar1 >> (uVar2 & 0xff);
      }
      return uVar1;
    }
  }
  return 0;
}



/* ===== FUN_0802cffc @ 0802cffc ===== */

undefined8 FUN_0802cffc(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  if (param_1 != 0) {
    uVar1 = param_1 << LZCOUNT(param_1);
    iVar3 = (0x420 - (LZCOUNT(param_1) + 3)) * 0x100000 + (uVar1 >> 0xb);
    iVar2 = uVar1 << 0x15;
  }
  return CONCAT44(iVar3,iVar2);
}



/* ===== FUN_0802d018 @ 0802d018 ===== */

longlong FUN_0802d018(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint unaff_r7;
  uint uVar9;
  int iVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  
  uVar11 = (param_2 ^ param_4) & 0x80000000;
  uVar7 = param_2 >> 0x14 & 0x7ff;
  bVar12 = uVar7 == 0;
  if (!bVar12) {
    unaff_r7 = param_4 >> 0x14 & 0x7ff;
    bVar12 = unaff_r7 == 0;
  }
  if (!bVar12) {
    bVar12 = uVar7 == 0x7ff;
  }
  if (!bVar12) {
    bVar12 = unaff_r7 == 0x7ff;
  }
  if (bVar12) {
    uVar9 = param_4 >> 0x14 & 0x7ff;
    if (uVar7 == 0x7ff || uVar9 == 0x7ff) {
      bVar12 = (param_2 & 0x7fffffff) == 0;
      bVar13 = param_1 == 0 && bVar12;
      if (param_1 != 0 || !bVar12) {
        bVar13 = param_3 == 0 && (param_4 & 0x7fffffff) == 0;
      }
      if (bVar13) {
        param_2 = 0xffffffff;
      }
      uVar7 = param_4 * 2;
      if (uVar7 < 0xffe00001) {
        uVar7 = param_2 * 2;
        param_4 = param_2;
      }
      if (uVar7 < 0xffe00001) {
        return (ulonglong)(uVar11 | 0x7ff00000) << 0x20;
      }
      goto LAB_0802d0c6;
    }
    bVar13 = (param_2 & 0x7fffffff) == 0;
    bVar12 = param_1 == 0 && bVar13;
    if (param_1 != 0 || !bVar13) {
      bVar12 = param_3 == 0 && (param_4 & 0x7fffffff) == 0;
    }
    if (!bVar12) {
      if (uVar7 != 0) {
        param_4 = param_4 & 0x7fffffff;
        iVar8 = LZCOUNT(param_4);
        if (param_4 == 0) {
          iVar8 = LZCOUNT(param_3) + 0x20;
        }
        uVar4 = iVar8 - 0xb;
        if (uVar4 < 0x20) {
          uVar6 = param_4 << (uVar4 & 0xff) | param_3 >> (0x20 - uVar4 & 0xff);
        }
        else {
          uVar6 = param_3 << (iVar8 - 0x2bU & 0xff);
        }
        param_3 = param_3 << (uVar4 & 0xff);
        iVar8 = ((uVar7 + uVar9) - uVar4) + 1;
        goto LAB_0802d040;
      }
      if (uVar9 != 0) {
        uVar7 = param_1;
        uVar6 = param_2 << 0xc;
        if (param_2 << 0xc == 0) {
          uVar7 = 0;
          uVar9 = uVar9 - 0x14;
          uVar6 = param_1;
        }
        iVar10 = LZCOUNT(uVar6);
        iVar8 = uVar9 - iVar10;
        param_1 = uVar7 << iVar10 + 0xc;
        uVar7 = uVar6 << iVar10 | uVar7 >> (0x20U - (iVar10 + 0xc) & 0xff);
        uVar6 = param_4 & 0x1fffff | 0x100000;
        goto LAB_0802d04c;
      }
    }
  }
  else {
    iVar8 = uVar7 + unaff_r7;
    uVar6 = param_4 & 0x1fffff | 0x100000;
LAB_0802d040:
    uVar7 = param_2 << 0xb | 0x80000000 | param_1 >> 0x15;
    param_1 = param_1 << 0xb;
LAB_0802d04c:
    uVar1 = (ulonglong)uVar7 * (ulonglong)param_3 +
            ((ulonglong)param_1 * (ulonglong)param_3 >> 0x20);
    uVar9 = (uint)(uVar1 >> 0x20);
    lVar2 = (ulonglong)uVar6 * (ulonglong)param_1 + (uVar1 & 0xffffffff);
    uVar5 = (uint)lVar2;
    uVar4 = (uint)((ulonglong)lVar2 >> 0x20);
    if ((int)((ulonglong)param_1 * (ulonglong)param_3) != 0) {
      uVar5 = uVar5 | 1;
    }
    uVar1 = (ulonglong)uVar6 * (ulonglong)uVar7 +
            (ulonglong)CONCAT14(CARRY4(uVar9,uVar4),uVar9 + uVar4);
    uVar7 = (uint)uVar1;
    uVar6 = (uint)(uVar1 >> 0x20);
    bVar12 = (uVar1 & 0x10000000000000) != 0;
    if (!bVar12) {
      bVar13 = (uVar5 & 0x80000000) != 0;
      uVar5 = uVar5 << 1;
      bVar14 = CARRY4(uVar7,uVar7) || CARRY4(uVar7 * 2,(uint)bVar13);
      bVar12 = CARRY4(uVar6,uVar6) || CARRY4(uVar6 * 2,(uint)bVar14);
      uVar1 = CONCAT44(uVar6 * 2 + (uint)bVar14,uVar7 * 2 + (uint)bVar13);
    }
    uVar6 = (uint)(uVar1 >> 0x20);
    uVar7 = (uint)uVar1;
    iVar10 = iVar8 + -0x3ff + (uint)bVar12;
    if (iVar10 != 0 &&
        iVar10 < 0 == (SCARRY4(iVar8 + -0x400,1) != SCARRY4(iVar8 + -0x3ff,(uint)bVar12))) {
      bVar12 = 0x80000000 < uVar5 || uVar5 + 0x80000000 < (uint)((uVar1 & 1) != 0);
      iVar8 = uVar6 + iVar10 * 0x100000 + (uint)CARRY4(uVar7,(uint)bVar12);
      if (iVar8 < 0) {
        return (ulonglong)(uVar11 | 0x7ff00000) << 0x20;
      }
      return CONCAT44(iVar8 - 0x100000U | uVar11,uVar7 + bVar12);
    }
    uVar9 = -iVar10 + 1;
    uVar4 = -iVar10 - 0x1f;
    if ((int)uVar9 < 0x20) {
      bVar12 = (uVar5 & 1) != 0;
      uVar5 = uVar5 >> 1;
      if (bVar12) {
        uVar5 = uVar5 | 1;
      }
      uVar4 = 0x20 - uVar9 & 0xff;
      bVar12 = uVar4 == 0 && bVar12 || uVar4 != 0 && (uVar7 << uVar4 - 1 & 0x80000000) != 0;
      uVar5 = uVar5 | uVar7 << uVar4;
      uVar3 = uVar7 >> (uVar9 & 0xff) | uVar6 << (0x20 - uVar9 & 0xff);
      uVar6 = uVar6 >> (uVar9 & 0xff);
LAB_0802d1ac:
      bVar12 = 0x80000000 < uVar5 || uVar5 + 0x80000000 < (uint)bVar12;
      return CONCAT44(uVar6 + uVar11 + CARRY4(uVar3,(uint)bVar12),uVar3 + bVar12);
    }
    if ((int)uVar9 < 0x36) {
      uVar7 = uVar7 >> (uVar4 & 0xff);
      if (uVar5 != 0 || (uVar1 & 0x7fffffff) != 0) {
        uVar7 = uVar7 | 1;
      }
      uVar5 = uVar4 & 0xff;
      uVar3 = uVar6 >> uVar5;
      uVar9 = 0x20 - uVar4 & 0xff;
      bVar12 = uVar9 == 0 &&
               (uVar5 == 0 && (bool)((byte)(uVar1 >> 0x18) >> 7) ||
               uVar5 != 0 && (uVar6 >> uVar5 - 1 & 1) != 0) ||
               uVar9 != 0 && (uVar6 << uVar9 - 1 & 0x80000000) != 0;
      uVar5 = uVar7 | uVar6 << uVar9;
      uVar6 = 0;
      goto LAB_0802d1ac;
    }
  }
  param_1 = 0;
  param_4 = uVar11;
LAB_0802d0c6:
  return CONCAT44(param_4,param_1);
}



/* ===== FUN_0802d1ba @ 0802d1ba ===== */

undefined8 FUN_0802d1ba(void)

{
  int iVar1;
  undefined4 unaff_r7;
  
  iVar1 = FUN_0802c8c0();
  return CONCAT44(unaff_r7,*(undefined4 *)(iVar1 + 0x40));
}



/* ===== FUN_0802d1c4 @ 0802d1c4 ===== */

void FUN_0802d1c4(uint *param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = FUN_0802d204();
  iVar2 = DAT_0802d304;
  puVar1 = DAT_0802d300;
  *param_1 = uVar3;
  param_1[1] = uVar3 >> *(sbyte *)(iVar2 + ((*puVar1 & 0xff) >> 4));
  iVar2 = DAT_0802d30c;
  param_1[2] = param_1[1] >> *(sbyte *)(DAT_0802d30c + ((*puVar1 & 0x7ff) >> 8));
  param_1[3] = param_1[1] >> *(sbyte *)(iVar2 + ((*puVar1 & 0x3fff) >> 0xb));
  return;
}



/* ===== FUN_0802d204 @ 0802d204 ===== */

uint FUN_0802d204(void)

{
  uint uVar1;
  
  uVar1 = DAT_0802d2f0[2] & 0xc;
  if (uVar1 == 0) {
LAB_0802d2b0:
    if ((int)(*DAT_0802d2f0 << 0x1c) < 0) {
      if ((int)(*DAT_0802d2f0 << 0x1c) < 0) {
        uVar1 = *DAT_0802d2f0 & 0xf0;
      }
      else {
        uVar1 = *DAT_0802d308 & 0xf00;
      }
      uVar1 = uVar1 >> 4;
    }
    else {
      if ((int)(*DAT_0802d2f0 << 0x1c) < 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = *DAT_0802d308 & 0xf00;
      }
      uVar1 = uVar1 >> 8;
    }
    return *(uint *)(DAT_0802d314 + uVar1 * 4);
  }
  if (uVar1 == 4) {
    return DAT_0802d310;
  }
  if (uVar1 == 8) {
    return DAT_0802d318;
  }
  if (uVar1 != 0xc) goto LAB_0802d2b0;
  uVar1 = DAT_0802d2f0[3] & 3;
  if ((uVar1 != 1) && (uVar1 != 0)) {
    if (uVar1 == 3) {
      uVar1 = DAT_0802d318;
      goto LAB_0802d292;
    }
    if (uVar1 < 3) {
      uVar1 = DAT_0802d310;
      goto LAB_0802d292;
    }
  }
  if ((int)(*DAT_0802d2f0 << 0x1c) < 0) {
    if ((int)(*DAT_0802d2f0 << 0x1c) < 0) {
      uVar1 = *DAT_0802d2f0 & 0xf0;
    }
    else {
      uVar1 = *DAT_0802d308 & 0xf00;
    }
    uVar1 = *(uint *)(DAT_0802d314 + (uVar1 >> 4) * 4);
  }
  else {
    if ((int)(*DAT_0802d2f0 << 0x1c) < 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *DAT_0802d308 & 0xf00;
    }
    uVar1 = *(uint *)(DAT_0802d314 + (uVar1 >> 8) * 4);
  }
LAB_0802d292:
  return (((DAT_0802d2f0[3] & 0x7fff) >> 8) * (uVar1 / (((DAT_0802d2f0[3] & 0x7f) >> 4) + 1))) /
         ((((DAT_0802d2f0[3] & 0x7ffffff) >> 0x19) + 1) * 2);
}



/* ===== FUN_0802d90c @ 0802d90c ===== */

undefined4 FUN_0802d90c(void)

{
  return DAT_0802d918;
}



/* ===== FUN_0802d91c @ 0802d91c ===== */

ulonglong FUN_0802d91c(int param_1,undefined4 param_2,uint param_3)

{
  char cVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  bool bVar6;
  uint local_18;
  
  puVar2 = DAT_0802d970;
  piVar5 = *(int **)(param_1 + 0x10);
  local_18 = param_3;
  if (piVar5 != (int *)0x0) {
    cVar1 = *(char *)(param_1 + 0x15);
    bVar6 = cVar1 == '\x01';
    if (bVar6) {
      cVar1 = *(char *)(param_1 + 0x14);
    }
    if (bVar6 && cVar1 == '\0') {
      *DAT_0802d970 = *DAT_0802d970 | 0x800000;
      uVar4 = *puVar2;
      local_18 = uVar4 & 0x800000;
      (**(code **)(*piVar5 + 0x10))(piVar5,param_1 + 0x28);
      *puVar2 = *puVar2 & 0xff7fffff;
      iVar3 = FUN_08022d90(param_1,(int)(char)piVar5[1]);
      if (iVar3 == 0) {
        return CONCAT44(uVar4,param_1 + 0x28) & 0x800000ffffffff;
      }
    }
  }
  return (ulonglong)local_18 << 0x20;
}



/* ===== FUN_0802d974 @ 0802d974 ===== */

char FUN_0802d974(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  undefined4 uVar5;
  float fVar6;
  
  piVar4 = *(int **)(param_1 + 0x38);
  if (piVar4 == (int *)0x0) {
    FUN_08016aea(4);
    *(uint *)(DAT_0802da7c + 8) = *(uint *)(DAT_0802da7c + 8) & 0xfff7ffff;
    *DAT_0802da80 = 0x2000;
    return -1;
  }
  iVar1 = (**(code **)(*piVar4 + 8))(piVar4);
  if (*(char *)((int)piVar4 + 5) == '\0') {
    iVar2 = *(int *)(param_1 + 0x10);
    uVar5 = VectorSignedFixedToFloat(iVar1,0x20,8);
    *(undefined4 *)(param_1 + 0x18) = uVar5;
    cVar3 = '\0';
    if (iVar2 < 2) {
      *(int *)(param_1 + 0x10) = iVar2 + 1;
      if (iVar2 < 1) {
        return '\0';
      }
      iVar1 = iVar1 << 6;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x14);
      iVar1 = (iVar1 + iVar2) - ((int)(iVar2 + ((uint)(iVar2 >> 5) >> 0x1a)) >> 6);
    }
    *(int *)(param_1 + 0x14) = iVar1;
    iVar1 = DAT_0802da7c;
    uVar5 = VectorSignedFixedToFloat(*(undefined4 *)(param_1 + 0x14),0x20,0xe);
    *(undefined4 *)(param_1 + 0x1c) = uVar5;
    if (*(int *)(iVar1 + 8) << 0xb < 0) {
      fVar6 = *(float *)(param_1 + 0x18) - *(float *)(param_1 + 0x1c);
      if (fVar6 < 0.0) {
        if (fVar6 < *(float *)(param_1 + 0x2c)) {
          *(float *)(param_1 + 0x2c) = fVar6;
        }
      }
      else if (*(float *)(param_1 + 0x28) < fVar6) {
        *(float *)(param_1 + 0x28) = fVar6;
      }
    }
    else {
      FUN_080170a4();
      *(float *)(param_1 + 0x1c) = *(float *)(param_1 + 0x1c) + *(float *)(param_1 + 0x30);
    }
    FUN_080170fc(*(undefined4 *)(param_1 + 0x1c));
    FUN_08015aa8(*(undefined4 *)(param_1 + 0x1c));
  }
  else {
    cVar3 = *(char *)((int)piVar4 + 5) + '\x10';
    if (*(char *)(param_1 + 0x34) == '\0') {
      *(char *)(param_1 + 0x34) = cVar3;
    }
    FUN_08016aea(4);
    *(uint *)(DAT_0802da7c + 8) = *(uint *)(DAT_0802da7c + 8) & 0xfff7ffff;
    *DAT_0802da80 = 0x2000;
  }
  return cVar3;
}



/* ===== FUN_0802da84 @ 0802da84 ===== */

void FUN_0802da84(int param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_0802dd3c;
  *(uint *)(param_1 + 8) = DAT_0802dd3c[2];
  *(uint *)(param_1 + 0xc) = puVar1[3];
  *(uint *)(param_1 + 0x10) = *puVar1 & 0x18;
  *(uint *)(param_1 + 0x14) = *puVar1 & 0x60;
  *(uint *)(param_1 + 0x18) = *puVar1 & 0x80;
  *puVar1 = *puVar1 & 0xffffff9f;
  *puVar1 = *puVar1 & 0xffffff7f;
  puVar1[3] = 0x31;
  *puVar1 = *puVar1 & 0xffffffe7 | 0x10;
  puVar1[2] = 0xffffffff;
  *puVar1 = *puVar1 | 1;
  return;
}



/* ===== FUN_0802dad6 @ 0802dad6 ===== */

void FUN_0802dad6(int param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_0802dd3c;
  *DAT_0802dd3c = *DAT_0802dd3c & 0xffffff9f | *(uint *)(param_1 + 0x14);
  *puVar1 = *puVar1 & 0xffffff7f | *(uint *)(param_1 + 0x18);
  puVar1[3] = *(uint *)(param_1 + 0xc);
  *puVar1 = *puVar1 & 0xffffffe7 | *(uint *)(param_1 + 0x10);
  puVar1[2] = *(uint *)(param_1 + 8);
  *puVar1 = *puVar1 | 1;
  return;
}



/* ===== FUN_0802db0e @ 0802db0e ===== */

undefined4 FUN_0802db0e(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  undefined1 local_24;
  undefined1 local_23;
  byte local_22;
  undefined1 local_21;
  undefined1 local_20;
  byte local_1f;
  undefined4 uStack_1c;
  
  piVar3 = DAT_0802dd48;
  uVar2 = DAT_0802dd44;
  puVar1 = DAT_0802dd40;
  *(undefined1 *)(param_1 + 5) = 0xff;
  *puVar1 = *puVar1 | 0x200000;
  *(undefined1 *)(param_1 + 4) = 0x88;
  uStack_1c = param_4;
  iVar5 = FUN_0802aa70(uVar2,0x88,0x94,0,0);
  if (iVar5 != 0) {
    *(undefined1 *)(param_1 + 4) = 0x8a;
    do {
    } while ((uint)(*piVar3 - *piVar3) < 2000);
    iVar5 = FUN_0802aa70(uVar2,0x8a,0x94,0,0);
    if (iVar5 != 0) {
      *(undefined1 *)(param_1 + 4) = 0;
      goto LAB_0802db6e;
    }
  }
  do {
  } while ((uint)(*piVar3 - *piVar3) < 10000);
  iVar5 = FUN_0802aa70(uVar2,*(undefined1 *)(param_1 + 4),0x94,0,0);
  if (iVar5 == 0) {
    do {
    } while ((uint)(*piVar3 - *piVar3) < 10000);
    iVar5 = FUN_0802aa70(uVar2,*(undefined1 *)(param_1 + 4),0x89,0,0);
    if (iVar5 == 0) {
      do {
      } while ((uint)(*piVar3 - *piVar3) < 2000);
      iVar5 = FUN_0802ac24(uVar2,*(undefined1 *)(param_1 + 4),&local_24,6);
      *puVar1 = *puVar1 & 0xffdfffff;
      if (iVar5 == 0) {
        FUN_0802da84(param_1);
        puVar4 = DAT_0802dd4c;
        *(undefined1 *)DAT_0802dd4c = local_24;
        *(undefined1 *)puVar4 = local_23;
        if ((uint)local_22 == (*puVar4 & 0xff)) {
          puVar4[4] = 0xffffffff;
          puVar4[2] = puVar4[2] | 1;
          *(undefined1 *)puVar4 = local_21;
          *(undefined1 *)puVar4 = local_20;
          uVar6 = *puVar4;
          FUN_0802dad6(param_1);
          if ((uint)local_1f == (uVar6 & 0xff)) {
            if (*(char *)(param_1 + 5) < '\x01') {
              *(undefined1 *)(param_1 + 5) = 0;
            }
            return 0;
          }
        }
        else {
          FUN_0802dad6(param_1);
        }
      }
    }
  }
LAB_0802db6e:
  *puVar1 = *puVar1 & 0xffdfffff;
  if (*(char *)(param_1 + 5) < '\x01') {
    *(undefined1 *)(param_1 + 5) = 1;
  }
  return 1;
}



/* ===== FUN_0802dc5e @ 0802dc5e ===== */

int FUN_0802dc5e(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_1c;
  undefined4 uStack_18;
  
  local_1c = param_3;
  uStack_18 = param_4;
  FUN_08016fec();
  uVar2 = DAT_0802dd44;
  puVar1 = DAT_0802dd40;
  *DAT_0802dd40 = *DAT_0802dd40 | 0x200000;
  iVar3 = FUN_0802aa70(uVar2,*(undefined1 *)(param_1 + 4),0xfd,0,0);
  *puVar1 = *puVar1 & 0xffdfffff;
  FUN_08016fbc();
  if (iVar3 == 0) {
    do {
    } while ((uint)(*DAT_0802dd48 - *DAT_0802dd48) < 10000);
    FUN_08016fec();
    *puVar1 = *puVar1 | 0x200000;
    iVar3 = FUN_0802ac24(uVar2,*(undefined1 *)(param_1 + 4),&local_1c,3,*puVar1 & 0x200000);
    *puVar1 = *puVar1 & 0xffdfffff;
    FUN_08016fbc();
    if (iVar3 == 0) {
      FUN_0802da84(param_1);
      puVar1 = DAT_0802dd4c;
      *(undefined1 *)DAT_0802dd4c = (undefined1)local_1c;
      *(undefined1 *)puVar1 = local_1c._1_1_;
      uVar4 = *puVar1;
      FUN_0802dad6(param_1);
      if ((local_1c >> 0x10 & 0xff) == (uVar4 & 0xff)) {
        return (uint)((ulonglong)((uint)CONCAT11((undefined1)local_1c,local_1c._1_1_) * 0xaf00) *
                      (ulonglong)DAT_0802dd50 >> 0x2f) - 0x2d00;
      }
    }
  }
  if (*(char *)(param_1 + 5) < '\x01') {
    *(undefined1 *)(param_1 + 5) = 1;
  }
  return DAT_0802dd54;
}



/* ===== FUN_0802dd38 @ 0802dd38 ===== */

undefined4 FUN_0802dd38(void)

{
  return DAT_0802dd58;
}



/* ===== FUN_0802dd5c @ 0802dd5c ===== */

void FUN_0802dd5c(int param_1,undefined4 param_2,ushort *param_3,undefined4 param_4)

{
  FUN_0802ab2e(DAT_0802df04,*(undefined1 *)(param_1 + 4),param_2,param_3,2,param_4);
  *param_3 = *param_3 >> 8 | *param_3 << 8;
  return;
}



/* ===== FUN_0802dd7c @ 0802dd7c ===== */

void FUN_0802dd7c(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  ushort local_c;
  undefined2 uStack_a;
  
  _local_c = CONCAT22((short)((uint)param_4 >> 0x10),
                      (ushort)((uint)param_3 >> 8) | (ushort)(param_3 << 8));
  FUN_0802aa70(DAT_0802df04,*(undefined1 *)(param_1 + 4),param_2,&local_c,2);
  return;
}



/* ===== FUN_0802dd9a @ 0802dd9a ===== */

undefined1 FUN_0802dd9a(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint *puVar2;
  int iVar3;
  undefined1 uVar4;
  bool bVar5;
  undefined8 uVar6;
  undefined4 local_1c;
  undefined4 uStack_18;
  
  puVar2 = DAT_0802df08;
  uVar1 = DAT_0802df04;
  local_1c = param_3 & 0xffff0000;
  *(undefined1 *)(param_1 + 5) = 0xff;
  *puVar2 = *puVar2 | 0x200000;
  uStack_18 = param_4;
  iVar3 = FUN_0802ac24(uVar1,0,&local_1c,2,*puVar2 & 0x200000);
  uVar4 = 1;
  if (iVar3 == 0) {
    *(undefined1 *)(param_1 + 4) = 0x8a;
    iVar3 = FUN_0802dd5c(param_1,1,&local_1c);
    if (iVar3 != 0) {
      *(undefined1 *)(param_1 + 4) = 0x92;
      iVar3 = FUN_0802dd5c(param_1,1,&local_1c);
      if (iVar3 != 0) {
        *(undefined1 *)(param_1 + 4) = 0;
        goto LAB_0802de2c;
      }
    }
    local_1c = CONCAT22(0x6040,(undefined2)local_1c);
    iVar3 = FUN_0802aa70(uVar1,*(undefined1 *)(param_1 + 4),1,(int)&local_1c + 2,2);
    if (iVar3 == 0) {
      uVar6 = FUN_0802dd5c(param_1,1,&local_1c);
      bVar5 = (int)uVar6 == 0;
      if (bVar5) {
        uVar6 = CONCAT44(0x4060,local_1c & 0xffff);
      }
      if (bVar5 && (int)uVar6 == (int)((ulonglong)uVar6 >> 0x20)) {
        uVar4 = 0;
      }
    }
  }
LAB_0802de2c:
  *puVar2 = *puVar2 & 0xffdfffff;
  if (*(char *)(param_1 + 5) < '\x01') {
    *(undefined1 *)(param_1 + 5) = uVar4;
  }
  return uVar4;
}



/* ===== FUN_0802de44 @ 0802de44 ===== */

undefined8 FUN_0802de44(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  byte bVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint local_18;
  uint local_14;
  
  local_18 = param_3;
  local_14 = param_4;
  FUN_08016fec();
  puVar2 = DAT_0802df08;
  *DAT_0802df08 = *DAT_0802df08 | 0x200000;
  local_14 = *puVar2 & 0x200000;
  iVar3 = FUN_0802dd5c(param_1,1,&local_18);
  iVar5 = 0;
  if (iVar3 != 0) {
    uVar4 = local_18 & 0xffff | 0x100;
    local_18 = CONCAT22(local_18._2_2_,(short)uVar4);
    iVar5 = FUN_0802dd7c(param_1,1,uVar4);
  }
  *DAT_0802df04 = *DAT_0802df04 & 0xfffffffe;
  *puVar2 = *puVar2 & 0xffdfffff;
  FUN_08016fbc();
  bVar1 = (byte)~(byte)(-(uint)(iVar5 == 0) >> 0x18) >> 7;
  if (*(char *)(param_1 + 5) < '\x01') {
    *(byte *)(param_1 + 5) = bVar1;
  }
  return CONCAT44(local_18,(int)(char)bVar1);
}



/* ===== FUN_0802deb2 @ 0802deb2 ===== */

undefined8 FUN_0802deb2(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  undefined4 local_18;
  uint local_14;
  
  local_18 = param_3;
  local_14 = param_4;
  FUN_08016fec();
  puVar1 = DAT_0802df08;
  *DAT_0802df08 = *DAT_0802df08 | 0x200000;
  local_14 = *puVar1 & 0x200000;
  iVar2 = FUN_0802dd5c(param_1,0,&local_18);
  *puVar1 = *puVar1 & 0xffdfffff;
  FUN_08016fbc();
  if (iVar2 == 0) {
    return CONCAT44(local_18,(int)(short)local_18 << 1);
  }
  if (*(char *)(param_1 + 5) < '\x01') {
    *(undefined1 *)(param_1 + 5) = 1;
  }
  return CONCAT44(local_18,DAT_0802df0c);
}



/* ===== FUN_0802df00 @ 0802df00 ===== */

undefined4 FUN_0802df00(void)

{
  return DAT_0802df10;
}



/* ===== FUN_0802df14 @ 0802df14 ===== */

void FUN_0802df14(void)

{
  FUN_0802f2cc(1);
  return;
}



/* ===== FUN_0802df1c @ 0802df1c ===== */

int * FUN_0802df1c(void)

{
  int *piVar1;
  
  if (*DAT_0802df3c == 0) {
    piVar1 = (int *)(DAT_0802df40 & 0xfffffff8);
    *DAT_0802df3c = (uint)piVar1;
    *piVar1 = (DAT_0802df44 & 0xfffffff8) - (int)piVar1;
    return piVar1;
  }
  return (int *)0x0;
}



/* ===== FUN_0802df48 @ 0802df48 ===== */

undefined1 FUN_0802df48(undefined4 param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)(param_2 + 8);
  if (10 < uVar2) {
    return 0;
  }
  if (uVar2 != 7) {
    return *(undefined1 *)(DAT_0802df88 + uVar2 * 2 + 1);
  }
  cVar1 = *(char *)(param_2 + 0xb);
  if (cVar1 == '\x03' || cVar1 == '\f') {
    return 10;
  }
  if (cVar1 == '0') {
    return 0xc;
  }
  if (cVar1 == '@') {
    return 6;
  }
  *(undefined1 *)(param_2 + 0xb) = 0;
  return 4;
}



/* ===== FUN_0802e17c @ 0802e17c ===== */

uint FUN_0802e17c(undefined4 param_1,undefined2 *param_2)

{
  uint *puVar1;
  int iVar2;
  undefined2 *puVar3;
  
  puVar1 = DAT_0802e1dc;
  DAT_0802e1dc[2] = DAT_0802e1dc[2] & 0xffffff9f;
  puVar1[2] = puVar1[2] & 0xffffff7f;
  puVar1[2] = puVar1[2] & 0xffffffe7 | 8;
  puVar1[5] = 0x8005;
  puVar1[4] = 0xffffffff;
  puVar1[2] = puVar1[2] | 1;
  *(undefined2 *)puVar1 = *param_2;
  iVar2 = 3;
  do {
    *(undefined2 *)puVar1 = param_2[1];
    iVar2 = iVar2 + -1;
    puVar3 = param_2 + 3;
    *(undefined2 *)puVar1 = param_2[2];
    param_2 = param_2 + 4;
    *(undefined2 *)puVar1 = *puVar3;
    *(undefined2 *)puVar1 = *param_2;
  } while (iVar2 != 0);
  return *puVar1 & 0xffff;
}



/* ===== FUN_0802e1e0 @ 0802e1e0 ===== */

uint FUN_0802e1e0(int param_1,undefined1 param_2,undefined1 *param_3,int param_4)

{
  uint uVar1;
  
  do {
  } while (*(int *)(param_1 + 8) << 0x1f < 0);
  do {
  } while (-1 < *(int *)(param_1 + 8) << 0x1e);
  *(undefined1 *)(param_1 + 0xc) = param_2;
  do {
  } while (-1 < *(int *)(param_1 + 8) << 0x1f);
  uVar1 = *(uint *)(param_1 + 0xc);
  for (; param_4 != 0; param_4 = param_4 + -1) {
    do {
    } while (-1 < *(int *)(param_1 + 8) << 0x1e);
    *(undefined1 *)(param_1 + 0xc) = 0;
    do {
    } while (-1 < *(int *)(param_1 + 8) << 0x1f);
    *param_3 = (char)*(undefined4 *)(param_1 + 0xc);
    param_3 = param_3 + 1;
  }
  return uVar1 & 0xff;
}



/* ===== FUN_0802e21a @ 0802e21a ===== */

uint FUN_0802e21a(int param_1,undefined1 param_2,undefined1 *param_3,int param_4)

{
  uint uVar1;
  
  do {
  } while (*(int *)(param_1 + 8) << 0x1f < 0);
  do {
  } while (-1 < *(int *)(param_1 + 8) << 0x1e);
  *(undefined1 *)(param_1 + 0xc) = param_2;
  do {
  } while (-1 < *(int *)(param_1 + 8) << 0x1f);
  uVar1 = *(uint *)(param_1 + 0xc);
  for (; param_4 != 0; param_4 = param_4 + -1) {
    do {
    } while (-1 < *(int *)(param_1 + 8) << 0x1e);
    *(undefined1 *)(param_1 + 0xc) = *param_3;
    do {
    } while (-1 < *(int *)(param_1 + 8) << 0x1f);
    param_3 = param_3 + 1;
  }
  return uVar1 & 0xff;
}



/* ===== FUN_0802e258 @ 0802e258 ===== */

uint * FUN_0802e258(int param_1,uint param_2,uint param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = (param_3 & 0xff) << 8;
  uVar4 = param_3 & 0xff | uVar5;
  uVar5 = uVar4 | (param_3 & 0xffff00ff | uVar5) << 0x10;
  puVar3 = (uint *)(param_1 + param_2);
  uVar6 = (uint)puVar3 & 3;
  uVar1 = (undefined1)param_3;
  uVar2 = (undefined2)uVar4;
  if (uVar6 != 0) {
    uVar4 = param_2 - uVar6;
    if (param_2 < uVar6) {
      if (uVar4 + uVar6 != 0) {
        puVar3 = (uint *)((int)puVar3 + -1);
        *(undefined1 *)puVar3 = uVar1;
      }
      if (((uVar4 + uVar6) * 0x40000000 & 0x80000000) != 0) {
        puVar3 = (uint *)((int)puVar3 + -1);
        *(undefined1 *)puVar3 = uVar1;
      }
      return puVar3;
    }
    uVar6 = (uint)puVar3 & 2;
    if ((int)puVar3 * -0x80000000 < 0) {
      puVar3 = (uint *)((int)puVar3 + -1);
      *(undefined1 *)puVar3 = uVar1;
    }
    param_2 = uVar4;
    if (uVar6 != 0) {
      puVar3 = (uint *)((int)puVar3 + -2);
      *(undefined2 *)puVar3 = uVar2;
    }
  }
  do {
    uVar4 = param_2;
    if (0xf < uVar4) {
      puVar3[-1] = uVar5;
      puVar3[-2] = uVar5;
      puVar3[-3] = uVar5;
      puVar3[-4] = uVar5;
      puVar3 = puVar3 + -4;
    }
    param_2 = uVar4 - 0x10;
  } while (0xf < uVar4 && uVar4 - 0x10 != 0);
  if ((uVar4 & 8) != 0) {
    puVar3[-1] = uVar5;
    puVar3[-2] = uVar5;
    puVar3 = puVar3 + -2;
  }
  if ((int)(uVar4 << 0x1d) < 0) {
    puVar3 = puVar3 + -1;
    *puVar3 = uVar5;
  }
  if ((uVar4 & 2) != 0) {
    puVar3 = (uint *)((int)puVar3 + -2);
    *(undefined2 *)puVar3 = uVar2;
  }
  if ((int)(uVar4 << 0x1f) < 0) {
    puVar3 = (uint *)((int)puVar3 + -1);
    *(undefined1 *)puVar3 = uVar1;
  }
  return puVar3;
}



/* ===== FUN_0802e2c0 @ 0802e2c0 ===== */

void FUN_0802e2c0(void)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_0802e2f0;
  *DAT_0802e2f0 = *DAT_0802e2f0 | 1;
  *puVar1 = *puVar1 & 0xffffff9f;
  uVar2 = DAT_0802e2f4;
  *puVar1 = *puVar1 & 0xffffff7f;
  puVar1[3] = uVar2;
  *puVar1 = *puVar1 & 0xffffffe7;
  puVar1[2] = 0xffffffff;
  return;
}



/* ===== FUN_0802e2f8 @ 0802e2f8 ===== */

void FUN_0802e2f8(int param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else if (param_2 < 0x100) {
    uVar1 = 1;
  }
  else {
    uVar1 = 4;
  }
  iVar2 = *(int *)(param_1 + 0x1c);
  iVar4 = param_2 - iVar2;
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  if (iVar4 < 0x80) {
    uVar3 = 0x100;
  }
  else if (iVar4 < 0x8000) {
    uVar3 = 0x200;
  }
  else if (iVar4 < 0x800000) {
    uVar3 = 0x300;
  }
  else {
    uVar3 = 0x400;
  }
  *(uint *)(param_1 + 0x1c) = param_2;
  uVar5 = *(undefined4 *)(param_1 + 0x18);
  *(int *)(param_1 + 0x18) = iVar2;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x14) = uVar5;
  *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(param_1 + 0xe);
  *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(param_1 + 0x10);
  *(ushort *)(param_1 + 0x10) = uVar1 | uVar3;
  return;
}



/* ===== FUN_0802e354 @ 0802e354 ===== */

void FUN_0802e354(uint param_1,uint param_2,uint param_3,uint param_4,int param_5,undefined2 param_6
                 )

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  byte bVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  byte *pbVar16;
  byte bVar17;
  undefined1 *puVar18;
  byte *pbVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint local_58;
  uint local_54;
  
  *DAT_0802e670 = 0;
  pbVar19 = DAT_0802e678;
  pbVar16 = DAT_0802e674;
  bVar1 = (byte)param_1;
  if ((uint)*DAT_0802e674 < (uint)*DAT_0802e678) {
    *DAT_0802e678 = bVar1;
LAB_0802e37e:
    *pbVar16 = bVar1;
  }
  else if ((int)param_1 < (int)(uint)*DAT_0802e678) {
    *DAT_0802e678 = bVar1;
  }
  else if ((int)(uint)*DAT_0802e674 < (int)param_1) goto LAB_0802e37e;
  pbVar4 = DAT_0802e680;
  pbVar3 = DAT_0802e67c;
  bVar1 = (byte)param_2;
  if ((uint)*DAT_0802e680 < (uint)*DAT_0802e67c) {
    *DAT_0802e67c = bVar1;
LAB_0802e3a4:
    *pbVar4 = bVar1;
  }
  else if ((int)param_2 < (int)(uint)*DAT_0802e67c) {
    *DAT_0802e67c = bVar1;
  }
  else if ((int)(uint)*DAT_0802e680 < (int)param_2) goto LAB_0802e3a4;
  bVar1 = (byte)param_3;
  if ((uint)*pbVar16 < (uint)*pbVar19) {
    *pbVar19 = bVar1;
LAB_0802e3c6:
    *pbVar16 = bVar1;
  }
  else if ((int)param_3 < (int)(uint)*pbVar19) {
    *pbVar19 = bVar1;
  }
  else if ((int)(uint)*pbVar16 < (int)param_3) goto LAB_0802e3c6;
  bVar1 = (byte)param_4;
  if ((uint)*pbVar4 < (uint)*pbVar3) {
    *pbVar3 = bVar1;
  }
  else {
    if ((int)param_4 < (int)(uint)*pbVar3) {
      *pbVar3 = bVar1;
      goto LAB_0802e3e6;
    }
    if ((int)param_4 <= (int)(uint)*pbVar4) goto LAB_0802e3e6;
  }
  *pbVar4 = bVar1;
LAB_0802e3e6:
  iVar5 = DAT_0802e68c;
  if ((int)(param_4 - param_2) < param_5) {
    FUN_08026a64(param_1,param_2,param_3,param_4,param_6);
  }
  else {
    bVar17 = *(byte *)(DAT_0802e684 + (param_2 & 7));
    bVar2 = *(byte *)(DAT_0802e688 + (param_4 & 7));
    bVar1 = *(byte *)(DAT_0802e688 + (param_4 - param_5 & 7));
    uVar7 = (param_5 + param_2 & 7) - (param_2 & 7);
    uVar13 = param_4 >> 3;
    uVar9 = (param_4 - param_5 & 0xff) >> 3;
    uVar8 = (param_2 + param_5 + ((uint)((int)(param_2 + param_5) >> 2) >> 0x1d) & 0x7ff) >> 3;
    param_2 = param_2 >> 3;
    uVar15 = param_2;
    uVar20 = param_3;
    for (; param_2 <= uVar13; param_2 = param_2 + 1 & 0xff) {
      if (param_2 == uVar13) {
        bVar17 = bVar2 & bVar17;
      }
      uVar10 = param_1;
      local_58 = uVar13;
      local_54 = uVar15;
      do {
        uVar21 = (uVar20 & 0xff) - uVar10;
        if (7 < (uVar21 & 0xff)) {
          uVar21 = 7;
        }
        uVar22 = 0;
        uVar14 = uVar21;
        puVar18 = (undefined1 *)(DAT_0802e690 + uVar8 * 0x80 + (uVar10 & 0xffff));
        while( true ) {
          *(undefined1 *)(iVar5 + uVar22) = *puVar18;
          iVar6 = DAT_0802e694;
          if ((uVar14 & 0xff) == 0) break;
          uVar22 = uVar22 + 1 & 0xff;
          uVar14 = uVar14 - 1;
          puVar18 = puVar18 + 1;
        }
        if ((int)uVar7 < 1) {
          if (((int)uVar7 < 0) && (uVar8 != local_54)) {
            uVar14 = uVar8 - 1;
            goto LAB_0802e536;
          }
        }
        else if (uVar8 != local_58) {
          uVar14 = uVar8 + 1;
LAB_0802e536:
          uVar22 = 0;
          puVar18 = (undefined1 *)(DAT_0802e690 + uVar10 + (uVar14 & 0x1f) * 0x80);
          uVar14 = uVar21;
          while( true ) {
            *(undefined1 *)(iVar6 + uVar22) = *puVar18;
            uVar22 = uVar22 + 1 & 0xff;
            if ((uVar14 & 0xff) == 0) break;
            uVar14 = uVar14 - 1;
            puVar18 = puVar18 + 1;
          }
        }
        iVar6 = DAT_0802e694;
        local_58 = uVar13 & 0xff;
        local_54 = uVar15 & 0xff;
        uVar22 = 0;
        uVar14 = uVar21;
        while( true ) {
          if (uVar9 < param_2) {
            *(byte *)(iVar5 + uVar22) = (byte)param_6;
          }
          else {
            if (uVar7 == 0) {
              bVar11 = *(byte *)(iVar5 + uVar22);
            }
            else if ((int)uVar7 < 1) {
              if (param_2 == local_54) {
                uVar12 = 0;
              }
              else {
                uVar12 = (uint)*(byte *)(iVar6 + uVar22);
              }
              bVar11 = (byte)(((uVar12 | (uint)*(byte *)(iVar5 + uVar22) << 8) << -(char)uVar7) >> 8
                             );
            }
            else {
              uVar12 = (uint)*(byte *)(iVar5 + uVar22);
              if (uVar8 != local_58) {
                uVar12 = (uint)CONCAT11(*(undefined1 *)(iVar6 + uVar22),*(byte *)(iVar5 + uVar22));
              }
              bVar11 = (byte)(uVar12 >> (uVar7 & 0xff));
            }
            if (param_2 == uVar9) {
              bVar11 = (byte)param_6 & ~bVar1 | bVar1 & bVar11;
            }
            *(byte *)(iVar5 + uVar22) = bVar11;
          }
          if ((uVar14 & 0xff) == 0) break;
          uVar14 = uVar14 - 1;
          uVar22 = uVar22 + 1 & 0xff;
        }
        pbVar16 = (byte *)(DAT_0802e690 + (uVar10 & 0xffff) + param_2 * 0x80);
        if (bVar17 != 0xff) {
          uVar22 = 0;
          pbVar19 = pbVar16;
          uVar14 = uVar21;
          while( true ) {
            *(byte *)(iVar5 + uVar22) = bVar17 & *(byte *)(iVar5 + uVar22) | ~bVar17 & *pbVar19;
            if ((uVar14 & 0xff) == 0) break;
            uVar14 = uVar14 - 1;
            uVar22 = uVar22 + 1 & 0xff;
            pbVar19 = pbVar19 + 1;
          }
        }
        uVar22 = 0;
        uVar14 = uVar21;
        while( true ) {
          *pbVar16 = *(byte *)(iVar5 + uVar22);
          if ((uVar14 & 0xff) == 0) break;
          uVar14 = uVar14 - 1;
          uVar22 = uVar22 + 1 & 0xff;
          pbVar16 = pbVar16 + 1;
        }
        uVar10 = uVar10 + uVar21 + 1 & 0xff;
      } while ((int)uVar10 <= (int)param_3);
      uVar20 = uVar20 & 0xff;
      uVar15 = uVar15 & 0xff;
      uVar13 = uVar13 & 0xff;
      bVar17 = 0xff;
      uVar8 = uVar8 + 1 & 0xff;
    }
  }
  return;
}



/* ===== FUN_0802e698 @ 0802e698 ===== */

void FUN_0802e698(int param_1,uint param_2,uint param_3,uint param_4,byte *param_5,int param_6,
                 int param_7)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  
  uVar2 = (uint)param_5[1];
  uVar1 = (uint)*param_5;
  if (uVar2 != 0 && uVar1 != 0) {
    param_5 = param_5 + 2;
    if ((int)((uint)*(ushort *)(*DAT_0802e72c + 0x10) << 0x1f) < 0) {
      uVar3 = 0x80;
    }
    else {
      uVar3 = 0;
    }
    if (param_7 == 0) {
      uVar4 = (ushort)(uVar1 + 7 >> 3);
    }
    else {
      uVar4 = (ushort)(param_7 / (int)uVar2);
    }
    if ((int)((uint)*(ushort *)(*DAT_0802e72c + 0x10) << 0x10) < 0) {
      uVar3 = uVar3 | 0x40;
    }
    if (param_6 != 0) {
      param_2 = param_6 + param_2;
      uVar2 = uVar2 - param_6;
      param_5 = param_5 + (int)(short)param_6 * (int)(short)(uVar4 & 0xff);
    }
    uVar1 = param_1 + -1 + uVar1;
    uVar2 = ((uVar2 & 0xffff) + (param_2 & 0xff)) - 1;
    if (param_3 < (uVar1 & 0xffff)) {
      uVar1 = param_3;
    }
    if (param_4 < (uVar2 & 0xffff)) {
      uVar2 = param_4;
    }
    *DAT_0802e730 = 0;
    FUN_0802f334(param_1,param_2 & 0xff,uVar1 & 0xff,uVar2 & 0xff,param_5,(char)uVar4,uVar3,param_4)
    ;
  }
  return;
}



/* ===== FUN_0802e734 @ 0802e734 ===== */

undefined4 FUN_0802e734(undefined4 param_1)

{
  FUN_0802498c();
  return param_1;
}



/* ===== FUN_0802e740 @ 0802e740 ===== */

undefined4 FUN_0802e740(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0802e258(param_1,param_3,param_2);
  return param_1;
}



/* ===== FUN_0802e754 @ 0802e754 ===== */

void FUN_0802e754(uint *param_1)

{
  uint *puVar1;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  *param_1 = 6;
  puVar3 = DAT_0802e880;
  uVar5 = param_1[1];
  if ((uVar5 < 2) || (uVar5 == 2 || uVar5 == 4)) {
    *param_1 = 7;
    if (uVar5 == 0) {
      param_1[2] = puVar3[3] & 0xff;
      uVar5 = puVar3[3];
    }
    else if (uVar5 == 1) {
      param_1[2] = puVar3[4] & 0xff;
      uVar5 = puVar3[4];
    }
    else if (uVar5 == 2) {
      param_1[2] = puVar3[0xb] & 0xff;
      uVar5 = puVar3[0xb];
    }
    else {
      if (uVar5 != 4) goto LAB_0802e7b6;
      param_1[2] = puVar3[0xc] & 0xff;
      uVar5 = puVar3[0xc];
    }
    param_1[3] = (uVar5 & 0xffffff) >> 0x10;
  }
LAB_0802e7b6:
  if ((*puVar3 & 0xff) == 0xaa || (*puVar3 & 0xff) == 0xcc) {
    uVar5 = *puVar3 & 0xff;
  }
  else {
    uVar5 = 0xbb;
  }
  param_1[4] = uVar5;
  param_1[6] = *puVar3 & 0xffffff00;
  piVar2 = DAT_0802e874;
  puVar1 = DAT_0802e870;
  uVar5 = param_1[7];
  if (uVar5 == 1 || uVar5 == 2) {
    *param_1 = *param_1 | 8;
    uVar4 = DAT_0802e884;
    uVar6 = *puVar1;
    if (*piVar2 << 0x17 < 0) {
      if ((uVar6 & 0xffff) == 0xffff) {
        iVar8 = DAT_0802e87c;
      }
      else {
        iVar8 = (DAT_0802e878 & uVar6 << 9) + 0x8000000;
      }
      iVar7 = 0x8000000;
    }
    else {
      iVar8 = 0x8000000;
      iVar7 = DAT_0802e87c;
      if ((uVar6 & 0xffff) != 0xffff) {
        iVar7 = (DAT_0802e878 & uVar6 << 9) + 0x8000000;
      }
    }
    if ((uVar5 & 3) == 1) {
      param_1[8] = iVar8 + (DAT_0802e884 & puVar3[1] << 3);
      param_1[9] = iVar8 + (uVar4 & puVar3[2] << 3) + 7;
    }
    else if ((uVar5 & 3) == 2) {
      param_1[8] = iVar7 + (DAT_0802e884 & puVar3[9] << 3);
      param_1[9] = iVar7 + (uVar4 & puVar3[10] << 3) + 7;
    }
    param_1[7] = uVar5 | puVar3[2] & 0x80000000;
  }
  return;
}



/* ===== FUN_0802e888 @ 0802e888 ===== */

uint FUN_0802e888(uint *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint in_r12;
  uint uVar3;
  bool bVar4;
  
  uVar1 = 0;
  while (((uint)param_1 & 3) != 0) {
    bVar4 = param_3 != 0;
    param_3 = param_3 - 1;
    uVar2 = param_3;
    if (bVar4) {
      in_r12 = (uint)(byte)*param_2;
      uVar1 = (byte)*param_1 - in_r12;
      uVar2 = uVar1;
      param_2 = (uint *)((int)param_2 + 1);
      param_1 = (uint *)((int)param_1 + 1);
    }
    if (uVar2 != 0) {
      return uVar1;
    }
  }
  if (((uint)param_2 & 3) == 0) {
    do {
      uVar3 = param_3;
      uVar2 = uVar3 - 4;
      bVar4 = uVar2 == 0;
      if (3 < uVar3) {
        uVar1 = *param_1;
        in_r12 = *param_2;
        bVar4 = uVar1 == in_r12;
        param_2 = param_2 + 1;
        param_1 = param_1 + 1;
      }
      param_3 = uVar2;
    } while (bVar4);
    param_3 = uVar3;
    if (uVar2 < 0xfffffffc) {
      uVar1 = uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 |
              uVar1 >> 0x18;
      uVar3 = in_r12 << 0x18 | (in_r12 >> 8 & 0xff) << 0x10 | (in_r12 >> 0x10 & 0xff) << 8 |
              in_r12 >> 0x18;
      uVar2 = uVar1 - uVar3;
      bVar4 = uVar2 != 0;
      if (uVar1 < uVar3) {
        uVar2 = 0xffffffff;
      }
      if (uVar1 >= uVar3 && bVar4) {
        uVar2 = 1;
      }
      return uVar2;
    }
  }
  do {
    uVar3 = param_3;
    uVar2 = uVar3 - 1;
    if (uVar3 != 0) {
      uVar1 = (uint)(byte)*param_1 - (uint)(byte)*param_2;
      uVar2 = uVar1;
      param_2 = (uint *)((int)param_2 + 1);
      param_1 = (uint *)((int)param_1 + 1);
    }
    param_3 = uVar3 - 1;
  } while (uVar2 == 0);
  if (uVar3 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}



/* ===== FUN_0802e8f0 @ 0802e8f0 ===== */

int FUN_0802e8f0(int param_1)

{
  FUN_0802f5cc(param_1 + 8);
  FUN_0802f604(param_1 + 0x50);
  *(undefined1 *)(param_1 + 0x80) = 0;
  FUN_0802f604(param_1 + 0x88);
  *(undefined1 *)(param_1 + 0xb8) = 0;
  FUN_0802f604(param_1 + 0xc0);
  *(undefined1 *)(param_1 + 0xf0) = 0;
  FUN_0802a3ec(param_1);
  return param_1;
}



/* ===== FUN_0802e930 @ 0802e930 ===== */

int FUN_0802e930(int param_1,code *param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = param_1;
  if (param_2 != (code *)0x0 && param_1 != 0) {
    for (; param_4 != 0; param_4 = param_4 + -1) {
      (*param_2)(iVar1);
      iVar1 = iVar1 + param_3;
    }
  }
  return param_1;
}



/* ===== FUN_0802e958 @ 0802e958 ===== */

undefined4 FUN_0802e958(int *param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  longlong lVar1;
  longlong lVar2;
  
  param_1[6] = param_1[6] + 1;
  *param_1 = (*param_2 & 0xffffff) + *param_1;
  lVar1 = *(longlong *)(param_1 + 2);
  lVar2 = FUN_08029e90(param_2[1]);
  *(longlong *)(param_1 + 2) = lVar2 + lVar1;
  lVar1 = *(longlong *)(param_1 + 4);
  lVar2 = FUN_08029e90(param_2[2]);
  *(longlong *)(param_1 + 4) = lVar2 + lVar1;
  return param_4;
}



/* ===== FUN_0802ea58 @ 0802ea58 ===== */

undefined8 FUN_0802ea58(uint param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  uVar8 = param_2 >> 0x1f;
  uVar2 = param_1 + uVar8 ^ uVar8;
  uVar5 = param_2 + uVar8 + (uint)CARRY4(param_1,uVar8) ^ uVar8;
  if (uVar5 == 0) {
    iVar7 = 0;
    iVar4 = 0;
    if (uVar2 != 0) {
      uVar5 = uVar2 << LZCOUNT(uVar2);
      bVar1 = (uVar5 & 0x100) != 0;
      uVar6 = uVar5 * 0x1000000;
      iVar7 = (uVar6 + 0x80000000) - (uint)!bVar1;
      iVar4 = (uVar8 << 0x1f | (0x9d - LZCOUNT(uVar2)) * 0x800000) +
              (uVar5 >> 8) + (uint)(0x80000000 < uVar6 || uVar6 + 0x80000000 < (uint)bVar1);
    }
    return CONCAT44(iVar7,iVar4);
  }
  uVar3 = uVar2 << LZCOUNT(uVar5);
  iVar7 = -LZCOUNT(uVar5);
  uVar6 = iVar7 + 0x20U & 0x1f;
  uVar2 = ((uVar5 ^ uVar2) >> uVar6 | (uVar5 ^ uVar2) << 0x20 - uVar6) ^ uVar3;
  if (uVar3 != 0) {
    uVar2 = uVar2 | 1;
  }
  uVar5 = uVar8 << 0x1f | (iVar7 + 0xbd) * 0x800000;
  return CONCAT44(uVar5,uVar5 + (uVar2 >> 8) +
                                (uint)(0x80000000 < uVar2 * 0x1000000 ||
                                      uVar2 * 0x1000000 + 0x80000000 < (uint)((uVar2 & 0x100) != 0))
                 );
}



/* ===== FUN_0802eab0 @ 0802eab0 ===== */

undefined4 FUN_0802eab0(undefined4 param_1,uint *param_2,undefined4 *param_3,undefined4 param_4)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  float *pfVar7;
  uint uVar8;
  int *piVar9;
  float *pfVar10;
  uint in_fpscr;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  longlong lVar15;
  
  uVar5 = param_3[1];
  uVar8 = *param_2 & 0xff000000 | uVar5 & 0xffffff;
  *param_2 = uVar8;
  *param_2 = uVar8 | 0xff000000;
  iVar3 = DAT_0802ebfc;
  fVar11 = (float)VectorUnsignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
  fVar13 = (float)VectorSignedToFloat(*param_3,(byte)(in_fpscr >> 0x16) & 3);
  fVar11 = 1.0 - (fVar11 * DAT_0802ebf4) / fVar13;
  uVar5 = in_fpscr & 0xfffffff;
  if (fVar11 < DAT_0802ebf8) {
    fVar11 = DAT_0802ebf8;
  }
  piVar9 = param_3 + 2;
  lVar2 = 0;
  lVar1 = 0;
  pfVar10 = (float *)(DAT_0802ebfc + 0x14);
  if (DAT_0802ebfc + 0x14U < DAT_0802ebfc + 0x414U) {
    fVar13 = *(float *)(DAT_0802ebfc + 4);
    pfVar7 = (float *)(DAT_0802ebfc + 0x414);
    lVar1 = 0;
    for (; pfVar10 < pfVar7; pfVar10 = pfVar10 + 1) {
      iVar4 = 0;
      piVar6 = piVar9 + 4;
      if (piVar9 < piVar6) {
        for (; piVar9 < piVar6; piVar9 = piVar9 + 1) {
          iVar4 = *piVar9 + iVar4;
        }
        if (iVar4 != 0) {
          fVar14 = *pfVar10;
          fVar12 = (float)VectorUnsignedToFloat(iVar4,(byte)(uVar5 >> 0x16) & 3);
          fVar12 = fVar12 * fVar14;
          lVar15 = FUN_08029e90(fVar12);
          lVar1 = lVar15 + lVar1;
          lVar15 = FUN_08029e90(fVar14 * fVar12 * (1.0 / fVar13));
          lVar2 = lVar15 + lVar2;
        }
      }
    }
  }
  fVar11 = *(float *)(iVar3 + 8) / fVar11;
  fVar13 = (float)FUN_0802a3a4((int)lVar1,(int)((ulonglong)lVar1 >> 0x20));
  *(float *)(iVar3 + 0xc) = fVar13 * fVar11;
  fVar12 = (float)FUN_0802a3a4((int)lVar2,(int)((ulonglong)lVar2 >> 0x20));
  *(float *)(iVar3 + 0x10) = fVar12 * fVar11 * fVar11;
  param_2[1] = (uint)(fVar13 * fVar11 + 0.5);
  param_2[2] = (uint)(*(float *)(iVar3 + 0x10) + 0.5);
  return param_4;
}



/* ===== FUN_0802ec00 @ 0802ec00 ===== */

undefined4 FUN_0802ec00(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x18);
  if (iVar2 < 1) {
    return 0;
  }
  uVar1 = FUN_08025a30(iVar2 * 0x1f4000 + 0x7d,
                       ((iVar2 * 0xfa >> 0x1f) << 0xd | (uint)(iVar2 * 0xfa) >> 0x13) +
                       (uint)(0xffffff82 < (uint)(iVar2 * 0x1f4000)),0xfa,0);
  return uVar1;
}



/* ===== FUN_0802ec28 @ 0802ec28 ===== */

void FUN_0802ec28(float *param_1,int param_2,float *param_3)

{
  uint uVar1;
  byte bVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  uint in_fpscr;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  
  pfVar5 = DAT_0802ed50;
  pfVar3 = (float *)0x0;
  *param_1 = 0.0;
  fVar9 = DAT_0802ed4c;
  pfVar6 = pfVar5 + 2;
  iVar7 = 1;
  while( true ) {
    if (param_2 < iVar7) {
      return;
    }
    fVar11 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
    fVar11 = *param_3 + fVar11 * (param_3[1] + fVar11 * param_3[2]);
    uVar1 = in_fpscr & 0xfffffff | (uint)(fVar11 < 0.0) << 0x1f | (uint)(fVar11 == 0.0) << 0x1e;
    in_fpscr = uVar1 | (uint)NAN(fVar11) << 0x1c;
    bVar2 = (byte)(uVar1 >> 0x18);
    if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) break;
    param_1[1] = 0.0;
    iVar7 = iVar7 + 1;
    param_1 = param_1 + 1;
  }
  iVar8 = iVar7 * 2 + -1;
  pfVar4 = pfVar5 + 0x4a;
  fVar11 = fVar9;
  fVar10 = fVar9;
  do {
    fVar13 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
    fVar12 = *param_3 + fVar13 * (param_3[1] + fVar13 * param_3[2]);
    fVar13 = DAT_0802ed4c;
    while( true ) {
      fVar14 = *pfVar6;
      fVar15 = pfVar6[1];
      if (pfVar3 != pfVar5) {
        fVar11 = (fVar15 - pfVar5[1]) / (fVar14 - *pfVar5);
        fVar9 = pfVar5[1] - fVar11 * *pfVar5;
        pfVar3 = pfVar5;
      }
      if (fVar14 < fVar10 || (fVar14 < fVar10 || fVar12 < fVar14)) {
        fVar15 = fVar9 + fVar11 * fVar12;
        fVar14 = fVar12;
      }
      uVar1 = in_fpscr & 0xfffffff | (uint)(fVar14 < fVar12) << 0x1f;
      in_fpscr = uVar1 | (uint)(NAN(fVar14) || NAN(fVar12)) << 0x1c;
      fVar13 = fVar13 + (fVar15 + fVar9 + fVar11 * fVar10) * (fVar14 - fVar10);
      if ((byte)(uVar1 >> 0x1f) == ((byte)(in_fpscr >> 0x1c) & 1)) break;
      fVar10 = fVar14;
      if (pfVar6 < pfVar4) {
        pfVar5 = pfVar6;
        pfVar6 = pfVar6 + 2;
      }
    }
    fVar10 = (float)VectorSignedToFloat(iVar8,(byte)(in_fpscr >> 0x16) & 3);
    *param_1 = fVar13 / ((param_3[1] + fVar10 * param_3[2]) * 2.0);
    param_1 = param_1 + 1;
    iVar7 = iVar7 + 1;
    iVar8 = iVar8 + 2;
    fVar10 = fVar12;
  } while (iVar7 <= param_2);
  return;
}



/* ===== FUN_0802ed54 @ 0802ed54 ===== */

int FUN_0802ed54(uint param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  
  if ((int)param_1 < 1) {
    if (-4 < (int)param_1) {
      iVar1 = 0;
      goto LAB_0802ed76;
    }
    iVar1 = param_1 + ((uint)((int)param_1 >> 1) >> 0x1e);
  }
  else {
    iVar1 = (param_1 - 1) + ((uint)((int)(param_1 - 1) >> 1) >> 0x1e);
  }
  iVar1 = iVar1 >> 2;
LAB_0802ed76:
  if (((param_1 & 3) == 0) && (param_1 != 0)) {
    puVar2 = &DAT_0802ed90;
  }
  else {
    puVar2 = &DAT_0802eda8;
  }
  return *(short *)(puVar2 + param_2 * 2) + iVar1;
}



/* ===== FUN_0802edc0 @ 0802edc0 ===== */

/* WARNING: Removing unreachable block (ram,0x0802ede4) */

undefined8 FUN_0802edc0(uint *param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined *puVar2;
  short *psVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar6 = DAT_0802ee94;
  if (param_1 == (uint *)0x0) {
    param_1 = DAT_0802ee98;
  }
  uVar5 = DAT_0802ee90 + param_2;
  param_1[8] = param_3;
  uVar7 = uVar5 / uVar6;
  param_1[6] = (int)(uVar7 + 1) % 7;
  uVar4 = (int)uVar7 / 0x16d;
  while( true ) {
    iVar1 = FUN_0802ed54(uVar4,0);
    iVar1 = uVar4 * 0x16d + iVar1;
    if (iVar1 <= (int)uVar7) break;
    uVar4 = uVar4 - 1;
  }
  uVar8 = uVar7 - iVar1;
  param_1[5] = uVar4;
  param_1[7] = uVar8;
  if (((uVar4 & 3) == 0) && (uVar4 != 0)) {
    puVar2 = &UNK_0802ee9c;
  }
  else {
    puVar2 = &UNK_0802eeb4;
  }
  uVar4 = 0xc;
  psVar3 = (short *)(puVar2 + 0x18);
  do {
    psVar3 = psVar3 + -1;
    uVar4 = uVar4 - 1;
  } while ((int)uVar8 < (int)*psVar3);
  param_1[4] = uVar4;
  uVar6 = uVar5 - uVar6 * uVar7;
  param_1[3] = (uVar8 - (int)*(short *)(puVar2 + uVar4 * 2)) + 1;
  param_1[2] = uVar6 / 0xe10;
  uVar6 = uVar6 % 0xe10;
  param_1[1] = uVar6 / 0x3c;
  *param_1 = uVar6 % 0x3c;
  if ((int)param_1[8] < 0) {
    param_1[8] = 0xffffffff;
  }
  return CONCAT44(uVar5 + 0xe10,param_1);
}



/* ===== FUN_0802eecc @ 0802eecc ===== */

undefined4 FUN_0802eecc(void)

{
  return 0;
}



/* ===== FUN_0802eed0 @ 0802eed0 ===== */

void FUN_0802eed0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0802c8c0();
                    /* WARNING: Could not recover jumptable at 0x0802eee2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0x20))(param_1);
  return;
}



/* ===== FUN_0802eee4 @ 0802eee4 ===== */

void FUN_0802eee4(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0802c8c0();
                    /* WARNING: Could not recover jumptable at 0x0802eef6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0x28))(param_1);
  return;
}



/* ===== FUN_0802eef8 @ 0802eef8 ===== */

void FUN_0802eef8(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  param_1[1] = 0;
  param_1[2] = 0x6b;
  return;
}



/* ===== FUN_0802ef04 @ 0802ef04 ===== */

int FUN_0802ef04(code *param_1,int param_2,int *param_3,int *param_4,undefined1 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined1 auStack_160 [8];
  code *local_158;
  int local_154;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  int local_134;
  int local_130;
  int local_12c;
  ushort local_128;
  int local_124;
  undefined1 local_120;
  undefined *local_118;
  undefined *local_114 [60];
  
  iVar1 = DAT_0802f0c0;
  local_130 = 0;
  local_120 = param_5;
  local_118 = &DAT_0802f0e4;
  local_158 = param_1;
  local_154 = param_2;
  do {
    iVar2 = FUN_0802f61a(param_3,&DAT_0802f0c4);
    if (0 < iVar2) {
      local_154 = (*local_158)(local_154,param_3,iVar2);
      if (local_154 == 0) {
        return -1;
      }
      local_130 = iVar2 + local_130;
    }
    if (param_3[iVar2] == 0) {
      return local_130;
    }
    param_3 = param_3 + iVar2 + 1;
    local_138 = 0;
    local_13c = 0;
    local_140 = 0;
    local_144 = 0;
    local_148 = 0;
    local_14c = 0;
    local_128 = 0;
    local_114[0] = &DAT_0802f0cc;
    while (iVar2 = thunk_FUN_0802f644(&DAT_0802f0cc,*param_3,5), iVar2 != 0) {
      param_3 = param_3 + 1;
      local_128 = local_128 |
                  (ushort)*(undefined4 *)(&UNK_0802f100 + (iVar2 - (int)local_114[0] & 0xfffffffc));
    }
    if (*param_3 == 0x2a) {
      local_12c = *(int *)*param_4;
      *param_4 = (int)((int *)*param_4 + 1);
      if (local_12c < 0) {
        local_12c = -local_12c;
        local_128 = local_128 | 4;
      }
      param_3 = param_3 + 1;
    }
    else {
      local_12c = 0;
      while (iVar2 = FUN_0802f652(*param_3), iVar2 != 0) {
        if (local_12c < iVar1) {
          local_12c = *param_3 + local_12c * 10 + -0x30;
        }
        param_3 = param_3 + 1;
      }
    }
    if (*param_3 == 0x2e) {
      iVar2 = param_3[1];
      if (iVar2 == 0x2a) {
        local_134 = *(int *)*param_4;
        *param_4 = (int)((int *)*param_4 + 1);
        param_3 = param_3 + 2;
      }
      else {
        if (iVar2 == 0x2d) {
          iVar2 = 0x2d;
          param_3 = param_3 + 2;
        }
        else {
          iVar2 = 0;
          param_3 = param_3 + 1;
        }
        local_134 = 0;
        while (iVar3 = FUN_0802f652(*param_3), iVar3 != 0) {
          if ((iVar2 == 0) && (local_134 < iVar1)) {
            local_134 = *param_3 + local_134 * 10 + -0x30;
          }
          param_3 = param_3 + 1;
        }
      }
    }
    else {
      local_134 = -1;
    }
    iVar2 = FUN_0802f658(local_118,*param_3);
    local_124 = 0;
    piVar4 = param_3;
    if (iVar2 != 0) {
      piVar4 = param_3 + 1;
      local_124 = *param_3;
    }
    if (local_124 == 0x68) {
      if (*piVar4 == 0x68) {
        local_124 = 0x62;
LAB_0802f092:
        piVar4 = piVar4 + 1;
      }
    }
    else {
      iVar2 = local_124;
      if (local_124 == 0x6c) {
        iVar2 = *piVar4;
      }
      if (local_124 == 0x6c && iVar2 == 0x6c) {
        local_124 = 0x71;
        goto LAB_0802f092;
      }
    }
    param_3 = piVar4 + 1;
    iVar2 = FUN_0802f66c(auStack_160,param_4,*piVar4,local_114);
    if (iVar2 < 0) {
      return -1;
    }
    iVar2 = FUN_0802fa38(auStack_160,local_114);
    if (iVar2 < 0) {
      return -1;
    }
  } while( true );
}



/* ===== FUN_0802f2cc @ 0802f2cc ===== */

void FUN_0802f2cc(void)

{
  do {
    software_bkpt(0xab);
  } while( true );
}



/* ===== FUN_0802f2e0 @ 0802f2e0 ===== */

int FUN_0802f2e0(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  short local_38 [16];
  undefined4 uStack_18;
  
  iVar1 = 0;
  uStack_18 = param_4;
  do {
    iVar2 = iVar1;
    FUN_0802543c(param_2,0x1e,local_38);
    if (local_38[0] == -1) {
      *(uint *)(param_1 + 4) = param_2;
      return iVar2;
    }
    if (*(uint *)(param_1 + 8) < 0x2000000) {
LAB_0802f30e:
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 0x1e;
    }
    else if (local_38[0] == 0xa5) {
      *(uint *)(param_1 + 8) = param_2;
      goto LAB_0802f30e;
    }
    param_2 = param_2 + 0x1e;
    if (((param_2 & 0xfff) == 0) || (iVar1 = iVar2 + 0x1e, 0x1000 - (param_2 & 0xfff) < 0x1e)) {
      return iVar2 + 0x2e;
    }
  } while( true );
}



/* ===== FUN_0802f334 @ 0802f334 ===== */

void FUN_0802f334(uint param_1,uint param_2,uint param_3,uint param_4,int param_5,int param_6,
                 uint param_7)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  byte bVar8;
  uint uVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  uint uVar14;
  byte bVar15;
  byte bVar16;
  byte bVar17;
  byte bVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  byte local_57;
  uint local_50;
  
  uVar14 = (uint)*DAT_0802f5b0;
  uVar21 = (uint)*DAT_0802f5b4;
  uVar9 = (uint)*DAT_0802f5ac;
  uVar19 = (uint)*DAT_0802f5b8;
  if (param_5 == 0) {
    return;
  }
  if (param_6 == 0) {
    return;
  }
  uVar20 = param_1;
  if (uVar21 < uVar19) {
LAB_0802f378:
    uVar19 = uVar20;
    uVar21 = param_1;
  }
  else if ((int)param_1 < (int)uVar19) {
    uVar19 = param_1;
  }
  else {
    uVar20 = uVar19;
    if ((int)uVar21 < (int)param_1) goto LAB_0802f378;
  }
  uVar20 = param_2;
  if (uVar14 < uVar9) {
LAB_0802f38e:
    uVar9 = uVar20;
    uVar14 = param_2;
  }
  else if ((int)param_2 < (int)uVar9) {
    uVar9 = param_2;
  }
  else {
    uVar20 = uVar9;
    if ((int)uVar14 < (int)param_2) goto LAB_0802f38e;
  }
  uVar20 = param_3;
  if (uVar21 < uVar19) {
LAB_0802f3aa:
    bVar18 = (byte)uVar20;
    uVar21 = param_3;
  }
  else {
    bVar18 = (byte)uVar19;
    if ((int)param_3 < (int)uVar19) {
      bVar18 = (byte)param_3;
    }
    else {
      uVar20 = uVar19;
      if ((int)uVar21 < (int)param_3) goto LAB_0802f3aa;
    }
  }
  uVar19 = param_4;
  if (uVar9 <= uVar14) {
    bVar8 = (byte)uVar9;
    if ((int)param_4 < (int)uVar9) {
      bVar8 = (byte)param_4;
      goto LAB_0802f3c8;
    }
    uVar19 = uVar9;
    if ((int)param_4 <= (int)uVar14) goto LAB_0802f3c8;
  }
  bVar8 = (byte)uVar19;
  uVar14 = param_4;
LAB_0802f3c8:
  bVar11 = *(byte *)(DAT_0802f5bc + (param_2 & 7));
  bVar2 = *(byte *)(DAT_0802f5c0 + (param_4 & 7));
  bVar17 = 0;
  while( true ) {
    pbVar6 = DAT_0802f5b8;
    pbVar5 = DAT_0802f5b0;
    pbVar4 = DAT_0802f5ac;
    if ((param_4 & 0xff) < (param_2 & 0xff)) break;
    if ((param_2 & 0xf8) == (param_4 & 0xf8)) {
      bVar11 = bVar11 & bVar2;
    }
    uVar19 = 0;
    bVar1 = *(byte *)(DAT_0802f5c4 + (param_2 & 7));
    uVar9 = param_2;
    local_50 = param_1;
    do {
      uVar20 = uVar9;
      cVar3 = (char)local_50;
      bVar13 = (byte)param_3 - cVar3;
      local_50 = ((param_2 & 0xff) >> 3) * 0x80 + local_50;
      uVar9 = 0x80;
      local_57 = bVar13;
      if (7 < bVar13) {
        local_57 = 7;
      }
      while( true ) {
        local_50 = local_50 & 0xffff;
        bVar12 = 0;
        bVar15 = bVar17;
        bVar10 = bVar1;
        bVar16 = (byte)uVar20;
        do {
          pbVar4 = DAT_0802f5b8;
          *DAT_0802f5b4 = (byte)uVar21;
          *pbVar4 = bVar18;
          bVar16 = bVar16 + 1;
          *DAT_0802f5b0 = (byte)uVar14;
          *DAT_0802f5ac = bVar8;
          uVar7 = (uint)bVar15;
          bVar15 = bVar15 + 1;
          if ((*(byte *)(param_5 + param_6 * uVar7 + uVar19) & uVar9) != 0) {
            bVar12 = bVar12 | bVar10;
          }
          bVar10 = bVar10 << 1;
        } while ((bVar10 != 0) && ((uint)bVar16 <= (param_4 & 0xff)));
        if ((param_7 >> 6 & 1) == 0) {
          if ((param_7 & 0x80) != 0) {
            bVar12 = bVar12 ^ 0xff;
          }
          if (bVar11 != 0xff) {
            bVar12 = bVar12 & bVar11 | ~bVar11 & *(byte *)(DAT_0802f5c8 + local_50);
          }
        }
        else if ((param_7 & 0x80) == 0) {
          bVar12 = bVar12 & bVar11 | *(byte *)(DAT_0802f5c8 + local_50);
        }
        else {
          bVar12 = (bVar12 ^ 0xff | ~bVar11) & *(byte *)(DAT_0802f5c8 + local_50);
        }
        *(byte *)(DAT_0802f5c8 + local_50) = bVar12;
        uVar9 = uVar9 >> 1;
        local_50 = local_50 + 1;
        if (local_57 == 0) break;
        local_57 = local_57 - 1;
      }
      if (bVar13 < 8) {
        bVar13 = bVar13 + cVar3 + 1;
      }
      else {
        bVar13 = cVar3 + 8;
      }
      local_50 = (uint)bVar13;
      uVar19 = uVar19 + 1 & 0xff;
      uVar9 = uVar20 & 0xff;
    } while ((int)local_50 <= (int)param_3);
    bVar11 = 0xff;
    param_2 = (uVar20 & 0xf8) + 8;
    bVar17 = bVar15;
  }
  *DAT_0802f5b4 = (byte)uVar21;
  *pbVar6 = bVar18;
  *pbVar5 = (byte)uVar14;
  *pbVar4 = bVar8;
  return;
}



/* ===== FUN_0802f5cc @ 0802f5cc ===== */

undefined4 * FUN_0802f5cc(undefined4 *param_1)

{
  FUN_08029eca();
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  *param_1 = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 0xd) = 0;
  param_1[0xf] = 0xffffffff;
  param_1[0xe] = 0xc0;
  param_1[0x10] = 0xc0;
  return param_1;
}



/* ===== FUN_0802f604 @ 0802f604 ===== */

int FUN_0802f604(int param_1)

{
  FUN_08029eca();
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  return param_1;
}



/* ===== FUN_0802f61a @ 0802f61a ===== */

int FUN_0802f61a(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  for (piVar1 = param_1; *piVar1 != 0; piVar1 = piVar1 + 1) {
    piVar2 = param_2;
    while (*piVar2 != 0) {
      iVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      if (*piVar1 == iVar3) goto LAB_0802f636;
    }
  }
LAB_0802f636:
  return (int)piVar1 - (int)param_1 >> 2;
}



/* ===== thunk_FUN_0802f644 @ 0802f63e ===== */

int * thunk_FUN_0802f644(int *param_1,int param_2,int param_3)

{
  while( true ) {
    if (param_3 == 0) {
      return (int *)0x0;
    }
    if (*param_1 == param_2) break;
    param_1 = param_1 + 1;
    param_3 = param_3 + -1;
  }
  return param_1;
}



/* ===== FUN_0802f644 @ 0802f644 ===== */

int * FUN_0802f644(int *param_1,int param_2,int param_3)

{
  while( true ) {
    if (param_3 == 0) {
      return (int *)0x0;
    }
    if (*param_1 == param_2) break;
    param_1 = param_1 + 1;
    param_3 = param_3 + -1;
  }
  return param_1;
}



/* ===== FUN_0802f652 @ 0802f652 ===== */

uint FUN_0802f652(uint param_1)

{
  ushort uVar1;
  
  if (param_1 < 0x80) {
    uVar1 = *(ushort *)(DAT_0802fc00 + param_1 * 2);
  }
  else {
    uVar1 = 0;
  }
  return ~-(uint)((uVar1 & 0x40) == 0) >> 0x1f;
}



/* ===== FUN_0802f658 @ 0802f658 ===== */

int * FUN_0802f658(int *param_1,int param_2)

{
  int iVar1;
  
  do {
    if (*param_1 == param_2) {
      return param_1;
    }
    iVar1 = *param_1;
    param_1 = param_1 + 1;
  } while (iVar1 != 0);
  return (int *)0x0;
}



/* ===== FUN_0802f66c @ 0802f66c ===== */

longlong FUN_0802f66c(uint *param_1,int *param_2,uint param_3,uint param_4)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined2 *puVar5;
  undefined *puVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint *puVar10;
  
  if (param_3 == 0x25) {
    uVar3 = param_1[5];
    param_1[5] = uVar3 + 1;
    *(undefined4 *)(param_4 + uVar3 * 4) = 0x25;
    goto LAB_0802f9ba;
  }
  if ((param_3 != 0x41) && (2 < param_3 - 0x45)) {
    if (param_3 == 0x58) goto LAB_0802f78e;
    if (param_3 == 0x61) goto LAB_0802f81e;
    if (param_3 == 99) {
      if (param_1[0xf] == 0x6c) {
        uVar3 = param_1[5];
        param_1[5] = uVar3 + 1;
        uVar8 = *(undefined4 *)*param_2;
        *param_2 = (int)((undefined4 *)*param_2 + 1);
        *(undefined4 *)(param_4 + uVar3 * 4) = uVar8;
      }
      else {
        uVar8 = *(undefined4 *)*param_2;
        *param_2 = (int)((undefined4 *)*param_2 + 1);
        iVar2 = FUN_0802fc04(uVar8);
        if (iVar2 == -1) {
LAB_0802f998:
          return CONCAT44(param_4,0xffffffff);
        }
        uVar3 = param_1[5];
        param_1[5] = uVar3 + 1;
        *(int *)(param_4 + uVar3 * 4) = iVar2;
      }
      goto LAB_0802f9ba;
    }
    if (param_3 == 100) {
LAB_0802f706:
      uVar3 = param_1[0xf];
      puVar10 = (uint *)*param_2;
      if (uVar3 == 0x6c) {
        uVar7 = *puVar10;
        *param_2 = (int)(puVar10 + 1);
LAB_0802f736:
        uVar9 = (int)uVar7 >> 0x1f;
      }
      else {
        if (uVar3 != 0x71 && uVar3 != 0x6a) {
          uVar7 = *puVar10;
          *param_2 = (int)(puVar10 + 1);
          goto LAB_0802f736;
        }
        puVar10 = (uint *)((int)puVar10 + 7U & 0xfffffff8);
        *param_2 = (int)puVar10;
        uVar7 = *puVar10;
        uVar9 = puVar10[1];
        *param_2 = (int)(puVar10 + 2);
      }
      *param_1 = uVar7;
      param_1[1] = uVar9;
      if (uVar3 == 0x68) {
        uVar7 = (uint)(short)uVar7;
LAB_0802f754:
        *param_1 = uVar7;
        param_1[1] = (int)uVar7 >> 0x1f;
      }
      else {
        if (uVar3 == 0x62) {
          uVar7 = (uint)(char)uVar7;
          goto LAB_0802f754;
        }
        if (uVar3 == 0x74 || uVar3 == 0x7a) goto LAB_0802f754;
      }
      if ((int)param_1[1] < 0) {
        uVar3 = param_1[5];
        param_1[5] = uVar3 + 1;
        uVar8 = 0x2d;
LAB_0802f788:
        *(undefined4 *)(param_4 + uVar3 * 4) = uVar8;
      }
      else {
        if ((int)((uint)(ushort)param_1[0xe] << 0x1e) < 0) {
          uVar3 = param_1[5];
          param_1[5] = uVar3 + 1;
          uVar8 = 0x2b;
          goto LAB_0802f788;
        }
        if ((int)((uint)(ushort)param_1[0xe] << 0x1f) < 0) {
          uVar3 = param_1[5];
          param_1[5] = uVar3 + 1;
          uVar8 = 0x20;
          goto LAB_0802f788;
        }
      }
LAB_0802f814:
      param_1[4] = param_4 + param_1[5] * 4;
    }
    else {
      if (param_3 - 0x65 < 3) goto LAB_0802f81e;
      if (param_3 == 0x69) goto LAB_0802f706;
      if (param_3 == 0x6e) {
        if ((char)param_1[0x10] != '\0') {
          pcVar1 = "wprintf_s: %n disallowed";
LAB_0802f982:
          iVar2 = FUN_0802c9a4(pcVar1);
          return CONCAT44(param_4,-1 - iVar2);
        }
        uVar3 = param_1[0xf];
        if (uVar3 == 0x62) {
          puVar4 = *(undefined1 **)*param_2;
          *param_2 = (int)((undefined4 *)*param_2 + 1);
          if (puVar4 == (undefined1 *)0x0) {
            pcVar1 = "wprintf: bad %n argument";
            goto LAB_0802f982;
          }
          *puVar4 = (char)param_1[0xc];
        }
        else if (uVar3 == 0x68) {
          puVar5 = *(undefined2 **)*param_2;
          *param_2 = (int)((undefined4 *)*param_2 + 1);
          if (puVar5 == (undefined2 *)0x0) {
            pcVar1 = "wprintf: bad %n argument";
            goto LAB_0802f982;
          }
          *puVar5 = (short)param_1[0xc];
        }
        else if ((uVar3 == 0x6a) || ((uVar3 != 0x6c && (uVar3 == 0x71)))) {
          puVar10 = *(uint **)*param_2;
          *param_2 = (int)((int *)*param_2 + 1);
          if (puVar10 == (uint *)0x0) {
            pcVar1 = "wprintf: bad %n argument";
            goto LAB_0802f982;
          }
          uVar3 = param_1[0xc];
          *puVar10 = uVar3;
          puVar10[1] = (int)uVar3 >> 0x1f;
        }
        else {
          puVar10 = *(uint **)*param_2;
          *param_2 = (int)((undefined4 *)*param_2 + 1);
          if (puVar10 == (uint *)0x0) {
            pcVar1 = "wprintf: bad %n argument";
            goto LAB_0802f982;
          }
          *puVar10 = param_1[0xc];
        }
        goto LAB_0802f9ba;
      }
      if (param_3 == 0x6f) {
LAB_0802f78e:
        uVar3 = param_1[0xf];
        puVar10 = (uint *)*param_2;
        if (uVar3 == 0x6c) {
          uVar7 = *puVar10;
          *param_2 = (int)(puVar10 + 1);
LAB_0802f7be:
          uVar9 = 0;
        }
        else {
          if (uVar3 != 0x71 && uVar3 != 0x6a) {
            uVar7 = *puVar10;
            *param_2 = (int)(puVar10 + 1);
            goto LAB_0802f7be;
          }
          puVar10 = (uint *)((int)puVar10 + 7U & 0xfffffff8);
          *param_2 = (int)puVar10;
          uVar7 = *puVar10;
          uVar9 = puVar10[1];
          *param_2 = (int)(puVar10 + 2);
        }
        *param_1 = uVar7;
        param_1[1] = uVar9;
        if (uVar3 == 0x68) {
          uVar7 = uVar7 & 0xffff;
LAB_0802f7dc:
          *param_1 = uVar7;
          param_1[1] = 0;
        }
        else {
          if (uVar3 == 0x62) {
            uVar7 = uVar7 & 0xff;
            goto LAB_0802f7dc;
          }
          if (uVar3 == 0x74 || uVar3 == 0x7a) goto LAB_0802f7dc;
        }
        if ((((int)((uint)(byte)param_1[0xe] << 0x1c) < 0) && (param_1[1] != 0 || *param_1 != 0)) &&
           ((param_3 | 0x20) == 0x78)) {
          uVar3 = param_1[5];
          param_1[5] = uVar3 + 1;
          *(undefined4 *)(param_4 + uVar3 * 4) = 0x30;
          uVar3 = param_1[5];
          param_1[5] = uVar3 + 1;
          *(uint *)(param_4 + uVar3 * 4) = param_3;
        }
        goto LAB_0802f814;
      }
      if (param_3 != 0x70) {
        if (param_3 == 0x73) {
          uVar3 = param_1[0xf];
          puVar6 = *(undefined **)*param_2;
          *param_2 = (int)((undefined4 *)*param_2 + 1);
          if (uVar3 == 0x6c) {
            param_1[4] = (uint)puVar6;
            if (puVar6 == (undefined *)0x0) {
              if ((char)param_1[0x10] != '\0') {
                pcVar1 = "wprintf_s: bad %ls argument";
                goto LAB_0802f982;
              }
              param_1[4] = (uint)&DAT_0802fa14;
            }
            if ((int)param_1[0xb] < 0) {
              uVar3 = FUN_0803025e();
            }
            else {
              iVar2 = thunk_FUN_0802f644(param_1[4],0);
              if (iVar2 == 0) {
                uVar3 = param_1[0xb];
              }
              else {
                uVar3 = (int)(iVar2 - param_1[4]) >> 2;
              }
            }
            param_1[7] = uVar3;
          }
          else {
            if (puVar6 == (undefined *)0x0) {
              if ((char)param_1[0x10] != '\0') {
                pcVar1 = "wprintf_s: bad %s argument";
                goto LAB_0802f982;
              }
              puVar6 = &DAT_0802fa34;
            }
            iVar2 = FUN_08030270(param_1,puVar6);
            if (iVar2 < 0) goto LAB_0802f998;
          }
          goto LAB_0802f9ba;
        }
        if ((param_3 != 0x75) && (param_3 != 0x78)) {
          uVar3 = param_1[5];
          param_1[5] = uVar3 + 1;
          if (param_3 == 0) {
            param_3 = 0x25;
          }
          *(uint *)(param_4 + uVar3 * 4) = param_3;
          goto LAB_0802f9ba;
        }
        goto LAB_0802f78e;
      }
      uVar3 = *(uint *)*param_2;
      *param_2 = (int)((uint *)*param_2 + 1);
      *param_1 = uVar3;
      param_1[1] = 0;
      param_1[4] = param_4 + param_1[5] * 4;
      param_3 = 0x78;
    }
    FUN_0803011c(param_1,param_3);
    goto LAB_0802f9ba;
  }
LAB_0802f81e:
  puVar10 = (uint *)(*param_2 + 7U & 0xfffffff8);
  *param_2 = (int)puVar10;
  uVar3 = *puVar10;
  uVar7 = puVar10[1];
  *param_2 = (int)(puVar10 + 2);
  *param_1 = uVar3;
  param_1[1] = uVar7;
  if ((int)param_1[1] < 0) {
    uVar3 = param_1[5];
    param_1[5] = uVar3 + 1;
    uVar8 = 0x2d;
LAB_0802f862:
    *(undefined4 *)(param_4 + uVar3 * 4) = uVar8;
  }
  else {
    if ((int)((uint)(ushort)param_1[0xe] << 0x1e) < 0) {
      uVar3 = param_1[5];
      param_1[5] = uVar3 + 1;
      uVar8 = 0x2b;
      goto LAB_0802f862;
    }
    if ((int)((uint)(ushort)param_1[0xe] << 0x1f) < 0) {
      uVar3 = param_1[5];
      param_1[5] = uVar3 + 1;
      uVar8 = 0x20;
      goto LAB_0802f862;
    }
  }
  param_1[4] = param_4 + param_1[5] * 4;
  FUN_0802fc3c(param_1);
LAB_0802f9ba:
  return (ulonglong)param_4 << 0x20;
}



/* ===== FUN_0802fa38 @ 0802fa38 ===== */

longlong FUN_0802fa38(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar2 = (((((*(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x14)) - *(int *)(param_1 + 0x18)) -
            *(int *)(param_1 + 0x1c)) - *(int *)(param_1 + 0x20)) - *(int *)(param_1 + 0x24)) -
          *(int *)(param_1 + 0x28);
  if ((-1 < (int)((uint)*(byte *)(param_1 + 0x38) << 0x1d)) && (0 < (int)uVar2)) {
    iVar4 = (int)&DAT_0802fbe4 + DAT_0802fbe4;
    uVar5 = uVar2;
    do {
      if (uVar5 < 0x20) {
        uVar3 = uVar5;
      }
      else {
        uVar3 = 0x1f;
      }
      iVar1 = (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0xc),iVar4,uVar3);
      *(int *)(param_1 + 0xc) = iVar1;
      if (iVar1 == 0) goto LAB_0802fbdc;
      uVar5 = uVar5 - uVar3;
      *(uint *)(param_1 + 0x30) = uVar3 + *(int *)(param_1 + 0x30);
    } while (0 < (int)uVar5);
  }
  if (0 < *(int *)(param_1 + 0x14)) {
    iVar4 = (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0xc),param_2);
    *(int *)(param_1 + 0xc) = iVar4;
    if (iVar4 == 0) goto LAB_0802fbdc;
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x30);
  }
  uVar5 = *(uint *)(param_1 + 0x18);
  if (0 < (int)uVar5) {
    iVar4 = DAT_0802fbe4 + 0x802fc64;
    do {
      if (uVar5 < 0x20) {
        uVar3 = uVar5;
      }
      else {
        uVar3 = 0x1f;
      }
      iVar1 = (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0xc),iVar4,uVar3);
      *(int *)(param_1 + 0xc) = iVar1;
      if (iVar1 == 0) goto LAB_0802fbdc;
      uVar5 = uVar5 - uVar3;
      *(uint *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + uVar3;
    } while (0 < (int)uVar5);
  }
  if (0 < *(int *)(param_1 + 0x1c)) {
    iVar4 = (**(code **)(param_1 + 8))
                      (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10));
    *(int *)(param_1 + 0xc) = iVar4;
    if (iVar4 == 0) goto LAB_0802fbdc;
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x30);
  }
  uVar5 = *(uint *)(param_1 + 0x20);
  if (0 < (int)uVar5) {
    iVar4 = DAT_0802fbe4 + 0x802fc64;
    do {
      if (uVar5 < 0x20) {
        uVar3 = uVar5;
      }
      else {
        uVar3 = 0x1f;
      }
      iVar1 = (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0xc),iVar4,uVar3);
      *(int *)(param_1 + 0xc) = iVar1;
      if (iVar1 == 0) goto LAB_0802fbdc;
      uVar5 = uVar5 - uVar3;
      *(uint *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + uVar3;
    } while (0 < (int)uVar5);
  }
  if (0 < *(int *)(param_1 + 0x24)) {
    iVar4 = (**(code **)(param_1 + 8))
                      (*(undefined4 *)(param_1 + 0xc),
                       *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x1c) * 4);
    *(int *)(param_1 + 0xc) = iVar4;
    if (iVar4 == 0) {
LAB_0802fbdc:
      return CONCAT44(param_4,0xffffffff);
    }
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x30);
  }
  uVar5 = *(uint *)(param_1 + 0x28);
  if (0 < (int)uVar5) {
    iVar4 = DAT_0802fbe4 + 0x802fc64;
    do {
      if (uVar5 < 0x20) {
        uVar3 = uVar5;
      }
      else {
        uVar3 = 0x1f;
      }
      iVar1 = (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0xc),iVar4,uVar3);
      *(int *)(param_1 + 0xc) = iVar1;
      if (iVar1 == 0) goto LAB_0802fbdc;
      uVar5 = uVar5 - uVar3;
      *(uint *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + uVar3;
    } while (0 < (int)uVar5);
  }
  if (((int)((uint)*(byte *)(param_1 + 0x38) << 0x1d) < 0) && (0 < (int)uVar2)) {
    iVar4 = (int)&DAT_0802fbe4 + DAT_0802fbe4;
    do {
      if (uVar2 < 0x20) {
        uVar5 = uVar2;
      }
      else {
        uVar5 = 0x1f;
      }
      iVar1 = (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0xc),iVar4,uVar5);
      *(int *)(param_1 + 0xc) = iVar1;
      if (iVar1 == 0) goto LAB_0802fbdc;
      uVar2 = uVar2 - uVar5;
      *(uint *)(param_1 + 0x30) = uVar5 + *(int *)(param_1 + 0x30);
    } while (0 < (int)uVar2);
  }
  return (ulonglong)param_4 << 0x20;
}



/* ===== FUN_0802fc04 @ 0802fc04 ===== */

undefined4 FUN_0802fc04(int param_1)

{
  int iVar1;
  undefined1 local_18 [4];
  undefined4 local_14;
  undefined1 auStack_10 [8];
  
  if (param_1 != -1) {
    FUN_08030312(auStack_10,0,8);
    local_18[0] = (undefined1)param_1;
    iVar1 = FUN_0802c96e(&local_14,local_18,1,auStack_10);
    if (-1 < iVar1) {
      return local_14;
    }
  }
  return 0xffffffff;
}



/* ===== FUN_0802fc3c @ 0802fc3c ===== */

void FUN_0802fc3c(ulonglong *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint *puVar5;
  undefined *puVar6;
  uint uVar7;
  uint extraout_r1;
  int iVar8;
  int iVar9;
  uint extraout_r2;
  uint *puVar10;
  short sVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  char cVar17;
  ulonglong uVar18;
  undefined8 uVar19;
  ulonglong uVar20;
  longlong lVar21;
  uint local_d4;
  uint local_d0;
  uint uStack_cc;
  uint local_c8 [7];
  uint local_ac [33];
  undefined4 uStack_28;
  
  uStack_28 = param_4;
  uVar15 = param_2 | 0x20;
  uVar2 = *param_1;
  uVar13 = *(uint *)((int)param_1 + 4);
  uVar1 = *param_1;
  uVar20 = *param_1;
  puVar5 = local_c8;
  if (uVar15 != 0x61) {
    if (*(int *)((int)param_1 + 0x2c) < 0) {
      uVar3 = 6;
    }
    else {
      if (*(int *)((int)param_1 + 0x2c) != 0 || uVar15 != 0x67) goto LAB_0802fc70;
      uVar3 = 1;
    }
    *(undefined4 *)((int)param_1 + 0x2c) = uVar3;
  }
LAB_0802fc70:
  local_d0 = (uint)*param_1;
  uStack_cc = *(uint *)((int)param_1 + 4);
  uVar18 = *param_1;
  iVar9 = (int)(uStack_cc << 1) >> 0x15;
  if ((iVar9 == -1) && ((uStack_cc & 0xfffff) != 0)) {
    *(undefined4 *)((int)param_1 + 0x1c) = 3;
    if (param_2 - 0x61 < 0x1a) {
      puVar6 = &DAT_080300fc;
    }
    else {
      puVar6 = &DAT_0803010c;
    }
  }
  else {
    if ((iVar9 != -1) || ((uStack_cc & 0xfffff) != 0)) {
      uVar12 = uStack_cc & 0x7fffffff;
      if (uVar12 < 0x100000) {
        local_d4 = 0;
        if (uVar12 != 0 || local_d0 != 0) {
          uVar18 = FUN_0802ca3c(local_d0,uStack_cc,&local_d4);
        }
      }
      else {
        local_d4 = DAT_080300c0 + (uVar12 >> 0x14);
        uVar18 = CONCAT44(DAT_080300c8 | uStack_cc & DAT_080300c4,local_d0);
      }
      *param_1 = uVar18;
      if (uVar15 == 0x61) {
        puVar4 = *(undefined4 **)(param_1 + 2);
        *puVar4 = 0x30;
        *(undefined4 **)(param_1 + 2) = puVar4 + 2;
        if (param_2 == 0x61) {
          uVar3 = 0x78;
        }
        else {
          uVar3 = 0x58;
        }
        puVar4[1] = uVar3;
        *(int *)((int)param_1 + 0x14) = *(int *)((int)param_1 + 0x14) + 2;
      }
      uVar12 = (uint)*param_1;
      uVar7 = *(uint *)((int)param_1 + 4);
      local_d0 = uVar12;
      uStack_cc = uVar7;
      if ((uVar7 & 0x7fffffff) == 0 && uVar12 == 0) {
        sVar11 = 0;
      }
      else {
        if (uVar15 == 0x61) {
          if (param_2 == 0x61) {
            iVar9 = DAT_08030004 + 0x803004c;
          }
          else {
            iVar9 = DAT_08030004 + 0x803008c;
          }
          cVar17 = '\x01';
          if (*(int *)((int)param_1 + 0x2c) < 0) {
            iVar16 = 0x21;
          }
          else {
            iVar16 = *(int *)((int)param_1 + 0x2c) + 1;
          }
          FUN_0802caac((int)uVar2,uVar13,0,0);
          iVar14 = iVar16 + 2;
          if (cVar17 == '\0') {
            uVar7 = uVar7 ^ 0x80000000;
          }
          uVar20 = CONCAT44(uVar7,uVar12);
          local_d4 = local_d4 - 4;
          local_c8[0] = extraout_r2;
          puVar5 = local_c8 + 1;
          if (0 < iVar14) {
            local_d0 = DAT_080300c4;
            do {
              uVar13 = (uint)(uVar20 >> 0x20);
              iVar8 = (int)uVar20;
              cVar17 = '\x01';
              FUN_0802cadc(iVar8,uVar13,0,0);
              if (cVar17 != '\0') break;
              uVar15 = (extraout_r1 & 0x7fffffff) >> 0x14;
              uVar12 = uVar15 + 0x1c;
              if ((uVar15 == 0) || (uVar12 == 0)) {
                if ((uVar20 & 0x7fffffff00000000) != 0 || iVar8 != 0) {
                  uVar20 = FUN_0802cb0c(iVar8,uVar13,0x1c);
                }
              }
              else if (uVar12 < 0x7ff) {
                uVar20 = CONCAT44(extraout_r1 & local_d0 | uVar12 * 0x100000,iVar8);
              }
              else {
                uVar20 = (ulonglong)(uVar13 & 0x80000000 | DAT_080300cc) << 0x20;
              }
              uVar3 = (undefined4)(uVar20 >> 0x20);
              uVar13 = FUN_0802cc48((int)uVar20,uVar3);
              iVar14 = iVar14 + -7;
              if (0 < iVar14) {
                uVar19 = FUN_0802cc84();
                uVar20 = FUN_0802cca8((int)uVar20,uVar3,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20)
                                     );
              }
              puVar5 = puVar5 + 7;
              iVar8 = 7;
              while ((0 < (int)uVar13 && (iVar8 = iVar8 + -1, -1 < iVar8))) {
                puVar5 = puVar5 + -1;
                *puVar5 = uVar13 & 0xf;
                uVar13 = (int)uVar13 >> 4;
              }
              while (iVar8 = iVar8 + -1, -1 < iVar8) {
                puVar5 = puVar5 + -1;
                *puVar5 = 0;
              }
              puVar5 = puVar5 + 7;
            } while (0 < iVar14);
          }
          iVar8 = (int)puVar5 - (int)(local_c8 + 1) >> 2;
          iVar14 = iVar8;
          if (iVar16 < iVar8) {
            iVar14 = iVar16;
          }
          puVar5 = local_c8 + 1;
          if (-1 < iVar14) {
            if ((iVar14 < iVar8) && (7 < local_c8[iVar14 + 1])) {
              uVar13 = 0xf;
            }
            else {
              uVar13 = 0;
            }
            iVar16 = iVar14;
            puVar10 = local_c8 + iVar14;
            while( true ) {
              if (*puVar10 != uVar13) break;
              iVar14 = iVar14 + -1;
              iVar16 = iVar16 + -1;
              puVar10 = puVar10 + -1;
            }
            if (uVar13 == 0xf) {
              local_c8[iVar16] = local_c8[iVar16] + 1;
            }
            if (iVar16 + -1 < 0) {
              local_d4 = local_d4 + 4;
              puVar5 = local_c8;
              iVar14 = iVar14 + 1;
            }
            iVar16 = iVar14 + -1;
            if (-1 < iVar16) {
              puVar10 = puVar5 + iVar16;
              do {
                *puVar10 = *(uint *)(iVar9 + *puVar10 * 4);
                iVar16 = iVar16 + -1;
                puVar10 = puVar10 + -1;
              } while (-1 < iVar16);
            }
          }
          if (*(int *)((int)param_1 + 0x2c) < 0) {
            *(int *)((int)param_1 + 0x2c) = iVar14 + -1;
          }
        }
        else {
          local_d4 = (int)(local_d4 * 0x7597) / DAT_080300d0 - 4;
          uVar20 = uVar20 & 0x7fffffffffffffff;
          if ((int)local_d4 < 0) {
            uVar13 = 3 - local_d4 & 0xfffffffc;
            local_d4 = -uVar13;
            puVar4 = (undefined4 *)((int)&DAT_08030004 + DAT_08030004);
            for (; 0 < (int)uVar13; uVar13 = (int)uVar13 >> 1) {
              if ((int)(uVar13 << 0x1f) < 0) {
                uVar20 = FUN_0802d018(*puVar4,puVar4[1]);
              }
              puVar4 = puVar4 + 2;
            }
          }
          else {
            uVar20 = uVar1 & 0x7fffffffffffffff;
            if (0 < (int)local_d4) {
              uVar12 = local_d4 & 0xfffffffc;
              lVar21 = (ulonglong)DAT_080300d4 << 0x20;
              puVar4 = (undefined4 *)((int)&DAT_08030004 + DAT_08030004);
              local_d4 = uVar12;
              while( true ) {
                uVar3 = (undefined4)((ulonglong)lVar21 >> 0x20);
                if ((int)uVar12 < 1) break;
                if ((int)(uVar12 << 0x1f) < 0) {
                  lVar21 = FUN_0802d018((int)lVar21,uVar3,*puVar4,puVar4[1]);
                }
                uVar12 = (int)uVar12 >> 1;
                puVar4 = puVar4 + 2;
              }
              uVar20 = FUN_0802cd8c((int)uVar2,uVar13 & 0x7fffffff,(int)lVar21,uVar3);
            }
          }
          if (uVar15 == 0x66) {
            iVar9 = local_d4 + 0xb;
          }
          else {
            iVar9 = 7;
          }
          iVar9 = iVar9 + *(int *)((int)param_1 + 0x2c);
          if (0x13 < iVar9) {
            iVar9 = 0x13;
          }
          local_c8[0] = 0x30;
          puVar5 = local_c8 + 1;
          while( true ) {
            uVar3 = (undefined4)(uVar20 >> 0x20);
            if (iVar9 < 1) break;
            cVar17 = '\x01';
            FUN_0802cadc((int)uVar20,uVar3,0,0);
            if (cVar17 != '\0') break;
            iVar14 = FUN_0802cc48();
            iVar9 = iVar9 + -8;
            if (0 < iVar9) {
              uVar19 = FUN_0802cc84();
              uVar19 = FUN_0802cca8((int)uVar20,uVar3,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
              uVar20 = FUN_0802d018((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0,DAT_080300d8);
            }
            puVar5 = puVar5 + 8;
            iVar16 = 8;
            while ((0 < iVar14 && (iVar16 = iVar16 + -1, -1 < iVar16))) {
              puVar5 = puVar5 + -1;
              *puVar5 = iVar14 % 10 + 0x30;
              iVar14 = iVar14 / 10;
            }
            while (iVar16 = iVar16 + -1, -1 < iVar16) {
              puVar5 = puVar5 + -1;
              *puVar5 = 0x30;
            }
            puVar5 = puVar5 + 8;
          }
          local_d4 = local_d4 + 7;
          iVar9 = (int)puVar5 - (int)(local_c8 + 1) >> 2;
          puVar5 = local_c8;
          while (puVar5 = puVar5 + 1, *puVar5 == 0x30) {
            local_d4 = local_d4 - 1;
            iVar9 = iVar9 + -1;
          }
          if (uVar15 == 0x66) {
            iVar14 = local_d4 + 1;
          }
          else if (uVar15 == 0x65) {
            iVar14 = 1;
          }
          else {
            iVar14 = 0;
          }
          iVar14 = iVar14 + *(int *)((int)param_1 + 0x2c);
          iVar16 = iVar9;
          if (iVar14 < iVar9) {
            iVar16 = iVar14;
          }
          iVar14 = iVar16;
          if (-1 < iVar16) {
            if ((iVar16 < iVar9) && (0x34 < puVar5[iVar16])) {
              uVar13 = 0x39;
            }
            else {
              uVar13 = 0x30;
            }
            puVar10 = puVar5 + -1 + iVar16;
            while( true ) {
              iVar16 = iVar16 + -1;
              if (*puVar10 != uVar13) break;
              iVar14 = iVar14 + -1;
              puVar10 = puVar10 + -1;
            }
            if (uVar13 == 0x39) {
              puVar5[iVar16] = puVar5[iVar16] + 1;
            }
            if (iVar16 < 0) {
              local_d4 = local_d4 + 1;
              iVar14 = iVar14 + 1;
              puVar5 = puVar5 + -1;
            }
          }
        }
        sVar11 = (short)iVar14;
        uVar12 = local_d4;
      }
      FUN_08030338(param_1,param_2,puVar5,(int)sVar11,(int)(short)uVar12);
      return;
    }
    *(undefined4 *)((int)param_1 + 0x1c) = 3;
    if (param_2 - 0x61 < 0x1a) {
      puVar6 = &DAT_080300dc;
    }
    else {
      puVar6 = &DAT_080300ec;
    }
  }
  FUN_08030326((int)param_1[2],puVar6,3);
  return;
}



/* ===== FUN_0803011c @ 0803011c ===== */

void FUN_0803011c(int *param_1,int param_2)

{
  int extraout_r2;
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  longlong lVar8;
  int aiStack_80 [24];
  
  iVar6 = (int)&DAT_08030194 + DAT_08030194;
  if (param_2 == 0x58) {
    iVar6 = DAT_08030194 + 0x80301d4;
  }
  else {
    if (param_2 == 0x6f) {
      iVar3 = 8;
      goto LAB_08030136;
    }
    if (param_2 != 0x78) {
      iVar3 = 10;
      goto LAB_08030136;
    }
  }
  iVar3 = 0x10;
LAB_08030136:
  iVar1 = *param_1;
  iVar2 = param_1[1];
  uVar5 = 0x18;
  if ((param_2 == 100 || param_2 == 0x69) && (param_1[1] < 0)) {
    bVar7 = iVar1 != 0;
    iVar1 = -iVar1;
    iVar2 = -iVar2 - (uint)bVar7;
  }
  bVar7 = iVar2 == 0 && iVar1 == 0;
  if (iVar2 == 0 && iVar1 == 0) {
    bVar7 = param_1[0xb] == 0;
  }
  if (!bVar7) {
    FUN_08025a74(iVar1,iVar2,iVar3,0);
    aiStack_80[0x17] = *(undefined4 *)(iVar6 + extraout_r2 * 4);
    uVar5 = 0x17;
  }
  lVar8 = FUN_08025a74(iVar1,iVar2,iVar3,0);
  piVar4 = aiStack_80 + uVar5;
  while( true ) {
    iVar1 = (int)lVar8;
    piVar4 = piVar4 + -1;
    if ((lVar8 == 0) || ((int)uVar5 < 1)) break;
    lVar8 = FUN_08025a74(iVar1,(int)((ulonglong)lVar8 >> 0x20),iVar3,0);
    *piVar4 = *(int *)(iVar6 + (iVar1 - iVar3 * (int)lVar8) * 4);
    uVar5 = uVar5 - 1;
  }
  if (((iVar3 == 8) && ((int)((uint)*(byte *)(param_1 + 0xe) << 0x1c) < 0)) &&
     ((0x17 < uVar5 || (aiStack_80[uVar5] != 0x30)))) {
    uVar5 = uVar5 - 1;
    aiStack_80[uVar5] = 0x30;
  }
  param_1[7] = 0x18 - uVar5;
  FUN_08030326(param_1[4],aiStack_80 + uVar5);
  iVar6 = param_1[0xb];
  iVar3 = param_1[7];
  if (iVar3 < iVar6) {
    param_1[6] = iVar6 - iVar3;
    *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) & 0xffef;
  }
  else if (((iVar6 < 0) && ((*(byte *)(param_1 + 0xe) & 0x14) == 0x10)) &&
          (iVar3 = ((param_1[0xd] - param_1[5]) - param_1[6]) - iVar3, 0 < iVar3)) {
    param_1[6] = iVar3;
  }
  return;
}



/* ===== FUN_0803025e @ 0803025e ===== */

int FUN_0803025e(int *param_1)

{
  int *piVar1;
  
  for (piVar1 = param_1; *piVar1 != 0; piVar1 = piVar1 + 1) {
  }
  return (int)piVar1 - (int)param_1 >> 2;
}



/* ===== FUN_08030270 @ 08030270 ===== */

int FUN_08030270(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined1 auStack_220 [8];
  int aiStack_218 [128];
  
  iVar3 = *(int *)(param_1 + 0x2c);
  uVar4 = *(uint *)(param_1 + 0x34);
  if (iVar3 < 0) {
    iVar3 = 0x7fffffff;
  }
  FUN_08030312(auStack_220,0,8);
  if (0x80 < uVar4) {
    return -1;
  }
  iVar5 = 0;
  if (0 < iVar3) {
    do {
      if (0x7f < *(uint *)(param_1 + 0x14)) {
        *(undefined4 *)(param_1 + 0x34) = 0;
        iVar5 = FUN_0802fa38(param_1,aiStack_218);
        if (iVar5 < 0) break;
        *(undefined4 *)(param_1 + 0x14) = 0;
      }
      uVar6 = FUN_0802c96e(aiStack_218 + *(int *)(param_1 + 0x14),param_2,0xffffffff,auStack_220);
      iVar2 = (int)((ulonglong)uVar6 >> 0x20);
      iVar1 = (int)uVar6;
      if (iVar1 < 0) {
        return -1;
      }
      if (iVar1 == 0) {
        iVar2 = aiStack_218[*(int *)(param_1 + 0x14)];
      }
      if (iVar1 == 0 && iVar2 == 0) break;
      iVar3 = iVar3 + -1;
      param_2 = param_2 + iVar1;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    } while (iVar3 != 0);
    if (iVar5 != 0) {
      return iVar5;
    }
  }
  iVar3 = FUN_0802fa38(param_1,aiStack_218);
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return iVar3;
}



/* ===== FUN_08030312 @ 08030312 ===== */

undefined4 FUN_08030312(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0802e258(param_1,param_3,param_2);
  return param_1;
}



/* ===== FUN_08030326 @ 08030326 ===== */

void FUN_08030326(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *param_1 = *param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



/* ===== FUN_08030338 @ 08030338 ===== */

void FUN_08030338(int param_1,uint param_2,undefined4 *param_3,int param_4,short param_5)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  byte *pbVar7;
  short sVar8;
  int iVar9;
  int iVar10;
  byte abStack_31 [13];
  undefined4 *puStack_24;
  int iStack_20;
  
  puStack_24 = param_3;
  iStack_20 = param_4;
  iVar1 = FUN_0802c97e();
  iVar1 = FUN_0802fc04(**(undefined1 **)(iVar1 + 0x24));
  if (iVar1 == -1) {
    iVar1 = 0x2e;
  }
  if (param_4 < 1) {
    param_4 = 1;
    param_3 = &DAT_080305e0;
  }
  iVar9 = (int)param_5;
  if ((param_2 | 0x20) == 0x66) {
LAB_080303aa:
    sVar8 = (short)(iVar9 + 1);
    iVar10 = (int)sVar8;
    iVar2 = *(int *)(param_1 + 0x10);
    iVar4 = *(int *)(param_1 + 0x1c);
    if (iVar10 < 1) {
      *(int *)(param_1 + 0x1c) = iVar4 + 1;
      *(undefined4 *)(iVar2 + iVar4 * 4) = 0x30;
      if ((0 < *(int *)(param_1 + 0x2c)) || ((int)((uint)*(byte *)(param_1 + 0x38) << 0x1c) < 0)) {
        iVar9 = *(int *)(param_1 + 0x1c);
        *(int *)(param_1 + 0x1c) = iVar9 + 1;
        *(int *)(iVar2 + iVar9 * 4) = iVar1;
      }
      iVar1 = *(int *)(param_1 + 0x2c);
      if (iVar1 + iVar10 < 0 != SCARRY4(iVar1,iVar10)) {
        sVar8 = -(short)iVar1;
      }
      iVar1 = sVar8 + iVar1;
      *(int *)(param_1 + 0x20) = -(int)sVar8;
      *(int *)(param_1 + 0x2c) = iVar1;
      if (iVar1 < param_4) {
        param_4 = iVar1;
      }
      iVar1 = (int)(short)param_4;
      *(int *)(param_1 + 0x24) = iVar1;
      FUN_08030326(iVar2 + *(int *)(param_1 + 0x1c) * 4,param_3,iVar1);
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x2c) - iVar1;
    }
    else {
      iVar2 = iVar2 + iVar4 * 4;
      if (param_4 < sVar8) {
        FUN_08030326(iVar2,param_3,param_4);
        iVar9 = param_4 + *(int *)(param_1 + 0x1c);
        *(int *)(param_1 + 0x1c) = iVar9;
        *(int *)(param_1 + 0x20) = iVar10 - param_4;
        if ((0 < *(int *)(param_1 + 0x2c)) || ((int)((uint)*(byte *)(param_1 + 0x38) << 0x1c) < 0))
        {
          *(int *)(*(int *)(param_1 + 0x10) + iVar9 * 4) = iVar1;
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
        }
        *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x2c);
      }
      else {
        FUN_08030326(iVar2,param_3);
        param_4 = param_4 - (iVar9 + 1);
        iVar9 = *(int *)(param_1 + 0x1c) + iVar10;
        *(int *)(param_1 + 0x1c) = iVar9;
        if ((0 < *(int *)(param_1 + 0x2c)) || ((int)((uint)*(byte *)(param_1 + 0x38) << 0x1c) < 0))
        {
          *(int *)(param_1 + 0x1c) = iVar9 + 1;
          *(int *)(*(int *)(param_1 + 0x10) + iVar9 * 4) = iVar1;
        }
        if (*(int *)(param_1 + 0x2c) < (int)(short)param_4) {
          param_4 = *(int *)(param_1 + 0x2c);
        }
        sVar8 = (short)param_4;
        FUN_08030326(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x1c) * 4,param_3 + iVar10,
                     (int)sVar8);
        *(int *)(param_1 + 0x1c) = (int)sVar8 + *(int *)(param_1 + 0x1c);
        *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x2c) - (int)sVar8;
      }
    }
  }
  else {
    if ((param_2 | 0x20) == 0x67) {
      iVar2 = *(int *)(param_1 + 0x2c);
      if ((-5 < iVar9) && (iVar9 < iVar2)) {
        if ((-1 < (int)((uint)*(byte *)(param_1 + 0x38) << 0x1c)) && (param_4 < iVar2)) {
          *(int *)(param_1 + 0x2c) = param_4;
        }
        iVar2 = *(int *)(param_1 + 0x2c) - (int)(short)(param_5 + 1);
        *(int *)(param_1 + 0x2c) = iVar2;
        if (iVar2 < 0) {
          *(undefined4 *)(param_1 + 0x2c) = 0;
        }
        goto LAB_080303aa;
      }
      if ((param_4 < iVar2) && (-1 < (int)((uint)*(byte *)(param_1 + 0x38) << 0x1c))) {
        *(int *)(param_1 + 0x2c) = param_4;
      }
      iVar2 = *(int *)(param_1 + 0x2c) + -1;
      *(int *)(param_1 + 0x2c) = iVar2;
      if (iVar2 < 0) {
        *(undefined4 *)(param_1 + 0x2c) = 0;
      }
      if (param_2 == 0x67) {
        param_2 = 0x65;
      }
      else {
        param_2 = 0x45;
      }
    }
    else if (param_2 == 0x61) {
      param_2 = 0x70;
    }
    else if (param_2 == 0x41) {
      param_2 = 0x50;
    }
    iVar4 = *(int *)(param_1 + 0x1c);
    *(int *)(param_1 + 0x1c) = iVar4 + 1;
    iVar2 = *(int *)(param_1 + 0x10);
    *(undefined4 *)(iVar2 + iVar4 * 4) = *param_3;
    if ((0 < *(int *)(param_1 + 0x2c)) || ((int)((uint)*(byte *)(param_1 + 0x38) << 0x1c) < 0)) {
      iVar4 = *(int *)(param_1 + 0x1c);
      *(int *)(param_1 + 0x1c) = iVar4 + 1;
      *(int *)(iVar2 + iVar4 * 4) = iVar1;
      iVar1 = *(int *)(param_1 + 0x2c);
      if (0 < iVar1) {
        iVar4 = param_4 + -1;
        if (iVar1 < (short)(param_4 + -1)) {
          iVar4 = iVar1;
        }
        sVar8 = (short)iVar4;
        FUN_08030326(iVar2 + *(int *)(param_1 + 0x1c) * 4,param_3 + 1,(int)sVar8);
        *(int *)(param_1 + 0x1c) = (int)sVar8 + *(int *)(param_1 + 0x1c);
        *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x2c) - (int)sVar8;
      }
    }
    iVar1 = *(int *)(param_1 + 0x10);
    puVar3 = (uint *)(iVar1 + *(int *)(param_1 + 0x1c) * 4);
    *puVar3 = param_2;
    if (iVar9 < 0) {
      puVar3[1] = 0x2d;
      iVar9 = -iVar9;
    }
    else {
      puVar3[1] = 0x2b;
    }
    puVar5 = puVar3 + 2;
    iVar2 = 0;
    pbVar7 = abStack_31 + 1;
    while (0 < (short)iVar9) {
      iVar4 = (int)(short)iVar9 / 10;
      *pbVar7 = (char)iVar9 + (char)iVar4 * -10;
      iVar2 = iVar2 + 1;
      pbVar7 = pbVar7 + 1;
      iVar9 = iVar4;
    }
    puVar6 = puVar5;
    if ((iVar2 < 2) && ((param_2 | 0x20) == 0x65)) {
      puVar6 = puVar3 + 3;
      *puVar5 = 0x30;
    }
    puVar3 = puVar6;
    if (iVar2 == 0) {
      puVar3 = puVar6 + 1;
      *puVar6 = 0x30;
    }
    else {
      for (; 0 < iVar2; iVar2 = iVar2 + -1) {
        *puVar3 = abStack_31[iVar2] + 0x30;
        puVar3 = puVar3 + 1;
      }
    }
    *(int *)(param_1 + 0x24) = (int)puVar3 - (iVar1 + *(int *)(param_1 + 0x1c) * 4) >> 2;
  }
  if ((*(byte *)(param_1 + 0x38) & 0x14) == 0x10) {
    iVar1 = *(int *)(param_1 + 0x28) +
            *(int *)(param_1 + 0x24) +
            *(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x14);
    if (iVar1 < *(int *)(param_1 + 0x34)) {
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x34) - iVar1;
    }
  }
  return;
}



/* ===== FUN_08035560 @ 08035560 ===== */

longlong FUN_08035560(undefined1 *param_1)

{
  uint unaff_r7;
  
  FUN_08035ac4(*param_1,*(undefined2 *)(param_1 + 1),param_1[3]);
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035572 @ 08035572 ===== */

longlong FUN_08035572(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035584 @ 08035584 ===== */

longlong FUN_08035584(int param_1)

{
  return (ulonglong)*(ushort *)(param_1 + 6) << 0x20;
}



/* ===== FUN_0803559c @ 0803559c ===== */

longlong FUN_0803559c(undefined1 *param_1)

{
  uint unaff_r7;
  
  FUN_08035b00(*param_1);
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080355a8 @ 080355a8 ===== */

longlong FUN_080355a8(byte *param_1)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined2 auStack_90 [66];
  
  puVar3 = auStack_90;
  pbVar4 = param_1 + 1;
  for (iVar1 = 0; iVar1 < (int)(uint)*param_1; iVar1 = iVar1 + 1) {
    pbVar5 = pbVar4 + 2;
    puVar2 = puVar3 + 1;
    *puVar3 = *(undefined2 *)pbVar4;
    pbVar4 = pbVar4 + 4;
    puVar3 = puVar3 + 2;
    *puVar2 = *(undefined2 *)pbVar5;
  }
  return ZEXT48(auStack_90) << 0x20;
}



/* ===== FUN_080355d6 @ 080355d6 ===== */

longlong FUN_080355d6(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080355e2 @ 080355e2 ===== */

longlong FUN_080355e2(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080355f2 @ 080355f2 ===== */

longlong FUN_080355f2(undefined1 *param_1)

{
  uint unaff_r7;
  
  FUN_08035b94(*param_1);
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080355fe @ 080355fe ===== */

longlong FUN_080355fe(void)

{
  uint unaff_r7;
  
  FUN_08035bec();
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035608 @ 08035608 ===== */

longlong FUN_08035608(int param_1)

{
  return (ulonglong)*(uint *)(param_1 + 1) << 0x20;
}



/* ===== FUN_08035660 @ 08035660 ===== */

longlong FUN_08035660(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035672 @ 08035672 ===== */

longlong FUN_08035672(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035684 @ 08035684 ===== */

longlong FUN_08035684(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035694 @ 08035694 ===== */

longlong FUN_08035694(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_0803569e @ 0803569e ===== */

longlong FUN_0803569e(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080356ae @ 080356ae ===== */

longlong FUN_080356ae(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080356ba @ 080356ba ===== */

longlong FUN_080356ba(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080356c6 @ 080356c6 ===== */

longlong FUN_080356c6(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080356d0 @ 080356d0 ===== */

longlong FUN_080356d0(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080356da @ 080356da ===== */

longlong FUN_080356da(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080356ec @ 080356ec ===== */

longlong FUN_080356ec(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080356f8 @ 080356f8 ===== */

longlong FUN_080356f8(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035708 @ 08035708 ===== */

longlong FUN_08035708(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035716 @ 08035716 ===== */

longlong FUN_08035716(undefined2 *param_1)

{
  uint unaff_r7;
  
  FUN_08035c14(*param_1,param_1[1]);
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035724 @ 08035724 ===== */

longlong FUN_08035724(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035734 @ 08035734 ===== */

longlong FUN_08035734(int param_1)

{
  return (ulonglong)*(byte *)(param_1 + 2) << 0x20;
}



/* ===== FUN_08035760 @ 08035760 ===== */

longlong FUN_08035760(int param_1)

{
  return (ulonglong)(param_1 + 6) << 0x20;
}



/* ===== FUN_08035778 @ 08035778 ===== */

longlong FUN_08035778(undefined2 *param_1)

{
  FUN_08035c28(*param_1,param_1[1],param_1[2],param_1[3]);
  return ZEXT48(param_1 + 4) << 0x20;
}



/* ===== FUN_08035790 @ 08035790 ===== */

longlong FUN_08035790(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_0803579c @ 0803579c ===== */

longlong FUN_0803579c(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080357aa @ 080357aa ===== */

longlong FUN_080357aa(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080357bc @ 080357bc ===== */

undefined4 FUN_080357bc(int param_1)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 auStack_90 [66];
  
  puVar3 = auStack_90;
  puVar4 = (undefined2 *)(param_1 + 3);
  for (iVar1 = 0; iVar1 < (int)(uint)*(byte *)(param_1 + 2); iVar1 = iVar1 + 1) {
    puVar5 = puVar4 + 1;
    puVar2 = puVar3 + 1;
    *puVar3 = *puVar4;
    puVar4 = puVar4 + 2;
    puVar3 = puVar3 + 2;
    *puVar2 = *puVar5;
  }
  return 0;
}



/* ===== FUN_080357ee @ 080357ee ===== */

longlong FUN_080357ee(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035800 @ 08035800 ===== */

longlong FUN_08035800(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035810 @ 08035810 ===== */

longlong FUN_08035810(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035820 @ 08035820 ===== */

longlong FUN_08035820(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035830 @ 08035830 ===== */

longlong FUN_08035830(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035842 @ 08035842 ===== */

longlong FUN_08035842(int param_1)

{
  return (ulonglong)(param_1 + 7) << 0x20;
}



/* ===== FUN_08035858 @ 08035858 ===== */

longlong FUN_08035858(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035864 @ 08035864 ===== */

longlong FUN_08035864(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035876 @ 08035876 ===== */

longlong FUN_08035876(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035888 @ 08035888 ===== */

longlong FUN_08035888(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035896 @ 08035896 ===== */

longlong FUN_08035896(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080358aa @ 080358aa ===== */

longlong FUN_080358aa(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080358bc @ 080358bc ===== */

longlong FUN_080358bc(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080358ce @ 080358ce ===== */

longlong FUN_080358ce(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080358de @ 080358de ===== */

undefined4 FUN_080358de(int param_1)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 auStack_88 [64];
  
  puVar2 = auStack_88;
  puVar3 = (undefined2 *)(param_1 + 3);
  for (iVar1 = 0; iVar1 < (int)(uint)*(byte *)(param_1 + 2); iVar1 = iVar1 + 1) {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return 0;
}



/* ===== FUN_08035908 @ 08035908 ===== */

longlong FUN_08035908(undefined2 *param_1)

{
  uint unaff_r7;
  
  FUN_08035c48(*param_1,param_1[1]);
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035916 @ 08035916 ===== */

longlong FUN_08035916(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035922 @ 08035922 ===== */

longlong FUN_08035922(int param_1)

{
  return (ulonglong)(param_1 + 7) << 0x20;
}



/* ===== FUN_08035938 @ 08035938 ===== */

undefined4 FUN_08035938(undefined1 *param_1)

{
  FUN_08035c8c(*param_1,*(undefined2 *)(param_1 + 1),param_1[3],param_1[4],param_1 + 5,
               *(undefined2 *)(param_1 + 0xb),*(undefined2 *)(param_1 + 0xd),
               *(undefined2 *)(param_1 + 0xf),param_1[0x11]);
  return 0;
}



/* ===== FUN_0803596a @ 0803596a ===== */

longlong FUN_0803596a(byte *param_1)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  byte local_90 [120];
  
  pbVar3 = local_90;
  cVar2 = '\x01';
  pbVar4 = param_1 + 1;
  for (iVar5 = 0; iVar5 < (int)(uint)*param_1; iVar5 = iVar5 + 1) {
    *pbVar3 = *pbVar4;
    pbVar3[1] = pbVar4[1];
    FUN_0802e734(pbVar3 + 2,pbVar4 + 2,6);
    pbVar3[8] = pbVar4[8];
    *(byte **)(pbVar3 + 0xc) = pbVar4 + 9;
    bVar1 = pbVar4[8] + 9 + cVar2;
    cVar2 = bVar1 + 1;
    pbVar3[0x10] = param_1[bVar1];
    pbVar3 = pbVar3 + 0x14;
    pbVar4 = pbVar4 + 0xb;
  }
  return ZEXT48(local_90) << 0x20;
}



/* ===== FUN_080359c4 @ 080359c4 ===== */

longlong FUN_080359c4(undefined1 *param_1)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 7);
  FUN_08035cb8(*param_1,*(undefined2 *)(param_1 + 1),*(undefined2 *)(param_1 + 3),
               *(undefined2 *)(param_1 + 5));
  return (ulonglong)uVar1 << 0x20;
}



/* ===== FUN_080359e2 @ 080359e2 ===== */

longlong FUN_080359e2(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080359f4 @ 080359f4 ===== */

longlong FUN_080359f4(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035a04 @ 08035a04 ===== */

longlong FUN_08035a04(int param_1)

{
  return (ulonglong)*(ushort *)(param_1 + 8) << 0x20;
}



/* ===== FUN_08035a1a @ 08035a1a ===== */

longlong FUN_08035a1a(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035a28 @ 08035a28 ===== */

longlong FUN_08035a28(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08035a36 @ 08035a36 ===== */

longlong FUN_08035a36(int param_1)

{
  return (ulonglong)*(ushort *)(param_1 + 1) << 0x20;
}



/* ===== FUN_08035a74 @ 08035a74 ===== */

longlong FUN_08035a74(byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte local_98 [8];
  byte local_90 [7];
  byte local_89 [113];
  undefined4 uStack_18;
  
  pbVar2 = local_98;
  pbVar3 = param_1 + 1;
  uStack_18 = param_4;
  for (iVar1 = 0; iVar1 < (int)(uint)*param_1; iVar1 = iVar1 + 1) {
    *pbVar2 = *pbVar3;
    pbVar2[1] = pbVar3[1];
    FUN_0802e734(pbVar2 + 2,pbVar3 + 2,6);
    pbVar2[8] = pbVar3[8];
    FUN_0802e734(pbVar2 + 9,pbVar3 + 9,6);
    pbVar2[0xf] = pbVar3[0xf];
    pbVar3 = pbVar3 + 0x10;
    pbVar2 = pbVar2 + 0x10;
  }
  return ZEXT48(local_98) << 0x20;
}



/* ===== FUN_08035ac4 @ 08035ac4 ===== */

void FUN_08035ac4(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  FUN_08019fc2(param_2,param_3);
  if (param_3 == 0x13) {
    uVar1 = DAT_08035af4;
  }
  else {
    if (param_3 != 8) {
      FUN_080187dc(DAT_08035afc,param_3);
      return;
    }
    uVar1 = DAT_08035af8;
  }
  FUN_08018794(uVar1);
  return;
}



/* ===== FUN_08035b00 @ 08035b00 ===== */

void FUN_08035b00(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  bool bVar5;
  
  iVar1 = DAT_08035b78;
  if (param_1 == 0) {
    bVar5 = *(int *)(DAT_08035b78 + 0x24) != -1;
    *(undefined4 *)(DAT_08035b78 + 0x24) = 0;
    uVar3 = DAT_08035b7c;
  }
  else if (param_1 == 2) {
    uVar4 = *(int *)(DAT_08035b78 + 0x2c) + 1;
    bVar5 = 4 < uVar4;
    if (bVar5) {
      uVar4 = 0;
    }
    *(uint *)(DAT_08035b78 + 0x2c) = uVar4;
    uVar3 = DAT_08035b84;
  }
  else {
    if (1 < param_1) {
      FUN_08018794(DAT_08035b88);
      uVar4 = 0xff;
      goto LAB_08035b5c;
    }
    uVar4 = *(int *)(DAT_08035b78 + 0x28) + 1;
    bVar5 = 9 < uVar4;
    if (bVar5) {
      uVar4 = 0;
    }
    *(uint *)(DAT_08035b78 + 0x28) = uVar4;
    uVar3 = DAT_08035b80;
  }
  FUN_08018794(uVar3);
  uVar4 = param_1 + 0xb | 0x80;
  if (!bVar5) {
    return;
  }
LAB_08035b5c:
  puVar2 = DAT_08035b8c;
  *(undefined1 *)(iVar1 + 0x18) = 0;
  *puVar2 = 1;
  if (*(char *)(iVar1 + 0x1a) == '\0') {
    *(char *)(iVar1 + 0x1a) = (char)uVar4;
  }
  FUN_080187dc(DAT_08035b90,uVar4 & 0xff);
  return;
}



/* ===== FUN_08035b94 @ 08035b94 ===== */

undefined4 FUN_08035b94(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  
  puVar2 = DAT_08035be4;
  iVar1 = DAT_08035be0;
  uVar3 = 1;
  if (param_1 != 1) {
    if (2 < param_1 - 2U) {
      if (param_1 - 5U < 5) {
        *(undefined1 *)(DAT_08035be0 + 0x18) = 0;
        *puVar2 = 1;
        if (*(char *)(iVar1 + 0x1a) == '\0') {
          *(undefined1 *)(iVar1 + 0x1a) = 0x81;
        }
        uVar4 = 0x81;
      }
      else {
        *(undefined1 *)(DAT_08035be0 + 0x18) = 0;
        *puVar2 = 1;
        if (*(char *)(iVar1 + 0x1a) == '\0') {
          *(undefined1 *)(iVar1 + 0x1a) = 0x86;
        }
        uVar4 = 0x86;
      }
      uVar4 = FUN_080187dc(DAT_08035be8,uVar4,param_4);
      return uVar4;
    }
    uVar3 = 2;
  }
  *(undefined1 *)(DAT_08035be0 + 0x18) = uVar3;
  return param_4;
}



/* ===== FUN_08035bec @ 08035bec ===== */

void FUN_08035bec(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_08035c0c;
  iVar1 = DAT_08035c08;
  *(undefined1 *)(DAT_08035c08 + 0x18) = 0;
  *puVar2 = 1;
  if (*(char *)(iVar1 + 0x1a) == '\0') {
    *(undefined1 *)(iVar1 + 0x1a) = 0x11;
  }
  FUN_080187dc(DAT_08035c10,0x11);
  return;
}



/* ===== FUN_08035c14 @ 08035c14 ===== */

void FUN_08035c14(uint param_1)

{
  if (param_1 == *(ushort *)(DAT_08035c24 + 4)) {
    return;
  }
  FUN_08023160(0x42);
  FUN_08018826(DAT_08023340,0x42,*(undefined2 *)(DAT_0802333c + 6));
  return;
}



/* ===== FUN_08035c28 @ 08035c28 ===== */

void FUN_08035c28(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
                 undefined4 param_5)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(DAT_08035c44 + 0x20) + 4);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x08035c3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_2,param_4,param_5);
  return;
}



/* ===== FUN_08035c48 @ 08035c48 ===== */

void FUN_08035c48(void)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  
  puVar3 = DAT_08035c84;
  puVar2 = DAT_08035c80;
  iVar1 = DAT_08035c7c;
  if (*(char *)(DAT_08035c7c + 0x18) == '\b') {
    *(undefined1 *)(DAT_08035c7c + 0x18) = 7;
    *puVar2 = *puVar2 | 4;
    return;
  }
  *(undefined1 *)(DAT_08035c7c + 0x18) = 0;
  *puVar3 = 1;
  if (*(char *)(iVar1 + 0x1a) == '\0') {
    *(undefined1 *)(iVar1 + 0x1a) = 0x12;
  }
  FUN_080187dc(DAT_08035c88,0x12);
  return;
}



/* ===== FUN_08035c8c @ 08035c8c ===== */

void FUN_08035c8c(undefined4 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8)

{
  int *piVar1;
  
  piVar1 = DAT_08035cb0;
  *(undefined2 *)(DAT_08035cb0 + 1) = param_2;
  *(undefined1 *)(piVar1 + 6) = 7;
  *piVar1 = *piVar1 + 1;
  *(undefined2 *)(piVar1 + 2) = param_7;
  *(undefined2 *)((int)piVar1 + 6) = param_6;
  *(undefined2 *)((int)piVar1 + 10) = param_8;
  FUN_08018794(DAT_08035cb4,param_3,param_4);
  return;
}



/* ===== FUN_08035cb8 @ 08035cb8 ===== */

undefined4
FUN_08035cb8(uint param_1,uint param_2,undefined2 param_3,undefined4 param_4,undefined2 param_5)

{
  undefined4 uVar1;
  int *unaff_r4;
  bool bVar2;
  
  bVar2 = param_1 == 0;
  if (bVar2) {
    param_1 = (uint)*(ushort *)(DAT_08035cec + 1);
    unaff_r4 = DAT_08035cec;
  }
  if (bVar2 && param_2 == param_1) {
    *(undefined2 *)((int)unaff_r4 + 10) = param_5;
    *unaff_r4 = *unaff_r4 + 1;
    *(undefined2 *)((int)unaff_r4 + 6) = param_3;
    *(short *)(unaff_r4 + 2) = (short)param_4;
    if (*(char *)((int)unaff_r4 + 0xd) == '\x02') {
      *(undefined1 *)((int)unaff_r4 + 0xd) = 3;
    }
    return param_4;
  }
  FUN_08023160(0x40,param_4);
  uVar1 = FUN_08018826(DAT_08023340,0x40,*(undefined2 *)(DAT_0802333c + 6));
  return uVar1;
}



/* ===== FUN_08037048 @ 08037048 ===== */

void FUN_08037048(void)

{
  return;
}



/* ===== FUN_0803704a @ 0803704a ===== */

void FUN_0803704a(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_0803704c @ 0803704c ===== */

void FUN_0803704c(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_0803704e @ 0803704e ===== */

void FUN_0803704e(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_08037050 @ 08037050 ===== */

void FUN_08037050(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_08037052 @ 08037052 ===== */

void FUN_08037052(void)

{
  return;
}



/* ===== FUN_08037054 @ 08037054 ===== */

void FUN_08037054(void)

{
  return;
}



/* ===== FUN_08037056 @ 08037056 ===== */

void FUN_08037056(void)

{
  return;
}



/* ===== FUN_08037058 @ 08037058 ===== */

void FUN_08037058(void)

{
  return;
}



/* ===== FUN_0803705a @ 0803705a ===== */

int * FUN_0803705a(void)

{
  int *piVar1;
  
  piVar1 = DAT_080371bc;
  if (*DAT_080371bc << 0x1e < 0) {
    *DAT_080371bc = 2;
    return (int *)*piVar1;
  }
  return DAT_080371bc;
}



/* ===== FUN_0803706e @ 0803706e ===== */

void FUN_0803706e(void)

{
  if (*DAT_080371bc << 0x1d < 0) {
    *DAT_080371bc = 4;
    *(undefined1 *)(DAT_080226dc + 5) = 1;
    *DAT_080226e0 = 1;
    DataSynchronizationBarrier(0xf);
    return;
  }
  return;
}



/* ===== FUN_08037082 @ 08037082 ===== */

int * FUN_08037082(void)

{
  int *piVar1;
  int *unaff_r7;
  
  piVar1 = DAT_080371bc;
  if (*DAT_080371bc << 0x1b < 0) {
    *DAT_080371bc = 0x10;
    FUN_08022b64(*piVar1);
    *DAT_080371c0 = 1;
    DataSynchronizationBarrier(0xf);
    return unaff_r7;
  }
  return DAT_080371bc;
}



/* ===== FUN_080370a0 @ 080370a0 ===== */

void FUN_080370a0(void)

{
  if (*DAT_080371c4 << 0x1e < 0) {
    DAT_080371c4[1] = 2;
    FUN_0801819c();
    *DAT_080371c0 = 1;
    DataSynchronizationBarrier(0xf);
  }
  return;
}



/* ===== FUN_080370c0 @ 080370c0 ===== */

void FUN_080370c0(void)

{
  int *piVar1;
  
  piVar1 = DAT_080371c4;
  if (*DAT_080371c4 << 0x1a < 0) {
    DAT_080371c4[1] = 0x20;
    FUN_0801947c();
  }
  if (*piVar1 << 0x19 < 0) {
    piVar1[1] = 0x40;
    FUN_0801947c();
  }
  if (*piVar1 << 0x18 < 0) {
    piVar1[1] = 0x80;
  }
  return;
}



/* ===== FUN_080370ec @ 080370ec ===== */

void FUN_080370ec(void)

{
  char cVar1;
  char *pcVar2;
  uint *puVar3;
  byte *pbVar4;
  byte bVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  bool bVar8;
  
  if ((-1 < *DAT_080371c8 << 0x1c) ||
     (*DAT_080371c8 = 8, pbVar4 = DAT_080371d0, (short)*DAT_080371cc < 1)) {
    return;
  }
  if ((int)((uint)DAT_080371d0[8] << 0x1f) < 0) {
    if (DAT_080371d0[0x20] == 0) {
      uVar7 = *(undefined4 *)(DAT_080371d0 + 0x10);
      uVar6 = 0;
    }
    else {
      uVar7 = 0;
      uVar6 = *(undefined4 *)(DAT_080371d0 + 0x14);
    }
    FUN_08021158(uVar6,uVar7);
  }
  bVar5 = FUN_0802092a();
  pcVar2 = DAT_08020b50;
  bVar8 = bVar5 == 0;
  if (bVar8) {
    bVar5 = *pbVar4 & 5;
  }
  if (!bVar8 || bVar5 != 5) {
    return;
  }
  cVar1 = *DAT_08020b50;
  bVar8 = cVar1 == '\0';
  if (bVar8) {
    cVar1 = DAT_08020b50[1];
  }
  if (bVar8 && cVar1 == '\0') {
    *DAT_08020b54 = 1;
    pcVar2[0xc] = '\x01';
    pcVar2[0xd] = '\0';
    pcVar2[0xe] = '\0';
    pcVar2[0xf] = '\0';
    pcVar2[0x14] = '\0';
    pcVar2[0x15] = '\0';
    pcVar2[0x16] = '\0';
    pcVar2[0x17] = '\0';
    pcVar2[0x18] = '\0';
    pcVar2[0x19] = '\0';
    pcVar2[0x1a] = '\0';
    pcVar2[0x1b] = '\0';
    pcVar2[0x1c] = '\0';
    pcVar2[0x1d] = '\0';
    pcVar2[0x1e] = '\0';
    pcVar2[0x1f] = '\0';
    pcVar2[0x20] = '\0';
    pcVar2[0x21] = '\0';
    pcVar2[0x22] = '\0';
    pcVar2[0x23] = '\0';
    pcVar2[1] = '\x01';
    pcVar2[2] = '\0';
    pcVar2[0x10] = '\0';
    pcVar2[0x11] = '\0';
    pcVar2[0x12] = '\0';
    pcVar2[0x13] = '\0';
    *(undefined4 *)(pcVar2 + 0x2c) = *(undefined4 *)(DAT_08020b58 + 0xc);
    pcVar2[0x3c] = -0x18;
    pcVar2[0x3d] = '\x03';
    pcVar2[0x3e] = '\0';
    pcVar2[0x3f] = '\0';
    pcVar2[0x34] = -0x18;
    puVar3 = DAT_08020b5c;
    pcVar2[0x35] = '\x03';
    pcVar2[0x36] = '\0';
    pcVar2[0x37] = '\0';
    DAT_08020b5c[0xb] = 2999;
    *puVar3 = *puVar3 | 1;
    puVar3 = DAT_08020b60;
    *DAT_08020b60 = *DAT_08020b60 & 0xfffffffe;
    puVar3[9] = 0;
    puVar3[4] = 0xfffffffe;
    puVar3[3] = puVar3[3] | 1;
    puVar3[0xb] = 1;
    *puVar3 = *puVar3 | 1;
  }
  return;
}



/* ===== FUN_0803710a @ 0803710a ===== */

void FUN_0803710a(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_080371bc;
  iVar2 = *DAT_080371bc;
  if (iVar2 << 0x1a < 0) {
    *DAT_080371bc = 0x20;
    FUN_08022b64(iVar2 << 0x1a,0x20,*piVar1);
    *DAT_080371c0 = 1;
    DataSynchronizationBarrier(0xf);
  }
  iVar2 = *piVar1;
  if (iVar2 << 0x19 < 0) {
    *piVar1 = 0x40;
    FUN_08022b64(iVar2 << 0x19,0x40,*piVar1);
    *DAT_080371c0 = 1;
    DataSynchronizationBarrier(0xf);
  }
  return;
}



/* ===== FUN_08037144 @ 08037144 ===== */

void FUN_08037144(void)

{
  if (*DAT_080371bc << 0x12 < 0) {
    *DAT_080371bc = 0x2000;
    *DAT_080371c0 = 1;
    DataSynchronizationBarrier(0xf);
    *DAT_080371d4 = 1;
  }
  return;
}



/* ===== thunk_FUN_08020934 @ 08037166 ===== */

undefined8 thunk_FUN_08020934(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  undefined *puVar9;
  uint uStack_20;
  uint uStack_1c;
  
  puVar5 = DAT_08020b6c;
  puVar2 = DAT_08020b5c;
  DAT_08020b6c[0x11] = DAT_08020b6c[0x11] & 0xffff7fff;
  *puVar2 = *puVar2 & 0xfffffffe;
  puVar2[3] = puVar2[3] & 0xfffffeff;
  puVar4 = DAT_08020b68;
  DataSynchronizationBarrier(0xf);
  DataMemoryBarrier(0x1f);
  *DAT_08020b68 = *DAT_08020b68 & 0xfffffffe;
  iVar1 = DAT_08020b50;
  DataSynchronizationBarrier(0xf);
  DataMemoryBarrier(0x1f);
  iVar8 = *(int *)(DAT_08020b50 + 0x2c);
  uStack_20 = param_3;
  uStack_1c = param_4;
  if (iVar8 == 0) {
    *(undefined1 *)(DAT_08020b50 + 1) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *DAT_08020b54 = 0;
    if (*(int *)(iVar1 + 4) == 0) {
      *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(iVar1 + 0x24);
    }
    else {
      *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 0x24);
    }
    *(undefined4 *)(iVar1 + 0x24) = 0;
    puVar9 = (undefined *)0x0;
  }
  else if (*(char *)(DAT_08020b50 + 1) == '\0') {
    puVar9 = (undefined *)0x0;
  }
  else {
    uStack_1c = (((uint)((*(int *)(iVar8 + 4) + 1) * 1000) / *(uint *)(DAT_08020b50 + 0x38)) * 1000)
                / *(uint *)(DAT_08020b50 + 0x3c) - 1;
    uStack_20 = ((DAT_08020b70 / *(uint *)(DAT_08020b50 + 0x30)) * 1000) /
                *(uint *)(DAT_08020b50 + 0x34);
    if (uStack_20 < 0xff) {
      uStack_20 = 0xff;
    }
    iVar6 = (**(code **)(iVar8 + 0x1c))(iVar8,&uStack_20,&uStack_1c);
    puVar2[0xb] = uStack_1c;
    puVar3 = DAT_08020b60;
    *DAT_08020b60 = *DAT_08020b60 & 0xfffffffe;
    puVar3[9] = 0;
    puVar3[0xb] = *(uint *)(iVar8 + 8);
    *puVar5 = *puVar5 & 0xfffffffe;
    puVar5[0xb] = uStack_20;
    if (iVar6 != 0) {
      puVar4[1] = *(uint *)(iVar8 + 0xc) | puVar4[1] & 0xffff0000;
      *puVar4 = *puVar4 | 1;
      puVar2[3] = puVar2[3] | 0x100;
      puVar5[0x11] = puVar5[0x11] | 0x8000;
    }
    *puVar2 = *puVar2 | 1;
    piVar7 = *(int **)(iVar8 + 0x14);
    if (piVar7 == (int *)0x0) {
      puVar9 = *(undefined **)(iVar8 + 0x10);
      if (puVar9 == &UNK_08020b88) {
        puVar9 = (undefined *)(*(int *)(iVar1 + 0x2c) + 0x20);
      }
      else if (((puVar9 == (undefined *)0x0) && (*(char *)(iVar1 + 2) != '\0')) &&
              (*(byte *)(iVar1 + 2) < 0x11)) {
        *(undefined1 *)(iVar1 + 1) = *(undefined1 *)(iVar1 + 2);
        *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar1 + 0x10);
        iVar8 = DAT_08020b74;
        *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar1 + 0x28);
        puVar9 = *(undefined **)(iVar8 + (uint)*(byte *)(iVar1 + 2) * 8);
        *(undefined1 *)(iVar1 + 2) = 0;
        *(undefined4 *)(iVar1 + 0x10) = 0;
        *(undefined4 *)(iVar1 + 0x28) = 0;
      }
    }
    else {
      if (*piVar7 == 0) {
        iVar6 = *(int *)(iVar8 + 0x18);
      }
      else {
        iVar6 = *piVar7 + -1;
      }
      *piVar7 = iVar6;
      if (iVar6 == 0) {
        *(undefined4 *)(iVar1 + 0x3c) = *(undefined4 *)(iVar1 + 0x38);
        puVar9 = (undefined *)(*(int *)(iVar1 + 0x2c) + 0x20);
        *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(iVar1 + 0x30);
      }
      else {
        puVar9 = *(undefined **)(iVar8 + 0x10);
      }
    }
  }
  puVar2 = DAT_08020b60;
  DAT_08020b60[4] = 0xfffffffe;
  *puVar2 = *puVar2 | 1;
  *puVar5 = *puVar5 | 1;
  *(undefined **)(iVar1 + 0x2c) = puVar9;
  return CONCAT44(uStack_1c,uStack_20);
}



/* ===== thunk_FUN_080211b8 @ 0803716a ===== */

uint thunk_FUN_080211b8(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  
  puVar1 = DAT_080211dc;
  *DAT_080211dc = 0;
  puVar1[1] = 0;
  *DAT_080211e0 = 0;
  puVar2 = DAT_080211e4;
  *DAT_080211e4 = *DAT_080211e4 & 0xfffffffe;
  puVar2[4] = 0xfffffffe;
  return puVar2[4];
}



/* ===== FUN_0803716e @ 0803716e ===== */

undefined4 FUN_0803716e(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar2 = DAT_080371d8;
  puVar1 = DAT_080371c0;
  DAT_080371d8[1] = DAT_080371d8[1] | 1;
  uVar3 = *puVar2;
  *puVar1 = 1;
  DataSynchronizationBarrier(0xf);
  return uVar3;
}



/* ===== FUN_08037186 @ 08037186 ===== */

void FUN_08037186(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 in_r3;
  undefined4 uVar4;
  uint uVar5;
  
  *(uint *)(DAT_080371dc + 4) = *(uint *)(DAT_080371dc + 4) | 2;
  iVar1 = DAT_08019754;
  FUN_08019126(DAT_08019754 + 4);
  iVar2 = *(int *)(iVar1 + 0xc + *(int *)(iVar1 + 0x1c) * 4);
  iVar3 = *(int *)(iVar2 + 0x14) + 1;
  *(int *)(iVar2 + 0x14) = iVar3;
  if (0xff < iVar3) {
    uVar4 = *(undefined4 *)(iVar1 + 0xc + *(int *)(iVar1 + 0x1c) * 4);
    uVar5 = *(int *)(iVar1 + 0x1c) + 1;
    if (3 < uVar5) {
      uVar5 = 0;
    }
    iVar2 = *(int *)(iVar1 + 0xc + uVar5 * 4);
    FUN_08025caa(iVar2);
    FUN_08026000(uVar4);
    *(uint *)(iVar1 + 0x1c) = uVar5;
    *(undefined1 *)(iVar2 + 9) = 1;
    *(undefined1 *)(iVar2 + 8) = 0;
    FUN_08026014(DAT_0801973c,uVar4);
    *DAT_08019774 = 1;
    DataSynchronizationBarrier(0xf);
    *DAT_0801976c = 1;
  }
  FUN_0801919c(in_r3);
  return;
}



/* ===== FUN_08037196 @ 08037196 ===== */

int * FUN_08037196(void)

{
  int *piVar1;
  
  piVar1 = DAT_080371bc;
  if (*DAT_080371bc << 0x1c < 0) {
    *DAT_080371bc = 8;
    piVar1 = (int *)*piVar1;
  }
  return piVar1;
}



/* ===== FUN_080371a6 @ 080371a6 ===== */

undefined4 FUN_080371a6(void)

{
  undefined4 unaff_r7;
  
  (*(code *)*DAT_080371e0)();
  *DAT_080371c0 = 1;
  DataSynchronizationBarrier(0xf);
  return unaff_r7;
}



/* ===== FUN_080371e4 @ 080371e4 ===== */

undefined8 FUN_080371e4(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  char local_18;
  char local_17;
  char local_16;
  char local_15;
  uint local_14;
  
  iVar3 = (int)param_2 >> 4;
  local_14 = param_4 & 0xffffff00;
  local_16 = (char)iVar3;
  switch(param_2 & 0xf) {
  case 1:
    local_16 = local_16 + '0';
    local_18 = '_';
    local_15 = ' ';
    local_17 = '_';
    break;
  case 2:
    local_15 = ' ';
    local_17 = (char)((longlong)iVar3 * (longlong)DAT_08037378 >> 0x22) -
               (char)((longlong)iVar3 * (longlong)DAT_08037378 >> 0x3f);
    local_16 = local_16 + local_17 * -10 + '0';
    local_17 = local_17 + '0';
    local_18 = '_';
    break;
  case 3:
    iVar3 = (int)((ulonglong)((longlong)iVar3 * (longlong)DAT_08037378) >> 0x20);
    iVar3 = (iVar3 >> 2) - (iVar3 >> 0x1f);
    cVar2 = (char)iVar3;
    local_15 = local_16 + cVar2 * -10 + '0';
    lVar1 = (longlong)iVar3 * (longlong)DAT_08037378;
    local_18 = (char)(lVar1 >> 0x22) - (char)(lVar1 >> 0x3f);
    local_16 = cVar2 + local_18 * -10 + '0';
    local_18 = local_18 + '0';
    local_17 = '.';
    break;
  case 4:
    iVar3 = (int)((ulonglong)((longlong)iVar3 * (longlong)DAT_08037378) >> 0x20);
    iVar3 = (iVar3 >> 2) - (iVar3 >> 0x1f);
    cVar2 = (char)iVar3;
    local_15 = local_16 + cVar2 * -10 + '0';
    local_16 = '.';
    lVar1 = (longlong)iVar3 * (longlong)DAT_08037378;
    local_18 = (char)(lVar1 >> 0x22) - (char)(lVar1 >> 0x3f);
    local_17 = cVar2 + local_18 * -10 + '0';
    local_18 = local_18 + '0';
    break;
  case 5:
    local_15 = ' ';
    iVar3 = (int)((ulonglong)((longlong)iVar3 * (longlong)DAT_08037378) >> 0x20);
    iVar3 = (iVar3 >> 2) - (iVar3 >> 0x1f);
    cVar2 = (char)iVar3;
    local_16 = local_16 + cVar2 * -10 + '0';
    lVar1 = (longlong)iVar3 * (longlong)DAT_08037378;
    local_18 = (char)(lVar1 >> 0x22) - (char)(lVar1 >> 0x3f);
    local_17 = cVar2 + local_18 * -10 + '0';
    local_18 = local_18 + '0';
    break;
  case 6:
    local_17 = (char)((longlong)iVar3 * (longlong)DAT_08037378 >> 0x22) -
               (char)((longlong)iVar3 * (longlong)DAT_08037378 >> 0x3f);
    local_15 = local_16 + local_17 * -10 + '0';
    local_17 = local_17 + '0';
    local_16 = '.';
    local_18 = '>';
    break;
  case 7:
    local_15 = ' ';
    local_17 = (char)((longlong)iVar3 * (longlong)DAT_08037378 >> 0x22) -
               (char)((longlong)iVar3 * (longlong)DAT_08037378 >> 0x3f);
    local_16 = local_16 + local_17 * -10 + '0';
    local_17 = local_17 + '0';
    local_18 = '>';
    break;
  default:
    local_15 = '-';
    local_16 = '-';
    local_17 = '-';
    local_18 = ' ';
  }
  FUN_08019780(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
  FUN_08019d56(&local_18);
  return CONCAT44(local_14,CONCAT13(local_15,CONCAT12(local_16,CONCAT11(local_17,local_18))));
}



/* ===== FUN_0803737c @ 0803737c ===== */

void FUN_0803737c(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  undefined2 uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  undefined4 uVar13;
  undefined4 local_24;
  undefined4 uStack_20;
  
  iVar8 = *(int *)(param_1 + 8);
  if (0x4f < iVar8) {
    iVar8 = 0x4f;
  }
  iVar10 = param_2;
  if (0x4f < param_2) {
    iVar10 = 0x4f;
  }
  if (iVar10 != iVar8) {
    local_24 = param_3;
    uStack_20 = param_4;
    FUN_0802c2fc(&local_24,(int)&local_24 + 3,(int)&local_24 + 1,(int)&local_24 + 2,param_2);
    uVar4 = CONCAT11(local_24._3_1_,local_24._2_1_ - local_24._3_1_);
    if ((local_24 >> 8 & 0xff) + (local_24 & 0xff) < 0x80) {
      local_24 = CONCAT22(uVar4,0x1001);
    }
    else {
      local_24 = CONCAT31(CONCAT21(uVar4,(local_24._1_1_ - (char)local_24) + -1),
                          (local_24._1_1_ - (char)local_24) + -0x10);
    }
    uVar13 = local_24;
    bVar2 = local_24._2_1_ - 2;
    iVar11 = (int)(iVar8 + ((uint)(iVar8 >> 3) >> 0x1c)) >> 4;
    iVar1 = (int)(iVar10 + ((uint)(iVar10 >> 3) >> 0x1c)) >> 4;
    local_24._0_3_ = CONCAT12(bVar2,(undefined2)local_24);
    uVar6 = local_24;
    iVar8 = iVar8 + iVar11 * -0x10;
    if (iVar11 < iVar1) {
      local_24._0_1_ = (char)uVar13;
      uVar7 = (uint)bVar2 + iVar11 * -6;
      bVar2 = (char)iVar8 + (char)local_24 + 1;
      local_24._1_1_ = SUB41(uVar13,1);
      bVar5 = local_24._1_1_;
      bVar12 = bVar2 <= local_24._1_1_;
      local_24 = uVar6;
      if (bVar12) {
        FUN_08037510(bVar2,uVar7 - 2 & 0xff,bVar5,uVar7 & 0xff,0xffff);
      }
      iVar8 = -1;
      while (iVar11 = iVar11 + 1, iVar11 != iVar1) {
        FUN_08037510(local_24 & 0xff,uVar7 - 8 & 0xff,local_24._1_1_,uVar7 - 6 & 0xff,0xffff);
        uVar7 = uVar7 - 6;
      }
    }
    if (iVar1 < iVar11) {
      uVar6 = (local_24 >> 0x10 & 0xff) + iVar11 * -6;
      bVar2 = (char)iVar8 + (char)local_24;
      if ((local_24 & 0xff) <= (uint)bVar2) {
        FUN_08037510(local_24 & 0xff,uVar6 - 2 & 0xff,bVar2,uVar6 & 0xff,0);
      }
      iVar8 = 0xf;
      while (iVar11 = iVar11 + -1, iVar11 != iVar1) {
        FUN_08037510(local_24 & 0xff,uVar6 + 4 & 0xff,local_24._1_1_,uVar6 + 6 & 0xff,0);
        uVar6 = uVar6 + 6;
      }
    }
    uVar9 = (local_24 & 0xff) + iVar8;
    uVar6 = (local_24 & 0xff) + iVar10 + iVar1 * -0x10;
    uVar7 = (local_24 >> 0x10 & 0xff) + iVar11 * -6;
    if ((int)uVar9 < (int)uVar6) {
      uVar13 = 0xffff;
      uVar3 = uVar6;
      uVar6 = uVar9;
    }
    else {
      if ((int)uVar9 <= (int)uVar6) {
        return;
      }
      uVar13 = 0;
      uVar3 = uVar9;
    }
    FUN_08037510(uVar6 + 1 & 0xff,uVar7 - 2 & 0xff,uVar3 & 0xff,uVar7 & 0xff,uVar13);
  }
  return;
}



/* ===== FUN_08037510 @ 08037510 ===== */

void FUN_08037510(int param_1,int param_2,int param_3,int param_4,ushort param_5)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  
  pbVar8 = (byte *)*DAT_08037594;
  uVar7 = (uint)*pbVar8;
  uVar9 = (uint)pbVar8[1];
  uVar2 = uVar7 + param_1;
  if ((uVar7 + param_1 & 0xff) < uVar7) {
    uVar2 = uVar7;
  }
  bVar6 = pbVar8[2];
  bVar1 = (byte)uVar2;
  if ((uint)bVar6 < (uVar2 & 0xff)) {
    bVar1 = bVar6;
  }
  bVar4 = (byte)(uVar7 + param_3);
  if ((uint)bVar6 < (uVar7 + param_3 & 0xff)) {
    bVar4 = bVar6;
  }
  bVar6 = bVar1;
  if (bVar1 < bVar4) {
    bVar6 = bVar4;
  }
  uVar2 = uVar9 + param_2;
  if ((uVar9 + param_2 & 0xff) < uVar9) {
    uVar2 = uVar9;
  }
  bVar4 = pbVar8[3];
  bVar3 = (byte)uVar2;
  if ((uint)bVar4 < (uVar2 & 0xff)) {
    bVar3 = bVar4;
  }
  bVar5 = (byte)(uVar9 + param_4);
  if ((uint)bVar4 < (uVar9 + param_4 & 0xff)) {
    bVar5 = bVar4;
  }
  bVar4 = bVar3;
  if (bVar3 < bVar5) {
    bVar4 = bVar5;
  }
  *DAT_08037598 = 0;
  if ((int)((uint)pbVar8[0x10] << 0x1f) < 0) {
    param_5 = ~param_5;
  }
  FUN_08026a64(bVar1,bVar3,bVar6,bVar4,param_5,param_3,param_4);
  FUN_0802ad48();
  return;
}



/* ===== FUN_08037d48 @ 08037d48 ===== */

undefined4
FUN_08037d48(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  float fVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint in_fpscr;
  float fVar9;
  float fVar10;
  int iVar11;
  
  puVar3 = DAT_08037e50;
  *param_1 = 0;
  fVar2 = DAT_08037e4c;
  param_1[1] = *puVar3;
  FUN_080200dc(0);
  FUN_080200f6(0,0x1c);
  FUN_080200f6(0x69,0x1c);
  FUN_08037510(0,0x1d,0x69,0x1f,0);
  uVar4 = (*(uint *)(DAT_08037e54 + 0x58) & 0x1ff) >> 7;
  fVar9 = (float)VectorUnsignedToFloat
                           ((uint)*(byte *)(DAT_08037e58 + uVar4),(byte)(in_fpscr >> 0x16) & 3);
  if (uVar4 < 2) {
    iVar8 = 1;
  }
  else {
    iVar8 = 5;
  }
  iVar7 = 0;
  do {
    fVar10 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
    fVar10 = (float)FUN_0801d1de(fVar10 * fVar2);
    iVar11 = (int)(fVar10 * (1.0 / fVar9));
    uVar4 = iVar11 + 1;
    if (0x68 < (int)uVar4) {
      return param_4;
    }
    if (-1 < (int)uVar4) {
      iVar5 = (int)((ulonglong)((longlong)iVar7 * (longlong)DAT_08037e5c) >> 0x20);
      if (iVar7 == ((iVar5 >> 2) - (iVar5 >> 0x1f)) * 10) {
        if (0 < (int)uVar4) {
          cVar1 = (char)uVar4 + -1;
          FUN_080200dc(cVar1,0x1e,(int)((longlong)iVar7 * (longlong)DAT_08037e5c));
          FUN_080200f6(cVar1,0x1f);
        }
        FUN_080200dc(uVar4 & 0xff,0x1d);
        FUN_080200f6(uVar4 & 0xff,0x1e);
        uVar4 = iVar11 + 2;
        uVar6 = 0x1e;
      }
      else {
        iVar11 = (int)((ulonglong)((longlong)iVar7 * (longlong)DAT_08037e5c) >> 0x20);
        if (iVar7 != ((iVar11 >> 1) - (iVar11 >> 0x1f)) * 5) {
          FUN_08037e60(uVar4 & 0xff,0x1f,1);
          goto LAB_08037e08;
        }
        uVar6 = 0x1d;
      }
      FUN_080200dc(uVar4 & 0xff,uVar6);
      FUN_080200f6(uVar4 & 0xff,0x1f);
    }
LAB_08037e08:
    iVar7 = iVar8 + iVar7;
  } while( true );
}



/* ===== FUN_08037e60 @ 08037e60 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_08037e60(int param_1,int param_2,byte param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint unaff_r7;
  bool bVar8;
  
  pbVar4 = (byte *)*DAT_08037eac;
  uVar6 = (uint)*pbVar4;
  uVar5 = (uint)pbVar4[1];
  uVar1 = uVar6 + param_1;
  uVar3 = uVar5 + param_2;
  uVar7 = uVar1 & 0xff;
  bVar8 = uVar6 <= uVar7;
  if (bVar8) {
    uVar6 = (uint)pbVar4[2];
    unaff_r7 = uVar1 & 0xff;
  }
  if (bVar8 && unaff_r7 <= uVar6) {
    bVar8 = uVar5 <= (uVar3 & 0xff);
    if (bVar8) {
      uVar5 = (uint)pbVar4[3];
      uVar7 = uVar3 & 0xff;
    }
    if (bVar8 && uVar7 <= uVar5) {
      *_DAT_08037eb0 = 0;
      if ((int)((uint)pbVar4[0x10] << 0x1f) < 0) {
        param_3 = ~param_3;
      }
      FUN_0802c6ac(uVar1 & 0xff,uVar3 & 0xff,param_3);
      uVar2 = FUN_0802ad48(param_4);
      return uVar2;
    }
  }
  return param_4;
}



/* ===== FUN_08038698 @ 08038698 ===== */

undefined8 FUN_08038698(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  byte local_18;
  byte local_17;
  char local_16;
  char local_15;
  undefined4 uStack_14;
  
  local_18 = (byte)param_3;
  local_17 = (byte)((uint)param_3 >> 8);
  local_16 = (char)((uint)param_3 >> 0x10);
  local_15 = (char)((uint)param_3 >> 0x18);
  uStack_14 = param_4;
  FUN_0802c2fc(&local_17,&local_15,&local_18,&local_16);
  uVar2 = (uint)local_18;
  local_18 = local_18 - local_17;
  local_16 = local_16 - local_15;
  if ((int)-(uint)(uVar2 + local_17 < 0x80) < 0) {
    local_18 = 0x11;
  }
  else {
    local_17 = local_18 - 0x11;
  }
  bVar1 = local_17;
  iVar3 = 5;
  cVar4 = local_16 + -1;
  do {
    FUN_080200dc(bVar1 + 1,cVar4);
    FUN_080200f6(bVar1 + 0x10,cVar4);
    FUN_080200dc(bVar1 + 0x11,cVar4 + -1);
    FUN_080200f6(bVar1 + 0x11,cVar4 + -3);
    FUN_080200dc(bVar1 + 0x10,cVar4 + -4);
    FUN_080200f6(bVar1 + 1,cVar4 + -4);
    FUN_080200dc(bVar1,cVar4 + -3);
    FUN_080200f6(bVar1,cVar4 + -1);
    cVar4 = cVar4 + -6;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return CONCAT44(uStack_14,CONCAT13(local_15,CONCAT12(local_16,CONCAT11(local_17,local_18))));
}



/* ===== FUN_080392a8 @ 080392a8 ===== */

undefined8 FUN_080392a8(int param_1,uint param_2)

{
  ulonglong uVar1;
  undefined1 local_18;
  char cStack_17;
  char cStack_16;
  char cStack_15;
  undefined4 uStack_14;
  
  uStack_14 = DAT_08039318[1];
  local_18 = (undefined1)*DAT_08039318;
  if (param_2 < 0x3df) {
    if (param_2 < 100) {
      cStack_17 = (char)((ulonglong)param_2 * (ulonglong)DAT_0803931c >> 0x23);
      cStack_15 = (char)param_2 + cStack_17 * -10 + '0';
      cStack_16 = '.';
      goto LAB_080392fe;
    }
  }
  else {
    param_2 = 0x3de;
  }
  uVar1 = (ulonglong)param_2 * (ulonglong)DAT_0803931c >> 0x23;
  cStack_17 = (char)((ulonglong)(uint)uVar1 * (ulonglong)DAT_0803931c >> 0x23);
  cStack_15 = ' ';
  cStack_16 = (char)uVar1 + cStack_17 * -10 + '0';
LAB_080392fe:
  cStack_17 = cStack_17 + '0';
  FUN_08019780(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
  FUN_08019d56(&local_18);
  return CONCAT44(uStack_14,CONCAT13(cStack_15,CONCAT12(cStack_16,CONCAT11(cStack_17,local_18))));
}



/* ===== FUN_08039398 @ 08039398 ===== */

undefined8 FUN_08039398(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char cVar7;
  char *pcVar8;
  undefined4 local_20;
  
  pcVar6 = param_1 + 0x6c;
  pcVar8 = param_1 + 0x210;
  cVar7 = '\x01';
  param_1[0x210] = '\0';
  local_20 = param_3;
  if (pcVar6 < pcVar8) {
    for (; pcVar6 < pcVar8; pcVar6 = pcVar6 + 4) {
      cVar1 = *param_1;
      cVar2 = *pcVar6;
      if ((int)cVar2 != (int)cVar1) {
        *param_1 = cVar2;
        iVar3 = -(int)cVar1;
        uVar5 = iVar3 + 0x1c;
        iVar4 = -(int)cVar2;
        if ((char)(iVar4 + 0x1cU) < (char)uVar5) {
          local_20 = 0xffff;
          uVar5 = iVar4 + 0x1cU;
          iVar4 = iVar3;
        }
        else {
          local_20 = 0;
        }
        FUN_08037510(cVar7,uVar5 & 0xff,cVar7,iVar4 + 0x1bU & 0xff);
      }
      cVar7 = cVar7 + '\x01';
      param_1 = param_1 + 1;
    }
  }
  return CONCAT44(param_4,local_20);
}



/* ===== FUN_08039404 @ 08039404 ===== */

void FUN_08039404(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  FUN_0802af5c(*(undefined1 *)(param_1 + 0x14),
               *(char *)(param_1 + 0x16) + ('/' - *(char *)(param_1 + 0x17)),
               *(undefined1 *)(param_1 + 0x15),0x2f,param_4);
  uVar1 = FUN_08039470();
  if (*(char *)(param_1 + 9) == '\0') {
    uVar1 = uVar1 & 0xfffe;
  }
  else {
    uVar1 = uVar1 | 1;
  }
  FUN_080197c8(uVar1);
  uVar2 = FUN_0801fb10(DAT_08039468);
  FUN_08019d62(*(undefined4 *)(*DAT_0803946c + *(int *)(param_1 + 0x18) * 4));
  FUN_0801fb10(uVar2);
  FUN_0802af5c(*(undefined1 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x16),
               *(undefined1 *)(param_1 + 0x15),*(undefined1 *)(param_1 + 0x17));
  return;
}



/* ===== FUN_08039470 @ 08039470 ===== */

undefined2 FUN_08039470(void)

{
  return *(undefined2 *)(*DAT_08039478 + 0x10);
}



/* ===== FUN_08039668 @ 08039668 ===== */

void FUN_08039668(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  undefined1 auStack_20c [512];
  
  FUN_0801fb94(**(undefined1 **)(param_1 + 0xc));
  puVar4 = *(undefined1 **)(param_1 + 0x1c);
  if (puVar4 != (undefined1 *)0x0) {
    uVar1 = *puVar4;
    uVar2 = *DAT_080396bc;
    uVar3 = puVar4[1];
    FUN_08019780(*(undefined1 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x15));
    FUN_0802c0e8(auStack_20c,0x80,DAT_080396c4,
                 *(undefined4 *)
                  (*(int *)(DAT_080396c0 + 0x70) + (uint)*(byte *)(*(int *)(param_1 + 0x1c) + 1) * 4
                  ),*(int *)(param_1 + 0x1c) + 2);
    FUN_08019d62(auStack_20c);
    *(uint *)(param_1 + 0x18) = (uint)CONCAT12(uVar3,CONCAT11(uVar1,uVar2));
  }
  return;
}



/* ===== FUN_080396c8 @ 080396c8 ===== */

void FUN_080396c8(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  
  *DAT_08039704 = *DAT_08039704 | 0xf00000;
  puVar1 = DAT_08039708;
  *DAT_08039708 = *DAT_08039708 | 1;
  puVar1[2] = 0;
  *puVar1 = *puVar1 & DAT_0803970c;
  puVar1[3] = 0x1000;
  puVar2 = DAT_08039710;
  *puVar1 = *puVar1 & 0xfffbffff;
  puVar1[6] = 0;
  *puVar2 = DAT_08039714;
  return;
}



/* ===== FUN_0803a338 @ 0803a338 ===== */

void FUN_0803a338(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  param_2 = param_2 + param_1[6];
  iVar1 = (**(code **)(*param_1 + 0x18))(param_1);
  if (iVar1 < param_2) {
    param_2 = (**(code **)(*param_1 + 0x14))(param_1);
  }
  param_1[6] = param_2;
  FUN_0801a1be(param_1,param_4);
  return;
}



/* ===== FUN_0803a468 @ 0803a468 ===== */

void FUN_0803a468(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  param_2 = param_1[6] - param_2;
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
  if (param_2 < iVar1) {
    param_2 = (**(code **)(*param_1 + 0x18))(param_1);
  }
  param_1[6] = param_2;
  FUN_0801a1be(param_1,param_4);
  return;
}



/* ===== FUN_0803b280 @ 0803b280 ===== */

void FUN_0803b280(void)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)((int)&DAT_0803b2a4 + DAT_0803b2a4);
  for (piVar1 = (int *)((int)&DAT_0803b2a0 + DAT_0803b2a0); piVar1 != piVar2;
      piVar1 = (int *)(*(code *)((int)piVar1 + *piVar1))(piVar1 + 1)) {
  }
  return;
}



/* ===== FUN_0803b698 @ 0803b698 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0803b698(void)

{
  _DAT_e000ed88 = _DAT_e000ed88 | 0xf00000;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return 0x2000000;
}



/* ===== FUN_0803bb88 @ 0803bb88 ===== */

void FUN_0803bb88(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  undefined4 uVar3;
  
  *(undefined1 *)(param_1 + 10) = 0;
  FUN_0802c2fc(0,param_1 + 0x16,0,param_1 + 0x17);
  uVar3 = extraout_r3;
  FUN_0802af5c(*(char *)(param_1 + 0x14) + -1,*(undefined1 *)(param_1 + 0x16),
               *(undefined1 *)(param_1 + 0x15),*(undefined1 *)(param_1 + 0x17),extraout_r3,unaff_r4)
  ;
  uVar2 = FUN_08039470();
  uVar1 = DAT_08039ac4;
  if (*(char *)(param_1 + 9) == '\0') {
    uVar2 = uVar2 & 0xfffe;
  }
  else {
    uVar2 = uVar2 | 1;
  }
  FUN_080197c8(uVar2);
  FUN_0802c0e8(uVar1,0x20,DAT_08039ac8,*(undefined4 *)(param_1 + 0x18));
  FUN_08019d62(uVar1,uVar3);
  return;
}



/* ===== FUN_0803bbe8 @ 0803bbe8 ===== */

undefined4 FUN_0803bbe8(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    (*(code *)((int)param_1 + *param_1))();
  }
  return param_4;
}



/* ===== FUN_0803bc00 @ 0803bc00 ===== */

void FUN_0803bc00(void)

{
  undefined4 uVar1;
  
  FUN_0803b280();
  FUN_0801da0c(0);
  uVar1 = thunk_FUN_0803bc24();
  do {
    FUN_0802f2cc(uVar1);
  } while( true );
}



/* ===== thunk_FUN_0803bc24 @ 0803bc1e ===== */

void thunk_FUN_0803bc24(undefined4 param_1)

{
  do {
    FUN_0802f2cc(param_1);
  } while( true );
}



/* ===== FUN_0803bc24 @ 0803bc24 ===== */

void FUN_0803bc24(undefined4 param_1)

{
  do {
    FUN_0802f2cc(param_1);
  } while( true );
}



/* ===== Reset_Handler @ 0803c7c8 ===== */

void Reset_Handler(void)

{
  bool bVar1;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(DAT_0803c7d8);
  }
  (*DAT_0803c7dc)();
                    /* WARNING: Could not recover jumptable at 0x0803c7d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0803c7e0)();
  return;
}



/* ===== FUN_0803c97c @ 0803c97c ===== */

void FUN_0803c97c(int param_1)

{
  FUN_0801fb94(**(undefined1 **)(param_1 + 0xc));
  FUN_0801ffd0(param_1 + 0x10);
  return;
}



/* ===== FUN_0803c994 @ 0803c994 ===== */

undefined4 FUN_0803c994(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 extraout_r3;
  int unaff_r5;
  
  FUN_0801fb94(**(undefined1 **)(param_1 + 0xc));
  piVar1 = *(int **)(param_1 + 0x1c);
  iVar2 = 0;
  if (piVar1 != (int *)0x0) {
    unaff_r5 = *piVar1;
    iVar2 = *(int *)(param_1 + 0x18);
  }
  if (piVar1 != (int *)0x0 && unaff_r5 != iVar2) {
    FUN_0802c330(param_1 + 0x10,unaff_r5);
    *(int *)(param_1 + 0x18) = unaff_r5;
  }
  return extraout_r3;
}



/* ===== FUN_0803c9ac @ 0803c9ac ===== */

void FUN_0803c9ac(int param_1)

{
  FUN_0801fb94(**(undefined1 **)(param_1 + 0xc));
  FUN_08020248(param_1 + 0x10);
  return;
}



/* ===== FUN_0803c9c4 @ 0803c9c4 ===== */

void FUN_0803c9c4(int param_1)

{
  FUN_0801fb94(**(undefined1 **)(param_1 + 0xc));
  FUN_080202d4(param_1 + 0x10);
  return;
}



/* ===== FUN_0803c9dc @ 0803c9dc ===== */

void FUN_0803c9dc(int param_1)

{
  FUN_08025ca4(param_1 + 0x18,0x1000);
  *(undefined1 *)(param_1 + 8) = 1;
  return;
}



/* ===== FUN_0803cc9a @ 0803cc9a ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0803cc9a(int param_1)

{
  int iVar1;
  int iVar2;
  int extraout_r3;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  FUN_0801fb94(**(undefined1 **)(param_1 + 0xc));
  iVar1 = DAT_080149b0;
  iVar2 = (int)*(char *)(DAT_080149b0 + 0x14);
  if (iVar2 < 1) {
    return iVar2;
  }
  iVar2 = *(int *)(_DAT_080149ec + iVar2 * 4 + -4);
  if (*(char *)(iVar2 + 0x14) != '\0') {
    *(undefined1 *)(iVar2 + 0x14) = 0;
    puVar3 = (undefined4 *)(iVar1 + *(char *)(iVar2 + 0x17) * 4 + 0x28);
    puVar4 = puVar3 + *(char *)(iVar2 + 0x16);
    if (puVar3 < puVar4) {
      for (; puVar3 < puVar4; puVar3 = puVar3 + 1) {
        (**(code **)(*(int *)*puVar3 + 0xc))();
      }
    }
  }
  return extraout_r3;
}



/* ===== FUN_0803d244 @ 0803d244 ===== */

void FUN_0803d244(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



