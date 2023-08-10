#include <bits/stdc++.h>


void print_flag(void) {
  int in_GS_OFFSET;
  int local_3c;
  int local_37[0x27] = {0x69 ^ 6, 0x74 ^ 6, 0x73 ^ 6, 0x5f ^ 6, 0x61 ^ 6, 0x5f ^ 6, 0x66 ^ 6, 0x6c ^ 6, 0x61 ^ 6, 0x67 ^ 6, 0x5f ^ 6, 0x7b ^ 6, 0x64 ^ 6, 0x61 ^ 6, 0x32 ^ 6, 0x31 ^ 6, 0x35 ^ 6, 0x30 ^ 6, 0x37 ^ 6, 0x32 ^ 6, 0x31 ^ 6, 0x63 ^ 6, 0x36 ^ 6, 0x37 ^ 6, 0x62 ^ 6, 0x35 ^ 6, 0x39 ^ 6 };
  
  local_3c = *(int *)(in_GS_OFFSET + 0x14);

  for (int i = 0; i < 0x27; i++) {
    putchar(local_37[i]);
  }

  if (local_3c != *(int *)(in_GS_OFFSET + 0x14)) {
    __stack_chk_fail_local();
  }

  return;
}

int main()
{
    print_flag();
    return 0;
}