// Copyright 2022 The CRC32C Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

// LoongArch-specific code checking for the availability of CRC32C instructions.

#ifndef CRC32C_CRC32C_LOONGARCH_CHECK_H_
#define CRC32C_CRC32C_LOONGARCH_CHECK_H_

#include <cstddef>
#include <cstdint>

#include "crc32c/crc32c_config.h"

#ifdef __linux__
#include <sys/auxv.h>
#endif

#if HAVE_LOONGARCH_CRC32C

#define AT_HWCAP 16

namespace crc32c {

inline bool CanUseLoongArchCrc32() {
#if defined (__linux__)
  // From 'arch/loongarch/include/uapi/asm/hwcap.h' in Linux kernel source code.
  constexpr unsigned long HWCAP_LOONGARCH_CRC32 = 1 << 6;
  unsigned long hwcap = getauxval(AT_HWCAP);

  return hwcap & HWCAP_LOONGARCH_CRC32;
#endif
  return false;
}

}  // namespace crc32c

#endif  // HAVE_LOONGARCH_CRC32C

#endif  // CRC32C_CRC32C_LOONGARCH_CHECK_H_
