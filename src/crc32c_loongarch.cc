// Copyright 2022 The CRC32C Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#include <cstddef>
#include <cstdint>

#include "./crc32c_internal.h"
#include "./crc32c_loongarch.h"

#if HAVE_LOONGARCH_CRC32C

#include <larchintrin.h>

namespace crc32c {

uint32_t ExtendLoongArch(uint32_t crc, const uint8_t *data, size_t size) {

  crc = crc ^ kCRC32Xor;

  while (size >= sizeof(uint64_t)) {
    crc = __crcc_w_d_w(*(const uint64_t *)data, crc);
    data += sizeof(uint64_t);
    size -= sizeof(uint64_t);
  }

  if (size & sizeof(uint32_t)) {
    crc = __crcc_w_w_w(*(const uint32_t *)data, crc);
    data += sizeof(uint32_t);
    size -= sizeof(uint32_t);
  }

  if (size & sizeof(uint16_t)) {
    crc = __crcc_w_h_w(*(const uint16_t *)data, crc);
    data += sizeof(uint16_t);
    size -= sizeof(uint16_t);
  }

  if (size & sizeof(uint8_t)) {
    crc = __crcc_w_b_w(*data, crc);
  }

  return crc ^ kCRC32Xor;
}

}  // namespace crc32c

#endif  // HAVE_LOONGARCH_CRC32C
