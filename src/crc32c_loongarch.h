// Copyright 2022 The CRC32C Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

// LoongArch-specific code

#ifndef CRC32C_CRC32C_LOONGARCH_H_
#define CRC32C_CRC32C_LOONGARCH_H_

#include <cstddef>
#include <cstdint>

#include "crc32c/crc32c_config.h"

#if HAVE_LOONGARCH_CRC32C

namespace crc32c {

uint32_t ExtendLoongArch(uint32_t crc, const uint8_t* data, size_t count);

}  // namespace crc32c

#endif  // HAVE_LOONGARCH_CRC32C

#endif  // CRC32C_CRC32C_LOONGARCH_H_
