/* firmware/rc-410/fw4.16 - flash.bin, Cortex-M4 (ARMv7E-M), Ghidra headless decompilation, one block per function */

/* ===== FUN_08010190 @ 08010190 ===== */

void FUN_08010190(int param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_08010d74;
  if (param_1 == 0) {
    *(uint *)(DAT_08010cc4 + 100) = *(uint *)(DAT_08010cc4 + 100) & 0xfffffeff;
    FUN_080157d4();
    *puVar1 = *puVar1 & 0xfffffffe;
    FUN_08020bd0(0);
    return;
  }
  *(uint *)(DAT_08010cc4 + 100) = *(uint *)(DAT_08010cc4 + 100) | 0x100;
  FUN_080157d4(1);
  FUN_080165a4(puVar1,1);
  return;
}



/* ===== FUN_080101ca @ 080101ca ===== */

void FUN_080101ca(uint param_1)

{
  *(uint *)(DAT_08010cc4 + 100) = *(uint *)(DAT_08010cc4 + 100) & 0xfffffbff | (param_1 & 1) << 10;
  if (param_1 == 0) {
    *DAT_08010d74 = *DAT_08010d74 & 0xfffffffb;
    return;
  }
  FUN_080165a4(DAT_08010d74,4);
  return;
}



/* ===== FUN_08010202 @ 08010202 ===== */

void FUN_08010202(int param_1)

{
  *(undefined1 *)(param_1 + 0x18) = 0;
  FUN_080157ba(0);
  *(undefined1 *)(param_1 + 0x1c) = 0;
  FUN_080165ac(param_1,0xf0000);
  return;
}



/* ===== FUN_08010222 @ 08010222 ===== */

void FUN_08010222(int param_1)

{
  if (*(char *)(param_1 + 0x1d) == '\0') {
    return;
  }
  FUN_080166a6(0x1009);
  *(undefined1 *)(param_1 + 0x18) = 1;
  FUN_080157ba(1);
  *(undefined1 *)(param_1 + 0x1c) = 1;
  return;
}



/* ===== FUN_0801035a @ 0801035a ===== */

/* WARNING: Removing unreachable block (ram,0x080271c8) */
/* WARNING: Removing unreachable block (ram,0x080271d2) */

void FUN_0801035a(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  iVar1 = FUN_080179f8(0x14);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_08017a98(iVar1,0,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = DAT_08018654;
  iVar3 = *(int *)(DAT_08018654 + 0x28);
  if (iVar3 == 0) {
    iVar7 = 0;
  }
  else {
    iVar7 = *(int *)(iVar3 + 0x10);
  }
  iVar9 = (int)*(char *)(param_1 + 0x15);
  *(undefined4 *)(param_1 + 0x10) = 0;
  iVar8 = iVar9;
  if (0 < iVar7) {
    iVar8 = *(int *)(param_1 + 0xc) / iVar7;
  }
  if ((0 < iVar8) && (iVar8 < iVar9)) {
    iVar9 = iVar8;
  }
  *(char *)(param_1 + 0x16) = (char)iVar9;
  if (iVar3 == 0) {
    return;
  }
  iVar1 = *(int *)(iVar1 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar1 + 9) = 1;
  *(undefined1 *)(iVar1 + 10) = 1;
  cVar6 = *(char *)(param_1 + 0x17);
  iVar1 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar7 = *(char *)(param_1 + 0x16) + -1;
    iVar8 = (int)cVar6;
    bVar10 = SBORROW4(iVar1,iVar8);
    iVar3 = iVar1 - iVar8;
    if (iVar8 <= iVar1) {
      iVar1 = iVar1 - iVar7;
      bVar10 = SBORROW4((int)cVar6,iVar1);
      iVar3 = cVar6 - iVar1;
    }
    if (iVar3 < 0 != bVar10) {
      cVar6 = (char)iVar1;
    }
    *(char *)(param_1 + 0x17) = cVar6;
    iVar1 = *(int *)(param_1 + 0x10);
    piVar4 = (int *)(DAT_08027214 + cVar6 * 4 + 0x28);
    iVar3 = 0;
    piVar5 = piVar4;
    while( true ) {
      iVar8 = *piVar5;
      *(int *)(iVar8 + 0xc) = iVar3;
      *(undefined1 *)(iVar8 + 10) = 1;
      if (piVar4 + iVar7 <= piVar5) break;
      iVar3 = iVar3 + *(int *)(*piVar5 + 0x10) + iVar1;
      piVar5 = piVar5 + 1;
    }
  }
  return;
}



/* ===== FUN_08011094 @ 08011094 ===== */

void FUN_08011094(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08011808;
  uVar3 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar3 = 0x3001;
  }
  FUN_08018b1c(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_08018b64(uVar3);
  FUN_080190f8(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_08018b64(uVar3 & 0xcfff | 8);
  if (*(int *)(DAT_0801180c + 100) << 0x1d < 0) {
    iVar2 = 0x40;
  }
  else {
    iVar2 = 0x4c;
  }
  FUN_080190f8(*(undefined4 *)(*piVar1 + iVar2));
  return;
}



/* ===== FUN_08011134 @ 08011134 ===== */

void FUN_08011134(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08011808;
  uVar3 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar3 = 0x3001;
  }
  FUN_08018b1c(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_08018b64(uVar3);
  FUN_080190f8(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_08018b64(uVar3 & 0xcfff | 8);
  if ((int)((uint)*(byte *)(DAT_0801180c + 100) << 0x1e) < 0) {
    iVar2 = 0x78;
  }
  else {
    iVar2 = 0x74;
  }
  FUN_080190f8(*(undefined4 *)(*piVar1 + iVar2));
  return;
}



/* ===== FUN_0801119a @ 0801119a ===== */

/* WARNING: Removing unreachable block (ram,0x080271c8) */
/* WARNING: Removing unreachable block (ram,0x080271d2) */

void FUN_0801119a(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  if (*(int *)(DAT_0801180c + 100) << 0x1d < 0) {
    iVar1 = FUN_080179f8(0x18);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = FUN_08019a50(iVar1,0x35,0xe,param_1);
    }
    FUN_08017a48(param_1,uVar2);
    iVar1 = FUN_080179f8(0x18);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = FUN_08019a80(iVar1,0x38,0xe,param_1);
    }
  }
  else {
    iVar1 = FUN_080179f8(0x18);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_080199f0(iVar1,0x35,0xe,param_1);
    }
    FUN_08017a48(param_1,uVar2);
    iVar1 = FUN_080179f8(0x18);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = FUN_08019a20(iVar1,0x38,0xe,param_1);
    }
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_08019990(iVar1,0x27,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_080199c0(iVar1,0x28,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = DAT_08018654;
  iVar3 = *(int *)(DAT_08018654 + 0x28);
  if (iVar3 == 0) {
    iVar7 = 2;
  }
  else {
    iVar7 = *(int *)(iVar3 + 0x10) + 2;
  }
  iVar9 = (int)*(char *)(param_1 + 0x15);
  *(undefined4 *)(param_1 + 0x10) = 2;
  iVar8 = iVar9;
  if (0 < iVar7) {
    iVar8 = (*(int *)(param_1 + 0xc) + 2) / iVar7;
  }
  if ((0 < iVar8) && (iVar8 < iVar9)) {
    iVar9 = iVar8;
  }
  *(char *)(param_1 + 0x16) = (char)iVar9;
  if (iVar3 == 0) {
    return;
  }
  iVar1 = *(int *)(iVar1 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar1 + 9) = 1;
  *(undefined1 *)(iVar1 + 10) = 1;
  cVar6 = *(char *)(param_1 + 0x17);
  iVar1 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar7 = *(char *)(param_1 + 0x16) + -1;
    iVar8 = (int)cVar6;
    bVar10 = SBORROW4(iVar1,iVar8);
    iVar3 = iVar1 - iVar8;
    if (iVar8 <= iVar1) {
      iVar1 = iVar1 - iVar7;
      bVar10 = SBORROW4((int)cVar6,iVar1);
      iVar3 = cVar6 - iVar1;
    }
    if (iVar3 < 0 != bVar10) {
      cVar6 = (char)iVar1;
    }
    *(char *)(param_1 + 0x17) = cVar6;
    iVar1 = *(int *)(param_1 + 0x10);
    piVar4 = (int *)(DAT_08027214 + cVar6 * 4 + 0x28);
    iVar3 = 0;
    piVar5 = piVar4;
    while( true ) {
      iVar8 = *piVar5;
      *(int *)(iVar8 + 0xc) = iVar3;
      *(undefined1 *)(iVar8 + 10) = 1;
      if (piVar4 + iVar7 <= piVar5) break;
      iVar3 = iVar3 + *(int *)(*piVar5 + 0x10) + iVar1;
      piVar5 = piVar5 + 1;
    }
  }
  return;
}



/* ===== FUN_08011866 @ 08011866 ===== */

void FUN_08011866(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  byte extraout_r2;
  int iVar4;
  int *piVar5;
  char cVar6;
  byte bVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  undefined4 uVar11;
  ulonglong uVar12;
  byte local_29 [13];
  undefined4 uStack_1c;
  
  uVar1 = DAT_080121f4;
  uVar12 = CONCAT44(param_4,param_3);
  pbVar9 = local_29 + 1;
  cVar6 = '\0';
  uStack_1c = param_4;
  while( true ) {
    iVar3 = (int)(uVar12 >> 0x20);
    if ((iVar3 == 0) && ((uint)uVar12 < uVar1)) break;
    uVar12 = FUN_08019bf4((uint)uVar12,iVar3,1000,0);
    cVar6 = cVar6 + '\x01';
  }
  uVar12 = uVar12 & 0xffffffff;
  while( true ) {
    uVar11 = (undefined4)(uVar12 >> 0x20);
    FUN_08019bf4((int)uVar12,uVar11,10,0);
    *pbVar9 = extraout_r2;
    uVar12 = FUN_08019bf4((int)uVar12,uVar11,10,0);
    if (uVar12 == 0) break;
    pbVar9 = pbVar9 + 1;
  }
  iVar3 = (int)pbVar9 - (int)(local_29 + 1);
  if ((int)((uint)*(byte *)(DAT_08012464 + 100) << 0x1f) < 0) {
    if (iVar3 < 2) {
      iVar4 = 0x30;
      pbVar8 = pbVar9;
    }
    else {
      pbVar8 = pbVar9 + -1;
      iVar4 = *pbVar9 + 0x30;
    }
    *param_1 = iVar4;
    if ((iVar3 < 3) || (iVar3 == 5 || iVar3 == 8)) {
      iVar4 = 0x2e;
      pbVar10 = pbVar8;
    }
    else {
      pbVar10 = pbVar8 + -1;
      iVar4 = *pbVar8 + 0x30;
    }
    param_1[1] = iVar4;
    pbVar8 = pbVar10;
    if (pbVar9 == local_29 + 1) {
      iVar4 = 0x30;
    }
    else if (iVar3 == 3 || iVar3 == 6) {
      iVar4 = 0x2e;
    }
    else {
      pbVar8 = pbVar10 + -1;
      iVar4 = *pbVar10 + 0x30;
    }
    param_1[2] = iVar4;
    if (iVar3 == 4 || iVar3 == 7) {
      iVar4 = 0x2e;
      pbVar9 = pbVar8;
    }
    else {
      pbVar9 = pbVar8 + -1;
      iVar4 = *pbVar8 + 0x30;
    }
    param_1[3] = iVar4;
    piVar5 = param_1 + 4;
    if (2 < iVar3) {
      piVar5 = param_1 + 5;
      param_1[4] = *pbVar9 + 0x30;
    }
    if (iVar3 < 5) {
      bVar7 = cVar6 + 1;
    }
    else if (iVar3 < 8) {
      bVar7 = cVar6 + 2;
    }
    else {
      bVar7 = cVar6 + 3;
    }
  }
  else {
    *param_1 = *pbVar9 + 0x30;
    piVar5 = param_1 + 1;
    if (pbVar9 != local_29 + 1) {
      if (iVar3 == 3 || iVar3 == 6) {
        iVar4 = 0x2e;
        pbVar8 = pbVar9 + -1;
      }
      else {
        pbVar8 = pbVar9 + -2;
        iVar4 = pbVar9[-1] + 0x30;
      }
      param_1[1] = iVar4;
      piVar5 = param_1 + 2;
      if (iVar3 != 1) {
        piVar5 = param_1 + 3;
        if (iVar3 == 4 || iVar3 == 7) {
          iVar4 = 0x2e;
          pbVar9 = pbVar8;
        }
        else {
          pbVar9 = pbVar8 + -1;
          iVar4 = *pbVar8 + 0x30;
        }
        param_1[2] = iVar4;
        if (iVar3 != 2) {
          if (iVar3 == 5 || iVar3 == 8) {
            iVar4 = 0x2e;
            pbVar8 = pbVar9;
          }
          else {
            pbVar8 = pbVar9 + -1;
            iVar4 = *pbVar9 + 0x30;
          }
          *piVar5 = iVar4;
          piVar5 = param_1 + 5;
          param_1[4] = *pbVar8 + 0x30;
          if (2 < iVar3) {
            if (iVar3 < 6) {
              bVar7 = cVar6 + 5;
            }
            else {
              bVar7 = cVar6 + 6;
            }
            goto LAB_080119aa;
          }
        }
      }
    }
    bVar7 = cVar6 + 4;
  }
LAB_080119aa:
  piVar2 = DAT_080125e4;
  *piVar5 = 0x20;
  FUN_08019ab0(piVar5 + 1,*(undefined4 *)(*piVar2 + (uint)bVar7 * 4));
  return;
}



/* ===== FUN_08011b50 @ 08011b50 ===== */

/* WARNING: Removing unreachable block (ram,0x080271c8) */
/* WARNING: Removing unreachable block (ram,0x080271d2) */

void FUN_08011b50(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  iVar1 = FUN_080179f8(0x18);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0801b140(iVar1,0x45,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_0801b170(iVar1,0x52,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_08019990(iVar1,0x27,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_080199c0(iVar1,0x28,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = DAT_08018654;
  iVar3 = *(int *)(DAT_08018654 + 0x28);
  if (iVar3 == 0) {
    iVar7 = 2;
  }
  else {
    iVar7 = *(int *)(iVar3 + 0x10) + 2;
  }
  iVar9 = (int)*(char *)(param_1 + 0x15);
  *(undefined4 *)(param_1 + 0x10) = 2;
  iVar8 = iVar9;
  if (0 < iVar7) {
    iVar8 = (*(int *)(param_1 + 0xc) + 2) / iVar7;
  }
  if ((0 < iVar8) && (iVar8 < iVar9)) {
    iVar9 = iVar8;
  }
  *(char *)(param_1 + 0x16) = (char)iVar9;
  if (iVar3 == 0) {
    return;
  }
  iVar1 = *(int *)(iVar1 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar1 + 9) = 1;
  *(undefined1 *)(iVar1 + 10) = 1;
  cVar6 = *(char *)(param_1 + 0x17);
  iVar1 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar7 = *(char *)(param_1 + 0x16) + -1;
    iVar8 = (int)cVar6;
    bVar10 = SBORROW4(iVar1,iVar8);
    iVar3 = iVar1 - iVar8;
    if (iVar8 <= iVar1) {
      iVar1 = iVar1 - iVar7;
      bVar10 = SBORROW4((int)cVar6,iVar1);
      iVar3 = cVar6 - iVar1;
    }
    if (iVar3 < 0 != bVar10) {
      cVar6 = (char)iVar1;
    }
    *(char *)(param_1 + 0x17) = cVar6;
    iVar1 = *(int *)(param_1 + 0x10);
    piVar4 = (int *)(DAT_08027214 + cVar6 * 4 + 0x28);
    iVar3 = 0;
    piVar5 = piVar4;
    while( true ) {
      iVar8 = *piVar5;
      *(int *)(iVar8 + 0xc) = iVar3;
      *(undefined1 *)(iVar8 + 10) = 1;
      if (piVar4 + iVar7 <= piVar5) break;
      iVar3 = iVar3 + *(int *)(*piVar5 + 0x10) + iVar1;
      piVar5 = piVar5 + 1;
    }
  }
  return;
}



/* ===== FUN_08012544 @ 08012544 ===== */

void FUN_08012544(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_080125e4;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08018b1c(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_08018b64(uVar2);
  FUN_080190f8(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_08018b64(uVar2 & 0xcfff | 8);
  FUN_080190f8(*(undefined4 *)
                (*piVar1 + ((*(uint *)(DAT_08013080 + 100) & 0x3fffff) >> 0x15) * 4 + 0x1b8));
  return;
}



/* ===== FUN_080125e8 @ 080125e8 ===== */

/* WARNING: Removing unreachable block (ram,0x080271c8) */
/* WARNING: Removing unreachable block (ram,0x080271d2) */

void FUN_080125e8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  iVar1 = FUN_080179f8(0x18);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0801ba30(iVar1,0x2c,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_0801ba60(iVar1,0x2f,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_0801ba90(iVar1,0x30,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_0801bac0(iVar1,0x31,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_08019990(iVar1,0x27,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_080199c0(iVar1,0x28,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = DAT_08018654;
  iVar3 = *(int *)(DAT_08018654 + 0x28);
  if (iVar3 == 0) {
    iVar7 = 2;
  }
  else {
    iVar7 = *(int *)(iVar3 + 0x10) + 2;
  }
  iVar9 = (int)*(char *)(param_1 + 0x15);
  *(undefined4 *)(param_1 + 0x10) = 2;
  iVar8 = iVar9;
  if (0 < iVar7) {
    iVar8 = (*(int *)(param_1 + 0xc) + 2) / iVar7;
  }
  if ((0 < iVar8) && (iVar8 < iVar9)) {
    iVar9 = iVar8;
  }
  *(char *)(param_1 + 0x16) = (char)iVar9;
  if (iVar3 == 0) {
    return;
  }
  iVar1 = *(int *)(iVar1 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar1 + 9) = 1;
  *(undefined1 *)(iVar1 + 10) = 1;
  cVar6 = *(char *)(param_1 + 0x17);
  iVar1 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar7 = *(char *)(param_1 + 0x16) + -1;
    iVar8 = (int)cVar6;
    bVar10 = SBORROW4(iVar1,iVar8);
    iVar3 = iVar1 - iVar8;
    if (iVar8 <= iVar1) {
      iVar1 = iVar1 - iVar7;
      bVar10 = SBORROW4((int)cVar6,iVar1);
      iVar3 = cVar6 - iVar1;
    }
    if (iVar3 < 0 != bVar10) {
      cVar6 = (char)iVar1;
    }
    *(char *)(param_1 + 0x17) = cVar6;
    iVar1 = *(int *)(param_1 + 0x10);
    piVar4 = (int *)(DAT_08027214 + cVar6 * 4 + 0x28);
    iVar3 = 0;
    piVar5 = piVar4;
    while( true ) {
      iVar8 = *piVar5;
      *(int *)(iVar8 + 0xc) = iVar3;
      *(undefined1 *)(iVar8 + 10) = 1;
      if (piVar4 + iVar7 <= piVar5) break;
      iVar3 = iVar3 + *(int *)(*piVar5 + 0x10) + iVar1;
      piVar5 = piVar5 + 1;
    }
  }
  return;
}



/* ===== FUN_08012920 @ 08012920 ===== */

void FUN_08012920(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_080131fc;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08018b1c(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_08018b64(uVar2);
  FUN_080190f8(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_08018b64(uVar2 & 0xcfff | 8);
  FUN_080190f8(*(undefined4 *)
                (*piVar1 + ((*(uint *)(DAT_08013080 + 100) & 0xffffff) >> 0x17) * 4 + 0x1b8));
  return;
}



/* ===== FUN_080129c0 @ 080129c0 ===== */

/* WARNING: Removing unreachable block (ram,0x080271c8) */
/* WARNING: Removing unreachable block (ram,0x080271d2) */

void FUN_080129c0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  iVar1 = FUN_080179f8(0x18);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0801bc58(iVar1,0x5c,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_0801bc88(iVar1,0x5e,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_08019990(iVar1,0x27,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_080199c0(iVar1,0x28,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = DAT_08018654;
  iVar3 = *(int *)(DAT_08018654 + 0x28);
  if (iVar3 == 0) {
    iVar7 = 2;
  }
  else {
    iVar7 = *(int *)(iVar3 + 0x10) + 2;
  }
  iVar9 = (int)*(char *)(param_1 + 0x15);
  *(undefined4 *)(param_1 + 0x10) = 2;
  iVar8 = iVar9;
  if (0 < iVar7) {
    iVar8 = (*(int *)(param_1 + 0xc) + 2) / iVar7;
  }
  if ((0 < iVar8) && (iVar8 < iVar9)) {
    iVar9 = iVar8;
  }
  *(char *)(param_1 + 0x16) = (char)iVar9;
  if (iVar3 == 0) {
    return;
  }
  iVar1 = *(int *)(iVar1 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar1 + 9) = 1;
  *(undefined1 *)(iVar1 + 10) = 1;
  cVar6 = *(char *)(param_1 + 0x17);
  iVar1 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar7 = *(char *)(param_1 + 0x16) + -1;
    iVar8 = (int)cVar6;
    bVar10 = SBORROW4(iVar1,iVar8);
    iVar3 = iVar1 - iVar8;
    if (iVar8 <= iVar1) {
      iVar1 = iVar1 - iVar7;
      bVar10 = SBORROW4((int)cVar6,iVar1);
      iVar3 = cVar6 - iVar1;
    }
    if (iVar3 < 0 != bVar10) {
      cVar6 = (char)iVar1;
    }
    *(char *)(param_1 + 0x17) = cVar6;
    iVar1 = *(int *)(param_1 + 0x10);
    piVar4 = (int *)(DAT_08027214 + cVar6 * 4 + 0x28);
    iVar3 = 0;
    piVar5 = piVar4;
    while( true ) {
      iVar8 = *piVar5;
      *(int *)(iVar8 + 0xc) = iVar3;
      *(undefined1 *)(iVar8 + 10) = 1;
      if (piVar4 + iVar7 <= piVar5) break;
      iVar3 = iVar3 + *(int *)(*piVar5 + 0x10) + iVar1;
      piVar5 = piVar5 + 1;
    }
  }
  return;
}



/* ===== FUN_080129f8 @ 080129f8 ===== */

void FUN_080129f8(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_080131fc;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08018b1c(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_08018b64(uVar2);
  FUN_080190f8(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_08018b64(uVar2 & 0xcfff | 8);
  FUN_080190f8(*(undefined4 *)
                (*piVar1 + ((*(uint *)(DAT_08013080 + 100) & 0x1fff) >> 0xc) * 4 + 0x1b8));
  return;
}



/* ===== FUN_08012aa4 @ 08012aa4 ===== */

void FUN_08012aa4(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_080131fc;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08018b1c(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_08018b64(uVar2);
  FUN_080190f8(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_08018b64(uVar2 & 0xcfff | 8);
  FUN_080190f8(*(undefined4 *)(*piVar1 + ((*(int *)(DAT_08013080 + 100) << 7) >> 0x1f) * -4 + 0x1b8)
              );
  return;
}



/* ===== FUN_08012e70 @ 08012e70 ===== */

void FUN_08012e70(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_080131fc;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08018b1c(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_08018b64(uVar2);
  FUN_080190f8(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_08018b64(uVar2 & 0xcfff | 8);
  FUN_080190f8(*(undefined4 *)(*piVar1 + ((*(int *)(DAT_08013080 + 100) << 5) >> 0x1f) * -4 + 0x1b8)
              );
  return;
}



/* ===== FUN_08012f0c @ 08012f0c ===== */

/* WARNING: Removing unreachable block (ram,0x080271c8) */
/* WARNING: Removing unreachable block (ram,0x080271d2) */

void FUN_08012f0c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  iVar1 = FUN_080179f8(0x18);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0801be44(iVar1,0x5c,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_0801be74(iVar1,0x5e,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_08019990(iVar1,0x27,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_080199c0(iVar1,0x28,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = DAT_08018654;
  iVar3 = *(int *)(DAT_08018654 + 0x28);
  if (iVar3 == 0) {
    iVar7 = 2;
  }
  else {
    iVar7 = *(int *)(iVar3 + 0x10) + 2;
  }
  iVar9 = (int)*(char *)(param_1 + 0x15);
  *(undefined4 *)(param_1 + 0x10) = 2;
  iVar8 = iVar9;
  if (0 < iVar7) {
    iVar8 = (*(int *)(param_1 + 0xc) + 2) / iVar7;
  }
  if ((0 < iVar8) && (iVar8 < iVar9)) {
    iVar9 = iVar8;
  }
  *(char *)(param_1 + 0x16) = (char)iVar9;
  if (iVar3 == 0) {
    return;
  }
  iVar1 = *(int *)(iVar1 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar1 + 9) = 1;
  *(undefined1 *)(iVar1 + 10) = 1;
  cVar6 = *(char *)(param_1 + 0x17);
  iVar1 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar7 = *(char *)(param_1 + 0x16) + -1;
    iVar8 = (int)cVar6;
    bVar10 = SBORROW4(iVar1,iVar8);
    iVar3 = iVar1 - iVar8;
    if (iVar8 <= iVar1) {
      iVar1 = iVar1 - iVar7;
      bVar10 = SBORROW4((int)cVar6,iVar1);
      iVar3 = cVar6 - iVar1;
    }
    if (iVar3 < 0 != bVar10) {
      cVar6 = (char)iVar1;
    }
    *(char *)(param_1 + 0x17) = cVar6;
    iVar1 = *(int *)(param_1 + 0x10);
    piVar4 = (int *)(DAT_08027214 + cVar6 * 4 + 0x28);
    iVar3 = 0;
    piVar5 = piVar4;
    while( true ) {
      iVar8 = *piVar5;
      *(int *)(iVar8 + 0xc) = iVar3;
      *(undefined1 *)(iVar8 + 10) = 1;
      if (piVar4 + iVar7 <= piVar5) break;
      iVar3 = iVar3 + *(int *)(*piVar5 + 0x10) + iVar1;
      piVar5 = piVar5 + 1;
    }
  }
  return;
}



/* ===== FUN_08012f44 @ 08012f44 ===== */

void FUN_08012f44(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_080131fc;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08018b1c(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_08018b64(uVar2);
  FUN_080190f8(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_08018b64(uVar2 & 0xcfff | 8);
  FUN_080190f8(*(undefined4 *)
                (*piVar1 + ((*(int *)(DAT_08013c2c + 100) << 0x10) >> 0x1f) * -4 + 0x1b8));
  return;
}



/* ===== FUN_08012fe2 @ 08012fe2 ===== */

void FUN_08012fe2(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_080131fc;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08018b1c(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_08018b64(uVar2);
  FUN_080190f8(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_08018b64(uVar2 & 0xcfff | 8);
  FUN_080190f8(*(undefined4 *)(*piVar1 + ((*(int *)(DAT_08013c2c + 100) << 4) >> 0x1f) * -4 + 0x1b8)
              );
  return;
}



/* ===== FUN_08013084 @ 08013084 ===== */

/* WARNING: Removing unreachable block (ram,0x080271c8) */
/* WARNING: Removing unreachable block (ram,0x080271d2) */

void FUN_08013084(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  iVar1 = FUN_080179f8(0x18);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0801bea4(iVar1,0x5c,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_0801bed4(iVar1,0x5e,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_08019990(iVar1,0x27,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_080199c0(iVar1,0x28,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = DAT_08018654;
  iVar3 = *(int *)(DAT_08018654 + 0x28);
  if (iVar3 == 0) {
    iVar7 = 2;
  }
  else {
    iVar7 = *(int *)(iVar3 + 0x10) + 2;
  }
  iVar9 = (int)*(char *)(param_1 + 0x15);
  *(undefined4 *)(param_1 + 0x10) = 2;
  iVar8 = iVar9;
  if (0 < iVar7) {
    iVar8 = (*(int *)(param_1 + 0xc) + 2) / iVar7;
  }
  if ((0 < iVar8) && (iVar8 < iVar9)) {
    iVar9 = iVar8;
  }
  *(char *)(param_1 + 0x16) = (char)iVar9;
  if (iVar3 == 0) {
    return;
  }
  iVar1 = *(int *)(iVar1 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar1 + 9) = 1;
  *(undefined1 *)(iVar1 + 10) = 1;
  cVar6 = *(char *)(param_1 + 0x17);
  iVar1 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar7 = *(char *)(param_1 + 0x16) + -1;
    iVar8 = (int)cVar6;
    bVar10 = SBORROW4(iVar1,iVar8);
    iVar3 = iVar1 - iVar8;
    if (iVar8 <= iVar1) {
      iVar1 = iVar1 - iVar7;
      bVar10 = SBORROW4((int)cVar6,iVar1);
      iVar3 = cVar6 - iVar1;
    }
    if (iVar3 < 0 != bVar10) {
      cVar6 = (char)iVar1;
    }
    *(char *)(param_1 + 0x17) = cVar6;
    iVar1 = *(int *)(param_1 + 0x10);
    piVar4 = (int *)(DAT_08027214 + cVar6 * 4 + 0x28);
    iVar3 = 0;
    piVar5 = piVar4;
    while( true ) {
      iVar8 = *piVar5;
      *(int *)(iVar8 + 0xc) = iVar3;
      *(undefined1 *)(iVar8 + 10) = 1;
      if (piVar4 + iVar7 <= piVar5) break;
      iVar3 = iVar3 + *(int *)(*piVar5 + 0x10) + iVar1;
      piVar5 = piVar5 + 1;
    }
  }
  return;
}



/* ===== FUN_0801315c @ 0801315c ===== */

void FUN_0801315c(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_080131fc;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08018b1c(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_08018b64(uVar2);
  FUN_080190f8(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_08018b64(uVar2 & 0xcfff | 8);
  FUN_080190f8(*(undefined4 *)(*piVar1 + ((*(int *)(DAT_08013c2c + 100) << 3) >> 0x1f) * -4 + 0x1b8)
              );
  return;
}



/* ===== FUN_08013200 @ 08013200 ===== */

/* WARNING: Removing unreachable block (ram,0x080271c8) */
/* WARNING: Removing unreachable block (ram,0x080271d2) */

void FUN_08013200(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  iVar1 = FUN_080179f8(0x18);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0801bf04(iVar1,0x35,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_0801bf34(iVar1,0x38,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_0801bf64(iVar1,0x3b,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_08019990(iVar1,0x27,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_080199c0(iVar1,0x28,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = DAT_08018654;
  iVar3 = *(int *)(DAT_08018654 + 0x28);
  if (iVar3 == 0) {
    iVar7 = 2;
  }
  else {
    iVar7 = *(int *)(iVar3 + 0x10) + 2;
  }
  iVar9 = (int)*(char *)(param_1 + 0x15);
  *(undefined4 *)(param_1 + 0x10) = 2;
  iVar8 = iVar9;
  if (0 < iVar7) {
    iVar8 = (*(int *)(param_1 + 0xc) + 2) / iVar7;
  }
  if ((0 < iVar8) && (iVar8 < iVar9)) {
    iVar9 = iVar8;
  }
  *(char *)(param_1 + 0x16) = (char)iVar9;
  if (iVar3 == 0) {
    return;
  }
  iVar1 = *(int *)(iVar1 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar1 + 9) = 1;
  *(undefined1 *)(iVar1 + 10) = 1;
  cVar6 = *(char *)(param_1 + 0x17);
  iVar1 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar7 = *(char *)(param_1 + 0x16) + -1;
    iVar8 = (int)cVar6;
    bVar10 = SBORROW4(iVar1,iVar8);
    iVar3 = iVar1 - iVar8;
    if (iVar8 <= iVar1) {
      iVar1 = iVar1 - iVar7;
      bVar10 = SBORROW4((int)cVar6,iVar1);
      iVar3 = cVar6 - iVar1;
    }
    if (iVar3 < 0 != bVar10) {
      cVar6 = (char)iVar1;
    }
    *(char *)(param_1 + 0x17) = cVar6;
    iVar1 = *(int *)(param_1 + 0x10);
    piVar4 = (int *)(DAT_08027214 + cVar6 * 4 + 0x28);
    iVar3 = 0;
    piVar5 = piVar4;
    while( true ) {
      iVar8 = *piVar5;
      *(int *)(iVar8 + 0xc) = iVar3;
      *(undefined1 *)(iVar8 + 10) = 1;
      if (piVar4 + iVar7 <= piVar5) break;
      iVar3 = iVar3 + *(int *)(*piVar5 + 0x10) + iVar1;
      piVar5 = piVar5 + 1;
    }
  }
  return;
}



/* ===== FUN_080133ac @ 080133ac ===== */

void FUN_080133ac(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08013dc4;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08018b1c(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_08018b64(uVar2);
  FUN_080190f8(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_08018b64(uVar2 & 0xcfff | 8);
  FUN_080190f8(*(undefined4 *)(*piVar1 + ((*(int *)(DAT_08013c2c + 100) << 2) >> 0x1f) * -4 + 0x1b8)
              );
  return;
}



/* ===== FUN_08013450 @ 08013450 ===== */

/* WARNING: Removing unreachable block (ram,0x080271c8) */
/* WARNING: Removing unreachable block (ram,0x080271d2) */

void FUN_08013450(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  iVar1 = FUN_080179f8(0x18);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0801c030(iVar1,0x5c,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_0801c060(iVar1,0x5e,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_08019990(iVar1,0x27,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_080199c0(iVar1,0x28,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = DAT_08018654;
  iVar3 = *(int *)(DAT_08018654 + 0x28);
  if (iVar3 == 0) {
    iVar7 = 2;
  }
  else {
    iVar7 = *(int *)(iVar3 + 0x10) + 2;
  }
  iVar9 = (int)*(char *)(param_1 + 0x15);
  *(undefined4 *)(param_1 + 0x10) = 2;
  iVar8 = iVar9;
  if (0 < iVar7) {
    iVar8 = (*(int *)(param_1 + 0xc) + 2) / iVar7;
  }
  if ((0 < iVar8) && (iVar8 < iVar9)) {
    iVar9 = iVar8;
  }
  *(char *)(param_1 + 0x16) = (char)iVar9;
  if (iVar3 == 0) {
    return;
  }
  iVar1 = *(int *)(iVar1 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar1 + 9) = 1;
  *(undefined1 *)(iVar1 + 10) = 1;
  cVar6 = *(char *)(param_1 + 0x17);
  iVar1 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar7 = *(char *)(param_1 + 0x16) + -1;
    iVar8 = (int)cVar6;
    bVar10 = SBORROW4(iVar1,iVar8);
    iVar3 = iVar1 - iVar8;
    if (iVar8 <= iVar1) {
      iVar1 = iVar1 - iVar7;
      bVar10 = SBORROW4((int)cVar6,iVar1);
      iVar3 = cVar6 - iVar1;
    }
    if (iVar3 < 0 != bVar10) {
      cVar6 = (char)iVar1;
    }
    *(char *)(param_1 + 0x17) = cVar6;
    iVar1 = *(int *)(param_1 + 0x10);
    piVar4 = (int *)(DAT_08027214 + cVar6 * 4 + 0x28);
    iVar3 = 0;
    piVar5 = piVar4;
    while( true ) {
      iVar8 = *piVar5;
      *(int *)(iVar8 + 0xc) = iVar3;
      *(undefined1 *)(iVar8 + 10) = 1;
      if (piVar4 + iVar7 <= piVar5) break;
      iVar3 = iVar3 + *(int *)(*piVar5 + 0x10) + iVar1;
      piVar5 = piVar5 + 1;
    }
  }
  return;
}



/* ===== FUN_08013488 @ 08013488 ===== */

void FUN_08013488(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08013dc4;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08018b1c(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_08018b64(uVar2);
  FUN_080190f8(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_08018b64(uVar2 & 0xcfff | 8);
  FUN_080190f8(*(undefined4 *)
                (*piVar1 + ((*(int *)(DAT_08013c2c + 100) << 0xd) >> 0x1f) * -4 + 0x1b8));
  return;
}



/* ===== FUN_0801352c @ 0801352c ===== */

void FUN_0801352c(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08013dc4;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08018b1c(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_08018b64(uVar2);
  FUN_080190f8(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_08018b64(uVar2 & 0xcfff | 8);
  FUN_080190f8(*(undefined4 *)(*piVar1 + ((*(int *)(DAT_08013c2c + 100) << 1) >> 0x1f) * -4 + 0x1b8)
              );
  return;
}



/* ===== FUN_080135d0 @ 080135d0 ===== */

/* WARNING: Removing unreachable block (ram,0x080271c8) */
/* WARNING: Removing unreachable block (ram,0x080271d2) */

void FUN_080135d0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  iVar1 = FUN_080179f8(0x18);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0801c090(iVar1,0x5c,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_0801c0c0(iVar1,0x5e,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_08019990(iVar1,0x27,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_080199c0(iVar1,0x28,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = DAT_08018654;
  iVar3 = *(int *)(DAT_08018654 + 0x28);
  if (iVar3 == 0) {
    iVar7 = 2;
  }
  else {
    iVar7 = *(int *)(iVar3 + 0x10) + 2;
  }
  iVar9 = (int)*(char *)(param_1 + 0x15);
  *(undefined4 *)(param_1 + 0x10) = 2;
  iVar8 = iVar9;
  if (0 < iVar7) {
    iVar8 = (*(int *)(param_1 + 0xc) + 2) / iVar7;
  }
  if ((0 < iVar8) && (iVar8 < iVar9)) {
    iVar9 = iVar8;
  }
  *(char *)(param_1 + 0x16) = (char)iVar9;
  if (iVar3 == 0) {
    return;
  }
  iVar1 = *(int *)(iVar1 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar1 + 9) = 1;
  *(undefined1 *)(iVar1 + 10) = 1;
  cVar6 = *(char *)(param_1 + 0x17);
  iVar1 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar7 = *(char *)(param_1 + 0x16) + -1;
    iVar8 = (int)cVar6;
    bVar10 = SBORROW4(iVar1,iVar8);
    iVar3 = iVar1 - iVar8;
    if (iVar8 <= iVar1) {
      iVar1 = iVar1 - iVar7;
      bVar10 = SBORROW4((int)cVar6,iVar1);
      iVar3 = cVar6 - iVar1;
    }
    if (iVar3 < 0 != bVar10) {
      cVar6 = (char)iVar1;
    }
    *(char *)(param_1 + 0x17) = cVar6;
    iVar1 = *(int *)(param_1 + 0x10);
    piVar4 = (int *)(DAT_08027214 + cVar6 * 4 + 0x28);
    iVar3 = 0;
    piVar5 = piVar4;
    while( true ) {
      iVar8 = *piVar5;
      *(int *)(iVar8 + 0xc) = iVar3;
      *(undefined1 *)(iVar8 + 10) = 1;
      if (piVar4 + iVar7 <= piVar5) break;
      iVar3 = iVar3 + *(int *)(*piVar5 + 0x10) + iVar1;
      piVar5 = piVar5 + 1;
    }
  }
  return;
}



/* ===== FUN_08013608 @ 08013608 ===== */

void FUN_08013608(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08013dc4;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08018b1c(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_08018b64(uVar2);
  FUN_080190f8(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_08018b64(uVar2 & 0xcfff | 8);
  FUN_080190f8(*(undefined4 *)
                (*piVar1 + ((*(int *)(DAT_08013c2c + 100) << 0xc) >> 0x1f) * -4 + 0x1b8));
  return;
}



/* ===== FUN_080136ac @ 080136ac ===== */

void FUN_080136ac(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  *(undefined1 *)(param_1 + 10) = 0;
  piVar1 = DAT_08013dc4;
  uVar2 = 0x3000;
  if (*(char *)(param_1 + 9) != '\0') {
    uVar2 = 0x3001;
  }
  FUN_08018b1c(*(uint *)(param_1 + 0x14) & 0xff,
               (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc)) - 1U & 0xff);
  FUN_08018b64(uVar2);
  FUN_080190f8(*(undefined4 *)(*piVar1 + (uint)*(byte *)(param_1 + 8) * 4));
  FUN_08018b64(uVar2 & 0xcfff | 8);
  FUN_080190f8(*(undefined4 *)(*piVar1 + (*(int *)(DAT_08013c2c + 100) >> 0x1f) * -4 + 0x1b8));
  return;
}



/* ===== FUN_08013746 @ 08013746 ===== */

undefined8 FUN_08013746(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ulonglong uVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  char cVar11;
  char cVar12;
  char *pcVar13;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_28 = param_3;
  uStack_24 = param_4;
  FUN_08015d88(0x35);
  piVar7 = *(int **)(*DAT_08013dc4 + 0x108);
  cVar12 = '\x19';
  *(undefined1 *)(param_1 + 0x9f) = 0;
  *(int **)(param_1 + 0xa0) = piVar7;
  cVar11 = '\0';
  piVar9 = (int *)(param_1 + 0x1c);
LAB_0801377c:
  while( true ) {
    piVar8 = piVar7;
    piVar7 = piVar8 + 1;
    iVar4 = *piVar8;
    if (iVar4 == 0x3c) goto LAB_08013770;
    if (iVar4 != 0x3e) break;
    if (*piVar7 == 0x3e) goto LAB_08013776;
  }
  if (iVar4 == 0) {
    *piVar9 = 0;
    bVar3 = FUN_0801c174(param_1 + 0x1c);
    if (bVar3 < 0x81) {
      cVar11 = (char)(0x80 - bVar3 >> 1);
    }
    else {
      bVar3 = 0x80;
    }
    *(char *)(param_1 + 0x9e) = cVar11;
    *(char *)(param_1 + 0x9c) = cVar11;
    *(byte *)(param_1 + 0x9d) = bVar3 + cVar11 + -1;
    iVar2 = DAT_080146e0;
    iVar4 = DAT_0801441c;
    for (uVar5 = *(uint *)(DAT_08013c2c + 0x50); 9999 < uVar5;
        uVar5 = (uint)((ulonglong)uVar5 * (ulonglong)DAT_080146bc >> 0x29)) {
      cVar12 = cVar12 + '\x01';
    }
    for (pcVar13 = (char *)((int)&uStack_24 + 3); &uStack_24 <= pcVar13; pcVar13 = pcVar13 + -1) {
      uVar1 = (ulonglong)uVar5 * (ulonglong)DAT_080146dc >> 0x23;
      *pcVar13 = (char)uVar5 + (char)uVar1 * -10;
      uVar5 = (uint)uVar1;
    }
    iVar10 = 4;
    do {
      FUN_0801d5c8(param_1,&uStack_28);
      piVar7 = (int *)FUN_080179f8(0x1c);
      if (piVar7 == (int *)0x0) {
        piVar7 = (int *)0x0;
      }
      else {
        pcVar13 = pcVar13 + 1;
        FUN_0801d688(piVar7,param_1,&uStack_28,*pcVar13);
        *piVar7 = iVar2 + 8;
      }
      cVar11 = *(char *)(param_1 + 0x15);
      if (cVar11 != 0x10) {
        *(int **)(iVar4 + cVar11 * 4 + 0x28) = piVar7;
        *(char *)(param_1 + 0x15) = cVar11 + '\x01';
      }
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    FUN_0801d5c8(param_1,&uStack_28);
    puVar6 = (undefined4 *)FUN_080179f8(0x1c);
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      FUN_0801d688(puVar6,param_1,&uStack_28,cVar12);
      *puVar6 = DAT_080147b0;
    }
    FUN_08017a48(param_1,puVar6);
    FUN_0801692c(param_1,0,1);
    return CONCAT44(uStack_24,uStack_28);
  }
  goto LAB_08013778;
LAB_08013770:
  if (*piVar7 == 0x3c) {
LAB_08013776:
    piVar7 = piVar8 + 2;
LAB_08013778:
    *piVar9 = iVar4;
    piVar9 = piVar9 + 1;
  }
  goto LAB_0801377c;
}



/* ===== FUN_08013c30 @ 08013c30 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08013c30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ulonglong uVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  char cVar11;
  char *pcVar12;
  char cVar13;
  char cVar14;
  undefined1 auStack_30 [4];
  char acStack_2c [5];
  char acStack_27 [3];
  undefined4 uStack_24;
  
  uStack_24 = param_4;
  FUN_08015d88(0x35);
  iVar10 = _LAB_080147bc;
  cVar13 = '\x17';
  if ((int)((uint)*(byte *)(_LAB_080147bc + 100) << 0x1f) < 0) {
    piVar7 = *(int **)(*DAT_08013dc4 + 0xf8);
    *(int **)(param_1 + 0xa0) = piVar7;
    *(undefined1 *)(param_1 + 0x9f) = 0;
    cVar14 = '\0';
    piVar9 = (int *)(param_1 + 0x1c);
LAB_08013cd0:
    while( true ) {
      piVar8 = piVar7;
      piVar7 = piVar8 + 1;
      iVar4 = *piVar8;
      if (iVar4 == 0x3c) goto LAB_08013cc4;
      if (iVar4 != 0x3e) break;
      if (*piVar7 == 0x3e) goto LAB_08013cca;
    }
    if (iVar4 != 0) goto LAB_08013ccc;
    *piVar9 = 0;
    bVar3 = FUN_0801c174(param_1 + 0x1c);
    if (bVar3 < 0x81) {
      cVar14 = (char)(0x80 - bVar3 >> 1);
    }
    else {
      bVar3 = 0x80;
    }
    cVar11 = bVar3 + cVar14;
  }
  else {
    piVar7 = *(int **)(*DAT_08013dc4 + 0xfc);
    *(int **)(param_1 + 0xa0) = piVar7;
    *(undefined1 *)(param_1 + 0x9f) = 0;
    cVar14 = '\0';
    piVar9 = (int *)(param_1 + 0x1c);
LAB_08013c72:
    while( true ) {
      piVar8 = piVar7;
      piVar7 = piVar8 + 1;
      iVar4 = *piVar8;
      if (iVar4 == 0x3c) goto LAB_08013c66;
      if (iVar4 != 0x3e) break;
      if (*piVar7 == 0x3e) goto LAB_08013c6c;
    }
    if (iVar4 != 0) goto LAB_08013c6e;
    *piVar9 = 0;
    bVar3 = FUN_0801c174(param_1 + 0x1c);
    if (bVar3 < 0x81) {
      cVar14 = (char)(0x80 - bVar3 >> 1);
    }
    else {
      bVar3 = 0x80;
    }
    cVar11 = bVar3 + cVar14;
  }
  *(char *)(param_1 + 0x9c) = cVar14;
  *(char *)(param_1 + 0x9d) = cVar11 + -1;
  *(char *)(param_1 + 0x9e) = cVar14;
  iVar2 = DAT_080146e0;
  iVar4 = DAT_0801441c;
  for (uVar5 = *(uint *)(iVar10 + 0x40); _LAB_080147c4 <= uVar5;
      uVar5 = (uint)((ulonglong)uVar5 * (ulonglong)DAT_080146bc >> 0x29)) {
    cVar13 = cVar13 + '\x01';
  }
  for (pcVar12 = acStack_2c + 4; acStack_2c <= pcVar12; pcVar12 = pcVar12 + -1) {
    uVar1 = (ulonglong)uVar5 * (ulonglong)DAT_080146dc >> 0x23;
    *pcVar12 = (char)uVar5 + (char)uVar1 * -10;
    uVar5 = (uint)uVar1;
  }
  iVar10 = 5;
  do {
    FUN_0801d5c8(param_1,auStack_30);
    piVar7 = (int *)FUN_080179f8(0x1c);
    if (piVar7 == (int *)0x0) {
      piVar7 = (int *)0x0;
    }
    else {
      pcVar12 = pcVar12 + 1;
      FUN_0801d688(piVar7,param_1,auStack_30,*pcVar12);
      *piVar7 = iVar2 + 8;
    }
    cVar14 = *(char *)(param_1 + 0x15);
    if (cVar14 != 0x10) {
      *(int **)(iVar4 + cVar14 * 4 + 0x28) = piVar7;
      *(char *)(param_1 + 0x15) = cVar14 + '\x01';
    }
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  FUN_0801d5c8(param_1,auStack_30);
  puVar6 = (undefined4 *)FUN_080179f8(0x1c);
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    FUN_0801d688(puVar6,param_1,auStack_30,cVar13);
    *puVar6 = _LAB_080147c8;
  }
  FUN_08017a48(param_1,puVar6);
  FUN_0801692c(param_1,0,1);
  return;
LAB_08013cc4:
  if (*piVar7 == 0x3c) {
LAB_08013cca:
    piVar7 = piVar8 + 2;
LAB_08013ccc:
    *piVar9 = iVar4;
    piVar9 = piVar9 + 1;
  }
  goto LAB_08013cd0;
LAB_08013c66:
  if (*piVar7 == 0x3c) {
LAB_08013c6c:
    piVar7 = piVar8 + 2;
LAB_08013c6e:
    *piVar9 = iVar4;
    piVar9 = piVar9 + 1;
  }
  goto LAB_08013c72;
}



/* ===== FUN_08013dc8 @ 08013dc8 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08013dc8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ulonglong uVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  char cVar11;
  char *pcVar12;
  char cVar13;
  char cVar14;
  undefined1 auStack_30 [4];
  char acStack_2c [5];
  char acStack_27 [3];
  undefined4 uStack_24;
  
  uStack_24 = param_4;
  FUN_08015d88(0x38);
  iVar10 = _LAB_080147bc;
  cVar13 = '\x17';
  if ((int)((uint)*(byte *)(_LAB_080147bc + 100) << 0x1f) < 0) {
    piVar7 = *(int **)(*_LAB_080147c0 + 0xf8);
    *(int **)(param_1 + 0xa0) = piVar7;
    *(undefined1 *)(param_1 + 0x9f) = 0;
    cVar14 = '\0';
    piVar9 = (int *)(param_1 + 0x1c);
LAB_08013e6a:
    while( true ) {
      piVar8 = piVar7;
      piVar7 = piVar8 + 1;
      iVar4 = *piVar8;
      if (iVar4 == 0x3c) goto LAB_08013e5e;
      if (iVar4 != 0x3e) break;
      if (*piVar7 == 0x3e) goto LAB_08013e64;
    }
    if (iVar4 != 0) goto LAB_08013e66;
    *piVar9 = 0;
    bVar3 = FUN_0801c174(param_1 + 0x1c);
    if (bVar3 < 0x81) {
      cVar14 = (char)(0x80 - bVar3 >> 1);
    }
    else {
      bVar3 = 0x80;
    }
    cVar11 = bVar3 + cVar14;
  }
  else {
    piVar7 = *(int **)(*_LAB_080147c0 + 0xfc);
    *(int **)(param_1 + 0xa0) = piVar7;
    *(undefined1 *)(param_1 + 0x9f) = 0;
    cVar14 = '\0';
    piVar9 = (int *)(param_1 + 0x1c);
LAB_08013e0c:
    while( true ) {
      piVar8 = piVar7;
      piVar7 = piVar8 + 1;
      iVar4 = *piVar8;
      if (iVar4 == 0x3c) goto LAB_08013e00;
      if (iVar4 != 0x3e) break;
      if (*piVar7 == 0x3e) goto LAB_08013e06;
    }
    if (iVar4 != 0) goto LAB_08013e08;
    *piVar9 = 0;
    bVar3 = FUN_0801c174(param_1 + 0x1c);
    if (bVar3 < 0x81) {
      cVar14 = (char)(0x80 - bVar3 >> 1);
    }
    else {
      bVar3 = 0x80;
    }
    cVar11 = bVar3 + cVar14;
  }
  *(char *)(param_1 + 0x9c) = cVar14;
  *(char *)(param_1 + 0x9d) = cVar11 + -1;
  *(char *)(param_1 + 0x9e) = cVar14;
  iVar2 = DAT_080146e0;
  iVar4 = DAT_0801441c;
  for (uVar5 = *(uint *)(iVar10 + 0x44); _LAB_080147c4 <= uVar5;
      uVar5 = (uint)((ulonglong)uVar5 * (ulonglong)DAT_080146bc >> 0x29)) {
    cVar13 = cVar13 + '\x01';
  }
  for (pcVar12 = acStack_2c + 4; acStack_2c <= pcVar12; pcVar12 = pcVar12 + -1) {
    uVar1 = (ulonglong)uVar5 * (ulonglong)DAT_080146dc >> 0x23;
    *pcVar12 = (char)uVar5 + (char)uVar1 * -10;
    uVar5 = (uint)uVar1;
  }
  iVar10 = 5;
  do {
    FUN_0801d5c8(param_1,auStack_30);
    piVar7 = (int *)FUN_080179f8(0x1c);
    if (piVar7 == (int *)0x0) {
      piVar7 = (int *)0x0;
    }
    else {
      pcVar12 = pcVar12 + 1;
      FUN_0801d688(piVar7,param_1,auStack_30,*pcVar12);
      *piVar7 = iVar2 + 8;
    }
    cVar14 = *(char *)(param_1 + 0x15);
    if (cVar14 != 0x10) {
      *(int **)(iVar4 + cVar14 * 4 + 0x28) = piVar7;
      *(char *)(param_1 + 0x15) = cVar14 + '\x01';
    }
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  FUN_0801d5c8(param_1,auStack_30);
  puVar6 = (undefined4 *)FUN_080179f8(0x1c);
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    FUN_0801d688(puVar6,param_1,auStack_30,cVar13);
    *puVar6 = _LAB_080147c8;
  }
  FUN_08017a48(param_1,puVar6);
  FUN_0801692c(param_1,0,1);
  return;
LAB_08013e5e:
  if (*piVar7 == 0x3c) {
LAB_08013e64:
    piVar7 = piVar8 + 2;
LAB_08013e66:
    *piVar9 = iVar4;
    piVar9 = piVar9 + 1;
  }
  goto LAB_08013e6a;
LAB_08013e00:
  if (*piVar7 == 0x3c) {
LAB_08013e06:
    piVar7 = piVar8 + 2;
LAB_08013e08:
    *piVar9 = iVar4;
    piVar9 = piVar9 + 1;
  }
  goto LAB_08013e0c;
}



/* ===== FUN_0801411a @ 0801411a ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801411a(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ulonglong uVar1;
  int iVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  char cVar11;
  char *pcVar12;
  undefined1 auStack_30 [4];
  char acStack_2c [9];
  char acStack_23 [3];
  undefined4 uStack_20;
  
  iVar10 = _LAB_080147bc;
  bVar3 = *(byte *)(_LAB_080147bc + 100);
  if ((bVar3 & 1) == 0) {
    uVar4 = 0x3a;
  }
  else {
    uVar4 = 0x39;
  }
  uStack_20 = param_4;
  FUN_08015d88(uVar4);
  if ((bVar3 & 1) == 0) {
    iVar5 = 0x104;
  }
  else {
    iVar5 = 0x100;
  }
  piVar7 = *(int **)(*_LAB_080147c0 + iVar5);
  *(undefined1 *)(param_1 + 0x9f) = 0;
  *(int **)(param_1 + 0xa0) = piVar7;
  cVar11 = '\0';
  piVar9 = (int *)(param_1 + 0x1c);
LAB_0801416a:
  while( true ) {
    piVar8 = piVar7;
    piVar7 = piVar8 + 1;
    iVar5 = *piVar8;
    if (iVar5 == 0x3c) goto LAB_0801415e;
    if (iVar5 != 0x3e) break;
    if (*piVar7 == 0x3e) goto LAB_08014164;
  }
  if (iVar5 == 0) {
    *piVar9 = 0;
    bVar3 = FUN_0801c174(param_1 + 0x1c);
    if (bVar3 < 0x81) {
      cVar11 = (char)(0x80 - bVar3 >> 1);
    }
    else {
      bVar3 = 0x80;
    }
    *(char *)(param_1 + 0x9e) = cVar11;
    *(char *)(param_1 + 0x9c) = cVar11;
    *(byte *)(param_1 + 0x9d) = bVar3 + cVar11 + -1;
    iVar2 = DAT_080146e0;
    iVar5 = DAT_0801441c;
    uVar6 = *(uint *)(iVar10 + 0x4c);
    if (DAT_080147cc < *(uint *)(iVar10 + 0x4c)) {
      uVar6 = DAT_080147cc;
    }
    for (pcVar12 = acStack_2c + 8; acStack_2c <= pcVar12; pcVar12 = pcVar12 + -1) {
      uVar1 = (ulonglong)uVar6 * (ulonglong)DAT_080146dc >> 0x23;
      *pcVar12 = (char)uVar6 + (char)uVar1 * -10;
      uVar6 = (uint)uVar1;
    }
    iVar10 = 9;
    do {
      FUN_0801d5c8(param_1,auStack_30);
      piVar7 = (int *)FUN_080179f8(0x1c);
      if (piVar7 == (int *)0x0) {
        piVar7 = (int *)0x0;
      }
      else {
        pcVar12 = pcVar12 + 1;
        FUN_0801d688(piVar7,param_1,auStack_30,*pcVar12);
        *piVar7 = iVar2 + 8;
      }
      cVar11 = *(char *)(param_1 + 0x15);
      if (cVar11 != 0x10) {
        *(int **)(iVar5 + cVar11 * 4 + 0x28) = piVar7;
        *(char *)(param_1 + 0x15) = cVar11 + '\x01';
      }
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    FUN_0801692c(param_1,0,1);
    return;
  }
  goto LAB_08014166;
LAB_0801415e:
  if (*piVar7 == 0x3c) {
LAB_08014164:
    piVar7 = piVar8 + 2;
LAB_08014166:
    *piVar9 = iVar5;
    piVar9 = piVar9 + 1;
  }
  goto LAB_0801416a;
}



/* ===== FUN_08014420 @ 08014420 ===== */

/* WARNING: Removing unreachable block (ram,0x080271c8) */
/* WARNING: Removing unreachable block (ram,0x080271d2) */

void FUN_08014420(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  iVar1 = FUN_080179f8(0x18);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0801da44(iVar1,0x68,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_0801da74(iVar1,0x69,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_0801daa4(iVar1,0x6a,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_0801dad4(iVar1,0x6b,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_08019990(iVar1,0x27,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = FUN_080179f8(0x18);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_080199c0(iVar1,0x28,0xe,param_1);
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = DAT_08018654;
  iVar3 = *(int *)(DAT_08018654 + 0x28);
  if (iVar3 == 0) {
    iVar7 = 2;
  }
  else {
    iVar7 = *(int *)(iVar3 + 0x10) + 2;
  }
  iVar9 = (int)*(char *)(param_1 + 0x15);
  *(undefined4 *)(param_1 + 0x10) = 2;
  iVar8 = iVar9;
  if (0 < iVar7) {
    iVar8 = (*(int *)(param_1 + 0xc) + 2) / iVar7;
  }
  if ((0 < iVar8) && (iVar8 < iVar9)) {
    iVar9 = iVar8;
  }
  *(char *)(param_1 + 0x16) = (char)iVar9;
  if (iVar3 == 0) {
    return;
  }
  iVar1 = *(int *)(iVar1 + 0x28 + *(char *)(param_1 + 0x18) * 4);
  *(undefined1 *)(iVar1 + 9) = 1;
  *(undefined1 *)(iVar1 + 10) = 1;
  cVar6 = *(char *)(param_1 + 0x17);
  iVar1 = (int)*(char *)(param_1 + 0x18);
  if (0 < *(char *)(param_1 + 0x16)) {
    iVar7 = *(char *)(param_1 + 0x16) + -1;
    iVar8 = (int)cVar6;
    bVar10 = SBORROW4(iVar1,iVar8);
    iVar3 = iVar1 - iVar8;
    if (iVar8 <= iVar1) {
      iVar1 = iVar1 - iVar7;
      bVar10 = SBORROW4((int)cVar6,iVar1);
      iVar3 = cVar6 - iVar1;
    }
    if (iVar3 < 0 != bVar10) {
      cVar6 = (char)iVar1;
    }
    *(char *)(param_1 + 0x17) = cVar6;
    iVar1 = *(int *)(param_1 + 0x10);
    piVar4 = (int *)(DAT_08027214 + cVar6 * 4 + 0x28);
    iVar3 = 0;
    piVar5 = piVar4;
    while( true ) {
      iVar8 = *piVar5;
      *(int *)(iVar8 + 0xc) = iVar3;
      *(undefined1 *)(iVar8 + 10) = 1;
      if (piVar4 + iVar7 <= piVar5) break;
      iVar3 = iVar3 + *(int *)(*piVar5 + 0x10) + iVar1;
      piVar5 = piVar5 + 1;
    }
  }
  return;
}



/* ===== FUN_0801460c @ 0801460c ===== */

void FUN_0801460c(undefined4 param_1)

{
  FUN_08015d8e(0x6d,&LAB_080147b8);
  FUN_0801692c(param_1,0,3);
  return;
}



/* ===== FUN_08014640 @ 08014640 ===== */

void FUN_08014640(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = DAT_080147b4;
  *(undefined1 *)(DAT_080147b4 + 0x14) = 0;
  iVar2 = FUN_080179f8(0x1c);
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = FUN_0801fb00(iVar2,0);
  }
  FUN_08017b2c(iVar1,uVar3);
  return;
}



/* ===== FUN_0801465c @ 0801465c ===== */

undefined4 FUN_0801465c(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DAT_080147b4;
  FUN_0801fb14(DAT_080147b4,param_1);
  return *(undefined4 *)(iVar1 + 0x10);
}



/* ===== FUN_0801466c @ 0801466c ===== */

void FUN_0801466c(void)

{
  int iVar1;
  
  iVar1 = DAT_080147b4;
  if ('\x02' < *(char *)(DAT_080147b4 + 0x14)) {
    return;
  }
  if (*(char *)(DAT_080147b4 + 0x1d) != '\0') {
    FUN_080166a6(0x1009);
  }
  *(undefined1 *)(iVar1 + 0x18) = 1;
  FUN_080157ba(1);
  *(undefined1 *)(iVar1 + 0x1c) = 1;
  return;
}



/* ===== FUN_08014692 @ 08014692 ===== */

void FUN_08014692(void)

{
  *(undefined1 *)(DAT_080147b4 + 0x1a) = 1;
  return;
}



/* ===== FUN_0801469a @ 0801469a ===== */

void FUN_0801469a(void)

{
  *(undefined2 *)(DAT_080147b4 + 0x1a) = 0;
  return;
}



/* ===== FUN_080146a2 @ 080146a2 ===== */

void FUN_080146a2(void)

{
  int iVar1;
  
  iVar1 = DAT_080147b4;
  if ((*(char *)(DAT_080147b4 + 0x1c) != '\0') && (*(char *)(DAT_080147b4 + 0x1d) == '\0')) {
    FUN_080166a6(0x1009);
  }
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  return;
}



/* ===== FUN_0801472c @ 0801472c ===== */

void FUN_0801472c(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if (0 < *(char *)(DAT_080147b4 + 0x14)) {
    iVar1 = *(int *)(DAT_080147f4 + *(char *)(DAT_080147b4 + 0x14) * 4 + -4);
    piVar2 = (int *)(DAT_080147b4 + *(char *)(iVar1 + 0x17) * 4 + 0x28);
    piVar3 = piVar2 + *(char *)(iVar1 + 0x16);
    for (; piVar2 < piVar3; piVar2 = piVar2 + 1) {
      *(undefined1 *)(*piVar2 + 10) = 1;
    }
    *(undefined1 *)(iVar1 + 0x14) = 1;
  }
  return;
}



/* ===== FUN_0801476a @ 0801476a ===== */

undefined1 FUN_0801476a(void)

{
  if (*(char *)(DAT_080147b4 + 0x14) < 1) {
    return 0;
  }
  return *(undefined1 *)(*(int *)(DAT_080147f4 + *(char *)(DAT_080147b4 + 0x14) * 4 + -4) + 4);
}



/* ===== FUN_08014786 @ 08014786 ===== */

undefined4 FUN_08014786(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = DAT_080147b4;
  *(undefined4 *)(DAT_080147b4 + 0x24) = param_1;
  FUN_08017a6c(iVar1,0);
  puVar2 = (undefined4 *)FUN_080179f8(0xa4);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    FUN_080198ac(puVar2,0xd);
    *puVar2 = DAT_080147f8;
  }
  FUN_08017b2c(iVar1,puVar2);
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 7;
  return param_4;
}



/* ===== FUN_080149d2 @ 080149d2 ===== */

int FUN_080149d2(int *param_1)

{
  int iVar1;
  
  (**(code **)(*param_1 + 0x14))(param_1,(int)*DAT_08015724);
  iVar1 = param_1[3];
  if (*(int *)(iVar1 + 0xc) != 0) {
    FUN_0801ff48();
  }
  FUN_08018b64(*(undefined2 *)(iVar1 + 8));
  return iVar1;
}



/* ===== FUN_080149f8 @ 080149f8 ===== */

void FUN_080149f8(int *param_1,int param_2)

{
  char *pcVar1;
  
  pcVar1 = DAT_08015724;
  param_1[3] = param_2;
  (**(code **)(*param_1 + 0x14))(param_1,(int)*pcVar1);
  if (*(int *)(param_2 + 0xc) != 0) {
    FUN_0801ff48();
  }
  FUN_08018b64(*(undefined2 *)(param_2 + 8));
  return;
}



/* ===== FUN_08014a1e @ 08014a1e ===== */

void FUN_08014a1e(int param_1)

{
  FUN_080149f8(param_1,&LAB_080150a8);
  *(undefined1 *)(param_1 + 0x10) = 0xff;
  return;
}



/* ===== FUN_08014a34 @ 08014a34 ===== */

void FUN_08014a34(int param_1)

{
  FUN_080149f8(param_1,&LAB_08014a5c);
  FUN_0801ffd0(**(undefined1 **)(param_1 + 0xc));
  FUN_0802003c(param_1 + 0x10,DAT_080157d0,0,0);
  return;
}



/* ===== FUN_08014c9c @ 08014c9c ===== */

void FUN_08014c9c(int param_1)

{
  undefined *puVar1;
  
  if (*(char *)(DAT_0801530c + 10) == '\a') {
    puVar1 = &DAT_08014cd4;
  }
  else {
    puVar1 = &LAB_08014ce4;
  }
  FUN_080149f8(param_1,puVar1);
  FUN_0801ffd0(**(undefined1 **)(param_1 + 0xc));
  FUN_0802003c(param_1 + 0x10,DAT_08015894,0,0x1f);
  return;
}



/* ===== FUN_08014f86 @ 08014f86 ===== */

undefined4 FUN_08014f86(int param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  byte *pbVar5;
  undefined4 uVar6;
  uint extraout_r1;
  undefined4 extraout_r3;
  uint unaff_r5;
  uint uVar7;
  int iVar8;
  
  FUN_0801ffd0(**(undefined1 **)(param_1 + 0xc));
  puVar3 = *(uint **)(param_1 + 0x1c);
  uVar4 = 0;
  uVar7 = unaff_r5;
  if (puVar3 != (uint *)0x0) {
    uVar7 = *puVar3;
    uVar4 = *(uint *)(param_1 + 0x18);
  }
  if (puVar3 != (uint *)0x0 && uVar7 != uVar4) {
    FUN_0802039c(param_1 + 0x10,uVar7);
    *(uint *)(param_1 + 0x18) = uVar7;
  }
  iVar2 = DAT_0801571c;
  iVar1 = DAT_08015308;
  FUN_080204be(DAT_08015340);
  if ((*(byte **)(iVar2 + 0xc) != (byte *)0x0) &&
     (iVar8 = *(int *)(*(int *)(iVar1 + 0x74) + (uint)**(byte **)(iVar2 + 0xc) * 4),
     iVar8 != *(int *)(iVar2 + 8))) {
    FUN_08020456(iVar2,iVar8);
    *(int *)(iVar2 + 8) = iVar8;
  }
  iVar2 = DAT_0801530c;
  FUN_08020254(DAT_08015334);
  FUN_0802027c(iVar1 + 0x14);
  FUN_080202b4(iVar1 + 0xc);
  FUN_080202e8(iVar1 + 4);
  FUN_08020320(iVar2 + 0xc);
  pbVar5 = *(byte **)(iVar2 + 0x18);
  uVar7 = 0;
  uVar4 = extraout_r1;
  if (pbVar5 != (byte *)0x0) {
    uVar7 = (uint)*pbVar5;
    uVar4 = (uint)*(byte *)(iVar2 + 0x17);
    unaff_r5 = uVar7;
  }
  if (pbVar5 != (byte *)0x0 && uVar7 != uVar4) {
    if (uVar7 < *(ushort *)(DAT_08020380 + 8)) {
      uVar6 = FUN_0802c8ac();
      FUN_0802c8c8(*(undefined1 *)(iVar2 + 0x15),*(undefined1 *)(iVar2 + 0x16),uVar6);
    }
    *(char *)(iVar2 + 0x17) = (char)unaff_r5;
  }
  return extraout_r3;
}



/* ===== FUN_0801516c @ 0801516c ===== */

void FUN_0801516c(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  FUN_080149f8(param_1,&DAT_080151b0);
  FUN_0802075c(param_1 + 0x10);
  FUN_080149f8(param_1,&LAB_080151c0);
  piVar1 = *(int **)(param_1 + 0x38);
  if (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    iVar3 = piVar1[1];
    if (iVar3 != *(int *)(param_1 + 0x34) || iVar2 != *(int *)(param_1 + 0x30)) {
      FUN_080206e8(param_1 + 0x20,*(int *)(param_1 + 0x34),iVar2,iVar3);
      *(int *)(param_1 + 0x30) = iVar2;
      *(int *)(param_1 + 0x34) = iVar3;
    }
  }
  return;
}



/* ===== FUN_08015358 @ 08015358 ===== */

undefined4 FUN_08015358(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *unaff_r4;
  
  piVar1 = param_1;
  if (*DAT_08015eb8 != 0) {
    piVar1 = (int *)(uint)*(byte *)((int)param_1 + 10);
    unaff_r4 = param_1;
  }
  if (*DAT_08015eb8 == 0 || piVar1 == param_2) {
switchD_0801538c_default:
    return param_4;
  }
  iVar2 = *unaff_r4;
  while (iVar2 != 0) {
    iVar4 = *(int *)(iVar2 + 8);
    *(undefined4 *)(iVar2 + 8) = 0;
    *(undefined4 *)(iVar2 + 4) = 0;
    iVar2 = iVar4;
  }
  unaff_r4[1] = 0;
  *unaff_r4 = 0;
  *(char *)((int)unaff_r4 + 10) = (char)param_2;
  iVar2 = DAT_08015ec0;
  switch(param_2) {
  case (int *)0x0:
    iVar2 = DAT_08015ebc;
    break;
  case (int *)0x1:
    FUN_0802078c(unaff_r4,DAT_08015ec0 + 0xa0);
    iVar2 = iVar2 + 0xb4;
    break;
  case (int *)0x2:
    FUN_0802078c(unaff_r4,DAT_08015ec0 + 0xa0);
    FUN_0802078c(unaff_r4,iVar2 + 0xd4);
    FUN_0802078c(unaff_r4,iVar2 + 0xf4);
    FUN_0802078c(unaff_r4,iVar2 + 0x114);
    FUN_0802078c(unaff_r4,iVar2 + 0x24);
    FUN_0802078c(unaff_r4,iVar2 + 0x1c8);
    iVar2 = iVar2 + 0x1e4;
    break;
  case (int *)0x3:
    FUN_0802078c(unaff_r4,DAT_08015ec0 + 0x78);
    FUN_0802078c(unaff_r4,iVar2 + 0xd4);
    FUN_0802078c(unaff_r4,iVar2 + 0xf4);
    FUN_0802078c(unaff_r4,iVar2 + 0x114);
    FUN_0802078c(unaff_r4,iVar2 + 0x1c8);
    FUN_0802078c(unaff_r4,iVar2 + 0x1e4);
    iVar2 = iVar2 + 0x270;
    break;
  case (int *)0x4:
    FUN_0802078c(unaff_r4,DAT_08015ec4);
    FUN_0802078c(unaff_r4,iVar2 + 0xd4);
    FUN_0802078c(unaff_r4,iVar2 + 0xf4);
    FUN_0802078c(unaff_r4,iVar2 + 0x1fc);
    iVar2 = iVar2 + 0x44;
    break;
  case (int *)0x5:
    FUN_0802078c(unaff_r4,DAT_08015ec0 + 0xa0);
    FUN_0802078c(unaff_r4,iVar2 + 0x13c);
    FUN_0802078c(unaff_r4,iVar2 + 0x15c);
    FUN_0802078c(unaff_r4,iVar2 + 0x34);
    FUN_0802078c(unaff_r4,iVar2 + 0x114);
    FUN_0802078c(unaff_r4,iVar2 + 0x1c8);
    iVar2 = iVar2 + 0x1e4;
    break;
  case (int *)0x6:
    FUN_0802078c(unaff_r4,DAT_08015ec0 + 0x78);
    FUN_0802078c(unaff_r4,iVar2 + 0x13c);
    FUN_0802078c(unaff_r4,iVar2 + 0x15c);
    FUN_0802078c(unaff_r4,iVar2 + 0x114);
    FUN_0802078c(unaff_r4,iVar2 + 0x1c8);
    FUN_0802078c(unaff_r4,iVar2 + 0x1e4);
    iVar2 = iVar2 + 0x270;
    break;
  case (int *)0x7:
    FUN_0802078c(unaff_r4,DAT_08015ec4);
    FUN_0802078c(unaff_r4,iVar2 + 0x13c);
    FUN_0802078c(unaff_r4,iVar2 + 0x15c);
    FUN_0802078c(unaff_r4,iVar2 + 0x1fc);
    iVar2 = iVar2 + 0x44;
    break;
  case (int *)0x8:
    FUN_0802078c(unaff_r4,DAT_08015ec0 + 0xa0);
    FUN_0802078c(unaff_r4,DAT_08015ec8);
    FUN_0802078c(unaff_r4,iVar2 + 0x17c);
    FUN_0802078c(unaff_r4,iVar2 + 0x1a0);
    FUN_0802078c(unaff_r4,iVar2 + 0x1c8);
    iVar2 = iVar2 + 0x1e4;
    break;
  case (int *)0x9:
    FUN_0802078c(unaff_r4,DAT_08015ec0 + 0x78);
    FUN_0802078c(unaff_r4,DAT_08015ec8);
    FUN_0802078c(unaff_r4,iVar2 + 0x1c8);
    FUN_0802078c(unaff_r4,iVar2 + 0x1e4);
    iVar2 = iVar2 + 0x270;
    break;
  case (int *)0xa:
    FUN_0802078c(unaff_r4,DAT_08015ec4);
    FUN_0802078c(unaff_r4,DAT_08015ec8);
    FUN_0802078c(unaff_r4,iVar2 + 0x1fc);
    iVar2 = iVar2 + 0x44;
    break;
  case (int *)0xb:
    FUN_0802078c(unaff_r4,DAT_08015ec0 + 0xa0);
    iVar2 = iVar2 + 0x54;
    break;
  case (int *)0xc:
    FUN_0802078c(unaff_r4,DAT_08015ec0 + 0xa0);
    iVar4 = iVar2 + 0x21c;
    goto LAB_08015612;
  case (int *)0xd:
    FUN_0802078c(unaff_r4,DAT_08015ec0 + 0xa0);
    iVar4 = iVar2 + 0x23c;
LAB_08015612:
    FUN_0802078c(unaff_r4,iVar4);
    iVar2 = iVar2 + 100;
    break;
  default:
    goto switchD_0801538c_default;
  }
  uVar3 = FUN_0802078c(unaff_r4,iVar2,param_4);
  return uVar3;
}



/* ===== FUN_08015628 @ 08015628 ===== */

void FUN_08015628(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = FUN_0801476a();
  iVar1 = DAT_08015ecc;
  FUN_08015358(DAT_08015ecc,uVar2);
  uVar3 = (*(byte *)(DAT_08015ed0 + 0x68) & 0xf) >> 2;
  *(byte *)(DAT_08015ed0 + 0x68) = *(byte *)(DAT_08015ed0 + 0x68) & 0xf3 | (byte)(uVar3 << 2);
  if (uVar3 == 1) {
    *(undefined1 *)(iVar1 + 9) = 1;
  }
  else if (uVar3 == 2) {
    *(undefined1 *)(iVar1 + 9) = 0;
    return;
  }
  return;
}



/* ===== FUN_08015666 @ 08015666 ===== */

void FUN_08015666(void)

{
  FUN_08015358(DAT_08015ecc,0);
  return;
}



/* ===== FUN_0801566a @ 0801566a ===== */

void FUN_0801566a(undefined4 param_1)

{
  FUN_08015358(DAT_08015ecc,param_1);
  return;
}



/* ===== FUN_08015672 @ 08015672 ===== */

void FUN_08015672(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  if ((param_1 == 4 || param_1 == 7) || param_1 == 10) {
    *param_2 = 0x13;
    *param_3 = 0x30;
    return;
  }
  if (param_1 == 0xb) {
    *param_2 = 0x80;
    *param_3 = 0x30;
    return;
  }
  *param_3 = 0;
  *param_2 = 0;
  return;
}



/* ===== FUN_080156a2 @ 080156a2 ===== */

undefined4 FUN_080156a2(void)

{
  undefined4 *puVar1;
  undefined4 in_r3;
  int *piVar2;
  
  puVar1 = DAT_08015ecc;
  if (*DAT_08015eb8 == 0) {
    return 0;
  }
  if (*DAT_08015884 != *(char *)((int)DAT_08015ecc + 9)) {
    FUN_0801b65e();
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



/* ===== FUN_08015794 @ 08015794 ===== */

uint FUN_08015794(uint param_1,int param_2)

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
    if (*(int *)(DAT_08015ed4 + param_1 * 4) != 0) break;
    param_1 = iVar1 + param_1;
  }
  return param_1 & 0xff;
}



/* ===== FUN_080157ba @ 080157ba ===== */

void FUN_080157ba(undefined1 param_1)

{
  *(undefined1 *)(DAT_08015ec0 + 0x1d) = param_1;
  return;
}



/* ===== FUN_080157c2 @ 080157c2 ===== */

undefined4 FUN_080157c2(void)

{
  return DAT_08015ed8;
}



/* ===== FUN_080157c8 @ 080157c8 ===== */

void FUN_080157c8(undefined1 param_1)

{
  *(undefined1 *)(DAT_08015ec0 + 0x1c) = param_1;
  return;
}



/* ===== FUN_080157d4 @ 080157d4 ===== */

void FUN_080157d4(undefined1 param_1)

{
  *(undefined1 *)(DAT_08015ec0 + 0x1e) = param_1;
  return;
}



/* ===== FUN_080157e4 @ 080157e4 ===== */

void FUN_080157e4(float param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = DAT_08015ec0;
  uVar3 = (uint)*(byte *)(DAT_08015ec0 + 0x1f);
  iVar4 = (int)(param_1 + 0.5);
  switch(param_2) {
  case 0:
  case 3:
    iVar2 = (iVar4 + -5) * 9;
    iVar2 = (int)((ulonglong)((longlong)iVar2 * (longlong)DAT_08015edc) >> 0x20) + iVar2;
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
  *(char *)(DAT_08015ec0 + 0x20) = (char)iVar4;
  *(char *)(iVar1 + 0x1f) = (char)uVar3;
  return;
}



/* ===== FUN_08015850 @ 08015850 ===== */

undefined8 FUN_08015850(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    uVar1 = param_1 >> 1;
    if (uVar1 < 1000) break;
    param_1 = (uint)((ulonglong)uVar1 * (ulonglong)DAT_08015ee0 >> 0x22);
    iVar2 = iVar2 + 1;
  }
  uVar1 = (param_1 & 1) + uVar1;
  if (999 < uVar1) {
    uVar1 = (uint)((ulonglong)uVar1 * (ulonglong)DAT_08015ee0 >> 0x23);
    iVar2 = iVar2 + 1;
  }
  return CONCAT44(iVar2,uVar1);
}



/* ===== FUN_0801589c @ 0801589c ===== */

void FUN_0801589c(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  uVar4 = CONCAT44(param_2,param_1);
  while( true ) {
    uVar3 = (uint)(uVar4 & 0x100000001);
    uVar2 = (uint)(uVar4 >> 0x21);
    uVar1 = (uint)((int)((uVar4 & 0x100000001) >> 0x20) != 0) << 0x1f | (uint)uVar4 >> 1;
    if ((uVar2 == 0) && (uVar1 < 1000)) break;
    uVar4 = FUN_08019bf4(uVar1,uVar2,5);
  }
  if ((CARRY4(uVar1,uVar3)) || (999 < uVar1 + uVar3)) {
    FUN_08019bf4(uVar1 + uVar3,CARRY4(uVar1,uVar3),10);
  }
  return;
}



/* ===== FUN_080158dc @ 080158dc ===== */

undefined4
FUN_080158dc(float param_1,float param_2,uint *param_3,char param_4,undefined4 param_5,
            undefined4 param_6)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  
  bVar3 = *(byte *)(DAT_08015ecc + 10);
  *(byte *)param_3 = (byte)*param_3 & 0xf | param_4 << 4;
  iVar5 = -(uint)(bVar3 - 8 < 3);
  if (*(int *)(DAT_08015ed0 + 100) << 0x1d < 0) {
    bVar3 = 0x10;
  }
  else {
    bVar3 = 0x13;
  }
  if (0.0 <= param_1) {
    if (param_1 < DAT_08015a70) {
      uVar1 = VectorFloatToUnsigned(param_2 * DAT_08015c30 + 0.5,3);
      param_3[3] = uVar1;
      if (bVar3 == 0x10) {
        uVar6 = VectorFloatToUnsigned(param_1,3);
      }
      else {
        param_1 = param_1 * 6.0;
        uVar6 = VectorFloatToUnsigned(param_1 / 10.0,3);
      }
      if (iVar5 < 0) {
        uVar4 = DAT_08015ee4;
      }
      else {
        uVar4 = DAT_08015ee8;
      }
      uVar1 = FUN_08015e34(uVar6,uVar4,0x10);
      param_3[1] = uVar1;
      FUN_080207ec(param_1 * DAT_08015c58);
      uVar7 = FUN_0801589c();
      uVar1 = (uint)(uVar7 >> 0x20);
      iVar5 = uVar1 + (uint)((ulonglong)uVar1 * (ulonglong)DAT_08015eec >> 0x21) * -3;
      if (bVar3 == 0x10) {
        bVar2 = (&DAT_08015f14)[iVar5];
        bVar3 = 0x10;
        if (uVar7 < 0x600000000) {
          if (0x2ffffffff < uVar7) {
            bVar3 = 0x11;
          }
        }
        else {
          bVar3 = 0x12;
        }
      }
      else {
        bVar2 = (&DAT_08015f18)[iVar5];
        if (uVar7 < 0x800000000) {
          if (uVar7 < 0x500000000) {
            if (0x1ffffffff < uVar7) {
              bVar3 = 0x14;
            }
          }
          else {
            bVar3 = 0x15;
          }
        }
        else {
          bVar3 = 0x16;
        }
      }
      *(byte *)(param_3 + 2) = bVar3;
      *(byte *)param_3 = (byte)*param_3 & 0xf0 | bVar2 & 0xf;
      *param_3 = *param_3 & 0xff | (int)uVar7 << 8;
    }
    else {
      bVar2 = (byte)*param_3 & 0xf0;
      if (bVar3 == 0x10) {
        *(byte *)param_3 = bVar2 | 8;
        *param_3 = *param_3 & 0xff | 0x3200;
        bVar3 = 0x12;
      }
      else {
        *(byte *)param_3 = bVar2 | 6;
        *param_3 = *param_3 & 0xff | 0x1e00;
        bVar3 = 0x16;
      }
      *(byte *)(param_3 + 2) = bVar3;
      param_3[3] = 0;
      if (iVar5 < 0) {
        uVar1 = 0x50;
      }
      else {
        uVar1 = 0x78;
      }
      param_3[1] = uVar1;
    }
  }
  else {
    *param_3 = 0;
    *(byte *)(param_3 + 2) = bVar3;
    param_3[3] = 0x3de;
  }
  return param_6;
}



/* ===== FUN_08015a4c @ 08015a4c ===== */

void FUN_08015a4c(undefined1 param_1)

{
  if ((int)((uint)*(byte *)(DAT_08015ed0 + 100) << 0x1b) < 0) {
    FUN_080158dc(DAT_08015ef0,param_1);
    return;
  }
  return;
}



/* ===== FUN_08015a74 @ 08015a74 ===== */

void FUN_08015a74(float param_1,float param_2,char param_3)

{
  ulonglong uVar1;
  uint *puVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined8 uVar8;
  
  puVar2 = DAT_08015ef0;
  iVar6 = DAT_08015ed0;
  if ((int)((uint)*(byte *)(DAT_08015ed0 + 100) << 0x1b) < 0) {
    return;
  }
  *(byte *)DAT_08015ef0 = (byte)*DAT_08015ef0 & 0xf | param_3 << 4;
  iVar4 = *(int *)(iVar6 + 100);
  if (iVar4 << 0x1f < 0) {
    bVar3 = 9;
  }
  else {
    bVar3 = 0xc;
  }
  if (param_1 < 0.0) {
    *puVar2 = 0;
    if ((bVar3 == 9) && (iVar4 << 0x1c < 0)) {
      bVar3 = 8;
    }
    *(byte *)(puVar2 + 2) = bVar3;
    puVar2[3] = 0x3de;
    uVar5 = 0xffffffff;
LAB_08015b12:
    puVar2[1] = uVar5;
    return;
  }
  if (DAT_08015da0 <= param_1) {
    uVar5 = (byte)*puVar2 & 0xf0;
    if (bVar3 == 0xc) {
      *(byte *)puVar2 = (byte)uVar5 | 6;
      *puVar2 = uVar5 | 0x906;
      bVar3 = 0xf;
    }
    else {
      *(byte *)puVar2 = (byte)uVar5 | 9;
      *puVar2 = uVar5 | 0x909;
      bVar3 = 0xb;
    }
    *(byte *)(puVar2 + 2) = bVar3;
    uVar5 = 0x78;
    puVar2[3] = 0;
    goto LAB_08015b12;
  }
  uVar7 = VectorFloatToUnsigned(param_1 * DAT_08015de4,3);
  uVar5 = VectorFloatToUnsigned(param_2 * DAT_08015c30 + 0.5,3);
  uVar1 = (ulonglong)DAT_08015ee0;
  puVar2[3] = uVar5;
  iVar4 = 0;
  uVar5 = FUN_08015e34((uint)(uVar7 * uVar1 >> 0x24),DAT_08015ee8,0x10,(int)(uVar7 * uVar1));
  puVar2[1] = uVar5;
  if ((bVar3 == 0xc) || (*(int *)(iVar6 + 100) << 0x1c < 0)) {
    if (param_1 < DAT_08015e28) {
      uVar7 = VectorFloatToUnsigned(param_1 * DAT_08015e30,3);
    }
    else {
      uVar7 = VectorFloatToUnsigned(param_1 * DAT_08015e2c,3);
      iVar4 = 3;
    }
  }
  uVar8 = FUN_08015850(uVar7);
  uVar5 = iVar4 + (int)((ulonglong)uVar8 >> 0x20);
  if (bVar3 == 0xc) {
    iVar6 = (int)((ulonglong)((longlong)(int)uVar5 * (longlong)DAT_08015ef4) >> 0x20);
    uVar7 = uVar5 + (iVar6 - (iVar6 >> 0x1f)) * -3 + 3;
    if (uVar5 < 9) {
      if (uVar5 < 6) {
        if (2 < uVar5) {
          bVar3 = 0xd;
        }
      }
      else {
        bVar3 = 0xe;
      }
    }
    else {
      bVar3 = 0xf;
    }
    goto LAB_08015c16;
  }
  if (*(int *)(iVar6 + 100) << 0x1c < 0) {
    iVar6 = (int)((ulonglong)((longlong)(int)(uVar5 + 1) * (longlong)DAT_08015ef4) >> 0x20);
    uVar7 = uVar5 + 1 + (iVar6 - (iVar6 >> 0x1f)) * -3 + 3;
    if (7 < uVar5) {
LAB_08015c0c:
      bVar3 = 0xb;
      goto LAB_08015c16;
    }
    if (uVar5 < 5) {
      if (uVar5 < 2) {
        bVar3 = 8;
      }
      goto LAB_08015c16;
    }
  }
  else {
    iVar6 = (int)((ulonglong)((longlong)(int)uVar5 * (longlong)DAT_08015ef4) >> 0x20);
    uVar7 = uVar5 + (iVar6 - (iVar6 >> 0x1f)) * -3 + 3;
    if (5 < uVar5) goto LAB_08015c0c;
    if (uVar5 < 3) goto LAB_08015c16;
  }
  bVar3 = 10;
LAB_08015c16:
  *(byte *)(puVar2 + 2) = bVar3;
  uVar5 = (byte)*puVar2 & 0xfffffff0 | uVar7 & 0xf;
  *(byte *)puVar2 = (byte)uVar5;
  *puVar2 = uVar5 | (int)uVar8 << 8;
  return;
}



/* ===== FUN_08015c34 @ 08015c34 ===== */

void FUN_08015c34(int param_1)

{
  uint uVar1;
  
  *DAT_08015ef8 = (char)param_1;
  FUN_08017db2(0x30000);
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x10000;
  }
  *(uint *)(DAT_08017e1c + 0x10) = uVar1 | *(uint *)(DAT_08017e1c + 0x10);
  return;
}



/* ===== FUN_08015c6c @ 08015c6c ===== */

void FUN_08015c6c(uint param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  puVar1 = DAT_08015efc;
  DAT_08015efc[3] = param_3;
  if ((int)((uint)*(byte *)(DAT_08015ed0 + 100) << 0x1f) < 0) {
    bVar3 = 1;
  }
  else {
    bVar3 = 4;
  }
  if ((int)param_2 < 0) {
    *(byte *)(puVar1 + 2) = bVar3;
    *puVar1 = 0;
    puVar1[1] = 0xffffffff;
    return;
  }
  if ((1 < param_2) && ((2 < param_2 || (DAT_08015f00 <= param_1)))) {
    bVar2 = (byte)*puVar1 & 0xf0;
    if (bVar3 == 4) {
      *(byte *)puVar1 = bVar2 | 8;
      *puVar1 = (byte)*puVar1 | 0xa00;
      bVar3 = 7;
    }
    else {
      *(byte *)puVar1 = bVar2 | 7;
      *puVar1 = (byte)*puVar1 | 0x6400;
      bVar3 = 3;
    }
    *(byte *)(puVar1 + 2) = bVar3;
    puVar1[1] = 0x78;
    return;
  }
  uVar4 = FUN_08019bb0(param_1,param_2,100,0);
  uVar5 = FUN_08015e34(uVar4,DAT_08015ee8,0x10);
  if (0x78 < (int)uVar5) {
    uVar5 = 0x78;
  }
  puVar1[1] = uVar5;
  uVar7 = FUN_0801589c(param_1 << 1,param_2 << 1 | param_1 >> 0x1f);
  uVar6 = (uint)(uVar7 >> 0x20);
  uVar5 = (uint)uVar7;
  if (bVar3 == 4) {
    if (uVar6 == 0) {
      bVar3 = 4;
      if (uVar5 < 10) {
        uVar6 = 1;
      }
      else if (uVar5 < 100) {
        uVar6 = 2;
      }
      else {
        uVar6 = 5;
      }
      goto LAB_08015d6e;
    }
    uVar6 = (uint)(byte)(&DAT_08015f1c)
                        [uVar6 + (uint)((ulonglong)uVar6 * (ulonglong)DAT_08015eec >> 0x21) * -3];
    if (uVar7 < 0x700000000) {
      if (uVar7 < 0x400000000) {
        bVar3 = 5;
      }
      else {
        bVar3 = 6;
      }
    }
    else {
      bVar3 = 7;
    }
  }
  else {
    uVar6 = (uint)(byte)(&LAB_08015f20)
                        [uVar6 + (uint)((ulonglong)uVar6 * (ulonglong)DAT_08015eec >> 0x21) * -3];
    if (uVar7 < 0x600000000) {
      if (uVar7 < 0x300000000) {
        bVar3 = 1;
      }
      else {
        bVar3 = 2;
      }
    }
    else {
      bVar3 = 3;
    }
  }
  uVar6 = uVar6 & 0xf;
LAB_08015d6e:
  *(byte *)(puVar1 + 2) = bVar3;
  uVar6 = uVar6 | (byte)*puVar1 & 0xf0;
  *(byte *)puVar1 = (byte)uVar6;
  *puVar1 = uVar6 | uVar5 << 8;
  return;
}



/* ===== FUN_08015d88 @ 08015d88 ===== */

void FUN_08015d88(undefined1 param_1)

{
  *DAT_08015eb0 = param_1;
  return;
}



/* ===== FUN_08015d8e @ 08015d8e ===== */

char * FUN_08015d8e(char param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = DAT_08015eb4;
  cVar1 = *DAT_08015eb4;
  DAT_08015eb4[1] = param_1;
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



/* ===== FUN_08015da4 @ 08015da4 ===== */

void FUN_08015da4(uint param_1)

{
  if (3 < param_1) {
    param_1 = 3;
  }
  *(uint *)(DAT_08015ec8 + 0x24) = (uint)(ushort)(&DAT_08015f0c)[param_1];
  return;
}



/* ===== FUN_08015de8 @ 08015de8 ===== */

void FUN_08015de8(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = DAT_08015ec8;
  *(undefined4 *)(DAT_08015ec8 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x30) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x2c) = 0;
  for (puVar2 = (undefined1 *)(iVar1 + 0x34); puVar2 < (undefined1 *)(iVar1 + 0x108);
      puVar2 = puVar2 + 2) {
    *puVar2 = 0;
  }
  *(undefined1 *)(iVar1 + 0x28) = 1;
  return;
}



/* ===== FUN_08015e20 @ 08015e20 ===== */

int * FUN_08015e20(float param_1,int param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  int *piVar6;
  int *piVar7;
  char cVar8;
  uint in_fpscr;
  int iVar9;
  float fVar10;
  float fVar11;
  
  piVar1 = DAT_08015f04;
  fVar10 = (float)VectorUnsignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
  iVar9 = VectorFloatToUnsigned(fVar10 * param_1 * DAT_080209b4 + 0.5,3);
  iVar2 = DAT_08015f04[3];
  DAT_08015f04[3] = iVar2 + iVar9;
  uVar3 = piVar1[4] + param_2;
  piVar1[4] = uVar3;
  if (uVar3 < (uint)piVar1[5]) {
    return param_5;
  }
  fVar10 = (float)VectorUnsignedToFloat(iVar2 + iVar9,(byte)(in_fpscr >> 0x16) & 3);
  fVar11 = (float)VectorUnsignedToFloat(uVar3,(byte)(in_fpscr >> 0x16) & 3);
  fVar11 = (fVar10 * DAT_080209b8) / fVar11;
  FUN_080158dc(fVar11,DAT_080209bc,DAT_080209c0,1);
  iVar2 = piVar1[2];
  piVar1[3] = 0;
  piVar1[4] = 0;
  if (iVar2 == 0) {
    piVar1[7] = 0;
  }
  fVar10 = (float)FUN_0802a9a0(fVar11);
  if (iVar2 < 0x6a) {
    piVar1[2] = iVar2 + 1;
  }
  iVar2 = piVar1[1] + 1;
  if (0x69 < iVar2) {
    iVar2 = 0;
  }
  piVar1[1] = iVar2;
  *(float *)(*piVar1 + iVar2 * 4) = fVar10;
  uVar3 = 0;
  if ((float)piVar1[7] == 0.0) {
    if (fVar10 <= 0.0) {
      iVar9 = -1;
    }
    else {
      piVar1[7] = (int)(28.0 / fVar10);
      uVar3 = 0x1c;
      iVar9 = iVar2;
    }
    piVar1[8] = iVar9;
  }
  else {
    uVar3 = FUN_0802cd68(fVar10,piVar1);
  }
  cVar8 = (char)uVar3;
  if (cVar8 == '\x1c') {
    piVar1[8] = iVar2;
LAB_080209a0:
    piVar6 = piVar1 + 9;
    piVar7 = (int *)((int)piVar1 + 0x26);
    while (piVar7 < piVar1 + 0x3e) {
      pcVar4 = (char *)((int)piVar6 + 1);
      iVar2 = *piVar7;
      *(char *)piVar6 = (char)iVar2;
      piVar6 = piVar7;
      piVar7 = (int *)((int)piVar7 + 2);
      if ((char)iVar2 != *pcVar4) {
        *(undefined1 *)(piVar1 + 6) = 1;
      }
    }
    *(char *)piVar6 = cVar8;
    if (uVar3 != *(byte *)((int)piVar6 + 1)) {
      *(undefined1 *)(piVar1 + 6) = 1;
    }
    return piVar1;
  }
  if ((char)(cVar8 + -0x1c) < '\x01') {
    if (piVar1[8] != iVar2) goto LAB_080209a0;
    piVar1[7] = 0;
    piVar1[8] = -1;
    iVar9 = piVar1[1];
    iVar2 = FUN_0802cd90(piVar1);
    fVar10 = DAT_080209bc;
    while( true ) {
      fVar11 = *(float *)(*piVar1 + iVar9 * 4);
      if (fVar10 < fVar11) {
        piVar1[8] = iVar9;
        fVar10 = fVar11;
      }
      if (iVar9 == iVar2) break;
      iVar9 = iVar9 + -1;
      if (iVar9 < 0) {
        iVar9 = 0x69;
      }
    }
    if (0.0 < fVar10) {
      piVar1[7] = (int)(28.0 / fVar10);
    }
  }
  else {
    piVar1[8] = iVar2;
    piVar1[7] = (int)(28.0 / fVar10);
  }
  iVar2 = piVar1[1];
  iVar9 = (iVar2 - piVar1[2]) + 1;
  pcVar4 = (char *)((int)piVar1 + 0xf6);
  if (iVar9 < 0) {
    iVar9 = (iVar2 - piVar1[2]) + 0x6b;
  }
  while( true ) {
    fVar10 = *(float *)(*piVar1 + iVar2 * 4);
    if (fVar10 <= 0.0) {
      cVar8 = '\0';
    }
    else {
      cVar8 = (char)(int)((float)piVar1[7] * fVar10);
      if (cVar8 == '\0') {
        cVar8 = '\x01';
      }
    }
    pcVar5 = pcVar4 + -2;
    *pcVar4 = cVar8;
    if (iVar2 == iVar9) break;
    iVar2 = iVar2 + -1;
    pcVar4 = pcVar5;
    if (iVar2 < 0) {
      iVar2 = 0x69;
    }
  }
  *(undefined1 *)(piVar1 + 6) = 1;
  return piVar1;
}



/* ===== FUN_08015e34 @ 08015e34 ===== */

uint FUN_08015e34(uint param_1,int param_2,int param_3)

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
          (param_1 = param_1 >> (iVar1 + 0x117U & 0xff), param_1 = (param_1 & 1) + (param_1 >> 1),
          0xff < param_1)) {
    param_1 = param_1 >> 1;
    uVar2 = iVar1 + 0x20;
  }
  return (((uint)*(byte *)(param_1 + DAT_08015f08 + -0x80) + uVar2 * 0x100) * param_2 >>
         (param_3 + 7U & 0xff)) + 1 >> 1;
}



/* ===== FUN_08015e8a @ 08015e8a ===== */

void FUN_08015e8a(void)

{
  if ((*(byte *)(DAT_08015ed0 + 0x68) & 0xf) >> 2 == 0) {
    *(undefined1 *)(DAT_08015ecc + 9) = 1;
  }
  return;
}



/* ===== FUN_08015e9e @ 08015e9e ===== */

void FUN_08015e9e(void)

{
  if ((*(byte *)(DAT_08015ed0 + 0x68) & 0xf) >> 2 == 0) {
    *(undefined1 *)(DAT_08015ecc + 9) = 0;
  }
  return;
}



/* ===== FUN_08015f2a @ 08015f2a ===== */

void FUN_08015f2a(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0x3c;
  FUN_080165ac(param_1,0);
  return;
}



/* ===== FUN_08015f34 @ 08015f34 ===== */

void FUN_08015f34(undefined4 param_1)

{
  FUN_08020bd0(0xc);
  FUN_08020fd6(DAT_0801655c);
  FUN_080165ce(param_1);
  return;
}



/* ===== FUN_08015f50 @ 08015f50 ===== */

longlong FUN_08015f50(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10) + -1;
  *(int *)(param_1 + 0x10) = iVar1;
  if (iVar1 < 0) {
    FUN_08020bd0(0xc);
    FUN_08020fd6(DAT_0801655c);
    FUN_080165ce(param_1);
    FUN_080178f6(2);
    return (ulonglong)param_4 << 0x20;
  }
  if (iVar1 * -0x80000000 < 0) {
    FUN_080162f2(DAT_08016558);
  }
  *(int *)(param_1 + 8) = param_2 + 0x8000;
  return CONCAT44(param_4,param_1);
}



/* ===== FUN_080160ec @ 080160ec ===== */

void FUN_080160ec(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 in_r3;
  int iVar4;
  
  iVar2 = DAT_08016560;
  puVar1 = DAT_08016558;
  iVar4 = *(int *)(DAT_08016560 + 100);
  uVar3 = (uint)(iVar4 << 0x17 < 0);
  if (iVar4 << 0x16 < 0) {
    uVar3 = uVar3 | 2;
  }
  if (iVar4 << 0x15 < 0) {
    uVar3 = uVar3 | 4;
  }
  if (iVar4 << 0x14 < 0) {
    uVar3 = uVar3 | 0x200;
  }
  if (iVar4 << 0x13 < 0) {
    uVar3 = uVar3 | 0x400;
  }
  if (iVar4 << 0x12 < 0) {
    uVar3 = uVar3 | 0x800;
  }
  if (iVar4 << 0x11 < 0) {
    uVar3 = uVar3 | 8;
  }
  if (iVar4 << 0x10 < 0) {
    uVar3 = uVar3 | 0x10;
  }
  if (iVar4 << 0xf < 0) {
    uVar3 = uVar3 | 0x20;
  }
  if (iVar4 << 0xe < 0) {
    uVar3 = uVar3 | 0x40;
  }
  if (iVar4 << 0xd < 0) {
    uVar3 = uVar3 | 0x80;
  }
  if (iVar4 << 0xc < 0) {
    uVar3 = uVar3 | 0x100;
  }
  if (*(int *)(DAT_08016560 + 0x68) << 0x13 < 0) {
    uVar3 = uVar3 | 0x4000;
  }
  if (*(int *)(DAT_08016560 + 0x68) << 0x12 < 0) {
    uVar3 = uVar3 | 0x8000;
  }
  *DAT_08016558 = uVar3;
  iVar4 = *(int *)(iVar2 + 100);
  uVar3 = (uint)(iVar4 << 0xb < 0);
  if (iVar4 << 10 < 0) {
    uVar3 = uVar3 | 2;
  }
  if (iVar4 << 9 < 0) {
    uVar3 = uVar3 | 4;
  }
  if (iVar4 << 8 < 0) {
    uVar3 = uVar3 | 0x200;
  }
  if (iVar4 << 7 < 0) {
    uVar3 = uVar3 | 0x400;
  }
  if (iVar4 << 6 < 0) {
    uVar3 = uVar3 | 0x800;
  }
  if (iVar4 << 5 < 0) {
    uVar3 = uVar3 | 8;
  }
  if (iVar4 << 4 < 0) {
    uVar3 = uVar3 | 0x10;
  }
  if (iVar4 << 3 < 0) {
    uVar3 = uVar3 | 0x20;
  }
  if (iVar4 << 2 < 0) {
    uVar3 = uVar3 | 0x40;
  }
  if (iVar4 << 1 < 0) {
    uVar3 = uVar3 | 0x80;
  }
  if (iVar4 < 0) {
    uVar3 = uVar3 | 0x100;
  }
  puVar1[1] = uVar3;
  puVar1[2] = (uint)(*(int *)(iVar2 + 100) << 0x18 < 0);
  puVar1[3] = 0;
  puVar1[4] = 200;
  puVar1[5] = 800;
  puVar1[6] = 0;
  puVar1[7] = 0;
  *(undefined1 *)(puVar1 + 8) = 0;
  FUN_080213d4(DAT_08016564,4,in_r3);
  return;
}



/* ===== FUN_080160f2 @ 080160f2 ===== */

undefined4 FUN_080160f2(uint param_1)

{
  int iVar1;
  
  iVar1 = DAT_08016558;
  if (param_1 == 0) {
    FUN_080214ec(DAT_08016558,2);
    FUN_08020bd0(5);
    FUN_08020bd0(6);
    FUN_08020bd0(7);
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    FUN_080213d4(DAT_08016564,2);
  }
  else if (param_1 == 2) {
    FUN_08016570(DAT_08016558);
  }
  else {
    if (1 < param_1) {
      return 0;
    }
    FUN_080163bc(DAT_08016558);
  }
  return 1;
}



/* ===== FUN_08016146 @ 08016146 ===== */

void FUN_08016146(void)

{
  undefined4 unaff_r7;
  
  FUN_08020bd0(0);
  FUN_08020fd6(DAT_0801655c,unaff_r7);
  return;
}



/* ===== FUN_08016178 @ 08016178 ===== */

/* WARNING: Removing unreachable block (ram,0x08021552) */
/* WARNING: Removing unreachable block (ram,0x08021558) */

void FUN_08016178(int param_1)

{
  undefined4 *puVar1;
  
  if ((int)(*(uint *)(param_1 + 8) << 0x1f) < 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffffe;
    puVar1 = DAT_08021598;
    *DAT_08021598 = 0;
    puVar1[1] = 0;
    *DAT_0802159c = 0;
    return;
  }
  return;
}



/* ===== FUN_0801618e @ 0801618e ===== */

undefined4 FUN_0801618e(byte *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar3 = param_2 & 0xc;
  if (uVar3 == 4) {
    FUN_0801b4ec(0);
  }
  else if (uVar3 == 8) {
    FUN_0801b544();
  }
  else if (uVar3 == 0xc) {
    FUN_0801b55c();
  }
  uVar1 = FUN_08020c96();
  uVar3 = *(uint *)(DAT_0801655c + 0x18) & 0xff;
  if (uVar3 < (uVar1 & 0xff)) {
    uVar3 = uVar1 & 0xff;
  }
  if (uVar3 < 2) {
    if (((param_1[4] & 3) == 3) && ((int)(param_2 << 0x1e) < 0)) {
      FUN_08020f58(DAT_0801655c,2);
    }
    if (((*param_1 & 3) == 3) && ((int)(param_2 << 0x1f) < 0)) {
      FUN_08020a8a(4,2,0);
    }
  }
  if ((param_2 & 0x300) == 0) {
    return param_4;
  }
  FUN_08020bd0(5);
  FUN_08020bd0(6);
  FUN_08020bd0(7);
  uVar2 = DAT_08016564;
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
  uVar2 = FUN_080213d4(uVar2,uVar4,param_4);
  return uVar2;
}



/* ===== FUN_08016234 @ 08016234 ===== */

void FUN_08016234(byte *param_1)

{
  char cVar1;
  char *pcVar2;
  uint *puVar3;
  byte bVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  bool bVar7;
  
  if ((int)((uint)param_1[8] << 0x1f) < 0) {
    if (param_1[0x20] == 0) {
      uVar6 = *(undefined4 *)(param_1 + 0x10);
      uVar5 = 0;
    }
    else {
      uVar6 = 0;
      uVar5 = *(undefined4 *)(param_1 + 0x14);
    }
    FUN_08021510(uVar5,uVar6);
  }
  bVar4 = FUN_08020c96();
  pcVar2 = DAT_08020ec0;
  bVar7 = bVar4 == 0;
  if (bVar7) {
    bVar4 = *param_1 & 5;
  }
  if (!bVar7 || bVar4 != 5) {
    return;
  }
  cVar1 = *DAT_08020ec0;
  bVar7 = cVar1 == '\0';
  if (bVar7) {
    cVar1 = DAT_08020ec0[1];
  }
  if (bVar7 && cVar1 == '\0') {
    *DAT_08020ec4 = 1;
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
    *(undefined4 *)(pcVar2 + 0x2c) = *(undefined4 *)(DAT_08020ec8 + 0xc);
    pcVar2[0x3c] = -0x18;
    pcVar2[0x3d] = '\x03';
    pcVar2[0x3e] = '\0';
    pcVar2[0x3f] = '\0';
    pcVar2[0x34] = -0x18;
    puVar3 = DAT_08020ecc;
    pcVar2[0x35] = '\x03';
    pcVar2[0x36] = '\0';
    pcVar2[0x37] = '\0';
    DAT_08020ecc[0xb] = 2999;
    *puVar3 = *puVar3 | 1;
    puVar3 = DAT_08020ed0;
    *DAT_08020ed0 = *DAT_08020ed0 & 0xfffffffe;
    puVar3[9] = 0;
    puVar3[4] = 0xfffffffe;
    puVar3[3] = puVar3[3] | 1;
    puVar3[0xb] = 1;
    *puVar3 = *puVar3 | 1;
  }
  return;
}



/* ===== FUN_08016272 @ 08016272 ===== */

void FUN_08016272(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_08020c96();
  uVar2 = *(uint *)(DAT_0801655c + 0x18) & 0xff;
  if (uVar2 < (uVar1 & 0xff)) {
    uVar2 = uVar1 & 0xff;
  }
  if (uVar2 < 8) {
    if ((int)((uint)(byte)param_1[1] << 0x1f) < 0) {
      FUN_08020f70(DAT_0801655c,8);
    }
    if ((*param_1 & 0x8001) == 0x8001) {
      FUN_08020a8a(10,8,0);
      return;
    }
  }
  return;
}



/* ===== FUN_080162b6 @ 080162b6 ===== */

void FUN_080162b6(uint *param_1)

{
  byte bVar1;
  
  param_1[6] = 0;
  param_1[7] = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  FUN_080213d4(DAT_08016564,4);
  bVar1 = FUN_08020c96();
  if ((bVar1 < 8) && ((*param_1 & 0x8001) == 0x8001)) {
    FUN_08020a8a(0xb,8,0);
    return;
  }
  return;
}



/* ===== FUN_080162f2 @ 080162f2 ===== */

undefined4 FUN_080162f2(byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = FUN_08020c96();
  uVar3 = *(uint *)(DAT_0801655c + 0x18) & 0xff;
  if (uVar3 < (uVar2 & 0xff)) {
    uVar3 = uVar2 & 0xff;
  }
  if (uVar3 < 7) {
    uVar3 = param_1[4] & 1;
    if ((param_1[4] & 1) != 0) {
      uVar3 = FUN_08020f90(DAT_0801655c,7);
    }
    uVar2 = *param_1 & 1;
    if ((*param_1 & 1) != 0) {
      uVar2 = FUN_08020a8a(0xc,7,0);
    }
    if ((*(int *)(param_1 + 0x18) != 0) && (uVar3 != 0 || uVar2 != 0)) {
      param_1[0x1c] = 0;
      param_1[0x1d] = 0;
      param_1[0x1e] = 0;
      param_1[0x1f] = 0;
      uVar1 = FUN_080213d4(DAT_08016564,0,param_4);
      return uVar1;
    }
  }
  return param_4;
}



/* ===== FUN_08016384 @ 08016384 ===== */

void FUN_08016384(uint *param_1,uint param_2)

{
  byte bVar1;
  
  param_1[3] = param_1[3] & ~(1 << (param_2 & 0xff));
  if (((param_2 == 2) && (bVar1 = FUN_08020c96(), bVar1 < 3)) && ((*param_1 & 0x4001) == 0x4001)) {
    FUN_08020a8a(9,3,0);
    return;
  }
  return;
}



/* ===== FUN_080163bc @ 080163bc ===== */

void FUN_080163bc(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_08020c96();
  uVar2 = *(uint *)(DAT_0801655c + 0x18) & 0xff;
  if (uVar2 < (uVar1 & 0xff)) {
    uVar2 = uVar1 & 0xff;
  }
  if (uVar2 < 9) {
    FUN_08020f90(DAT_0801655c,9);
    FUN_08020a8a(0xd,9,0);
    if (*(int *)(param_1 + 0x18) != 0) {
      *(undefined4 *)(param_1 + 0x1c) = 0;
      FUN_080213d4(DAT_08016564);
      return;
    }
  }
  return;
}



/* ===== FUN_080163f4 @ 080163f4 ===== */

void FUN_080163f4(byte *param_1)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = FUN_08020c96();
  if (((bVar1 < 8) && ((int)((uint)*param_1 << 0x1f) < 0)) &&
     (iVar2 = FUN_08020a8a(0xe,8,0), *(int *)(param_1 + 0x18) != 0 && iVar2 != 0)) {
    param_1[0x1c] = 0;
    param_1[0x1d] = 0;
    param_1[0x1e] = 0;
    param_1[0x1f] = 0;
    FUN_080213d4(DAT_08016564,0);
    return;
  }
  return;
}



/* ===== FUN_08016444 @ 08016444 ===== */

longlong FUN_08016444(uint *param_1,uint param_2,int param_3,uint param_4)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 < 1) {
    param_1[6] = param_1[6] & ~(1 << (param_2 & 0xff));
    return (ulonglong)param_4 << 0x20;
  }
  iVar2 = DAT_08016568 + param_2 * 0x24 + param_3 * 0xc;
  uVar1 = *(undefined1 *)(iVar2 + -0xb);
  if ((*param_1 & *(uint *)(iVar2 + -8)) == *(uint *)(iVar2 + -8)) {
    iVar3 = FUN_08020a8a(*(undefined1 *)(iVar2 + -0xc),uVar1,DAT_0801656c);
  }
  else {
    iVar3 = 0;
  }
  if ((param_1[1] & *(uint *)(iVar2 + -4)) == *(uint *)(iVar2 + -4)) {
    iVar2 = FUN_08020fa8(DAT_0801655c,uVar1,param_3,DAT_0801656c);
  }
  else {
    iVar2 = 0;
  }
  if (iVar2 != 0 || iVar3 != 0) {
    param_1[7] = iVar2 + iVar3;
    param_1[6] = 1 << (param_2 & 0xff) | param_1[6];
  }
  return CONCAT44(param_4,~-(uint)(iVar2 == 0 && iVar3 == 0) >> 0x1f);
}



/* ===== FUN_080164dc @ 080164dc ===== */

void FUN_080164dc(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & ~(1 << (param_2 & 0xff));
  return;
}



/* ===== FUN_080164ee @ 080164ee ===== */

undefined4 FUN_080164ee(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  
  bVar1 = FUN_08020c96();
  uVar3 = *(uint *)(DAT_0801655c + 0x18) & 0xff;
  if (uVar3 < bVar1) {
    uVar3 = (uint)bVar1;
  }
  if (uVar3 < 4) {
    uVar2 = FUN_08016444(param_1,param_2,param_3);
    return uVar2;
  }
  return 0;
}



/* ===== FUN_0801651c @ 0801651c ===== */

undefined4 FUN_0801651c(uint *param_1,int param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  if (0 < param_3) {
    iVar2 = DAT_08016568 + param_2 * 0x24 + param_3 * 0xc;
    puVar1 = (uint *)(iVar2 - 0xc);
    uVar3 = *(uint *)(iVar2 + -8);
    bVar4 = (*param_1 & uVar3) != uVar3;
    if (bVar4) {
      puVar1 = *(uint **)(iVar2 + -4);
      param_1 = (uint *)(param_1[1] & (uint)puVar1);
    }
    if (!bVar4 || param_1 == puVar1) {
      return 0;
    }
  }
  return 1;
}



/* ===== FUN_08016570 @ 08016570 ===== */

undefined4 FUN_08016570(void)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 unaff_r7;
  
  iVar2 = FUN_08020c80(0x11);
  if (iVar2 != 0) {
    uVar3 = FUN_08020bd0(0x11,unaff_r7);
    return uVar3;
  }
  bVar1 = FUN_08020c96();
  if (bVar1 < 9) {
    uVar3 = FUN_08020a8a(0x11,9,0,unaff_r7);
    return uVar3;
  }
  return unaff_r7;
}



/* ===== FUN_0801659e @ 0801659e ===== */

void FUN_0801659e(void)

{
  FUN_08020c80(0xb);
  return;
}



/* ===== FUN_080165a4 @ 080165a4 ===== */

void FUN_080165a4(uint *param_1,uint param_2)

{
  *param_1 = param_2 | *param_1;
  return;
}



/* ===== FUN_080165ac @ 080165ac ===== */

void FUN_080165ac(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = DAT_08016698;
  *(int *)(param_1 + 8) = param_2 + *DAT_08016694;
  FUN_080215a4(uVar1,param_1);
  FUN_080215c8(uVar1,param_1,param_4);
  return;
}



/* ===== FUN_080165ce @ 080165ce ===== */

void FUN_080165ce(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *DAT_08016698;
  if (iVar1 != 0) {
    if (iVar1 == param_1) {
      *DAT_08016698 = *(int *)(param_1 + 4);
    }
    else {
      do {
        iVar2 = iVar1;
        iVar1 = *(int *)(iVar2 + 4);
        if (iVar1 == 0) goto LAB_080165ec;
      } while (iVar1 != param_1);
      *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar1 + 4);
    }
  }
LAB_080165ec:
  *(undefined1 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}



/* ===== FUN_080165f4 @ 080165f4 ===== */

longlong FUN_080165f4(int param_1,int param_2,undefined4 param_3,uint param_4)

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



/* ===== FUN_0801661e @ 0801661e ===== */

void FUN_0801661e(int param_1,undefined4 *param_2,int param_3)

{
  if (param_3 != 0) {
    if ((code *)*param_2 != (code *)0x0) {
      (*(code *)*param_2)();
    }
    if (param_3 + -1 != 0) {
      FUN_080165ac(param_1,param_2[1]);
      *(int *)(param_1 + 0x10) = param_3 + -1;
      *(undefined4 **)(param_1 + 0x14) = param_2 + 2;
    }
  }
  return;
}



/* ===== FUN_08016644 @ 08016644 ===== */

void FUN_08016644(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  if (param_3 == 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x14) = param_2;
  *(int *)(param_1 + 0x10) = param_3;
  FUN_080165ac(param_1,param_4);
  return;
}



/* ===== FUN_08016650 @ 08016650 ===== */

void FUN_08016650(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar2 = DAT_08016698;
  piVar1 = DAT_08016694;
  while( true ) {
    piVar4 = (int *)*piVar2;
    if ((piVar4 == (int *)0x0) || (*piVar1 - piVar4[2] < 0)) break;
    *piVar2 = piVar4[1];
    piVar4[1] = 0;
    *(undefined1 *)(piVar4 + 3) = 0;
    iVar3 = (**(code **)(*piVar4 + 8))();
    if (iVar3 != 0) {
      FUN_080215c8(piVar2,iVar3);
    }
  }
  return;
}



/* ===== FUN_08016680 @ 08016680 ===== */

bool FUN_08016680(void)

{
  return *DAT_08016698 != 0;
}



/* ===== FUN_0801668a @ 0801668a ===== */

undefined4 FUN_0801668a(void)

{
  return *(undefined4 *)(*DAT_08016698 + 8);
}



/* ===== FUN_0801669c @ 0801669c ===== */

void FUN_0801669c(void)

{
  int iVar1;
  
  iVar1 = DAT_08016714;
  *(undefined4 *)(DAT_08016714 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  return;
}



/* ===== FUN_080166a6 @ 080166a6 ===== */

undefined4 FUN_080166a6(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_08016714;
  iVar2 = *(int *)(DAT_08016714 + 0x20) + 1;
  if (iVar2 == 0x10) {
    iVar2 = 0;
  }
  if (*(int *)(DAT_08016714 + 0x24) == iVar2) {
    return 1;
  }
  *(undefined2 *)(DAT_08016714 + iVar2 * 2) = param_1;
  *(int *)(iVar1 + 0x20) = iVar2;
  return 0;
}



/* ===== FUN_080166c6 @ 080166c6 ===== */

undefined2 FUN_080166c6(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_08016714;
  if (*(int *)(DAT_08016714 + 0x24) == *(int *)(DAT_08016714 + 0x20)) {
    return 0;
  }
  iVar2 = *(int *)(DAT_08016714 + 0x24) + 1;
  if (iVar2 == 0x10) {
    iVar2 = 0;
  }
  *(int *)(DAT_08016714 + 0x24) = iVar2;
  return *(undefined2 *)(iVar1 + iVar2 * 2);
}



/* ===== FUN_080166e4 @ 080166e4 ===== */

undefined4 FUN_080166e4(void)

{
  if (*(int *)(DAT_08016714 + 0x24) == *(int *)(DAT_08016714 + 0x20)) {
    return 0;
  }
  return 1;
}



/* ===== FUN_080166f6 @ 080166f6 ===== */

undefined4 FUN_080166f6(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_r7;
  
  iVar1 = FUN_080166c6();
  if (iVar1 == 0) {
    return unaff_r7;
  }
  uVar2 = FUN_0801465c();
  uVar2 = FUN_0801618e(DAT_08016718,uVar2,unaff_r7);
  return uVar2;
}



/* ===== FUN_080167da @ 080167da ===== */

void FUN_080167da(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = DAT_08016870;
  puVar2 = DAT_08016870 + 4;
  puVar3 = (undefined4 *)*DAT_08016870;
  if ((undefined4 *)*DAT_08016870 == (undefined4 *)0x0) {
    *DAT_08016870 = puVar2;
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



/* ===== FUN_080167e8 @ 080167e8 ===== */

void FUN_080167e8(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = DAT_08016870;
  puVar2 = DAT_08016870 + 6;
  puVar3 = (undefined4 *)*DAT_08016870;
  if ((undefined4 *)*DAT_08016870 == (undefined4 *)0x0) {
    *DAT_08016870 = puVar2;
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



/* ===== FUN_080167f6 @ 080167f6 ===== */

void FUN_080167f6(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = DAT_08016870;
  puVar2 = DAT_08016870 + 10;
  puVar3 = (undefined4 *)*DAT_08016870;
  if ((undefined4 *)*DAT_08016870 == (undefined4 *)0x0) {
    *DAT_08016870 = puVar2;
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



/* ===== FUN_08016804 @ 08016804 ===== */

void FUN_08016804(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = DAT_08016870;
  puVar2 = DAT_08016870 + 0xc;
  puVar3 = (undefined4 *)*DAT_08016870;
  if ((undefined4 *)*DAT_08016870 == (undefined4 *)0x0) {
    *DAT_08016870 = puVar2;
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



/* ===== FUN_08016812 @ 08016812 ===== */

void FUN_08016812(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = DAT_08016870;
  puVar2 = DAT_08016870 + 0xe;
  puVar3 = (undefined4 *)*DAT_08016870;
  if ((undefined4 *)*DAT_08016870 == (undefined4 *)0x0) {
    *DAT_08016870 = puVar2;
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



/* ===== FUN_08016820 @ 08016820 ===== */

void FUN_08016820(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = DAT_08016870;
  puVar2 = DAT_08016870 + 0x10;
  puVar3 = (undefined4 *)*DAT_08016870;
  if ((undefined4 *)*DAT_08016870 == (undefined4 *)0x0) {
    *DAT_08016870 = puVar2;
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



/* ===== FUN_0801682e @ 0801682e ===== */

void FUN_0801682e(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = DAT_08016870;
  puVar2 = DAT_08016870 + 0x12;
  puVar3 = (undefined4 *)*DAT_08016870;
  if ((undefined4 *)*DAT_08016870 == (undefined4 *)0x0) {
    *DAT_08016870 = puVar2;
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



/* ===== FUN_08016844 @ 08016844 ===== */

void FUN_08016844(void)

{
  *(undefined1 *)(DAT_08016870 + 4) = 0;
  return;
}



/* ===== FUN_0801684c @ 0801684c ===== */

undefined4 FUN_0801684c(void)

{
  undefined4 *puVar1;
  undefined4 in_r3;
  undefined4 *unaff_r4;
  
  puVar1 = DAT_08016870;
  if (*(char *)(DAT_08016870 + 1) != '\0') {
    unaff_r4 = (undefined4 *)*DAT_08016870;
  }
  if (*(char *)(DAT_08016870 + 1) != '\0' && unaff_r4 != (undefined4 *)0x0) {
    FUN_08014786(unaff_r4[1]);
    *(undefined1 *)(puVar1 + 1) = 0;
    *puVar1 = *unaff_r4;
    *unaff_r4 = 0;
  }
  return in_r3;
}



/* ===== FUN_080168e8 @ 080168e8 ===== */

int FUN_080168e8(undefined1 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 *local_1c;
  int local_18;
  int local_14;
  undefined4 *local_10;
  undefined4 uStack_4;
  
  local_10 = &uStack_4;
  local_14 = 0;
  if (param_2 == 0) {
    local_1c = (undefined1 *)0x0;
    local_18 = 0;
  }
  else {
    local_18 = param_2 + -1;
    local_1c = param_1;
  }
  uStack_4 = param_4;
  iVar1 = FUN_0802164e((int)&DAT_08016928 + DAT_08016928,&local_1c,param_3,&local_10,0);
  if (local_1c != (undefined1 *)0x0) {
    *local_1c = 0;
  }
  if (-1 < iVar1) {
    iVar1 = local_14;
  }
  return iVar1;
}



/* ===== FUN_0801692c @ 0801692c ===== */

undefined8 FUN_0801692c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_10;
  undefined1 local_f;
  undefined2 uStack_e;
  undefined4 uStack_c;
  
  uStack_e = (undefined2)((uint)param_3 >> 0x10);
  uStack_c = param_4;
  switch(param_3) {
  case 1:
    local_10 = 0x4a;
    local_f = 0x7f;
    iVar1 = FUN_080179f8(0x1c);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_08022628(iVar1,param_1,&local_10,0x70);
    }
    FUN_08017a48(param_1,uVar2);
    local_10 = 0;
    local_f = 0x35;
    iVar1 = FUN_080179f8(0x1c);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = FUN_0802263c(iVar1,param_1,&local_10,0x71);
    }
    break;
  case 2:
    local_10 = 0x4a;
    local_f = 0x7f;
    iVar1 = FUN_080179f8(0x1c);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = FUN_08022650(iVar1,param_1,&local_10,0x73);
    }
    FUN_08017a48(param_1,uVar2);
    local_10 = 0;
    local_f = 0x35;
    iVar1 = FUN_080179f8(0x1c);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = FUN_08022664(iVar1,param_1,&local_10,0x74);
    }
    break;
  case 3:
    local_10 = 0x4a;
    local_f = 0x7f;
    iVar1 = FUN_080179f8(0x1c);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = FUN_08022664(iVar1,param_1,&local_10,0x74);
    }
    FUN_08017a48(param_1,uVar2);
    local_10 = 0;
    local_f = 0x35;
    iVar1 = FUN_080179f8(0x1c);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = FUN_08022650(iVar1,param_1,&local_10,0x73);
    }
    break;
  case 4:
    local_10 = 0x4a;
    local_f = 0x7f;
    iVar1 = FUN_080179f8(0x1c);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = FUN_08022678(iVar1,param_1,&local_10,0x75);
    }
    FUN_08017a48(param_1,uVar2);
    local_10 = 0;
    local_f = 0x35;
    iVar1 = FUN_080179f8(0x1c);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = FUN_0802268c(iVar1,param_1,&local_10,0x76);
    }
    break;
  case 5:
    local_10 = 0x25;
    local_f = 0x5b;
    iVar1 = FUN_080179f8(0x1c);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = FUN_0802268c(iVar1,param_1,&local_10,0x76);
    }
    break;
  default:
    local_10 = 0x25;
    local_f = 0x5b;
    iVar1 = FUN_080179f8(0x1c);
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = FUN_080226a0(iVar1,param_1,&local_10,0x72);
    }
  }
  FUN_08017a48(param_1,uVar2);
  iVar1 = DAT_08016ac8;
  if (*(int *)(DAT_08016ac8 + 0x28) != 0) {
    *(undefined1 *)(param_1 + 0x16) = *(undefined1 *)(param_1 + 0x15);
    *(undefined1 *)(param_1 + 0x17) = 0;
    *(undefined1 *)(param_1 + 0x18) = 0;
    iVar1 = *(int *)(iVar1 + 0x28);
    *(undefined1 *)(iVar1 + 9) = 1;
    *(undefined1 *)(iVar1 + 10) = 1;
  }
  return CONCAT44(uStack_c,CONCAT22(uStack_e,CONCAT11(local_f,local_10)));
}



/* ===== FUN_08016af8 @ 08016af8 ===== */

undefined4 FUN_08016af8(int param_1,int param_2)

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



/* ===== FUN_08016b8e @ 08016b8e ===== */

void FUN_08016b8e(void)

{
  *DAT_080177d8 = 0x800;
  return;
}



/* ===== FUN_08016b94 @ 08016b94 ===== */

void FUN_08016b94(void)

{
  *DAT_08017698 = 0x800;
  return;
}



/* ===== FUN_08016c5a @ 08016c5a ===== */

uint FUN_08016c5a(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  FUN_08022978();
  puVar1 = DAT_080176e8;
  DAT_080176e8[3] = DAT_080176e8[3] | 0x40000000;
  uVar3 = puVar1[3];
  *DAT_080176ec = *DAT_080176ec & 0xfffffffe;
  puVar1[3] = puVar1[3] & 0xbfffffff;
  *puVar1 = *puVar1 & 0xffffdfff;
  puVar2 = DAT_080176f0;
  *DAT_080176f0 = 0x700;
  *puVar2 = 0x80;
  FUN_0801831c();
  UNRECOVERED_JUMPTABLE = *(code **)(DAT_08017484 + 0x74);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    return uVar3 & 0x40000000;
  }
                    /* WARNING: Could not recover jumptable at 0x08016cb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*UNRECOVERED_JUMPTABLE)(2,UNRECOVERED_JUMPTABLE,uVar3 & 0x40000000);
  return uVar3;
}



/* ===== FUN_08016cb8 @ 08016cb8 ===== */

void FUN_08016cb8(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *DAT_08017608 = *DAT_08017608 & DAT_08017604 | 1;
  puVar1 = DAT_080176f4;
  *DAT_080176f4 = 2;
  uVar2 = DAT_080177dc;
  puVar1[1] = puVar1[1] | 2;
  puVar1[4] = uVar2;
  puVar1[2] = puVar1[2] & 0xffff0000 | 6;
  puVar1[1] = puVar1[1] | 1;
  FUN_080165ac(DAT_08017964,0x4000);
  FUN_0801b652();
  FUN_080165ac(DAT_0801da34,0);
  return;
}



/* ===== FUN_08016d0c @ 08016d0c ===== */

undefined4 FUN_08016d0c(void)

{
  uint uVar1;
  uint *puVar2;
  undefined4 unaff_r7;
  
  FUN_0801d7fa();
  FUN_08015666();
  FUN_0801b6d4();
  puVar2 = DAT_080177e0;
  uVar1 = DAT_08017604;
  DAT_080177e0[1] = DAT_080177e0[1] & DAT_08017604 | 0x10;
  *puVar2 = *puVar2 & 0xfffffffb;
  puVar2[1] = uVar1 & puVar2[1] | 2;
  puVar2 = DAT_080177e4;
  *DAT_080177e4 = *DAT_080177e4 & 0xfffffffe;
  *puVar2 = *puVar2 & 0xfffffffd;
  FUN_080165ce(DAT_08017484);
  *DAT_080177d4 = 0;
  return unaff_r7;
}



/* ===== FUN_08016d64 @ 08016d64 ===== */

void FUN_08016d64(void)

{
  uint *puVar1;
  
  FUN_0801b4ca(1);
  FUN_0801b4ec(0);
  FUN_08017cb8();
  puVar1 = DAT_08017968;
  *DAT_08017968 = *DAT_08017968 | 0x20000000;
  FUN_08023d24(*puVar1 & 0x20000000);
  return;
}



/* ===== FUN_08016d94 @ 08016d94 ===== */

undefined4 FUN_08016d94(void)

{
  undefined4 unaff_r7;
  
  FUN_0801b4ca(0);
  FUN_08017cc2();
  FUN_08023d24();
  *DAT_08017968 = *DAT_08017968 & 0xdfffffff;
  return unaff_r7;
}



/* ===== FUN_08016db2 @ 08016db2 ===== */

void FUN_08016db2(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  
  puVar2 = DAT_080177e8;
  DAT_080177e8[0xf] = DAT_080177e8[0xf] & 0xfff8ffff | 0x20000;
  puVar1 = DAT_080176f0;
  *puVar2 = *puVar2 | 0x10000;
  *puVar1 = 8;
  return;
}



/* ===== FUN_08016dd2 @ 08016dd2 ===== */

void FUN_08016dd2(void)

{
  uint *puVar1;
  
  *DAT_080176e4 = 8;
  puVar1 = DAT_080177e8;
  *DAT_080177e8 = *DAT_080177e8 & 0xfffeffff;
  puVar1[0xf] = puVar1[0xf] & 0xfff8ffff | 0x30000;
  return;
}



/* ===== FUN_08016df2 @ 08016df2 ===== */

undefined4 FUN_08016df2(void)

{
  undefined4 unaff_r7;
  
  FUN_08023d78();
  *DAT_080176e4 = 0x10;
  return unaff_r7;
}



/* ===== FUN_08016e02 @ 08016e02 ===== */

void FUN_08016e02(void)

{
  *DAT_080176f0 = 0x10;
  FUN_08023d78();
  return;
}



/* ===== FUN_08016e14 @ 08016e14 ===== */

uint FUN_08016e14(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  
  puVar2 = DAT_08017908;
  *DAT_08017908 = 8;
  uVar5 = DAT_0801790c;
  puVar2[1] = puVar2[1] | 8;
  puVar2[2] = puVar2[2] & uVar5 | 0x80000000;
  puVar1 = DAT_080176f4;
  do {
  } while ((int)puVar2[2] < 0);
  *DAT_080176f4 = 0x10;
  *puVar1 = 0x80;
  *puVar1 = 0x20;
  *puVar1 = 0x40;
  puVar1[6] = puVar1[6] | 8;
  puVar1[6] = puVar1[6] | 2;
  puVar1[6] = puVar1[6] | 4;
  puVar1[7] = puVar1[7] & 0xffff0000 | 0x80;
  puVar1[6] = puVar1[6] | 1;
  uVar5 = DAT_08017604;
  puVar2[2] = puVar2[2] & DAT_08017604 | 1;
  puVar2[2] = puVar2[2] & uVar5 | 8;
  puVar2[2] = uVar5 & puVar2[2] | 4;
  puVar3 = DAT_0801796c;
  *DAT_0801796c = *DAT_0801796c | 0x20;
  puVar4 = DAT_08017970;
  uVar5 = *puVar3;
  *DAT_08017970 = *DAT_08017970 | 2;
  puVar4[3] = puVar4[3] | 1;
  do {
  } while (-1 < (int)(puVar4[3] << 0x1f));
  puVar4[3] = puVar4[3] & 0xfffffff9 | 4;
  FUN_08023d94();
  *DAT_08017974 = 0x800;
  return uVar5 & 0x20;
}



/* ===== FUN_08016ee4 @ 08016ee4 ===== */

void FUN_08016ee4(void)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = DAT_08017978;
  *DAT_08017698 = 0x800;
  FUN_08023dae();
  FUN_08023ec4(iVar2);
  do {
  } while (*(int *)(iVar2 + 0x10) << 0x1f < 0);
  *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) & 0xfffffffd;
  *(uint *)(iVar2 + 4) = *(uint *)(iVar2 + 4) | 2;
  *DAT_0801796c = *DAT_0801796c & 0xffffffdf;
  puVar3 = DAT_0801797c;
  uVar1 = DAT_08017604;
  DAT_0801797c[1] = DAT_0801797c[1] & DAT_08017604 | 0x10;
  puVar3[1] = puVar3[1] & uVar1 | 0x20;
  *puVar3 = *puVar3 & 0xfffffffb;
  puVar3[1] = uVar1 & puVar3[1] | 2;
  puVar3 = DAT_08017980;
  *DAT_08017980 = *DAT_08017980 & 0xfffffffe;
  *puVar3 = *puVar3 & 0xfffffff7;
  *puVar3 = *puVar3 & 0xfffffffd;
  *puVar3 = *puVar3 & 0xfffffffb;
  return;
}



/* ===== FUN_08016f8c @ 08016f8c ===== */

undefined4 FUN_08016f8c(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_r7;
  
  *DAT_0801798c = 0x10000;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  iVar1 = FUN_08022a56();
  FUN_0802e744(iVar1 + 0x4c);
  FUN_0802e2a8();
  FUN_0802dd06();
  uVar2 = FUN_08022a56();
  FUN_0802d978(uVar2,0);
  uVar2 = FUN_08022a56();
  FUN_0802d930(uVar2,0);
  FUN_0801b05a();
  *(uint *)(DAT_08023e4c + 8) = *(uint *)(DAT_08023e4c + 8) & 0xffffefdf | 0x20;
  return unaff_r7;
}



/* ===== FUN_08016fa4 @ 08016fa4 ===== */

void FUN_08016fa4(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint in_fpscr;
  float fVar4;
  float fVar5;
  float fVar6;
  
  iVar1 = DAT_08017484;
  iVar3 = param_1 - *(uint *)(DAT_08017484 + 0x78);
  if (-1 < iVar3) {
    uVar2 = *(uint *)(DAT_08017484 + 0x78);
    if (1 < iVar3) {
      uVar2 = param_1;
    }
    param_1 = uVar2;
  }
  *(uint *)(DAT_08017484 + 0x78) = param_1;
  if (param_1 < 0xe47) {
    if (param_1 < 0xdfc) {
      if (param_1 < 0xd93) {
        fVar4 = DAT_08017330;
        if (param_1 < 0xce5) goto LAB_08017092;
        fVar5 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        fVar4 = DAT_08017338;
        fVar6 = DAT_08017334;
      }
      else {
        fVar5 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
        fVar4 = DAT_0801732c;
        fVar6 = DAT_08017328;
      }
    }
    else {
      fVar5 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      if (param_1 < 0xe29) {
        fVar4 = DAT_0801724c;
        fVar6 = DAT_08017248;
        goto LAB_08017052;
      }
      fVar4 = DAT_08017244;
      fVar6 = DAT_08017240;
    }
  }
  else if (param_1 < 0xf14) {
    fVar5 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    if (param_1 < 0xe7e) {
      fVar4 = DAT_0801723c;
      fVar6 = DAT_08017238;
      goto LAB_08017052;
    }
    fVar4 = DAT_08017234;
    fVar6 = DAT_08017230;
  }
  else {
    if (param_1 < 0x101d) {
      fVar5 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
      fVar4 = DAT_0801722c;
      fVar6 = DAT_08017228;
LAB_08017052:
      fVar4 = fVar4 + fVar5 * fVar6;
      goto LAB_08017092;
    }
    fVar4 = DAT_0801721c;
    if (0x1067 < param_1) goto LAB_08017092;
    fVar5 = (float)VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
    fVar4 = DAT_08017224;
    fVar6 = DAT_08017220;
  }
  fVar4 = fVar4 + fVar5 * fVar6;
LAB_08017092:
  *(float *)(iVar1 + 0x70) = fVar4;
  return;
}



/* ===== FUN_08017098 @ 08017098 ===== */

void FUN_08017098(undefined1 param_1)

{
  undefined4 uVar1;
  undefined4 unaff_r7;
  
  *(undefined1 *)(DAT_08017964 + 0x11) = param_1;
  uVar1 = FUN_08016af8();
  FUN_08017ce2(uVar1,unaff_r7);
  return;
}



/* ===== thunk_FUN_0801769c @ 080170ae ===== */

void thunk_FUN_0801769c(void)

{
  int iVar1;
  
  iVar1 = DAT_08017964;
  *(undefined1 *)(DAT_08017964 + 0x11) = 1;
  FUN_08016af8(iVar1,1);
  FUN_08017ce2();
  *(undefined4 *)(iVar1 + 0x74) = DAT_080179d4;
  FUN_0802407c(iVar1 + 0x40,0);
  return;
}



/* ===== FUN_080170b0 @ 080170b0 ===== */

void FUN_080170b0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  FUN_08017098(4);
  iVar1 = DAT_08017964;
  *(undefined1 **)(DAT_08017964 + 0x74) = &LAB_08017250_1;
  FUN_0802407c(iVar1 + 0x40,7);
  FUN_08016272(DAT_08017990);
  disableIRQinterrupts();
  uVar3 = *DAT_08017994;
  uVar4 = DAT_08017994[1];
  enableIRQinterrupts();
  uVar2 = FUN_08017dbe();
  FUN_080181c8(uVar3,uVar4,uVar2,1);
  FUN_080181c8(uVar3,uVar4,uVar2,3);
  return;
}



/* ===== FUN_080170c8 @ 080170c8 ===== */

void FUN_080170c8(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  FUN_08017098(6);
  iVar1 = DAT_08017964;
  *(undefined **)(DAT_08017964 + 0x74) = &DAT_0801740d;
  FUN_08023fea();
  FUN_0802407c(iVar1 + 0x40,7);
  FUN_08016272(DAT_08017990);
  disableIRQinterrupts();
  uVar3 = *DAT_08017994;
  uVar4 = DAT_08017994[1];
  enableIRQinterrupts();
  uVar2 = FUN_08017dbe();
  FUN_080181c8(uVar3,uVar4,uVar2,1);
  FUN_080181c8(uVar3,uVar4,uVar2,3);
  return;
}



/* ===== FUN_08017122 @ 08017122 ===== */

void FUN_08017122(uint param_1)

{
  int iVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  
  puVar3 = DAT_0801799c;
  piVar2 = DAT_08017998;
  iVar1 = DAT_08017484;
  if (param_1 == 1) {
    FUN_080166a6(0x1003);
LAB_0801713a:
    FUN_080170b0();
  }
  else {
    if (param_1 == 0) goto LAB_0801713e;
    if (param_1 == 3) {
      if (*DAT_08017998 == 0x5a5a) {
        *DAT_0801799c = *DAT_0801799c | 0x100;
        *piVar2 = 0;
        *puVar3 = *puVar3 & 0xfffffeff;
        FUN_080166a6(0x1003);
        if (0xe74 < *(ushort *)(iVar1 + 0x38)) {
          FUN_080170c8();
          goto LAB_0801713e;
        }
        goto LAB_0801713a;
      }
      iVar4 = FUN_080241fe(0x40);
      if (iVar4 == 0) {
        *(undefined1 *)(iVar1 + 0x11) = 3;
        FUN_08016af8(iVar1,3);
        FUN_08017ce2();
        *(undefined **)(iVar1 + 0x74) = &DAT_080171bd;
        goto LAB_0801713e;
      }
      iVar4 = *(int *)(iVar1 + 0x7c) + -1;
      *(int *)(iVar1 + 0x7c) = iVar4;
      if (0 < iVar4) {
        return;
      }
    }
    else if (2 < param_1) goto LAB_0801713e;
    thunk_FUN_0801769c();
  }
LAB_0801713e:
  *(undefined4 *)(DAT_08017484 + 0x7c) = 8;
  return;
}



/* ===== FUN_080175e8 @ 080175e8 ===== */

undefined2 FUN_080175e8(int param_1)

{
  return *(undefined2 *)(DAT_08017964 + param_1 * 2 + 0x34);
}



/* ===== FUN_080175f4 @ 080175f4 ===== */

void FUN_080175f4(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_080179c0;
  *DAT_080179c0 = 0;
  puVar1[1] = 0;
  return;
}



/* ===== FUN_0801760c @ 0801760c ===== */

void FUN_0801760c(void)

{
  undefined4 *puVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  
  puVar3 = DAT_080179c4;
  iVar2 = DAT_08017964;
  *DAT_080179c4 = *DAT_080179c4 | 0x800;
  puVar3[2] = puVar3[2] | 0x8000;
  FUN_0802407c(iVar2 + 0x40,2);
  puVar1 = DAT_080179c0;
  *DAT_080179c8 = *DAT_080179c8 | 0x70;
  *puVar1 = 0;
  *(undefined1 *)(iVar2 + 0x11) = 0;
  FUN_08016af8(iVar2);
  FUN_08017ce2();
  iVar5 = DAT_080176c4;
  *(undefined4 *)(iVar2 + 0x74) = DAT_080179b0;
  uVar4 = *(uint *)(iVar5 + 8);
  *(uint *)(iVar5 + 8) = uVar4 | 0x200000;
  if ((int)(uVar4 << 0xb) < 0) {
    DAT_080177d8[4] = 0x2000;
  }
  else {
    *DAT_080177d8 = 0x2000;
  }
  *DAT_080179cc = *DAT_080179cc | 0x800000;
  iVar5 = FUN_08023af0(DAT_080179d0);
  puVar1 = DAT_08016870;
  if (iVar5 == 0) {
    return;
  }
  piVar6 = (int *)*DAT_08016870;
  if ((int *)*DAT_08016870 == (int *)0x0) {
    *DAT_08016870 = DAT_08016870 + 2;
    puVar1[2] = 0;
LAB_080167d6:
    puVar1[3] = 0x21;
  }
  else {
    while ((piVar6[1] & 0xff00U) != 0) {
      if ((int *)*piVar6 == (int *)0x0) {
        *piVar6 = (int)(DAT_08016870 + 2);
        puVar1[2] = 0;
        goto LAB_080167d6;
      }
      piVar6 = (int *)*piVar6;
    }
  }
  return;
}



/* ===== FUN_0801769c @ 0801769c ===== */

void FUN_0801769c(void)

{
  int iVar1;
  
  iVar1 = DAT_08017964;
  *(undefined1 *)(DAT_08017964 + 0x11) = 1;
  FUN_08016af8(iVar1,1);
  FUN_08017ce2();
  *(undefined4 *)(iVar1 + 0x74) = DAT_080179d4;
  FUN_0802407c(iVar1 + 0x40,0);
  return;
}



/* ===== FUN_080176c8 @ 080176c8 ===== */

undefined4 FUN_080176c8(void)

{
  if (*DAT_08017994 - *DAT_080179d8 < 1) {
    return 0;
  }
  return 1;
}



/* ===== FUN_080176f8 @ 080176f8 ===== */

undefined4 FUN_080176f8(void)

{
  uint *puVar1;
  uint *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  undefined4 in_r3;
  int *unaff_r4;
  int iVar7;
  bool bVar8;
  
  disableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  iVar6 = FUN_08024278();
  bVar8 = iVar6 != 0;
  if (!bVar8) {
    iVar6 = DAT_080179c0[1];
    unaff_r4 = DAT_080179c0;
  }
  if (bVar8 || iVar6 != 0) goto LAB_080177ca;
  iVar7 = *DAT_08017994;
  iVar6 = FUN_08016680();
  if (iVar6 == 0) {
LAB_0801772e:
    iVar6 = 0x4000;
  }
  else {
    iVar6 = FUN_0801668a();
    iVar6 = iVar6 - iVar7;
    if (iVar6 < 1) goto LAB_080177ca;
    if (0x4000 < iVar6) goto LAB_0801772e;
  }
  puVar4 = DAT_080179dc;
  piVar3 = DAT_080179d8;
  puVar2 = DAT_080179c4;
  *DAT_080179d8 = iVar7 + iVar6;
  piVar3[1] = 0;
  piVar5 = DAT_080179e0;
  do {
    *puVar4 = 1;
    if (*unaff_r4 == 0) {
      if (*piVar5 == 0) {
        puVar2[2] = puVar2[2] & 0xfffffffc | 1;
        *puVar2 = *puVar2 & 0xfffffffe;
        do {
        } while ((int)((*puVar2 >> 1) << 0x1f) < 0);
        *DAT_0801799c = *DAT_0801799c & 0xfffffff8;
        puVar1 = DAT_080179bc;
        *DAT_080179bc = *DAT_080179bc | 4;
        DataSynchronizationBarrier(0xf);
        InstructionSynchronizationBarrier(0xf);
        WaitForInterrupt();
        *puVar1 = *puVar1 & 0xfffffffb;
        *puVar2 = *puVar2 | 1;
        do {
        } while (-1 < (int)(*puVar2 << 0x1e));
        puVar2[2] = puVar2[2] & 0xfffffffc;
        do {
        } while ((puVar2[2] & 0xc) != 0);
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
  } while (piVar3[1] == 0);
LAB_080177ca:
  enableIRQinterrupts();
  return in_r3;
}



/* ===== FUN_080177ec @ 080177ec ===== */

void FUN_080177ec(void)

{
  byte bVar1;
  bool bVar2;
  ushort *puVar3;
  undefined1 uVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined2 uVar9;
  uint uVar10;
  float fVar11;
  
  iVar8 = DAT_08017964;
  if (*(char *)(DAT_08017964 + 0x10) == '\0') {
    return;
  }
  *(undefined1 *)(DAT_08017964 + 0x10) = 0;
  uVar10 = DAT_080179e8;
  iVar7 = DAT_080179e4;
  *(short *)(iVar8 + 0x38) =
       (short)((ulonglong)((uint)*(ushort *)(DAT_080179e4 + 4) * 0x1e7b + 0xfff) *
               (ulonglong)DAT_080179e8 + (ulonglong)DAT_080179e8 >> 0x2c);
  puVar3 = DAT_080179f0;
  *(short *)(iVar8 + 0x3a) =
       (short)((ulonglong)((uint)*(ushort *)(iVar7 + 6) * 0x4d5f + DAT_080179ec) * (ulonglong)uVar10
               + (ulonglong)uVar10 >> 0x2c);
  uVar10 = ((uint)*puVar3 * 3000) / (uint)*(ushort *)(iVar7 + 8);
  *(short *)(iVar8 + 0x3c) = (short)uVar10;
  *(short *)(iVar8 + 0x3e) =
       (short)((int)(*(ushort *)(iVar7 + 10) * uVar10 * 100 - *(int *)(iVar8 + 100)) /
              *(int *)(iVar8 + 0x68));
  puVar5 = (undefined2 *)FUN_0802464c();
  if (puVar5 == (undefined2 *)0x0) {
    uVar9 = 0xce4;
  }
  else {
    fVar11 = *(float *)(puVar5 + 2);
    uVar9 = *puVar5;
    if (((0.0 <= fVar11) && (*(char *)(iVar8 + 0x12) == -1)) ||
       ((fVar11 < 0.0 && (*(char *)(iVar8 + 0x12) == '\x01')))) {
      *(undefined1 *)(iVar8 + 0x14) = 0;
    }
    if (0.0 <= fVar11) {
      uVar4 = 1;
    }
    else {
      uVar4 = 0xff;
    }
    *(undefined1 *)(iVar8 + 0x12) = uVar4;
  }
  uVar6 = FUN_08024ccc(iVar8 + 0x14,uVar9);
  *(short *)(iVar8 + 0x36) = (short)uVar6;
  if (*(code **)(iVar8 + 0x74) != (code *)0x0) {
    (**(code **)(iVar8 + 0x74))(3);
  }
  bVar1 = *(byte *)(iVar8 + 0x11);
  iVar7 = FUN_08016af8(iVar8,bVar1);
  FUN_08016fa4(uVar6);
  if ((*(float *)(puVar5 + 2) < 0.0) || (4 < bVar1)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  fVar11 = *(float *)(iVar8 + 0x70);
  iVar8 = FUN_08017902();
  if (4 < iVar8) {
    if ((iVar7 == 0x4000) && (DAT_08017e0c <= fVar11)) {
      fVar11 = DAT_08017e10;
    }
    FUN_08017ce2(iVar7);
  }
  iVar8 = DAT_08017e1c;
  *(float *)(DAT_08017e1c + 0x30) = fVar11;
  if (bVar2) {
    FUN_080157e4(fVar11,(*(uint *)(iVar8 + 0x10) & 0x7fff) >> 0xd);
    *(int *)(iVar8 + 0x34) = iVar7;
    return;
  }
  FUN_080157e4(fVar11,*(uint *)(iVar8 + 0x34) >> 0xd);
  return;
}



/* ===== FUN_080178f6 @ 080178f6 ===== */

void FUN_080178f6(void)

{
                    /* WARNING: Could not recover jumptable at 0x080178fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  if (*(code **)(DAT_08017964 + 0x74) == (code *)0x0) {
    return;
  }
  (**(code **)(DAT_08017964 + 0x74))();
  return;
}



/* ===== FUN_08017902 @ 08017902 ===== */

undefined1 FUN_08017902(void)

{
  return *(undefined1 *)(DAT_08017964 + 0x11);
}



/* ===== FUN_08017956 @ 08017956 ===== */

void FUN_08017956(void)

{
  *(undefined1 *)(DAT_08017964 + 0x10) = 1;
  *DAT_080179f4 = 0;
  return;
}



/* ===== FUN_080179f8 @ 080179f8 ===== */

void FUN_080179f8(undefined4 param_1)

{
  int iVar1;
  
  while (iVar1 = FUN_08024de4(param_1), iVar1 == 0) {
    if ((code *)*DAT_08017a18 == (code *)0x0) {
      thunk_FUN_0802f29a();
    }
    else {
      (*(code *)*DAT_08017a18)();
    }
  }
  return;
}



/* ===== FUN_08017a48 @ 08017a48 ===== */

undefined4 FUN_08017a48(int param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x15);
  if (cVar1 == 0x10) {
    return 0;
  }
  *(undefined4 *)(DAT_08017a68 + cVar1 * 4 + 0x28) = param_2;
  *(char *)(param_1 + 0x15) = cVar1 + '\x01';
  return 1;
}



/* ===== FUN_08017a6c @ 08017a6c ===== */

void FUN_08017a6c(int param_1)

{
  int *piVar1;
  
  if (*(char *)(param_1 + 0x14) < 1) {
    return;
  }
  piVar1 = *(int **)(DAT_08017a94 + *(char *)(param_1 + 0x14) * 4 + -4);
  (**(code **)(*piVar1 + 0xc))(piVar1);
  FUN_0802160c(piVar1);
  return;
}



/* ===== FUN_08017a98 @ 08017a98 ===== */

void FUN_08017a98(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = DAT_08017abc;
  param_1[1] = param_3;
  param_1[4] = param_2;
  param_1[3] = 0xffffffff;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_08017ac0;
  return;
}



/* ===== FUN_08017ac4 @ 08017ac4 ===== */

void FUN_08017ac4(int param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  if (param_2 + 1 < (int)*(char *)(param_1 + 0x14)) {
    puVar1 = (undefined4 *)(DAT_08017b14 + *(char *)(param_1 + 0x14) * 4);
    puVar3 = (undefined4 *)(DAT_08017b14 + param_2 * 4);
    while (puVar1 = puVar1 + -1, puVar3 < puVar1) {
      piVar2 = (int *)*puVar1;
      (**(code **)(*piVar2 + 0xc))(piVar2,1);
      FUN_0802160c(piVar2);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 4))(piVar2);
      }
      *puVar1 = 0;
    }
    *(char *)(param_1 + 0x14) = (char)param_2 + '\x01';
  }
  return;
}



/* ===== FUN_08017b18 @ 08017b18 ===== */

undefined4 * FUN_08017b18(undefined4 *param_1)

{
  FUN_08026250();
  *param_1 = DAT_08017b28;
  return param_1;
}



/* ===== FUN_08017b2c @ 08017b2c ===== */

undefined4 FUN_08017b2c(int param_1,int *param_2)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x14);
  if (cVar1 < 8) {
    *(int **)(DAT_08017b5c + cVar1 * 4) = param_2;
    *(char *)(param_1 + 0x14) = cVar1 + '\x01';
    (**(code **)(*param_2 + 8))(param_2,0);
    *(undefined1 *)(param_1 + 0x17) = *(undefined1 *)(param_1 + 0x16);
    return 1;
  }
  return 0;
}



/* ===== FUN_08017b60 @ 08017b60 ===== */

void FUN_08017b60(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = DAT_08017b84;
  param_1[1] = param_3;
  param_1[4] = param_2;
  param_1[3] = 0xffffffff;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_08017b88;
  return;
}



/* ===== FUN_08017b8c @ 08017b8c ===== */

void FUN_08017b8c(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = DAT_08017bb0;
  param_1[1] = param_3;
  param_1[4] = param_2;
  param_1[3] = 0xffffffff;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_08017bb4;
  return;
}



/* ===== FUN_08017bb8 @ 08017bb8 ===== */

undefined4 * FUN_08017bb8(undefined4 *param_1)

{
  FUN_08026250();
  *param_1 = DAT_08017bc8;
  return param_1;
}



/* ===== FUN_08017be4 @ 08017be4 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_08017be4(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  int iVar5;
  int iVar6;
  uint in_fpscr;
  float fVar7;
  float fVar8;
  int iStack_28;
  int iStack_24;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  undefined4 uStack_1a;
  undefined2 uStack_16;
  undefined2 uStack_14;
  ushort uStack_12;
  undefined2 uStack_10;
  undefined2 uStack_e;
  
  iVar2 = DAT_08017e18;
  piVar1 = DAT_08017e14;
  uStack_10 = (undefined2)unaff_r7;
  uStack_e = (undefined2)((uint)unaff_r7 >> 0x10);
  uStack_14 = (undefined2)unaff_r6;
  uStack_12 = (ushort)((uint)unaff_r6 >> 0x10);
  uStack_1a._2_2_ = (undefined2)unaff_r5;
  uStack_16 = (undefined2)((uint)unaff_r5 >> 0x10);
  uStack_1c = (undefined2)unaff_r4;
  uStack_1a._0_2_ = (undefined2)((uint)unaff_r4 >> 0x10);
  uStack_20 = (undefined2)param_4;
  uStack_1e = (undefined2)((uint)param_4 >> 0x10);
  iVar5 = *DAT_08017e14;
  iVar6 = *(int *)(DAT_08017e18 + 0x10);
  fVar7 = (float)FUN_08024884(param_1,*(undefined4 *)(DAT_08017e18 + 0x14));
  uVar4 = *(uint *)(param_1 + 0x10);
  if (param_2 == 0) {
    if ((*(char *)(param_1 + 0x18) != '\0') &&
       ((iVar5 - *(int *)(param_1 + 0x1c) < 0xf0000 ||
        (((((uint)(iVar6 - *(int *)(param_1 + 0x20)) < 10 &&
           (in_fpscr = in_fpscr & 0xfffffff, ABS(fVar7 - *(float *)(param_1 + 0x24)) < DAT_08017e04)
           ) && (ABS(*(float *)(DAT_08017e1c + 0x30) - *(float *)(param_1 + 0x28)) < 1.0)) &&
         (((*(uint *)(param_1 + 0x2c) ^ uVar4) & 0x6000) == 0)))))) {
      return CONCAT22(uStack_1e,uStack_20);
    }
  }
  else {
    if (param_2 == 2) goto LAB_08017c8a;
    if (1 < param_2) {
      return CONCAT22(uStack_1e,uStack_20);
    }
  }
  *(undefined1 *)(param_1 + 0x18) = 1;
  *(float *)(param_1 + 0x24) = fVar7;
  *(int *)(param_1 + 0x1c) = iVar5;
  *(int *)(param_1 + 0x20) = iVar6;
  uVar3 = *(undefined4 *)(DAT_08017e1c + 0x30);
  *(uint *)(param_1 + 0x2c) = uVar4;
  *(undefined4 *)(param_1 + 0x28) = uVar3;
  uVar4 = uVar4 | 0x1000;
LAB_08017c8a:
  disableIRQinterrupts();
  iStack_28 = *piVar1;
  iStack_24 = piVar1[1];
  enableIRQinterrupts();
  uStack_1a = (float)VectorUnsignedToFloat(iVar6,(byte)(in_fpscr >> 0x16) & 3);
  uStack_1a = uStack_1a * DAT_08017e08;
  uStack_1e = (undefined2)*(undefined4 *)(iVar2 + 0x1c);
  uStack_1c = (undefined2)((uint)*(undefined4 *)(iVar2 + 0x1c) >> 0x10);
  fVar7 = (fVar7 + 20.0) * DAT_080183f4;
  if (DAT_080183f0 <= fVar7) {
    fVar7 = DAT_080183f8;
  }
  else if (fVar7 < DAT_080183fc) {
    fVar7 = DAT_080183fc;
  }
  fVar8 = *(float *)(DAT_08017e1c + 0x30) * DAT_080183f4;
  uStack_16 = (undefined2)(int)fVar7;
  if (fVar8 < 0.0) {
    fVar8 = _UNK_08018400;
  }
  else if (DAT_080183f0 <= fVar8) {
    fVar8 = DAT_080183f8;
  }
  uStack_14 = (undefined2)(int)fVar8;
  uStack_12 = (ushort)uVar4 & 0xf0d8;
  uStack_10 = 0;
  uVar3 = FUN_080263ea(DAT_080184b4,&iStack_28,3);
  return uVar3;
}



/* ===== FUN_08017cb8 @ 08017cb8 ===== */

void FUN_08017cb8(void)

{
  FUN_080165ac(DAT_08017e1c,0x10000);
  return;
}



/* ===== FUN_08017cc2 @ 08017cc2 ===== */

void FUN_08017cc2(void)

{
  int iVar1;
  
  iVar1 = DAT_08017e1c;
  FUN_08017be4(DAT_08017e1c,1);
  *(undefined1 *)(iVar1 + 0x18) = 0;
  FUN_080165ce(iVar1);
  return;
}



/* ===== FUN_08017cdc @ 08017cdc ===== */

void FUN_08017cdc(undefined4 param_1)

{
  FUN_08017be4(DAT_08017e1c,param_1);
  return;
}



/* ===== FUN_08017ce2 @ 08017ce2 ===== */

undefined4 FUN_08017ce2(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  bool bVar4;
  
  bVar4 = (*(uint *)(DAT_08017e1c + 0x10) & 0x6000) == 0x4000;
  uVar1 = param_1 >> 0xd & 3;
  uVar2 = *(uint *)(DAT_08017e1c + 0x10) & 0xffff9fff | uVar1 << 0xd;
  *(uint *)(DAT_08017e1c + 0x10) = uVar2;
  if (bVar4 == (uVar1 == 2)) {
    return param_4;
  }
  if (bVar4) {
    uVar3 = 8;
  }
  else {
    uVar3 = 7;
  }
  disableIRQinterrupts();
  enableIRQinterrupts();
  uVar3 = FUN_080181c8(*DAT_08017e14,DAT_08017e14[1],uVar2,uVar3);
  return uVar3;
}



/* ===== FUN_08017d9a @ 08017d9a ===== */

void FUN_08017d9a(uint param_1,uint param_2)

{
  *(uint *)(DAT_08017e1c + 0x10) = param_1 & param_2 | *(uint *)(DAT_08017e1c + 0x10) & ~param_1;
  return;
}



/* ===== FUN_08017db2 @ 08017db2 ===== */

void FUN_08017db2(uint param_1)

{
  *(uint *)(DAT_08017e1c + 0x10) = *(uint *)(DAT_08017e1c + 0x10) & ~param_1;
  return;
}



/* ===== FUN_08017dbe @ 08017dbe ===== */

undefined4 FUN_08017dbe(void)

{
  return *(undefined4 *)(DAT_08017e1c + 0x10);
}



/* ===== FUN_08017dc4 @ 08017dc4 ===== */

uint FUN_08017dc4(uint param_1,uint param_2)

{
  return -(uint)((param_1 & (param_2 ^ *(uint *)(DAT_08017e1c + 0x10))) == 0) >> 0x1f;
}



/* ===== FUN_08017de6 @ 08017de6 ===== */

void FUN_08017de6(uint param_1)

{
  *(uint *)(DAT_08017e1c + 0x14) = param_1 | *(uint *)(DAT_08017e1c + 0x14);
  return;
}



/* ===== FUN_08017df0 @ 08017df0 ===== */

void FUN_08017df0(uint param_1)

{
  *(uint *)(DAT_08017e1c + 0x14) = *(uint *)(DAT_08017e1c + 0x14) & ~param_1;
  return;
}



/* ===== FUN_08017e58 @ 08017e58 ===== */

int FUN_08017e58(uint param_1,int param_2,uint param_3,int param_4)

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
  uVar4 = DAT_080184ac / param_3 >> (uVar3 & 0xff);
  lVar1 = (ulonglong)uVar4 * (ulonglong)param_1 +
          CONCAT44(uVar4 * param_2,0x8000 >> (-param_4 + 7U & 0xff));
  iVar2 = FUN_080262b0((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),0xf - uVar3);
  if (bVar5) {
    iVar2 = -iVar2;
  }
  return iVar2;
}



/* ===== FUN_08017eaa @ 08017eaa ===== */

undefined4 FUN_08017eaa(undefined4 param_1,int param_2,undefined4 param_3)

{
  if (*(char *)(param_2 + 8) == '\b') {
    return 0;
  }
  FUN_080262d4(param_1,param_2 + 10,param_3);
  return param_3;
}



/* ===== FUN_08017ec4 @ 08017ec4 ===== */

undefined4 FUN_08017ec4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  
  puVar1 = DAT_080184a4;
  *DAT_080184a4 = *DAT_080184a4 | 4;
  FUN_080262d4(puVar1 + 0xd,param_1,0x1b);
  *(undefined2 *)(puVar1 + 0xf) = 0;
  return param_4;
}



/* ===== FUN_08017ee8 @ 08017ee8 ===== */

void FUN_08017ee8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined4 local_10;
  undefined4 uStack_c;
  
  disableIRQinterrupts();
  local_1c = *DAT_080184b0;
  local_18 = DAT_080184b0[1];
  enableIRQinterrupts();
  local_14 = 7;
  local_13 = 0;
  local_12 = 0x11;
  local_11 = 0;
  uStack_c = param_4;
  local_10 = FUN_08017dbe();
  FUN_0802637a(DAT_080184a4,&local_1c,param_1,0,0,0,0);
  return;
}



/* ===== FUN_08017f38 @ 08017f38 ===== */

void FUN_08017f38(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined4 local_10;
  
  disableIRQinterrupts();
  local_1c = *DAT_080184b0;
  local_18 = DAT_080184b0[1];
  enableIRQinterrupts();
  local_14 = 7;
  local_13 = 0;
  local_12 = 0x11;
  local_11 = 0;
  local_10 = FUN_08017dbe();
  FUN_0802637a(DAT_080184a4,&local_1c,param_1,param_2,0,0,0);
  return;
}



/* ===== FUN_08017f8a @ 08017f8a ===== */

void FUN_08017f8a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined4 local_18;
  undefined4 uStack_14;
  
  disableIRQinterrupts();
  local_24 = *DAT_080184b0;
  local_20 = DAT_080184b0[1];
  enableIRQinterrupts();
  local_1c = 7;
  local_1b = 0;
  local_1a = 0x11;
  local_19 = 0;
  uStack_14 = param_4;
  local_18 = FUN_08017dbe();
  FUN_0802637a(DAT_080184a4,&local_24,param_1,param_2,param_3,0,0);
  return;
}



/* ===== FUN_08017fde @ 08017fde ===== */

void FUN_08017fde(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined4 local_18;
  
  disableIRQinterrupts();
  local_24 = *DAT_080184b0;
  local_20 = DAT_080184b0[1];
  enableIRQinterrupts();
  local_1c = 7;
  local_1b = 0;
  local_1a = 0x11;
  local_19 = 0;
  local_18 = FUN_08017dbe();
  FUN_0802637a(DAT_080184a4,&local_24,param_1,param_2,param_3,param_4,0);
  return;
}



/* ===== FUN_08018028 @ 08018028 ===== */

void FUN_08018028(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined4 local_18;
  
  disableIRQinterrupts();
  local_24 = *DAT_080184b0;
  local_20 = DAT_080184b0[1];
  enableIRQinterrupts();
  local_1c = 7;
  local_1b = 0;
  local_1a = 0x11;
  local_19 = 0;
  local_18 = FUN_08017dbe();
  FUN_0802637a(DAT_080184a4,&local_24,param_1,param_2,param_3,param_4,param_5);
  return;
}



/* ===== FUN_0801807e @ 0801807e ===== */

void FUN_0801807e(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_080184a8;
  iVar2 = DAT_080184a8[2];
  if (iVar2 == 0x80) {
    iVar2 = 0x7f;
  }
  DAT_080184a8[2] = iVar2 + 1;
  iVar2 = piVar1[1] + 1;
  if (0x7f < iVar2) {
    iVar2 = 0;
  }
  piVar1[1] = iVar2;
  FUN_080262d4(*piVar1 + iVar2 * 0x12,param_1,0x12);
  iVar2 = *piVar1 + piVar1[1] * 0x12;
  *(undefined1 *)(iVar2 + 8) = 1;
  *(undefined1 *)(iVar2 + 9) = 0;
  return;
}



/* ===== FUN_080180c4 @ 080180c4 ===== */

void FUN_080180c4(undefined4 param_1)

{
  FUN_080263ea(DAT_080184b4,param_1,2);
  return;
}



/* ===== FUN_080180d2 @ 080180d2 ===== */

void FUN_080180d2(undefined4 param_1)

{
  FUN_080263ea(DAT_080184b4,param_1,4);
  return;
}



/* ===== FUN_080180d8 @ 080180d8 ===== */

void FUN_080180d8(int param_1)

{
  char cVar1;
  uint uVar2;
  uint *puVar3;
  
  cVar1 = *(char *)(param_1 + 10);
  if (cVar1 != '\x03' && cVar1 != '\x06') {
    FUN_080263ea(DAT_080184b4,param_1,7);
    return;
  }
  puVar3 = DAT_080184a4 + 1;
  if (cVar1 == '\x03') {
    uVar2 = *DAT_080184a4 | 1;
  }
  else {
    if (cVar1 != '\x06') {
      return;
    }
    uVar2 = *DAT_080184a4 | 2;
    puVar3 = DAT_080184a4 + 7;
  }
  *DAT_080184a4 = uVar2;
  FUN_080262d4(puVar3,param_1,0x18);
  *(undefined1 *)(puVar3 + 2) = 7;
  *(undefined1 *)((int)puVar3 + 9) = 0;
  return;
}



/* ===== FUN_080181c8 @ 080181c8 ===== */

void FUN_080181c8(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_16;
  undefined1 local_15;
  uint local_14;
  
  local_16 = (undefined1)param_4;
  if ((param_4 != 3 && param_4 != 6) && (param_4 != 0x11 && param_4 != 0x12)) {
    param_3 = param_3 | 0x1000;
  }
  local_15 = 0;
  local_20 = param_1;
  local_1c = param_2;
  local_14 = param_3;
  FUN_080180d8(&local_20);
  return;
}



/* ===== FUN_080181f4 @ 080181f4 ===== */

void FUN_080181f4(undefined4 param_1,float param_2,undefined4 param_3,undefined4 param_4,
                 undefined1 param_5)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_16;
  undefined1 local_15;
  uint uStack_14;
  undefined4 local_10;
  undefined2 uStack_c;
  
  local_15 = 3;
  if (DAT_080184a0 <= param_2 * DAT_0801849c) {
    uStack_c = 0x3de;
  }
  else {
    uStack_c = (undefined2)(int)(param_2 * DAT_0801849c);
  }
  local_20 = param_3;
  local_1c = param_4;
  local_16 = param_5;
  local_10 = param_1;
  uStack_14 = FUN_08017dbe();
  uStack_14 = uStack_14 | 0x1000;
  FUN_080180d8(&local_20);
  return;
}



/* ===== FUN_08018234 @ 08018234 ===== */

void FUN_08018234(undefined4 param_1,float param_2,undefined4 param_3,undefined4 param_4,
                 undefined1 param_5)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_16;
  undefined1 local_15;
  uint local_14;
  undefined4 local_10;
  undefined2 local_c;
  
  local_15 = 0xc;
  if (DAT_080184a0 <= param_2 * DAT_0801849c) {
    local_c = 0x3de;
  }
  else {
    local_c = (undefined2)(int)(param_2 * DAT_0801849c);
  }
  local_20 = param_3;
  local_1c = param_4;
  local_16 = param_5;
  local_10 = param_1;
  local_14 = FUN_08017dbe();
  local_14 = local_14 | 0x1000;
  FUN_080180d8(&local_20);
  return;
}



/* ===== FUN_0801828e @ 0801828e ===== */

void FUN_0801828e(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined1 param_5)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_16;
  undefined1 local_15;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_15 = 0x30;
  local_20 = param_2;
  local_1c = param_3;
  local_16 = param_5;
  local_10 = param_4;
  local_c = param_1;
  local_14 = FUN_08017dbe();
  local_14 = local_14 | 0x1000;
  FUN_080180d8(&local_20);
  return;
}



/* ===== FUN_080182c4 @ 080182c4 ===== */

void FUN_080182c4(float param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  float fVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_16;
  undefined1 local_15;
  uint uStack_14;
  undefined2 local_10;
  
  fVar1 = (param_1 + 20.0) * DAT_080183f4;
  local_15 = 0x40;
  if (DAT_080183f0 <= fVar1) {
    fVar1 = DAT_080183f8;
  }
  else if (fVar1 < DAT_080183fc) {
    fVar1 = DAT_080183fc;
  }
  local_10 = (undefined2)(int)fVar1;
  local_20 = param_2;
  local_1c = param_3;
  local_16 = param_4;
  uStack_14 = FUN_08017dbe();
  uStack_14 = uStack_14 | 0x1000;
  FUN_080180d8(&local_20);
  return;
}



/* ===== FUN_0801831c @ 0801831c ===== */

void FUN_0801831c(void)

{
  int iVar1;
  
  iVar1 = DAT_080184a8;
  while (0 < *(int *)(iVar1 + 0x14)) {
    FUN_080184bc(iVar1 + 0xc);
  }
  return;
}



/* ===== FUN_08018404 @ 08018404 ===== */

undefined4 FUN_08018404(char *param_1,int param_2)

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
      bVar6 = SBORROW4(*(int *)(param_1 + 3),DAT_080184b8);
      iVar3 = *(int *)(param_1 + 3) - DAT_080184b8;
    }
    if (iVar3 < 0 == bVar6) {
      return 0;
    }
    uVar2 = (uint)(byte)param_1[2];
    if (uVar2 < 9) {
      if (uVar2 == 7) {
        if (param_1[1] != '\0') goto LAB_08018430;
        cVar1 = param_1[8];
        if (cVar1 == '\0') {
          uVar2 = 6;
        }
        else if (cVar1 == '\x03' || cVar1 == '\f') {
          uVar2 = 0xc;
        }
        else if (cVar1 == '0') {
          uVar2 = 0xe;
        }
        else {
          if (cVar1 != '@') goto LAB_08018430;
          uVar2 = 8;
        }
      }
      else {
        uVar2 = (uint)(byte)(&LAB_080185a4_1)[uVar2 * 2];
      }
    }
    else {
LAB_08018430:
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



/* ===== FUN_080184bc @ 080184bc ===== */

void FUN_080184bc(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_08026b00();
  switch(*(undefined1 *)(iVar1 + 8)) {
  case 2:
  case 5:
  case 6:
    uVar2 = *(uint *)(iVar1 + 0x18);
    break;
  case 3:
    uVar2 = *(uint *)(iVar1 + 0x16);
    break;
  case 4:
    uVar2 = *(uint *)(iVar1 + 0xe);
    break;
  case 7:
    if (1 < *(byte *)(iVar1 + 10) - 0x11) {
      uVar2 = *(uint *)(iVar1 + 0xc);
      break;
    }
    goto LAB_08018500;
  case 8:
    uVar2 = *(uint *)(iVar1 + 10);
    break;
  default:
    goto switchD_080184cc_default;
  }
  if ((uVar2 >> 0xc & 1) != 0) {
LAB_08018500:
    *(undefined1 *)(iVar1 + 9) = 0;
    switch(*(undefined1 *)(iVar1 + 8)) {
    case 2:
    case 5:
    case 6:
      *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | 0x8000;
      break;
    case 3:
      *(uint *)(iVar1 + 0x16) = *(uint *)(iVar1 + 0x16) | 0x8000;
      break;
    case 4:
      *(uint *)(iVar1 + 0xe) = *(uint *)(iVar1 + 0xe) | 0x8000;
      break;
    case 7:
      *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 0x8000;
      break;
    case 8:
      *(uint *)(iVar1 + 10) = *(uint *)(iVar1 + 10) | 0x8000;
    }
    FUN_08026b1e();
  }
switchD_080184cc_default:
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  return;
}



/* ===== FUN_08018560 @ 08018560 ===== */

void FUN_08018560(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 auStack_38 [8];
  undefined1 local_30;
  undefined4 uStack_14;
  
  uStack_14 = param_4;
  FUN_080270fa();
  while ((*(int *)(param_1 + 8) != 0x20 && (iVar1 = FUN_08026c8c(), iVar1 == 0))) {
    iVar1 = FUN_08026bdc(auStack_38);
    if (iVar1 == 0) {
      FUN_08027170(param_1,auStack_38,local_30);
    }
  }
  FUN_08027126();
  FUN_08026894(param_1,param_2,param_3);
  return;
}



/* ===== FUN_080185cc @ 080185cc ===== */

void FUN_080185cc(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = DAT_080185f0;
  param_1[1] = param_3;
  param_1[4] = param_2;
  param_1[3] = 0xffffffff;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_080185f4;
  return;
}



/* ===== FUN_08018658 @ 08018658 ===== */

void FUN_08018658(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = DAT_0801867c;
  param_1[1] = param_3;
  param_1[4] = param_2;
  param_1[3] = 0xffffffff;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_08018680;
  return;
}



/* ===== FUN_08018684 @ 08018684 ===== */

/* WARNING: Removing unreachable block (ram,0x080271c8) */
/* WARNING: Removing unreachable block (ram,0x080271d2) */

int FUN_08018684(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

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
  
  iVar6 = DAT_080186e4;
  cVar1 = *(char *)(param_1 + 0x18);
  iVar2 = (int)cVar1;
  if (iVar2 < 1) {
    cVar1 = *(char *)(param_1 + 0x15);
  }
  cVar1 = cVar1 + -1;
  iVar7 = (int)cVar1;
  if (iVar7 != iVar2) {
    iVar2 = *(int *)(DAT_080186e4 + 0x28 + iVar2 * 4);
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
        piVar3 = (int *)(DAT_08027214 + cVar5 * 4 + 0x28);
        iVar6 = 0;
        piVar4 = piVar3;
        while( true ) {
          iVar2 = *piVar4;
          *(int *)(iVar2 + 0xc) = iVar6;
          *(undefined1 *)(iVar2 + 10) = 1;
          if (piVar3 + iVar7 <= piVar4) break;
          iVar6 = iVar6 + *(int *)(*piVar4 + 0x10) + param_1;
          piVar4 = piVar4 + 1;
        }
      }
      return param_1;
    }
  }
  return param_4;
}



/* ===== FUN_080186e8 @ 080186e8 ===== */

/* WARNING: Removing unreachable block (ram,0x080271c8) */
/* WARNING: Removing unreachable block (ram,0x080271d2) */

void FUN_080186e8(int param_1)

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
  
  iVar9 = DAT_08018750;
  cVar6 = *(char *)(param_1 + 0x17);
  iVar7 = (int)cVar6;
  cVar1 = *(char *)(param_1 + 0x16);
  cVar2 = *(char *)(param_1 + 0x18);
  cVar3 = cVar2 + '\x01';
  if (cVar3 == *(char *)(param_1 + 0x15)) {
    cVar3 = '\0';
  }
  if ((int)cVar3 != (int)cVar2) {
    iVar8 = *(int *)(DAT_08018750 + 0x28 + cVar2 * 4);
    *(undefined1 *)(iVar8 + 9) = 0;
    *(undefined1 *)(iVar8 + 10) = 1;
    iVar9 = *(int *)(iVar9 + 0x28 + cVar3 * 4);
    *(undefined1 *)(iVar9 + 9) = 1;
    *(undefined1 *)(iVar9 + 10) = 1;
    iVar8 = (int)cVar3;
    *(char *)(param_1 + 0x18) = cVar3;
    *(undefined1 *)(param_1 + 0x14) = 1;
    bVar11 = SBORROW4(iVar8,iVar7);
    iVar9 = iVar8 - iVar7;
    if (iVar7 <= iVar8) {
      iVar9 = (int)(char)(cVar1 + cVar6 + -1);
      bVar11 = SBORROW4(iVar9,iVar8);
      iVar9 = iVar9 - iVar8;
    }
    if (iVar9 < 0 != bVar11) {
      iVar9 = (int)cVar3;
      if (0 < *(char *)(param_1 + 0x16)) {
        iVar8 = *(char *)(param_1 + 0x16) + -1;
        iVar10 = (int)cVar6;
        bVar11 = SBORROW4(iVar9,iVar10);
        iVar7 = iVar9 - iVar10;
        if (iVar10 <= iVar9) {
          iVar9 = iVar9 - iVar8;
          bVar11 = SBORROW4((int)cVar6,iVar9);
          iVar7 = cVar6 - iVar9;
        }
        if (iVar7 < 0 != bVar11) {
          cVar6 = (char)iVar9;
        }
        *(char *)(param_1 + 0x17) = cVar6;
        iVar9 = *(int *)(param_1 + 0x10);
        piVar4 = (int *)(DAT_08027214 + cVar6 * 4 + 0x28);
        iVar7 = 0;
        piVar5 = piVar4;
        while( true ) {
          iVar10 = *piVar5;
          *(int *)(iVar10 + 0xc) = iVar7;
          *(undefined1 *)(iVar10 + 10) = 1;
          if (piVar4 + iVar8 <= piVar5) break;
          iVar7 = iVar7 + *(int *)(*piVar5 + 0x10) + iVar9;
          piVar5 = piVar5 + 1;
        }
      }
      return;
    }
  }
  return;
}



/* ===== FUN_08018b1c @ 08018b1c ===== */

void FUN_08018b1c(char param_1,char param_2)

{
  int *piVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  byte bVar5;
  
  piVar1 = DAT_08018b60;
  pbVar4 = (byte *)*DAT_08018b60;
  bVar5 = *pbVar4;
  bVar3 = pbVar4[1];
  bVar2 = bVar5 + param_1;
  if ((byte)(bVar5 + param_1) < bVar5) {
    bVar2 = bVar5;
  }
  bVar5 = pbVar4[2];
  if (bVar2 < pbVar4[2]) {
    bVar5 = bVar2;
  }
  if (bVar3 < (byte)(bVar3 + param_2)) {
    bVar3 = bVar3 + param_2;
  }
  bVar2 = pbVar4[3];
  if (bVar3 < pbVar4[3]) {
    bVar2 = bVar3;
  }
  pbVar4[6] = bVar5;
  *(byte *)(*piVar1 + 7) = bVar2;
  *(byte *)(*piVar1 + 4) = bVar5;
  *(byte *)(*piVar1 + 5) = bVar2;
  return;
}



/* ===== FUN_08018b64 @ 08018b64 ===== */

undefined2 FUN_08018b64(undefined2 param_1)

{
  undefined2 uVar1;
  
  uVar1 = *(undefined2 *)(*DAT_08018b70 + 0x10);
  *(undefined2 *)(*DAT_08018b70 + 0x10) = param_1;
  return uVar1;
}



/* ===== FUN_08018b74 @ 08018b74 ===== */

undefined4 FUN_08018b74(int *param_1)

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
  
  piVar2 = DAT_08019114;
  iVar5 = DAT_08019110;
  sVar11 = 0;
  puVar3 = (uint *)param_1[2];
  if (puVar3 != (uint *)0x0) {
    cVar1 = *(char *)(DAT_08019110 + 0x8f);
    if (cVar1 == '\0') {
      uVar6 = (uint)(byte)*puVar3;
    }
    else {
      uVar6 = *puVar3;
    }
    if (uVar6 != 0) {
      puVar7 = (undefined1 *)*DAT_08019114;
      uVar6 = (uint)*(ushort *)(puVar7 + 0x10);
      if ((int)(uVar6 << 0x1c) < 0) {
        if (cVar1 == '\0') goto LAB_08018bb0;
        do {
          uVar6 = *puVar3;
          while( true ) {
            if ((uVar6 != 0x20 && uVar6 != 9) && uVar6 != 0xd) goto LAB_08018bd4;
            if (cVar1 != '\0') break;
            puVar3 = (uint *)((int)puVar3 + 1);
LAB_08018bb0:
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
LAB_08018bd4:
        puVar7[4] = *puVar7;
      }
      *param_1 = (int)puVar3;
      param_1[1] = (int)puVar3;
      iVar10 = 0;
      *(undefined2 *)(param_1 + 3) = 0;
      bVar12 = true;
LAB_08018bfe:
      if (*(char *)(iVar5 + 0x8f) == '\0') {
        uVar6 = (uint)(byte)*puVar3;
      }
      else {
        uVar6 = *puVar3;
      }
      if (uVar6 == 0 || uVar6 == 10) goto LAB_08018cbe;
      if (uVar6 == 0xd) {
        puVar7 = (undefined1 *)*piVar2;
        if ((puVar7[0x10] & 0xc) != 0) {
LAB_08018c30:
          uVar6 = 0x20;
LAB_08018c32:
          iVar10 = param_1[1];
          sVar11 = (short)param_1[3];
          goto LAB_08018c20;
        }
        if (!bVar12) goto LAB_08018cbe;
        puVar7[4] = *puVar7;
      }
      else {
        if (uVar6 == 9) {
          if ((*(byte *)(*piVar2 + 0x10) & 0xc) != 0) goto LAB_08018c30;
          sVar11 = (short)param_1[3];
          iVar10 = param_1[1];
          iVar9 = FUN_0802736a(sVar11 + (ushort)*(byte *)(*piVar2 + 4) & 0xff);
          uVar6 = (iVar9 - (uint)*(byte *)(*piVar2 + 4)) - (uint)*(ushort *)(param_1 + 3) & 0xffff;
        }
        else {
          if (uVar6 == 0x20) goto LAB_08018c32;
LAB_08018c20:
          uVar6 = FUN_08027288(uVar6);
        }
        pbVar8 = (byte *)*piVar2;
        uVar4 = (uint)pbVar8[2];
        if ((uVar4 - *pbVar8) + 1 <= uVar6) {
          *(ushort *)(param_1 + 3) = ((ushort)pbVar8[2] - (ushort)*pbVar8) + 1;
          if (*(char *)(iVar5 + 0x8f) == '\0') {
            puVar3 = (uint *)((int)puVar3 + 1);
          }
          else {
            puVar3 = puVar3 + 1;
          }
          goto LAB_08018cbe;
        }
        if ((int)((uint)*(ushort *)(pbVar8 + 0x10) << 0x16) < 0) {
          if ((*(ushort *)(pbVar8 + 0x10) & 0xc) == 8) {
            iVar9 = uVar6 - 1;
          }
          else {
            iVar9 = 0;
          }
          if (uVar4 < iVar9 + (uint)pbVar8[4] + (uint)*(ushort *)(param_1 + 3)) goto LAB_08018cbe;
        }
        else if (uVar4 < (uVar6 + *(ushort *)(param_1 + 3) + (uint)pbVar8[4]) - 1) {
          if ((iVar10 == 0) || ((pbVar8[0x10] & 0xc0) != 0x40)) goto LAB_08018cbe;
          param_1[1] = iVar10;
          *(short *)(param_1 + 3) = sVar11;
          if (sVar11 == 0) {
            iVar9 = iVar10;
            if (*(char *)(iVar5 + 0x8f) != '\0') goto LAB_08018d12;
          }
          else {
            if (*(char *)(iVar5 + 0x8f) != '\0') {
              iVar9 = iVar10 + 4;
LAB_08018d12:
              puVar3 = (uint *)(iVar9 + 4);
LAB_08018cbe:
              param_1[2] = (int)puVar3;
              cVar1 = *(char *)(iVar5 + 0x8f);
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
                if (cVar1 == '\0') goto LAB_08018d74;
LAB_08018d58:
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
LAB_08018d98:
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
                  if (uVar6 == 10) goto LAB_08018d98;
                  if (cVar1 != '\0') goto code_r0x08018d6a;
                  param_1[2] = param_1[2] + 1;
LAB_08018d74:
                  uVar6 = (uint)*(byte *)param_1[2];
                } while( true );
              }
              goto LAB_08018d18;
            }
            iVar9 = iVar10 + 1;
          }
          puVar3 = (uint *)(iVar9 + 1);
          goto LAB_08018cbe;
        }
        *(short *)(param_1 + 3) = (short)uVar6 + (short)param_1[3];
      }
      param_1[1] = (int)puVar3;
      if (*(char *)(iVar5 + 0x8f) == '\0') {
        puVar3 = (uint *)((int)puVar3 + 1);
      }
      else {
        puVar3 = puVar3 + 1;
      }
      bVar12 = false;
      goto LAB_08018bfe;
    }
  }
LAB_08018d18:
  return 0;
code_r0x08018d6a:
  param_1[2] = param_1[2] + 4;
  goto LAB_08018d58;
}



/* ===== FUN_08018daa @ 08018daa ===== */

undefined4 FUN_08018daa(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  undefined4 unaff_r4;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  bool bVar19;
  
  if (param_1[2] != 0) {
    FUN_0802731c();
    piVar4 = DAT_08019114;
    uVar6 = FUN_0802749c(*(undefined4 *)(*DAT_08019114 + 0xc));
    pcVar5 = DAT_08019118;
    if (uVar6 != 0) {
      iVar11 = *piVar4;
      uVar2 = *(ushort *)(iVar11 + 0x10);
      uVar16 = ((uint)*(byte *)(iVar11 + 3) - (uint)*(byte *)(iVar11 + 1)) + 1 & 0xff;
      bVar19 = (uVar2 & 0x8001) != 0x8000;
      if ((*DAT_08019118 == '\0') || ((int)uVar6 <= (int)uVar16)) {
        cVar3 = (char)uVar6;
        if ((uVar2 & 0x30) == 0x30 || (uVar2 & 0x30) == 0x20) {
          uVar18 = (uint)*(byte *)(iVar11 + 4);
          uVar17 = 0;
          iVar11 = param_1[2];
          while( true ) {
            uVar7 = FUN_08018b74(param_1);
            if (uVar7 < 2) break;
            if (uVar7 == 3) {
              uVar17 = uVar17 + 1;
            }
            ((undefined1 *)*piVar4)[4] = *(undefined1 *)*piVar4;
          }
          if (uVar7 == 1) {
            uVar17 = uVar17 + 1;
          }
          param_1[2] = iVar11;
          *(char *)(*piVar4 + 4) = (char)uVar18;
          iVar15 = (uVar17 & 0xffff) * uVar6;
          iVar11 = *piVar4;
          if ((*(byte *)(iVar11 + 0x10) & 0x30) == 0x30) {
            *(char *)(iVar11 + 5) = *(char *)(iVar11 + 1) + cVar3 + -1;
            if (iVar15 < (int)uVar16) {
              *(char *)(*piVar4 + 5) =
                   *(char *)(*piVar4 + 5) + (char)((uVar16 - uVar6 * uVar17 & 0xff) >> 1);
            }
          }
          else if ((int)uVar16 < iVar15) {
            *(char *)(iVar11 + 5) =
                 ((char)(uVar16 - 1) + *(char *)(iVar11 + 1)) - cVar3 * (char)((uVar16 - 1) / uVar6)
            ;
            if (*pcVar5 == '\0') {
              uVar16 = ((uVar16 + uVar6) - 1) / uVar6;
            }
            else {
              uVar16 = (int)uVar16 / (int)uVar6;
              *(char *)(*piVar4 + 5) = *(char *)(*piVar4 + 5) + cVar3;
            }
            for (uVar17 = uVar17 - uVar16; (uVar17 & 0xffff) != 0; uVar17 = uVar17 - 1) {
              FUN_08018b74(param_1);
            }
          }
          else {
            *(char *)(iVar11 + 5) = *(char *)(iVar11 + 3) - cVar3 * ((char)uVar17 + -1);
          }
        }
        else if ((uVar2 & 0x30) == 0x10) {
          *(byte *)(iVar11 + 5) = *(byte *)(iVar11 + 1) + cVar3 + -1;
        }
        iVar11 = FUN_08018b74(param_1);
        puVar8 = (undefined1 *)*piVar4;
        if ((((int)((uint)*(ushort *)(puVar8 + 0x10) << 0x15) < 0) &&
            ((int)uVar6 <= (int)(uint)(byte)puVar8[5])) && (bVar19)) {
          if ((int)((uint)*(ushort *)(puVar8 + 0x10) << 0x1f) < 0) {
            uVar12 = 0xffff;
          }
          else {
            uVar12 = 0;
          }
          FUN_080274b0(*puVar8,puVar8[1],puVar8[2],(byte)puVar8[5] - uVar6 & 0xff,uVar12);
        }
        if (iVar11 == 0) {
          puVar8 = (undefined1 *)*piVar4;
          uVar16 = (uint)*(ushort *)(puVar8 + 0x10);
          if (((*(ushort *)(puVar8 + 0x10) & 0x3000) != 0) && (bVar19)) {
            uVar12 = 0;
            if ((int)(uVar16 << 0x1f) < 0) {
              uVar12 = 0xffff;
            }
            uVar18 = (uint)(byte)puVar8[5];
            uVar17 = (uint)(byte)puVar8[3];
            if (uVar18 <= (byte)puVar8[3]) {
              uVar17 = uVar18;
            }
            if ((int)(uVar16 << 0x12) < 0) {
              cVar14 = puVar8[2];
            }
            else {
              cVar14 = puVar8[4] + -1;
            }
            bVar10 = puVar8[1];
            if ((int)(uVar6 + bVar10) <= (int)uVar18) {
              bVar10 = (puVar8[5] - cVar3) + 1;
            }
            if ((int)(uVar16 << 0x13) < 0) {
              uVar1 = *puVar8;
            }
            else {
              uVar1 = puVar8[4];
            }
            FUN_080274b0(uVar1,bVar10,cVar14,uVar17,uVar12);
          }
LAB_080190b6:
          puVar8 = (undefined1 *)*piVar4;
          if ((int)((uint)*(ushort *)(puVar8 + 0x10) << 0x14) < 0) {
            if (((byte)puVar8[5] < (byte)puVar8[3]) && (bVar19)) {
              if ((int)((uint)*(ushort *)(puVar8 + 0x10) << 0x1f) < 0) {
                uVar12 = 0xffff;
              }
              else {
                uVar12 = 0;
              }
              FUN_080274b0(*puVar8,puVar8[5] + 1,puVar8[2],puVar8[3],uVar12);
            }
          }
          piVar4 = DAT_0802748c;
          iVar11 = *DAT_0802748c;
          bVar10 = *(byte *)(iVar11 + 2);
          if (*(byte *)(iVar11 + 4) < *(byte *)(iVar11 + 2)) {
            bVar10 = *(byte *)(iVar11 + 4);
          }
          *(byte *)(iVar11 + 4) = bVar10;
          iVar11 = *piVar4;
          bVar10 = *(byte *)(iVar11 + 3);
          if (*(byte *)(iVar11 + 5) < *(byte *)(iVar11 + 3)) {
            bVar10 = *(byte *)(iVar11 + 5);
          }
          *(byte *)(iVar11 + 5) = bVar10;
          *(undefined1 *)(*piVar4 + 6) = *(undefined1 *)(*piVar4 + 4);
          *(undefined1 *)(*piVar4 + 7) = *(undefined1 *)(*piVar4 + 5);
          uVar12 = FUN_0802b7ec(unaff_r4);
          return uVar12;
        }
LAB_08018f1a:
        pbVar9 = (byte *)*piVar4;
        if ((*(ushort *)(pbVar9 + 0x10) & 0xc) == 0xc) {
          bVar10 = *pbVar9;
          uVar16 = ((uint)pbVar9[2] - (uint)bVar10) + 1;
          if (*(ushort *)(param_1 + 3) < uVar16) {
            bVar10 = bVar10 + (char)(uVar16 - *(ushort *)(param_1 + 3) >> 1);
          }
        }
        else {
          if ((*(ushort *)(pbVar9 + 0x10) & 0xc) != 8) goto LAB_08018f5e;
          bVar10 = *pbVar9;
          if ((uint)*(ushort *)(param_1 + 3) < ((uint)pbVar9[2] - (uint)bVar10) + 1) {
            bVar10 = (pbVar9[2] + 1) - (char)*(ushort *)(param_1 + 3);
          }
        }
        pbVar9[4] = bVar10;
LAB_08018f5e:
        pbVar9 = (byte *)*piVar4;
        if ((int)((uint)*(ushort *)(pbVar9 + 0x10) << 0x13) < 0) {
          if ((*pbVar9 < pbVar9[4]) && (bVar19)) {
            if ((int)((uint)*(ushort *)(pbVar9 + 0x10) << 0x1f) < 0) {
              uVar12 = 0xffff;
            }
            else {
              uVar12 = 0;
            }
            uVar17 = (uint)pbVar9[5];
            uVar16 = (uint)pbVar9[3];
            if (uVar17 <= pbVar9[3]) {
              uVar16 = uVar17;
            }
            bVar10 = pbVar9[1];
            if ((int)(uVar6 + bVar10) <= (int)uVar17) {
              bVar10 = (pbVar9[5] - cVar3) + 1;
            }
            FUN_080274b0(*pbVar9,bVar10,pbVar9[4] - 1,uVar16,uVar12);
          }
        }
        iVar15 = DAT_08019110;
        if (*(char *)(DAT_08019110 + 0x8f) == '\0') goto LAB_08018fc8;
        do {
          uVar16 = *(uint *)*param_1;
          while( true ) {
            if (((*(byte *)(*piVar4 + 0x10) & 0xc) != 0) && (uVar16 == 0xd || uVar16 == 9)) {
              uVar16 = 0x20;
            }
            FUN_08027392(uVar16);
            iVar13 = *param_1;
            if (iVar13 == param_1[1]) {
              iVar15 = *piVar4;
              if ((int)((uint)*(ushort *)(iVar15 + 0x10) << 0x12) < 0) {
                if ((*(byte *)(iVar15 + 4) <= *(byte *)(iVar15 + 2)) && (bVar19)) {
                  if ((int)((uint)*(ushort *)(iVar15 + 0x10) << 0x1f) < 0) {
                    uVar12 = 0xffff;
                  }
                  else {
                    uVar12 = 0;
                  }
                  uVar17 = (uint)*(byte *)(iVar15 + 5);
                  uVar16 = (uint)*(byte *)(iVar15 + 3);
                  if (uVar17 <= *(byte *)(iVar15 + 3)) {
                    uVar16 = uVar17;
                  }
                  bVar10 = *(byte *)(iVar15 + 1);
                  if ((int)(uVar6 + bVar10) <= (int)uVar17) {
                    bVar10 = (*(byte *)(iVar15 + 5) - cVar3) + 1;
                  }
                  FUN_080274b0(*(byte *)(iVar15 + 4),bVar10,*(byte *)(iVar15 + 2),uVar16,uVar12);
                }
              }
              if (((iVar11 == 3) && (iVar11 = FUN_080272a0(uVar6), iVar11 != 0)) ||
                 (iVar11 = FUN_08018b74(param_1), iVar11 == 0)) goto LAB_080190b6;
              goto LAB_08018f1a;
            }
            if (*(char *)(iVar15 + 0x8f) != '\0') break;
            *param_1 = iVar13 + 1;
LAB_08018fc8:
            uVar16 = (uint)*(byte *)*param_1;
          }
          *param_1 = iVar13 + 4;
        } while( true );
      }
    }
  }
  return param_4;
}



/* ===== FUN_080190ec @ 080190ec ===== */

void FUN_080190ec(undefined4 param_1)

{
  undefined1 auStack_18 [8];
  undefined4 local_10;
  
  *(undefined1 *)(DAT_08019110 + 0x8f) = 0;
  local_10 = param_1;
  FUN_08018daa(auStack_18);
  return;
}



/* ===== FUN_080190f8 @ 080190f8 ===== */

void FUN_080190f8(undefined4 param_1)

{
  undefined1 auStack_18 [8];
  undefined4 local_10;
  
  *(undefined1 *)(DAT_08019110 + 0x8f) = 1;
  local_10 = param_1;
  FUN_08018daa(auStack_18);
  return;
}



/* ===== FUN_0801912e @ 0801912e ===== */

void FUN_0801912e(void)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  char cVar5;
  int iVar6;
  char cVar7;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  puVar2 = DAT_080196dc;
  *DAT_080196dc = 0;
  iVar3 = DAT_080196e0;
  bVar1 = *(byte *)(DAT_080196e0 + 0x1a);
  if (bVar1 != 0) {
    if ((int)((uint)bVar1 << 0x18) < 0) {
      FUN_080167e8(bVar1 & 0x7f);
    }
    else {
      FUN_08024908();
      FUN_080248f0();
    }
    *(undefined1 *)(iVar3 + 0x1a) = 0;
    return;
  }
  if (((*(char *)(DAT_080196e0 + 0x18) == '\0') || (iVar6 = FUN_08024986(), iVar6 != 0)) ||
     (iVar6 = FUN_080249e6(), iVar6 != 0)) {
    return;
  }
  if (*(char *)(iVar3 + 0x18) != '\x05') {
    FUN_08027aa0();
    FUN_0802818c(DAT_080196f0);
    FUN_0802a02c();
    if ((*(char *)(iVar3 + 0xd) == '\x01') && (*(char *)(DAT_080196f4 + 0xb) != '\x01')) {
      FUN_080193a4();
    }
    if (*DAT_080196f8 << 0x12 < 0) {
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
  iVar6 = FUN_0802768c(0,400,0x1e0);
  uVar4 = DAT_080196e4;
  if (iVar6 == 0) {
    local_34._0_2_ = CONCAT11(9,(undefined1)local_34);
    FUN_080262d4((int)&local_34 + 2,"RadiaCode Zero",0xe);
    local_24 = CONCAT31(local_24._1_3_,0x23);
    iVar6 = FUN_08027878(uVar4);
    if (iVar6 == 0xd) {
      FUN_080262d4((int)&local_24 + 1,uVar4,0xd);
      cVar7 = '\x1e';
      cVar5 = '\x1d';
    }
    else {
      cVar5 = FUN_080278b0((int)&local_24 + 1,"RC-410-%06.6X",*DAT_080196e8);
      cVar7 = cVar5 + '\x11';
      cVar5 = cVar5 + '\x10';
    }
    local_34 = CONCAT31(local_34._1_3_,cVar5);
    iVar6 = FUN_0802782a(10);
    if (iVar6 == 0) {
      iVar6 = FUN_08027960(cVar7,&local_34);
    }
    if (iVar6 != 0) goto LAB_08019278;
    FUN_080262f4(&local_34,&DAT_080197f4,3);
    uVar4 = local_30;
    local_34._3_1_ = '\x03';
    local_30._3_1_ = SUB41(uVar4,3);
    local_30._0_3_ = CONCAT12(DAT_080197f9,CONCAT11(DAT_080197f8,0xff));
    local_38 = *(uint *)(iVar3 + 0x10) & 0xfffff;
    FUN_080262d4((int)&local_30 + 3,&local_38,3);
    local_34 = CONCAT13(local_34._3_1_ + '\x03',(undefined3)local_34);
    local_2c = CONCAT13(7,CONCAT12(0x11,(undefined2)local_2c));
    FUN_080262d4(&local_28,DAT_080196ec,0x10);
    iVar6 = FUN_080279b2(0x1c,&local_34);
  }
  if (iVar6 == 0) {
    *(undefined1 *)(iVar3 + 0x18) = 6;
    return;
  }
LAB_08019278:
  *(undefined1 *)(iVar3 + 0x18) = 0;
  *puVar2 = 1;
  if (*(char *)(iVar3 + 0x1a) == '\0') {
    *(undefined1 *)(iVar3 + 0x1a) = 2;
  }
  FUN_08017f38("BLE: error #0x%0.2X!",2);
  return;
}



/* ===== FUN_080192cc @ 080192cc ===== */

uint FUN_080192cc(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint *puVar3;
  undefined1 uVar4;
  
  if (param_1 == 1) {
    FUN_0802a23e();
    uVar4 = 100;
  }
  else {
    uVar4 = 0x32;
  }
  iVar2 = DAT_080196e0;
  puVar1 = DAT_080196dc;
  *(undefined1 *)(DAT_080196e0 + 0x19) = uVar4;
  *(undefined1 *)(iVar2 + 0x18) = 0;
  *puVar1 = 0;
  puVar3 = DAT_08019700;
  puVar1 = DAT_080196fc;
  DAT_080196fc[4] = 4;
  *puVar3 = *puVar3 & 0xffffdfff;
  puVar3[5] = 0x2000;
  *puVar3 = *puVar3 | 0x2000;
  do {
  } while ((uint)(*DAT_08019704 - *DAT_08019704) < 5000);
  *puVar1 = 4;
  FUN_08027a7c();
  FUN_08029fe0();
  *(undefined1 *)(iVar2 + 0xd) = 0;
  puVar3 = DAT_08019708;
  *DAT_08019708 = *DAT_08019708 | 0x8000;
  return *puVar3 & 0x8000;
}



/* ===== FUN_0801937c @ 0801937c ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801937c(undefined4 param_1,undefined1 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  FUN_08029fe0();
  iVar2 = DAT_080196e0;
  *(undefined1 *)(DAT_080196e0 + 0xd) = 0;
  *(undefined1 *)(iVar2 + 0xc) = param_2;
  FUN_0802a2f4();
  puVar1 = DAT_080196dc;
  *(undefined1 *)(iVar2 + 0x18) = 0;
  *puVar1 = 0;
  if (*DAT_08024ad4 == '\0') {
    uVar3 = 0x4000;
  }
  else {
    uVar3 = 0x50000;
  }
  FUN_080165ac(_DAT_08024af8,uVar3);
  return;
}



/* ===== FUN_080193a4 @ 080193a4 ===== */

undefined4 FUN_080193a4(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 in_r3;
  undefined4 extraout_r3;
  undefined4 uVar5;
  
  iVar1 = DAT_080196e0;
  uVar5 = 500;
  iVar4 = FUN_0802a398(*(undefined2 *)(DAT_080196e0 + 4),6,10,0,500,in_r3);
  puVar3 = DAT_08024ad8;
  puVar2 = DAT_08024ad4;
  if (iVar4 == 0) {
    *(undefined1 *)(iVar1 + 0xd) = 2;
    return uVar5;
  }
  *DAT_08024ad4 = 0;
  *puVar3 = 1;
  if (puVar2[2] == '\0') {
    puVar2[2] = 0x41;
  }
  uVar5 = extraout_r3;
  FUN_08017f38("BLE: error #0x%0.2X!",0x41);
  uVar5 = FUN_08017f8a(DAT_08024aec,0x41,*(undefined2 *)(DAT_08024ae8 + 6),uVar5);
  return uVar5;
}



/* ===== FUN_080193ce @ 080193ce ===== */

ushort FUN_080193ce(void)

{
  ushort uVar1;
  int iVar2;
  undefined1 uStack_c;
  undefined1 uStack_b;
  ushort local_a;
  short local_8;
  undefined1 auStack_6 [2];
  
  iVar2 = FUN_080278f0(&uStack_b,&local_8,&uStack_c,auStack_6,&local_a);
  if (iVar2 == 0) {
    uVar1 = local_a & 0xff | local_8 << 8;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* ===== FUN_0801941c @ 0801941c ===== */

undefined4 FUN_0801941c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  
  iVar2 = DAT_080196e0;
  puVar1 = DAT_080196dc;
  uVar3 = 1;
  if (param_1 != 1) {
    if (2 < param_1 - 2U) {
      if (param_1 - 5U < 5) {
        *(undefined1 *)(DAT_080196e0 + 0x18) = 0;
        *puVar1 = 1;
        if (*(char *)(iVar2 + 0x1a) == '\0') {
          *(undefined1 *)(iVar2 + 0x1a) = 0x81;
        }
        uVar4 = 0x81;
      }
      else {
        *(undefined1 *)(DAT_080196e0 + 0x18) = 0;
        *puVar1 = 1;
        if (*(char *)(iVar2 + 0x1a) == '\0') {
          *(undefined1 *)(iVar2 + 0x1a) = 0x86;
        }
        uVar4 = 0x86;
      }
      uVar4 = FUN_08017f38("BLE: error #0x%0.2X!",uVar4,param_4);
      return uVar4;
    }
    uVar3 = 2;
  }
  *(undefined1 *)(DAT_080196e0 + 0x18) = uVar3;
  return param_4;
}



/* ===== FUN_08019464 @ 08019464 ===== */

void FUN_08019464(undefined4 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8)

{
  int *piVar1;
  
  piVar1 = DAT_080196e0;
  *(undefined2 *)(DAT_080196e0 + 1) = param_2;
  *(undefined1 *)(piVar1 + 6) = 7;
  *piVar1 = *piVar1 + 1;
  *(undefined2 *)(piVar1 + 2) = param_7;
  *(undefined2 *)((int)piVar1 + 10) = param_8;
  *(undefined2 *)((int)piVar1 + 6) = param_6;
  FUN_08017ee8("BLE: client connected",param_3,param_4);
  return;
}



/* ===== FUN_0801948a @ 0801948a ===== */

undefined4
FUN_0801948a(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *unaff_r4;
  uint unaff_r5;
  
  puVar2 = DAT_08024ad8;
  puVar1 = DAT_08024ad4;
  if (param_1 == 0) {
    unaff_r5 = (uint)*(ushort *)(DAT_080196e0 + 1);
    unaff_r4 = DAT_080196e0;
  }
  if (param_1 == 0 && param_2 == unaff_r5) {
    *(undefined2 *)((int)unaff_r4 + 10) = param_5;
    *unaff_r4 = *unaff_r4 + 1;
    *(short *)((int)unaff_r4 + 6) = (short)param_3;
    *(short *)(unaff_r4 + 2) = (short)param_4;
    if (*(char *)((int)unaff_r4 + 0xd) == '\x02') {
      *(undefined1 *)((int)unaff_r4 + 0xd) = 3;
    }
    return param_3;
  }
  *DAT_08024ad4 = 0;
  *puVar2 = 1;
  if (puVar1[2] == '\0') {
    puVar1[2] = 0x40;
  }
  FUN_08017f38("BLE: error #0x%0.2X!",0x40);
  uVar3 = FUN_08017f8a(DAT_08024aec,0x40,*(undefined2 *)(DAT_08024ae8 + 6),param_4);
  return uVar3;
}



/* ===== FUN_080194bc @ 080194bc ===== */

void FUN_080194bc(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_08024ad8;
  puVar1 = DAT_08024ad4;
  if (param_1 == *(ushort *)(DAT_080196e0 + 4)) {
    return;
  }
  *DAT_08024ad4 = 0;
  *puVar2 = 1;
  if (puVar1[2] == '\0') {
    puVar1[2] = 0x42;
  }
  FUN_08017f38("BLE: error #0x%0.2X!",0x42);
  FUN_08017f8a(DAT_08024aec,0x42,*(undefined2 *)(DAT_08024ae8 + 6),param_4);
  return;
}



/* ===== FUN_080194cc @ 080194cc ===== */

void FUN_080194cc(undefined4 param_1,undefined4 param_2,int param_3)

{
  char *pcVar1;
  
  FUN_0801937c(param_2,param_3);
  if (param_3 == 0x13) {
    pcVar1 = DAT_08019710;
  }
  else {
    if (param_3 != 8) {
      FUN_08017f38(PTR_s_BLE__disconnected_by_reason_0x_0_08019714,param_3);
      return;
    }
    pcVar1 = "BLE: connection timeout expired";
  }
  FUN_08017ee8(pcVar1);
  return;
}



/* ===== FUN_080194fa @ 080194fa ===== */

void FUN_080194fa(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
                 undefined4 param_5)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(DAT_080196e0 + 0x20) + 4);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0801950e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(param_2,param_4,param_5);
  return;
}



/* ===== FUN_08019514 @ 08019514 ===== */

void FUN_08019514(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  bool bVar5;
  
  iVar2 = DAT_080196e0;
  if (param_1 == 0) {
    bVar5 = *(int *)(DAT_080196e0 + 0x24) != -1;
    *(undefined4 *)(DAT_080196e0 + 0x24) = 0;
    pcVar3 = "BLE: HW error/SPI";
  }
  else if (param_1 == 2) {
    uVar4 = *(int *)(DAT_080196e0 + 0x2c) + 1;
    bVar5 = 4 < uVar4;
    if (bVar5) {
      uVar4 = 0;
    }
    *(uint *)(DAT_080196e0 + 0x2c) = uVar4;
    pcVar3 = "BLE: HW error/Timer overrun";
  }
  else {
    if (1 < param_1) {
      FUN_08017ee8("BLE: HW error/Unknown");
      uVar4 = 0xff;
      goto LAB_08019574;
    }
    uVar4 = *(int *)(DAT_080196e0 + 0x28) + 1;
    bVar5 = 9 < uVar4;
    if (bVar5) {
      uVar4 = 0;
    }
    *(uint *)(DAT_080196e0 + 0x28) = uVar4;
    pcVar3 = "BLE: HW error/Radio";
  }
  FUN_08017ee8(pcVar3);
  uVar4 = param_1 + 0xb | 0x80;
  if (!bVar5) {
    return;
  }
LAB_08019574:
  puVar1 = DAT_080196dc;
  *(undefined1 *)(iVar2 + 0x18) = 0;
  *puVar1 = 1;
  if (*(char *)(iVar2 + 0x1a) == '\0') {
    *(char *)(iVar2 + 0x1a) = (char)uVar4;
  }
  FUN_08017f38("BLE: error #0x%0.2X!",uVar4 & 0xff);
  return;
}



/* ===== FUN_08019592 @ 08019592 ===== */

void FUN_08019592(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = DAT_080196e0;
  puVar1 = DAT_080196dc;
  *(undefined1 *)(DAT_080196e0 + 0x18) = 0;
  *puVar1 = 1;
  if (*(char *)(iVar2 + 0x1a) == '\0') {
    *(undefined1 *)(iVar2 + 0x1a) = 0x11;
  }
  FUN_08017f38("BLE: error #0x%0.2X!",0x11);
  return;
}



/* ===== FUN_080195aa @ 080195aa ===== */

void FUN_080195aa(void)

{
  undefined4 *puVar1;
  int iVar2;
  uint *puVar3;
  
  puVar3 = DAT_080196f4;
  iVar2 = DAT_080196e0;
  puVar1 = DAT_080196dc;
  if (*(char *)(DAT_080196e0 + 0x18) == '\b') {
    *(undefined1 *)(DAT_080196e0 + 0x18) = 7;
    *puVar3 = *puVar3 | 4;
    return;
  }
  *(undefined1 *)(DAT_080196e0 + 0x18) = 0;
  *puVar1 = 1;
  if (*(char *)(iVar2 + 0x1a) == '\0') {
    *(undefined1 *)(iVar2 + 0x1a) = 0x12;
  }
  FUN_08017f38("BLE: error #0x%0.2X!",0x12);
  return;
}



/* ===== FUN_080198ac @ 080198ac ===== */

undefined4 * FUN_080198ac(undefined4 *param_1)

{
  FUN_08026250();
  *param_1 = DAT_080198cc;
  *(undefined1 *)((int)param_1 + 0x9e) = 0;
  *(undefined1 *)((int)param_1 + 0x9d) = 0;
  *(undefined1 *)(param_1 + 0x27) = 0;
  param_1[0x28] = 0;
  *(undefined1 *)((int)param_1 + 0x9f) = 0;
  return param_1;
}



/* ===== FUN_08019990 @ 08019990 ===== */

void FUN_08019990(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_080199b8;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_080199bc;
  param_1[5] = 2;
  return;
}



/* ===== FUN_080199c0 @ 080199c0 ===== */

void FUN_080199c0(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_080199e8;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_080199ec;
  param_1[5] = 2;
  return;
}



/* ===== FUN_080199f0 @ 080199f0 ===== */

void FUN_080199f0(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_08019a18;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_08019a1c;
  param_1[5] = 2;
  return;
}



/* ===== FUN_08019a20 @ 08019a20 ===== */

void FUN_08019a20(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_08019a48;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_08019a4c;
  param_1[5] = 2;
  return;
}



/* ===== FUN_08019a50 @ 08019a50 ===== */

void FUN_08019a50(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_08019a78;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_08019a7c;
  param_1[5] = 2;
  return;
}



/* ===== FUN_08019a80 @ 08019a80 ===== */

void FUN_08019a80(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_08019aa8;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_08019aac;
  param_1[5] = 2;
  return;
}



/* ===== FUN_08019ab0 @ 08019ab0 ===== */

void FUN_08019ab0(int *param_1,int *param_2)

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



/* ===== FUN_08019ac0 @ 08019ac0 ===== */

void FUN_08019ac0(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_08019ae8;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_08019aec;
  param_1[5] = 2;
  return;
}



/* ===== FUN_08019bb0 @ 08019bb0 ===== */

uint FUN_08019bb0(uint param_1,uint param_2,uint param_3,uint param_4)

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
    uVar1 = FUN_08019bf4(param_1,param_2);
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
LAB_08019c98:
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
LAB_08019d26:
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
      if (uVar7 < 0xf || uVar10 == 0) goto LAB_08019c98;
      goto LAB_08019d26;
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



/* ===== FUN_08019bf4 @ 08019bf4 ===== */

ulonglong FUN_08019bf4(uint param_1,uint param_2,uint param_3,uint param_4)

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
LAB_08019c98:
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
LAB_08019d26:
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
      if (uVar7 < 0xf || uVar10 == 0) goto LAB_08019c98;
      goto LAB_08019d26;
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



/* ===== FUN_08019e2c @ 08019e2c ===== */

float FUN_08019e2c(float *param_1,uint param_2)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  if (param_2 < 0x33) {
    fVar1 = param_1[param_2 * 2 + 3];
  }
  else {
    fVar2 = (float)VectorUnsignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
    fVar1 = (float)FUN_0802a9a0(fVar2);
    fVar1 = (fVar2 - *param_1 * fVar1) + param_1[1];
  }
  return fVar1;
}



/* ===== FUN_08019e60 @ 08019e60 ===== */

float FUN_08019e60(float *param_1,uint param_2)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  if (param_2 < 0x33) {
    fVar1 = param_1[param_2 * 2 + 4];
  }
  else {
    fVar2 = (float)VectorUnsignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
    fVar1 = (float)FUN_0802a9a0(fVar2);
    fVar1 = fVar2 + *param_1 * fVar1 + param_1[2];
  }
  return fVar1;
}



/* ===== FUN_08019e9c @ 08019e9c ===== */

undefined4 FUN_08019e9c(uint *param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  
  *param_1 = (uint)*(ushort *)(param_2 + 2);
  param_1[1] = *(uint *)(param_2 + 4);
  uVar1 = FUN_080207ec(*(undefined4 *)(param_2 + 8));
  *(undefined8 *)(param_1 + 2) = uVar1;
  uVar1 = FUN_080207ec(*(undefined4 *)(param_2 + 0xc));
  *(undefined8 *)(param_1 + 4) = uVar1;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[*param_2 + 7] = 1;
  param_1[6] = 1;
  return param_4;
}



/* ===== FUN_08019ed4 @ 08019ed4 ===== */

undefined4 FUN_08019ed4(int *param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  longlong lVar1;
  longlong lVar2;
  
  param_1[*param_2 + 7] = param_1[*param_2 + 7] + 1;
  param_1[6] = param_1[6] + 1;
  *param_1 = *param_1 + (uint)*(ushort *)(param_2 + 2);
  param_1[1] = *(int *)(param_2 + 4) + param_1[1];
  lVar1 = *(longlong *)(param_1 + 2);
  lVar2 = FUN_080207ec(*(undefined4 *)(param_2 + 8));
  *(longlong *)(param_1 + 2) = lVar2 + lVar1;
  lVar1 = *(longlong *)(param_1 + 4);
  lVar2 = FUN_080207ec(*(undefined4 *)(param_2 + 0xc));
  *(longlong *)(param_1 + 4) = lVar2 + lVar1;
  return param_4;
}



/* ===== FUN_08019f22 @ 08019f22 ===== */

undefined4 FUN_08019f22(int *param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  *param_1 = *param_1 - (uint)*(ushort *)(param_2 + 2);
  param_1[1] = param_1[1] - *(int *)(param_2 + 4);
  uVar1 = param_1[2];
  iVar2 = param_1[3];
  uVar3 = FUN_080207ec(*(undefined4 *)(param_2 + 8));
  param_1[2] = uVar1 - (uint)uVar3;
  param_1[3] = (iVar2 - (int)((ulonglong)uVar3 >> 0x20)) - (uint)(uVar1 < (uint)uVar3);
  uVar1 = param_1[4];
  iVar2 = param_1[5];
  uVar3 = FUN_080207ec(*(undefined4 *)(param_2 + 0xc));
  param_1[4] = uVar1 - (uint)uVar3;
  param_1[5] = (iVar2 - (int)((ulonglong)uVar3 >> 0x20)) - (uint)(uVar1 < (uint)uVar3);
  param_1[6] = param_1[6] + -1;
  param_1[*param_2 + 7] = param_1[*param_2 + 7] + -1;
  return param_4;
}



/* ===== FUN_08019f74 @ 08019f74 ===== */

void FUN_08019f74(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  param_1[6] = param_2[6] + param_1[6];
  param_1[7] = param_2[7] + param_1[7];
  param_1[8] = param_2[8] + param_1[8];
  *param_1 = *param_2 + *param_1;
  param_1[1] = param_2[1] + param_1[1];
  uVar1 = param_2[2];
  iVar2 = param_2[3];
  uVar3 = param_1[2];
  param_1[2] = uVar3 + uVar1;
  param_1[3] = iVar2 + param_1[3] + (uint)CARRY4(uVar3,uVar1);
  uVar3 = param_1[4];
  uVar1 = param_2[4];
  iVar2 = param_2[5];
  param_1[4] = uVar3 + uVar1;
  param_1[5] = iVar2 + param_1[5] + (uint)CARRY4(uVar3,uVar1);
  return;
}



/* ===== FUN_08019fc2 @ 08019fc2 ===== */

void FUN_08019fc2(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  *param_1 = *param_1 - *param_2;
  param_1[1] = param_1[1] - param_2[1];
  uVar1 = param_2[2];
  iVar2 = param_2[3];
  uVar3 = param_1[2];
  param_1[2] = uVar3 - uVar1;
  param_1[3] = (param_1[3] - iVar2) - (uint)(uVar3 < uVar1);
  uVar3 = param_1[4];
  uVar1 = param_2[4];
  iVar2 = param_2[5];
  param_1[4] = uVar3 - uVar1;
  param_1[5] = (param_1[5] - iVar2) - (uint)(uVar3 < uVar1);
  param_1[6] = param_1[6] - param_2[6];
  param_1[7] = param_1[7] - param_2[7];
  param_1[8] = param_1[8] - param_2[8];
  return;
}



/* ===== FUN_0801a014 @ 0801a014 ===== */

undefined4 FUN_0801a014(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if (iVar1 != 0) {
    param_4 = *(int *)(param_2 + 0x18);
  }
  if (iVar1 != 0 && param_4 != 0) {
    iVar2 = *(int *)(param_1 + 0x1c);
    iVar3 = *(int *)(param_2 + 0x1c);
    if (iVar3 == 0 && iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x20);
      iVar3 = *(int *)(param_2 + 0x20);
    }
    if (iVar2 == iVar1 && iVar3 == param_4) {
      return 1;
    }
  }
  return 0;
}



/* ===== FUN_0801a044 @ 0801a044 ===== */

undefined4 FUN_0801a044(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint in_fpscr;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  float fVar6;
  
  iVar1 = FUN_0801a014();
  uVar5 = 0;
  if (iVar1 != 0) {
    iVar2 = *(int *)(param_1 + 4);
    iVar1 = *(int *)(param_2 + 4);
    if ((uint)(iVar1 * *(int *)(param_1 + 0x18)) < (uint)(iVar2 * *(int *)(param_2 + 0x18))) {
      fVar3 = (float)FUN_08019e2c(param_3,iVar2);
      fVar4 = (float)VectorSignedToFloat(*(undefined4 *)(param_2 + 0x18),
                                         (byte)(in_fpscr >> 0x16) & 3);
      fVar4 = fVar4 * fVar3;
      fVar3 = (float)FUN_08019e60(param_3,iVar1);
      uVar5 = *(undefined4 *)(param_1 + 0x18);
    }
    else {
      fVar3 = (float)FUN_08019e2c(param_3,iVar1);
      fVar4 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x18),
                                         (byte)(in_fpscr >> 0x16) & 3);
      fVar4 = fVar4 * fVar3;
      fVar3 = (float)FUN_08019e60(param_3,iVar2);
      uVar5 = *(undefined4 *)(param_2 + 0x18);
    }
    fVar6 = (float)VectorSignedToFloat(uVar5,(byte)(in_fpscr >> 0x16) & 3);
    if (fVar4 < fVar6 * fVar3) {
      uVar5 = 1;
    }
    else {
      uVar5 = 0;
    }
  }
  return uVar5;
}



/* ===== FUN_0801a0c8 @ 0801a0c8 ===== */

void FUN_0801a0c8(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = DAT_0801ae00;
  piVar1 = DAT_0801abb4;
  uVar3 = *(uint *)(param_1 + 0x38);
  if (0 < param_3) {
    do {
      FUN_0802a9be(param_2,uVar3);
      uVar3 = uVar3 + 0x10;
      if (*piVar1 + 0x8000U <= uVar3) {
        uVar3 = uVar3 + iVar2;
      }
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}



/* ===== FUN_0801a0fc @ 0801a0fc ===== */

undefined4 FUN_0801a0fc(int param_1,int param_2,int param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  longlong lVar10;
  
  puVar1 = DAT_0801abb4;
  uVar3 = *(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x18) * 0x10;
  if (*DAT_0801abb4 + 0x8000 <= uVar3) {
    uVar3 = uVar3 - 0x8000;
  }
  if (param_3 < 1) {
    return param_4;
  }
  do {
    uVar4 = uVar3 - 0x10;
    if (uVar4 < *puVar1) {
      uVar4 = uVar3 + 0x7ff0;
    }
    uVar9 = *(uint *)(uVar4 + 4);
    uVar3 = *(uint *)(param_2 + 0x18);
    uVar5 = *(uint *)(param_2 + 0x28);
    uVar8 = uVar5 + *(uint *)(param_2 + 4);
    lVar10 = (ulonglong)uVar9 * (ulonglong)uVar3;
    uVar6 = (uint)lVar10;
    *(uint *)(param_2 + 0x28) = uVar8 - uVar6;
    *(uint *)(param_2 + 0x2c) =
         ((*(int *)(param_2 + 0x2c) + (uint)CARRY4(uVar5,*(uint *)(param_2 + 4))) -
         (uVar9 * ((int)uVar3 >> 0x1f) + (int)((ulonglong)lVar10 >> 0x20))) - (uint)(uVar8 < uVar6);
    uVar8 = *(uint *)(param_2 + 0x30);
    iVar7 = *(int *)(param_2 + 0x34);
    uVar5 = *(uint *)(param_2 + 8);
    iVar2 = *(int *)(param_2 + 0xc);
    uVar9 = uVar8 + uVar5;
    lVar10 = FUN_0802aa28(*(undefined4 *)(uVar4 + 8));
    uVar6 = (uint)(lVar10 * (int)uVar3);
    *(uint *)(param_2 + 0x30) = uVar9 - uVar6;
    *(uint *)(param_2 + 0x34) =
         ((iVar7 + iVar2 + (uint)CARRY4(uVar8,uVar5)) -
         (int)((ulonglong)(lVar10 * (int)uVar3) >> 0x20)) - (uint)(uVar9 < uVar6);
    FUN_08019ed4(param_2,uVar4);
    param_3 = param_3 + -1;
    uVar3 = uVar4;
  } while (param_3 != 0);
  return param_4;
}



/* ===== FUN_0801a1ae @ 0801a1ae ===== */

void FUN_0801a1ae(int param_1,int param_2,int param_3,undefined4 param_4)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined1 auStack_60 [4];
  uint local_5c;
  uint local_58;
  int iStack_54;
  uint local_48;
  uint local_38;
  int iStack_34;
  uint local_30;
  int iStack_2c;
  undefined4 uStack_28;
  
  uStack_28 = param_4;
  FUN_0802aa70(auStack_60);
  local_38 = 0;
  iStack_34 = 0;
  local_30 = 0;
  iStack_2c = 0;
  iVar6 = *(int *)(param_1 + 0x18);
  iVar4 = iVar6;
  if (param_3 < iVar6) {
    iVar4 = param_3;
  }
  uVar9 = *(int *)(param_1 + 0x38) + iVar4 * 0x10;
  iVar6 = iVar6 - iVar4;
  if (*DAT_0801abb4 + 0x8000U <= uVar9) {
    uVar9 = uVar9 - 0x8000;
  }
  FUN_0802aa70(auStack_60);
  local_38 = 0;
  iStack_34 = 0;
  local_30 = 0;
  iStack_2c = 0;
  if (iVar4 < iVar6) {
    FUN_0801a0c8(param_1,auStack_60,iVar4);
    uVar2 = *(uint *)(param_1 + 0x28);
    uVar10 = *(uint *)(param_1 + 0x18);
    uVar5 = uVar2 - local_38;
    lVar1 = (ulonglong)*(uint *)(param_1 + 4) * (ulonglong)local_48;
    uVar7 = (uint)lVar1;
    uVar8 = uVar5 - uVar7;
    uVar3 = (uint)((ulonglong)local_5c * (ulonglong)uVar10);
    *(uint *)(param_1 + 0x28) = uVar8 + uVar3;
    *(uint *)(param_1 + 0x2c) =
         local_5c * ((int)uVar10 >> 0x1f) + (int)((ulonglong)local_5c * (ulonglong)uVar10 >> 0x20) +
         ((((*(int *)(param_1 + 0x2c) - iStack_34) - (uint)(uVar2 < local_38)) -
          (*(uint *)(param_1 + 4) * ((int)local_48 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20))) -
         (uint)(uVar5 < uVar7)) + (uint)CARRY4(uVar8,uVar3);
    uVar3 = *(uint *)(param_1 + 0x30);
    uVar5 = uVar3 - local_30;
    lVar1 = (ulonglong)*(uint *)(param_1 + 8) * (ulonglong)local_48;
    uVar7 = (uint)lVar1;
    uVar2 = uVar5 - uVar7;
    uVar8 = (uint)((ulonglong)local_58 * (ulonglong)uVar10);
    *(uint *)(param_1 + 0x30) = uVar2 + uVar8;
    *(uint *)(param_1 + 0x34) =
         ((((*(int *)(param_1 + 0x34) - iStack_2c) - (uint)(uVar3 < local_30)) -
          (*(int *)(param_1 + 0xc) * local_48 +
          *(uint *)(param_1 + 8) * ((int)local_48 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20))) -
         (uint)(uVar5 < uVar7)) +
         iStack_54 * uVar10 +
         local_58 * ((int)uVar10 >> 0x1f) + (int)((ulonglong)local_58 * (ulonglong)uVar10 >> 0x20) +
         (uint)CARRY4(uVar2,uVar8);
    FUN_08019fc2(param_1,auStack_60);
    FUN_0802aa86(param_2,auStack_60);
  }
  else {
    FUN_080262f4(param_2,param_1,0x38);
    if (iVar6 != 0) {
      FUN_0801a0fc(param_1,auStack_60,iVar6);
      uVar2 = *(uint *)(param_2 + 0x28);
      uVar10 = *(uint *)(param_2 + 0x18);
      lVar1 = (ulonglong)*(uint *)(param_2 + 4) * (ulonglong)local_48 +
              CONCAT44(*(uint *)(param_2 + 4) * ((int)local_48 >> 0x1f),uVar2 - local_38);
      uVar5 = (uint)lVar1;
      uVar3 = (uint)((ulonglong)local_5c * (ulonglong)uVar10);
      *(uint *)(param_2 + 0x28) = uVar5 - uVar3;
      *(uint *)(param_2 + 0x2c) =
           ((((*(int *)(param_2 + 0x2c) - iStack_34) - (uint)(uVar2 < local_38)) +
            (int)((ulonglong)lVar1 >> 0x20)) -
           (local_5c * ((int)uVar10 >> 0x1f) +
           (int)((ulonglong)local_5c * (ulonglong)uVar10 >> 0x20))) - (uint)(uVar5 < uVar3);
      uVar5 = *(uint *)(param_2 + 0x30);
      uVar3 = uVar5 - local_30;
      lVar1 = (ulonglong)*(uint *)(param_2 + 8) * (ulonglong)local_48;
      uVar7 = (uint)lVar1;
      uVar2 = uVar3 + uVar7;
      uVar8 = (uint)((ulonglong)local_58 * (ulonglong)uVar10);
      *(uint *)(param_2 + 0x30) = uVar2 - uVar8;
      *(uint *)(param_2 + 0x34) =
           ((((*(int *)(param_2 + 0x34) - iStack_2c) - (uint)(uVar5 < local_30)) +
            *(int *)(param_2 + 0xc) * local_48 +
            *(uint *)(param_2 + 8) * ((int)local_48 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20) +
            (uint)CARRY4(uVar3,uVar7)) -
           (iStack_54 * uVar10 +
           local_58 * ((int)uVar10 >> 0x1f) + (int)((ulonglong)local_58 * (ulonglong)uVar10 >> 0x20)
           )) - (uint)(uVar2 < uVar8);
      FUN_08019fc2(param_2,auStack_60);
    }
    FUN_080262f4(param_1,auStack_60,0x38);
  }
  *(uint *)(param_1 + 0x38) = uVar9;
  return;
}



/* ===== FUN_0801a35e @ 0801a35e ===== */

longlong FUN_0801a35e(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 0x50);
  iVar1 = FUN_0802ab14(param_1,param_2,uVar2);
  if (iVar1 == 0) {
    return (ulonglong)param_4 << 0x20;
  }
  iVar1 = FUN_0802ab14(param_1 + 0x28,iVar1,uVar2);
  return CONCAT44(param_4,(uint)(iVar1 != 0));
}



/* ===== FUN_0801a384 @ 0801a384 ===== */

uint FUN_0801a384(int param_1,float *param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint in_fpscr;
  undefined4 uVar7;
  
  if (*(uint *)(param_1 + 0x40) < *(uint *)(param_1 + 0x50)) {
    return 1;
  }
  iVar1 = FUN_0801a014(param_1,param_1 + 0x28);
  if (iVar1 != 0) {
    if (*(int *)(param_1 + 0x1c) == *(int *)(param_1 + 0x18)) {
      uVar6 = *(uint *)(param_1 + 0x2c);
      uVar5 = *(uint *)(param_1 + 4);
      uVar4 = uVar5;
      if (uVar6 < uVar5) {
        uVar4 = uVar6;
        uVar6 = uVar5;
      }
      if (uVar4 < 0x40) {
        uVar4 = (uint)*(byte *)((int)param_2 + uVar4 + 8);
      }
      else {
        uVar7 = VectorUnsignedToFloat(uVar4,(byte)(in_fpscr >> 0x16) & 3);
        fVar2 = (float)FUN_0802ab98(uVar7);
        fVar3 = (float)FUN_0802a9a0(uVar7);
        fVar3 = *param_2 + param_2[1] * fVar2 + fVar3;
        uVar4 = VectorFloatToUnsigned(fVar3 * fVar3,3);
      }
      return ~-(uint)(uVar4 < uVar6) >> 0x1f;
    }
    fVar2 = (float)FUN_0802ab50(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
    fVar3 = (float)FUN_0802ab50(*(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x34));
    if (fVar2 == fVar3) {
      return 1;
    }
    if (ABS(fVar2 - fVar3) / (fVar2 + fVar3) < DAT_0801a5dc) {
      return 1;
    }
  }
  return 0;
}



/* ===== FUN_0801a478 @ 0801a478 ===== */

undefined4 FUN_0801a478(float param_1,int param_2)

{
  undefined4 unaff_r7;
  
  if (*(char *)(param_2 + 0xc) != '\0') {
    if ((*(int *)(param_2 + 0x2c) == *(int *)(param_2 + 0x28)) &&
       (((*(int *)(param_2 + 0x14) < 0x14 || (param_1 < DAT_0801a5e0)) ||
        (*(char *)(param_2 + 0x3c) == '\0')))) {
      return unaff_r7;
    }
    FUN_080165ce();
  }
  return unaff_r7;
}



/* ===== FUN_0801a4c0 @ 0801a4c0 ===== */

void FUN_0801a4c0(int param_1,byte *param_2)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  uint in_fpscr;
  float fVar7;
  float fVar8;
  
  iVar6 = *(int *)(param_1 + 0x28);
  if (*(int *)(param_1 + (uint)*param_2 * 4 + 0x2c) == iVar6) {
    FUN_08019ed4(param_1 + 0x10,param_2);
    if (0x800 < *(int *)(param_1 + 0x28)) {
      uVar3 = *(int *)(param_1 + 0x34) + 0x10;
      if (*DAT_0801abb4 + 0x8000U <= uVar3) {
        uVar3 = *(int *)(param_1 + 0x34) - 0x7ff0;
      }
      *(uint *)(param_1 + 0x34) = uVar3;
      FUN_08019f22(param_1 + 0x10);
    }
  }
  else {
    FUN_08019e9c();
    uVar3 = *(int *)(param_1 + 0x34) + iVar6 * 0x10;
    if (*DAT_0801abb4 + 0x8000U <= uVar3) {
      uVar3 = uVar3 - 0x8000;
    }
    *(uint *)(param_1 + 0x34) = uVar3;
  }
  if (*param_2 == 0) {
    fVar4 = (float)FUN_0802ab50(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1c));
    fVar7 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x28),(byte)(in_fpscr >> 0x16) & 3)
    ;
    fVar4 = (fVar4 * DAT_0801a5e4) / fVar7 + DAT_0801a5e8;
    uVar3 = in_fpscr & 0xfffffff;
    uVar1 = uVar3 | (uint)(fVar4 < 0.0) << 0x1f | (uint)(fVar4 == 0.0) << 0x1e;
    in_fpscr = uVar1 | (uint)NAN(fVar4) << 0x1c;
    bVar2 = (byte)(uVar1 >> 0x18);
    if (((bool)(bVar2 >> 6 & 1) || bVar2 >> 7 != ((byte)(in_fpscr >> 0x1c) & 1)) ||
       (in_fpscr = uVar3, fVar4 == 0.0)) {
      fVar4 = DAT_0801a8a0;
    }
    else {
      if (*(int *)(param_1 + 0x10) == 0) {
        fVar7 = DAT_0801a8a0;
      }
      else {
        fVar7 = (float)VectorUnsignedToFloat
                                 (*(undefined4 *)(param_1 + 0x14),(byte)(uVar3 >> 0x16) & 3);
        fVar8 = (float)VectorUnsignedToFloat(*(int *)(param_1 + 0x10),(byte)(uVar3 >> 0x16) & 3);
        fVar7 = (fVar7 * DAT_0801a5ec) / fVar8;
      }
      fVar4 = fVar7 / fVar4;
    }
    *DAT_0801b10c = fVar4;
  }
  if (*(int *)(param_1 + 0x30) == *(int *)(param_1 + 0x28)) {
    fVar4 = DAT_0801a8a0;
  }
  else {
    uVar5 = FUN_0802ab50(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x24));
    fVar4 = (float)FUN_0802a9a0(uVar5);
    fVar7 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x28),(byte)(in_fpscr >> 0x16) & 3)
    ;
    fVar4 = (fVar4 * DAT_0801a8a4) / fVar7;
  }
  *(float *)(param_1 + 0x38) = fVar4;
  return;
}



/* ===== FUN_0801a5f0 @ 0801a5f0 ===== */

undefined8
FUN_0801a5f0(byte *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  byte bVar1;
  int iVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar3;
  undefined4 local_20;
  
  bVar1 = *param_1;
  if (bVar1 == 0) {
    iVar2 = *(int *)(param_1 + 0x118);
    *(int *)(param_1 + 0x118) = iVar2 + 1;
    local_20 = param_3;
    if (0x3f < iVar2 + 1) {
      FUN_0802ac38(param_1 + 8,(int)*(char *)(param_2 + 1));
      *(int *)(param_1 + 0x40) = param_2;
      FUN_08019e9c(param_1 + 8,param_2);
      *param_1 = 1;
      param_1[1] = 1;
      return CONCAT44(param_4,param_3);
    }
  }
  else {
    if (bVar1 == 2) {
      FUN_0802ac38(param_1 + 8,(int)*(char *)(param_2 + 1));
      FUN_0802a9be(param_1 + 8,param_2);
      param_1[1] = 4;
      uVar3 = extraout_r1_00;
    }
    else {
      if (1 < bVar1) {
        return CONCAT44(param_4,param_3);
      }
      FUN_0802ac38(param_1 + 8,(int)*(char *)(param_2 + 1));
      FUN_0802a9be(param_1 + 8,param_2);
      uVar3 = extraout_r1;
    }
    local_20 = param_5;
    FUN_0801a8a8(param_1,uVar3,param_3,param_4);
  }
  return CONCAT44(param_4,local_20);
}



/* ===== FUN_0801a680 @ 0801a680 ===== */

undefined8 FUN_0801a680(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint in_fpscr;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  int local_38;
  int local_34;
  
  uVar8 = DAT_0801b110;
  iVar12 = param_1 + 0xd8;
  if (*(int *)(param_1 + 0xb0) == 0) {
    FUN_080262f4(param_1 + 0x98,iVar12,0x39);
    FUN_0802aa70(iVar12);
    *(undefined4 *)(param_1 + 0x100) = 0;
    *(undefined4 *)(param_1 + 0x104) = 0;
    *(undefined4 *)(param_1 + 0x108) = 0;
    *(undefined4 *)(param_1 + 0x10c) = 0;
    *(undefined1 *)(param_1 + 0x110) = 0;
    if (*(char *)(param_1 + 0xd0) == '\0') {
      iVar12 = *(int *)(param_1 + 0xb0);
      goto joined_r0x0801a730;
    }
LAB_0801a732:
    uVar8 = 0;
  }
  else {
    iVar4 = FUN_0801a044(param_1 + 0x98,iVar12,DAT_0801b110);
    iVar5 = FUN_0801a044(param_1 + 0x98,param_1 + 0x58,uVar8);
    if (iVar4 == 0) {
      local_38 = *(int *)(param_1 + 0xb0);
      local_34 = *(int *)(param_1 + 0xf0);
      piVar6 = &local_34;
      if (*(int *)(param_1 + 0xb0) < *(int *)(param_1 + 0xf0)) {
        piVar6 = &local_38;
      }
      *(int *)(param_1 + 0x120) = *piVar6;
      uVar7 = *(uint *)(param_1 + 0xb0);
      if ((iVar5 == 0) || (0x10 < (int)uVar7)) {
        if ((3 < (int)uVar7) &&
           (((iVar5 == 0 && ((int)uVar7 <= *(int *)(param_1 + 0xf0) * 2)) ||
            (*(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 4, iVar5 == 0)))) {
          fVar16 = (float)FUN_0802ac80(param_1 + 0x58);
          fVar17 = (float)FUN_0802ac80(param_1 + 0x98);
          if (*(int *)(param_1 + 0xf0) < 1) {
            fVar18 = DAT_0801a8a0;
          }
          else {
            fVar18 = (float)VectorUnsignedToFloat
                                      (*(undefined4 *)(param_1 + 0xdc),(byte)(in_fpscr >> 0x16) & 3)
            ;
            fVar19 = (float)VectorSignedToFloat(*(int *)(param_1 + 0xf0),
                                                (byte)(in_fpscr >> 0x16) & 3);
            fVar18 = fVar18 / fVar19;
          }
          if (fVar18 <= fVar16) {
            if (fVar16 < fVar17 && (fVar16 < fVar17 && fVar17 < fVar18)) goto LAB_0801a876;
          }
          else if (fVar18 < fVar17 && (fVar18 < fVar17 && fVar17 < fVar16)) {
LAB_0801a876:
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
      }
      else {
        uVar9 = *(uint *)(param_1 + 0xc0);
        uVar11 = *(uint *)(param_1 + 0x70);
        lVar2 = (ulonglong)*(uint *)(param_1 + 0x9c) * (ulonglong)uVar11 +
                CONCAT44(*(uint *)(param_1 + 0x9c) * ((int)uVar11 >> 0x1f),
                         uVar9 + *(uint *)(param_1 + 0x80));
        uVar13 = (uint)lVar2;
        lVar1 = (ulonglong)*(uint *)(param_1 + 0x5c) * (ulonglong)uVar7;
        uVar10 = (uint)lVar1;
        *(uint *)(param_1 + 0xc0) = uVar13 - uVar10;
        *(uint *)(param_1 + 0xc4) =
             ((*(int *)(param_1 + 0xc4) +
               *(int *)(param_1 + 0x84) + (uint)CARRY4(uVar9,*(uint *)(param_1 + 0x80)) +
              (int)((ulonglong)lVar2 >> 0x20)) -
             (*(uint *)(param_1 + 0x5c) * ((int)uVar7 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20))) -
             (uint)(uVar13 < uVar10);
        uVar9 = *(uint *)(param_1 + 200);
        uVar15 = uVar9 + *(uint *)(param_1 + 0x88);
        lVar1 = (ulonglong)*(uint *)(param_1 + 0xa0) * (ulonglong)uVar11;
        uVar13 = (uint)lVar1;
        uVar10 = uVar15 + uVar13;
        lVar2 = (ulonglong)*(uint *)(param_1 + 0x60) * (ulonglong)uVar7;
        uVar14 = (uint)lVar2;
        *(uint *)(param_1 + 200) = uVar10 - uVar14;
        *(uint *)(param_1 + 0xcc) =
             ((*(int *)(param_1 + 0xcc) +
               *(int *)(param_1 + 0x8c) + (uint)CARRY4(uVar9,*(uint *)(param_1 + 0x88)) +
              *(int *)(param_1 + 0xa4) * uVar11 +
              *(uint *)(param_1 + 0xa0) * ((int)uVar11 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20) +
              (uint)CARRY4(uVar15,uVar13)) -
             (*(int *)(param_1 + 100) * uVar7 +
             *(uint *)(param_1 + 0x60) * ((int)uVar7 >> 0x1f) + (int)((ulonglong)lVar2 >> 0x20))) -
             (uint)(uVar10 < uVar14);
        FUN_08019f74(param_1 + 0x98,param_1 + 0x58);
        bVar3 = *(byte *)(param_1 + 1) | 4;
      }
    }
    else {
      FUN_0802aa86(param_1 + 0x98,iVar12);
      FUN_0802aa70(iVar12);
      *(undefined4 *)(param_1 + 0x100) = 0;
      *(undefined4 *)(param_1 + 0x104) = 0;
      *(undefined4 *)(param_1 + 0x108) = 0;
      *(undefined4 *)(param_1 + 0x10c) = 0;
      *(undefined1 *)(param_1 + 0x110) = 0;
      iVar12 = *(int *)(param_1 + 0xb0);
      if ((iVar5 == 0) && (*(int *)(param_1 + 0x70) * 2 <= iVar12)) {
        *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) | 1;
      }
joined_r0x0801a730:
      if (iVar12 < 0xc0) goto LAB_0801a732;
      bVar3 = *(byte *)(param_1 + 1) | 2;
    }
    *(byte *)(param_1 + 1) = bVar3;
    uVar8 = 1;
  }
  return CONCAT44(param_4,uVar8);
}



/* ===== FUN_0801a8a8 @ 0801a8a8 ===== */

undefined8 FUN_0801a8a8(int param_1,undefined4 param_2,uint param_3,int param_4,int param_5)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  bool bVar13;
  uint in_fpscr;
  float fVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  float fVar18;
  int iVar19;
  int local_60;
  int local_5c;
  undefined4 *local_58;
  uint local_50;
  int iStack_4c;
  
  fVar4 = DAT_0801abc0;
  fVar3 = DAT_0801abbc;
  fVar2 = DAT_0801abb8;
  local_58 = (undefined4 *)(param_1 + 0xa0);
  iVar11 = param_1 + 0x98;
  local_50 = param_3;
  iStack_4c = param_4;
  while (*(int *)(param_1 + 0x48) <= *(int *)(param_1 + 0x20)) {
    FUN_0801a1ae(param_1 + 8,param_1 + 0xd8);
    *(undefined1 *)(param_1 + 0x110) = *(undefined1 *)(param_1 + 0x44);
    *(undefined1 *)(param_1 + 0x44) = 0;
    iVar5 = FUN_0801a680(param_1);
    if (iVar5 == 0) break;
    uVar9 = *(int *)(param_1 + 0x20) + local_58[0x14] + 0x40;
    if ((int)((uint)*(byte *)(param_1 + 1) << 0x1f) < 0) {
      *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xfe;
      uVar12 = *(uint *)(param_1 + 0x11c);
      uVar7 = uVar9 + local_58[4];
      bVar13 = local_50 < uVar7 * 0x4000;
      uVar8 = local_50 + uVar7 * -0x4000;
      iVar5 = iStack_4c - (((int)uVar7 >> 0x1f) << 0xe | uVar7 >> 0x12);
      fVar14 = (float)FUN_0802aca8(iVar11,(int)uVar12 / 2);
      iVar10 = VectorFloatToUnsigned(fVar14 + 0.5,3);
      if (*(int *)(param_1 + 0x98) == 0) {
        fVar14 = DAT_0801ace0;
      }
      else {
        fVar14 = (float)VectorUnsignedToFloat(iVar10,(byte)(in_fpscr >> 0x16) & 3);
        fVar18 = (float)VectorUnsignedToFloat(*(int *)(param_1 + 0x98),(byte)(in_fpscr >> 0x16) & 3)
        ;
        fVar14 = (fVar14 * fVar4) / fVar18;
      }
      uVar15 = FUN_0802ad20(iVar11,DAT_0801b110);
      uVar16 = FUN_0802ad98(iVar11,(int)uVar12 / 2);
      uVar17 = FUN_0802ae58(iVar11);
      local_5c = param_5;
      local_60 = iVar10;
      FUN_0801abc4(fVar14,uVar15,uVar16,uVar17,param_1,extraout_r1,uVar8 + uVar12 * 0x1000,
                   (iVar5 - (uint)bVar13) +
                   (((int)uVar12 >> 0x1f) << 0xc | uVar12 >> 0x14) +
                   (uint)CARRY4(uVar8,uVar12 * 0x1000));
    }
    if ((int)((uint)*(byte *)(param_1 + 1) << 0x1e) < 0) {
      *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xfd;
      iVar10 = *(int *)(param_1 + 0x9c);
      iVar5 = local_58[4];
      if (local_58[5] == iVar5) {
        if (*(int *)(param_1 + 0x98) == 0) {
          fVar14 = DAT_0801ace0;
        }
        else {
          fVar14 = (float)VectorUnsignedToFloat(iVar10,(byte)(in_fpscr >> 0x16) & 3);
          fVar18 = (float)VectorUnsignedToFloat
                                    (*(int *)(param_1 + 0x98),(byte)(in_fpscr >> 0x16) & 3);
          fVar14 = (fVar14 * fVar4) / fVar18;
        }
      }
      else {
        fVar14 = (float)FUN_0802ab50(*local_58,local_58[1]);
        fVar18 = (float)VectorSignedToFloat(iVar5,(byte)(in_fpscr >> 0x16) & 3);
        fVar14 = (fVar14 * fVar3) / fVar18 + fVar2;
        uVar7 = in_fpscr & 0xfffffff | (uint)(fVar14 < 0.0) << 0x1f | (uint)(fVar14 == 0.0) << 0x1e;
        in_fpscr = uVar7 | (uint)NAN(fVar14) << 0x1c;
        bVar1 = (byte)(uVar7 >> 0x18);
        if ((bool)(bVar1 >> 6 & 1) || bVar1 >> 7 != ((byte)(in_fpscr >> 0x1c) & 1)) {
          fVar14 = DAT_0801ace0;
        }
        fVar14 = fVar14 * *DAT_0801b10c;
      }
      uVar15 = FUN_0802ad20(iVar11,DAT_0801b110);
      uVar16 = FUN_0802aedc(iVar11,extraout_r1_00,*local_58,local_58[1]);
      uVar17 = FUN_0802ae58(iVar11);
      uVar7 = iVar5 + uVar9 * 2;
      local_5c = param_5;
      local_60 = iVar10;
      FUN_0801abc4(fVar14,uVar15,uVar16,uVar17,param_1,iStack_4c,local_50 + uVar7 * -0x2000,
                   (iStack_4c - (((int)uVar7 >> 0x1f) << 0xd | uVar7 >> 0x13)) -
                   (uint)(local_50 < uVar7 * 0x2000));
    }
    if ((int)((uint)*(byte *)(param_1 + 1) << 0x1d) < 0) {
      *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) & 0xfb | 1;
      uVar8 = *(uint *)(param_1 + 0x120);
      bVar13 = local_50 < uVar9 * 0x4000;
      uVar7 = local_50 + uVar9 * -0x4000;
      iVar5 = iStack_4c - (((int)uVar9 >> 0x1f) << 0xe | uVar9 >> 0x12);
      iVar10 = local_58[4] - (int)uVar8 / 2;
      fVar14 = (float)FUN_0802aca8(iVar11,iVar10);
      iVar19 = VectorFloatToUnsigned(fVar14 + 0.5,3);
      if (*(int *)(param_1 + 0x98) == 0) {
        fVar14 = DAT_0801ace0;
      }
      else {
        fVar14 = (float)VectorUnsignedToFloat(iVar19,(byte)(in_fpscr >> 0x16) & 3);
        fVar18 = (float)VectorUnsignedToFloat(*(int *)(param_1 + 0x98),(byte)(in_fpscr >> 0x16) & 3)
        ;
        fVar14 = (fVar14 * fVar4) / fVar18;
      }
      uVar15 = FUN_0802ad20(iVar11,DAT_0801b110);
      uVar16 = FUN_0802ad98(iVar11,iVar10);
      uVar17 = FUN_0802ae58(iVar11);
      local_5c = param_5;
      local_60 = iVar19;
      FUN_0801abc4(fVar14,uVar15,uVar16,uVar17,param_1,extraout_r1_01,uVar7 + uVar8 * -0x1000,
                   ((iVar5 - (uint)bVar13) - (((int)uVar8 >> 0x1f) << 0xc | uVar8 >> 0x14)) -
                   (uint)(uVar7 < uVar8 * 0x1000));
    }
    FUN_080262f4(param_1 + 0x58,iVar11,0x39);
    FUN_080262f4(iVar11,param_1 + 0xd8,0x39);
    local_60 = local_58[4];
    local_5c = *(int *)(param_1 + 0x70);
    if ((int)local_58[4] < *(int *)(param_1 + 0x70)) {
      piVar6 = &local_60;
    }
    else {
      piVar6 = &local_5c;
    }
    *(int *)(param_1 + 0x11c) = *piVar6;
    FUN_0802aa70(param_1 + 0xd8);
    local_58[0x18] = 0;
    local_58[0x19] = 0;
    local_58[0x1a] = 0;
    local_58[0x1b] = 0;
    *(undefined1 *)(param_1 + 0x110) = 0;
  }
  return CONCAT44(param_4,param_3);
}



/* ===== FUN_0801abc4 @ 0801abc4 ===== */

void FUN_0801abc4(float param_1,undefined4 param_2,float param_3,float param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                 uint param_10)

{
  uint uVar1;
  uint in_fpscr;
  float fVar2;
  float fVar3;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_36;
  float local_32;
  float local_2e;
  undefined2 local_2a;
  uint local_28;
  
  param_10 = param_10 & DAT_0801b114;
  fVar2 = param_3 * DAT_0801aea8;
  fVar3 = (float)VectorUnsignedToFloat
                           (*(undefined4 *)(DAT_0801b118 + 0x40),(byte)(in_fpscr >> 0x16) & 3);
  if (fVar3 <= fVar2) {
    fVar3 = (float)VectorUnsignedToFloat
                             (*(undefined4 *)(DAT_0801b118 + 0x44),
                              (byte)((in_fpscr & 0xfffffff) >> 0x16) & 3);
    if (fVar2 < fVar3) {
      param_10 = param_10 | 1;
    }
    else if (fVar2 < DAT_0801aee0) {
      param_10 = param_10 | 2;
    }
    else {
      param_10 = param_10 | 3;
      if (DAT_0801af28 <= param_3) {
        param_3 = DAT_0801af2c;
      }
    }
  }
  uVar1 = FUN_0801af3c(param_1);
  if (uVar1 == 1) {
    param_10 = param_10 | 0x100;
  }
  else if (uVar1 != 0) {
    if (uVar1 == 3) {
      param_10 = param_10 | 0x300;
      if (DAT_0801af50 <= param_1) {
        param_1 = DAT_0801af30;
      }
    }
    else if (uVar1 < 3) {
      param_10 = param_10 | 0x200;
    }
  }
  local_36 = param_9;
  if (DAT_0801af38 <= param_4 * DAT_0801af34) {
    local_2a = 0x3de;
  }
  else {
    local_2a = (undefined2)(int)(param_4 * DAT_0801af34);
  }
  local_28 = param_10 & 0xf303 | 0x1000;
  local_40 = param_7;
  local_3c = param_8;
  local_32 = param_1;
  local_2e = param_3;
  FUN_080180c4(&local_40);
  return;
}



/* ===== FUN_0801ace4 @ 0801ace4 ===== */

undefined4 FUN_0801ace4(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  param_1[2] = 0;
  iVar1 = *param_1 + param_1[1] * 0x10;
  uVar2 = iVar1 + 0x10;
  if (*param_1 + 0x8000U <= uVar2) {
    uVar2 = iVar1 - 0x7ff0;
  }
  param_1[0x11] = uVar2;
  FUN_0802aa70(param_1 + 8);
  FUN_0802aa70(param_1 + 0x14);
  FUN_0802af24(param_1 + 0x1e);
  uVar3 = 0;
  uVar4 = 0x40;
  param_1 = param_1 + 0x68;
  do {
    param_1[9] = uVar2;
    FUN_0802aa70(param_1);
    param_1[0x13] = uVar2;
    FUN_0802aa70(param_1 + 10);
    param_1[0x14] = uVar4;
    uVar3 = uVar3 + 1;
    uVar4 = uVar4 >> 1;
    param_1 = param_1 + 0x16;
  } while (uVar3 < 7);
  return param_4;
}



/* ===== FUN_0801ad46 @ 0801ad46 ===== */

void FUN_0801ad46(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = *param_1;
  uVar3 = param_1[1];
  if ((int)uVar3 < 0) {
    if ((uVar3 != 0xffffffff) || (-1 < (int)uVar2)) {
      uVar2 = 0x8000000;
    }
  }
  else {
    uVar4 = *param_2;
    uVar1 = uVar2 >> 0x18 | uVar3 << 8;
    *param_2 = uVar4 + uVar1;
    param_2[1] = param_2[1] + ((int)uVar3 >> 0x18) + (uint)CARRY4(uVar4,uVar1);
    uVar2 = uVar2 & 0xffffff;
    *param_1 = uVar2;
    param_1[1] = 0;
  }
  param_2[2] = uVar2;
  return;
}



/* ===== FUN_0801ad8a @ 0801ad8a ===== */

bool FUN_0801ad8a(uint *param_1,uint *param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar2 = param_2[4] + 500;
  bVar5 = 999 < uVar2;
  if (bVar5) {
    uVar4 = (uint)((ulonglong)uVar2 * (ulonglong)DAT_0801b11c >> 0x29);
    uVar2 = uVar2 + uVar4 * -1000;
    param_2[3] = uVar4 + param_2[3];
  }
  param_2[4] = uVar2;
  uVar2 = *param_1 + param_3;
  uVar4 = param_4 + param_1[1] + (uint)CARRY4(*param_1,param_3);
  *param_1 = uVar2;
  param_1[1] = uVar4;
  if ((int)uVar4 < 0) {
    uVar2 = 0;
  }
  else {
    if (!bVar5) {
      return bVar5;
    }
    uVar3 = *param_2;
    uVar1 = uVar2 >> 0x18 | uVar4 * 0x100;
    *param_2 = uVar3 + uVar1;
    param_2[1] = param_2[1] + ((int)uVar4 >> 0x18) + (uint)CARRY4(uVar3,uVar1);
    uVar2 = uVar2 & 0xffffff;
    *param_1 = uVar2;
    param_1[1] = 0;
  }
  param_2[2] = uVar2;
  return bVar5;
}



/* ===== FUN_0801ae04 @ 0801ae04 ===== */

int FUN_0801ae04(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = DAT_0801b118;
  *(undefined4 *)(DAT_0801b118 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *param_1 = 0;
  param_1[1] = 0;
  return iVar1 + 0x10;
}



/* ===== FUN_0801ae1c @ 0801ae1c ===== */

void FUN_0801ae1c(undefined4 *param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar2 = DAT_0801b118;
  iVar3 = FUN_0801ad8a(param_1,DAT_0801b118 + 0x10);
  if (iVar3 == 0) {
    return;
  }
  uVar4 = *(uint *)(iVar2 + 0x10);
  uVar5 = *(uint *)(iVar2 + 0x14);
  if ((uVar5 < 2) || ((uVar5 < 3 && (uVar4 < DAT_0801b120)))) {
    lVar1 = (ulonglong)*(uint *)(iVar2 + 0x4c) * 10;
    uVar6 = (uint)((ulonglong)lVar1 >> 0x20);
    if ((uVar5 < uVar6) || (uVar5 <= uVar6 && uVar4 <= (uint)lVar1)) {
      lVar1 = (ulonglong)*(uint *)(iVar2 + 0x48) * 10;
      uVar6 = (uint)((ulonglong)lVar1 >> 0x20);
      if ((uVar5 < uVar6) || (uVar5 <= uVar6 && uVar4 <= (uint)lVar1)) {
        iVar3 = 0;
      }
      else {
        iVar3 = 1;
      }
    }
    else {
      iVar3 = 2;
    }
  }
  else {
    iVar3 = 3;
  }
  FUN_08021118(DAT_0801b124,2,iVar3);
  if (iVar3 == 3) {
    *(uint *)(iVar2 + 0x10) = DAT_0801b120;
    *(undefined4 *)(iVar2 + 0x14) = 2;
    *(undefined4 *)(iVar2 + 0x18) = 0;
    *param_1 = 0;
    param_1[1] = 0;
  }
  FUN_08015c6c(*(undefined4 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0x14),
               *(undefined4 *)(iVar2 + 0x1c));
  return;
}



/* ===== FUN_0801aeac @ 0801aeac ===== */

void FUN_0801aeac(int param_1)

{
  uint uVar1;
  
  uVar1 = *(int *)(DAT_0801b118 + 0x34) - *(int *)(param_1 + 0xc);
  if (uVar1 < 0x3c) {
    return;
  }
  if (uVar1 < 0x4b0) {
    if ((*(uint *)(DAT_0801b118 + 0x2c) ==
         (uint)(*(uint *)(DAT_0801b118 + 0x28) < *(uint *)(param_1 + 8))) &&
       (*(uint *)(DAT_0801b118 + 0x28) - *(uint *)(param_1 + 8) < 10)) {
      return;
    }
  }
  FUN_0801aee4();
  return;
}



/* ===== FUN_0801aee4 @ 0801aee4 ===== */

void FUN_0801aee4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_16;
  uint local_12;
  undefined4 uStack_c;
  
  iVar1 = DAT_0801b118;
  uVar3 = *(undefined4 *)(DAT_0801b118 + 0x28);
  *(undefined4 *)(param_1 + 8) = uVar3;
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar1 + 0x34);
  uStack_c = param_4;
  uVar2 = FUN_08017dbe();
  disableIRQinterrupts();
  local_20 = *DAT_0801b128;
  local_1c = DAT_0801b128[1];
  enableIRQinterrupts();
  local_12 = uVar2 & 0xf303 | 0x1000;
  local_16 = uVar3;
  FUN_080180d2(&local_20);
  return;
}



/* ===== FUN_0801af3c @ 0801af3c ===== */

undefined4 FUN_0801af3c(float param_1,float param_2)

{
  uint uVar1;
  uint in_fpscr;
  float fVar2;
  float fVar3;
  
  uVar1 = in_fpscr & 0xfffffff;
  if (!NAN(param_1) && !NAN(DAT_0801af50)) {
    return 3;
  }
  if (!NAN(param_2) && !NAN(DAT_0801b104)) {
    return 0xffffffff;
  }
  param_1 = param_1 * 10.0;
  fVar2 = (float)VectorUnsignedToFloat
                           (*(undefined4 *)(DAT_0801b118 + 0x54),(byte)(uVar1 >> 0x16) & 3);
  if (DAT_0801b108 <= param_2) {
    fVar3 = (1.0 - param_2 * 0.5) * param_1;
    uVar1 = uVar1 | (uint)(fVar3 < fVar2) << 0x1f;
    if (SUB41(uVar1 >> 0x1f,0) == (NAN(fVar3) || NAN(fVar2))) {
      return 2;
    }
    fVar2 = (float)VectorUnsignedToFloat
                             (*(undefined4 *)(DAT_0801b118 + 0x50),(byte)(uVar1 >> 0x16) & 3);
    if (fVar3 < fVar2) {
      if (fVar2 <= (param_2 * 0.5 * 2.0 + 1.0) * param_1) {
        return 0xffffffff;
      }
      return 0;
    }
  }
  else {
    uVar1 = uVar1 | (uint)(param_1 < fVar2) << 0x1f;
    if (SUB41(uVar1 >> 0x1f,0) == (NAN(param_1) || NAN(fVar2))) {
      return 2;
    }
    fVar2 = (float)VectorUnsignedToFloat
                             (*(undefined4 *)(DAT_0801b118 + 0x50),(byte)(uVar1 >> 0x16) & 3);
    if (param_1 < fVar2) {
      return 0;
    }
  }
  return 1;
}



/* ===== FUN_0801b014 @ 0801b014 ===== */

void FUN_0801b014(void)

{
  int iVar1;
  int iVar2;
  undefined4 in_r3;
  
  iVar2 = DAT_0801b12c;
  iVar1 = DAT_0801b118;
  FUN_0801ad46(DAT_0801b12c,DAT_0801b118 + 0x10);
  FUN_0801ad46(iVar2 + 8,iVar1 + 0x28,in_r3);
  return;
}



/* ===== FUN_0801b05a @ 0801b05a ===== */

void FUN_0801b05a(void)

{
  undefined4 unaff_r7;
  
  FUN_0801aee4(DAT_0801b134);
  FUN_080165ce(DAT_0801b138);
  FUN_08015a4c(0xbf800000,0x3f800000,0);
  FUN_08015a74(0xbf800000,0x3f800000,0,unaff_r7);
  return;
}



/* ===== FUN_0801b094 @ 0801b094 ===== */

undefined4 FUN_0801b094(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  undefined4 extraout_r1;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint in_fpscr;
  uint uVar15;
  float fVar16;
  float fVar17;
  undefined4 uVar18;
  float fVar19;
  undefined4 uVar20;
  float fVar21;
  float fVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  undefined1 local_74;
  undefined1 local_73;
  undefined2 local_72;
  undefined4 local_70;
  float local_6c;
  float local_68;
  int local_64;
  int local_60;
  undefined4 local_5a;
  float local_56;
  undefined2 local_52;
  undefined2 local_50;
  undefined4 local_4e;
  undefined1 local_4a;
  
  piVar2 = DAT_0801b130;
  iVar14 = -1;
  local_73 = 0xff;
  local_74 = *(undefined1 *)(param_1 + 1);
  local_72 = (undefined2)*(undefined4 *)(param_1 + 4);
  fVar16 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 4),(byte)(in_fpscr >> 0x16) & 3);
  local_70 = *(undefined4 *)(param_1 + 8);
  fVar16 = DAT_0802b0b0 / fVar16;
  local_6c = *(float *)(param_1 + 0xc) * fVar16 + 0.5;
  local_68 = fVar16 * DAT_0802b0b4 * fVar16 * *(float *)(param_1 + 0x10) + 0.5;
  FUN_08019e9c(DAT_0801b130 + 0x14,&local_74);
  FUN_0801a4c0(piVar2 + 4,&local_74);
  iVar4 = piVar2[1] + 1;
  if (0x7ff < iVar4) {
    iVar4 = 0;
  }
  piVar2[1] = iVar4;
  iVar12 = DAT_0802b4b8;
  FUN_080262d4(*piVar2 + iVar4 * 0x10,&local_74,0x10);
  fVar16 = DAT_0802b0b8;
  uVar8 = 0;
  piVar10 = piVar2 + 0x68;
  do {
    iVar4 = FUN_0801a35e(piVar10,&local_74);
    if ((iVar4 != 0) && (iVar4 = FUN_0801a384(piVar10,iVar12), iVar4 == 0)) {
      if ((int)*(char *)(piVar10[9] + 1) < (int)uVar8) {
        *(char *)(piVar10[9] + 1) = (char)uVar8;
      }
      if (piVar10[6] < piVar2[0xe]) {
        FUN_080262f4(piVar2 + 8,piVar10,0x28);
        iVar4 = piVar10[6];
        if (piVar10[8] == iVar4) {
          fVar17 = DAT_0802b0bc;
        }
        else {
          uVar18 = FUN_0802ab50(piVar10[4],piVar10[5]);
          fVar17 = (float)FUN_0802a9a0(uVar18);
          fVar5 = (float)VectorSignedToFloat(iVar4,(byte)(in_fpscr >> 0x16) & 3);
          fVar17 = (fVar17 * fVar16) / fVar5;
        }
        piVar2[0x12] = (int)fVar17;
      }
    }
    uVar8 = uVar8 + 1;
    piVar10 = piVar10 + 0x16;
    iVar12 = iVar12 + 0x48;
  } while (uVar8 < 7);
  FUN_0802fd94(piVar2 + 0x14);
  FUN_08015e20(500);
  uVar18 = FUN_0802fd94(piVar2 + 8);
  disableIRQinterrupts();
  uVar9 = *DAT_0802b4bc;
  uVar11 = DAT_0802b4bc[1];
  enableIRQinterrupts();
  fVar5 = (float)FUN_0802ab50(piVar2[10],piVar2[0xb]);
  fVar17 = DAT_0802b320;
  fVar16 = DAT_0802b31c;
  fVar21 = (float)VectorSignedToFloat(piVar2[0xe],(byte)(in_fpscr >> 0x16) & 3);
  fVar5 = (fVar5 * DAT_0802b31c) / fVar21 + DAT_0802b320;
  uVar15 = in_fpscr & 0xfffffff | (uint)(fVar5 < 0.0) << 0x1f | (uint)(fVar5 == 0.0) << 0x1e;
  uVar8 = uVar15 | (uint)NAN(fVar5) << 0x1c;
  bVar1 = (byte)(uVar15 >> 0x18);
  if ((bool)(bVar1 >> 6 & 1) || bVar1 >> 7 != ((byte)(uVar8 >> 0x1c) & 1)) {
    fVar5 = DAT_0802b490;
  }
  fVar21 = (float)FUN_0802ae58(piVar2 + 8);
  fVar19 = (float)FUN_0802ad20(piVar2 + 8,DAT_0802b4c0);
  FUN_08015c34(piVar2[0xf] != piVar2[0xe]);
  iVar4 = FUN_08017dc4(0xc0,0x40);
  uVar8 = uVar8 & 0xfffffff;
  uVar13 = ~-(uint)(iVar4 == 0) >> 0x1f;
  uVar15 = uVar13;
  if (0.5 <= fVar19) {
    uVar15 = 0;
  }
  FUN_08015a4c(uVar18,fVar19,uVar15);
  iVar12 = FUN_0801af3c(uVar18,fVar19);
  iVar4 = DAT_0802b4c4;
  FUN_08021118(DAT_0802b4c4,0,iVar12);
  if (iVar12 == 3) {
    uVar18 = DAT_0802b494;
  }
  uVar8 = uVar8 & 0xfffffff;
  if (DAT_0802b498 <= fVar21) {
    uVar13 = 0;
  }
  uVar20 = FUN_0801a478(fVar5,piVar2 + 4);
  FUN_08015a74(uVar20,fVar21,uVar13);
  iVar12 = DAT_0802b4c8;
  fVar3 = DAT_0802b4a0;
  fVar22 = (float)VectorUnsignedToFloat
                            (*(undefined4 *)(DAT_0802b4c8 + 0x40),(byte)(uVar8 >> 0x16) & 3);
  uVar8 = uVar8 & 0xfffffff;
  fVar22 = fVar22 * DAT_0802b4a0;
  fVar6 = (float)piVar2[0x12];
  if ((float)piVar2[0x12] < fVar5 * DAT_0802b49c) {
    fVar6 = fVar5 * DAT_0802b49c;
  }
  if (fVar5 + fVar6 < fVar22) {
    iVar14 = 0;
  }
  else {
    uVar13 = uVar8 | (uint)(fVar5 < fVar22) << 0x1f;
    uVar15 = uVar13 | (uint)(NAN(fVar5) || NAN(fVar22)) << 0x1c;
    fVar22 = (float)VectorUnsignedToFloat
                              (*(undefined4 *)(DAT_0802b4c8 + 0x44),(byte)(uVar15 >> 0x16) & 3);
    fVar22 = fVar22 * DAT_0802b4a0;
    if (((byte)(uVar13 >> 0x1f) != ((byte)(uVar15 >> 0x1c) & 1)) ||
       (uVar15 = uVar8, fVar22 <= fVar5 + fVar6)) {
      uVar15 = uVar15 & 0xfffffff;
      uVar13 = uVar15 | (uint)(fVar5 < fVar22) << 0x1f;
      uVar8 = uVar13 | (uint)(NAN(fVar5) || NAN(fVar22)) << 0x1c;
      if ((byte)(uVar13 >> 0x1f) == ((byte)(uVar8 >> 0x1c) & 1)) {
        uVar8 = uVar15;
        if (fVar5 < DAT_0802b4a4) {
          iVar14 = 2;
        }
        else {
          iVar14 = 3;
        }
      }
    }
    else {
      iVar14 = 1;
    }
  }
  FUN_08021118(iVar4,1,iVar14);
  if (iVar14 == 3) {
    fVar5 = DAT_0802b4a4;
  }
  fVar6 = (float)FUN_0802ab50(piVar2[0x16],piVar2[0x17]);
  fVar22 = (float)VectorSignedToFloat(piVar2[0x1a],(byte)(uVar8 >> 0x16) & 3);
  fVar6 = (fVar6 * fVar16) / fVar22 + fVar17;
  uVar8 = uVar8 & 0xfffffff | (uint)(fVar6 < DAT_0802b4a8) << 0x1f;
  uVar15 = uVar8 | (uint)(NAN(fVar6) || NAN(DAT_0802b4a8)) << 0x1c;
  if ((byte)(uVar8 >> 0x1f) == ((byte)(uVar15 >> 0x1c) & 1)) {
    fVar6 = DAT_0802b4a4;
  }
  uVar23 = FUN_0802aa28(fVar6 * DAT_0802b4ac);
  iVar14 = DAT_0802b4cc;
  uVar7 = (undefined4)((ulonglong)uVar23 >> 0x20);
  uVar24 = FUN_0801ad8a(DAT_0802b4cc + 8,iVar12 + 0x28,(int)uVar23,uVar7);
  uVar20 = (undefined4)((ulonglong)uVar24 >> 0x20);
  if ((int)uVar24 != 0) {
    FUN_0801aeac(iVar14 + 8);
    uVar20 = extraout_r1;
  }
  FUN_0801ae1c(iVar14,uVar20,(int)uVar23,uVar7);
  FUN_0802132a(iVar4);
  uVar8 = FUN_08017dbe();
  iVar14 = piVar2[2];
  piVar2[2] = iVar14 + 1;
  if (-1 < (iVar14 + 1) * -0x80000000) {
    uVar13 = FUN_0802fe30(piVar2 + 8);
    local_64 = uVar9 - uVar13;
    local_60 = (uVar11 - ((int)uVar13 >> 0x1f)) - (uint)(uVar9 < uVar13);
    if (NAN(fVar19 * DAT_0802b4b0) || NAN(DAT_0802b4b4)) {
      local_52 = (undefined2)(int)(fVar19 * DAT_0802b4b0);
    }
    else {
      local_52 = 0x3de;
    }
    fVar6 = fVar21 * DAT_0802b4b0;
    uVar13 = uVar15 & 0xfffffff | (uint)(fVar6 < DAT_0802b4b4) << 0x1f;
    uVar15 = uVar13 | (uint)(NAN(fVar6) || NAN(DAT_0802b4b4)) << 0x1c;
    if ((byte)(uVar13 >> 0x1f) == ((byte)(uVar15 >> 0x1c) & 1)) {
      local_50 = 0x3de;
    }
    else {
      local_50 = (undefined2)(int)fVar6;
    }
    local_4e = 0;
    local_4a = 0;
    local_5a = uVar18;
    local_56 = fVar5;
    FUN_08017ec4(&local_64);
  }
  uVar13 = FUN_0802fe30(piVar2 + 0x14);
  uVar20 = FUN_0802fd94(piVar2 + 0x14);
  fVar6 = (float)FUN_0802ab50(piVar2[0x16],piVar2[0x17]);
  fVar22 = (float)VectorSignedToFloat(piVar2[0x1a],(byte)(uVar15 >> 0x16) & 3);
  local_56 = (fVar6 * fVar16) / fVar22 + fVar17;
  if (local_56 <= 0.0) {
    local_56 = DAT_0802b490;
  }
  local_64 = uVar9 - uVar13;
  local_60 = (uVar11 - ((int)uVar13 >> 0x1f)) - (uint)(uVar9 < uVar13);
  local_5a = uVar20;
  FUN_0801807e(&local_64);
  FUN_0801a5f0(piVar2 + 0x1e,piVar2[0x71],uVar9,uVar11,uVar8 | 0x1000);
  if (*(char *)(iVar4 + 0x18) == '\0') {
    iVar14 = 0;
  }
  else {
    *(undefined1 *)(iVar4 + 0x18) = 0;
    iVar14 = (int)*(char *)(iVar4 + 0x14);
  }
  if (0 < iVar14) {
    FUN_080181f4(uVar18,fVar19,uVar9,uVar11,iVar14 + 0x13U & 0xff);
  }
  if (*(char *)(iVar4 + 0x1d) == '\0') {
    iVar14 = 0;
  }
  else {
    *(undefined1 *)(iVar4 + 0x1d) = 0;
    iVar14 = (int)*(char *)(iVar4 + 0x19);
  }
  if (0 < iVar14) {
    FUN_08018234(fVar5,fVar21,uVar9,uVar11,iVar14 + 8U & 0xff);
  }
  if (*(char *)(iVar4 + 0x22) == '\0') {
    iVar4 = 0;
  }
  else {
    *(undefined1 *)(iVar4 + 0x22) = 0;
    iVar4 = (int)*(char *)(iVar4 + 0x1e);
  }
  if (0 < iVar4) {
    fVar16 = (float)FUN_0802ab50(*(undefined4 *)(iVar12 + 0x10),*(undefined4 *)(iVar12 + 0x14));
    FUN_0801828e(fVar16 * fVar3,uVar9,uVar11,*(undefined4 *)(iVar12 + 0x1c),iVar4 + 0xbU & 0xff);
  }
  return param_4;
}



/* ===== FUN_0801b09c @ 0801b09c ===== */

void FUN_0801b09c(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 unaff_r7;
  
  puVar1 = (undefined4 *)FUN_0801ae04(DAT_0801b12c);
  FUN_08015c6c(*puVar1,puVar1[1],puVar1[3]);
  uVar2 = FUN_08017dbe();
  disableIRQinterrupts();
  enableIRQinterrupts();
  FUN_080181c8(*DAT_0801b128,DAT_0801b128[1],uVar2,4);
  FUN_08017cdc(1,unaff_r7);
  return;
}



/* ===== FUN_0801b0ce @ 0801b0ce ===== */

longlong FUN_0801b0ce(undefined4 param_1,int param_2)

{
  uint unaff_r7;
  
  if (param_2 < 0x18) {
    return (ulonglong)unaff_r7 << 0x20;
  }
  FUN_080262d4(param_1,DAT_0801b13c,0x18);
  return CONCAT44(unaff_r7,0x18);
}



/* ===== FUN_0801b0e4 @ 0801b0e4 ===== */

void FUN_0801b0e4(void)

{
  int iVar1;
  int iVar2;
  undefined4 in_r3;
  
  iVar2 = DAT_0801b12c;
  iVar1 = DAT_0801b118;
  FUN_0801ad46(DAT_0801b12c + 8,DAT_0801b118 + 0x28);
  FUN_0801ad46(iVar2,iVar1 + 0x10,in_r3);
  return;
}



/* ===== FUN_0801b140 @ 0801b140 ===== */

void FUN_0801b140(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801b168;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801b16c;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801b170 @ 0801b170 ===== */

void FUN_0801b170(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801b198;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801b19c;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801b1a0 @ 0801b1a0 ===== */

undefined4 * FUN_0801b1a0(undefined4 *param_1)

{
  FUN_08026250();
  *param_1 = DAT_0801b1b0;
  return param_1;
}



/* ===== FUN_0801b272 @ 0801b272 ===== */

undefined4 FUN_0801b272(void)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 in_r3;
  uint in_fpscr;
  float fVar6;
  float fVar7;
  undefined2 local_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  
  uVar2 = DAT_0801b450;
  puVar1 = DAT_0801b44c;
  local_18 = 0;
  local_1c = 0;
  *DAT_0801b44c = *DAT_0801b44c | 0x800000;
  uStack_14 = in_r3;
  iVar3 = FUN_0802b5e0(uVar2,0xa6,0xd,&local_18,3);
  iVar4 = FUN_0802b5e0(uVar2,0xa6,5,(int)&local_1c + 1,1);
  iVar5 = FUN_0802b5e0(uVar2,0xa6,4,&local_1c,1);
  *puVar1 = *puVar1 & 0xff7fffff;
  if (iVar5 == 0 && (iVar4 == 0 && iVar3 == 0)) {
    fVar6 = (float)VectorUnsignedToFloat(local_18,(byte)(in_fpscr >> 0x16) & 3);
    fVar7 = (float)VectorUnsignedToFloat
                             ((uint)*(ushort *)(&LAB_0801b468 + (uint)((byte)local_1c >> 4) * 2) *
                              (uint)(byte)(&DAT_0801b460)[local_1c._1_1_],
                              (byte)(in_fpscr >> 0x16) & 3);
    local_18 = VectorFloatToUnsigned((fVar6 * DAT_0801b444) / fVar7,3);
  }
  else {
    FUN_080167f6(2);
  }
  return local_18;
}



/* ===== FUN_0801b328 @ 0801b328 ===== */

undefined8 FUN_0801b328(void)

{
  uint *puVar1;
  uint *puVar2;
  int *piVar3;
  int iVar4;
  bool bVar5;
  undefined8 uVar6;
  int local_14;
  
  piVar3 = DAT_0801b458;
  puVar1 = DAT_0801b44c;
  local_14 = 0;
  do {
  } while (*DAT_0801b458 - (*DAT_0801b454 + 0xccd) < 1);
  *DAT_0801b44c = *DAT_0801b44c | 0x800000;
  puVar2 = DAT_0801b450;
  *DAT_0801b450 = *DAT_0801b450 | 1;
  iVar4 = FUN_0802b51e(puVar2,0xa6,0,&local_14);
  puVar2 = DAT_0801b450;
  if (iVar4 == 0) {
    do {
    } while (*piVar3 - (*piVar3 + 0x148) < 1);
    uVar6 = FUN_0802b5e0(DAT_0801b450,0xa6,6,&local_14);
    bVar5 = (int)uVar6 == 0;
    iVar4 = (int)((ulonglong)uVar6 >> 0x20);
    if (bVar5) {
      iVar4 = local_14;
    }
    if (bVar5 && iVar4 == 0xb1) {
      local_14 = 2;
      iVar4 = FUN_0802b51e(puVar2,0xa6,0,&local_14);
      if (iVar4 == 0) {
        *(undefined1 *)(DAT_0801b448 + 0x10) = 1;
      }
    }
  }
  iVar4 = DAT_0801b448;
  *puVar1 = *puVar1 & 0xff7fffff;
  if (*(char *)(iVar4 + 0x10) == '\0') {
    FUN_080167f6(1);
    return CONCAT44(local_14,1);
  }
  if ((*(byte *)(DAT_0801b45c + 0x68) & 3) == 2) {
    FUN_080165ac(iVar4,0x28f);
  }
  return CONCAT44(local_14,1);
}



/* ===== FUN_0801b3de @ 0801b3de ===== */

undefined8 FUN_0801b3de(void)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 local_14;
  
  puVar2 = DAT_0801b450;
  puVar1 = DAT_0801b44c;
  local_14 = 0;
  *DAT_0801b44c = *DAT_0801b44c | 0x800000;
  FUN_0802b51e(puVar2,0xa6,0,&local_14);
  *puVar2 = *puVar2 & 0xfffffffe;
  *puVar1 = *puVar1 & 0xff7fffff;
  return CONCAT44(local_14,1);
}



/* ===== FUN_0801b41c @ 0801b41c ===== */

void FUN_0801b41c(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 in_r3;
  
  iVar2 = DAT_0801b448;
  uVar1 = DAT_08016698;
  if (*(char *)(DAT_0801b448 + 0x10) == '\0') {
    return;
  }
  *(int *)(DAT_0801b448 + 8) = *DAT_08016694 + 0x28f;
  FUN_080215a4(uVar1,iVar2);
  FUN_080215c8(uVar1,iVar2,in_r3);
  return;
}



/* ===== FUN_0801b42e @ 0801b42e ===== */

void FUN_0801b42e(void)

{
  FUN_080165ce(DAT_0801b448);
  return;
}



/* ===== FUN_0801b434 @ 0801b434 ===== */

uint FUN_0801b434(void)

{
  return ~-(uint)(*(char *)(DAT_0801b448 + 0xd) == '\0') >> 0x1f;
}



/* ===== FUN_0801b474 @ 0801b474 ===== */

void FUN_0801b474(uint *param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  
  bVar2 = (byte)param_2;
  bVar3 = (byte)((uint)param_2 >> 8);
  bVar4 = (byte)((uint)param_2 >> 0x10);
  bVar1 = (byte)((uint)param_2 >> 0x18);
  iVar5 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1
                                  | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) <<
                                1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18 |
                  (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1
                                  | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) <<
                                1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
                  (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1
                                  | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) <<
                                1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
                  (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1
                                  | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) <<
                                1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7)) << 1;
  *param_1 = param_3 << iVar5 | *param_1 & ~(3 << iVar5);
  return;
}



/* ===== FUN_0801b494 @ 0801b494 ===== */

void FUN_0801b494(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  
  bVar2 = (byte)param_2;
  bVar3 = (byte)((uint)param_2 >> 8);
  bVar4 = (byte)((uint)param_2 >> 0x10);
  bVar1 = (byte)((uint)param_2 >> 0x18);
  iVar5 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1
                                  | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) <<
                                1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18 |
                  (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1
                                  | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) <<
                                1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
                  (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1
                                  | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) <<
                                1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
                  (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1
                                  | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) <<
                                1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7)) << 1;
  *(uint *)(param_1 + 0xc) = param_3 << iVar5 | *(uint *)(param_1 + 0xc) & ~(3 << iVar5);
  return;
}



/* ===== FUN_0801b4b4 @ 0801b4b4 ===== */

void FUN_0801b4b4(int param_1)

{
  undefined4 *puVar1;
  
  FUN_0801466c();
  puVar1 = DAT_0801b7c0;
  *DAT_0801b7bc = 0;
  *puVar1 = 0;
  *(undefined1 *)(param_1 + 0xd) = 0;
  return;
}



/* ===== FUN_0801b4ca @ 0801b4ca ===== */

void FUN_0801b4ca(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = DAT_0801b7c4;
  if (param_1 == 0) {
    FUN_080165ce(DAT_0801b7c4);
    puVar1 = DAT_0801b7c0;
    *DAT_0801b7bc = 0;
    *puVar1 = 0;
    *(undefined1 *)(iVar2 + 0xd) = 0;
  }
  *(bool *)(iVar2 + 0x10) = param_1 != 0;
  return;
}



/* ===== FUN_0801b4ec @ 0801b4ec ===== */

void FUN_0801b4ec(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar3 = DAT_0801b7c8;
  uVar4 = (uint)*(byte *)(DAT_0801b7c8 + 5);
  if (5 < uVar4) {
    uVar4 = 5;
    *(undefined1 *)(DAT_0801b7c8 + 5) = 5;
  }
  iVar2 = DAT_0801b7c4;
  FUN_080165ac(DAT_0801b7c4,*(undefined4 *)(&DAT_0801b810 + uVar4 * 4));
  if ((*(char *)(iVar2 + 0x10) != '\0') &&
     ((param_1 != 0 ||
      (((*(byte *)(iVar3 + 0x68) & 3) != 0 &&
       (((*(byte *)(iVar3 + 0x68) & 3) != 2 || (iVar5 = FUN_0801b434(), iVar5 == 0)))))))) {
    uVar4 = (uint)*(byte *)(iVar3 + 1);
    if (9 < uVar4) {
      uVar4 = 9;
      *(undefined1 *)(iVar3 + 1) = 9;
    }
    puVar1 = DAT_0801b7c0;
    *DAT_0801b7bc = (uint)*(ushort *)(&DAT_0801b7fc + uVar4 * 2);
    *puVar1 = 1;
    *(undefined1 *)(iVar2 + 0xd) = 1;
  }
  return;
}



/* ===== FUN_0801b544 @ 0801b544 ===== */

void FUN_0801b544(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = DAT_0801b7c4;
  FUN_080165ce(DAT_0801b7c4);
  puVar1 = DAT_0801b7c0;
  *DAT_0801b7bc = 0;
  *puVar1 = 0;
  *(undefined1 *)(iVar2 + 0xd) = 0;
  return;
}



/* ===== FUN_0801b55c @ 0801b55c ===== */

undefined4 FUN_0801b55c(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  undefined4 in_r3;
  bool bVar7;
  
  iVar3 = DAT_0801b7c8;
  iVar2 = DAT_0801b7c4;
  if (*(char *)(DAT_0801b7c4 + 0xd) != '\0') {
    FUN_080165ce(DAT_0801b7c4);
    puVar1 = DAT_0801b7c0;
    *DAT_0801b7bc = 0;
    *puVar1 = 0;
    *(undefined1 *)(iVar2 + 0xd) = 0;
    return in_r3;
  }
  uVar5 = (uint)*(byte *)(DAT_0801b7c8 + 5);
  if (5 < uVar5) {
    uVar5 = 5;
    *(undefined1 *)(DAT_0801b7c8 + 5) = 5;
  }
  FUN_080165ac(iVar2,*(undefined4 *)(&DAT_0801b810 + uVar5 * 4));
  bVar7 = *(char *)(iVar2 + 0x10) == '\0';
  bVar4 = 0;
  if (!bVar7) {
    bVar4 = *(byte *)(iVar3 + 0x68) & 3;
    bVar7 = bVar4 == 0;
  }
  if ((!bVar7) && ((bVar4 != 2 || (iVar6 = FUN_0801b434(), iVar6 == 0)))) {
    uVar5 = (uint)*(byte *)(iVar3 + 1);
    if (9 < uVar5) {
      uVar5 = 9;
      *(undefined1 *)(iVar3 + 1) = 9;
    }
    puVar1 = DAT_0801b7c0;
    *DAT_0801b7bc = (uint)*(ushort *)(&DAT_0801b7fc + uVar5 * 2);
    *puVar1 = 1;
    *(undefined1 *)(iVar2 + 0xd) = 1;
  }
  return in_r3;
}



/* ===== FUN_0801b5da @ 0801b5da ===== */

void FUN_0801b5da(void)

{
  *DAT_0801b7d0 = 0x40;
  return;
}



/* ===== FUN_0801b5e2 @ 0801b5e2 ===== */

void FUN_0801b5e2(void)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 in_r3;
  
  puVar2 = DAT_0801b7d8;
  puVar1 = DAT_0801b7d4;
  *DAT_0801b7d4 = *DAT_0801b7d4 | 0x4000;
  uVar3 = *puVar1;
  FUN_0801b474(puVar2,1,2,uVar3 & 0x4000);
  FUN_0801b474(puVar2,2,2);
  puVar1 = DAT_0801b7dc;
  *puVar2 = *puVar2 & 0xfffffcff | 0x200;
  *puVar1 = *puVar1 | 0x40;
  FUN_0802b76c();
  FUN_0802b88c(1,uVar3 & 0x4000,in_r3);
  return;
}



/* ===== FUN_0801b630 @ 0801b630 ===== */

void FUN_0801b630(undefined1 param_1)

{
  int *piVar1;
  
  piVar1 = DAT_0801b7e0;
  do {
  } while (*DAT_0801b7e0 << 0x18 < 0);
  *DAT_0801b7cc = 0x20;
  *(undefined1 *)(piVar1 + 1) = param_1;
  return;
}



/* ===== FUN_0801b63e @ 0801b63e ===== */

void FUN_0801b63e(undefined1 param_1)

{
  int *piVar1;
  
  piVar1 = DAT_0801b7e0;
  do {
  } while (*DAT_0801b7e0 << 0x18 < 0);
  *DAT_0801b7d0 = 0x20;
  *(undefined1 *)(piVar1 + 1) = param_1;
  return;
}



/* ===== FUN_0801b652 @ 0801b652 ===== */

void FUN_0801b652(void)

{
  FUN_08016644(DAT_0801b7e8,DAT_0801b7e4,5,0);
  return;
}



/* ===== FUN_0801b65e @ 0801b65e ===== */

void FUN_0801b65e(int param_1)

{
  undefined4 uVar1;
  undefined4 unaff_r7;
  
  *DAT_0801b7ec = (char)param_1;
  if (param_1 == 0) {
    thunk_FUN_0801b630(0xc0);
    uVar1 = 0xa1;
  }
  else {
    thunk_FUN_0801b630(200);
    uVar1 = 0xa0;
  }
  thunk_FUN_0801b630(uVar1,unaff_r7);
  return;
}



/* ===== FUN_0801b680 @ 0801b680 ===== */

void FUN_0801b680(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = DAT_0801b7d8;
  FUN_0801b494(DAT_0801b7d8,1,0);
  FUN_0801b494(iVar1,2,0);
  FUN_0801b494(iVar1,0x10,0);
  piVar2 = DAT_0801b7e0;
  do {
  } while (*DAT_0801b7e0 << 0x18 < 0);
  *(undefined4 *)(iVar1 + 0x28) = 0x20;
  *(undefined1 *)(piVar2 + 1) = 0xa4;
  FUN_0802b9e2();
  FUN_0801ffd0(0);
  FUN_0802b9fc(0,0,0x7f,0x2f);
  FUN_080204dc();
  *DAT_0801b7f0 = 1;
  return;
}



/* ===== FUN_0801b6d4 @ 0801b6d4 ===== */

void FUN_0801b6d4(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_0801b7f0;
  FUN_080165ce(DAT_0801b7f0 + 1);
  *puVar2 = 0;
  FUN_0802b9d0();
  iVar1 = DAT_0801b7d8;
  *(undefined4 *)(DAT_0801b7d8 + 0x28) = 0x20;
  *(undefined4 *)(iVar1 + 0x28) = 0x40;
  FUN_0801b494(iVar1,1,2);
  FUN_0801b494(iVar1,2,2);
  FUN_0801b494(iVar1,0x10,2);
  *DAT_0801b7dc = *DAT_0801b7dc & 0xffffffbf;
  *DAT_0801b7d4 = *DAT_0801b7d4 & 0xffffbfff;
  return;
}



/* ===== FUN_0801ba30 @ 0801ba30 ===== */

void FUN_0801ba30(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801ba58;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801ba5c;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801ba60 @ 0801ba60 ===== */

void FUN_0801ba60(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801ba88;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801ba8c;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801ba90 @ 0801ba90 ===== */

void FUN_0801ba90(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801bab8;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801babc;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801bac0 @ 0801bac0 ===== */

void FUN_0801bac0(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801bae8;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801baec;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801bc58 @ 0801bc58 ===== */

void FUN_0801bc58(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801bc80;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801bc84;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801bc88 @ 0801bc88 ===== */

void FUN_0801bc88(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801bcb0;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801bcb4;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801be44 @ 0801be44 ===== */

void FUN_0801be44(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801be6c;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801be70;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801be74 @ 0801be74 ===== */

void FUN_0801be74(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801be9c;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801bea0;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801bea4 @ 0801bea4 ===== */

void FUN_0801bea4(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801becc;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801bed0;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801bed4 @ 0801bed4 ===== */

void FUN_0801bed4(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801befc;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801bf00;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801bf04 @ 0801bf04 ===== */

void FUN_0801bf04(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801bf2c;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801bf30;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801bf34 @ 0801bf34 ===== */

void FUN_0801bf34(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801bf5c;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801bf60;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801bf64 @ 0801bf64 ===== */

void FUN_0801bf64(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801bf8c;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801bf90;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801c030 @ 0801c030 ===== */

void FUN_0801c030(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801c058;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801c05c;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801c060 @ 0801c060 ===== */

void FUN_0801c060(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801c088;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801c08c;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801c090 @ 0801c090 ===== */

void FUN_0801c090(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801c0b8;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801c0bc;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801c0c0 @ 0801c0c0 ===== */

void FUN_0801c0c0(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801c0e8;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801c0ec;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801c174 @ 0801c174 ===== */

ushort FUN_0801c174(uint *param_1)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  ushort uVar4;
  ushort uVar5;
  
  *(undefined1 *)(DAT_0801c184 + 0x8f) = 1;
  iVar1 = DAT_0801c184;
  if (param_1 == (uint *)0x0) {
    return 0;
  }
  uVar4 = 0;
  uVar5 = 0;
  if (*(char *)(DAT_0801c184 + 0x8f) == '\0') goto LAB_0801c156;
  do {
    uVar2 = *param_1;
    while( true ) {
      if (uVar2 == 0) {
        if (uVar4 <= uVar5) {
          uVar4 = uVar5;
        }
        return uVar4;
      }
      if (uVar2 == 9) {
        uVar4 = uVar4 + 8;
      }
      else if (uVar2 == 10 || uVar2 == 0xd) {
        if (uVar4 < uVar5) {
          uVar4 = uVar5;
        }
        uVar5 = uVar4;
        uVar4 = 0;
      }
      else {
        pbVar3 = (byte *)FUN_08027218(uVar2,*(undefined4 *)(*DAT_0801c188 + 0xc),
                                      *(undefined4 *)(*DAT_0801c188 + 8));
        if (pbVar3 != (byte *)0x0) {
          uVar4 = uVar4 + *pbVar3;
        }
      }
      if (*(char *)(iVar1 + 0x8f) != '\0') break;
      param_1 = (uint *)((int)param_1 + 1);
LAB_0801c156:
      uVar2 = (uint)(byte)*param_1;
    }
    param_1 = param_1 + 1;
  } while( true );
}



/* ===== FUN_0801c1a8 @ 0801c1a8 ===== */

void FUN_0801c1a8(int param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_0801cc80;
  if (param_1 == 0) {
    *(uint *)(DAT_0801cc20 + 0xf4) = *(uint *)(DAT_0801cc20 + 0xf4) & 0xfffffeff;
    FUN_080157d4();
    *puVar1 = *puVar1 & 0xfffffffe;
    FUN_08020bd0(0);
    return;
  }
  *(uint *)(DAT_0801cc20 + 0xf4) = *(uint *)(DAT_0801cc20 + 0xf4) | 0x100;
  FUN_080157d4(1);
  FUN_080165a4(puVar1,1);
  return;
}



/* ===== FUN_0801c1e8 @ 0801c1e8 ===== */

undefined1 FUN_0801c1e8(undefined1 *param_1)

{
  return *param_1;
}



/* ===== FUN_0801c4ca @ 0801c4ca ===== */

undefined4 FUN_0801c4ca(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0801cc20;
  if (param_1 == DAT_0801cc20) {
    *(int *)(DAT_0801cc20 + 0x78) = param_2;
    iVar2 = FUN_0801cc24(iVar1 + 0x134,iVar1 + 0xc,2);
    if (iVar2 != param_2) {
      *(undefined4 *)(iVar1 + 0x78) = 0xffffffff;
      *(undefined4 *)(param_1 + 0xc) = 0;
      return 0;
    }
  }
  return 1;
}



/* ===== FUN_0801c52e @ 0801c52e ===== */

longlong FUN_0801c52e(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar1 = DAT_0801cc20;
  if (param_1 == DAT_0801cc20) {
    *(int *)(DAT_0801cc20 + 0x80) = param_2;
    iVar2 = FUN_0801cc24(iVar1 + 0x134,iVar1 + 0x10,0xc);
    if (iVar2 != param_2) {
      *(undefined4 *)(iVar1 + 0x80) = 0xffffffff;
      uVar3 = DAT_0801ce74[1];
      uVar4 = DAT_0801ce74[2];
      uVar5 = DAT_0801ce74[3];
      uVar6 = DAT_0801ce74[4];
      uVar7 = DAT_0801ce74[5];
      *(undefined4 *)(param_1 + 0x10) = *DAT_0801ce74;
      *(undefined4 *)(param_1 + 0x14) = uVar3;
      *(undefined4 *)(param_1 + 0x18) = uVar4;
      *(undefined4 *)(param_1 + 0x1c) = uVar5;
      *(undefined4 *)(param_1 + 0x20) = uVar6;
      *(undefined4 *)(param_1 + 0x24) = uVar7;
      return (ulonglong)param_4 << 0x20;
    }
  }
  return CONCAT44(param_4,1);
}



/* ===== FUN_0801c598 @ 0801c598 ===== */

longlong FUN_0801c598(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar1 = DAT_0801cc20;
  if (param_1 == DAT_0801cc20) {
    *(int *)(DAT_0801cc20 + 0x84) = param_2;
    iVar2 = FUN_0801cc24(iVar1 + 0x134,iVar1 + 0x28,0xc);
    if (iVar2 != param_2) {
      *(undefined4 *)(iVar1 + 0x84) = 0xffffffff;
      uVar3 = DAT_0801ce78[1];
      uVar4 = DAT_0801ce78[2];
      uVar5 = DAT_0801ce78[3];
      uVar6 = DAT_0801ce78[4];
      uVar7 = DAT_0801ce78[5];
      *(undefined4 *)(param_1 + 0x28) = *DAT_0801ce78;
      *(undefined4 *)(param_1 + 0x2c) = uVar3;
      *(undefined4 *)(param_1 + 0x30) = uVar4;
      *(undefined4 *)(param_1 + 0x34) = uVar5;
      *(undefined4 *)(param_1 + 0x38) = uVar6;
      *(undefined4 *)(param_1 + 0x3c) = uVar7;
      return (ulonglong)param_4 << 0x20;
    }
  }
  return CONCAT44(param_4,1);
}



/* ===== FUN_0801c63c @ 0801c63c ===== */

longlong FUN_0801c63c(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar1 = DAT_0801cc20;
  if (param_1 == DAT_0801cc20) {
    *(int *)(DAT_0801cc20 + 0x7c) = param_2;
    iVar2 = FUN_0802ba70(iVar1,iVar1);
    if (iVar2 != param_2) {
      *(undefined4 *)(iVar1 + 0x7c) = 0xffffffff;
      uVar3 = DAT_0801d078[1];
      uVar4 = DAT_0801d078[2];
      uVar5 = DAT_0801d078[3];
      uVar6 = DAT_0801d078[4];
      uVar7 = DAT_0801d078[5];
      *(undefined4 *)(param_1 + 0x40) = *DAT_0801d078;
      *(undefined4 *)(param_1 + 0x44) = uVar3;
      *(undefined4 *)(param_1 + 0x48) = uVar4;
      *(undefined4 *)(param_1 + 0x4c) = uVar5;
      *(undefined4 *)(param_1 + 0x50) = uVar6;
      *(undefined4 *)(param_1 + 0x54) = uVar7;
      return (ulonglong)param_4 << 0x20;
    }
  }
  return CONCAT44(param_4,1);
}



/* ===== FUN_0801cbce @ 0801cbce ===== */

void FUN_0801cbce(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_0801d550;
  uVar1 = FUN_0801cc24(DAT_0801d550,param_1 + 0xc,2);
  *(undefined4 *)(param_1 + 0x78) = uVar1;
  uVar1 = FUN_0802ba70(param_1,param_1);
  *(undefined4 *)(param_1 + 0x7c) = uVar1;
  uVar1 = FUN_0801cc24(uVar2,param_1 + 0x10,0xc);
  *(undefined4 *)(param_1 + 0x80) = uVar1;
  uVar1 = FUN_0801cc24(uVar2,param_1 + 0x28,0xc);
  *(undefined4 *)(param_1 + 0x84) = uVar1;
  uVar2 = FUN_0801cc24(uVar2,param_1 + 0x58,6);
  *(undefined4 *)(param_1 + 0x88) = uVar2;
  return;
}



/* ===== FUN_0801cc24 @ 0801cc24 ===== */

uint FUN_0801cc24(char *param_1,undefined2 *param_2,int param_3)

{
  uint *puVar1;
  undefined2 *puVar2;
  
  puVar1 = DAT_0801d554;
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
  for (; param_2 < puVar2; param_2 = param_2 + 1) {
    *(undefined2 *)puVar1 = *param_2;
  }
  return *puVar1 & 0xffff;
}



/* ===== FUN_0801cc84 @ 0801cc84 ===== */

uint FUN_0801cc84(char *param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = DAT_0801d554;
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



/* ===== FUN_0801ccda @ 0801ccda ===== */

undefined8 FUN_0801ccda(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_18;
  int local_14;
  
  iVar2 = DAT_0801d558;
  uVar5 = 1;
  bVar1 = true;
  local_14 = param_1;
  if (DAT_0801d55c <= *(uint *)(DAT_0801d558 + 0x74)) {
    *(undefined4 *)(DAT_0801d558 + 0x74) = DAT_0801d560;
    iVar3 = FUN_08026fa2();
    if (iVar3 != 0) {
      FUN_08016820(4);
    }
    local_14 = DAT_0801d564;
    uVar5 = 0;
    bVar1 = false;
  }
  FUN_08026e02(*(undefined4 *)(iVar2 + 0x74),4,&local_14);
  FUN_08026d9e(*(undefined4 *)(iVar2 + 0x74),4,&local_18);
  if (local_18 != local_14) {
    local_14 = 0;
    FUN_08026e02(*(undefined4 *)(iVar2 + 0x74),4,&local_14);
    if (bVar1) {
      uVar4 = 5;
    }
    else {
      uVar4 = 0;
    }
    FUN_08016820(uVar4);
  }
  *(int *)(iVar2 + 0x74) = *(int *)(iVar2 + 0x74) + 4;
  return CONCAT44(local_18,uVar5);
}



/* ===== FUN_0801cd4c @ 0801cd4c ===== */

int FUN_0801cd4c(void)

{
  ushort *puVar1;
  undefined4 uVar2;
  int iVar3;
  ushort *puVar4;
  uint *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  ushort *puVar10;
  code *pcVar11;
  
  iVar3 = DAT_0801d558;
  FUN_0801b0e4();
  uVar2 = DAT_0801ce70;
  pcVar9 = (char *)(iVar3 + 0x70);
  *(float *)(iVar3 + 0xec) = *(float *)(iVar3 + 0xec) * 4.0;
  *(float *)(iVar3 + 0xf0) = *(float *)(iVar3 + 0xf0) * 16.0;
  FUN_080270fa();
  if (*pcVar9 == '\0') {
    FUN_080262f4(iVar3,uVar2,0x70);
    FUN_0801d2f8(iVar3);
    FUN_0801cbce(iVar3);
    *(undefined4 *)(iVar3 + 0x74) = DAT_0801d568;
    FUN_0801ccda(0);
  }
  puVar4 = DAT_0801d56c;
  puVar1 = puVar4;
  while (puVar10 = puVar1 + 6, *puVar10 != 0xffff) {
    pcVar11 = *(code **)(puVar1 + 8);
    puVar1 = puVar10;
    if (pcVar11 != (code *)0x0) {
      iVar7 = (*pcVar11)(iVar3 + 0x90);
      iVar8 = (*pcVar11)(iVar3);
      if (iVar7 != iVar8) {
        FUN_0801cc84(iVar3 + 0x134,(uint)*puVar10 | iVar7 << 0x10);
        iVar7 = FUN_0801ccda();
        if (iVar7 == 0) {
          if (*pcVar9 == '\0') goto LAB_0801ce22;
          *pcVar9 = '\0';
          FUN_080262f4(iVar3,uVar2,0x70);
          FUN_0801d2f8(iVar3);
          FUN_0801cbce(iVar3);
          puVar1 = puVar4;
        }
      }
    }
  }
  FUN_080262f4(iVar3,iVar3 + 0x90,0x70);
  FUN_0801cbce(iVar3);
  *pcVar9 = '\x01';
LAB_0801ce22:
  FUN_08027126();
  FUN_0802babc(iVar3 + 0x134,0);
  puVar6 = DAT_0801d574;
  puVar5 = DAT_0801d570;
  *(float *)(iVar3 + 0xec) = *(float *)(iVar3 + 0xec) * 0.25;
  *(float *)(iVar3 + 0xf0) = *(float *)(iVar3 + 0xf0) * DAT_0801d074;
  *puVar5 = *puVar5 | 0x100;
  *puVar6 = 0;
  *puVar5 = *puVar5 & 0xfffffeff;
  return iVar3 + 0x90;
}



/* ===== FUN_0801ce7c @ 0801ce7c ===== */

uint FUN_0801ce7c(void)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  byte bVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined1 uVar10;
  code *pcVar11;
  undefined4 in_r3;
  uint uVar12;
  byte *pbVar13;
  uint uVar14;
  uint uVar15;
  undefined1 *puVar16;
  uint uVar17;
  
  iVar3 = DAT_0801d558;
  FUN_080262f4(DAT_0801d558,DAT_0801d07c,0x70,in_r3,in_r3);
  FUN_0801d2f8(iVar3);
  FUN_0801cbce(iVar3);
  uVar15 = DAT_0801d560;
  puVar16 = (undefined1 *)(iVar3 + 0x70);
  *puVar16 = 1;
  *(uint *)(iVar3 + 0x74) = uVar15;
  FUN_080270fa();
  piVar5 = DAT_0801d578;
  iVar4 = DAT_0801d56c;
  uVar2 = DAT_0801d550;
  uVar17 = uVar15;
  do {
    uVar12 = uVar15 & 0xfff;
    if (((uVar12 == 0) && (FUN_08026d9e(uVar15,0x1000,piVar5), uVar15 == uVar17)) &&
       (uVar12 = 4, uVar15 = DAT_0801d57c, *piVar5 != DAT_0801d564)) goto LAB_0801cf0c;
    uVar14 = *(uint *)((int)piVar5 + uVar12);
    if (uVar14 != 0) {
      if (uVar14 == 0xffffffff) {
        puVar1 = (uint *)((int)piVar5 + uVar12);
        goto joined_r0x0801cf8e;
      }
      uVar12 = FUN_0801cc84(uVar2,uVar14);
      if (uVar12 == uVar14) {
        uVar12 = uVar14 & 0xff;
        if (uVar12 < 0x5b) {
          if (*(ushort *)(iVar4 + uVar12 * 0xc) != uVar12) {
            FUN_08016820(1,uVar14 >> 0x10);
            break;
          }
          pcVar11 = *(code **)(iVar4 + uVar12 * 0xc + 8);
          if ((pcVar11 != (code *)0x0) && (iVar9 = (*pcVar11)(iVar3), iVar9 == 0)) {
            *puVar16 = 0;
            uVar8 = 2;
            goto LAB_0801cff4;
          }
        }
      }
      else {
        *puVar16 = 0;
        uVar8 = 3;
LAB_0801cff4:
        FUN_08016820(uVar8);
      }
    }
    uVar15 = uVar15 + 4;
  } while (uVar15 < DAT_0801d588);
  goto LAB_0801cf10;
joined_r0x0801cf8e:
  if (0xffc < uVar12) goto LAB_0801cfa0;
  if (*puVar1 != 0xffffffff) goto LAB_0801cf0c;
  uVar12 = uVar12 + 4;
  puVar1 = puVar1 + 1;
  goto joined_r0x0801cf8e;
LAB_0801cfa0:
  if ((0x1000 - uVar12 != 0) &&
     (uVar12 = (0x1000 - uVar12) * 8, *puVar1 >> (uVar12 & 0xff) != 0xffffffffU >> (uVar12 & 0xff)))
  {
LAB_0801cf0c:
    *puVar16 = 0;
  }
LAB_0801cf10:
  FUN_08027126();
  pbVar13 = (byte *)(iVar3 + 0x90);
  *(uint *)(iVar3 + 0x74) = uVar15;
  FUN_080262f4(pbVar13,iVar3,0x70);
  FUN_0802babc(uVar2,0);
  *(float *)(iVar3 + 0xec) = *(float *)(iVar3 + 0xec) * 0.25;
  *(undefined1 *)(iVar3 + 0x104) = 0;
  *(float *)(iVar3 + 0xf0) = *(float *)(iVar3 + 0xf0) * DAT_0801d074;
  bVar6 = FUN_08015794(*pbVar13,1);
  *pbVar13 = bVar6;
  *DAT_0801d584 = *(undefined4 *)(DAT_0801d580 + (uint)*pbVar13 * 4);
  FUN_0801c1a8((*(uint *)(iVar3 + 0xf4) & 0x1ff) >> 8);
  uVar15 = *(uint *)(iVar3 + 0xe0);
  if (uVar15 == 0) {
    uVar15 = 1;
  }
  else if (DAT_0801d58c <= uVar15) {
    uVar15 = DAT_0801d590;
  }
  *(uint *)(iVar3 + 0xe0) = uVar15;
  if (*(uint *)(iVar3 + 0xe4) < uVar15) {
    *(uint *)(iVar3 + 0xe4) = uVar15;
  }
  uVar15 = *(uint *)(iVar3 + 0xe4);
  if (uVar15 == 0) {
    uVar15 = 1;
  }
  else if (DAT_0801d58c <= uVar15) {
    uVar15 = DAT_0801d590;
  }
  *(uint *)(iVar3 + 0xe4) = uVar15;
  if (uVar15 < *(uint *)(iVar3 + 0xe0)) {
    *(uint *)(iVar3 + 0xe0) = uVar15;
  }
  if ((int)((uint)*(byte *)(iVar3 + 0xf4) << 0x1f) < 0) {
    uVar7 = 0xb;
    uVar10 = 3;
  }
  else {
    uVar7 = 0xe;
    uVar10 = 6;
  }
  *(undefined1 *)(iVar3 + 0x110) = uVar7;
  *(undefined1 *)(iVar3 + 0x124) = uVar10;
  uVar15 = FUN_08015da4((*(uint *)(iVar3 + 0xf8) & 0x3ff) >> 7);
  *(uint *)(iVar3 + 0xf8) = *(uint *)(iVar3 + 0xf8) & 0xfffffc7f | (uVar15 & 7) << 7;
  return uVar17;
}



/* ===== FUN_0801d080 @ 0801d080 ===== */

void FUN_0801d080(void)

{
  int iVar1;
  byte bVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 uVar7;
  undefined4 in_r3;
  byte *pbVar8;
  uint uVar9;
  int local_60 [2];
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  iVar1 = DAT_0801d558;
  iVar5 = DAT_0801d53c;
  uVar9 = *(uint *)(DAT_0801d53c + 0x68);
  pbVar8 = (byte *)(DAT_0801d558 + 0x90);
  *(uint *)(DAT_0801d558 + 0xf8) =
       *(uint *)(DAT_0801d558 + 0xf8) & 0xffffffdf | (uVar9 >> 5 & 1) << 5;
  uStack_28 = in_r3;
  FUN_0801c1a8((*(uint *)(iVar5 + 100) & 0x1ff) >> 8);
  if (*(int *)(iVar1 + 0xd0) == 0x28) {
LAB_0801d0bc:
    if (*(int *)(iVar1 + 0xd4) != 0x78) goto LAB_0801d0c2;
  }
  else {
    *(undefined4 *)(iVar1 + 0xd0) = 0x28;
    if (0x27 < *(uint *)(iVar1 + 0xd4)) goto LAB_0801d0bc;
    *(undefined4 *)(iVar1 + 0xd4) = 0x28;
LAB_0801d0c2:
    *(undefined4 *)(iVar1 + 0xd4) = 0x78;
    if (0x78 < *(uint *)(iVar1 + 0xd0)) {
      *(undefined4 *)(iVar1 + 0xd0) = 0x78;
    }
  }
  uVar4 = DAT_0801d594;
  if (*(uint *)(iVar1 + 0xd8) != DAT_0801d594) {
    *(uint *)(iVar1 + 0xd8) = DAT_0801d594;
    if (*(uint *)(iVar1 + 0xdc) < uVar4) {
      *(uint *)(iVar1 + 0xdc) = uVar4;
      goto LAB_0801d0f4;
    }
  }
  if (*(uint *)(iVar1 + 0xdc) != uVar4) {
    *(uint *)(iVar1 + 0xdc) = uVar4;
    if (uVar4 < *(uint *)(iVar1 + 0xd8)) {
      *(uint *)(iVar1 + 0xd8) = uVar4;
    }
  }
LAB_0801d0f4:
  *(undefined4 *)(iVar1 + 0xe0) = 200;
  if (*(uint *)(iVar1 + 0xe4) < 200) {
    *(undefined4 *)(iVar1 + 0xe4) = 200;
  }
  *(undefined4 *)(iVar1 + 0xe4) = 600;
  uVar4 = FUN_08015da4((uVar9 & 0x3ff) >> 7);
  *(uint *)(iVar1 + 0xf8) = *(uint *)(iVar1 + 0xf8) & 0xfffffc7f | (uVar4 & 7) << 7;
  FUN_0801d3dc((uVar9 & 0xfff) >> 10);
  local_40 = *(undefined4 *)(iVar1 + 0xa0);
  uStack_3c = *(undefined4 *)(iVar1 + 0xa4);
  uStack_38 = *(undefined4 *)(iVar1 + 0xa8);
  uStack_34 = *(undefined4 *)(iVar1 + 0xac);
  uStack_30 = *(undefined4 *)(iVar1 + 0xb0);
  uStack_2c = *(undefined4 *)(iVar1 + 0xb4);
  local_58 = *(undefined4 *)(iVar1 + 0xb8);
  uStack_54 = *(undefined4 *)(iVar1 + 0xbc);
  uStack_50 = *(undefined4 *)(iVar1 + 0xc0);
  uStack_4c = *(undefined4 *)(iVar1 + 0xc4);
  uStack_48 = *(undefined4 *)(iVar1 + 200);
  uStack_44 = *(undefined4 *)(iVar1 + 0xcc);
  FUN_080262f4(pbVar8,iVar5,0x70);
  FUN_0801d2f8(pbVar8);
  iVar5 = FUN_0801d2b6(0x50,local_60,1);
  if ((iVar5 != 0) && (iVar5 = FUN_0802442e(), iVar5 != local_60[0])) {
    FUN_080243e8(local_60[0]);
  }
  *(undefined4 *)(iVar1 + 0xa0) = local_40;
  *(undefined4 *)(iVar1 + 0xa4) = uStack_3c;
  *(undefined4 *)(iVar1 + 0xa8) = uStack_38;
  *(undefined4 *)(iVar1 + 0xac) = uStack_34;
  *(undefined4 *)(iVar1 + 0xb0) = uStack_30;
  *(undefined4 *)(iVar1 + 0xb4) = uStack_2c;
  *(undefined4 *)(iVar1 + 0xb8) = local_58;
  *(undefined4 *)(iVar1 + 0xbc) = uStack_54;
  *(undefined4 *)(iVar1 + 0xc0) = uStack_50;
  *(undefined4 *)(iVar1 + 0xc4) = uStack_4c;
  *(undefined4 *)(iVar1 + 200) = uStack_48;
  *(undefined4 *)(iVar1 + 0xcc) = uStack_44;
  bVar2 = FUN_08015794(*pbVar8,1);
  *pbVar8 = bVar2;
  *DAT_0801d584 = *(undefined4 *)(DAT_0801d580 + (uint)*pbVar8 * 4);
  if ((int)((uint)*(byte *)(iVar1 + 0xf4) << 0x1f) < 0) {
    uVar3 = 0xb;
    uVar7 = 3;
  }
  else {
    uVar3 = 0xe;
    uVar7 = 6;
  }
  *(undefined1 *)(iVar1 + 0x124) = uVar7;
  *(undefined1 *)(iVar1 + 0x110) = uVar3;
  *(uint *)(iVar1 + 0x108) = *(uint *)(iVar1 + 0x108) & DAT_0801d598 | 0x20;
  uVar6 = FUN_08017dbe();
  disableIRQinterrupts();
  enableIRQinterrupts();
  FUN_080181c8(*DAT_0801d59c,DAT_0801d59c[1],uVar6,3);
  return;
}



/* ===== FUN_0801d1e0 @ 0801d1e0 ===== */

undefined8 FUN_0801d1e0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  piVar1 = DAT_0801d5a0;
  while (*piVar1 != -1) {
    iVar2 = iVar2 + 4;
    piVar1 = piVar1 + 1;
  }
  if (iVar2 < param_2) {
    param_2 = iVar2;
  }
  FUN_080262d4(param_1,DAT_0801d5a0,param_2);
  return CONCAT44(param_4,param_2);
}



/* ===== FUN_0801d20a @ 0801d20a ===== */

undefined8
FUN_0801d20a(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_10;
  
  if ((*(byte *)(DAT_0801d558 + 0x106) & 3) == 0) {
    return CONCAT44(param_4,0xffffffff);
  }
  *param_1 = DAT_0801d5a4;
  local_10 = param_4;
  FUN_08023af0(param_1);
  iVar1 = FUN_0801d27c(0x10,&local_10,1,param_1);
  if (iVar1 != 0) {
    FUN_0802483e(local_10);
  }
  return CONCAT44(local_10,param_2);
}



/* ===== FUN_0801d24c @ 0801d24c ===== */

float FUN_0801d24c(float param_1,float *param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  
  if (param_3 < 0) {
    return DAT_0801d4c8;
  }
  pfVar1 = param_2 + param_3;
  fVar2 = *pfVar1;
  while (pfVar1 = pfVar1 + -1, param_2 <= pfVar1) {
    fVar2 = *pfVar1 + fVar2 * param_1;
  }
  return fVar2;
}



/* ===== FUN_0801d27c @ 0801d27c ===== */

uint FUN_0801d27c(uint param_1,undefined4 param_2,uint param_3,int *param_4)

{
  ushort *puVar1;
  uint uVar2;
  
  puVar1 = (ushort *)(param_4 + 1);
  if (*param_4 == DAT_0801d5a4) {
    while( true ) {
      if (puVar1[1] == 0xffff) break;
      uVar2 = (uint)*puVar1;
      if (puVar1[1] == param_1) {
        if (param_3 < uVar2) {
          return 0;
        }
        FUN_080262d4(param_2,puVar1 + 2,uVar2 << 2);
        return uVar2;
      }
      puVar1 = puVar1 + 2 + uVar2 * 2;
    }
  }
  return 0;
}



/* ===== FUN_0801d2b6 @ 0801d2b6 ===== */

uint FUN_0801d2b6(uint param_1,undefined4 param_2,uint param_3)

{
  ushort *puVar1;
  uint uVar2;
  
  puVar1 = (ushort *)(DAT_0801d5a0 + 1);
  if (*DAT_0801d5a0 == DAT_0801d5a4) {
    for (; puVar1[1] != 0xffff; puVar1 = puVar1 + uVar2 * 2 + 2) {
      uVar2 = (uint)*puVar1;
      if (puVar1[1] == param_1) {
        if (param_3 < uVar2) {
          return 0;
        }
        FUN_080262d4(param_2,puVar1 + 2,uVar2 << 2);
        return uVar2;
      }
    }
  }
  return 0;
}



/* ===== FUN_0801d2f8 @ 0801d2f8 ===== */

undefined4 FUN_0801d2f8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_0801d2b6(0x20,param_1 + 0x58,3);
  if (iVar1 == 0) {
    uVar2 = DAT_0801d5a8[1];
    uVar3 = DAT_0801d5a8[2];
    *(undefined4 *)(param_1 + 0x58) = *DAT_0801d5a8;
    *(undefined4 *)(param_1 + 0x5c) = uVar2;
    *(undefined4 *)(param_1 + 0x60) = uVar3;
  }
  if (param_1 == DAT_0801d5ac) {
    *(float *)(param_1 + 0x5c) = *(float *)(param_1 + 0x5c) * 0.25;
    *(float *)(param_1 + 0x60) = *(float *)(param_1 + 0x60) * DAT_0801d538;
  }
  return param_4;
}



/* ===== FUN_0801d3dc @ 0801d3dc ===== */

ulonglong FUN_0801d3dc(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint unaff_r7;
  
  if (3 < param_1) {
    param_1 = 3;
  }
  uVar2 = *(uint *)(DAT_0801d558 + 0xf8);
  *(uint *)(DAT_0801d558 + 0xf8) = uVar2 & 0xfffff3ff | (param_1 & 3) << 10;
  if (-1 < (int)(uVar2 << 0x19)) {
    return (ulonglong)param_1;
  }
  if (*(char *)(DAT_080196e0 + 0x18) == '\0') {
    return (ulonglong)unaff_r7 << 0x20;
  }
  iVar1 = FUN_0802a454(1,param_1 + 4 & 0xff);
  return CONCAT44(unaff_r7,~-(uint)(iVar1 == 0) >> 0x1f);
}



/* ===== FUN_0801d400 @ 0801d400 ===== */

void FUN_0801d400(uint param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar2 = DAT_0801d5b4;
  if (param_2 != 0 || param_1 != *DAT_0801d5b4) {
    if (param_2 == 0 && param_1 == 0) {
      param_1 = 1;
    }
    else if ((param_2 != 0) || (DAT_0801d5b8 <= param_1)) {
      param_2 = 0;
      param_1 = DAT_0801d5bc;
    }
    puVar1 = DAT_0801d5b4 + 1;
    *DAT_0801d5b4 = param_1;
    if (param_2 != 0 || *puVar1 < param_1) {
      puVar2[1] = param_1;
    }
  }
  return;
}



/* ===== FUN_0801d43a @ 0801d43a ===== */

void FUN_0801d43a(uint param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_0801d5b4;
  if (param_2 != 0 || param_1 != DAT_0801d5b4[1]) {
    if (param_2 == 0 && param_1 == 0) {
      param_1 = 1;
    }
    else if ((param_2 != 0) || (DAT_0801d5b8 <= param_1)) {
      param_2 = 0;
      param_1 = DAT_0801d5bc;
    }
    uVar2 = *DAT_0801d5b4;
    DAT_0801d5b4[1] = param_1;
    if ((param_2 == 0) && (param_1 < uVar2)) {
      *puVar1 = param_1;
    }
  }
  return;
}



/* ===== FUN_0801d474 @ 0801d474 ===== */

void FUN_0801d474(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_0801d5c0;
  if (param_1 != *DAT_0801d5c0) {
    if (param_1 == 0) {
      param_1 = 1;
    }
    else if (DAT_0801d594 < param_1) {
      param_1 = DAT_0801d594;
    }
    uVar2 = *(uint *)(DAT_0801d558 + 0xdc);
    *DAT_0801d5c0 = param_1;
    if (param_1 < uVar2) {
      param_1 = uVar2;
    }
    puVar1[1] = param_1;
  }
  return;
}



/* ===== FUN_0801d49c @ 0801d49c ===== */

void FUN_0801d49c(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_0801d5c0;
  if (param_1 != DAT_0801d5c0[1]) {
    if (param_1 == 0) {
      param_1 = 1;
    }
    else if (DAT_0801d594 < param_1) {
      param_1 = DAT_0801d594;
    }
    uVar2 = *(uint *)(DAT_0801d558 + 0xd8);
    DAT_0801d5c0[1] = param_1;
    if (uVar2 < param_1) {
      param_1 = uVar2;
    }
    *puVar1 = param_1;
  }
  return;
}



/* ===== FUN_0801d4cc @ 0801d4cc ===== */

void FUN_0801d4cc(uint param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar2 = DAT_0801d5c4;
  if (param_2 == 0 && param_1 == 0) {
    param_1 = 1;
  }
  else if ((param_2 != 0) || (DAT_0801d58c <= param_1)) {
    param_2 = 0;
    param_1 = DAT_0801d590;
  }
  puVar1 = DAT_0801d5c4 + 1;
  *DAT_0801d5c4 = param_1;
  if (param_2 != 0 || *puVar1 < param_1) {
    puVar2[1] = param_1;
  }
  return;
}



/* ===== FUN_0801d502 @ 0801d502 ===== */

void FUN_0801d502(uint param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_0801d5c4;
  if (param_2 == 0 && param_1 == 0) {
    param_1 = 1;
  }
  else if ((param_2 != 0) || (DAT_0801d58c <= param_1)) {
    param_2 = 0;
    param_1 = DAT_0801d590;
  }
  uVar2 = *DAT_0801d5c4;
  DAT_0801d5c4[1] = param_1;
  if ((param_2 == 0) && (param_1 < uVar2)) {
    *puVar1 = param_1;
  }
  return;
}



/* ===== FUN_0801d5c8 @ 0801d5c8 ===== */

undefined8 FUN_0801d5c8(int param_1,char *param_2)

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
      if (*piVar7 == 0x3c) goto LAB_0801d61a;
      *param_2 = cVar5;
      piVar6 = piVar7;
    }
    if (iVar2 == 0x3e) {
      if (*piVar7 != 0x3e) {
        param_2[1] = bVar4;
        *(int **)(param_1 + 0xa0) = piVar7;
        *(byte *)(param_1 + 0x9e) = bVar4 + 1;
        uVar3 = 1;
LAB_0801d62a:
        return CONCAT44(local_20[0],uVar3);
      }
LAB_0801d61a:
      piVar7 = piVar6 + 2;
    }
    else {
      uVar3 = 0;
      if (iVar2 == 0) goto LAB_0801d62a;
    }
    local_20[0] = iVar2;
    cVar1 = FUN_0801c174(local_20);
    bVar4 = (cVar5 + cVar1) - 1;
    if (*(byte *)(param_1 + 0x9d) < bVar4) {
      bVar4 = *(byte *)(param_1 + 0x9d);
    }
    cVar5 = bVar4 + 1;
    piVar6 = piVar7;
  } while( true );
}



/* ===== FUN_0801d62e @ 0801d62e ===== */

longlong FUN_0801d62e(int param_1,int param_2,undefined4 param_3,uint param_4)

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
    if (*(char *)(param_1 + 0x18) != '\0') goto LAB_0801d662;
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
LAB_0801d662:
      iVar2 = iVar2 + iVar4;
      if (iVar2 == iVar5) break;
      puVar3 = puVar3 + iVar4 * 2;
    }
    *(int *)(param_1 + 0x10) = iVar2;
  }
  *(undefined1 *)(param_1 + 0x18) = 0;
  return (ulonglong)param_4 << 0x20;
}



/* ===== FUN_0801d688 @ 0801d688 ===== */

void FUN_0801d688(undefined4 *param_1,undefined4 param_2,undefined2 *param_3,undefined4 param_4)

{
  *param_1 = DAT_0801d6b4;
  param_1[1] = param_2;
  param_1[3] = 0xffffffff;
  *(undefined1 *)(param_1 + 2) = 0;
  param_1[4] = 0;
  *(undefined1 *)((int)param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801d6b8;
  *(undefined1 *)((int)param_1 + 0x16) = 0;
  *(undefined1 *)((int)param_1 + 0x17) = 0;
  *(undefined2 *)(param_1 + 5) = *param_3;
  param_1[6] = param_4;
  return;
}



/* ===== FUN_0801d6bc @ 0801d6bc ===== */

void FUN_0801d6bc(void)

{
  *DAT_0801da14 = 1;
  return;
}



/* ===== FUN_0801d6c4 @ 0801d6c4 ===== */

void FUN_0801d6c4(void)

{
  uint uVar1;
  uint *puVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 in_r3;
  uint uVar8;
  undefined8 uVar9;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  undefined4 uStack_14;
  
  uStack_14 = in_r3;
  FUN_0802bb20(&local_40,0x2c,0);
  puVar2 = DAT_0801da1c;
  *DAT_0801da18 = *DAT_0801da18 | 0x100;
  puVar2[9] = 0xca;
  puVar2[9] = 0x53;
  disableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  FUN_0802bdd6(puVar2);
  do {
    uVar8 = puVar2[10];
  } while ((uVar8 & 0xffff) == (puVar2[10] & 0xffff));
  *DAT_0801da20 = *DAT_0801da20 & 0xfffffff9 | 4;
  uVar6 = *puVar2 & DAT_0801da24;
  uVar4 = DAT_0801da28 & puVar2[1];
  uVar1 = (uVar4 >> 0x14) << 4;
  enableIRQinterrupts();
  puVar2[9] = 0xff;
  *DAT_0801da18 = *DAT_0801da18 & 0xfffffeff;
  local_40 = (uVar6 & 0xf) + ((uVar6 & 0xff) >> 4) * 10;
  local_3c = (uVar6 >> 8 & 0xf) + ((uVar6 >> 8 & 0xff) >> 4) * 10;
  local_38 = (uVar6 >> 0x10 & 0xf) + (uVar6 >> 0x14) * 10;
  uVar6 = (0xff - (uVar8 & 0xffff)) * 0x80;
  local_34 = ((uVar4 << 0x10 & 0xf0000) >> 0x10) + ((uVar4 << 0x10 & 0xff0000) >> 0x14) * 10;
  local_30 = ((uVar4 & 0x1f00 | uVar1) >> 8 & 0xf) + ((uVar4 & 0x1f00 | uVar1 & 0xff00) >> 0xc) * 10
             + -1;
  local_2c = ((uVar4 & 0xfffff) >> 0x10) + ((uVar1 & 0xff) >> 4) * 10 + 100;
  uVar9 = FUN_0802be38(&local_40);
  piVar3 = DAT_0801da2c;
  uVar8 = (uint)uVar9 * 0x8000;
  iVar5 = uVar6 + uVar8;
  iVar7 = ((int)((ulonglong)uVar9 >> 0x20) << 0xf | (uint)uVar9 >> 0x11) + (uint)CARRY4(uVar6,uVar8)
  ;
  *DAT_0801da2c = iVar5;
  piVar3[1] = iVar7;
  piVar3[2] = iVar5;
  piVar3[3] = iVar7;
  piVar3[4] = iVar5;
  piVar3[5] = iVar7;
  return;
}



/* ===== FUN_0801d7dc @ 0801d7dc ===== */

void FUN_0801d7dc(void)

{
  int iVar1;
  
  iVar1 = DAT_0801da30;
  *(uint *)(DAT_0801da30 + 8) = *(uint *)(DAT_0801da30 + 8) & 0xfffffffd;
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) | 2;
  FUN_08023ec4();
  return;
}



/* ===== FUN_0801d7fa @ 0801d7fa ===== */

void FUN_0801d7fa(void)

{
  FUN_080165ce(DAT_0801da34);
  return;
}



/* ===== FUN_0801d800 @ 0801d800 ===== */

void FUN_0801d800(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar7;
  int iVar6;
  uint uVar8;
  uint uVar9;
  char local_38;
  char local_37;
  undefined1 local_36;
  char local_35;
  undefined1 auStack_34 [4];
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  uint local_28;
  int iStack_24;
  undefined4 uStack_20;
  
  iVar4 = DAT_0801da38;
  puVar3 = DAT_0801da2c;
  iVar6 = *(int *)(DAT_0801da38 + 8) << 8;
  uVar7 = iVar6 >> 8;
  disableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  uVar9 = uVar7 * 0x8000;
  uVar8 = *DAT_0801da2c + uVar9;
  uVar9 = DAT_0801da2c[1] + ((iVar6 >> 0x1f) << 0xf | uVar7 >> 0x11) +
          (uint)CARRY4(*DAT_0801da2c,uVar9);
  *DAT_0801da2c = uVar8;
  puVar3[1] = uVar9;
  uVar2 = DAT_0801da1c;
  puVar1 = DAT_0801da18;
  enableIRQinterrupts();
  if (param_2 != 0 || param_1 != 0) {
    disableIRQinterrupts();
    enableIRQinterrupts();
    iVar6 = (param_2 - puVar3[1]) - (uint)(param_1 < *puVar3);
    if (-1 < iVar6) {
      disableIRQinterrupts();
      InstructionSynchronizationBarrier(0xf);
      DataSynchronizationBarrier(0xf);
      uVar9 = param_1 - *puVar3 & DAT_0801da3c;
      uVar7 = *puVar3 + uVar9;
      uVar8 = uVar7 + 0x50000;
      uVar9 = iVar6 + puVar3[1] + (uint)CARRY4(*puVar3,uVar9) + (uint)(0xfffaffff < uVar7);
      *puVar3 = uVar8;
      puVar3[1] = uVar9;
      local_28 = uVar8 >> 0xf | uVar9 * 0x20000;
      iStack_24 = (int)uVar9 >> 0xf;
      uStack_20 = param_4;
      puVar5 = (undefined4 *)FUN_0802bf18(&local_28);
      local_30 = (undefined1)puVar5[2];
      local_2f = (undefined1)puVar5[1];
      local_2e = (undefined1)*puVar5;
      local_35 = (char)puVar5[5] + -100;
      local_37 = (char)puVar5[4] + '\x01';
      local_38 = (char)puVar5[6] + '\x01';
      local_36 = (undefined1)puVar5[3];
      *puVar1 = *puVar1 | 0x100;
      FUN_0802bc02(uVar2,0,auStack_34);
      FUN_0802bcdc(uVar2,0,&local_38);
      *puVar1 = *puVar1 & 0xfffffeff;
      enableIRQinterrupts();
      *(uint *)(iVar4 + 8) = *(uint *)(iVar4 + 8) & 0xff000000;
    }
  }
  puVar3[2] = uVar8;
  puVar3[3] = uVar9;
  puVar3[4] = uVar8;
  puVar3[5] = uVar9;
  return;
}



/* ===== FUN_0801d92c @ 0801d92c ===== */

void FUN_0801d92c(char *param_1,uint param_2)

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



/* ===== FUN_0801d96e @ 0801d96e ===== */

undefined4 FUN_0801d96e(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  puVar2 = DAT_0801da1c;
  puVar1 = DAT_0801da18;
  *DAT_0801da18 = *DAT_0801da18 | 0x100;
  puVar2[9] = 0xca;
  puVar2[9] = 0x53;
  disableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  FUN_0802bdd6(puVar2);
  uVar5 = *puVar2 & DAT_0801da24;
  FUN_0802bc02(puVar2,0,param_1);
  iVar3 = DAT_0801da38;
  enableIRQinterrupts();
  *puVar1 = *puVar1 & 0xfffffeff;
  uVar4 = *(uint *)(iVar3 + 8);
  *(uint *)(iVar3 + 8) =
       uVar4 & 0xff000000 |
       uVar4 + (((uVar5 & 0xf) + ((uVar5 & 0xff) >> 4) * 10 +
                ((uVar5 >> 8 & 0xf) + ((uVar5 >> 8 & 0xff) >> 4) * 10 +
                ((uVar5 >> 0x10 & 0xf) + (uVar5 >> 0x14) * 10) * 0x3c) * 0x3c) -
               (uint)*(byte *)(param_1 + 6)) +
               ((uint)*(byte *)(param_1 + 5) + (uint)*(byte *)(param_1 + 4) * 0x3c) * -0x3c &
       0xffffff;
  return param_4;
}



/* ===== FUN_0801da44 @ 0801da44 ===== */

void FUN_0801da44(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801da6c;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801da70;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801da74 @ 0801da74 ===== */

void FUN_0801da74(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801da9c;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801daa0;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801daa4 @ 0801daa4 ===== */

void FUN_0801daa4(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801dacc;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801dad0;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801dad4 @ 0801dad4 ===== */

void FUN_0801dad4(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_0801dafc;
  *(undefined1 *)(param_1 + 2) = param_2;
  param_1[4] = param_3;
  *(undefined1 *)((int)param_1 + 9) = 0;
  param_1[3] = 0xffffffff;
  param_1[1] = param_4;
  *(undefined1 *)((int)param_1 + 10) = 1;
  *param_1 = DAT_0801db00;
  param_1[5] = 2;
  return;
}



/* ===== FUN_0801db04 @ 0801db04 ===== */

uint FUN_0801db04(uint param_1,uint param_2,uint param_3)

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



/* ===== FUN_0801db38 @ 0801db38 ===== */

void FUN_0801db38(int param_1,int param_2,uint param_3)

{
  *(uint *)(param_1 + (uint)(byte)(&DAT_0801dbb8)[param_2]) =
       param_3 | DAT_0801dbe0 & *(uint *)(param_1 + (uint)(byte)(&DAT_0801dbb8)[param_2]);
  return;
}



/* ===== FUN_0801db50 @ 0801db50 ===== */

void FUN_0801db50(int param_1,int param_2,uint param_3)

{
  *(uint *)(param_1 + (uint)(byte)(&DAT_0801dbb8)[param_2]) =
       param_3 | *(uint *)(param_1 + (uint)(byte)(&DAT_0801dbb8)[param_2]) & 0xffffffdf;
  return;
}



/* ===== FUN_0801db60 @ 0801db60 ===== */

void FUN_0801db60(int param_1,int param_2,uint param_3)

{
  *(uint *)(param_1 + (uint)(byte)(&DAT_0801dbb8)[param_2]) =
       param_3 | *(uint *)(param_1 + (uint)(byte)(&DAT_0801dbb8)[param_2]) & 0xffffffbf;
  return;
}



/* ===== FUN_0801db78 @ 0801db78 ===== */

void FUN_0801db78(int param_1,int param_2,uint param_3)

{
  *(uint *)(param_1 + (uint)(byte)(&DAT_0801dbb8)[param_2]) =
       param_3 | *(uint *)(param_1 + (uint)(byte)(&DAT_0801dbb8)[param_2]) & 0xffffff7f;
  return;
}



/* ===== FUN_0801db88 @ 0801db88 ===== */

void FUN_0801db88(int param_1,int param_2,uint param_3)

{
  *(uint *)(param_1 + (uint)(byte)(&DAT_0801dbb8)[param_2]) =
       param_3 | *(uint *)(param_1 + (uint)(byte)(&DAT_0801dbb8)[param_2]) & 0xfffffcff;
  return;
}



/* ===== FUN_0801db98 @ 0801db98 ===== */

void FUN_0801db98(int param_1,int param_2,uint param_3)

{
  *(uint *)(param_1 + (uint)(byte)(&DAT_0801dbb8)[param_2]) =
       param_3 | *(uint *)(param_1 + (uint)(byte)(&DAT_0801dbb8)[param_2]) & 0xfffff3ff;
  return;
}



/* ===== FUN_0801dba8 @ 0801dba8 ===== */

void FUN_0801dba8(int param_1,int param_2,uint param_3)

{
  *(uint *)(param_1 + (uint)(byte)(&DAT_0801dbb8)[param_2]) =
       param_3 | *(uint *)(param_1 + (uint)(byte)(&DAT_0801dbb8)[param_2]) & 0xffffcfff;
  return;
}



/* ===== FUN_0801dbc0 @ 0801dbc0 ===== */

uint FUN_0801dbc0(uint param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_0801dbe4;
  *DAT_0801dbe4 = *DAT_0801dbe4 | param_1;
  return param_1 & *puVar1;
}



/* ===== FUN_0801dbc4 @ 0801dbc4 ===== */

uint FUN_0801dbc4(uint param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_0801dbe8;
  *DAT_0801dbe8 = *DAT_0801dbe8 | param_1;
  return param_1 & *puVar1;
}



/* ===== FUN_0801dbda @ 0801dbda ===== */

uint FUN_0801dbda(uint param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_0801dbec;
  *DAT_0801dbec = *DAT_0801dbec | param_1;
  return param_1 & *puVar1;
}



/* ===== FUN_0801dbf0 @ 0801dbf0 ===== */

void FUN_0801dbf0(uint *param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  
  bVar2 = (byte)param_2;
  bVar3 = (byte)((uint)param_2 >> 8);
  bVar4 = (byte)((uint)param_2 >> 0x10);
  bVar1 = (byte)((uint)param_2 >> 0x18);
  iVar5 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1
                                  | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) <<
                                1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18 |
                  (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1
                                  | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) <<
                                1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
                  (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1
                                  | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) <<
                                1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
                  (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1
                                  | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) <<
                                1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7)) << 1;
  *param_1 = param_3 << iVar5 | *param_1 & ~(3 << iVar5);
  return;
}



/* ===== FUN_0801dc10 @ 0801dc10 ===== */

void FUN_0801dc10(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  
  bVar2 = (byte)param_2;
  bVar3 = (byte)((uint)param_2 >> 8);
  bVar4 = (byte)((uint)param_2 >> 0x10);
  bVar1 = (byte)((uint)param_2 >> 0x18);
  iVar5 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1
                                  | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) <<
                                1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18 |
                  (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1
                                  | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) <<
                                1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
                  (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1
                                  | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) <<
                                1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
                  (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1
                                  | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) <<
                                1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7)) << 1;
  *(uint *)(param_1 + 8) = param_3 << iVar5 | *(uint *)(param_1 + 8) & ~(3 << iVar5);
  return;
}



/* ===== FUN_0801dc30 @ 0801dc30 ===== */

void FUN_0801dc30(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  
  bVar2 = (byte)param_2;
  bVar3 = (byte)((uint)param_2 >> 8);
  bVar4 = (byte)((uint)param_2 >> 0x10);
  bVar1 = (byte)((uint)param_2 >> 0x18);
  iVar5 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1
                                  | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) <<
                                1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18 |
                  (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1
                                  | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) <<
                                1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
                  (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1
                                  | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) <<
                                1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
                  (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1
                                  | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) <<
                                1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7)) << 1;
  *(uint *)(param_1 + 0xc) = param_3 << iVar5 | *(uint *)(param_1 + 0xc) & ~(3 << iVar5);
  return;
}



/* ===== FUN_0801dc50 @ 0801dc50 ===== */

void FUN_0801dc50(void)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined1 *puVar9;
  char cVar10;
  undefined2 uVar11;
  int iVar12;
  undefined4 uVar13;
  undefined1 uVar14;
  uint uVar15;
  int iVar16;
  undefined4 in_r3;
  uint uVar17;
  uint uVar18;
  uint local_a0;
  uint3 local_9c [5];
  uint local_88;
  uint local_84 [2];
  undefined3 local_7c;
  undefined2 uStack_7a;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  uint local_64 [16];
  
  local_64[0xf] = in_r3;
  FUN_0801dbda(1);
  FUN_0801dbc4(0x10000000);
  puVar2 = DAT_0801ebac;
  puVar1 = DAT_0801ddac;
  *DAT_0801ebac = *DAT_0801ebac & 0xf8ff | DAT_0801dda8;
  cVar10 = FUN_0801db04((*puVar2 & 0x7ff) >> 8,3,3);
  *(char *)((int)DAT_0801ebac + 0x17) = cVar10 << 4;
  FUN_0801f85c();
  *puVar1 = *puVar1 & 0xfffffeff;
  local_84[0] = 0;
  local_84[1] = 0;
  _local_7c = 0;
  FUN_08024bbc(local_9c,0x18);
  FUN_08024bbc(&local_78,0x18);
  FUN_0801dbc0(0x80);
  local_78 = 3;
  local_74 = 0;
  local_68 = 2;
  FUN_08024bc4(DAT_0801ddb0,&local_78);
  iVar12 = DAT_0801ddb0;
  for (local_a0 = 10; 0 < (int)local_a0; local_a0 = local_a0 - 1) {
  }
  uVar17 = *(uint *)(DAT_0801ddb0 + 0x10);
  FUN_0801dc30(DAT_0801ddb0,1,1);
  FUN_0801dc30(iVar12,2,1);
  iVar3 = DAT_0801ddb8;
  puVar2 = DAT_0801ddb4;
  for (local_a0 = 10; 0 < (int)local_a0; local_a0 = local_a0 - 1) {
  }
  uVar18 = *(uint *)(iVar12 + 0x10);
  local_74 = 3;
  local_68 = 0;
  FUN_08024bc4(iVar12,&local_78);
  puVar2[1] = puVar2[1] & 0xffffff7f;
  *(undefined1 *)(iVar3 + 0x12) = 0xff;
  uVar15 = uVar17 * 2 + (uint)((~uVar18 & 1) != 0) & 3;
  if ((uVar15 != 3) && (uVar17 = (~uVar18 & 3) >> 1 | uVar17 & 2, uVar17 != 3)) {
    iVar16 = uVar17 * 3 + uVar15;
    uVar14 = (undefined1)iVar16;
    if (iVar16 == 0) {
      FUN_0801dbc0(0x80);
      local_78 = 1;
      local_74 = 0;
      local_68 = 2;
      FUN_08024bc4(iVar12,&local_78);
      *(undefined4 *)(iVar12 + 0x18) = 2;
      local_78 = 2;
      local_74 = 1;
      local_6c = 0;
      local_68 = 0;
      FUN_08024bc4(iVar12,&local_78);
      for (local_a0 = 10; 0 < (int)local_a0; local_a0 = local_a0 - 1) {
      }
      uVar17 = *(uint *)(iVar12 + 0x10);
      FUN_0801dc30(iVar12,1,1);
      *(undefined4 *)(iVar12 + 0x28) = 2;
      for (local_a0 = 10; 0 < (int)local_a0; local_a0 = local_a0 - 1) {
      }
      uVar15 = *(uint *)(iVar12 + 0x10);
      local_78 = 3;
      local_74 = 3;
      local_68 = 0;
      FUN_08024bc4(iVar12,&local_78);
      puVar2[1] = puVar2[1] & 0xffffff7f;
      if ((uVar17 & 3) == 3 && (uVar15 & 3) == 0) {
        uVar14 = 9;
      }
      else {
        uVar14 = 0;
      }
    }
    *(undefined1 *)(iVar3 + 0x12) = uVar14;
  }
  FUN_0801dbc0(0x10);
  FUN_0801dbc0(2);
  FUN_0801dbc0(0x80);
  FUN_0801dbc0(8);
  FUN_0801dbc0(1);
  FUN_0801dbc0(4);
  iVar4 = DAT_0801ed20;
  iVar16 = DAT_0801ed1c;
  iVar3 = DAT_0801ed18;
  puVar1[1] = puVar1[1] | 0x200;
  FUN_0801dbc0(0x40);
  FUN_0801dbc0(0x20);
  *(undefined4 *)(DAT_0801ed24 + 0x28) = 100;
  iVar5 = DAT_0801ed28;
  *(undefined4 *)(DAT_0801ed28 + 0x28) = 0x6880;
  *(undefined4 *)(iVar3 + 0x28) = 0x87d5;
  *(undefined4 *)(iVar16 + 0x28) = 0x40;
  *(undefined4 *)(iVar4 + 0x28) = 0x80;
  *(undefined4 *)(iVar5 + 0x18) = 0x40;
  *(undefined4 *)(iVar3 + 0x18) = 8;
  *(undefined4 *)(iVar4 + 0x18) = 0x1000;
  local_9c[0]._0_4_ = 2;
  local_9c[1]._0_4_ = 0;
  local_9c[4]._0_4_ = 0;
  FUN_08024bc4(iVar4,local_9c);
  local_9c[0]._0_4_ = 0xb;
  local_9c[1]._0_4_ = 3;
  local_9c[4]._0_4_ = 0;
  FUN_08024bc4(iVar12,local_9c);
  puVar2[1] = puVar2[1] & 0xffffff7f;
  local_9c[0]._0_4_ = 0x60;
  local_9c[1]._0_4_ = 1;
  local_9c[2]._0_4_ = 0;
  local_9c[3]._0_4_ = 0;
  local_9c[4]._0_4_ = 0;
  FUN_08024bc4(DAT_0801ed24,local_9c);
  local_9c[0]._0_4_ = 0x43c;
  local_9c[1]._0_4_ = 3;
  local_9c[4]._0_4_ = 0;
  FUN_08024bc4(DAT_0801ed28,local_9c);
  local_9c[0]._0_4_ = 0x8006;
  local_9c[1]._0_4_ = 3;
  local_9c[4]._0_4_ = 0;
  FUN_08024bc4(&DAT_48000000,local_9c);
  local_9c[1]._0_4_ = 2;
  local_9c[3]._0_4_ = 0;
  local_9c[4]._0_4_ = 0;
  local_9c[0]._0_4_ = 0x1800;
  local_88 = 10;
  local_9c[2]._0_4_ = 3;
  FUN_08024bc4(&DAT_48000000,local_9c);
  local_9c[0]._0_4_ = 0xe04;
  local_9c[1]._0_4_ = 3;
  local_9c[4]._0_4_ = 0;
  FUN_08024bc4(iVar4,local_9c);
  *(undefined4 *)(iVar4 + 0x18) = 4;
  *(uint *)(iVar4 + 4) = *(uint *)(iVar4 + 4) & 0xfffffffb;
  FUN_0801dc10(iVar4,4,0);
  local_9c[0]._0_4_ = 0x6880;
  local_9c[1]._0_4_ = 1;
  local_9c[2]._0_4_ = 0;
  local_9c[3]._0_4_ = 0;
  local_9c[4]._0_4_ = 0;
  FUN_08024bc4(DAT_0801ed28,local_9c);
  local_9c[1]._0_4_ = 1;
  local_9c[2]._0_4_ = 2;
  local_9c[0]._0_4_ = 0x40;
  local_9c[3]._0_4_ = 0;
  local_9c[4]._0_4_ = 1;
  FUN_08024bc4(DAT_0801ed28,local_9c);
  local_9c[0]._0_4_ = 0x1f08;
  local_9c[1]._0_4_ = 3;
  local_9c[4]._0_4_ = 0;
  FUN_08024bc4(DAT_0801ed24,local_9c);
  local_9c[0]._0_4_ = 0x7800;
  local_9c[1]._0_4_ = 3;
  local_9c[4]._0_4_ = 0;
  FUN_08024bc4(iVar3,local_9c);
  local_9c[1]._0_4_ = 1;
  local_9c[0]._0_4_ = 4;
  local_9c[3]._0_4_ = 0;
  local_9c[4]._0_4_ = 0;
  local_9c[2]._0_4_ = 2;
  FUN_08024bc4(DAT_0801ed24,local_9c);
  local_9c[0]._0_4_ = 0x400;
  local_9c[1]._0_4_ = 3;
  local_9c[2]._0_4_ = 0;
  local_9c[4]._0_4_ = 0;
  FUN_08024bc4(&DAT_48000000,local_9c);
  local_9c[0]._0_4_ = 0x200;
  local_9c[1]._0_4_ = 3;
  local_9c[2]._0_4_ = 0;
  local_9c[4]._0_4_ = 0;
  FUN_08024bc4(iVar16,local_9c);
  local_9c[0]._0_4_ = 0xf83c;
  local_9c[1]._0_4_ = 3;
  local_9c[4]._0_4_ = 0;
  FUN_08024bc4(DAT_0801ef28,local_9c);
  local_9c[0]._0_4_ = 0x87d5;
  local_9c[1]._0_4_ = 1;
  local_9c[2]._0_4_ = 0;
  local_9c[3]._0_4_ = 0;
  local_9c[4]._0_4_ = 0;
  FUN_08024bc4(iVar3,local_9c);
  local_9c[0]._0_4_ = 0x200;
  local_9c[1]._0_4_ = 0;
  local_9c[4]._0_4_ = 0;
  FUN_08024bc4(&DAT_48000000,local_9c);
  local_9c[0]._0_4_ = 0x100;
  local_9c[1]._0_4_ = 2;
  local_9c[2]._0_4_ = 0;
  local_9c[3]._0_4_ = 0;
  local_9c[4]._0_4_ = 0;
  local_88 = 0;
  FUN_08024bc4(&DAT_48000000,local_9c);
  local_9c[0]._0_4_ = 8;
  local_9c[1]._0_4_ = 1;
  local_9c[3]._0_4_ = 1;
  local_9c[2]._0_4_ = 0;
  local_9c[4]._0_4_ = 0;
  FUN_08024bc4(iVar3,local_9c);
  local_9c[0]._0_4_ = 0x98;
  local_9c[1]._0_4_ = 3;
  local_9c[4]._0_4_ = 0;
  FUN_08024bc4(iVar16,local_9c);
  local_9c[0]._0_4_ = 0x40;
  local_9c[1]._0_4_ = 1;
  local_9c[2]._0_4_ = 0;
  local_9c[3]._0_4_ = 0;
  local_9c[4]._0_4_ = 0;
  FUN_08024bc4(iVar16,local_9c);
  local_9c[0]._0_4_ = 0x1000;
  local_9c[1]._0_4_ = 1;
  local_9c[2]._0_4_ = 0;
  local_9c[3]._0_4_ = 0;
  local_9c[4]._0_4_ = 0;
  FUN_08024bc4(iVar3,local_9c);
  local_9c[0]._0_4_ = 0x1000;
  local_9c[1]._0_4_ = 0;
  local_9c[4]._0_4_ = 1;
  FUN_08024bc4(DAT_0801ed28,local_9c);
  local_9c[0]._0_4_ = 0x80;
  local_9c[1]._0_4_ = 1;
  local_9c[2]._0_4_ = 0;
  local_9c[3]._0_4_ = 0;
  local_9c[4]._0_4_ = 0;
  FUN_08024bc4(iVar4,local_9c);
  puVar1 = DAT_0801ef2c;
  DAT_0801ef2c[2] = DAT_0801ef2c[2] & 0xffff0fff | 0x3000;
  puVar1[2] = puVar1[2] & 0xfffffff0 | 4;
  puVar1[4] = puVar1[4] & 0xffffff0f | 0x20;
  puVar1[2] = puVar1[2] & 0xffffff0f | 0x40;
  puVar1[1] = puVar1[1] & 0xfffffff0 | 4;
  puVar1[2] = puVar1[2] & 0xfffff0ff | 0x400;
  puVar1[3] = puVar1[3] & 0xfffffff0 | 4;
  local_84[0] = 0x80;
  local_84[1] = 0;
  local_7c = 0x10001;
  FUN_0802bf38(local_84);
  local_84[0] = 0x10;
  local_84[1] = 0;
  local_7c = 0x10001;
  FUN_0802bf38(local_84);
  local_84[0] = 0x2000;
  local_84[1] = 0;
  local_7c = 0x10001;
  FUN_0802bf38(local_84);
  local_84[0] = 0x20;
  local_84[1] = 0;
  local_7c = 0x10001;
  FUN_0802bf38(local_84);
  local_84[0] = 1;
  _local_7c = CONCAT13(uStack_7a._1_1_,0x10001);
  local_84[1] = 0;
  _local_7c = CONCAT22(uStack_7a,1);
  FUN_0802bf38(local_84);
  local_84[0] = 0x40;
  local_84[1] = 0;
  local_7c = 0x10001;
  FUN_0802bf38(local_84);
  local_84[0] = 0x100;
  local_84[1] = 0;
  _local_7c = CONCAT13(uStack_7a._1_1_,0x10001);
  FUN_0802bf38(local_84);
  FUN_0801dc30(DAT_0801ed24,0x80,0);
  FUN_0801dc30(iVar4,0x10,2);
  FUN_0801dc30(iVar16,0x2000,2);
  FUN_0801dc30(iVar4,0x20,2);
  FUN_0801dc30(iVar4,1,2);
  FUN_0801dc30(iVar4,0x40,2);
  FUN_0801dc30(iVar4,0x100,0);
  FUN_0801dbf0(DAT_0801ed24,0x80,0);
  FUN_0801dbf0(iVar4,0x10,0);
  FUN_0801dbf0(iVar16,0x2000,0);
  FUN_0801dc10(iVar16,0x2000,2);
  *(uint *)(iVar16 + 4) = *(uint *)(iVar16 + 4) & 0xffffdfff;
  *(undefined4 *)(iVar16 + 0x18) = 0x2000;
  FUN_0801dbf0(iVar4,0x20,0);
  FUN_0801dbf0(iVar4,1,0);
  FUN_0801dbf0(iVar4,0x40,0);
  FUN_0801dbf0(iVar4,0x100,0);
  cVar10 = FUN_0801db04((*DAT_0801ebac & 0x7ff) >> 8,3,0);
  *DAT_0801f130 = cVar10 << 4;
  *DAT_0801f134 = 0x40;
  cVar10 = FUN_0801db04((*DAT_0801ebac & 0x7ff) >> 8,3,2);
  DAT_0801f130[4] = cVar10 << 4;
  *DAT_0801f134 = 0x400;
  cVar10 = FUN_0801db04((*DAT_0801ebac & 0x7ff) >> 8,3,2);
  DAT_0801f130[0x11] = cVar10 << 4;
  *DAT_0801f134 = 0x800000;
  cVar10 = FUN_0801db04((*DAT_0801ebac & 0x7ff) >> 8,2,0);
  *DAT_0801f138 = cVar10 << 4;
  DAT_0801f134[1] = 0x100;
  *puVar2 = *puVar2 | 1;
  puVar1 = DAT_0801ebac;
  *puVar2 = *puVar2 | 2;
  local_a0 = *puVar2 & 2;
  cVar10 = FUN_0801db04((*puVar1 & 0x7ff) >> 8,3,3);
  DAT_0801f130[5] = cVar10 << 4;
  *DAT_0801f134 = 0x800;
  cVar10 = FUN_0801db04((*DAT_0801ebac & 0x7ff) >> 8,1,0);
  DAT_0801f130[6] = cVar10 << 4;
  *DAT_0801f134 = 0x1000;
  cVar10 = FUN_0801db04((*DAT_0801ebac & 0x7ff) >> 8,1,0);
  DAT_0801f138[8] = cVar10 << 4;
  *DAT_0801f13c = 0x10000;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  cVar10 = FUN_0801db04((*DAT_0801ebac & 0x7ff) >> 8,0,0);
  DAT_0801f138[0x10] = cVar10 << 4;
  DAT_0801f134[1] = 0x1000000;
  FUN_0801f954();
  iVar12 = DAT_0801f140;
  *(undefined4 *)(DAT_0801f140 + 0x10) = DAT_0801f144;
  local_a0 = 0;
  local_9c[0]._0_4_ = 0;
  local_9c[1]._0_4_ = 0;
  FUN_08024bbc(&stack0xffffff84,0x18);
  local_64[4] = 0;
  local_64[5] = 0;
  local_64[6] = 0;
  local_64[7] = 0;
  local_64[0] = 0;
  local_64[1] = 0;
  local_64[2] = 0;
  local_64[3] = 0;
  FUN_08024bbc(local_9c + 2,0x18);
  puVar2[0x10] = puVar2[0x10] | 0x30000000;
  FUN_0801dbc0(0x2000);
  FUN_0801dbc0(4);
  FUN_0801dbc0(2);
  local_9c[2]._0_4_ = 0x24;
  local_84[0] = 0;
  local_9c[3]._0_4_ = 3;
  FUN_08024bc4(iVar16,local_9c + 2);
  local_9c[2]._0_4_ = 1;
  local_84[0] = 0;
  local_9c[3]._0_4_ = 3;
  FUN_08024bc4(DAT_0801ed28,local_9c + 2);
  *DAT_0801f3c8 = *DAT_0801f3c8 & 0xfffffff0;
  FUN_0801db38(iVar12,0,0);
  FUN_0801dba8(iVar12,0,0);
  FUN_0801db50(iVar12,0,0x20);
  FUN_0801db60(iVar12,0,0);
  FUN_0801db78(iVar12,0,0x80);
  FUN_0801db88(iVar12,0,0x100);
  FUN_0801db98(iVar12,0,0x400);
  cVar10 = FUN_0801db04((*DAT_0801ebac & 0x7ff) >> 8,0,0);
  DAT_0801f130[0xc] = cVar10 << 4;
  *DAT_0801f134 = 0x40000;
  iVar3 = DAT_0801f3cc;
  local_a0 = 0;
  local_9c[0]._0_4_ = 0;
  local_9c[1]._0_4_ = 0;
  FUN_0802c0d6(DAT_0801f3cc,&local_a0);
  _local_7c = 0;
  local_78 = 5;
  local_74 = 0;
  local_70 = 0;
  local_68 = 0;
  local_6c = 3;
  FUN_0802c100(iVar3,&stack0xffffff84);
  *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) & DAT_0801f480;
  *(uint *)(DAT_0801f484 + 8) = *(uint *)(DAT_0801f484 + 8) & 0xfe3fffff | 0xc00000;
  local_64[4] = 0;
  local_64[5] = 0;
  FUN_0802c090(DAT_0801f484,local_64 + 4);
  local_64[2] = 0;
  local_64[3] = 0;
  FUN_0802c168(iVar3,local_64);
  *(uint *)(iVar3 + 0x4c) = *(uint *)(iVar3 + 0x4c) & 0xffffff03;
  *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) & DAT_0801f480;
  *(uint *)(iVar3 + 4) = *(uint *)(iVar3 + 4) & 0xffffffdf;
  *(uint *)(iVar3 + 4) = *(uint *)(iVar3 + 4) & 0xffffffbf;
  *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) & DAT_0801f4e8;
  *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) & DAT_0801f4ec | 0x10000000;
  *(uint *)(iVar3 + 0x30) = *(uint *)(iVar3 + 0x30) & 0xfffff83f | 0xc0;
  *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffff1ff | 0x800;
  puVar1 = DAT_0801f4f0;
  *DAT_0801f4f0 = *DAT_0801f4f0 & 0xfffffff7;
  *(uint *)(iVar3 + 0x30) = *(uint *)(iVar3 + 0x30) & 0xfffe0fff | 0x3000;
  *puVar1 = *puVar1 & 0xfffffff7;
  *(uint *)(iVar3 + 0x30) = *(uint *)(iVar3 + 0x30) & 0xff83ffff | 0x380000;
  *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) & 0xffff8fff | 0x4000;
  *puVar1 = *puVar1 & 0xffffbfff;
  *(uint *)(iVar3 + 0x30) = *(uint *)(iVar3 + 0x30) & 0xe0ffffff | 0xf000000;
  *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) & 0xfffc7fff | 0x20000;
  *puVar1 = *puVar1 & 0xffff7fff;
  *(uint *)(iVar3 + 0x34) = *(uint *)(iVar3 + 0x34) & 0xffffffe0;
  *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffffff8 | 6;
  *puVar1 = *puVar1 & 0xfffffffe;
  *(uint *)(iVar3 + 0x34) = *(uint *)(iVar3 + 0x34) & 0xfffff83f | 0x440;
  *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) & 0xff1fffff | 0xc00000;
  *puVar1 = *puVar1 & 0xfffdffff;
  uVar13 = DAT_0801f574;
  puVar2[1] = puVar2[1] & 0xffffdfff;
  *(undefined4 *)(iVar12 + 0x24) = uVar13;
  *(undefined4 *)(iVar12 + 0x28) = DAT_0801f578;
  local_a0 = 0;
  local_9c[0]._0_4_ = 0;
  local_9c[1]._0_4_ = 0;
  FUN_08024bbc(local_84,0x18);
  local_64[4] = 0;
  local_64[5] = 0;
  local_64[6] = 0;
  local_64[7] = 0;
  local_9c[2]._0_4_ = 0;
  local_9c[3]._0_4_ = 0;
  local_9c[4]._0_4_ = 0;
  local_88 = 0;
  FUN_08024bbc(&local_6c,0x18);
  puVar2[0x10] = puVar2[0x10] | 0x30000000;
  FUN_0801dbc0(0x2000);
  FUN_0801dbc0(1);
  local_6c = 1;
  local_64[2] = 0;
  local_68 = 3;
  FUN_08024bc4(&DAT_48000000,&local_6c);
  *DAT_0801f3c8 = *DAT_0801f3c8 & 0xffffff0f;
  FUN_0801db38(iVar12,1,0);
  FUN_0801dba8(iVar12,1,0);
  FUN_0801db50(iVar12,1,0x20);
  FUN_0801db60(iVar12,1,0);
  FUN_0801db78(iVar12,1,0x80);
  FUN_0801db88(iVar12,1,0x100);
  FUN_0801db98(iVar12,1,0x400);
  cVar10 = FUN_0801db04((*DAT_0801ebac & 0x7ff) >> 8,0,0);
  DAT_0801f130[0xc] = cVar10 << 4;
  *DAT_0801f134 = 0x40000;
  iVar3 = DAT_0801f65c;
  local_a0 = 0;
  local_9c[0]._0_4_ = 0;
  local_9c[1]._0_4_ = 0;
  FUN_0802c0d6(DAT_0801f65c,&local_a0);
  local_84[0] = 0x7c0;
  local_84[1] = 0;
  _local_7c = 0;
  local_78 = 0;
  local_70 = 0;
  local_74 = 3;
  FUN_0802c100(iVar3,local_84);
  *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) & DAT_0801f480;
  local_64[4] = 0;
  FUN_0802c090(DAT_0801f484,local_64 + 4);
  local_9c[3]._0_4_ = 0;
  local_9c[4]._0_4_ = 0;
  local_88 = 0;
  FUN_0802c168(iVar3,local_9c + 2);
  iVar12 = DAT_0801f484;
  *(uint *)(iVar3 + 0x4c) = *(uint *)(iVar3 + 0x4c) & 0xffffff03 | 0x50;
  *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) & DAT_0801f6cc | 0x80000000;
  *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) & DAT_0801f480;
  *(uint *)(iVar3 + 0x4c) = *(uint *)(iVar3 + 0x4c) & 0xffffff3f | 0x40;
  *(uint *)(iVar3 + 4) = *(uint *)(iVar3 + 4) & 0xffffffdf;
  *(uint *)(iVar3 + 4) = *(uint *)(iVar3 + 4) & 0xffffffbf;
  *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) & 0xfffff3ff | 0x400;
  *(uint *)(iVar12 + 8) = *(uint *)(iVar12 + 8) & 0xfe3fffff;
  *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) & DAT_0801f4e8;
  *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) & DAT_0801f4ec | 0x10000000;
  *(uint *)(iVar3 + 0x30) = *(uint *)(iVar3 + 0x30) & 0xfffff83f | 0x140;
  *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffc7fff | 0x10000;
  *DAT_0801f72c = *DAT_0801f72c & 0xffffffdf;
  uVar17 = DAT_0801f730;
  *(uint *)(iVar3 + 0x4c) = *(uint *)(iVar3 + 0x4c) & 0xffffe0ff | 0x500;
  *(uint *)(iVar3 + 0x60) = *(uint *)(iVar3 + 0x60) & DAT_0801f734 | uVar17;
  puVar2[1] = puVar2[1] & 0xffffdfff;
  FUN_08024bbc(&local_a0,0x18);
  FUN_08024bbc(&local_88,0x18);
  FUN_0801dbc4(0x20000000);
  FUN_0801dbc0(1);
  local_88 = 0x30;
  local_78 = 0;
  local_84[0] = 3;
  FUN_08024bc4(&DAT_48000000,&local_88);
  cVar10 = FUN_0801db04((*DAT_0801ebac & 0x7ff) >> 8,0,0);
  DAT_0801f138[0xe] = cVar10 << 4;
  DAT_0801f134[1] = 0x400000;
  puVar1 = DAT_0801f738;
  local_a0 = 0x38;
  local_9c[0]._0_4_ = 0;
  local_9c[2]._0_4_ = 0;
  local_9c[3]._0_4_ = 0;
  local_9c[4]._0_4_ = 0;
  FUN_0802c1ac(DAT_0801f738,DAT_0801f73c,&local_a0);
  uVar13 = DAT_0801f740;
  *puVar1 = *puVar1 & 0xfffffffb;
  FUN_0802c1ac(puVar1,uVar13,&local_a0);
  *puVar1 = *puVar1 & 0xfffbffff;
  puVar1[2] = puVar1[2] & 0xfffff000;
  puVar1[5] = puVar1[5] & 0xfffff000;
  puVar6 = DAT_0801f744;
  puVar2[4] = puVar2[4] & 0xdfffffff;
  FUN_08024bbc(&local_88,0x1c);
  FUN_08024bbc(&local_a0,0x18);
  puVar2[0x10] = puVar2[0x10] & 0xffffcfff;
  FUN_0801dbc0(2);
  local_9c[1]._0_4_ = 1;
  local_9c[2]._0_4_ = 1;
  local_a0 = 0x300;
  local_9c[3]._0_4_ = 0;
  local_9c[0]._0_4_ = 2;
  local_9c[4]._0_4_ = 4;
  FUN_08024bc4(DAT_0801ed28,&local_a0);
  FUN_0801dbc4(0x200000);
  puVar6[1] = puVar6[1] | 0x2000000;
  puVar6[3] = puVar6[3] & 0xffff7fff;
  *puVar6 = *puVar6 & 0xfff7ffff;
  local_84[0] = DAT_0801f84c;
  *puVar6 = *puVar6 & 0xfffdffff;
  local_88 = 0;
  local_84[1] = 0;
  _local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  FUN_0802c210(puVar6,&local_88);
  puVar1 = DAT_0801ef2c;
  puVar6[3] = puVar6[3] & 0xfffff801;
  puVar6 = DAT_0801f850;
  *puVar1 = *puVar1 | 0x100000;
  puVar2[4] = puVar2[4] & 0xffdfffff;
  FUN_08024bbc(&local_88,0x1c);
  FUN_08024bbc(&local_a0,0x18);
  puVar2[0x10] = puVar2[0x10] & 0xffff3fff;
  FUN_0801dbc0(0x20);
  local_9c[2]._0_4_ = 1;
  local_9c[3]._0_4_ = 1;
  local_9c[1]._0_4_ = 0;
  local_a0 = 3;
  local_9c[0]._0_4_ = 2;
  local_9c[4]._0_4_ = 4;
  FUN_08024bc4(DAT_0801ef28,&local_a0);
  FUN_0801dbc4(0x400000);
  puVar6[1] = puVar6[1] | 0x2000000;
  puVar6[3] = puVar6[3] & 0xffff7fff;
  *puVar6 = *puVar6 & 0xfff7ffff;
  local_84[0] = DAT_0801f84c;
  *puVar6 = *puVar6 & 0xfffdffff;
  local_88 = 0;
  local_84[1] = 0;
  _local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  FUN_0802c210(puVar6,&local_88);
  puVar6[3] = puVar6[3] & 0xfffff801;
  puVar1 = DAT_0801f854;
  puVar2[4] = puVar2[4] & 0xffbfffff;
  FUN_08024bbc(&local_88,0x1c);
  FUN_08024bbc(&local_a0,0x18);
  puVar2[0x10] = puVar2[0x10] & 0xfffcffff;
  FUN_0801dbc0(4);
  local_9c[2]._0_4_ = 1;
  local_9c[3]._0_4_ = 1;
  local_9c[1]._0_4_ = 0;
  local_a0 = 3;
  local_9c[0]._0_4_ = 2;
  local_9c[4]._0_4_ = 4;
  FUN_08024bc4(iVar16,&local_a0);
  FUN_0801dbc4(0x800000);
  puVar1[1] = puVar1[1] | 0x2000000;
  puVar1[3] = puVar1[3] & 0xffff7fff;
  *puVar1 = *puVar1 & 0xfff7ffff;
  local_84[0] = DAT_0801f84c;
  *puVar1 = *puVar1 & 0xfffdffff;
  local_88 = 0;
  local_84[1] = 0;
  _local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  FUN_0802c210(puVar1,&local_88);
  puVar1[3] = puVar1[3] & 0xfffff801;
  puVar1 = DAT_0801f858;
  puVar2[4] = puVar2[4] & 0xff7fffff;
  local_9c[0]._0_4_ = 0;
  local_9c[1]._0_4_ = 0;
  local_9c[2]._0_4_ = 0;
  local_9c[3]._0_4_ = 0;
  FUN_08024bbc(local_9c + 4,0x18);
  FUN_0801dbc4(0x40000000);
  puVar2[1] = puVar2[1] | 1;
  local_a0 = puVar2[1] & 1;
  local_9c[4]._0_4_ = 8;
  _local_7c = 0;
  local_88 = 3;
  FUN_08024bc4(&DAT_48000000,local_9c + 4);
  local_9c[0]._0_4_ = 0;
  local_9c[1]._0_4_ = 0xc;
  local_9c[2]._0_4_ = 0x400;
  FUN_0802c27c(puVar1,local_9c);
  *puVar1 = *puVar1 | 0x80000000;
  *puVar1 = *puVar1 & 0xffffbfff;
  puVar2[4] = puVar2[4] & 0xbfffffff;
  local_84[0] = 0;
  local_84[1] = 0;
  _local_7c = 0;
  local_78 = 0;
  FUN_08024bbc(local_9c,0x18);
  FUN_0801dbc4(0x40000000);
  puVar2[1] = puVar2[1] | 1;
  puVar2[1] = puVar2[1] | 2;
  local_a0 = puVar2[1] & 2;
  local_9c[0]._0_4_ = 0x40;
  local_9c[4]._0_4_ = 0;
  local_9c[1]._0_4_ = 3;
  FUN_08024bc4(&DAT_48000000,local_9c);
  local_9c[0]._0_4_ = 1;
  local_9c[4]._0_4_ = 0;
  local_9c[1]._0_4_ = 3;
  FUN_08024bc4(DAT_0801ed28,local_9c);
  local_84[1] = 0;
  _local_7c = 0;
  local_84[0] = 3;
  local_78 = 0x100;
  FUN_0802c27c(DAT_0801f94c,local_84);
  puVar6 = DAT_0801f94c;
  *puVar1 = *puVar1 | 0x80000000;
  puVar1 = DAT_0801f950;
  *puVar6 = *puVar6 & 0xffffbfff;
  puVar2[4] = puVar2[4] & 0xbfffffff;
  FUN_08024bbc(local_84,0x28);
  FUN_08024bbc(&local_a0,0x18);
  FUN_0801dbda(0x1000);
  puVar2[1] = puVar2[1] | 0x10;
  local_88 = puVar2[1] & 0x10;
  local_a0 = 0xa000;
  local_9c[1]._0_4_ = 0;
  local_9c[2]._0_4_ = 0;
  local_9c[0]._0_4_ = 2;
  local_9c[3]._0_4_ = 1;
  local_9c[4]._0_4_ = 5;
  FUN_08024bc4(iVar4,&local_a0);
  local_a0 = 0x4000;
  local_9c[0]._0_4_ = 2;
  local_9c[1]._0_4_ = 0;
  local_9c[2]._0_4_ = 0;
  local_9c[3]._0_4_ = 2;
  local_9c[4]._0_4_ = 5;
  FUN_08024bc4(iVar4,&local_a0);
  *puVar1 = *puVar1 & 0xffffffbf;
  local_84[1] = 0x104;
  local_84[0] = 0;
  local_70 = 0x200;
  local_78 = 0;
  local_74 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64[0] = 0;
  local_64[1] = 7;
  _local_7c = 0x700;
  FUN_0802c2b8(puVar1,local_84);
  puVar1[1] = puVar1[1] & 0xffffffef;
  puVar1[1] = puVar1[1] & 0xfffffff7;
  puVar1[1] = puVar1[1] | 0x1000;
  puVar2[6] = puVar2[6] & 0xffffefff;
  FUN_08024bbc(local_84,0x28);
  FUN_08024bbc(local_9c,0x18);
  FUN_0801dbc4(0x4000);
  iVar12 = DAT_0801fa4c;
  puVar2[1] = puVar2[1] | 8;
  local_a0 = puVar2[1] & 8;
  local_9c[0]._0_4_ = 0x13;
  local_9c[1]._0_4_ = 2;
  local_9c[2]._0_4_ = 2;
  local_9c[3]._0_4_ = 0;
  local_9c[4]._0_4_ = 2;
  local_88 = 5;
  FUN_08024bc4(DAT_0801ed24,local_9c,local_a0);
  local_84[1] = 0x104;
  local_70 = 0x40000;
  local_84[0] = 0;
  local_78 = 0;
  local_74 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64[0] = 0;
  local_64[1] = 7;
  _local_7c = 0x700;
  FUN_0802c2b8(iVar12,local_84);
  *(uint *)(iVar12 + 4) = *(uint *)(iVar12 + 4) & 0xffffffef;
  *(uint *)(iVar12 + 4) = *(uint *)(iVar12 + 4) | 8;
  puVar1 = DAT_0801fa5c;
  puVar2[4] = puVar2[4] & 0xffffbfff;
  FUN_08024bbc(local_84,0x28);
  FUN_08024bbc(&local_a0,0x18);
  FUN_0801dbc4(0x8000);
  puVar2[1] = puVar2[1] | 4;
  local_88 = puVar2[1] & 4;
  local_9c[2]._0_4_ = 0;
  local_a0 = 0x1400;
  local_9c[4]._0_4_ = 6;
  local_9c[3]._0_4_ = 1;
  local_9c[0]._0_4_ = 2;
  local_9c[1]._0_4_ = 2;
  FUN_08024bc4(iVar16,&local_a0);
  local_9c[2]._0_4_ = 0;
  local_a0 = 0x800;
  local_9c[4]._0_4_ = 6;
  local_9c[0]._0_4_ = 2;
  local_9c[1]._0_4_ = 2;
  local_9c[3]._0_4_ = 2;
  FUN_08024bc4(iVar16,&local_a0);
  local_84[1] = 0x104;
  _local_7c = 0x700;
  local_70 = 0x200;
  local_74 = 1;
  local_84[0] = 0;
  local_78 = 0;
  local_68 = 0;
  local_64[0] = 0;
  local_64[1] = 7;
  local_6c = 0x28;
  FUN_0802c2b8(puVar1,local_84);
  puVar1[1] = puVar1[1] & 0xffffffef;
  puVar1[1] = puVar1[1] & 0xfffffff7;
  puVar1[1] = puVar1[1] | 0x1000;
  *puVar1 = *puVar1 | 0x40;
  FUN_0801dc30(iVar16,0x400,0);
  FUN_0801dc30(iVar16,0x1000,0);
  FUN_08024bbc(local_64,0x14);
  FUN_08024bbc(local_84,0x20);
  FUN_08024bbc(&local_a0,0x18);
  FUN_0801dbc4(2);
  puVar1 = DAT_0801fa60;
  puVar2[1] = puVar2[1] | 0x10;
  local_88 = puVar2[1] & 0x10;
  local_a0 = 8;
  local_9c[1]._0_4_ = 0;
  local_9c[2]._0_4_ = 0;
  local_9c[3]._0_4_ = 0;
  local_9c[0]._0_4_ = 2;
  local_9c[4]._0_4_ = 2;
  FUN_08024bc4(iVar4,&local_a0);
  local_64[0] = local_64[0] & 0xffff0000;
  local_64[1] = 0;
  local_64[3] = 0;
  local_64[2] = 0xbf;
  FUN_0802c32c(puVar1,local_64);
  uVar15 = DAT_0801fa64;
  *puVar1 = *puVar1 & 0xffffff7f;
  puVar1[2] = uVar15 & puVar1[2];
  puVar1[6] = puVar1[6] | 0x800;
  local_84[0] = 0x70;
  local_84[1] = 0;
  _local_7c = 0;
  local_78 = 0xb2;
  local_74 = 0;
  FUN_0802c3e8(puVar1,0x10,local_84);
  puVar1[6] = puVar1[6] & 0xfffffbff;
  puVar1[7] = puVar1[7] | 8;
  local_78 = 0xb6;
  local_74 = 2;
  FUN_0802c3e8(puVar1,0x100,local_84);
  puVar1[7] = puVar1[7] & 0xfffffffb;
  puVar1[7] = puVar1[7] | 0x800;
  local_78 = 1;
  local_74 = 0;
  FUN_0802c3e8(puVar1,0x1000,local_84);
  puVar1[7] = puVar1[7] & 0xfffffbff;
  *puVar1 = *puVar1 | 8;
  puVar1[2] = puVar1[2] & 0xfffffff7;
  puVar1[2] = puVar1[2] & 0xffffbfff;
  puVar1[2] = puVar1[2] & 0xffff40ff;
  puVar1[2] = puVar1[2] & 0xffffff8f | 0x50;
  puVar1[2] = puVar1[2] & DAT_0801fa68 | 6;
  puVar1[6] = puVar1[6] & 0xffffff0f;
  puVar1[8] = puVar1[8] & 0xfffffff5;
  puVar1[3] = puVar1[3] & 0xffffffbf;
  puVar1[3] = puVar1[3] & 0xffffbfff;
  puVar1[1] = puVar1[1] & 0xffffff8f;
  puVar1[2] = puVar1[2] & 0xffffff7f;
  puVar1[6] = puVar1[6] & 0xfffff7ff;
  puVar1[7] = puVar1[7] & 0xfffffff7;
  puVar1[7] = puVar1[7] & 0xfffff7ff;
  puVar1[8] = puVar1[8] | 0x1110;
  puVar2[4] = puVar2[4] & 0xfffffffd;
  puVar2[1] = puVar2[1] | 4;
  puVar2[1] = puVar2[1] | 1;
  local_88 = puVar2[1] & 1;
  local_a0 = 0x100;
  local_9c[1]._0_4_ = 0;
  local_9c[2]._0_4_ = 0;
  local_9c[3]._0_4_ = 0;
  local_9c[0]._0_4_ = 2;
  local_9c[4]._0_4_ = 2;
  FUN_08024bc4(iVar16,&local_a0);
  local_a0 = 0x80;
  local_9c[1]._0_4_ = 0;
  local_9c[2]._0_4_ = 0;
  local_9c[3]._0_4_ = 0;
  local_9c[0]._0_4_ = 2;
  local_9c[4]._0_4_ = 2;
  FUN_08024bc4(&DAT_48000000,&local_a0);
  FUN_08024bbc(local_64,0x14);
  FUN_08024bbc(local_84,0x20);
  FUN_08024bbc(local_9c,0x18);
  FUN_0801dbc4(4);
  puVar1 = DAT_0801fa6c;
  local_64[0] = CONCAT22(local_64[0]._2_2_,0x2f);
  local_64[1] = 0;
  local_64[3] = 0;
  local_64[2] = 999;
  FUN_0802c32c(DAT_0801fa6c,local_64);
  *puVar1 = *puVar1 | 0x80;
  puVar1[2] = uVar15 & puVar1[2];
  puVar1[6] = puVar1[6] | 0x800;
  local_84[0] = 0x70;
  local_84[1] = 0;
  _local_7c = 0;
  local_78 = 0;
  local_74 = 2;
  FUN_0802c3e8(puVar1,0x10,local_84);
  puVar1[6] = puVar1[6] & 0xfffffbff;
  puVar1[7] = puVar1[7] | 8;
  FUN_0802c3e8(puVar1,0x100,local_84);
  puVar1[7] = puVar1[7] & 0xfffffffb;
  puVar1[7] = puVar1[7] | 0x800;
  FUN_0802c3e8(puVar1,0x1000,local_84);
  puVar1[7] = puVar1[7] & 0xfffffbff;
  puVar1[2] = puVar1[2] & 0xfffffff7;
  puVar1[2] = puVar1[2] & 0xffffbfff;
  puVar1[2] = puVar1[2] & 0xffff40ff;
  puVar1[1] = puVar1[1] & 0xffffff8f;
  puVar1[2] = puVar1[2] & 0xffffff7f;
  puVar1[6] = puVar1[6] & 0xfffff7ff;
  puVar1[7] = puVar1[7] & 0xfffffff7;
  puVar1[7] = puVar1[7] & 0xfffff7ff;
  *puVar1 = *puVar1 | 1;
  puVar1[8] = puVar1[8] | 0x1110;
  puVar1 = DAT_0801fa70;
  puVar2[1] = puVar2[1] | 8;
  local_a0 = puVar2[1] & 8;
  local_9c[0]._0_4_ = 0xe000;
  local_9c[2]._0_4_ = 0;
  local_9c[3]._0_4_ = 0;
  local_9c[1]._0_4_ = 2;
  local_9c[4]._0_4_ = 2;
  local_88 = 2;
  FUN_08024bc4(DAT_0801fa74,local_9c);
  *(undefined4 *)(DAT_0801fa78 + 0x10) = DAT_0801fa7c;
  FUN_08024bbc(local_84,0x14);
  FUN_08024bbc(local_64 + 7,0x20);
  FUN_08024bbc(&local_70,0x28);
  FUN_08024bbc(local_9c,0x18);
  FUN_0801dbda(0x10000);
  local_84[0] = local_84[0] & 0xffff0000;
  local_84[1] = 0;
  local_78 = 0;
  local_74 = 0;
  _local_7c = 0xff;
  FUN_0802c32c(puVar1,local_84);
  *puVar1 = *puVar1 | 0x80;
  puVar1[2] = uVar15 & puVar1[2];
  puVar1[6] = puVar1[6] | 0x800;
  local_64[7] = 0x70;
  local_64[8] = 0;
  local_64[9] = 0;
  local_64[10] = 0;
  local_64[0xc] = 0;
  local_64[0xd] = 0;
  local_64[0xe] = 0;
  local_64[0xb] = 2;
  FUN_0802c3e8(puVar1,0x10,local_64 + 7);
  puVar1[6] = puVar1[6] & 0xfffffbff;
  puVar1[1] = puVar1[1] & 0xffffff8f | 0x20;
  puVar1[2] = puVar1[2] & 0xffffff7f;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64[0] = (local_64[0] >> 8 & 0xff) << 8;
  local_64[1] = 0x2000;
  local_64[6] = 0;
  FUN_0802c6c8(puVar1,&local_70);
  *puVar1 = *puVar1 | 1;
  puVar1[8] = puVar1[8] | 0x10;
  puVar1[0xe] = 0;
  puVar1[0x11] = puVar1[0x11] & 0xffff7fff;
  puVar2[1] = puVar2[1] | 2;
  local_a0 = puVar2[1] & 2;
  local_9c[0]._0_4_ = 0x8000;
  local_88 = 0xe;
  local_9c[2]._0_4_ = 0;
  local_9c[3]._0_4_ = 0;
  local_9c[1]._0_4_ = 2;
  local_9c[4]._0_4_ = 2;
  FUN_08024bc4(DAT_0801fa80,local_9c);
  FUN_08024bbc(&local_a0,0x14);
  FUN_0801dbc4(1);
  local_a0 = CONCAT22(local_a0._2_2_,0x2f);
  local_9c[0]._0_4_ = 0;
  local_9c[1]._0_4_ = 0xffffffff;
  local_9c[2]._0_4_ = 0;
  FUN_0802c32c(0x40000000,&local_a0);
  uVar17 = DAT_40000000;
  DAT_40000000 = uVar17 | 0x80;
  uVar17 = DAT_40000008;
  DAT_40000008 = uVar15 & uVar17;
  uVar17 = DAT_40000004;
  DAT_40000004 = uVar17 & 0xffffff8f | 0x20;
  uVar17 = DAT_40000008;
  DAT_40000008 = uVar17 & 0xffffff7f;
  uVar17 = DAT_40000000;
  DAT_40000000 = uVar17 | 1;
  puVar2[0x10] = puVar2[0x10] | 0xc0000;
  FUN_0801dbc4(0x80000000);
  cVar10 = FUN_0801db04((*DAT_0801fa84 & 0x7ff) >> 8,0,3);
  *(char *)(DAT_0801fa88 + 0x19) = cVar10 << 4;
  DAT_0801fa8c[2] = 2;
  piVar8 = DAT_0801fa90;
  DAT_0801fa90[3] = DAT_0801fa90[3] & 0xfffffffe;
  piVar8[3] = piVar8[3] & 0xfffff1ff;
  piVar8[3] = piVar8[3] & 0xffdfffff;
  piVar8[3] = piVar8[3] & 0xffbfffff;
  piVar8[3] = piVar8[3] & 0xff7fffff;
  piVar8[3] = piVar8[3] & 0xfff9ffff;
  piVar8[8] = piVar8[8] & 0xfffffffc;
  piVar8[8] = piVar8[8] & 0xfffffffc;
  piVar8[1] = piVar8[1] | 2;
  piVar8[2] = piVar8[2] | 2;
  piVar8[4] = piVar8[4] | 1;
  do {
  } while (-1 < piVar8[4] << 0x1f);
  piVar8[6] = piVar8[6] & 0xffff0000U | 0x1f;
  do {
  } while (-1 < *piVar8 << 0x1b);
  piVar8[4] = piVar8[4] & 0xfffffff9U | 4;
  FUN_08024bbc(local_9c,0x18);
  puVar2[0x10] = puVar2[0x10] & 0xffcfffff;
  puVar2[5] = puVar2[5] | 0x20;
  puVar2[1] = puVar2[1] | 2;
  local_a0 = puVar2[1] & 2;
  local_88 = 0xe;
  local_9c[2]._0_4_ = 0;
  local_9c[3]._0_4_ = 0;
  local_9c[4]._0_4_ = 0;
  local_9c[0]._0_4_ = 2;
  local_9c[1]._0_4_ = 2;
  FUN_08024bc4(DAT_0801fa80,local_9c);
  cVar10 = FUN_0801db04((*DAT_0801fa84 & 0x7ff) >> 8,1,0);
  *(char *)(DAT_0801fa88 + 0x1a) = cVar10 << 4;
  DAT_0801fa8c[2] = 4;
  iVar12 = DAT_0801fa94;
  *(uint *)(DAT_0801fa94 + 0xc) = *(uint *)(DAT_0801fa94 + 0xc) | 1;
  *(uint *)(iVar12 + 0xc) = *(uint *)(iVar12 + 0xc) & 0xfffff1ff;
  *(uint *)(iVar12 + 0xc) = *(uint *)(iVar12 + 0xc) & 0xffdfffff;
  *(uint *)(iVar12 + 0xc) = *(uint *)(iVar12 + 0xc) & 0xffbfffff;
  *(uint *)(iVar12 + 0xc) = *(uint *)(iVar12 + 0xc) | 0x800000;
  *(uint *)(iVar12 + 0xc) = *(uint *)(iVar12 + 0xc) & 0xffffffe1;
  *(uint *)(iVar12 + 0xc) = *(uint *)(iVar12 + 0xc) & 0xfff9ffff;
  *(uint *)(iVar12 + 0x20) = *(uint *)(iVar12 + 0x20) & 0xfffffffc;
  *(uint *)(iVar12 + 0x10) = *(uint *)(iVar12 + 0x10) | 1;
  *(uint *)(iVar12 + 0x18) = *(uint *)(iVar12 + 0x18) | 0xffff;
  FUN_08023ec4();
  puVar2[5] = puVar2[5] & 0xffffffdf;
  puVar7 = DAT_0801fa98;
  *DAT_0801fa98 = 0xcccc;
  *puVar7 = 0x5555;
  puVar7[1] = 3;
  puVar7[2] = 0xfff;
  do {
  } while ((puVar7[3] & 7) != 0);
  *puVar7 = 0xaaaa;
  *puVar2 = *puVar2 | 0x1000;
  puVar1 = DAT_0801fa9c;
  local_a0 = *puVar2 & 0x1000;
  *DAT_0801fa9c = *DAT_0801fa9c & 0xffffff9f;
  uVar17 = DAT_0801faa0;
  *puVar1 = *puVar1 & 0xffffff7f;
  puVar1[3] = uVar17;
  *puVar1 = *puVar1 & 0xffffffe7;
  puVar1[2] = 0xffffffff;
  FUN_08024bbc(&local_a0,0x14);
  FUN_0801dbc4(8);
  iVar3 = DAT_0801fa88;
  cVar10 = FUN_0801db04((*DAT_0801fa84 & 0x7ff) >> 8,0,0);
  *(char *)(iVar3 + 10) = cVar10 << 4;
  puVar7 = DAT_0801fa8c;
  DAT_0801fa8c[1] = 0x40000;
  puVar1 = DAT_0801faa4;
  uVar17 = DAT_0801fa64;
  local_a0 = local_a0 & 0xffff0000;
  local_9c[0]._0_4_ = 0;
  local_9c[1]._0_4_ = 0;
  local_9c[2]._0_4_ = 0;
  FUN_0802c32c(DAT_0801faa4,&local_a0);
  *puVar1 = *puVar1 & 0xffffff7f;
  *puVar1 = *puVar1 | 8;
  puVar1[2] = puVar1[2] & 0xffffff8f | 0x30;
  puVar1[2] = uVar17 & puVar1[2] | 7;
  puVar1[3] = puVar1[3] & 0xffffffbf;
  puVar1[3] = puVar1[3] & 0xffffbfff;
  puVar1[1] = puVar1[1] & 0xffffff8f | 0x20;
  puVar1[2] = puVar1[2] & 0xffffff7f;
  *puVar1 = *puVar1 & 0xfffffffb;
  puVar1[4] = 0xfffffffe;
  puVar1[3] = puVar1[3] | 1;
  FUN_08024bbc(&local_a0,0x14);
  FUN_0801dbda(0x2000);
  iVar12 = DAT_0801fa78;
  *DAT_0801faa8 = *DAT_0801faa8 & 0xfffffff0 | 7;
  FUN_0801db38(iVar12,0,0x10);
  FUN_0801dba8(iVar12,0,0x3000);
  FUN_0801db50(iVar12,0,0x20);
  FUN_0801db60(iVar12,0,0);
  FUN_0801db78(iVar12,0,0x80);
  FUN_0801db88(iVar12,0,0x100);
  FUN_0801db98(iVar12,0,0);
  puVar1 = DAT_0801faac;
  local_a0 = local_a0 & 0xffff0000;
  local_9c[0]._0_4_ = 0;
  local_9c[2]._0_4_ = 0;
  local_9c[3]._0_4_ = 0;
  local_9c[1]._0_4_ = 2999;
  FUN_0802c32c(DAT_0801faac,&local_a0);
  *puVar1 = *puVar1 | 0x80;
  puVar1[2] = uVar17 & puVar1[2];
  puVar1[1] = puVar1[1] & 0xffffff8f | 0x20;
  puVar1[1] = puVar1[1] & 0xff0fffff | 0x200000;
  puVar1[2] = puVar1[2] & 0xffffff7f;
  FUN_08024bbc(&local_a0,0x14);
  FUN_0801dbc4(0x10);
  cVar10 = FUN_0801db04((*DAT_0801fa84 & 0x7ff) >> 8,0,0);
  *(char *)(iVar3 + 0xe) = cVar10 << 4;
  puVar7[1] = 0x400000;
  puVar1 = DAT_0801fab0;
  local_a0 = CONCAT22(local_a0._2_2_,0x2f);
  local_9c[0]._0_4_ = 0;
  local_9c[1]._0_4_ = 10000;
  FUN_0802c32c(DAT_0801fab0,&local_a0);
  *puVar1 = *puVar1 & 0xffffff7f;
  puVar1[1] = puVar1[1] & 0xffffff8f | 0x20;
  puVar1[2] = puVar1[2] & 0xffffff7f;
  *puVar1 = *puVar1 | 8;
  puVar1[4] = 0xfffffffe;
  puVar1[3] = puVar1[3] | 1;
  FUN_0801f954();
  *(uint *)(DAT_0801fab4 + 4) = *(uint *)(DAT_0801fab4 + 4) & 0xffff0fff | 0x4000;
  local_9c[0]._0_4_ = 0;
  local_a0 = 8;
  local_9c[1]._0_4_ = 0x10101;
  FUN_0802bf38(&local_a0);
  cVar10 = FUN_0801db04((*DAT_0801fa84 & 0x7ff) >> 8,0,1);
  *(char *)(DAT_0801fab8 + 3) = cVar10 << 4;
  *puVar7 = 0x200;
  puVar7 = DAT_0801fabc;
  puVar2[8] = puVar2[8] & 0xfffffeff;
  puVar2[9] = puVar2[9] & DAT_0801fac0;
  FUN_080175f4();
  *puVar7 = 0;
  puVar9 = DAT_0801fac4;
  iVar12 = FUN_08027878(DAT_0801fac4);
  if (iVar12 == 0xd) {
    puVar7[1] = 0xd;
    iVar12 = DAT_0801facc;
    FUN_080262d4(&local_a0,DAT_0801fac8,6);
    local_9c[0] = (uint3)(ushort)local_9c[0];
    uVar13 = thunk_FUN_0802a738(&local_a0);
    puVar7[2] = uVar13;
    FUN_080262d4(&local_a0,iVar12,3);
    local_a0 = local_a0 & 0xffffff;
    uVar11 = thunk_FUN_0802a738(&local_a0);
    *(undefined2 *)(puVar7 + 4) = uVar11;
    *(bool *)((int)puVar7 + 0xf) = *(char *)(iVar12 + 3) != '-';
    *(undefined1 *)(puVar7 + 3) = *puVar9;
    *(undefined1 *)((int)puVar7 + 0xd) = puVar9[1];
    *(undefined1 *)((int)puVar7 + 0xe) = 0;
    *puVar7 = puVar9;
  }
  FUN_0801d6c4();
  do {
  } while (*DAT_0801fad0 - (*DAT_0801fad0 + 0x666) < 1);
  FUN_08027096();
  FUN_0801ce7c();
  FUN_08026b18();
  FUN_0801d800();
  FUN_080248c8();
  FUN_0801669c();
  FUN_080241ae();
  FUN_08022942();
  FUN_080247a8();
  FUN_0801b328();
  thunk_FUN_080242f2();
  FUN_080245bc();
  FUN_0801760c();
  thunk_FUN_08028238();
  FUN_08014640();
  FUN_080209c4();
  FUN_080160ec();
  puVar7 = DAT_0801fa98;
  FUN_08017ee8("Start Main loop");
  do {
    do {
      *puVar7 = 0xaaaa;
      FUN_08024210();
      FUN_08016650();
      FUN_080177ec();
      FUN_08023fd8();
      FUN_0801912e();
      FUN_08023d14();
      FUN_080166f6();
      FUN_0802298c();
      FUN_080156a2();
      FUN_0801684c();
      FUN_080209ea();
      iVar12 = FUN_080166e4();
    } while (iVar12 != 0);
    *puVar7 = 0xaaaa;
    FUN_080176f8();
  } while( true );
}



/* ===== FUN_0801f85c @ 0801f85c ===== */

void FUN_0801f85c(void)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_0801fad4;
  *DAT_0801fad4 = *DAT_0801fad4 & 0xfffffff8 | 2;
  puVar2 = DAT_0801fad8;
  do {
  } while ((*puVar1 & 7) != 2);
  *DAT_0801fad8 = *DAT_0801fad8 & 0xfffff9ff | 0x200;
  puVar1 = DAT_0801fadc;
  do {
  } while ((int)((puVar2[5] >> 10) << 0x1f) < 0);
  *DAT_0801fadc = *DAT_0801fadc | 0x100;
  do {
  } while (-1 < (int)(*puVar1 << 0x15));
  puVar1[1] = puVar1[1] & 0x80ffffff | 0x40000000;
  puVar2 = DAT_0801fae0;
  DAT_0801fae0[1] = DAT_0801fae0[1] | 1;
  puVar1 = DAT_0801fadc;
  do {
  } while (-1 < (int)(puVar2[1] << 0x1e));
  *DAT_0801fadc = *DAT_0801fadc | 1;
  do {
  } while (-1 < (int)(*puVar1 << 0x1e));
  *puVar1 = *puVar1 | 8;
  *puVar1 = *puVar1 & 0xffffff0f | 0xb0;
  puVar1[1] = puVar1[1] & 0xffff00ff;
  *DAT_0801fad8 = *DAT_0801fad8 | 0x100;
  puVar2 = DAT_0801fae0;
  *DAT_0801fae0 = *DAT_0801fae0 & 0xffffffe7 | 8;
  *puVar2 = *puVar2 | 1;
  puVar1 = DAT_0801fadc;
  do {
  } while (-1 < (int)(*puVar2 << 0x1e));
  *DAT_0801fadc = *DAT_0801fadc | 4;
  puVar1[2] = puVar1[2] & 0xfffffffc;
  uVar3 = DAT_0801fae4;
  do {
  } while ((puVar1[2] & 0xc) != 0);
  puVar1[2] = puVar1[2] & 0xffffff0f;
  puVar1[2] = puVar1[2] & 0xfffff8ff | 0x400;
  puVar1[2] = puVar1[2] & 0xffffc7ff | 0x2000;
  FUN_0802c75c(uVar3);
  FUN_0802c79a(uVar3);
  puVar1[2] = puVar1[2] & 0x80ffffff | 0x1000000;
  return;
}



/* ===== FUN_0801f954 @ 0801f954 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0801f954(void)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  bool bVar4;
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar2 = DAT_0801fae8;
  if (-1 < *(int *)(DAT_0801fae8 + 0xc) << 0x1b) {
    FUN_0801d6bc();
    puVar3 = _DAT_0801faec;
    puVar1 = DAT_0801fad8;
    *DAT_0801fad8 = *DAT_0801fad8 | 0x100;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    if ((puVar3[0xe] & 0x300) != 0x100) {
      bVar4 = -1 < (int)(*puVar3 << 3);
      if (bVar4) {
        FUN_0801dbc4(0x10000000);
      }
      if (-1 < (int)(*puVar1 << 0x17)) {
        *puVar1 = *puVar1 | 0x100;
        do {
        } while (-1 < (int)(*puVar1 << 0x17));
      }
      puVar3[0xe] = puVar3[0xe] | 0x10000;
      puVar3[0xe] = puVar3[0xe] & 0xfffeffff;
      puVar3[0xe] = puVar3[0xe] & 0xffffffe7 | 8;
      puVar3[0xe] = puVar3[0xe] | 1;
      do {
      } while (-1 < (int)(puVar3[0xe] << 0x1e));
      puVar3[0xe] = puVar3[0xe] & 0xfffffcff | 0x100;
      if (bVar4) {
        *puVar3 = *puVar3 & 0xefffffff;
      }
    }
    puVar3[0xe] = puVar3[0xe] | 0x8000;
    local_1c = 0;
    local_14 = 0xff;
    local_18 = 0x7f;
    FUN_0802bbb4(iVar2,&local_1c);
    local_20 = local_20 & 0xff000000;
    FUN_0802bc02(iVar2,1,&local_24);
    local_28 = 0x20010103;
    FUN_0802bcdc(iVar2,1,&local_28);
    *puVar1 = *puVar1 & 0xfffffeff;
  }
  return;
}



/* ===== FUN_0801fb00 @ 0801fb00 ===== */

undefined4 * FUN_0801fb00(undefined4 *param_1)

{
  FUN_08026250();
  *param_1 = DAT_0801fb10;
  return param_1;
}



/* ===== FUN_0801fb14 @ 0801fb14 ===== */

undefined4 FUN_0801fb14(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 extraout_r3;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (*(char *)(param_1 + 0x14) < 1) {
    return param_4;
  }
  iVar3 = *(char *)(param_1 + 0x14) + -1;
  piVar8 = *(int **)(DAT_0801fcb0 + iVar3 * 4);
  if ((param_2 & 0x7000) == 0x1000) {
    param_2 = param_2 & 0x8fff;
    (**(code **)(*piVar8 + 0x18))(piVar8,param_2);
    iVar3 = DAT_0801fcb4;
    if (param_2 == 2) {
      FUN_08016844();
      iVar3 = DAT_0801fcb4;
      piVar8 = DAT_080168e4;
      if (1 < *(char *)(DAT_0801fcb4 + 0x14)) {
        piVar2 = DAT_080168e4 + *(char *)(DAT_0801fcb4 + 0x14);
        while (piVar2 = piVar2 + -1, piVar8 < piVar2) {
          piVar7 = (int *)*piVar2;
          (**(code **)(*piVar7 + 0xc))(piVar7,1);
          FUN_0802160c(piVar7);
          if (piVar7 != (int *)0x0) {
            (**(code **)(*piVar7 + 4))(piVar7);
          }
          *piVar2 = 0;
        }
        *(undefined1 *)(iVar3 + 0x14) = 1;
        iVar4 = *piVar8;
        FUN_0801566a(*(undefined1 *)(iVar4 + 4));
        *(undefined1 *)(iVar4 + 0x14) = 1;
        (**(code **)(*(int *)*piVar8 + 8))((int *)*piVar8,1);
        *(undefined1 *)(iVar3 + 0x17) = *(undefined1 *)(iVar3 + 0x16);
      }
      return extraout_r3;
    }
    if (param_2 != 6) {
      return param_4;
    }
    FUN_08017ac4(DAT_0801fcb4,0);
    iVar4 = FUN_080179f8(0x1c);
    uVar5 = 0;
    if (iVar4 != 0) {
      uVar5 = FUN_0802c7ac(iVar4,1);
    }
    uVar5 = FUN_08017b2c(iVar3,uVar5,param_4);
    return uVar5;
  }
  if ((param_2 & 0x7000) != 0x2000) {
    return param_4;
  }
  uVar9 = 0;
  if ((0 < iVar3) && (*(char *)(param_1 + 0x18) == '\0')) {
    FUN_080165ac(param_1,0xf0000);
  }
  switch(param_2 & 7) {
  case 0:
    uVar9 = 0x20;
    break;
  case 1:
    *(undefined1 *)(param_1 + 0x16) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    uVar9 = 0x10;
    *(undefined1 *)(param_1 + 0x1b) = *(undefined1 *)(param_1 + 0x1a);
    break;
  case 2:
    uVar9 = 0x40;
    *(undefined1 *)(param_1 + 0x16) = 1;
    break;
  case 3:
    uVar9 = 0x30;
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  }
  pcVar1 = DAT_0801fcb8;
  if (*(char *)(param_1 + 0x17) == '\0') {
    *(undefined1 *)(param_1 + 0x17) = *(undefined1 *)(param_1 + 0x16);
    return param_4;
  }
  uVar9 = uVar9 | *(uint *)(param_1 + 0x10);
  *(uint *)(param_1 + 0x10) = uVar9;
  if (*pcVar1 == '\0') {
    if ((param_2 & 0x30) == 0) {
      param_2 = param_2 & 0xffffffcf | 0x10;
    }
    else if ((param_2 & 0x30) == 0x10) {
      param_2 = param_2 & 0xffffffcf;
    }
  }
  if (*(char *)(param_1 + 0x1b) == '\0') {
    uVar6 = param_2 & 0x30;
    if (uVar6 == 0) {
      if (*(char *)(param_1 + 0x18) == '\0') {
        if ((param_2 & 7) == 1) {
          *(uint *)(param_1 + 0x10) = uVar9 | 4;
        }
        (**(code **)(*piVar8 + 0x14))(piVar8,param_2);
        goto LAB_0801fc92;
      }
    }
    else {
      if (uVar6 != 0x10) {
        if (uVar6 == 0x20) {
          if ((param_2 & 7) == 1) {
            *(undefined1 *)(param_1 + 0x19) = *(undefined1 *)(param_1 + 0x18);
            if (*(char *)(param_1 + 0x18) == '\0') {
              uVar6 = 4;
            }
            else {
              uVar6 = 8;
            }
            *(uint *)(param_1 + 0x10) = uVar9 | uVar6;
          }
          (**(code **)(*piVar8 + 0x1c))(piVar8,param_2);
        }
        goto LAB_0801fc92;
      }
      if (*(char *)(param_1 + 0x18) == '\0') {
        if ((param_2 & 7) == 1) {
          *(uint *)(param_1 + 0x10) = uVar9 | 4;
        }
        (**(code **)(*piVar8 + 0x10))(piVar8,param_2);
        goto LAB_0801fc92;
      }
    }
    uVar9 = uVar9 | 0x80;
  }
  else {
    if ((param_2 & 0x37) != 0x21) goto LAB_0801fc92;
    *(undefined1 *)(param_1 + 0x17) = 0;
    uVar9 = uVar9 | 0x104;
  }
  *(uint *)(param_1 + 0x10) = uVar9;
LAB_0801fc92:
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



/* ===== FUN_0801fefe @ 0801fefe ===== */

undefined8
FUN_0801fefe(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  *param_1 = 0;
  FUN_0802003c(param_1,0,0,0,param_4);
  uVar1 = 0;
  FUN_08020384(param_1,0,0,0);
  return CONCAT44(uVar1,param_1);
}



/* ===== FUN_0801ff48 @ 0801ff48 ===== */

undefined4 FUN_0801ff48(undefined1 *param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  byte bVar4;
  int iVar5;
  
  puVar2 = DAT_0801ffcc;
  piVar1 = DAT_0801ffc8;
  iVar5 = *DAT_0801ffc8;
  uVar3 = *(undefined4 *)(iVar5 + 0xc);
  if (param_1 == (undefined1 *)0x0) {
    *(undefined1 **)(iVar5 + 0xc) = DAT_0801ffcc;
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
    bVar4 = *(byte *)(iVar5 + 3);
    if (*(byte *)(iVar5 + 5) < *(byte *)(iVar5 + 3)) {
      bVar4 = *(byte *)(iVar5 + 5);
    }
    *(byte *)(iVar5 + 5) = bVar4;
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



/* ===== FUN_0801ffae @ 0801ffae ===== */

undefined1 FUN_0801ffae(int param_1)

{
  if (param_1 == 0) {
    param_1 = DAT_0801ffcc;
  }
  return *(undefined1 *)(param_1 + 1);
}



/* ===== FUN_0801ffb6 @ 0801ffb6 ===== */

undefined2 FUN_0801ffb6(int param_1)

{
  if (param_1 == 0) {
    param_1 = DAT_0801ffcc;
  }
  return *(undefined2 *)(param_1 + 2);
}



/* ===== FUN_0801ffbe @ 0801ffbe ===== */

undefined2 FUN_0801ffbe(int param_1)

{
  if (param_1 == 0) {
    param_1 = DAT_0801ffcc;
  }
  return *(undefined2 *)(param_1 + 8);
}



/* ===== FUN_0801ffd0 @ 0801ffd0 ===== */

undefined1 FUN_0801ffd0(uint param_1)

{
  int iVar1;
  int unaff_r5;
  undefined1 uVar2;
  bool bVar3;
  
  iVar1 = *DAT_08020034;
  uVar2 = iVar1 != DAT_08020038;
  if ((bool)uVar2) {
    unaff_r5 = DAT_08020038 + 0x14;
  }
  if ((bool)uVar2 && iVar1 != unaff_r5) {
    uVar2 = 2;
    bVar3 = iVar1 != DAT_08020038 + 0x28;
    if (bVar3) {
      uVar2 = 3;
      unaff_r5 = DAT_08020038 + 0x3c;
    }
    if (bVar3 && iVar1 != unaff_r5) {
      uVar2 = 4;
      bVar3 = iVar1 != DAT_08020038 + 0x50;
      if (bVar3) {
        uVar2 = 5;
        unaff_r5 = DAT_08020038 + 100;
      }
      if ((bVar3 && iVar1 != unaff_r5) && (uVar2 = 6, iVar1 != DAT_08020038 + 0x78)) {
        uVar2 = 0;
      }
    }
  }
  if (6 < param_1) {
    param_1 = 6;
  }
  *DAT_08020034 = DAT_08020038 + param_1 * 0x14;
  return uVar2;
}



/* ===== FUN_0802003c @ 0802003c ===== */

void FUN_0802003c(undefined4 *param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4)

{
  param_1[3] = param_2;
  *(undefined1 *)(param_1 + 1) = param_3;
  *(undefined1 *)((int)param_1 + 5) = param_4;
  param_1[2] = *param_1;
  return;
}



/* ===== FUN_08020048 @ 08020048 ===== */

void FUN_08020048(undefined1 *param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[3] = *param_1;
  return;
}



/* ===== FUN_08020054 @ 08020054 ===== */

void FUN_08020054(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 auStack_18 [12];
  undefined4 uStack_c;
  
  uStack_c = param_4;
  FUN_0801d92c(auStack_18);
  FUN_08018b1c(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
  FUN_080190ec(auStack_18);
  return;
}



/* ===== FUN_0802008c @ 0802008c ===== */

void FUN_0802008c(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

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
  
  local_44 = *DAT_080200d8;
  uStack_40 = DAT_080200d8[1];
  uStack_3c = DAT_080200d8[2];
  uStack_38 = DAT_080200d8[3];
  uStack_34 = DAT_080200d8[4];
  uStack_30 = DAT_080200d8[5];
  uStack_2c = DAT_080200d8[6];
  uStack_28 = DAT_080200d8[7];
  uVar1 = param_2 >> 0x18;
  uStack_24 = param_4;
  if (uVar1 == 0x43 || uVar1 == 0x46) {
    local_48 = (short)param_2;
    FUN_0802c818(&local_44,8,DAT_080200dc,(int)local_48,param_2 >> 0x10 & 0xff,uVar1);
  }
  FUN_08018b1c(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
  FUN_080190f8(&local_44);
  return;
}



/* ===== FUN_080200e0 @ 080200e0 ===== */

void FUN_080200e0(undefined4 *param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4)

{
  *(undefined1 *)(param_1 + 2) = param_3;
  *(undefined1 *)((int)param_1 + 9) = param_4;
  param_1[6] = param_2;
  param_1[4] = *param_1;
  param_1[5] = param_1[1];
  return;
}



/* ===== FUN_080200f0 @ 080200f0 ===== */

void FUN_080200f0(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 auStack_20 [12];
  
  uVar1 = DAT_08020158;
  FUN_08018b1c(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
  uVar2 = (uint)((ulonglong)param_2 * (ulonglong)DAT_0802015c >> 0x25);
  uVar5 = (uint)((ulonglong)uVar2 * (ulonglong)DAT_0802015c >> 0x25);
  uVar1 = (uint)((ulonglong)uVar5 * (ulonglong)uVar1 >> 0x24);
  uVar3 = uVar2 + uVar5 * -0x3c & 0xff;
  uVar5 = uVar5 + uVar1 * -0x18 & 0xff;
  if (uVar1 == 0) {
    uVar4 = DAT_08020160;
    uVar1 = uVar5;
    uVar5 = uVar3;
    uVar3 = param_2 + uVar2 * -0x3c & 0xff;
  }
  else {
    uVar4 = DAT_08020164;
  }
  FUN_080168e8(auStack_20,0xc,uVar4,uVar1,uVar5,uVar3);
  FUN_080190ec(auStack_20);
  return;
}



/* ===== FUN_08020168 @ 08020168 ===== */

void FUN_08020168(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 0x18);
  if (puVar1 != (undefined4 *)0x0) {
    uVar2 = *puVar1;
    uVar3 = puVar1[1];
    FUN_0802c854(param_1,param_2,uVar2,uVar3);
    *(undefined4 *)(param_1 + 0x10) = uVar2;
    *(undefined4 *)(param_1 + 0x14) = uVar3;
  }
  return;
}



/* ===== FUN_08020184 @ 08020184 ===== */

undefined4 FUN_08020184(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*(char **)(param_1 + 4) != (char *)0x0) {
    cVar1 = **(char **)(param_1 + 4);
    if (1 < *(ushort *)(DAT_080201b0 + 8)) {
      uVar2 = FUN_0802c8ac(~-(uint)(cVar1 == '\0') >> 0x1f);
      FUN_0802c8c8(*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2),uVar2);
    }
    *(char *)(param_1 + 3) = cVar1;
  }
  return param_4;
}



/* ===== FUN_080201b4 @ 080201b4 ===== */

undefined4 FUN_080201b4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  undefined4 uVar2;
  
  if (*(byte **)(param_1 + 4) != (byte *)0x0) {
    bVar1 = **(byte **)(param_1 + 4);
    if ((ushort)bVar1 < *(ushort *)(DAT_080201dc + 8)) {
      uVar2 = FUN_0802c8ac();
      FUN_0802c8c8(*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2),uVar2);
    }
    *(byte *)(param_1 + 3) = bVar1;
  }
  return param_4;
}



/* ===== FUN_080201e0 @ 080201e0 ===== */

undefined4 FUN_080201e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*(char **)(param_1 + 4) != (char *)0x0) {
    cVar1 = **(char **)(param_1 + 4);
    if (1 < *(ushort *)(DAT_0802020c + 8)) {
      uVar2 = FUN_0802c8ac(~-(uint)(cVar1 == '\0') >> 0x1f);
      FUN_0802c8c8(*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2),uVar2);
    }
    *(char *)(param_1 + 3) = cVar1;
  }
  return param_4;
}



/* ===== FUN_08020210 @ 08020210 ===== */

undefined4 FUN_08020210(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  
  if (*(char **)(param_1 + 4) != (char *)0x0) {
    cVar1 = **(char **)(param_1 + 4);
    FUN_0802c924(param_1,(int)cVar1);
    *(char *)(param_1 + 3) = cVar1;
  }
  return param_4;
}



/* ===== FUN_08020254 @ 08020254 ===== */

void FUN_08020254(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = *(int **)(param_1 + 0x18);
  if (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    iVar3 = piVar1[1];
    if (iVar3 != *(int *)(param_1 + 0x14) || iVar2 != *(int *)(param_1 + 0x10)) {
      FUN_0802c854(param_1,*(int *)(param_1 + 0x14),iVar2,iVar3);
      *(int *)(param_1 + 0x10) = iVar2;
      *(int *)(param_1 + 0x14) = iVar3;
    }
  }
  return;
}



/* ===== FUN_0802027c @ 0802027c ===== */

undefined4 FUN_0802027c(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

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
    if (1 < *(ushort *)(DAT_080202b0 + 8)) {
      uVar2 = FUN_0802c8ac(~-(uint)(unaff_r5 == 0) >> 0x1f);
      FUN_0802c8c8(*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2),uVar2);
    }
    *(char *)(param_1 + 3) = (char)unaff_r5;
  }
  return param_4;
}



/* ===== FUN_080202b4 @ 080202b4 ===== */

undefined4 FUN_080202b4(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

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
    if (uVar3 < *(ushort *)(DAT_080202e4 + 8)) {
      uVar2 = FUN_0802c8ac();
      FUN_0802c8c8(*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2),uVar2);
    }
    *(byte *)(param_1 + 3) = unaff_r5;
  }
  return param_4;
}



/* ===== FUN_080202e8 @ 080202e8 ===== */

undefined4 FUN_080202e8(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

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
    if (1 < *(ushort *)(DAT_0802031c + 8)) {
      uVar2 = FUN_0802c8ac(~-(uint)(unaff_r5 == 0) >> 0x1f);
      FUN_0802c8c8(*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2),uVar2);
    }
    *(char *)(param_1 + 3) = (char)unaff_r5;
  }
  return param_4;
}



/* ===== FUN_08020320 @ 08020320 ===== */

undefined4 FUN_08020320(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  int unaff_r5;
  
  pcVar1 = *(char **)(param_1 + 4);
  if (pcVar1 != (char *)0x0) {
    unaff_r5 = (int)*pcVar1;
    param_2 = (int)*(char *)(param_1 + 3);
  }
  if (pcVar1 != (char *)0x0 && unaff_r5 != param_2) {
    FUN_0802c924(param_1,unaff_r5);
    *(char *)(param_1 + 3) = (char)unaff_r5;
  }
  return param_4;
}



/* ===== FUN_08020384 @ 08020384 ===== */

void FUN_08020384(undefined4 *param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4,
                 undefined1 param_5)

{
  param_1[3] = param_2;
  *(undefined1 *)(param_1 + 1) = param_3;
  *(undefined1 *)((int)param_1 + 5) = param_4;
  param_1[2] = *param_1;
  *(undefined1 *)(param_1 + 4) = param_5;
  return;
}



/* ===== FUN_0802039c @ 0802039c ===== */

void FUN_0802039c(int param_1,uint param_2)

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
  
  uVar2 = (uint)((ulonglong)param_2 * (ulonglong)DAT_08020434 >> 0x28) + 1 >> 1;
  if (uVar2 == 0) {
    local_24 = *DAT_08020438;
  }
  else if (uVar2 < 10) {
    local_24 = uVar2 + 0x30;
  }
  else {
    local_24 = 0x30;
  }
  FUN_08019ab0(auStack_20,*(undefined4 *)(*(int *)(DAT_0802043c + 0x74) + 0x70));
  uVar3 = FUN_08018b64(0x2184);
  FUN_0802c994(&local_26,&local_27,&local_25,&local_28);
  cVar1 = *(char *)(param_1 + 4) + local_26;
  FUN_0802b9fc(cVar1,local_27,*(char *)(param_1 + 0x10) + cVar1,local_28);
  FUN_08018b1c(0,*(undefined1 *)(param_1 + 5));
  FUN_080190f8(&local_24);
  FUN_0802b9fc(local_26,local_27,local_25,local_28);
  FUN_08018b64(uVar3);
  return;
}



/* ===== FUN_08020440 @ 08020440 ===== */

undefined4 FUN_08020440(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(undefined4 **)(param_1 + 0xc) != (undefined4 *)0x0) {
    uVar1 = **(undefined4 **)(param_1 + 0xc);
    FUN_0802c9c8(param_1,uVar1);
    *(undefined4 *)(param_1 + 8) = uVar1;
  }
  return param_4;
}



/* ===== FUN_08020456 @ 08020456 ===== */

undefined8 FUN_08020456(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  uVar2 = FUN_08018b64(0x2184);
  FUN_0802c994(&local_16,&local_17,&local_15,&local_18);
  cVar1 = *(char *)(param_1 + 4) + local_16;
  FUN_0802b9fc(cVar1,local_17,*(char *)(param_1 + 0x10) + cVar1,local_18);
  FUN_08018b1c(0,*(undefined1 *)(param_1 + 5));
  FUN_080190f8(param_2);
  FUN_0802b9fc(local_16,local_17,local_15,local_18);
  FUN_08018b64(uVar2);
  return CONCAT44(uStack_14,CONCAT13(local_15,CONCAT12(local_16,CONCAT11(local_17,local_18))));
}



/* ===== FUN_080204be @ 080204be ===== */

undefined4 FUN_080204be(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
    FUN_0802c9c8(param_1,unaff_r5);
    *(int *)(param_1 + 8) = unaff_r5;
  }
  return param_4;
}



/* ===== FUN_080204dc @ 080204dc ===== */

undefined4 FUN_080204dc(void)

{
  int *piVar1;
  char cVar2;
  undefined1 *puVar3;
  int iVar4;
  byte bVar5;
  undefined4 uVar6;
  
  piVar1 = DAT_0802054c;
  *DAT_08020548 = 0;
  puVar3 = (undefined1 *)*piVar1;
  if ((int)((uint)(byte)puVar3[0x10] << 0x1f) < 0) {
    uVar6 = 0xffff;
  }
  else {
    uVar6 = 0;
  }
  FUN_080274b0(*puVar3,puVar3[1],puVar3[2],puVar3[3]);
  FUN_0802b7ec();
  ((undefined1 *)*piVar1)[4] = *(undefined1 *)*piVar1;
  cVar2 = FUN_0801ffae(*(undefined4 *)(*piVar1 + 0xc));
  *(char *)(*piVar1 + 5) = cVar2 + *(char *)(*piVar1 + 1) + -1;
  if (0x7f < *(byte *)(*piVar1 + 4)) {
    *(undefined1 *)(*piVar1 + 4) = 0x7f;
  }
  iVar4 = *piVar1;
  bVar5 = *(byte *)(iVar4 + 3);
  if (*(byte *)(iVar4 + 5) < *(byte *)(iVar4 + 3)) {
    bVar5 = *(byte *)(iVar4 + 5);
  }
  *(byte *)(iVar4 + 5) = bVar5;
  ((undefined1 *)*piVar1)[6] = *(undefined1 *)*piVar1;
  *(undefined1 *)(*piVar1 + 7) = *(undefined1 *)(*piVar1 + 1);
  return uVar6;
}



/* ===== FUN_08020550 @ 08020550 ===== */

void FUN_08020550(char param_1,char param_2)

{
  int *piVar1;
  
  piVar1 = DAT_080206b8;
  ((char *)*DAT_080206b8)[6] = *(char *)*DAT_080206b8 + param_1;
  *(char *)(*piVar1 + 7) = *(char *)(*piVar1 + 1) + param_2;
  return;
}



/* ===== FUN_0802056a @ 0802056a ===== */

void FUN_0802056a(char param_1,char param_2,undefined4 param_3,uint param_4)

{
  uint *puVar1;
  undefined1 *puVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  uint uVar9;
  char *pcVar10;
  byte *pbVar11;
  uint local_18;
  
  puVar1 = DAT_080206b8;
  pcVar10 = (char *)*DAT_080206b8;
  bVar8 = pcVar10[6];
  uVar9 = (uint)(byte)pcVar10[7];
  bVar3 = *pcVar10 + param_1;
  bVar4 = pcVar10[1] + param_2;
  pcVar10[6] = bVar3;
  puVar2 = DAT_080206bc;
  uVar6 = *puVar1;
  *(byte *)(uVar6 + 7) = bVar4;
  *puVar2 = 0;
  if (bVar8 != bVar3) {
    uVar6 = (uint)bVar4;
  }
  if (bVar8 != bVar3 && uVar9 != uVar6) {
    FUN_080205f4(bVar8,uVar9);
    local_18 = param_4;
  }
  else {
    pbVar11 = (byte *)*puVar1;
    if (bVar8 < *pbVar11) {
      bVar8 = *pbVar11;
    }
    bVar5 = pbVar11[2];
    if (bVar3 < pbVar11[2]) {
      bVar5 = bVar3;
    }
    uVar6 = (uint)pbVar11[1];
    if (pbVar11[1] < uVar9) {
      uVar6 = uVar9;
    }
    uVar9 = (uint)pbVar11[3];
    if ((uint)bVar4 < (uint)pbVar11[3]) {
      uVar9 = (uint)bVar4;
    }
    bVar3 = bVar8;
    if (bVar5 < bVar8) {
      bVar3 = bVar5;
      bVar5 = bVar8;
    }
    uVar7 = uVar9;
    if (uVar9 < uVar6) {
      uVar7 = uVar6;
      uVar6 = uVar9;
    }
    local_18 = pbVar11[0x10] & 1 ^ 1;
    FUN_0802cc5e(bVar3,uVar6,bVar5,uVar7);
  }
  FUN_0802b7ec(local_18);
  return;
}



/* ===== FUN_080205f4 @ 080205f4 ===== */

void FUN_080205f4(ushort param_1,uint param_2,short param_3,int param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  ushort uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  short sVar14;
  short sVar15;
  int iVar16;
  int iVar17;
  bool bVar18;
  
  iVar10 = (int)(short)(param_3 - param_1);
  param_4 = param_4 - param_2;
  if (iVar10 < 0) {
    iVar10 = (int)(short)-(param_3 - param_1);
    sVar4 = -1;
  }
  else {
    sVar4 = 1;
  }
  if ((short)param_4 < 0) {
    param_4 = -(int)(short)param_4;
    iVar7 = -1;
  }
  else {
    iVar7 = 1;
  }
  if (iVar10 < (short)param_4) {
    iVar11 = (int)(short)param_4;
    param_4 = iVar10;
    iVar17 = iVar7;
    sVar15 = 0;
  }
  else {
    iVar17 = 0;
    iVar11 = iVar10;
    sVar15 = sVar4;
  }
  iVar10 = (param_4 << 0x10) >> 0xf;
  iVar13 = (int)(short)((short)iVar10 - (short)iVar11);
  iVar16 = iVar13 - iVar11;
  for (sVar14 = 0; sVar14 <= iVar11; sVar14 = sVar14 + 1) {
    pbVar8 = (byte *)*DAT_080206b8;
    uVar5 = (ushort)*pbVar8;
    uVar9 = param_1 & 0xff;
    bVar18 = uVar5 <= uVar9;
    if (bVar18) {
      uVar9 = (ushort)pbVar8[2];
      uVar5 = param_1 & 0xff;
    }
    if (bVar18 && uVar5 <= uVar9) {
      uVar6 = (uint)pbVar8[1];
      uVar12 = param_2 & 0xff;
      bVar18 = uVar6 <= uVar12;
      if (bVar18) {
        uVar12 = (uint)pbVar8[3];
        uVar6 = param_2 & 0xff;
      }
      if (bVar18 && uVar6 <= uVar12) {
        FUN_0802ccdc(param_1 & 0xff,param_2 & 0xff,pbVar8[0x10] & 1 ^ 1);
      }
    }
    iVar2 = iVar10;
    iVar3 = iVar17;
    sVar1 = sVar15;
    if (-1 < (short)iVar13) {
      iVar2 = iVar16;
      iVar3 = iVar7;
      sVar1 = sVar4;
    }
    param_2 = param_2 + iVar3;
    iVar13 = iVar2 + iVar13;
    param_1 = param_1 + sVar1;
  }
  return;
}



/* ===== FUN_080206c0 @ 080206c0 ===== */

undefined4 FUN_080206c0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(byte **)(param_1 + 0xc) != (byte *)0x0) {
    uVar1 = *(undefined4 *)(*(int *)(DAT_080206e4 + 0x74) + (uint)**(byte **)(param_1 + 0xc) * 4);
    FUN_08018b1c(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
    FUN_080190f8(uVar1);
    *(undefined4 *)(param_1 + 8) = uVar1;
  }
  return param_4;
}



/* ===== FUN_080206e8 @ 080206e8 ===== */

void FUN_080206e8(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined1 uVar1;
  char cVar2;
  undefined1 *puVar3;
  undefined1 local_18;
  undefined1 local_17 [2];
  undefined1 local_15;
  undefined4 local_14;
  undefined4 uStack_10;
  
  if ((param_3 & 0xff) != 0) {
    _local_18 = CONCAT31((int3)((uint)param_2 >> 8),(char)param_3);
    puVar3 = local_17;
    local_14 = param_3;
    if ((local_17 < (undefined1 *)((int)&local_14 + 3U)) &&
       (cVar2 = (char)(param_3 >> 8), cVar2 != '\0')) {
      local_15 = (undefined1)((uint)param_2 >> 0x18);
      _local_18 = CONCAT22(CONCAT11(local_15,cVar2),CONCAT11(0xa0,(char)param_3));
      puVar3 = &local_15;
      cVar2 = (char)(param_3 >> 0x10);
      if (cVar2 != '\0') {
        local_14 = CONCAT31((int3)(param_3 >> 8),cVar2);
        _local_18 = CONCAT13(0xa0,_local_18);
        puVar3 = (undefined1 *)((int)&local_14 + 1);
        if (param_3 >> 0x18 != 0) {
          uVar1 = (undefined1)(param_3 >> 0x18);
          local_14 = CONCAT13(uVar1,CONCAT12(uVar1,CONCAT11(0xa0,cVar2)));
          puVar3 = (undefined1 *)((int)&local_14 + 3);
        }
      }
    }
    uStack_10 = param_4;
    *puVar3 = 0;
    FUN_08018b1c(*(undefined1 *)(param_1 + 8),*(undefined1 *)(param_1 + 9));
    FUN_080190ec(&local_18);
  }
  return;
}



/* ===== FUN_0802075c @ 0802075c ===== */

undefined4 FUN_0802075c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (*(byte **)(param_1 + 0xc) != (byte *)0x0) {
    iVar1 = *(int *)(*(int *)(DAT_08020788 + 0x74) + (uint)**(byte **)(param_1 + 0xc) * 4);
    if (iVar1 != *(int *)(param_1 + 8)) {
      FUN_08018b1c(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
      FUN_080190f8(iVar1);
      *(int *)(param_1 + 8) = iVar1;
    }
  }
  return param_4;
}



/* ===== FUN_0802078c @ 0802078c ===== */

void FUN_0802078c(int *param_1,int *param_2)

{
  if (param_2 != (int *)0x0) {
    if (param_1[1] == 0) {
      param_1[1] = (int)param_2;
      *param_1 = (int)param_2;
      param_2[1] = 0;
    }
    else {
      param_2[1] = param_1[1];
      *(int **)(param_1[1] + 8) = param_2;
      param_1[1] = (int)param_2;
    }
    param_2[2] = 0;
    (**(code **)(*param_2 + 8))(param_2);
    *(undefined1 *)(param_1 + 2) = 1;
  }
  return;
}



/* ===== FUN_080207ec @ 080207ec ===== */

ulonglong FUN_080207ec(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = -(param_1 >> 0x17);
  uVar4 = iVar1 + 0x9e;
  uVar2 = param_1 << 8 | 0x80000000;
  if (uVar4 != 0 && param_1 >> 0x17 < 0x9f) {
    return (ulonglong)(uVar2 >> (uVar4 & 0xff));
  }
  uVar4 = iVar1 + 0xbe;
  if ((int)uVar4 < 0) {
    return CONCAT44(~((int)param_1 >> 0x1f),~((int)param_1 >> 0x1f));
  }
  uVar3 = uVar2 >> (uVar4 & 0xff);
  return CONCAT44(uVar3,(uVar2 >> (uVar4 & 0x1f) | uVar2 << 0x20 - (uVar4 & 0x1f)) ^ uVar3);
}



/* ===== FUN_080209c4 @ 080209c4 ===== */

void FUN_080209c4(void)

{
  undefined1 *puVar1;
  
  puVar1 = DAT_08020ec0;
  *DAT_08020ec0 = 0;
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



/* ===== FUN_080209ea @ 080209ea ===== */

void FUN_080209ea(void)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = DAT_08020ec0;
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



/* ===== FUN_08020a8a @ 08020a8a ===== */

undefined4 FUN_08020a8a(int param_1,int param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  
  puVar5 = DAT_08020ed0;
  puVar2 = DAT_08020ec0;
  if (param_1 != 0) {
    DAT_08020ed0[3] = DAT_08020ed0[3] & 0xfffffffe;
    *puVar2 = 1;
    iVar3 = DAT_08020ec8;
    uVar1 = (undefined1)param_1;
    if (puVar2[1] == '\0') {
      *DAT_08020ec4 = 1;
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
      puVar4 = DAT_08020ecc;
      DAT_08020ecc[0xb] = 2999;
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
    if (*(char *)(DAT_08020ec8 + (uint)(byte)puVar2[1] * 8) == '\x03') {
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
      puVar4 = DAT_08020ecc;
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



/* ===== FUN_08020bd0 @ 08020bd0 ===== */

void FUN_08020bd0(uint param_1)

{
  bool bVar1;
  int iVar2;
  uint *puVar3;
  bool bVar4;
  
  iVar2 = DAT_08020ec0;
  bVar1 = false;
  if (param_1 == 0) {
    bVar4 = true;
    bVar1 = true;
  }
  else {
    bVar4 = param_1 == *(byte *)(DAT_08020ec0 + 1);
    if (param_1 == *(byte *)(DAT_08020ec0 + 2)) {
      bVar1 = true;
    }
  }
  if (((*(char *)(DAT_08020ec0 + 2) == '\0') || (0x11 < *(byte *)(DAT_08020ec0 + 2))) || (bVar1)) {
    *(undefined1 *)(DAT_08020ec0 + 2) = 0;
    *(undefined4 *)(iVar2 + 0x10) = 0;
    *(undefined4 *)(iVar2 + 0x28) = 0;
    if (bVar4) {
      *DAT_08020ed4 = *DAT_08020ed4 & 0xffff7fff;
      puVar3 = DAT_08020ecc;
      *DAT_08020ecc = *DAT_08020ecc & 0xfffffffe;
      puVar3[3] = puVar3[3] & 0xfffffeff;
      DataSynchronizationBarrier(0xf);
      DataMemoryBarrier(0x1f);
      *DAT_08020ed8 = *DAT_08020ed8 & 0xfffffffe;
      DataSynchronizationBarrier(0xf);
      DataMemoryBarrier(0x1f);
      *(undefined1 *)(iVar2 + 1) = 0;
      *(undefined4 *)(iVar2 + 0xc) = 0;
      *(undefined4 *)(iVar2 + 0x24) = 0;
      *(undefined4 *)(iVar2 + 0x2c) = 0;
      *DAT_08020ec4 = 0;
      return;
    }
  }
  else if (bVar4) {
    *(undefined1 *)(DAT_08020ec0 + 1) = *(undefined1 *)(DAT_08020ec0 + 2);
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar2 + 0x10);
    *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar2 + 0x28);
    *(undefined1 *)(iVar2 + 2) = 0;
    *(undefined4 *)(iVar2 + 0x10) = 0;
    *(undefined4 *)(iVar2 + 0x28) = 0;
    *(undefined4 *)(iVar2 + 0x2c) =
         *(undefined4 *)(DAT_08020ec8 + (uint)*(byte *)(iVar2 + 2) * 8 + 4);
  }
  return;
}



/* ===== FUN_08020c80 @ 08020c80 ===== */

undefined4 FUN_08020c80(uint param_1)

{
  uint uVar1;
  bool bVar2;
  
  bVar2 = param_1 != *(byte *)(DAT_08020ec0 + 1);
  uVar1 = DAT_08020ec0;
  if (bVar2) {
    uVar1 = (uint)*(byte *)(DAT_08020ec0 + 2);
  }
  if (bVar2 && param_1 != uVar1) {
    return 0;
  }
  return 1;
}



/* ===== FUN_08020c96 @ 08020c96 ===== */

undefined4 FUN_08020c96(void)

{
  return *(undefined4 *)(DAT_08020ec0 + 0xc);
}



/* ===== FUN_08020ca0 @ 08020ca0 ===== */

undefined8 FUN_08020ca0(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  undefined *puVar8;
  int *piVar9;
  int iVar10;
  uint local_20;
  uint local_1c;
  
  puVar6 = DAT_08020edc;
  puVar3 = DAT_08020ecc;
  DAT_08020edc[0x11] = DAT_08020edc[0x11] & 0xffff7fff;
  *puVar3 = *puVar3 & 0xfffffffe;
  puVar3[3] = puVar3[3] & 0xfffffeff;
  puVar5 = DAT_08020ed8;
  DataSynchronizationBarrier(0xf);
  DataMemoryBarrier(0x1f);
  *DAT_08020ed8 = *DAT_08020ed8 & 0xfffffffe;
  iVar1 = DAT_08020ec0;
  DataSynchronizationBarrier(0xf);
  DataMemoryBarrier(0x1f);
  iVar10 = *(int *)(DAT_08020ec0 + 0x2c);
  local_20 = param_3;
  local_1c = param_4;
  if (iVar10 == 0) {
    *(undefined1 *)(DAT_08020ec0 + 1) = 0;
    puVar2 = DAT_08020ec4;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *puVar2 = 0;
    if (*(int *)(iVar1 + 4) == 0) {
      *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(iVar1 + 0x24);
    }
    else {
      *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 0x24);
    }
    *(undefined4 *)(iVar1 + 0x24) = 0;
  }
  else {
    puVar8 = (undefined *)0x0;
    if (*(char *)(DAT_08020ec0 + 1) != '\0') {
      local_1c = (((uint)((*(int *)(iVar10 + 4) + 1) * 1000) / *(uint *)(DAT_08020ec0 + 0x38)) *
                 1000) / *(uint *)(DAT_08020ec0 + 0x3c) - 1;
      local_20 = ((DAT_08020ee0 / *(uint *)(DAT_08020ec0 + 0x30)) * 1000) /
                 *(uint *)(DAT_08020ec0 + 0x34);
      if (local_20 < 0xff) {
        local_20 = 0xff;
      }
      iVar7 = (**(code **)(iVar10 + 0x1c))(iVar10,&local_20,&local_1c);
      puVar3[0xb] = local_1c;
      puVar4 = DAT_08020ed0;
      *DAT_08020ed0 = *DAT_08020ed0 & 0xfffffffe;
      puVar4[9] = 0;
      puVar4[0xb] = *(uint *)(iVar10 + 8);
      *puVar6 = *puVar6 & 0xfffffffe;
      puVar6[0xb] = local_20;
      if (iVar7 != 0) {
        puVar5[1] = *(uint *)(iVar10 + 0xc) | puVar5[1] & 0xffff0000;
        *puVar5 = *puVar5 | 1;
        puVar3[3] = puVar3[3] | 0x100;
        puVar6[0x11] = puVar6[0x11] | 0x8000;
      }
      *puVar3 = *puVar3 | 1;
      piVar9 = *(int **)(iVar10 + 0x14);
      if (piVar9 == (int *)0x0) {
        puVar8 = *(undefined **)(iVar10 + 0x10);
        if (puVar8 == &UNK_08020ef8) {
          puVar8 = (undefined *)(*(int *)(iVar1 + 0x2c) + 0x20);
        }
        else if (((puVar8 == (undefined *)0x0) && (*(char *)(iVar1 + 2) != '\0')) &&
                (*(byte *)(iVar1 + 2) < 0x12)) {
          *(undefined1 *)(iVar1 + 1) = *(undefined1 *)(iVar1 + 2);
          iVar10 = DAT_08020ee4;
          *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar1 + 0x10);
          *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar1 + 0x28);
          puVar8 = *(undefined **)(iVar10 + (uint)*(byte *)(iVar1 + 2) * 8);
          *(undefined1 *)(iVar1 + 2) = 0;
          *(undefined4 *)(iVar1 + 0x10) = 0;
          *(undefined4 *)(iVar1 + 0x28) = 0;
        }
      }
      else {
        if (*piVar9 == 0) {
          iVar7 = *(int *)(iVar10 + 0x18);
        }
        else {
          iVar7 = *piVar9 + -1;
        }
        *piVar9 = iVar7;
        if (iVar7 == 0) {
          *(undefined4 *)(iVar1 + 0x3c) = *(undefined4 *)(iVar1 + 0x38);
          puVar8 = (undefined *)(*(int *)(iVar1 + 0x2c) + 0x20);
          *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(iVar1 + 0x30);
        }
        else {
          puVar8 = *(undefined **)(iVar10 + 0x10);
        }
      }
    }
    *(undefined **)(iVar1 + 0x2c) = puVar8;
  }
  puVar3 = DAT_08020ed0;
  DAT_08020ed0[4] = 0xfffffffe;
  *puVar3 = *puVar3 | 1;
  *puVar6 = *puVar6 | 1;
  return CONCAT44(local_1c,local_20);
}



/* ===== FUN_08020e24 @ 08020e24 ===== */

undefined4 FUN_08020e24(undefined4 *param_1)

{
  FUN_080262f4(DAT_08020ee8 + 0x300,DAT_08020ee8,0x300);
  *DAT_08020eec = *param_1;
  DataSynchronizationBarrier(0xf);
  DataMemoryBarrier(0x1f);
  return 1;
}



/* ===== FUN_08020ef4 @ 08020ef4 ===== */

undefined4 FUN_08020ef4(void)

{
  return 0;
}



/* ===== FUN_08020f1e @ 08020f1e ===== */

void FUN_08020f1e(void)

{
  *DAT_08020ff0 = 0x4000;
  return;
}



/* ===== FUN_08020f22 @ 08020f22 ===== */

void FUN_08020f22(void)

{
  *DAT_08020ff4 = 0x4000;
  return;
}



/* ===== FUN_08020f2c @ 08020f2c ===== */

void FUN_08020f2c(void)

{
  int iVar1;
  
  iVar1 = DAT_08020fec;
  *DAT_08020ff4 = 0x4000;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  return;
}



/* ===== FUN_08020f58 @ 08020f58 ===== */

longlong FUN_08020f58(int param_1,int param_2)

{
  uint unaff_r7;
  
  if (*(int *)(param_1 + 0x18) < param_2) {
    *(int *)(param_1 + 0x18) = param_2;
    FUN_08016644(param_1,&UNK_08020ffc,2,0);
    return CONCAT44(unaff_r7,1);
  }
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08020f70 @ 08020f70 ===== */

longlong FUN_08020f70(int param_1,int param_2)

{
  uint unaff_r7;
  
  if (*(int *)(param_1 + 0x18) < param_2) {
    *(int *)(param_1 + 0x18) = param_2;
    FUN_08016644(param_1,&DAT_0802100c,2,0);
    return CONCAT44(unaff_r7,1);
  }
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08020f90 @ 08020f90 ===== */

longlong FUN_08020f90(int param_1,int param_2)

{
  uint unaff_r7;
  
  if (*(int *)(param_1 + 0x18) < param_2) {
    *(int *)(param_1 + 0x18) = param_2;
    FUN_08016644(param_1,&UNK_0802101c,4,0x4000);
    return CONCAT44(unaff_r7,1);
  }
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08020fa8 @ 08020fa8 ===== */

undefined4 FUN_08020fa8(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  if (param_3 == 1) {
    puVar2 = &LAB_0802103c;
    uVar1 = 4;
  }
  else {
    if (1 < param_3 - 2U) {
      return 0;
    }
    uVar1 = 6;
    puVar2 = DAT_08020ff8;
  }
  *(undefined4 *)(param_1 + 0x1c) = param_4;
  *(undefined4 *)(param_1 + 0x18) = param_2;
  FUN_08016644(param_1,puVar2,uVar1,0);
  return 1;
}



/* ===== FUN_08020fd6 @ 08020fd6 ===== */

undefined4 FUN_08020fd6(void)

{
  int iVar1;
  undefined4 unaff_r7;
  
  FUN_080165ce();
  iVar1 = DAT_08020fec;
  *DAT_08020ff4 = 0x4000;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  return unaff_r7;
}



/* ===== FUN_08021070 @ 08021070 ===== */

void FUN_08021070(int param_1)

{
  char cVar1;
  char *pcVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  
  if (*(char *)(param_1 + 0xc) != '\0') {
    return;
  }
  pcVar2 = (char *)FUN_080157c2();
  cVar3 = '\0';
  if (pcVar2[1] == ' ') {
    cVar1 = pcVar2[2];
    cVar3 = '\x02';
    bVar4 = cVar1 == ' ';
    if (bVar4) {
      cVar3 = '\x04';
      cVar1 = pcVar2[3];
    }
    bVar5 = bVar4 && cVar1 == ' ';
    if (bVar4 && cVar1 == ' ') {
      cVar3 = '\x06';
      bVar5 = pcVar2[4] == ' ';
    }
    if (bVar5) {
      return;
    }
  }
  *pcVar2 = cVar3 + '\x01';
  FUN_080165ac(param_1,0x4000);
  return;
}



/* ===== FUN_080210b0 @ 080210b0 ===== */

void FUN_080210b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_1 + 0xd) = 0;
  FUN_0801469a();
  FUN_08017df0(8);
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined1 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 0x15) = 0;
  *(undefined1 *)(param_1 + 0x16) = 0;
  *(undefined1 *)(param_1 + 0x17) = 0;
  uVar1 = DAT_080214e0;
  FUN_080164dc(DAT_080214e0);
  *(undefined1 *)(param_1 + 0x19) = 0;
  *(undefined1 *)(param_1 + 0x1a) = 0;
  *(undefined1 *)(param_1 + 0x1b) = 0;
  *(undefined1 *)(param_1 + 0x1c) = 0;
  FUN_080164dc(uVar1,1);
  *(undefined1 *)(param_1 + 0x1e) = 0;
  *(undefined1 *)(param_1 + 0x1f) = 0;
  *(undefined1 *)(param_1 + 0x20) = 0;
  *(undefined1 *)(param_1 + 0x21) = 0;
  FUN_080164dc(uVar1,2);
  *(undefined1 *)(param_1 + 0x23) = 0;
  *(undefined1 *)(param_1 + 0x24) = 0;
  *(undefined1 *)(param_1 + 0x25) = 0;
  *(undefined1 *)(param_1 + 0x26) = 0;
  FUN_080164dc(uVar1,3,param_4);
  return;
}



/* ===== FUN_08021118 @ 08021118 ===== */

undefined4 FUN_08021118(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  switch(param_2) {
  case 0:
    uVar2 = 0x300;
    iVar1 = param_3 << 8;
    break;
  case 1:
    uVar2 = 3;
    iVar1 = param_3;
    break;
  case 2:
    uVar2 = 0x18;
    iVar1 = param_3 << 3;
    break;
  case 3:
    uVar2 = 0xc0;
    if (param_3 == 0) {
      iVar1 = 0x40;
    }
    else if (param_3 == 2) {
      iVar1 = 0x80;
    }
    else if (param_3 == 3) {
      iVar1 = 0xc0;
    }
    else {
      iVar1 = 0;
    }
    break;
  default:
    goto switchD_08021124_default;
  }
  iVar3 = param_2 * 5 + param_1;
  if (-1 < param_3) {
    FUN_08017d9a(uVar2,iVar1);
    iVar1 = (int)*(char *)(iVar3 + 0x14);
    if (param_3 != iVar1) {
      *(char *)(iVar3 + 0x14) = (char)param_3;
      if (param_3 < iVar1) {
        if ((*(byte *)(iVar3 + 0x17) == 1) && (*(char *)(iVar3 + 0x15) = (char)param_3, param_3 < 1)
           ) {
          *(undefined1 *)(iVar3 + 0x17) = 0;
          FUN_080164dc(DAT_080214e0,param_2);
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
switchD_08021124_default:
  return param_4;
}



/* ===== FUN_080211bc @ 080211bc ===== */

void FUN_080211bc(int param_1)

{
  char *pcVar2;
  char *pcVar1;
  undefined1 uVar3;
  
  uVar3 = 0;
  pcVar2 = (char *)(param_1 + 0x14);
  if ((char *)(param_1 + 0x14) < (char *)0xffffffec) {
    do {
      pcVar1 = pcVar2 + 5;
      if ('\0' < *pcVar2) {
        uVar3 = 1;
        break;
      }
      pcVar2 = pcVar1;
    } while (pcVar1 < (char *)(param_1 + 0x28));
  }
  *(undefined1 *)(DAT_080214e0 + 0x20) = uVar3;
  return;
}



/* ===== FUN_080211de @ 080211de ===== */

void FUN_080211de(int param_1)

{
  uint uVar1;
  
  uVar1 = param_1 + 0x14;
  if (uVar1 < 0xffffffec) {
    do {
      if (2 < *(byte *)(uVar1 + 3)) {
        *(undefined1 *)(uVar1 + 3) = 2;
      }
      uVar1 = uVar1 + 5;
    } while (uVar1 < param_1 + 0x28U);
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



/* ===== FUN_08021202 @ 08021202 ===== */

void FUN_08021202(int param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(param_1 + 0x14);
  if (puVar1 < (undefined1 *)0xffffffec) {
    do {
      if (puVar1[3] != '\0') {
        puVar1[1] = *puVar1;
        puVar1[2] = 0;
        puVar1[3] = 1;
      }
      puVar1 = puVar1 + 5;
    } while (puVar1 < (undefined1 *)(param_1 + 0x28));
  }
  *(undefined1 *)(param_1 + 0xd) = 0;
  FUN_0801469a();
  FUN_08017df0(8);
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



/* ===== FUN_0802123a @ 0802123a ===== */

int FUN_0802123a(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  
  cVar1 = -1;
  iVar2 = 0;
  cVar3 = '\x03';
  param_1 = param_1 + 0xf;
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



/* ===== FUN_08021276 @ 08021276 ===== */

undefined4 FUN_08021276(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  char cVar4;
  
  pbVar1 = (byte *)FUN_080157c2();
  if (-1 < (int)((uint)*pbVar1 << 0x1f)) {
    pbVar1[1] = *(char *)(param_1 + 0x14) + 0x20;
    cVar4 = *(char *)(param_1 + 0x19);
    if (cVar4 != '\0') {
      cVar4 = cVar4 + '\x03';
    }
    pbVar1[2] = cVar4 + 0x20;
    cVar4 = *(char *)(param_1 + 0x1e);
    if (cVar4 != '\0') {
      cVar4 = cVar4 + '\x06';
    }
    pbVar1[3] = cVar4 + 0x20;
    cVar4 = *(char *)(param_1 + 0x23);
    if (cVar4 != '\0') {
      cVar4 = cVar4 + '\t';
    }
    pbVar1[4] = cVar4 + 0x20;
    if (*(int *)pbVar1 != *(int *)pbVar1) {
      if (*(int *)pbVar1 == 0x20202020) {
        if (*(char *)(DAT_080214e4 + 0xc) != '\0') {
          FUN_080165ce();
        }
      }
      else {
        FUN_08021070();
      }
    }
  }
  pbVar2 = pbVar1 + 8;
  if ('\0' < *(char *)(param_1 + 0x24)) {
    pbVar2 = pbVar1 + 9;
    pbVar1[8] = *(char *)(param_1 + 0x24) + 0x29;
  }
  pbVar3 = pbVar2;
  if ('\0' < *(char *)(param_1 + 0x1f)) {
    pbVar3 = pbVar2 + 1;
    *pbVar2 = *(char *)(param_1 + 0x1f) + 0x26;
  }
  pbVar2 = pbVar3;
  if ('\0' < *(char *)(param_1 + 0x1a)) {
    pbVar2 = pbVar3 + 1;
    *pbVar3 = *(char *)(param_1 + 0x1a) + 0x23;
  }
  pbVar3 = pbVar2;
  if ('\0' < *(char *)(param_1 + 0x15)) {
    pbVar3 = pbVar2 + 1;
    *pbVar2 = *(char *)(param_1 + 0x15) + 0x20;
  }
  pbVar2 = pbVar3;
  if (pbVar3 == pbVar1 + 8) {
    pbVar2 = pbVar3 + 1;
    *pbVar3 = 0x20;
  }
  *pbVar2 = 0;
  return param_4;
}



/* ===== FUN_0802132a @ 0802132a ===== */

void FUN_0802132a(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  FUN_080211bc();
  uVar4 = DAT_080214e0;
  do {
    if (*(int *)(param_1 + 0x10) < 1) {
LAB_08021384:
      FUN_08021276(param_1);
      return;
    }
    uVar3 = FUN_0802123a(param_1,3);
    if ((int)uVar3 < 0) {
      return;
    }
    FUN_080146a2();
    iVar6 = param_1 + uVar3 * 5;
    cVar1 = *(char *)(iVar6 + 0x16);
    iVar5 = (int)cVar1;
    if (iVar5 < 1) goto LAB_08021384;
    if ((0 < *(char *)(param_1 + 0xd)) && (iVar5 <= *(char *)(param_1 + 0xd))) {
      FUN_080211de(param_1);
      goto LAB_08021384;
    }
    iVar2 = FUN_0801651c(uVar4,uVar3,iVar5);
    if (iVar2 == 0) {
      iVar5 = FUN_080164ee(uVar4,uVar3,iVar5);
      if (iVar5 != 0) {
        FUN_08014692();
        if (*(char *)(param_1 + 0xc) != '\0') {
          FUN_080165ce(param_1);
        }
        *(char *)(param_1 + 0xd) = cVar1;
        FUN_080211de(param_1);
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
        FUN_08017df0(7);
        FUN_08017de6(uVar4);
      }
      goto LAB_08021384;
    }
    *(char *)(iVar6 + 0x16) = cVar1 + -1;
  } while( true );
}



/* ===== FUN_080213d4 @ 080213d4 ===== */

undefined4 FUN_080213d4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  FUN_08017df0(7);
  switch(param_2) {
  case 0:
    if (*(char *)(param_1 + 0xd) < '\x01') {
      return param_4;
    }
    uVar1 = 0x20000;
    break;
  case 1:
    if (*(int *)(DAT_080214e8 + 0x68) << 0x1a < 0) {
      *(undefined1 *)(param_1 + 0xd) = 0;
      FUN_0801469a();
      uVar1 = FUN_08017df0(8,param_4);
      return uVar1;
    }
    uVar1 = 0x28000;
    break;
  case 3:
  case 4:
    FUN_08021202(param_1);
  case 2:
    *(undefined1 *)(param_1 + 0xd) = 0;
    FUN_0801469a();
    FUN_08017df0(8);
    if (*(char *)(param_1 + 0xc) == '\0') {
      return param_4;
    }
    uVar1 = FUN_080165ce(param_1,param_4);
    return uVar1;
  default:
    return param_4;
  }
  uVar1 = FUN_080165ac(param_1,uVar1,param_4);
  return uVar1;
}



/* ===== FUN_0802144c @ 0802144c ===== */

longlong FUN_0802144c(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  FUN_0801469a();
  uVar4 = DAT_080214e0;
  do {
    uVar2 = FUN_0802123a(param_1,2);
    if ((int)uVar2 < 0) {
LAB_080214c8:
      return (ulonglong)param_4 << 0x20;
    }
    iVar6 = param_1 + uVar2 * 5;
    cVar1 = *(char *)(iVar6 + 0x16);
    iVar5 = (int)cVar1;
    if (iVar5 < 1) goto LAB_080214c8;
    iVar3 = FUN_0801651c(uVar4,uVar2,iVar5);
    if (iVar3 == 0) {
      FUN_08014692();
      iVar5 = FUN_080164ee(uVar4,uVar2,iVar5);
      if (iVar5 == 0) {
        *(int *)(param_1 + 8) = param_2 + 0x8000;
        return CONCAT44(param_4,param_1);
      }
      *(char *)(param_1 + 0xd) = cVar1;
      FUN_080211de(param_1);
      if (uVar2 == 0) {
        uVar4 = 0xc;
      }
      else if (uVar2 == 2) {
        uVar4 = 10;
      }
      else {
        if (1 < uVar2) goto LAB_080214c8;
        uVar4 = 9;
      }
      FUN_08017df0(7);
      FUN_08017de6(uVar4);
      goto LAB_080214c8;
    }
    *(char *)(iVar6 + 0x16) = cVar1 + -1;
  } while( true );
}



/* ===== FUN_080214ec @ 080214ec ===== */

uint FUN_080214ec(undefined4 param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = FUN_08020c96();
  uVar2 = *(uint *)(DAT_0802150c + 0x18) & 0xff;
  if (uVar2 < bVar1) {
    uVar2 = (uint)bVar1;
  }
  return -(uint)(uVar2 < param_2) >> 0x1f;
}



/* ===== FUN_08021510 @ 08021510 ===== */

void FUN_08021510(uint param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = DAT_08021598;
  if (param_2 + param_1 != 0) {
    if (999 < param_1) {
      param_1 = 999;
    }
    if (999 < param_2) {
      param_2 = 999;
    }
    *DAT_08021598 = param_2;
    puVar1[1] = param_1;
    *DAT_0802159c = 1;
    puVar1 = DAT_080215a0;
    DAT_080215a0[4] = 0xfffffffe;
    puVar1[3] = puVar1[3] | 1;
    *puVar1 = *puVar1 | 1;
  }
  return;
}



/* ===== FUN_08021570 @ 08021570 ===== */

uint FUN_08021570(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  
  puVar1 = DAT_08021598;
  *DAT_08021598 = 0;
  puVar1[1] = 0;
  *DAT_0802159c = 0;
  puVar2 = DAT_080215a0;
  *DAT_080215a0 = *DAT_080215a0 & 0xfffffffe;
  puVar2[4] = 0xfffffffe;
  return puVar2[4];
}



/* ===== FUN_080215a4 @ 080215a4 ===== */

void FUN_080215a4(int *param_1,int param_2)

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
        if (iVar1 == 0) goto LAB_080215c0;
      } while (iVar1 != param_2);
      *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar1 + 4);
    }
  }
LAB_080215c0:
  *(undefined1 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 4) = 0;
  return;
}



/* ===== FUN_080215c8 @ 080215c8 ===== */

void FUN_080215c8(int *param_1,int param_2)

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



/* ===== FUN_0802160c @ 0802160c ===== */

void FUN_0802160c(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  if (0 < *(char *)(param_1 + 0x15)) {
    piVar2 = (int *)(DAT_08021644 + 0x28);
    for (piVar1 = (int *)(DAT_08021644 + *(char *)(param_1 + 0x15) * 4 + 0x24); piVar2 <= piVar1;
        piVar1 = piVar1 + -1) {
      if ((int *)*piVar1 != (int *)0x0) {
        (**(code **)(*(int *)*piVar1 + 4))();
      }
      *piVar1 = 0;
    }
    *(undefined1 *)(param_1 + 0x15) = 0;
  }
  return;
}



/* ===== FUN_08021648 @ 08021648 ===== */

uint FUN_08021648(uint param_1)

{
  return param_1 | 0x20;
}



/* ===== FUN_0802164e @ 0802164e ===== */

/* WARNING: Type propagation algorithm not settling */

int FUN_0802164e(undefined4 param_1,undefined4 param_2,byte *param_3,int *param_4,undefined1 param_5
                )

{
  short sVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined1 *puVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  byte bVar11;
  undefined *puVar12;
  uint uVar13;
  byte *pbVar14;
  undefined1 extraout_r2;
  undefined4 *puVar15;
  uint *puVar16;
  byte bVar17;
  short sVar18;
  int iVar19;
  uint uVar20;
  byte *pbVar21;
  byte *pbVar22;
  uint uVar23;
  char cVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  int local_f0;
  undefined4 local_ec;
  undefined4 uStack_e8;
  uint local_e4;
  undefined8 local_e0;
  undefined4 local_d8;
  byte *local_d4;
  byte *local_d0;
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
  char acStack_75 [5];
  uint local_70;
  uint uStack_6c;
  byte local_68 [64];
  undefined4 local_28;
  
  local_ec = 0;
  uStack_e8 = 0;
  local_b4 = 0;
  local_a0 = &local_a6;
  local_a5 = param_5;
  local_d8 = param_2;
  local_28 = param_1;
  do {
    for (; *param_3 != 0x25; param_3 = param_3 + iVar4) {
      iVar4 = FUN_0802cf2e(param_3,0xffffffff,&local_ec);
      if (iVar4 == 0) {
        return local_b4;
      }
      if (iVar4 < 0) {
        iVar4 = 1;
      }
      else {
        iVar8 = FUN_080225e4(local_28,&local_e0,param_3,iVar4);
        if (iVar8 < 0) {
          return -1;
        }
      }
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
              pbVar21 = param_3 + 1;
              bVar11 = *pbVar21;
              if (bVar11 != 0x20) break;
              local_a8 = local_a8 | 1;
              param_3 = pbVar21;
            }
            if (bVar11 != 0x23) break;
            local_a8 = local_a8 | 8;
            param_3 = pbVar21;
          }
          if (bVar11 != 0x2b) break;
          local_a8 = local_a8 | 2;
          param_3 = pbVar21;
        }
        if (bVar11 != 0x2d) break;
        local_a8 = local_a8 | 4;
        param_3 = pbVar21;
      }
      if (bVar11 != 0x30) break;
      local_a8 = local_a8 | 0x10;
      param_3 = pbVar21;
    }
    if (bVar11 == 0x2a) {
      local_ac = *(int *)*param_4;
      *param_4 = (int)((int *)*param_4 + 1);
      if (local_ac < 0) {
        local_ac = -local_ac;
        local_a8 = local_a8 | 4;
      }
      pbVar21 = param_3 + 2;
    }
    else {
      local_ac = 0;
      for (; *pbVar21 - 0x30 < 10; pbVar21 = pbVar21 + 1) {
        if (local_ac < DAT_0802222c) {
          local_ac = (uint)*pbVar21 + local_ac * 10 + -0x30;
        }
      }
    }
    if (*pbVar21 == 0x2e) {
      bVar11 = pbVar21[1];
      if (bVar11 == 0x2a) {
        local_b0 = *(uint *)*param_4;
        *param_4 = (int)((uint *)*param_4 + 1);
        pbVar21 = pbVar21 + 2;
      }
      else {
        if (bVar11 == 0x2d) {
          cVar24 = '-';
          pbVar21 = pbVar21 + 2;
        }
        else {
          cVar24 = '\0';
          pbVar21 = pbVar21 + 1;
        }
        local_b0 = 0;
        for (; *pbVar21 - 0x30 < 10; pbVar21 = pbVar21 + 1) {
          if ((cVar24 == '\0') && ((int)local_b0 < DAT_0802222c)) {
            local_b0 = ((uint)*pbVar21 + local_b0 * 10) - 0x30;
          }
        }
      }
    }
    else {
      local_b0 = 0xffffffff;
    }
    uVar25 = FUN_0802cf50("hjltzL",*pbVar21);
    uVar9 = local_b0;
    uVar23 = (uint)((ulonglong)uVar25 >> 0x20);
    local_a6 = 0;
    pbVar22 = pbVar21;
    if ((int)uVar25 != 0) {
      pbVar22 = pbVar21 + 1;
      local_a6 = *pbVar21;
    }
    if (local_a6 == 0x68) {
      if (*pbVar22 == 0x68) {
        local_a6 = 0x62;
        goto LAB_080217e0;
      }
    }
    else {
      if (local_a6 == 0x6c) {
        uVar23 = (uint)*pbVar22;
      }
      if (local_a6 == 0x6c && uVar23 == 0x6c) {
        local_a6 = 0x71;
LAB_080217e0:
        pbVar22 = pbVar22 + 1;
      }
    }
    local_d0 = local_68;
    param_3 = pbVar22 + 1;
    bVar11 = *pbVar22;
    uVar23 = (uint)bVar11;
    if (uVar23 == 0x25) {
      local_cc = 1;
      local_68[0] = 0x25;
      goto LAB_080218b4;
    }
    if ((uVar23 == 0x41) || (uVar23 - 0x45 < 3)) {
LAB_08021a4a:
      puVar16 = (uint *)(*param_4 + 7U & 0xfffffff8);
      *param_4 = (int)puVar16;
      local_e0._0_4_ = *puVar16;
      local_e0._4_4_ = puVar16[1];
      if (local_a6 == 0x4c) {
        *param_4 = (int)(puVar16 + 2);
      }
      else {
        *param_4 = (int)(puVar16 + 2);
      }
      if ((int)local_e0._4_4_ < 0) {
        bVar17 = 0x2d;
LAB_08021a96:
        local_68[local_cc] = bVar17;
        local_cc = local_cc + 1;
      }
      else {
        if ((int)((uint)local_a8 << 0x1e) < 0) {
          bVar17 = 0x2b;
          goto LAB_08021a96;
        }
        if ((int)((uint)local_a8 << 0x1f) < 0) {
          bVar17 = 0x20;
          goto LAB_08021a96;
        }
      }
      local_d4 = local_68 + local_cc;
      pbVar21 = (byte *)&local_9c;
      if ((uVar23 | 0x20) != 0x61) {
        if ((int)local_b0 < 0) {
          local_b0 = 6;
        }
        else {
          if (local_b0 == 0) {
            uVar9 = uVar23 | 0x20;
          }
          if (!(local_b0 != 0 || uVar9 != 0x67)) {
            local_b0 = 1;
          }
        }
      }
      uVar9 = local_e0._4_4_ << 1 | (uint)local_e0 >> 0x1f;
      local_70 = (uint)local_e0;
      uStack_6c = local_e0._4_4_;
      if (((int)uVar9 < 0 && (int)uVar9 >> 0x15 == -1) &&
         (((local_e0._4_4_ & 0xfffff) != 0 || (uint)local_e0 >> 0x14 != 0) ||
          ((uint)local_e0 & 0xfffff) != 0)) {
        if (uVar23 - 0x61 < 0x1a) {
          puVar12 = &DAT_08022614;
        }
        else {
          puVar12 = &DAT_08022618;
        }
      }
      else {
        if (((int)(local_e0._4_4_ << 1) >> 0x15 != -1) || ((local_e0._4_4_ & 0xfffff) != 0)) {
          local_e0 = FUN_0802d000((uint)local_e0,local_e0._4_4_,&local_f0);
          uVar9 = local_70;
          uVar20 = (uint)(local_e0 >> 0x20);
          iVar4 = (int)local_e0;
          if ((uVar23 | 0x20) == 0x61) {
            *local_d4 = 0x30;
            if (uVar23 == 0x61) {
              bVar17 = 0x78;
            }
            else {
              bVar17 = 0x58;
            }
            local_d4[1] = bVar17;
            local_cc = local_cc + 2;
            local_d4 = local_d4 + 2;
          }
          if ((local_e0 & 0x7fffffff00000000) == 0 && iVar4 == 0) {
            uVar9 = 0;
            iVar4 = 0;
          }
          else {
            uVar13 = uVar23 | 0x20;
            if (uVar13 == 0x61) {
              if ((int)local_b0 < 0) {
                local_e4 = 0x21;
              }
              else {
                local_e4 = local_b0 + 1;
              }
              cVar24 = 0xfffffffe < local_e4;
              iVar8 = local_e4 + 1;
              FUN_0802d070(local_70,uStack_6c,0,0);
              if (cVar24 == '\0') {
                uVar20 = uVar20 ^ 0x80000000;
              }
              uVar25 = CONCAT44(uVar20,iVar4);
              local_9c = CONCAT31(local_9c._1_3_,extraout_r2);
              local_f0 = local_f0 + -4;
              pbVar21 = (byte *)((int)&local_9c + 1);
              while( true ) {
                if (iVar8 < 1) break;
                cVar24 = '\x01';
                uVar25 = FUN_0802d0a4((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),0,0);
                if (cVar24 != '\0') break;
                uVar25 = FUN_0802d0d8((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),0x1c);
                iVar4 = FUN_0802d214();
                iVar8 = iVar8 + -7;
                if (0 < iVar8) {
                  uVar26 = FUN_0802d24c();
                  uVar25 = FUN_0802d3dc((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),(int)uVar26,
                                        (int)((ulonglong)uVar26 >> 0x20));
                }
                pbVar21 = pbVar21 + 7;
                iVar19 = 7;
                while ((0 < iVar4 && (iVar19 = iVar19 + -1, -1 < iVar19))) {
                  pbVar21 = pbVar21 + -1;
                  *pbVar21 = (byte)iVar4 & 0xf;
                  iVar4 = iVar4 >> 4;
                }
                while (iVar19 = iVar19 + -1, -1 < iVar19) {
                  pbVar21 = pbVar21 + -1;
                  *pbVar21 = 0;
                }
                pbVar21 = pbVar21 + 7;
              }
              uVar20 = (int)pbVar21 - ((int)&local_9c + 1);
              pbVar21 = (byte *)((int)&local_9c + 1);
              uVar9 = local_e4;
              if ((int)uVar20 <= (int)local_e4) {
                uVar9 = uVar20;
              }
              if (-1 < (int)uVar9) {
                if (((int)uVar9 < (int)uVar20) && (7 < (byte)acStack_94[uVar9 - 7])) {
                  cVar24 = '\x0f';
                }
                else {
                  cVar24 = '\0';
                }
                uVar20 = uVar9;
                pcVar3 = acStack_94 + (uVar9 - 8);
                while( true ) {
                  if (*pcVar3 != cVar24) break;
                  uVar9 = uVar9 - 1;
                  uVar20 = uVar20 - 1;
                  pcVar3 = pcVar3 + -1;
                }
                if (cVar24 == '\x0f') {
                  acStack_94[uVar20 - 8] = acStack_94[uVar20 - 8] + '\x01';
                }
                if ((int)(uVar20 - 1) < 0) {
                  local_f0 = local_f0 + 4;
                  pbVar21 = (byte *)&local_9c;
                  uVar9 = uVar9 + 1;
                }
                iVar4 = uVar9 - 1;
                if (-1 < iVar4) {
                  pbVar22 = pbVar21 + iVar4;
                  do {
                    bVar17 = *pbVar22 + 0x30;
                    if (0x39 < (byte)(*pbVar22 + 0x30)) {
                      bVar17 = (bVar17 + bVar11) - 0x3a;
                    }
                    iVar4 = iVar4 + -1;
                    *pbVar22 = bVar17;
                    pbVar22 = pbVar22 + -1;
                  } while (-1 < iVar4);
                }
              }
              if ((int)local_b0 < 0) {
                local_b0 = uVar9 - 1;
              }
            }
            else {
              local_f0 = (local_f0 * 0x7597) / DAT_080225d4;
              uVar20 = uStack_6c & 0x7fffffff;
              if (7 - local_f0 < 1) {
                uVar25 = FUN_0802258e(0,DAT_080225d8,-(7 - local_f0));
                uVar25 = FUN_0802d4c0(uVar9,uVar20,(int)uVar25,(int)((ulonglong)uVar25 >> 0x20));
              }
              else {
                uVar25 = FUN_0802258e(local_70,uVar20);
              }
              if (uVar13 == 0x66) {
                iVar4 = local_f0 + 10;
              }
              else {
                iVar4 = 6;
              }
              iVar4 = iVar4 + local_b0;
              if (0x14 < iVar4) {
                iVar4 = 0x14;
              }
              local_9c = CONCAT31(local_9c._1_3_,0x30);
              local_70 = 0;
              uStack_6c = DAT_080225dc;
              pcVar3 = (char *)((int)&local_9c + 1);
              while (0 < iVar4) {
                while( true ) {
                  uVar10 = (undefined4)((ulonglong)uVar25 >> 0x20);
                  uVar20 = FUN_0802d708((int)uVar25,uVar10);
                  iVar8 = 4;
                  uVar9 = uVar20;
                  pcVar2 = pcVar3 + 8;
                  do {
                    pcVar3 = pcVar2;
                    cVar24 = (char)(uVar9 / 10);
                    pcVar3[-1] = (char)uVar9 + cVar24 * -10 + '0';
                    uVar9 = (uVar9 / 10) / 10;
                    iVar8 = iVar8 + -1;
                    pcVar3[-2] = cVar24 + (char)uVar9 * -10 + '0';
                    pcVar2 = pcVar3 + -2;
                  } while (iVar8 != 0);
                  iVar4 = iVar4 + -8;
                  pcVar3 = pcVar3 + 6;
                  if (iVar4 < 1) break;
                  uVar26 = FUN_0802d72c(uVar20);
                  uVar25 = FUN_0802d3dc((int)uVar25,uVar10,(int)uVar26,
                                        (int)((ulonglong)uVar26 >> 0x20));
                  uVar25 = FUN_0802d748((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),local_70,
                                        uStack_6c);
                }
              }
              iVar4 = (int)pcVar3 - ((int)&local_9c + 1);
              for (pbVar21 = (byte *)((int)&local_9c + 1); *pbVar21 == 0x30; pbVar21 = pbVar21 + 1)
              {
                local_f0 = local_f0 + -1;
                iVar4 = iVar4 + -1;
              }
              if (uVar13 == 0x66) {
                iVar8 = local_f0 + 1;
              }
              else if (uVar13 == 0x65) {
                iVar8 = 1;
              }
              else {
                iVar8 = 0;
              }
              uVar9 = iVar8 + local_b0;
              if (iVar4 < (int)uVar9) {
                uVar9 = iVar4 - 1;
              }
              if (-1 < (int)uVar9) {
                if (((int)uVar9 < iVar4) && (0x34 < pbVar21[uVar9])) {
                  bVar11 = 0x39;
                }
                else {
                  bVar11 = 0x30;
                }
                uVar20 = uVar9;
                pbVar22 = pbVar21 + -1 + uVar9;
                while( true ) {
                  uVar20 = uVar20 - 1;
                  if (*pbVar22 != bVar11) break;
                  uVar9 = uVar9 - 1;
                  pbVar22 = pbVar22 + -1;
                }
                if (bVar11 == 0x39) {
                  pbVar21[uVar20] = pbVar21[uVar20] + 1;
                }
                if ((int)uVar20 < 0) {
                  local_f0 = local_f0 + 1;
                  uVar9 = uVar9 + 1;
                  pbVar21 = pbVar21 + -1;
                }
              }
            }
            iVar4 = local_f0;
          }
          iVar8 = FUN_0802cf42();
          bVar11 = **(byte **)(iVar8 + 0x24);
          if ((short)uVar9 < 1) {
            uVar9 = 1;
            pbVar21 = &DAT_08022624;
          }
          sVar1 = (short)uVar9;
          uVar20 = local_b0;
          if ((uVar23 | 0x20) == 0x66) {
LAB_08021e74:
            sVar18 = (short)(iVar4 + 1);
            iVar8 = (int)sVar18;
            if (iVar8 < 1) {
              local_d4[local_c8] = 0x30;
              if ((0 < (int)uVar20) ||
                 (uVar23 = local_c8 + 1, (int)((uint)(byte)local_a8 << 0x1c) < 0)) {
                local_d4[local_c8 + 1] = bVar11;
                uVar23 = local_c8 + 2;
              }
              local_c8 = uVar23;
              if ((int)(uVar20 + iVar8) < 0 != SCARRY4(uVar20,iVar8)) {
                sVar18 = -(short)uVar20;
              }
              local_bc = -(int)sVar18;
              uVar20 = (int)sVar18 + uVar20;
              if ((int)uVar20 < (int)sVar1) {
                uVar9 = uVar20;
              }
              iVar4 = (int)(short)uVar9;
              local_c4 = iVar4;
              FUN_080262d4(local_d4 + local_c8,pbVar21,iVar4);
              local_b8 = uVar20 - iVar4;
            }
            else if (sVar1 < sVar18) {
              FUN_080262d4(local_d4 + local_c8,pbVar21,(int)sVar1);
              local_c8 = (int)sVar1 + local_c8;
              local_bc = iVar8 - sVar1;
              if ((0 < (int)uVar20) || ((int)((uint)(byte)local_a8 << 0x1c) < 0)) {
                local_d4[local_c8] = bVar11;
                local_c4 = local_c4 + 1;
              }
              local_b8 = uVar20;
            }
            else {
              FUN_080262d4(local_d4 + local_c8,pbVar21);
              uVar9 = uVar9 - (iVar4 + 1);
              iVar4 = local_c8 + iVar8;
              if ((int)uVar20 < 1) {
                local_c8 = iVar4;
                if ((int)((uint)(byte)local_a8 << 0x1c) < 0) goto LAB_08022040;
              }
              else {
LAB_08022040:
                local_c8 = iVar4 + 1;
                local_d4[iVar4] = bVar11;
              }
              if ((int)uVar20 < (int)(short)uVar9) {
                uVar9 = uVar20;
              }
              sVar1 = (short)uVar9;
              FUN_080262d4(local_d4 + local_c8,pbVar21 + iVar8,(int)sVar1);
              local_c8 = (int)sVar1 + local_c8;
              local_bc = uVar20 - (int)sVar1;
            }
          }
          else {
            sVar18 = (short)iVar4;
            if ((uVar23 | 0x20) == 0x67) {
              if ((-5 < sVar18) && ((int)sVar18 < (int)local_b0)) {
                if ((-1 < (int)((uint)(byte)local_a8 << 0x1c)) && ((int)sVar1 <= (int)local_b0)) {
                  uVar20 = (int)sVar1;
                }
                uVar20 = uVar20 - (int)(short)(sVar18 + 1);
                if ((int)uVar20 < 0) {
                  uVar20 = 0;
                }
                goto LAB_08021e74;
              }
              if (((int)sVar1 < (int)local_b0) && (-1 < (int)((uint)(byte)local_a8 << 0x1c))) {
                uVar20 = (int)sVar1;
              }
              uVar20 = uVar20 - 1;
              if ((int)uVar20 < 0) {
                uVar20 = 0;
              }
              if (uVar23 == 0x67) {
                uVar23 = 0x65;
              }
              else {
                uVar23 = 0x45;
              }
            }
            else if (uVar23 == 0x61) {
              uVar23 = 0x70;
            }
            else if (uVar23 == 0x41) {
              uVar23 = 0x50;
            }
            uVar13 = local_c8 + 1;
            local_d4[local_c8] = *pbVar21;
            if ((0 < (int)uVar20) || ((int)((uint)(byte)local_a8 << 0x1c) < 0)) {
              local_c8 = local_c8 + 2;
              local_d4[uVar13] = bVar11;
              uVar13 = local_c8;
              if (0 < (int)uVar20) {
                uVar13 = uVar9 - 1;
                if ((int)uVar20 < (int)(short)(uVar9 - 1)) {
                  uVar13 = uVar20;
                }
                sVar1 = (short)uVar13;
                FUN_080262d4(local_d4 + local_c8,pbVar21 + 1,(int)sVar1);
                local_bc = uVar20 - (int)sVar1;
                uVar13 = (int)sVar1 + local_c8;
              }
            }
            local_c8 = uVar13;
            pbVar21 = local_d4 + local_c8;
            *pbVar21 = (byte)uVar23;
            if (sVar18 < 0) {
              pbVar21[1] = 0x2d;
              iVar4 = -(int)sVar18;
            }
            else {
              pbVar21[1] = 0x2b;
            }
            pbVar22 = pbVar21 + 2;
            iVar8 = 0;
            pcVar3 = acStack_75;
            while( true ) {
              pcVar3 = pcVar3 + 1;
              if ((short)iVar4 < 1) break;
              iVar19 = (int)(short)iVar4 / 10;
              *pcVar3 = (char)iVar4 + (char)iVar19 * -10;
              iVar8 = iVar8 + 1;
              iVar4 = iVar19;
            }
            pbVar14 = pbVar22;
            if ((iVar8 < 2) && ((uVar23 | 0x20) == 0x65)) {
              pbVar14 = pbVar21 + 3;
              *pbVar22 = 0x30;
            }
            pbVar21 = pbVar14;
            if (iVar8 == 0) {
              pbVar21 = pbVar14 + 1;
              *pbVar14 = 0x30;
            }
            else {
              for (; 0 < iVar8; iVar8 = iVar8 + -1) {
                *pbVar21 = acStack_75[iVar8] + 0x30;
                pbVar21 = pbVar21 + 1;
              }
            }
            local_c4 = (int)pbVar21 - (int)(local_d4 + local_c8);
          }
          if ((((byte)local_a8 & 0x14) == 0x10) &&
             (iVar4 = local_b8 + local_c4 + local_bc + local_c8 + local_cc, iVar4 < local_ac)) {
            local_c0 = local_ac - iVar4;
          }
          goto LAB_080218b4;
        }
        if (uVar23 - 0x61 < 0x1a) {
          puVar12 = &DAT_0802261c;
        }
        else {
          puVar12 = &DAT_08022620;
        }
      }
      local_c8 = 3;
      FUN_080262d4(local_d4,puVar12,3);
    }
    else if (uVar23 == 0x53) {
      local_a6 = 0x6c;
LAB_08021864:
      puVar15 = *(undefined4 **)*param_4;
      *param_4 = (int)((undefined4 *)*param_4 + 1);
      if (puVar15 == (undefined4 *)0x0) {
        if (local_a0[1] != 0) {
          pcVar3 = "printf_s: bad %ls argument";
          goto LAB_080218ac;
        }
        puVar15 = (undefined4 *)&DAT_08022274;
      }
LAB_080218fe:
      iVar4 = FUN_080223ba(local_28,&local_e0,puVar15);
      if (iVar4 < 0) {
        return -1;
      }
    }
    else {
      if (uVar23 == 0x58) goto LAB_0802209c;
      if (uVar23 == 0x61) goto LAB_08021a4a;
      if (uVar23 == 99) {
        if (local_a6 != 0x6c) {
          local_cc = 1;
          uVar10 = *(undefined4 *)*param_4;
          *param_4 = (int)((undefined4 *)*param_4 + 1);
          local_68[0] = (byte)uVar10;
          goto LAB_080218b4;
        }
        local_9c = *(undefined4 *)*param_4;
        *param_4 = (int)((undefined4 *)*param_4 + 1);
        local_98 = 0;
        local_b0 = 0xffffffff;
        puVar15 = &local_9c;
        goto LAB_080218fe;
      }
      if (uVar23 == 100) {
LAB_08022132:
        if (local_a6 == 0x62) {
          uVar10 = *(undefined4 *)*param_4;
          *param_4 = (int)((undefined4 *)*param_4 + 1);
          local_e0._0_4_ = (uint)(char)uVar10;
LAB_08022192:
          local_e0._4_4_ = (int)(uint)local_e0 >> 0x1f;
        }
        else {
          if (local_a6 == 0x68) {
            uVar10 = *(undefined4 *)*param_4;
            *param_4 = (int)((undefined4 *)*param_4 + 1);
            local_e0._0_4_ = (uint)(short)uVar10;
            goto LAB_08022192;
          }
          if ((local_a6 != 0x6a) && ((local_a6 == 0x6c || (local_a6 != 0x71)))) {
            local_e0._0_4_ = *(uint *)*param_4;
            *param_4 = (int)((uint *)*param_4 + 1);
            goto LAB_08022192;
          }
          puVar16 = (uint *)(*param_4 + 7U & 0xfffffff8);
          *param_4 = (int)puVar16;
          local_e0._0_4_ = *puVar16;
          local_e0._4_4_ = puVar16[1];
          *param_4 = (int)(puVar16 + 2);
        }
        if ((int)local_e0._4_4_ < 0) {
          bVar11 = 0x2d;
LAB_080221b8:
          local_68[local_cc] = bVar11;
          local_cc = local_cc + 1;
        }
        else {
          if ((int)((uint)local_a8 << 0x1e) < 0) {
            bVar11 = 0x2b;
            goto LAB_080221b8;
          }
          if ((int)((uint)local_a8 << 0x1f) < 0) {
            bVar11 = 0x20;
            goto LAB_080221b8;
          }
        }
LAB_080221c0:
        local_d4 = local_68 + local_cc;
      }
      else {
        if (uVar23 - 0x65 < 3) goto LAB_08021a4a;
        if (uVar23 == 0x69) goto LAB_08022132;
        if (uVar23 == 0x6e) {
          if (local_a0[1] == 0) {
            if (local_a6 == 0x62) {
              puVar6 = *(undefined1 **)*param_4;
              *param_4 = (int)((undefined4 *)*param_4 + 1);
              if (puVar6 != (undefined1 *)0x0) {
                *puVar6 = (char)local_b4;
                goto LAB_080218b4;
              }
              pcVar3 = "printf: bad %n argument";
            }
            else if (local_a6 == 0x68) {
              puVar5 = *(undefined2 **)*param_4;
              *param_4 = (int)((undefined4 *)*param_4 + 1);
              if (puVar5 != (undefined2 *)0x0) {
                *puVar5 = (short)local_b4;
                goto LAB_080218b4;
              }
              pcVar3 = "printf: bad %n argument";
            }
            else if (local_a6 == 0x6a) {
              piVar7 = *(int **)*param_4;
              *param_4 = (int)((int *)*param_4 + 1);
              if (piVar7 != (int *)0x0) {
LAB_080219ee:
                *piVar7 = local_b4;
                piVar7[1] = local_b4 >> 0x1f;
                goto LAB_080218b4;
              }
              pcVar3 = "printf: bad %n argument";
            }
            else if (local_a6 == 0x6c) {
              piVar7 = *(int **)*param_4;
              *param_4 = (int)((int *)*param_4 + 1);
              if (piVar7 != (int *)0x0) goto LAB_0802197e;
              pcVar3 = "printf: bad %n argument";
            }
            else if (local_a6 == 0x71) {
              piVar7 = *(int **)*param_4;
              *param_4 = (int)((int *)*param_4 + 1);
              if (piVar7 != (int *)0x0) goto LAB_080219ee;
              pcVar3 = "printf: bad %n argument";
            }
            else if (local_a6 == 0x74) {
              piVar7 = *(int **)*param_4;
              *param_4 = (int)((int *)*param_4 + 1);
              if (piVar7 != (int *)0x0) goto LAB_0802197e;
              pcVar3 = "printf: bad %n argument";
            }
            else if (local_a6 == 0x7a) {
              piVar7 = *(int **)*param_4;
              *param_4 = (int)((int *)*param_4 + 1);
              if (piVar7 != (int *)0x0) goto LAB_0802197e;
              pcVar3 = "printf: bad %n argument";
            }
            else {
              piVar7 = *(int **)*param_4;
              *param_4 = (int)((int *)*param_4 + 1);
              if (piVar7 != (int *)0x0) {
LAB_0802197e:
                *piVar7 = local_b4;
                goto LAB_080218b4;
              }
              pcVar3 = "printf: bad %n argument";
            }
          }
          else {
            pcVar3 = "printf_s: %n disallowed";
          }
LAB_080218ac:
          iVar4 = FUN_0802cf68(pcVar3);
          if (iVar4 != -1) {
            return -1;
          }
          goto LAB_080218b4;
        }
        if (uVar23 == 0x6f) {
LAB_0802209c:
          if (local_a6 == 0x62) {
            uVar9 = *(uint *)*param_4;
            *param_4 = (int)((uint *)*param_4 + 1);
            local_e0._0_4_ = uVar9 & 0xff;
LAB_080220fc:
            local_e0._4_4_ = 0;
          }
          else {
            if (local_a6 == 0x68) {
              uVar9 = *(uint *)*param_4;
              *param_4 = (int)((uint *)*param_4 + 1);
              local_e0._0_4_ = uVar9 & 0xffff;
              goto LAB_080220fc;
            }
            if ((local_a6 != 0x6a) && ((local_a6 == 0x6c || (local_a6 != 0x71)))) {
              local_e0._0_4_ = *(uint *)*param_4;
              *param_4 = (int)((uint *)*param_4 + 1);
              goto LAB_080220fc;
            }
            puVar16 = (uint *)(*param_4 + 7U & 0xfffffff8);
            *param_4 = (int)puVar16;
            local_e0._0_4_ = *puVar16;
            local_e0._4_4_ = puVar16[1];
            *param_4 = (int)(puVar16 + 2);
          }
          if ((((int)((uint)(byte)local_a8 << 0x1c) < 0) &&
              (local_e0._4_4_ != 0 || (uint)local_e0 != 0)) && ((uVar23 | 0x20) == 0x78)) {
            local_68[local_cc] = 0x30;
            local_68[local_cc + 1] = bVar11;
            local_cc = local_cc + 2;
          }
          goto LAB_080221c0;
        }
        if (uVar23 != 0x70) {
          if (uVar23 == 0x73) {
            if (local_a6 == 0x6c) goto LAB_08021864;
            pbVar21 = *(byte **)*param_4;
            *param_4 = (int)((undefined4 *)*param_4 + 1);
            local_d4 = pbVar21;
            if (pbVar21 == (byte *)0x0) {
              if (local_a0[1] != 0) {
                pcVar3 = "printf_s: bad %s argument";
                goto LAB_080218ac;
              }
              local_d4 = &DAT_08022270;
            }
            else {
              if ((int)local_b0 < 0) {
                uVar9 = FUN_08027878(pbVar21);
              }
              else {
                iVar4 = FUN_0802cfa8(pbVar21,0,local_b0);
                if (iVar4 != 0) {
                  uVar9 = iVar4 - (int)pbVar21;
                }
              }
              local_c8 = uVar9;
            }
          }
          else {
            if ((uVar23 == 0x75) || (uVar23 == 0x78)) goto LAB_0802209c;
            local_cc = 1;
            local_68[0] = 0x25;
            if (uVar23 != 0) {
              local_cc = 2;
              local_68[1] = bVar11;
            }
          }
          goto LAB_080218b4;
        }
        local_e0._0_4_ = *(uint *)*param_4;
        *param_4 = (int)((uint *)*param_4 + 1);
        local_e0._4_4_ = 0;
        local_d4 = local_68;
        uVar23 = 0x78;
      }
      FUN_0802247a(&local_e0,uVar23);
    }
LAB_080218b4:
    iVar4 = FUN_080222ae(local_28,&local_e0,local_68);
    if (iVar4 < 0) {
      return -1;
    }
  } while( true );
}



/* ===== FUN_080222ae @ 080222ae ===== */

longlong FUN_080222ae(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint local_20;
  undefined4 uStack_1c;
  
  iVar3 = (((((*(int *)(param_2 + 0x34) - *(int *)(param_2 + 0x14)) - *(int *)(param_2 + 0x20)) -
            *(int *)(param_2 + 0x18)) - *(int *)(param_2 + 0x24)) - *(int *)(param_2 + 0x1c)) -
          *(int *)(param_2 + 0x28);
  local_20 = param_3;
  uStack_1c = param_4;
  if ((-1 < (int)((uint)*(byte *)(param_2 + 0x38) << 0x1d)) &&
     (local_20._1_3_ = (undefined3)(param_3 >> 8), local_20 = CONCAT31(local_20._1_3_,0x20),
     0 < iVar3)) {
    iVar2 = iVar3;
    do {
      iVar1 = FUN_080225e4(param_1,param_2,&local_20,1);
      if (iVar1 != 0) goto LAB_080223b2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  iVar2 = FUN_080225e4(param_1,param_2,param_3,*(undefined4 *)(param_2 + 0x14));
  if (iVar2 == 0) {
    local_20 = CONCAT31(local_20._1_3_,0x30);
    iVar2 = *(int *)(param_2 + 0x20);
    if (0 < iVar2) {
      do {
        iVar1 = FUN_080225e4(param_1,param_2,&local_20,1);
        if (iVar1 != 0) goto LAB_080223b2;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    iVar2 = FUN_080225e4(param_1,param_2,*(undefined4 *)(param_2 + 0xc),
                         *(undefined4 *)(param_2 + 0x18));
    if (iVar2 == 0) {
      local_20 = CONCAT31(local_20._1_3_,0x30);
      iVar2 = *(int *)(param_2 + 0x24);
      if (0 < iVar2) {
        do {
          iVar1 = FUN_080225e4(param_1,param_2,&local_20,1);
          if (iVar1 != 0) goto LAB_080223b2;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      iVar2 = FUN_080225e4(param_1,param_2,*(int *)(param_2 + 0xc) + *(int *)(param_2 + 0x18),
                           *(undefined4 *)(param_2 + 0x1c));
      if (iVar2 == 0) {
        local_20 = CONCAT31(local_20._1_3_,0x30);
        iVar2 = *(int *)(param_2 + 0x28);
        if (0 < iVar2) {
          do {
            iVar1 = FUN_080225e4(param_1,param_2,&local_20,1);
            if (iVar1 != 0) goto LAB_080223b2;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
        if (((int)((uint)*(byte *)(param_2 + 0x38) << 0x1d) < 0) &&
           (local_20 = CONCAT31(local_20._1_3_,0x20), 0 < iVar3)) {
          do {
            iVar2 = FUN_080225e4(param_1,param_2,&local_20,1);
            if (iVar2 != 0) goto LAB_080223b2;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        return (ulonglong)local_20 << 0x20;
      }
    }
  }
LAB_080223b2:
  return CONCAT44(local_20,0xffffffff);
}



/* ===== FUN_080223ba @ 080223ba ===== */

int FUN_080223ba(undefined4 param_1,int param_2,int *param_3,undefined4 param_4)

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
  
  iVar3 = *(int *)(param_2 + 0x30);
  if (iVar3 < 0) {
    iVar3 = 0x7fffffff;
  }
  uStack_24 = param_4;
  iVar1 = FUN_0802d8f2();
  local_ac = 0;
  uStack_a8 = 0;
  if ((uint)(iVar1 + *(int *)(param_2 + 0x34)) < 0x81) {
    iVar1 = 0;
    for (; 0 < iVar3; iVar3 = iVar3 - iVar2) {
      iVar2 = FUN_0802cf3e(auStack_b0,*param_3,&local_ac);
      if ((iVar2 < 0) || ((*param_3 == 0 && (iVar2 = iVar2 + -1, iVar2 < 0)))) {
        iVar1 = -1;
        goto LAB_08022474;
      }
      if (iVar3 < iVar2) break;
      if (0x80 < (uint)(iVar2 + *(int *)(param_2 + 0x14))) {
        *(undefined4 *)(param_2 + 0x34) = 0;
        iVar1 = FUN_080222ae(param_1,param_2,auStack_a4);
        if (iVar1 < 0) break;
        *(undefined4 *)(param_2 + 0x14) = 0;
      }
      iVar4 = *(int *)(param_2 + 0x14);
      FUN_080262d4(auStack_a4 + iVar4,auStack_b0,iVar2);
      *(int *)(param_2 + 0x14) = iVar2 + iVar4;
      if (*param_3 == 0) break;
      param_3 = param_3 + 1;
    }
    if (iVar1 == 0) {
      iVar1 = FUN_080222ae(param_1,param_2,auStack_a4);
    }
    if (iVar1 == 0) {
      *(undefined4 *)(param_2 + 0x14) = 0;
      *(undefined4 *)(param_2 + 0x34) = 0;
    }
  }
  else {
    iVar1 = -1;
  }
LAB_08022474:
  return iVar1;
}



/* ===== FUN_0802247a @ 0802247a ===== */

undefined8 FUN_0802247a(int *param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int extraout_r2;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  bool bVar8;
  longlong lVar9;
  undefined4 local_28;
  int local_24;
  
  iVar6 = param_1[4];
  if (param_2 == 0x6f) {
    iVar4 = 8;
  }
  else {
    iVar4 = FUN_08021648();
    if (iVar4 == 0x78) {
      iVar4 = 0x10;
    }
    else {
      iVar4 = 10;
    }
  }
  iVar1 = *param_1;
  iVar2 = param_1[1];
  iVar5 = 0x3c;
  if ((param_2 == 100 || param_2 == 0x69) && (iVar2 < 0)) {
    bVar8 = iVar1 != 0;
    iVar1 = -iVar1;
    iVar2 = -iVar2 - (uint)bVar8;
  }
  lVar9 = CONCAT44(iVar2,iVar1);
  if ((iVar2 == 0 && iVar1 == 0) && (param_1[0xc] == 0)) {
    local_28 = param_3;
    local_24 = param_4;
    if ((iVar4 == 8) && ((int)((uint)*(byte *)(param_1 + 0xe) << 0x1c) < 0)) {
      *(undefined1 *)(iVar6 + 0x3b) = 0x30;
      iVar5 = 0x3b;
    }
  }
  else {
    local_28 = CONCAT31((int3)((uint)param_3 >> 8),(char)param_2);
    do {
      iVar1 = iVar5;
      uVar7 = (undefined4)((ulonglong)lVar9 >> 0x20);
      FUN_08019bf4((int)lVar9,uVar7,iVar4,0);
      cVar3 = (char)(extraout_r2 + 0x30U);
      local_24 = iVar1 + -1;
      if (0x39 < (extraout_r2 + 0x30U & 0xff)) {
        cVar3 = cVar3 + (char)param_2 + -0x51;
      }
      *(char *)(iVar6 + local_24) = cVar3;
      lVar9 = FUN_08019bf4((int)lVar9,uVar7,iVar4,0);
      iVar5 = local_24;
    } while ((lVar9 != 0) && ((uint)param_1[3] < (uint)(iVar6 + local_24)));
    if ((iVar4 == 8) &&
       (((int)((uint)*(byte *)(param_1 + 0xe) << 0x1c) < 0 && (*(char *)(iVar6 + local_24) != '0')))
       ) {
      iVar5 = iVar1 + -2;
      *(undefined1 *)(iVar6 + iVar5) = 0x30;
    }
  }
  iVar1 = 0x3c - iVar5;
  iVar4 = param_1[0xc];
  param_1[6] = iVar1;
  param_1[3] = iVar6 + iVar5;
  if (iVar1 < iVar4) {
    *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) & 0xffef;
    param_1[8] = iVar4 - iVar1;
    return CONCAT44(local_24,local_28);
  }
  if ((iVar4 < 0) && ((*(byte *)(param_1 + 0xe) & 0x14) == 0x10)) {
    iVar1 = ((param_1[0xd] - param_1[5]) - param_1[8]) - iVar1;
    if (0 < iVar1) {
      param_1[8] = iVar1;
    }
  }
  return CONCAT44(local_24,local_28);
}



/* ===== FUN_0802258e @ 0802258e ===== */

undefined8 FUN_0802258e(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar3 = CONCAT44(param_2,param_1);
  uVar1 = 0;
  uVar2 = DAT_080225e0;
  for (; param_3 != 0; param_3 = param_3 >> 1) {
    if (param_3 << 0x1f < 0) {
      uVar3 = FUN_0802d748((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),uVar1,uVar2);
    }
    uVar4 = FUN_0802d748(uVar1,uVar2,uVar1,uVar2);
    uVar2 = (undefined4)((ulonglong)uVar4 >> 0x20);
    uVar1 = (undefined4)uVar4;
  }
  return uVar3;
}



/* ===== FUN_080225e4 @ 080225e4 ===== */

longlong FUN_080225e4(code *param_1,int param_2,undefined1 *param_3,uint param_4)

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



/* ===== FUN_08022628 @ 08022628 ===== */

undefined4 * FUN_08022628(undefined4 *param_1)

{
  FUN_0801d688();
  *param_1 = DAT_08022638;
  return param_1;
}



/* ===== FUN_0802263c @ 0802263c ===== */

undefined4 * FUN_0802263c(undefined4 *param_1)

{
  FUN_0801d688();
  *param_1 = DAT_0802264c;
  return param_1;
}



/* ===== FUN_08022650 @ 08022650 ===== */

undefined4 * FUN_08022650(undefined4 *param_1)

{
  FUN_0801d688();
  *param_1 = DAT_08022660;
  return param_1;
}



/* ===== FUN_08022664 @ 08022664 ===== */

undefined4 * FUN_08022664(undefined4 *param_1)

{
  FUN_0801d688();
  *param_1 = DAT_08022674;
  return param_1;
}



/* ===== FUN_08022678 @ 08022678 ===== */

undefined4 * FUN_08022678(undefined4 *param_1)

{
  FUN_0801d688();
  *param_1 = DAT_08022688;
  return param_1;
}



/* ===== FUN_0802268c @ 0802268c ===== */

undefined4 * FUN_0802268c(undefined4 *param_1)

{
  FUN_0801d688();
  *param_1 = DAT_0802269c;
  return param_1;
}



/* ===== FUN_080226a0 @ 080226a0 ===== */

undefined4 * FUN_080226a0(undefined4 *param_1)

{
  FUN_0801d688();
  *param_1 = DAT_080226b0;
  return param_1;
}



/* ===== FUN_08022718 @ 08022718 ===== */

void FUN_08022718(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0802b5e0(DAT_08022a00,0x30,param_2,param_3,1);
  return;
}



/* ===== FUN_0802272c @ 0802272c ===== */

void FUN_0802272c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0802b51e(DAT_08022a00,0x30,param_2,param_3,1);
  return;
}



/* ===== FUN_08022740 @ 08022740 ===== */

uint FUN_08022740(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

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
  
  uVar2 = DAT_08022a00;
  local_2c = param_3;
  uStack_28 = param_4;
  uVar4 = FUN_0802b5e0(DAT_08022a00,0x30,0x25,&local_2c,1);
  local_2c = local_2c & 0xffffff07 | 0xc4;
  uVar5 = FUN_0802b51e(uVar2,0x30,0x25,&local_2c,1);
  uVar3 = FUN_0802b5e0(uVar2,0x30,0x20,&local_2c,1);
  local_2c._1_3_ = CONCAT21(local_2c._2_2_,uVar3);
  local_2c._0_1_ = 0x60;
  uVar6 = FUN_0802b51e(uVar2,0x30,0x20,&local_2c,1);
  uVar7 = FUN_0802b5e0(uVar2,0x30,0x30,&local_2c,1);
  local_2c = CONCAT31(local_2c._1_3_,(undefined1)local_2c) | 0xe0;
  uVar8 = FUN_0802b51e(uVar2,0x30,0x30,&local_2c,1);
  uVar9 = FUN_0802b5e0(uVar2,0x30,0x3f,&local_2c,1);
  local_2c = local_2c | 0x21;
  uVar10 = FUN_0802b51e(uVar2,0x30,0x3f,&local_2c,1);
  uVar11 = FUN_0802b5e0(uVar2,0x30,0x23,&local_2c,1);
  local_2c = local_2c | 0x80;
  uVar12 = FUN_0802b51e(uVar2,0x30,0x23,&local_2c,1);
  uVar1 = local_2c >> 8;
  uVar13 = FUN_0802b5e0(uVar2,0x30,0x23,&local_2c,1);
  return uVar13 | uVar11 | uVar10 | uVar9 | uVar4 | uVar5 | uVar1 & 0xff | uVar6 | uVar7 | uVar8 |
                  uVar12;
}



/* ===== FUN_08022862 @ 08022862 ===== */

uint FUN_08022862(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint local_1c;
  undefined4 uStack_18;
  
  puVar2 = DAT_08022a04;
  puVar1 = DAT_08022a00;
  *(undefined1 *)(param_1 + 5) = 0;
  *puVar2 = *puVar2 | 0x800000;
  uVar3 = *puVar2;
  uVar4 = *puVar1;
  *puVar1 = uVar4 | 1;
  local_1c = param_3;
  uStack_18 = param_4;
  uVar4 = FUN_08022718(param_1,0xf,&local_1c,uVar4 | 1,uVar3 & 0x800000);
  uVar3 = uVar4;
  if (uVar4 == 0) {
    uVar3 = local_1c & 0xff;
  }
  if (uVar4 == 0 && uVar3 == 0x44) {
    local_1c = CONCAT31(local_1c._1_3_,0x40);
    uVar4 = FUN_0802272c(param_1,0x21,&local_1c);
    uVar3 = 0;
    if (uVar4 == 0) {
      do {
        uVar4 = FUN_0802b5e0(puVar1,0x30,0x21,&local_1c,1);
        uVar3 = uVar3 | uVar4;
        uVar4 = uVar3;
      } while ((int)(local_1c << 0x19) < 0);
    }
    if (uVar4 == 0) {
      uVar4 = FUN_08022740(param_1);
    }
  }
  *puVar2 = *puVar2 & 0xff7fffff;
  return ~-(uint)(uVar4 == 0) >> 0x1f;
}



/* ===== FUN_08022942 @ 08022942 ===== */

void FUN_08022942(void)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  iVar1 = DAT_08022a0c;
  if (*(char *)(DAT_08022a0c + 4) == '\0') {
    iVar3 = FUN_08022862(DAT_08022a0c);
    bVar2 = (byte)(-(uint)(iVar3 == 0) >> 0x1f);
  }
  else {
    bVar2 = 1;
  }
  *(byte *)(iVar1 + 4) = bVar2;
  return;
}



/* ===== FUN_0802295e @ 0802295e ===== */

ulonglong FUN_0802295e(void)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint in_r3;
  uint local_14;
  
  if (*(char *)(DAT_08022a0c + 4) == '\0') {
    return (ulonglong)DAT_08022a0c;
  }
  *(undefined1 *)(DAT_08022a0c + 4) = 0;
  puVar2 = DAT_08022a04;
  puVar1 = DAT_08022a00;
  local_14 = in_r3 & 0xffffff00;
  *DAT_08022a04 = *DAT_08022a04 | 0x800000;
  iVar3 = FUN_0802b51e(puVar1,0x30,0x20,&local_14);
  *puVar1 = *puVar1 & 0xfffffffe;
  *puVar2 = *puVar2 & 0xff7fffff;
  *DAT_08022a08 = *DAT_08022a08 & 0xfffffffe;
  return CONCAT44(1,~-(uint)(iVar3 == 0) >> 0x1f);
}



/* ===== FUN_08022978 @ 08022978 ===== */

void FUN_08022978(void)

{
  return;
}



/* ===== FUN_0802298c @ 0802298c ===== */

undefined8 FUN_0802298c(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint *puVar1;
  int iVar2;
  int local_14;
  
  iVar2 = DAT_08022a0c;
  puVar1 = DAT_08022a04;
  if (*(char *)(DAT_08022a0c + 5) != '\0') {
    if (*DAT_08022a14 == '\0') {
      *DAT_08022a04 = *DAT_08022a04 | 0x800000;
      local_14 = param_4;
      FUN_0802b5e0(DAT_08022a00,0x30,0x3a,&local_14);
      *puVar1 = *puVar1 & 0xff7fffff;
      if ((local_14 << 0x19 < 0) || (*(char *)(iVar2 + 5) == '\x02')) {
        if (local_14 << 0x1e < 0) {
          FUN_08015e9e();
        }
        else if (local_14 << 0x1f < 0) {
          FUN_08015e8a();
        }
      }
      *(undefined1 *)(iVar2 + 5) = 0;
      return CONCAT44(local_14,1);
    }
    *(undefined1 *)(DAT_08022a0c + 5) = 2;
  }
  return CONCAT44(param_4,param_3);
}



/* ===== FUN_08022a56 @ 08022a56 ===== */

undefined4 FUN_08022a56(void)

{
  return DAT_080236ac;
}



/* ===== FUN_08022a5c @ 08022a5c ===== */

void FUN_08022a5c(undefined1 *param_1)

{
  *(undefined2 *)(param_1 + 0x10) = 0x800;
  *(undefined **)(param_1 + 0xc) = &DAT_44800000;
  param_1[1] = 0;
  *param_1 = 0;
  param_1[4] = 1;
  param_1[3] = 1;
  param_1[2] = 1;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}



/* ===== FUN_08022a84 @ 08022a84 ===== */

undefined4 FUN_08022a84(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  float fVar3;
  
  fVar3 = DAT_08022d54 - (*(float *)(param_1 + 0xc) + DAT_08022d4c) * DAT_08022d50;
  *(float *)(param_1 + 0x14) = DAT_08022d4c;
  FUN_0802d8fc(param_1,(int)(short)(int)fVar3);
  FUN_0802d910();
  FUN_0802d930(param_1,0);
  FUN_0802d978(param_1,0);
  *(undefined1 *)(param_1 + 2) = 1;
  puVar1 = DAT_080236b0;
  *(undefined1 *)(param_1 + 3) = 1;
  *puVar1 = 0x400;
  FUN_0802d9e8(param_1);
  puVar1[4] = 0x200;
  FUN_0802d9f0(0);
  puVar2 = DAT_080236b4;
  *(undefined1 *)(param_1 + 5) = 0;
  *puVar2 = 0x80;
  *(undefined1 *)(param_1 + 6) = 0;
  *DAT_080236b8 = 0x40;
  *(undefined1 *)(param_1 + 7) = 0;
  *puVar1 = 0x8000;
  return param_4;
}



/* ===== FUN_08022b62 @ 08022b62 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08022b62(float param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  byte bVar3;
  undefined4 unaff_r7;
  bool bVar4;
  
  bVar4 = *(char *)(param_2 + 2) == '\0';
  cVar1 = '\0';
  if (!bVar4) {
    cVar1 = *(char *)(param_2 + 4);
  }
  if (bVar4 || cVar1 == '\0') {
    bVar3 = 0;
  }
  else {
    bVar3 = (byte)~(byte)(-(uint)(*(char *)(param_2 + 1) == '\0') >> 0x18) >> 7;
  }
  *(float *)(param_2 + 0x14) = param_1;
  if (bVar3 != 0) {
    param_1 = param_1 + *(float *)(param_2 + 0xc);
  }
  uVar2 = FUN_0802d8fc(param_2,(int)(short)(int)(_UNK_0802da44 - param_1 * _UNK_0802da40));
  FUN_0802d910(uVar2,unaff_r7);
  return;
}



/* ===== FUN_08022b80 @ 08022b80 ===== */

float FUN_08022b80(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x14);
  if (*(char *)(param_1 + 3) != *(char *)(param_1 + 2)) {
    if (*(char *)(param_1 + 3) == '\0') {
      return fVar1 + *(float *)(param_1 + 0xc);
    }
    fVar1 = fVar1 - *(float *)(param_1 + 0xc);
  }
  return fVar1;
}



/* ===== FUN_08022b9e @ 08022b9e ===== */

undefined8 FUN_08022b9e(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_08022a5c();
  FUN_0802da48(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  FUN_0802da74(param_1 + 0x4c);
  *(undefined1 *)(param_1 + 0x19dc) = 0;
  *(undefined1 *)(param_1 + 0x18) = 0;
  *(undefined1 *)(param_1 + 0x1a) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined1 *)(param_1 + 0x1b) = 1;
  *(undefined1 *)(param_1 + 0x28) = 1;
  return CONCAT44(param_4,param_1);
}



/* ===== FUN_08022bdc @ 08022bdc ===== */

undefined4 FUN_08022bdc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0802dac4(param_1 + 0x4c);
  disableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  *(undefined4 *)(param_1 + 0x38) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x34) = 2;
  *(undefined4 *)(param_1 + 0x30) = DAT_080238a0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  enableIRQinterrupts();
  FUN_08022a84(param_1);
  *(undefined1 *)(param_1 + 0x18) = 0;
  *(undefined1 *)(param_1 + 0x1b) = 1;
  *(undefined1 *)(param_1 + 0x1a) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined1 *)(param_1 + 0x28) = 1;
  *(undefined1 *)(param_1 + 0x19f0) = 0;
  return param_4;
}



/* ===== FUN_08022c3e @ 08022c3e ===== */

void FUN_08022c3e(int param_1)

{
  *(undefined1 *)(*(int *)(param_1 + 0x5c) + 4) = *(undefined1 *)(param_1 + 5);
  return;
}



/* ===== FUN_08022c46 @ 08022c46 ===== */

undefined4 FUN_08022c46(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x5c);
  *(undefined1 *)(iVar3 + 5) = 1;
  uVar2 = FUN_0802defe();
  *(undefined4 *)(iVar3 + 0x14) = uVar2;
  uVar2 = FUN_08024846();
  *(undefined4 *)(iVar3 + 8) = uVar2;
  *(short *)(iVar3 + 0xc) = (short)(int)(*(float *)(param_1 + 0x14) + 0.5);
  uVar1 = FUN_080175e8(3);
  *(undefined2 *)(iVar3 + 0xe) = uVar1;
  return param_4;
}



/* ===== FUN_08022c56 @ 08022c56 ===== */

undefined4 FUN_08022c56(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x5c);
  *(undefined1 *)(iVar3 + 0x19) = 1;
  uVar2 = FUN_0802defe();
  *(undefined4 *)(iVar3 + 0x28) = uVar2;
  uVar2 = FUN_08024846();
  *(undefined4 *)(iVar3 + 0x1c) = uVar2;
  *(short *)(iVar3 + 0x20) = (short)(int)(*(float *)(param_1 + 0x14) + 0.5);
  uVar1 = FUN_080175e8(3);
  *(undefined2 *)(iVar3 + 0x22) = uVar1;
  return param_4;
}



/* ===== FUN_08022cb8 @ 08022cb8 ===== */

undefined4 FUN_08022cb8(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  
  iVar4 = *(int *)(param_1 + 0x5c);
  *(char *)(iVar4 + 5) = (char)param_2;
  *(char *)(iVar4 + 4) = (char)param_3;
  if (param_2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0802e334();
  }
  *(undefined4 *)(iVar4 + 0x14) = uVar3;
  if (param_2 == 3) {
    if (param_3 == 0) {
      iVar2 = param_1 + 0x44;
    }
    else {
      iVar2 = param_1 + 0x48;
    }
    FUN_0802e378(*(undefined4 *)(param_1 + 0xc),iVar2,uVar3);
  }
  uVar5 = FUN_08024846();
  uVar6 = (uint)(*(float *)(param_1 + 0x14) + 0.5);
  if (param_2 == 2) {
    uVar3 = FUN_0802e3b8(uVar5,param_1 + 0x44,param_3,DAT_08023608,uVar6 & 0xffff,uVar3);
    *(undefined4 *)(iVar4 + 0x10) = uVar3;
  }
  *(undefined4 *)(iVar4 + 8) = uVar5;
  *(short *)(iVar4 + 0xc) = (short)uVar6;
  uVar1 = FUN_080175e8(3);
  *(undefined2 *)(iVar4 + 0xe) = uVar1;
  return param_4;
}



/* ===== FUN_08022d62 @ 08022d62 ===== */

void FUN_08022d62(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  float fVar5;
  
  iVar3 = *(int *)(param_1 + 0x5c);
  *(undefined1 *)(iVar3 + 0x19) = 2;
  *(char *)(iVar3 + 0x18) = (char)param_2;
  uVar2 = FUN_0802e334();
  *(undefined4 *)(iVar3 + 0x28) = uVar2;
  uVar4 = FUN_08024846();
  fVar5 = (float)FUN_08022b80(param_1);
  uVar2 = FUN_0802e3b8(uVar4,param_1 + 0x44,param_2,DAT_08023608,(int)(fVar5 + 0.5) & 0xffff,uVar2);
  *(undefined4 *)(iVar3 + 0x24) = uVar2;
  *(undefined4 *)(iVar3 + 0x1c) = uVar4;
  *(short *)(iVar3 + 0x20) = (short)(int)(fVar5 + 0.5);
  uVar1 = FUN_080175e8(3);
  *(undefined2 *)(iVar3 + 0x22) = uVar1;
  return;
}



/* ===== FUN_08022dd4 @ 08022dd4 ===== */

void FUN_08022dd4(int param_1)

{
  int iVar1;
  
  if (*(code **)(param_1 + 0x1c) != (code *)0x0) {
    iVar1 = *(int *)(param_1 + 0x20) + -1;
                    /* WARNING: Could not recover jumptable at 0x08022de2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    if (iVar1 < 1) {
      (**(code **)(param_1 + 0x1c))();
      return;
    }
    *(int *)(param_1 + 0x20) = iVar1;
  }
  return;
}



/* ===== FUN_08022e0a @ 08022e0a ===== */

void FUN_08022e0a(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_08023a34;
  *(undefined1 *)(param_1 + 3) = 0;
  *puVar1 = 0x400;
  FUN_0802e454(param_1,0);
  puVar1 = DAT_080236b8;
  *(undefined1 *)(param_1 + 6) = 0;
  *puVar1 = 0x40;
  return;
}



/* ===== FUN_08022e32 @ 08022e32 ===== */

undefined4 FUN_08022e32(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  FUN_0802e4ac(param_1,0);
  puVar1 = DAT_080236b0;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  puVar1[4] = 0x400;
  FUN_0802d9e8(param_1);
  puVar2 = DAT_080236b8;
  *(undefined1 *)(param_1 + 6) = 0;
  *puVar2 = 0x40;
  *(undefined1 *)(param_1 + 7) = 0;
  *puVar1 = 0x8000;
  return param_4;
}



/* ===== FUN_08022e6a @ 08022e6a ===== */

undefined4 FUN_08022e6a(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_080236b0;
  *(undefined1 *)(param_1 + 7) = 0;
  *puVar1 = 0x8000;
  FUN_0802d9f0(1);
  FUN_0802e454(param_1,1);
  *(undefined1 *)(param_1 + 3) = 1;
  *puVar1 = 0x400;
  *(undefined1 *)(param_1 + 6) = 1;
  *DAT_08023b94 = 0x40;
  return param_4;
}



/* ===== FUN_08022ea0 @ 08022ea0 ===== */

void FUN_08022ea0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_080236b0;
  *(undefined1 *)(param_1 + 7) = 0;
  *puVar1 = 0x8000;
  FUN_0802d9e8(param_1,1);
  *(undefined1 *)(param_1 + 2) = 1;
  *(undefined1 *)(param_1 + 3) = 1;
  *puVar1 = 0x400;
  FUN_0802e4ac(param_1,1,param_4);
  return;
}



/* ===== FUN_08022ed2 @ 08022ed2 ===== */

void FUN_08022ed2(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *(int *)(param_1 + 0x5c);
  *(undefined1 *)(iVar2 + 5) = 0;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  uVar3 = FUN_08024846();
  *(undefined4 *)(iVar2 + 8) = uVar3;
  *(short *)(iVar2 + 0xc) = (short)(int)(*(float *)(param_1 + 0x14) + 0.5);
  uVar1 = FUN_080175e8(3);
  *(undefined2 *)(iVar2 + 0xe) = uVar1;
  *(undefined4 *)(param_1 + 0x1c) = 0x8022f15;
  *(undefined4 *)(param_1 + 0x20) = 0x100;
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 0x100;
  return;
}



/* ===== FUN_08022f14 @ 08022f14 ===== */

void FUN_08022f14(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_0802e4b4();
  iVar2 = 0;
  switch(uVar1) {
  case 0:
    *(undefined1 **)(param_1 + 0x1c) = &LAB_08022fc0_1;
    iVar2 = 0x200 - *(int *)(param_1 + 0x24);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    *(int *)(param_1 + 0x20) = iVar2;
    *(int *)(param_1 + 0x24) = iVar2 + *(int *)(param_1 + 0x24);
    return;
  case 1:
  case 4:
    iVar2 = 0xe6;
    break;
  case 2:
  case 3:
    iVar2 = 0xcd;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0x8022f49;
  *(int *)(param_1 + 0x20) = iVar2;
  *(int *)(param_1 + 0x24) = iVar2 + *(int *)(param_1 + 0x24);
  return;
}



/* ===== FUN_08022f48 @ 08022f48 ===== */

void FUN_08022f48(int param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  bVar1 = *(byte *)(param_1 + 0x1a);
  if (bVar1 == 1) {
    FUN_0802e4ac(param_1,0);
    puVar2 = DAT_08023a34;
    *(undefined1 *)(param_1 + 2) = 0;
    *(undefined1 *)(param_1 + 3) = 0;
    *puVar2 = 0x400;
    FUN_0802d9e8(param_1,0);
  }
  else if (bVar1 != 0) {
    if (bVar1 == 3) {
      FUN_0802e4ac(param_1,0);
      *(undefined1 *)(param_1 + 2) = 0;
      *(undefined1 *)(param_1 + 3) = 0;
      *DAT_08023a34 = 0x400;
    }
    else if (2 < bVar1) goto LAB_08022df4;
    uVar3 = FUN_0802e554(param_1);
    FUN_0802e578(param_1,uVar3);
    puVar2 = DAT_08023b94;
    *(undefined1 *)(param_1 + 6) = 1;
    *puVar2 = 0x40;
    FUN_0802d9f0(1);
  }
LAB_08022df4:
  *(undefined1 **)(param_1 + 0x1c) = &LAB_08022fc0_1;
  iVar4 = 0x200 - *(int *)(param_1 + 0x24);
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  *(int *)(param_1 + 0x20) = iVar4;
  *(int *)(param_1 + 0x24) = iVar4 + *(int *)(param_1 + 0x24);
  return;
}



/* ===== FUN_08023018 @ 08023018 ===== */

void FUN_08023018(int param_1)

{
  FUN_0802dd94();
  *(undefined4 *)(param_1 + 0x1c) = 0x8023039;
  *(undefined4 *)(param_1 + 0x20) = 0x1cd;
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 0x1cd;
  return;
}



/* ===== FUN_08023038 @ 08023038 ===== */

void FUN_08023038(int param_1)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  
  FUN_0802de04();
  FUN_08022c46(param_1);
  iVar1 = FUN_0802e5a4(*(undefined4 *)(param_1 + 0x5c));
  if (*(int *)(iVar1 + 0xc) == 0) {
    fVar2 = DAT_08023308;
  }
  else {
    fVar2 = (float)VectorUnsignedToFloat(*(int *)(iVar1 + 0xc),(byte)(in_fpscr >> 0x16) & 3);
    fVar2 = DAT_0802330c / fVar2;
    if (fVar2 < DAT_08023310) {
      fVar2 = 2.0;
    }
  }
  *(undefined1 *)(param_1 + 0x19f0) = 1;
  FUN_0802debe(fVar2);
  FUN_08022e6a(param_1);
  *(undefined4 *)(param_1 + 0x1c) = 0x8023099;
  *(undefined4 *)(param_1 + 0x20) = 3;
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 3;
  return;
}



/* ===== FUN_08023098 @ 08023098 ===== */

void FUN_08023098(int param_1)

{
  FUN_0802d9f0(0);
  FUN_0802e2aa();
  *(undefined **)(param_1 + 0x1c) = &DAT_080230b5;
  *(undefined4 *)(param_1 + 0x20) = 0x2e;
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 0x2e;
  return;
}



/* ===== FUN_080231b8 @ 080231b8 ===== */

void FUN_080231b8(int param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  int iVar3;
  
  puVar1 = DAT_08023b94;
  if (*(char *)(param_1 + 5) == '\0') {
    if (*(char *)(param_1 + 0x28) != '\0') {
      FUN_0802e2aa();
    }
    iVar3 = 0x100;
    pcVar2 = (code *)&DAT_08023215;
  }
  else {
    *(undefined1 *)(param_1 + 6) = 1;
    *puVar1 = 0x40;
    FUN_0802d9f0(1);
    iVar3 = 0x33;
    pcVar2 = FUN_080231f4 + 1;
  }
  *(code **)(param_1 + 0x1c) = pcVar2;
  *(int *)(param_1 + 0x20) = iVar3;
  *(int *)(param_1 + 0x24) = iVar3 + *(int *)(param_1 + 0x24);
  return;
}



/* ===== FUN_080231f4 @ 080231f4 ===== */

void FUN_080231f4(int param_1)

{
  FUN_0802d9f0(0);
  FUN_0802e2aa();
  *(undefined **)(param_1 + 0x1c) = &DAT_08023215;
  *(undefined4 *)(param_1 + 0x20) = 0x100;
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 0x100;
  return;
}



/* ===== FUN_08023314 @ 08023314 ===== */

void FUN_08023314(int param_1)

{
  FUN_0802dd94();
  *(undefined4 *)(param_1 + 0x1c) = 0x8023331;
  *(undefined4 *)(param_1 + 0x20) = 0x66;
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 0x66;
  return;
}



/* ===== FUN_08023330 @ 08023330 ===== */

void FUN_08023330(int param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  
  FUN_0802de04();
  FUN_08022c56(param_1);
  if (*(char *)(param_1 + 0x3c) == '\x01') {
    if (*(char *)(*(int *)(param_1 + 0x5c) + 0x19) == '\x01') {
      iVar3 = *(int *)(*(int *)(param_1 + 0x5c) + 0x28);
      cVar2 = '\x02';
      if ((iVar3 == 0) || ((uint)(*(int *)(iVar3 + 0x10) * 0x14) < *(uint *)(iVar3 + 0xc)))
      goto LAB_08023370;
      goto LAB_0802336a;
    }
  }
  else if (*(char *)(param_1 + 0x3c) == '\x02') {
LAB_0802336a:
    cVar2 = '\x01';
    goto LAB_08023370;
  }
  cVar2 = '\x02';
LAB_08023370:
  *(char *)(param_1 + 0x1a) = cVar2;
  if (cVar2 == '\x01') {
    FUN_08022e32();
  }
  else {
    FUN_08022ea0(param_1);
    iVar3 = FUN_0802e554(param_1);
    if (iVar3 == 0) {
      FUN_0802d9f0(1);
      puVar1 = DAT_08023b94;
      *(undefined1 *)(param_1 + 6) = 1;
      *puVar1 = 0x40;
    }
  }
  *(undefined4 *)(param_1 + 0x1c) = 0x80233a9;
  iVar3 = 0x200 - *(int *)(param_1 + 0x24);
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  *(int *)(param_1 + 0x20) = iVar3;
  *(int *)(param_1 + 0x24) = iVar3 + *(int *)(param_1 + 0x24);
  return;
}



/* ===== FUN_080233a8 @ 080233a8 ===== */

void FUN_080233a8(int param_1)

{
  char cVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  
  puVar3 = DAT_08023e3c;
  cVar1 = *(char *)(param_1 + 0x19);
  cVar2 = *(char *)(param_1 + 0x1b);
  switch(*(undefined1 *)(param_1 + 0x1a)) {
  case 0:
    if (cVar1 == '\0') {
      FUN_0802e2cc();
      FUN_08022cb8(param_1,2,0);
    }
    puVar3 = DAT_08023e3c;
    *(undefined1 *)(param_1 + 5) = 1;
    *puVar3 = 0x80;
    puVar3 = DAT_08023b94;
    *(undefined1 *)(param_1 + 6) = 0;
    puVar3[4] = 0x40;
    break;
  case 2:
    if (cVar1 == '\0') {
      if (cVar2 != '\0') {
        FUN_0802e2cc();
      }
      iVar7 = *(int *)(param_1 + 0x5c);
      *(undefined1 *)(iVar7 + 5) = 2;
      *(undefined1 *)(iVar7 + 4) = 0;
      uVar6 = FUN_0802e334();
      *(undefined4 *)(iVar7 + 0x14) = uVar6;
      uVar8 = FUN_08024846();
      uVar9 = (uint)(*(float *)(param_1 + 0x14) + 0.5);
      uVar6 = FUN_0802e3b8(uVar8,param_1 + 0x44,0,DAT_08023608,uVar9 & 0xffff,uVar6);
      *(undefined4 *)(iVar7 + 0x10) = uVar6;
      *(undefined4 *)(iVar7 + 8) = uVar8;
      *(short *)(iVar7 + 0xc) = (short)uVar9;
      uVar5 = FUN_080175e8(3);
      *(undefined2 *)(iVar7 + 0xe) = uVar5;
    }
    else if (cVar2 == '\0') {
      FUN_0802d9f0(0);
    }
    FUN_0802e578(param_1,cVar2);
    break;
  case 3:
    FUN_0802e4ac(param_1,0);
    *(undefined1 *)(param_1 + 2) = 0;
    *(undefined1 *)(param_1 + 3) = 0;
    *DAT_08023a34 = 0x400;
    break;
  case 4:
    if (cVar1 == '\0') {
      FUN_0802e2cc();
      iVar7 = *(int *)(param_1 + 0x5c);
      *(undefined1 *)(iVar7 + 5) = 2;
      *(undefined1 *)(iVar7 + 4) = 0;
      uVar6 = FUN_0802e334();
      *(undefined4 *)(iVar7 + 0x14) = uVar6;
      uVar8 = FUN_08024846();
      uVar9 = (uint)(*(float *)(param_1 + 0x14) + 0.5);
      uVar6 = FUN_0802e3b8(uVar8,param_1 + 0x44,0,DAT_08023608,uVar9 & 0xffff,uVar6);
      *(undefined4 *)(iVar7 + 0x10) = uVar6;
      *(undefined4 *)(iVar7 + 8) = uVar8;
      *(short *)(iVar7 + 0xc) = (short)uVar9;
      uVar5 = FUN_080175e8(3);
      *(undefined2 *)(iVar7 + 0xe) = uVar5;
    }
    else {
      *(undefined1 *)(param_1 + 5) = 0;
      puVar3[4] = 0x80;
    }
    FUN_0802e4ac(param_1,0);
    *(undefined1 *)(param_1 + 2) = 0;
    *(undefined1 *)(param_1 + 3) = 0;
    puVar3 = DAT_08023a34;
    *DAT_08023a34 = 0x400;
    puVar4 = DAT_08023b94;
    *(undefined1 *)(param_1 + 6) = 1;
    *puVar4 = 0x40;
    *(undefined1 *)(param_1 + 7) = 1;
    *puVar3 = 0x8000;
  }
  if (*(undefined1 **)(param_1 + 0x5c) != (undefined1 *)0x0) {
    **(undefined1 **)(param_1 + 0x5c) = 1;
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}



/* ===== FUN_0802352e @ 0802352e ===== */

void FUN_0802352e(int param_1)

{
  if (*(char *)(param_1 + 0x28) != '\0') {
    FUN_0802e2aa();
  }
  *(undefined **)(param_1 + 0x1c) = &UNK_08023545;
  *(undefined4 *)(param_1 + 0x20) = 0x100;
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 0x100;
  return;
}



/* ===== FUN_080236bc @ 080236bc ===== */

void FUN_080236bc(int param_1)

{
  if (*(char *)(param_1 + 0x28) != '\0') {
    FUN_0802e2aa();
  }
  *(undefined4 *)(param_1 + 0x1c) = 0x80236e1;
  *(undefined4 *)(param_1 + 0x20) = 0x100;
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 0x100;
  return;
}



/* ===== FUN_080236e0 @ 080236e0 ===== */

void FUN_080236e0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0802e4b4();
  if (iVar1 - 1U < 3) {
    *(undefined **)(param_1 + 0x1c) = &DAT_08023711;
    *(undefined4 *)(param_1 + 0x20) = 0xcd;
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 0xcd;
    return;
  }
  if (iVar1 == 4) {
    *(undefined1 *)(param_1 + 0x28) = 0;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0x80237d9;
  iVar1 = 0x200 - *(int *)(param_1 + 0x24);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  *(int *)(param_1 + 0x20) = iVar1;
  *(int *)(param_1 + 0x24) = iVar1 + *(int *)(param_1 + 0x24);
  return;
}



/* ===== FUN_080237d8 @ 080237d8 ===== */

void FUN_080237d8(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  cVar1 = *(char *)(param_1 + 0x1a);
  if (cVar1 == '\0') {
    FUN_0802e2cc();
    iVar6 = *(int *)(param_1 + 0x5c);
    *(undefined1 *)(iVar6 + 5) = 4;
    uVar5 = FUN_0802e334();
    *(undefined4 *)(iVar6 + 0x14) = uVar5;
    uVar5 = FUN_08024846();
    *(undefined4 *)(iVar6 + 8) = uVar5;
    *(short *)(iVar6 + 0xc) = (short)(int)(*(float *)(param_1 + 0x14) + 0.5);
    uVar4 = FUN_080175e8(3);
    *(undefined2 *)(iVar6 + 0xe) = uVar4;
    *(undefined1 *)(param_1 + 2) = 1;
    *(undefined1 *)(param_1 + 3) = 1;
    puVar3 = DAT_08023e44;
    *DAT_08023e44 = 0x400;
    FUN_0802e4ac(param_1);
    puVar2 = DAT_08023e38;
    *(undefined1 *)(param_1 + 6) = 0;
    *puVar2 = 0x40;
    *(undefined1 *)(param_1 + 7) = 0;
    *puVar3 = 0x8000;
    puVar2 = DAT_08023e3c;
    *(undefined1 *)(param_1 + 5) = 1;
    *puVar2 = 0x80;
  }
  else if (cVar1 == '\x02') {
    FUN_0802d9f0(0);
  }
  else if (cVar1 == '\x04') {
    iVar6 = *(int *)(param_1 + 0x5c);
    *(undefined1 *)(iVar6 + 5) = 4;
    uVar5 = FUN_0802e334();
    *(undefined4 *)(iVar6 + 0x14) = uVar5;
    uVar5 = FUN_08024846();
    *(undefined4 *)(iVar6 + 8) = uVar5;
    *(short *)(iVar6 + 0xc) = (short)(int)(*(float *)(param_1 + 0x14) + 0.5);
    uVar4 = FUN_080175e8(3);
    *(undefined2 *)(iVar6 + 0xe) = uVar4;
  }
  if (*(undefined1 **)(param_1 + 0x5c) != (undefined1 *)0x0) {
    **(undefined1 **)(param_1 + 0x5c) = 1;
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}



/* ===== FUN_080238a4 @ 080238a4 ===== */

undefined4 FUN_080238a4(undefined4 param_1)

{
  undefined4 unaff_r7;
  uint in_fpscr;
  undefined4 uVar1;
  
  disableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  FUN_08022a56();
  uVar1 = VectorSignedToFloat(param_1,(byte)(in_fpscr >> 0x16) & 3);
  FUN_08022b62(uVar1);
  enableIRQinterrupts();
  return unaff_r7;
}



/* ===== FUN_080238cc @ 080238cc ===== */

undefined4 FUN_080238cc(void)

{
  undefined4 unaff_r7;
  
  disableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  FUN_080238a4();
  enableIRQinterrupts();
  return unaff_r7;
}



/* ===== FUN_0802391c @ 0802391c ===== */

ulonglong FUN_0802391c(void)

{
  int iVar1;
  undefined4 unaff_r7;
  
  iVar1 = FUN_08022a56();
  return CONCAT44(unaff_r7,(int)(*(float *)(iVar1 + 0x14) + 0.5)) & 0xffffffff0000ffff;
}



/* ===== FUN_08023940 @ 08023940 ===== */

void FUN_08023940(undefined4 param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  undefined4 unaff_lr;
  
  iVar2 = FUN_08022a56();
  uVar1 = FUN_0802d8fc(iVar2,param_1,extraout_r2,extraout_r3,unaff_r4,unaff_lr);
  *(undefined2 *)(iVar2 + 8) = uVar1;
  if (*(char *)(iVar2 + 4) == '\0') {
    FUN_0802e760();
    return;
  }
  return;
}



/* ===== FUN_08023952 @ 08023952 ===== */

void FUN_08023952(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  undefined4 unaff_lr;
  
  if ((*(byte *)(DAT_08023e4c + 6) & 3) == 0) {
    return;
  }
  *DAT_08023e50 = (short)param_1;
  if (param_1 < 0) {
    param_1 = FUN_0802e1ae();
  }
  iVar2 = FUN_08022a56();
  uVar1 = FUN_0802d8fc(iVar2,(int)(short)param_1,extraout_r2,extraout_r3,unaff_r4,unaff_lr);
  *(undefined2 *)(iVar2 + 8) = uVar1;
  if (*(char *)(iVar2 + 4) == '\0') {
    FUN_0802e760();
    return;
  }
  return;
}



/* ===== FUN_080239a0 @ 080239a0 ===== */

undefined4 FUN_080239a0(uint param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar3;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 unaff_r7;
  uint in_fpscr;
  undefined4 uVar4;
  undefined4 uVar5;
  float fVar6;
  undefined8 unaff_d8;
  char cStackY_17;
  byte bStackY_15;
  
  bVar1 = (byte)(param_1 >> 0x1c);
  if (bVar1 == 0) {
    uVar5 = DAT_08023c18;
  }
  else {
    if (bVar1 == 2) {
      cStackY_17 = (char)(param_1 >> 8);
      fVar6 = (float)VectorSignedToFloat((int)cStackY_17,(byte)(in_fpscr >> 0x16) & 3);
      uVar5 = VectorUnsignedToFloat(param_1 & 0xff,(byte)(in_fpscr >> 0x16) & 3);
      FUN_08023a82(uVar5);
      puVar2 = DAT_08023e48;
      DAT_08023e48[1] =
           (float)DAT_08023e48[1] +
           ((float)DAT_08023e48[2] + fVar6 * (float)DAT_08023e48[3]) * fVar6;
      puVar2[2] = 0;
      puVar2[3] = 0;
      uVar5 = extraout_r2_00;
      uVar3 = extraout_r3_00;
      goto LAB_080238e0;
    }
    if (1 < bVar1) {
      return unaff_r7;
    }
    uVar5 = VectorUnsignedToFloat(param_1 & 0xff,(byte)(in_fpscr >> 0x16) & 3);
  }
  FUN_08023a82(uVar5);
  uVar5 = extraout_r2;
  uVar3 = extraout_r3;
LAB_080238e0:
  uVar4 = *DAT_08023e48;
  DAT_08023e48[0x1f] = param_1;
  puVar2 = DAT_08023e48;
  uVar5 = FUN_0801d24c(DAT_08023e48 + 1,2,uVar5,uVar3,unaff_d8);
  *puVar2 = uVar4;
  disableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  FUN_08022a56();
  uVar5 = FUN_08022b62(uVar5);
  enableIRQinterrupts();
  return uVar5;
}



/* ===== FUN_08023a38 @ 08023a38 ===== */

float FUN_08023a38(float param_1,float param_2,float *param_3)

{
  return *param_3 + (param_3[1] + param_1 * param_3[2]) * param_1 +
         (param_3[3] + (param_3[4] + param_1 * param_3[5]) * param_1 +
         (param_3[6] + (param_3[7] + param_1 * param_3[8]) * param_1) * param_2) * param_2;
}



/* ===== FUN_08023a82 @ 08023a82 ===== */

void FUN_08023a82(float param_1)

{
  int iVar1;
  undefined4 unaff_r7;
  
  iVar1 = DAT_08023e48;
  *(float *)(DAT_08023e48 + 4) =
       *(float *)(DAT_08023e48 + 0x10) +
       (*(float *)(DAT_08023e48 + 0x14) + param_1 * *(float *)(DAT_08023e48 + 0x18)) * param_1;
  *(float *)(iVar1 + 8) =
       *(float *)(iVar1 + 0x1c) +
       (*(float *)(iVar1 + 0x20) + param_1 * *(float *)(iVar1 + 0x24)) * param_1;
  *(float *)(iVar1 + 0xc) =
       *(float *)(iVar1 + 0x28) +
       (*(float *)(iVar1 + 0x2c) + param_1 * *(float *)(iVar1 + 0x30)) * param_1;
  iVar1 = FUN_08022a56();
  FUN_0802e5cc(param_1,iVar1 + 0x60,unaff_r7);
  return;
}



/* ===== FUN_08023af0 @ 08023af0 ===== */

longlong FUN_08023af0(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  
  iVar3 = DAT_08023e48;
  iVar2 = FUN_0801d27c(0x70,DAT_08023e48 + 0x10,9,param_1);
  if ((iVar2 == 0) || (iVar2 = FUN_0801d27c(0x74,iVar3 + 0x34,9,param_1), iVar2 == 0)) {
LAB_08023b78:
    FUN_080262f4(iVar3,DAT_08023e54,0x7c);
    iVar3 = FUN_08022a56();
    FUN_0802e5cc(DAT_08023c18,iVar3 + 0x60);
    return CONCAT44(param_4,1);
  }
  iVar2 = FUN_0801d27c(0x79,iVar3 + 0x58,9,param_1);
  if (iVar2 == 0) {
    iVar2 = FUN_0801d27c(0x78,iVar3 + 0x58,9,param_1);
    fVar1 = DAT_08023e34;
    if (iVar2 == 0) goto LAB_08023b78;
    pfVar4 = (float *)(iVar3 + 0x58);
    iVar3 = 3;
    do {
      *pfVar4 = *pfVar4 * fVar1;
      pfVar4[1] = pfVar4[1] * fVar1;
      pfVar4[2] = pfVar4[2] * fVar1;
      pfVar4 = pfVar4 + 3;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  FUN_08023a82(DAT_08023c18);
  return (ulonglong)param_4 << 0x20;
}



/* ===== FUN_08023c1c @ 08023c1c ===== */

int FUN_08023c1c(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_08022a56();
  disableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  enableIRQinterrupts();
  iVar2 = *(int *)(iVar1 + 0x34) * 4;
  if (param_2 < iVar2) {
    iVar2 = -1;
  }
  else {
    FUN_080262d4(param_1,*(undefined4 *)(iVar1 + 0x30),iVar2);
  }
  return iVar2;
}



/* ===== FUN_08023d06 @ 08023d06 ===== */

void FUN_08023d06(void)

{
  int iVar1;
  
  iVar1 = FUN_08022a56();
  *(undefined4 *)(iVar1 + 0x4c) = 0;
  disableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  *(undefined1 *)(*(int *)(iVar1 + 0x50) + *(int *)(iVar1 + 0x54) * 0x2c + 1) = 1;
  enableIRQinterrupts();
  disableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  *(undefined4 *)(iVar1 + 0x38) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x40) = 0;
  enableIRQinterrupts();
  return;
}



/* ===== FUN_08023d14 @ 08023d14 ===== */

void FUN_08023d14(void)

{
  int iVar1;
  undefined4 unaff_r7;
  
  iVar1 = FUN_08022a56();
  FUN_0802e744(iVar1 + 0x4c,unaff_r7);
  return;
}



/* ===== FUN_08023d24 @ 08023d24 ===== */

void FUN_08023d24(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_08022a56();
  FUN_0802d910(0);
  FUN_0802e760(0);
  puVar1 = DAT_08023e44;
  *DAT_08023e5c = 0x80;
  FUN_0802d9f0(0);
  *DAT_08023e38 = 0x40;
  puVar1[4] = 0x8000;
  puVar1[4] = 4;
  *puVar1 = 0x200;
  *puVar1 = 0x400;
  FUN_0802e454(uVar2,1);
  puVar1[4] = 0x200;
  puVar1[4] = 0x40;
  puVar1[4] = 1;
  return;
}



/* ===== FUN_08023d78 @ 08023d78 ===== */

undefined4 FUN_08023d78(void)

{
  undefined4 unaff_r7;
  
  disableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  FUN_08022a56();
  FUN_08022b62(DAT_08023e40);
  enableIRQinterrupts();
  return unaff_r7;
}



/* ===== FUN_08023d94 @ 08023d94 ===== */

void FUN_08023d94(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  FUN_08022a56();
  FUN_08022bdc();
  FUN_0802e28e();
  FUN_0802dcbc();
  piVar1 = DAT_0801b12c;
  iVar3 = DAT_0801b118;
  iVar2 = *(int *)(DAT_0801b118 + 0x18);
  *DAT_0801b12c = iVar2;
  piVar1[1] = iVar2 >> 0x1f;
  iVar3 = *(int *)(iVar3 + 0x30);
  piVar1[2] = iVar3;
  piVar1[3] = iVar3 >> 0x1f;
  return;
}



/* ===== FUN_08023dae @ 08023dae ===== */

void FUN_08023dae(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 extraout_r3;
  
  FUN_0802e292();
  FUN_0802dcda();
  FUN_0801b014();
  iVar3 = FUN_08022a56();
  *(undefined1 *)(iVar3 + 0x18) = 0;
  *(undefined1 *)(iVar3 + 0x1a) = 0;
  *(undefined1 *)(iVar3 + 0x1b) = 1;
  puVar1 = DAT_080236b0;
  *(undefined1 *)(iVar3 + 2) = 1;
  *(undefined1 *)(iVar3 + 3) = 1;
  *puVar1 = 0x400;
  FUN_0802d9e8(iVar3);
  FUN_0802d9f0(0);
  puVar2 = DAT_080236b8;
  *(undefined1 *)(iVar3 + 6) = 0;
  *puVar2 = 0x40;
  *(undefined1 *)(iVar3 + 7) = 1;
  puVar1[4] = 0x8000;
  FUN_0802d978(iVar3,0);
  puVar1[4] = 0x200;
  puVar1 = DAT_080236b4;
  *(undefined1 *)(iVar3 + 5) = 0;
  *puVar1 = 0x80;
  FUN_0802d930(iVar3,0,extraout_r3);
  return;
}



/* ===== thunk_FUN_0802dd36 @ 08023e60 ===== */

void thunk_FUN_0802dd36(void)

{
  char *pcVar1;
  undefined1 auStack_38 [6];
  undefined1 uStack_32;
  undefined1 uStack_31;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 uStack_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  pcVar1 = DAT_0802e200;
  if (*DAT_0802e200 != '\0') {
    uStack_31 = 0;
    uStack_18 = *(undefined4 *)(DAT_0802e200 + 0x18);
    uStack_14 = *(undefined4 *)(DAT_0802e200 + 0x1c);
    uStack_20 = *(undefined4 *)(DAT_0802e200 + 0x10);
    uStack_1c = *(undefined4 *)(DAT_0802e200 + 0x14);
    uStack_30 = *(undefined4 *)(DAT_0802e200 + 8);
    uStack_2c = *(undefined4 *)(DAT_0802e200 + 0xc);
    disableIRQinterrupts();
    enableIRQinterrupts();
    uStack_28 = FUN_0802db00(*DAT_0802e220,DAT_0802e220[1]);
    uStack_10 = 0;
    uStack_c = 0;
    uStack_32 = 0;
    FUN_080305d8(0,auStack_38,pcVar1 + 0x34);
  }
  return;
}



/* ===== FUN_08023e64 @ 08023e64 ===== */

undefined4 FUN_08023e64(void)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  undefined4 extraout_r3;
  undefined4 unaff_r7;
  
  FUN_0802e2d6();
  FUN_0802ded2();
  iVar1 = FUN_08022a56();
  FUN_08022dd4(iVar1,unaff_r7);
  if (*(char *)(iVar1 + 0x18) == '\x01') {
    if (*(char *)(iVar1 + 0x19f0) == '\0') goto LAB_0802e79a;
    FUN_0802de62();
  }
  if (*(char *)(iVar1 + 0x18) == '\x02') {
    FUN_0802e31a(100);
  }
LAB_0802e79a:
  if (*(int *)(iVar1 + 0x1c) == 0) {
    if (*(int *)(iVar1 + 0x58) < 4) {
      *(int *)(iVar1 + 0x58) = *(int *)(iVar1 + 0x58) + 1;
    }
    iVar4 = *(int *)(iVar1 + 0x54) + 1;
    if (3 < iVar4) {
      iVar4 = 0;
    }
    *(int *)(iVar1 + 0x54) = iVar4;
    *(int *)(iVar1 + 0x5c) = *(int *)(iVar1 + 0x50) + iVar4 * 0x2c;
    FUN_0803124c();
    *DAT_0802e860 = 1;
    DataSynchronizationBarrier(0xf);
    *DAT_0802e864 = 1;
    *(undefined1 *)(iVar1 + 0x19) = *(undefined1 *)(iVar1 + 5);
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(undefined4 *)(iVar1 + 0x24) = 0;
    switch(*(undefined1 *)(iVar1 + 0x1a)) {
    case 0:
      FUN_08022ed2(iVar1);
      break;
    case 1:
      FUN_08023018(iVar1);
      break;
    case 2:
      FUN_080231b8(iVar1);
      break;
    case 3:
      FUN_0802352e(iVar1);
      break;
    case 4:
      FUN_080236bc(iVar1);
    }
    *(undefined1 *)(iVar1 + 0x28) = 1;
    *(undefined1 *)(iVar1 + 0x18) = *(undefined1 *)(iVar1 + 0x1a);
    FUN_08022c3e(iVar1);
    *(undefined1 *)(iVar1 + 0x2c) = *(undefined1 *)(iVar1 + 0x3c);
    iVar4 = *(int *)(iVar1 + 0x40);
    if (0 < iVar4) {
      iVar4 = iVar4 + -1;
    }
    *(int *)(iVar1 + 0x40) = iVar4;
    if ((iVar4 == 0) && (*(int *)(iVar1 + 0x34) != 0)) {
      iVar4 = *(int *)(iVar1 + 0x38) + 1;
      if (*(int *)(iVar1 + 0x34) <= iVar4) {
        iVar4 = 0;
      }
      *(int *)(iVar1 + 0x38) = iVar4;
      iVar4 = *(int *)(iVar1 + 0x30) + iVar4 * 4;
      bVar3 = *(byte *)(iVar4 + 1);
      if (bVar3 < 9) {
        uVar2 = (uint)*(ushort *)(iVar4 + 2);
      }
      else {
        bVar3 = 0;
        uVar2 = 0;
      }
      *(byte *)(iVar1 + 0x3c) = bVar3;
      *(uint *)(iVar1 + 0x40) = uVar2;
    }
  }
  return extraout_r3;
}



/* ===== FUN_08023e88 @ 08023e88 ===== */

undefined4 FUN_08023e88(int param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_08023fc8;
  if (param_1 == DAT_08023fc4) {
    *DAT_08023fc8 = *DAT_08023fc8 | 0x80000000;
    *puVar1 = *puVar1 & 0x7fffffff;
    return 0;
  }
  if (param_1 == DAT_08023fcc) {
    DAT_08023fc8[1] = DAT_08023fc8[1] | 0x20;
    puVar1[1] = puVar1[1] & 0xffffffdf;
    return 0;
  }
  return 1;
}



/* ===== FUN_08023ec4 @ 08023ec4 ===== */

void FUN_08023ec4(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int local_38 [4];
  undefined4 uStack_28;
  
  uVar3 = 0;
  uVar8 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar8 = isIRQinterruptsEnabled();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts(1);
  }
  if (param_1 == DAT_08023fc4) {
    uVar3 = *DAT_08023fd0 >> 0x10 & 0xc | 0xc0000;
  }
  else if (param_1 == DAT_08023fcc) {
    uVar3 = *DAT_08023fd0 >> 0x10 & 0x30 | 0x300000;
  }
  iVar9 = param_1[2];
  iVar6 = param_1[3];
  iVar5 = param_1[5];
  iVar4 = param_1[6];
  iVar7 = param_1[8];
  uStack_28 = param_4;
  FUN_08023e88(param_1);
  FUN_0802e868(local_38);
  if (iVar4 == 0 && iVar5 == 0) goto LAB_08023fa6;
  if (param_1 == DAT_08023fc4) {
    uVar2 = *DAT_08023fd0 & 0xfff3ffff;
LAB_08023f46:
    *DAT_08023fd0 = uVar2;
  }
  else if (param_1 == DAT_08023fcc) {
    uVar2 = *DAT_08023fd0 & 0xffcfffff;
    goto LAB_08023f46;
  }
  if (iVar5 != 0) {
    param_1[4] = param_1[4] | 1;
    param_1[5] = iVar5;
    do {
      local_38[0] = local_38[0] + -1;
      if (*param_1 << 0x1c < 0) break;
    } while (local_38[0] != 0);
    param_1[1] = param_1[1] | 8;
  }
  if (iVar4 != 0) {
    param_1[4] = param_1[4] | 1;
    param_1[6] = iVar4;
    FUN_0802e868(local_38);
    do {
      local_38[0] = local_38[0] + -1;
      if (*param_1 << 0x1b < 0) break;
    } while (local_38[0] != 0);
    param_1[1] = param_1[1] | 0x10;
  }
  *DAT_08023fd0 = *DAT_08023fd0 & ~(uVar3 & 0xffff0000) | uVar3 << 0x10;
LAB_08023fa6:
  param_1[4] = param_1[4] & 0xfffffffe;
  param_1[2] = iVar9;
  param_1[3] = iVar6;
  param_1[8] = iVar7;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar8 & 1) == 1);
  }
  return;
}



/* ===== thunk_FUN_08028238 @ 08023fd4 ===== */

void thunk_FUN_08028238(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = DAT_08028c10;
  iVar2 = *DAT_08028bdc;
  *(int *)*DAT_08028c10 = *(int *)(iVar2 + 8) + 4;
  *(undefined4 *)puVar1[1] = *(undefined4 *)(iVar2 + 4);
  *(undefined1 *)puVar1[2] = 0;
  *(undefined1 *)puVar1[3] = 0;
  *(undefined4 *)puVar1[4] = 0;
  *(undefined4 *)puVar1[5] = 0;
  *(short *)puVar1[6] = (short)*(undefined4 *)(iVar2 + 0x10) + -4;
  *(short *)puVar1[7] = (short)*(undefined4 *)(iVar2 + 0xc) + -4;
  return;
}



/* ===== FUN_08023fd8 @ 08023fd8 ===== */

undefined4 * FUN_08023fd8(void)

{
  char cVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  bool bVar7;
  
  piVar2 = DAT_08024060;
  if (*(int *)*DAT_0802405c != 5) {
    return DAT_0802405c;
  }
  if (((code *)DAT_08024060[6] != (code *)0x0) && (*(char *)DAT_08024060[4] == '\0')) {
    (*(code *)DAT_08024060[6])(DAT_08024060);
    piVar2[6] = 0;
  }
  cVar1 = *(char *)piVar2[3];
  bVar7 = cVar1 == '\x01';
  if (bVar7) {
    cVar1 = *(char *)piVar2[4];
  }
  if (bVar7 && cVar1 == '\0') {
    *(char *)piVar2[3] = cVar1;
    FUN_0802a31c(*(undefined1 *)*piVar2);
    iVar4 = *piVar2;
    puVar5 = *(uint **)(iVar4 + 4);
    piVar2[1] = (int)(puVar5 + 1);
    puVar3 = DAT_08028bf4;
    uVar6 = *puVar5;
    *DAT_08028bf4 = uVar6 & 0x1f000000;
    piVar2[2] = *(int *)(iVar4 + 8) + 4;
    puVar5 = DAT_08028c0c;
    if (-1 < (int)((uint)(byte)puVar3[1] << 0x1e)) {
      puVar5 = (uint *)&UNK_08028220;
    }
    for (; *puVar5 != (uVar6 & 0xe0ffffff) && *puVar5 != 0; puVar5 = puVar5 + 2) {
    }
    (*(code *)puVar5[1])(piVar2);
    FUN_0802827e(piVar2);
    if ((code *)piVar2[5] != (code *)0x0) {
      (*(code *)piVar2[5])(piVar2);
      piVar2[5] = 0;
    }
    (**(code **)(*piVar2 + 0x14))(piVar2);
    return (undefined4 *)0x1;
  }
  return (undefined4 *)0x0;
}



/* ===== FUN_08023fea @ 08023fea ===== */

uint FUN_08023fea(void)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint unaff_r7;
  
  if (*DAT_08024064 != 0) {
    return (uint)*DAT_08024064;
  }
  *DAT_08024064 = 1;
  (*(code *)*DAT_08024068)();
  puVar1 = DAT_08024074;
  uVar3 = (*DAT_0802406c & 0x7ff) >> 8;
  if (7 - uVar3 < 5) {
    uVar2 = (1 << (7 - uVar3 & 0xff)) - 1U & 2;
  }
  else {
    uVar2 = 2;
  }
  if (6 < uVar3 + 4) {
    uVar2 = uVar2 << (uVar3 - 3 & 0xff);
  }
  *DAT_08024070 = (char)(uVar2 << 4);
  *puVar1 = 1;
  return unaff_r7;
}



/* ===== FUN_0802407c @ 0802407c ===== */

undefined4 FUN_0802407c(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14);
  if (iVar2 != param_2) {
    *(int *)(param_1 + 0x14) = param_2;
    if ((*(char *)(param_1 + 0x18) == '\0') ||
       (*(int *)(param_1 + 0x10) < iVar2 != *(int *)(param_1 + 0x10) < param_2)) {
      uVar1 = FUN_080165ac(param_1,0,param_4);
      return uVar1;
    }
  }
  return param_4;
}



/* ===== FUN_080240ac @ 080240ac ===== */

uint FUN_080240ac(int param_1,uint param_2)

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



/* ===== FUN_080240ce @ 080240ce ===== */

undefined4 FUN_080240ce(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
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
  uVar3 = param_3 | uVar2 | 0x2000;
  if (*(char *)(param_1 + 0x20) != '\0') {
    uVar3 = param_3 | uVar2 | 0x2100;
  }
  uVar1 = FUN_080166a6(uVar3);
  return uVar1;
}



/* ===== FUN_08024100 @ 08024100 ===== */

int FUN_08024100(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  *(int *)(param_1 + 8) = param_2 + 0x28f;
  uVar3 = *(uint *)(param_1 + 0x1c);
  if ((uVar3 == 0) && (uVar3 = *DAT_080242c4 & 0x70, (int)(uVar3 << 0x19) < 0)) {
    uVar3 = 0x40;
  }
  *(uint *)(param_1 + 0x14) = uVar3;
  iVar1 = FUN_080240ac(param_1);
  iVar4 = *(int *)(param_1 + 0x10);
  *(int *)(param_1 + 0x10) = iVar1;
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
    if ((iVar4 != 0) && (iVar1 = FUN_080240ce(param_1,iVar4,2), iVar1 == 0)) {
      *(undefined1 *)(param_1 + 0x20) = 0;
      *(undefined1 *)(param_1 + 0x21) = 0;
    }
    return 0;
  }
  iVar2 = *(int *)(param_1 + 0x18);
  if (*(char *)(param_1 + 0x21) == '\0') {
    if ((iVar4 == iVar1) && (iVar2 < 0)) {
      *(undefined4 *)(param_1 + 0x18) = 0x32;
      iVar1 = FUN_080240ce(param_1,iVar1,1);
      if (iVar1 == 0) {
        *(undefined1 *)(param_1 + 0x20) = 0;
        return param_1;
      }
      return param_1;
    }
    if ((iVar2 < 1) || (iVar2 = iVar2 + -1, iVar2 != 0)) goto LAB_080241a8;
    iVar1 = FUN_080240ce(param_1);
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
    if (iVar2 != 0) goto LAB_080241a8;
    iVar1 = FUN_080240ce(param_1,iVar1,3);
    if (iVar1 != 0) {
      return param_1;
    }
  }
  iVar2 = 10;
LAB_080241a8:
  *(int *)(param_1 + 0x18) = iVar2;
  return param_1;
}



/* ===== FUN_080241ae @ 080241ae ===== */

void FUN_080241ae(void)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  undefined4 in_r3;
  
  iVar2 = DAT_080242d0;
  *(undefined4 *)(DAT_080242d0 + 0x10) = 0;
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  *(undefined4 *)(iVar2 + 0x18) = 0xffffffff;
  *(undefined2 *)(iVar2 + 0x20) = 0;
  piVar1 = DAT_080242c8;
  *(undefined1 *)(iVar2 + 0x22) = 0;
  *(int *)(iVar2 + 0x24) = *piVar1 + 0x50000;
  puVar3 = DAT_080242d4;
  DAT_080242d4[5] = 0x40;
  *puVar3 = *puVar3 | 0x40;
  *(undefined4 *)(iVar2 + 0x18) = 0xffffffff;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  *(undefined1 *)(iVar2 + 0x21) = 0;
  *(undefined1 *)(iVar2 + 0x22) = 0;
  *(int *)(iVar2 + 0x24) = *piVar1 + 0x50000;
  FUN_080165ac(iVar2,0,in_r3);
  return;
}



/* ===== FUN_080241fe @ 080241fe ===== */

uint FUN_080241fe(uint param_1)

{
  return param_1 & *(uint *)(DAT_080242d0 + 0x14);
}



/* ===== FUN_08024206 @ 08024206 ===== */

undefined1 FUN_08024206(void)

{
  int iVar1;
  
  iVar1 = DAT_080242d0;
  *(undefined1 *)(DAT_080242d0 + 0x22) = 1;
  return *(undefined1 *)(iVar1 + 0x22);
}



/* ===== FUN_08024210 @ 08024210 ===== */

void FUN_08024210(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = DAT_080242d0;
  piVar1 = DAT_080242c8;
  if ((*DAT_080242c4 & 0x50) == 0x50) {
    if (0 < *DAT_080242c8 - *(int *)(DAT_080242d0 + 0x24)) {
      *DAT_080242cc = 0x5555;
      DAT_080242cc[2] = 0;
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  else {
    *(int *)(DAT_080242d0 + 0x24) = *DAT_080242c8 + 0x50000;
  }
  if (*(char *)(iVar2 + 0x22) == '\0') {
    return;
  }
  *(undefined1 *)(iVar2 + 0x22) = 0;
  if (*(char *)(iVar2 + 0xc) == '\0') {
    *(undefined4 *)(iVar2 + 0x10) = 0;
    *(undefined4 *)(iVar2 + 0x18) = 0xffffffff;
    *(undefined1 *)(iVar2 + 0x21) = 0;
    *(undefined1 *)(iVar2 + 0x22) = 0;
    *(int *)(iVar2 + 0x24) = *piVar1 + 0x50000;
    FUN_080165ac(iVar2,0);
    return;
  }
  return;
}



/* ===== FUN_08024278 @ 08024278 ===== */

undefined1 FUN_08024278(void)

{
  return *(undefined1 *)(DAT_080242d0 + 0x22);
}



/* ===== FUN_080242d8 @ 080242d8 ===== */

uint FUN_080242d8(uint param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_08024498;
  *DAT_08024498 = *DAT_08024498 | param_1;
  return param_1 & *puVar1;
}



/* ===== thunk_FUN_080242f2 @ 080242ee ===== */

void thunk_FUN_080242f2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_14 = param_3;
  uStack_10 = param_4;
  FUN_080242d8(0x800000);
  uVar2 = DAT_080244a0;
  puVar1 = DAT_0802449c;
  *DAT_0802449c = 0x58;
  uStack_14._0_2_ = (ushort)(byte)uStack_14;
  iVar3 = FUN_0802b51e(uVar2,0x58,3,(int)&uStack_14 + 1,1);
  if (iVar3 != 0) {
    uStack_14._0_2_ = (ushort)(byte)uStack_14;
    *puVar1 = 0x5e;
    FUN_0802b51e(uVar2,0x5e,3,(int)&uStack_14 + 1,1);
  }
  uStack_14 = uStack_14 & 0xffffff00;
  FUN_0802b51e(uVar2,*puVar1,4,&uStack_14,1);
  *DAT_08024498 = *DAT_08024498 & 0xff7fffff;
  return;
}



/* ===== thunk_FUN_0802435c @ 080242f0 ===== */

void thunk_FUN_0802435c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  undefined1 *puVar2;
  undefined1 uStack_14;
  undefined3 uStack_13;
  undefined4 uStack_10;
  
  puVar2 = DAT_0802449c;
  puVar1 = DAT_08024498;
  *DAT_08024498 = *DAT_08024498 | 0x800000;
  _uStack_14 = CONCAT31((int3)((uint)param_3 >> 8),1);
  uStack_10 = param_4;
  FUN_0802b51e(DAT_080244a0,*puVar2,3,&uStack_14,1);
  *puVar1 = *puVar1 & 0xff7fffff;
  return;
}



/* ===== FUN_080242f2 @ 080242f2 ===== */

void FUN_080242f2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_14;
  undefined4 uStack_10;
  
  local_14 = param_3;
  uStack_10 = param_4;
  FUN_080242d8(0x800000);
  uVar2 = DAT_080244a0;
  puVar1 = DAT_0802449c;
  *DAT_0802449c = 0x58;
  local_14._0_2_ = (ushort)(byte)local_14;
  iVar3 = FUN_0802b51e(uVar2,0x58,3,(int)&local_14 + 1,1);
  if (iVar3 != 0) {
    local_14._0_2_ = (ushort)(byte)local_14;
    *puVar1 = 0x5e;
    FUN_0802b51e(uVar2,0x5e,3,(int)&local_14 + 1,1);
  }
  local_14 = local_14 & 0xffffff00;
  FUN_0802b51e(uVar2,*puVar1,4,&local_14,1);
  *DAT_08024498 = *DAT_08024498 & 0xff7fffff;
  return;
}



/* ===== FUN_0802435c @ 0802435c ===== */

void FUN_0802435c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  undefined1 *puVar2;
  undefined1 local_14;
  undefined3 uStack_13;
  undefined4 uStack_10;
  
  puVar2 = DAT_0802449c;
  puVar1 = DAT_08024498;
  *DAT_08024498 = *DAT_08024498 | 0x800000;
  _local_14 = CONCAT31((int3)((uint)param_3 >> 8),1);
  uStack_10 = param_4;
  FUN_0802b51e(DAT_080244a0,*puVar2,3,&local_14,1);
  *puVar1 = *puVar1 & 0xff7fffff;
  return;
}



/* ===== FUN_08024386 @ 08024386 ===== */

void FUN_08024386(undefined4 param_1)

{
  uint *puVar1;
  undefined1 *puVar2;
  undefined4 uStack_10;
  
  puVar2 = DAT_0802449c;
  puVar1 = DAT_08024498;
  *DAT_08024498 = *DAT_08024498 | 0x800000;
  uStack_10 = param_1;
  FUN_0802b51e(DAT_080244a0,*puVar2,2,&uStack_10,1);
  *puVar1 = *puVar1 & 0xff7fffff;
  return;
}



/* ===== FUN_080243bc @ 080243bc ===== */

uint FUN_080243bc(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint *puVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  uint local_1c;
  undefined4 uStack_18;
  
  uVar3 = DAT_080244a0;
  puVar2 = DAT_0802449c;
  puVar1 = DAT_08024498;
  *DAT_08024498 = *DAT_08024498 | 0x800000;
  local_1c = param_3 & 0xffffff00;
  uStack_18 = param_4;
  FUN_0802b51e(uVar3,*puVar2,5,&local_1c,1);
  FUN_0802b6ce(uVar3,*puVar2,&local_1c,1);
  *puVar1 = *puVar1 & 0xff7fffff;
  return local_1c & 0xff;
}



/* ===== FUN_080243e8 @ 080243e8 ===== */

void FUN_080243e8(undefined4 param_1)

{
  uint *puVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uStack_18;
  
  uVar3 = DAT_080244a0;
  puVar2 = DAT_0802449c;
  puVar1 = DAT_08024498;
  *DAT_08024498 = *DAT_08024498 | 0x800000;
  uStack_18 = param_1;
  FUN_0802b51e(uVar3,*puVar2,2,&uStack_18,1);
  FUN_0802b51e(uVar3,*puVar2,1,&uStack_18,1);
  *puVar1 = *puVar1 & 0xff7fffff;
  return;
}



/* ===== FUN_0802442e @ 0802442e ===== */

uint FUN_0802442e(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint *puVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  uint local_1c;
  undefined4 uStack_18;
  
  uVar3 = DAT_080244a0;
  puVar2 = DAT_0802449c;
  puVar1 = DAT_08024498;
  *DAT_08024498 = *DAT_08024498 | 0x800000;
  local_1c = param_3 & 0xffffff00;
  uStack_18 = param_4;
  FUN_0802b51e(uVar3,*puVar2,6,&local_1c,1);
  FUN_0802b6ce(uVar3,*puVar2,&local_1c,1);
  *puVar1 = *puVar1 & 0xff7fffff;
  return local_1c & 0xff;
}



/* ===== FUN_080244a4 @ 080244a4 ===== */

uint FUN_080244a4(int param_1,undefined4 param_2)

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
    FUN_0801682e();
  }
  return ~-(uint)(*(char *)(param_1 + 0x14) == '\0') >> 0x1f;
}



/* ===== FUN_080244f2 @ 080244f2 ===== */

longlong FUN_080244f2(int param_1,int param_2,uint param_3)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int unaff_r8;
  uint local_20;
  
  puVar1 = DAT_080246b4;
  piVar3 = *(int **)(param_1 + 0x10);
  local_20 = param_3;
  if (piVar3 == (int *)0x0) goto LAB_0802458c;
  if ('\0' < (char)piVar3[1]) goto LAB_08024592;
  *DAT_080246b4 = *DAT_080246b4 | 0x400000;
  local_20 = *puVar1 & 0x400000;
  if (*(char *)(param_1 + 0x15) == '\0') {
    unaff_r8 = (**(code **)(*piVar3 + 4))(piVar3);
    iVar2 = unaff_r8;
    if (unaff_r8 < 1) {
      iVar2 = (int)(char)piVar3[1];
    }
    if (iVar2 < 1) {
      *(undefined1 *)(param_1 + 0x15) = 1;
      (**(code **)(*piVar3 + 0x14))(piVar3,param_1 + 0x28);
      goto LAB_0802454e;
    }
  }
  else {
    if (*(char *)(param_1 + 0x15) == '\x01') {
LAB_0802454e:
      (**(code **)(*piVar3 + 0x10))(piVar3,param_1 + 0x1c);
      if (*(int *)(param_1 + 0x18) != 0) {
        (**(code **)(*piVar3 + 0x14))(piVar3,param_1 + 0x28);
        (**(code **)(param_1 + 0x18))();
        unaff_r8 = 0x8000;
        goto LAB_08024578;
      }
    }
    unaff_r8 = 0x28000;
  }
LAB_08024578:
  *puVar1 = *puVar1 & 0xffbfffff;
  iVar2 = FUN_080244a4(param_1,(int)(char)piVar3[1]);
  if (iVar2 == 0) {
LAB_08024592:
    *(int *)(param_1 + 8) = param_2 + unaff_r8;
    return CONCAT44(local_20,param_1);
  }
LAB_0802458c:
  return (ulonglong)local_20 << 0x20;
}



/* ===== FUN_0802459c @ 0802459c ===== */

undefined8 FUN_0802459c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)FUN_0802ec5a();
  iVar2 = (**(code **)*puVar1)();
  if (iVar2 != 0) {
    *(undefined4 **)(param_1 + 0x10) = puVar1;
  }
  return CONCAT44(param_4,~-(uint)(iVar2 == 0) >> 0x1f);
}



/* ===== FUN_080245bc @ 080245bc ===== */

uint FUN_080245bc(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = DAT_080246b8;
  puVar1 = DAT_080246b4;
  *(undefined4 *)(DAT_080246b8 + 0x10) = 0;
  *(undefined2 *)(iVar2 + 0x14) = 0;
  *puVar1 = *puVar1 | 0x400000;
  uVar3 = *puVar1 & 0x400000;
  iVar4 = FUN_0802459c(iVar2);
  *puVar1 = *puVar1 & 0xffbfffff;
  if (iVar4 != 0) {
    uVar3 = FUN_080165ac(iVar2,0x199a,uVar3);
    return uVar3;
  }
  if (*(char *)(iVar2 + 0x14) == '\0') {
    *(undefined1 *)(iVar2 + 0x14) = 1;
    uVar3 = FUN_0801682e(1,uVar3);
    return uVar3;
  }
  return uVar3;
}



/* ===== FUN_0802460c @ 0802460c ===== */

void FUN_0802460c(void)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  code *pcVar5;
  
  iVar2 = DAT_080246b8;
  puVar1 = DAT_080246b4;
  piVar3 = *(int **)(DAT_080246b8 + 0x10);
  *(undefined1 *)(DAT_080246b8 + 0x15) = 2;
  *puVar1 = *puVar1 | 0x400000;
  uVar4 = *puVar1;
  pcVar5 = *(code **)(*piVar3 + 8);
  (*pcVar5)(piVar3,pcVar5,uVar4 & 0x400000);
  *DAT_080246bc = *DAT_080246bc & 0xfffffffe;
  *puVar1 = *puVar1 & 0xffbfffff;
  FUN_080165ce(iVar2,uVar4 & 0x400000);
  return;
}



/* ===== FUN_0802464c @ 0802464c ===== */

ulonglong FUN_0802464c(undefined4 param_1,undefined4 param_2,uint param_3)

{
  char cVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  bool bVar7;
  uint local_18;
  
  iVar3 = DAT_080246b8;
  puVar2 = DAT_080246b4;
  piVar6 = *(int **)(DAT_080246b8 + 0x10);
  local_18 = param_3;
  if (piVar6 != (int *)0x0) {
    cVar1 = *(char *)(DAT_080246b8 + 0x15);
    bVar7 = cVar1 == '\x01';
    if (bVar7) {
      cVar1 = *(char *)(DAT_080246b8 + 0x14);
    }
    if (bVar7 && cVar1 == '\0') {
      *DAT_080246b4 = *DAT_080246b4 | 0x400000;
      uVar4 = *puVar2;
      local_18 = uVar4 & 0x400000;
      (**(code **)(*piVar6 + 0x10))(piVar6,iVar3 + 0x1c);
      *puVar2 = *puVar2 & 0xffbfffff;
      iVar5 = FUN_080244a4(iVar3,(int)(char)piVar6[1]);
      if (iVar5 == 0) {
        return CONCAT44(uVar4,iVar3 + 0x1c) & 0x400000ffffffff;
      }
    }
  }
  return (ulonglong)local_18 << 0x20;
}



/* ===== FUN_0802469e @ 0802469e ===== */

bool FUN_0802469e(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0802ec70(DAT_080246b8);
  if (iVar1 != 0) {
    *param_1 = (int)*(short *)(iVar1 + 4);
  }
  return iVar1 != 0;
}



/* ===== FUN_080247a8 @ 080247a8 ===== */

undefined4 FUN_080247a8(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 in_r3;
  
  iVar1 = DAT_0802489c;
  iVar2 = FUN_0801d2b6(0x10,DAT_0802489c + 0x30,1);
  if (iVar2 == 0) {
    *(undefined4 *)(iVar1 + 0x30) = 0;
  }
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0x2c) = 0;
  puVar3 = (undefined4 *)FUN_0802f086();
  iVar2 = (**(code **)*puVar3)();
  if (iVar2 != 0) {
    puVar3 = (undefined4 *)FUN_0802f252();
    iVar2 = (**(code **)*puVar3)();
    if (iVar2 != 0) {
      FUN_08016804(1);
      *(uint *)(DAT_080248a0 + 8) = *(uint *)(DAT_080248a0 + 8) & 0xffdfffff;
      *DAT_080248a4 = 0x2000;
      return in_r3;
    }
  }
  *(undefined4 **)(iVar1 + 0x38) = puVar3;
  uVar4 = FUN_080165ac(iVar1,0x199a,in_r3);
  return uVar4;
}



/* ===== FUN_08024808 @ 08024808 ===== */

undefined4 FUN_08024808(void)

{
  int iVar1;
  int iVar2;
  undefined4 in_r3;
  int *piVar3;
  
  iVar1 = DAT_0802489c;
  piVar3 = *(int **)(DAT_0802489c + 0x38);
  FUN_080165ce(DAT_0802489c);
  if (piVar3 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar3 + 4))(piVar3);
    *(undefined4 *)(iVar1 + 0x38) = 0;
    if (iVar2 != 0) {
      FUN_08016804(2);
      *(uint *)(DAT_080248a0 + 8) = *(uint *)(DAT_080248a0 + 8) & 0xffdfffff;
      *DAT_080248a4 = 0x2000;
    }
  }
  return in_r3;
}



/* ===== FUN_0802483e @ 0802483e ===== */

void FUN_0802483e(undefined4 param_1)

{
  *(undefined4 *)(DAT_0802489c + 0x30) = param_1;
  return;
}



/* ===== FUN_08024846 @ 08024846 ===== */

undefined4 FUN_08024846(void)

{
  return *(undefined4 *)(DAT_0802489c + 0x18);
}



/* ===== FUN_08024884 @ 08024884 ===== */

undefined4 FUN_08024884(void)

{
  return *(undefined4 *)(DAT_0802489c + 0x1c);
}



/* ===== FUN_080248a8 @ 080248a8 ===== */

void FUN_080248a8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_08024ad8;
  puVar1 = DAT_08024ad4;
  *DAT_08024ad4 = 0;
  *puVar2 = 1;
  if (puVar1[2] == '\0') {
    puVar1[2] = (char)param_1;
  }
  FUN_08017f38("BLE: error #0x%0.2X!",param_1,param_4);
  return;
}



/* ===== FUN_080248c8 @ 080248c8 ===== */

void FUN_080248c8(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_08017ee8("BLE: Hardware initialization");
  puVar1 = DAT_08024ad8;
  *DAT_08024ad4 = 0;
  *puVar1 = 0;
  FUN_0801661e(DAT_08024adc,&DAT_08024b84,4);
  iVar2 = DAT_08027f90;
  *(undefined4 *)(DAT_08027f90 + 8) = *DAT_08027f8c;
  *(undefined4 *)(iVar2 + 4) = 0;
  return;
}



/* ===== FUN_080248f0 @ 080248f0 ===== */

void FUN_080248f0(void)

{
  undefined4 unaff_r7;
  
  FUN_08017ee8("BLE: Start");
  FUN_0801661e(DAT_08024ae0,&DAT_08024ba4,3,unaff_r7);
  return;
}



/* ===== FUN_08024908 @ 08024908 ===== */

void FUN_08024908(void)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  
  FUN_08017ee8("BLE: Stop");
  FUN_080165ce(DAT_08024adc);
  FUN_080165ce(DAT_08024ae0);
  puVar3 = DAT_0801970c;
  iVar1 = DAT_080196e0;
  *DAT_08019700 = *DAT_08019700 & 0xffffdfff;
  *(undefined1 *)(iVar1 + 0x18) = 0;
  *DAT_080196dc = 0;
  puVar2 = DAT_08019708;
  *puVar3 = 4;
  *puVar2 = *puVar2 & 0xffff7fff;
  return;
}



/* ===== FUN_08024926 @ 08024926 ===== */

void FUN_08024926(void)

{
  FUN_080192cc(1);
  return;
}



/* ===== FUN_0802492c @ 0802492c ===== */

undefined4 FUN_0802492c(void)

{
  undefined4 uVar1;
  undefined4 unaff_r7;
  
  FUN_0802a25a();
  FUN_08027aa0();
  if (*DAT_08024ad4 == '\x02') {
    return unaff_r7;
  }
  FUN_080248a8(0x85,unaff_r7);
  FUN_080165ce(DAT_08024adc);
  uVar1 = FUN_08017ee8("BLE: Init sequence error!",unaff_r7);
  return uVar1;
}



/* ===== FUN_08024948 @ 08024948 ===== */

undefined4 FUN_08024948(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_r7;
  
  iVar1 = FUN_0802a186();
  if (iVar1 == 0) {
    return unaff_r7;
  }
  FUN_080248a8(0x84,unaff_r7);
  FUN_080165ce(DAT_08024adc);
  uVar2 = FUN_08017ee8("BLE: Init sequence error!",unaff_r7);
  return uVar2;
}



/* ===== FUN_0802495a @ 0802495a ===== */

longlong FUN_0802495a(void)

{
  uint unaff_r7;
  
  if (*(int *)(DAT_08024ae4 + 0x68) << 0x19 < 0) {
    FUN_080248f0();
  }
  else {
    FUN_08024908();
  }
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08024986 @ 08024986 ===== */

uint FUN_08024986(void)

{
  return ~-(uint)(*(char *)(DAT_08024adc + 0xc) == '\0') >> 0x1f;
}



/* ===== FUN_0802498a @ 0802498a ===== */

void FUN_0802498a(void)

{
  undefined4 unaff_r7;
  
  FUN_080165ce(DAT_08024adc);
  FUN_080192cc(0,unaff_r7);
  return;
}



/* ===== FUN_080249e6 @ 080249e6 ===== */

uint FUN_080249e6(void)

{
  return ~-(uint)(*(char *)(DAT_08024ae0 + 0xc) == '\0') >> 0x1f;
}



/* ===== FUN_08024a7e @ 08024a7e ===== */

void FUN_08024a7e(void)

{
  FUN_080165ce(DAT_08024af4);
  return;
}



/* ===== FUN_08024a84 @ 08024a84 ===== */

longlong FUN_08024a84(void)

{
  char *pcVar1;
  undefined4 *puVar2;
  uint unaff_r7;
  
  puVar2 = DAT_08024ad8;
  pcVar1 = DAT_08024ad4;
  if (*DAT_08024ad4 == '\0') {
    *DAT_08024ad4 = '\x05';
    FUN_08027a7c();
  }
  else {
    *DAT_08024ad4 = '\0';
    *puVar2 = 1;
    if (pcVar1[2] == '\0') {
      pcVar1[2] = '\t';
    }
    FUN_08017f38("BLE: error #0x%0.2X!",9);
  }
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08024acc @ 08024acc ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_08024acc(void)

{
  FUN_080165ce(_DAT_08024af8);
  return;
}



/* ===== FUN_08024bbc @ 08024bbc ===== */

undefined4 * FUN_08024bbc(undefined4 *param_1,uint param_2)

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



/* ===== FUN_08024bc4 @ 08024bc4 ===== */

void FUN_08024bc4(uint *param_1,uint *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
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
    uVar6 = 1 << (uVar5 & 0xff) & *param_2;
    if (uVar6 != 0) {
      bVar2 = (byte)uVar6;
      bVar3 = (byte)(uVar6 >> 8);
      bVar4 = (byte)(uVar6 >> 0x10);
      bVar1 = (byte)(uVar6 >> 0x18);
      iVar9 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1)
                                       << 1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                    bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) <<
                      0x18 | (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 |
                                              bVar3 >> 2 & 1) << 1 | bVar3 >> 3 & 1) << 1 |
                                            bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                                          bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
                      (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1)
                                       << 1 | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 |
                                    bVar4 >> 5 & 1) << 1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
                      (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1)
                                       << 1 | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 |
                                    bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7));
      iVar7 = iVar9 << 1;
      uVar8 = ~(3 << iVar7);
      if ((param_2[1] == 1) || (param_2[1] == 2)) {
        param_1[2] = param_2[2] << iVar7 | uVar8 & param_1[2];
        param_1[1] = param_2[3] * *param_2 | param_1[1] & ~*param_2;
      }
      param_1[3] = param_2[4] << iVar7 | uVar8 & param_1[3];
      if (param_2[1] == 2) {
        if (uVar6 < 0x100) {
          iVar9 = iVar9 << 2;
          param_1[8] = param_2[5] << iVar9 | param_1[8] & ~(0xf << iVar9);
        }
        else {
          iVar9 = LZCOUNT((uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 |
                                           bVar3 >> 2 & 1) << 1 | bVar3 >> 3 & 1) << 1 |
                                         bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                                       bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x18 |
                          (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 |
                                           bVar4 >> 2 & 1) << 1 | bVar4 >> 3 & 1) << 1 |
                                         bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                                       bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 0x10 |
                          (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 |
                                           bVar1 >> 2 & 1) << 1 | bVar1 >> 3 & 1) << 1 |
                                         bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                                       bVar1 >> 6 & 1) << 1 | bVar1 >> 7) << 8) << 2;
          param_1[9] = param_2[5] << iVar9 | param_1[9] & ~(0xf << iVar9);
        }
      }
      *param_1 = param_2[1] << iVar7 | uVar8 & *param_1;
    }
  }
  return;
}



/* ===== FUN_08024ccc @ 08024ccc ===== */

int FUN_08024ccc(char *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar4;
  int *piVar3;
  int iVar5;
  int iVar6;
  
  if (*param_1 == '\0') {
    *param_1 = '\x01';
    piVar2 = *(int **)(param_1 + 0xc);
    piVar3 = piVar2;
    if (piVar2 < (int *)0xfffffff4) {
      do {
        piVar4 = piVar3 + 1;
        *piVar3 = param_2;
        piVar3 = piVar4;
      } while (piVar4 < piVar2 + 3);
    }
    param_1[0x10] = '\0';
    param_1[0x11] = '\0';
    param_1[0x12] = '\0';
    param_1[0x13] = '\0';
    iVar5 = param_2 << 7;
    goto LAB_08024d4a;
  }
  iVar5 = *(int *)(param_1 + 0x10) + 1;
  if (2 < iVar5) {
    iVar5 = 0;
  }
  *(int *)(param_1 + 0x10) = iVar5;
  *(int *)(*(int *)(param_1 + 0xc) + iVar5 * 4) = param_2;
  iVar5 = *(int *)(param_1 + 0x18);
  iVar1 = *(int *)(param_1 + 0x14);
  iVar6 = *(int *)(param_1 + 0x1c);
  if (iVar1 < iVar5) {
    if (iVar6 <= iVar1) goto LAB_08024d20;
    if (iVar6 <= iVar5) goto LAB_08024d1c;
  }
  else if (iVar1 < iVar6) {
LAB_08024d20:
    iVar5 = iVar1;
  }
  else if (iVar5 < iVar6) {
LAB_08024d1c:
    iVar5 = iVar6;
  }
  iVar5 = (iVar5 + *(int *)(param_1 + 4)) - *(int *)(param_1 + 8);
  if (iVar5 < 0) {
    param_2 = 0;
    iVar5 = 0;
  }
  else if (DAT_08024d54 < iVar5) {
    param_2 = 0x1194;
    iVar5 = DAT_08024d54;
  }
  else {
    param_2 = (int)(iVar5 + ((uint)(iVar5 >> 6) >> 0x19)) >> 7;
  }
LAB_08024d4a:
  *(int *)(param_1 + 8) = param_2;
  *(int *)(param_1 + 4) = iVar5;
  return param_2;
}



/* ===== thunk_FUN_0802f29a @ 08024d58 ===== */

void thunk_FUN_0802f29a(void)

{
  FUN_08031294(1);
  return;
}



/* ===== FUN_08024d5c @ 08024d5c ===== */

void FUN_08024d5c(int param_1,uint param_2)

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



/* ===== FUN_08024d78 @ 08024d78 ===== */

undefined4 FUN_08024d78(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_08024dd8;
  if (*DAT_08024dd8 == 0) {
    DAT_08024dd8[2] = 0x10000;
    piVar1[1] = 0x1000;
    iVar2 = DAT_08024ddc;
    piVar1[3] = -1;
    piVar1[4] = -1;
    piVar1[5] = 4;
    *(undefined4 *)(iVar2 + 0x1bc) = 4;
    *piVar1 = DAT_08024de0;
  }
  return 1;
}



/* ===== FUN_08024da4 @ 08024da4 ===== */

void FUN_08024da4(int param_1,int param_2,int param_3)

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
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(DAT_08024dd8 + 0x10);
  return;
}



/* ===== FUN_08024de4 @ 08024de4 ===== */

uint * FUN_08024de4(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  uint *puVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  uint uVar13;
  int *piVar14;
  uint uVar15;
  uint *puVar16;
  uint *puVar17;
  uint uVar18;
  uint *unaff_r8;
  uint *puVar19;
  uint uVar20;
  int *piVar21;
  bool bVar22;
  int local_2c;
  
  puVar1 = DAT_08024e6c;
  if (param_1 < 0xf5) {
    if (param_1 < 0xb) {
      uVar15 = 0x10;
    }
    else {
      uVar15 = param_1 + 0xb & 0xfffffff8;
    }
    uVar20 = uVar15 >> 3;
    uVar2 = *DAT_08024e6c >> (uVar20 & 0xff);
    if ((uVar2 & 3) != 0) {
      uVar20 = uVar20 + (~uVar2 & 1);
      puVar12 = DAT_08024e6c + uVar20 * 2 + 10;
      uVar15 = uVar20 * 8;
      puVar17 = (uint *)puVar12[2];
      if ((puVar17[1] & 0xfffffff8) != uVar15) {
        FUN_0802f29a();
      }
      puVar19 = (uint *)puVar17[2];
      if (puVar17 == puVar12) {
        FUN_0802f29a();
      }
      if (puVar17 == puVar19) {
        FUN_0802f29a();
      }
      if ((puVar17[1] & 0xfffffff8) != uVar15) {
        FUN_0802f29a();
      }
      if (puVar12 == puVar19) {
        *puVar1 = *puVar1 & ~(1 << (uVar20 & 0xff));
      }
      else if ((puVar19 < (uint *)puVar1[4]) || ((uint *)puVar19[3] != puVar17)) {
        FUN_0802f29a();
      }
      else {
        puVar12[2] = (uint)puVar19;
        puVar19[3] = (uint)puVar12;
      }
      puVar17[1] = uVar15 | 3;
      puVar17[uVar20 * 2 + 1] = puVar17[uVar20 * 2 + 1] | 1;
      return puVar17 + 2;
    }
    if (uVar15 <= DAT_08024e6c[2]) goto LAB_08025616;
    if (uVar2 != 0) {
      iVar8 = 1 << (uVar20 & 0xff);
      uVar2 = (iVar8 * 2 | iVar8 * -2) & uVar2 << (uVar20 & 0xff);
      uVar20 = (-uVar2 & uVar2) - 1;
      uVar2 = uVar20 >> 0xc & 0x10;
      uVar20 = uVar20 >> uVar2;
      uVar9 = uVar20 >> 5 & 8;
      uVar20 = uVar20 >> uVar9;
      uVar11 = uVar20 >> 2 & 4;
      uVar20 = uVar20 >> uVar11;
      uVar13 = uVar20 >> 1 & 2;
      uVar20 = uVar20 >> uVar13;
      uVar18 = -((int)(uVar20 << 0x1e) >> 0x1f);
      uVar20 = (uVar20 >> (uVar18 & 0xff)) + uVar18 + uVar13 + uVar11 + uVar9 + uVar2;
      puVar12 = DAT_08024e6c + uVar20 * 2 + 10;
      uVar2 = uVar20 * 8;
      puVar17 = (uint *)puVar12[2];
      if ((puVar17[1] & 0xfffffff8) != uVar2) {
        FUN_0802f29a();
      }
      puVar19 = (uint *)puVar17[2];
      if (puVar17 == puVar12) {
        FUN_0802f29a();
      }
      if (puVar17 == puVar19) {
        FUN_0802f29a();
      }
      if ((puVar17[1] & 0xfffffff8) != uVar2) {
        FUN_0802f29a();
      }
      if (puVar12 == puVar19) {
        *puVar1 = *puVar1 & ~(1 << (uVar20 & 0xff));
      }
      else if ((puVar19 < (uint *)puVar1[4]) || ((uint *)puVar19[3] != puVar17)) {
        FUN_0802f29a();
      }
      else {
        puVar12[2] = (uint)puVar19;
        puVar19[3] = (uint)puVar12;
      }
      uVar2 = uVar2 - uVar15;
      puVar17[1] = uVar15 | 3;
      *(uint *)((int)puVar17 + uVar15 + 4) = uVar2 | 1;
      *(uint *)((int)puVar17 + uVar15 + uVar2) = uVar2;
      uVar20 = puVar1[2];
      uVar9 = uVar20 >> 3;
      if (0x1f < uVar9) {
        FUN_0802f29a();
      }
      if (uVar20 != 0) {
        uVar11 = puVar1[5];
        puVar12 = puVar1 + uVar9 * 2 + 10;
        if (uVar20 < 0x10) {
          FUN_0802f29a();
        }
        if ((int)((*puVar1 >> (uVar9 & 0xff)) << 0x1f) < 0) {
          puVar19 = (uint *)puVar12[2];
          if (puVar19 < (uint *)puVar1[4]) {
            FUN_0802f29a();
            puVar19 = puVar12;
          }
        }
        else {
          *puVar1 = 1 << (uVar9 & 0xff) | *puVar1;
          puVar19 = puVar12;
        }
        puVar12[2] = uVar11;
        puVar19[3] = uVar11;
        *(uint **)(uVar11 + 8) = puVar19;
        *(uint **)(uVar11 + 0xc) = puVar12;
      }
      puVar1[2] = uVar2;
      puVar1[5] = (int)puVar17 + uVar15;
      return puVar17 + 2;
    }
    uVar2 = DAT_08024e6c[1];
    if (uVar2 != 0) {
      uVar2 = (uVar2 & -uVar2) - 1;
      uVar20 = uVar2 >> 0xc & 0x10;
      uVar2 = uVar2 >> uVar20;
      uVar9 = uVar2 >> 5 & 8;
      uVar2 = uVar2 >> uVar9;
      uVar11 = uVar2 >> 2 & 4;
      uVar2 = uVar2 >> uVar11;
      uVar13 = uVar2 >> 1 & 2;
      uVar2 = uVar2 >> uVar13;
      uVar18 = -((int)(uVar2 << 0x1e) >> 0x1f);
      unaff_r8 = DAT_08024e6c + 0x4c;
      uVar2 = unaff_r8[(uVar2 >> (uVar18 & 0xff)) + uVar13 + uVar11 + uVar9 + uVar20 + uVar18];
      uVar9 = (*(uint *)(uVar2 + 4) & 0xfffffff8) - uVar15;
      uVar20 = uVar2;
      while ((uVar11 = *(uint *)(uVar2 + 0x10), uVar11 != 0 ||
             (uVar11 = *(uint *)(uVar2 + 0x14), uVar11 != 0))) {
        uVar13 = (*(uint *)(uVar11 + 4) & 0xfffffff8) - uVar15;
        uVar2 = uVar11;
        if (uVar13 < uVar9) {
          uVar9 = uVar13;
          uVar20 = uVar11;
        }
      }
      if (DAT_08024e6c[4] <= uVar20) {
        uVar2 = uVar15 + uVar9;
        if ((*(uint *)(uVar20 + 4) & 0xfffffff8) != uVar2) {
          FUN_0802f29a();
        }
        uVar11 = uVar20 + uVar15;
        if (uVar20 < uVar11) {
          uVar13 = *(uint *)(uVar20 + 0xc);
          uVar18 = *(uint *)(uVar20 + 0x18);
          if (uVar13 == uVar20) {
            uVar13 = *(uint *)(uVar20 + 0x14);
            puVar12 = (uint *)(uVar20 + 0x14);
            if (uVar13 == 0) {
              puVar12 = (uint *)(uVar20 + 0x10);
              uVar13 = *puVar12;
              if (uVar13 == 0) goto LAB_080250f6;
            }
            while( true ) {
              puVar17 = (uint *)(uVar13 + 0x14);
              uVar10 = *puVar17;
              bVar22 = uVar10 == 0;
              if (bVar22) {
                puVar17 = (uint *)(uVar13 + 0x10);
                uVar10 = *puVar17;
              }
              if (bVar22 && uVar10 == 0) break;
              uVar13 = *puVar17;
              puVar12 = puVar17;
            }
            if (puVar12 < (uint *)puVar1[4]) goto LAB_080250f2;
            *puVar12 = 0;
          }
          else {
            uVar3 = *(uint *)(uVar20 + 8);
            uVar10 = puVar1[4];
            if (uVar10 <= uVar3) {
              bVar22 = *(uint *)(uVar3 + 0xc) == uVar20;
              if (bVar22) {
                uVar10 = *(uint *)(uVar13 + 8);
              }
              if (bVar22 && uVar10 == uVar20) {
                *(uint *)(uVar3 + 0xc) = uVar13;
                *(uint *)(uVar13 + 8) = uVar3;
                goto LAB_080250f6;
              }
            }
LAB_080250f2:
            FUN_0802f29a();
          }
LAB_080250f6:
          if (uVar18 != 0) {
            puVar12 = unaff_r8 + *(uint *)(uVar20 + 0x1c);
            if (uVar20 == *puVar12) {
              if (uVar13 != 0) {
                *puVar12 = uVar13;
                goto LAB_08025136;
              }
              puVar1[1] = puVar1[1] & ~(1 << (*(uint *)(uVar20 + 0x1c) & 0xff));
              *puVar12 = 0;
            }
            else {
              if (uVar18 < puVar1[4]) {
                FUN_0802f29a();
              }
              else if (*(uint *)(uVar18 + 0x10) == uVar20) {
                *(uint *)(uVar18 + 0x10) = uVar13;
              }
              else {
                *(uint *)(uVar18 + 0x14) = uVar13;
              }
              if (uVar13 != 0) {
LAB_08025136:
                uVar10 = puVar1[4];
                if (uVar13 < uVar10) {
LAB_08025170:
                  FUN_0802f29a();
                }
                else {
                  *(uint *)(uVar13 + 0x18) = uVar18;
                  uVar18 = *(uint *)(uVar20 + 0x10);
                  if (uVar18 != 0) {
                    if (uVar18 < uVar10) {
                      FUN_0802f29a();
                    }
                    else {
                      *(uint *)(uVar13 + 0x10) = uVar18;
                      *(uint *)(uVar18 + 0x18) = uVar13;
                    }
                  }
                  uVar18 = *(uint *)(uVar20 + 0x14);
                  if (uVar18 != 0) {
                    if (uVar18 < puVar1[4]) goto LAB_08025170;
                    *(uint *)(uVar13 + 0x14) = uVar18;
                    *(uint *)(uVar18 + 0x18) = uVar13;
                  }
                }
              }
            }
          }
          if (uVar9 < 0x10) {
            *(uint *)(uVar20 + 4) = uVar2 | 3;
            *(uint *)(uVar20 + 4 + uVar2) = *(uint *)(uVar20 + 4 + uVar2) | 1;
          }
          else {
            *(uint *)(uVar20 + 4) = uVar15 | 3;
            *(uint *)(uVar20 + 4 + uVar15) = uVar9 | 1;
            *(uint *)(uVar11 + uVar9) = uVar9;
            uVar2 = puVar1[2];
            uVar13 = uVar2 >> 3;
            if (0x1f < uVar13) {
              FUN_0802f29a();
            }
            if (uVar2 != 0) {
              uVar18 = puVar1[5];
              unaff_r8 = puVar1 + uVar13 * 2 + 10;
              if (uVar2 < 0x10) {
                FUN_0802f29a();
              }
              if ((int)((*puVar1 >> (uVar13 & 0xff)) << 0x1f) < 0) {
                puVar12 = (uint *)unaff_r8[2];
                if (puVar12 < (uint *)puVar1[4]) {
                  FUN_0802f29a();
                  puVar12 = unaff_r8;
                }
              }
              else {
                *puVar1 = 1 << (uVar13 & 0xff) | *puVar1;
                puVar12 = unaff_r8;
              }
              unaff_r8[2] = uVar18;
              puVar12[3] = uVar18;
              *(uint **)(uVar18 + 8) = puVar12;
              *(uint **)(uVar18 + 0xc) = unaff_r8;
            }
            puVar1[2] = uVar9;
            puVar1[5] = uVar11;
          }
joined_r0x08025612:
          if ((uint *)(uVar20 + 8) != (uint *)0x0) {
            return (uint *)(uVar20 + 8);
          }
          goto LAB_08025616;
        }
      }
LAB_0802521c:
      unaff_r8 = puVar1 + 0x4c;
      FUN_0802f29a();
      goto LAB_08025616;
    }
  }
  else {
    if (param_1 < 0xffffffc0) {
      uVar15 = param_1 + 0xb & 0xfffffff8;
      if (DAT_08024e6c[1] != 0) {
        uVar20 = 0;
        uVar2 = -uVar15;
        uVar9 = param_1 + 0xb >> 8;
        if (uVar9 == 0) {
          uVar9 = 0;
        }
        else if (uVar9 < 0x10000) {
          uVar11 = uVar9 - 0x100 >> 0x10 & 8;
          iVar8 = uVar9 << uVar11;
          uVar9 = iVar8 - 0x1000U >> 0x10 & 4;
          iVar8 = iVar8 << uVar9;
          uVar13 = iVar8 - 0x4000U >> 0x10 & 2;
          iVar8 = (((0xe - uVar11) - uVar9) - uVar13) + ((uint)(iVar8 << uVar13) >> 0xf);
          uVar9 = (uVar15 >> (iVar8 + 7U & 0xff) & 1) + iVar8 * 2;
        }
        else {
          uVar9 = 0x1f;
        }
        unaff_r8 = DAT_08024e6c + 0x4c;
        uVar11 = uVar2;
        if (unaff_r8[uVar9] == 0) {
LAB_080252f6:
          iVar8 = 1 << (uVar9 & 0xff);
          uVar2 = DAT_08024e6c[1] & (iVar8 * 2 | iVar8 * -2);
          if (uVar2 == 0) goto LAB_08025616;
          uVar18 = (uVar2 & -uVar2) - 1;
          uVar2 = uVar18 >> 0xc & 0x10;
          uVar18 = uVar18 >> uVar2;
          uVar9 = uVar18 >> 5 & 8;
          uVar18 = uVar18 >> uVar9;
          uVar13 = uVar18 >> 2 & 4;
          uVar18 = uVar18 >> uVar13;
          uVar10 = uVar18 >> 1 & 2;
          uVar18 = uVar18 >> uVar10;
          uVar3 = -((int)(uVar18 << 0x1e) >> 0x1f);
          uVar10 = unaff_r8[(uVar18 >> (uVar3 & 0xff)) + uVar10 + uVar13 + uVar9 + uVar2 + uVar3];
LAB_0802535e:
          for (; uVar10 != 0; uVar10 = *(uint *)(uVar10 + 0x14)) {
            while( true ) {
              uVar2 = (*(uint *)(uVar10 + 4) & 0xfffffff8) - uVar15;
              if (uVar2 < uVar11) {
                uVar20 = uVar10;
                uVar11 = uVar2;
              }
              if (*(uint *)(uVar10 + 0x10) == 0) break;
              uVar10 = *(uint *)(uVar10 + 0x10);
            }
          }
        }
        else {
          uVar13 = uVar15;
          if (uVar9 != 0x1f) {
            uVar13 = uVar15 << (0x19 - (uVar9 >> 1) & 0xff);
          }
          uVar11 = unaff_r8[uVar9];
          uVar18 = 0;
          while( true ) {
            uVar10 = uVar11;
            uVar11 = (*(uint *)(uVar10 + 4) & 0xfffffff8) - uVar15;
            if (uVar11 < uVar2) {
              uVar2 = uVar11;
              uVar20 = uVar10;
              if (uVar11 == 0) goto LAB_080252ec;
            }
            uVar3 = *(uint *)(uVar10 + 0x14);
            uVar11 = *(uint *)(uVar10 + 0x10 + ((int)uVar13 >> 0x1f) * -4);
            uVar10 = uVar18;
            if ((uVar3 != 0) && (uVar3 != uVar11)) {
              uVar10 = uVar3;
            }
            if (uVar11 == 0) break;
            uVar13 = uVar13 << 1;
            uVar18 = uVar10;
          }
          uVar11 = uVar2;
LAB_080252ec:
          if (uVar10 != 0) goto LAB_0802535e;
          if (uVar20 == 0) goto LAB_080252f6;
        }
        if ((uVar20 != 0) && (uVar11 < DAT_08024e6c[2] - uVar15)) {
          if (DAT_08024e6c[4] <= uVar20) {
            if ((*(uint *)(uVar20 + 4) & 0xfffffff8) != uVar15 + uVar11) {
              FUN_0802f29a();
            }
            uVar2 = uVar20 + uVar15;
            if (uVar20 < uVar2) {
              uVar9 = *(uint *)(uVar20 + 0xc);
              uVar13 = *(uint *)(uVar20 + 0x18);
              if (uVar9 == uVar20) {
                uVar9 = *(uint *)(uVar20 + 0x14);
                puVar12 = (uint *)(uVar20 + 0x14);
                if (uVar9 == 0) {
                  puVar12 = (uint *)(uVar20 + 0x10);
                  uVar9 = *puVar12;
                  if (uVar9 == 0) goto LAB_080253fc;
                }
                while( true ) {
                  puVar17 = (uint *)(uVar9 + 0x14);
                  uVar18 = *puVar17;
                  bVar22 = uVar18 == 0;
                  if (bVar22) {
                    puVar17 = (uint *)(uVar9 + 0x10);
                    uVar18 = *puVar17;
                  }
                  if (bVar22 && uVar18 == 0) break;
                  uVar9 = *puVar17;
                  puVar12 = puVar17;
                }
                if (puVar12 < (uint *)puVar1[4]) goto LAB_080253f8;
                *puVar12 = 0;
              }
              else {
                uVar10 = *(uint *)(uVar20 + 8);
                uVar18 = puVar1[4];
                if (uVar18 <= uVar10) {
                  bVar22 = *(uint *)(uVar10 + 0xc) == uVar20;
                  if (bVar22) {
                    uVar18 = *(uint *)(uVar9 + 8);
                  }
                  if (bVar22 && uVar18 == uVar20) {
                    *(uint *)(uVar10 + 0xc) = uVar9;
                    *(uint *)(uVar9 + 8) = uVar10;
                    goto LAB_080253fc;
                  }
                }
LAB_080253f8:
                FUN_0802f29a();
              }
LAB_080253fc:
              if (uVar13 != 0) {
                puVar12 = unaff_r8 + *(uint *)(uVar20 + 0x1c);
                if (uVar20 == *puVar12) {
                  if (uVar9 != 0) {
                    *puVar12 = uVar9;
                    goto LAB_08025434;
                  }
                  puVar1[1] = puVar1[1] & ~(1 << (*(uint *)(uVar20 + 0x1c) & 0xff));
                  *puVar12 = 0;
                }
                else {
                  if (uVar13 < puVar1[4]) {
                    FUN_0802f29a();
                  }
                  else if (*(uint *)(uVar13 + 0x10) == uVar20) {
                    *(uint *)(uVar13 + 0x10) = uVar9;
                  }
                  else {
                    *(uint *)(uVar13 + 0x14) = uVar9;
                  }
                  if (uVar9 != 0) {
LAB_08025434:
                    uVar18 = puVar1[4];
                    if (uVar9 < uVar18) {
LAB_0802546c:
                      FUN_0802f29a();
                    }
                    else {
                      *(uint *)(uVar9 + 0x18) = uVar13;
                      uVar13 = *(uint *)(uVar20 + 0x10);
                      if (uVar13 != 0) {
                        if (uVar13 < uVar18) {
                          FUN_0802f29a();
                        }
                        else {
                          *(uint *)(uVar9 + 0x10) = uVar13;
                          *(uint *)(uVar13 + 0x18) = uVar9;
                        }
                      }
                      uVar13 = *(uint *)(uVar20 + 0x14);
                      if (uVar13 != 0) {
                        if (uVar13 < puVar1[4]) goto LAB_0802546c;
                        *(uint *)(uVar9 + 0x14) = uVar13;
                        *(uint *)(uVar13 + 0x18) = uVar9;
                      }
                    }
                  }
                }
              }
              if (uVar11 < 0x10) {
                uVar11 = uVar11 + uVar15;
                *(uint *)(uVar20 + 4) = uVar11 | 3;
                *(uint *)(uVar20 + 4 + uVar11) = *(uint *)(uVar20 + 4 + uVar11) | 1;
              }
              else {
                *(uint *)(uVar20 + 4) = uVar15 | 3;
                *(uint *)(uVar20 + 4 + uVar15) = uVar11 | 1;
                uVar9 = uVar11 >> 3;
                *(uint *)(uVar2 + uVar11) = uVar11;
                if (uVar9 < 0x20) {
                  puVar12 = puVar1 + uVar9 * 2 + 10;
                  if ((int)((*puVar1 >> (uVar9 & 0xff)) << 0x1f) < 0) {
                    unaff_r8 = (uint *)puVar12[2];
                    if (unaff_r8 < (uint *)puVar1[4]) {
                      FUN_0802f29a();
                      unaff_r8 = puVar12;
                    }
                  }
                  else {
                    *puVar1 = 1 << (uVar9 & 0xff) | *puVar1;
                    unaff_r8 = puVar12;
                  }
                  puVar12[2] = uVar2;
                  unaff_r8[3] = uVar2;
                  *(uint **)(uVar20 + 8 + uVar15) = unaff_r8;
                  *(uint **)(uVar20 + 0xc + uVar15) = puVar12;
                }
                else {
                  uVar9 = uVar11 >> 8;
                  if (uVar9 == 0) {
                    uVar9 = 0;
                  }
                  else if (uVar9 < 0x10000) {
                    uVar13 = uVar9 - 0x100 >> 0x10 & 8;
                    iVar8 = uVar9 << uVar13;
                    uVar9 = iVar8 - 0x1000U >> 0x10 & 4;
                    iVar8 = iVar8 << uVar9;
                    uVar18 = iVar8 - 0x4000U >> 0x10 & 2;
                    iVar8 = (((0xe - uVar13) - uVar9) - uVar18) + ((uint)(iVar8 << uVar18) >> 0xf);
                    uVar9 = (uVar11 >> (iVar8 + 7U & 0xff) & 1) + iVar8 * 2;
                  }
                  else {
                    uVar9 = 0x1f;
                  }
                  *(uint *)(uVar2 + 0x1c) = uVar9;
                  *(undefined4 *)(uVar20 + 0x14 + uVar15) = 0;
                  puVar12 = unaff_r8 + uVar9;
                  *(undefined4 *)(uVar20 + 0x10 + uVar15) = 0;
                  if ((int)((puVar1[1] >> (uVar9 & 0xff)) << 0x1f) < 0) {
                    uVar13 = *puVar12;
                    if (uVar9 == 0x1f) {
                      uVar9 = uVar11;
                    }
                    else {
                      uVar9 = uVar11 << (0x19 - (uVar9 >> 1) & 0xff);
                    }
                    while ((*(uint *)(uVar13 + 4) & 0xfffffff8) != uVar11) {
                      puVar12 = (uint *)(uVar13 + 0x10 + ((int)uVar9 >> 0x1f) * -4);
                      if (*puVar12 == 0) {
                        if (puVar12 < (uint *)puVar1[4]) goto LAB_0802560a;
                        *puVar12 = uVar2;
                        *(uint *)(uVar2 + 0x18) = uVar13;
                        *(uint *)(uVar20 + 0xc + uVar15) = uVar2;
                        *(uint *)(uVar20 + 8 + uVar15) = uVar2;
                        goto joined_r0x08025612;
                      }
                      uVar9 = uVar9 << 1;
                      uVar13 = *puVar12;
                    }
                    uVar9 = *(uint *)(uVar13 + 8);
                    if (uVar13 < puVar1[4] || uVar9 < puVar1[4]) {
LAB_0802560a:
                      FUN_0802f29a();
                    }
                    else {
                      *(uint *)(uVar9 + 0xc) = uVar2;
                      *(uint *)(uVar13 + 8) = uVar2;
                      *(uint *)(uVar20 + 8 + uVar15) = uVar9;
                      *(uint *)(uVar20 + 0xc + uVar15) = uVar13;
                      *(undefined4 *)(uVar2 + 0x18) = 0;
                    }
                  }
                  else {
                    puVar1[1] = 1 << (uVar9 & 0xff) | puVar1[1];
                    *puVar12 = uVar2;
                    *(uint **)(uVar2 + 0x18) = puVar12;
                    *(uint *)(uVar20 + 0xc + uVar15) = uVar2;
                    *(uint *)(uVar20 + 8 + uVar15) = uVar2;
                  }
                }
              }
              goto joined_r0x08025612;
            }
          }
          goto LAB_0802521c;
        }
      }
    }
    else {
      uVar15 = 0xffffffff;
    }
LAB_08025616:
    uVar2 = puVar1[2];
    if (uVar15 <= uVar2) {
      uVar20 = uVar2 - uVar15;
      uVar9 = puVar1[5];
      if (uVar20 < 0x10) {
        puVar1[2] = 0;
        *(uint *)(uVar9 + 4) = uVar2 | 3;
        *(uint *)(uVar9 + 4 + uVar2) = *(uint *)(uVar9 + 4 + uVar2) | 1;
        uVar2 = 0;
      }
      else {
        puVar1[2] = uVar20;
        uVar2 = uVar9 + uVar15;
        *(uint *)(uVar9 + 4 + uVar15) = uVar20 | 1;
        *(uint *)(uVar2 + uVar20) = uVar20;
        *(uint *)(uVar9 + 4) = uVar15 | 3;
      }
      puVar1[5] = uVar2;
      goto LAB_08025d04;
    }
  }
  puVar12 = DAT_08026240;
  uVar2 = puVar1[3];
  if (uVar2 <= uVar15) {
    if (*DAT_08026240 == 0) {
      FUN_08024d78();
    }
    uVar2 = puVar12[2];
    uVar2 = uVar2 + uVar15 + 0x2f & ~(uVar2 - 1);
    if (uVar2 <= uVar15) {
      return (uint *)0x0;
    }
    puVar17 = puVar1 + 0x6c;
    if (puVar1[0x6e] != 0) {
      uVar2 = uVar2 + *puVar17;
      if (uVar2 <= *puVar17) {
        return (uint *)0x0;
      }
      if (puVar1[0x6e] < uVar2) {
        return (uint *)0x0;
      }
    }
    piVar4 = (int *)FUN_0802f2a0();
    if (piVar4 != (int *)0x0) {
      unaff_r8 = (uint *)*piVar4;
    }
    if (piVar4 == (int *)0x0 || piVar4 == (int *)0xffffffff) {
      return (uint *)0x0;
    }
    uVar20 = *puVar17 + (int)unaff_r8;
    uVar2 = puVar1[0x6d];
    if (puVar1[0x6d] <= uVar20) {
      uVar2 = uVar20;
    }
    puVar1[0x6d] = uVar2;
    *puVar17 = uVar20;
    piVar14 = (int *)puVar1[6];
    if (piVar14 != (int *)0x0) {
      puVar17 = puVar1 + 0x70;
      for (puVar12 = puVar17; puVar12 != (uint *)0x0; puVar12 = (uint *)puVar12[2]) {
        if (piVar4 == (int *)(puVar12[1] + *puVar12)) {
          if (((-1 < (int)((uint)(byte)puVar12[3] << 0x1c)) && ((int *)*puVar12 <= piVar14)) &&
             (piVar14 < (int *)((int)*puVar12 + puVar12[1]))) {
            puVar12[1] = puVar12[1] + (int)unaff_r8;
            puVar12 = (uint *)((int)unaff_r8 + puVar1[3]);
            goto LAB_08025746;
          }
          break;
        }
      }
      if (piVar4 < (int *)puVar1[4]) {
        puVar1[4] = (uint)piVar4;
      }
      while( true ) {
        if (puVar17 == (uint *)0x0) goto LAB_08025aee;
        if (*puVar17 == (int)piVar4 + (int)unaff_r8) break;
        puVar17 = (uint *)puVar17[2];
      }
      if ((int)((uint)(byte)puVar17[3] << 0x1c) < 0) goto LAB_08025aee;
      puVar12 = (uint *)*puVar17;
      *puVar17 = (uint)piVar4;
      puVar17[1] = puVar17[1] + (int)unaff_r8;
      if (((uint)(piVar4 + 2) & 7) != 0) {
        piVar4 = (int *)((int)piVar4 + (8U - (int)(piVar4 + 2) & 7));
      }
      if (((uint)(puVar12 + 2) & 7) != 0) {
        puVar12 = (uint *)((int)puVar12 + (8U - (int)(puVar12 + 2) & 7));
      }
      puVar17 = (uint *)((int)piVar4 + uVar15);
      uVar2 = (int)puVar12 + (-uVar15 - (int)piVar4);
      piVar4[1] = uVar15 | 3;
      if (puVar12 <= puVar17) {
        FUN_0802f29a();
      }
      if (-1 < (int)((uint)(byte)puVar12[1] << 0x1f)) {
        FUN_0802f29a();
      }
      if (uVar2 < 0x10) {
        FUN_0802f29a();
      }
      if (puVar12 == (uint *)puVar1[6]) {
        uVar15 = puVar1[3];
        puVar1[3] = uVar2 + uVar15;
        puVar1[6] = (uint)puVar17;
        puVar17[1] = uVar2 + uVar15 | 1;
        goto LAB_08025ae8;
      }
      if (puVar12 == (uint *)puVar1[5]) {
        puVar1[5] = (uint)puVar17;
        uVar2 = uVar2 + puVar1[2];
        puVar1[2] = uVar2;
        puVar17[1] = uVar2 | 1;
        *(uint *)((int)puVar17 + uVar2) = uVar2;
        goto LAB_08025ae8;
      }
      uVar15 = puVar12[1];
      if ((uVar15 & 3) != 1) goto LAB_0802599e;
      uVar20 = uVar15 >> 3;
      if (uVar20 < 0x20) {
        puVar19 = (uint *)puVar12[2];
        puVar16 = (uint *)puVar12[3];
        if (puVar12 == puVar16) {
          FUN_0802f29a();
        }
        if (puVar12 == puVar19) {
          FUN_0802f29a();
        }
        if ((puVar12[1] & 0xfffffff8) != uVar20 * 8) {
          FUN_0802f29a();
        }
        if ((puVar19 != puVar1 + uVar20 * 2 + 10) &&
           ((puVar19 < (uint *)puVar1[4] || ((uint *)puVar19[3] != puVar12)))) goto LAB_08025994;
        if (puVar16 == puVar19) {
          *puVar1 = *puVar1 & ~(1 << (uVar20 & 0xff));
          goto LAB_08025998;
        }
        if ((puVar16 != puVar1 + uVar20 * 2 + 10) &&
           ((puVar16 < (uint *)puVar1[4] || ((uint *)puVar16[2] != puVar12)))) goto LAB_08025994;
        puVar19[3] = (uint)puVar16;
        puVar16[2] = (uint)puVar19;
        goto LAB_08025998;
      }
      uVar20 = puVar12[6];
      puVar19 = (uint *)puVar12[3];
      if (puVar19 == puVar12) {
        puVar19 = (uint *)puVar12[5];
        puVar16 = puVar12 + 5;
        if (puVar19 != (uint *)0x0) goto LAB_080258f6;
        puVar16 = puVar12 + 4;
        puVar19 = (uint *)*puVar16;
        if (puVar19 == (uint *)0x0) goto LAB_0802591a;
LAB_080258f6:
        while( true ) {
          puVar5 = puVar19 + 5;
          uVar9 = *puVar5;
          bVar22 = uVar9 == 0;
          if (bVar22) {
            puVar5 = puVar19 + 4;
            uVar9 = *puVar5;
          }
          if (bVar22 && uVar9 == 0) break;
          puVar19 = (uint *)*puVar5;
          puVar16 = puVar5;
        }
        if (puVar16 < (uint *)puVar1[4]) {
LAB_08025916:
          FUN_0802f29a();
        }
        else {
          *puVar16 = 0;
        }
      }
      else {
        puVar5 = (uint *)puVar12[2];
        puVar16 = (uint *)puVar1[4];
        if (puVar5 < puVar16) goto LAB_08025916;
        if ((uint *)puVar5[3] == puVar12) {
          puVar16 = (uint *)puVar19[2];
        }
        if ((uint *)puVar5[3] != puVar12 || puVar16 != puVar12) goto LAB_08025916;
        puVar5[3] = (uint)puVar19;
        puVar19[2] = (uint)puVar5;
      }
LAB_0802591a:
      if (uVar20 == 0) goto LAB_08025998;
      puVar16 = puVar1 + puVar12[7] + 0x4c;
      if (puVar12 == (uint *)*puVar16) {
        if (puVar19 == (uint *)0x0) {
          puVar1[1] = puVar1[1] & ~(1 << (puVar12[7] & 0xff));
          *puVar16 = 0;
          goto LAB_08025998;
        }
        *puVar16 = (uint)puVar19;
      }
      else {
        if (uVar20 < puVar1[4]) {
          FUN_0802f29a();
        }
        else if (*(uint **)(uVar20 + 0x10) == puVar12) {
          *(uint **)(uVar20 + 0x10) = puVar19;
        }
        else {
          *(uint **)(uVar20 + 0x14) = puVar19;
        }
        if (puVar19 == (uint *)0x0) goto LAB_08025998;
      }
      puVar16 = (uint *)puVar1[4];
      if (puVar16 <= puVar19) {
        puVar19[6] = uVar20;
        puVar5 = (uint *)puVar12[4];
        if (puVar5 != (uint *)0x0) {
          if (puVar5 < puVar16) {
            FUN_0802f29a();
          }
          else {
            puVar19[4] = (uint)puVar5;
            puVar5[6] = (uint)puVar19;
          }
        }
        uVar20 = puVar12[5];
        if (uVar20 == 0) goto LAB_08025998;
        if (puVar1[4] <= uVar20) {
          puVar19[5] = uVar20;
          *(uint **)(uVar20 + 0x18) = puVar19;
          goto LAB_08025998;
        }
      }
LAB_08025994:
      FUN_0802f29a();
LAB_08025998:
      puVar12 = (uint *)((int)puVar12 + (uVar15 & 0xfffffff8));
      uVar2 = uVar2 + (uVar15 & 0xfffffff8);
LAB_0802599e:
      puVar12[1] = puVar12[1] & 0xfffffffe;
      puVar17[1] = uVar2 | 1;
      uVar15 = uVar2 >> 3;
      *(uint *)((int)puVar17 + uVar2) = uVar2;
      if (uVar15 < 0x20) {
        puVar12 = puVar1 + uVar15 * 2 + 10;
        if (uVar2 < 0x10) {
          FUN_0802f29a();
        }
        if ((int)((*puVar1 >> (uVar15 & 0xff)) << 0x1f) < 0) {
          puVar19 = (uint *)puVar12[2];
          if (puVar19 < (uint *)puVar1[4]) {
            FUN_0802f29a();
            puVar19 = puVar12;
          }
        }
        else {
          *puVar1 = 1 << (uVar15 & 0xff) | *puVar1;
          puVar19 = puVar12;
        }
        puVar12[2] = (uint)puVar17;
        puVar19[3] = (uint)puVar17;
        puVar17[2] = (uint)puVar19;
        puVar17[3] = (uint)puVar12;
      }
      else {
        uVar15 = uVar2 >> 8;
        if (uVar15 == 0) {
          uVar15 = 0;
        }
        else if (uVar15 < 0x10000) {
          uVar20 = uVar15 - 0x100 >> 0x10 & 8;
          iVar8 = uVar15 << uVar20;
          uVar15 = iVar8 - 0x1000U >> 0x10 & 4;
          iVar8 = iVar8 << uVar15;
          uVar9 = iVar8 - 0x4000U >> 0x10 & 2;
          iVar8 = (((0xe - uVar20) - uVar15) - uVar9) + ((uint)(iVar8 << uVar9) >> 0xf);
          uVar15 = (uVar2 >> (iVar8 + 7U & 0xff) & 1) + iVar8 * 2;
        }
        else {
          uVar15 = 0x1f;
        }
        puVar17[7] = uVar15;
        puVar17[5] = 0;
        puVar17[4] = 0;
        puVar12 = puVar1 + uVar15 + 0x4c;
        if ((int)((puVar1[1] >> (uVar15 & 0xff)) << 0x1f) < 0) {
          uVar20 = *puVar12;
          if (uVar15 == 0x1f) {
            uVar15 = uVar2;
          }
          else {
            uVar15 = uVar2 << (0x19 - (uVar15 >> 1) & 0xff);
          }
          while ((*(uint *)(uVar20 + 4) & 0xfffffff8) != uVar2) {
            puVar12 = (uint *)(uVar20 + 0x10 + ((int)uVar15 >> 0x1f) * -4);
            if (*puVar12 == 0) {
              if (puVar12 < (uint *)puVar1[4]) goto LAB_08025ae4;
              *puVar12 = (uint)puVar17;
              puVar17[6] = uVar20;
              goto LAB_08025ac0;
            }
            uVar15 = uVar15 << 1;
            uVar20 = *puVar12;
          }
          uVar15 = *(uint *)(uVar20 + 8);
          if (uVar20 < puVar1[4] || uVar15 < puVar1[4]) {
LAB_08025ae4:
            FUN_0802f29a();
          }
          else {
            *(uint **)(uVar15 + 0xc) = puVar17;
            *(uint **)(uVar20 + 8) = puVar17;
            puVar17[2] = uVar15;
            puVar17[3] = uVar20;
            puVar17[6] = 0;
          }
        }
        else {
          puVar1[1] = 1 << (uVar15 & 0xff) | puVar1[1];
          *puVar12 = (uint)puVar17;
          puVar17[6] = (uint)puVar12;
LAB_08025ac0:
          puVar17[3] = (uint)puVar17;
          puVar17[2] = (uint)puVar17;
        }
      }
LAB_08025ae8:
      return (uint *)(piVar4 + 2);
    }
    if (((int *)puVar1[4] == (int *)0x0) || (piVar4 < (int *)puVar1[4])) {
      puVar1[4] = (uint)piVar4;
    }
    puVar1[0x70] = (uint)piVar4;
    puVar1[0x71] = (uint)unaff_r8;
    puVar1[0x73] = 0;
    puVar1[9] = *puVar12;
    puVar1[8] = 0xffffffff;
    puVar12 = puVar1 + 10;
    uVar2 = 0;
    do {
      puVar12[2] = (uint)puVar12;
      puVar12[3] = (uint)puVar12;
      puVar12[5] = (uint)(puVar12 + 2);
      puVar12[4] = (uint)(puVar12 + 2);
      uVar2 = uVar2 + 2;
      puVar12 = puVar12 + 4;
    } while (uVar2 < 0x20);
    puVar12 = unaff_r8 + -10;
    piVar14 = piVar4;
LAB_08025746:
    FUN_08024da4(puVar1,piVar14,puVar12);
    goto LAB_08025ce8;
  }
  goto LAB_08025cee;
LAB_08025aee:
  piVar6 = (int *)FUN_08024d5c(puVar1,piVar14);
  piVar6 = (int *)(piVar6[1] + *piVar6);
  if (((int)piVar6 - 0x27U & 7) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 8 - ((int)piVar6 - 0x27U) & 7;
  }
  piVar21 = (int *)((int)piVar6 + (uVar2 - 0x2f));
  if (piVar21 < piVar14 + 4) {
    piVar21 = piVar14;
  }
  piVar7 = piVar21 + 6;
  local_2c = 0;
  FUN_08024da4(puVar1,piVar4,unaff_r8 + -10);
  if (((uint)(piVar21 + 2) & 7) != 0) {
    FUN_0802f29a();
  }
  piVar21[1] = 0x1b;
  uVar2 = puVar1[0x71];
  uVar20 = puVar1[0x72];
  uVar9 = puVar1[0x73];
  piVar21[2] = puVar1[0x70];
  piVar21[3] = uVar2;
  piVar21[4] = uVar20;
  piVar21[5] = uVar9;
  puVar1[0x73] = 0;
  puVar1[0x72] = (uint)(piVar21 + 2);
  puVar1[0x70] = (uint)piVar4;
  puVar1[0x71] = (uint)unaff_r8;
  while( true ) {
    local_2c = local_2c + 1;
    piVar7[1] = 7;
    if (piVar6 <= piVar7 + 2) break;
    piVar7 = piVar7 + 1;
  }
  if (local_2c < 2) {
    FUN_0802f29a();
  }
  if (piVar21 != piVar14) {
    uVar20 = (int)piVar21 - (int)piVar14;
    *(uint *)((int)piVar14 + uVar20 + 4) = *(uint *)((int)piVar14 + uVar20 + 4) & 0xfffffffe;
    piVar14[1] = uVar20 | 1;
    uVar2 = uVar20 >> 3;
    *(uint *)((int)piVar14 + uVar20) = uVar20;
    if (uVar2 < 0x20) {
      puVar12 = puVar1 + uVar2 * 2 + 10;
      if (uVar20 < 0x10) {
        FUN_0802f29a();
      }
      if ((int)((*puVar1 >> (uVar2 & 0xff)) << 0x1f) < 0) {
        puVar17 = (uint *)puVar12[2];
        if (puVar17 < (uint *)puVar1[4]) {
          FUN_0802f29a();
          puVar17 = puVar12;
        }
      }
      else {
        *puVar1 = *puVar1 | 1 << (uVar2 & 0xff);
        puVar17 = puVar12;
      }
      puVar12[2] = (uint)piVar14;
      puVar17[3] = (uint)piVar14;
      piVar14[2] = (int)puVar17;
      piVar14[3] = (int)puVar12;
    }
    else {
      uVar2 = uVar20 >> 8;
      if (uVar2 == 0) {
        uVar2 = 0;
      }
      else if (uVar2 < 0x10000) {
        uVar9 = uVar2 - 0x100 >> 0x10 & 8;
        iVar8 = uVar2 << uVar9;
        uVar2 = iVar8 - 0x1000U >> 0x10 & 4;
        iVar8 = iVar8 << uVar2;
        uVar11 = iVar8 - 0x4000U >> 0x10 & 2;
        iVar8 = (((0xe - uVar9) - uVar2) - uVar11) + ((uint)(iVar8 << uVar11) >> 0xf);
        uVar2 = (uVar20 >> (iVar8 + 7U & 0xff) & 1) + iVar8 * 2;
      }
      else {
        uVar2 = 0x1f;
      }
      piVar14[7] = uVar2;
      piVar14[5] = 0;
      piVar14[4] = 0;
      puVar12 = puVar1 + uVar2 + 0x4c;
      if ((int)((puVar1[1] >> (uVar2 & 0xff)) << 0x1f) < 0) {
        uVar9 = *puVar12;
        if (uVar2 == 0x1f) {
          uVar2 = uVar20;
        }
        else {
          uVar2 = uVar20 << (0x19 - (uVar2 >> 1) & 0xff);
        }
        while ((*(uint *)(uVar9 + 4) & 0xfffffff8) != uVar20) {
          puVar12 = (uint *)(uVar9 + 0x10 + ((int)uVar2 >> 0x1f) * -4);
          if (*puVar12 == 0) {
            if (puVar12 < (uint *)puVar1[4]) goto LAB_08025ce4;
            *puVar12 = (uint)piVar14;
            piVar14[6] = uVar9;
            goto LAB_08025cc4;
          }
          uVar2 = uVar2 << 1;
          uVar9 = *puVar12;
        }
        uVar2 = *(uint *)(uVar9 + 8);
        if (uVar9 < puVar1[4] || uVar2 < puVar1[4]) {
LAB_08025ce4:
          FUN_0802f29a();
        }
        else {
          *(int **)(uVar2 + 0xc) = piVar14;
          *(int **)(uVar9 + 8) = piVar14;
          piVar14[2] = uVar2;
          piVar14[3] = uVar9;
          piVar14[6] = 0;
        }
      }
      else {
        puVar1[1] = 1 << (uVar2 & 0xff) | puVar1[1];
        *puVar12 = (uint)piVar14;
        piVar14[6] = (int)puVar12;
LAB_08025cc4:
        piVar14[3] = (int)piVar14;
        piVar14[2] = (int)piVar14;
      }
    }
  }
LAB_08025ce8:
  uVar2 = puVar1[3];
  if (uVar2 <= uVar15) {
    return (uint *)0x0;
  }
LAB_08025cee:
  uVar9 = puVar1[6];
  puVar1[3] = uVar2 - uVar15;
  puVar1[6] = uVar9 + uVar15;
  *(uint *)(uVar9 + uVar15 + 4) = uVar2 - uVar15 | 1;
  *(uint *)(uVar9 + 4) = uVar15 | 3;
LAB_08025d04:
  return (uint *)(uVar9 + 8);
}



/* ===== FUN_08025d1c @ 08025d1c ===== */

void FUN_08025d1c(int param_1)

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
  
  puVar1 = DAT_0802624c;
  puVar10 = (uint *)(param_1 + -8);
  puVar6 = (uint *)DAT_0802624c[4];
  if ((puVar10 < puVar6) || (uVar2 = *(uint *)(param_1 + -4), (uVar2 & 3) == 1)) goto LAB_0802623a;
  uVar12 = uVar2 & 0xfffffff8;
  puVar7 = (uint *)(uVar2 << 0x1f);
  puVar11 = (uint *)((int)puVar10 + uVar12);
  if ((int)puVar7 < 0) goto LAB_08025dc2;
  uVar9 = *puVar10;
  if ((uVar2 & 3) == 0) {
    return;
  }
  puVar10 = (uint *)((int)puVar10 - uVar9);
  uVar12 = uVar12 + uVar9;
  if (puVar10 < puVar6) goto LAB_0802623a;
  if (puVar10 == (uint *)DAT_0802624c[5]) {
    if ((puVar11[1] & 3) == 3) {
      DAT_0802624c[2] = uVar12;
      puVar11[1] = puVar11[1] & 0xfffffffe;
      puVar10[1] = uVar12 | 1;
      goto LAB_08025f62;
    }
    goto LAB_08025dc2;
  }
  uVar9 = uVar9 >> 3;
  if (uVar9 < 0x20) {
    puVar7 = (uint *)puVar10[3];
    puVar6 = (uint *)puVar10[2];
    if (puVar10 == puVar7) {
      FUN_0802f29a();
    }
    if (puVar10 == puVar6) {
      FUN_0802f29a();
    }
    if ((puVar10[1] & 0xfffffff8) != uVar9 * 8) {
      FUN_0802f29a();
    }
    if ((puVar6 == puVar1 + uVar9 * 2 + 10) ||
       (((uint *)puVar1[4] <= puVar6 && ((uint *)puVar6[3] == puVar10)))) {
      if (puVar7 == puVar6) {
        *puVar1 = *puVar1 & ~(1 << (uVar9 & 0xff));
      }
      else {
        if ((puVar7 != puVar1 + uVar9 * 2 + 10) &&
           ((puVar7 < (uint *)puVar1[4] || ((uint *)puVar7[2] != puVar10)))) goto LAB_08025e52;
        puVar6[3] = (uint)puVar7;
        puVar7[2] = (uint)puVar6;
      }
      goto LAB_08025dc2;
    }
    goto LAB_08025e52;
  }
  puVar4 = (uint *)puVar10[3];
  uVar2 = puVar10[6];
  if (puVar4 == puVar10) {
    puVar4 = (uint *)puVar10[5];
    puVar7 = puVar10 + 5;
    if (puVar4 == (uint *)0x0) {
      puVar7 = puVar10 + 4;
      puVar4 = (uint *)*puVar7;
      if (puVar4 == (uint *)0x0) goto LAB_08025eb0;
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
    if (puVar7 < puVar6) goto LAB_08025eac;
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
        goto LAB_08025eb0;
      }
    }
LAB_08025eac:
    FUN_0802f29a();
  }
LAB_08025eb0:
  if (uVar2 != 0) {
    puVar6 = puVar1 + puVar10[7] + 0x4c;
    if (puVar10 == (uint *)*puVar6) {
      if (puVar4 == (uint *)0x0) {
        puVar1[1] = puVar1[1] & ~(1 << (puVar10[7] & 0xff));
        *puVar6 = 0;
      }
      else {
        *puVar6 = (uint)puVar4;
LAB_08025eee:
        puVar6 = (uint *)puVar1[4];
        if (puVar4 < puVar6) {
LAB_08025e52:
          FUN_0802f29a();
        }
        else {
          puVar4[6] = uVar2;
          puVar7 = (uint *)puVar10[4];
          if (puVar7 != (uint *)0x0) {
            if (puVar7 < puVar6) {
              FUN_0802f29a();
            }
            else {
              puVar4[4] = (uint)puVar7;
              puVar7[6] = (uint)puVar4;
            }
          }
          uVar2 = puVar10[5];
          if (uVar2 != 0) {
            if (uVar2 < puVar1[4]) goto LAB_08025e52;
            puVar4[5] = uVar2;
            *(uint **)(uVar2 + 0x18) = puVar4;
          }
        }
      }
    }
    else {
      if (uVar2 < puVar1[4]) {
        FUN_0802f29a();
      }
      else if (*(uint **)(uVar2 + 0x10) == puVar10) {
        *(uint **)(uVar2 + 0x10) = puVar4;
      }
      else {
        *(uint **)(uVar2 + 0x14) = puVar4;
      }
      if (puVar4 != (uint *)0x0) goto LAB_08025eee;
    }
  }
LAB_08025dc2:
  if ((puVar11 <= puVar10) || (uVar2 = puVar11[1], -1 < (int)(uVar2 << 0x1f))) {
LAB_0802623a:
    FUN_0802f29a();
    return;
  }
  if ((int)(uVar2 << 0x1e) < 0) {
    puVar11[1] = uVar2 & 0xfffffffe;
    puVar10[1] = uVar12 | 1;
    *(uint *)((int)puVar10 + uVar12) = uVar12;
    goto LAB_080260ec;
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
    if (*DAT_08026240 == 0) {
      FUN_08024d78();
    }
    if (puVar1[6] == 0) {
      return;
    }
    if (0x28 < puVar1[3]) {
      FUN_08024d5c(puVar1);
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
LAB_08025f62:
    *(uint *)((int)puVar10 + uVar12) = uVar12;
    return;
  }
  uVar12 = uVar12 + (uVar2 & 0xfffffff8);
  uVar2 = uVar2 >> 3;
  if (uVar2 < 0x20) {
    puVar7 = (uint *)puVar11[3];
    puVar6 = (uint *)puVar11[2];
    if (puVar11 == puVar7) {
      FUN_0802f29a();
    }
    if (puVar11 == puVar6) {
      FUN_0802f29a();
    }
    if ((puVar11[1] & 0xfffffff8) != uVar2 * 8) {
      FUN_0802f29a();
    }
    if ((puVar6 != puVar1 + uVar2 * 2 + 10) &&
       ((puVar6 < (uint *)puVar1[4] || ((uint *)puVar6[3] != puVar11)))) goto LAB_080260c0;
    if (puVar7 == puVar6) {
      *puVar1 = *puVar1 & ~(1 << (uVar2 & 0xff));
    }
    else {
      if ((puVar7 != puVar1 + uVar2 * 2 + 10) &&
         ((puVar7 < (uint *)puVar1[4] || ((uint *)puVar7[2] != puVar11)))) goto LAB_080260c0;
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
        if (puVar6 == (uint *)0x0) goto LAB_0802604c;
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
      if (puVar7 < (uint *)puVar1[4]) goto LAB_08026048;
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
          goto LAB_0802604c;
        }
      }
LAB_08026048:
      FUN_0802f29a();
    }
LAB_0802604c:
    if (uVar2 != 0) {
      puVar7 = puVar1 + puVar11[7] + 0x4c;
      if (puVar11 == (uint *)*puVar7) {
        if (puVar6 == (uint *)0x0) {
          puVar1[1] = puVar1[1] & ~(1 << (puVar11[7] & 0xff));
          *puVar7 = 0;
        }
        else {
          *puVar7 = (uint)puVar6;
LAB_08026088:
          puVar7 = (uint *)puVar1[4];
          if (puVar6 < puVar7) {
LAB_080260c0:
            FUN_0802f29a();
          }
          else {
            puVar6[6] = uVar2;
            puVar4 = (uint *)puVar11[4];
            if (puVar4 != (uint *)0x0) {
              if (puVar4 < puVar7) {
                FUN_0802f29a();
              }
              else {
                puVar6[4] = (uint)puVar4;
                puVar4[6] = (uint)puVar6;
              }
            }
            uVar2 = puVar11[5];
            if (uVar2 != 0) {
              if (uVar2 < puVar1[4]) goto LAB_080260c0;
              puVar6[5] = uVar2;
              *(uint **)(uVar2 + 0x18) = puVar6;
            }
          }
        }
      }
      else {
        if (uVar2 < puVar1[4]) {
          FUN_0802f29a();
        }
        else if (*(uint **)(uVar2 + 0x10) == puVar11) {
          *(uint **)(uVar2 + 0x10) = puVar6;
        }
        else {
          *(uint **)(uVar2 + 0x14) = puVar6;
        }
        if (puVar6 != (uint *)0x0) goto LAB_08026088;
      }
    }
  }
  puVar10[1] = uVar12 | 1;
  *(uint *)((int)puVar10 + uVar12) = uVar12;
  if (puVar10 == (uint *)puVar1[5]) {
    puVar1[2] = uVar12;
    return;
  }
LAB_080260ec:
  uVar2 = uVar12 >> 3;
  if (uVar2 < 0x20) {
    puVar6 = puVar1 + uVar2 * 2 + 10;
    if (uVar12 < 0x10) {
      FUN_0802f29a();
    }
    if ((int)((*puVar1 >> (uVar2 & 0xff)) << 0x1f) < 0) {
      puVar7 = (uint *)puVar6[2];
      if (puVar7 < (uint *)puVar1[4]) {
        FUN_0802f29a();
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
    puVar10[5] = 0;
    puVar10[4] = 0;
    puVar10[7] = uVar2;
    puVar6 = puVar1 + uVar2 + 0x4c;
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
          if (puVar6 < (uint *)puVar1[4]) goto LAB_08026214;
          *puVar6 = (uint)puVar10;
          puVar10[6] = uVar9;
          goto LAB_080261f4;
        }
        uVar2 = uVar2 << 1;
        uVar9 = *puVar6;
      }
      uVar2 = *(uint *)(uVar9 + 8);
      if (uVar9 < puVar1[4] || uVar2 < puVar1[4]) {
LAB_08026214:
        FUN_0802f29a();
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
LAB_080261f4:
      puVar10[3] = (uint)puVar10;
      puVar10[2] = (uint)puVar10;
    }
    uVar2 = puVar1[8] - 1;
    if (uVar2 == 0) {
      puVar1[8] = 0;
      for (uVar2 = puVar1[0x72]; uVar2 != 0; uVar2 = *(uint *)(uVar2 + 8)) {
      }
      uVar2 = 0xffffffff;
    }
    puVar1[8] = uVar2;
  }
  return;
}



/* ===== FUN_08026250 @ 08026250 ===== */

undefined8
FUN_08026250(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = DAT_08026284;
  *(char *)(param_1 + 1) = (char)param_2;
  FUN_0801566a(param_2);
  FUN_08015672(param_2,param_1 + 2,param_1 + 3);
  param_1[4] = 0;
  *(undefined1 *)(param_1 + 6) = 0;
  *(undefined1 *)((int)param_1 + 0x17) = 0;
  *(undefined1 *)((int)param_1 + 0x16) = 0;
  *(undefined1 *)((int)param_1 + 0x15) = 0;
  *(undefined1 *)(param_1 + 5) = 1;
  return CONCAT44(param_4,param_1);
}



/* ===== FUN_080262b0 @ 080262b0 ===== */

undefined8 FUN_080262b0(uint param_1,uint param_2,byte param_3)

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



/* ===== FUN_080262d4 @ 080262d4 ===== */

void FUN_080262d4(undefined4 *param_1,undefined4 *param_2,uint param_3)

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



/* ===== FUN_080262f4 @ 080262f4 ===== */

void FUN_080262f4(undefined4 *param_1,undefined4 *param_2,uint param_3)

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



/* ===== FUN_0802637a @ 0802637a ===== */

uint FUN_0802637a(uint *param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,
                 uint param_6,uint param_7)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  if (param_1[0x16] == 0) {
    *param_1 = *param_1 | 8;
  }
  FUN_080262d4(param_1 + 0x17,param_2,0x10);
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
  puVar3 = (uint *)(param_1[0x14] + uVar1 * 0x20);
  uVar2 = param_1[0x18];
  *puVar3 = param_1[0x17];
  puVar3[1] = uVar2;
  puVar3[2] = param_3;
  param_1[0x15] = uVar1;
  puVar3[3] = param_4;
  puVar3[6] = param_7;
  puVar3[4] = param_5;
  puVar3[5] = param_6;
  return param_4;
}



/* ===== FUN_080263ea @ 080263ea ===== */

undefined4 FUN_080263ea(int param_1,undefined4 param_2,undefined4 param_3)

{
  while (0x1c < *(int *)(param_1 + 8)) {
    FUN_080184bc(param_1);
  }
  FUN_08027170(param_1,param_2,param_3);
  return 0;
}



/* ===== FUN_08026410 @ 08026410 ===== */

int FUN_08026410(uint *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  undefined1 *puVar8;
  undefined1 auStack_44 [32];
  
  iVar5 = 0;
LAB_08026424:
  do {
    if ((int)param_1[0x16] < 1) {
      return iVar5;
    }
    iVar1 = param_1[0x15] - param_1[0x16];
    iVar2 = iVar1 + 1;
    if (iVar2 < 0) {
      iVar2 = iVar1 + 9;
    }
    puVar6 = (uint *)(param_1[0x14] + iVar2 * 0x20);
    uVar3 = *puVar6 - *DAT_0802650c;
    iVar1 = (puVar6[1] - DAT_0802650c[1]) - (uint)(*puVar6 < *DAT_0802650c);
    if (iVar1 < 0) {
      uVar7 = -uVar3;
      iVar2 = -iVar1 - (uint)(uVar3 != 0);
    }
    else {
      uVar7 = uVar3;
      iVar2 = iVar1;
    }
    if ((iVar2 < 0xa3) || ((iVar2 < 0xa4 && (uVar7 < DAT_08026510)))) {
      uVar4 = FUN_08017e58(uVar3,iVar1,10000,4);
      if (param_1[0x1b] == 0) {
        puVar8 = (undefined1 *)puVar6[2];
      }
      else {
        FUN_080168e8(auStack_44,0x1f,DAT_08026518);
        puVar8 = auStack_44;
      }
      if (param_3 < 0x100) {
        disableIRQinterrupts();
        uVar3 = DAT_08026514[1];
        enableIRQinterrupts();
        param_1[0x17] = *DAT_08026514;
        param_1[0x18] = uVar3;
        *param_1 = *param_1 | 8;
        return iVar5;
      }
      iVar2 = FUN_080168e8(param_2,10,DAT_0802651c,uVar4);
      iVar1 = FUN_080168e8(param_2 + iVar2,0xf3,puVar8,puVar6[3],puVar6[4],puVar6[5],puVar6[6]);
      iVar1 = param_2 + iVar2 + iVar1;
      iVar2 = FUN_080168e8(iVar1,3,DAT_08026520);
      iVar1 = iVar1 + iVar2;
      iVar5 = iVar5 + (iVar1 - param_2);
      param_3 = param_3 - (iVar1 - param_2);
      if (param_1[0x1b] != 0) {
        param_1[0x1b] = 0;
        param_2 = iVar1;
        goto LAB_08026424;
      }
    }
    else {
      param_1[0x1b] = param_1[0x1b] + 1;
      iVar1 = param_2;
    }
    param_1[0x16] = param_1[0x16] - 1;
    param_2 = iVar1;
  } while( true );
}



/* ===== FUN_08026894 @ 08026894 ===== */

char * FUN_08026894(int *param_1,char *param_2,int param_3)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  char *pcVar11;
  uint *puVar12;
  int iVar13;
  int iVar14;
  
  puVar12 = DAT_08026aec;
  while( true ) {
    iVar13 = param_1[2];
    if (iVar13 < 1) {
      return (char *)0x0;
    }
    iVar14 = *param_1;
    iVar3 = (param_1[1] - iVar13) + 1;
    if (iVar3 < 0) {
      iVar3 = (param_1[1] - iVar13) + 0x21;
    }
    iVar3 = iVar3 * 0x24;
    uVar9 = *(uint *)(iVar14 + iVar3);
    uVar4 = *puVar12;
    uVar5 = uVar9 - uVar4;
    iVar7 = (((uint *)(iVar14 + iVar3))[1] - puVar12[1]) - (uint)(uVar9 < uVar4);
    if (iVar7 < 0) {
      uVar4 = -uVar5;
      iVar10 = -iVar7 - (uint)(uVar5 != 0);
    }
    else {
      uVar4 = uVar5;
      iVar10 = iVar7;
    }
    if ((iVar10 < 0xa4) && ((iVar10 < 0xa3 || (uVar4 < DAT_08026af0)))) break;
    param_1[2] = iVar13 + -1;
  }
  uVar6 = FUN_08017e58(uVar5,iVar7,10000,4);
  pcVar11 = DAT_08026af4;
  puVar12 = (uint *)(iVar14 + iVar3);
  iVar13 = FUN_0802f2cc(DAT_08026af4 + 1,puVar12);
  if (iVar13 < 1) {
    param_1[2] = param_1[2] + -1;
    return (char *)0x0;
  }
  if (param_3 - 0xdU < (uint)(iVar13 << 1)) {
    return (char *)0x0;
  }
  *(undefined4 *)(param_2 + 3) = uVar6;
  cVar2 = *pcVar11 + '\x01';
  *pcVar11 = cVar2;
  *param_2 = cVar2;
  cVar2 = *(char *)(DAT_08026af8 + (uint)*(byte *)(iVar14 + 8 + iVar3) * 2);
  param_2[2] = cVar2;
  if ((cVar2 != '\a') && (1 < param_1[2])) {
    puVar8 = puVar12 + 9;
    if ((uint *)(*param_1 + 0x480) <= puVar8) {
      puVar8 = puVar12 + -0x117;
    }
    if (*(char *)(DAT_08026af8 + (uint)(byte)puVar8[2] * 2) == cVar2) {
      uVar4 = *puVar8 - *puVar12;
      iVar3 = (puVar8[1] - puVar12[1]) - (uint)(*puVar8 < *puVar12);
      if ((((-1 < iVar3) && (iVar3 < 0x148)) && ((iVar3 < 0x147 || (uVar4 < DAT_08026afc)))) &&
         (lVar1 = (ulonglong)uVar4 * 0x19, uVar4 = (uint)lVar1,
         iVar3 = iVar3 * 0x19 + (int)((ulonglong)lVar1 >> 0x20) + (uint)(0xffffefff < uVar4),
         -1 < iVar3 >> 0xd)) {
        *(uint *)(param_2 + 9) = uVar4 + 0x1000 >> 0xd | iVar3 * 0x80000;
        param_2[1] = '\x01';
        iVar14 = FUN_08017eaa(param_2 + 0xd,puVar12,iVar13);
        iVar3 = DAT_08026af8;
        pcVar11 = param_2 + 0xd + iVar14;
        param_1[2] = param_1[2] + -1;
        param_2[7] = '\x01';
        param_2[8] = '\0';
        do {
          if ((char)puVar8[2] != '\b') {
            FUN_080262d4(pcVar11,(int)puVar8 + 10,iVar13);
            pcVar11 = pcVar11 + iVar13;
          }
          uVar4 = *puVar8;
          uVar5 = puVar8[1];
          iVar14 = param_1[2];
          param_1[2] = iVar14 + -1;
          *(short *)(param_2 + 7) = *(short *)(param_2 + 7) + 1;
          if ((iVar14 + -1 < 1) || (param_2 + (param_3 - iVar13) <= pcVar11)) break;
          puVar12 = puVar8 + 9;
          if ((uint *)(*param_1 + 0x480) <= puVar12) {
            puVar12 = puVar8 + -0x117;
          }
          if (*(char *)(iVar3 + (uint)(byte)puVar12[2] * 2) != cVar2) break;
          uVar9 = *puVar12 - uVar4;
          iVar14 = (puVar12[1] - uVar5) - (uint)(*puVar12 < uVar4);
          if (((iVar14 < 0) || (0x147 < iVar14)) || ((0x146 < iVar14 && (DAT_08026afc <= uVar9)))) {
            uVar4 = 0xffffffff;
            iVar14 = -1;
          }
          else {
            lVar1 = (ulonglong)uVar9 * 0x19;
            uVar4 = (uint)lVar1;
            iVar14 = iVar14 * 0x19 + (int)((ulonglong)lVar1 >> 0x20) + (uint)(0xffffefff < uVar4);
            uVar4 = uVar4 + 0x1000 >> 0xd | iVar14 * 0x80000;
            iVar14 = iVar14 >> 0xd;
          }
          puVar8 = puVar12;
        } while (iVar14 == 0 && *(uint *)(param_2 + 9) == uVar4);
        return pcVar11 + -(int)param_2;
      }
    }
  }
  param_2[1] = '\0';
  iVar13 = FUN_08017eaa(param_2 + 7,puVar12,iVar13);
  param_1[2] = param_1[2] + -1;
  return param_2 + 7 + (iVar13 - (int)param_2);
}



/* ===== FUN_08026b00 @ 08026b00 ===== */

int FUN_08026b00(int *param_1)

{
  int iVar1;
  
  iVar1 = (param_1[1] - param_1[2]) + 1;
  if (iVar1 < 0) {
    iVar1 = (param_1[1] - param_1[2]) + 0x21;
  }
  return *param_1 + iVar1 * 0x24;
}



/* ===== FUN_08026b18 @ 08026b18 ===== */

undefined8 FUN_08026b18(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 in_r3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  short local_50 [2];
  uint local_4c;
  int local_48;
  undefined4 uStack_28;
  
  iVar3 = DAT_08026c98;
  uVar4 = 0;
  uStack_28 = in_r3;
  FUN_080270fa();
  uVar7 = 0x2000000;
  iVar5 = 0;
  uVar10 = 0;
  uVar8 = DAT_0802f504;
  do {
    FUN_08026d9e(uVar8,0x28,local_50);
    uVar2 = DAT_0802f504;
    if (((local_50[0] != -1) && (local_48 != -1 || local_4c != 0xffffffff)) &&
       ((iVar5 < local_48 || ((iVar5 <= local_48 && (uVar4 < local_4c)))))) {
      uVar4 = local_4c;
      iVar5 = local_48;
      uVar7 = uVar8;
    }
    uVar10 = uVar10 + 1;
    uVar8 = uVar8 + 0x1000;
  } while (uVar10 < 2000);
  if (uVar7 < 0x2000000) {
    uVar9 = 1;
    iVar11 = 1999;
    bVar1 = false;
    uVar8 = uVar7;
    uVar10 = uVar7;
    do {
      uVar6 = uVar8 - 0x1000;
      if ((int)uVar6 < (int)uVar2) {
        uVar6 = uVar8 + 0x7cf000;
      }
      FUN_08026d9e(uVar6,0x28,local_50);
      if ((local_50[0] == -1) || (local_48 == -1 && local_4c == 0xffffffff)) {
        if (!bVar1) {
          bVar1 = true;
        }
      }
      else {
        if (!bVar1) {
          if ((local_48 <= iVar5) && ((local_48 < iVar5 || (local_4c < uVar4)))) {
            uVar9 = uVar9 + 1;
            uVar4 = local_4c;
            iVar5 = local_48;
            uVar10 = uVar6;
            goto LAB_0802f3d0;
          }
          bVar1 = true;
        }
        FUN_08026fa2(uVar6);
      }
LAB_0802f3d0:
      iVar11 = iVar11 + -1;
      uVar8 = uVar6;
    } while (iVar11 != 0);
    *(undefined4 *)(iVar3 + 4) = 0x2000000;
    *(undefined4 *)(iVar3 + 8) = 0x2000000;
    if (uVar9 < 3) {
      iVar5 = 0;
    }
    else {
      iVar5 = (uVar9 - 2) * 0xff0;
    }
    *(int *)(iVar3 + 0xc) = iVar5;
    iVar5 = DAT_0802f508;
    if (1 < uVar9) {
      iVar11 = uVar9 - 1;
      do {
        FUN_080312a8(iVar3,uVar10);
        if ((uint)(*(int *)(iVar3 + 8) + iVar5) < 0x7d0000) break;
        FUN_08026fa2(uVar10);
        uVar10 = uVar7 + 0x1000;
        if (0x1ffffff < uVar7 + 0x1000) {
          uVar10 = uVar2;
        }
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
    }
    iVar5 = FUN_080312a8(iVar3,uVar7);
    if (iVar5 == 0x1000) {
      uVar4 = uVar7 + 0x1000;
      if (0x1ffffff < uVar7 + 0x1000) {
        uVar4 = uVar2;
      }
      *(uint *)(iVar3 + 4) = uVar4;
    }
    if ((*(uint *)(iVar3 + 8) < 0x2000000) && (0x27 < *(uint *)(iVar3 + 0xc))) {
      uVar4 = *(uint *)(iVar3 + 4);
      if (uVar4 == *(uint *)(iVar3 + 8)) {
        *(undefined4 *)(iVar3 + 0xc) = DAT_0802f50c;
      }
      iVar3 = uVar4 - 0x28;
      if (((uVar4 & 0xfff) == 0) && (iVar3 = uVar4 - 0x38, iVar3 < (int)uVar2)) {
        iVar3 = uVar4 + 0x7cffc8;
      }
      FUN_08026d9e(iVar3,0x28,local_50);
      FUN_08027126();
      return CONCAT44(local_48,local_4c);
    }
    *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 4);
  }
  else {
    *(uint *)(iVar3 + 4) = DAT_0802f504;
    *(uint *)(iVar3 + 8) = uVar2;
  }
  *(undefined4 *)(iVar3 + 0xc) = 0;
  FUN_08027126();
  return 0;
}



/* ===== FUN_08026b1e @ 08026b1e ===== */

void FUN_08026b1e(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  undefined2 local_38;
  undefined2 local_36;
  undefined1 auStack_34 [36];
  undefined4 uStack_10;
  
  puVar2 = DAT_08026c98;
  if ((((*(uint *)(DAT_08026c98 + 4) & 0xfff) == 0) &&
      ((*(uint *)(DAT_08026c98 + 4) & 0xfffff000) == (*(uint *)(DAT_08026c98 + 8) & 0xfffff000))) &&
     (piVar1 = (int *)(DAT_08026c98 + 0xc), 0 < *piVar1)) {
    *DAT_08026c98 = 1;
    uVar4 = *(int *)(puVar2 + 8) + 0x1000;
    *(int *)(puVar2 + 0xc) = *(int *)(puVar2 + 8) + (*piVar1 - *(int *)(puVar2 + 4)) + -0xff0;
    if (0x1ffffff < uVar4) {
      uVar4 = DAT_08026c9c;
    }
    *(uint *)(puVar2 + 8) = uVar4 & 0xfffff000;
  }
  uStack_10 = param_4;
  FUN_080262d4(auStack_34,param_1,0x24);
  local_36 = FUN_0802f510(puVar2,param_1);
  local_38 = 0xa5;
  FUN_080270fa();
  iVar3 = FUN_08026e02(*(undefined4 *)(puVar2 + 4),0x28,&local_38);
  FUN_08027126();
  if (iVar3 != 0) {
    FUN_080167da();
    return;
  }
  uVar4 = *(int *)(puVar2 + 4) + 0x28;
  if ((uVar4 & 0xfff) == 0) {
    if (0x1ffffff < uVar4) {
      uVar4 = DAT_08026c9c;
    }
  }
  else if (0x1000 - (uVar4 & 0xfff) < 0x28) {
    uVar4 = *(int *)(puVar2 + 4) + 0x1028;
    if (0x1ffffff < uVar4) {
      uVar4 = DAT_08026c9c;
    }
    uVar4 = uVar4 & 0xfffff000;
  }
  *(uint *)(puVar2 + 4) = uVar4;
  *(int *)(puVar2 + 0xc) = *(int *)(puVar2 + 0xc) + 0x28;
  return;
}



/* ===== FUN_08026bdc @ 08026bdc ===== */

undefined4 FUN_08026bdc(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  short local_38;
  ushort local_36;
  undefined1 auStack_34 [36];
  
  iVar1 = DAT_08026c98;
  uVar4 = 1;
  if (*(int *)(DAT_08026c98 + 0xc) == 0) {
    return 1;
  }
  FUN_08026d9e(*(undefined4 *)(DAT_08026c98 + 8),0x28,&local_38);
  if ((local_38 == 0xa5) && (uVar2 = FUN_0802f510(iVar1,auStack_34), local_36 == uVar2)) {
    FUN_080262d4(param_1,auStack_34,0x24);
    uVar4 = 0;
    local_38 = 0;
    FUN_08026eaa(*(undefined4 *)(iVar1 + 8),2,&local_38);
  }
  uVar2 = *(int *)(iVar1 + 8) + 0x28;
  if ((uVar2 & 0xfff) == 0) {
    if (0x1ffffff < uVar2) {
      uVar2 = DAT_08026c9c;
    }
  }
  else {
    if (0x27 < 0x1000 - (uVar2 & 0xfff)) {
      *(uint *)(iVar1 + 8) = uVar2;
      goto LAB_08026c56;
    }
    uVar2 = *(int *)(iVar1 + 8) + 0x1028;
    if (0x1ffffff < uVar2) {
      uVar2 = DAT_08026c9c;
    }
    uVar2 = uVar2 & 0xfffff000;
  }
  *(uint *)(iVar1 + 8) = uVar2;
  uVar2 = *(int *)(iVar1 + 8) - 0x1000;
  if ((int)uVar2 < (int)DAT_08026c9c) {
    uVar2 = *(int *)(iVar1 + 8) + 0x7cf000;
  }
  FUN_08026fa2(uVar2 & 0xfffff000);
LAB_08026c56:
  if (*(int *)(iVar1 + 8) == *(int *)(iVar1 + 4)) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(iVar1 + 0xc) + -0x28;
  }
  *(int *)(iVar1 + 0xc) = iVar3;
  return uVar4;
}



/* ===== FUN_08026c8c @ 08026c8c ===== */

uint FUN_08026c8c(void)

{
  return -(uint)(*(int *)(DAT_08026c98 + 0xc) == 0) >> 0x1f;
}



/* ===== FUN_08026ca0 @ 08026ca0 ===== */

uint FUN_08026ca0(uint param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_0802714c;
  *DAT_0802714c = *DAT_0802714c | param_1;
  return param_1 & *puVar1;
}



/* ===== FUN_08026cb8 @ 08026cb8 ===== */

void FUN_08026cb8(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  
  bVar2 = (byte)param_2;
  bVar3 = (byte)((uint)param_2 >> 8);
  bVar4 = (byte)((uint)param_2 >> 0x10);
  bVar1 = (byte)((uint)param_2 >> 0x18);
  iVar5 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1
                                  | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) <<
                                1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18 |
                  (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1
                                  | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) <<
                                1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
                  (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1
                                  | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) <<
                                1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
                  (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1
                                  | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) <<
                                1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7)) << 1;
  *(uint *)(param_1 + 0xc) = param_3 << iVar5 | *(uint *)(param_1 + 0xc) & ~(3 << iVar5);
  return;
}



/* ===== FUN_08026cd8 @ 08026cd8 ===== */

void FUN_08026cd8(uint param_1)

{
  do {
  } while ((uint)(*DAT_08027150 - *DAT_08027150) < param_1);
  return;
}



/* ===== FUN_08026ce8 @ 08026ce8 ===== */

void FUN_08026ce8(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_08027154;
  DAT_08027154[4] = 0x1000;
  FUN_08026cd8(2);
  FUN_0802f5a4(DAT_08027158,param_1,0,0);
  FUN_08026cd8(2);
  *puVar1 = 0x1000;
  return;
}



/* ===== FUN_08026d0c @ 08026d0c ===== */

void FUN_08026d0c(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_08027154;
  DAT_08027154[4] = 0x1000;
  FUN_08026cd8(2);
  FUN_0802f564(DAT_08027158,5,param_1,1);
  FUN_08026cd8(2);
  *puVar1 = 0x1000;
  return;
}



/* ===== FUN_08026d28 @ 08026d28 ===== */

longlong FUN_08026d28(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint local_10;
  
  puVar2 = DAT_08027154;
  local_10 = 0;
  DAT_08027154[4] = 0x1000;
  FUN_08026cd8(2);
  FUN_0802f564(DAT_08027158,0x9f,&local_10,3);
  FUN_08026cd8(2);
  *puVar2 = 0x1000;
  uVar3 = (local_10 & 0xff) << 0x10 | ((local_10 & 0xffffff) >> 8 & 0xff) << 8 |
          (local_10 & 0xffffff) >> 0x10;
  uVar1 = DAT_08027160;
  if (uVar3 != DAT_08027160) {
    uVar1 = DAT_08027164;
  }
  if (uVar3 != DAT_08027160 && uVar3 != uVar1) {
    return CONCAT44(local_10,1);
  }
  return (ulonglong)local_10 << 0x20;
}



/* ===== FUN_08026d72 @ 08026d72 ===== */

void FUN_08026d72(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_08027154;
  DAT_08027154[4] = 0x1000;
  FUN_08026cd8(2);
  FUN_0802f564(DAT_08027158,0x70,param_1,1);
  FUN_08026cd8(2);
  *puVar1 = 0x1000;
  return;
}



/* ===== FUN_08026d9e @ 08026d9e ===== */

undefined8 FUN_08026d9e(uint param_1,int param_2,undefined1 *param_3)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined4 uStack_20;
  uint local_1c;
  
  uVar3 = DAT_08027158;
  puVar1 = DAT_08027154;
  if (param_2 != 0) {
    if (0x1ffffff < param_1) {
      uVar3 = 1;
      goto LAB_08026dfe;
    }
    if (0x2000000 < param_2 + param_1) {
      uVar3 = 2;
      goto LAB_08026dfe;
    }
    local_1c = param_1 << 0x18 | (param_1 >> 8 & 0xff) << 0x10 | (param_1 >> 0x10 & 0xff) << 8 |
               param_1 >> 0x18;
    DAT_08027154[4] = 0x1000;
    FUN_08026cd8(2);
    FUN_0802f5a4(uVar3,0x13,&local_1c,4);
    uVar2 = FUN_0802f564(uVar3,0xaa,param_3 + 1,param_2 + -1);
    *param_3 = uVar2;
    FUN_08026cd8(2);
    *puVar1 = 0x1000;
  }
  uVar3 = 0;
LAB_08026dfe:
  return CONCAT44(uStack_20,uVar3);
}



/* ===== FUN_08026e02 @ 08026e02 ===== */

longlong FUN_08026e02(uint param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  
  iVar1 = 0;
  if (param_2 == 0) {
LAB_08026e44:
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
    iVar1 = FUN_08026eaa(param_1,uVar3);
    if (iVar1 != 0) goto LAB_08026ea8;
    if (uVar3 == param_2) goto LAB_08026e44;
  }
  param_1 = uVar3 + param_1;
  param_3 = param_3 + uVar3;
  uVar2 = uVar3 + 0x100;
  while (uVar2 <= param_2) {
    if (((param_1 & 0xfff) == 0) && (iVar1 = FUN_08026fa2(param_1), iVar1 != 0)) {
      return CONCAT44(param_4,iVar1);
    }
    iVar1 = FUN_08026eaa(param_1,0x100,param_3);
    if (iVar1 != 0) {
      return CONCAT44(param_4,iVar1);
    }
    param_1 = param_1 + 0x100;
    param_3 = param_3 + 0x100;
    iVar1 = 0;
    uVar2 = uVar3 + 0x200;
    uVar3 = uVar3 + 0x100;
  }
  if ((uVar3 < param_2) && (((param_1 & 0xfff) != 0 || (iVar1 = FUN_08026fa2(param_1), iVar1 == 0)))
     ) {
    lVar4 = FUN_08026eaa(param_1,param_2 - uVar3,param_3,param_4);
    return lVar4;
  }
LAB_08026ea8:
  return CONCAT44(param_4,iVar1);
}



/* ===== FUN_08026eaa @ 08026eaa ===== */

undefined8 FUN_08026eaa(uint param_1,int param_2,undefined1 *param_3,uint param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_20;
  uint local_1c;
  
  local_20 = param_3;
  local_1c = param_4;
  FUN_08026d0c((int)&local_20 + 1);
  if (((int)(((uint)local_20 >> 8) << 0x1f) < 0) ||
     (iVar4 = FUN_08026f50(), puVar2 = DAT_08027154, iVar4 != 0)) {
    return CONCAT44(local_20,8);
  }
  local_1c = param_1 << 0x18 | (param_1 >> 8 & 0xff) << 0x10 | (param_1 >> 0x10 & 0xff) << 8 |
             param_1 >> 0x18;
  DAT_08027154[4] = 0x1000;
  FUN_08026cd8(2);
  uVar5 = DAT_08027158;
  FUN_0802f5a4(DAT_08027158,0x12,&local_1c,4);
  FUN_0802f5a4(uVar5,*param_3,param_3 + 1,param_2 + -1);
  FUN_08026cd8(2);
  piVar1 = DAT_08027150;
  *puVar2 = 0x1000;
  uVar3 = DAT_0802715c;
  iVar4 = *piVar1;
  do {
    FUN_08026d0c((int)&local_20 + 1);
    if (-1 < (int)(((uint)local_20 >> 8) << 0x1f)) {
      FUN_08026d72(&local_20);
      FUN_08026ce8(0x50);
      if (((uint)local_20 & 0x7e) == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 10;
      }
      return CONCAT44(local_20,uVar5);
    }
  } while ((uint)(*piVar1 - iVar4) < uVar3);
  return CONCAT44(local_20,9);
}



/* ===== FUN_08026f50 @ 08026f50 ===== */

longlong FUN_08026f50(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint local_20;
  undefined4 uStack_1c;
  
  local_20 = param_3;
  uStack_1c = param_4;
  FUN_08026ce8(6);
  uVar3 = DAT_08027158;
  puVar2 = DAT_08027154;
  piVar1 = DAT_08027150;
  iVar4 = *DAT_08027150;
  do {
    puVar2[4] = 0x1000;
    FUN_08026cd8(2);
    FUN_0802f564(uVar3,5,&local_20,1);
    FUN_08026cd8(2);
    *puVar2 = 0x1000;
    if ((int)(local_20 << 0x1e) < 0) {
      return (ulonglong)local_20 << 0x20;
    }
  } while ((uint)(*piVar1 - iVar4) < 0x65);
  return CONCAT44(local_20,1);
}



/* ===== FUN_08026fa2 @ 08026fa2 ===== */

longlong FUN_08026fa2(uint param_1,undefined4 param_2,uint param_3,uint param_4)

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
  FUN_08026d0c((int)&local_18 + 1);
  if (((int)((local_18 >> 8) << 0x1f) < 0) ||
     (iVar4 = FUN_08026f50(), puVar2 = DAT_08027154, iVar4 != 0)) {
    return CONCAT44(local_18,0xc);
  }
  local_14 = param_1 << 0x18 | (param_1 >> 8 & 0xff) << 0x10 | (param_1 >> 0x10 & 0xff) << 8 |
             param_1 >> 0x18;
  DAT_08027154[4] = 0x1000;
  FUN_08026cd8(2);
  uVar3 = DAT_0802715c;
  FUN_0802f5a4(DAT_08027158,0x21,&local_14,4);
  FUN_08026cd8(2);
  *puVar2 = 0x1000;
  piVar1 = DAT_08027150;
  iVar4 = *DAT_08027150;
  do {
    FUN_08026d0c((int)&local_18 + 1);
    if (-1 < (int)((local_18 >> 8) << 0x1f)) {
      FUN_08026d72(&local_18);
      FUN_08026ce8(0x50);
      if ((local_18 & 0x7e) == 0) {
        return (ulonglong)local_18 << 0x20;
      }
      return CONCAT44(local_18,0xe);
    }
  } while ((uint)(*piVar1 - iVar4) < uVar3);
  return CONCAT44(local_18,0xd);
}



/* ===== FUN_08027032 @ 08027032 ===== */

longlong FUN_08027032(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_18 = param_3;
  uStack_14 = param_4;
  FUN_08026d0c((int)&local_18 + 1);
  if (((int)((local_18 >> 8) << 0x1f) < 0) || (iVar3 = FUN_08026f50(), iVar3 != 0)) {
    return CONCAT44(local_18,0xf);
  }
  FUN_08026ce8(199);
  uVar2 = DAT_0802715c;
  piVar1 = DAT_08027150;
  iVar3 = *DAT_08027150;
  do {
    FUN_08026d0c((int)&local_18 + 1);
    if (-1 < (int)((local_18 >> 8) << 0x1f)) {
      FUN_08026d72(&local_18);
      FUN_08026ce8(0x50);
      if ((local_18 & 0x7e) == 0) {
        return (ulonglong)local_18 << 0x20;
      }
      return CONCAT44(local_18,0x11);
    }
  } while ((uint)(*piVar1 - iVar3) < uVar2);
  return CONCAT44(local_18,0x10);
}



/* ===== FUN_08027096 @ 08027096 ===== */

void FUN_08027096(void)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_08026ca0(0x1000);
  uVar1 = DAT_0802716c;
  *DAT_08027158 = *DAT_08027158 | 0x40;
  FUN_08026cb8(uVar1,0x2000,0);
  FUN_08026cb8(uVar1,0x8000,0);
  FUN_08026ce8(0x66);
  FUN_08026ce8(0x99);
  do {
  } while ((uint)(*DAT_08027150 - *DAT_08027150) < 500);
  *(undefined4 *)(DAT_08027168 + 4) = 0;
  FUN_080270fa();
  iVar2 = FUN_08026d28();
  if (iVar2 != 0) {
    FUN_080167da(1);
  }
  FUN_08027126();
  return;
}



/* ===== FUN_080270fa @ 080270fa ===== */

undefined4 FUN_080270fa(void)

{
  undefined4 unaff_r7;
  
  FUN_08026ca0(0x1000);
  FUN_08026ce8(0xab);
  do {
  } while ((uint)(*DAT_08027150 - *DAT_08027150) < 0x32);
  FUN_08026ce8(0xb7);
  *(int *)(DAT_08027168 + 4) = *(int *)(DAT_08027168 + 4) + 1;
  return unaff_r7;
}



/* ===== FUN_08027126 @ 08027126 ===== */

undefined4 FUN_08027126(void)

{
  int iVar1;
  undefined4 unaff_r7;
  
  if (*(int *)(DAT_08027168 + 4) == 0) {
    return 0;
  }
  iVar1 = *(int *)(DAT_08027168 + 4) + -1;
  *(int *)(DAT_08027168 + 4) = iVar1;
  if (iVar1 == 0) {
    FUN_08026ce8(0xb9);
    *DAT_0802714c = *DAT_0802714c & 0xffffefff;
  }
  return unaff_r7;
}



/* ===== FUN_08027170 @ 08027170 ===== */

undefined8 FUN_08027170(int *param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = param_1[2];
  bVar2 = iVar1 == 0x20;
  if (bVar2) {
    iVar1 = 0x1f;
  }
  param_1[2] = iVar1 + 1;
  iVar1 = param_1[1] + 1;
  if (0x1f < iVar1) {
    iVar1 = 0;
  }
  param_1[1] = iVar1;
  FUN_080262d4(*param_1 + iVar1 * 0x24,param_2,0x24);
  iVar1 = *param_1 + param_1[1] * 0x24;
  *(undefined1 *)(iVar1 + 8) = param_3;
  *(undefined1 *)(iVar1 + 9) = 0;
  return CONCAT44(param_4,(uint)bVar2);
}



/* ===== FUN_08027218 @ 08027218 ===== */

longlong FUN_08027218(uint param_1,int param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_3 == (uint *)0x0) {
    uVar2 = FUN_0801ffbe(param_2);
    if (param_1 <= uVar2) {
LAB_0802726c:
      return CONCAT44(param_4,*(int *)(param_2 + 4) +
                              (ushort)(*(short *)(param_2 + 2) + 2) * param_1);
    }
  }
  else if (*param_3 != 0) {
    do {
      uVar5 = 0;
      uVar2 = *param_3;
      do {
        while( true ) {
          uVar1 = uVar2 >> 1;
          iVar3 = uVar1 + (uVar5 & 0xffff);
          uVar4 = param_3[iVar3 * 3 + 2];
          if ((uVar4 <= param_1) && (param_1 <= param_3[iVar3 * 3 + 3])) {
            param_1 = (param_1 + param_3[iVar3 * 3 + 4]) - uVar4;
            goto LAB_0802726c;
          }
          if (uVar1 == 0) goto LAB_08027230;
          if (uVar4 <= param_1) break;
          uVar2 = uVar1;
        }
        uVar2 = uVar2 - uVar1;
        uVar5 = uVar5 + uVar1;
      } while (uVar2 != 0);
LAB_08027230:
      if (param_1 == param_3[1]) break;
      param_1 = param_3[1];
    } while( true );
  }
  return (ulonglong)param_4 << 0x20;
}



/* ===== FUN_08027288 @ 08027288 ===== */

undefined8 FUN_08027288(undefined4 param_1)

{
  byte *pbVar1;
  uint uVar2;
  undefined4 unaff_r7;
  
  pbVar1 = (byte *)FUN_08027218(param_1,*(undefined4 *)(*DAT_0802729c + 0xc),
                                *(undefined4 *)(*DAT_0802729c + 8));
  uVar2 = 0;
  if (pbVar1 != (byte *)0x0) {
    uVar2 = (uint)*pbVar1;
  }
  return CONCAT44(unaff_r7,uVar2);
}



/* ===== FUN_080272a0 @ 080272a0 ===== */

undefined4 FUN_080272a0(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  piVar1 = DAT_0802748c;
  if (param_1 == 0) {
    param_1 = FUN_0802749c(*(undefined4 *)(*DAT_0802748c + 0xc));
  }
  iVar3 = *piVar1;
  uVar5 = (uint)*(byte *)(iVar3 + 5);
  uVar6 = (uint)*(byte *)(iVar3 + 3);
  if ((int)uVar6 < (int)(param_1 + uVar5)) {
    if ((int)((uint)*(byte *)(iVar3 + 0x10) << 0x1e) < 0) {
      if ((*DAT_08027490 != '\0') || (uVar6 <= uVar5)) {
        return 1;
      }
      *(byte *)(iVar3 + 5) = (char)param_1 + *(byte *)(iVar3 + 5);
    }
    else {
      if (*DAT_08027490 == '\0') {
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
      FUN_0802f5e4(*puVar2,puVar2[1],puVar2[2],puVar2[3],param_1 & 0xff,uVar4,param_4);
    }
  }
  else {
    FUN_0802b7ec();
    *(char *)(*piVar1 + 5) = (char)param_1 + *(char *)(*piVar1 + 5);
  }
  ((undefined1 *)*piVar1)[4] = *(undefined1 *)*piVar1;
  return 0;
}



/* ===== FUN_0802731c @ 0802731c ===== */

void FUN_0802731c(void)

{
  int *piVar1;
  
  piVar1 = DAT_0802748c;
  *DAT_08027494 = 0;
  *DAT_08027490 = (byte)((ushort)*(undefined2 *)(*piVar1 + 0x10) >> 8) & 1 ^ 1;
  return;
}



/* ===== FUN_0802736a @ 0802736a ===== */

uint FUN_0802736a(int param_1)

{
  return (short)((short)((ulonglong)(param_1 - (uint)*(byte *)*DAT_0802748c & 0xff) *
                         (ulonglong)DAT_08027498 + (ulonglong)DAT_08027498 >> 0x24) + 1) * 0x15 +
         (uint)*(byte *)*DAT_0802748c & 0xff;
}



/* ===== FUN_08027392 @ 08027392 ===== */

undefined4 FUN_08027392(int param_1)

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
  
  piVar2 = DAT_0802748c;
  if (param_1 != 10 && param_1 != 0xd) {
    pbVar9 = (byte *)*DAT_0802748c;
    if (param_1 == 9) {
      uVar3 = FUN_0802736a(pbVar9[4]);
      if (uVar3 != *pbVar9) {
        iVar4 = FUN_0802749c(*(undefined4 *)(pbVar9 + 0xc));
        iVar5 = *piVar2;
        if ((int)((uint)*(byte *)(iVar5 + 0x10) << 0x1f) < 0) {
          uVar8 = 0xffff;
        }
        else {
          uVar8 = 0;
        }
        bVar6 = *(byte *)(iVar5 + 1);
        bVar1 = *(byte *)(iVar5 + 5);
        if ((int)(iVar4 + (uint)bVar6) <= (int)(uint)bVar1) {
          bVar6 = (bVar1 - (char)iVar4) + 1;
        }
        FUN_080274b0(*(undefined1 *)(iVar5 + 4),bVar6,uVar3,(uint)bVar1,uVar8);
        *(char *)(*piVar2 + 4) = (char)uVar3;
      }
    }
    else {
      iVar4 = FUN_0802749c(*(undefined4 *)(pbVar9 + 0xc));
      iVar5 = *piVar2;
      if (*(byte *)(iVar5 + 2) < *(byte *)(iVar5 + 4)) {
        *(byte *)(iVar5 + 4) = *(byte *)(iVar5 + 2) + 1;
      }
      else {
        pbVar9 = (byte *)FUN_08027218(param_1,*(undefined4 *)(iVar5 + 0xc),
                                      *(undefined4 *)(iVar5 + 8));
        if (pbVar9 != (byte *)0x0) {
          iVar5 = *piVar2;
          bVar6 = *pbVar9;
          if ((-1 < (int)((uint)*(ushort *)(iVar5 + 0x10) << 0x16)) &&
             ((uint)*(byte *)(iVar5 + 2) < ((uint)bVar6 + (uint)*(byte *)(iVar5 + 4)) - 1)) {
            return 1;
          }
          uVar8 = FUN_0801ffb6(*(undefined4 *)(iVar5 + 0xc));
          iVar5 = *piVar2;
          bVar1 = *(byte *)(iVar5 + 5);
          if ((int)((uint)bVar1 - (uint)*(byte *)(iVar5 + 1)) < iVar4) {
            cVar7 = *(byte *)(iVar5 + 1) + ((char)iVar4 - bVar1) + -1;
          }
          else {
            cVar7 = '\0';
          }
          FUN_0802f90c(*(undefined1 *)(iVar5 + 4),(bVar1 + 1) - iVar4 & 0xff,
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



/* ===== FUN_0802749c @ 0802749c ===== */

undefined1 FUN_0802749c(int param_1)

{
  if (param_1 == 0) {
    return *(undefined1 *)(DAT_080274ac + 1);
  }
  if (param_1 == 0) {
    param_1 = DAT_0801ffcc;
  }
  return *(undefined1 *)(param_1 + 1);
}



/* ===== FUN_080274b0 @ 080274b0 ===== */

void FUN_080274b0(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte bVar9;
  byte bVar10;
  uint uVar11;
  byte bVar12;
  uint uVar13;
  uint uVar14;
  byte bVar15;
  uint uVar16;
  uint uVar17;
  
  uVar16 = (uint)*DAT_08027668;
  uVar17 = (uint)*DAT_0802766c;
  *DAT_08027670 = 0;
  pbVar8 = DAT_08027678;
  pbVar4 = DAT_08027674;
  uVar11 = param_1;
  if (uVar16 < uVar17) {
LAB_080274de:
    uVar17 = uVar11;
    uVar16 = param_1;
  }
  else if ((int)param_1 < (int)uVar17) {
    uVar17 = param_1;
  }
  else {
    uVar11 = uVar17;
    if ((int)uVar16 < (int)param_1) goto LAB_080274de;
  }
  uVar11 = (uint)*DAT_08027674;
  bVar12 = *DAT_08027678;
  uVar13 = (uint)bVar12;
  uVar14 = param_2;
  if (uVar11 < uVar13) {
LAB_08027500:
    bVar12 = (byte)uVar14;
    uVar11 = param_2;
  }
  else if ((int)param_2 < (int)uVar13) {
    bVar12 = (byte)param_2;
  }
  else {
    uVar14 = uVar13;
    if ((int)uVar11 < (int)param_2) goto LAB_08027500;
  }
  *DAT_08027674 = (byte)uVar11;
  *pbVar8 = bVar12;
  puVar5 = DAT_0802767c;
  uVar14 = param_3;
  if (uVar16 < uVar17) {
LAB_0802751e:
    bVar12 = (byte)uVar14;
    uVar16 = param_3;
  }
  else {
    bVar12 = (byte)uVar17;
    if ((int)param_3 < (int)uVar17) {
      bVar12 = (byte)param_3;
    }
    else {
      uVar14 = uVar17;
      if ((int)uVar16 < (int)param_3) goto LAB_0802751e;
    }
  }
  bVar15 = (byte)uVar16;
  bVar9 = *pbVar8;
  uVar17 = (uint)bVar9;
  uVar16 = param_4;
  if (uVar17 <= uVar11) {
    if ((int)param_4 < (int)uVar17) {
      bVar9 = (byte)param_4;
      goto LAB_0802753c;
    }
    uVar16 = uVar17;
    if ((int)param_4 <= (int)uVar11) goto LAB_0802753c;
  }
  bVar9 = (byte)uVar16;
  uVar11 = param_4;
LAB_0802753c:
  *pbVar4 = (byte)uVar11;
  pbVar7 = (byte *)(param_5 & 0xffff);
  *pbVar8 = bVar9;
  pbVar4 = DAT_0802766c;
  if (pbVar7 != (byte *)0x0) {
    pbVar8 = (byte *)0xffff;
  }
  uVar2 = (undefined1)param_5;
  if (pbVar7 == (byte *)0x0 || pbVar7 == pbVar8) {
    *puVar5 = uVar2;
    uVar3 = (undefined1)((uint)pbVar7 >> 8);
    puVar5[1] = uVar3;
    puVar5[2] = uVar2;
    puVar5[3] = uVar3;
    puVar5[4] = uVar2;
    puVar5[5] = uVar3;
    puVar5[6] = uVar2;
    puVar5[7] = uVar3;
  }
  else {
    *DAT_08027668 = bVar15;
    *pbVar4 = bVar12;
    FUN_0802b934(puVar5,0,param_5 & 0xff);
    FUN_0802b934(puVar5,1,(param_5 & 0xffff) >> 8);
    FUN_0802b934(puVar5,2,param_5 & 0xff);
    FUN_0802b934(puVar5,3,(param_5 & 0xffff) >> 8);
    FUN_0802b934(puVar5,4,param_5 & 0xff);
    FUN_0802b934(puVar5,5,(param_5 & 0xffff) >> 8);
    FUN_0802b934(puVar5,6,param_5 & 0xff);
    FUN_0802b934(puVar5,7,(param_5 & 0xffff) >> 8);
    bVar15 = *DAT_08027668;
    bVar12 = *DAT_0802766c;
  }
  iVar6 = DAT_08027688;
  bVar9 = *(byte *)(DAT_08027680 + (param_2 & 7));
  bVar1 = *(byte *)(DAT_08027684 + (param_4 & 7));
  for (param_2 = param_2 >> 3; pbVar8 = DAT_08027668, uVar16 = param_4 >> 3 & 0xff,
      param_2 <= uVar16; param_2 = param_2 + 1 & 0xff) {
    if (param_2 == uVar16) {
      bVar9 = bVar9 & bVar1;
    }
    uVar16 = param_1 & 0xff;
    uVar17 = param_1 + param_2 * 0x80;
    if (uVar16 <= param_3) {
      do {
        bVar10 = puVar5[uVar16 & 7];
        if (bVar9 != 0xff) {
          bVar10 = bVar10 & bVar9 | ~bVar9 & *(byte *)(iVar6 + (uVar17 & 0xffff));
        }
        *(byte *)(iVar6 + (uVar17 & 0xffff)) = bVar10;
        uVar16 = uVar16 + 1;
        uVar17 = uVar17 + 1;
      } while ((uVar16 & 0xff) <= param_3);
    }
    bVar9 = 0xff;
  }
  *DAT_0802766c = bVar12;
  *pbVar8 = bVar15;
  return;
}



/* ===== FUN_0802768c @ 0802768c ===== */

undefined1
FUN_0802768c(undefined1 param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,
            undefined1 param_5,byte param_6,undefined4 param_7,byte param_8,undefined4 param_9,
            undefined2 param_10,undefined2 param_11)

{
  int iVar1;
  uint uVar2;
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
  byte local_125;
  byte bStack_124;
  undefined2 auStack_123 [125];
  undefined4 uStack_28;
  
  local_125 = param_6;
  uVar2 = (uint)param_6;
  iVar1 = (uint)param_8 + (uVar2 - 300);
  local_127 = (undefined1)param_4;
  local_126 = param_5;
  local_148[0] = 0;
  local_12c = param_1;
  local_12b = param_2;
  local_129 = param_3;
  uStack_28 = param_4;
  FUN_0802f9b8(&bStack_124,param_7,param_6);
  *(byte *)((int)auStack_123 + (uVar2 - 1)) = param_8;
  FUN_0802f9b8((int)auStack_123 + uVar2,param_9,param_8);
  *(undefined2 *)((int)auStack_123 + iVar1 + 300) = param_10;
  *(undefined2 *)((int)auStack_123 + iVar1 + 0x12e) = param_11;
  FUN_0802f9c4(&local_144,0,0x18);
  local_13c = &local_12c;
  local_144 = 0x3f;
  local_142 = 0x83;
  local_138 = (uint)(byte)(param_8 + param_6 + 0xd);
  local_130 = 1;
  local_134 = local_148;
  iVar1 = FUN_08027c74(&local_144,0);
  if (iVar1 < 0) {
    local_148[0] = 0xff;
  }
  return local_148[0];
}



/* ===== FUN_0802773a @ 0802773a ===== */

undefined1
FUN_0802773a(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
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
  
  local_138[0] = 0;
  local_118 = param_5;
  local_117 = param_6;
  local_116 = param_7;
  local_115 = param_8;
  local_111 = param_9;
  local_11c = param_1;
  local_11b = param_2;
  local_11a = param_3;
  local_119 = param_4;
  FUN_0802f9c4(&local_134,0,0x18);
  local_132 = 0x86;
  local_134 = 0x3f;
  local_128 = 0xc;
  local_12c = &local_11c;
  local_120 = 1;
  local_124 = local_138;
  iVar1 = FUN_08027c74(&local_134,0);
  if (iVar1 < 0) {
    local_138[0] = 0xff;
  }
  return local_138[0];
}



/* ===== FUN_080277b2 @ 080277b2 ===== */

char FUN_080277b2(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined2 *param_4,
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
  
  FUN_0802f9c4(&local_138,0,7);
  local_118 = param_1;
  local_117 = param_2;
  local_116 = param_3;
  FUN_0802f9c4(&local_130,0,0x18);
  local_12e = 0x8a;
  local_124 = 3;
  local_130 = 0x3f;
  local_128 = &local_118;
  local_11c = 7;
  local_120 = &local_138;
  iVar1 = FUN_08027c74(&local_130,0);
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



/* ===== FUN_0802782a @ 0802782a ===== */

undefined1 FUN_0802782a(undefined1 param_1)

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
  FUN_0802f9c4(&local_124,0,0x18);
  local_124 = 0x3f;
  local_122 = 0x8f;
  local_11c = local_10c;
  local_118 = 1;
  local_110 = 1;
  local_114 = local_128;
  iVar1 = FUN_08027c74(&local_124,0);
  if (iVar1 < 0) {
    local_128[0] = 0xff;
  }
  return local_128[0];
}



/* ===== FUN_08027878 @ 08027878 ===== */

int FUN_08027878(uint *param_1)

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
    if ((char)uVar4 == '\0') goto LAB_080278aa;
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
LAB_080278aa:
  return (int)puVar1 - (int)((int)param_1 + 1);
}



/* ===== FUN_080278b0 @ 080278b0 ===== */

int FUN_080278b0(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  iVar1 = FUN_0802164e((int)&DAT_080278ec + DAT_080278ec,&local_1c,param_2,&local_18,0);
  *local_1c = 0;
  if (-1 < iVar1) {
    iVar1 = (int)local_1c - (int)param_1;
  }
  return iVar1;
}



/* ===== FUN_080278f0 @ 080278f0 ===== */

char FUN_080278f0(undefined1 *param_1,undefined2 *param_2,undefined1 *param_3,undefined2 *param_4,
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
  
  FUN_0802f9c4(&local_38,0,9);
  FUN_0802f9c4(&local_2c,0,0x18);
  local_2a = 1;
  local_2c = 4;
  local_18 = 9;
  local_1c = &local_38;
  iVar1 = FUN_08027c74(&local_2c,0);
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



/* ===== FUN_08027960 @ 08027960 ===== */

undefined1 FUN_08027960(undefined1 param_1,undefined4 param_2)

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
  FUN_0802f9b8(auStack_10b,param_2,0x1f);
  FUN_0802f9c4(&local_124,0,0x18);
  local_118 = 0x20;
  local_124 = 8;
  local_122 = 8;
  local_11c = &local_10c;
  local_110 = 1;
  local_114 = local_128;
  iVar1 = FUN_08027c74(&local_124,0);
  if (iVar1 < 0) {
    local_128[0] = 0xff;
  }
  return local_128[0];
}



/* ===== FUN_080279b2 @ 080279b2 ===== */

undefined1 FUN_080279b2(undefined1 param_1,undefined4 param_2)

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
  FUN_0802f9b8(auStack_10b,param_2,0x1f);
  FUN_0802f9c4(&local_124,0,0x18);
  local_122 = 9;
  local_118 = 0x20;
  local_124 = 8;
  local_11c = &local_10c;
  local_110 = 1;
  local_114 = local_128;
  iVar1 = FUN_08027c74(&local_124,0);
  if (iVar1 < 0) {
    local_128[0] = 0xff;
  }
  return local_128[0];
}



/* ===== FUN_08027a06 @ 08027a06 ===== */

undefined1 FUN_08027a06(undefined1 param_1,undefined1 param_2,undefined1 param_3)

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
  FUN_0802f9c4(&local_124,0,0x18);
  local_122 = 0x1e;
  local_124 = 8;
  local_118 = 3;
  local_11c = &local_10c;
  local_110 = 1;
  local_114 = local_128;
  iVar1 = FUN_08027c74(&local_124,0);
  if (iVar1 < 0) {
    local_128[0] = 0xff;
  }
  return local_128[0];
}



/* ===== FUN_08027a58 @ 08027a58 ===== */

void FUN_08027a58(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_08027f84;
  puVar1 = DAT_08027f80;
  *DAT_08027f80 = 0;
  *puVar2 = 1;
  if (puVar1[2] == '\0') {
    puVar1[2] = (char)param_1;
  }
  FUN_08017f38("BLE: error #0x%0.2X!",param_1,param_4);
  return;
}



/* ===== FUN_08027a7c @ 08027a7c ===== */

void FUN_08027a7c(void)

{
  int iVar1;
  
  iVar1 = DAT_08027f88;
  *(int *)(DAT_08027f88 + 0x53c) = DAT_08027f88;
  *(int *)(iVar1 + 0x540) = iVar1;
  *(undefined4 *)(iVar1 + 0x544) = 0;
  return;
}



/* ===== FUN_08027aa0 @ 08027aa0 ===== */

void FUN_08027aa0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = DAT_08027f94;
  *DAT_08027f90 = 0x20;
  iVar2 = FUN_08027ace();
  while( true ) {
    iVar3 = piVar1[1];
    if (iVar3 == *piVar1) {
      iVar2 = piVar1[2];
    }
    if (iVar3 == *piVar1 && iVar2 == 0) break;
    FUN_08027e98(iVar3 + 6);
    iVar2 = FUN_08027e7c();
  }
  return;
}



/* ===== FUN_08027ace @ 08027ace ===== */

/* WARNING: Removing unreachable block (ram,0x08027bd0) */
/* WARNING: Removing unreachable block (ram,0x08027bf6) */

void FUN_08027ace(void)

{
  char cVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  byte *pbVar6;
  int *piVar7;
  undefined1 uVar8;
  undefined4 uVar9;
  int iVar10;
  char *pcVar11;
  uint uVar12;
  int *piVar13;
  char *pcVar14;
  undefined1 auStack_30 [2];
  ushort local_2e;
  int *local_2c;
  int local_28;
  
  uVar9 = DAT_08027f9c;
  piVar7 = DAT_08027f98;
  iVar4 = DAT_08027f88;
  local_28 = *DAT_08027f98;
  uVar12 = 0;
  local_2c = DAT_08027fa0;
  piVar13 = (int *)(DAT_08027f88 + 0x53c);
  while( true ) {
    if (-1 < *local_2c << 0x12) {
      return;
    }
    if (*(int *)(iVar4 + 0x544) != 0) {
      return;
    }
    iVar10 = *piVar13;
    DAT_08027fa4[4] = 0x40;
    do {
    } while ((uint)(*piVar7 - *piVar7) < 2);
    FUN_0802f564(uVar9,0xb,auStack_30,4);
    pcVar14 = (char *)(uint)local_2e;
    pcVar11 = (char *)0x0;
    if (pcVar14 != (char *)0x0) {
      if (pcVar14 < (char *)0x81) {
        uVar8 = FUN_0802f564(uVar9,0xb,iVar10 + 7,pcVar14 + -1);
        *(undefined1 *)(iVar10 + 6) = uVar8;
        pcVar11 = pcVar14;
      }
      else {
        pcVar11 = (char *)(0x80 - (int)pcVar14);
      }
    }
    do {
    } while ((uint)(*piVar7 - *piVar7) < 2);
    *DAT_08027fa4 = 0x40;
    pbVar6 = DAT_08027f90;
    piVar5 = DAT_08027f8c;
    if ((int)pcVar11 < 0) break;
    uVar12 = uVar12 + 1;
    if (pcVar11 != (char *)0x0) {
      *(short *)(*piVar13 + 4) = (short)*piVar7 - (short)local_28;
      iVar10 = *(int *)(pbVar6 + 4);
      *(char *)(*piVar13 + 1) = (char)iVar10;
      *(int *)(pbVar6 + 4) = iVar10 + 1;
      *(byte *)*piVar13 = (byte)uVar12 | *pbVar6;
      *pbVar6 = 0;
      iVar10 = *piVar5;
      *(short *)(*piVar13 + 2) = (short)((iVar10 - *(int *)(pbVar6 + 8)) * 0x7d + 0x800U >> 0xc);
      *(int *)(pbVar6 + 8) = iVar10;
      puVar3 = DAT_08027f84;
      puVar2 = DAT_08027f80;
      iVar10 = *piVar13;
      pcVar14 = (char *)(iVar10 + 6);
      cVar1 = *pcVar14;
      if (cVar1 == '\x04') {
        pcVar11 = pcVar11 + -3;
        pcVar14 = (char *)(uint)*(byte *)(iVar10 + 8);
      }
      if (cVar1 == '\x04' && pcVar11 == pcVar14) {
        *piVar13 = iVar10 + 0x86;
        if (piVar13 <= (int *)(iVar10 + 0x86)) {
          *piVar13 = iVar4;
        }
        *(uint *)(iVar4 + 0x544) = (uint)(*piVar13 == *(int *)(iVar4 + 0x540));
        puVar3 = DAT_08027f84;
        puVar2 = DAT_08027f80;
        if (*(int *)(iVar4 + 0x544) == 0) {
          return;
        }
        *DAT_08027f80 = 0;
        *puVar3 = 1;
        if (puVar2[2] == '\0') {
          puVar2[2] = 0xb3;
        }
        uVar9 = 0xb3;
      }
      else {
        *DAT_08027f80 = 0;
        *puVar3 = 1;
        if (puVar2[2] == '\0') {
          puVar2[2] = 0x32;
        }
        uVar9 = 0x32;
      }
      FUN_08017f38("BLE: error #0x%0.2X!",uVar9);
      return;
    }
    if (6 < uVar12) {
      uVar9 = 0x31;
      goto LAB_08027b88;
    }
    do {
    } while ((uint)(*piVar7 - *piVar7) < 0x14);
  }
  uVar9 = 0x30;
LAB_08027b88:
  FUN_08027a58(uVar9);
  return;
}



/* ===== FUN_08027c74 @ 08027c74 ===== */

/* WARNING: Removing unreachable block (ram,0x08027e6a) */

int FUN_08027c74(ushort *param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  uint *puVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined1 *puVar13;
  bool bVar14;
  undefined2 local_3f;
  undefined1 local_3d;
  ushort *local_3c;
  ushort local_38 [2];
  uint local_34;
  uint local_30;
  ushort *puStack_2c;
  uint local_28;
  
  pcVar8 = DAT_08027f80;
  if (*DAT_08027f80 == '\0') {
    return 0xf2;
  }
  iVar11 = 0;
  local_34 = param_1[1] & 0xffff03ff | (*param_1 & 0x3f) << 10;
  *DAT_08027f90 = 0x40;
  puVar4 = DAT_08027fa0;
  uVar3 = DAT_08027f9c;
  piVar2 = DAT_08027f98;
  uVar6 = *(uint *)(param_1 + 6);
  puVar13 = *(undefined1 **)(param_1 + 4);
  local_3c = param_1;
  puStack_2c = param_1;
  local_28 = param_2;
  if ((uVar6 & 0xff) < 0x7c) {
    local_3f = (undefined2)local_34;
    local_30 = uVar6 & 0xff;
    iVar12 = *DAT_08027f98;
    local_3d = (char)uVar6;
LAB_08027cd0:
    uVar6 = local_30;
    if ((uint)(*piVar2 - iVar12) < 0x4e21) {
      DAT_08027fa4[4] = 0x40;
      iVar11 = 0;
      do {
      } while ((uint)(*piVar2 - *piVar2) < 2);
      do {
        if ((int)(*puVar4 << 0x12) < 0) {
          FUN_0802f564(uVar3,10,local_38,4);
          if (uVar6 + 4 <= (uint)local_38[0]) {
            FUN_0802f5a4(uVar3,1,&local_3f,3);
            if (uVar6 != 0) {
              FUN_0802f5a4(uVar3,*puVar13,puVar13 + 1,uVar6 - 1);
            }
            iVar11 = 1;
          }
          goto LAB_08027d5c;
        }
      } while ((uint)(*piVar2 - *piVar2) < 0x2711);
      do {
      } while ((uint)(*piVar2 - *piVar2) < 2);
      *DAT_08027fa4 = 0x40;
      iVar11 = -1;
      goto LAB_08027d82;
    }
    goto LAB_08027d90;
  }
  iVar11 = -3;
  goto LAB_08027d9c;
  while ((uint)(*piVar2 - *piVar2) < 0x1389) {
LAB_08027d5c:
    if (-1 < (int)((*puVar4 >> 0xd) << 0x1f)) goto LAB_08027d72;
  }
  iVar11 = -2;
LAB_08027d72:
  do {
  } while ((uint)(*piVar2 - *piVar2) < 2);
  *DAT_08027fa4 = 0x40;
LAB_08027d82:
  do {
  } while ((uint)(*piVar2 - *piVar2) < 0x14);
  if (iVar11 != 0) goto LAB_08027d90;
  goto LAB_08027cd0;
LAB_08027d90:
  uVar6 = local_34;
  puVar5 = local_3c;
  piVar1 = DAT_08027f94;
  if (iVar11 == 0) {
    iVar11 = -4;
  }
  else if (-1 < iVar11) {
    if (pcVar8[1] == 0) {
      uVar7 = 1000;
    }
    else {
      uVar7 = (short)(ushort)(byte)pcVar8[1] * 1000;
    }
    iVar11 = *piVar2;
    if ((local_28 & 0xff) != 0) {
      do {
      } while ((uint)(*piVar2 - iVar11) <= uVar7);
      return 2;
    }
    iVar12 = 0;
    do {
      do {
        if (uVar7 < (uint)(*piVar2 - iVar11)) goto LAB_08027e60;
        FUN_08027ace();
        iVar10 = piVar1[1];
      } while ((iVar10 == *piVar1) && (piVar1[2] == 0));
      pcVar8 = (char *)(iVar10 + 9);
      uVar9 = (uint)*(byte *)(iVar10 + 8);
      if (*(char *)(iVar10 + 7) == '\x0e') {
        if (*(ushort *)(iVar10 + 10) != uVar6) goto LAB_08027e0e;
        pcVar8 = (char *)(iVar10 + 0xc);
        uVar9 = uVar9 - 3;
        iVar12 = 2;
LAB_08027e46:
        if (*(uint *)(puVar5 + 10) <= uVar9) {
          uVar9 = *(uint *)(puVar5 + 10);
        }
        *(uint *)(puVar5 + 10) = uVar9;
        FUN_0802f9b8(*(undefined4 *)(puVar5 + 8),pcVar8);
      }
      else {
        if (*(char *)(iVar10 + 7) == '\x0f') {
          bVar14 = *(ushort *)(iVar10 + 0xb) != uVar6;
          if (!bVar14) {
            iVar10 = *(int *)(puVar5 + 2);
          }
          if ((bVar14 || iVar10 != 0xf) || (*pcVar8 != '\0')) {
            iVar12 = 0xf3;
          }
          else {
            iVar12 = 1;
          }
          goto LAB_08027e46;
        }
LAB_08027e0e:
        if (iVar12 != 0) goto LAB_08027e46;
        FUN_08027e98(iVar10 + 6);
      }
      FUN_08027e7c();
    } while (iVar12 == 0);
LAB_08027e60:
    if (iVar12 == 0) {
      return 0xf4;
    }
    return iVar12;
  }
LAB_08027d9c:
  FUN_08027a58(0x20U - iVar11 & 0xff);
  return iVar11;
}



/* ===== FUN_08027e7c @ 08027e7c ===== */

void FUN_08027e7c(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_08027f88;
  piVar2 = (int *)(DAT_08027f88 + 0x540);
  iVar4 = DAT_08027f88 + 0x53c;
  iVar3 = *piVar2;
  *piVar2 = iVar3 + 0x86;
  if (iVar3 + 0x86 == iVar4) {
    *piVar2 = iVar1;
  }
  *(undefined4 *)(iVar1 + 0x544) = 0;
  return;
}



/* ===== FUN_08027e98 @ 08027e98 ===== */

undefined8 FUN_08027e98(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

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
  
  puVar4 = DAT_08027f84;
  puVar3 = DAT_08027f80;
  uVar8 = 0;
  uVar5 = (uint)*(byte *)(param_1 + 1);
  if (uVar5 == 0x3e) {
    uVar7 = 0;
    puVar6 = DAT_08027fa8;
    do {
      uVar5 = (uint)*(byte *)(param_1 + 3);
      if (uVar5 != *puVar6) {
        uVar7 = uVar7 + 1;
        unaff_r6 = (uint)puVar6[4];
      }
      if (uVar5 == *puVar6 || uVar5 == unaff_r6) {
        param_1 = param_1 + 4;
        puVar6 = DAT_08027fa8;
        goto LAB_08027f12;
      }
      uVar7 = uVar7 + 1;
      puVar6 = puVar6 + 8;
    } while (uVar7 < 10);
LAB_08027f4e:
    *DAT_08027f80 = 0;
    *puVar4 = 1;
    if (puVar3[2] == '\0') {
      puVar3[2] = 0x10;
    }
    FUN_08017f38("BLE: error #0x%0.2X!",0x10);
    local_18 = (uint)*(byte *)(param_1 + 4);
    FUN_08018028(DAT_08027fb4,*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2),
                 *(undefined1 *)(param_1 + 3));
  }
  else {
    uVar7 = 0;
    if (uVar5 == 0xff) {
      if (*(ushort *)(param_1 + 3) != *DAT_08027fac) {
        uVar7 = 1;
        puVar6 = DAT_08027fac + 4;
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
          if ((bVar10 || bVar11) || uVar2 == uVar1) goto LAB_08027f04;
          uVar7 = uVar7 + 1;
          puVar6 = puVar6 + 0xc;
        } while (uVar7 < 0x2b);
        goto LAB_08027f4e;
      }
LAB_08027f04:
      param_1 = param_1 + 5;
      puVar6 = DAT_08027fac;
    }
    else {
      if (uVar5 != *DAT_08027fb0) {
        uVar9 = (uint)DAT_08027fb0[4];
        uVar7 = 1;
        bVar10 = uVar5 != uVar9;
        if (bVar10) {
          uVar7 = 2;
          uVar9 = (uint)DAT_08027fb0[8];
        }
        if (bVar10 && uVar5 != uVar9) {
          uVar9 = (uint)DAT_08027fb0[0xc];
          uVar7 = 3;
          bVar10 = uVar5 != uVar9;
          if (bVar10) {
            uVar7 = 4;
            uVar9 = (uint)DAT_08027fb0[0x10];
          }
          if (bVar10 && uVar5 != uVar9) {
            uVar7 = 5;
            uVar9 = param_4;
            if (uVar5 != DAT_08027fb0[0x14]) {
              uVar7 = 6;
              uVar9 = (uint)DAT_08027fb0[0x18];
            }
            if (uVar5 != DAT_08027fb0[0x14] && uVar5 != uVar9) goto LAB_08027f4e;
          }
        }
      }
      param_1 = param_1 + 3;
      puVar6 = DAT_08027fb0;
    }
LAB_08027f12:
    uVar8 = 1;
    (**(code **)(puVar6 + uVar7 * 4 + 2))(param_1);
    local_18 = param_4;
  }
  return CONCAT44(local_18,uVar8);
}



/* ===== FUN_08027fe2 @ 08027fe2 ===== */

void FUN_08027fe2(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  return;
}



/* ===== FUN_08027fe6 @ 08027fe6 ===== */

undefined8 FUN_08027fe6(void)

{
  disableIRQinterrupts();
  enableIRQinterrupts();
  return *DAT_08028be0;
}



/* ===== FUN_08027ff4 @ 08027ff4 ===== */

byte FUN_08027ff4(void)

{
  return *(byte *)(DAT_08028be4 + 6) & 3;
}



/* ===== FUN_08028018 @ 08028018 ===== */

void FUN_08028018(int param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_08028bec;
  if (param_1 == 0) {
    *(uint *)(DAT_08028be8 + 100) = *(uint *)(DAT_08028be8 + 100) & 0xfffffeff;
    FUN_080157d4();
    *puVar1 = *puVar1 & 0xfffffffe;
    FUN_08020bd0(0);
    return;
  }
  *(uint *)(DAT_08028be8 + 100) = *(uint *)(DAT_08028be8 + 100) | 0x100;
  FUN_080157d4(1);
  FUN_080165a4(puVar1,1);
  return;
}



/* ===== FUN_08028052 @ 08028052 ===== */

void FUN_08028052(uint param_1)

{
  *(uint *)(DAT_08028be8 + 100) = *(uint *)(DAT_08028be8 + 100) & 0xffefffff | (param_1 & 1) << 0x14
  ;
  if (param_1 != 0) {
    *(uint *)(DAT_08028bec + 4) = *(uint *)(DAT_08028bec + 4) | 1;
    return;
  }
  if ((int)(*(uint *)(DAT_08028bec + 4) << 0x1f) < 0) {
    *(uint *)(DAT_08028bec + 4) = *(uint *)(DAT_08028bec + 4) & 0xfffffffe;
    FUN_08020fd6(DAT_0801655c);
    return;
  }
  return;
}



/* ===== FUN_08028076 @ 08028076 ===== */

void FUN_08028076(uint param_1)

{
  *(byte *)(DAT_08028be8 + 0x68) =
       *(byte *)(DAT_08028be8 + 0x68) & 0xf3 | (byte)((param_1 & 3) << 2);
  if (param_1 == 1) {
    *(undefined1 *)(DAT_08015ecc + 9) = 1;
    return;
  }
  if (param_1 == 2) {
    *(undefined1 *)(DAT_08015ecc + 9) = 0;
    return;
  }
  return;
}



/* ===== FUN_08028098 @ 08028098 ===== */

int FUN_08028098(int *param_1)

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
  for (; pbVar3 < pbVar5; pbVar3 = pbVar3 + 1) {
    iVar2 = iVar2 + (uint)*pbVar3;
  }
  return iVar2;
}



/* ===== FUN_080280bc @ 080280bc ===== */

void FUN_080280bc(int *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  puVar5 = *(uint **)(*param_1 + 8);
  uVar4 = *puVar5;
  if (uVar4 < 0xc) {
    uVar2 = DAT_08028bf0;
    uVar1 = uVar4;
  }
  else {
    uVar1 = puVar5[1];
    if (uVar1 == (*DAT_08028bf4 | DAT_08028bf8)) {
      uVar1 = puVar5[2];
      if (uVar1 == 1) {
        uVar1 = puVar5[3];
        if (uVar4 - uVar1 != 0xc) {
          FUN_08017fde(DAT_08028c04,param_2);
          return;
        }
        if ((uVar1 == 0) || (iVar3 = FUN_08018404(puVar5 + 4,uVar1), iVar3 != 0)) {
          return;
        }
        FUN_08017f38(DAT_08028c08,param_2);
        return;
      }
      uVar2 = DAT_08028c00;
    }
    else {
      uVar2 = DAT_08028bfc;
    }
  }
  FUN_08017f8a(uVar2,param_2,uVar1);
  return;
}



/* ===== FUN_08028136 @ 08028136 ===== */

void FUN_08028136(int param_1)

{
  undefined4 uVar1;
  
  FUN_080280bc(param_1,1);
  uVar1 = FUN_08028098(param_1);
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  return;
}



/* ===== FUN_0802814c @ 0802814c ===== */

void FUN_0802814c(int param_1)

{
  int iVar1;
  
  FUN_080280bc(param_1,2);
  iVar1 = FUN_08028098(param_1);
  if (iVar1 == *(int *)(param_1 + 0x1c)) {
    return;
  }
  FUN_08017f8a("CRC Error: 0x%08X != 0x%08X");
  return;
}



/* ===== FUN_0802818c @ 0802818c ===== */

undefined4 FUN_0802818c(int *param_1)

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
    FUN_0802a31c(*(undefined1 *)*param_1);
    iVar3 = *param_1;
    puVar4 = *(uint **)(iVar3 + 4);
    param_1[1] = (int)(puVar4 + 1);
    puVar2 = DAT_08028bf4;
    uVar5 = *puVar4;
    *DAT_08028bf4 = uVar5 & 0x1f000000;
    param_1[2] = *(int *)(iVar3 + 8) + 4;
    puVar4 = DAT_08028c0c;
    if (-1 < (int)((uint)(byte)puVar2[1] << 0x1e)) {
      puVar4 = (uint *)&UNK_08028220;
    }
    for (; *puVar4 != (uVar5 & 0xe0ffffff) && *puVar4 != 0; puVar4 = puVar4 + 2) {
    }
    (*(code *)puVar4[1])(param_1);
    FUN_0802827e(param_1);
    if ((code *)param_1[5] != (code *)0x0) {
      (*(code *)param_1[5])(param_1);
      param_1[5] = 0;
    }
    (**(code **)(*param_1 + 0x14))(param_1);
    return 1;
  }
  return 0;
}



/* ===== FUN_08028238 @ 08028238 ===== */

void FUN_08028238(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = DAT_08028c10;
  iVar2 = *DAT_08028bdc;
  *(int *)*DAT_08028c10 = *(int *)(iVar2 + 8) + 4;
  *(undefined4 *)puVar1[1] = *(undefined4 *)(iVar2 + 4);
  *(undefined1 *)puVar1[2] = 0;
  *(undefined1 *)puVar1[3] = 0;
  *(undefined4 *)puVar1[4] = 0;
  *(undefined4 *)puVar1[5] = 0;
  *(short *)puVar1[6] = (short)*(undefined4 *)(iVar2 + 0x10) + -4;
  *(short *)puVar1[7] = (short)*(undefined4 *)(iVar2 + 0xc) + -4;
  return;
}



/* ===== FUN_0802827e @ 0802827e ===== */

void FUN_0802827e(int *param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  puVar1 = *(uint **)(*param_1 + 8);
  iVar2 = param_1[2];
  param_1[2] = (int)(puVar1 + 1);
  uVar3 = iVar2 - (int)(puVar1 + 1);
  if (*(uint *)(*param_1 + 0x10) < uVar3) {
    puVar1[1] = DAT_08028c14;
    uVar3 = 4;
  }
  *puVar1 = uVar3;
  puVar1[1] = puVar1[1] | *DAT_08028bf4;
  return;
}



/* ===== FUN_080282ae @ 080282ae ===== */

void FUN_080282ae(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  int *piVar2;
  char *pcVar3;
  
  FUN_0802827e();
  puVar1 = DAT_08028c18;
  pcVar3 = (char *)*param_1;
  if (*pcVar3 == '\x02') {
    piVar2 = *(int **)(pcVar3 + 8);
    DAT_08028c18[5] = *piVar2 + 4;
    param_1[2] = piVar2;
    *(undefined1 *)param_1[4] = 1;
    *puVar1 = *puVar1 | 4;
    while (*(char *)param_1[4] != '\0') {
      *puVar1 = *puVar1 | 4;
      FUN_0802a02c();
    }
  }
  else {
    (**(code **)(pcVar3 + 0x14))(param_1);
    do {
    } while (*(char *)param_1[4] != '\0');
  }
  FUN_0802c778(0x14,param_4);
  return;
}



/* ===== FUN_08028306 @ 08028306 ===== */

void FUN_08028306(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = DAT_08028c1c;
  (*(code *)DAT_08028c1c[6])();
  *(undefined4 *)*puVar1 = **(undefined4 **)(*param_1 + 8);
  UNRECOVERED_JUMPTABLE = (code *)puVar1[5];
                    /* WARNING: Could not recover jumptable at 0x08028322. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(UNRECOVERED_JUMPTABLE,param_4);
  return;
}



/* ===== FUN_0802836c @ 0802836c ===== */

undefined4
FUN_0802836c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  iVar1 = DAT_08028c28;
  piVar2 = (int *)param_1[1];
  param_1[1] = piVar2 + 1;
  uVar4 = DAT_08028c20;
  if (*piVar2 == iVar1) {
    *(uint *)(DAT_08028bf4 + 4) = *(uint *)(DAT_08028bf4 + 4) | 2;
    uVar4 = DAT_08028c30;
    puVar5 = (undefined4 *)param_1[2];
    *puVar5 = DAT_08028c2c;
    puVar5[1] = uVar4;
    puVar3 = (undefined1 *)*param_1;
    puVar5[2] = *(uint *)(puVar3 + 0x10) | (*(int *)(puVar3 + 0xc) + -0x20) * 0x10000;
    param_1[2] = puVar5 + 4;
    uVar4 = FUN_0802a304(*puVar3);
    puVar5[3] = uVar4;
    if (*(char *)*param_1 == '\x01') {
      *(undefined1 *)param_1[4] = 0;
      return param_4;
    }
    if (*(char *)*param_1 == '\x02') {
      FUN_0802a012();
      if (*(char *)(DAT_08028c34 + 0xd) == '\0') {
        *(undefined1 *)(DAT_08028c34 + 0xd) = 1;
        return param_4;
      }
    }
  }
  else {
    puVar5 = (undefined4 *)param_1[2];
    param_1[2] = puVar5 + 1;
    *puVar5 = uVar4;
  }
  return param_4;
}



/* ===== FUN_080283ee @ 080283ee ===== */

void FUN_080283ee(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  
  iVar4 = DAT_08028c28;
  piVar5 = *(int **)(param_1 + 4);
  *(int **)(param_1 + 4) = piVar5 + 1;
  uVar3 = DAT_08028c38;
  uVar2 = DAT_08028c20;
  uVar1 = DAT_08028bec;
  if (*piVar5 != iVar4) {
    puVar6 = *(undefined4 **)(param_1 + 8);
    *(undefined4 **)(param_1 + 8) = puVar6 + 1;
    *puVar6 = uVar2;
    return;
  }
  puVar6 = *(undefined4 **)(param_1 + 8);
  *(undefined4 **)(param_1 + 8) = puVar6 + 1;
  *puVar6 = uVar3;
  FUN_080282ae(param_1,puVar6);
  FUN_0801831c();
  thunk_FUN_0802dd36();
  FUN_0801cd4c();
  FUN_080163f4(uVar1);
  *DAT_08028c3c = 0xaaaa;
  do {
    iVar4 = FUN_0801659e(uVar1);
  } while (iVar4 != 0);
  *DAT_08028c40 = *DAT_08028c40 | 0x100;
  *DAT_08028c44 = 0x55aa;
  DAT_08028c44[1] = 0x5a5a;
  *DAT_08028c40 = *DAT_08028c40 & 0xfffffeff;
  DataSynchronizationBarrier(0xf);
  *DAT_08028c48 = *DAT_08028c48 & 0x700 | DAT_08028c4c;
  DataSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_08028c58 @ 08028c58 ===== */

undefined8 FUN_08028c58(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int iVar19;
  uint uVar20;
  undefined4 uVar21;
  uint uVar22;
  undefined4 uVar23;
  uint uVar24;
  undefined8 uVar25;
  
  puVar6 = DAT_08029a58;
  pbVar5 = DAT_08029a4c;
  iVar19 = DAT_08029a44;
  puVar3 = DAT_080299b0;
  puVar2 = DAT_08029394;
  uVar23 = 1;
  if (param_2 == 0x500) {
    if (-1 < (int)(param_3 << 0x1f)) {
      param_3 = param_3 & 0xfffffffd;
    }
    if ((int)(param_3 << 0x1f) < 0) {
      uVar17 = 1;
    }
    else {
      uVar17 = 2;
    }
    FUN_080178f6(uVar17);
    iVar19 = DAT_08029a44;
    *(uint *)(DAT_08029a44 + 8) =
         *(uint *)(DAT_08029a44 + 8) & 0xffffff7f | (param_3 >> 1 & 1 ^ 1) << 7;
    FUN_08028018(param_3 >> 2 & 1);
    puVar2 = DAT_080299b0;
    if ((int)(param_3 << 0x1c) < 0) {
      *DAT_08029394 = *DAT_08029394 | 0x80;
      puVar2[2] = puVar2[2] | 1;
    }
    else {
      *DAT_08029394 = *DAT_08029394 & 0xffffff7f;
      FUN_08016178();
    }
    FUN_08028052(param_3 >> 4 & 1);
    iVar4 = DAT_080299fc;
    uVar20 = *(uint *)(iVar19 + 8);
    if ((int)(param_3 << 0x1a) < 0) {
      *(uint *)(iVar19 + 8) = uVar20 | 0x200000;
      if (-1 < (int)(uVar20 << 0xb)) goto LAB_08028df4;
      *(undefined4 *)(iVar4 + 0x28) = 0x2000;
    }
    else {
      *(uint *)(iVar19 + 8) = uVar20 & 0xffdfffff;
LAB_08028df4:
      FUN_08027fe2(iVar4,0x2000);
    }
    uVar17 = FUN_08017dbe();
    disableIRQinterrupts();
    uVar18 = *DAT_08029a48;
    uVar21 = DAT_08029a48[1];
LAB_080292f6:
    uVar25 = CONCAT44(uVar21,uVar18);
    enableIRQinterrupts();
  }
  else {
    bVar7 = (byte)param_3;
    if (param_2 == 0x502) {
      bVar7 = FUN_08015794(param_3 & 0xff,1);
      *pbVar5 = bVar7;
      *DAT_08029a54 = *(undefined4 *)(DAT_08029a50 + (uint)*pbVar5 * 4);
      goto LAB_0802938a;
    }
    if (param_2 == 0x503) {
      if (param_3 == 0) {
        uVar17 = 2;
      }
      else {
        uVar17 = 1;
      }
      FUN_080178f6(uVar17);
      goto LAB_0802938a;
    }
    if (param_2 == 0x504) {
      if (param_3 == 0) {
        disableIRQinterrupts();
        uVar17 = DAT_08029a48[1];
        enableIRQinterrupts();
        *DAT_08029a58 = *DAT_08029a48;
        puVar6[1] = uVar17;
      }
      goto LAB_0802938a;
    }
    if (param_2 == 0x510) {
      uVar22 = *(uint *)(DAT_08029a44 + 8);
      uVar20 = (param_3 & 1 ^ 1) << 7;
      *(uint *)(DAT_08029a44 + 8) = uVar22 & 0xffffff7f | uVar20;
      *(uint *)(iVar19 + 8) = uVar22 & 0xfffffe7f | uVar20 | (param_3 >> 1 & 1) << 8;
      uVar20 = (param_3 & 0xf) >> 2;
      if (uVar20 != ((byte)DAT_08029394[1] & 3)) {
        *(byte *)(DAT_08029394 + 1) = (byte)DAT_08029394[1] & 0xfc | (byte)uVar20;
        if (uVar20 == 0) {
          FUN_0801b544();
LAB_08028eaa:
          FUN_0801b42e();
        }
        else if (uVar20 == 2) {
          FUN_0801b41c();
        }
        else if (uVar20 < 2) goto LAB_08028eaa;
      }
      param_3 = (param_3 & 0x3f) >> 4;
LAB_08028ef0:
      FUN_08028076(param_3);
      goto LAB_0802938a;
    }
    if (param_2 == 0x511) {
      if (DAT_08029a4c[1] != param_3) {
        DAT_08029a4c[1] = bVar7;
        FUN_0801b4ec(1);
      }
      goto LAB_0802938a;
    }
    if (param_2 == 0x512) {
      DAT_08029a4c[2] = bVar7;
      goto LAB_0802938a;
    }
    if (param_2 == 0x513) {
      DAT_08029a4c[5] = bVar7;
      goto LAB_0802938a;
    }
    if (param_2 == 0x514) {
      uVar20 = *(uint *)(DAT_08029a44 + 8) & 0xffffff7f | (param_3 & 1 ^ 1) << 7;
LAB_08028f00:
      *(uint *)(DAT_08029a44 + 8) = uVar20;
      goto LAB_0802938a;
    }
    if (param_2 == 0x515) {
      param_3 = param_3 & 0xff;
      goto LAB_08028ef0;
    }
    if (param_2 == 0x516) {
      uVar20 = *(uint *)(DAT_08029a44 + 8) & 0xfffffeff | (param_3 & 1) << 8;
      goto LAB_08028f00;
    }
    if (param_2 == 0x520) {
      *DAT_08029394 = *DAT_08029394 & 0xfffffdff | (param_3 & 1) << 9;
      if ((param_3 & 1) == 0) {
        *puVar3 = *puVar3 & 0xfffffffd;
      }
      else {
        FUN_080165a4(puVar3,2);
      }
      uVar20 = param_3 >> 1 & 1;
      *puVar2 = *puVar2 & 0xfffffbff | uVar20 << 10;
      if (uVar20 == 0) {
        *puVar3 = *puVar3 & 0xfffffffb;
      }
      else {
        FUN_080165a4(puVar3,4);
      }
      uVar20 = param_3 >> 10 & 1;
      *puVar2 = *puVar2 & 0xfffff7ff | uVar20 << 0xb;
      if (uVar20 == 0) {
        *puVar3 = *puVar3 & 0xfffffdff;
      }
      else {
        FUN_080165a4(puVar3,0x200);
      }
      uVar20 = param_3 >> 0xb & 1;
      *puVar2 = *puVar2 & 0xffffefff | uVar20 << 0xc;
      if (uVar20 == 0) {
        *puVar3 = *puVar3 & 0xfffffbff;
      }
      else {
        FUN_080165a4(puVar3,0x400);
      }
      uVar20 = param_3 >> 0xc & 1;
      *puVar2 = *puVar2 & 0xffffdfff | uVar20 << 0xd;
      if (uVar20 == 0) {
        *puVar3 = *puVar3 & 0xfffff7ff;
      }
      else {
        FUN_080165a4(puVar3,0x800);
      }
      uVar20 = param_3 >> 2 & 1;
      *puVar2 = *puVar2 & 0xffffbfff | uVar20 << 0xe;
      if (uVar20 == 0) {
        *puVar3 = *puVar3 & 0xfffffff7;
      }
      else {
        FUN_080165a4(puVar3,8);
      }
      uVar20 = param_3 >> 3 & 1;
      *puVar2 = *puVar2 & 0xffff7fff | uVar20 << 0xf;
      if (uVar20 == 0) {
        FUN_0802fb10(puVar3,0x10);
      }
      else {
        FUN_080165a4(puVar3,0x10);
      }
      uVar20 = param_3 >> 4 & 1;
      *puVar2 = *puVar2 & 0xfffeffff | uVar20 << 0x10;
      if (uVar20 == 0) {
        *puVar3 = *puVar3 & 0xffffffdf;
      }
      else {
        FUN_080165a4(puVar3,0x20);
      }
      uVar20 = param_3 >> 5 & 1;
      *puVar2 = *puVar2 & 0xfffdffff | uVar20 << 0x11;
      if (uVar20 == 0) {
        FUN_0802fb10(puVar3,0x40);
      }
      else {
        FUN_080165a4(puVar3,0x40);
      }
      uVar20 = param_3 >> 6 & 1;
      *puVar2 = *puVar2 & 0xfffbffff | uVar20 << 0x12;
      if (uVar20 == 0) {
        FUN_0802fb10(puVar3,0x80);
      }
      else {
        FUN_080165a4(puVar3,0x80);
      }
      uVar20 = param_3 >> 7 & 1;
      *puVar2 = *puVar2 & 0xfff7ffff | uVar20 << 0x13;
      if (uVar20 == 0) {
        *puVar3 = *puVar3 & 0xfffffeff;
      }
      else {
        FUN_080165a4(puVar3,0x100);
      }
      uVar20 = param_3 >> 8 & 1;
      puVar2[1] = puVar2[1] & 0xffffefff | uVar20 << 0xc;
      if (uVar20 == 0) {
        *puVar3 = *puVar3 & 0xffffbfff;
      }
      else {
        FUN_080165a4(puVar3,0x4000);
      }
      uVar20 = param_3 >> 9 & 1;
      puVar2[1] = puVar2[1] & 0xffffdfff | uVar20 << 0xd;
      if (uVar20 == 0) {
        FUN_0802fb10();
      }
      else {
        FUN_080165a4(puVar3,0x8000);
      }
      goto LAB_080292e6;
    }
    if (param_2 == 0x521) {
      DAT_08029a4c[4] = bVar7;
      goto LAB_0802938a;
    }
    if (param_2 != 0x522) {
      if (param_2 == 0x530) {
        uVar22 = *DAT_08029394;
        uVar20 = (param_3 & 1) << 0x15;
        *DAT_08029394 = uVar22 & 0xffdfffff | uVar20;
        if ((param_3 & 1) == 0) {
          uVar24 = puVar3[1] & 0xfffffffd;
        }
        else {
          uVar24 = puVar3[1] | 2;
        }
        uVar8 = param_3 >> 1 & 1;
        uVar1 = uVar8 << 0x16;
        *puVar2 = uVar22 & 0xff9fffff | uVar20 | uVar1;
        if (uVar8 == 0) {
          uVar24 = uVar24 & 0xfffffffb;
        }
        else {
          uVar24 = uVar24 | 4;
        }
        uVar9 = param_3 >> 10 & 1;
        uVar8 = uVar9 << 0x17;
        *puVar2 = uVar22 & 0xff1fffff | uVar20 | uVar1 | uVar8;
        if (uVar9 == 0) {
          uVar24 = uVar24 & 0xfffffdff;
        }
        else {
          uVar24 = uVar24 | 0x200;
        }
        uVar10 = param_3 >> 0xb & 1;
        uVar9 = uVar10 << 0x18;
        *puVar2 = uVar22 & 0xfe1fffff | uVar20 | uVar1 | uVar8 | uVar9;
        if (uVar10 == 0) {
          uVar24 = uVar24 & 0xfffffbff;
        }
        else {
          uVar24 = uVar24 | 0x400;
        }
        uVar11 = param_3 >> 0xc & 1;
        uVar10 = uVar11 << 0x19;
        *puVar2 = uVar22 & 0xfc1fffff | uVar20 | uVar1 | uVar8 | uVar9 | uVar10;
        if (uVar11 == 0) {
          uVar24 = uVar24 & 0xfffff7ff;
        }
        else {
          uVar24 = uVar24 | 0x800;
        }
        uVar12 = param_3 >> 2 & 1;
        uVar11 = uVar12 << 0x1a;
        *puVar2 = uVar22 & 0xf81fffff | uVar20 | uVar1 | uVar8 | uVar9 | uVar10 | uVar11;
        if (uVar12 == 0) {
          uVar24 = uVar24 & 0xfffffff7;
        }
        else {
          uVar24 = uVar24 | 8;
        }
        uVar13 = param_3 >> 3 & 1;
        uVar12 = uVar13 << 0x1b;
        *puVar2 = uVar22 & 0xf01fffff | uVar20 | uVar1 | uVar8 | uVar9 | uVar10 | uVar11 | uVar12;
        if (uVar13 == 0) {
          uVar24 = uVar24 & 0xffffffef;
        }
        else {
          uVar24 = uVar24 | 0x10;
        }
        uVar14 = param_3 >> 4 & 1;
        uVar13 = uVar14 << 0x1c;
        *puVar2 = uVar22 & 0xe01fffff | uVar20 | uVar1 | uVar8 | uVar9 | uVar10 | uVar11 | uVar12 |
                  uVar13;
        if (uVar14 == 0) {
          uVar24 = uVar24 & 0xffffffdf;
        }
        else {
          uVar24 = uVar24 | 0x20;
        }
        uVar15 = param_3 >> 5 & 1;
        uVar14 = uVar15 << 0x1d;
        *puVar2 = uVar22 & 0xc01fffff | uVar20 | uVar1 | uVar8 | uVar9 | uVar10 | uVar11 | uVar12 |
                  uVar13 | uVar14;
        if (uVar15 == 0) {
          uVar24 = uVar24 & 0xffffffbf;
        }
        else {
          uVar24 = uVar24 | 0x40;
        }
        uVar16 = param_3 >> 6 & 1;
        uVar15 = uVar16 << 0x1e;
        *puVar2 = uVar22 & 0x801fffff | uVar20 | uVar1 | uVar8 | uVar9 | uVar10 | uVar11 | uVar12 |
                  uVar13 | uVar14 | uVar15;
        if (uVar16 == 0) {
          uVar24 = uVar24 & 0xffffff7f;
        }
        else {
          uVar24 = uVar24 | 0x80;
        }
        *puVar2 = uVar22 & 0x1fffff | uVar20 | uVar1 | uVar8 | uVar9 | uVar10 | uVar11 | uVar12 |
                  uVar13 | uVar14 | uVar15 | (param_3 >> 7) << 0x1f;
        if ((param_3 >> 7 & 1) == 0) {
          uVar24 = uVar24 & 0xfffffeff;
        }
        else {
          uVar24 = uVar24 | 0x100;
        }
        puVar3[1] = uVar24;
      }
      else if (param_2 == 0x531) {
        FUN_08028052(param_3);
      }
      else {
        if (param_2 == 0x5e0) {
          DAT_08029394[1] = DAT_08029394[1] & 0xffffffdf | (param_3 & 1) << 5;
          goto LAB_0802938a;
        }
        if (param_2 == 0x5e1) {
          uVar23 = FUN_080160f2(param_3);
          goto LAB_0802938a;
        }
        if (param_2 == 0x700) {
          FUN_0801d3dc(param_3);
          goto LAB_0802938a;
        }
        if (param_2 == 0x8000) {
          FUN_0801d400(param_3);
        }
        else if (param_2 == 0x8001) {
          FUN_0801d43a(param_3);
        }
        else if (param_2 == 0x8002) {
          FUN_0801d474(param_3 * 100);
        }
        else {
          if (param_2 != 0x8003) {
            if (param_2 == 0x8004) {
              uVar20 = *DAT_08029394 & 0xfffffffe | param_3 & 1;
            }
            else {
              if (param_2 != 0x8005) {
                if (param_2 == 0x8007) {
                  FUN_0801b09c(param_3);
                  goto LAB_0802938a;
                }
                if (param_2 == 0x8008) {
                  if (param_3 == 0) {
                    param_3 = *(uint *)(DAT_08029dbc + 0x50);
                  }
                  FUN_0801d4cc(param_3);
                }
                else {
                  if (param_2 != 0x8009) {
                    if (param_2 == 0x800c) {
                      uVar20 = *DAT_08029394 & 0xfffffff7 | (param_3 & 1) << 3;
                    }
                    else {
                      if (param_2 != 0x8013) {
                        if (param_2 == 0x8014) {
                          FUN_0801d474(param_3);
                        }
                        else {
                          if (param_2 != 0x8015) {
                            if (param_2 == 0x8016) {
                              bVar7 = 0;
                              if (param_3 == 1) {
                                bVar7 = 2;
                              }
                              *(byte *)DAT_08029394 = bVar7 | (byte)*DAT_08029394 & 0xfd;
                            }
                            else if (param_2 == 0xc000) {
                              iVar19 = FUN_08027ff4();
                              if (iVar19 == 1) {
                                FUN_080238cc(param_3);
                              }
                            }
                            else if (param_2 == 0xc001) {
                              FUN_08023952((int)(short)param_3);
                            }
                            else if (param_2 == 0xc002) {
                              if ((param_3 & 0xff) == 0) {
                                *DAT_08029dc0 = 0xffff;
                              }
                              *(byte *)(DAT_08029a44 + 6) =
                                   *(byte *)(DAT_08029a44 + 6) & 0xfc | bVar7 & 3;
                            }
                            else if (param_2 == 0xc004) {
                              iVar19 = FUN_08027ff4();
                              if (iVar19 != 0) {
                                FUN_08024386(param_3);
                              }
                            }
                            else if (param_2 == 0xc005) {
                              if ((*(byte *)(DAT_08029a44 + 6) & 3) != 0) {
                                FUN_080243e8(param_3);
                              }
                            }
                            else if (param_2 == 0xc008) {
                              FUN_08023d06();
                            }
                            else if (param_2 == 0xc009) {
                              FUN_080239a0(param_3);
                            }
                            else if (param_2 == 0xc00a) {
                              FUN_0802db38(param_3);
                            }
                            else {
                              uVar23 = 0;
                            }
                            goto LAB_0802938a;
                          }
                          FUN_0801d49c(param_3);
                        }
                        goto LAB_080292e6;
                      }
                      uVar20 = 0;
                      if (param_3 == 0) {
                        uVar20 = 4;
                      }
                      uVar20 = uVar20 | *DAT_08029394 & 0xfffffffb;
                    }
                    goto LAB_080292c4;
                  }
                  if (param_3 == 0) {
                    param_3 = *(uint *)(DAT_08029dbc + 0x54);
                  }
                  FUN_0801d502(param_3);
                }
                goto LAB_080292e6;
              }
              uVar20 = *DAT_08029394 & 0xffffff9f | (param_3 & 3) << 5;
            }
LAB_080292c4:
            *DAT_08029394 = uVar20;
            goto LAB_0802938a;
          }
          FUN_0801d49c(param_3 * 100);
        }
      }
LAB_080292e6:
      uVar17 = FUN_08017dbe();
      disableIRQinterrupts();
      uVar18 = *DAT_08029a48;
      uVar21 = DAT_08029a48[1];
      goto LAB_080292f6;
    }
    FUN_08028018(param_3);
    uVar17 = FUN_08017dbe();
    uVar25 = FUN_08027fe6();
  }
  FUN_080181c8((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),uVar17,3);
LAB_0802938a:
  FUN_0801472c();
  return CONCAT44(param_4,uVar23);
}



/* ===== FUN_08029398 @ 08029398 ===== */

undefined4 FUN_08029398(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  puVar2 = *(undefined4 **)(param_1 + 4);
  puVar4 = *(undefined4 **)(param_1 + 8);
  uVar1 = *puVar2;
  *(undefined4 **)(param_1 + 4) = puVar2 + 2;
  uVar3 = puVar2[1];
  *puVar4 = DAT_08029dc4;
  *(undefined4 **)(param_1 + 8) = puVar4 + 2;
  uVar1 = FUN_08028c58(param_1,uVar1,uVar3);
  puVar4[1] = uVar1;
  return param_4;
}



/* ===== FUN_080293bc @ 080293bc ===== */

undefined4 FUN_080293bc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  uVar1 = DAT_08029dc8;
  puVar3 = *(uint **)(param_1 + 4);
  puVar5 = *(undefined4 **)(param_1 + 8);
  *(uint **)(param_1 + 4) = puVar3 + 1;
  puVar8 = *(undefined4 **)(param_1 + 4);
  uVar4 = *puVar3;
  *puVar5 = uVar1;
  puVar9 = puVar8 + uVar4;
  uVar7 = 0;
  *(undefined4 **)(param_1 + 8) = puVar5 + 2;
  uVar6 = 0;
  if (uVar4 != 0) {
    do {
      iVar2 = FUN_08028c58(param_1,*puVar8,*puVar9);
      if (iVar2 != 0) {
        uVar7 = uVar7 | 1 << (uVar6 & 0xff);
      }
      uVar6 = uVar6 + 1;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
    } while (uVar6 < uVar4);
  }
  puVar5[1] = uVar7;
  return param_4;
}



/* ===== FUN_08029a00 @ 08029a00 ===== */

void FUN_08029a00(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 auStack_90 [128];
  
  uVar1 = DAT_08029e40;
  puVar2 = *(undefined4 **)(param_1 + 8);
  *(undefined4 **)(param_1 + 8) = puVar2 + 1;
  *puVar2 = uVar1;
  iVar3 = *(int *)(param_1 + 4);
  *(int *)(param_1 + 4) = iVar3 + 4;
  FUN_0801d96e(auStack_90 + 0x80,*(undefined1 *)(iVar3 + 6),puVar2);
  return;
}



/* ===== FUN_08029c3e @ 08029c3e ===== */

undefined8 FUN_08029c3e(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  
  uVar2 = DAT_08029e70;
  if ((int)((uint)*DAT_08029e0c << 0x1a) < 0) {
    puVar4 = (undefined4 *)param_1[1];
    uVar1 = *puVar4;
    uVar3 = puVar4[1];
    puVar7 = (undefined4 *)param_1[2];
    param_1[1] = (int)(puVar4 + 3);
    uVar5 = puVar4[2];
    param_1[2] = (int)(puVar7 + 1);
    *puVar7 = uVar2;
    iVar6 = *(int *)(*param_1 + 0xc);
    if (iVar6 - 0x20U < uVar5) {
      uVar2 = 0x13;
    }
    else if (uVar5 == 0) {
      uVar2 = (*(code *)DAT_08029e74[1])(*(undefined4 *)(*param_1 + 4),iVar6,uVar1);
    }
    else {
      uVar2 = (*(code *)*DAT_08029e74)(uVar1,uVar3);
    }
  }
  else {
    uVar2 = DAT_08029e64;
  }
  puVar4 = (undefined4 *)param_1[2];
  param_1[2] = (int)(puVar4 + 1);
  *puVar4 = uVar2;
  return CONCAT44(puVar4,param_4);
}



/* ===== FUN_08029d58 @ 08029d58 ===== */

undefined4 FUN_08029d58(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  puVar3 = *(uint **)(param_1 + 4);
  uVar6 = *puVar3;
  uVar1 = puVar3[1];
  uVar4 = puVar3[2];
  *(uint **)(param_1 + 4) = puVar3 + 4;
  iVar2 = FUN_08027a06(uVar1 & 0xff,uVar4 & 0xff,puVar3[3] & 0xff);
  if (iVar2 == 0) {
    iVar2 = FUN_0802a454(1,uVar6 & 0xff);
  }
  puVar5 = *(undefined4 **)(param_1 + 8);
  *puVar5 = DAT_08029e88;
  *(undefined4 **)(param_1 + 8) = puVar5 + 2;
  puVar5[1] = iVar2;
  return param_4;
}



/* ===== FUN_08029fe0 @ 08029fe0 ===== */

undefined4 FUN_08029fe0(void)

{
  uint *puVar1;
  int iVar2;
  undefined4 in_r3;
  
  iVar2 = DAT_0802a0ec;
  puVar1 = DAT_0802a0e8;
  **(undefined1 **)(DAT_0802a0ec + 0xc) = 0;
  puVar1[4] = 0;
  puVar1[3] = 0;
  FUN_08024acc();
  **(undefined1 **)(iVar2 + 0x10) = 0;
  puVar1[5] = 0;
  *puVar1 = *puVar1 & 0xfffffffb;
  FUN_08024a7e();
  *puVar1 = *puVar1 & 0xfffffffd;
  return in_r3;
}



/* ===== FUN_0802a012 @ 0802a012 ===== */

void FUN_0802a012(void)

{
  uint *puVar1;
  uint uVar2;
  
  **(undefined1 **)(DAT_0802a0ec + 0x10) = 0;
  puVar1 = DAT_0802a0e8;
  uVar2 = *DAT_0802a0e8;
  DAT_0802a0e8[5] = 0;
  *puVar1 = uVar2 & 0xfffffffb;
  FUN_08024a7e();
  return;
}



/* ===== FUN_0802a02c @ 0802a02c ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0802a02c(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  uint *puVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 unaff_r7;
  int iVar9;
  undefined4 unaff_lr;
  
  pcVar2 = DAT_0802a0f4;
  iVar7 = DAT_0802a0ec;
  puVar1 = DAT_0802a0e8;
  if (*DAT_0802a0f4 == '\a') {
    uVar5 = *DAT_0802a0e8;
    iVar9 = *(int *)(DAT_0802a0ec + 8);
    if (((int)(uVar5 << 0x1e) < 0) && ((int)(uVar5 << 0x1d) < 0)) {
      uVar8 = DAT_0802a0e8[5];
      *DAT_0802a0e8 = uVar5 & 0xfffffffb;
      if (0x14 < uVar8) {
        uVar8 = 0x14;
      }
      iVar6 = FUN_0802a8ec((short)puVar1[1],*(undefined2 *)((int)puVar1 + 6),0,uVar8 & 0xff);
      puVar3 = _DAT_0802a0f8;
      if (iVar6 == 100) {
        *pcVar2 = '\b';
        iVar7 = 10000;
      }
      else {
        if (iVar6 != 0) {
          if (iVar6 < 0xf2) {
            FUN_08016812();
            *pcVar2 = '\0';
            *puVar3 = 1;
            if (pcVar2[2] == '\0') {
              pcVar2[2] = ' ';
            }
            uVar5 = 0x20;
          }
          else {
            *pcVar2 = '\0';
            *puVar3 = 1;
            if (pcVar2[2] == '\0') {
              pcVar2[2] = (char)(0x20U - iVar6);
            }
            uVar5 = 0x20U - iVar6 & 0xff;
          }
          FUN_08017f38("BLE: error #0x%0.2X!",uVar5);
          puVar1[5] = 0;
          iVar7 = FUN_08024a7e(iVar9,param_4);
          return iVar7;
        }
        *(uint *)(iVar7 + 8) = (uVar8 & 0xff) + iVar9;
        uVar5 = puVar1[5] - (uVar8 & 0xff);
        puVar1[5] = uVar5;
        if (uVar5 == 0) {
          FUN_08024a7e();
          **(undefined1 **)(iVar7 + 0x10) = 0;
          return iVar9;
        }
        iVar7 = 5;
      }
      uVar4 = FUN_08019bb0(iVar7 * 0x2000 + 0x7d,0xffffff82 < (uint)(iVar7 * 0x2000),0xfa,0,unaff_r7
                           ,unaff_lr);
      iVar7 = FUN_080165ac(DAT_08024af4,uVar4,unaff_r7);
      return iVar7;
    }
  }
  return param_3;
}



/* ===== FUN_0802a144 @ 0802a144 ===== */

longlong FUN_0802a144(int param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  
  iVar1 = FUN_0802a4f0(param_2);
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
      iVar1 = FUN_0802a538(param_2,sVar2,param_1);
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



/* ===== FUN_0802a186 @ 0802a186 ===== */

char FUN_0802a186(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  uint uVar8;
  
  iVar4 = FUN_0802a268();
  if (iVar4 == 0) {
    iVar5 = FUN_0802a216();
    iVar4 = DAT_0802a2c0;
    if (iVar5 == 6) {
      uVar8 = 0;
      iVar5 = DAT_0802a2bc;
      do {
        iVar6 = FUN_0802a596(iVar4 + uVar8,0x40,iVar5);
        iVar1 = DAT_0802a2bc;
        if (iVar6 != 0) goto LAB_0802a1e6;
        uVar8 = uVar8 + 0x40;
        iVar5 = iVar5 + 0x40;
      } while (uVar8 < 0x800);
      FUN_080262d4(DAT_0802a2bc + 0x100,DAT_0802a2c4,0xe);
      iVar4 = FUN_0802a144(iVar1,iVar4,0x800);
      if ((iVar4 == 0) && (iVar4 = FUN_0802a216(), iVar4 == 0)) {
        return '\0';
      }
LAB_0802a1e6:
      cVar7 = '\x03';
    }
    else {
      if (iVar5 == 0) {
        return '\0';
      }
      cVar7 = '\x02';
    }
  }
  else {
    cVar7 = '\x01';
  }
  puVar3 = DAT_0802a2cc;
  puVar2 = DAT_0802a2c8;
  *DAT_0802a2c8 = 0;
  *puVar3 = 1;
  if (puVar2[2] == '\0') {
    puVar2[2] = cVar7 + 4U | 0x80;
  }
  FUN_08017f38("BLE: error #0x%0.2X!");
  return cVar7;
}



/* ===== FUN_0802a216 @ 0802a216 ===== */

undefined4 FUN_0802a216(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_48 [64];
  
  iVar1 = FUN_0802a596(DAT_0802a2d0,0xe,auStack_48);
  if (iVar1 != 0) {
    return 3;
  }
  iVar1 = FUN_0802fb1c(auStack_48,DAT_0802a2c4,0xe);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 6;
  }
  return uVar2;
}



/* ===== FUN_0802a23e @ 0802a23e ===== */

void FUN_0802a23e(void)

{
  uint *puVar1;
  
  puVar1 = DAT_0802a2b4;
  DAT_0802a2b4[6] = 0x1000;
  *puVar1 = *puVar1 & 0xfcffffff | 0x1000000;
  puVar1[1] = puVar1[1] & 0xffffefff;
  return;
}



/* ===== FUN_0802a25a @ 0802a25a ===== */

void FUN_0802a25a(void)

{
  *DAT_0802a2b4 = *DAT_0802a2b4 & 0xfcffffff | 0x2000000;
  return;
}



/* ===== FUN_0802a268 @ 0802a268 ===== */

undefined4 FUN_0802a268(void)

{
  int *piVar1;
  char *pcVar2;
  
  pcVar2 = DAT_0802a2c8;
  if (*DAT_0802a2c8 != '\x02') {
    FUN_080192cc(1);
    piVar1 = DAT_0802a2b8;
    do {
    } while ((uint)(*DAT_0802a2b8 - *DAT_0802a2b8) < DAT_0802a2d4);
    *DAT_0802a2b4 = *DAT_0802a2b4 & 0xfcffffff | 0x2000000;
    do {
    } while ((uint)(*piVar1 - *piVar1) < DAT_0802a2d8);
    FUN_08027aa0();
    if (*pcVar2 != '\x02') {
      return 1;
    }
  }
  pcVar2[1] = 'd';
  return 0;
}



/* ===== FUN_0802a2f4 @ 0802a2f4 ===== */

void FUN_0802a2f4(void)

{
  int iVar1;
  
  iVar1 = DAT_0802a390;
  if (*(char *)(DAT_0802a390 + 0xd) == '\x02') {
    FUN_08016384(DAT_0802a394,2);
    *(undefined1 *)(iVar1 + 0xd) = 0;
    FUN_080157c8(0);
    FUN_080165ce(iVar1);
    return;
  }
  return;
}



/* ===== FUN_0802a304 @ 0802a304 ===== */

uint FUN_0802a304(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)(DAT_0802a390 + 0xd);
  if (param_1 == uVar2) {
    uVar1 = 1;
  }
  else {
    uVar1 = -(uint)(uVar2 == 0) >> 0x1f;
  }
  return uVar1 | uVar2 << 8;
}



/* ===== FUN_0802a31c @ 0802a31c ===== */

uint FUN_0802a31c(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint *puVar2;
  byte bVar3;
  uint uVar4;
  undefined4 uVar5;
  bool bVar6;
  
  iVar1 = DAT_0802a390;
  if (*(byte *)(DAT_0802a390 + 0xd) != param_1) {
    if (*(byte *)(DAT_0802a390 + 0xd) != 0) {
      return param_4;
    }
    *(char *)(DAT_0802a390 + 0xd) = (char)param_1;
  }
  FUN_080157c8(param_1);
  if (*(char *)(iVar1 + 0xc) == '\0') {
    FUN_08017cdc(2);
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
  FUN_080165ac(iVar1,uVar5);
  puVar2 = DAT_0802a394;
  uVar4 = 1 << (param_1 & 0xff);
  bVar6 = (DAT_0802a394[3] & uVar4) == 0;
  if (bVar6) {
    uVar4 = uVar4 | DAT_0802a394[3];
    DAT_0802a394[3] = uVar4;
  }
  if (bVar6 && param_1 == 2) {
    bVar3 = FUN_08020c96();
    uVar4 = (uint)bVar3;
    if ((uVar4 < 3) && (uVar4 = 0x4001, (*puVar2 & 0x4001) == 0x4001)) {
      uVar4 = FUN_08020a8a(8,3,0);
      return uVar4;
    }
  }
  return uVar4;
}



/* ===== FUN_0802a364 @ 0802a364 ===== */

void FUN_0802a364(uint param_1)

{
  int iVar1;
  
  iVar1 = DAT_0802a390;
  if (param_1 == *(byte *)(DAT_0802a390 + 0xd)) {
    FUN_08016384(DAT_0802a394);
    *(undefined1 *)(iVar1 + 0xd) = 0;
    FUN_080157c8(0);
    FUN_080165ce(iVar1);
    return;
  }
  return;
}



/* ===== FUN_0802a398 @ 0802a398 ===== */

undefined1
FUN_0802a398(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,
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
  FUN_0802f9c4(&local_12c,0,0x18);
  local_12c = 0x3f;
  local_128 = 0xf;
  local_12a = 0x181;
  local_120 = 10;
  local_124 = &local_114;
  local_118 = 1;
  local_11c = local_130;
  iVar1 = FUN_08027c74(&local_12c,0);
  if (iVar1 < 0) {
    local_130[0] = 0xff;
  }
  return local_130[0];
}



/* ===== FUN_0802a3f6 @ 0802a3f6 ===== */

undefined1 FUN_0802a3f6(undefined1 param_1,int param_2,undefined4 param_3)

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
  FUN_0802f9b8(auStack_10a,param_3,param_2);
  FUN_0802f9c4(&local_124,0,0x18);
  local_11c = &local_10c;
  local_124 = 0x3f;
  local_122 = 0xc;
  local_118 = param_2 + 2U & 0xff;
  local_110 = 1;
  local_114 = local_128;
  iVar1 = FUN_08027c74(&local_124,0);
  if (iVar1 < 0) {
    local_128[0] = 0xff;
  }
  return local_128[0];
}



/* ===== FUN_0802a454 @ 0802a454 ===== */

undefined1 FUN_0802a454(undefined1 param_1,undefined1 param_2)

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
  FUN_0802f9c4(&local_124,0,0x18);
  local_122 = 0xf;
  local_124 = 0x3f;
  local_118 = 2;
  local_11c = &local_10c;
  local_110 = 1;
  local_114 = local_128;
  iVar1 = FUN_08027c74(&local_124,0);
  if (iVar1 < 0) {
    local_128[0] = 0xff;
  }
  return local_128[0];
}



/* ===== FUN_0802a4a2 @ 0802a4a2 ===== */

undefined1 FUN_0802a4a2(undefined1 param_1,undefined1 param_2)

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
  FUN_0802f9c4(&local_124,0,0x18);
  local_122 = 0x15;
  local_124 = 0x3f;
  local_118 = 2;
  local_11c = &local_10c;
  local_110 = 1;
  local_114 = local_128;
  iVar1 = FUN_08027c74(&local_124,0);
  if (iVar1 < 0) {
    local_128[0] = 0xff;
  }
  return local_128[0];
}



/* ===== FUN_0802a4f0 @ 0802a4f0 ===== */

undefined1 FUN_0802a4f0(undefined4 param_1)

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
  FUN_0802f9c4(&local_124,0,0x18);
  local_122 = 0x26;
  local_124 = 0x3f;
  local_118 = 4;
  local_11c = local_10c;
  local_110 = 1;
  local_114 = local_128;
  iVar1 = FUN_08027c74(&local_124,0);
  if (iVar1 < 0) {
    local_128[0] = 0xff;
  }
  return local_128[0];
}



/* ===== FUN_0802a538 @ 0802a538 ===== */

undefined1 FUN_0802a538(undefined4 param_1,int param_2,undefined4 param_3)

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
  FUN_0802f9b8(auStack_106,param_3,param_2);
  FUN_0802f9c4(&local_124,0,0x18);
  local_11c = &local_10c;
  local_124 = 0x3f;
  local_122 = 0x27;
  local_118 = param_2 + 6U & 0xff;
  local_110 = 1;
  local_114 = local_128;
  iVar1 = FUN_08027c74(&local_124,0);
  if (iVar1 < 0) {
    local_128[0] = 0xff;
  }
  return local_128[0];
}



/* ===== FUN_0802a596 @ 0802a596 ===== */

char FUN_0802a596(undefined4 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4)

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
  FUN_0802f9c4(&local_198,0,0x80);
  local_118 = param_1;
  local_114 = param_2;
  FUN_0802f9c4(&local_1b0,0,0x18);
  local_1ae = 0x28;
  local_1a8 = &local_118;
  local_1a4 = 6;
  local_1b0 = 0x3f;
  local_1a0 = &local_198;
  local_19c = 0x80;
  iVar1 = FUN_08027c74(&local_1b0,0);
  if (iVar1 < 0) {
    local_198 = -1;
  }
  else if (local_198 == '\0') {
    FUN_0802f9b8(param_3,auStack_197,local_19c + -1);
    local_198 = '\0';
  }
  return local_198;
}



/* ===== FUN_0802a604 @ 0802a604 ===== */

uint FUN_0802a604(char *param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint unaff_r6;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char cVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  pcVar6 = param_1;
  while (iVar4 = FUN_0802fb84(*pcVar6), iVar2 = DAT_0802a6b0, iVar4 != 0) {
    pcVar6 = pcVar6 + 1;
  }
  cVar1 = *pcVar6;
  if (cVar1 == '-' || cVar1 == '+') {
    cVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  }
  else {
    cVar9 = '+';
  }
  if ((((int)param_3 < 0) || (param_3 == 1)) || (0x24 < (int)param_3)) {
    if (param_2 == (undefined4 *)0x0) {
      return 0;
    }
    *param_2 = param_1;
    return 0;
  }
  pcVar7 = pcVar6;
  if ((int)param_3 < 1) {
    if (*pcVar6 != '0') {
      param_3 = 10;
      goto LAB_0802a68e;
    }
    if ((byte)(pcVar6[1] | 0x20U) != 0x78) {
      param_3 = 8;
      goto LAB_0802a68e;
    }
    param_3 = 0x10;
  }
  else {
    bVar12 = param_3 == 0x10;
    if (bVar12) {
      cVar1 = *pcVar6;
    }
    bVar13 = bVar12 && cVar1 == '0';
    if (bVar12 && cVar1 == '0') {
      bVar13 = (byte)(pcVar6[1] | 0x20U) == 0x78;
    }
    if (!bVar13) goto LAB_0802a68e;
  }
  pcVar6 = pcVar6 + 2;
  pcVar7 = pcVar6;
LAB_0802a68e:
  for (; *pcVar6 == '0'; pcVar6 = pcVar6 + 1) {
  }
  cVar1 = (char)DAT_0802a6b0;
  pcVar8 = pcVar6;
  uVar3 = 0;
  uVar11 = 0;
  while( true ) {
    uVar10 = uVar3;
    uVar5 = FUN_0802fb98(*pcVar8);
    iVar4 = FUN_0802cfa8(iVar2 + 0x802a6d8,uVar5,param_3);
    if (iVar4 == 0) break;
    unaff_r6 = iVar4 - (uint)(byte)(cVar1 - 0x28) & 0xff;
    pcVar8 = pcVar8 + 1;
    uVar3 = param_3 * uVar10 + unaff_r6;
    uVar11 = uVar10;
  }
  if (pcVar7 == pcVar8) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_1;
    }
    return 0;
  }
  if (((int)(pcVar8 + (-(uint)*(byte *)((int)&DAT_0802a6b0 + param_3 + iVar2) - (int)pcVar6)) < 0)
     || ((((int)(pcVar8 + (-(uint)*(byte *)((int)&DAT_0802a6b0 + param_3 + iVar2) - (int)pcVar6)) <
           1 && (unaff_r6 <= uVar10)) && ((uVar10 - unaff_r6) / param_3 == uVar11)))) {
    if (cVar9 == '-') {
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
    *param_2 = pcVar8;
  }
  return uVar10;
}



/* ===== thunk_FUN_0802a738 @ 0802a736 ===== */

void thunk_FUN_0802a738(undefined4 param_1)

{
  FUN_0802a604(param_1,0,10,0);
  return;
}



/* ===== FUN_0802a738 @ 0802a738 ===== */

void FUN_0802a738(undefined4 param_1)

{
  FUN_0802a604(param_1,0,10,0);
  return;
}



/* ===== FUN_0802a742 @ 0802a742 ===== */

undefined1 FUN_0802a742(void)

{
  int iVar1;
  undefined1 local_20 [4];
  undefined2 local_1c;
  undefined2 local_1a;
  undefined1 *local_c;
  undefined4 local_8;
  
  local_20[0] = 0;
  FUN_0802f9c4(&local_1c,0,0x18);
  local_1a = 0x101;
  local_1c = 0x3f;
  local_8 = 1;
  local_c = local_20;
  iVar1 = FUN_08027c74(&local_1c,0);
  if (iVar1 < 0) {
    local_20[0] = 0xff;
  }
  return local_20[0];
}



/* ===== FUN_0802a782 @ 0802a782 ===== */

char FUN_0802a782(int param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4,
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
  FUN_0802f9c4(&local_138,0,3);
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
  FUN_0802f9b8(auStack_11b,param_2,iVar2);
  auStack_11b[iVar1] = param_3;
  auStack_11b[iVar1 + 1] = param_4;
  FUN_0802f9c4(&local_134,0,0x18);
  local_12c = &local_11c;
  local_134 = 0x3f;
  local_132 = 0x102;
  local_128 = iVar2 + 3;
  local_120 = 3;
  local_124 = &local_138;
  iVar1 = FUN_08027c74(&local_134,0);
  if (iVar1 < 0) {
    local_138 = -1;
  }
  else if (local_138 == '\0') {
    *param_5 = local_137;
    local_138 = '\0';
  }
  return local_138;
}



/* ===== FUN_0802a826 @ 0802a826 ===== */

char FUN_0802a826(undefined2 param_1,int param_2,undefined4 param_3,undefined2 param_4,
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
  FUN_0802f9c4(&local_148,0,3);
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
  FUN_0802f9b8(&local_129,local_28,iVar2);
  *(undefined2 *)(local_127 + iVar1 + -2) = param_4;
  local_127[iVar1] = param_5;
  local_127[iVar1 + 1] = param_6;
  local_127[iVar1 + 2] = param_7;
  local_127[iVar1 + 3] = param_8;
  local_127[iVar1 + 4] = param_9;
  FUN_0802f9c4(&local_144,0,0x18);
  local_13c = &local_12c;
  local_144 = 0x3f;
  local_142 = 0x104;
  local_138 = iVar2 + 10;
  local_130 = 3;
  local_134 = &local_148;
  iVar1 = FUN_08027c74(&local_144,0);
  if (iVar1 < 0) {
    local_148 = -1;
  }
  else if (local_148 == '\0') {
    *param_10 = local_147;
    local_148 = '\0';
  }
  return local_148;
}



/* ===== FUN_0802a8ec @ 0802a8ec ===== */

byte FUN_0802a8ec(undefined2 param_1,undefined2 param_2,undefined1 param_3,int param_4,
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
  FUN_0802f9b8(auStack_10e,param_5,param_4);
  FUN_0802f9c4(&local_12c,0,0x18);
  local_124 = &local_114;
  local_12c = 0x3f;
  local_12a = 0x106;
  local_120 = param_4 + 6U & 0xff;
  local_118 = 1;
  local_11c = local_130;
  bVar1 = FUN_08027c74(&local_12c,0);
  if (0xf1 < bVar1) {
    local_130[0] = bVar1;
  }
  return local_130[0];
}



/* ===== FUN_0802a95c @ 0802a95c ===== */

int * FUN_0802a95c(int *param_1)

{
  *param_1 = (int)(param_1 + 0x102);
  param_1[1] = 0;
  FUN_0802fbac(param_1 + 4);
  FUN_0802aa70(param_1 + 0x14);
  FUN_0802fbe0(param_1 + 0x1e);
  FUN_0802fc3a(param_1 + 0x68,DAT_0802a99c,0x58,7);
  FUN_0801ace4(param_1);
  return param_1;
}



/* ===== FUN_0802a9a0 @ 0802a9a0 ===== */

float FUN_0802a9a0(float param_1)

{
  if (0.0 <= param_1) {
    return SQRT(param_1);
  }
  return NAN;
}



/* ===== FUN_0802a9be @ 0802a9be ===== */

void FUN_0802a9be(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar5 = *(uint *)(param_1 + 0x18);
  lVar1 = (ulonglong)*(uint *)(param_2 + 4) * (ulonglong)uVar5 +
          CONCAT44(*(uint *)(param_2 + 4) * ((int)uVar5 >> 0x1f),*(undefined4 *)(param_1 + 0x28));
  uVar2 = (uint)lVar1;
  *(uint *)(param_1 + 0x28) = uVar2 - *(uint *)(param_1 + 4);
  *(uint *)(param_1 + 0x2c) =
       (*(int *)(param_1 + 0x2c) + (int)((ulonglong)lVar1 >> 0x20)) -
       (uint)(uVar2 < *(uint *)(param_1 + 4));
  uVar6 = *(uint *)(param_1 + 0x30);
  iVar4 = *(int *)(param_1 + 0x34);
  uVar7 = FUN_0802aa28(*(undefined4 *)(param_2 + 8));
  lVar1 = (uVar7 & 0xffffffff) * (ulonglong)uVar5;
  uVar2 = (uint)lVar1;
  uVar3 = uVar6 + uVar2;
  *(uint *)(param_1 + 0x30) = uVar3 - *(uint *)(param_1 + 8);
  *(uint *)(param_1 + 0x34) =
       (((int)(uVar7 >> 0x20) * uVar5 +
         (int)uVar7 * ((int)uVar5 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20) + iVar4 +
        (uint)CARRY4(uVar6,uVar2)) - *(int *)(param_1 + 0xc)) -
       (uint)(uVar3 < *(uint *)(param_1 + 8));
  FUN_08019ed4(param_1,param_2,param_4);
  return;
}



/* ===== FUN_0802aa28 @ 0802aa28 ===== */

ulonglong FUN_0802aa28(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = (param_1 & 0x7fffffff) >> 0x17;
  uVar3 = (int)param_1 >> 0x1f;
  iVar1 = -uVar4;
  uVar5 = iVar1 + 0x9e;
  uVar2 = param_1 << 8 | 0x80000000;
  if (uVar5 == 0 || 0x9e < uVar4) {
    uVar4 = iVar1 + 0xbe;
    if (uVar4 != 0 && -0x21 < (int)uVar5) {
      uVar5 = uVar2 << (0x20 - uVar4 & 0xff) ^ uVar3;
      return CONCAT44(((uVar2 >> (uVar4 & 0xff) ^ uVar3) - uVar3) - (uint)(uVar5 < uVar3),
                      uVar5 - uVar3);
    }
    if (iVar1 != -0xff) {
      return CONCAT44(~uVar3,~uVar3) ^ 0x8000000000000000;
    }
  }
  else {
    uVar2 = uVar2 >> (uVar5 & 0xff);
    if (uVar2 != 0) {
      return CONCAT44(uVar3,uVar2 + uVar3 ^ uVar3);
    }
  }
  return 0;
}



/* ===== FUN_0802aa70 @ 0802aa70 ===== */

void FUN_0802aa70(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  return;
}



/* ===== FUN_0802aa86 @ 0802aa86 ===== */

void FUN_0802aa86(int param_1,int param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  uVar5 = *(uint *)(param_1 + 0x28);
  uVar7 = *(uint *)(param_2 + 0x28);
  iVar4 = *(int *)(param_2 + 0x2c);
  uVar3 = *(uint *)(param_2 + 0x18);
  uVar13 = *(uint *)(param_1 + 0x18);
  uVar11 = uVar5 + uVar7;
  lVar1 = (ulonglong)*(uint *)(param_1 + 4) * (ulonglong)uVar3;
  uVar8 = (uint)lVar1;
  lVar2 = (ulonglong)*(uint *)(param_2 + 4) * (ulonglong)uVar13 +
          CONCAT44(*(uint *)(param_2 + 4) * ((int)uVar13 >> 0x1f),uVar11 - uVar8);
  *(int *)(param_1 + 0x28) = (int)lVar2;
  *(uint *)(param_1 + 0x2c) =
       (((*(int *)(param_1 + 0x2c) + iVar4 + (uint)CARRY4(uVar5,uVar7)) -
        (*(uint *)(param_1 + 4) * ((int)uVar3 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20))) -
       (uint)(uVar11 < uVar8)) + (int)((ulonglong)lVar2 >> 0x20);
  uVar11 = *(uint *)(param_2 + 0x30);
  iVar4 = *(int *)(param_2 + 0x34);
  uVar7 = *(uint *)(param_1 + 0x30);
  uVar12 = uVar7 + uVar11;
  lVar1 = (ulonglong)*(uint *)(param_1 + 8) * (ulonglong)uVar3;
  uVar9 = (uint)lVar1;
  uVar8 = *(uint *)(param_2 + 8);
  iVar6 = *(int *)(param_2 + 0xc);
  uVar5 = uVar12 - uVar9;
  lVar2 = (ulonglong)uVar8 * (ulonglong)uVar13;
  uVar10 = (uint)lVar2;
  *(uint *)(param_1 + 0x30) = uVar5 + uVar10;
  *(uint *)(param_1 + 0x34) =
       (((*(int *)(param_1 + 0x34) + iVar4 + (uint)CARRY4(uVar7,uVar11)) -
        (*(int *)(param_1 + 0xc) * uVar3 +
        *(uint *)(param_1 + 8) * ((int)uVar3 >> 0x1f) + (int)((ulonglong)lVar1 >> 0x20))) -
       (uint)(uVar12 < uVar9)) +
       iVar6 * uVar13 + uVar8 * ((int)uVar13 >> 0x1f) + (int)((ulonglong)lVar2 >> 0x20) +
       (uint)CARRY4(uVar5,uVar10);
  FUN_08019f74();
  return;
}



/* ===== FUN_0802ab14 @ 0802ab14 ===== */

longlong FUN_0802ab14(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  
  FUN_08019ed4();
  if (*(int *)(param_1 + 0x18) <= param_3) {
    return (ulonglong)param_4 << 0x20;
  }
  iVar2 = *(int *)(param_1 + 0x24);
  uVar1 = iVar2 + 0x10;
  if (*DAT_0802ab4c + 0x8000U <= uVar1) {
    uVar1 = iVar2 - 0x7ff0;
  }
  *(uint *)(param_1 + 0x24) = uVar1;
  FUN_08019f22(param_1,iVar2);
  return CONCAT44(param_4,iVar2);
}



/* ===== FUN_0802ab50 @ 0802ab50 ===== */

undefined8 FUN_0802ab50(uint param_1,uint param_2)

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



/* ===== FUN_0802ab98 @ 0802ab98 ===== */

float FUN_0802ab98(float param_1)

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
        param_1 = param_1 * *(float *)(DAT_0802ac34 + 0x802abc2);
        uVar2 = (uint)param_1 >> 0x17;
        param_1 = (float)((int)param_1 + (uVar2 - 0x7e) * -0x800000);
        iVar1 = uVar2 - 0x95;
      }
      else {
        iVar1 = ((uint)param_1 >> 0x17) - 0x7e;
        param_1 = (float)((int)param_1 + iVar1 * -0x800000);
      }
      if (param_1 < *(float *)(DAT_0802ac34 + 0x802abb6)) {
        iVar1 = iVar1 + -1;
        param_1 = param_1 * *(float *)(DAT_0802ac34 + 0x802abbe);
      }
      fVar4 = (float)VectorSignedToFloat(iVar1,(byte)((in_fpscr & 0xfffffff) >> 0x16) & 3);
      fVar5 = param_1 - *(float *)(DAT_0802ac34 + 0x802abba);
      fVar6 = fVar5 / (param_1 + *(float *)(DAT_0802ac34 + 0x802abba));
      fVar7 = fVar6 * fVar6;
      return (*(float *)(DAT_0802ac34 + 0x802abf6) * fVar5 -
             *(float *)(DAT_0802ac34 + 0x802abf2) *
             (fVar5 - (*(float *)(DAT_0802ac34 + 0x802abce) +
                      (*(float *)(DAT_0802ac34 + 0x802abca) +
                      *(float *)(DAT_0802ac34 + 0x802abc6) * fVar7) * fVar7) * fVar7) * fVar6) +
             *(float *)(DAT_0802ac34 + 0x802abf2) * fVar5 + fVar4;
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



/* ===== FUN_0802ac38 @ 0802ac38 ===== */

void FUN_0802ac38(int param_1,int param_2)

{
  int iVar1;
  byte *pbVar2;
  
  pbVar2 = (byte *)(param_1 + 0x3c);
  if (param_2 - *(int *)(param_1 + 0x44) < 0) {
    *pbVar2 = 1;
    iVar1 = *(int *)(param_1 + 0x48) + -1;
    *(int *)(param_1 + 0x48) = iVar1;
    if (0 < iVar1) {
      return;
    }
  }
  else if (param_2 == *(int *)(param_1 + 0x44)) goto LAB_0802ac60;
  *(int *)(param_1 + 0x44) = param_2;
  *(uint *)(param_1 + 0x40) = (uint)*(ushort *)(DAT_0802ac7c + param_2 * 2 + 2);
LAB_0802ac60:
  *pbVar2 = (byte)~(byte)(-(uint)(*pbVar2 == 0 && *(int *)(param_1 + 0x44) < 0) >> 0x18) >> 7;
  *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x40) << 1;
  return;
}



/* ===== FUN_0802ac80 @ 0802ac80 ===== */

float FUN_0802ac80(int param_1)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  if (*(int *)(param_1 + 0x18) < 1) {
    return DAT_0802aca4;
  }
  fVar1 = (float)VectorUnsignedToFloat(*(undefined4 *)(param_1 + 4),(byte)(in_fpscr >> 0x16) & 3);
  fVar2 = (float)VectorSignedToFloat(*(int *)(param_1 + 0x18),(byte)(in_fpscr >> 0x16) & 3);
  return fVar1 / fVar2;
}



/* ===== FUN_0802aca8 @ 0802aca8 ===== */

undefined4 FUN_0802aca8(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint in_fpscr;
  
  iVar4 = *(int *)(param_1 + 0x18);
  VectorUnsignedToFloat(*(undefined4 *)(param_1 + 4),(byte)(in_fpscr >> 0x16) & 3);
  if ((0 < iVar4) && (1 < iVar4)) {
    uVar3 = (param_2 * 2 - iVar4) + 1;
    uVar1 = (ulonglong)uVar3 * (ulonglong)*(uint *)(param_1 + 0x28);
    lVar2 = (uVar1 & 0xffffffff) * 3;
    FUN_0802fd24((int)lVar2,
                 (((int)uVar3 >> 0x1f) * *(uint *)(param_1 + 0x28) +
                 uVar3 * *(int *)(param_1 + 0x2c) + (int)(uVar1 >> 0x20)) * 3 +
                 (int)((ulonglong)lVar2 >> 0x20));
    VectorSignedToFloat((iVar4 + -1) * (iVar4 + 1),(byte)(in_fpscr >> 0x16) & 3);
  }
  return param_4;
}



/* ===== FUN_0802ad20 @ 0802ad20 ===== */

float FUN_0802ad20(int param_1,float *param_2)

{
  uint uVar1;
  uint in_fpscr;
  float fVar2;
  float fVar3;
  float fVar4;
  
  if (*(int *)(param_1 + 0x20) == *(int *)(param_1 + 0x18)) {
    return DAT_0802ad94;
  }
  uVar1 = *(uint *)(param_1 + 4);
  if (uVar1 < 0x33) {
    fVar2 = param_2[uVar1 * 2 + 3];
    fVar3 = param_2[uVar1 * 2 + 4];
  }
  else {
    fVar4 = (float)VectorUnsignedToFloat(uVar1,(byte)(in_fpscr >> 0x16) & 3);
    fVar2 = (float)FUN_0802a9a0(fVar4);
    fVar3 = fVar4 + *param_2 * fVar2 + param_2[2];
    fVar2 = (fVar4 - *param_2 * fVar2) + param_2[1];
  }
  return (fVar3 - fVar2) / (fVar3 + fVar2);
}



/* ===== FUN_0802ad98 @ 0802ad98 ===== */

float FUN_0802ad98(int param_1,int param_2)

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
  fVar3 = (float)FUN_0802ab50(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
  if (0 < iVar7) {
    if (1 < iVar7) {
      uVar4 = (param_2 * 2 - iVar7) + 1;
      uVar1 = (ulonglong)uVar4 * (ulonglong)*(uint *)(param_1 + 0x30);
      lVar2 = (uVar1 & 0xffffffff) * 3;
      fVar5 = (float)FUN_0802fd24((int)lVar2,
                                  (((int)uVar4 >> 0x1f) * *(uint *)(param_1 + 0x30) +
                                  uVar4 * *(int *)(param_1 + 0x34) + (int)(uVar1 >> 0x20)) * 3 +
                                  (int)((ulonglong)lVar2 >> 0x20));
      fVar6 = (float)VectorSignedToFloat((iVar7 + -1) * (iVar7 + 1),(byte)(in_fpscr >> 0x16) & 3);
      fVar3 = fVar5 / fVar6 + fVar3;
    }
    in_fpscr = in_fpscr & 0xfffffff;
    if (0.0 <= fVar3) goto LAB_0802ae0c;
  }
  fVar3 = DAT_0802ae4c;
LAB_0802ae0c:
  FUN_080207ec(fVar3);
  fVar3 = (float)FUN_0802ab50();
  fVar5 = (float)VectorSignedToFloat(iVar7,(byte)(in_fpscr >> 0x16) & 3);
  fVar3 = (fVar3 * DAT_0802ae50) / fVar5 + DAT_0802ae54;
  if (fVar3 <= 0.0) {
    fVar3 = DAT_0802ae4c;
  }
  return fVar3;
}



/* ===== FUN_0802ae58 @ 0802ae58 ===== */

float FUN_0802ae58(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint in_fpscr;
  float fVar6;
  
  iVar5 = *(int *)(param_1 + 0x18);
  if (*(int *)(param_1 + 0x20) == iVar5) {
    return DAT_0802aed0;
  }
  iVar3 = *(int *)(param_1 + 0x10);
  iVar4 = *(int *)(param_1 + 0x14);
  if (iVar4 != 0 || iVar3 != 0) {
    fVar1 = (float)FUN_0802ab50(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
    fVar6 = (float)VectorSignedToFloat(iVar5,(byte)(in_fpscr >> 0x16) & 3);
    fVar1 = fVar1 - fVar6 * DAT_0802aed4;
    if (0.0 < fVar1) {
      uVar2 = FUN_0802ab50(iVar3,iVar4);
      fVar6 = (float)FUN_0802a9a0(uVar2);
      return (fVar6 * DAT_0802aed8) / fVar1;
    }
  }
  return 1.0;
}



/* ===== FUN_0802aedc @ 0802aedc ===== */

float FUN_0802aedc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  uint in_fpscr;
  float fVar2;
  
  fVar1 = (float)FUN_0802ab50(param_3,param_4);
  fVar2 = (float)VectorSignedToFloat(*(undefined4 *)(param_1 + 0x18),(byte)(in_fpscr >> 0x16) & 3);
  fVar1 = (fVar1 * DAT_0802af18) / fVar2 + DAT_0802af1c;
  if (fVar1 <= 0.0) {
    fVar1 = DAT_0802af20;
  }
  return fVar1;
}



/* ===== FUN_0802af24 @ 0802af24 ===== */

undefined4
FUN_0802af24(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  FUN_0802fd7e(param_1 + 8);
  param_1[0x44] = 0;
  FUN_0802aa70(param_1 + 0x58);
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  param_1[0x90] = 0;
  FUN_0802aa70(param_1 + 0x98);
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  param_1[0xd0] = 0;
  FUN_0802aa70(param_1 + 0xd8);
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  param_1[0x110] = 0;
  return param_4;
}



/* ===== FUN_0802b4d0 @ 0802b4d0 ===== */

void FUN_0802b4d0(uint *param_1)

{
  int *piVar1;
  
  *param_1 = *param_1 & 0xfffffffe;
  piVar1 = DAT_0802b764;
  do {
  } while ((uint)(*DAT_0802b764 - *DAT_0802b764) < 2);
  *param_1 = *param_1 | 1;
  do {
  } while ((uint)(*piVar1 - *piVar1) < 2);
  return;
}



/* ===== FUN_0802b4f8 @ 0802b4f8 ===== */

void FUN_0802b4f8(int param_1)

{
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x4000;
  do {
    if (500 < (uint)(*DAT_0802b764 - *DAT_0802b764)) {
      return;
    }
  } while (-1 < (int)((*(uint *)(param_1 + 0x18) >> 5) << 0x1f));
  return;
}



/* ===== FUN_0802b51e @ 0802b51e ===== */

ulonglong FUN_0802b51e(int param_1,uint param_2,undefined4 param_3,byte *param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  piVar1 = DAT_0802b764;
  do {
  } while ((uint)(*DAT_0802b764 - *DAT_0802b764) < 0x14);
  FUN_0802b4d0(param_1);
  *(uint *)(param_1 + 4) = param_2 | *(uint *)(param_1 + 4) & 0xfffffc00;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffbff;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xff00ffff | (param_5 + 1) * 0x10000;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfeffffff;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x2000000;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x2000;
  *(undefined4 *)(param_1 + 0x28) = param_3;
  piVar2 = DAT_0802b768;
  iVar3 = param_5;
  do {
    if (iVar3 == 0) {
      do {
      } while (-1 < *(int *)(param_1 + 0x18) << 0x1a);
      if (*(int *)(param_1 + 0x18) << 0x1b < 0) {
        uVar4 = 0x80;
      }
      else {
        uVar4 = 0;
      }
      return CONCAT44(param_3,uVar4);
    }
    piVar2[1] = 500;
    iVar5 = *piVar1;
    *piVar2 = iVar5;
    do {
      if (500 < (uint)(*piVar1 - iVar5)) {
        *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x4000;
        goto LAB_0802b5c6;
      }
    } while (-1 < *(int *)(param_1 + 0x18) << 0x1f);
    iVar3 = iVar3 + -1;
    *(uint *)(param_1 + 0x28) = (uint)*param_4;
    param_4 = param_4 + 1;
  } while( true );
  while (-1 < *(int *)(param_1 + 0x18) << 0x1a) {
LAB_0802b5c6:
    if (500 < (uint)(*piVar1 - *piVar1)) break;
  }
  return CONCAT44(param_3,(param_5 + 4) - iVar3) & 0xffffffff000000ff;
}



/* ===== FUN_0802b5e0 @ 0802b5e0 ===== */

ulonglong FUN_0802b5e0(int param_1,uint param_2,uint param_3,undefined1 *param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined1 *local_1c;
  
  piVar1 = DAT_0802b764;
  if (param_5 == 0) {
LAB_0802b6c8:
    return (ulonglong)param_3 << 0x20;
  }
  do {
  } while ((uint)(*DAT_0802b764 - *DAT_0802b764) < 0x14);
  FUN_0802b4d0(param_1);
  *(uint *)(param_1 + 4) = param_2 | *(uint *)(param_1 + 4) & 0xfffffc00;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffbff;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xff00ffff | 0x10000;
  piVar2 = DAT_0802b768;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfeffffff;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfdffffff;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x2000;
  *(uint *)(param_1 + 0x28) = param_3;
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
      local_1c = param_4;
      do {
        piVar2[1] = 500;
        iVar4 = *piVar1;
        *piVar2 = iVar4;
        do {
          if (500 < (uint)(*piVar1 - iVar4)) {
            return CONCAT44(param_3,(param_5 + 4) - iVar3) & 0xffffffff000000ff;
          }
        } while (-1 < *(int *)(param_1 + 0x18) << 0x1d);
        iVar3 = iVar3 + -1;
        *local_1c = (char)*(undefined4 *)(param_1 + 0x24);
        local_1c = local_1c + 1;
      } while (iVar3 != 0);
      do {
      } while (-1 < *(int *)(param_1 + 0x18) << 0x1a);
      goto LAB_0802b6c8;
    }
  } while (-1 < (int)((*(uint *)(param_1 + 0x18) >> 4) << 0x1f));
  FUN_0802b4f8(param_1);
  return CONCAT44(param_3,1);
}



/* ===== FUN_0802b6ce @ 0802b6ce ===== */

ulonglong FUN_0802b6ce(int param_1,uint param_2,undefined1 *param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *local_18;
  
  piVar1 = DAT_0802b764;
  local_18 = param_3;
  if (param_4 != 0) {
    do {
    } while ((uint)(*DAT_0802b764 - *DAT_0802b764) < 0x14);
    FUN_0802b4d0(param_1);
    piVar2 = DAT_0802b768;
    *(uint *)(param_1 + 4) = param_2 | *(uint *)(param_1 + 4) & 0xfffffc00;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x400;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xff00ffff | param_4 << 0x10;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfeffffff;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x2000000;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x2000;
    iVar3 = param_4;
    local_18 = param_3;
    do {
      piVar2[1] = 500;
      iVar4 = *piVar1;
      *piVar2 = iVar4;
      do {
        if (500 < (uint)(*piVar1 - iVar4)) {
          return CONCAT44(local_18,(param_4 + 4) - iVar3) & 0xffffffff000000ff;
        }
      } while (-1 < *(int *)(param_1 + 0x18) << 0x1d);
      puVar5 = local_18 + 1;
      iVar3 = iVar3 + -1;
      *local_18 = (char)*(undefined4 *)(param_1 + 0x24);
      local_18 = puVar5;
    } while (iVar3 != 0);
    do {
    } while (-1 < *(int *)(param_1 + 0x18) << 0x1a);
  }
  return ZEXT48(local_18) << 0x20;
}



/* ===== FUN_0802b76c @ 0802b76c ===== */

undefined8 FUN_0802b76c(void)

{
  char cVar1;
  int *piVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined4 in_r3;
  int iVar8;
  
  iVar5 = FUN_0802b95a();
  puVar3 = DAT_0802b7e4;
  piVar2 = DAT_0802b7e0;
  if (iVar5 == 0) {
    iVar6 = 7;
    puVar7 = DAT_0802b7e8;
    do {
      *piVar2 = (int)puVar7;
      *puVar7 = 0;
      *(undefined1 *)(*piVar2 + 1) = 0;
      *(undefined1 *)(*piVar2 + 2) = 0x7f;
      *(undefined1 *)(*piVar2 + 3) = 0x2f;
      *(undefined1 *)(*piVar2 + 6) = 0;
      *(undefined1 *)(*piVar2 + 7) = 0;
      *(undefined1 *)(*piVar2 + 4) = 0;
      *(undefined1 *)(*piVar2 + 5) = 7;
      cVar1 = puVar3[1];
      *(char *)(*piVar2 + 5) = cVar1 + -1;
      iVar8 = *piVar2;
      *(undefined2 *)(iVar8 + 0x10) = 0;
      *(undefined1 **)(iVar8 + 0xc) = puVar3;
      iVar6 = iVar6 + -1;
      *(undefined4 *)(iVar8 + 8) = *(undefined4 *)(puVar3 + 0xc);
      *(undefined1 *)(iVar8 + 0x12) = *puVar3;
      *(char *)(*piVar2 + 0x13) = cVar1;
      puVar4 = DAT_0802b7e8;
      puVar7 = puVar7 + 0x14;
    } while (iVar6 != 0);
    DAT_0802b7e8[0x8c] = 0;
    *piVar2 = (int)puVar4;
    puVar4[0x8f] = 0;
  }
  return CONCAT44(in_r3,iVar5);
}



/* ===== FUN_0802b7ec @ 0802b7ec ===== */

uint FUN_0802b7ec(void)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  uint in_r3;
  uint uVar8;
  undefined1 *puVar9;
  
  pbVar3 = DAT_0802b8c0;
  pbVar2 = DAT_0802b8bc;
  bVar1 = *DAT_0802b8b4;
  if (bVar1 != 0) {
    return (uint)bVar1;
  }
  uVar7 = (uint)*DAT_0802b8c0;
  *DAT_0802b8b8 = bVar1;
  pbVar5 = DAT_0802b8c8;
  pbVar4 = DAT_0802b8c4;
  bVar1 = *pbVar2;
  if ((bVar1 <= uVar7) && (*DAT_0802b8c8 <= *DAT_0802b8c4)) {
    if (0x2f < uVar7) {
      uVar7 = 0x2f;
    }
    if (0x7f < *DAT_0802b8c4) {
      *DAT_0802b8c4 = 0x7f;
    }
    bVar1 = bVar1 >> 3;
    *pbVar3 = (byte)(uVar7 >> 3);
    *pbVar2 = bVar1;
    iVar6 = DAT_0802b8cc;
    for (uVar7 = (uint)bVar1; uVar7 <= *pbVar3; uVar7 = uVar7 + 1 & 0xff) {
      FUN_0802b8d4(*pbVar5,(uVar7 & 0x1f) << 3);
      uVar8 = (uint)*pbVar4 - (uint)*pbVar5;
      if ((uVar8 & 0xff) != 0xff) {
        uVar8 = uVar8 + 1 & 0xff;
        puVar9 = (undefined1 *)(iVar6 + (uint)*pbVar5 + uVar7 * 0x80);
        do {
          FUN_0802b922(*puVar9);
          uVar8 = uVar8 - 1;
          puVar9 = puVar9 + 1;
        } while (uVar8 != 0);
      }
    }
    *pbVar5 = 1;
    *pbVar2 = 1;
    *pbVar4 = 0;
    *pbVar3 = 0;
  }
  return in_r3;
}



/* ===== FUN_0802b7f6 @ 0802b7f6 ===== */

undefined4 FUN_0802b7f6(undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined1 *puVar9;
  
  pbVar3 = DAT_0802b8c0;
  pbVar2 = DAT_0802b8bc;
  uVar7 = (uint)*DAT_0802b8c0;
  *DAT_0802b8b8 = param_1;
  pbVar5 = DAT_0802b8c8;
  pbVar4 = DAT_0802b8c4;
  bVar1 = *pbVar2;
  if ((bVar1 <= uVar7) && (*DAT_0802b8c8 <= *DAT_0802b8c4)) {
    if (0x2f < uVar7) {
      uVar7 = 0x2f;
    }
    if (0x7f < *DAT_0802b8c4) {
      *DAT_0802b8c4 = 0x7f;
    }
    bVar1 = bVar1 >> 3;
    *pbVar3 = (byte)(uVar7 >> 3);
    *pbVar2 = bVar1;
    iVar6 = DAT_0802b8cc;
    for (uVar7 = (uint)bVar1; uVar7 <= *pbVar3; uVar7 = uVar7 + 1 & 0xff) {
      FUN_0802b8d4(*pbVar5,(uVar7 & 0x1f) << 3);
      uVar8 = (uint)*pbVar4 - (uint)*pbVar5;
      if ((uVar8 & 0xff) != 0xff) {
        uVar8 = uVar8 + 1 & 0xff;
        puVar9 = (undefined1 *)(iVar6 + (uint)*pbVar5 + uVar7 * 0x80);
        do {
          FUN_0802b922(*puVar9);
          uVar8 = uVar8 - 1;
          puVar9 = puVar9 + 1;
        } while (uVar8 != 0);
      }
    }
    *pbVar5 = 1;
    *pbVar2 = 1;
    *pbVar4 = 0;
    *pbVar3 = 0;
  }
  return param_4;
}



/* ===== FUN_0802b88c @ 0802b88c ===== */

undefined4 FUN_0802b88c(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  
  if (*DAT_0802b8b4 == 0) {
    uVar2 = 1;
    bVar1 = (byte)(-(uint)(param_1 == 0) >> 0x1f);
  }
  else {
    uVar2 = 0;
    if (param_1 != 0) {
      *DAT_0802b8b4 = 0;
      FUN_0802b7ec();
      return 0;
    }
    bVar1 = 1;
  }
  *DAT_0802b8b4 = bVar1;
  return uVar2;
}



/* ===== thunk_FUN_0801b630 @ 0802b8d0 ===== */

void thunk_FUN_0801b630(undefined1 param_1)

{
  int *piVar1;
  
  piVar1 = DAT_0801b7e0;
  do {
  } while (*DAT_0801b7e0 << 0x18 < 0);
  *DAT_0801b7cc = 0x20;
  *(undefined1 *)(piVar1 + 1) = param_1;
  return;
}



/* ===== FUN_0802b8d4 @ 0802b8d4 ===== */

undefined4 FUN_0802b8d4(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte *pbVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  pbVar2 = DAT_0802b9e8;
  bVar1 = DAT_0802b9e8[1];
  DAT_0802b9e8[1] = (byte)param_2;
  if ((param_2 & 0xf8) != (bVar1 & 0xf8)) {
    FUN_0801b630(param_2 >> 3 | 0xb0);
  }
  pcVar3 = DAT_0802b9ec;
  if (*pbVar2 == param_1) {
    return param_4;
  }
  *pbVar2 = (byte)param_1;
  if (*pcVar3 == '\0') {
    param_1 = param_1 + 4;
  }
  FUN_0801b630((param_1 & 0xff) >> 4 | 0x10);
  uVar4 = FUN_0801b630(param_1 & 0xf,param_4);
  return uVar4;
}



/* ===== FUN_0802b922 @ 0802b922 ===== */

undefined4 FUN_0802b922(void)

{
  undefined4 unaff_r7;
  
  FUN_0801b63e();
  *DAT_0802b9e8 = *DAT_0802b9e8 + '\x01';
  return unaff_r7;
}



/* ===== FUN_0802b934 @ 0802b934 ===== */

void FUN_0802b934(byte *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  
  uVar2 = 0x80;
  bVar1 = (&DAT_0802b9f4)[param_2 & 7];
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



/* ===== FUN_0802b95a @ 0802b95a ===== */

uint FUN_0802b95a(void)

{
  undefined1 *puVar1;
  
  puVar1 = DAT_0802b9f0;
  *DAT_0802b9f0 = 0;
  puVar1[2] = 0;
  puVar1[1] = 0x7f;
  puVar1[3] = 0x2f;
  puVar1[4] = 0;
  puVar1[5] = 0;
  if (puVar1[5] == '\0') {
    FUN_0801b630(0xe2);
    FUN_0802c778(2);
    FUN_0801b630(0x40);
    FUN_0801b630(0xa2);
    FUN_0801b630(0xa6);
    FUN_0801b630(0x23);
    puVar1[6] = 0x3c;
    FUN_0801b630(0x81);
    FUN_0801b630(0x26);
    FUN_0801b630(0x2f);
    FUN_0801b630(200);
    FUN_0801b630(0xa0);
    return ~-(uint)(puVar1[5] == '\0') >> 0x1f;
  }
  return 1;
}



/* ===== FUN_0802b9d0 @ 0802b9d0 ===== */

undefined4 FUN_0802b9d0(void)

{
  undefined4 unaff_r7;
  
  FUN_0801b630(0xae);
  return unaff_r7;
}



/* ===== FUN_0802b9e2 @ 0802b9e2 ===== */

void FUN_0802b9e2(void)

{
  FUN_0801b630(0xaf);
  return;
}



/* ===== FUN_0802b9fc @ 0802b9fc ===== */

uint FUN_0802b9fc(uint param_1,uint param_2,uint param_3,uint param_4)

{
  undefined1 uVar1;
  char cVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  piVar3 = DAT_0802ba6c;
  if (0x7f < param_1) {
    param_1 = 0x7f;
  }
  if (0x7f < param_3) {
    param_3 = 0x7f;
  }
  if (0x2f < param_2) {
    param_2 = 0x2f;
  }
  uVar7 = param_4;
  if (0x2f < param_4) {
    uVar7 = 0x2f;
  }
  uVar8 = param_3;
  if (param_1 < param_3) {
    uVar8 = param_1;
  }
  uVar9 = uVar7;
  if (param_2 < uVar7) {
    uVar9 = param_2;
  }
  uVar1 = (undefined1)uVar8;
  *(undefined1 *)*DAT_0802ba6c = uVar1;
  cVar2 = (char)uVar9;
  *(char *)(*piVar3 + 1) = cVar2;
  *(char *)(*piVar3 + 2) = (char)param_3;
  *(char *)(*piVar3 + 3) = (char)uVar7;
  *(undefined1 *)(*piVar3 + 4) = uVar1;
  if (*(int *)(*piVar3 + 0xc) == 0) {
    cVar4 = '\a';
  }
  else {
    cVar4 = FUN_0801ffae();
    cVar4 = cVar4 + -1;
  }
  *(char *)(*piVar3 + 5) = cVar4 + cVar2;
  iVar5 = *piVar3;
  bVar6 = *(byte *)(iVar5 + 3);
  if (*(byte *)(iVar5 + 5) < *(byte *)(iVar5 + 3)) {
    bVar6 = *(byte *)(iVar5 + 5);
  }
  *(byte *)(iVar5 + 5) = bVar6;
  *(undefined1 *)(*piVar3 + 6) = uVar1;
  *(char *)(*piVar3 + 7) = cVar2;
  return param_4;
}



/* ===== FUN_0802ba70 @ 0802ba70 ===== */

void FUN_0802ba70(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_30;
  undefined4 uStack_2c;
  uint local_28;
  uint local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  local_30 = *(undefined4 *)(param_2 + 0x40);
  uStack_2c = *(undefined4 *)(param_2 + 0x44);
  local_28 = *(uint *)(param_2 + 0x48);
  local_24 = *(uint *)(param_2 + 0x4c);
  uStack_20 = *(undefined4 *)(param_2 + 0x50);
  uStack_1c = *(undefined4 *)(param_2 + 0x54);
  if (local_28 == 0) {
    local_28 = 1;
  }
  else if (DAT_0802bab4 < local_28) {
    local_28 = DAT_0802bab4;
  }
  if (local_24 == 0) {
    local_24 = 1;
  }
  else if (DAT_0802bab4 < local_24) {
    local_24 = DAT_0802bab4;
  }
  uStack_18 = param_4;
  FUN_0801cc24(DAT_0802bab8,&local_30,0xc);
  return;
}



/* ===== FUN_0802babc @ 0802babc ===== */

void FUN_0802babc(byte *param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  
  puVar1 = DAT_0802bb18;
  if (param_2 == *param_1) goto LAB_0802bb0e;
  *param_1 = (byte)param_2;
  *puVar1 = *puVar1 & 0xffffff9f;
  *puVar1 = *puVar1 & 0xffffff7f;
  if (param_2 == 2) {
    puVar1[3] = 0x8005;
    iVar2 = 1;
LAB_0802baf2:
    *puVar1 = *puVar1 & 0xffffffe7 | iVar2 << 3;
  }
  else {
    if (param_2 == 3) {
      puVar1[3] = 7;
      iVar2 = 2;
      goto LAB_0802baf2;
    }
    puVar1[3] = DAT_0802bb1c;
    *puVar1 = *puVar1 & 0xffffffe7;
  }
  puVar1[2] = 0xffffffff;
LAB_0802bb0e:
  *puVar1 = *puVar1 | 1;
  return;
}



/* ===== FUN_0802bb20 @ 0802bb20 ===== */

uint * FUN_0802bb20(int param_1,uint param_2,uint param_3)

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



/* ===== FUN_0802bb88 @ 0802bb88 ===== */

void FUN_0802bb88(int param_1,int param_2,uint param_3,uint param_4,uint param_5)

{
  *(uint *)(param_1 + 4) =
       param_3 & 0xff |
       (param_4 & 0xff) << 8 |
       (param_5 & 0xff) << 0x10 | *(uint *)(param_1 + 4) & DAT_0802be28 | param_2 << 0xd;
  return;
}



/* ===== FUN_0802bbb4 @ 0802bbb4 ===== */

bool FUN_0802bbb4(int param_1,uint *param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x24) = 0xca;
  *(undefined4 *)(param_1 + 0x24) = 0x53;
  iVar1 = FUN_0802bd88();
  if (iVar1 != 1) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffffffbf | *param_2;
    *(uint *)(param_1 + 0x10) = param_2[2] | *(uint *)(param_1 + 0x10) & 0xffff8000;
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xff80ffff | param_2[1] << 0x10;
    *(undefined4 *)(param_1 + 0xc) = 0xffffff7f;
  }
  *(undefined4 *)(param_1 + 0x24) = 0xff;
  return iVar1 == 1;
}



/* ===== FUN_0802bc02 @ 0802bc02 ===== */

undefined4 FUN_0802bc02(uint *param_1,int param_2,uint *param_3)

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
  iVar1 = FUN_0802bd88(param_1);
  if (iVar1 != 1) {
    uVar3 = (uint)*(byte *)((int)param_3 + 6);
    uVar4 = (uint)*(byte *)((int)param_3 + 5);
    uVar2 = (uint)(byte)param_3[1];
    if (param_2 == 0) {
      uVar8 = (uint)((ulonglong)uVar2 * (ulonglong)DAT_0802be30 >> 0x23);
      uVar7 = (uint)((ulonglong)uVar4 * (ulonglong)DAT_0802be30 >> 0x23);
      uVar5 = (uint)((ulonglong)uVar3 * (ulonglong)DAT_0802be30 >> 0x23);
      *param_1 = *param_3 | DAT_0802be2c & *param_1 |
                 ((uVar2 + uVar8 * -10 | uVar8 << 4) & 0xff) << 0x10 |
                 ((uVar4 + uVar7 * -10 | uVar7 << 4) & 0xff) << 8 |
                 (uVar3 + uVar5 * -10 | uVar5 << 4) & 0xff;
    }
    else {
      *param_1 = uVar3 | *param_3 | DAT_0802be2c & *param_1 | uVar2 << 0x10 | uVar4 << 8;
    }
    param_1[3] = 0xffffff7f;
    if ((int)(param_1[2] << 0x1a) < 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_0802bdd6(param_1);
    }
  }
  param_1[9] = 0xff;
  return uVar6;
}



/* ===== FUN_0802bcdc @ 0802bcdc ===== */

undefined8 FUN_0802bcdc(int param_1,int param_2,undefined1 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  
  uVar6 = 1;
  if ((param_2 == 0) && ((int)((uint)(byte)param_3[1] << 0x1b) < 0)) {
    param_3[1] = (param_3[1] & 0xef) + 10;
  }
  *(undefined4 *)(param_1 + 0x24) = 0xca;
  *(undefined4 *)(param_1 + 0x24) = 0x53;
  puVar2 = param_3;
  iVar1 = FUN_0802bd88();
  if (iVar1 != 1) {
    uVar3 = (uint)(byte)param_3[2];
    uVar4 = (uint)(byte)param_3[1];
    puVar2 = (undefined1 *)(uint)(byte)param_3[3];
    if (param_2 == 0) {
      uVar7 = (uint)(ZEXT48(puVar2) * (ulonglong)DAT_0802be30 >> 0x23);
      puVar2 = (undefined1 *)(((uint)(puVar2 + uVar7 * -10) | uVar7 << 4) & 0xff);
      uVar7 = (uint)((ulonglong)uVar3 * (ulonglong)DAT_0802be30 >> 0x23);
      uVar5 = (uint)((ulonglong)uVar4 * (ulonglong)DAT_0802be30 >> 0x23);
      uVar4 = (uVar4 + uVar5 * -10 | uVar5 << 4) & 0xff;
      uVar3 = (uVar3 + uVar7 * -10 | uVar7 << 4) & 0xff;
    }
    FUN_0802bb88(param_1,*param_3,uVar3,uVar4,puVar2,param_4);
    *(undefined4 *)(param_1 + 0xc) = 0xffffff7f;
    if (*(int *)(param_1 + 8) << 0x1a < 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_0802bdd6(param_1);
    }
  }
  *(undefined4 *)(param_1 + 0x24) = 0xff;
  return CONCAT44(puVar2,uVar6);
}



/* ===== FUN_0802bd88 @ 0802bd88 ===== */

undefined4 FUN_0802bd88(int param_1)

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
      if (*DAT_0802be34 << 0xf < 0) {
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



/* ===== FUN_0802bdd6 @ 0802bdd6 ===== */

undefined4 FUN_0802bdd6(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int local_4;
  
  piVar1 = DAT_0802be34;
  local_4 = 1000;
  uVar2 = 0;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0x80 | 0xffffff5f;
  uVar3 = *(uint *)(param_1 + 0xc) >> 5 & 1;
  while ((local_4 != 0 && (uVar3 == 0))) {
    if (*piVar1 << 0xf < 0) {
      local_4 = local_4 + -1;
    }
    uVar3 = *(uint *)(param_1 + 0xc) >> 5 & 1;
    if (local_4 == 0) {
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* ===== FUN_0802be38 @ 0802be38 ===== */

longlong FUN_0802be38(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar2 = param_1[4] / 0xc;
  iVar3 = param_1[4] % 0xc;
  if (iVar3 < 0) {
    iVar3 = iVar3 + 0xc;
    iVar2 = iVar2 + -1;
  }
  if (iVar2 < 0) {
    iVar4 = -0x80000000 - iVar2;
    if (param_1[5] < -0x80000000 - iVar2) {
      return -1;
    }
  }
  else {
    iVar4 = param_4;
    if ((0 < iVar2) && (iVar4 = param_1[5], 0x7fffffff - iVar2 < iVar4)) {
      return -1;
    }
  }
  iVar2 = iVar2 + param_1[5];
  iVar3 = FUN_0802fe8c(iVar2,iVar3,param_1[5],iVar4,param_3,param_4);
  iVar5 = *param_1 / DAT_0802bf10;
  iVar4 = (param_1[1] % 0x5a0) * 0x3c;
  lVar1 = (longlong)DAT_0802bf10 *
          (longlong)
          (DAT_0802bf14 +
          iVar5 + param_1[3] + iVar2 * 0x16d + iVar3 + param_1[2] / 0x18 + param_1[1] / 0x5a0) +
          (longlong)((*param_1 + (param_1[2] % 0x18) * 0xe10 + iVar4) - DAT_0802bf10 * iVar5);
  uVar6 = (uint)lVar1;
  iVar3 = (int)((ulonglong)lVar1 >> 0x20);
  FUN_0802ff24(param_1,iVar4,uVar6,iVar3,param_1[8]);
  if (0 < param_1[8]) {
    lVar1 = CONCAT44(iVar3 - (uint)(uVar6 < 0xe10),uVar6 - 0xe10);
  }
  return lVar1;
}



/* ===== FUN_0802bf18 @ 0802bf18 ===== */

void FUN_0802bf18(undefined4 *param_1,undefined4 param_2)

{
  FUN_0802ff24(0,param_2,*param_1,param_1[1],0xffffffff);
  return;
}



/* ===== FUN_0802bf38 @ 0802bf38 ===== */

uint FUN_0802bf38(uint *param_1)

{
  byte bVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar2 = DAT_0802c08c;
  uVar4 = *param_1;
  uVar3 = 0;
  if ((char)param_1[2] == '\0') {
    *DAT_0802c08c = *DAT_0802c08c & ~uVar4;
    puVar2[1] = puVar2[1] & ~*param_1;
    puVar2[8] = puVar2[8] & ~param_1[1];
    puVar2[9] = puVar2[9] & ~param_1[1];
    return 0;
  }
  if (uVar4 != 0) {
    bVar1 = *(byte *)((int)param_1 + 9);
    if (bVar1 == 0) {
      DAT_0802c08c[1] = DAT_0802c08c[1] & ~uVar4;
      *puVar2 = *puVar2 | *param_1;
    }
    else {
      if (bVar1 == 2) {
        uVar4 = uVar4 | *DAT_0802c08c;
      }
      else {
        if (1 < bVar1) {
          uVar3 = 1;
          goto LAB_0802bf88;
        }
        uVar4 = *DAT_0802c08c & ~uVar4;
      }
      *DAT_0802c08c = uVar4;
      puVar2[1] = puVar2[1] | *param_1;
    }
LAB_0802bf88:
    puVar2 = DAT_0802c08c;
    bVar1 = *(byte *)((int)param_1 + 10);
    if (bVar1 != 0) {
      if (bVar1 == 1) {
        DAT_0802c08c[3] = DAT_0802c08c[3] & ~*param_1;
        puVar2[2] = puVar2[2] | *param_1;
      }
      else if (bVar1 == 0) {
LAB_0802bfcc:
        uVar3 = uVar3 | 2;
      }
      else {
        if (bVar1 == 3) {
          uVar4 = DAT_0802c08c[2] | *param_1;
        }
        else {
          if (2 < bVar1) goto LAB_0802bfcc;
          uVar4 = DAT_0802c08c[2] & ~*param_1;
        }
        DAT_0802c08c[2] = uVar4;
        puVar2[3] = puVar2[3] | *param_1;
      }
    }
  }
  puVar2 = DAT_0802c08c;
  uVar4 = param_1[1];
  if (uVar4 == 0) {
    return uVar3;
  }
  bVar1 = *(byte *)((int)param_1 + 9);
  if (bVar1 == 0) {
    DAT_0802c08c[9] = DAT_0802c08c[9] & ~uVar4;
    puVar2[8] = puVar2[8] | param_1[1];
  }
  else {
    if (bVar1 == 2) {
      uVar4 = uVar4 | DAT_0802c08c[8];
    }
    else {
      if (1 < bVar1) {
        uVar3 = uVar3 | 4;
        goto LAB_0802c016;
      }
      uVar4 = DAT_0802c08c[8] & ~uVar4;
    }
    DAT_0802c08c[8] = uVar4;
    puVar2[9] = puVar2[9] | param_1[1];
  }
LAB_0802c016:
  puVar2 = DAT_0802c08c;
  bVar1 = *(byte *)((int)param_1 + 10);
  if (bVar1 == 0) {
    return uVar3;
  }
  if (bVar1 == 1) {
    DAT_0802c08c[0xb] = DAT_0802c08c[0xb] & ~param_1[1];
    puVar2[10] = puVar2[10] | param_1[1];
    return uVar3;
  }
  if (bVar1 == 0) {
LAB_0802c05c:
    uVar3 = 1;
  }
  else {
    if (bVar1 == 3) {
      uVar4 = DAT_0802c08c[10] | param_1[1];
    }
    else {
      if (2 < bVar1) goto LAB_0802c05c;
      uVar4 = DAT_0802c08c[10] & ~param_1[1];
    }
    DAT_0802c08c[10] = uVar4;
    puVar2[0xb] = puVar2[0xb] | param_1[1];
  }
  return uVar3;
}



/* ===== FUN_0802c090 @ 0802c090 ===== */

undefined4 FUN_0802c090(int param_1,uint *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((int)((*DAT_0802c150 | *DAT_0802c154 | *DAT_0802c158) << 0x1f) < 0) {
    uVar1 = 1;
  }
  else if (param_2[1] == 0) {
    *(uint *)(param_1 + 8) = *param_2 | DAT_0802c15c & *(uint *)(param_1 + 8);
  }
  else {
    *(uint *)(param_1 + 8) =
         param_2[1] | *param_2 | DAT_0802c15c & *(uint *)(param_1 + 8) | param_2[2] | param_2[3];
  }
  return uVar1;
}



/* ===== FUN_0802c0d6 @ 0802c0d6 ===== */

undefined4 FUN_0802c0d6(int param_1,uint *param_2)

{
  if (*(int *)(param_1 + 8) << 0x1f < 0) {
    return 1;
  }
  *(uint *)(param_1 + 0xc) =
       *(uint *)(param_1 + 0xc) & DAT_0802c160 | *param_2 | param_2[1] | param_2[2];
  return 0;
}



/* ===== FUN_0802c100 @ 0802c100 ===== */

undefined4 FUN_0802c100(int param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 8) << 0x1f < 0) {
    uVar1 = 1;
  }
  else {
    if (param_2[1] == 0) {
      uVar2 = *param_2 | DAT_0802c164 & *(uint *)(param_1 + 0xc);
    }
    else {
      uVar2 = *param_2 | DAT_0802c164 & *(uint *)(param_1 + 0xc) | param_2[2];
    }
    *(uint *)(param_1 + 0xc) = param_2[5] | param_2[4] | param_2[3] | uVar2;
    *(uint *)(param_1 + 0x30) = param_2[1] | *(uint *)(param_1 + 0x30) & 0xfffffff0;
  }
  return uVar1;
}



/* ===== FUN_0802c168 @ 0802c168 ===== */

undefined4 FUN_0802c168(int param_1,uint *param_2)

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
    *(uint *)(param_1 + 0x4c) = param_2[1] | *(uint *)(param_1 + 0x4c) & 0xffffff00 | *param_2;
  }
  return uVar1;
}



/* ===== FUN_0802c1ac @ 0802c1ac ===== */

bool FUN_0802c1ac(uint *param_1,uint param_2,uint *param_3)

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



/* ===== FUN_0802c210 @ 0802c210 ===== */

undefined4 FUN_0802c210(uint *param_1,uint *param_2)

{
  *param_1 = *param_1 & 0xfffffffe;
  *param_1 = *param_1 & 0xffffe0ff | param_2[2] | param_2[3] << 8;
  param_1[4] = param_2[1];
  *param_1 = *param_1 | 1;
  param_1[2] = param_1[2] & 0xffff7fff;
  param_1[2] = param_2[6] | param_1[2] & 0xfffff800 | param_2[4];
  if (param_2[4] != 0) {
    param_1[2] = param_1[2] | 0x8000;
  }
  *param_1 = *param_1 & 0xffcfffff | *param_2;
  param_1[1] = param_1[1] & 0xffff7fff | param_2[5];
  return 0;
}



/* ===== FUN_0802c27c @ 0802c27c ===== */

undefined4 FUN_0802c27c(uint *param_1,byte *param_2)

{
  uint uVar1;
  
  if (*(uint *)(param_2 + 4) == 0xc) {
    uVar1 = *(uint *)(param_2 + 8) | *param_2 & 2 | DAT_0802c2b4 & *param_1 | 0x20c;
  }
  else {
    uVar1 = *(uint *)(param_2 + 8) | *param_2 & 2 | DAT_0802c2b4 & *param_1 | *(uint *)(param_2 + 4)
            | *(uint *)(param_2 + 0xc);
  }
  *param_1 = uVar1;
  return 0;
}



/* ===== FUN_0802c2b8 @ 0802c2b8 ===== */

undefined4 FUN_0802c2b8(uint *param_1,uint *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (-1 < (int)(*param_1 << 0x19)) {
    *param_1 = *param_1 & DAT_0802c324 | *param_2 | param_2[1] | param_2[3] | param_2[4] |
               param_2[5] | param_2[6] | param_2[7] | param_2[8];
    param_1[1] = param_1[1] & DAT_0802c328 | param_2[2] | param_2[5] >> 0x10;
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



/* ===== FUN_0802c32c @ 0802c32c ===== */

undefined4 FUN_0802c32c(uint *param_1,ushort *param_2)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint *unaff_r5;
  bool bVar4;
  
  puVar1 = DAT_0802c72c;
  uVar2 = *param_1;
  if (param_1 == DAT_0802c72c || param_1 == &DAT_40000000) {
LAB_0802c35e:
    uVar2 = *(uint *)(param_2 + 2) | uVar2 & 0xffffff8f;
    if (param_1 != DAT_0802c72c && param_1 != &DAT_40000000) {
      bVar4 = param_1 != DAT_0802c730;
      if (bVar4) {
        unaff_r5 = DAT_0802c734;
      }
      puVar3 = DAT_0802c730;
      if (bVar4 && param_1 != unaff_r5) {
        puVar3 = DAT_0802c738;
      }
      if ((bVar4 && param_1 != unaff_r5) && param_1 != puVar3) goto LAB_0802c386;
    }
LAB_0802c3a6:
    uVar2 = *(uint *)(param_2 + 6) | uVar2 & 0xfffffcff;
  }
  else {
    if (param_1 != DAT_0802c730) {
      unaff_r5 = DAT_0802c734;
    }
    if (param_1 == DAT_0802c730 || param_1 == unaff_r5) goto LAB_0802c35e;
    if (param_1 != DAT_0802c738) {
      unaff_r5 = DAT_0802c73c;
    }
    puVar3 = DAT_0802c738;
    if (param_1 == DAT_0802c738 || param_1 == unaff_r5) goto LAB_0802c35e;
LAB_0802c386:
    if (param_1 != DAT_0802c73c) {
      puVar3 = DAT_0802c740;
    }
    if (param_1 == DAT_0802c73c || param_1 == puVar3) goto LAB_0802c3a6;
    if (param_1 != DAT_0802c744) {
      puVar3 = DAT_0802c748;
    }
    if (param_1 == DAT_0802c744 || param_1 == puVar3) goto LAB_0802c3a6;
  }
  *param_1 = uVar2;
  param_1[0xb] = *(uint *)(param_2 + 4);
  param_1[10] = (uint)*param_2;
  puVar3 = puVar1;
  if (param_1 != puVar1) {
    puVar3 = DAT_0802c73c;
  }
  if (param_1 != puVar1 && param_1 != puVar3) {
    bVar4 = param_1 != DAT_0802c740;
    if (bVar4) {
      puVar3 = DAT_0802c744;
    }
    puVar1 = DAT_0802c740;
    if (bVar4 && param_1 != puVar3) {
      puVar1 = DAT_0802c748;
    }
    if ((bVar4 && param_1 != puVar3) && param_1 != puVar1) goto LAB_0802c3de;
  }
  param_1[0xc] = *(uint *)(param_2 + 8);
LAB_0802c3de:
  param_1[5] = param_1[5] | 1;
  return 0;
}



/* ===== FUN_0802c3e8 @ 0802c3e8 ===== */

undefined4 FUN_0802c3e8(uint param_1,int param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  uVar2 = DAT_0802c750;
  uVar5 = DAT_0802c72c;
  if (param_2 == 1) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffe;
    uVar2 = *(uint *)(param_1 + 4);
    uVar6 = *param_3;
    uVar3 = *(uint *)(param_1 + 0x18) & DAT_0802c74c;
    uVar5 = (*(uint *)(param_1 + 0x20) & 0xfffffffd | param_3[4]) >> 1;
    uVar4 = param_3[1] | uVar5 << 1;
    if (param_1 != DAT_0802c72c) {
      uVar5 = DAT_0802c73c;
    }
    if (param_1 != DAT_0802c72c && param_1 != uVar5) {
      bVar8 = param_1 != DAT_0802c740;
      if (bVar8) {
        uVar5 = DAT_0802c744;
      }
      uVar7 = DAT_0802c740;
      if (bVar8 && param_1 != uVar5) {
        uVar7 = DAT_0802c748;
      }
      if ((bVar8 && param_1 != uVar5) && param_1 != uVar7) goto LAB_0802c48e;
    }
    uVar4 = (uVar4 & 0xfffffff7 | param_3[5] << 2) & 0xfffffffb | param_3[2] << 2;
    uVar2 = (uVar2 & 0xfffffeff | param_3[6]) & 0xfffffdff | param_3[7] << 1;
LAB_0802c48e:
    *(uint *)(param_1 + 4) = uVar2;
    *(uint *)(param_1 + 0x18) = uVar6 | uVar3;
    *(uint *)(param_1 + 0x34) = param_3[3];
    *(uint *)(param_1 + 0x20) = uVar4;
    return 0;
  }
  if (param_2 == 0x10) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffffef;
    uVar6 = *(uint *)(param_1 + 4);
    uVar4 = *param_3;
    uVar3 = (*(uint *)(param_1 + 0x20) & 0xffffffdf | param_3[4] << 4) & 0xffffffef |
            param_3[1] << 4;
    uVar5 = param_3[1];
    if (param_1 != DAT_0802c72c) {
      uVar5 = DAT_0802c73c;
    }
    if (param_1 != DAT_0802c72c && param_1 != uVar5) {
      bVar8 = param_1 != DAT_0802c740;
      if (bVar8) {
        uVar5 = DAT_0802c744;
      }
      uVar7 = DAT_0802c740;
      if (bVar8 && param_1 != uVar5) {
        uVar7 = DAT_0802c748;
      }
      if ((bVar8 && param_1 != uVar5) && param_1 != uVar7) goto LAB_0802c516;
    }
    uVar3 = (uVar3 & 0xffffff7f | param_3[5] << 6) & 0xffffffbf | param_3[2] << 6;
    uVar6 = (uVar6 & 0xfffffbff | param_3[6] << 2) & 0xfffff7ff | param_3[7] << 3;
LAB_0802c516:
    *(uint *)(param_1 + 4) = uVar6;
    *(uint *)(param_1 + 0x18) = uVar2 & *(uint *)(param_1 + 0x18) | uVar4 << 8;
    *(uint *)(param_1 + 0x38) = param_3[3];
    *(uint *)(param_1 + 0x20) = uVar3;
    return 0;
  }
  if (param_2 == 0x100) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffeff;
    uVar3 = *(uint *)(param_1 + 4);
    uVar7 = *(uint *)(param_1 + 0x1c) & DAT_0802c74c;
    uVar6 = *param_3;
    uVar4 = (*(uint *)(param_1 + 0x20) & 0xfffffdff | param_3[4] << 8) & 0xfffffeff |
            param_3[1] << 8;
    uVar2 = param_3[1];
    if (param_1 != uVar5) {
      uVar2 = DAT_0802c73c;
    }
    if (param_1 != uVar5 && param_1 != uVar2) {
      bVar8 = param_1 != DAT_0802c740;
      if (bVar8) {
        uVar2 = DAT_0802c744;
      }
      uVar5 = DAT_0802c740;
      if (bVar8 && param_1 != uVar2) {
        uVar5 = DAT_0802c748;
      }
      if ((bVar8 && param_1 != uVar2) && param_1 != uVar5) goto LAB_0802c59c;
    }
    uVar4 = (uVar4 & 0xfffff7ff | param_3[5] << 10) & 0xfffffbff | param_3[2] << 10;
    uVar3 = (uVar3 & 0xffffefff | param_3[6] << 4) & 0xffffdfff | param_3[7] << 5;
LAB_0802c59c:
    *(uint *)(param_1 + 4) = uVar3;
    *(uint *)(param_1 + 0x1c) = uVar6 | uVar7;
    *(uint *)(param_1 + 0x3c) = param_3[3];
    *(uint *)(param_1 + 0x20) = uVar4;
    return 0;
  }
  if (param_2 == 0x1000) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffefff;
    uVar6 = *(uint *)(param_1 + 4);
    uVar7 = *param_3;
    uVar3 = param_3[4];
    uVar4 = param_3[1];
    uVar5 = uVar4;
    if (param_1 != DAT_0802c72c) {
      uVar5 = DAT_0802c73c;
    }
    if (param_1 != DAT_0802c72c && param_1 != uVar5) {
      bVar8 = param_1 != DAT_0802c740;
      if (bVar8) {
        uVar5 = DAT_0802c744;
      }
      uVar1 = DAT_0802c740;
      if (bVar8 && param_1 != uVar5) {
        uVar1 = DAT_0802c748;
      }
      if ((bVar8 && param_1 != uVar5) && param_1 != uVar1) goto LAB_0802c5fc;
    }
    uVar6 = uVar6 & 0xffffbfff | param_3[6] << 6;
LAB_0802c5fc:
    *(uint *)(param_1 + 4) = uVar6;
    *(uint *)(param_1 + 0x1c) = uVar2 & *(uint *)(param_1 + 0x1c) | uVar7 << 8;
    *(uint *)(param_1 + 0x40) = param_3[3];
    *(uint *)(param_1 + 0x20) =
         (*(uint *)(param_1 + 0x20) & 0xffffdfff | uVar3 << 0xc) & 0xffffefff | uVar4 << 0xc;
    return 0;
  }
  if (param_2 == 0x10000) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffeffff;
    uVar4 = *(uint *)(param_1 + 0x54) & DAT_0802c754;
    uVar6 = *param_3;
    uVar3 = (*(uint *)(param_1 + 0x20) & 0xfffdffff | param_3[4] << 0x10) & 0xfffeffff |
            param_3[1] << 0x10;
    uVar2 = param_3[1];
    if (param_1 != uVar5) {
      uVar2 = DAT_0802c73c;
    }
    if (param_1 == uVar5 || param_1 == uVar2) {
LAB_0802c64c:
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffeffff | param_3[6] << 8;
    }
    else {
      bVar8 = param_1 != DAT_0802c740;
      if (bVar8) {
        uVar2 = DAT_0802c744;
      }
      uVar5 = DAT_0802c740;
      if (bVar8 && param_1 != uVar2) {
        uVar5 = DAT_0802c748;
      }
      if ((!bVar8 || param_1 == uVar2) || param_1 == uVar5) goto LAB_0802c64c;
    }
    *(uint *)(param_1 + 0x54) = uVar6 | uVar4;
    *(uint *)(param_1 + 0x58) = param_3[3];
    goto LAB_0802c6be;
  }
  if (param_2 != 0x100000) {
    return 1;
  }
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffefffff;
  uVar6 = *param_3;
  uVar2 = DAT_0802c758 & *(uint *)(param_1 + 0x54);
  uVar3 = (*(uint *)(param_1 + 0x20) & 0xffdfffff | param_3[4] << 0x14) & 0xffefffff |
          param_3[1] << 0x14;
  uVar5 = param_3[1];
  if (param_1 != DAT_0802c72c) {
    uVar5 = DAT_0802c73c;
  }
  if (param_1 == DAT_0802c72c || param_1 == uVar5) {
LAB_0802c6aa:
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffbffff | param_3[6] << 10;
  }
  else {
    bVar8 = param_1 != DAT_0802c740;
    if (bVar8) {
      uVar5 = DAT_0802c744;
    }
    uVar4 = DAT_0802c740;
    if (bVar8 && param_1 != uVar5) {
      uVar4 = DAT_0802c748;
    }
    if ((!bVar8 || param_1 == uVar5) || param_1 == uVar4) goto LAB_0802c6aa;
  }
  *(uint *)(param_1 + 0x54) = uVar2 | uVar6 << 8;
  *(uint *)(param_1 + 0x5c) = param_3[3];
LAB_0802c6be:
  *(uint *)(param_1 + 0x20) = uVar3;
  return 0;
}



/* ===== FUN_0802c6c8 @ 0802c6c8 ===== */

undefined4 FUN_0802c6c8(uint param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_2[5] |
          ((((((uint)(byte)param_2[3] | param_2[2] & 0xfffffbff | param_2[1]) & 0xfffff7ff |
             *param_2) & 0xffffefff | (uint)*(ushort *)((int)param_2 + 0xe)) & 0xffffdfff |
           param_2[4]) & 0xffffbfff | param_2[9]) & 0xfff0ffff;
  uVar1 = param_2[9];
  if (param_1 != DAT_0802c72c) {
    uVar1 = DAT_0802c73c;
  }
  if (param_1 == DAT_0802c72c || param_1 == uVar1) {
    uVar2 = param_2[7] | ((uVar2 & 0xff0fffff | param_2[8]) & 0xfeffffff | param_2[6]) & 0xfdffffff;
  }
  *(uint *)(param_1 + 0x44) = uVar2;
  return 0;
}



/* ===== FUN_0802c75c @ 0802c75c ===== */

void FUN_0802c75c(uint param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0802c7a4;
  DAT_0802c7a4[1] = (uint)((ulonglong)param_1 * (ulonglong)DAT_0802c7a0 >> 0x29) - 1;
  puVar1[2] = 0;
  *puVar1 = 5;
  return;
}



/* ===== FUN_0802c778 @ 0802c778 ===== */

void FUN_0802c778(int param_1)

{
  if (param_1 == -1) goto LAB_0802c78c;
  for (param_1 = param_1 + 1; param_1 != 0; param_1 = param_1 + -1) {
LAB_0802c78c:
    do {
    } while (-1 < *DAT_0802c7a4 << 0xf);
  }
  return;
}



/* ===== FUN_0802c79a @ 0802c79a ===== */

void FUN_0802c79a(undefined4 param_1)

{
  *DAT_0802c7a8 = param_1;
  return;
}



/* ===== FUN_0802c7ac @ 0802c7ac ===== */

undefined4 * FUN_0802c7ac(undefined4 *param_1)

{
  FUN_08026250();
  *param_1 = DAT_0802c7bc;
  return param_1;
}



/* ===== FUN_0802c7cc @ 0802c7cc ===== */

int * FUN_0802c7cc(int *param_1)

{
  *param_1 = (int)(param_1 + 0x3e);
  param_1[1] = 0;
  param_1[2] = 0x6b;
  param_1[2] = 0;
  param_1[8] = -1;
  param_1[7] = 0;
  FUN_08024bbc(param_1 + 9,0xd4);
  *(undefined1 *)(param_1 + 6) = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = (uint)*(ushort *)(DAT_0802c814 + ((*(uint *)(DAT_0802c810 + 0x68) & 0x3ff) >> 7) * 2)
  ;
  return param_1;
}



/* ===== FUN_0802c818 @ 0802c818 ===== */

void FUN_0802c818(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

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
  FUN_08030080((int)&DAT_0802c850 + DAT_0802c850,&local_18,param_3,&local_1c,0);
  if (local_18 != (undefined4 *)0x0) {
    *local_18 = 0;
  }
  return;
}



/* ===== FUN_0802c854 @ 0802c854 ===== */

uint FUN_0802c854(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint local_10;
  
  if ((int)(param_3 << 0x1f) < 0) {
    uVar3 = (param_3 & 0xff) >> 1;
    if (3 < uVar3) {
      uVar3 = 3;
    }
    local_10 = param_4;
    uVar1 = FUN_08030294(param_3 >> 8 | param_4 << 0x18,param_4 >> 8,uVar3 << 3);
    local_10 = CONCAT31(local_10._1_3_,uVar1);
  }
  else {
    local_10._1_3_ = (undefined3)(param_4 >> 8);
    local_10 = CONCAT31(local_10._1_3_,0x20);
  }
  local_10._0_2_ = (ushort)(byte)local_10;
  uVar2 = FUN_0801ff48(DAT_0802c8a8);
  FUN_08018b1c(*(undefined1 *)(param_1 + 8),*(undefined1 *)(param_1 + 9));
  FUN_080190ec(&local_10);
  FUN_0801ff48(uVar2);
  return local_10;
}



/* ===== FUN_0802c8ac @ 0802c8ac ===== */

/* WARNING: Removing unreachable block (ram,0x08027220) */
/* WARNING: Removing unreachable block (ram,0x08027238) */
/* WARNING: Removing unreachable block (ram,0x08027242) */
/* WARNING: Removing unreachable block (ram,0x0802725e) */
/* WARNING: Removing unreachable block (ram,0x08027266) */
/* WARNING: Removing unreachable block (ram,0x08027258) */
/* WARNING: Removing unreachable block (ram,0x0802725c) */
/* WARNING: Removing unreachable block (ram,0x08027226) */
/* WARNING: Removing unreachable block (ram,0x0802722a) */
/* WARNING: Removing unreachable block (ram,0x08027230) */
/* WARNING: Removing unreachable block (ram,0x08027236) */
/* WARNING: Removing unreachable block (ram,0x08027240) */
/* WARNING: Removing unreachable block (ram,0x08027224) */

longlong FUN_0802c8ac(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  
  bVar2 = param_2 == 0;
  if (bVar2) {
    param_2 = *(uint *)(*DAT_0802c8c4 + 0xc);
  }
  if (bVar2 && param_2 == 0) {
    return (ulonglong)param_2 << 0x20;
  }
  uVar1 = FUN_0801ffbe(param_2);
  if (uVar1 < param_1) {
    return (ulonglong)param_4 << 0x20;
  }
  return CONCAT44(param_4,*(int *)(param_2 + 4) + (ushort)(*(short *)(param_2 + 2) + 2) * param_1);
}



/* ===== FUN_0802c8c8 @ 0802c8c8 ===== */

void FUN_0802c8c8(char param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  uint unaff_r7;
  bool bVar6;
  
  pbVar4 = (byte *)*DAT_0802c91c;
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
        *DAT_0802c920 = 0;
        FUN_0802f90c(bVar2,uVar3 & 0xff,pbVar4[2],pbVar4[3],param_3,0,0);
        FUN_0802b7ec();
        return;
      }
    }
  }
  return;
}



/* ===== FUN_0802c924 @ 0802c924 ===== */

undefined8 FUN_0802c924(int param_1,int param_2,int param_3,undefined4 param_4)

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
  
  uVar5 = *DAT_0802c98c;
  local_18 = (char)uVar5;
  cStack_17 = (char)((uint)uVar5 >> 8);
  cStack_16 = (char)((uint)uVar5 >> 0x10);
  uStack_15 = (undefined1)((uint)uVar5 >> 0x18);
  if (param_2 < 0x65) {
    puVar4 = DAT_0802c98c;
    if (param_2 < 0) goto LAB_0802c97c;
  }
  else {
    param_2 = 100;
  }
  puVar4 = (undefined4 *)((longlong)param_2 * (longlong)DAT_0802c990);
  iVar3 = (int)((ulonglong)((longlong)param_2 * (longlong)DAT_0802c990) >> 0x20);
  param_3 = (iVar3 >> 2) - (iVar3 >> 0x1f);
  cVar1 = (char)param_3;
  cStack_16 = (char)param_2 + cVar1 * -10 + '0';
  if (cVar1 != '\0') {
    cVar2 = (char)((longlong)(int)cVar1 * (longlong)DAT_0802c990 >> 0x22) -
            (char)((longlong)(int)cVar1 * (longlong)DAT_0802c990 >> 0x3f);
    cStack_17 = cVar1 + cVar2 * -10 + '0';
    param_3 = (int)cVar2;
    if (param_3 != 0) {
      local_18 = cVar2 + '0';
    }
  }
LAB_0802c97c:
  uStack_14 = param_4;
  FUN_08018b1c(*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2),param_3,puVar4);
  FUN_080190ec(&local_18);
  return CONCAT44(uStack_14,CONCAT13(uStack_15,CONCAT12(cStack_16,CONCAT11(cStack_17,local_18))));
}



/* ===== FUN_0802c994 @ 0802c994 ===== */

void FUN_0802c994(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3,undefined1 *param_4)

{
  if (param_1 != (undefined1 *)0x0) {
    *param_1 = *(undefined1 *)*DAT_0802c9c4;
  }
  if (param_2 != (undefined1 *)0x0) {
    *param_2 = *(undefined1 *)(*DAT_0802c9c4 + 1);
  }
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = *(undefined1 *)(*DAT_0802c9c4 + 2);
  }
  if (param_4 != (undefined1 *)0x0) {
    *param_4 = *(undefined1 *)(*DAT_0802c9c4 + 3);
  }
  return;
}



/* ===== FUN_0802c9c8 @ 0802c9c8 ===== */

void FUN_0802c9c8(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  uint local_18;
  
  uVar2 = param_2 >> 8;
  local_18._0_1_ = (byte)param_2;
  if ((byte)local_18 >> 4 == 0) {
    local_38 = 0x1030;
  }
  else {
    local_38 = 0x30;
  }
  local_28 = 0;
  switch(param_2 & 0xf) {
  case 3:
    uVar1 = (uint)((ulonglong)uVar2 * (ulonglong)DAT_0802cafc >> 0x23);
    local_2c = uVar2 + local_38 + uVar1 * -10;
    uVar2 = (uint)((ulonglong)uVar1 * (ulonglong)DAT_0802cafc >> 0x23);
    local_30 = uVar1 + local_38 + uVar2 * -10;
    local_38 = uVar2 + local_38;
    local_34 = 0x2e;
    break;
  case 4:
    uVar1 = (uint)((ulonglong)uVar2 * (ulonglong)DAT_0802cafc >> 0x23);
    local_2c = uVar2 + local_38 + uVar1 * -10;
    local_30 = 0x2e;
    uVar2 = (uint)((ulonglong)uVar1 * (ulonglong)DAT_0802cafc >> 0x23);
    local_34 = uVar1 + local_38 + uVar2 * -10;
    local_38 = uVar2 + local_38;
    break;
  case 5:
    uVar1 = (uint)((ulonglong)uVar2 * (ulonglong)DAT_0802cafc >> 0x23);
    local_2c = 0x20;
    local_30 = uVar2 + local_38 + uVar1 * -10;
    uVar2 = (uint)((ulonglong)uVar1 * (ulonglong)DAT_0802cafc >> 0x23);
    local_34 = uVar1 + local_38 + uVar2 * -10;
    local_38 = uVar2 + local_38;
    break;
  case 6:
    uVar1 = (uint)((ulonglong)uVar2 * (ulonglong)DAT_0802cafc >> 0x23);
    local_2c = uVar2 + local_38 + uVar1 * -10;
    local_34 = uVar1 + local_38;
    local_30 = 0x2e;
    local_38 = 0x3e;
    break;
  default:
    local_2c = 0x2d;
    local_30 = 0x2d;
    local_34 = 0x2d;
    local_38 = 0x20;
    break;
  case 8:
    uVar1 = (uint)((ulonglong)uVar2 * (ulonglong)DAT_0802cafc >> 0x23);
    local_30 = uVar1 + local_38;
    local_2c = uVar2 + local_38 + uVar1 * -10;
    local_34 = 0x3e;
    local_38 = 0x20;
    break;
  case 9:
    local_30 = uVar2 + local_38;
    local_2c = 0x20;
    local_34 = 0x3e;
    local_38 = 0x20;
  }
  local_18 = param_2;
  FUN_08018b1c(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
  FUN_080190f8(&local_38);
  return;
}



/* ===== FUN_0802cb00 @ 0802cb00 ===== */

void FUN_0802cb00(uint param_1,uint param_2,uint param_3,int param_4)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  
  pbVar1 = DAT_0802ccb8;
  uVar4 = (uint)*DAT_0802ccb4;
  bVar5 = *DAT_0802ccb8;
  uVar6 = (uint)bVar5;
  uVar7 = param_1;
  if (uVar4 < uVar6) {
LAB_0802cb1e:
    bVar5 = (byte)uVar7;
    uVar4 = param_1;
  }
  else if ((int)param_1 < (int)uVar6) {
    bVar5 = (byte)param_1;
  }
  else {
    uVar7 = uVar6;
    if ((int)uVar4 < (int)param_1) goto LAB_0802cb1e;
  }
  *DAT_0802ccb4 = (byte)uVar4;
  *pbVar1 = bVar5;
  pbVar1 = DAT_0802ccc0;
  uVar4 = (uint)*DAT_0802ccbc;
  uVar7 = (uint)*DAT_0802ccc0;
  uVar6 = param_2;
  if (uVar4 < uVar7) {
LAB_0802cb40:
    uVar7 = uVar6;
    uVar4 = param_2;
  }
  else if ((int)param_2 < (int)uVar7) {
    uVar7 = param_2;
  }
  else {
    uVar6 = uVar7;
    if ((int)uVar4 < (int)param_2) goto LAB_0802cb40;
  }
  uVar6 = param_3;
  if (uVar7 <= uVar4) {
    bVar5 = (byte)uVar7;
    if ((int)param_3 < (int)uVar7) {
      bVar5 = (byte)param_3;
      goto LAB_0802cb58;
    }
    uVar6 = uVar7;
    if ((int)param_3 <= (int)uVar4) goto LAB_0802cb58;
  }
  bVar5 = (byte)uVar6;
  uVar4 = param_3;
LAB_0802cb58:
  *DAT_0802ccbc = (byte)uVar4;
  *pbVar1 = bVar5;
  iVar2 = DAT_0802cccc;
  param_1 = param_1 + (param_2 >> 3) * 0x80;
  bVar5 = *(byte *)(DAT_0802ccc4 + (param_3 & 7));
  bVar3 = *(byte *)(DAT_0802ccc8 + (param_2 & 7));
  for (param_2 = param_2 & 0xfff8; param_2 <= (param_3 & 0xf8); param_2 = param_2 + 8 & 0xffff) {
    if (param_2 == (param_3 & 0xf8)) {
      bVar3 = bVar3 & bVar5;
    }
    if (param_4 == 0) {
      if (bVar3 == 0xff) {
        bVar3 = 0;
      }
      else {
        bVar3 = *(byte *)(iVar2 + param_1) & ~bVar3;
      }
    }
    else if (bVar3 != 0xff) {
      bVar3 = bVar3 | *(byte *)(iVar2 + param_1);
    }
    *(byte *)(iVar2 + param_1) = bVar3;
    param_1 = param_1 + 0x80 & 0xffff;
    bVar3 = 0xff;
  }
  if (*DAT_0802ccd0 == '\0') {
    FUN_0802b7ec();
    return;
  }
  return;
}



/* ===== FUN_0802cbbe @ 0802cbbe ===== */

void FUN_0802cbbe(uint param_1,uint param_2,uint param_3,int param_4)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  
  pbVar1 = DAT_0802ccb8;
  uVar3 = (uint)*DAT_0802ccb4;
  uVar6 = (uint)*DAT_0802ccb8;
  uVar7 = param_1;
  if (uVar3 < uVar6) {
LAB_0802cbdc:
    uVar6 = uVar7;
    uVar3 = param_1;
  }
  else if ((int)param_1 < (int)uVar6) {
    uVar6 = param_1;
  }
  else {
    uVar7 = uVar6;
    if ((int)uVar3 < (int)param_1) goto LAB_0802cbdc;
  }
  uVar7 = param_3;
  if (uVar3 < uVar6) {
LAB_0802cbf2:
    bVar5 = (byte)uVar7;
    uVar3 = param_3;
  }
  else {
    bVar5 = (byte)uVar6;
    if ((int)param_3 < (int)uVar6) {
      bVar5 = (byte)param_3;
    }
    else {
      uVar7 = uVar6;
      if ((int)uVar3 < (int)param_3) goto LAB_0802cbf2;
    }
  }
  *DAT_0802ccb4 = (byte)uVar3;
  *pbVar1 = bVar5;
  pbVar1 = DAT_0802ccc0;
  uVar3 = (uint)*DAT_0802ccbc;
  bVar5 = *DAT_0802ccc0;
  uVar7 = (uint)bVar5;
  uVar6 = param_2;
  if (uVar7 <= uVar3) {
    if ((int)param_2 < (int)uVar7) {
      bVar5 = (byte)param_2;
      goto LAB_0802cc16;
    }
    uVar6 = uVar7;
    if ((int)param_2 <= (int)uVar3) goto LAB_0802cc16;
  }
  bVar5 = (byte)uVar6;
  uVar3 = param_2;
LAB_0802cc16:
  *DAT_0802ccbc = (byte)uVar3;
  *pbVar1 = bVar5;
  iVar2 = DAT_0802cccc;
  uVar3 = param_1 + (param_2 >> 3) * 0x80;
  bVar5 = *(byte *)(DAT_0802ccd4 + (param_2 & 7));
  uVar6 = param_1;
  if (param_4 == 0) {
    bVar5 = ~bVar5;
  }
  while (uVar6 <= param_3) {
    bVar4 = *(byte *)(iVar2 + uVar3);
    if (param_4 == 0) {
      bVar4 = bVar4 & bVar5;
    }
    else {
      bVar4 = bVar4 | bVar5;
    }
    *(byte *)(iVar2 + uVar3) = bVar4;
    param_1 = param_1 + 1;
    uVar3 = uVar3 + 1 & 0xffff;
    uVar6 = param_1 & 0xff;
  }
  if (*DAT_0802ccd0 == '\0') {
    FUN_0802b7ec();
    return;
  }
  return;
}



/* ===== FUN_0802cc5e @ 0802cc5e ===== */

void FUN_0802cc5e(int param_1,int param_2,int param_3,int param_4,undefined1 param_5)

{
  *DAT_0802ccd8 = 0;
  if (param_1 != param_3) {
    FUN_0802cbbe(param_1,param_2,param_3,param_5);
  }
  if ((param_2 == param_4) || (FUN_0802cb00(param_1,param_2,param_4,param_5), param_1 == param_3)) {
    return;
  }
  FUN_0802cbbe(param_1,param_4,param_3,param_5);
  FUN_0802cb00(param_3,param_2,param_4,param_5);
  return;
}



/* ===== FUN_0802ccdc @ 0802ccdc ===== */

void FUN_0802ccdc(uint param_1,uint param_2,int param_3)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  iVar7 = DAT_0802cd50;
  *DAT_0802cd4c = 0;
  pbVar2 = DAT_0802cd58;
  bVar5 = *(byte *)(iVar7 + (param_2 & 7));
  iVar7 = param_1 + (param_2 >> 3) * 0x80;
  bVar1 = *(byte *)(DAT_0802cd54 + iVar7);
  if (param_3 == 0) {
    bVar5 = bVar1 & ~bVar5;
  }
  else {
    bVar5 = bVar5 | bVar1;
  }
  *(byte *)(DAT_0802cd54 + iVar7) = bVar5;
  pbVar3 = DAT_0802cd5c;
  bVar5 = *pbVar2;
  uVar6 = (uint)bVar5;
  uVar8 = (uint)*DAT_0802cd5c;
  uVar4 = param_1;
  if (uVar8 < uVar6) {
LAB_0802cd1e:
    bVar5 = (byte)uVar4;
    uVar8 = param_1;
  }
  else if ((int)param_1 < (int)uVar6) {
    bVar5 = (byte)param_1;
  }
  else {
    uVar4 = uVar6;
    if ((int)uVar8 < (int)param_1) goto LAB_0802cd1e;
  }
  *pbVar2 = bVar5;
  *pbVar3 = (byte)uVar8;
  pbVar2 = DAT_0802cd64;
  bVar5 = *DAT_0802cd60;
  uVar6 = (uint)bVar5;
  uVar8 = (uint)*DAT_0802cd64;
  uVar4 = param_2;
  if (uVar6 <= uVar8) {
    if ((int)param_2 < (int)uVar6) {
      bVar5 = (byte)param_2;
      goto LAB_0802cd42;
    }
    uVar4 = uVar6;
    if ((int)param_2 <= (int)uVar8) goto LAB_0802cd42;
  }
  bVar5 = (byte)uVar4;
  uVar8 = param_2;
LAB_0802cd42:
  *DAT_0802cd60 = bVar5;
  *pbVar2 = (byte)uVar8;
  return;
}



/* ===== FUN_0802cd68 @ 0802cd68 ===== */

int FUN_0802cd68(float param_1,int param_2)

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



/* ===== FUN_0802cd90 @ 0802cd90 ===== */

int FUN_0802cd90(int param_1)

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



/* ===== FUN_0802ce84 @ 0802ce84 ===== */

undefined4 FUN_0802ce84(void)

{
  return DAT_0802cf48;
}



/* ===== FUN_0802ce88 @ 0802ce88 ===== */

void FUN_0802ce88(byte *param_1,int param_2,int param_3)

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



/* ===== FUN_0802ceb0 @ 0802ceb0 ===== */

undefined8 FUN_0802ceb0(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_2 != 0) {
    FUN_0802ce88();
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



/* ===== FUN_0802cedc @ 0802cedc ===== */

undefined8 FUN_0802cedc(int param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  if (param_3 != 0) {
    FUN_0802ce88(param_2,param_3,param_4);
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



/* ===== FUN_0802cf2e @ 0802cf2e ===== */

void FUN_0802cf2e(void)

{
  FUN_0802ceb0();
  return;
}



/* ===== FUN_0802cf32 @ 0802cf32 ===== */

void FUN_0802cf32(void)

{
  FUN_0802cedc();
  return;
}



/* ===== FUN_0802cf3e @ 0802cf3e ===== */

void FUN_0802cf3e(void)

{
                    /* WARNING: Could not recover jumptable at 0x0802cf2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(DAT_0802cf48 + 0x3c))();
  return;
}



/* ===== FUN_0802cf42 @ 0802cf42 ===== */

undefined4 FUN_0802cf42(void)

{
  return DAT_0802cf4c;
}



/* ===== FUN_0802cf50 @ 0802cf50 ===== */

char * FUN_0802cf50(char *param_1,char param_2)

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



/* ===== FUN_0802cf68 @ 0802cf68 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0802cf68(char *param_1)

{
  undefined4 unaff_r7;
  
  if (param_1 == (char *)0x0) {
    param_1 = "constraint handler: bad message";
  }
  if ((code *)*_DAT_0802cf84 == (code *)0x0) {
    FUN_0802f29a(param_1);
  }
  else {
    (*(code *)*_DAT_0802cf84)(param_1,0,0x22);
  }
  return CONCAT44(unaff_r7,0x22);
}



/* ===== FUN_0802cfa8 @ 0802cfa8 ===== */

char * FUN_0802cfa8(uint *param_1,char param_2,uint param_3)

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
    if (bVar6) goto LAB_0802cff8;
    puVar1 = (uint *)((int)param_1 + 1);
    uVar2 = *param_1;
    param_1 = puVar1;
    if (param_2 == (char)uVar2) goto LAB_0802cffc;
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
  do {
    bVar6 = iVar3 != 0;
    iVar3 = iVar3 + -1;
    bVar5 = iVar3 == 0;
    if (bVar6) {
      bVar5 = param_2 == (char)*param_1;
      param_1 = (uint *)((int)param_1 + 1);
    }
  } while (bVar6 && !bVar5);
LAB_0802cff8:
  puVar1 = param_1;
  if (!bVar5) {
    puVar1 = (uint *)0x1;
  }
LAB_0802cffc:
  return (char *)((int)puVar1 + -1);
}



/* ===== FUN_0802d000 @ 0802d000 ===== */

void FUN_0802d000(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 extraout_r2;
  
  FUN_0802d00c();
  *param_3 = extraout_r2;
  return;
}



/* ===== FUN_0802d00c @ 0802d00c ===== */

undefined8 FUN_0802d00c(uint param_1,uint param_2)

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



/* ===== FUN_0802d070 @ 0802d070 ===== */

void FUN_0802d070(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  if (((int)(param_2 | param_4) < 0) || (0xffe00000 < param_4 * 2)) {
    return;
  }
  return;
}



/* ===== FUN_0802d0a4 @ 0802d0a4 ===== */

void FUN_0802d0a4(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  if (((int)(param_2 | param_4) < 0) || (0xffe00000 < param_2 * 2)) {
    return;
  }
  return;
}



/* ===== FUN_0802d0d8 @ 0802d0d8 ===== */

longlong FUN_0802d0d8(uint param_1,uint param_2,uint param_3)

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
      if (uVar6 == 0x7ff) goto LAB_0802d14e;
      if (uVar7 < uVar6) {
        return CONCAT44(param_2 + param_3 * 0x100000,param_1);
      }
      uVar7 = (uVar7 - uVar6) + 1;
      param_2 = param_2 & ~(uVar6 << 0x14) | 0x100000;
    }
    if (param_1 == 0 && (param_2 & 0x7fffffff) == 0) goto LAB_0802d14e;
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
    goto code_r0x0802d104;
  }
  uVar7 = param_2 >> 0x14 & 0x7ff;
  if (uVar7 != 0) {
    if (uVar7 == 0x7ff) goto LAB_0802d14e;
    uVar7 = uVar7 + param_3;
LAB_0802d0ec:
    if (uVar7 < 0x7ff) {
      return CONCAT44(param_2 + param_3 * 0x100000,param_1);
    }
    uVar6 = param_2 & 0x80000000 | 0x7ff00000;
    iVar4 = 0;
code_r0x0802d104:
    return CONCAT44(uVar6,iVar4);
  }
  if (param_1 == 0 && (param_2 & 0x7fffffff) == 0) goto LAB_0802d14e;
  uVar7 = param_2 & 0x80000000;
  param_2 = param_2 ^ uVar7;
  if (param_2 == 0) {
    uVar6 = LZCOUNT(param_1) + 0x15;
    if (uVar6 < 0x20) goto LAB_0802d11c;
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
      goto LAB_0802d0ec;
    }
  }
  else {
    uVar6 = LZCOUNT(param_2) - 0xb;
LAB_0802d11c:
    if (uVar6 < param_3) {
      param_3 = param_3 - uVar6;
      param_2 = (param_2 << (uVar6 & 0xff) | uVar7) + (param_1 >> (0x20 - uVar6 & 0xff));
      param_1 = param_1 << (uVar6 & 0xff);
      uVar7 = param_3 + 1;
      goto LAB_0802d0ec;
    }
  }
  param_2 = param_2 << (param_3 & 0xff) | uVar7 | param_1 >> (0x20 - param_3 & 0xff);
  param_1 = param_1 << (param_3 & 0xff);
LAB_0802d14e:
  return CONCAT44(param_2,param_1);
}



/* ===== FUN_0802d214 @ 0802d214 ===== */

uint FUN_0802d214(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = (param_2 & 0x7fffffff) >> 0x14;
  iVar2 = -uVar3;
  iVar4 = iVar2 + 0x41e;
  uVar1 = (int)param_2 >> 0x1f;
  if (iVar4 != 0 && uVar3 < 0x41f) {
    uVar3 = UnsignedSaturate(iVar4,7);
    UnsignedDoesSaturate(iVar4,7);
    return ((param_2 << 0xb | param_1 >> 0x15 | 0x80000000) >> (uVar3 & 0xff)) + uVar1 ^ uVar1;
  }
  uVar3 = 0;
  if (iVar2 != -0x7ff) {
    uVar3 = ~uVar1 ^ 0x80000000;
  }
  return uVar3;
}



/* ===== FUN_0802d24c @ 0802d24c ===== */

undefined8 FUN_0802d24c(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_1 & 0x80000000;
  iVar2 = 0;
  if (param_1 != 0) {
    if ((int)uVar3 < 0) {
      param_1 = -param_1;
    }
    uVar1 = param_1 << LZCOUNT(param_1);
    uVar3 = (uVar3 | (0x420 - (LZCOUNT(param_1) + 3)) * 0x100000) + (uVar1 >> 0xb);
    iVar2 = uVar1 << 0x15;
  }
  return CONCAT44(uVar3,iVar2);
}



/* ===== FUN_0802d3dc @ 0802d3dc ===== */

longlong FUN_0802d3dc(uint param_1,uint param_2,uint param_3,uint param_4)

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
      if (0x35 < (int)uVar6) goto LAB_0802d4b6;
      param_4 = (param_4 << 0xb | 0x80000000) >> 0xb;
    }
    else {
      if (0xffdfffff < param_2 << 1) {
        return CONCAT44(param_2,param_1);
      }
      if (param_3 == 0 && (param_4 & 0x7fffffff) == 0) {
LAB_0802d4b6:
        return CONCAT44(param_2,param_1);
      }
      if (param_2 * 2 < 0x200001 && param_2 * -2 != -0x200000) {
        bVar11 = CARRY4(param_1,param_3);
        param_1 = param_1 + param_3;
        param_2 = param_2 + (param_4 & 0x7fffffff) + (uint)bVar11;
        goto LAB_0802d4b6;
      }
      param_4 = param_4 & 0x7fffffff;
      uVar6 = (param_2 >> 0x14) - 1;
      if (0x34 < (int)uVar6) goto LAB_0802d4b6;
    }
    uVar3 = (int)(param_2 << 0xb | 0x80000000) >> 0xb;
    uVar8 = uVar6 - 0x20;
    if (uVar8 == 0 || (int)uVar6 < 0x20) {
      uVar4 = param_3 >> (uVar6 & 0xff);
      uVar9 = (param_3 >> (uVar6 & 0x1f) | param_3 << 0x20 - (uVar6 & 0x1f)) ^ uVar4;
      uVar8 = param_4 >> (uVar6 & 0x1f) | param_4 << 0x20 - (uVar6 & 0x1f);
      uVar5 = (uVar8 << (uVar6 & 0xff)) >> (uVar6 & 0xff);
      uVar4 = uVar4 ^ uVar8 ^ uVar5;
      uVar6 = param_1 + uVar4;
      uVar8 = uVar3 + uVar5 + (uint)CARRY4(param_1,uVar4);
      if (!CARRY4(uVar3,uVar5) && !CARRY4(uVar3 + uVar5,(uint)CARRY4(param_1,uVar4)))
      goto LAB_0802d46c;
    }
    else {
      uVar4 = param_4 >> (uVar8 & 0xff);
      uVar9 = (param_4 >> (uVar8 & 0x1f) | param_4 << 0x20 - (uVar8 & 0x1f)) ^ uVar4;
      if (param_3 != 0) {
        uVar9 = uVar9 | 1;
      }
      uVar6 = param_1 + uVar4;
      uVar8 = uVar3 + CARRY4(param_1,uVar4);
      if (!CARRY4(uVar3,(uint)CARRY4(param_1,uVar4))) goto LAB_0802d46c;
    }
    uVar3 = uVar8 & 1;
    uVar8 = uVar8 >> 1;
    bVar2 = (byte)uVar6;
    uVar6 = (uint)(uVar3 != 0) << 0x1f | uVar6 >> 1;
    uVar3 = uVar9 & 1;
    uVar9 = (uint)(bVar2 & 1) << 0x1f | uVar9 >> 1;
    if (uVar3 != 0) {
      uVar9 = uVar9 | 1;
    }
LAB_0802d46c:
    bVar11 = 0x80000000 < uVar9 || uVar9 + 0x80000000 < (uint)((uVar6 & 1) != 0);
    uVar3 = uVar8 + 0x100000 + (param_2 & 0xfff00000) + (uint)CARRY4(uVar6,(uint)bVar11);
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
    uVar8 = uVar3 - (param_4 >> 0x14);
    if (0x36 < (int)uVar8) goto LAB_0802d396;
    uVar4 = param_4 << 0xb | 0x80000000;
    if ((int)uVar8 < 2) {
      uVar4 = uVar4 | param_3 >> 0x15;
      if (uVar8 == 1) {
        param_3 = param_3 << 10;
        uVar4 = uVar4 >> 1;
      }
      else {
        param_3 = param_3 << 0xb;
      }
      uVar8 = param_1 >> 0x15;
      uVar6 = param_1 * 0x800;
      param_1 = uVar6 - param_3;
      uVar8 = ((param_2 << 0xb | 0x80000000 | uVar8) - uVar4) - (uint)(uVar6 < param_3);
      uVar6 = uVar3 << 0x14;
      if (-1 < (int)uVar8) {
        if (uVar8 == 0) {
          iVar10 = LZCOUNT(param_1);
          uVar8 = param_1 << iVar10;
          uVar6 = 0;
          if (uVar8 == 0) goto LAB_0802d396;
          param_1 = 0;
          iVar10 = iVar10 + 0x20;
        }
        else {
          iVar10 = LZCOUNT(uVar8);
          uVar8 = uVar8 << iVar10 | param_1 >> (0x20U - iVar10 & 0xff);
          param_1 = param_1 << iVar10;
        }
        uVar4 = -((int)param_2 >> 0x1f) | uVar3 << 0x15;
        uVar6 = uVar4 + iVar10 * -0x200000;
        uVar5 = uVar6 & 0xfffffffe;
        uVar3 = ((int)param_2 >> 0x1f) * -0x80000000;
        uVar6 = uVar6 >> 1 | uVar3;
        if (uVar4 < (uint)(iVar10 * 0x200000) || uVar5 == 0) {
          uVar5 = 0x200000 - uVar5 >> 0x15;
          uVar6 = uVar8 >> (uVar5 & 0x1f);
          uVar4 = uVar8 << 0x20 - (uVar5 & 0x1f);
          uVar8 = uVar8 >> (uVar5 & 0xff);
          param_1 = param_1 >> (uVar5 & 0xff) ^ (uVar6 | uVar4) ^ uVar8;
          uVar6 = uVar3;
        }
      }
      uVar3 = param_1 >> 0xb | uVar8 << 0x15;
      bVar11 = (param_1 >> 10 & 1) != 0 && (param_1 >> 0xb & 1) != 0;
      param_1 = uVar3 + bVar11;
      uVar6 = uVar6 + ((uVar8 & 0x7fffffff) >> 0xb) + (uint)CARRY4(uVar3,(uint)bVar11);
      goto LAB_0802d396;
    }
    uVar4 = uVar4 >> 0xb;
LAB_0802d32c:
    uVar3 = param_2 >> 0x14;
    uVar6 = (param_2 << 0xb | 0x80000000) >> 0xb;
    uVar5 = uVar8 - 0x20;
    if (uVar5 == 0 || (int)uVar8 < 0x20) {
      uVar5 = param_3 >> (uVar8 & 0xff);
      uVar7 = (param_3 >> (uVar8 & 0x1f) | param_3 << 0x20 - (uVar8 & 0x1f)) ^ uVar5;
      uVar9 = uVar4 >> (uVar8 & 0xff);
      uVar4 = uVar5 ^ (uVar4 >> (uVar8 & 0x1f) | uVar4 << 0x20 - (uVar8 & 0x1f)) ^ uVar9;
      uVar8 = (param_1 - uVar4) - (uint)(uVar7 != 0);
      uVar6 = (uVar6 - uVar9) - (uint)(param_1 <= uVar4 && (uint)(uVar7 == 0) <= param_1 - uVar4);
    }
    else {
      uVar9 = uVar4 >> (uVar5 & 0xff);
      uVar7 = (param_3 | param_3 << 0x10) >> 0x10 | uVar4 << (0x20 - uVar5 & 0xff);
      uVar8 = (param_1 - uVar9) - (uint)(uVar7 != 0);
      uVar6 = uVar6 - (param_1 <= uVar9 && (uint)(uVar7 == 0) <= param_1 - uVar9);
    }
    uVar4 = -uVar7;
    if (((uVar6 & 0x100000) == 0) && (uVar3 = uVar3 - 1, (uVar3 & 0x7ff) != 0)) {
      bVar1 = (uVar4 & 0x80000000) != 0;
      uVar4 = uVar7 * -2;
      uVar5 = uVar8 * 2;
      bVar11 = CARRY4(uVar8,uVar8);
      uVar8 = uVar8 * 2 + (uint)bVar1;
      uVar6 = uVar6 * 2 + (uint)(bVar11 || CARRY4(uVar5,(uint)bVar1));
    }
    bVar11 = 0x80000000 < uVar4 || uVar4 + 0x80000000 < (uint)((uVar8 & 1) != 0);
    param_1 = uVar8 + bVar11;
    uVar6 = (uVar6 & 0xffefffff) + uVar3 * 0x100000 + (uint)CARRY4(uVar8,(uint)bVar11);
  }
  else {
    if (0xffdfffff < param_2 * 2) {
      if (param_2 * 2 != 0xffe00000 || 0xffdfffff < param_4 << 1) {
        uVar6 = 0xffffffff;
      }
      goto LAB_0802d396;
    }
    uVar4 = param_4 & 0x7fffffff;
    if (param_3 != 0 || (param_4 & 0x7fffffff) != 0) {
      if (0x400000 < param_2 * 2 || param_2 * -2 == -0x400000) {
        uVar8 = (param_2 >> 0x14) - 1;
        if (0x34 < (int)uVar8) goto LAB_0802d396;
        goto LAB_0802d32c;
      }
      bVar11 = param_1 < param_3;
      param_1 = param_1 - param_3;
      uVar6 = (param_2 - uVar4) - (uint)bVar11;
    }
    if (param_1 == 0 && (uVar6 & 0x7fffffff) == 0) {
      uVar6 = 0;
    }
  }
LAB_0802d396:
  return CONCAT44(uVar6,param_1);
}



/* ===== FUN_0802d4c0 @ 0802d4c0 ===== */

ulonglong FUN_0802d4c0(uint param_1,uint param_2,uint param_3,uint param_4)

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
      uVar2 = param_3 * 2;
      iVar4 = param_4 * 2 + (uint)CARRY4(param_3,param_3);
      iVar11 = LZCOUNT(iVar4);
      if (iVar4 == 0) {
        iVar11 = LZCOUNT(uVar2) + 0x20;
      }
      uVar8 = iVar11 - 0xb;
      if (uVar8 < 0x20) {
        param_4 = iVar4 << (uVar8 & 0xff) | uVar2 >> (0x20 - uVar8 & 0xff);
      }
      else {
        param_4 = uVar2 << (iVar11 - 0x2bU & 0xff);
      }
      param_3 = uVar2 << (uVar8 & 0xff);
      if (uVar5 != 0) {
        iVar4 = uVar5 + uVar8 + -1;
        goto LAB_0802d4e0;
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
LAB_0802d4e0:
  param_2 = param_2 & 0xfffff;
  param_4 = param_4 & 0xfffff;
  uVar5 = param_1 - param_3;
  iVar11 = (param_2 - param_4) - (uint)(param_3 > param_1);
  uVar8 = param_4 | 0x100000;
  if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
    iVar4 = iVar4 + -1;
    bVar14 = CARRY4(uVar5,uVar5);
    uVar2 = uVar5 * 2;
    uVar5 = uVar2 + param_3;
    iVar11 = iVar11 * 2 + (uint)bVar14 + uVar8 + (uint)CARRY4(uVar2,param_3);
  }
  uVar3 = iVar11 << 0xb | uVar5 >> 0x15;
  uVar7 = uVar3 / uVar8;
  uVar3 = uVar3 - uVar8 * uVar7;
  uVar9 = (uint)((ulonglong)param_3 * (ulonglong)uVar7);
  uVar6 = (uint)((ulonglong)param_3 * (ulonglong)uVar7 >> 0x20);
  uVar5 = uVar5 * 0x800;
  uVar2 = uVar5 - uVar9;
  iVar11 = (uVar3 - uVar6) - (uint)(uVar9 > uVar5);
  if (uVar3 <= uVar6 && (uint)(uVar9 <= uVar5) <= uVar3 - uVar6) {
    uVar7 = uVar7 - 1;
    bVar14 = CARRY4(uVar2,param_3);
    uVar2 = uVar2 + param_3;
    iVar11 = iVar11 + uVar8 + (uint)bVar14;
  }
  uVar3 = iVar11 << 0xb | uVar2 >> 0x15;
  uVar13 = uVar3 / uVar8;
  uVar3 = uVar3 - uVar8 * uVar13;
  uVar9 = (uint)((ulonglong)param_3 * (ulonglong)uVar13);
  uVar6 = (uint)((ulonglong)param_3 * (ulonglong)uVar13 >> 0x20);
  uVar2 = uVar2 * 0x800;
  uVar5 = uVar2 - uVar9;
  iVar11 = (uVar3 - uVar6) - (uint)(uVar9 > uVar2);
  if (uVar3 <= uVar6 && (uint)(uVar9 <= uVar2) <= uVar3 - uVar6) {
    uVar13 = uVar13 - 1;
    bVar14 = CARRY4(uVar5,param_3);
    uVar5 = uVar5 + param_3;
    iVar11 = iVar11 + uVar8 + (uint)bVar14;
  }
  uVar3 = iVar11 << 10 | uVar5 >> 0x16;
  uVar9 = uVar3 / uVar8;
  uVar3 = uVar3 - uVar8 * uVar9;
  uVar10 = (uint)((ulonglong)param_3 * (ulonglong)uVar9);
  uVar6 = (uint)((ulonglong)param_3 * (ulonglong)uVar9 >> 0x20);
  uVar5 = uVar5 * 0x400;
  uVar2 = uVar5 - uVar10;
  iVar11 = (uVar3 - uVar6) - (uint)(uVar10 > uVar5);
  if (uVar3 <= uVar6 && (uint)(uVar10 <= uVar5) <= uVar3 - uVar6) {
    uVar9 = uVar9 - 1;
    bVar14 = CARRY4(uVar2,param_3);
    uVar2 = uVar2 + param_3;
    iVar11 = iVar11 + uVar8 + (uint)bVar14;
  }
  uVar3 = iVar11 << 0xb | uVar2 >> 0x15;
  uVar9 = uVar7 << 0x15 | uVar13 << 10 | uVar9;
  uVar7 = uVar3 / uVar8;
  uVar3 = uVar3 - uVar8 * uVar7;
  uVar13 = (uint)((ulonglong)param_3 * (ulonglong)uVar7);
  uVar6 = (uint)((ulonglong)param_3 * (ulonglong)uVar7 >> 0x20);
  uVar2 = uVar2 * 0x800;
  uVar5 = uVar2 - uVar13;
  iVar11 = (uVar3 - uVar6) - (uint)(uVar13 > uVar2);
  if (uVar3 <= uVar6 && (uint)(uVar13 <= uVar2) <= uVar3 - uVar6) {
    uVar7 = uVar7 - 1;
    bVar14 = CARRY4(uVar5,param_3);
    uVar5 = uVar5 + param_3;
    iVar11 = iVar11 + uVar8 + (uint)bVar14;
  }
  uVar2 = iVar11 << 0xb | uVar5 >> 0x15;
  uVar6 = uVar2 / uVar8;
  uVar2 = uVar2 - uVar8 * uVar6;
  uVar8 = (uint)((ulonglong)param_3 * (ulonglong)uVar6);
  uVar3 = (uint)((ulonglong)param_3 * (ulonglong)uVar6 >> 0x20);
  uVar5 = uVar5 * 0x800;
  uVar6 = uVar6 - (uVar2 <= uVar3 && (uint)(uVar8 <= uVar5) <= uVar2 - uVar3);
  if (uVar2 - uVar3 != (uint)(uVar8 > uVar5) || uVar5 != uVar8) {
    uVar6 = uVar6 | 1;
  }
  uVar5 = (uVar6 & 0xffc007ff | (uVar7 & 0x7ff) << 0xb) >> 2;
  iVar11 = iVar4 + 0x400;
  if (iVar11 != 0 && -0x401 < iVar4) {
    bVar14 = 0x80000000 < uVar6 * 0x40000000 ||
             uVar6 * 0x40000000 + 0x80000000 < (uint)((uVar6 & 4) != 0);
    uVar8 = uVar9 * 0x100000;
    uVar2 = (uVar9 >> 0xc) +
            iVar11 * 0x100000 + (uint)(CARRY4(uVar5,uVar8) || CARRY4(uVar5 + uVar8,(uint)bVar14));
    if ((int)(uVar2 + 0x100000) < 0) {
      return (ulonglong)(uVar12 | 0x7ff00000) << 0x20;
    }
    return CONCAT44(uVar2 | uVar12,uVar5 + uVar8 + bVar14);
  }
  uVar3 = (uVar6 & 3) << 0x1d;
  uVar5 = uVar5 | uVar9 << 0x14;
  uVar8 = uVar9 >> 0xc | 0x100000;
  uVar2 = -iVar11 + 1;
  uVar6 = -iVar11 - 0x1f;
  if ((int)uVar2 < 0x20) {
    uVar13 = uVar2 & 0xff;
    uVar10 = uVar2 & 0xff;
    uVar6 = uVar8 >> (uVar2 & 0xff);
    uVar7 = uVar5 >> (uVar2 & 0xff) | uVar8 << (0x20 - uVar2 & 0xff);
    uVar9 = 0x20 - uVar2 & 0xff;
    bVar14 = uVar9 == 0 &&
             (uVar10 == 0 &&
              (uVar13 == 0 && 0x1f < uVar2 || uVar13 != 0 && (uVar5 >> uVar13 - 1 & 1) != 0) ||
             uVar10 != 0 && (uVar8 >> uVar10 - 1 & 1) != 0) ||
             uVar9 != 0 && (uVar5 << uVar9 - 1 & 0x80000000) != 0;
    uVar3 = uVar3 | uVar5 << uVar9;
  }
  else {
    if (0x34 < (int)uVar2) {
      return (ulonglong)uVar12 << 0x20;
    }
    uVar7 = uVar8 >> (uVar6 & 0xff);
    uVar2 = 0x20 - uVar6 & 0xff;
    bVar14 = uVar2 != 0 && (uVar8 << uVar2 - 1 & 0x80000000) != 0;
    uVar3 = (uVar3 | uVar5 << 1) >> 1 | uVar5 >> (uVar6 & 0xff) | uVar8 << uVar2;
    uVar6 = 0;
  }
  bVar14 = 0x80000000 < uVar3 || uVar3 + 0x80000000 < (uint)bVar14;
  return CONCAT44(uVar6 + uVar12 + CARRY4(uVar7,(uint)bVar14),uVar7 + bVar14);
}



/* ===== FUN_0802d708 @ 0802d708 ===== */

uint FUN_0802d708(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0x41e - (param_2 >> 0x14);
  if (iVar2 < 0) {
    return ~((int)param_2 >> 0x1f);
  }
  uVar1 = UnsignedSaturate(iVar2,7);
  UnsignedDoesSaturate(iVar2,7);
  return (param_1 >> 0x15 | param_2 << 0xb | 0x80000000) >> (uVar1 & 0xff);
}



/* ===== FUN_0802d72c @ 0802d72c ===== */

undefined8 FUN_0802d72c(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = param_1 << LZCOUNT(param_1);
  return CONCAT44((0x420 - (LZCOUNT(param_1) + 3)) * 0x100000 + (uVar1 >> 0xb),uVar1 << 0x15);
}



/* ===== FUN_0802d748 @ 0802d748 ===== */

longlong FUN_0802d748(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint unaff_r5;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  
  uVar6 = param_2 >> 0x14 & 0x7ff;
  bVar12 = uVar6 == 0;
  if (!bVar12) {
    unaff_r5 = param_4 >> 0x14 & 0x7ff;
    bVar12 = unaff_r5 == 0;
  }
  if (!bVar12) {
    bVar12 = uVar6 == 0x7ff;
  }
  if (!bVar12) {
    bVar12 = unaff_r5 == 0x7ff;
  }
  if (bVar12) {
    uVar8 = param_4 >> 0x14 & 0x7ff;
    uVar11 = (param_2 ^ param_4) & 0x80000000;
    if (uVar6 == 0x7ff || uVar8 == 0x7ff) {
      bVar12 = (param_2 & 0x7fffffff) == 0;
      bVar13 = param_1 == 0 && bVar12;
      if (param_1 != 0 || !bVar12) {
        bVar13 = param_3 == 0 && (param_4 & 0x7fffffff) == 0;
      }
      if (bVar13) {
        param_2 = 0xffffffff;
      }
      uVar6 = param_4 * 2;
      uVar5 = param_4;
      if (uVar6 < 0xffe00001) {
        uVar6 = param_2 * 2;
        uVar5 = param_2;
      }
      if (uVar6 < 0xffe00001) goto LAB_0802d7d2;
      if (uVar6 < 0xffe00001) {
        return CONCAT44(uVar5,param_1);
      }
      goto LAB_0802d802;
    }
    bVar13 = (param_2 & 0x7fffffff) == 0;
    bVar12 = param_1 == 0 && bVar13;
    if (param_1 != 0 || !bVar13) {
      bVar12 = param_3 == 0 && (param_4 & 0x7fffffff) == 0;
    }
    uVar5 = uVar11;
    if (!bVar12) {
      if (uVar6 != 0) {
        param_4 = param_4 & 0x7fffffff;
        iVar7 = LZCOUNT(param_4);
        if (param_4 == 0) {
          iVar7 = LZCOUNT(param_3) + 0x20;
        }
        uVar3 = iVar7 - 0xb;
        if (uVar3 < 0x20) {
          uVar5 = param_4 << (uVar3 & 0xff) | param_3 >> (0x20 - uVar3 & 0xff);
        }
        else {
          uVar5 = param_3 << (iVar7 - 0x2bU & 0xff);
        }
        param_3 = param_3 << (uVar3 & 0xff);
        iVar7 = ((uVar6 + uVar8) - uVar3) + 1;
        goto LAB_0802d770;
      }
      if (uVar8 != 0) {
        uVar6 = param_1;
        uVar5 = param_2 << 0xc;
        if (param_2 << 0xc == 0) {
          uVar6 = 0;
          uVar8 = uVar8 - 0x14;
          uVar5 = param_1;
        }
        iVar9 = LZCOUNT(uVar5);
        iVar7 = uVar8 - iVar9;
        param_1 = uVar6 << iVar9 + 0xc;
        uVar6 = uVar5 << iVar9 | uVar6 >> (0x20U - (iVar9 + 0xc) & 0xff);
        uVar5 = param_4 & 0x1fffff | 0x100000;
        goto LAB_0802d77c;
      }
    }
  }
  else {
    iVar7 = uVar6 + unaff_r5;
    uVar11 = (param_2 ^ param_4) & 0x80000000;
    uVar5 = param_4 & 0x1fffff | 0x100000;
LAB_0802d770:
    uVar6 = param_2 << 0xb | 0x80000000 | param_1 >> 0x15;
    param_1 = param_1 << 0xb;
LAB_0802d77c:
    uVar1 = (ulonglong)uVar6 * (ulonglong)param_3 +
            ((ulonglong)param_1 * (ulonglong)param_3 >> 0x20);
    uVar3 = (uint)(uVar1 >> 0x20);
    lVar2 = (ulonglong)uVar5 * (ulonglong)param_1 + (uVar1 & 0xffffffff);
    uVar8 = (uint)lVar2;
    uVar4 = (uint)((ulonglong)lVar2 >> 0x20);
    if ((int)((ulonglong)param_1 * (ulonglong)param_3) != 0) {
      uVar8 = uVar8 | 1;
    }
    uVar1 = (ulonglong)uVar5 * (ulonglong)uVar6 +
            (ulonglong)CONCAT14(CARRY4(uVar3,uVar4),uVar3 + uVar4);
    uVar6 = (uint)uVar1;
    uVar5 = (uint)(uVar1 >> 0x20);
    bVar12 = (uVar1 & 0x10000000000000) != 0;
    if (!bVar12) {
      bVar13 = CARRY4(uVar8,uVar8);
      uVar8 = uVar8 * 2;
      bVar14 = CARRY4(uVar6,uVar6) || CARRY4(uVar6 * 2,(uint)bVar13);
      bVar12 = CARRY4(uVar5,uVar5) || CARRY4(uVar5 * 2,(uint)bVar14);
      uVar1 = CONCAT44(uVar5 * 2 + (uint)bVar14,uVar6 * 2 + (uint)bVar13);
    }
    uVar3 = (uint)(uVar1 >> 0x20);
    uVar6 = (uint)uVar1;
    iVar9 = iVar7 + -0x3ff + (uint)bVar12;
    if (iVar9 != 0 &&
        iVar9 < 0 == (SCARRY4(iVar7 + -0x400,1) != SCARRY4(iVar7 + -0x3ff,(uint)bVar12))) {
      bVar12 = 0x80000000 < uVar8 || uVar8 + 0x80000000 < (uint)((uVar1 & 1) != 0);
      iVar7 = uVar3 + iVar9 * 0x100000 + (uint)CARRY4(uVar6,(uint)bVar12);
      if (-1 < iVar7) {
        return CONCAT44(iVar7 - 0x100000U | uVar11,uVar6 + bVar12);
      }
LAB_0802d7d2:
      return (ulonglong)(uVar11 | 0x7ff00000) << 0x20;
    }
    uVar4 = -iVar9 + 1;
    uVar10 = -iVar9 - 0x1f;
    if ((int)uVar4 < 0x20) {
      bVar12 = (uVar8 & 1) != 0;
      uVar8 = uVar8 >> 1;
      if (bVar12) {
        uVar8 = uVar8 | 1;
      }
      uVar5 = 0x20 - uVar4 & 0xff;
      bVar12 = uVar5 == 0 && bVar12 || uVar5 != 0 && (uVar6 << uVar5 - 1 & 0x80000000) != 0;
      uVar8 = uVar8 + (uVar6 << uVar5);
      uVar5 = uVar6 >> (uVar4 & 0xff) | uVar3 << (0x20 - uVar4 & 0xff);
      uVar3 = uVar3 >> (uVar4 & 0xff);
LAB_0802d8e4:
      bVar12 = 0x80000000 < uVar8 || uVar8 + 0x80000000 < (uint)bVar12;
      return CONCAT44(uVar3 + uVar11 + CARRY4(uVar5,(uint)bVar12),uVar5 + bVar12);
    }
    uVar5 = uVar11;
    if ((int)uVar4 < 0x36) {
      uVar6 = uVar6 >> (uVar10 & 0xff);
      if (uVar8 != 0 || (uVar1 & 0x7fffffff) != 0) {
        uVar6 = uVar6 | 1;
      }
      uVar4 = uVar10 & 0xff;
      uVar5 = uVar3 >> uVar4;
      uVar8 = 0x20 - uVar10 & 0xff;
      bVar12 = uVar8 == 0 &&
               (uVar4 == 0 && (bool)((byte)(uVar1 >> 0x18) >> 7) ||
               uVar4 != 0 && (uVar3 >> uVar4 - 1 & 1) != 0) ||
               uVar8 != 0 && (uVar3 << uVar8 - 1 & 0x80000000) != 0;
      uVar8 = uVar6 | uVar3 << uVar8;
      uVar3 = 0;
      goto LAB_0802d8e4;
    }
  }
  param_1 = 0;
LAB_0802d802:
  return CONCAT44(uVar5,param_1);
}



/* ===== FUN_0802d8f2 @ 0802d8f2 ===== */

undefined8 FUN_0802d8f2(void)

{
  int iVar1;
  undefined4 unaff_r7;
  
  iVar1 = FUN_0802ce84();
  return CONCAT44(unaff_r7,*(undefined4 *)(iVar1 + 0x40));
}



/* ===== FUN_0802d8fc @ 0802d8fc ===== */

int FUN_0802d8fc(undefined4 param_1,int param_2)

{
  if (param_2 < 0) {
    return 0;
  }
  if (0xfff < param_2) {
    param_2 = 0xfff;
  }
  return param_2;
}



/* ===== FUN_0802d910 @ 0802d910 ===== */

void FUN_0802d910(uint param_1)

{
  if (*DAT_0802d928 << 2 < 0) {
    *DAT_0802d92c = param_1 | *DAT_0802d92c & 0xfffff000;
  }
  return;
}



/* ===== FUN_0802d930 @ 0802d930 ===== */

undefined4 FUN_0802d930(undefined1 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 unaff_r7;
  
  *param_1 = (char)param_2;
  puVar1 = DAT_0802d974;
  if (param_2 == 0) {
    if (param_1[4] == '\0') {
      FUN_080302b4();
      FUN_080302e8();
    }
    puVar1 = DAT_0802d974;
    DAT_0802d974[4] = 0x40;
    puVar1[4] = 1;
    return unaff_r7;
  }
  *DAT_0802d974 = 0x40;
  *puVar1 = 1;
  if (param_1[4] == '\0') {
    FUN_0802e760((int)*(short *)(param_1 + 8));
    FUN_08030304();
    uVar2 = FUN_08030338(unaff_r7);
    return uVar2;
  }
  return unaff_r7;
}



/* ===== FUN_0802d978 @ 0802d978 ===== */

undefined4 FUN_0802d978(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  *(char *)(param_1 + 1) = (char)param_2;
  puVar1 = DAT_0802d9e4;
  if (param_2 == 0) {
    if (*(char *)(param_1 + 4) != '\0') {
      FUN_08030354(param_1);
      FUN_080302e8();
    }
    DAT_0802d9e0[4] = 0x40;
    puVar1 = DAT_0802d9e4;
    DAT_0802d9e4[4] = 0x8000;
    puVar1[4] = 4;
    return param_4;
  }
  *DAT_0802d9e4 = 4;
  if (*(char *)(param_1 + 4) != '\0') {
    FUN_0802e760((int)*(short *)(param_1 + 0x10));
    FUN_08030338();
    FUN_08030354(param_1);
  }
  if (*(char *)(param_1 + 7) == '\0') {
    *puVar1 = 0x8000;
  }
  else {
    puVar1[4] = 0x8000;
  }
  if (*(char *)(param_1 + 6) == '\0') {
    DAT_0802d9e0[4] = 0x40;
    return param_4;
  }
  *DAT_0802d9e0 = 0x40;
  return param_4;
}



/* ===== FUN_0802d9e8 @ 0802d9e8 ===== */

void FUN_0802d9e8(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 4) = param_2;
  FUN_0802e454();
  return;
}



/* ===== FUN_0802d9f0 @ 0802d9f0 ===== */

void FUN_0802d9f0(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 3;
  }
  else {
    iVar1 = 1;
  }
  *DAT_0802da04 = iVar1 << 4 | *DAT_0802da04 & 0xffffffcf;
  return;
}



/* ===== FUN_0802da48 @ 0802da48 ===== */

void FUN_0802da48(int param_1)

{
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  disableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
  *(undefined4 *)(param_1 + 8) = 2;
  *(undefined4 *)(param_1 + 4) = DAT_0802da70;
  *(undefined4 *)(param_1 + 0x14) = 0;
  enableIRQinterrupts();
  return;
}



/* ===== FUN_0802da74 @ 0802da74 ===== */

undefined8 FUN_0802da74(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0803035c(param_1 + 4,param_1 + 0x18e0);
  FUN_08030368(param_1 + 0x14);
  *(undefined1 *)(param_1 + 0x1430) = 0;
  FUN_08030384(param_1 + 0x1444);
  FUN_08030398(param_1 + 0x1854);
  FUN_0802fc3a(param_1 + 0x18e0,DAT_0802dac0,0x2c,4);
  FUN_0802dac4(param_1);
  return CONCAT44(param_4,param_1);
}



/* ===== FUN_0802dac4 @ 0802dac4 ===== */

void FUN_0802dac4(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[4] = 0;
  FUN_080303aa(param_1 + 0x108);
  *(undefined1 *)(param_1 + 0x50c) = 0;
  disableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  param_1[3] = 0;
  enableIRQinterrupts();
  param_1[0x513] = 0;
  param_1[0x617] = 0;
  return;
}



/* ===== FUN_0802db00 @ 0802db00 ===== */

undefined8 FUN_0802db00(uint param_1,int param_2)

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



/* ===== FUN_0802db38 @ 0802db38 ===== */

void FUN_0802db38(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 2) {
    uVar1 = 1;
  }
  else if (param_1 < 0xb) {
    uVar1 = 10;
  }
  else if (param_1 < 0x65) {
    uVar1 = 100;
  }
  else {
    uVar1 = 1000;
  }
  *DAT_0802e204 = uVar1;
  return;
}



/* ===== FUN_0802db62 @ 0802db62 ===== */

int FUN_0802db62(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar5;
  int *piVar4;
  int *piVar6;
  int iVar7;
  
  piVar1 = DAT_0802e20c;
  uVar3 = *DAT_0802e208 & 0xffff;
  if (0x80 < uVar3) {
    uVar3 = *DAT_0802e208 & 0xffff;
  }
  if (uVar3 < 0x81) {
    if (uVar3 == 0) {
      uVar3 = 0x80;
    }
    iVar2 = *(int *)(DAT_0802e210 + *DAT_0802e20c * 4);
    piVar6 = (int *)((int)DAT_0802e20c + uVar3 * -2 + 300);
    piVar5 = (int *)*param_1;
    if ((int *)*param_1 != piVar6) {
      do {
        piVar4 = (int *)((int)piVar5 + 2);
        iVar7 = (int)(short)*piVar5 - piVar1[9];
        if (-1 < iVar7) {
          iVar7 = (int)((ulonglong)((longlong)iVar7 * (longlong)DAT_0802e214) >> 0x20);
          iVar7 = iVar7 - (iVar7 >> 0x1f);
          if (0x3ff < iVar7) {
            iVar7 = 0x3ff;
          }
          if (*(char *)(iVar2 + 1) != '\0') {
            *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;
            if (iVar7 < 0) {
              *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + 1;
            }
            else if (iVar7 < 0x400) {
              *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;
              iVar7 = iVar2 + iVar7 * 4;
              *(int *)(iVar7 + 0x14) = *(int *)(iVar7 + 0x14) + 1;
            }
          }
        }
        if (piVar1 + 0x4b <= piVar4) {
          piVar4 = piVar1 + 0xb;
        }
        piVar5 = piVar4;
      } while (piVar4 != piVar6);
      *param_1 = piVar6;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



/* ===== FUN_0802dc06 @ 0802dc06 ===== */

void FUN_0802dc06(undefined1 *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  
  *param_2 = *(int *)(param_1 + 0x10) + *param_2;
  param_2[1] = *(int *)(param_1 + 8) + param_2[1];
  param_2[2] = *(int *)(param_1 + 0xc) + param_2[2];
  param_2[3] = *(int *)(param_1 + 4) + param_2[3];
  piVar1 = param_2 + 4;
  for (piVar2 = (int *)(param_1 + 0x14); piVar2 < param_1 + 0x1014; piVar2 = piVar2 + 1) {
    *piVar1 = *piVar2 + *piVar1;
    *piVar2 = 0;
    piVar1 = piVar1 + 1;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 1;
  return;
}



/* ===== FUN_0802dc60 @ 0802dc60 ===== */

undefined4 FUN_0802dc60(void)

{
  short sVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 in_r3;
  int iVar5;
  
  iVar3 = DAT_0802e20c;
  sVar1 = *DAT_0802e218;
  if (-1 < sVar1) {
    *(undefined4 *)(DAT_0802e20c + 0x24) = 0;
    iVar3 = sVar1 + 0x2a5;
    if (0xfff < iVar3) {
      iVar3 = 0xfff;
    }
    uVar4 = FUN_08023940((int)(short)iVar3,in_r3);
    return uVar4;
  }
  iVar5 = *(int *)(DAT_0802e20c + 0x28);
  *(int *)(DAT_0802e20c + 0x24) = iVar5;
  FUN_08023940((int)(short)((short)iVar5 + 0x2a5));
  cVar2 = *(char *)(iVar3 + 0x18);
  if (cVar2 == '\0') {
    iVar5 = iVar5 + 1;
    if (0xff < iVar5) {
      iVar5 = 0xff;
      cVar2 = '\x01';
    }
  }
  else {
    iVar5 = iVar5 + -1;
    if (iVar5 < 0) {
      iVar5 = 0;
      cVar2 = '\0';
    }
  }
  *(char *)(iVar3 + 0x18) = cVar2;
  *(int *)(iVar3 + 0x28) = iVar5;
  return in_r3;
}



/* ===== FUN_0802dcbc @ 0802dcbc ===== */

void FUN_0802dcbc(void)

{
  int iVar1;
  
  iVar1 = DAT_0802e20c;
  *(undefined4 *)(DAT_0802e20c + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(undefined1 *)(iVar1 + 0x18) = 0;
  FUN_0802dc60();
  *(int *)(iVar1 + 0x1c) = iVar1 + 0x2c;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  return;
}



/* ===== FUN_0802dcda @ 0802dcda ===== */

void FUN_0802dcda(void)

{
  return;
}



/* ===== FUN_0802dd06 @ 0802dd06 ===== */

void FUN_0802dd06(void)

{
  char *pcVar1;
  int iVar2;
  undefined1 auStack_38 [6];
  undefined1 uStack_32;
  undefined1 uStack_31;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 uStack_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  FUN_0802de04();
  iVar2 = *(int *)(DAT_0802e210 + *DAT_0802e20c * 4);
  if (*(char *)(iVar2 + 1) != '\0') {
    *(undefined1 *)(iVar2 + 1) = 0;
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) * 0x7d >> 7;
  }
  pcVar1 = DAT_0802e200;
  if (*DAT_0802e200 != '\0') {
    uStack_31 = 0;
    uStack_18 = *(undefined4 *)(DAT_0802e200 + 0x18);
    uStack_14 = *(undefined4 *)(DAT_0802e200 + 0x1c);
    uStack_20 = *(undefined4 *)(DAT_0802e200 + 0x10);
    uStack_1c = *(undefined4 *)(DAT_0802e200 + 0x14);
    uStack_30 = *(undefined4 *)(DAT_0802e200 + 8);
    uStack_2c = *(undefined4 *)(DAT_0802e200 + 0xc);
    disableIRQinterrupts();
    enableIRQinterrupts();
    uStack_28 = FUN_0802db00(*DAT_0802e220,DAT_0802e220[1]);
    uStack_10 = 0;
    uStack_c = 0;
    uStack_32 = 0;
    FUN_080305d8(0,auStack_38,pcVar1 + 0x34);
  }
  return;
}



/* ===== FUN_0802dd36 @ 0802dd36 ===== */

void FUN_0802dd36(void)

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
  
  pcVar1 = DAT_0802e200;
  if (*DAT_0802e200 != '\0') {
    local_31 = 0;
    local_18 = *(undefined4 *)(DAT_0802e200 + 0x18);
    local_14 = *(undefined4 *)(DAT_0802e200 + 0x1c);
    local_20 = *(undefined4 *)(DAT_0802e200 + 0x10);
    local_1c = *(undefined4 *)(DAT_0802e200 + 0x14);
    local_30 = *(undefined4 *)(DAT_0802e200 + 8);
    local_2c = *(undefined4 *)(DAT_0802e200 + 0xc);
    disableIRQinterrupts();
    enableIRQinterrupts();
    local_28 = FUN_0802db00(*DAT_0802e220,DAT_0802e220[1]);
    local_10 = 0;
    local_c = 0;
    local_32 = 0;
    FUN_080305d8(0,auStack_38,pcVar1 + 0x34);
  }
  return;
}



/* ===== FUN_0802dd94 @ 0802dd94 ===== */

void FUN_0802dd94(void)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  
  if (*(char *)(DAT_0802e20c + 4) == '\0') {
    *(undefined1 *)(DAT_0802e20c + 4) = 1;
    puVar1 = DAT_0802e224;
    DAT_0802e224[5] = 8;
    puVar2 = DAT_0802e228;
    *puVar1 = *puVar1 | 8;
    puVar1 = DAT_0802e230;
    *puVar2 = *puVar2 & DAT_0802e22c | 4;
    *puVar1 = *puVar1 | 2;
    puVar1 = DAT_0802e234;
    DAT_0802e234[10] = 0x100;
    puVar3 = DAT_0802e238;
    *puVar1 = *puVar1 & 0xfffcffff | 0x10000;
    *puVar3 = 0;
    *puVar1 = *puVar1 & 0xfffcffff | 0x20000;
  }
  return;
}



/* ===== FUN_0802de04 @ 0802de04 ===== */

void FUN_0802de04(void)

{
  uint *puVar1;
  
  puVar1 = DAT_0802e23c;
  if (*(char *)(DAT_0802e20c + 4) != '\0') {
    *(undefined1 *)(DAT_0802e20c + 4) = 0;
    *puVar1 = *puVar1 & 0xfffffffe;
    puVar1[9] = 0;
    puVar1 = DAT_0802e234;
    DAT_0802e234[10] = 0x100;
    *puVar1 = *puVar1 & 0xfffcffff | 0x10000;
    *DAT_0802e230 = *DAT_0802e230 & 0xfffffffd;
    puVar1 = DAT_0802e224;
    *DAT_0802e228 = *DAT_0802e228 & DAT_0802e22c | 0x10;
    *puVar1 = *puVar1 & 0xfffffff7;
    puVar1[5] = 8;
  }
  return;
}



/* ===== FUN_0802de62 @ 0802de62 ===== */

void FUN_0802de62(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  
  iVar3 = DAT_0802e244;
  puVar2 = DAT_0802e240;
  iVar1 = DAT_0802e20c;
  bVar4 = *(byte *)(DAT_0802e20c + 0x14);
  fVar6 = *(float *)(DAT_0802e20c + 8) + 1.0;
  fVar7 = *(float *)(DAT_0802e20c + 0x10);
  while (fVar7 < fVar6) {
    uVar5 = (uint)bVar4;
    bVar4 = bVar4 + 1;
    fVar7 = fVar7 + *(float *)(iVar1 + 0xc) * *(float *)(iVar3 + uVar5 * 4);
    if (199 < bVar4) {
      bVar4 = 0;
    }
    *puVar2 = 0x40000;
  }
  *(float *)(iVar1 + 0x10) = fVar7;
  *(byte *)(iVar1 + 0x14) = bVar4;
  *(float *)(iVar1 + 8) = fVar6;
  return;
}



/* ===== FUN_0802debe @ 0802debe ===== */

void FUN_0802debe(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DAT_0802e20c;
  *(undefined4 *)(DAT_0802e20c + 0xc) = param_1;
  *(undefined4 *)(iVar1 + 0x10) = param_1;
  *(undefined4 *)(iVar1 + 8) = 0;
  return;
}



/* ===== thunk_FUN_0802defa @ 0802ded0 ===== */

void thunk_FUN_0802defa(void)

{
  FUN_0802db62(DAT_0802e248);
  return;
}



/* ===== FUN_0802ded2 @ 0802ded2 ===== */

void FUN_0802ded2(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_0802e20c;
  if ((char)DAT_0802e20c[1] == '\0') {
    return;
  }
  FUN_0802db62(DAT_0802e20c + 7);
  iVar2 = *(int *)(DAT_0802e210 + *piVar1 * 4);
  *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
  FUN_0802dc60();
  return;
}



/* ===== FUN_0802defa @ 0802defa ===== */

void FUN_0802defa(void)

{
  FUN_0802db62(DAT_0802e248);
  return;
}



/* ===== FUN_0802defe @ 0802defe ===== */

undefined4 FUN_0802defe(void)

{
  uint *puVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  
  puVar1 = DAT_0802e20c;
  uVar2 = FUN_0802db62(DAT_0802e20c + 7);
  uVar5 = *puVar1;
  iVar4 = *(int *)(DAT_0802e210 + uVar5 * 4);
  uVar5 = uVar5 + 1;
  if (3 < uVar5) {
    uVar5 = 0;
  }
  puVar3 = *(undefined1 **)(DAT_0802e210 + uVar5 * 4);
  FUN_08030406(puVar3);
  if (*(char *)(iVar4 + 1) != '\0') {
    *(undefined1 *)(iVar4 + 1) = 0;
    *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) * 0x7d >> 7;
  }
  *puVar1 = uVar5;
  puVar3[1] = 1;
  *puVar3 = 0;
  return uVar2;
}



/* ===== FUN_0802df4a @ 0802df4a ===== */

undefined8 FUN_0802df4a(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  
  iVar5 = DAT_0802e200;
  if (param_2 < 8) {
    iVar5 = 0;
  }
  else {
    iVar7 = *DAT_0802e204;
    uVar10 = *(uint *)(DAT_0802e200 + 0x18) + *(uint *)(DAT_0802e200 + 0x10);
    uVar9 = uVar10 - *(uint *)(DAT_0802e200 + 0x20);
    uVar6 = FUN_08019bf4(uVar9 + iVar7 / 2,
                         (((*(int *)(DAT_0802e200 + 0x1c) +
                           *(int *)(DAT_0802e200 + 0x14) +
                           (uint)CARRY4(*(uint *)(DAT_0802e200 + 0x18),
                                        *(uint *)(DAT_0802e200 + 0x10))) -
                          *(int *)(DAT_0802e200 + 0x24)) -
                         (uint)(uVar10 < *(uint *)(DAT_0802e200 + 0x20))) +
                         (iVar7 - (iVar7 >> 0x1f) >> 0x1f) + (uint)CARRY4(uVar9,iVar7 / 2),iVar7,
                         iVar7 >> 0x1f);
    *param_1 = uVar6;
    piVar4 = DAT_0802e24c;
    piVar8 = (int *)(iVar5 + 0x34);
    param_1[1] = 0;
    piVar1 = (int *)(iVar5 + 0x1034U);
    piVar2 = (int *)(iVar5 + 0x2034);
    piVar3 = piVar4;
    for (; piVar8 < (int *)(iVar5 + 0x1034U); piVar8 = piVar8 + 1) {
      iVar11 = *piVar8;
      iVar7 = *piVar1;
      *piVar3 = (iVar7 + iVar11) - *piVar2;
      *piVar2 = iVar7 + iVar11;
      piVar1 = piVar1 + 1;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
    iVar5 = FUN_08030cc0(param_1 + 2,piVar4,0x400);
    if (iVar5 == 0) {
      iVar5 = -1;
    }
    else {
      iVar5 = (iVar5 - (int)(param_1 + 2)) + 8;
    }
  }
  return CONCAT44(param_4,iVar5);
}



/* ===== FUN_0802dfe6 @ 0802dfe6 ===== */

undefined8 FUN_0802dfe6(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  
  iVar5 = DAT_0802e200;
  if (param_2 < 0x14) {
    iVar5 = 0;
  }
  else {
    iVar7 = *DAT_0802e204;
    uVar8 = *(uint *)(DAT_0802e200 + 0x18) + *(uint *)(DAT_0802e200 + 0x10);
    uVar6 = FUN_08019bf4(uVar8 + iVar7 / 2,
                         *(int *)(DAT_0802e200 + 0x1c) +
                         *(int *)(DAT_0802e200 + 0x14) +
                         (uint)CARRY4(*(uint *)(DAT_0802e200 + 0x18),*(uint *)(DAT_0802e200 + 0x10))
                         + (iVar7 - (iVar7 >> 0x1f) >> 0x1f) + (uint)CARRY4(uVar8,iVar7 / 2),iVar7,
                         iVar7 >> 0x1f);
    *param_1 = uVar6;
    FUN_080262d4(param_1 + 1,DAT_0802e250,0xc);
    param_1[4] = 0;
    *(uint *)(iVar5 + 0x20) = *(uint *)(iVar5 + 0x18) + *(uint *)(iVar5 + 0x10);
    *(uint *)(iVar5 + 0x24) =
         *(int *)(iVar5 + 0x14) + *(int *)(iVar5 + 0x1c) +
         (uint)CARRY4(*(uint *)(iVar5 + 0x18),*(uint *)(iVar5 + 0x10));
    *(int *)(iVar5 + 0x30) = *(int *)(iVar5 + 0x28) + *(int *)(iVar5 + 0x2c);
    piVar4 = DAT_0802e24c;
    piVar1 = (int *)(iVar5 + 0x2034);
    piVar2 = (int *)(iVar5 + 0x1034U);
    piVar3 = DAT_0802e24c;
    for (piVar9 = (int *)(iVar5 + 0x34); piVar9 < (int *)(iVar5 + 0x1034U); piVar9 = piVar9 + 1) {
      iVar10 = *piVar9;
      iVar7 = *piVar2;
      *piVar1 = iVar7 + iVar10;
      *piVar3 = iVar7 + iVar10;
      piVar1 = piVar1 + 1;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
    iVar5 = FUN_08030cc0(param_1 + 5,piVar4,0x400);
    if (iVar5 == 0) {
      iVar5 = -1;
    }
    else {
      iVar5 = (iVar5 - (int)(param_1 + 5)) + 0x14;
    }
  }
  return CONCAT44(param_4,iVar5);
}



/* ===== FUN_0802e096 @ 0802e096 ===== */

int FUN_0802e096(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = DAT_0802e200;
  if (param_2 < 0x14) {
    iVar1 = 0;
  }
  else {
    iVar3 = *DAT_0802e204;
    uVar2 = FUN_08019bb0(*(uint *)(DAT_0802e200 + 0x10) + iVar3 / 2,
                         *(int *)(DAT_0802e200 + 0x14) +
                         (iVar3 - (iVar3 >> 0x1f) >> 0x1f) +
                         (uint)CARRY4(*(uint *)(DAT_0802e200 + 0x10),iVar3 / 2),iVar3,iVar3 >> 0x1f)
    ;
    *param_1 = uVar2;
    FUN_080262d4(param_1 + 1,DAT_0802e250,0xc);
    param_1[4] = 0;
    iVar1 = FUN_08030cc0(param_1 + 5,iVar1 + 0x34,0x400);
    if (iVar1 == 0) {
      iVar1 = -1;
    }
    else {
      iVar1 = (iVar1 - (int)(param_1 + 5)) + 0x14;
    }
  }
  return iVar1;
}



/* ===== FUN_0802e0f4 @ 0802e0f4 ===== */

longlong FUN_0802e0f4(undefined4 *param_1,int param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_0802e200;
  if (param_2 < 8) {
    return (ulonglong)param_4 << 0x20;
  }
  iVar3 = *DAT_0802e204;
  uVar1 = FUN_08019bf4(*(uint *)(DAT_0802e200 + 0x18) + iVar3 / 2,
                       (iVar3 - (iVar3 >> 0x1f) >> 0x1f) + *(int *)(DAT_0802e200 + 0x1c) +
                       (uint)CARRY4(*(uint *)(DAT_0802e200 + 0x18),iVar3 / 2),iVar3,iVar3 >> 0x1f);
  *param_1 = uVar1;
  param_1[1] = 0;
  iVar2 = FUN_08030cc0(param_1 + 2,iVar2 + 0x1034,0x400);
  if (iVar2 == 0) {
    return CONCAT44(param_4,0xffffffff);
  }
  return CONCAT44(param_4,(iVar2 - (int)(param_1 + 2)) + 8);
}



/* ===== FUN_0802e18c @ 0802e18c ===== */

void FUN_0802e18c(void)

{
  undefined4 uVar1;
  
  FUN_08030e08(DAT_0802e200);
  uVar1 = FUN_08017dbe();
  disableIRQinterrupts();
  enableIRQinterrupts();
  FUN_080181c8(*DAT_0802e220,DAT_0802e220[1],uVar1,0x13);
  return;
}



/* ===== FUN_0802e1ae @ 0802e1ae ===== */

undefined8 FUN_0802e1ae(void)

{
  return CONCAT44(*DAT_0802e20c,0x2a5);
}



/* ===== FUN_0802e1b8 @ 0802e1b8 ===== */

void FUN_0802e1b8(uint *param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  
  iVar2 = DAT_0802e200;
  piVar4 = (int *)(DAT_0802e200 + 0x1034);
  puVar1 = param_1 + 4;
  for (piVar6 = (int *)(DAT_0802e200 + 0x34); piVar6 < piVar4; piVar6 = piVar6 + 1) {
    *piVar6 = *puVar1 + *piVar6;
    puVar1 = puVar1 + 1;
  }
  uVar5 = *(uint *)(iVar2 + 0x10);
  uVar3 = *param_1;
  *(uint *)(iVar2 + 0x10) = uVar5 + uVar3;
  *(uint *)(iVar2 + 0x14) =
       ((int)uVar3 >> 0x1f) + *(int *)(iVar2 + 0x14) + (uint)CARRY4(uVar5,uVar3);
  *(uint *)(iVar2 + 0x28) = param_1[1] + *(int *)(iVar2 + 0x28);
  return;
}



/* ===== FUN_0802e28e @ 0802e28e ===== */

void FUN_0802e28e(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = DAT_0802e370;
  *(undefined1 *)(DAT_0802e370 + 8) = 0;
  uVar1 = *DAT_0802e36c;
  while( true ) {
    if ((uVar1 & 0xffff) == (*DAT_0802e36c & 0xffff)) break;
    uVar1 = *DAT_0802e36c;
  }
  *(short *)(iVar2 + 10) = (short)uVar1;
  *(undefined4 *)(iVar2 + 4) = 0;
  iVar2 = DAT_0802e370 + *(int *)(iVar2 + 4) * 8;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  return;
}



/* ===== FUN_0802e292 @ 0802e292 ===== */

void FUN_0802e292(void)

{
  return;
}



/* ===== FUN_0802e2a8 @ 0802e2a8 ===== */

void FUN_0802e2a8(void)

{
  *(undefined1 *)(DAT_0802e370 + 8) = 0;
  return;
}



/* ===== FUN_0802e2aa @ 0802e2aa ===== */

void FUN_0802e2aa(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_0802e370;
  *(undefined1 *)(DAT_0802e370 + 8) = 1;
  uVar2 = *DAT_0802e36c;
  while( true ) {
    if ((uVar2 & 0xffff) == (*DAT_0802e36c & 0xffff)) break;
    uVar2 = *DAT_0802e36c;
  }
  *(short *)(iVar1 + 10) = (short)uVar2;
  return;
}



/* ===== FUN_0802e2cc @ 0802e2cc ===== */

void FUN_0802e2cc(void)

{
  *(undefined1 *)(DAT_0802e370 + 8) = 0;
  return;
}



/* ===== FUN_0802e2d6 @ 0802e2d6 ===== */

void FUN_0802e2d6(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = DAT_0802e370;
  if (*(char *)(DAT_0802e370 + 8) == '\0') {
    return;
  }
  iVar2 = DAT_0802e370 + *(int *)(DAT_0802e370 + 4) * 8;
  uVar3 = *DAT_0802e36c;
  while( true ) {
    if ((uVar3 & 0xffff) == (*DAT_0802e36c & 0xffff)) break;
    uVar3 = *DAT_0802e36c;
  }
  *(int *)(iVar2 + 0xc) =
       (int)(short)((short)uVar3 - *(short *)(DAT_0802e370 + 10)) + *(int *)(iVar2 + 0xc);
  *(short *)(iVar1 + 10) = (short)uVar3;
  *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
  return;
}



/* ===== FUN_0802e31a @ 0802e31a ===== */

void FUN_0802e31a(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_0802e370;
  uVar2 = *DAT_0802e370 + 1;
  if (param_1 <= uVar2) {
    *DAT_0802e370 = uVar2;
    FUN_08016234(DAT_0802e374);
    uVar2 = 0;
  }
  *puVar1 = uVar2;
  return;
}



/* ===== FUN_0802e334 @ 0802e334 ===== */

int FUN_0802e334(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = DAT_0802e370;
  iVar3 = *(int *)(DAT_0802e370 + 4);
  iVar2 = DAT_0802e370 + 0xc;
  uVar4 = *(int *)(DAT_0802e370 + 4) + 1;
  if (7 < uVar4) {
    uVar4 = 0;
  }
  *(undefined4 *)(DAT_0802e370 + 0xc + uVar4 * 8) = 0;
  *(undefined4 *)(iVar1 + uVar4 * 8 + 0x10) = 0;
  *(uint *)(iVar1 + 4) = uVar4;
  return iVar2 + iVar3 * 8;
}



/* ===== FUN_0802e378 @ 0802e378 ===== */

void FUN_0802e378(float param_1,float *param_2,int *param_3)

{
  uint in_fpscr;
  float fVar1;
  float fVar2;
  
  if (*param_3 != 0 && param_3[1] != 0) {
    fVar1 = (float)VectorUnsignedToFloat(param_3[1],(byte)(in_fpscr >> 0x16) & 3);
    fVar2 = (float)VectorUnsignedToFloat(*param_3,(byte)(in_fpscr >> 0x16) & 3);
    *param_2 = (((DAT_0802e3b4 - param_1) / 10.0) * fVar1) / fVar2;
  }
  return;
}



/* ===== FUN_0802e3b8 @ 0802e3b8 ===== */

float FUN_0802e3b8(undefined4 param_1,float *param_2,int param_3,int param_4,undefined4 param_5,
                  undefined4 *param_6)

{
  uint uVar1;
  uint uVar2;
  uint in_fpscr;
  float fVar3;
  float fVar4;
  float fVar5;
  
  if (param_3 != 0) {
    param_2 = param_2 + 1;
  }
  if (param_6[1] != 0) {
    fVar3 = (float)VectorUnsignedToFloat(*param_6,(byte)(in_fpscr >> 0x16) & 3);
    fVar4 = (float)VectorUnsignedToFloat(param_6[1],(byte)(in_fpscr >> 0x16) & 3);
    fVar4 = (fVar3 * *param_2) / fVar4;
    uVar1 = in_fpscr & 0xfffffff | (uint)(fVar4 == 0.0) << 0x1e;
    uVar2 = uVar1 | (uint)(0.0 <= fVar4) << 0x1d;
    if ((bool)((byte)(uVar2 >> 0x1d) & 1) && !SUB41(uVar1 >> 0x1e,0)) {
      fVar5 = (float)VectorUnsignedToFloat(param_5,(byte)(uVar2 >> 0x16) & 3);
      fVar5 = fVar5 + fVar4 * DAT_0802e44c;
      FUN_08023a38(fVar5,param_1,param_4 + 0x58);
      fVar3 = (float)FUN_08030ea4();
      if (0.0 <= fVar4 - fVar3) {
        fVar5 = (float)FUN_08023a38(fVar5,param_1,param_4 + 0x34);
        return (fVar4 - fVar3) / fVar5;
      }
    }
  }
  return DAT_0802e450;
}



/* ===== FUN_0802e454 @ 0802e454 ===== */

void FUN_0802e454(char *param_1,int param_2)

{
  if (param_2 == 0) {
    if (*param_1 == '\0') {
      FUN_080302b4();
      FUN_080302e8();
    }
    else {
      FUN_0802e760((int)*(short *)(param_1 + 8));
      FUN_08030338();
      FUN_08030304();
    }
    DAT_0802e4a8[4] = 0x100;
    return;
  }
  FUN_080302b4();
  if (param_1[1] == '\0') {
    FUN_080302e8();
  }
  else {
    FUN_08030338();
    FUN_0802e760((int)*(short *)(param_1 + 0x10));
  }
  *DAT_0802e4a8 = 0x100;
  return;
}



/* ===== FUN_0802e4ac @ 0802e4ac ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0802e4ac(int param_1,char param_2)

{
  undefined4 uVar1;
  undefined4 unaff_r7;
  float fVar2;
  
  fVar2 = *(float *)(param_1 + 0x14);
  *(float *)(param_1 + 0x14) = fVar2;
  if (param_2 != '\0') {
    fVar2 = fVar2 + *(float *)(param_1 + 0xc);
  }
  uVar1 = FUN_0802d8fc(param_1,(int)(short)(int)(_UNK_0802da44 - fVar2 * _UNK_0802da40));
  FUN_0802d910(uVar1,unaff_r7);
  return;
}



/* ===== FUN_0802e4b4 @ 0802e4b4 ===== */

undefined1 FUN_0802e4b4(int param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  
  switch(*(undefined1 *)(param_1 + 0x3c)) {
  case 0:
    param_2 = 0;
    break;
  case 1:
    switch(*(undefined1 *)(param_1 + 0x18)) {
    case 0:
    case 3:
    case 4:
      break;
    case 1:
      iVar1 = *(int *)(param_1 + 0x5c);
      if (((*(char *)(iVar1 + 5) == '\x01') &&
          ((iVar2 = *(int *)(iVar1 + 0x14), iVar2 != 0 && (*(char *)(iVar1 + 0x19) == '\x02')))) &&
         (((uint)(*(int *)(iVar2 + 0x10) * 0x1e) < *(uint *)(iVar2 + 0xc) ||
          (DAT_0802e54c <= *(float *)(iVar1 + 0x24))))) goto switchD_0802e4c0_caseD_3;
      break;
    case 2:
      if ((*(char *)(*(int *)(param_1 + 0x5c) + 5) != '\x02') ||
         (DAT_0802e550 <= *(float *)(*(int *)(param_1 + 0x5c) + 0x10)))
      goto switchD_0802e4c0_caseD_3;
      break;
    default:
      goto switchD_0802e4c0_default;
    }
  case 2:
    param_2 = 1;
    break;
  case 3:
  case 4:
  case 5:
switchD_0802e4c0_caseD_3:
    param_2 = 2;
    break;
  case 6:
  case 7:
    param_2 = 3;
    break;
  case 8:
    param_2 = 4;
  }
switchD_0802e4c0_default:
  *(undefined1 *)(param_1 + 0x1a) = param_2;
  return param_2;
}



/* ===== FUN_0802e554 @ 0802e554 ===== */

uint FUN_0802e554(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1;
  switch(*(undefined1 *)(param_1 + 0x3c)) {
  case 0:
  case 4:
  case 6:
  case 8:
    uVar1 = 0;
    break;
  case 1:
  case 2:
  case 3:
  case 5:
  case 7:
    uVar1 = 1;
  }
  *(char *)(param_1 + 0x1b) = (char)uVar1;
  return uVar1 & 0xff;
}



/* ===== FUN_0802e578 @ 0802e578 ===== */

void FUN_0802e578(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 5) = param_2;
  if (*(char *)(param_1 + 5) == '\0') {
    DAT_0802e58c[4] = 0x80;
    return;
  }
  *DAT_0802e58c = 0x80;
  return;
}



/* ===== FUN_0802e5a4 @ 0802e5a4 ===== */

undefined4 FUN_0802e5a4(int param_1)

{
  if (*(char *)(param_1 + 5) == '\x01') {
    return *(undefined4 *)(param_1 + 0x14);
  }
  return 0;
}



/* ===== FUN_0802e5cc @ 0802e5cc ===== */

void FUN_0802e5cc(float param_1,float *param_2)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  float fVar6;
  float fVar7;
  float unaff_s16;
  undefined *local_20;
  float local_1c;
  undefined4 local_18;
  
  iVar1 = DAT_0802e6dc;
  local_20 = &DAT_41700000;
  local_1c = DAT_0802e6cc / param_1;
  *(undefined **)(DAT_0802e6dc + 0x58) = &DAT_41700000;
  local_18 = 0;
  *(undefined4 *)(iVar1 + 0x60) = 0;
  *(float *)(iVar1 + 0x5c) = local_1c * 0.25;
  FUN_08030f04(param_2 + 3,0x100,&local_20);
  pfVar4 = param_2 + 3;
  pfVar5 = param_2 + 0x103;
  pfVar3 = pfVar4;
  pfVar2 = pfVar4;
  fVar6 = DAT_0802e6d0;
  if (pfVar4 < pfVar5) {
    do {
      pfVar3 = pfVar2 + 1;
      fVar6 = ABS(*pfVar2);
      unaff_s16 = fVar6;
      if (pfVar5 <= pfVar3) break;
      pfVar2 = pfVar3;
    } while (fVar6 == 0.0);
  }
  for (; pfVar3 < pfVar5; pfVar3 = pfVar3 + 1) {
    fVar7 = ABS(*pfVar3);
    if (0.0 < fVar7) {
      if (fVar7 < fVar6) {
        fVar6 = fVar7;
      }
      if (unaff_s16 < fVar7) {
        unaff_s16 = fVar7;
      }
    }
  }
  if (fVar6 != 0.0) {
    if (fVar6 < unaff_s16 * DAT_0802e6d4) {
      fVar6 = unaff_s16 * DAT_0802e6d4;
    }
    *param_2 = fVar6;
    fVar6 = DAT_0802e6d8 / fVar6;
    for (; pfVar4 < pfVar5; pfVar4 = pfVar4 + 1) {
      *pfVar4 = *pfVar4 * fVar6;
    }
  }
  return;
}



/* ===== FUN_0802e744 @ 0802e744 ===== */

void FUN_0802e744(undefined4 param_1)

{
  int iVar1;
  
  *DAT_0802e75c = 0;
  do {
    iVar1 = FUN_08031038(param_1);
  } while (iVar1 != 0);
  return;
}



/* ===== FUN_0802e760 @ 0802e760 ===== */

void FUN_0802e760(uint param_1)

{
  *DAT_0802e770 = param_1 | *DAT_0802e770 & 0xfffff000;
  return;
}



/* ===== FUN_0802e868 @ 0802e868 ===== */

void FUN_0802e868(uint *param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = FUN_0802e8a8();
  *param_1 = uVar3;
  iVar2 = DAT_0802e9ac;
  puVar1 = DAT_0802e9a4;
  uVar3 = *param_1 >> *(sbyte *)(DAT_0802e9a0 + ((*DAT_0802e9a4 & 0xff) >> 4));
  param_1[1] = uVar3;
  param_1[2] = uVar3 >> *(sbyte *)(iVar2 + ((*puVar1 & 0x7ff) >> 8));
  param_1[3] = param_1[1] >> *(sbyte *)(iVar2 + ((*puVar1 & 0x3fff) >> 0xb));
  return;
}



/* ===== FUN_0802e8a8 @ 0802e8a8 ===== */

uint FUN_0802e8a8(void)

{
  uint uVar1;
  
  uVar1 = DAT_0802e97c[2] & 0xc;
  if (uVar1 == 0) {
LAB_0802e93a:
    if ((int)(*DAT_0802e97c << 0x1c) < 0) {
      if ((int)(*DAT_0802e97c << 0x1c) < 0) {
        uVar1 = *DAT_0802e97c & 0xf0;
      }
      else {
        uVar1 = *DAT_0802e9a8 & 0xf00;
      }
      uVar1 = uVar1 >> 4;
    }
    else {
      if ((int)(*DAT_0802e97c << 0x1c) < 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = *DAT_0802e9a8 & 0xf00;
      }
      uVar1 = uVar1 >> 8;
    }
    return *(uint *)(DAT_0802e9b4 + uVar1 * 4);
  }
  if (uVar1 == 4) {
    return DAT_0802e9b0;
  }
  if (uVar1 == 8) {
    return DAT_0802e9b8;
  }
  if (uVar1 != 0xc) goto LAB_0802e93a;
  uVar1 = DAT_0802e97c[3] & 3;
  if ((uVar1 != 1) && (uVar1 != 0)) {
    if (uVar1 == 3) {
      uVar1 = DAT_0802e9b8;
      goto LAB_0802e932;
    }
    if (uVar1 < 3) {
      uVar1 = DAT_0802e9b0;
      goto LAB_0802e932;
    }
  }
  if ((int)(*DAT_0802e97c << 0x1c) < 0) {
    if ((int)(*DAT_0802e97c << 0x1c) < 0) {
      uVar1 = *DAT_0802e97c & 0xf0;
    }
    else {
      uVar1 = *DAT_0802e9a8 & 0xf00;
    }
    uVar1 = *(uint *)(DAT_0802e9b4 + (uVar1 >> 4) * 4);
  }
  else {
    if ((int)(*DAT_0802e97c << 0x1c) < 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *DAT_0802e9a8 & 0xf00;
    }
    uVar1 = *(uint *)(DAT_0802e9b4 + (uVar1 >> 8) * 4);
  }
LAB_0802e932:
  return (((DAT_0802e97c[3] & 0x7fff) >> 8) * (uVar1 / (((DAT_0802e97c[3] & 0x7f) >> 4) + 1))) /
         ((((DAT_0802e97c[3] & 0x7ffffff) >> 0x19) + 1) * 2);
}



/* ===== FUN_0802eaf2 @ 0802eaf2 ===== */

void FUN_0802eaf2(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = DAT_0802ec68;
  iVar2 = FUN_0802b5e0(DAT_0802ec68,0xd4,0x30,param_1 + 9,2,param_4);
  if (iVar2 == 0) {
    iVar2 = FUN_0802b5e0(uVar1,0xd4,0x2a,param_1 + 5,2,param_4);
    if (iVar2 == 0) {
      FUN_0802b5e0(uVar1,0xd4,0x1f,param_1 + 0x15,1,param_4);
    }
  }
  return;
}



/* ===== FUN_0802ec5a @ 0802ec5a ===== */

undefined4 FUN_0802ec5a(void)

{
  return DAT_0802ec6c;
}



/* ===== FUN_0802ec70 @ 0802ec70 ===== */

ulonglong FUN_0802ec70(int param_1,undefined4 param_2,uint param_3)

{
  char cVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  bool bVar6;
  uint local_18;
  
  puVar2 = DAT_0802ecc4;
  piVar5 = *(int **)(param_1 + 0x10);
  local_18 = param_3;
  if (piVar5 != (int *)0x0) {
    cVar1 = *(char *)(param_1 + 0x15);
    bVar6 = cVar1 == '\x01';
    if (bVar6) {
      cVar1 = *(char *)(param_1 + 0x14);
    }
    if (bVar6 && cVar1 == '\0') {
      *DAT_0802ecc4 = *DAT_0802ecc4 | 0x400000;
      uVar3 = *puVar2;
      local_18 = uVar3 & 0x400000;
      (**(code **)(*piVar5 + 0x14))(piVar5,param_1 + 0x28);
      *puVar2 = *puVar2 & 0xffbfffff;
      iVar4 = FUN_080244a4(param_1,(int)(char)piVar5[1]);
      if (iVar4 == 0) {
        return CONCAT44(uVar3,param_1 + 0x28) & 0x400000ffffffff;
      }
    }
  }
  return (ulonglong)local_18 << 0x20;
}



/* ===== FUN_0802edd4 @ 0802edd4 ===== */

void FUN_0802edd4(int param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_0802f08c;
  *(uint *)(param_1 + 8) = DAT_0802f08c[2];
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



/* ===== FUN_0802ee24 @ 0802ee24 ===== */

void FUN_0802ee24(int param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_0802f08c;
  *DAT_0802f08c = *DAT_0802f08c & 0xffffff9f | *(uint *)(param_1 + 0x14);
  *puVar1 = *puVar1 & 0xffffff7f | *(uint *)(param_1 + 0x18);
  puVar1[3] = *(uint *)(param_1 + 0xc);
  *puVar1 = *puVar1 & 0xffffffe7 | *(uint *)(param_1 + 0x10);
  puVar1[2] = *(uint *)(param_1 + 8);
  *puVar1 = *puVar1 | 1;
  return;
}



/* ===== FUN_0802ee5c @ 0802ee5c ===== */

undefined4 FUN_0802ee5c(int param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  undefined1 local_1c;
  undefined1 local_1b;
  byte local_1a;
  undefined1 local_19;
  undefined1 local_18;
  byte local_17;
  
  piVar3 = DAT_0802f098;
  uVar2 = DAT_0802f094;
  puVar1 = DAT_0802f090;
  *(undefined1 *)(param_1 + 5) = 0xff;
  *puVar1 = *puVar1 | 0x200000;
  *(undefined1 *)(param_1 + 4) = 0x88;
  iVar5 = FUN_0802b51e(uVar2,0x88,0x94,0,0);
  if (iVar5 != 0) {
    *(undefined1 *)(param_1 + 4) = 0x8a;
    do {
    } while ((uint)(*piVar3 - *piVar3) < 2000);
    iVar5 = FUN_0802b51e(uVar2,0x8a,0x94,0,0);
    if (iVar5 != 0) {
      *(undefined1 *)(param_1 + 4) = 0;
      goto LAB_0802eeba;
    }
  }
  do {
  } while ((uint)(*piVar3 - *piVar3) < 10000);
  iVar5 = FUN_0802b51e(DAT_0802f094,*(undefined1 *)(param_1 + 4),0x94,0,0);
  uVar2 = DAT_0802f094;
  if (iVar5 == 0) {
    do {
    } while ((uint)(*piVar3 - *piVar3) < 10000);
    iVar5 = FUN_0802b51e(DAT_0802f094,*(undefined1 *)(param_1 + 4),0x89,0,0);
    if (iVar5 == 0) {
      do {
      } while ((uint)(*piVar3 - *piVar3) < 2000);
      iVar5 = FUN_0802b6ce(uVar2,*(undefined1 *)(param_1 + 4),&local_1c,6);
      *puVar1 = *puVar1 & 0xffdfffff;
      if (iVar5 == 0) {
        FUN_0802edd4(param_1);
        puVar4 = DAT_0802f09c;
        *(undefined1 *)DAT_0802f09c = local_1c;
        *(undefined1 *)puVar4 = local_1b;
        if ((uint)local_1a == (*puVar4 & 0xff)) {
          puVar4[4] = 0xffffffff;
          puVar4[2] = puVar4[2] | 1;
          *(undefined1 *)puVar4 = local_19;
          *(undefined1 *)puVar4 = local_18;
          uVar6 = *puVar4;
          FUN_0802ee24(param_1);
          if ((uint)local_17 == (uVar6 & 0xff)) {
            if (*(char *)(param_1 + 5) < '\x01') {
              *(undefined1 *)(param_1 + 5) = 0;
            }
            return 0;
          }
        }
        else {
          FUN_0802ee24(param_1);
        }
      }
    }
  }
LAB_0802eeba:
  *puVar1 = *puVar1 & 0xffdfffff;
  if (*(char *)(param_1 + 5) < '\x01') {
    *(undefined1 *)(param_1 + 5) = 1;
  }
  return 1;
}



/* ===== FUN_0802efac @ 0802efac ===== */

int FUN_0802efac(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_1c;
  undefined4 uStack_18;
  
  local_1c = param_3;
  uStack_18 = param_4;
  FUN_08016b94();
  uVar2 = DAT_0802f094;
  puVar1 = DAT_0802f090;
  *DAT_0802f090 = *DAT_0802f090 | 0x200000;
  iVar3 = FUN_0802b51e(uVar2,*(undefined1 *)(param_1 + 4),0xfd,0,0);
  *puVar1 = *puVar1 & 0xffdfffff;
  FUN_08016b8e();
  if (iVar3 == 0) {
    do {
    } while ((uint)(*DAT_0802f098 - *DAT_0802f098) < 10000);
    FUN_08016b94();
    *puVar1 = *puVar1 | 0x200000;
    iVar3 = FUN_0802b6ce(uVar2,*(undefined1 *)(param_1 + 4),&local_1c,3,*puVar1 & 0x200000);
    *puVar1 = *puVar1 & 0xffdfffff;
    FUN_08016b8e();
    if (iVar3 == 0) {
      FUN_0802edd4(param_1);
      puVar1 = DAT_0802f09c;
      *(undefined1 *)DAT_0802f09c = (undefined1)local_1c;
      *(undefined1 *)puVar1 = local_1c._1_1_;
      uVar4 = *puVar1;
      FUN_0802ee24(param_1);
      if ((local_1c >> 0x10 & 0xff) == (uVar4 & 0xff)) {
        return (uint)((ulonglong)((uint)CONCAT11((undefined1)local_1c,local_1c._1_1_) * 0xaf00) *
                      (ulonglong)DAT_0802f0a0 >> 0x2f) - 0x2d00;
      }
    }
  }
  if (*(char *)(param_1 + 5) < '\x01') {
    *(undefined1 *)(param_1 + 5) = 1;
  }
  return DAT_0802f0a4;
}



/* ===== FUN_0802f086 @ 0802f086 ===== */

undefined4 FUN_0802f086(void)

{
  return DAT_0802f0a8;
}



/* ===== FUN_0802f0ac @ 0802f0ac ===== */

void FUN_0802f0ac(int param_1,undefined4 param_2,ushort *param_3,undefined4 param_4)

{
  FUN_0802b5e0(DAT_0802f258,*(undefined1 *)(param_1 + 4),param_2,param_3,2,param_4);
  *param_3 = *param_3 >> 8 | *param_3 << 8;
  return;
}



/* ===== FUN_0802f0cc @ 0802f0cc ===== */

void FUN_0802f0cc(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  ushort local_14;
  undefined2 uStack_12;
  undefined4 uStack_10;
  
  _local_14 = CONCAT22((short)((uint)param_3 >> 0x10),
                       (ushort)((uint)param_3 >> 8) | (ushort)(param_3 << 8));
  uStack_10 = param_4;
  FUN_0802b51e(DAT_0802f258,*(undefined1 *)(param_1 + 4),param_2,&local_14,2);
  return;
}



/* ===== FUN_0802f0ec @ 0802f0ec ===== */

undefined1 FUN_0802f0ec(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint *puVar2;
  int iVar3;
  undefined1 uVar4;
  bool bVar5;
  undefined8 uVar6;
  undefined4 local_1c;
  undefined4 uStack_18;
  
  puVar2 = DAT_0802f25c;
  uVar1 = DAT_0802f258;
  local_1c = param_3 & 0xffff0000;
  *(undefined1 *)(param_1 + 5) = 0xff;
  *puVar2 = *puVar2 | 0x200000;
  uStack_18 = param_4;
  iVar3 = FUN_0802b6ce(uVar1,0,&local_1c,2,*puVar2 & 0x200000);
  uVar4 = 1;
  if (iVar3 == 0) {
    *(undefined1 *)(param_1 + 4) = 0x8a;
    iVar3 = FUN_0802f0ac(param_1,1,&local_1c);
    if (iVar3 != 0) {
      *(undefined1 *)(param_1 + 4) = 0x92;
      iVar3 = FUN_0802f0ac(param_1,1,&local_1c);
      if (iVar3 != 0) {
        *(undefined1 *)(param_1 + 4) = 0;
        goto LAB_0802f17e;
      }
    }
    local_1c = CONCAT22(0x6040,(undefined2)local_1c);
    iVar3 = FUN_0802b51e(uVar1,*(undefined1 *)(param_1 + 4),1,(int)&local_1c + 2,2);
    if (iVar3 == 0) {
      uVar6 = FUN_0802f0ac(param_1,1,&local_1c);
      bVar5 = (int)uVar6 == 0;
      if (bVar5) {
        uVar6 = CONCAT44(0x4060,local_1c & 0xffff);
      }
      if (bVar5 && (int)uVar6 == (int)((ulonglong)uVar6 >> 0x20)) {
        uVar4 = 0;
      }
    }
  }
LAB_0802f17e:
  *puVar2 = *puVar2 & 0xffdfffff;
  if (*(char *)(param_1 + 5) < '\x01') {
    *(undefined1 *)(param_1 + 5) = uVar4;
  }
  return uVar4;
}



/* ===== FUN_0802f196 @ 0802f196 ===== */

void FUN_0802f196(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint local_18;
  uint local_14;
  
  local_18 = param_3;
  local_14 = param_4;
  FUN_08016b94();
  puVar1 = DAT_0802f25c;
  *DAT_0802f25c = *DAT_0802f25c | 0x200000;
  local_14 = *puVar1 & 0x200000;
  iVar3 = FUN_0802f0ac(param_1,1,&local_18);
  uVar2 = local_18;
  iVar4 = 0;
  if (iVar3 != 0) {
    local_18 = local_18 | 0x100;
    iVar4 = FUN_0802f0cc(param_1,1,uVar2 & 0xffff | 0x100);
  }
  *DAT_0802f258 = *DAT_0802f258 & 0xfffffffe;
  *puVar1 = *puVar1 & 0xffdfffff;
  FUN_08016b8e();
  if (*(char *)(param_1 + 5) < '\x01') {
    *(byte *)(param_1 + 5) = (byte)~(byte)(-(uint)(iVar4 == 0) >> 0x18) >> 7;
  }
  return;
}



/* ===== FUN_0802f204 @ 0802f204 ===== */

undefined8 FUN_0802f204(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  undefined4 local_18;
  uint local_14;
  
  local_18 = param_3;
  local_14 = param_4;
  FUN_08016b94();
  puVar1 = DAT_0802f25c;
  *DAT_0802f25c = *DAT_0802f25c | 0x200000;
  local_14 = *puVar1 & 0x200000;
  iVar2 = FUN_0802f0ac(param_1,0,&local_18);
  *puVar1 = *puVar1 & 0xffdfffff;
  FUN_08016b8e();
  if (iVar2 == 0) {
    return CONCAT44(local_18,(int)(short)local_18 << 1);
  }
  if (*(char *)(param_1 + 5) < '\x01') {
    *(undefined1 *)(param_1 + 5) = 1;
  }
  return CONCAT44(local_18,DAT_0802f260);
}



/* ===== FUN_0802f252 @ 0802f252 ===== */

undefined4 FUN_0802f252(void)

{
  return DAT_0802f264;
}



/* ===== FUN_0802f29a @ 0802f29a ===== */

void FUN_0802f29a(void)

{
  FUN_08031294(1);
  return;
}



/* ===== FUN_0802f2a0 @ 0802f2a0 ===== */

int * FUN_0802f2a0(void)

{
  int *piVar1;
  
  if (*DAT_0802f2c0 == 0) {
    piVar1 = (int *)(DAT_0802f2c4 & 0xfffffff8);
    *DAT_0802f2c0 = (uint)piVar1;
    *piVar1 = (DAT_0802f2c8 & 0xfffffff8) - (int)piVar1;
    return piVar1;
  }
  return (int *)0x0;
}



/* ===== FUN_0802f2cc @ 0802f2cc ===== */

undefined1 FUN_0802f2cc(undefined4 param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = (uint)*(byte *)(param_2 + 8);
  if (8 < uVar2) {
    return 0;
  }
  if (uVar2 != 7) {
    return *(undefined1 *)(DAT_0802f30c + uVar2 * 2 + 1);
  }
  cVar1 = *(char *)(param_2 + 0xb);
  if (cVar1 == '\x03' || cVar1 == '\f') {
    return 0xc;
  }
  if (cVar1 == '0') {
    return 0xe;
  }
  if (cVar1 == '@') {
    return 8;
  }
  *(undefined1 *)(param_2 + 0xb) = 0;
  return 6;
}



/* ===== FUN_0802f510 @ 0802f510 ===== */

uint FUN_0802f510(undefined4 param_1,undefined2 *param_2)

{
  uint *puVar1;
  int iVar2;
  undefined2 *puVar3;
  
  puVar1 = DAT_0802f560;
  DAT_0802f560[2] = DAT_0802f560[2] & 0xffffff9f;
  puVar1[2] = puVar1[2] & 0xffffff7f;
  puVar1[2] = puVar1[2] & 0xffffffe7 | 8;
  puVar1[5] = 0x8005;
  puVar1[4] = 0xffffffff;
  puVar1[2] = puVar1[2] | 1;
  iVar2 = 6;
  do {
    *(undefined2 *)puVar1 = *param_2;
    iVar2 = iVar2 + -1;
    puVar3 = param_2 + 2;
    *(undefined2 *)puVar1 = param_2[1];
    param_2 = param_2 + 3;
    *(undefined2 *)puVar1 = *puVar3;
  } while (iVar2 != 0);
  return *puVar1 & 0xffff;
}



/* ===== FUN_0802f564 @ 0802f564 ===== */

undefined1 FUN_0802f564(int param_1,undefined1 param_2,undefined1 *param_3,int param_4)

{
  undefined1 uVar1;
  
  do {
  } while (*(int *)(param_1 + 8) << 0x1f < 0);
  do {
  } while (-1 < *(int *)(param_1 + 8) << 0x1e);
  *(undefined1 *)(param_1 + 0xc) = param_2;
  do {
  } while (-1 < *(int *)(param_1 + 8) << 0x1f);
  uVar1 = *(undefined1 *)(param_1 + 0xc);
  if (0 < param_4) {
    do {
      do {
      } while (-1 < *(int *)(param_1 + 8) << 0x1e);
      *(undefined1 *)(param_1 + 0xc) = 0;
      do {
      } while (-1 < *(int *)(param_1 + 8) << 0x1f);
      param_4 = param_4 + -1;
      *param_3 = *(undefined1 *)(param_1 + 0xc);
      param_3 = param_3 + 1;
    } while (param_4 != 0);
  }
  return uVar1;
}



/* ===== FUN_0802f5a4 @ 0802f5a4 ===== */

uint FUN_0802f5a4(int param_1,undefined1 param_2,undefined1 *param_3,int param_4)

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
  if (0 < param_4) {
    do {
      do {
      } while (-1 < *(int *)(param_1 + 8) << 0x1e);
      *(undefined1 *)(param_1 + 0xc) = *param_3;
      do {
      } while (-1 < *(int *)(param_1 + 8) << 0x1f);
      param_4 = param_4 + -1;
      param_3 = param_3 + 1;
    } while (param_4 != 0);
  }
  return uVar1 & 0xff;
}



/* ===== FUN_0802f5e4 @ 0802f5e4 ===== */

void FUN_0802f5e4(byte param_1,uint param_2,uint param_3,uint param_4,uint param_5,
                 undefined2 param_6)

{
  short sVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  byte bVar13;
  uint uVar14;
  uint uVar15;
  undefined1 *puVar16;
  byte bVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  byte bVar21;
  uint uVar22;
  byte *pbVar23;
  uint local_58;
  uint local_54;
  
  pbVar23 = DAT_0802f8e8;
  pbVar6 = DAT_0802f8e4;
  uVar20 = (uint)*DAT_0802f8e4;
  uVar22 = (uint)*DAT_0802f8e8;
  *DAT_0802f8ec = 0;
  pbVar3 = DAT_0802f8f4;
  pbVar2 = DAT_0802f8f0;
  uVar5 = (uint)param_1;
  uVar9 = uVar5;
  if (uVar20 < uVar22) {
LAB_0802f616:
    uVar22 = uVar9;
    uVar20 = uVar5;
  }
  else if (uVar5 < uVar22) {
    uVar22 = uVar5;
  }
  else {
    uVar9 = uVar22;
    if (uVar20 < uVar5) goto LAB_0802f616;
  }
  uVar18 = (uint)*DAT_0802f8f0;
  uVar9 = (uint)*DAT_0802f8f4;
  uVar10 = param_2;
  if (uVar18 < uVar9) {
LAB_0802f640:
    uVar9 = uVar10;
    uVar18 = param_2;
  }
  else if ((int)param_2 < (int)uVar9) {
    uVar9 = param_2;
  }
  else {
    uVar10 = uVar9;
    if ((int)uVar18 < (int)param_2) goto LAB_0802f640;
  }
  bVar21 = (byte)param_3;
  if (uVar20 < uVar22) {
LAB_0802f66a:
    uVar20 = param_3;
  }
  else {
    bVar21 = (byte)uVar22;
    if ((int)param_3 < (int)uVar22) {
      bVar21 = (byte)param_3;
    }
    else if ((int)uVar20 < (int)param_3) goto LAB_0802f66a;
  }
  bVar8 = (byte)param_4;
  if ((uVar9 & 0xff) <= (uVar18 & 0xff)) {
    bVar8 = (byte)uVar9;
    if ((int)param_4 < (int)(uVar9 & 0xff)) {
      bVar8 = (byte)param_4;
      goto LAB_0802f68a;
    }
    if ((int)param_4 <= (int)(uVar18 & 0xff)) goto LAB_0802f68a;
  }
  uVar18 = param_4;
LAB_0802f68a:
  *pbVar6 = (byte)uVar20;
  *pbVar23 = bVar21;
  *pbVar2 = (byte)uVar18;
  *pbVar3 = bVar8;
  if ((int)(param_4 - param_2) < (int)(param_5 & 0xff)) {
    FUN_080274b0(param_1,param_2,param_3 & 0xff,param_4,param_6);
  }
  else {
    bVar17 = *(byte *)(DAT_0802f8f8 + (param_2 & 7));
    bVar21 = *(byte *)(DAT_0802f8fc + (param_4 & 7));
    bVar8 = *(byte *)(DAT_0802f8fc + (param_4 - param_5 & 7));
    uVar10 = (param_4 - param_5 & 0xff) >> 3;
    sVar1 = ((short)param_5 + (ushort)param_2 & 7) - ((ushort)param_2 & 7);
    param_4 = param_4 >> 3;
    uVar22 = (uint)sVar1;
    uVar9 = (param_5 & 0xff) + param_2 >> 3;
    param_2 = param_2 >> 3;
    iVar7 = DAT_0802f904;
    iVar11 = DAT_0802f900;
    for (uVar20 = param_2; uVar20 <= param_4; uVar20 = uVar20 + 1 & 0xff) {
      if (uVar20 == param_4) {
        bVar17 = bVar21 & bVar17;
      }
      uVar18 = uVar5;
      local_58 = param_4;
      local_54 = param_2;
      do {
        uVar19 = (param_3 & 0xff) - uVar18;
        if (7 < (uVar19 & 0xff)) {
          uVar19 = 7;
        }
        uVar15 = 0;
        uVar14 = uVar19;
        puVar16 = (undefined1 *)(iVar7 + uVar9 * 0x80 + uVar18);
        while( true ) {
          *(undefined1 *)(iVar11 + uVar15) = *puVar16;
          iVar4 = DAT_0802f908;
          if ((uVar14 & 0xff) == 0) break;
          uVar15 = uVar15 + 1 & 0xff;
          uVar14 = uVar14 - 1;
          puVar16 = puVar16 + 1;
        }
        if ((int)uVar22 < 1) {
          if (((int)uVar22 < 0) && (uVar9 != local_54)) {
            uVar14 = uVar9 - 1;
            goto LAB_0802f7d8;
          }
        }
        else if (uVar9 != local_58) {
          uVar14 = uVar9 + 1;
LAB_0802f7d8:
          uVar12 = 0;
          uVar15 = uVar19;
          puVar16 = (undefined1 *)(iVar7 + uVar18 + (uVar14 & 0x1f) * 0x80);
          while( true ) {
            *(undefined1 *)(iVar4 + uVar12) = *puVar16;
            uVar12 = uVar12 + 1 & 0xff;
            if ((uVar15 & 0xff) == 0) break;
            uVar15 = uVar15 - 1;
            puVar16 = puVar16 + 1;
          }
        }
        iVar4 = DAT_0802f908;
        iVar11 = DAT_0802f900;
        local_58 = param_4 & 0xff;
        local_54 = param_2 & 0xff;
        uVar15 = 0;
        uVar14 = uVar19;
        while( true ) {
          if (uVar10 < uVar20) {
            *(byte *)(iVar11 + uVar15) = (byte)param_6;
          }
          else {
            if (uVar22 == 0) {
              bVar13 = *(byte *)(iVar11 + uVar15);
            }
            else if ((int)uVar22 < 1) {
              if (uVar20 == local_54) {
                uVar12 = 0;
              }
              else {
                uVar12 = (uint)*(byte *)(iVar4 + uVar15);
              }
              bVar13 = (byte)(((uVar12 | (uint)*(byte *)(iVar11 + uVar15) << 8) << -(char)sVar1) >>
                             8);
            }
            else {
              uVar12 = (uint)*(byte *)(iVar11 + uVar15);
              if (uVar9 != local_58) {
                uVar12 = (uint)CONCAT11(*(undefined1 *)(iVar4 + uVar15),*(byte *)(iVar11 + uVar15));
              }
              bVar13 = (byte)(uVar12 >> (uVar22 & 0xff));
            }
            if (uVar20 == uVar10) {
              bVar13 = bVar13 & bVar8 | (byte)param_6 & ~bVar8;
            }
            *(byte *)(iVar11 + uVar15) = bVar13;
          }
          iVar7 = DAT_0802f904;
          if ((uVar14 & 0xff) == 0) break;
          uVar14 = uVar14 - 1;
          uVar15 = uVar15 + 1 & 0xff;
        }
        pbVar6 = (byte *)(DAT_0802f904 + uVar20 * 0x80 + uVar18);
        if (bVar17 != 0xff) {
          uVar15 = 0;
          uVar14 = uVar19;
          pbVar23 = pbVar6;
          while( true ) {
            *(byte *)(iVar11 + uVar15) = *pbVar23 & ~bVar17 | bVar17 & *(byte *)(iVar11 + uVar15);
            if ((uVar14 & 0xff) == 0) break;
            uVar14 = uVar14 - 1;
            uVar15 = uVar15 + 1 & 0xff;
            pbVar23 = pbVar23 + 1;
          }
        }
        uVar15 = 0;
        uVar14 = uVar19;
        while( true ) {
          *pbVar6 = *(byte *)(iVar11 + uVar15);
          if ((uVar14 & 0xff) == 0) break;
          uVar14 = uVar14 - 1;
          uVar15 = uVar15 + 1 & 0xff;
          pbVar6 = pbVar6 + 1;
        }
        uVar18 = uVar18 + uVar19 + 1 & 0xff;
      } while ((int)uVar18 <= (int)param_3);
      param_2 = param_2 & 0xff;
      param_4 = param_4 & 0xff;
      bVar17 = 0xff;
      uVar9 = uVar9 + 1 & 0xff;
    }
  }
  return;
}



/* ===== FUN_0802f90c @ 0802f90c ===== */

void FUN_0802f90c(int param_1,byte param_2,uint param_3,uint param_4,byte *param_5,byte param_6,
                 ushort param_7)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  byte bVar4;
  
  uVar2 = (uint)param_5[1];
  uVar1 = (uint)*param_5;
  if (uVar2 != 0 && uVar1 != 0) {
    pbVar3 = param_5 + 2;
    bVar4 = (char)*(ushort *)(*DAT_0802f9b0 + 0x10) << 7;
    if (param_7 == 0) {
      param_7 = (ushort)(uVar1 + 7 >> 3);
    }
    else {
      param_7 = param_7 / param_5[1];
    }
    if ((int)((uint)*(ushort *)(*DAT_0802f9b0 + 0x10) << 0x10) < 0) {
      bVar4 = bVar4 | 0x40;
    }
    if (param_6 != 0) {
      param_2 = param_6 + param_2;
      uVar2 = uVar2 - param_6;
      pbVar3 = pbVar3 + (int)(short)(ushort)param_6 * (int)(short)(param_7 & 0xff);
    }
    uVar1 = (uVar1 + param_1) - 1;
    uVar2 = ((uVar2 & 0xffff) + (uint)param_2) - 1;
    if (param_3 < (uVar1 & 0xffff)) {
      uVar1 = param_3;
    }
    if (param_4 < (uVar2 & 0xffff)) {
      uVar2 = param_4;
    }
    *DAT_0802f9b4 = 0;
    FUN_08031300(param_1,param_2,uVar1 & 0xff,uVar2 & 0xff,pbVar3,(char)param_7,bVar4,param_4);
  }
  return;
}



/* ===== FUN_0802f9b8 @ 0802f9b8 ===== */

undefined4 FUN_0802f9b8(undefined4 param_1)

{
  FUN_080262d4();
  return param_1;
}



/* ===== FUN_0802f9c4 @ 0802f9c4 ===== */

undefined4 FUN_0802f9c4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0802bb20(param_1,param_3,param_2);
  return param_1;
}



/* ===== FUN_0802f9d8 @ 0802f9d8 ===== */

void FUN_0802f9d8(uint *param_1)

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
  puVar3 = DAT_0802fb08;
  uVar4 = param_1[1];
  if ((1 < uVar4) && (uVar4 != 2 && uVar4 != 4)) goto LAB_0802fa3c;
  uVar5 = param_1[3];
  *param_1 = 7;
  if (uVar4 == 0) {
    param_1[2] = puVar3[3] & 0xff;
    uVar4 = puVar3[3];
LAB_0802fa36:
    uVar5 = (uVar4 & 0xffffff) >> 0x10;
  }
  else {
    if (uVar4 == 1) {
      param_1[2] = puVar3[4] & 0xff;
      uVar4 = puVar3[4];
      goto LAB_0802fa36;
    }
    if (uVar4 == 2) {
      param_1[2] = puVar3[0xb] & 0xff;
      uVar4 = puVar3[0xb];
      goto LAB_0802fa36;
    }
    if (uVar4 == 4) {
      param_1[2] = puVar3[0xc] & 0xff;
      uVar4 = puVar3[0xc];
      goto LAB_0802fa36;
    }
  }
  param_1[3] = uVar5;
LAB_0802fa3c:
  if ((*puVar3 & 0xff) == 0xaa || (*puVar3 & 0xff) == 0xcc) {
    uVar4 = *puVar3 & 0xff;
  }
  else {
    uVar4 = 0xbb;
  }
  param_1[4] = uVar4;
  param_1[6] = *puVar3 & 0xffffff00;
  piVar2 = DAT_0802fafc;
  puVar1 = DAT_0802faf8;
  uVar4 = param_1[7];
  if (uVar4 == 1 || uVar4 == 2) {
    *param_1 = *param_1 | 8;
    uVar5 = DAT_0802fb0c;
    uVar6 = *puVar1;
    if (*piVar2 << 0x17 < 0) {
      if ((uVar6 & 0xffff) == 0xffff) {
        iVar8 = DAT_0802fb04;
      }
      else {
        iVar8 = (DAT_0802fb00 & uVar6 << 9) + 0x8000000;
      }
      iVar7 = 0x8000000;
    }
    else {
      iVar8 = 0x8000000;
      iVar7 = DAT_0802fb04;
      if ((uVar6 & 0xffff) != 0xffff) {
        iVar7 = (DAT_0802fb00 & uVar6 << 9) + 0x8000000;
      }
    }
    if ((uVar4 & 3) == 1) {
      param_1[8] = iVar8 + (DAT_0802fb0c & puVar3[1] << 3);
      param_1[9] = iVar8 + (uVar5 & puVar3[2] << 3) + 7;
    }
    else if ((uVar4 & 3) == 2) {
      param_1[8] = iVar7 + (DAT_0802fb0c & puVar3[9] << 3);
      param_1[9] = iVar7 + (uVar5 & puVar3[10] << 3) + 7;
    }
    param_1[7] = uVar4 | puVar3[2] & 0x80000000;
  }
  return;
}



/* ===== FUN_0802fb10 @ 0802fb10 ===== */

void FUN_0802fb10(uint *param_1,uint param_2)

{
  *param_1 = *param_1 & ~param_2;
  return;
}



/* ===== FUN_0802fb1c @ 0802fb1c ===== */

uint FUN_0802fb1c(uint *param_1,uint *param_2,uint param_3)

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



/* ===== FUN_0802fb84 @ 0802fb84 ===== */

void FUN_0802fb84(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0802ce84();
                    /* WARNING: Could not recover jumptable at 0x0802fb96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0x20))(param_1);
  return;
}



/* ===== FUN_0802fb98 @ 0802fb98 ===== */

void FUN_0802fb98(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0802ce84();
                    /* WARNING: Could not recover jumptable at 0x0802fbaa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0x28))(param_1);
  return;
}



/* ===== FUN_0802fbac @ 0802fbac ===== */

undefined4 * FUN_0802fbac(undefined4 *param_1)

{
  param_1[1] = 0;
  param_1[2] = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  *param_1 = DAT_0802fbdc;
  FUN_0802aa70(param_1 + 4);
  param_1[0xd] = 0;
  FUN_0802aa70(param_1 + 4);
  *(undefined1 *)(param_1 + 0xf) = 0;
  return param_1;
}



/* ===== FUN_0802fbe0 @ 0802fbe0 ===== */

int FUN_0802fbe0(int param_1)

{
  FUN_0803158c(param_1 + 8);
  FUN_0802aa70(param_1 + 0x58);
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined1 *)(param_1 + 0x90) = 0;
  FUN_0802aa70(param_1 + 0x98);
  *(undefined4 *)(param_1 + 0xc0) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined1 *)(param_1 + 0xd0) = 0;
  FUN_0802aa70(param_1 + 0xd8);
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  *(undefined1 *)(param_1 + 0x110) = 0;
  FUN_0802af24(param_1);
  return param_1;
}



/* ===== FUN_0802fc3a @ 0802fc3a ===== */

int FUN_0802fc3a(int param_1,code *param_2,int param_3,int param_4)

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



/* ===== FUN_0802fd24 @ 0802fd24 ===== */

undefined8 FUN_0802fd24(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  
  uVar5 = param_2 & 0x80000000;
  if ((int)uVar5 < 0) {
    bVar6 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar6 - param_2;
  }
  if (param_2 == 0) {
    iVar4 = 0;
    iVar3 = 0;
    if (param_1 != 0) {
      uVar2 = param_1 << LZCOUNT(param_1);
      bVar6 = (uVar2 & 0x100) != 0;
      uVar1 = uVar2 * 0x1000000;
      iVar4 = (uVar1 + 0x80000000) - (uint)!bVar6;
      iVar3 = (uVar5 | (0x9d - LZCOUNT(param_1)) * 0x800000) +
              (uVar2 >> 8) + (uint)(0x80000000 < uVar1 || uVar1 + 0x80000000 < (uint)bVar6);
    }
    return CONCAT44(iVar4,iVar3);
  }
  uVar1 = param_1 << LZCOUNT(param_2);
  iVar4 = -LZCOUNT(param_2);
  uVar2 = iVar4 + 0x20U & 0x1f;
  uVar2 = ((param_2 ^ param_1) >> uVar2 | (param_2 ^ param_1) << 0x20 - uVar2) ^ uVar1;
  if (uVar1 != 0) {
    uVar2 = uVar2 | 1;
  }
  uVar5 = uVar5 | (iVar4 + 0xbd) * 0x800000;
  return CONCAT44(uVar5,uVar5 + (uVar2 >> 8) +
                                (uint)(0x80000000 < uVar2 * 0x1000000 ||
                                      uVar2 * 0x1000000 + 0x80000000 < (uint)((uVar2 & 0x100) != 0))
                 );
}



/* ===== FUN_0802fd7e @ 0802fd7e ===== */

void FUN_0802fd7e(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x38) = param_2;
  FUN_0802aa70();
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  return;
}



/* ===== FUN_0802fd94 @ 0802fd94 ===== */

undefined4 FUN_0802fd94(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint in_fpscr;
  
  iVar1 = param_1[6];
  if (param_1[7] != iVar1) {
    FUN_0802ab50(param_1[2],param_1[3]);
    VectorSignedToFloat(iVar1,(byte)(in_fpscr >> 0x16) & 3);
    return param_4;
  }
  if (*param_1 == 0) {
    return param_4;
  }
  VectorUnsignedToFloat(param_1[1],(byte)(in_fpscr >> 0x16) & 3);
  VectorUnsignedToFloat(*param_1,(byte)(in_fpscr >> 0x16) & 3);
  return param_4;
}



/* ===== FUN_0802fe30 @ 0802fe30 ===== */

undefined4 FUN_0802fe30(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x18);
  if (iVar2 < 1) {
    return 0;
  }
  uVar1 = FUN_08019bb0(iVar2 * 0x1f4000 + 0x7d,
                       ((iVar2 * 0xfa >> 0x1f) << 0xd | (uint)(iVar2 * 0xfa) >> 0x13) +
                       (uint)(0xffffff82 < (uint)(iVar2 * 0x1f4000)),0xfa,0);
  return uVar1;
}



/* ===== FUN_0802fe58 @ 0802fe58 ===== */

undefined * FUN_0802fe58(uint param_1)

{
  if (((param_1 & 3) == 0) &&
     (((int)(param_1 + 0x76c) % 100 != 0 || ((int)(param_1 + 0x76c) % 400 == 0)))) {
    return &DAT_0802fef4;
  }
  return &DAT_0802ff0c;
}



/* ===== FUN_0802fe8c @ 0802fe8c ===== */

int FUN_0802fe8c(uint param_1,int param_2)

{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  
  if ((int)param_1 < 0) {
    iVar3 = param_1 - 100;
    uVar1 = param_1;
  }
  else {
    iVar3 = param_1 + 299;
    uVar1 = param_1 - 1;
  }
  if (((param_1 & 3) == 0) &&
     (((int)(param_1 + 0x76c) % 100 != 0 || ((int)(param_1 + 0x76c) % 400 == 0)))) {
    puVar2 = &DAT_0802fef4;
  }
  else {
    puVar2 = &DAT_0802ff0c;
  }
  return (int)*(short *)(puVar2 + param_2 * 2) +
         iVar3 / 400 + (((int)(uVar1 + ((uint)((int)uVar1 >> 1) >> 0x1e)) >> 2) - (int)uVar1 / 100);
}



/* ===== FUN_0802ff24 @ 0802ff24 ===== */

/* WARNING: Removing unreachable block (ram,0x0802ff52) */

undefined4 *
FUN_0802ff24(undefined4 *param_1,undefined4 param_2,uint param_3,int param_4,undefined4 param_5)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint extraout_r2;
  short *psVar6;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  int extraout_r3;
  undefined4 extraout_r3_00;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  uVar9 = param_3 + DAT_08030074;
  iVar7 = param_4 + (uint)CARRY4(param_3,DAT_08030074);
  if (param_1 == (undefined4 *)0x0) {
    param_1 = DAT_08030078;
  }
  param_1[8] = param_5;
  iVar2 = FUN_08019bb0(uVar9,iVar7,DAT_0803007c,0,uVar9 + 0xe10,iVar7 + (uint)(0xfffff1ef < uVar9),
                       param_4);
  FUN_08019bb0(uVar9,iVar7,DAT_0803007c,0);
  iVar7 = extraout_r3;
  uVar9 = extraout_r2;
  if (extraout_r3 < 0) {
    iVar2 = iVar2 + -1;
    uVar9 = extraout_r2 + DAT_0803007c;
    iVar7 = extraout_r3 + (uint)CARRY4(extraout_r2,DAT_0803007c);
  }
  iVar3 = (iVar2 + 1) % 7;
  if (iVar3 < 0) {
    iVar3 = iVar3 + 7;
  }
  param_1[6] = iVar3;
  uVar8 = iVar2 / 0x16d;
  while( true ) {
    while( true ) {
      iVar3 = FUN_0802fe8c(uVar8,0);
      iVar3 = uVar8 * 0x16d + iVar3;
      if (iVar3 <= iVar2) break;
      uVar8 = uVar8 - 1;
    }
    if ((iVar2 <= iVar3 + 0x16d) ||
       ((iVar2 + -0x16e == iVar3 && (uVar8 & 3) == 0 &&
        (((int)(uVar8 + 0x76c) % 100 != 0 || ((int)(uVar8 + 0x76c) % 400 == 0)))))) break;
    uVar8 = uVar8 + 1;
  }
  iVar2 = iVar2 - iVar3;
  param_1[5] = uVar8;
  param_1[7] = iVar2;
  iVar3 = FUN_0802fe58();
  iVar5 = 0xc;
  psVar6 = (short *)(iVar3 + 0x18);
  do {
    psVar6 = psVar6 + -1;
    iVar5 = iVar5 + -1;
  } while (iVar2 < *psVar6);
  param_1[4] = iVar5;
  sVar1 = *(short *)(iVar3 + iVar5 * 2);
  uVar4 = FUN_08019bb0(uVar9,iVar7,0xe10,0);
  param_1[3] = (iVar2 - sVar1) + 1;
  param_1[2] = uVar4;
  FUN_08019bb0(uVar9,iVar7,0xe10,0);
  uVar4 = FUN_08019bb0(extraout_r2_00,extraout_r3_00,0x3c,0);
  param_1[1] = uVar4;
  FUN_08019bb0(extraout_r2_00,extraout_r3_00,0x3c,0);
  *param_1 = extraout_r2_01;
  if ((int)param_1[8] < 0) {
    param_1[8] = 0xffffffff;
  }
  return param_1;
}



/* ===== FUN_08030080 @ 08030080 ===== */

int FUN_08030080(code *param_1,int param_2,int *param_3,undefined4 *param_4,undefined1 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined8 uVar5;
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
  undefined1 *local_118;
  undefined *local_114 [60];
  
  iVar1 = DAT_0803023c;
  local_130 = 0;
  local_120 = param_5;
  local_118 = &LAB_08030260;
  local_158 = param_1;
  local_154 = param_2;
  do {
    iVar2 = FUN_080315be(param_3,&DAT_08030240);
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
    local_114[0] = &DAT_08030248;
    while (iVar2 = FUN_080315e4(&DAT_08030248,*param_3,5), iVar2 != 0) {
      param_3 = param_3 + 1;
      local_128 = local_128 |
                  (ushort)*(undefined4 *)((iVar2 - (int)local_114[0] & 0xfffffffcU) + 0x803027c);
    }
    if (*param_3 == 0x2a) {
      local_12c = *(int *)*param_4;
      *param_4 = (int *)*param_4 + 1;
      if (local_12c < 0) {
        local_12c = -local_12c;
        local_128 = local_128 | 4;
      }
      param_3 = param_3 + 1;
    }
    else {
      local_12c = 0;
      while (iVar2 = FUN_080315f8(*param_3), iVar2 != 0) {
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
        *param_4 = (int *)*param_4 + 1;
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
        while (iVar3 = FUN_080315f8(*param_3), iVar3 != 0) {
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
    uVar5 = FUN_08031600(local_118,*param_3);
    iVar2 = (int)((ulonglong)uVar5 >> 0x20);
    local_124 = 0;
    piVar4 = param_3;
    if ((int)uVar5 != 0) {
      piVar4 = param_3 + 1;
      local_124 = *param_3;
    }
    if (local_124 == 0x68) {
      if (*piVar4 == 0x68) {
        local_124 = 0x62;
LAB_0803020e:
        piVar4 = piVar4 + 1;
      }
    }
    else {
      if (local_124 == 0x6c) {
        iVar2 = *piVar4;
      }
      if (local_124 == 0x6c && iVar2 == 0x6c) {
        local_124 = 0x71;
        goto LAB_0803020e;
      }
    }
    param_3 = piVar4 + 1;
    iVar2 = FUN_08031614(auStack_160,param_4,*piVar4,local_114);
    if (iVar2 < 0) {
      return -1;
    }
    iVar2 = FUN_08031a18(auStack_160,local_114);
    if (iVar2 < 0) {
      return -1;
    }
  } while( true );
}



/* ===== FUN_08030294 @ 08030294 ===== */

uint FUN_08030294(uint param_1,uint param_2,byte param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)param_3;
  if (uVar2 < 0x20) {
    uVar1 = param_2 >> (uVar2 & 0x1f) | param_2 << 0x20 - (uVar2 & 0x1f);
    return param_1 >> uVar2 ^ uVar1 ^ (uVar1 << uVar2) >> uVar2;
  }
  return param_2 >> (uVar2 - 0x20 & 0xff);
}



/* ===== FUN_080302b4 @ 080302b4 ===== */

void FUN_080302b4(void)

{
  uint *puVar1;
  
  puVar1 = DAT_080302e0;
  *DAT_080302e0 = *DAT_080302e0 | 0x40000000;
  *DAT_080302e4 = *DAT_080302e4 & 0xfffffffe;
  *puVar1 = *puVar1 & 0xbfffffff;
  return;
}



/* ===== FUN_080302e8 @ 080302e8 ===== */

void FUN_080302e8(void)

{
  uint *puVar1;
  
  puVar1 = DAT_08030300;
  *DAT_08030300 = *DAT_08030300 & 0xfffffffe;
  puVar1[0xf] = puVar1[0xf] & 0xfffffff8 | 3;
  return;
}



/* ===== FUN_08030304 @ 08030304 ===== */

void FUN_08030304(void)

{
  uint *puVar1;
  
  puVar1 = DAT_08030330;
  *DAT_08030330 = *DAT_08030330 | 0x40000000;
  *DAT_08030334 = *DAT_08030334 | 1;
  *puVar1 = *puVar1 & 0xbfffffff;
  return;
}



/* ===== FUN_08030338 @ 08030338 ===== */

void FUN_08030338(void)

{
  uint *puVar1;
  
  puVar1 = DAT_08030350;
  DAT_08030350[0xf] = DAT_08030350[0xf] & 0xfffffff8 | 1;
  *puVar1 = *puVar1 | 1;
  return;
}



/* ===== FUN_08030354 @ 08030354 ===== */

void FUN_08030354(int param_1)

{
  FUN_08022b62(*(undefined4 *)(param_1 + 0x14));
  return;
}



/* ===== FUN_0803035c @ 0803035c ===== */

void FUN_0803035c(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  param_1[1] = 0;
  param_1[2] = 5;
  return;
}



/* ===== FUN_08030368 @ 08030368 ===== */

undefined8 FUN_08030368(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_08031bc8();
  FUN_080303aa(param_1 + 0x40c);
  FUN_080303aa(param_1 + 0x40c);
  return CONCAT44(param_4,param_1);
}



/* ===== FUN_08030384 @ 08030384 ===== */

void FUN_08030384(int *param_1)

{
  *param_1 = (int)param_1 + 0xe;
  param_1[2] = 0x41;
  param_1[1] = 0;
  param_1[2] = 0;
  *(undefined2 *)(param_1 + 3) = 0;
  return;
}



/* ===== FUN_08030398 @ 08030398 ===== */

void FUN_08030398(int *param_1)

{
  *param_1 = (int)(param_1 + 3);
  param_1[2] = 0x21;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



/* ===== FUN_080303aa @ 080303aa ===== */

void FUN_080303aa(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  FUN_08031bd4(param_1 + 4,0x1000);
  return;
}



/* ===== FUN_080303be @ 080303be ===== */

undefined8
FUN_080303be(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  FUN_08031bd4(param_1 + 0x34,0x1000);
  FUN_08031bd4(param_1 + 0x1034,0x1000);
  FUN_08031bd4(param_1 + 0x2034,0x1000);
  return CONCAT44(param_4,param_1);
}



/* ===== FUN_08030406 @ 08030406 ===== */

void FUN_08030406(char *param_1)

{
  if (*param_1 == '\0') {
    param_1[1] = '\0';
    param_1[0x10] = '\0';
    param_1[0x11] = '\0';
    param_1[0x12] = '\0';
    param_1[0x13] = '\0';
    param_1[4] = '\0';
    param_1[5] = '\0';
    param_1[6] = '\0';
    param_1[7] = '\0';
    param_1[8] = '\0';
    param_1[9] = '\0';
    param_1[10] = '\0';
    param_1[0xb] = '\0';
    param_1[0xc] = '\0';
    param_1[0xd] = '\0';
    param_1[0xe] = '\0';
    param_1[0xf] = '\0';
    FUN_08031bd4(param_1 + 0x14,0x1000);
    *param_1 = '\x01';
  }
  return;
}



/* ===== FUN_0803042c @ 0803042c ===== */

void FUN_0803042c(undefined1 *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int unaff_r5;
  int *piVar5;
  int unaff_r6;
  undefined1 auStack_40 [6];
  char local_3a;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  
  iVar3 = FUN_080304ea(0,auStack_40,param_1 + 0x34);
  if (iVar3 == 0) {
    if (local_3a == '\0') {
      *(undefined4 *)(param_1 + 0x18) = local_20;
      *(undefined4 *)(param_1 + 0x1c) = local_1c;
      *(undefined4 *)(param_1 + 0x10) = local_28;
      *(undefined4 *)(param_1 + 0x14) = local_24;
      *(undefined4 *)(param_1 + 8) = local_38;
      *(undefined4 *)(param_1 + 0xc) = local_34;
      unaff_r5 = local_18;
      unaff_r6 = local_14;
    }
    iVar3 = FUN_08031bda(param_1,param_1 + 0x34);
    *(int *)(param_1 + 0x28) = unaff_r5 + iVar3;
    piVar5 = (int *)(param_1 + 0x1034);
    iVar3 = FUN_08031bda(param_1,piVar5);
    *(int *)(param_1 + 0x2c) = unaff_r6 + iVar3;
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x18) + *(uint *)(param_1 + 0x10);
    *(uint *)(param_1 + 0x24) =
         *(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x1c) +
         (uint)CARRY4(*(uint *)(param_1 + 0x18),*(uint *)(param_1 + 0x10));
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x28) + *(int *)(param_1 + 0x2c);
    piVar1 = piVar5;
    piVar2 = (int *)(param_1 + 0x2034);
    for (piVar4 = (int *)(param_1 + 0x34); piVar4 < piVar5; piVar4 = piVar4 + 1) {
      *piVar2 = *piVar4 + *piVar1;
      piVar1 = piVar1 + 1;
      piVar2 = piVar2 + 1;
    }
  }
  else {
    FUN_08030e08(param_1);
  }
  *param_1 = 1;
  return;
}



/* ===== FUN_080304d8 @ 080304d8 ===== */

void FUN_080304d8(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_080306cc;
  if (0 < param_1) {
    do {
      *puVar1 = *param_2;
      param_1 = param_1 + -1;
      param_2 = param_2 + 1;
    } while (param_1 != 0);
  }
  return;
}



/* ===== FUN_080304ea @ 080304ea ===== */

undefined4 FUN_080304ea(int param_1,int *param_2,int param_3)

{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  
  if (param_1 == 0) {
    FUN_080270fa();
    iVar4 = FUN_08026d9e(DAT_080306d0,0x30,param_2);
    FUN_08027126();
    if (iVar4 != 0) {
      return 2;
    }
    if (*(char *)((int)param_2 + 6) == '\0') {
      if (*(ushort *)(param_2 + 1) < 0x3f5) {
        FUN_080270fa();
        iVar4 = FUN_08026d9e(DAT_080306d8,(uint)*(ushort *)(param_2 + 1) << 2,DAT_080306d4);
        uVar7 = 0;
        if ((iVar4 != 0) ||
           (iVar4 = FUN_08026d9e(DAT_080306dc,0x1000,param_3 + 0x1000), bVar1 = false, iVar4 != 0))
        {
          uVar7 = 2;
          bVar1 = true;
        }
        FUN_08027126();
        if (!bVar1) {
          FUN_08031bf0();
          piVar2 = DAT_080306cc;
          *DAT_080306cc = param_2[1];
          iVar4 = 5;
          piVar5 = param_2;
          do {
            *piVar2 = piVar5[2];
            iVar4 = iVar4 + -1;
            *piVar2 = piVar5[3];
            uVar3 = DAT_080306d4;
            piVar5 = piVar5 + 2;
          } while (iVar4 != 0);
          FUN_080304d8((short)param_2[1],DAT_080306d4);
          piVar5 = (int *)(param_3 + 0x1000);
          iVar4 = 0x100;
          do {
            *piVar2 = *piVar5;
            iVar4 = iVar4 + -1;
            *piVar2 = piVar5[1];
            piVar6 = piVar5 + 3;
            *piVar2 = piVar5[2];
            piVar5 = piVar5 + 4;
            *piVar2 = *piVar6;
          } while (iVar4 != 0);
          iVar4 = *piVar2;
          if (iVar4 == -1) {
            iVar4 = 0;
          }
          if (iVar4 == *param_2) {
            iVar4 = FUN_08030d30(param_3,uVar3,0x400);
            if (iVar4 < 0) {
              uVar7 = 0x1a;
            }
          }
          else {
            uVar7 = 0x19;
          }
        }
      }
      else {
        uVar7 = 0x17;
      }
      return uVar7;
    }
  }
  return 0x18;
}



/* ===== FUN_080305d8 @ 080305d8 ===== */

undefined8 FUN_080305d8(uint param_1,int *param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  bool bVar8;
  
  iVar4 = DAT_080306d4;
  bVar8 = param_1 == 0;
  if (bVar8) {
    param_1 = (uint)*(byte *)((int)param_2 + 6);
  }
  if (!bVar8 || param_1 != 0) {
    return CONCAT44(param_4,0x17);
  }
  iVar3 = FUN_08030cc0(DAT_080306d4,param_3,0x400);
  if (iVar3 == 0) {
    iVar3 = 0x17;
  }
  else {
    uVar6 = (iVar3 - iVar4) + 3 >> 2;
    if (uVar6 < 0x3f5) {
      *(short *)(param_2 + 1) = (short)uVar6;
      FUN_080270fa();
      uVar2 = DAT_080306d0;
      iVar3 = FUN_08026fa2(DAT_080306d0);
      if ((iVar3 == 0) && (iVar3 = FUN_08026e02(DAT_080306d8,uVar6 << 2,iVar4), iVar3 == 0)) {
        piVar7 = (int *)(param_3 + 0x1000);
        iVar3 = FUN_08026e02(DAT_080306dc,0x1000,piVar7);
        if ((iVar3 == 0) && (iVar3 = FUN_08026eaa(DAT_080306e0,0x2c,param_2 + 1), iVar3 == 0)) {
          FUN_08031bf0();
          piVar1 = DAT_080306cc;
          *DAT_080306cc = param_2[1];
          iVar3 = 5;
          piVar5 = param_2;
          do {
            *piVar1 = piVar5[2];
            iVar3 = iVar3 + -1;
            *piVar1 = piVar5[3];
            piVar5 = piVar5 + 2;
          } while (iVar3 != 0);
          FUN_080304d8(uVar6,iVar4);
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
          iVar3 = FUN_08026eaa(uVar2,4,param_2);
        }
      }
      FUN_08027126();
    }
    else {
      iVar3 = 4;
    }
  }
  return CONCAT44(param_4,iVar3);
}



/* ===== FUN_080306e4 @ 080306e4 ===== */

void FUN_080306e4(int param_1,undefined2 param_2,undefined4 param_3)

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



/* ===== FUN_08030702 @ 08030702 ===== */

undefined4 * FUN_08030702(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = param_2 + 3;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  puVar1 = param_2;
  if (param_2 < (undefined4 *)0xfffffff4) {
    do {
      param_2 = puVar1 + 1;
      FUN_08031c28(param_1,*puVar1);
      puVar1 = param_2;
    } while (param_2 < puVar2);
  }
  return param_2;
}



/* ===== FUN_08030724 @ 08030724 ===== */

undefined4 FUN_08030724(int param_1)

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
      if (bVar5 <= bVar1) {
        bVar5 = bVar1;
      }
      bVar1 = (byte)*(undefined2 *)(param_1 + 0x10);
      if ((bVar1 != 5) && (bVar5 <= bVar1)) {
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
      if (uVar4 <= uVar2) {
        uVar4 = uVar2;
      }
      uVar2 = *(ushort *)(param_1 + 0x10) >> 8;
      if ((uVar2 != 5) && (uVar4 <= uVar2)) {
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



/* ===== FUN_080307a8 @ 080307a8 ===== */

uint FUN_080307a8(int param_1)

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



/* ===== FUN_080307ca @ 080307ca ===== */

undefined4 FUN_080307ca(int param_1)

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



/* ===== FUN_080307ee @ 080307ee ===== */

undefined4 FUN_080307ee(int param_1)

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



/* ===== FUN_08030820 @ 08030820 ===== */

undefined4 FUN_08030820(int param_1)

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



/* ===== FUN_08030852 @ 08030852 ===== */

undefined4 FUN_08030852(int param_1)

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



/* ===== FUN_08030886 @ 08030886 ===== */

void FUN_08030886(undefined4 *param_1,int param_2)

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
      FUN_080306e4(param_1,0x505,0);
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
  *puVar5 = ((*puVar5 >> 4) - (short)iVar1) * 0x10;
  *param_1 = puVar5 + 1;
  param_1[1] = puVar7;
  return;
}



/* ===== FUN_08030930 @ 08030930 ===== */

void FUN_08030930(undefined4 *param_1,int param_2)

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
      FUN_080306e4(param_1,0x505,0);
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
    iVar6 = FUN_080307a8(param_1);
    param_2 = iVar1;
    puVar7 = puVar8;
  } while (iVar6 == 0);
  *puVar5 = ((*puVar5 >> 4) - (short)iVar1) * 0x10 | 1;
  *param_1 = puVar8;
  param_1[1] = puVar9;
  return;
}



/* ===== FUN_080309e2 @ 080309e2 ===== */

void FUN_080309e2(undefined4 *param_1,int param_2)

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
    iVar1 = param_2 + -1;
    puVar8 = (ushort *)((int)puVar7 + 1);
    *(char *)puVar7 = (char)param_1[5] - (char)param_1[2];
    if (param_2 < 4) {
      FUN_080306e4(param_1,0x505,0);
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
    iVar6 = FUN_080307ca(param_1);
    param_2 = iVar1;
    puVar7 = puVar8;
  } while (iVar6 == 0);
  *puVar5 = ((*puVar5 >> 4) - (short)iVar1) * 0x10 | 2;
  *param_1 = puVar8;
  param_1[1] = puVar9;
  return;
}



/* ===== FUN_08030aa0 @ 08030aa0 ===== */

void FUN_08030aa0(undefined4 *param_1,int param_2)

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
    iVar1 = param_2 + -1;
    puVar8 = puVar7 + 1;
    *puVar7 = (short)param_1[5] - (short)param_1[2];
    if (param_2 < 4) {
      FUN_080306e4(param_1,0x505,0);
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
    iVar6 = FUN_080307ee(param_1);
    param_2 = iVar1;
    puVar7 = puVar8;
  } while (iVar6 == 0);
  *puVar5 = ((*puVar5 >> 4) - (short)iVar1) * 0x10 | 3;
  *param_1 = puVar8;
  param_1[1] = puVar9;
  return;
}



/* ===== FUN_08030b56 @ 08030b56 ===== */

void FUN_08030b56(undefined4 *param_1,int param_2)

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
    iVar1 = param_2 + -1;
    puVar8 = (ushort *)((int)puVar7 + 3);
    *(undefined4 *)puVar7 = param_1[5] - param_1[2];
    if (param_2 < 4) {
      FUN_080306e4(param_1,0x505,0);
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
    iVar6 = FUN_08030820(param_1);
    param_2 = iVar1;
    puVar7 = puVar8;
  } while (iVar6 == 0);
  *puVar5 = ((*puVar5 >> 4) - (short)iVar1) * 0x10 | 4;
  *param_1 = puVar8;
  param_1[1] = puVar9;
  return;
}



/* ===== FUN_08030c0c @ 08030c0c ===== */

void FUN_08030c0c(undefined4 *param_1,int param_2)

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
      FUN_080306e4(param_1,0x505,0);
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
    iVar6 = FUN_08030852(param_1);
    param_2 = iVar1;
    puVar7 = puVar8;
  } while (iVar6 == 0);
  *puVar5 = ((*puVar5 >> 4) - (short)iVar1) * 0x10 | 5;
  *param_1 = puVar8;
  param_1[1] = puVar9;
  return;
}



/* ===== FUN_08030cc0 @ 08030cc0 ===== */

longlong FUN_08030cc0(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_08030df4;
  *DAT_08030df4 = param_1;
  uVar2 = FUN_08030702(puVar1);
  puVar1[1] = uVar2;
  do {
    uVar2 = FUN_08030724(puVar1);
    switch(uVar2) {
    case 0:
      param_3 = FUN_08030886(puVar1,param_3);
      break;
    case 1:
      param_3 = FUN_08030930(puVar1,param_3);
      break;
    case 2:
      param_3 = FUN_080309e2(puVar1,param_3);
      break;
    case 3:
      param_3 = FUN_08030aa0(puVar1,param_3);
      break;
    case 4:
      param_3 = FUN_08030b56(puVar1,param_3);
      break;
    case 5:
      param_3 = FUN_08030c0c(puVar1,param_3);
      break;
    case 6:
      return CONCAT44(param_4,*puVar1);
    default:
      return (ulonglong)param_4 << 0x20;
    }
  } while( true );
}



/* ===== FUN_08030d30 @ 08030d30 ===== */

undefined4 FUN_08030d30(uint *param_1,uint *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  
  uVar5 = 0;
  do {
    iVar1 = DAT_08030df8;
    if (param_3 < 1) {
      *(uint *)(DAT_08030df8 + 4) = uVar5;
      *(uint **)(iVar1 + 8) = param_2;
      return 0;
    }
    puVar4 = (uint *)((int)param_2 + 2);
    uVar2 = (uint)(ushort)((ushort)*param_2 >> 4);
    if ((uVar2 == 0) || (param_3 = param_3 - uVar2, param_3 < 0)) break;
    puVar3 = param_1 + uVar2;
    switch((ushort)*param_2 & 0xf) {
    case 0:
      for (; param_1 < puVar3; param_1 = param_1 + 1) {
        *param_1 = 0;
      }
      uVar5 = 0;
      break;
    case 1:
      for (; param_1 < puVar3; param_1 = param_1 + 1) {
        uVar5 = (uint)(byte)*puVar4;
        *param_1 = uVar5;
        puVar4 = (uint *)((int)puVar4 + 1);
      }
      break;
    case 2:
      for (; param_1 < puVar3; param_1 = param_1 + 1) {
        uVar5 = (int)(char)*puVar4 + uVar5;
        *param_1 = uVar5;
        puVar4 = (uint *)((int)puVar4 + 1);
      }
      break;
    case 3:
      for (; param_1 < puVar3; param_1 = param_1 + 1) {
        uVar5 = (int)(short)(ushort)*puVar4 + uVar5;
        *param_1 = uVar5;
        puVar4 = (uint *)((int)puVar4 + 2);
      }
      break;
    case 4:
      for (; param_1 < puVar3; param_1 = param_1 + 1) {
        uVar5 = (int)(int3)*puVar4 + uVar5;
        puVar4 = (uint *)((int)puVar4 + 3);
        *param_1 = uVar5;
      }
      break;
    case 5:
      for (; param_1 < puVar3; param_1 = param_1 + 1) {
        uVar5 = *puVar4;
        *param_1 = uVar5;
        puVar4 = puVar4 + 1;
      }
      break;
    default:
      goto switchD_08030d54_default;
    }
    param_2 = puVar4;
  } while (param_1 == puVar3);
switchD_08030d54_default:
  iVar1 = DAT_08030df8;
  *(uint *)(DAT_08030df8 + 4) = uVar5;
  *(uint **)(iVar1 + 8) = puVar4;
  return 0xffffffff;
}



/* ===== FUN_08030e08 @ 08030e08 ===== */

void FUN_08030e08(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  bool bVar10;
  
  disableIRQinterrupts();
  uVar4 = *DAT_08030ea0;
  uVar5 = DAT_08030ea0[1];
  enableIRQinterrupts();
  bVar9 = (int)uVar5 < 0;
  if (bVar9) {
    bVar10 = uVar4 != 0;
    uVar4 = -uVar4;
    uVar5 = -uVar5 - (uint)bVar10;
  }
  uVar8 = (uint)((ulonglong)uVar4 * 0x7d);
  iVar6 = uVar5 * 0x7d + (int)((ulonglong)uVar4 * 0x7d >> 0x20) + (uint)(0xfffff7ff < uVar8);
  uVar4 = uVar8 + 0x800 >> 0xc | iVar6 * 0x100000;
  iVar6 = iVar6 >> 0xc;
  if (bVar9) {
    bVar9 = uVar4 != 0;
    uVar4 = -uVar4;
    iVar6 = -iVar6 - (uint)bVar9;
  }
  *(uint *)(param_1 + 8) = uVar4;
  *(int *)(param_1 + 0xc) = iVar6;
  iVar6 = *(uint *)(param_1 + 0x18) + *(uint *)(param_1 + 0x10);
  iVar7 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x14) +
          (uint)CARRY4(*(uint *)(param_1 + 0x18),*(uint *)(param_1 + 0x10));
  *(int *)(param_1 + 0x18) = iVar6;
  *(int *)(param_1 + 0x1c) = iVar7;
  *(int *)(param_1 + 0x20) = iVar6;
  *(int *)(param_1 + 0x24) = iVar7;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  iVar6 = *(int *)(param_1 + 0x28);
  *(undefined4 *)(param_1 + 0x28) = 0;
  iVar6 = iVar6 + *(int *)(param_1 + 0x2c);
  *(int *)(param_1 + 0x2c) = iVar6;
  *(int *)(param_1 + 0x30) = iVar6;
  piVar1 = (int *)(param_1 + 0x1034);
  piVar2 = (int *)(param_1 + 0x2034);
  for (piVar3 = (int *)(param_1 + 0x34); piVar3 < (int *)(param_1 + 0x1034); piVar3 = piVar3 + 1) {
    iVar7 = *piVar1;
    iVar6 = *piVar3;
    *piVar1 = iVar6 + iVar7;
    *piVar2 = iVar6 + iVar7;
    *piVar3 = 0;
    piVar1 = piVar1 + 1;
    piVar2 = piVar2 + 1;
  }
  return;
}



/* ===== FUN_08030ea4 @ 08030ea4 ===== */

float FUN_08030ea4(float param_1)

{
  uint uVar1;
  uint in_fpscr;
  float fVar2;
  float fVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar2 = *(float *)(DAT_08030ed4 + 0x8030eae);
  fVar3 = *(float *)(DAT_08030ed4 + 0x8030eb2);
  fVar7 = *(float *)((int)&DAT_08030ed4 + DAT_08030ed4 + 2);
  if (*(uint *)(DAT_08030ed4 + 0x8030eea) < (uint)((int)param_1 << 1)) {
    if ((uint)((int)param_1 * 2) < 0xff000000) {
      return param_1;
    }
    if (((uint)((int)param_1 * 2) < 0xff000001) && (CARRY4((uint)param_1,(uint)param_1))) {
      param_1 = 0.0;
    }
    return param_1;
  }
  if (param_1 == 0.0) {
    return param_1;
  }
  if ((int)param_1 < 0) {
    fVar3 = -fVar3;
  }
  uVar4 = (uint)(fVar3 + param_1 * *(float *)(DAT_08030ed4 + 0x8030eb6));
  fVar3 = (float)VectorSignedToFloat(uVar4,(byte)((in_fpscr & 0xfffffff) >> 0x16) & 3);
  fVar3 = (param_1 - fVar3 * *(float *)(DAT_08030ed4 + 0x8030ebe)) -
          fVar3 * *(float *)(DAT_08030ed4 + 0x8030ec2);
  uVar1 = uVar4 + 0x7f;
  if (*(float *)(DAT_08030ed4 + 0x8030ec6) <= ABS(fVar3)) {
    fVar5 = fVar3 * fVar3 * *(float *)(DAT_08030ed4 + 0x8030eca);
    fVar6 = *(float *)(&UNK_08030ed2 + DAT_08030ed4) +
            fVar3 * fVar3 * *(float *)(DAT_08030ed4 + 0x8030ece);
    fVar2 = fVar2 * ((fVar5 + fVar3 * fVar6 + fVar7) / ((fVar5 - fVar3 * fVar6) + fVar7));
  }
  if (uVar1 != 0) {
    fVar3 = (float)(uVar1 * 0x800000);
    if (uVar1 < 0xff) goto LAB_08031cee;
    if (0 < (int)uVar1) {
      fVar3 = *(float *)(DAT_08030ed4 + 0x8030eba);
      if (uVar4 < 0xff) {
        fVar2 = fVar2 * *(float *)(DAT_08030ed4 + 0x8030eda);
        fVar3 = (float)(uVar4 * 0x800000);
      }
      goto LAB_08031cee;
    }
  }
  fVar3 = (float)((uVar4 + 0xfd) * 0x800000);
  if ((int)(uVar4 + 0xfd) < 1) {
    fVar3 = fVar2 - fVar2;
  }
  else {
    fVar2 = fVar2 * *(float *)(DAT_08030ed4 + 0x8030ede);
  }
LAB_08031cee:
  return fVar3 * fVar2;
}



/* ===== FUN_08030f04 @ 08030f04 ===== */

void FUN_08030f04(undefined4 *param_1,int param_2,float *param_3)

{
  uint uVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  float *pfVar9;
  int iVar10;
  int iVar11;
  uint in_fpscr;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  
  pfVar8 = DAT_08031034;
  iVar10 = 1;
  pfVar6 = (float *)0x0;
  *param_1 = 0;
  fVar12 = DAT_08031030;
  pfVar9 = pfVar8 + 2;
  puVar3 = param_1 + 1;
  puVar4 = param_1 + 1;
  if (0 < param_2) {
    do {
      fVar13 = (float)VectorSignedToFloat(iVar10,(byte)(in_fpscr >> 0x16) & 3);
      fVar13 = *param_3 + fVar13 * (param_3[1] + fVar13 * param_3[2]);
      uVar1 = in_fpscr & 0xfffffff | (uint)(fVar13 < 0.0) << 0x1f | (uint)(fVar13 == 0.0) << 0x1e;
      in_fpscr = uVar1 | (uint)NAN(fVar13) << 0x1c;
      bVar2 = (byte)(uVar1 >> 0x18);
      puVar4 = puVar3;
      if (!(bool)(bVar2 >> 6 & 1) && bVar2 >> 7 == ((byte)(in_fpscr >> 0x1c) & 1)) break;
      iVar10 = iVar10 + 1;
      puVar4 = puVar3 + 1;
      *puVar3 = 0;
      puVar3 = puVar4;
    } while (iVar10 <= param_2);
  }
  pfVar5 = (float *)(puVar4 + -1);
  if (iVar10 <= param_2) {
    iVar11 = iVar10 * 2 + -1;
    pfVar7 = pfVar8 + 0x36;
    fVar13 = fVar12;
    fVar18 = fVar12;
    do {
      fVar15 = (float)VectorSignedToFloat(iVar10,(byte)(in_fpscr >> 0x16) & 3);
      fVar14 = *param_3 + fVar15 * (param_3[1] + fVar15 * param_3[2]);
      fVar15 = DAT_08031030;
      while( true ) {
        fVar16 = *pfVar9;
        fVar17 = pfVar9[1];
        if (pfVar6 != pfVar8) {
          fVar18 = (fVar17 - pfVar8[1]) / (fVar16 - *pfVar8);
          fVar12 = pfVar8[1] - fVar18 * *pfVar8;
          pfVar6 = pfVar8;
        }
        if ((fVar16 < fVar13) || (fVar14 < fVar16)) {
          fVar17 = fVar12 + fVar18 * fVar14;
          fVar16 = fVar14;
        }
        uVar1 = in_fpscr & 0xfffffff | (uint)(fVar16 < fVar14) << 0x1f;
        in_fpscr = uVar1 | (uint)(NAN(fVar16) || NAN(fVar14)) << 0x1c;
        fVar15 = fVar15 + (fVar17 + fVar12 + fVar18 * fVar13) * (fVar16 - fVar13);
        if ((byte)(uVar1 >> 0x1f) == ((byte)(in_fpscr >> 0x1c) & 1)) break;
        fVar13 = fVar16;
        if (pfVar9 < pfVar7) {
          pfVar8 = pfVar9;
          pfVar9 = pfVar9 + 2;
        }
      }
      fVar13 = (float)VectorSignedToFloat(iVar11,(byte)(in_fpscr >> 0x16) & 3);
      *pfVar5 = fVar15 / ((param_3[1] + fVar13 * param_3[2]) * 2.0);
      pfVar5 = pfVar5 + 1;
      iVar10 = iVar10 + 1;
      iVar11 = iVar11 + 2;
      fVar13 = fVar14;
    } while (iVar10 <= param_2);
  }
  return;
}



/* ===== FUN_08031038 @ 08031038 ===== */

undefined4 FUN_08031038(int *param_1)

{
  char *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  uint in_fpscr;
  float fVar9;
  float fVar10;
  
  if (param_1[3] < 1) {
    return 0;
  }
  disableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  iVar3 = param_1[2] - param_1[3];
  iVar4 = iVar3 + 1;
  if (iVar4 < 0) {
    iVar4 = iVar3 + 5;
  }
  enableIRQinterrupts();
  pcVar5 = (char *)(param_1[1] + iVar4 * 0x2c);
  if (*pcVar5 == '\0') {
    return 0;
  }
  pcVar1 = (char *)FUN_0802e5a4(pcVar5);
  piVar6 = param_1 + 0x50c;
  if (pcVar5[1] != '\0') {
    if ((pcVar1 != (char *)0x0) && (*pcVar1 == '\0')) {
      pcVar1[1] = '\0';
      pcVar1[0x10] = '\0';
      pcVar1[0x11] = '\0';
      pcVar1[0x12] = '\0';
      pcVar1[0x13] = '\0';
      pcVar1[4] = '\0';
      pcVar1[5] = '\0';
      pcVar1[6] = '\0';
      pcVar1[7] = '\0';
      pcVar1[8] = '\0';
      pcVar1[9] = '\0';
      pcVar1[10] = '\0';
      pcVar1[0xb] = '\0';
      pcVar1[0xc] = '\0';
      pcVar1[0xd] = '\0';
      pcVar1[0xe] = '\0';
      pcVar1[0xf] = '\0';
      FUN_08031bd4(pcVar1 + 0x14,0x1000);
      *pcVar1 = '\x01';
    }
    *param_1 = 0;
    FUN_080303aa(param_1 + 0x108);
    param_1[0x513] = 0;
    param_1[0x617] = 0;
    FUN_0802e18c();
    goto switchD_0803110c_default;
  }
  *param_1 = *param_1 + 5;
  uVar7 = (uint)(byte)pcVar5[5];
  switch(uVar7) {
  case 0:
    FUN_08031d64(param_1 + 0x511,0,pcVar5,500,0);
    break;
  case 1:
    if (pcVar1 != (char *)0x0) {
      piVar8 = param_1 + 0x108;
      FUN_0802dc06(pcVar1,piVar8);
      FUN_0802e1b8(piVar8);
      iVar4 = *piVar8;
      iVar3 = param_1[0x10a];
      fVar9 = (float)VectorSignedToFloat(iVar4,(byte)(in_fpscr >> 0x16) & 3);
      fVar10 = (float)VectorUnsignedToFloat(param_1[0x109],(byte)(in_fpscr >> 0x16) & 3);
      FUN_08031dfc(fVar9 / (fVar9 + fVar10 * DAT_0803123c),param_1 + 5,param_1 + 0x10c);
      param_1[0x50e] = iVar3;
      *(undefined1 *)((int)param_1 + 0x1431) = 0;
      *(char *)piVar6 = '\x01';
      param_1[0x50d] = iVar4;
      param_1[0x50f] = param_1[6];
      param_1[0x510] = param_1[7];
      FUN_080303aa(piVar8);
    }
    break;
  case 2:
  case 3:
  case 4:
    if ((2 < uVar7 - 2) || (puVar2 = *(undefined4 **)(pcVar5 + 0x14), puVar2 == (undefined4 *)0x0))
    break;
    fVar9 = (float)VectorSignedToFloat(puVar2[1],(byte)(in_fpscr >> 0x16) & 3);
    FUN_08031d64(param_1 + 0x511,uVar7,pcVar5,(int)(fVar9 * DAT_08031240 + 0.5),*puVar2);
    if (uVar7 != 2) break;
    fVar9 = *(float *)(pcVar5 + 0x10) * DAT_08031244;
    if (param_1[0x617] < 0x20) {
      param_1[0x617] = param_1[0x617] + 1;
    }
    iVar3 = param_1[0x616] + 1;
    if (0x1f < iVar3) {
      iVar3 = 0;
    }
    param_1[0x616] = iVar3;
    fVar10 = DAT_08031248;
    *(float *)(param_1[0x615] + param_1[0x616] * 4) = fVar9;
    fVar9 = *(float *)(pcVar5 + 0x10);
    *(undefined1 *)((int)param_1 + 0x1431) = 1;
    param_1[0x50d] = 500;
    param_1[0x50e] = 0;
    param_1[0x50f] = (int)(fVar9 * fVar10);
    param_1[0x510] = 0;
    *(char *)piVar6 = '\x01';
    goto LAB_080310ce;
  }
switchD_0803110c_default:
  if ((char)*piVar6 != '\0') {
LAB_080310ce:
    FUN_0801b094(piVar6);
  }
  *pcVar5 = '\0';
  disableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  param_1[3] = param_1[3] + -1;
  enableIRQinterrupts();
  *(short *)(param_1 + 0x514) = (short)param_1[0x514] + 1;
  return 1;
}



/* ===== FUN_0803124c @ 0803124c ===== */

void FUN_0803124c(undefined1 *param_1)

{
  FUN_08031ecc(param_1 + 4);
  FUN_08031ecc(param_1 + 0x18);
  *param_1 = 0;
  param_1[1] = 0;
  return;
}



/* ===== FUN_08031268 @ 08031268 ===== */

void FUN_08031268(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0802b51e(DAT_0803127c,0xd4,param_2,param_3,param_4);
  return;
}



/* ===== FUN_08031280 @ 08031280 ===== */

void FUN_08031280(int param_1,int param_2)

{
  if (*(char *)(param_1 + 4) < '\x01') {
    *(byte *)(param_1 + 4) = (byte)~(byte)(-(uint)(param_2 == 0) >> 0x18) >> 7;
  }
  return;
}



/* ===== FUN_08031294 @ 08031294 ===== */

void FUN_08031294(void)

{
  do {
    software_bkpt(0xab);
  } while( true );
}



/* ===== FUN_080312a8 @ 080312a8 ===== */

int FUN_080312a8(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  short local_40 [20];
  undefined4 uStack_18;
  
  iVar1 = 0;
  uStack_18 = param_4;
  do {
    iVar2 = iVar1;
    FUN_08026d9e(param_2,0x28,local_40);
    if (local_40[0] == -1) {
      *(uint *)(param_1 + 4) = param_2;
      return iVar2;
    }
    if (*(uint *)(param_1 + 8) < 0x2000000) {
LAB_080312d6:
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 0x28;
    }
    else if (local_40[0] == 0xa5) {
      *(uint *)(param_1 + 8) = param_2;
      goto LAB_080312d6;
    }
    param_2 = param_2 + 0x28;
    if (((param_2 & 0xfff) == 0) || (iVar1 = iVar2 + 0x28, 0x1000 - (param_2 & 0xfff) < 0x28)) {
      return iVar2 + 0x38;
    }
  } while( true );
}



/* ===== FUN_08031300 @ 08031300 ===== */

void FUN_08031300(uint param_1,uint param_2,uint param_3,uint param_4,int param_5,uint param_6,
                 uint param_7)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  char cVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  byte bVar12;
  uint uVar13;
  uint uVar14;
  byte bVar15;
  byte bVar16;
  byte bVar17;
  byte bVar18;
  byte bVar19;
  byte bVar20;
  byte bVar21;
  uint uVar22;
  
  pbVar7 = DAT_08031570;
  pbVar6 = DAT_0803156c;
  uVar13 = param_4;
  uVar11 = param_3;
  if (param_5 != 0) {
    uVar13 = param_6 & 0xff;
    uVar11 = param_6;
  }
  if (param_5 == 0 || uVar13 == 0) {
    return;
  }
  bVar3 = (byte)param_1;
  if ((uint)*DAT_08031570 < (uint)*DAT_0803156c) {
    *DAT_0803156c = bVar3;
LAB_08031340:
    *pbVar7 = bVar3;
  }
  else if ((int)param_1 < (int)(uint)*DAT_0803156c) {
    *DAT_0803156c = bVar3;
  }
  else if ((int)(uint)*DAT_08031570 < (int)param_1) goto LAB_08031340;
  pbVar9 = DAT_08031578;
  pbVar8 = DAT_08031574;
  bVar3 = (byte)param_2;
  if ((uint)*DAT_08031578 < (uint)*DAT_08031574) {
    *DAT_08031574 = bVar3;
LAB_08031368:
    *pbVar9 = bVar3;
  }
  else if ((int)param_2 < (int)(uint)*DAT_08031574) {
    *DAT_08031574 = bVar3;
  }
  else if ((int)(uint)*DAT_08031578 < (int)param_2) goto LAB_08031368;
  bVar3 = (byte)param_3;
  if ((uint)*pbVar7 < (uint)*pbVar6) {
    *pbVar6 = bVar3;
LAB_0803138e:
    *pbVar7 = bVar3;
  }
  else if ((int)param_3 < (int)(uint)*pbVar6) {
    *pbVar6 = bVar3;
  }
  else if ((int)(uint)*pbVar7 < (int)param_3) goto LAB_0803138e;
  bVar4 = (byte)param_4;
  if ((uint)*pbVar9 < (uint)*pbVar8) {
    *pbVar8 = bVar4;
  }
  else {
    if ((int)param_4 < (int)(uint)*pbVar8) {
      *pbVar8 = bVar4;
      goto LAB_080313bc;
    }
    if ((int)param_4 <= (int)(uint)*pbVar9) goto LAB_080313bc;
  }
  *pbVar9 = bVar4;
LAB_080313bc:
  bVar15 = *(byte *)(DAT_08031580 + (param_2 & 7));
  bVar1 = *(byte *)(DAT_0803157c + (param_4 & 7));
  bVar19 = 0;
  while ((param_2 & 0xff) <= (param_4 & 0xff)) {
    if ((param_2 & 0xf8) == (param_4 & 0xf8)) {
      bVar15 = bVar15 & bVar1;
    }
    bVar2 = *(byte *)(DAT_08031584 + (param_2 & 7));
    uVar22 = 0;
    uVar10 = param_2;
    uVar13 = param_1;
    do {
      uVar14 = uVar10;
      cVar5 = (char)uVar13;
      bVar16 = bVar3 - cVar5;
      uVar13 = ((param_2 & 0xff) >> 3) * 0x80 + uVar13;
      uVar10 = 0x80;
      bVar18 = bVar16;
      if (7 < bVar16) {
        bVar18 = 7;
      }
      param_6 = uVar11 & 0xff;
      while( true ) {
        uVar13 = uVar13 & 0xffff;
        bVar12 = 0;
        bVar21 = bVar19;
        bVar17 = bVar2;
        bVar20 = (byte)uVar14;
        do {
          if ((*(byte *)(param_5 + param_6 * bVar21 + uVar22) & uVar10) != 0) {
            bVar12 = bVar12 | bVar17;
          }
          bVar17 = bVar17 << 1;
          bVar21 = bVar21 + 1;
          bVar20 = bVar20 + 1;
        } while ((bVar17 != 0) && (bVar20 <= bVar4));
        if (((param_7 & 0xff) >> 6 & 1) == 0) {
          if ((param_7 & 0x80) != 0) {
            bVar12 = bVar12 ^ 0xff;
          }
          if (bVar15 != 0xff) {
            bVar12 = bVar12 & bVar15 | *(byte *)(DAT_08031588 + uVar13) & ~bVar15;
          }
        }
        else if ((param_7 & 0x80) == 0) {
          bVar12 = bVar12 & bVar15 | *(byte *)(DAT_08031588 + uVar13);
        }
        else {
          bVar12 = (bVar12 ^ 0xff | ~bVar15) & *(byte *)(DAT_08031588 + uVar13);
        }
        *(byte *)(DAT_08031588 + uVar13) = bVar12;
        uVar10 = uVar10 >> 1;
        uVar13 = uVar13 + 1;
        if (bVar18 == 0) break;
        bVar18 = bVar18 - 1;
      }
      uVar11 = uVar11 & 0xff;
      if (bVar16 < 8) {
        bVar16 = cVar5 + bVar16 + 1;
      }
      else {
        bVar16 = cVar5 + 8;
      }
      uVar22 = uVar22 + 1 & 0xff;
      uVar13 = (uint)bVar16;
      uVar10 = uVar14 & 0xff;
    } while ((int)uVar13 <= (int)param_3);
    bVar15 = 0xff;
    bVar19 = bVar21;
    param_2 = (uVar14 & 0xf8) + 8;
  }
  return;
}



/* ===== FUN_0803158c @ 0803158c ===== */

int FUN_0803158c(int param_1)

{
  FUN_0802aa70();
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  FUN_0802fd7e(param_1);
  *(undefined1 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x40) = 0xc0;
  *(undefined4 *)(param_1 + 0x48) = 0xc0;
  return param_1;
}



/* ===== FUN_080315be @ 080315be ===== */

int FUN_080315be(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  for (piVar1 = param_1; *piVar1 != 0; piVar1 = piVar1 + 1) {
    piVar2 = param_2;
    while (*piVar2 != 0) {
      iVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      if (*piVar1 == iVar3) goto LAB_080315da;
    }
  }
LAB_080315da:
  return (int)piVar1 - (int)param_1 >> 2;
}



/* ===== FUN_080315e4 @ 080315e4 ===== */

int * FUN_080315e4(int *param_1,int param_2,int param_3)

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



/* ===== FUN_080315f8 @ 080315f8 ===== */

uint FUN_080315f8(uint param_1)

{
  ushort uVar1;
  
  if (param_1 < 0x80) {
    uVar1 = *(ushort *)((int)&DAT_08031f00 + param_1 * 2 + DAT_08031f00);
  }
  else {
    uVar1 = 0;
  }
  return ~-(uint)((uVar1 & 0x40) == 0) >> 0x1f;
}



/* ===== FUN_08031600 @ 08031600 ===== */

int * FUN_08031600(int *param_1,int param_2)

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



/* ===== FUN_08031614 @ 08031614 ===== */

int FUN_08031614(uint *param_1,uint *param_2,uint param_3,int param_4)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  undefined *puVar6;
  uint uVar7;
  undefined4 uVar8;
  uint *puVar9;
  uint uVar10;
  
  if (param_3 == 0x25) {
    uVar5 = param_1[5];
    param_1[5] = uVar5 + 1;
    uVar8 = 0x25;
LAB_08031984:
    *(undefined4 *)(param_4 + uVar5 * 4) = uVar8;
    return 0;
  }
  if ((param_3 == 0x41) || (param_3 - 0x45 < 3)) {
LAB_080317e8:
    uVar5 = param_1[0xf];
    puVar9 = (uint *)(*param_2 + 7 & 0xfffffff8);
    *param_2 = (uint)puVar9;
    uVar7 = *puVar9;
    uVar10 = puVar9[1];
    if (uVar5 == 0x4c) {
      *param_2 = (uint)(puVar9 + 2);
    }
    else {
      *param_2 = (uint)(puVar9 + 2);
    }
    *param_1 = uVar7;
    param_1[1] = uVar10;
    if ((int)uVar10 < 0) {
      uVar5 = param_1[5];
      param_1[5] = uVar5 + 1;
      uVar8 = 0x2d;
    }
    else if ((int)((uint)(ushort)param_1[0xe] << 0x1e) < 0) {
      uVar5 = param_1[5];
      param_1[5] = uVar5 + 1;
      uVar8 = 0x2b;
    }
    else {
      if (-1 < (int)((uint)(ushort)param_1[0xe] << 0x1f)) goto LAB_08031838;
      uVar5 = param_1[5];
      param_1[5] = uVar5 + 1;
      uVar8 = 0x20;
    }
    *(undefined4 *)(param_4 + uVar5 * 4) = uVar8;
LAB_08031838:
    param_1[4] = param_4 + param_1[5] * 4;
    FUN_08031f38(param_1);
    return 0;
  }
  if (param_3 == 0x58) {
LAB_08031746:
    uVar5 = param_1[0xf];
    puVar9 = (uint *)*param_2;
    if (uVar5 == 0x6c) {
      uVar7 = *puVar9;
      *param_2 = (uint)(puVar9 + 1);
LAB_08031788:
      uVar10 = 0;
    }
    else {
      if (uVar5 != 0x71 && uVar5 != 0x6a) {
        if (uVar5 == 0x74) {
          uVar7 = *puVar9;
        }
        else {
          uVar7 = *puVar9;
          if (uVar5 != 0x7a) {
            *param_2 = (uint)(puVar9 + 1);
            goto LAB_08031788;
          }
        }
        *param_2 = (uint)(puVar9 + 1);
        goto LAB_08031788;
      }
      puVar9 = (uint *)((int)puVar9 + 7U & 0xfffffff8);
      *param_2 = (uint)puVar9;
      uVar7 = *puVar9;
      uVar10 = puVar9[1];
      *param_2 = (uint)(puVar9 + 2);
    }
    *param_1 = uVar7;
    param_1[1] = uVar10;
    if (uVar5 == 0x68) {
      uVar7 = uVar7 & 0xffff;
LAB_080317a6:
      *param_1 = uVar7;
      param_1[1] = 0;
    }
    else {
      if (uVar5 == 0x62) {
        uVar7 = uVar7 & 0xff;
        goto LAB_080317a6;
      }
      if (uVar5 == 0x74 || uVar5 == 0x7a) goto LAB_080317a6;
    }
    if ((((int)((uint)(byte)param_1[0xe] << 0x1c) < 0) && (param_1[1] != 0 || *param_1 != 0)) &&
       ((param_3 | 0x20) == 0x78)) {
      uVar5 = param_1[5];
      param_1[5] = uVar5 + 1;
      *(undefined4 *)(param_4 + uVar5 * 4) = 0x30;
      uVar5 = param_1[5];
      param_1[5] = uVar5 + 1;
      *(uint *)(param_4 + uVar5 * 4) = param_3;
    }
  }
  else {
    if (param_3 == 0x61) goto LAB_080317e8;
    if (param_3 == 99) {
      if (param_1[0xf] != 0x6c) {
        uVar8 = *(undefined4 *)*param_2;
        *param_2 = (uint)((undefined4 *)*param_2 + 1);
        iVar4 = FUN_08031f04(uVar8);
        if (iVar4 == -1) {
          return -1;
        }
        uVar5 = param_1[5];
        param_1[5] = uVar5 + 1;
        *(int *)(param_4 + uVar5 * 4) = iVar4;
        return 0;
      }
      uVar5 = param_1[5];
      param_1[5] = uVar5 + 1;
      uVar8 = *(undefined4 *)*param_2;
      *param_2 = (uint)((undefined4 *)*param_2 + 1);
      goto LAB_08031984;
    }
    if (param_3 != 100) {
      if (param_3 - 0x65 < 3) goto LAB_080317e8;
      if (param_3 != 0x69) {
        if (param_3 == 0x6e) {
          if ((char)param_1[0x10] == '\0') {
            uVar5 = param_1[0xf];
            if (uVar5 == 0x62) {
              puVar1 = *(undefined1 **)*param_2;
              *param_2 = (uint)((undefined4 *)*param_2 + 1);
              if (puVar1 != (undefined1 *)0x0) {
                *puVar1 = (char)param_1[0xc];
                return 0;
              }
              pcVar3 = "wprintf: bad %n argument";
            }
            else if (uVar5 == 0x68) {
              puVar2 = *(undefined2 **)*param_2;
              *param_2 = (uint)((undefined4 *)*param_2 + 1);
              if (puVar2 != (undefined2 *)0x0) {
                *puVar2 = (short)param_1[0xc];
                return 0;
              }
              pcVar3 = "wprintf: bad %n argument";
            }
            else if ((uVar5 == 0x6a) || ((uVar5 != 0x6c && (uVar5 == 0x71)))) {
              puVar9 = *(uint **)*param_2;
              *param_2 = (uint)((int *)*param_2 + 1);
              if (puVar9 != (uint *)0x0) {
                uVar5 = param_1[0xc];
                *puVar9 = uVar5;
                puVar9[1] = (int)uVar5 >> 0x1f;
                return 0;
              }
              pcVar3 = "wprintf: bad %n argument";
            }
            else {
              puVar9 = *(uint **)*param_2;
              *param_2 = (uint)((int *)*param_2 + 1);
              if (puVar9 != (uint *)0x0) {
                *puVar9 = param_1[0xc];
                return 0;
              }
              pcVar3 = "wprintf: bad %n argument";
            }
          }
          else {
            pcVar3 = "wprintf_s: %n disallowed";
          }
          goto LAB_0803195e;
        }
        if (param_3 != 0x6f) {
          if (param_3 == 0x70) {
            uVar5 = *(uint *)*param_2;
            *param_2 = (uint)((uint *)*param_2 + 1);
            *param_1 = uVar5;
            param_1[1] = 0;
            param_1[4] = param_4 + param_1[5] * 4;
            param_3 = 0x78;
            goto LAB_080318f6;
          }
          if (param_3 == 0x73) {
            puVar9 = (uint *)*param_2;
            if (param_1[0xf] != 0x6c) {
              puVar6 = (undefined *)*puVar9;
              *param_2 = (uint)(puVar9 + 1);
              if (puVar6 == (undefined *)0x0) {
                if ((char)param_1[0x10] != '\0') {
                  pcVar3 = "wprintf_s: bad %s argument";
                  goto LAB_0803195e;
                }
                puVar6 = &DAT_08031a14;
              }
              iVar4 = FUN_0803250c(param_1,puVar6);
              if (iVar4 < 0) {
                return -1;
              }
              return 0;
            }
            uVar5 = *puVar9;
            *param_2 = (uint)(puVar9 + 1);
            param_1[4] = uVar5;
            if (uVar5 == 0) {
              if ((char)param_1[0x10] != '\0') {
                pcVar3 = "wprintf_s: bad %ls argument";
LAB_0803195e:
                iVar4 = FUN_0802cf68(pcVar3);
                return -1 - iVar4;
              }
              param_1[4] = (uint)&DAT_080319f4;
            }
            if ((int)param_1[0xb] < 0) {
              uVar5 = FUN_080324fa();
            }
            else {
              iVar4 = FUN_080315e4(param_1[4],0);
              if (iVar4 == 0) {
                uVar5 = param_1[0xb];
              }
              else {
                uVar5 = (int)(iVar4 - param_1[4]) >> 2;
              }
            }
            param_1[7] = uVar5;
            return 0;
          }
          if ((param_3 != 0x75) && (param_3 != 0x78)) {
            uVar5 = param_1[5];
            param_1[5] = uVar5 + 1;
            if (param_3 == 0) {
              param_3 = 0x25;
            }
            *(uint *)(param_4 + uVar5 * 4) = param_3;
            return 0;
          }
        }
        goto LAB_08031746;
      }
    }
    uVar5 = param_1[0xf];
    puVar9 = (uint *)*param_2;
    if (uVar5 == 0x6c) {
      uVar7 = *puVar9;
      *param_2 = (uint)(puVar9 + 1);
LAB_080316ee:
      uVar10 = (int)uVar7 >> 0x1f;
    }
    else {
      if (uVar5 != 0x71 && uVar5 != 0x6a) {
        if (uVar5 == 0x74) {
          uVar7 = *puVar9;
        }
        else {
          uVar7 = *puVar9;
          if (uVar5 != 0x7a) {
            *param_2 = (uint)(puVar9 + 1);
            goto LAB_080316ee;
          }
        }
        *param_2 = (uint)(puVar9 + 1);
        goto LAB_080316ee;
      }
      puVar9 = (uint *)((int)puVar9 + 7U & 0xfffffff8);
      *param_2 = (uint)puVar9;
      uVar7 = *puVar9;
      uVar10 = puVar9[1];
      *param_2 = (uint)(puVar9 + 2);
    }
    *param_1 = uVar7;
    param_1[1] = uVar10;
    if (uVar5 == 0x68) {
      uVar7 = (uint)(short)uVar7;
LAB_0803170c:
      *param_1 = uVar7;
      param_1[1] = (int)uVar7 >> 0x1f;
    }
    else {
      if (uVar5 == 0x62) {
        uVar7 = (uint)(char)uVar7;
        goto LAB_0803170c;
      }
      if (uVar5 == 0x74 || uVar5 == 0x7a) goto LAB_0803170c;
    }
    if ((int)param_1[1] < 0) {
      uVar5 = param_1[5];
      param_1[5] = uVar5 + 1;
      uVar8 = 0x2d;
LAB_08031740:
      *(undefined4 *)(param_4 + uVar5 * 4) = uVar8;
    }
    else {
      if ((int)((uint)(ushort)param_1[0xe] << 0x1e) < 0) {
        uVar5 = param_1[5];
        param_1[5] = uVar5 + 1;
        uVar8 = 0x2b;
        goto LAB_08031740;
      }
      if ((int)((uint)(ushort)param_1[0xe] << 0x1f) < 0) {
        uVar5 = param_1[5];
        param_1[5] = uVar5 + 1;
        uVar8 = 0x20;
        goto LAB_08031740;
      }
    }
  }
  param_1[4] = param_4 + param_1[5] * 4;
LAB_080318f6:
  FUN_080323b8(param_1,param_3);
  return 0;
}



/* ===== FUN_08031a18 @ 08031a18 ===== */

longlong FUN_08031a18(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

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
    iVar4 = (int)&DAT_08031bc4 + DAT_08031bc4;
    uVar3 = uVar2;
    do {
      if (uVar3 < 0x20) {
        uVar5 = uVar3;
      }
      else {
        uVar5 = 0x1f;
      }
      iVar1 = (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0xc),iVar4,uVar5);
      *(int *)(param_1 + 0xc) = iVar1;
      if (iVar1 == 0) goto LAB_08031bba;
      uVar3 = uVar3 - uVar5;
      *(uint *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + uVar5;
    } while (0 < (int)uVar3);
  }
  if (0 < *(int *)(param_1 + 0x14)) {
    iVar4 = (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0xc),param_2);
    *(int *)(param_1 + 0xc) = iVar4;
    if (iVar4 == 0) goto LAB_08031bba;
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x30);
  }
  uVar3 = *(uint *)(param_1 + 0x18);
  if (0 < (int)uVar3) {
    iVar4 = DAT_08031bc4 + 0x8031c44;
    do {
      if (uVar3 < 0x20) {
        uVar5 = uVar3;
      }
      else {
        uVar5 = 0x1f;
      }
      iVar1 = (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0xc),iVar4,uVar5);
      *(int *)(param_1 + 0xc) = iVar1;
      if (iVar1 == 0) goto LAB_08031bba;
      uVar3 = uVar3 - uVar5;
      *(uint *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + uVar5;
    } while (0 < (int)uVar3);
  }
  if (0 < *(int *)(param_1 + 0x1c)) {
    iVar4 = (**(code **)(param_1 + 8))
                      (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10));
    *(int *)(param_1 + 0xc) = iVar4;
    if (iVar4 == 0) goto LAB_08031bba;
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x30);
  }
  uVar3 = *(uint *)(param_1 + 0x20);
  if (0 < (int)uVar3) {
    iVar4 = DAT_08031bc4 + 0x8031c44;
    do {
      if (uVar3 < 0x20) {
        uVar5 = uVar3;
      }
      else {
        uVar5 = 0x1f;
      }
      iVar1 = (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0xc),iVar4,uVar5);
      *(int *)(param_1 + 0xc) = iVar1;
      if (iVar1 == 0) goto LAB_08031bba;
      uVar3 = uVar3 - uVar5;
      *(uint *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + uVar5;
    } while (0 < (int)uVar3);
  }
  if (0 < *(int *)(param_1 + 0x24)) {
    iVar4 = (**(code **)(param_1 + 8))
                      (*(undefined4 *)(param_1 + 0xc),
                       *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x1c) * 4);
    *(int *)(param_1 + 0xc) = iVar4;
    if (iVar4 == 0) {
LAB_08031bba:
      return CONCAT44(param_4,0xffffffff);
    }
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x30);
  }
  uVar3 = *(uint *)(param_1 + 0x28);
  if (0 < (int)uVar3) {
    iVar4 = DAT_08031bc4 + 0x8031c44;
    do {
      if (uVar3 < 0x20) {
        uVar5 = uVar3;
      }
      else {
        uVar5 = 0x1f;
      }
      iVar1 = (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0xc),iVar4,uVar5);
      *(int *)(param_1 + 0xc) = iVar1;
      if (iVar1 == 0) goto LAB_08031bba;
      uVar3 = uVar3 - uVar5;
      *(uint *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + uVar5;
    } while (0 < (int)uVar3);
  }
  if (((int)((uint)*(byte *)(param_1 + 0x38) << 0x1d) < 0) && (0 < (int)uVar2)) {
    iVar4 = (int)&DAT_08031bc4 + DAT_08031bc4;
    do {
      if (uVar2 < 0x20) {
        uVar3 = uVar2;
      }
      else {
        uVar3 = 0x1f;
      }
      iVar1 = (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0xc),iVar4,uVar3);
      *(int *)(param_1 + 0xc) = iVar1;
      if (iVar1 == 0) goto LAB_08031bba;
      uVar2 = uVar2 - uVar3;
      *(uint *)(param_1 + 0x30) = uVar3 + *(int *)(param_1 + 0x30);
    } while (0 < (int)uVar2);
  }
  return (ulonglong)param_4 << 0x20;
}



/* ===== FUN_08031bc8 @ 08031bc8 ===== */

void FUN_08031bc8(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  return;
}



/* ===== FUN_08031bd4 @ 08031bd4 ===== */

undefined4 * FUN_08031bd4(int param_1,uint param_2)

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



/* ===== FUN_08031bda @ 08031bda ===== */

int FUN_08031bda(undefined4 param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_2 + 0x400;
  iVar1 = 0;
  for (; param_2 < piVar2; param_2 = param_2 + 1) {
    iVar1 = *param_2 + iVar1;
  }
  return iVar1;
}



/* ===== FUN_08031bf0 @ 08031bf0 ===== */

void FUN_08031bf0(void)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_08031c20;
  *DAT_08031c20 = *DAT_08031c20 | 1;
  *puVar1 = *puVar1 & 0xffffff9f;
  uVar2 = DAT_08031c24;
  *puVar1 = *puVar1 & 0xffffff7f;
  puVar1[3] = uVar2;
  *puVar1 = *puVar1 & 0xffffffe7;
  puVar1[2] = 0xffffffff;
  return;
}



/* ===== FUN_08031c28 @ 08031c28 ===== */

void FUN_08031c28(int param_1,uint param_2)

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



/* ===== FUN_08031d64 @ 08031d64 ===== */

undefined4 FUN_08031d64(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  undefined2 *puVar1;
  int iVar2;
  
  if (param_1[2] < 0x40) {
    param_1[2] = param_1[2] + 1;
  }
  iVar2 = param_1[1] + 1;
  if (0x3f < iVar2) {
    iVar2 = 0;
  }
  puVar1 = (undefined2 *)(*param_1 + iVar2 * 0x10);
  *puVar1 = 0;
  *(undefined1 *)(puVar1 + 1) = 0;
  param_1[1] = iVar2;
  *(uint *)(puVar1 + 1) = *(uint *)(puVar1 + 1) & 0xff;
  puVar1[3] = 0;
  *(undefined4 *)(puVar1 + 4) = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  *puVar1 = (short)param_1[3];
  puVar1[3] = (short)param_4;
  *(uint *)(puVar1 + 1) = *(uint *)(puVar1 + 1) & 0xff | param_5 << 8;
  *(undefined4 *)(puVar1 + 4) = *(undefined4 *)(param_3 + 8);
  puVar1[6] = *(undefined2 *)(param_3 + 0xc);
  puVar1[7] = *(undefined2 *)(param_3 + 0xe);
  switch(param_2) {
  case 0:
    param_3 = 1;
    break;
  case 1:
  case 2:
    if (*(char *)(param_3 + 4) == '\0') {
      param_3 = 2;
    }
    else {
      param_3 = 3;
    }
    break;
  case 3:
    if (*(char *)(param_3 + 4) == '\0') {
      param_3 = 4;
    }
    else {
      param_3 = 5;
    }
    break;
  case 4:
    param_3 = 6;
  }
  *(char *)(puVar1 + 1) = (char)param_3;
  return param_4;
}



/* ===== FUN_08031dfc @ 08031dfc ===== */

undefined4
FUN_08031dfc(float param_1,float *param_2,int *param_3,undefined4 param_4,undefined4 param_5)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  int *piVar4;
  float *pfVar5;
  int *piVar6;
  uint in_fpscr;
  float fVar7;
  float fVar8;
  float fVar9;
  longlong lVar10;
  
  pfVar5 = param_2 + 3;
  lVar2 = 0;
  piVar6 = param_3 + 4;
  lVar1 = 0;
  if (pfVar5 < param_2 + 0x103) {
    lVar2 = 0;
    lVar1 = 0;
    do {
      iVar3 = 0;
      piVar4 = param_3 + 4;
      if (param_3 < (int *)0xfffffff0) {
        do {
          if (piVar6 <= param_3) {
            iVar3 = *param_3 + iVar3;
          }
          param_3 = param_3 + 1;
        } while (param_3 < piVar4);
        if (iVar3 != 0) {
          fVar8 = *pfVar5;
          fVar7 = (float)VectorUnsignedToFloat(iVar3,(byte)(in_fpscr >> 0x16) & 3);
          fVar7 = fVar7 * fVar8;
          lVar10 = FUN_0802aa28(fVar7);
          lVar1 = lVar10 + lVar1;
          lVar10 = FUN_0802aa28(fVar8 * fVar7 * DAT_08031ec8);
          lVar2 = lVar10 + lVar2;
        }
      }
      pfVar5 = pfVar5 + 1;
    } while (pfVar5 < param_2 + 0x103);
  }
  fVar8 = *param_2;
  fVar9 = fVar8 * param_1 * DAT_08031ec8;
  fVar7 = (float)FUN_0802fd24((int)lVar1,(int)((ulonglong)lVar1 >> 0x20));
  param_2[1] = fVar7 * fVar9;
  fVar7 = (float)FUN_0802fd24((int)lVar2,(int)((ulonglong)lVar2 >> 0x20));
  param_2[2] = fVar7 * fVar9 * fVar8 * param_1;
  return param_5;
}



/* ===== FUN_08031ecc @ 08031ecc ===== */

void FUN_08031ecc(undefined1 *param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 1;
  param_1[1] = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  *(undefined2 *)(param_1 + 10) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}



/* ===== FUN_08031f04 @ 08031f04 ===== */

undefined4 FUN_08031f04(int param_1)

{
  int iVar1;
  undefined1 local_18 [4];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (param_1 != -1) {
    local_18[0] = (undefined1)param_1;
    local_10 = 0;
    local_c = 0;
    iVar1 = FUN_0802cf32(&local_14,local_18,1,&local_10);
    if (-1 < iVar1) {
      return local_14;
    }
  }
  return 0xffffffff;
}



/* ===== FUN_08031f38 @ 08031f38 ===== */

void FUN_08031f38(ulonglong *param_1,uint param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint *puVar5;
  undefined *puVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint extraout_r2;
  uint *puVar11;
  short sVar12;
  uint uVar13;
  undefined4 uVar14;
  uint uVar15;
  uint uVar16;
  char cVar17;
  ulonglong uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  ulonglong uVar21;
  longlong lVar22;
  uint local_d4;
  uint local_d0;
  uint uStack_cc;
  uint local_c8 [7];
  uint local_ac [33];
  uint local_28;
  
  uVar2 = *param_1;
  uVar13 = *(uint *)((int)param_1 + 4);
  uVar1 = *param_1;
  uVar21 = *param_1;
  uVar15 = param_2 | 0x20;
  iVar3 = *(int *)((int)param_1 + 0x2c);
  puVar5 = local_c8;
  if (uVar15 != 0x61) {
    if (iVar3 < 0) {
      iVar3 = 6;
    }
    else if (iVar3 == 0 && uVar15 == 0x67) {
      iVar3 = 1;
    }
  }
  *(int *)((int)param_1 + 0x2c) = iVar3;
  local_d0 = (uint)*param_1;
  uStack_cc = *(uint *)((int)param_1 + 4);
  uVar10 = uStack_cc << 1 | local_d0 >> 0x1f;
  local_28 = param_2;
  if (((int)uVar10 < 0 && (int)uVar10 >> 0x15 == -1) &&
     (((uStack_cc & 0xfffff) != 0 || local_d0 >> 0x14 != 0) || (local_d0 & 0xfffff) != 0)) {
    *(undefined4 *)((int)param_1 + 0x1c) = 3;
    if (param_2 - 0x61 < 0x1a) {
      puVar6 = &DAT_08032398;
    }
    else {
      puVar6 = &DAT_080323a8;
    }
  }
  else {
    if (((int)(uStack_cc << 1) >> 0x15 != -1) || ((uStack_cc & 0xfffff) != 0)) {
      uVar18 = FUN_0802d000(local_d0,uStack_cc,&local_d4);
      *param_1 = uVar18;
      if (uVar15 == 0x61) {
        puVar4 = *(undefined4 **)(param_1 + 2);
        *puVar4 = 0x30;
        *(undefined4 **)(param_1 + 2) = puVar4 + 2;
        if (local_28 == 0x61) {
          uVar7 = 0x78;
        }
        else {
          uVar7 = 0x58;
        }
        puVar4[1] = uVar7;
        *(int *)((int)param_1 + 0x14) = *(int *)((int)param_1 + 0x14) + 2;
      }
      uVar10 = (uint)*param_1;
      uVar16 = *(uint *)((int)param_1 + 4);
      if ((uVar16 & 0x7fffffff) == 0 && uVar10 == 0) {
        sVar12 = 0;
      }
      else {
        if (uVar15 == 0x61) {
          if (local_28 == 0x61) {
            local_d0 = DAT_080322ac + 0x80322f4;
          }
          else {
            local_d0 = DAT_080322ac + 0x8032334;
          }
          if (*(int *)((int)param_1 + 0x2c) < 0) {
            uVar15 = 0x21;
          }
          else {
            uVar15 = *(int *)((int)param_1 + 0x2c) + 1;
          }
          cVar17 = 0xfffffffd < uVar15;
          iVar3 = uVar15 + 2;
          FUN_0802d070((int)uVar2,uVar13,0,0);
          if (cVar17 == '\0') {
            uVar16 = uVar16 ^ 0x80000000;
          }
          uVar19 = CONCAT44(uVar16,uVar10);
          local_c8[0] = extraout_r2;
          local_d4 = local_d4 - 4;
          puVar5 = local_c8 + 1;
          if (0 < iVar3) {
            do {
              cVar17 = '\x01';
              uVar19 = FUN_0802d0a4((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0,0);
              if (cVar17 != '\0') break;
              uVar19 = FUN_0802d0d8((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0x1c);
              uVar13 = FUN_0802d214();
              iVar3 = iVar3 + -7;
              if (0 < iVar3) {
                uVar20 = FUN_0802d24c();
                uVar19 = FUN_0802d3dc((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar20,
                                      (int)((ulonglong)uVar20 >> 0x20));
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
            } while (0 < iVar3);
          }
          uVar13 = (int)puVar5 - (int)(local_c8 + 1) >> 2;
          puVar5 = local_c8 + 1;
          uVar10 = uVar13;
          if ((int)uVar15 < (int)uVar13) {
            uVar10 = uVar15;
          }
          if (-1 < (int)uVar10) {
            if (((int)uVar10 < (int)uVar13) && (7 < local_c8[uVar10 + 1])) {
              uVar13 = 0xf;
            }
            else {
              uVar13 = 0;
            }
            uVar15 = uVar10;
            puVar11 = local_c8 + uVar10;
            while( true ) {
              if (*puVar11 != uVar13) break;
              uVar10 = uVar10 - 1;
              uVar15 = uVar15 - 1;
              puVar11 = puVar11 + -1;
            }
            if (uVar13 == 0xf) {
              local_c8[uVar15] = local_c8[uVar15] + 1;
            }
            if ((int)(uVar15 - 1) < 0) {
              local_d4 = local_d4 + 4;
              puVar5 = local_c8;
              uVar10 = uVar10 + 1;
            }
            iVar3 = uVar10 - 1;
            if (-1 < iVar3) {
              puVar11 = puVar5 + iVar3;
              do {
                *puVar11 = *(uint *)(local_d0 + *puVar11 * 4);
                iVar3 = iVar3 + -1;
                puVar11 = puVar11 + -1;
              } while (-1 < iVar3);
            }
          }
          if (*(int *)((int)param_1 + 0x2c) < 0) {
            *(uint *)((int)param_1 + 0x2c) = uVar10 - 1;
          }
        }
        else {
          local_d4 = (int)(local_d4 * 0x7597) / DAT_0803236c - 4;
          uVar21 = uVar21 & 0x7fffffffffffffff;
          if ((int)local_d4 < 0) {
            uVar13 = 3 - local_d4 & 0xfffffffc;
            local_d4 = -uVar13;
            puVar4 = (undefined4 *)((int)&DAT_080322ac + DAT_080322ac);
            for (; 0 < (int)uVar13; uVar13 = (int)uVar13 >> 1) {
              if ((int)(uVar13 << 0x1f) < 0) {
                uVar21 = FUN_0802d748(*puVar4,puVar4[1]);
              }
              puVar4 = puVar4 + 2;
            }
          }
          else {
            uVar21 = uVar1 & 0x7fffffffffffffff;
            if (0 < (int)local_d4) {
              uVar10 = local_d4 & 0xfffffffc;
              lVar22 = (ulonglong)DAT_08032370 << 0x20;
              puVar4 = (undefined4 *)((int)&DAT_080322ac + DAT_080322ac);
              local_d4 = uVar10;
              while( true ) {
                if ((int)uVar10 < 1) break;
                if ((int)(uVar10 << 0x1f) < 0) {
                  lVar22 = FUN_0802d748(*puVar4,puVar4[1],(int)lVar22,
                                        (int)((ulonglong)lVar22 >> 0x20));
                }
                uVar10 = (int)uVar10 >> 1;
                puVar4 = puVar4 + 2;
              }
              uVar21 = FUN_0802d4c0((int)uVar2,uVar13 & 0x7fffffff);
            }
          }
          uVar7 = DAT_08032374;
          if (uVar15 == 0x66) {
            iVar3 = local_d4 + 0xb;
          }
          else {
            iVar3 = 7;
          }
          iVar3 = iVar3 + *(int *)((int)param_1 + 0x2c);
          if (0x13 < iVar3) {
            iVar3 = 0x13;
          }
          local_c8[0] = 0x30;
          puVar5 = local_c8 + 1;
          while (0 < iVar3) {
            uVar14 = (undefined4)(uVar21 >> 0x20);
            cVar17 = '\x01';
            FUN_0802d0a4((int)uVar21,uVar14,0,0);
            if (cVar17 != '\0') break;
            iVar8 = FUN_0802d214();
            iVar3 = iVar3 + -8;
            if (0 < iVar3) {
              uVar19 = FUN_0802d24c();
              uVar19 = FUN_0802d3dc((int)uVar21,uVar14,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20))
              ;
              uVar21 = FUN_0802d748((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0,uVar7);
            }
            puVar5 = puVar5 + 8;
            iVar9 = 8;
            while ((0 < iVar8 && (iVar9 = iVar9 + -1, -1 < iVar9))) {
              puVar5 = puVar5 + -1;
              *puVar5 = iVar8 % 10 + 0x30;
              iVar8 = iVar8 / 10;
            }
            while (iVar9 = iVar9 + -1, -1 < iVar9) {
              puVar5 = puVar5 + -1;
              *puVar5 = 0x30;
            }
            puVar5 = puVar5 + 8;
          }
          local_d4 = local_d4 + 7;
          uVar13 = (int)puVar5 - (int)(local_c8 + 1) >> 2;
          puVar5 = local_c8;
          while (puVar5 = puVar5 + 1, *puVar5 == 0x30) {
            local_d4 = local_d4 - 1;
            uVar13 = uVar13 - 1;
          }
          if ((local_28 | 0x20) == 0x66) {
            iVar3 = local_d4 + 1;
          }
          else if ((local_28 | 0x20) == 0x65) {
            iVar3 = 1;
          }
          else {
            iVar3 = 0;
          }
          uVar10 = iVar3 + *(int *)((int)param_1 + 0x2c);
          uVar15 = uVar13;
          if ((int)uVar10 < (int)uVar13) {
            uVar15 = uVar10;
          }
          uVar10 = uVar15;
          if (-1 < (int)uVar15) {
            if (((int)uVar15 < (int)uVar13) && (0x34 < puVar5[uVar15])) {
              uVar13 = 0x39;
            }
            else {
              uVar13 = 0x30;
            }
            puVar11 = puVar5 + -1 + uVar15;
            while( true ) {
              uVar15 = uVar15 - 1;
              if (*puVar11 != uVar13) break;
              uVar10 = uVar10 - 1;
              puVar11 = puVar11 + -1;
            }
            if (uVar13 == 0x39) {
              puVar5[uVar15] = puVar5[uVar15] + 1;
            }
            if ((int)uVar15 < 0) {
              local_d4 = local_d4 + 1;
              uVar10 = uVar10 + 1;
              puVar5 = puVar5 + -1;
            }
          }
        }
        sVar12 = (short)uVar10;
        uVar10 = local_d4;
      }
      FUN_080325c4(param_1,local_28,puVar5,(int)sVar12,(int)(short)uVar10);
      return;
    }
    *(undefined4 *)((int)param_1 + 0x1c) = 3;
    if (param_2 - 0x61 < 0x1a) {
      puVar6 = &DAT_08032378;
    }
    else {
      puVar6 = &DAT_08032388;
    }
  }
  FUN_080325b0((int)param_1[2],puVar6,3);
  return;
}



/* ===== FUN_080323b8 @ 080323b8 ===== */

void FUN_080323b8(int *param_1,int param_2)

{
  int extraout_r2;
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  bool bVar7;
  longlong lVar8;
  int aiStack_80 [24];
  
  iVar6 = (int)&DAT_08032430 + DAT_08032430;
  if (param_2 == 0x58) {
    iVar6 = DAT_08032430 + 0x8032470;
  }
  else {
    if (param_2 == 0x6f) {
      iVar3 = 8;
      goto LAB_080323d2;
    }
    if (param_2 != 0x78) {
      iVar3 = 10;
      goto LAB_080323d2;
    }
  }
  iVar3 = 0x10;
LAB_080323d2:
  uVar4 = 0x18;
  iVar1 = *param_1;
  iVar2 = param_1[1];
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
    FUN_08019bf4(iVar1,iVar2,iVar3,0);
    aiStack_80[0x17] = *(undefined4 *)(iVar6 + extraout_r2 * 4);
    uVar4 = 0x17;
  }
  lVar8 = FUN_08019bf4(iVar1,iVar2,iVar3,0);
  piVar5 = aiStack_80 + uVar4;
  while( true ) {
    iVar1 = (int)lVar8;
    piVar5 = piVar5 + -1;
    if ((lVar8 == 0) || ((int)uVar4 < 1)) break;
    lVar8 = FUN_08019bf4(iVar1,(int)((ulonglong)lVar8 >> 0x20),iVar3,0);
    *piVar5 = *(int *)(iVar6 + (iVar1 - iVar3 * (int)lVar8) * 4);
    uVar4 = uVar4 - 1;
  }
  if (((iVar3 == 8) && ((int)((uint)*(byte *)(param_1 + 0xe) << 0x1c) < 0)) &&
     ((0x17 < uVar4 || (aiStack_80[uVar4] != 0x30)))) {
    uVar4 = uVar4 - 1;
    aiStack_80[uVar4] = 0x30;
  }
  param_1[7] = 0x18 - uVar4;
  FUN_080325b0(param_1[4],aiStack_80 + uVar4);
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



/* ===== FUN_080324fa @ 080324fa ===== */

int FUN_080324fa(int *param_1)

{
  int *piVar1;
  
  for (piVar1 = param_1; *piVar1 != 0; piVar1 = piVar1 + 1) {
  }
  return (int)piVar1 - (int)param_1 >> 2;
}



/* ===== FUN_0803250c @ 0803250c ===== */

int FUN_0803250c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_220;
  undefined4 local_21c;
  int aiStack_218 [128];
  
  iVar2 = *(int *)(param_1 + 0x2c);
  if (iVar2 < 0) {
    iVar2 = 0x7fffffff;
  }
  local_220 = 0;
  local_21c = 0;
  if (0x80 < *(uint *)(param_1 + 0x34)) {
    return -1;
  }
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      if (0x7f < *(uint *)(param_1 + 0x14)) {
        *(undefined4 *)(param_1 + 0x34) = 0;
        iVar3 = FUN_08031a18(param_1,aiStack_218);
        if (iVar3 < 0) break;
        *(undefined4 *)(param_1 + 0x14) = 0;
      }
      iVar1 = FUN_0802cf32(aiStack_218 + *(int *)(param_1 + 0x14),param_2,0xffffffff,&local_220);
      if (iVar1 < 0) {
        return -1;
      }
      if ((iVar1 == 0) && (aiStack_218[*(int *)(param_1 + 0x14)] == 0)) break;
      iVar2 = iVar2 + -1;
      param_2 = param_2 + iVar1;
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    } while (iVar2 != 0);
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  iVar2 = FUN_08031a18(param_1,aiStack_218);
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return iVar2;
}



/* ===== FUN_080325b0 @ 080325b0 ===== */

void FUN_080325b0(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *param_1 = *param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



/* ===== FUN_080325c4 @ 080325c4 ===== */

void FUN_080325c4(int param_1,uint param_2,undefined4 *param_3,int param_4,short param_5)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  byte *pbVar9;
  short sVar10;
  int iVar11;
  byte abStack_31 [13];
  undefined4 *puStack_24;
  int iStack_20;
  
  puStack_24 = param_3;
  iStack_20 = param_4;
  iVar1 = FUN_0802cf42();
  iVar1 = FUN_08031f04(**(undefined1 **)(iVar1 + 0x24));
  if (iVar1 == -1) {
    iVar1 = 0x2e;
  }
  if (param_4 < 1) {
    param_4 = 1;
    param_3 = &DAT_0803285c;
  }
  uVar4 = param_2 | 0x20;
  iVar2 = *(int *)(param_1 + 0x2c);
  iVar11 = (int)param_5;
  if (uVar4 == 0x66) {
LAB_08032632:
    sVar10 = (short)(iVar11 + 1);
    iVar6 = (int)sVar10;
    if (uVar4 != 0x66) {
      if ((-1 < (int)((uint)*(byte *)(param_1 + 0x38) << 0x1c)) && (param_4 <= iVar2)) {
        iVar2 = param_4;
      }
      iVar2 = iVar2 - iVar6;
      if (iVar2 < 0) {
        iVar2 = 0;
      }
    }
    *(int *)(param_1 + 0x2c) = iVar2;
    iVar2 = *(int *)(param_1 + 0x10);
    iVar5 = *(int *)(param_1 + 0x1c);
    if (iVar6 < 1) {
      *(int *)(param_1 + 0x1c) = iVar5 + 1;
      *(undefined4 *)(iVar2 + iVar5 * 4) = 0x30;
      if ((0 < *(int *)(param_1 + 0x2c)) || ((int)((uint)*(byte *)(param_1 + 0x38) << 0x1c) < 0)) {
        iVar11 = *(int *)(param_1 + 0x1c);
        *(int *)(param_1 + 0x1c) = iVar11 + 1;
        *(int *)(iVar2 + iVar11 * 4) = iVar1;
      }
      iVar1 = *(int *)(param_1 + 0x2c);
      if (iVar1 + iVar6 < 0 != SCARRY4(iVar1,iVar6)) {
        sVar10 = -(short)iVar1;
      }
      iVar1 = sVar10 + iVar1;
      *(int *)(param_1 + 0x20) = -(int)sVar10;
      if (iVar1 < param_4) {
        param_4 = iVar1;
      }
      *(int *)(param_1 + 0x2c) = iVar1;
      iVar1 = (int)(short)param_4;
      *(int *)(param_1 + 0x24) = iVar1;
      FUN_080325b0(iVar2 + *(int *)(param_1 + 0x1c) * 4,param_3,iVar1);
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x2c) - iVar1;
    }
    else {
      iVar2 = iVar2 + iVar5 * 4;
      if (param_4 < sVar10) {
        FUN_080325b0(iVar2,param_3,param_4);
        iVar11 = *(int *)(param_1 + 0x1c) + param_4;
        *(int *)(param_1 + 0x1c) = iVar11;
        *(int *)(param_1 + 0x20) = iVar6 - param_4;
        if ((0 < *(int *)(param_1 + 0x2c)) || ((int)((uint)*(byte *)(param_1 + 0x38) << 0x1c) < 0))
        {
          *(int *)(*(int *)(param_1 + 0x10) + iVar11 * 4) = iVar1;
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
        }
        *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x2c);
      }
      else {
        FUN_080325b0(iVar2,param_3);
        iVar2 = iVar6 + *(int *)(param_1 + 0x1c);
        *(int *)(param_1 + 0x1c) = iVar2;
        param_4 = param_4 - (iVar11 + 1);
        if ((0 < *(int *)(param_1 + 0x2c)) || ((int)((uint)*(byte *)(param_1 + 0x38) << 0x1c) < 0))
        {
          *(int *)(param_1 + 0x1c) = iVar2 + 1;
          *(int *)(*(int *)(param_1 + 0x10) + iVar2 * 4) = iVar1;
        }
        if (*(int *)(param_1 + 0x2c) < (int)(short)param_4) {
          param_4 = *(int *)(param_1 + 0x2c);
        }
        sVar10 = (short)param_4;
        FUN_080325b0(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x1c) * 4,param_3 + iVar6,
                     (int)sVar10);
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + (int)sVar10;
        *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x2c) - (int)sVar10;
      }
    }
  }
  else {
    if (uVar4 == 0x67) {
      if ((-5 < iVar11) && (iVar11 < iVar2)) goto LAB_08032632;
      if ((param_4 < iVar2) && (-1 < (int)((uint)*(byte *)(param_1 + 0x38) << 0x1c))) {
        iVar2 = param_4;
      }
      iVar2 = iVar2 + -1;
      if (iVar2 < 0) {
        iVar2 = 0;
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
    *(int *)(param_1 + 0x2c) = iVar2;
    iVar6 = *(int *)(param_1 + 0x1c);
    *(int *)(param_1 + 0x1c) = iVar6 + 1;
    iVar2 = *(int *)(param_1 + 0x10);
    *(undefined4 *)(iVar2 + iVar6 * 4) = *param_3;
    if ((0 < *(int *)(param_1 + 0x2c)) || ((int)((uint)*(byte *)(param_1 + 0x38) << 0x1c) < 0)) {
      iVar6 = *(int *)(param_1 + 0x1c);
      *(int *)(param_1 + 0x1c) = iVar6 + 1;
      *(int *)(iVar2 + iVar6 * 4) = iVar1;
      iVar1 = *(int *)(param_1 + 0x2c);
      if (0 < iVar1) {
        iVar6 = param_4 + -1;
        if (iVar1 < (short)(param_4 + -1)) {
          iVar6 = iVar1;
        }
        sVar10 = (short)iVar6;
        FUN_080325b0(iVar2 + *(int *)(param_1 + 0x1c) * 4,param_3 + 1,(int)sVar10);
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + (int)sVar10;
        *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x2c) - (int)sVar10;
      }
    }
    iVar1 = *(int *)(param_1 + 0x10);
    puVar3 = (uint *)(iVar1 + *(int *)(param_1 + 0x1c) * 4);
    *puVar3 = param_2;
    if (iVar11 < 0) {
      puVar3[1] = 0x2d;
      iVar11 = -iVar11;
    }
    else {
      puVar3[1] = 0x2b;
    }
    puVar7 = puVar3 + 2;
    iVar2 = 0;
    pbVar9 = abStack_31 + 1;
    while (0 < (short)iVar11) {
      iVar6 = (int)(short)iVar11 / 10;
      *pbVar9 = (char)iVar11 + (char)iVar6 * -10;
      iVar2 = iVar2 + 1;
      pbVar9 = pbVar9 + 1;
      iVar11 = iVar6;
    }
    puVar8 = puVar7;
    if ((iVar2 < 2) && ((param_2 | 0x20) == 0x65)) {
      puVar8 = puVar3 + 3;
      *puVar7 = 0x30;
    }
    puVar3 = puVar8;
    if (iVar2 == 0) {
      puVar3 = puVar8 + 1;
      *puVar8 = 0x30;
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



/* ===== FUN_08038380 @ 08038380 ===== */

longlong FUN_08038380(undefined1 *param_1)

{
  uint unaff_r7;
  
  FUN_080194cc(*param_1,*(undefined2 *)(param_1 + 1),param_1[3]);
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08038392 @ 08038392 ===== */

longlong FUN_08038392(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080383a4 @ 080383a4 ===== */

longlong FUN_080383a4(int param_1)

{
  return (ulonglong)*(ushort *)(param_1 + 6) << 0x20;
}



/* ===== FUN_080383bc @ 080383bc ===== */

longlong FUN_080383bc(undefined1 *param_1)

{
  uint unaff_r7;
  
  FUN_08019514(*param_1);
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080383c8 @ 080383c8 ===== */

longlong FUN_080383c8(byte *param_1)

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



/* ===== FUN_080383fa @ 080383fa ===== */

longlong FUN_080383fa(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08038406 @ 08038406 ===== */

longlong FUN_08038406(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08038416 @ 08038416 ===== */

longlong FUN_08038416(undefined1 *param_1)

{
  uint unaff_r7;
  
  FUN_0801941c(*param_1);
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08038422 @ 08038422 ===== */

longlong FUN_08038422(void)

{
  uint unaff_r7;
  
  FUN_08019592();
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_0803842c @ 0803842c ===== */

longlong FUN_0803842c(int param_1)

{
  return (ulonglong)*(uint *)(param_1 + 1) << 0x20;
}



/* ===== FUN_08038484 @ 08038484 ===== */

longlong FUN_08038484(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08038496 @ 08038496 ===== */

longlong FUN_08038496(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080384a8 @ 080384a8 ===== */

longlong FUN_080384a8(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080384b8 @ 080384b8 ===== */

longlong FUN_080384b8(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080384c2 @ 080384c2 ===== */

longlong FUN_080384c2(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080384d2 @ 080384d2 ===== */

longlong FUN_080384d2(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080384de @ 080384de ===== */

longlong FUN_080384de(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080384ea @ 080384ea ===== */

longlong FUN_080384ea(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080384f4 @ 080384f4 ===== */

longlong FUN_080384f4(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080384fe @ 080384fe ===== */

longlong FUN_080384fe(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08038510 @ 08038510 ===== */

longlong FUN_08038510(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_0803851c @ 0803851c ===== */

longlong FUN_0803851c(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_0803852c @ 0803852c ===== */

longlong FUN_0803852c(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_0803853a @ 0803853a ===== */

longlong FUN_0803853a(undefined2 *param_1)

{
  uint unaff_r7;
  
  FUN_080194bc(*param_1,param_1[1]);
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08038548 @ 08038548 ===== */

longlong FUN_08038548(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08038558 @ 08038558 ===== */

longlong FUN_08038558(int param_1)

{
  return (ulonglong)*(byte *)(param_1 + 2) << 0x20;
}



/* ===== FUN_08038584 @ 08038584 ===== */

longlong FUN_08038584(int param_1)

{
  return (ulonglong)(param_1 + 6) << 0x20;
}



/* ===== FUN_0803859c @ 0803859c ===== */

longlong FUN_0803859c(undefined2 *param_1)

{
  FUN_080194fa(*param_1,param_1[1],param_1[2],param_1[3]);
  return ZEXT48(param_1 + 4) << 0x20;
}



/* ===== FUN_080385b4 @ 080385b4 ===== */

longlong FUN_080385b4(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080385c0 @ 080385c0 ===== */

longlong FUN_080385c0(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080385ce @ 080385ce ===== */

longlong FUN_080385ce(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080385e0 @ 080385e0 ===== */

undefined4 FUN_080385e0(int param_1)

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



/* ===== FUN_08038612 @ 08038612 ===== */

longlong FUN_08038612(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08038624 @ 08038624 ===== */

longlong FUN_08038624(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08038634 @ 08038634 ===== */

longlong FUN_08038634(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08038644 @ 08038644 ===== */

longlong FUN_08038644(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08038654 @ 08038654 ===== */

longlong FUN_08038654(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08038666 @ 08038666 ===== */

longlong FUN_08038666(int param_1)

{
  return (ulonglong)(param_1 + 7) << 0x20;
}



/* ===== FUN_0803867c @ 0803867c ===== */

longlong FUN_0803867c(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08038688 @ 08038688 ===== */

longlong FUN_08038688(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_0803869a @ 0803869a ===== */

longlong FUN_0803869a(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080386ac @ 080386ac ===== */

longlong FUN_080386ac(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080386ba @ 080386ba ===== */

longlong FUN_080386ba(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080386ce @ 080386ce ===== */

longlong FUN_080386ce(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080386e0 @ 080386e0 ===== */

longlong FUN_080386e0(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_080386f2 @ 080386f2 ===== */

longlong FUN_080386f2(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08038702 @ 08038702 ===== */

undefined4 FUN_08038702(int param_1)

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



/* ===== FUN_0803872c @ 0803872c ===== */

longlong FUN_0803872c(undefined2 *param_1)

{
  uint unaff_r7;
  
  FUN_080195aa(*param_1,param_1[1]);
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_0803873a @ 0803873a ===== */

longlong FUN_0803873a(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08038746 @ 08038746 ===== */

longlong FUN_08038746(int param_1)

{
  return (ulonglong)(param_1 + 7) << 0x20;
}



/* ===== FUN_0803875c @ 0803875c ===== */

undefined4
FUN_0803875c(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_08019464(*param_1,*(undefined2 *)(param_1 + 1),param_1[3],param_1[4],param_1 + 5,
               *(undefined2 *)(param_1 + 0xb),*(undefined2 *)(param_1 + 0xd),
               *(undefined2 *)(param_1 + 0xf),param_1[0x11],param_4);
  return 0;
}



/* ===== FUN_0803878e @ 0803878e ===== */

longlong FUN_0803878e(byte *param_1)

{
  char cVar1;
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
    FUN_0802f9b8(pbVar3 + 2,pbVar4 + 2,6);
    pbVar3[8] = pbVar4[8];
    *(byte **)(pbVar3 + 0xc) = pbVar4 + 9;
    cVar1 = pbVar4[8] + cVar2;
    cVar2 = cVar1 + '\n';
    pbVar3[0x10] = param_1[(byte)(cVar1 + 9)];
    pbVar3 = pbVar3 + 0x14;
    pbVar4 = pbVar4 + 0xb;
  }
  return ZEXT48(local_90) << 0x20;
}



/* ===== FUN_080387e8 @ 080387e8 ===== */

longlong FUN_080387e8(undefined1 *param_1)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 7);
  FUN_0801948a(*param_1,*(undefined2 *)(param_1 + 1),*(undefined2 *)(param_1 + 3),
               *(undefined2 *)(param_1 + 5));
  return (ulonglong)uVar1 << 0x20;
}



/* ===== FUN_08038806 @ 08038806 ===== */

longlong FUN_08038806(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08038818 @ 08038818 ===== */

longlong FUN_08038818(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_08038828 @ 08038828 ===== */

longlong FUN_08038828(int param_1)

{
  return (ulonglong)*(ushort *)(param_1 + 8) << 0x20;
}



/* ===== FUN_0803883e @ 0803883e ===== */

longlong FUN_0803883e(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_0803884c @ 0803884c ===== */

longlong FUN_0803884c(void)

{
  uint unaff_r7;
  
  return (ulonglong)unaff_r7 << 0x20;
}



/* ===== FUN_0803885a @ 0803885a ===== */

longlong FUN_0803885a(int param_1)

{
  return (ulonglong)*(ushort *)(param_1 + 1) << 0x20;
}



/* ===== FUN_08038898 @ 08038898 ===== */

longlong FUN_08038898(byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
    FUN_0802f9b8(pbVar2 + 2,pbVar3 + 2,6);
    pbVar2[8] = pbVar3[8];
    FUN_0802f9b8(pbVar2 + 9,pbVar3 + 9,6);
    pbVar2[0xf] = pbVar3[0xf];
    pbVar3 = pbVar3 + 0x10;
    pbVar2 = pbVar2 + 0x10;
  }
  return ZEXT48(local_98) << 0x20;
}



/* ===== FUN_0803992c @ 0803992c ===== */

void FUN_0803992c(void)

{
  return;
}



/* ===== FUN_0803992e @ 0803992e ===== */

void FUN_0803992e(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_08039930 @ 08039930 ===== */

void FUN_08039930(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_08039932 @ 08039932 ===== */

void FUN_08039932(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_08039934 @ 08039934 ===== */

void FUN_08039934(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_08039936 @ 08039936 ===== */

void FUN_08039936(void)

{
  return;
}



/* ===== FUN_08039938 @ 08039938 ===== */

void FUN_08039938(void)

{
  return;
}



/* ===== FUN_0803993a @ 0803993a ===== */

void FUN_0803993a(void)

{
  return;
}



/* ===== FUN_0803993c @ 0803993c ===== */

void FUN_0803993c(void)

{
  if (*DAT_08039ac8 << 0x1f < 0) {
    *DAT_08039ac8 = 1;
    *(undefined1 *)(DAT_08022a0c + 5) = 1;
    *DAT_08022a10 = 1;
    DataSynchronizationBarrier(0xf);
    return;
  }
  return;
}



/* ===== FUN_08039950 @ 08039950 ===== */

int * FUN_08039950(void)

{
  int *unaff_r7;
  
  if (*DAT_08039ac8 << 0x1b < 0) {
    *DAT_08039ac8 = 0x10;
    FUN_08024206();
    *DAT_08039acc = 1;
    DataSynchronizationBarrier(0xf);
    return unaff_r7;
  }
  return DAT_08039ac8;
}



/* ===== FUN_0803996e @ 0803996e ===== */

void FUN_0803996e(void)

{
  if (*DAT_08039ad0 << 0x1e < 0) {
    DAT_08039ad0[1] = 2;
    FUN_08017956();
    *DAT_08039acc = 1;
    DataSynchronizationBarrier(0xf);
  }
  return;
}



/* ===== FUN_0803998e @ 0803998e ===== */

void FUN_0803998e(void)

{
  int *piVar1;
  
  piVar1 = DAT_08039ad0;
  if (*DAT_08039ad0 << 0x1a < 0) {
    DAT_08039ad0[1] = 0x20;
    thunk_FUN_0802defa();
  }
  if (*piVar1 << 0x19 < 0) {
    piVar1[1] = 0x40;
    thunk_FUN_0802defa();
  }
  if (*piVar1 << 0x18 < 0) {
    piVar1[1] = 0x80;
  }
  return;
}



/* ===== FUN_080399ba @ 080399ba ===== */

void FUN_080399ba(void)

{
  if (*DAT_08039ad4 << 0x1c < 0) {
    *DAT_08039ad4 = 8;
    if ((short)*DAT_08039ad8 < 1) {
      return;
    }
  }
  FUN_08016234(DAT_08039adc);
  return;
}



/* ===== FUN_080399d8 @ 080399d8 ===== */

void FUN_080399d8(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_08039ac8;
  iVar2 = *DAT_08039ac8;
  if (iVar2 << 0x1a < 0) {
    *DAT_08039ac8 = 0x20;
    FUN_08024206(iVar2 << 0x1a,0x20,*piVar1);
    *DAT_08039acc = 1;
    DataSynchronizationBarrier(0xf);
  }
  iVar2 = *piVar1;
  if (iVar2 << 0x19 < 0) {
    *piVar1 = 0x40;
    FUN_08024206(iVar2 << 0x19,0x40,*piVar1);
    *DAT_08039acc = 1;
    DataSynchronizationBarrier(0xf);
  }
  if (*piVar1 << 0x18 < 0) {
    *piVar1 = 0x80;
  }
  if (*piVar1 << 0x17 < 0) {
    *piVar1 = 0x100;
  }
  return;
}



/* ===== FUN_08039a2c @ 08039a2c ===== */

void FUN_08039a2c(void)

{
  if (*DAT_08039ac8 << 0x12 < 0) {
    *DAT_08039ac8 = 0x2000;
    *DAT_08039acc = 1;
    DataSynchronizationBarrier(0xf);
    *DAT_08039ae0 = 1;
  }
  return;
}



/* ===== thunk_FUN_08020ca0 @ 08039a4e ===== */

undefined8 thunk_FUN_08020ca0(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  undefined *puVar8;
  int *piVar9;
  int iVar10;
  uint uStack_20;
  uint uStack_1c;
  
  puVar6 = DAT_08020edc;
  puVar3 = DAT_08020ecc;
  DAT_08020edc[0x11] = DAT_08020edc[0x11] & 0xffff7fff;
  *puVar3 = *puVar3 & 0xfffffffe;
  puVar3[3] = puVar3[3] & 0xfffffeff;
  puVar5 = DAT_08020ed8;
  DataSynchronizationBarrier(0xf);
  DataMemoryBarrier(0x1f);
  *DAT_08020ed8 = *DAT_08020ed8 & 0xfffffffe;
  iVar1 = DAT_08020ec0;
  DataSynchronizationBarrier(0xf);
  DataMemoryBarrier(0x1f);
  iVar10 = *(int *)(DAT_08020ec0 + 0x2c);
  uStack_20 = param_3;
  uStack_1c = param_4;
  if (iVar10 == 0) {
    *(undefined1 *)(DAT_08020ec0 + 1) = 0;
    puVar2 = DAT_08020ec4;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *puVar2 = 0;
    if (*(int *)(iVar1 + 4) == 0) {
      *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(iVar1 + 0x24);
    }
    else {
      *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 0x24);
    }
    *(undefined4 *)(iVar1 + 0x24) = 0;
  }
  else {
    puVar8 = (undefined *)0x0;
    if (*(char *)(DAT_08020ec0 + 1) != '\0') {
      uStack_1c = (((uint)((*(int *)(iVar10 + 4) + 1) * 1000) / *(uint *)(DAT_08020ec0 + 0x38)) *
                  1000) / *(uint *)(DAT_08020ec0 + 0x3c) - 1;
      uStack_20 = ((DAT_08020ee0 / *(uint *)(DAT_08020ec0 + 0x30)) * 1000) /
                  *(uint *)(DAT_08020ec0 + 0x34);
      if (uStack_20 < 0xff) {
        uStack_20 = 0xff;
      }
      iVar7 = (**(code **)(iVar10 + 0x1c))(iVar10,&uStack_20,&uStack_1c);
      puVar3[0xb] = uStack_1c;
      puVar4 = DAT_08020ed0;
      *DAT_08020ed0 = *DAT_08020ed0 & 0xfffffffe;
      puVar4[9] = 0;
      puVar4[0xb] = *(uint *)(iVar10 + 8);
      *puVar6 = *puVar6 & 0xfffffffe;
      puVar6[0xb] = uStack_20;
      if (iVar7 != 0) {
        puVar5[1] = *(uint *)(iVar10 + 0xc) | puVar5[1] & 0xffff0000;
        *puVar5 = *puVar5 | 1;
        puVar3[3] = puVar3[3] | 0x100;
        puVar6[0x11] = puVar6[0x11] | 0x8000;
      }
      *puVar3 = *puVar3 | 1;
      piVar9 = *(int **)(iVar10 + 0x14);
      if (piVar9 == (int *)0x0) {
        puVar8 = *(undefined **)(iVar10 + 0x10);
        if (puVar8 == &UNK_08020ef8) {
          puVar8 = (undefined *)(*(int *)(iVar1 + 0x2c) + 0x20);
        }
        else if (((puVar8 == (undefined *)0x0) && (*(char *)(iVar1 + 2) != '\0')) &&
                (*(byte *)(iVar1 + 2) < 0x12)) {
          *(undefined1 *)(iVar1 + 1) = *(undefined1 *)(iVar1 + 2);
          iVar10 = DAT_08020ee4;
          *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar1 + 0x10);
          *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar1 + 0x28);
          puVar8 = *(undefined **)(iVar10 + (uint)*(byte *)(iVar1 + 2) * 8);
          *(undefined1 *)(iVar1 + 2) = 0;
          *(undefined4 *)(iVar1 + 0x10) = 0;
          *(undefined4 *)(iVar1 + 0x28) = 0;
        }
      }
      else {
        if (*piVar9 == 0) {
          iVar7 = *(int *)(iVar10 + 0x18);
        }
        else {
          iVar7 = *piVar9 + -1;
        }
        *piVar9 = iVar7;
        if (iVar7 == 0) {
          *(undefined4 *)(iVar1 + 0x3c) = *(undefined4 *)(iVar1 + 0x38);
          puVar8 = (undefined *)(*(int *)(iVar1 + 0x2c) + 0x20);
          *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(iVar1 + 0x30);
        }
        else {
          puVar8 = *(undefined **)(iVar10 + 0x10);
        }
      }
    }
    *(undefined **)(iVar1 + 0x2c) = puVar8;
  }
  puVar3 = DAT_08020ed0;
  DAT_08020ed0[4] = 0xfffffffe;
  *puVar3 = *puVar3 | 1;
  *puVar6 = *puVar6 | 1;
  return CONCAT44(uStack_1c,uStack_20);
}



/* ===== thunk_FUN_08021570 @ 08039a52 ===== */

uint thunk_FUN_08021570(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  
  puVar1 = DAT_08021598;
  *DAT_08021598 = 0;
  puVar1[1] = 0;
  *DAT_0802159c = 0;
  puVar2 = DAT_080215a0;
  *DAT_080215a0 = *DAT_080215a0 & 0xfffffffe;
  puVar2[4] = 0xfffffffe;
  return puVar2[4];
}



/* ===== FUN_08039a56 @ 08039a56 ===== */

void FUN_08039a56(void)

{
  return;
}



/* ===== thunk_FUN_08023e64 @ 08039a58 ===== */

undefined4 thunk_FUN_08023e64(void)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  undefined4 extraout_r3;
  undefined4 unaff_r7;
  
  FUN_0802e2d6();
  FUN_0802ded2();
  iVar1 = FUN_08022a56();
  FUN_08022dd4(iVar1,unaff_r7);
  if (*(char *)(iVar1 + 0x18) == '\x01') {
    if (*(char *)(iVar1 + 0x19f0) == '\0') goto LAB_0802e79a;
    FUN_0802de62();
  }
  if (*(char *)(iVar1 + 0x18) == '\x02') {
    FUN_0802e31a(100);
  }
LAB_0802e79a:
  if (*(int *)(iVar1 + 0x1c) == 0) {
    if (*(int *)(iVar1 + 0x58) < 4) {
      *(int *)(iVar1 + 0x58) = *(int *)(iVar1 + 0x58) + 1;
    }
    iVar4 = *(int *)(iVar1 + 0x54) + 1;
    if (3 < iVar4) {
      iVar4 = 0;
    }
    *(int *)(iVar1 + 0x54) = iVar4;
    *(int *)(iVar1 + 0x5c) = *(int *)(iVar1 + 0x50) + iVar4 * 0x2c;
    FUN_0803124c();
    *DAT_0802e860 = 1;
    DataSynchronizationBarrier(0xf);
    *DAT_0802e864 = 1;
    *(undefined1 *)(iVar1 + 0x19) = *(undefined1 *)(iVar1 + 5);
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(undefined4 *)(iVar1 + 0x24) = 0;
    switch(*(undefined1 *)(iVar1 + 0x1a)) {
    case 0:
      FUN_08022ed2(iVar1);
      break;
    case 1:
      FUN_08023018(iVar1);
      break;
    case 2:
      FUN_080231b8(iVar1);
      break;
    case 3:
      FUN_0802352e(iVar1);
      break;
    case 4:
      FUN_080236bc(iVar1);
    }
    *(undefined1 *)(iVar1 + 0x28) = 1;
    *(undefined1 *)(iVar1 + 0x18) = *(undefined1 *)(iVar1 + 0x1a);
    FUN_08022c3e(iVar1);
    *(undefined1 *)(iVar1 + 0x2c) = *(undefined1 *)(iVar1 + 0x3c);
    iVar4 = *(int *)(iVar1 + 0x40);
    if (0 < iVar4) {
      iVar4 = iVar4 + -1;
    }
    *(int *)(iVar1 + 0x40) = iVar4;
    if ((iVar4 == 0) && (*(int *)(iVar1 + 0x34) != 0)) {
      iVar4 = *(int *)(iVar1 + 0x38) + 1;
      if (*(int *)(iVar1 + 0x34) <= iVar4) {
        iVar4 = 0;
      }
      *(int *)(iVar1 + 0x38) = iVar4;
      iVar4 = *(int *)(iVar1 + 0x30) + iVar4 * 4;
      bVar3 = *(byte *)(iVar4 + 1);
      if (bVar3 < 9) {
        uVar2 = (uint)*(ushort *)(iVar4 + 2);
      }
      else {
        bVar3 = 0;
        uVar2 = 0;
      }
      *(byte *)(iVar1 + 0x3c) = bVar3;
      *(uint *)(iVar1 + 0x40) = uVar2;
    }
  }
  return extraout_r3;
}



/* ===== FUN_08039a5c @ 08039a5c ===== */

void FUN_08039a5c(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  
  puVar2 = DAT_08039ae8;
  *(uint *)(DAT_08039ae4 + 4) = *(uint *)(DAT_08039ae4 + 4) | 2;
  *puVar2 = 0x10000;
  puVar3 = DAT_08039aec;
  uVar4 = *DAT_08039aec;
  puVar1 = DAT_08039aec + 1;
  *DAT_08039aec = uVar4 + 0x20;
  puVar3[1] = *puVar1 + (uint)(0xffffffdf < uVar4);
  iVar5 = FUN_080176c8();
  if (iVar5 != 0) {
    *DAT_08039acc = 1;
    DataSynchronizationBarrier(0xf);
  }
  return;
}



/* ===== FUN_08039a96 @ 08039a96 ===== */

undefined4 FUN_08039a96(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_08039af0;
  DAT_08039af0[1] = DAT_08039af0[1] | 2;
  return *puVar1;
}



/* ===== FUN_08039aa4 @ 08039aa4 ===== */

int * FUN_08039aa4(void)

{
  int *piVar1;
  
  piVar1 = DAT_08039ac8;
  if (*DAT_08039ac8 << 0x1c < 0) {
    *DAT_08039ac8 = 8;
    piVar1 = (int *)*piVar1;
  }
  return piVar1;
}



/* ===== FUN_08039ab4 @ 08039ab4 ===== */

undefined4 FUN_08039ab4(void)

{
  undefined4 unaff_r7;
  
  (*(code *)*DAT_08039af4)();
  *DAT_08039acc = 1;
  DataSynchronizationBarrier(0xf);
  return unaff_r7;
}



/* ===== FUN_08039af8 @ 08039af8 ===== */

void FUN_08039af8(int param_1,uint param_2)

{
  char cVar1;
  char cVar2;
  ulonglong uVar3;
  uint uVar4;
  char local_20;
  char local_1f;
  char local_1e;
  char local_1d;
  undefined1 local_1c;
  int iStack_18;
  uint local_14;
  
  uVar4 = param_2 >> 8;
  local_1c = 0;
  local_1e = (char)(param_2 >> 8);
  switch(param_2 & 0xf) {
  case 1:
    local_1e = local_1e + '0';
    local_20 = '_';
    local_1d = ' ';
    local_1f = '_';
    break;
  case 2:
    local_1f = (char)((ulonglong)uVar4 * (ulonglong)DAT_08039ca4 >> 0x23);
    local_1e = local_1e + local_1f * -10 + '0';
    local_1f = local_1f + '0';
    local_1d = ' ';
    local_20 = '_';
    break;
  case 3:
    uVar3 = (ulonglong)uVar4 * (ulonglong)DAT_08039ca4 >> 0x23;
    cVar1 = (char)uVar3;
    local_1d = local_1e + cVar1 * -10 + '0';
    local_20 = (char)((ulonglong)(uint)uVar3 * (ulonglong)DAT_08039ca4 >> 0x23);
    local_1e = cVar1 + local_20 * -10 + '0';
    local_20 = local_20 + '0';
    local_1f = '.';
    break;
  case 4:
    uVar3 = (ulonglong)uVar4 * (ulonglong)DAT_08039ca4 >> 0x23;
    cVar1 = (char)uVar3;
    local_1d = local_1e + cVar1 * -10 + '0';
    local_1e = '.';
    local_20 = (char)((ulonglong)(uint)uVar3 * (ulonglong)DAT_08039ca4 >> 0x23);
    local_1f = cVar1 + local_20 * -10 + '0';
    local_20 = local_20 + '0';
    break;
  case 5:
    uVar3 = (ulonglong)uVar4 * (ulonglong)DAT_08039ca4 >> 0x23;
    cVar1 = (char)uVar3;
    local_1e = local_1e + cVar1 * -10 + '0';
    local_1d = ' ';
    local_20 = (char)((ulonglong)(uint)uVar3 * (ulonglong)DAT_08039ca4 >> 0x23);
    local_1f = cVar1 + local_20 * -10 + '0';
    local_20 = local_20 + '0';
    break;
  case 6:
    local_1f = (char)((ulonglong)uVar4 * (ulonglong)DAT_08039ca4 >> 0x23);
    local_1d = local_1e + local_1f * -10 + '0';
    local_1f = local_1f + '0';
    local_1e = '.';
    local_20 = '>';
    break;
  case 7:
    uVar3 = (ulonglong)uVar4 * (ulonglong)DAT_08039ca4 >> 0x23;
    cVar2 = (char)uVar3;
    local_1d = local_1e + cVar2 * -10 + '0';
    cVar1 = (char)((ulonglong)(uint)uVar3 * (ulonglong)DAT_08039ca4 >> 0x23);
    local_1f = cVar1 + '0';
    local_1e = cVar2 + cVar1 * -10 + '0';
    local_20 = '>';
    break;
  case 8:
    local_1f = (char)((ulonglong)uVar4 * (ulonglong)DAT_08039ca4 >> 0x23);
    local_1e = local_1e + local_1f * -10 + '0';
    local_1f = local_1f + '0';
    local_1d = ' ';
    local_20 = '>';
    break;
  default:
    local_1d = '-';
    local_1e = '-';
    local_1f = '-';
    local_20 = ' ';
  }
  iStack_18 = param_1;
  local_14 = param_2;
  FUN_08018b1c(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5));
  FUN_080190ec(&local_20);
  return;
}



/* ===== FUN_08039fd8 @ 08039fd8 ===== */

undefined8 FUN_08039fd8(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 local_20;
  byte local_1c;
  byte local_1b;
  char local_1a;
  char local_19;
  
  local_1c = (byte)param_4;
  local_1b = (byte)((uint)param_4 >> 8);
  local_1a = (char)((uint)param_4 >> 0x10);
  local_19 = (char)((uint)param_4 >> 0x18);
  iVar3 = *(int *)(param_1 + 8);
  if (0x77 < iVar3) {
    iVar3 = 0x77;
  }
  if (0x77 < param_2) {
    param_2 = 0x77;
  }
  local_20 = param_3;
  if (param_2 != iVar3) {
    FUN_0802c994(&local_1b,&local_1a,&local_19,&local_1c);
    local_19 = local_19 - local_1b;
    local_1b = local_19 - 0x2d;
    iVar2 = (int)((ulonglong)((longlong)iVar3 * (longlong)DAT_0803a158) >> 0x20) + iVar3;
    local_1c = (local_1c - local_1a) - 1;
    iVar2 = (iVar2 >> 3) - (iVar2 >> 0x1f);
    local_1a = '\x01';
    iVar1 = (int)((ulonglong)((longlong)param_2 * (longlong)DAT_0803a158) >> 0x20) + param_2;
    iVar3 = iVar3 + iVar2 * -0xf;
    iVar1 = (iVar1 >> 3) - (iVar1 >> 0x1f);
    param_2 = param_2 + iVar1 * -0xf;
    if (iVar2 < iVar1) {
      uVar5 = (uint)local_1b + iVar2 * 6;
      FUN_0803a15c(uVar5 & 0xff,1,uVar5 + 2 & 0xff,((uint)local_1c - iVar3) - 1 & 0xff);
      if (iVar2 + 1 < iVar1) {
        iVar3 = iVar1 - (iVar2 + 1);
        do {
          FUN_0803a15c(uVar5 + 6 & 0xff,local_1a,uVar5 + 8 & 0xff,local_1c);
          iVar3 = iVar3 + -1;
          uVar5 = uVar5 + 6;
        } while (iVar3 != 0);
      }
      local_20 = 0xffff;
      iVar3 = -1;
    }
    else if (iVar1 < iVar2) {
      uVar5 = (uint)local_1b + iVar2 * 6;
      FUN_0803a15c(uVar5 & 0xff,(uint)local_1c - iVar3 & 0xff,uVar5 + 2 & 0xff);
      if (iVar1 < iVar2 + -1) {
        iVar3 = (iVar2 + -1) - iVar1;
        do {
          FUN_0803a15c(uVar5 - 6 & 0xff,local_1a,uVar5 - 4 & 0xff,local_1c);
          iVar3 = iVar3 + -1;
          uVar5 = uVar5 - 6;
        } while (iVar3 != 0);
      }
      local_20 = 0;
      iVar3 = 0xe;
    }
    uVar5 = (uint)local_1b + iVar1 * 6;
    if (iVar3 < param_2) {
      local_20 = 0xffff;
      iVar2 = (uint)local_1c - iVar3;
      uVar4 = (uint)local_1c - param_2;
    }
    else {
      if (iVar3 <= param_2) goto LAB_0803a154;
      local_20 = 0;
      iVar2 = (uint)local_1c - param_2;
      uVar4 = (uint)local_1c - iVar3;
    }
    FUN_0803a15c(uVar5 & 0xff,uVar4 & 0xff,uVar5 + 2 & 0xff,iVar2 - 1U & 0xff);
  }
LAB_0803a154:
  return CONCAT17(local_19,CONCAT16(local_1a,CONCAT15(local_1b,CONCAT14(local_1c,local_20))));
}



/* ===== FUN_0803a15c @ 0803a15c ===== */

void FUN_0803a15c(char param_1,char param_2,char param_3,char param_4,ushort param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte *pbVar6;
  
  pbVar6 = (byte *)*DAT_0803a1dc;
  bVar3 = *pbVar6;
  bVar4 = pbVar6[1];
  bVar1 = bVar3 + param_1;
  if ((byte)(bVar3 + param_1) < bVar3) {
    bVar1 = bVar3;
  }
  bVar5 = pbVar6[2];
  if (bVar1 < pbVar6[2]) {
    bVar5 = bVar1;
  }
  bVar1 = pbVar6[2];
  if ((byte)(bVar3 + param_3) < pbVar6[2]) {
    bVar1 = bVar3 + param_3;
  }
  bVar3 = bVar5;
  if (bVar5 < bVar1) {
    bVar3 = bVar1;
  }
  bVar1 = bVar4;
  if (bVar4 < (byte)(bVar4 + param_2)) {
    bVar1 = bVar4 + param_2;
  }
  bVar2 = pbVar6[3];
  if (bVar1 < pbVar6[3]) {
    bVar2 = bVar1;
  }
  bVar1 = pbVar6[3];
  if ((byte)(bVar4 + param_4) < pbVar6[3]) {
    bVar1 = bVar4 + param_4;
  }
  bVar4 = bVar2;
  if (bVar2 < bVar1) {
    bVar4 = bVar1;
  }
  *DAT_0803a1e0 = 0;
  if ((int)((uint)pbVar6[0x10] << 0x1f) < 0) {
    param_5 = ~param_5;
  }
  FUN_080274b0(bVar5,bVar2,bVar3,bVar4);
  FUN_0802b7ec(param_5);
  return;
}



/* ===== FUN_0803a85c @ 0803a85c ===== */

undefined8 FUN_0803a85c(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_20;
  
  iVar1 = *(int *)(param_1 + 8);
  if (0x17 < iVar1) {
    iVar1 = 0x17;
  }
  if (0x17 < param_2) {
    param_2 = 0x17;
  }
  local_20 = param_3;
  if (param_2 != iVar1) {
    iVar3 = (int)((ulonglong)
                  ((longlong)iVar1 *
                  (longlong)(int)s_gfffError__S_d_Packet_size_corru_0803a96c._0_4_) >> 0x20);
    iVar2 = (int)((ulonglong)
                  ((longlong)param_2 *
                  (longlong)(int)s_gfffError__S_d_Packet_size_corru_0803a96c._0_4_) >> 0x20);
    iVar3 = (iVar3 >> 2) - (iVar3 >> 0x1f);
    iVar2 = (iVar2 >> 2) - (iVar2 >> 0x1f);
    iVar1 = iVar1 + iVar3 * -10;
    param_2 = param_2 + iVar2 * -10;
    if (iVar3 < iVar2) {
      uVar4 = iVar3 * 0xd + 2;
      FUN_0803a15c(iVar1 + uVar4 + 1 & 0xff,2,iVar3 * 0xd + 0xbU & 0xff,4);
      if (iVar3 + 1 < iVar2) {
        iVar1 = iVar2 - (iVar3 + 1);
        do {
          FUN_0803a15c(uVar4 + 0xd & 0xff,2,uVar4 + 0x16 & 0xff,4);
          iVar1 = iVar1 + -1;
          uVar4 = uVar4 + 0xd;
        } while (iVar1 != 0);
      }
      local_20 = 0xffff;
      iVar1 = -1;
    }
    else if (iVar2 < iVar3) {
      uVar4 = iVar3 * 0xd + 2;
      FUN_0803a15c(uVar4 & 0xff,2,iVar1 + uVar4 + 1 & 0xff,4);
      if (iVar2 < iVar3 + -1) {
        iVar1 = (iVar3 + -1) - iVar2;
        do {
          FUN_0803a15c(uVar4 - 0xd & 0xff,2,uVar4 - 4 & 0xff,4);
          iVar1 = iVar1 + -1;
          uVar4 = uVar4 - 0xd;
        } while (iVar1 != 0);
      }
      local_20 = 0;
      iVar1 = 9;
    }
    iVar2 = iVar2 * 0xd + 2;
    if (iVar1 < param_2) {
      local_20 = 0xffff;
      iVar3 = param_2;
      param_2 = iVar1;
    }
    else {
      if (iVar1 <= param_2) goto LAB_0803a966;
      local_20 = 0;
      iVar3 = iVar1;
    }
    FUN_0803a15c(param_2 + iVar2 + 1U & 0xff,2,iVar3 + iVar2 & 0xff,4);
  }
LAB_0803a966:
  return CONCAT44(param_4,local_20);
}



/* ===== FUN_0803b8f0 @ 0803b8f0 ===== */

undefined4 FUN_0803b8f0(void)

{
  char cVar1;
  undefined4 in_r3;
  int iVar2;
  char cVar3;
  undefined4 local_10;
  
  local_10 = in_r3;
  FUN_0802c994((int)&local_10 + 1,(int)&local_10 + 3,&local_10,(int)&local_10 + 2);
  cVar1 = (char)local_10 - local_10._1_1_;
  iVar2 = 8;
  cVar3 = cVar1 + -0x2e;
  local_10 = CONCAT22(CONCAT11(local_10._3_1_,local_10._2_1_ - local_10._3_1_),CONCAT11(cVar3,cVar1)
                     );
  do {
    FUN_08020550(cVar3 + '\x01',0);
    FUN_0802056a(cVar3 + '\x03',0);
    FUN_08020550(cVar3 + '\x04',1);
    FUN_0802056a(cVar3 + '\x04',0xf);
    FUN_08020550(cVar3 + '\x03',0x10);
    FUN_0802056a(cVar3 + '\x01',0x10);
    FUN_08020550(cVar3,0xf);
    FUN_0802056a(cVar3,1);
    cVar3 = cVar3 + '\x06';
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return local_10;
}



/* ===== FUN_0803c098 @ 0803c098 ===== */

void FUN_0803c098(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  FUN_0802b9fc(*(undefined1 *)(param_1 + 0x14),
               *(char *)(param_1 + 0x16) + ('/' - *(char *)(param_1 + 0x17)),
               *(undefined1 *)(param_1 + 0x15),0x2f,param_4);
  uVar1 = FUN_0803c104();
  if (*(char *)(param_1 + 9) == '\0') {
    uVar1 = uVar1 & 0xfffe;
  }
  else {
    uVar1 = uVar1 | 1;
  }
  FUN_08018b64(uVar1);
  uVar2 = FUN_0801ff48(DAT_0803c0fc);
  FUN_080190f8(*(undefined4 *)(*DAT_0803c100 + *(int *)(param_1 + 0x18) * 4));
  FUN_0801ff48(uVar2);
  FUN_0802b9fc(*(undefined1 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x16),
               *(undefined1 *)(param_1 + 0x15),*(undefined1 *)(param_1 + 0x17));
  return;
}



/* ===== FUN_0803c104 @ 0803c104 ===== */

undefined2 FUN_0803c104(void)

{
  return *(undefined2 *)(*DAT_0803c10c + 0x10);
}



/* ===== FUN_0803c29c @ 0803c29c ===== */

void FUN_0803c29c(void)

{
  uint *puVar1;
  
  *DAT_0803c2d8 = DAT_0803c2dc;
  puVar1 = DAT_0803c2e4;
  *DAT_0803c2e0 = *DAT_0803c2e0 | 0xf00000;
  *puVar1 = *puVar1 | 1;
  puVar1[2] = 0;
  *puVar1 = *puVar1 & DAT_0803c2e8;
  puVar1[3] = 0x1000;
  *puVar1 = *puVar1 & 0xfffbffff;
  puVar1[6] = 0;
  return;
}



/* ===== FUN_0803c3b8 @ 0803c3b8 ===== */

void FUN_0803c3b8(int param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 == 2 || param_2 == 3) {
    if (*(short *)(DAT_0803c408 + 8) == 0) {
      return;
    }
    iVar3 = DAT_0803c408;
  }
  else {
    if (param_2 == 5 || param_2 == 6) {
      sVar1 = *(short *)(DAT_0803c40c + 8);
      iVar3 = DAT_0803c40c;
    }
    else {
      if (param_2 != 8 && param_2 != 9) {
        return;
      }
      sVar1 = *(short *)(DAT_0803c410 + 8);
      iVar3 = DAT_0803c410;
    }
    if (sVar1 == 0) {
      return;
    }
  }
  uVar2 = FUN_0802c8ac(0,iVar3);
  FUN_0802c8c8(*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2),uVar2);
  return;
}



/* ===== FUN_0803c414 @ 0803c414 ===== */

undefined4 FUN_0803c414(void)

{
  undefined4 in_r3;
  int iVar1;
  char cVar2;
  
  cVar2 = '\x01';
  iVar1 = 8;
  do {
    FUN_08020550(cVar2 + '\x01',1);
    FUN_0802056a(cVar2 + '\n',1);
    FUN_08020550(cVar2 + '\v',2);
    FUN_0802056a(cVar2 + '\v',4);
    FUN_08020550(cVar2 + '\n',5);
    FUN_0802056a(cVar2 + '\x01',5);
    FUN_08020550(cVar2,4);
    FUN_0802056a(cVar2,2);
    cVar2 = cVar2 + '\r';
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return in_r3;
}



/* ===== FUN_0803d0cc @ 0803d0cc ===== */

void FUN_0803d0cc(int param_1,undefined2 *param_2)

{
  int iVar1;
  uint in_fpscr;
  float fVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_0802eaf2();
  FUN_08031280(param_1,iVar1);
  if (iVar1 == 0) {
    if ((*(byte *)(param_1 + 0x15) & 0xf8) == 0) {
      fVar2 = (float)VectorUnsignedToFloat
                               ((uint)(*(ushort *)(param_1 + 9) >> 1),(byte)(in_fpscr >> 0x16) & 3);
      *param_2 = (short)(int)(fVar2 * DAT_0802ec60);
      uVar3 = VectorSignedToFloat((int)*(short *)(param_1 + 5) & 0xfffffffc,
                                  (byte)(in_fpscr >> 0x16) & 3);
      *(undefined4 *)(param_2 + 2) = uVar3;
      *(undefined4 *)(param_2 + 4) = 0;
      return;
    }
    if (*(char *)(param_1 + 4) < '\x01') {
      *(undefined1 *)(param_1 + 4) = 2;
    }
  }
  return;
}



/* ===== FUN_0803d174 @ 0803d174 ===== */

void FUN_0803d174(uint *param_1)

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
      puVar4 = (undefined4 *)((int)puVar4 + unaff_r9 + -1);
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



/* ===== FUN_0803d320 @ 0803d320 ===== */

undefined4 FUN_0803d320(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  param_2 = param_2 + param_1[6];
  iVar1 = (**(code **)(*param_1 + 0x18))(param_1);
  if (iVar1 < param_2) {
    param_2 = (**(code **)(*param_1 + 0x14))(param_1);
  }
  *(undefined1 *)((int)param_1 + 10) = 1;
  param_1[6] = param_2;
  *(undefined1 *)(param_1[1] + 0x14) = 1;
  return param_4;
}



/* ===== FUN_0803d41c @ 0803d41c ===== */

undefined4 FUN_0803d41c(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  param_2 = param_1[6] - param_2;
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1);
  if (param_2 < iVar1) {
    param_2 = (**(code **)(*param_1 + 0x18))(param_1);
  }
  *(undefined1 *)((int)param_1 + 10) = 1;
  param_1[6] = param_2;
  *(undefined1 *)(param_1[1] + 0x14) = 1;
  return param_4;
}



/* ===== FUN_0803d6c6 @ 0803d6c6 ===== */

undefined4 FUN_0803d6c6(int param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 extraout_r3;
  char cVar6;
  undefined4 unaff_r4;
  char *pcVar7;
  undefined4 uVar8;
  
  FUN_0801ffd0(**(undefined1 **)(param_1 + 0xc));
  for (uVar5 = param_1 + 0x34; uVar5 < param_1 + 0x108U; uVar5 = uVar5 + 2) {
    *(undefined1 *)(uVar5 + 1) = 0;
  }
  cVar6 = '\0';
  *(undefined1 *)(param_1 + 0x28) = 0;
  uVar8 = extraout_r3;
  for (pcVar7 = (char *)(param_1 + 0x34); pcVar7 < (char *)(param_1 + 0x108); pcVar7 = pcVar7 + 2) {
    cVar1 = pcVar7[1];
    cVar2 = *pcVar7;
    if ((int)cVar2 != (int)cVar1) {
      pcVar7[1] = cVar2;
      iVar3 = -(int)cVar1;
      uVar5 = iVar3 + 0x1d;
      iVar4 = -(int)cVar2;
      if ((char)(iVar4 + 0x1dU) < (char)uVar5) {
        uVar8 = 0xffff;
        uVar5 = iVar4 + 0x1dU;
        iVar4 = iVar3;
      }
      else {
        uVar8 = 0;
      }
      FUN_0803a15c(cVar6,uVar5 & 0xff,cVar6,iVar4 + 0x1cU & 0xff,uVar8,unaff_r4);
    }
    cVar6 = cVar6 + '\x01';
  }
  return uVar8;
}



/* ===== FUN_0803e120 @ 0803e120 ===== */

void FUN_0803e120(void)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)((int)&DAT_0803e144 + DAT_0803e144);
  for (piVar1 = (int *)((int)&DAT_0803e140 + DAT_0803e140); piVar1 != piVar2;
      piVar1 = (int *)(*(code *)((int)piVar1 + *piVar1))(piVar1 + 1)) {
  }
  return;
}



/* ===== FUN_0803e580 @ 0803e580 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0803e580(void)

{
  _DAT_e000ed88 = _DAT_e000ed88 | 0xf00000;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return 0x2040000;
}



/* ===== FUN_0803e5a4 @ 0803e5a4 ===== */

void FUN_0803e5a4(void)

{
  undefined4 uVar1;
  
  FUN_0803e120();
  FUN_0801dc50(0);
  thunk_FUN_0803e5cc();
  uVar1 = FUN_0803e5d0();
  do {
    FUN_08031294(uVar1);
  } while( true );
}



/* ===== thunk_FUN_0803e5cc @ 0803e5c6 ===== */

void thunk_FUN_0803e5cc(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0803e5d0();
  do {
    FUN_08031294(uVar1);
  } while( true );
}



/* ===== FUN_0803e5cc @ 0803e5cc ===== */

void FUN_0803e5cc(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0803e5d0();
  do {
    FUN_08031294(uVar1);
  } while( true );
}



/* ===== FUN_0803e5d0 @ 0803e5d0 ===== */

void FUN_0803e5d0(undefined4 param_1)

{
  do {
    FUN_08031294(param_1);
  } while( true );
}



/* ===== FUN_0803eb40 @ 0803eb40 ===== */

void FUN_0803eb40(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  undefined4 uVar3;
  
  *(undefined1 *)(param_1 + 10) = 0;
  FUN_0802c994(0,param_1 + 0x16,0,param_1 + 0x17);
  uVar3 = extraout_r3;
  FUN_0802b9fc(*(char *)(param_1 + 0x14) + -1,*(undefined1 *)(param_1 + 0x16),
               *(undefined1 *)(param_1 + 0x15),*(undefined1 *)(param_1 + 0x17),extraout_r3,unaff_r4)
  ;
  uVar2 = FUN_0803c104();
  if (*(char *)(param_1 + 9) == '\0') {
    uVar2 = uVar2 & 0xfffe;
  }
  else {
    uVar2 = uVar2 | 1;
  }
  FUN_08018b64(uVar2);
  uVar1 = DAT_0803c8e8;
  FUN_0802c818(DAT_0803c8e8,0x20,DAT_0803c8ec,*(undefined4 *)(param_1 + 0x18));
  FUN_080190f8(uVar1,uVar3);
  return;
}



/* ===== FUN_0803ebc0 @ 0803ebc0 ===== */

undefined4 FUN_0803ebc0(undefined4 param_1)

{
  FUN_0803ebe0((int)&DAT_0803ebdc + DAT_0803ebdc,(int)&DAT_0803ebd8 + DAT_0803ebd8);
  return param_1;
}



/* ===== FUN_0803ebe0 @ 0803ebe0 ===== */

undefined4 FUN_0803ebe0(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    (*(code *)((int)param_1 + *param_1))();
  }
  return param_4;
}



/* ===== Reset_Handler @ 0803f724 ===== */

void Reset_Handler(void)

{
  bool bVar1;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(DAT_0803f734);
  }
  (*DAT_0803f738)();
                    /* WARNING: Could not recover jumptable at 0x0803f730. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0803f73c)();
  return;
}



/* ===== FUN_0803f938 @ 0803f938 ===== */

void FUN_0803f938(int param_1)

{
  FUN_0801ffd0(**(undefined1 **)(param_1 + 0xc));
  FUN_08020440(param_1 + 0x10);
  return;
}



/* ===== FUN_0803f950 @ 0803f950 ===== */

void FUN_0803f950(int param_1)

{
  FUN_0801ffd0(**(undefined1 **)(param_1 + 0xc));
  FUN_080204be(param_1 + 0x10);
  return;
}



/* ===== FUN_0803f968 @ 0803f968 ===== */

void FUN_0803f968(int param_1)

{
  FUN_0801ffd0(**(undefined1 **)(param_1 + 0xc));
  FUN_080206c0(param_1 + 0x10);
  return;
}



/* ===== FUN_0803f980 @ 0803f980 ===== */

void FUN_0803f980(int param_1)

{
  FUN_0801ffd0(**(undefined1 **)(param_1 + 0xc));
  FUN_0802075c(param_1 + 0x10);
  return;
}



/* ===== FUN_0803fc52 @ 0803fc52 ===== */

int FUN_0803fc52(int param_1)

{
  int iVar1;
  int iVar2;
  int extraout_r3;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  FUN_0801ffd0(**(undefined1 **)(param_1 + 0xc));
  iVar1 = DAT_080147b4;
  iVar2 = (int)*(char *)(DAT_080147b4 + 0x14);
  if (iVar2 < 1) {
    return iVar2;
  }
  iVar2 = *(int *)(DAT_080147f4 + iVar2 * 4 + -4);
  if (*(char *)(iVar2 + 0x14) != '\0') {
    *(undefined1 *)(iVar2 + 0x14) = 0;
    puVar3 = (undefined4 *)(iVar1 + *(char *)(iVar2 + 0x17) * 4 + 0x28);
    puVar4 = puVar3 + *(char *)(iVar2 + 0x16);
    for (; puVar3 < puVar4; puVar3 = puVar3 + 1) {
      (**(code **)(*(int *)*puVar3 + 0xc))();
    }
  }
  return extraout_r3;
}



/* ===== FUN_08040148 @ 08040148 ===== */

undefined4 FUN_08040148(undefined4 param_1)

{
  FUN_08031ecc();
  return param_1;
}



/* ===== FUN_080401f4 @ 080401f4 ===== */

void FUN_080401f4(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



